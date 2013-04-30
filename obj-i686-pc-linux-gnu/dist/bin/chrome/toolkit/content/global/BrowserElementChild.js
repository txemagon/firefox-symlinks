/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

let { classes: Cc, interfaces: Ci, results: Cr, utils: Cu }  = Components;
Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://gre/modules/Services.jsm");
Cu.import("resource://gre/modules/Geometry.jsm");
Cu.import("resource://gre/modules/BrowserElementPromptService.jsm");

// Event whitelisted for bubbling.
let whitelistedEvents = [
  Ci.nsIDOMKeyEvent.DOM_VK_ESCAPE,   // Back button.
  Ci.nsIDOMKeyEvent.DOM_VK_SLEEP,    // Power button.
  Ci.nsIDOMKeyEvent.DOM_VK_CONTEXT_MENU,
  Ci.nsIDOMKeyEvent.DOM_VK_F5,       // Search button.
  Ci.nsIDOMKeyEvent.DOM_VK_PAGE_UP,  // Volume up.
  Ci.nsIDOMKeyEvent.DOM_VK_PAGE_DOWN // Volume down.
];

function debug(msg) {
  //dump("BrowserElementChild - " + msg + "\n");
}

function sendAsyncMsg(msg, data) {
  sendAsyncMessage('browser-element-api:' + msg, data);
}

function sendSyncMsg(msg, data) {
  return sendSyncMessage('browser-element-api:' + msg, data);
}

/**
 * The BrowserElementChild implements one half of <iframe mozbrowser>.
 * (The other half is, unsurprisingly, BrowserElementParent.)
 *
 * This script is injected into an <iframe mozbrowser> via
 * nsIMessageManager::LoadFrameScript().
 *
 * Our job here is to listen for events within this frame and bubble them up to
 * the parent process.
 */

var global = this;

function BrowserElementChild() {
  // Maps outer window id --> weak ref to window.  Used by modal dialog code.
  this._windowIDDict = {};

  // _forcedVisible corresponds to the visibility state our owner has set on us
  // (via iframe.setVisible).  ownerVisible corresponds to whether the docShell
  // whose window owns this element is visible.
  //
  // Our docShell is visible iff _forcedVisible and _ownerVisible are both
  // true.
  this._forcedVisible = true;
  this._ownerVisible = true;

  this._nextPaintHandler = null;

  this._init();
};

BrowserElementChild.prototype = {

  QueryInterface: XPCOMUtils.generateQI([Ci.nsIObserver,
                                         Ci.nsISupportsWeakReference]),

  _init: function() {
    debug("Starting up.");
    sendAsyncMsg("hello");

    // Set the docshell's name according to our <iframe>'s name attribute.
    docShell.QueryInterface(Ci.nsIDocShellTreeItem).name =
      sendSyncMsg('get-name')[0];

    docShell.setFullscreenAllowed(sendSyncMsg('get-fullscreen-allowed')[0]);

    BrowserElementPromptService.mapWindowToBrowserElementChild(content, this);

    docShell.QueryInterface(Ci.nsIWebProgress)
            .addProgressListener(this._progressListener,
                                 Ci.nsIWebProgress.NOTIFY_LOCATION |
                                 Ci.nsIWebProgress.NOTIFY_SECURITY |
                                 Ci.nsIWebProgress.NOTIFY_STATE_WINDOW);

    docShell.QueryInterface(Ci.nsIWebNavigation)
            .sessionHistory = Cc["@mozilla.org/browser/shistory;1"]
                                .createInstance(Ci.nsISHistory);

    // This is necessary to get security web progress notifications.
    var securityUI = Cc['@mozilla.org/secure_browser_ui;1']
                       .createInstance(Ci.nsISecureBrowserUI);
    securityUI.init(content);

    // A cache of the menuitem dom objects keyed by the id we generate
    // and pass to the embedder
    this._ctxHandlers = {};
    // Counter of contextmenu events fired
    this._ctxCounter = 0;

    addEventListener('DOMTitleChanged',
                     this._titleChangedHandler.bind(this),
                     /* useCapture = */ true,
                     /* wantsUntrusted = */ false);

    addEventListener('DOMLinkAdded',
                     this._iconChangedHandler.bind(this),
                     /* useCapture = */ true,
                     /* wantsUntrusted = */ false);

    // Registers a MozAfterPaint handler for the very first paint.
    this._addMozAfterPaintHandler(function () {
      sendAsyncMsg('firstpaint');
    });

    var self = this;
    function addMsgListener(msg, handler) {
      addMessageListener('browser-element-api:' + msg, handler.bind(self));
    }

    addMsgListener("purge-history", this._recvPurgeHistory);
    addMsgListener("get-screenshot", this._recvGetScreenshot);
    addMsgListener("set-visible", this._recvSetVisible);
    addMsgListener("send-mouse-event", this._recvSendMouseEvent);
    addMsgListener("send-touch-event", this._recvSendTouchEvent);
    addMsgListener("get-can-go-back", this._recvCanGoBack);
    addMsgListener("get-can-go-forward", this._recvCanGoForward);
    addMsgListener("go-back", this._recvGoBack);
    addMsgListener("go-forward", this._recvGoForward);
    addMsgListener("reload", this._recvReload);
    addMsgListener("stop", this._recvStop);
    addMsgListener("unblock-modal-prompt", this._recvStopWaiting);
    addMsgListener("fire-ctx-callback", this._recvFireCtxCallback);
    addMsgListener("owner-visibility-change", this._recvOwnerVisibilityChange);
    addMsgListener("exit-fullscreen", this._recvExitFullscreen.bind(this));
    addMsgListener("activate-next-paint-listener", this._activateNextPaintListener.bind(this));
    addMsgListener("deactivate-next-paint-listener", this._deactivateNextPaintListener.bind(this));

    let els = Cc["@mozilla.org/eventlistenerservice;1"]
                .getService(Ci.nsIEventListenerService);

    // We are using the system group for those events so if something in the
    // content called .stopPropagation() this will still be called.
    els.addSystemEventListener(global, 'keydown',
                               this._keyEventHandler.bind(this),
                               /* useCapture = */ true);
    els.addSystemEventListener(global, 'keypress',
                               this._keyEventHandler.bind(this),
                               /* useCapture = */ true);
    els.addSystemEventListener(global, 'keyup',
                               this._keyEventHandler.bind(this),
                               /* useCapture = */ true);
    els.addSystemEventListener(global, 'DOMWindowClose',
                               this._closeHandler.bind(this),
                               /* useCapture = */ false);
    els.addSystemEventListener(global, 'contextmenu',
                               this._contextmenuHandler.bind(this),
                               /* useCapture = */ false);
    els.addSystemEventListener(global, 'scroll',
                               this._scrollEventHandler.bind(this),
                               /* useCapture = */ false);

    Services.obs.addObserver(this,
                             "fullscreen-origin-change",
                             /* ownsWeak = */ true);

    Services.obs.addObserver(this,
                             'ask-parent-to-exit-fullscreen',
                             /* ownsWeak = */ true);

    Services.obs.addObserver(this,
                             'ask-parent-to-rollback-fullscreen',
                             /* ownsWeak = */ true);
  },

  observe: function(subject, topic, data) {
    // Ignore notifications not about our document.
    if (subject != content.document)
      return;
    switch (topic) {
      case 'fullscreen-origin-change':
        sendAsyncMsg('fullscreen-origin-change', data);
        break;
      case 'ask-parent-to-exit-fullscreen':
        sendAsyncMsg('exit-fullscreen');
        break;
      case 'ask-parent-to-rollback-fullscreen':
        sendAsyncMsg('rollback-fullscreen');
        break;
    }
  },

  _tryGetInnerWindowID: function(win) {
    let utils = win.QueryInterface(Ci.nsIInterfaceRequestor)
                   .getInterface(Ci.nsIDOMWindowUtils);
    try {
      return utils.currentInnerWindowID;
    }
    catch(e) {
      return null;
    }
  },

  /**
   * Show a modal prompt.  Called by BrowserElementPromptService.
   */
  showModalPrompt: function(win, args) {
    let utils = win.QueryInterface(Ci.nsIInterfaceRequestor)
                   .getInterface(Ci.nsIDOMWindowUtils);

    args.windowID = { outer: utils.outerWindowID,
                      inner: this._tryGetInnerWindowID(win) };
    sendAsyncMsg('showmodalprompt', args);

    let returnValue = this._waitForResult(win);

    if (args.promptType == 'prompt' ||
        args.promptType == 'confirm' ||
        args.promptType == 'custom-prompt') {
      return returnValue;
    }
  },

  /**
   * Spin in a nested event loop until we receive a unblock-modal-prompt message for
   * this window.
   */
  _waitForResult: function(win) {
    debug("_waitForResult(" + win + ")");
    let utils = win.QueryInterface(Ci.nsIInterfaceRequestor)
                   .getInterface(Ci.nsIDOMWindowUtils);

    let outerWindowID = utils.outerWindowID;
    let innerWindowID = this._tryGetInnerWindowID(win);
    if (innerWindowID === null) {
      // I have no idea what waiting for a result means when there's no inner
      // window, so let's just bail.
      debug("_waitForResult: No inner window. Bailing.");
      return;
    }

    this._windowIDDict[outerWindowID] = Cu.getWeakReference(win);

    debug("Entering modal state (outerWindowID=" + outerWindowID + ", " +
                                "innerWindowID=" + innerWindowID + ")");

    // In theory, we're supposed to pass |modalStateWin| back to
    // leaveModalStateWithWindow.  But in practice, the window is always null,
    // because it's the window associated with this script context, which
    // doesn't have a window.  But we'll play along anyway in case this
    // changes.
    var modalStateWin = utils.enterModalStateWithWindow();

    // We'll decrement win.modalDepth when we receive a unblock-modal-prompt message
    // for the window.
    if (!win.modalDepth) {
      win.modalDepth = 0;
    }
    win.modalDepth++;
    let origModalDepth = win.modalDepth;

    let thread = Services.tm.currentThread;
    debug("Nested event loop - begin");
    while (win.modalDepth == origModalDepth) {
      // Bail out of the loop if the inner window changed; that means the
      // window navigated.
      if (this._tryGetInnerWindowID(win) !== innerWindowID) {
        debug("_waitForResult: Inner window ID changed " +
              "while in nested event loop.");
        break;
      }

      thread.processNextEvent(/* mayWait = */ true);
    }
    debug("Nested event loop - finish");

    // If we exited the loop because the inner window changed, then bail on the
    // modal prompt.
    if (innerWindowID !== this._tryGetInnerWindowID(win)) {
      throw Components.Exception("Modal state aborted by navigation",
                                 Cr.NS_ERROR_NOT_AVAILABLE);
    }

    let returnValue = win.modalReturnValue;
    delete win.modalReturnValue;

    utils.leaveModalStateWithWindow(modalStateWin);

    debug("Leaving modal state (outerID=" + outerWindowID + ", " +
                               "innerID=" + innerWindowID + ")");
    return returnValue;
  },

  _recvStopWaiting: function(msg) {
    let outerID = msg.json.windowID.outer;
    let innerID = msg.json.windowID.inner;
    let returnValue = msg.json.returnValue;
    debug("recvStopWaiting(outer=" + outerID + ", inner=" + innerID +
          ", returnValue=" + returnValue + ")");

    if (!this._windowIDDict[outerID]) {
      debug("recvStopWaiting: No record of outer window ID " + outerID);
      return;
    }

    let win = this._windowIDDict[outerID].get();
    delete this._windowIDDict[outerID];

    if (!win) {
      debug("recvStopWaiting, but window is gone\n");
      return;
    }

    if (innerID !== this._tryGetInnerWindowID(win)) {
      debug("recvStopWaiting, but inner ID has changed\n");
      return;
    }

    debug("recvStopWaiting " + win);
    win.modalReturnValue = returnValue;
    win.modalDepth--;
  },

  _recvExitFullscreen: function() {
    var utils = content.document.defaultView
                       .QueryInterface(Ci.nsIInterfaceRequestor)
                       .getInterface(Ci.nsIDOMWindowUtils);
    utils.exitFullscreen();
  },

  _titleChangedHandler: function(e) {
    debug("Got titlechanged: (" + e.target.title + ")");
    var win = e.target.defaultView;

    // Ignore titlechanges which don't come from the top-level
    // <iframe mozbrowser> window.
    if (win == content) {
      sendAsyncMsg('titlechange', e.target.title);
    }
    else {
      debug("Not top level!");
    }
  },

  _iconChangedHandler: function(e) {
    debug("Got iconchanged: (" + e.target.href + ")");
    var hasIcon = e.target.rel.split(' ').some(function(x) {
      return x.toLowerCase() === 'icon';
    });

    if (hasIcon) {
      var win = e.target.ownerDocument.defaultView;
      // Ignore iconchanges which don't come from the top-level
      // <iframe mozbrowser> window.
      if (win == content) {
        sendAsyncMsg('iconchange', e.target.href);
      }
      else {
        debug("Not top level!");
      }
    }
  },

  _addMozAfterPaintHandler: function(callback) {
    function onMozAfterPaint() {
      let uri = docShell.QueryInterface(Ci.nsIWebNavigation).currentURI;
      debug("Got afterpaint event: " + uri.spec);
      if (uri.spec != "about:blank") {
        removeEventListener('MozAfterPaint', onMozAfterPaint,
                            /* useCapture = */ true);
        callback();
      }
    }

    addEventListener('MozAfterPaint', onMozAfterPaint, /* useCapture = */ true);
    return onMozAfterPaint;
  },

  _removeMozAfterPaintHandler: function(listener) {
    removeEventListener('MozAfterPaint', listener,
                        /* useCapture = */ true);
  },

  _activateNextPaintListener: function(e) {
    if (!this._nextPaintHandler) {
      this._nextPaintHandler = this._addMozAfterPaintHandler(function () {
        this._nextPaintHandler = null;
        sendAsyncMsg('nextpaint');
      }.bind(this));
    }
  },

  _deactivateNextPaintListener: function(e) {
    if (this._nextPaintHandler) {
      this._removeMozAfterPaintHandler(this._nextPaintHandler);
      this._nextPaintHandler = null;
    }
  },

  _closeHandler: function(e) {
    let win = e.target;
    if (win != content || e.defaultPrevented) {
      return;
    }

    debug("Closing window " + win);
    sendAsyncMsg('close');

    // Inform the window implementation that we handled this close ourselves.
    e.preventDefault();
  },

  _contextmenuHandler: function(e) {
    debug("Got contextmenu");

    if (e.defaultPrevented) {
      return;
    }

    e.preventDefault();

    this._ctxCounter++;
    this._ctxHandlers = {};

    var elem = e.target;
    var menuData = {systemTargets: [], contextmenu: null};
    var ctxMenuId = null;

    while (elem && elem.parentNode) {
      var ctxData = this._getSystemCtxMenuData(elem);
      if (ctxData) {
        menuData.systemTargets.push({
          nodeName: elem.nodeName,
          data: ctxData
        });
      }

      if (!ctxMenuId && 'hasAttribute' in elem && elem.hasAttribute('contextmenu')) {
        ctxMenuId = elem.getAttribute('contextmenu');
      }
      elem = elem.parentNode;
    }

    if (ctxMenuId) {
      var menu = e.target.ownerDocument.getElementById(ctxMenuId);
      if (menu) {
        menuData.contextmenu = this._buildMenuObj(menu, '');
      }
    }
    sendAsyncMsg('contextmenu', menuData);
  },

  _getSystemCtxMenuData: function(elem) {
    if ((elem instanceof Ci.nsIDOMHTMLAnchorElement && elem.href) ||
        (elem instanceof Ci.nsIDOMHTMLAreaElement && elem.href)) {
      return elem.href;
    }
    if (elem instanceof Ci.nsIImageLoadingContent && elem.currentURI) {
      return elem.currentURI.spec;
    }
    if ((elem instanceof Ci.nsIDOMHTMLMediaElement) ||
        (elem instanceof Ci.nsIDOMHTMLImageElement)) {
      return elem.currentSrc || elem.src;
    }
    return false;
  },

  _scrollEventHandler: function(e) {
    let win = e.target.defaultView;
    if (win != content) {
      return;
    }

    debug("scroll event " + win);
    sendAsyncMsg("scroll", { top: win.scrollY, left: win.scrollX });
  },

  _recvPurgeHistory: function(data) {
    debug("Received purgeHistory message: (" + data.json.id + ")");

    let history = docShell.QueryInterface(Ci.nsIWebNavigation).sessionHistory;

    try {
      if (history && history.count) {
        history.PurgeHistory(history.count);
      }
    } catch(e) {}

    sendAsyncMsg('got-purge-history', { id: data.json.id, successRv: true });
  },

  _recvGetScreenshot: function(data) {
    debug("Received getScreenshot message: (" + data.json.id + ")");

    let self = this;
    let maxWidth = data.json.args.width;
    let maxHeight = data.json.args.height;
    let domRequestID = data.json.id;

    let takeScreenshotClosure = function() {
      self._takeScreenshot(maxWidth, maxHeight, domRequestID);
    };

    let maxDelayMS = 2000;
    try {
      maxDelayMS = Services.prefs.getIntPref('dom.browserElement.maxScreenshotDelayMS');
    }
    catch(e) {}

    // Try to wait for the event loop to go idle before we take the screenshot,
    // but once we've waited maxDelayMS milliseconds, go ahead and take it
    // anyway.
    Cc['@mozilla.org/message-loop;1'].getService(Ci.nsIMessageLoop).postIdleTask(
      takeScreenshotClosure, maxDelayMS);
  },

  /**
   * Actually take a screenshot and foward the result up to our parent, given
   * the desired maxWidth and maxHeight, and given the DOMRequest ID associated
   * with the request from the parent.
   */
  _takeScreenshot: function(maxWidth, maxHeight, domRequestID) {
    // You can think of the screenshotting algorithm as carrying out the
    // following steps:
    //
    // - Let scaleWidth be the factor by which we'd need to downscale the
    //   viewport so it would fit within maxWidth.  (If the viewport's width
    //   is less than maxWidth, let scaleWidth be 1.) Compute scaleHeight
    //   the same way.
    //
    // - Scale the viewport by max(scaleWidth, scaleHeight).  Now either the
    //   viewport's width is no larger than maxWidth, the viewport's height is
    //   no larger than maxHeight, or both.
    //
    // - Crop the viewport so its width is no larger than maxWidth and its
    //   height is no larger than maxHeight.
    //
    // - Return a screenshot of the page's viewport scaled and cropped per
    //   above.
    debug("Taking a screenshot: maxWidth=" + maxWidth +
          ", maxHeight=" + maxHeight +
          ", domRequestID=" + domRequestID + ".");

    let scaleWidth = Math.min(1, maxWidth / content.innerWidth);
    let scaleHeight = Math.min(1, maxHeight / content.innerHeight);

    let scale = Math.max(scaleWidth, scaleHeight);

    let canvasWidth = Math.min(maxWidth, Math.round(content.innerWidth * scale));
    let canvasHeight = Math.min(maxHeight, Math.round(content.innerHeight * scale));

    var canvas = content.document
      .createElementNS("http://www.w3.org/1999/xhtml", "canvas");
    canvas.mozOpaque = true;
    canvas.width = canvasWidth;
    canvas.height = canvasHeight;

    var ctx = canvas.getContext("2d");
    ctx.scale(scale, scale);
    ctx.drawWindow(content, 0, 0, content.innerWidth, content.innerHeight,
                   "rgb(255,255,255)");

    // Take a JPEG screenshot to hack around the fact that we can't specify
    // opaque PNG.  This requires us to unpremultiply the alpha channel, which
    // is expensive on ARM processors because they lack a hardware integer
    // division instruction.
    canvas.toBlob(function(blob) {
      sendAsyncMsg('got-screenshot', {
        id: domRequestID,
        successRv: blob
      });
    }, 'image/jpeg');
  },

  _recvFireCtxCallback: function(data) {
    debug("Received fireCtxCallback message: (" + data.json.menuitem + ")");
    // We silently ignore if the embedder uses an incorrect id in the callback
    if (data.json.menuitem in this._ctxHandlers) {
      this._ctxHandlers[data.json.menuitem].click();
      this._ctxHandlers = {};
    } else {
      debug("Ignored invalid contextmenu invocation");
    }
  },

  _buildMenuObj: function(menu, idPrefix) {
    function maybeCopyAttribute(src, target, attribute) {
      if (src.getAttribute(attribute)) {
        target[attribute] = src.getAttribute(attribute);
      }
    }

    var menuObj = {type: 'menu', items: []};
    maybeCopyAttribute(menu, menuObj, 'label');

    for (var i = 0, child; child = menu.children[i++];) {
      if (child.nodeName === 'MENU') {
        menuObj.items.push(this._buildMenuObj(child, idPrefix + i + '_'));
      } else if (child.nodeName === 'MENUITEM') {
        var id = this._ctxCounter + '_' + idPrefix + i;
        var menuitem = {id: id, type: 'menuitem'};
        maybeCopyAttribute(child, menuitem, 'label');
        maybeCopyAttribute(child, menuitem, 'icon');
        this._ctxHandlers[id] = child;
        menuObj.items.push(menuitem);
      }
    }
    return menuObj;
  },

  _recvSetVisible: function(data) {
    debug("Received setVisible message: (" + data.json.visible + ")");
    this._forcedVisible = data.json.visible;
    this._updateDocShellVisibility();
  },

  /**
   * Called when the window which contains this iframe becomes hidden or
   * visible.
   */
  _recvOwnerVisibilityChange: function(data) {
    debug("Received ownerVisibilityChange: (" + data.json.visible + ")");
    this._ownerVisible = data.json.visible;
    this._updateDocShellVisibility();
  },

  _updateDocShellVisibility: function() {
    var visible = this._forcedVisible && this._ownerVisible;
    if (docShell.isActive !== visible) {
      docShell.isActive = visible;
    }
  },

  _recvSendMouseEvent: function(data) {
    let json = data.json;
    let utils = content.QueryInterface(Ci.nsIInterfaceRequestor)
                       .getInterface(Ci.nsIDOMWindowUtils);
    utils.sendMouseEvent(json.type, json.x, json.y, json.button,
                         json.clickCount, json.modifiers);
  },

  _recvSendTouchEvent: function(data) {
    let json = data.json;
    let utils = content.QueryInterface(Ci.nsIInterfaceRequestor)
                       .getInterface(Ci.nsIDOMWindowUtils);
    utils.sendTouchEvent(json.type, json.identifiers, json.touchesX,
                         json.touchesY, json.radiisX, json.radiisY,
                         json.rotationAngles, json.forces, json.count,
                         json.modifiers);
  },

  _recvCanGoBack: function(data) {
    var webNav = docShell.QueryInterface(Ci.nsIWebNavigation);
    sendAsyncMsg('got-can-go-back', {
      id: data.json.id,
      successRv: webNav.canGoBack
    });
  },

  _recvCanGoForward: function(data) {
    var webNav = docShell.QueryInterface(Ci.nsIWebNavigation);
    sendAsyncMsg('got-can-go-forward', {
      id: data.json.id,
      successRv: webNav.canGoForward
    });
  },

  _recvGoBack: function(data) {
    try {
      docShell.QueryInterface(Ci.nsIWebNavigation).goBack();
    } catch(e) {
      // Silently swallow errors; these happen when we can't go back.
    }
  },

  _recvGoForward: function(data) {
    try {
      docShell.QueryInterface(Ci.nsIWebNavigation).goForward();
    } catch(e) {
      // Silently swallow errors; these happen when we can't go forward.
    }
  },

  _recvReload: function(data) {
    let webNav = docShell.QueryInterface(Ci.nsIWebNavigation);
    let reloadFlags = data.json.hardReload ?
      webNav.LOAD_FLAGS_BYPASS_PROXY | webNav.LOAD_FLAGS_BYPASS_CACHE :
      webNav.LOAD_FLAGS_NONE;
    try {
      webNav.reload(reloadFlags);
    } catch(e) {
      // Silently swallow errors; these can happen if a used cancels reload
    }
  },

  _recvStop: function(data) {
    let webNav = docShell.QueryInterface(Ci.nsIWebNavigation);
    webNav.stop(webNav.STOP_NETWORK);
  },

  _keyEventHandler: function(e) {
    if (whitelistedEvents.indexOf(e.keyCode) != -1 && !e.defaultPrevented) {
      sendAsyncMsg('keyevent', {
        type: e.type,
        keyCode: e.keyCode,
        charCode: e.charCode,
      });
    }
  },

  // The docShell keeps a weak reference to the progress listener, so we need
  // to keep a strong ref to it ourselves.
  _progressListener: {
    QueryInterface: XPCOMUtils.generateQI([Ci.nsIWebProgressListener,
                                           Ci.nsISupportsWeakReference]),
    _seenLoadStart: false,

    onLocationChange: function(webProgress, request, location, flags) {
      // We get progress events from subshells here, which is kind of weird.
      if (webProgress != docShell) {
        return;
      }

      // Ignore locationchange events which occur before the first loadstart.
      // These are usually about:blank loads we don't care about.
      if (!this._seenLoadStart) {
        return;
      }

      // Remove password and wyciwyg from uri.
      location = Cc["@mozilla.org/docshell/urifixup;1"]
        .getService(Ci.nsIURIFixup).createExposableURI(location);

      sendAsyncMsg('locationchange', location.spec);
    },

    onStateChange: function(webProgress, request, stateFlags, status) {
      if (webProgress != docShell) {
        return;
      }

      if (stateFlags & Ci.nsIWebProgressListener.STATE_START) {
        this._seenLoadStart = true;
        sendAsyncMsg('loadstart');
      }

      if (stateFlags & Ci.nsIWebProgressListener.STATE_STOP) {
        sendAsyncMsg('loadend');

        // Ignoring NS_BINDING_ABORTED, which is set when loading page is
        // stopped.
        if (status == Cr.NS_OK ||
            status == Cr.NS_BINDING_ABORTED) {
          return;
        }

        // TODO See nsDocShell::DisplayLoadError for a list of all the error
        // codes (the status param) we should eventually handle here.
        sendAsyncMsg('error', {type: 'other'});
      }
    },

    onSecurityChange: function(webProgress, request, state) {
      if (webProgress != docShell) {
        return;
      }

      var stateDesc;
      if (state & Ci.nsIWebProgressListener.STATE_IS_SECURE) {
        stateDesc = 'secure';
      }
      else if (state & Ci.nsIWebProgressListener.STATE_IS_BROKEN) {
        stateDesc = 'broken';
      }
      else if (state & Ci.nsIWebProgressListener.STATE_IS_INSECURE) {
        stateDesc = 'insecure';
      }
      else {
        debug("Unexpected securitychange state!");
        stateDesc = '???';
      }

      // XXX Until bug 764496 is fixed, this will always return false.
      var isEV = !!(state & Ci.nsIWebProgressListener.STATE_IDENTITY_EV_TOPLEVEL);

      sendAsyncMsg('securitychange', {state: stateDesc, extendedValidation: isEV});
    },

    onStatusChange: function(webProgress, request, status, message) {},
    onProgressChange: function(webProgress, request, curSelfProgress,
                               maxSelfProgress, curTotalProgress, maxTotalProgress) {},
  },

  // Expose the message manager for WebApps and others.
  _messageManagerPublic: {
    sendAsyncMessage: global.sendAsyncMessage.bind(global),
    sendSyncMessage: global.sendSyncMessage.bind(global),
    addMessageListener: global.addMessageListener.bind(global),
    removeMessageListener: global.removeMessageListener.bind(global)
  },

  get messageManager() {
    return this._messageManagerPublic;
  }
};

var api = new BrowserElementChild();

// FIXME/bug 775438: use a JSM?
//
// The code in this included file depends on the |addEventListener|,
// |addMessageListener|, |content|, |Geometry| and |Services| symbols
// being "exported" from here.
/* -*- Mode: Java; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=2 sw=2 sts=2 et: */

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

const ContentPanning = {
  // Are we listening to touch or mouse events?
  watchedEventsType: '',

  // Are mouse events being delivered to this content along with touch
  // events, in violation of spec?
  hybridEvents: false,

  init: function cp_init() {
    var events;
    try {
      content.document.createEvent('TouchEvent');
      events = ['touchstart', 'touchend', 'touchmove'];
      this.watchedEventsType = 'touch';
//@line 32 "/home/txema/work/firefox-20.0+build1/dom/browser-element/BrowserElementScrolling.js"
    } catch(e) {
      // Touch events aren't supported, so fall back on mouse.
      events = ['mousedown', 'mouseup', 'mousemove'];
      this.watchedEventsType = 'mouse';
    }
    events.forEach(function(type) {
      addEventListener(type, ContentPanning, false);
    });

    addMessageListener("Viewport:Change", this._recvViewportChange.bind(this));
    addMessageListener("Gesture:DoubleTap", this._recvDoubleTap.bind(this));
  },

  handleEvent: function cp_handleEvent(evt) {
    if (evt.defaultPrevented)
      return;

    switch (evt.type) {
      case 'mousedown':
      case 'touchstart':
        this.onTouchStart(evt);
        break;
      case 'mousemove':
      case 'touchmove':
        this.onTouchMove(evt);
        break;
      case 'mouseup':
      case 'touchend':
        this.onTouchEnd(evt);
        break;
      case 'click':
        evt.stopPropagation();
        evt.preventDefault();

        let target = evt.target;
        let view = target.ownerDocument ? target.ownerDocument.defaultView
                                        : target;
        view.removeEventListener('click', this, true, true);
        break;
    }
  },

  position: new Point(0 , 0),

  findPrimaryPointer: function cp_findPrimaryPointer(touches) {
    if (!('primaryPointerId' in this))
      return null;

    for (let i = 0; i < touches.length; i++) {
      if (touches[i].identifier === this.primaryPointerId) {
        return touches[i];
      }
    }
    return null;
  },

  onTouchStart: function cp_onTouchStart(evt) {
    let screenX, screenY;
    if (this.watchedEventsType == 'touch') {
      if ('primaryPointerId' in this) {
        return;
      }

      let firstTouch = evt.changedTouches[0];
      this.primaryPointerId = firstTouch.identifier;
      this.pointerDownTarget = firstTouch.target;
      screenX = firstTouch.screenX;
      screenY = firstTouch.screenY;
    } else {
      this.pointerDownTarget = evt.target;
      screenX = evt.screenX;
      screenY = evt.screenY;
    }
    this.dragging = true;
    this.panning = false;

    let oldTarget = this.target;
    [this.target, this.scrollCallback] = this.getPannable(this.pointerDownTarget);

    // If we found a target, that means we have found a scrollable subframe. In
    // this case, and if we are using async panning and zooming on the parent
    // frame, inform the pan/zoom controller that it should not attempt to
    // handle any touch events it gets until the next batch (meaning the next
    // time we get a touch end).
    if (this.target != null && this._asyncPanZoomForViewportFrame) {
      this.detectingScrolling = true;
      var os = Cc["@mozilla.org/observer-service;1"].getService(Ci.nsIObserverService);
      os.notifyObservers(docShell, 'detect-scrollable-subframe', null);
    }

    // If we have a pointer down target and we're not async
    // pan/zooming, we may need to fill in for EventStateManager in
    // setting the active state on the target element.  Set a timer to
    // ensure the pointer-down target is active.  (If it's already
    // active, the timer is a no-op.)
    if (this.pointerDownTarget !== null && !this.detectingScrolling) {
      // If there's no possibility this is a drag/pan, activate now.
      // Otherwise wait a little bit to see if the gesture isn't a
      // tap.
      if (this.target === null) {
        this.notify(this._activationTimer);
      } else {
        this._activationTimer.initWithCallback(this,
                                               this._activationDelayMs,
                                               Ci.nsITimer.TYPE_ONE_SHOT);
      }
    }

    // If there is a pan animation running (from a previous pan gesture) and
    // the user touch back the screen, stop this animation immediatly and
    // prevent the possible click action if the touch happens on the same
    // target.
    this.preventNextClick = false;
    if (KineticPanning.active) {
      KineticPanning.stop();

      if (oldTarget && oldTarget == this.target)
        this.preventNextClick = true;
    }

    this.position.set(screenX, screenY);
    KineticPanning.record(new Point(0, 0), evt.timeStamp);
  },

  onTouchEnd: function cp_onTouchEnd(evt) {
    let touch = null;
    if (!this.dragging ||
        (this.watchedEventsType == 'touch' &&
         !(touch = this.findPrimaryPointer(evt.changedTouches)))) {
      return;
    }

    // !isPan() and evt.detail should always give the same answer here
    // since they use the same heuristics, but use the native gecko
    // computation when possible.
    //
    // NB: when we're using touch events, then !KineticPanning.isPan()
    // => this.panning, so we'll never attempt to block the click
    // event.  That's OK however, because we won't fire a synthetic
    // click when we're using touch events and this touch series
    // wasn't a "tap" gesture.
    let click = (this.watchedEventsType == 'mouse') ?
      evt.detail : !KineticPanning.isPan();
    // Additionally, if we're seeing non-compliant hybrid events, a
    // "real" click will be generated if we started and ended on the
    // same element.
    if (this.hybridEvents) {
      let target =
        content.document.elementFromPoint(touch.clientX, touch.clientY);
      click |= (target === this.pointerDownTarget);
    }

    if (this.target && click && (this.panning || this.preventNextClick)) {
      let target = this.target;
      let view = target.ownerDocument ? target.ownerDocument.defaultView
                                      : target;
      view.addEventListener('click', this, true, true);
    }

    this._resetActive();
    this.dragging = false;
    this.detectingScrolling = false;
    delete this.primaryPointerId;
    this._activationTimer.cancel();

    if (this.panning) {
      KineticPanning.start(this);
    }
  },

  // True when there's an async pan-zoom controll watching the
  // outermost scrollable frame, and we're waiting to see whether
  // we're going to take over from it and synchronously scroll an
  // inner scrollable frame.
  detectingScrolling: false,

  onTouchMove: function cp_onTouchMove(evt) {
    if (!this.dragging)
      return;

    let screenX, screenY;
    if (this.watchedEventsType == 'touch') {
      let primaryTouch = this.findPrimaryPointer(evt.changedTouches);
      if (evt.touches.length > 1 || !primaryTouch)
        return;
      screenX = primaryTouch.screenX;
      screenY = primaryTouch.screenY;
    } else {
      screenX = evt.screenX;
      screenY = evt.screenY;
    }

    let current = this.position;
    let delta = new Point(screenX - current.x, screenY - current.y);
    current.set(screenX, screenY);

    KineticPanning.record(delta, evt.timeStamp);

    // There's no possibility of us panning anything.
    if (!this.scrollCallback) {
      return;
    }

    let isPan = KineticPanning.isPan();
    if (this.detectingScrolling) {
      this.detectingScrolling = false;
      // Stop async-pan-zooming if the user is panning the subframe.
      if (isPan) {
        // We're going to drive synchronously scrolling an inner frame.
        Services.obs.notifyObservers(docShell, 'cancel-default-pan-zoom', null);
      } else {
        // Let AsyncPanZoomController handle the scrolling gesture.
        this.scrollCallback = null;
        return;
      }
    }

    this.scrollCallback(delta.scale(-1));

    // If a pan action happens, cancel the active state of the
    // current target.
    if (!this.panning && isPan) {
      this.panning = true;
      this._resetActive();
      this._activationTimer.cancel();
    }

    if (this.panning) {
      evt.stopPropagation();
      evt.preventDefault();
    }
  },

  // nsITimerCallback
  notify: function cp_notify(timer) {
    this._setActive(this.pointerDownTarget);
  },

  onKineticBegin: function cp_onKineticBegin(evt) {
  },

  onKineticPan: function cp_onKineticPan(delta) {
    return !this.scrollCallback(delta);
  },

  onKineticEnd: function cp_onKineticEnd() {
    if (!this.dragging)
      this.scrollCallback = null;
  },

  getPannable: function cp_getPannable(node) {
    let pannableNode = this._findPannable(node);
    if (pannableNode) {
      return [pannableNode, this._generateCallback(pannableNode)];
    }

    return [null, null];
  },

  _findPannable: function cp_findPannable(node) {
    if (!(node instanceof Ci.nsIDOMHTMLElement) || node.tagName == 'HTML') {
      return null;
    }

    let nodeContent = node.ownerDocument.defaultView;
    while (!(node instanceof Ci.nsIDOMHTMLBodyElement)) {
      let style = nodeContent.getComputedStyle(node, null);

      let overflow = [style.getPropertyValue('overflow'),
                      style.getPropertyValue('overflow-x'),
                      style.getPropertyValue('overflow-y')];

      let rect = node.getBoundingClientRect();
      let isAuto = (overflow.indexOf('auto') != -1 &&
                   (rect.height < node.scrollHeight ||
                    rect.width < node.scrollWidth));

      let isScroll = (overflow.indexOf('scroll') != -1);

      let isScrollableTextarea = (node.tagName == 'TEXTAREA' &&
          (node.scrollHeight > node.clientHeight ||
           node.scrollWidth > node.clientWidth ||
           ('scrollLeftMax' in node && node.scrollLeftMax > 0) ||
           ('scrollTopMax' in node && node.scrollTopMax > 0)));
      if (isScroll || isAuto || isScrollableTextarea) {
        return node;
      }

      node = node.parentNode;
    }

    if (ContentPanning._asyncPanZoomForViewportFrame &&
        nodeContent === content) {
        // The parent context is asynchronously panning and zooming our
        // root scrollable frame, so don't use our synchronous fallback.
        return null;
    }

    if (nodeContent.scrollMaxX || nodeContent.scrollMaxY) {
      return nodeContent;
    }

    return null;
  },

  _generateCallback: function cp_generateCallback(content) {
    let firstScroll = true;
    let target;
    let isScrolling = false;
    let oldX, oldY, newX, newY;
    let win, doc, htmlNode, bodyNode;

    function doScroll(node, delta) {
      if (node instanceof Ci.nsIDOMHTMLElement) {
        oldX = node.scrollLeft, oldY = node.scrollTop;
        node.scrollLeft += delta.x;
        node.scrollTop += delta.y;
        newX = node.scrollLeft, newY = node.scrollTop;
        return (newX != oldX || newY != oldY);
      } else if (node instanceof Ci.nsIDOMWindow) {
        win = node;
        doc = win.document;

        // "overflow:hidden" on either the <html> or the <body> node should
        // prevent the user from scrolling the root viewport.
        if (doc instanceof Ci.nsIDOMHTMLDocument) {
          htmlNode = doc.documentElement;
          bodyNode = doc.body;
          if (win.getComputedStyle(htmlNode, null).overflowX == "hidden" ||
              win.getComputedStyle(bodyNode, null).overflowX == "hidden") {
            delta.x = 0;
          }
          if (win.getComputedStyle(htmlNode, null).overflowY == "hidden" ||
              win.getComputedStyle(bodyNode, null).overflowY == "hidden") {
            delta.y = 0;
          }
        }
        oldX = node.scrollX, oldY = node.scrollY;
        node.scrollBy(delta.x, delta.y);
        newX = node.scrollX, newY = node.scrollY;
        return (newX != oldX || newY != oldY);
      }
      // If we get here, |node| isn't an HTML element and it's not a window,
      // but findPannable apparently thought it was scrollable... What is it?
      return false;
    };

    function scroll(delta) {
      for (target = content; target;
          target = ContentPanning._findPannable(target.parentNode)) {
        isScrolling = doScroll(target, delta);
        if (isScrolling || !firstScroll) {
          break;
        }
      }
      if (isScrolling) {
        if (firstScroll) {
          content = target; // set scrolling target to the first scrolling region
        }
        firstScroll = false; // lockdown the scrolling target after a success scrolling
      }
      return isScrolling;
    }
    return scroll;
  },

  get _domUtils() {
    delete this._domUtils;
    return this._domUtils = Cc['@mozilla.org/inspector/dom-utils;1']
                              .getService(Ci.inIDOMUtils);
  },

  get _activationTimer() {
    delete this._activationTimer;
    return this._activationTimer = Cc["@mozilla.org/timer;1"]
                                     .createInstance(Ci.nsITimer);
  },

  get _activationDelayMs() {
    let delay = Services.prefs.getIntPref('ui.touch_activation.delay_ms');
    delete this._activationDelayMs;
    return this._activationDelayMs = delay;
  },

  _resetActive: function cp_resetActive() {
    let elt = this.target || this.pointerDownTarget;
    let root = elt.ownerDocument || elt.document;
    this._setActive(root.documentElement);
  },

  _setActive: function cp_setActive(elt) {
    const kStateActive = 0x00000001;
    this._domUtils.setContentState(elt, kStateActive);
  },

  get _asyncPanZoomForViewportFrame() {
    return docShell.asyncPanZoomEnabled;
  },

  _recvViewportChange: function(data) {
    let metrics = data.json;
    this._viewport = new Rect(metrics.x, metrics.y,
                              metrics.viewport.width,
                              metrics.viewport.height);
    this._cssCompositedRect = new Rect(metrics.x, metrics.y,
                                       metrics.cssCompositedRect.width,
                                       metrics.cssCompositedRect.height);
    this._cssPageRect = new Rect(metrics.cssPageRect.x,
                                 metrics.cssPageRect.y,
                                 metrics.cssPageRect.width,
                                 metrics.cssPageRect.height);
  },

  _recvDoubleTap: function(data) {
    let data = data.json;

    // We haven't received a metrics update yet; don't do anything.
    if (this._viewport == null) {
      return;
    }

    let win = content;

    let element = ElementTouchHelper.anyElementFromPoint(win, data.x, data.y);
    if (!element) {
      this._zoomOut();
      return;
    }

    while (element && !this._shouldZoomToElement(element))
      element = element.parentNode;

    if (!element) {
      this._zoomOut();
    } else {
      const margin = 15;
      let rect = ElementTouchHelper.getBoundingContentRect(element);

      let cssPageRect = this._cssPageRect;
      let viewport = this._viewport;
      let bRect = new Rect(Math.max(cssPageRect.x, rect.x - margin),
                           rect.y,
                           rect.w + 2 * margin,
                           rect.h);
      // constrict the rect to the screen's right edge
      bRect.width = Math.min(bRect.width, cssPageRect.right - bRect.x);

      // if the rect is already taking up most of the visible area and is stretching the
      // width of the page, then we want to zoom out instead.
      if (this._isRectZoomedIn(bRect, this._cssCompositedRect)) {
        this._zoomOut();
        return;
      }

      rect.x = Math.round(bRect.x);
      rect.y = Math.round(bRect.y);
      rect.w = Math.round(bRect.width);
      rect.h = Math.round(bRect.height);

      // if the block we're zooming to is really tall, and the user double-tapped
      // more than a screenful of height from the top of it, then adjust the y-coordinate
      // so that we center the actual point the user double-tapped upon. this prevents
      // flying to the top of a page when double-tapping to zoom in (bug 761721).
      // the 1.2 multiplier is just a little fuzz to compensate for bRect including horizontal
      // margins but not vertical ones.
      let cssTapY = viewport.y + data.y;
      if ((bRect.height > rect.h) && (cssTapY > rect.y + (rect.h * 1.2))) {
        rect.y = cssTapY - (rect.h / 2);
      }

      var os = Cc["@mozilla.org/observer-service;1"].getService(Ci.nsIObserverService);
      os.notifyObservers(docShell, 'browser-zoom-to-rect', JSON.stringify(rect));
    }
  },

  _shouldZoomToElement: function(aElement) {
    let win = aElement.ownerDocument.defaultView;
    if (win.getComputedStyle(aElement, null).display == "inline")
      return false;
    if (aElement instanceof Ci.nsIDOMHTMLLIElement)
      return false;
    if (aElement instanceof Ci.nsIDOMHTMLQuoteElement)
      return false;
    return true;
  },

  _zoomOut: function() {
    let rect = new Rect(0, 0, 0, 0);
    var os = Cc["@mozilla.org/observer-service;1"].getService(Ci.nsIObserverService);
    os.notifyObservers(docShell, 'browser-zoom-to-rect', JSON.stringify(rect));
  },

  _isRectZoomedIn: function(aRect, aViewport) {
    // This function checks to see if the area of the rect visible in the
    // viewport (i.e. the "overlapArea" variable below) is approximately 
    // the max area of the rect we can show.
    let vRect = new Rect(aViewport.x, aViewport.y, aViewport.width, aViewport.height);
    let overlap = vRect.intersect(aRect);
    let overlapArea = overlap.width * overlap.height;
    let availHeight = Math.min(aRect.width * vRect.height / vRect.width, aRect.height);
    let showing = overlapArea / (aRect.width * availHeight);
    let ratioW = (aRect.width / vRect.width);
    let ratioH = (aRect.height / vRect.height);

    return (showing > 0.9 && (ratioW > 0.9 || ratioH > 0.9)); 
  }
};

ContentPanning.init();

// Min/max velocity of kinetic panning. This is in pixels/millisecond.
const kMinVelocity = 0.4;
const kMaxVelocity = 6;

// Constants that affect the "friction" of the scroll pane.
const kExponentialC = 1000;
const kPolynomialC = 100 / 1000000;

// How often do we change the position of the scroll pane?
// Too often and panning may jerk near the end.
// Too little and panning will be choppy. In milliseconds.
const kUpdateInterval = 16;

// The numbers of momentums to use for calculating the velocity of the pan.
// Those are taken from the end of the action
const kSamples = 5;

const KineticPanning = {
  _position: new Point(0, 0),
  _velocity: new Point(0, 0),
  _acceleration: new Point(0, 0),

  get active() {
    return this.target !== null;
  },

  target: null,
  start: function kp_start(target) {
    this.target = target;

    // Calculate the initial velocity of the movement based on user input
    let momentums = this.momentums.slice(-kSamples);

    let distance = new Point(0, 0);
    momentums.forEach(function(momentum) {
      distance.add(momentum.dx, momentum.dy);
    });

    let elapsed = momentums[momentums.length - 1].time - momentums[0].time;

    function clampFromZero(x, min, max) {
      if (x >= 0)
        return Math.max(min, Math.min(max, x));
      return Math.min(-min, Math.max(-max, x));
    }

    let velocityX = clampFromZero(distance.x / elapsed, 0, kMaxVelocity);
    let velocityY = clampFromZero(distance.y / elapsed, 0, kMaxVelocity);

    let velocity = this._velocity;
    velocity.set(Math.abs(velocityX) < kMinVelocity ? 0 : velocityX,
                 Math.abs(velocityY) < kMinVelocity ? 0 : velocityY);
    this.momentums = [];

    // Set acceleration vector to opposite signs of velocity
    function sign(x) {
      return x ? (x > 0 ? 1 : -1) : 0;
    }

    this._acceleration.set(velocity.clone().map(sign).scale(-kPolynomialC));

    // Reset the position
    this._position.set(0, 0);

    this._startAnimation();

    this.target.onKineticBegin();
  },

  stop: function kp_stop() {
    if (!this.target)
      return;

    this.momentums = [];
    this.distance.set(0, 0);

    this.target.onKineticEnd();
    this.target = null;
  },

  momentums: [],
  record: function kp_record(delta, timestamp) {
    this.momentums.push({ 'time': timestamp, 'dx' : delta.x, 'dy' : delta.y });
    this.distance.add(delta.x, delta.y);
  },

  get threshold() {
    let dpi = content.QueryInterface(Ci.nsIInterfaceRequestor)
                     .getInterface(Ci.nsIDOMWindowUtils)
                     .displayDPI;

    let threshold = Services.prefs.getIntPref('ui.dragThresholdX') / 240 * dpi;

    delete this.threshold;
    return this.threshold = threshold;
  },

  distance: new Point(0, 0),
  isPan: function cp_isPan() {
    return (Math.abs(this.distance.x) > this.threshold ||
            Math.abs(this.distance.y) > this.threshold);
  },

  _startAnimation: function kp_startAnimation() {
    let c = kExponentialC;
    function getNextPosition(position, v, a, t) {
      // Important traits for this function:
      //   p(t=0) is 0
      //   p'(t=0) is v0
      //
      // We use exponential to get a smoother stop, but by itself exponential
      // is too smooth at the end. Adding a polynomial with the appropriate
      // weight helps to balance
      position.set(v.x * Math.exp(-t / c) * -c + a.x * t * t + v.x * c,
                   v.y * Math.exp(-t / c) * -c + a.y * t * t + v.y * c);
    }

    let startTime = content.mozAnimationStartTime;
    let elapsedTime = 0, targetedTime = 0, averageTime = 0;

    let velocity = this._velocity;
    let acceleration = this._acceleration;

    let position = this._position;
    let nextPosition = new Point(0, 0);
    let delta = new Point(0, 0);

    let callback = (function(timestamp) {
      if (!this.target)
        return;

      // To make animation end fast enough but to keep smoothness, average the
      // ideal time frame (smooth animation) with the actual time lapse
      // (end fast enough).
      // Animation will never take longer than 2 times the ideal length of time.
      elapsedTime = timestamp - startTime;
      targetedTime += kUpdateInterval;
      averageTime = (targetedTime + elapsedTime) / 2;

      // Calculate new position.
      getNextPosition(nextPosition, velocity, acceleration, averageTime);
      delta.set(Math.round(nextPosition.x - position.x),
                Math.round(nextPosition.y - position.y));

      // Test to see if movement is finished for each component.
      if (delta.x * acceleration.x > 0)
        delta.x = position.x = velocity.x = acceleration.x = 0;

      if (delta.y * acceleration.y > 0)
        delta.y = position.y = velocity.y = acceleration.y = 0;

      if (velocity.equals(0, 0) || delta.equals(0, 0)) {
        this.stop();
        return;
      }

      position.add(delta);
      if (this.target.onKineticPan(delta.scale(-1))) {
        this.stop();
        return;
      }

      content.mozRequestAnimationFrame(callback);
    }).bind(this);

    content.mozRequestAnimationFrame(callback);
  }
};

const ElementTouchHelper = {
  anyElementFromPoint: function(aWindow, aX, aY) {
    let cwu = aWindow.QueryInterface(Ci.nsIInterfaceRequestor).getInterface(Ci.nsIDOMWindowUtils);
    let elem = cwu.elementFromPoint(aX, aY, true, true);

    let HTMLIFrameElement = Ci.nsIDOMHTMLIFrameElement;
    let HTMLFrameElement = Ci.nsIDOMHTMLFrameElement;
    while (elem && (elem instanceof HTMLIFrameElement || elem instanceof HTMLFrameElement)) {
      let rect = elem.getBoundingClientRect();
      aX -= rect.left;
      aY -= rect.top;
      cwu = elem.contentDocument.defaultView.QueryInterface(Ci.nsIInterfaceRequestor).getInterface(Ci.nsIDOMWindowUtils);
      elem = cwu.elementFromPoint(aX, aY, true, true);
    }

    return elem;
  },

  getBoundingContentRect: function(aElement) {
    if (!aElement)
      return {x: 0, y: 0, w: 0, h: 0};

    let document = aElement.ownerDocument;
    while (document.defaultView.frameElement)
      document = document.defaultView.frameElement.ownerDocument;

    let cwu = document.defaultView.QueryInterface(Ci.nsIInterfaceRequestor).getInterface(Ci.nsIDOMWindowUtils);
    let scrollX = {}, scrollY = {};
    cwu.getScrollXY(false, scrollX, scrollY);

    let r = aElement.getBoundingClientRect();

    // step out of iframes and frames, offsetting scroll values
    for (let frame = aElement.ownerDocument.defaultView; frame.frameElement && frame != content; frame = frame.parent) {
      // adjust client coordinates' origin to be top left of iframe viewport
      let rect = frame.frameElement.getBoundingClientRect();
      let left = frame.getComputedStyle(frame.frameElement, "").borderLeftWidth;
      let top = frame.getComputedStyle(frame.frameElement, "").borderTopWidth;
      scrollX.value += rect.left + parseInt(left);
      scrollY.value += rect.top + parseInt(top);
    }

    return {x: r.left + scrollX.value,
            y: r.top + scrollY.value,
            w: r.width,
            h: r.height };
  }
};
