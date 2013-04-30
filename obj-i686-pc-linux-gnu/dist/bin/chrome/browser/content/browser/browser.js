//@line 5 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

let Ci = Components.interfaces;
let Cu = Components.utils;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource:///modules/RecentWindow.jsm");

const nsIWebNavigation = Ci.nsIWebNavigation;

var gCharsetMenu = null;
var gLastBrowserCharset = null;
var gPrevCharset = null;
var gProxyFavIcon = null;
var gLastValidURLStr = "";
var gInPrintPreviewMode = false;
var gContextMenu = null; // nsContextMenu instance

//@line 23 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
var gEditUIVisible = true;
//@line 25 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

[
  ["gBrowser",            "content"],
  ["gNavToolbox",         "navigator-toolbox"],
  ["gURLBar",             "urlbar"],
  ["gNavigatorBundle",    "bundle_browser"]
].forEach(function (elementGlobal) {
  var [name, id] = elementGlobal;
  window.__defineGetter__(name, function () {
    var element = document.getElementById(id);
    if (!element)
      return null;
    delete window[name];
    return window[name] = element;
  });
  window.__defineSetter__(name, function (val) {
    delete window[name];
    return window[name] = val;
  });
});

// Smart getter for the findbar.  If you don't wish to force the creation of
// the findbar, check gFindBarInitialized first.
var gFindBarInitialized = false;
XPCOMUtils.defineLazyGetter(window, "gFindBar", function() {
  let XULNS = "http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul";
  let findbar = document.createElementNS(XULNS, "findbar");
  findbar.id = "FindToolbar";

  let browserBottomBox = document.getElementById("browser-bottombox");
  browserBottomBox.insertBefore(findbar, browserBottomBox.firstChild);

  // Force a style flush to ensure that our binding is attached.
  findbar.clientTop;
  findbar.browser = gBrowser;
  window.gFindBarInitialized = true;
  return findbar;
});

XPCOMUtils.defineLazyGetter(this, "gPrefService", function() {
  return Services.prefs;
});

__defineGetter__("AddonManager", function() {
  let tmp = {};
  Cu.import("resource://gre/modules/AddonManager.jsm", tmp);
  return this.AddonManager = tmp.AddonManager;
});
__defineSetter__("AddonManager", function (val) {
  delete this.AddonManager;
  return this.AddonManager = val;
});

__defineGetter__("PluralForm", function() {
  Cu.import("resource://gre/modules/PluralForm.jsm");
  return this.PluralForm;
});
__defineSetter__("PluralForm", function (val) {
  delete this.PluralForm;
  return this.PluralForm = val;
});

XPCOMUtils.defineLazyModuleGetter(this, "TelemetryStopwatch",
  "resource://gre/modules/TelemetryStopwatch.jsm");

XPCOMUtils.defineLazyModuleGetter(this, "AboutHomeUtils",
  "resource:///modules/AboutHomeUtils.jsm");

//@line 94 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
XPCOMUtils.defineLazyModuleGetter(this, "Weave",
  "resource://services-sync/main.js");
//@line 97 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

XPCOMUtils.defineLazyGetter(this, "PopupNotifications", function () {
  let tmp = {};
  Cu.import("resource://gre/modules/PopupNotifications.jsm", tmp);
  try {
    return new tmp.PopupNotifications(gBrowser,
                                      document.getElementById("notification-popup"),
                                      document.getElementById("notification-popup-box"));
  } catch (ex) {
    Cu.reportError(ex);
    return null;
  }
});

XPCOMUtils.defineLazyGetter(this, "DeveloperToolbar", function() {
  let tmp = {};
  Cu.import("resource:///modules/devtools/DeveloperToolbar.jsm", tmp);
  return new tmp.DeveloperToolbar(window, document.getElementById("developer-toolbar"));
});

XPCOMUtils.defineLazyGetter(this, "DebuggerUI", function() {
  let tmp = {};
  Cu.import("resource:///modules/devtools/DebuggerUI.jsm", tmp);
  return new tmp.DebuggerUI(window);
});

XPCOMUtils.defineLazyModuleGetter(this, "Social",
  "resource:///modules/Social.jsm");

XPCOMUtils.defineLazyModuleGetter(this, "PageThumbs",
  "resource:///modules/PageThumbs.jsm");

//@line 130 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
XPCOMUtils.defineLazyModuleGetter(this, "SafeBrowsing",
  "resource://gre/modules/SafeBrowsing.jsm");
//@line 133 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

XPCOMUtils.defineLazyModuleGetter(this, "gBrowserNewTabPreloader",
  "resource:///modules/BrowserNewTabPreloader.jsm", "BrowserNewTabPreloader");

XPCOMUtils.defineLazyModuleGetter(this, "PrivateBrowsingUtils",
  "resource://gre/modules/PrivateBrowsingUtils.jsm");

let gInitialPages = [
  "about:blank",
  "about:newtab",
  "about:home",
  "about:privatebrowsing",
  "about:sessionrestore"
];

//@line 5 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-addons.js"

const gXPInstallObserver = {
  _findChildShell: function (aDocShell, aSoughtShell)
  {
    if (aDocShell == aSoughtShell)
      return aDocShell;

    var node = aDocShell.QueryInterface(Components.interfaces.nsIDocShellTreeNode);
    for (var i = 0; i < node.childCount; ++i) {
      var docShell = node.getChildAt(i);
      docShell = this._findChildShell(docShell, aSoughtShell);
      if (docShell == aSoughtShell)
        return docShell;
    }
    return null;
  },

  _getBrowser: function (aDocShell)
  {
    for (let browser of gBrowser.browsers) {
      if (this._findChildShell(browser.docShell, aDocShell))
        return browser;
    }
    return null;
  },

  observe: function (aSubject, aTopic, aData)
  {
    var brandBundle = document.getElementById("bundle_brand");
    var installInfo = aSubject.QueryInterface(Components.interfaces.amIWebInstallInfo);
    var win = installInfo.originatingWindow;
    var shell = win.QueryInterface(Components.interfaces.nsIInterfaceRequestor)
                   .getInterface(Components.interfaces.nsIWebNavigation)
                   .QueryInterface(Components.interfaces.nsIDocShell);
    var browser = this._getBrowser(shell);
    if (!browser)
      return;
    const anchorID = "addons-notification-icon";
    var messageString, action;
    var brandShortName = brandBundle.getString("brandShortName");

    var notificationID = aTopic;
    // Make notifications persist a minimum of 30 seconds
    var options = {
      timeout: Date.now() + 30000
    };

    switch (aTopic) {
    case "addon-install-disabled":
      notificationID = "xpinstall-disabled"

      if (gPrefService.prefIsLocked("xpinstall.enabled")) {
        messageString = gNavigatorBundle.getString("xpinstallDisabledMessageLocked");
        buttons = [];
      }
      else {
        messageString = gNavigatorBundle.getString("xpinstallDisabledMessage");

        action = {
          label: gNavigatorBundle.getString("xpinstallDisabledButton"),
          accessKey: gNavigatorBundle.getString("xpinstallDisabledButton.accesskey"),
          callback: function editPrefs() {
            gPrefService.setBoolPref("xpinstall.enabled", true);
          }
        };
      }

      PopupNotifications.show(browser, notificationID, messageString, anchorID,
                              action, null, options);
      break;
    case "addon-install-blocked":
      messageString = gNavigatorBundle.getFormattedString("xpinstallPromptWarning",
                        [brandShortName, installInfo.originatingURI.host]);

      let secHistogram = Components.classes["@mozilla.org/base/telemetry;1"].getService(Ci.nsITelemetry).getHistogramById("SECURITY_UI");
      action = {
        label: gNavigatorBundle.getString("xpinstallPromptAllowButton"),
        accessKey: gNavigatorBundle.getString("xpinstallPromptAllowButton.accesskey"),
        callback: function() {
          secHistogram.add(Ci.nsISecurityUITelemetry.WARNING_ADDON_ASKING_PREVENTED_CLICK_THROUGH);
          installInfo.install();
        }
      };

      secHistogram.add(Ci.nsISecurityUITelemetry.WARNING_ADDON_ASKING_PREVENTED);
      PopupNotifications.show(browser, notificationID, messageString, anchorID,
                              action, null, options);
      break;
    case "addon-install-started":
      var needsDownload = function needsDownload(aInstall) {
        return aInstall.state != AddonManager.STATE_DOWNLOADED;
      }
      // If all installs have already been downloaded then there is no need to
      // show the download progress
      if (!installInfo.installs.some(needsDownload))
        return;
      notificationID = "addon-progress";
      messageString = gNavigatorBundle.getString("addonDownloading");
      messageString = PluralForm.get(installInfo.installs.length, messageString);
      options.installs = installInfo.installs;
      options.contentWindow = browser.contentWindow;
      options.sourceURI = browser.currentURI;
      options.eventCallback = function(aEvent) {
        if (aEvent != "removed")
          return;
        options.contentWindow = null;
        options.sourceURI = null;
      };
      PopupNotifications.show(browser, notificationID, messageString, anchorID,
                              null, null, options);
      break;
    case "addon-install-failed":
      // TODO This isn't terribly ideal for the multiple failure case
      for (let install of installInfo.installs) {
        let host = (installInfo.originatingURI instanceof Ci.nsIStandardURL) &&
                   installInfo.originatingURI.host;
        if (!host)
          host = (install.sourceURI instanceof Ci.nsIStandardURL) &&
                 install.sourceURI.host;

        let error = (host || install.error == 0) ? "addonError" : "addonLocalError";
        if (install.error != 0)
          error += install.error;
        else if (install.addon.blocklistState == Ci.nsIBlocklistService.STATE_BLOCKED)
          error += "Blocklisted";
        else
          error += "Incompatible";

        messageString = gNavigatorBundle.getString(error);
        messageString = messageString.replace("#1", install.name);
        if (host)
          messageString = messageString.replace("#2", host);
        messageString = messageString.replace("#3", brandShortName);
        messageString = messageString.replace("#4", Services.appinfo.version);

        PopupNotifications.show(browser, notificationID, messageString, anchorID,
                                action, null, options);
      }
      break;
    case "addon-install-complete":
      var needsRestart = installInfo.installs.some(function(i) {
        return i.addon.pendingOperations != AddonManager.PENDING_NONE;
      });

      if (needsRestart) {
        messageString = gNavigatorBundle.getString("addonsInstalledNeedsRestart");
        action = {
          label: gNavigatorBundle.getString("addonInstallRestartButton"),
          accessKey: gNavigatorBundle.getString("addonInstallRestartButton.accesskey"),
          callback: function() {
            Application.restart();
          }
        };
      }
      else {
        messageString = gNavigatorBundle.getString("addonsInstalled");
        action = null;
      }

      messageString = PluralForm.get(installInfo.installs.length, messageString);
      messageString = messageString.replace("#1", installInfo.installs[0].name);
      messageString = messageString.replace("#2", installInfo.installs.length);
      messageString = messageString.replace("#3", brandShortName);

      // Remove notificaion on dismissal, since it's possible to cancel the
      // install through the addons manager UI, making the "restart" prompt
      // irrelevant.
      options.removeOnDismissal = true;

      PopupNotifications.show(browser, notificationID, messageString, anchorID,
                              action, null, options);
      break;
    }
  }
};

/*
 * When addons are installed/uninstalled, check and see if the number of items
 * on the add-on bar changed:
 * - If an add-on was installed, incrementing the count, show the bar.
 * - If an add-on was uninstalled, and no more items are left, hide the bar.
 */
let AddonsMgrListener = {
  get addonBar() document.getElementById("addon-bar"),
  get statusBar() document.getElementById("status-bar"),
  getAddonBarItemCount: function() {
    // Take into account the contents of the status bar shim for the count.
    var itemCount = this.statusBar.childNodes.length;

    var defaultOrNoninteractive = this.addonBar.getAttribute("defaultset")
                                      .split(",")
                                      .concat(["separator", "spacer", "spring"]);
    for (let item of this.addonBar.currentSet.split(",")) {
      if (defaultOrNoninteractive.indexOf(item) == -1)
        itemCount++;
    }

    return itemCount;
  },
  onInstalling: function(aAddon) {
    this.lastAddonBarCount = this.getAddonBarItemCount();
  },
  onInstalled: function(aAddon) {
    if (this.getAddonBarItemCount() > this.lastAddonBarCount)
      setToolbarVisibility(this.addonBar, true);
  },
  onUninstalling: function(aAddon) {
    this.lastAddonBarCount = this.getAddonBarItemCount();
  },
  onUninstalled: function(aAddon) {
    if (this.getAddonBarItemCount() == 0)
      setToolbarVisibility(this.addonBar, false);
  },
  onEnabling: function(aAddon) this.onInstalling(),
  onEnabled: function(aAddon) this.onInstalled(),
  onDisabling: function(aAddon) this.onUninstalling(),
  onDisabled: function(aAddon) this.onUninstalled(),
};


var LightWeightThemeWebInstaller = {
  handleEvent: function (event) {
    switch (event.type) {
      case "InstallBrowserTheme":
      case "PreviewBrowserTheme":
      case "ResetBrowserThemePreview":
        // ignore requests from background tabs
        if (event.target.ownerDocument.defaultView.top != content)
          return;
    }
    switch (event.type) {
      case "InstallBrowserTheme":
        this._installRequest(event);
        break;
      case "PreviewBrowserTheme":
        this._preview(event);
        break;
      case "ResetBrowserThemePreview":
        this._resetPreview(event);
        break;
      case "pagehide":
      case "TabSelect":
        this._resetPreview();
        break;
    }
  },

  get _manager () {
    var temp = {};
    Cu.import("resource://gre/modules/LightweightThemeManager.jsm", temp);
    delete this._manager;
    return this._manager = temp.LightweightThemeManager;
  },

  _installRequest: function (event) {
    var node = event.target;
    var data = this._getThemeFromNode(node);
    if (!data)
      return;

    if (this._isAllowed(node)) {
      this._install(data);
      return;
    }

    var allowButtonText =
      gNavigatorBundle.getString("lwthemeInstallRequest.allowButton");
    var allowButtonAccesskey =
      gNavigatorBundle.getString("lwthemeInstallRequest.allowButton.accesskey");
    var message =
      gNavigatorBundle.getFormattedString("lwthemeInstallRequest.message",
                                          [node.ownerDocument.location.host]);
    var buttons = [{
      label: allowButtonText,
      accessKey: allowButtonAccesskey,
      callback: function () {
        LightWeightThemeWebInstaller._install(data);
      }
    }];

    this._removePreviousNotifications();

    var notificationBox = gBrowser.getNotificationBox();
    var notificationBar =
      notificationBox.appendNotification(message, "lwtheme-install-request", "",
                                         notificationBox.PRIORITY_INFO_MEDIUM,
                                         buttons);
    notificationBar.persistence = 1;
  },

  _install: function (newLWTheme) {
    var previousLWTheme = this._manager.currentTheme;

    var listener = {
      onEnabling: function(aAddon, aRequiresRestart) {
        if (!aRequiresRestart)
          return;

        let messageString = gNavigatorBundle.getFormattedString("lwthemeNeedsRestart.message",
          [aAddon.name], 1);

        let action = {
          label: gNavigatorBundle.getString("lwthemeNeedsRestart.button"),
          accessKey: gNavigatorBundle.getString("lwthemeNeedsRestart.accesskey"),
          callback: function () {
            Application.restart();
          }
        };

        let options = {
          timeout: Date.now() + 30000
        };

        PopupNotifications.show(gBrowser.selectedBrowser, "addon-theme-change",
                                messageString, "addons-notification-icon",
                                action, null, options);
      },

      onEnabled: function(aAddon) {
        LightWeightThemeWebInstaller._postInstallNotification(newLWTheme, previousLWTheme);
      }
    };

    AddonManager.addAddonListener(listener);
    this._manager.currentTheme = newLWTheme;
    AddonManager.removeAddonListener(listener);
  },

  _postInstallNotification: function (newTheme, previousTheme) {
    function text(id) {
      return gNavigatorBundle.getString("lwthemePostInstallNotification." + id);
    }

    var buttons = [{
      label: text("undoButton"),
      accessKey: text("undoButton.accesskey"),
      callback: function () {
        LightWeightThemeWebInstaller._manager.forgetUsedTheme(newTheme.id);
        LightWeightThemeWebInstaller._manager.currentTheme = previousTheme;
      }
    }, {
      label: text("manageButton"),
      accessKey: text("manageButton.accesskey"),
      callback: function () {
        BrowserOpenAddonsMgr("addons://list/theme");
      }
    }];

    this._removePreviousNotifications();

    var notificationBox = gBrowser.getNotificationBox();
    var notificationBar =
      notificationBox.appendNotification(text("message"),
                                         "lwtheme-install-notification", "",
                                         notificationBox.PRIORITY_INFO_MEDIUM,
                                         buttons);
    notificationBar.persistence = 1;
    notificationBar.timeout = Date.now() + 20000; // 20 seconds
  },

  _removePreviousNotifications: function () {
    var box = gBrowser.getNotificationBox();

    ["lwtheme-install-request",
     "lwtheme-install-notification"].forEach(function (value) {
        var notification = box.getNotificationWithValue(value);
        if (notification)
          box.removeNotification(notification);
      });
  },

  _previewWindow: null,
  _preview: function (event) {
    if (!this._isAllowed(event.target))
      return;

    var data = this._getThemeFromNode(event.target);
    if (!data)
      return;

    this._resetPreview();

    this._previewWindow = event.target.ownerDocument.defaultView;
    this._previewWindow.addEventListener("pagehide", this, true);
    gBrowser.tabContainer.addEventListener("TabSelect", this, false);

    this._manager.previewTheme(data);
  },

  _resetPreview: function (event) {
    if (!this._previewWindow ||
        event && !this._isAllowed(event.target))
      return;

    this._previewWindow.removeEventListener("pagehide", this, true);
    this._previewWindow = null;
    gBrowser.tabContainer.removeEventListener("TabSelect", this, false);

    this._manager.resetPreview();
  },

  _isAllowed: function (node) {
    var pm = Services.perms;

    var uri = node.ownerDocument.documentURIObject;
    return pm.testPermission(uri, "install") == pm.ALLOW_ACTION;
  },

  _getThemeFromNode: function (node) {
    return this._manager.parseTheme(node.getAttribute("data-browsertheme"),
                                    node.baseURI);
  }
}
//@line 5 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-feeds.js"

/**
 * The Feed Handler object manages discovery of RSS/ATOM feeds in web pages
 * and shows UI when they are discovered.
 */
var FeedHandler = {
  /**
   * The click handler for the Feed icon in the toolbar. Opens the
   * subscription page if user is not given a choice of feeds.
   * (Otherwise the list of available feeds will be presented to the
   * user in a popup menu.)
   */
  onFeedButtonClick: function(event) {
    event.stopPropagation();

    let feeds = gBrowser.selectedBrowser.feeds || [];
    // If there are multiple feeds, the menu will open, so no need to do
    // anything. If there are no feeds, nothing to do either.
    if (feeds.length != 1)
      return;

    if (event.eventPhase == Event.AT_TARGET &&
        (event.button == 0 || event.button == 1)) {
      this.subscribeToFeed(feeds[0].href, event);
    }
  },

 /** Called when the user clicks on the Subscribe to This Page... menu item.
   * Builds a menu of unique feeds associated with the page, and if there
   * is only one, shows the feed inline in the browser window.
   * @param   menuPopup
   *          The feed list menupopup to be populated.
   * @returns true if the menu should be shown, false if there was only
   *          one feed and the feed should be shown inline in the browser
   *          window (do not show the menupopup).
   */
  buildFeedList: function(menuPopup) {
    var feeds = gBrowser.selectedBrowser.feeds;
    if (feeds == null) {
      // XXX hack -- menu opening depends on setting of an "open"
      // attribute, and the menu refuses to open if that attribute is
      // set (because it thinks it's already open).  onpopupshowing gets
      // called after the attribute is unset, and it doesn't get unset
      // if we return false.  so we unset it here; otherwise, the menu
      // refuses to work past this point.
      menuPopup.parentNode.removeAttribute("open");
      return false;
    }

    while (menuPopup.firstChild)
      menuPopup.removeChild(menuPopup.firstChild);

    if (feeds.length <= 1)
      return false;

    // Build the menu showing the available feed choices for viewing.
    for (let feedInfo of feeds) {
      var menuItem = document.createElement("menuitem");
      var baseTitle = feedInfo.title || feedInfo.href;
      var labelStr = gNavigatorBundle.getFormattedString("feedShowFeedNew", [baseTitle]);
      menuItem.setAttribute("class", "feed-menuitem");
      menuItem.setAttribute("label", labelStr);
      menuItem.setAttribute("feed", feedInfo.href);
      menuItem.setAttribute("tooltiptext", feedInfo.href);
      menuItem.setAttribute("crop", "center");
      menuPopup.appendChild(menuItem);
    }
    return true;
  },

  /**
   * Subscribe to a given feed.  Called when
   *   1. Page has a single feed and user clicks feed icon in location bar
   *   2. Page has a single feed and user selects Subscribe menu item
   *   3. Page has multiple feeds and user selects from feed icon popup
   *   4. Page has multiple feeds and user selects from Subscribe submenu
   * @param   href
   *          The feed to subscribe to. May be null, in which case the
   *          event target's feed attribute is examined.
   * @param   event
   *          The event this method is handling. Used to decide where
   *          to open the preview UI. (Optional, unless href is null)
   */
  subscribeToFeed: function(href, event) {
    // Just load the feed in the content area to either subscribe or show the
    // preview UI
    if (!href)
      href = event.target.getAttribute("feed");
    urlSecurityCheck(href, gBrowser.contentPrincipal,
                     Ci.nsIScriptSecurityManager.DISALLOW_INHERIT_PRINCIPAL);
    var feedURI = makeURI(href, document.characterSet);
    // Use the feed scheme so X-Moz-Is-Feed will be set
    // The value doesn't matter
    if (/^https?$/.test(feedURI.scheme))
      href = "feed:" + href;
    this.loadFeed(href, event);
  },

  loadFeed: function(href, event) {
    var feeds = gBrowser.selectedBrowser.feeds;
    try {
      openUILink(href, event, { ignoreAlt: true });
    }
    finally {
      // We might default to a livebookmarks modal dialog,
      // so reset that if the user happens to click it again
      gBrowser.selectedBrowser.feeds = feeds;
    }
  },

  get _feedMenuitem() {
    delete this._feedMenuitem;
    return this._feedMenuitem = document.getElementById("singleFeedMenuitemState");
  },

  get _feedMenupopup() {
    delete this._feedMenupopup;
    return this._feedMenupopup = document.getElementById("multipleFeedsMenuState");
  },

  /**
   * Update the browser UI to show whether or not feeds are available when
   * a page is loaded or the user switches tabs to a page that has feeds.
   */
  updateFeeds: function() {
    if (this._updateFeedTimeout)
      clearTimeout(this._updateFeedTimeout);

    var feeds = gBrowser.selectedBrowser.feeds;
    var haveFeeds = feeds && feeds.length > 0;

    var feedButton = document.getElementById("feed-button");
    if (feedButton)
      feedButton.disabled = !haveFeeds;

    if (!haveFeeds) {
      this._feedMenuitem.setAttribute("disabled", "true");
      this._feedMenuitem.removeAttribute("hidden");
      this._feedMenupopup.setAttribute("hidden", "true");
      return;
    }

    if (feeds.length > 1) {
      this._feedMenuitem.setAttribute("hidden", "true");
      this._feedMenupopup.removeAttribute("hidden");
    } else {
      this._feedMenuitem.setAttribute("feed", feeds[0].href);
      this._feedMenuitem.removeAttribute("disabled");
      this._feedMenuitem.removeAttribute("hidden");
      this._feedMenupopup.setAttribute("hidden", "true");
    }
  },

  addFeed: function(link, targetDoc) {
    // find which tab this is for, and set the attribute on the browser
    var browserForLink = gBrowser.getBrowserForDocument(targetDoc);
    if (!browserForLink) {
      // ignore feeds loaded in subframes (see bug 305472)
      return;
    }

    if (!browserForLink.feeds)
      browserForLink.feeds = [];

    browserForLink.feeds.push({ href: link.href, title: link.title });

    // If this addition was for the current browser, update the UI. For
    // background browsers, we'll update on tab switch.
    if (browserForLink == gBrowser.selectedBrowser) {
      // Batch updates to avoid updating the UI for multiple onLinkAdded events
      // fired within 100ms of each other.
      if (this._updateFeedTimeout)
        clearTimeout(this._updateFeedTimeout);
      this._updateFeedTimeout = setTimeout(this.updateFeeds.bind(this), 100);
    }
  }
};
//@line 5 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-fullScreen.js"

var FullScreen = {
  _XULNS: "http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul",
  get _fullScrToggler() {
    delete this._fullScrToggler;
    return this._fullScrToggler = document.getElementById("fullscr-toggler");
  },
  toggle: function (event) {
    var enterFS = window.fullScreen;

    // We get the fullscreen event _before_ the window transitions into or out of FS mode.
    if (event && event.type == "fullscreen")
      enterFS = !enterFS;

    // Toggle the View:FullScreen command, which controls elements like the
    // fullscreen menuitem, menubars, and the appmenu.
    document.getElementById("View:FullScreen").setAttribute("checked", enterFS);

//@line 28 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-fullScreen.js"

    // On OS X Lion we don't want to hide toolbars when entering fullscreen, unless
    // we're entering DOM fullscreen, in which case we should hide the toolbars.
    // If we're leaving fullscreen, then we'll go through the exit code below to
    // make sure toolbars are made visible in the case of DOM fullscreen.
    if (enterFS && this.useLionFullScreen) {
      if (document.mozFullScreen) {
        this.showXULChrome("toolbar", false);
      }
      else {
        gNavToolbox.setAttribute("inFullscreen", true);
        document.documentElement.setAttribute("inFullscreen", true);
      }
      return;
    }

    // show/hide menubars, toolbars (except the full screen toolbar)
    this.showXULChrome("toolbar", !enterFS);

    if (enterFS) {
      // Add a tiny toolbar to receive mouseover and dragenter events, and provide affordance.
      // This will help simulate the "collapse" metaphor while also requiring less code and
      // events than raw listening of mouse coords. We don't add the toolbar in DOM full-screen
      // mode, only browser full-screen mode.
      if (!document.mozFullScreen) {
        this._fullScrToggler.addEventListener("mouseover", this._expandCallback, false);
        this._fullScrToggler.addEventListener("dragenter", this._expandCallback, false);
      }
      if (gPrefService.getBoolPref("browser.fullscreen.autohide"))
        gBrowser.mPanelContainer.addEventListener("mousemove",
                                                  this._collapseCallback, false);

      document.addEventListener("keypress", this._keyToggleCallback, false);
      document.addEventListener("popupshown", this._setPopupOpen, false);
      document.addEventListener("popuphidden", this._setPopupOpen, false);
      // We don't animate the toolbar collapse if in DOM full-screen mode,
      // as the size of the content area would still be changing after the
      // mozfullscreenchange event fired, which could confuse content script.
      this._shouldAnimate = !document.mozFullScreen;
      this.mouseoverToggle(false);

      // Autohide prefs
      gPrefService.addObserver("browser.fullscreen", this, false);
    }
    else {
      // The user may quit fullscreen during an animation
      this._cancelAnimation();
      gNavToolbox.style.marginTop = "";
      if (this._isChromeCollapsed)
        this.mouseoverToggle(true);
      // This is needed if they use the context menu to quit fullscreen
      this._isPopupOpen = false;

      this.cleanup();
    }
  },

  exitDomFullScreen : function() {
    document.mozCancelFullScreen();
  },

  handleEvent: function (event) {
    switch (event.type) {
      case "deactivate":
        // We must call exitDomFullScreen asynchronously, since "deactivate" is
        // dispatched in the middle of the focus manager's window lowering code,
        // and the focus manager gets confused if we exit fullscreen mode in the
        // middle of window lowering. See bug 729872.
        setTimeout(this.exitDomFullScreen.bind(this), 0);
        break;
      case "transitionend":
        if (event.propertyName == "opacity")
          this.cancelWarning();
        break;
    }
  },

  enterDomFullscreen : function(event) {
    if (!document.mozFullScreen)
      return;

    // However, if we receive a "MozEnteredDomFullScreen" event for a document
    // which is not a subdocument of the currently selected tab, we know that
    // we've switched tabs since the request to enter full-screen was made,
    // so we should exit full-screen since the "full-screen document" isn't
    // acutally visible.
    if (event.target.defaultView.top != gBrowser.contentWindow) {
      document.mozCancelFullScreen();
      return;
    }

    let focusManager = Cc["@mozilla.org/focus-manager;1"].getService(Ci.nsIFocusManager);
    if (focusManager.activeWindow != window) {
      // The top-level window has lost focus since the request to enter
      // full-screen was made. Cancel full-screen.
      document.mozCancelFullScreen();
      return;
    }

    // Ensure the sidebar is hidden.
    if (!document.getElementById("sidebar-box").hidden)
      toggleSidebar();

    if (gFindBarInitialized)
      gFindBar.close();

    this.showWarning(event.target);

    // Exit DOM full-screen mode upon open, close, or change tab.
    gBrowser.tabContainer.addEventListener("TabOpen", this.exitDomFullScreen);
    gBrowser.tabContainer.addEventListener("TabClose", this.exitDomFullScreen);
    gBrowser.tabContainer.addEventListener("TabSelect", this.exitDomFullScreen);

    // Exit DOM full-screen mode when the browser window loses focus (ALT+TAB, etc).
    if (!this.useLionFullScreen &&
        gPrefService.getBoolPref("full-screen-api.exit-on-deactivate")) {
      window.addEventListener("deactivate", this);
    }

    // Cancel any "hide the toolbar" animation which is in progress, and make
    // the toolbar hide immediately.
    this._cancelAnimation();
    this.mouseoverToggle(false);

    // Remove listeners on the full-screen toggler, so that mouseover
    // the top of the screen will not cause the toolbar to re-appear.
    this._fullScrToggler.removeEventListener("mouseover", this._expandCallback, false);
    this._fullScrToggler.removeEventListener("dragenter", this._expandCallback, false);
  },

  cleanup: function () {
    if (window.fullScreen) {
      gBrowser.mPanelContainer.removeEventListener("mousemove",
                                                   this._collapseCallback, false);
      document.removeEventListener("keypress", this._keyToggleCallback, false);
      document.removeEventListener("popupshown", this._setPopupOpen, false);
      document.removeEventListener("popuphidden", this._setPopupOpen, false);
      gPrefService.removeObserver("browser.fullscreen", this);

      this._fullScrToggler.removeEventListener("mouseover", this._expandCallback, false);
      this._fullScrToggler.removeEventListener("dragenter", this._expandCallback, false);
      this.cancelWarning();
      gBrowser.tabContainer.removeEventListener("TabOpen", this.exitDomFullScreen);
      gBrowser.tabContainer.removeEventListener("TabClose", this.exitDomFullScreen);
      gBrowser.tabContainer.removeEventListener("TabSelect", this.exitDomFullScreen);
      if (!this.useLionFullScreen)
        window.removeEventListener("deactivate", this);
    }
  },

  observe: function(aSubject, aTopic, aData)
  {
    if (aData == "browser.fullscreen.autohide") {
      if (gPrefService.getBoolPref("browser.fullscreen.autohide")) {
        gBrowser.mPanelContainer.addEventListener("mousemove",
                                                  this._collapseCallback, false);
      }
      else {
        gBrowser.mPanelContainer.removeEventListener("mousemove",
                                                     this._collapseCallback, false);
      }
    }
  },

  // Event callbacks
  _expandCallback: function()
  {
    FullScreen.mouseoverToggle(true);
  },
  _collapseCallback: function()
  {
    FullScreen.mouseoverToggle(false);
  },
  _keyToggleCallback: function(aEvent)
  {
    // if we can use the keyboard (eg Ctrl+L or Ctrl+E) to open the toolbars, we
    // should provide a way to collapse them too.
    if (aEvent.keyCode == aEvent.DOM_VK_ESCAPE) {
      FullScreen._shouldAnimate = false;
      FullScreen.mouseoverToggle(false, true);
    }
    // F6 is another shortcut to the address bar, but its not covered in OpenLocation()
    else if (aEvent.keyCode == aEvent.DOM_VK_F6)
      FullScreen.mouseoverToggle(true);
  },

  // Checks whether we are allowed to collapse the chrome
  _isPopupOpen: false,
  _isChromeCollapsed: false,
  _safeToCollapse: function(forceHide)
  {
    if (!gPrefService.getBoolPref("browser.fullscreen.autohide"))
      return false;

    // a popup menu is open in chrome: don't collapse chrome
    if (!forceHide && this._isPopupOpen)
      return false;

    // a textbox in chrome is focused (location bar anyone?): don't collapse chrome
    if (document.commandDispatcher.focusedElement &&
        document.commandDispatcher.focusedElement.ownerDocument == document &&
        document.commandDispatcher.focusedElement.localName == "input") {
      if (forceHide)
        // hidden textboxes that still have focus are bad bad bad
        document.commandDispatcher.focusedElement.blur();
      else
        return false;
    }
    return true;
  },

  _setPopupOpen: function(aEvent)
  {
    // Popups should only veto chrome collapsing if they were opened when the chrome was not collapsed.
    // Otherwise, they would not affect chrome and the user would expect the chrome to go away.
    // e.g. we wouldn't want the autoscroll icon firing this event, so when the user
    // toggles chrome when moving mouse to the top, it doesn't go away again.
    if (aEvent.type == "popupshown" && !FullScreen._isChromeCollapsed &&
        aEvent.target.localName != "tooltip" && aEvent.target.localName != "window")
      FullScreen._isPopupOpen = true;
    else if (aEvent.type == "popuphidden" && aEvent.target.localName != "tooltip" &&
             aEvent.target.localName != "window")
      FullScreen._isPopupOpen = false;
  },

  // Autohide helpers for the context menu item
  getAutohide: function(aItem)
  {
    aItem.setAttribute("checked", gPrefService.getBoolPref("browser.fullscreen.autohide"));
  },
  setAutohide: function()
  {
    gPrefService.setBoolPref("browser.fullscreen.autohide", !gPrefService.getBoolPref("browser.fullscreen.autohide"));
  },

  // Animate the toolbars disappearing
  _shouldAnimate: true,
  _isAnimating: false,
  _animationTimeout: 0,
  _animationHandle: 0,
  _animateUp: function() {
    // check again, the user may have done something before the animation was due to start
    if (!window.fullScreen || !this._safeToCollapse(false)) {
      this._isAnimating = false;
      this._shouldAnimate = true;
      return;
    }

    this._animateStartTime = window.mozAnimationStartTime;
    if (!this._animationHandle)
      this._animationHandle = window.mozRequestAnimationFrame(this);
  },

  sample: function (timeStamp) {
    const duration = 1500;
    const timePassed = timeStamp - this._animateStartTime;
    const pos = timePassed >= duration ? 1 :
                1 - Math.pow(1 - timePassed / duration, 4);

    if (pos >= 1) {
      // We've animated enough
      this._cancelAnimation();
      gNavToolbox.style.marginTop = "";
      this.mouseoverToggle(false);
      return;
    }

    gNavToolbox.style.marginTop = (gNavToolbox.boxObject.height * pos * -1) + "px";
    this._animationHandle = window.mozRequestAnimationFrame(this);
  },

  _cancelAnimation: function() {
    window.mozCancelAnimationFrame(this._animationHandle);
    this._animationHandle = 0;
    clearTimeout(this._animationTimeout);
    this._isAnimating = false;
    this._shouldAnimate = false;
  },

  cancelWarning: function(event) {
    if (!this.warningBox)
      return;
    this.fullscreenDoc = null;
    this.warningBox.removeEventListener("transitionend", this);
    if (this.warningFadeOutTimeout) {
      clearTimeout(this.warningFadeOutTimeout);
      this.warningFadeOutTimeout = null;
    }

    // Ensure focus switches away from the (now hidden) warning box. If the user
    // clicked buttons in the fullscreen key authorization UI, it would have been
    // focused, and any key events would be directed at the (now hidden) chrome
    // document instead of the target document.
    gBrowser.selectedBrowser.focus();

    this.warningBox.setAttribute("hidden", true);
    this.warningBox.removeAttribute("fade-warning-out");
    this.warningBox.removeAttribute("obscure-browser");
    this.warningBox = null;
  },

  setFullscreenAllowed: function(isApproved) {
    // The "remember decision" checkbox is hidden when showing for documents that
    // the permission manager can't handle (documents with URIs without a host).
    // We simply require those to be approved every time instead.
    let rememberCheckbox = document.getElementById("full-screen-remember-decision");
    let uri = this.fullscreenDoc.nodePrincipal.URI;
    if (!rememberCheckbox.hidden) {
      if (rememberCheckbox.checked)
        Services.perms.add(uri,
                           "fullscreen",
                           isApproved ? Services.perms.ALLOW_ACTION : Services.perms.DENY_ACTION,
                           Services.perms.EXPIRE_NEVER);
      else if (isApproved) {
        // The user has only temporarily approved fullscren for this fullscreen
        // session only. Add the permission (so Gecko knows to approve any further
        // fullscreen requests for this host in this fullscreen session) but add
        // a listener to revoke the permission when the chrome document exits
        // fullscreen.
        Services.perms.add(uri,
                           "fullscreen",
                           Services.perms.ALLOW_ACTION,
                           Services.perms.EXPIRE_SESSION);
        let host = uri.host;
        var onFullscreenchange = function onFullscreenchange(event) {
          if (event.target == document && document.mozFullScreenElement == null) {
            // The chrome document has left fullscreen. Remove the temporary permission grant.
            Services.perms.remove(host, "fullscreen");
            document.removeEventListener("mozfullscreenchange", onFullscreenchange);
          }
        }
        document.addEventListener("mozfullscreenchange", onFullscreenchange);
      }
    }
    if (this.warningBox)
      this.warningBox.setAttribute("fade-warning-out", "true");
    // If the document has been granted fullscreen, notify Gecko so it can resume
    // any pending pointer lock requests, otherwise exit fullscreen; the user denied
    // the fullscreen request.
    if (isApproved)
      Services.obs.notifyObservers(this.fullscreenDoc, "fullscreen-approved", "");
    else
      document.mozCancelFullScreen();
  },

  warningBox: null,
  warningFadeOutTimeout: null,
  fullscreenDoc: null,

  // Shows the fullscreen approval UI, or if the domain has already been approved
  // for fullscreen, shows a warning that the site has entered fullscreen for a short
  // duration.
  showWarning: function(targetDoc) {
    if (!document.mozFullScreen ||
        !gPrefService.getBoolPref("full-screen-api.approval-required"))
      return;

    // Set the strings on the fullscreen approval UI.
    this.fullscreenDoc = targetDoc;
    let uri = this.fullscreenDoc.nodePrincipal.URI;
    let host = null;
    try {
      host = uri.host;
    } catch (e) { }
    let hostLabel = document.getElementById("full-screen-domain-text");
    let rememberCheckbox = document.getElementById("full-screen-remember-decision");
    let isApproved = false;
    if (host) {
      // Document's principal's URI has a host. Display a warning including the hostname and
      // show UI to enable the user to permanently grant this host permission to enter fullscreen.
      let utils = {};
      Cu.import("resource://gre/modules/DownloadUtils.jsm", utils);
      let displayHost = utils.DownloadUtils.getURIHost(uri.spec)[0];
      let bundle = Services.strings.createBundle("chrome://browser/locale/browser.properties");

      hostLabel.textContent = bundle.formatStringFromName("fullscreen.entered", [displayHost], 1);
      hostLabel.removeAttribute("hidden");

      rememberCheckbox.label = bundle.formatStringFromName("fullscreen.rememberDecision", [displayHost], 1);
      rememberCheckbox.checked = false;
      rememberCheckbox.removeAttribute("hidden");

      // Note we only allow documents whose principal's URI has a host to
      // store permission grants.
      isApproved = Services.perms.testPermission(uri, "fullscreen") == Services.perms.ALLOW_ACTION;
    } else {
      hostLabel.setAttribute("hidden", "true");
      rememberCheckbox.setAttribute("hidden", "true");
    }

    // Note: the warning box can be non-null if the warning box from the previous request
    // wasn't hidden before another request was made.
    if (!this.warningBox) {
      this.warningBox = document.getElementById("full-screen-warning-container");
      // Add a listener to clean up state after the warning is hidden.
      this.warningBox.addEventListener("transitionend", this);
      this.warningBox.removeAttribute("hidden");
    } else {
      if (this.warningFadeOutTimeout) {
        clearTimeout(this.warningFadeOutTimeout);
        this.warningFadeOutTimeout = null;
      }
      this.warningBox.removeAttribute("fade-warning-out");
    }

    // If fullscreen mode has not yet been approved for the fullscreen
    // document's domain, show the approval UI and don't auto fade out the
    // fullscreen warning box. Otherwise, we're just notifying of entry into
    // fullscreen mode. Note if the resource's host is null, we must be
    // showing a local file or a local data URI, and we require explicit
    // approval every time.
    let authUI = document.getElementById("full-screen-approval-pane");
    if (isApproved) {
      authUI.setAttribute("hidden", "true");
      this.warningBox.removeAttribute("obscure-browser");
    } else {
      // Partially obscure the <browser> element underneath the approval UI.
      this.warningBox.setAttribute("obscure-browser", "true");
      authUI.removeAttribute("hidden");
    }

    // If we're not showing the fullscreen approval UI, we're just notifying the user
    // of the transition, so set a timeout to fade the warning out after a few moments.
    if (isApproved)
      this.warningFadeOutTimeout =
        setTimeout(
          function() {
            if (this.warningBox)
              this.warningBox.setAttribute("fade-warning-out", "true");
          }.bind(this),
          3000);
  },

  mouseoverToggle: function(aShow, forceHide)
  {
    // Don't do anything if:
    // a) we're already in the state we want,
    // b) we're animating and will become collapsed soon, or
    // c) we can't collapse because it would be undesirable right now
    if (aShow != this._isChromeCollapsed || (!aShow && this._isAnimating) ||
        (!aShow && !this._safeToCollapse(forceHide)))
      return;

    // browser.fullscreen.animateUp
    // 0 - never animate up
    // 1 - animate only for first collapse after entering fullscreen (default for perf's sake)
    // 2 - animate every time it collapses
    if (gPrefService.getIntPref("browser.fullscreen.animateUp") == 0)
      this._shouldAnimate = false;

    if (!aShow && this._shouldAnimate) {
      this._isAnimating = true;
      this._shouldAnimate = false;
      this._animationTimeout = setTimeout(this._animateUp.bind(this), 800);
      return;
    }

    // The chrome is collapsed so don't spam needless mousemove events
    if (aShow) {
      gBrowser.mPanelContainer.addEventListener("mousemove",
                                                this._collapseCallback, false);
    }
    else {
      gBrowser.mPanelContainer.removeEventListener("mousemove",
                                                   this._collapseCallback, false);
    }

    // Hiding/collapsing the toolbox interferes with the tab bar's scrollbox,
    // so we just move it off-screen instead. See bug 430687.
    gNavToolbox.style.marginTop =
      aShow ? "" : -gNavToolbox.getBoundingClientRect().height + "px";

    this._fullScrToggler.collapsed = aShow;
    this._isChromeCollapsed = !aShow;
    if (gPrefService.getIntPref("browser.fullscreen.animateUp") == 2)
      this._shouldAnimate = true;
  },

  showXULChrome: function(aTag, aShow)
  {
    var els = document.getElementsByTagNameNS(this._XULNS, aTag);

    for (let el of els) {
      // XXX don't interfere with previously collapsed toolbars
      if (el.getAttribute("fullscreentoolbar") == "true") {
        if (!aShow) {

          var toolbarMode = el.getAttribute("mode");
          if (toolbarMode != "text") {
            el.setAttribute("saved-mode", toolbarMode);
            el.setAttribute("saved-iconsize", el.getAttribute("iconsize"));
            el.setAttribute("mode", "icons");
            el.setAttribute("iconsize", "small");
          }

          // Give the main nav bar and the tab bar the fullscreen context menu,
          // otherwise remove context menu to prevent breakage
          el.setAttribute("saved-context", el.getAttribute("context"));
          if (el.id == "nav-bar" || el.id == "TabsToolbar")
            el.setAttribute("context", "autohide-context");
          else
            el.removeAttribute("context");

          // Set the inFullscreen attribute to allow specific styling
          // in fullscreen mode
          el.setAttribute("inFullscreen", true);
        }
        else {
          var restoreAttr = function restoreAttr(attrName) {
            var savedAttr = "saved-" + attrName;
            if (el.hasAttribute(savedAttr)) {
              el.setAttribute(attrName, el.getAttribute(savedAttr));
              el.removeAttribute(savedAttr);
            }
          }

          restoreAttr("mode");
          restoreAttr("iconsize");
          restoreAttr("context");

          el.removeAttribute("inFullscreen");
        }
      } else {
        // use moz-collapsed so it doesn't persist hidden/collapsed,
        // so that new windows don't have missing toolbars
        if (aShow)
          el.removeAttribute("moz-collapsed");
        else
          el.setAttribute("moz-collapsed", "true");
      }
    }

    if (aShow) {
      gNavToolbox.removeAttribute("inFullscreen");
      document.documentElement.removeAttribute("inFullscreen");
    } else {
      gNavToolbox.setAttribute("inFullscreen", true);
      document.documentElement.setAttribute("inFullscreen", true);
    }

    // In tabs-on-top mode, move window controls to the tab bar,
    // and in tabs-on-bottom mode, move them back to the navigation toolbar.
    // When there is a chance the tab bar may be collapsed, put window
    // controls on nav bar.
    var fullscreenctls = document.getElementById("window-controls");
    var navbar = document.getElementById("nav-bar");
    var ctlsOnTabbar = window.toolbar.visible &&
                       (navbar.collapsed ||
                          (TabsOnTop.enabled &&
                           !gPrefService.getBoolPref("browser.tabs.autoHide")));
    if (fullscreenctls.parentNode == navbar && ctlsOnTabbar) {
      fullscreenctls.removeAttribute("flex");
      document.getElementById("TabsToolbar").appendChild(fullscreenctls);
    }
    else if (fullscreenctls.parentNode.id == "TabsToolbar" && !ctlsOnTabbar) {
      fullscreenctls.setAttribute("flex", "1");
      navbar.appendChild(fullscreenctls);
    }
    fullscreenctls.hidden = aShow;
  }
};
XPCOMUtils.defineLazyGetter(FullScreen, "useLionFullScreen", function() {
  // We'll only use OS X Lion full screen if we're
  // * on OS X
  // * on Lion or higher (Darwin 11+)
  // * have fullscreenbutton="true"
//@line 598 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-fullScreen.js"
  return false;
//@line 600 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-fullScreen.js"
});
/*
//@line 7 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-fullZoom.js"
 */

// One of the possible values for the mousewheel.* preferences.
// From nsEventStateManager.cpp.
const MOUSE_SCROLL_ZOOM = 3;

Cu.import('resource://gre/modules/ContentPrefInstance.jsm');

function getContentPrefs(aWindow) {
  let context = aWindow ? aWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                                 .getInterface(Ci.nsIWebNavigation)
                                 .QueryInterface(Ci.nsILoadContext) : null;
  return new ContentPrefInstance(context);
}

/**
 * Controls the "full zoom" setting and its site-specific preferences.
 */
var FullZoom = {
  // Identifies the setting in the content prefs database.
  name: "browser.content.full-zoom",

  // The global value (if any) for the setting.  Lazily loaded from the service
  // when first requested, then updated by the pref change listener as it changes.
  // If there is no global value, then this should be undefined.
  get globalValue() {
    var globalValue = getContentPrefs(gBrowser.contentDocument.defaultView).getPref(null, this.name);
    if (typeof globalValue != "undefined")
      globalValue = this._ensureValid(globalValue);
    delete this.globalValue;
    return this.globalValue = globalValue;
  },

  // browser.zoom.siteSpecific preference cache
  _siteSpecificPref: undefined,

  // browser.zoom.updateBackgroundTabs preference cache
  updateBackgroundTabs: undefined,

  get siteSpecific() {
    return this._siteSpecificPref;
  },

  //**************************************************************************//
  // nsISupports

  QueryInterface: XPCOMUtils.generateQI([Ci.nsIDOMEventListener,
                                         Ci.nsIObserver,
                                         Ci.nsIContentPrefObserver,
                                         Ci.nsISupportsWeakReference,
                                         Ci.nsISupports]),

  //**************************************************************************//
  // Initialization & Destruction

  init: function FullZoom_init() {
    // Listen for scrollwheel events so we can save scrollwheel-based changes.
    window.addEventListener("DOMMouseScroll", this, false);

    // Register ourselves with the service so we know when our pref changes.
    getContentPrefs().addObserver(this.name, this);

    this._siteSpecificPref =
      gPrefService.getBoolPref("browser.zoom.siteSpecific");
    this.updateBackgroundTabs =
      gPrefService.getBoolPref("browser.zoom.updateBackgroundTabs");
    // Listen for changes to the browser.zoom branch so we can enable/disable
    // updating background tabs and per-site saving and restoring of zoom levels.
    gPrefService.addObserver("browser.zoom.", this, true);
  },

  destroy: function FullZoom_destroy() {
    gPrefService.removeObserver("browser.zoom.", this);
    getContentPrefs().removeObserver(this.name, this);
    window.removeEventListener("DOMMouseScroll", this, false);
  },


  //**************************************************************************//
  // Event Handlers

  // nsIDOMEventListener

  handleEvent: function FullZoom_handleEvent(event) {
    switch (event.type) {
      case "DOMMouseScroll":
        this._handleMouseScrolled(event);
        break;
    }
  },

  _handleMouseScrolled: function FullZoom__handleMouseScrolled(event) {
    // Construct the "mousewheel action" pref key corresponding to this event.
    // Based on nsEventStateManager::WheelPrefs::GetBasePrefName().
    var pref = "mousewheel.";

    var pressedModifierCount = event.shiftKey + event.ctrlKey + event.altKey +
                                 event.metaKey + event.getModifierState("OS");
    if (pressedModifierCount != 1) {
      pref += "default.";
    } else if (event.shiftKey) {
      pref += "with_shift.";
    } else if (event.ctrlKey) {
      pref += "with_control.";
    } else if (event.altKey) {
      pref += "with_alt.";
    } else if (event.metaKey) {
      pref += "with_meta.";
    } else {
      pref += "with_win.";
    }

    pref += "action";

    // Don't do anything if this isn't a "zoom" scroll event.
    var isZoomEvent = false;
    try {
      isZoomEvent = (gPrefService.getIntPref(pref) == MOUSE_SCROLL_ZOOM);
    } catch (e) {}
    if (!isZoomEvent)
      return;

    // XXX Lazily cache all the possible action prefs so we don't have to get
    // them anew from the pref service for every scroll event?  We'd have to
    // make sure to observe them so we can update the cache when they change.

    // We have to call _applySettingToPref in a timeout because we handle
    // the event before the event state manager has a chance to apply the zoom
    // during nsEventStateManager::PostHandleEvent.
    window.setTimeout(function (self) { self._applySettingToPref() }, 0, this);
  },

  // nsIObserver

  observe: function (aSubject, aTopic, aData) {
    switch (aTopic) {
      case "nsPref:changed":
        switch (aData) {
          case "browser.zoom.siteSpecific":
            this._siteSpecificPref =
              gPrefService.getBoolPref("browser.zoom.siteSpecific");
            break;
          case "browser.zoom.updateBackgroundTabs":
            this.updateBackgroundTabs =
              gPrefService.getBoolPref("browser.zoom.updateBackgroundTabs");
            break;
        }
        break;
    }
  },

  // nsIContentPrefObserver

  onContentPrefSet: function FullZoom_onContentPrefSet(aGroup, aName, aValue) {
    let contentPrefs = getContentPrefs(gBrowser.contentDocument.defaultView);
    if (aGroup == contentPrefs.grouper.group(gBrowser.currentURI))
      this._applyPrefToSetting(aValue);
    else if (aGroup == null) {
      this.globalValue = this._ensureValid(aValue);

      // If the current page doesn't have a site-specific preference,
      // then its zoom should be set to the new global preference now that
      // the global preference has changed.
      if (!contentPrefs.hasPref(gBrowser.currentURI, this.name))
        this._applyPrefToSetting();
    }
  },

  onContentPrefRemoved: function FullZoom_onContentPrefRemoved(aGroup, aName) {
    let contentPrefs = getContentPrefs(gBrowser.contentDocument.defaultView);
    if (aGroup == contentPrefs.grouper.group(gBrowser.currentURI))
      this._applyPrefToSetting();
    else if (aGroup == null) {
      this.globalValue = undefined;

      // If the current page doesn't have a site-specific preference,
      // then its zoom should be set to the default preference now that
      // the global preference has changed.
      if (!contentPrefs.hasPref(gBrowser.currentURI, this.name))
        this._applyPrefToSetting();
    }
  },

  // location change observer

  /**
   * Called when the location of a tab changes.
   * When that happens, we need to update the current zoom level if appropriate.
   *
   * @param aURI
   *        A URI object representing the new location.
   * @param aIsTabSwitch
   *        Whether this location change has happened because of a tab switch.
   * @param aBrowser
   *        (optional) browser object displaying the document
   */
  onLocationChange: function FullZoom_onLocationChange(aURI, aIsTabSwitch, aBrowser) {
    if (!aURI || (aIsTabSwitch && !this.siteSpecific))
      return;

    // Avoid the cps roundtrip and apply the default/global pref.
    if (aURI.spec == "about:blank") {
      this._applyPrefToSetting(undefined, aBrowser);
      return;
    }

    let browser = aBrowser || gBrowser.selectedBrowser;

    // Media documents should always start at 1, and are not affected by prefs.
    if (!aIsTabSwitch && browser.contentDocument.mozSyntheticDocument) {
      ZoomManager.setZoomForBrowser(browser, 1);
      return;
    }

    let contentPrefs = getContentPrefs(gBrowser.contentDocument.defaultView);
    if (contentPrefs.hasCachedPref(aURI, this.name)) {
      let zoomValue = contentPrefs.getPref(aURI, this.name);
      this._applyPrefToSetting(zoomValue, browser);
    } else {
      var self = this;
      contentPrefs.getPref(aURI, this.name, function (aResult) {
        // Check that we're still where we expect to be in case this took a while.
        // Null check currentURI, since the window may have been destroyed before
        // we were called.
        if (browser.currentURI && aURI.equals(browser.currentURI)) {
          self._applyPrefToSetting(aResult, browser);
        }
      });
    }
  },

  // update state of zoom type menu item

  updateMenu: function FullZoom_updateMenu() {
    var menuItem = document.getElementById("toggle_zoom");

    menuItem.setAttribute("checked", !ZoomManager.useFullZoom);
  },

  //**************************************************************************//
  // Setting & Pref Manipulation

  reduce: function FullZoom_reduce() {
    ZoomManager.reduce();
    this._applySettingToPref();
  },

  enlarge: function FullZoom_enlarge() {
    ZoomManager.enlarge();
    this._applySettingToPref();
  },

  reset: function FullZoom_reset() {
    if (typeof this.globalValue != "undefined")
      ZoomManager.zoom = this.globalValue;
    else
      ZoomManager.reset();

    this._removePref();
  },

  /**
   * Set the zoom level for the current tab.
   *
   * Per nsPresContext::setFullZoom, we can set the zoom to its current value
   * without significant impact on performance, as the setting is only applied
   * if it differs from the current setting.  In fact getting the zoom and then
   * checking ourselves if it differs costs more.
   * 
   * And perhaps we should always set the zoom even if it was more expensive,
   * since nsDocumentViewer::SetTextZoom claims that child documents can have
   * a different text zoom (although it would be unusual), and it implies that
   * those child text zooms should get updated when the parent zoom gets set,
   * and perhaps the same is true for full zoom
   * (although nsDocumentViewer::SetFullZoom doesn't mention it).
   *
   * So when we apply new zoom values to the browser, we simply set the zoom.
   * We don't check first to see if the new value is the same as the current
   * one.
   **/
  _applyPrefToSetting: function FullZoom__applyPrefToSetting(aValue, aBrowser) {
    if ((!this.siteSpecific) || gInPrintPreviewMode)
      return;

    var browser = aBrowser || (gBrowser && gBrowser.selectedBrowser);
    try {
      if (browser.contentDocument.mozSyntheticDocument)
        return;

      if (typeof aValue != "undefined")
        ZoomManager.setZoomForBrowser(browser, this._ensureValid(aValue));
      else if (typeof this.globalValue != "undefined")
        ZoomManager.setZoomForBrowser(browser, this.globalValue);
      else
        ZoomManager.setZoomForBrowser(browser, 1);
    }
    catch(ex) {}
  },

  _applySettingToPref: function FullZoom__applySettingToPref() {
    if (!this.siteSpecific || gInPrintPreviewMode ||
        content.document.mozSyntheticDocument)
      return;

    var zoomLevel = ZoomManager.zoom;
    getContentPrefs(gBrowser.contentDocument.defaultView).setPref(gBrowser.currentURI, this.name, zoomLevel);
  },

  _removePref: function FullZoom__removePref() {
    if (!(content.document.mozSyntheticDocument))
      getContentPrefs(gBrowser.contentDocument.defaultView).removePref(gBrowser.currentURI, this.name);
  },


  //**************************************************************************//
  // Utilities

  _ensureValid: function FullZoom__ensureValid(aValue) {
    if (isNaN(aValue))
      return 1;

    if (aValue < ZoomManager.MIN)
      return ZoomManager.MIN;

    if (aValue > ZoomManager.MAX)
      return ZoomManager.MAX;

    return aValue;
  }
};
//@line 4 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-places.js"


var StarUI = {
  _itemId: -1,
  uri: null,
  _batching: false,

  _element: function(aID) {
    return document.getElementById(aID);
  },

  // Edit-bookmark panel
  get panel() {
    delete this.panel;
    var element = this._element("editBookmarkPanel");
    // initially the panel is hidden
    // to avoid impacting startup / new window performance
    element.hidden = false;
    element.addEventListener("popuphidden", this, false);
    element.addEventListener("keypress", this, false);
    return this.panel = element;
  },

  // Array of command elements to disable when the panel is opened.
  get _blockedCommands() {
    delete this._blockedCommands;
    return this._blockedCommands =
      ["cmd_close", "cmd_closeWindow"].map(function (id) this._element(id), this);
  },

  _blockCommands: function SU__blockCommands() {
    this._blockedCommands.forEach(function (elt) {
      // make sure not to permanently disable this item (see bug 409155)
      if (elt.hasAttribute("wasDisabled"))
        return;
      if (elt.getAttribute("disabled") == "true") {
        elt.setAttribute("wasDisabled", "true");
      } else {
        elt.setAttribute("wasDisabled", "false");
        elt.setAttribute("disabled", "true");
      }
    });
  },

  _restoreCommandsState: function SU__restoreCommandsState() {
    this._blockedCommands.forEach(function (elt) {
      if (elt.getAttribute("wasDisabled") != "true")
        elt.removeAttribute("disabled");
      elt.removeAttribute("wasDisabled");
    });
  },

  // nsIDOMEventListener
  handleEvent: function SU_handleEvent(aEvent) {
    switch (aEvent.type) {
      case "popuphidden":
        if (aEvent.originalTarget == this.panel) {
          if (!this._element("editBookmarkPanelContent").hidden)
            this.quitEditMode();

          this._restoreCommandsState();
          this._itemId = -1;
          if (this._batching) {
            PlacesUtils.transactionManager.endBatch(false);
            this._batching = false;
          }

          switch (this._actionOnHide) {
            case "cancel": {
              PlacesUtils.transactionManager.undoTransaction();
              break;
            }
            case "remove": {
              // Remove all bookmarks for the bookmark's url, this also removes
              // the tags for the url.
              PlacesUtils.transactionManager.beginBatch(null);
              let itemIds = PlacesUtils.getBookmarksForURI(this._uriForRemoval);
              for (let i = 0; i < itemIds.length; i++) {
                let txn = new PlacesRemoveItemTransaction(itemIds[i]);
                PlacesUtils.transactionManager.doTransaction(txn);
              }
              PlacesUtils.transactionManager.endBatch(false);
              break;
            }
          }
          this._actionOnHide = "";
        }
        break;
      case "keypress":
        if (aEvent.defaultPrevented) {
          // The event has already been consumed inside of the panel.
          break;
        }
        switch (aEvent.keyCode) {
          case KeyEvent.DOM_VK_ESCAPE:
            if (!this._element("editBookmarkPanelContent").hidden)
              this.cancelButtonOnCommand();
            break;
          case KeyEvent.DOM_VK_RETURN:
            if (aEvent.target.className == "expander-up" ||
                aEvent.target.className == "expander-down" ||
                aEvent.target.id == "editBMPanel_newFolderButton") {
              //XXX Why is this necessary? The defaultPrevented check should
              //    be enough.
              break;
            }
            this.panel.hidePopup();
            break;
        }
        break;
    }
  },

  _overlayLoaded: false,
  _overlayLoading: false,
  showEditBookmarkPopup:
  function SU_showEditBookmarkPopup(aItemId, aAnchorElement, aPosition) {
    // Performance: load the overlay the first time the panel is opened
    // (see bug 392443).
    if (this._overlayLoading)
      return;

    if (this._overlayLoaded) {
      this._doShowEditBookmarkPanel(aItemId, aAnchorElement, aPosition);
      return;
    }

    this._overlayLoading = true;
    document.loadOverlay(
      "chrome://browser/content/places/editBookmarkOverlay.xul",
      (function (aSubject, aTopic, aData) {
        //XXX We just caused localstore.rdf to be re-applied (bug 640158)
        retrieveToolbarIconsizesFromTheme();

        // Move the header (star, title, button) into the grid,
        // so that it aligns nicely with the other items (bug 484022).
        let header = this._element("editBookmarkPanelHeader");
        let rows = this._element("editBookmarkPanelGrid").lastChild;
        rows.insertBefore(header, rows.firstChild);
        header.hidden = false;

        this._overlayLoading = false;
        this._overlayLoaded = true;
        this._doShowEditBookmarkPanel(aItemId, aAnchorElement, aPosition);
      }).bind(this)
    );
  },

  _doShowEditBookmarkPanel:
  function SU__doShowEditBookmarkPanel(aItemId, aAnchorElement, aPosition) {
    if (this.panel.state != "closed")
      return;

    this._blockCommands(); // un-done in the popuphiding handler

    // Set panel title:
    // if we are batching, i.e. the bookmark has been added now,
    // then show Page Bookmarked, else if the bookmark did already exist,
    // we are about editing it, then use Edit This Bookmark.
    this._element("editBookmarkPanelTitle").value =
      this._batching ?
        gNavigatorBundle.getString("editBookmarkPanel.pageBookmarkedTitle") :
        gNavigatorBundle.getString("editBookmarkPanel.editBookmarkTitle");

    // No description; show the Done, Cancel;
    this._element("editBookmarkPanelDescription").textContent = "";
    this._element("editBookmarkPanelBottomButtons").hidden = false;
    this._element("editBookmarkPanelContent").hidden = false;

    // The remove button is shown only if we're not already batching, i.e.
    // if the cancel button/ESC does not remove the bookmark.
    this._element("editBookmarkPanelRemoveButton").hidden = this._batching;

    // The label of the remove button differs if the URI is bookmarked
    // multiple times.
    var bookmarks = PlacesUtils.getBookmarksForURI(gBrowser.currentURI);
    var forms = gNavigatorBundle.getString("editBookmark.removeBookmarks.label");
    var label = PluralForm.get(bookmarks.length, forms).replace("#1", bookmarks.length);
    this._element("editBookmarkPanelRemoveButton").label = label;

    // unset the unstarred state, if set
    this._element("editBookmarkPanelStarIcon").removeAttribute("unstarred");

    this._itemId = aItemId !== undefined ? aItemId : this._itemId;
    this.beginBatch();

    this.panel.openPopup(aAnchorElement, aPosition);

    gEditItemOverlay.initPanel(this._itemId,
                               { hiddenRows: ["description", "location",
                                              "loadInSidebar", "keyword"] });
  },

  panelShown:
  function SU_panelShown(aEvent) {
    if (aEvent.target == this.panel) {
      if (!this._element("editBookmarkPanelContent").hidden) {
        let fieldToFocus = "editBMPanel_" +
          gPrefService.getCharPref("browser.bookmarks.editDialog.firstEditField");
        var elt = this._element(fieldToFocus);
        elt.focus();
        elt.select();
      }
      else {
        // Note this isn't actually used anymore, we should remove this
        // once we decide not to bring back the page bookmarked notification
        this.panel.focus();
      }
    }
  },

  quitEditMode: function SU_quitEditMode() {
    this._element("editBookmarkPanelContent").hidden = true;
    this._element("editBookmarkPanelBottomButtons").hidden = true;
    gEditItemOverlay.uninitPanel(true);
  },

  editButtonCommand: function SU_editButtonCommand() {
    this.showEditBookmarkPopup();
  },

  cancelButtonOnCommand: function SU_cancelButtonOnCommand() {
    this._actionOnHide = "cancel";
    this.panel.hidePopup();
  },

  removeBookmarkButtonCommand: function SU_removeBookmarkButtonCommand() {
    this._uriForRemoval = PlacesUtils.bookmarks.getBookmarkURI(this._itemId);
    this._actionOnHide = "remove";
    this.panel.hidePopup();
  },

  beginBatch: function SU_beginBatch() {
    if (!this._batching) {
      PlacesUtils.transactionManager.beginBatch(null);
      this._batching = true;
    }
  }
}

var PlacesCommandHook = {
  /**
   * Adds a bookmark to the page loaded in the given browser.
   *
   * @param aBrowser
   *        a <browser> element.
   * @param [optional] aParent
   *        The folder in which to create a new bookmark if the page loaded in
   *        aBrowser isn't bookmarked yet, defaults to the unfiled root.
   * @param [optional] aShowEditUI
   *        whether or not to show the edit-bookmark UI for the bookmark item
   */  
  bookmarkPage: function PCH_bookmarkPage(aBrowser, aParent, aShowEditUI) {
    var uri = aBrowser.currentURI;
    var itemId = PlacesUtils.getMostRecentBookmarkForURI(uri);
    if (itemId == -1) {
      // Copied over from addBookmarkForBrowser:
      // Bug 52536: We obtain the URL and title from the nsIWebNavigation
      // associated with a <browser/> rather than from a DOMWindow.
      // This is because when a full page plugin is loaded, there is
      // no DOMWindow (?) but information about the loaded document
      // may still be obtained from the webNavigation.
      var webNav = aBrowser.webNavigation;
      var url = webNav.currentURI;
      var title;
      var description;
      var charset;
      try {
        let isErrorPage = /^about:(neterror|certerror|blocked)/
                          .test(webNav.document.documentURI);
        title = isErrorPage ? PlacesUtils.history.getPageTitle(url)
                            : webNav.document.title;
        title = title || url.spec;
        description = PlacesUIUtils.getDescriptionFromDocument(webNav.document);
        charset = webNav.document.characterSet;
      }
      catch (e) { }

      if (aShowEditUI) {
        // If we bookmark the page here (i.e. page was not "starred" already)
        // but open right into the "edit" state, start batching here, so
        // "Cancel" in that state removes the bookmark.
        StarUI.beginBatch();
      }

      var parent = aParent != undefined ?
                   aParent : PlacesUtils.unfiledBookmarksFolderId;
      var descAnno = { name: PlacesUIUtils.DESCRIPTION_ANNO, value: description };
      var txn = new PlacesCreateBookmarkTransaction(uri, parent, 
                                                    PlacesUtils.bookmarks.DEFAULT_INDEX,
                                                    title, null, [descAnno]);
      PlacesUtils.transactionManager.doTransaction(txn);
      // Set the character-set
      if (charset && !PrivateBrowsingUtils.isWindowPrivate(aBrowser.contentWindow))
        PlacesUtils.history.setCharsetForURI(uri, charset);
      itemId = PlacesUtils.getMostRecentBookmarkForURI(uri);
    }

    // Revert the contents of the location bar
    if (gURLBar)
      gURLBar.handleRevert();

    // dock the panel to the star icon when possible, otherwise dock
    // it to the content area
    if (aBrowser.contentWindow == window.content) {
      var starIcon = aBrowser.ownerDocument.getElementById("star-button");
      if (starIcon && isElementVisible(starIcon)) {
        if (aShowEditUI)
          StarUI.showEditBookmarkPopup(itemId, starIcon, "bottomcenter topright");
        return;
      }
    }

    StarUI.showEditBookmarkPopup(itemId, aBrowser, "overlap");
  },

  /**
   * Adds a bookmark to the page loaded in the current tab. 
   */
  bookmarkCurrentPage: function PCH_bookmarkCurrentPage(aShowEditUI, aParent) {
    this.bookmarkPage(gBrowser.selectedBrowser, aParent, aShowEditUI);
  },

  /**
   * Adds a bookmark to the page targeted by a link.
   * @param aParent
   *        The folder in which to create a new bookmark if aURL isn't
   *        bookmarked.
   * @param aURL (string)
   *        the address of the link target
   * @param aTitle
   *        The link text
   */
  bookmarkLink: function PCH_bookmarkLink(aParent, aURL, aTitle) {
    var linkURI = makeURI(aURL);
    var itemId = PlacesUtils.getMostRecentBookmarkForURI(linkURI);
    if (itemId == -1) {
      PlacesUIUtils.showBookmarkDialog({ action: "add"
                                       , type: "bookmark"
                                       , uri: linkURI
                                       , title: aTitle
                                       , hiddenRows: [ "description"
                                                     , "location"
                                                     , "loadInSidebar"
                                                     , "keyword" ]
                                       }, window);
    }
    else {
      PlacesUIUtils.showBookmarkDialog({ action: "edit"
                                       , type: "bookmark"
                                       , itemId: itemId
                                       }, window);
    }
  },

  /**
   * List of nsIURI objects characterizing the tabs currently open in the
   * browser, modulo pinned tabs.  The URIs will be in the order in which their
   * corresponding tabs appeared and duplicates are discarded.
   */
  get uniqueCurrentPages() {
    let uniquePages = {};
    let URIs = [];
    gBrowser.visibleTabs.forEach(function (tab) {
      let spec = tab.linkedBrowser.currentURI.spec;
      if (!tab.pinned && !(spec in uniquePages)) {
        uniquePages[spec] = null;
        URIs.push(tab.linkedBrowser.currentURI);
      }
    });
    return URIs;
  },

  /**
   * Adds a folder with bookmarks to all of the currently open tabs in this 
   * window.
   */
  bookmarkCurrentPages: function PCH_bookmarkCurrentPages() {
    let pages = this.uniqueCurrentPages;
    if (pages.length > 1) {
    PlacesUIUtils.showBookmarkDialog({ action: "add"
                                     , type: "folder"
                                     , URIList: pages
                                     , hiddenRows: [ "description" ]
                                     }, window);
    }
  },

  /**
   * Updates disabled state for the "Bookmark All Tabs" command.
   */
  updateBookmarkAllTabsCommand:
  function PCH_updateBookmarkAllTabsCommand() {
    // There's nothing to do in non-browser windows.
    if (window.location.href != getBrowserURL())
      return;

    // Disable "Bookmark All Tabs" if there are less than two
    // "unique current pages".
    goSetCommandEnabled("Browser:BookmarkAllTabs",
                        this.uniqueCurrentPages.length >= 2);
  },

  /**
   * Adds a Live Bookmark to a feed associated with the current page. 
   * @param     url
   *            The nsIURI of the page the feed was attached to
   * @title     title
   *            The title of the feed. Optional.
   * @subtitle  subtitle
   *            A short description of the feed. Optional.
   */
  addLiveBookmark: function PCH_addLiveBookmark(url, feedTitle, feedSubtitle) {
    var feedURI = makeURI(url);
    
    var doc = gBrowser.contentDocument;
    var title = (arguments.length > 1) ? feedTitle : doc.title;
 
    var description;
    if (arguments.length > 2)
      description = feedSubtitle;
    else
      description = PlacesUIUtils.getDescriptionFromDocument(doc);

    var toolbarIP = new InsertionPoint(PlacesUtils.toolbarFolderId, -1);
    PlacesUIUtils.showBookmarkDialog({ action: "add"
                                     , type: "livemark"
                                     , feedURI: feedURI
                                     , siteURI: gBrowser.currentURI
                                     , title: title
                                     , description: description
                                     , defaultInsertionPoint: toolbarIP
                                     , hiddenRows: [ "feedLocation"
                                                   , "siteLocation"
                                                   , "description" ]
                                     }, window);
  },

  /**
   * Opens the Places Organizer. 
   * @param   aLeftPaneRoot
   *          The query to select in the organizer window - options
   *          are: History, AllBookmarks, BookmarksMenu, BookmarksToolbar,
   *          UnfiledBookmarks, Tags and Downloads.
   */
  showPlacesOrganizer: function PCH_showPlacesOrganizer(aLeftPaneRoot) {
    var organizer = Services.wm.getMostRecentWindow("Places:Organizer");
    if (!organizer) {
      // No currently open places window, so open one with the specified mode.
      openDialog("chrome://browser/content/places/places.xul", 
                 "", "chrome,toolbar=yes,dialog=no,resizable", aLeftPaneRoot);
    }
    else {
      organizer.PlacesOrganizer.selectLeftPaneQuery(aLeftPaneRoot);
      organizer.focus();
    }
  }
};

// View for the history menu.
function HistoryMenu(aPopupShowingEvent) {
  // Workaround for Bug 610187.  The sidebar does not include all the Places
  // views definitions, and we don't need them there.
  // Defining the prototype inheritance in the prototype itself would cause
  // browser.js to halt on "PlacesMenu is not defined" error.
  this.__proto__.__proto__ = PlacesMenu.prototype;
  XPCOMUtils.defineLazyServiceGetter(this, "_ss",
                                     "@mozilla.org/browser/sessionstore;1",
                                     "nsISessionStore");
  PlacesMenu.call(this, aPopupShowingEvent,
                  "place:sort=4&maxResults=15");
}

HistoryMenu.prototype = {
  toggleRecentlyClosedTabs: function HM_toggleRecentlyClosedTabs() {
    // enable/disable the Recently Closed Tabs sub menu
    var undoMenu = this._rootElt.getElementsByClassName("recentlyClosedTabsMenu")[0];

    // no restorable tabs, so disable menu
    if (this._ss.getClosedTabCount(window) == 0)
      undoMenu.setAttribute("disabled", true);
    else
      undoMenu.removeAttribute("disabled");
  },

  /**
    * Re-open a closed tab and put it to the end of the tab strip.
    * Used for a middle click.
    * @param aEvent
    *        The event when the user clicks the menu item
    */
  _undoCloseMiddleClick: function PHM__undoCloseMiddleClick(aEvent) {
    if (aEvent.button != 1)
      return;

    undoCloseTab(aEvent.originalTarget.value);
    gBrowser.moveTabToEnd();
  },

  /**
   * Populate when the history menu is opened
   */
  populateUndoSubmenu: function PHM_populateUndoSubmenu() {
    var undoMenu = this._rootElt.getElementsByClassName("recentlyClosedTabsMenu")[0];
    var undoPopup = undoMenu.firstChild;

    // remove existing menu items
    while (undoPopup.hasChildNodes())
      undoPopup.removeChild(undoPopup.firstChild);

    // no restorable tabs, so make sure menu is disabled, and return
    if (this._ss.getClosedTabCount(window) == 0) {
      undoMenu.setAttribute("disabled", true);
      return;
    }

    // enable menu
    undoMenu.removeAttribute("disabled");

    // populate menu
    var undoItems = JSON.parse(this._ss.getClosedTabData(window));
    for (var i = 0; i < undoItems.length; i++) {
      var m = document.createElement("menuitem");
      m.setAttribute("label", undoItems[i].title);
      if (undoItems[i].image) {
        let iconURL = undoItems[i].image;
        // don't initiate a connection just to fetch a favicon (see bug 467828)
        if (/^https?:/.test(iconURL))
          iconURL = "moz-anno:favicon:" + iconURL;
        m.setAttribute("image", iconURL);
      }
      m.setAttribute("class", "menuitem-iconic bookmark-item menuitem-with-favicon");
      m.setAttribute("value", i);
      m.setAttribute("oncommand", "undoCloseTab(" + i + ");");

      // Set the targetURI attribute so it will be shown in tooltip and trigger
      // onLinkHovered. SessionStore uses one-based indexes, so we need to
      // normalize them.
      let tabData = undoItems[i].state;
      let activeIndex = (tabData.index || tabData.entries.length) - 1;
      if (activeIndex >= 0 && tabData.entries[activeIndex])
        m.setAttribute("targetURI", tabData.entries[activeIndex].url);

      m.addEventListener("click", this._undoCloseMiddleClick, false);
      if (i == 0)
        m.setAttribute("key", "key_undoCloseTab");
      undoPopup.appendChild(m);
    }

    // "Restore All Tabs"
    var strings = gNavigatorBundle;
    undoPopup.appendChild(document.createElement("menuseparator"));
    m = undoPopup.appendChild(document.createElement("menuitem"));
    m.id = "menu_restoreAllTabs";
    m.setAttribute("label", strings.getString("menuRestoreAllTabs.label"));
    m.addEventListener("command", function() {
      for (var i = 0; i < undoItems.length; i++)
        undoCloseTab();
    }, false);
  },

  toggleRecentlyClosedWindows: function PHM_toggleRecentlyClosedWindows() {
    // enable/disable the Recently Closed Windows sub menu
    var undoMenu = this._rootElt.getElementsByClassName("recentlyClosedWindowsMenu")[0];

    // no restorable windows, so disable menu
    if (this._ss.getClosedWindowCount() == 0)
      undoMenu.setAttribute("disabled", true);
    else
      undoMenu.removeAttribute("disabled");
  },

  /**
   * Populate when the history menu is opened
   */
  populateUndoWindowSubmenu: function PHM_populateUndoWindowSubmenu() {
    let undoMenu = this._rootElt.getElementsByClassName("recentlyClosedWindowsMenu")[0];
    let undoPopup = undoMenu.firstChild;
    let menuLabelString = gNavigatorBundle.getString("menuUndoCloseWindowLabel");
    let menuLabelStringSingleTab =
      gNavigatorBundle.getString("menuUndoCloseWindowSingleTabLabel");

    // remove existing menu items
    while (undoPopup.hasChildNodes())
      undoPopup.removeChild(undoPopup.firstChild);

    // no restorable windows, so make sure menu is disabled, and return
    if (this._ss.getClosedWindowCount() == 0) {
      undoMenu.setAttribute("disabled", true);
      return;
    }

    // enable menu
    undoMenu.removeAttribute("disabled");

    // populate menu
    let undoItems = JSON.parse(this._ss.getClosedWindowData());
    for (let i = 0; i < undoItems.length; i++) {
      let undoItem = undoItems[i];
      let otherTabsCount = undoItem.tabs.length - 1;
      let label = (otherTabsCount == 0) ? menuLabelStringSingleTab
                                        : PluralForm.get(otherTabsCount, menuLabelString);
      let menuLabel = label.replace("#1", undoItem.title)
                           .replace("#2", otherTabsCount);
      let m = document.createElement("menuitem");
      m.setAttribute("label", menuLabel);
      let selectedTab = undoItem.tabs[undoItem.selected - 1];
      if (selectedTab.attributes.image) {
        let iconURL = selectedTab.attributes.image;
        // don't initiate a connection just to fetch a favicon (see bug 467828)
        if (/^https?:/.test(iconURL))
          iconURL = "moz-anno:favicon:" + iconURL;
        m.setAttribute("image", iconURL);
      }
      m.setAttribute("class", "menuitem-iconic bookmark-item menuitem-with-favicon");
      m.setAttribute("oncommand", "undoCloseWindow(" + i + ");");

      // Set the targetURI attribute so it will be shown in tooltip.
      // SessionStore uses one-based indexes, so we need to normalize them.
      let activeIndex = (selectedTab.index || selectedTab.entries.length) - 1;
      if (activeIndex >= 0 && selectedTab.entries[activeIndex])
        m.setAttribute("targetURI", selectedTab.entries[activeIndex].url);

      if (i == 0)
        m.setAttribute("key", "key_undoCloseWindow");
      undoPopup.appendChild(m);
    }

    // "Open All in Windows"
    undoPopup.appendChild(document.createElement("menuseparator"));
    let m = undoPopup.appendChild(document.createElement("menuitem"));
    m.id = "menu_restoreAllWindows";
    m.setAttribute("label", gNavigatorBundle.getString("menuRestoreAllWindows.label"));
    m.setAttribute("oncommand",
      "for (var i = 0; i < " + undoItems.length + "; i++) undoCloseWindow();");
  },

  toggleTabsFromOtherComputers: function PHM_toggleTabsFromOtherComputers() {
    // This is a no-op if MOZ_SERVICES_SYNC isn't defined
//@line 644 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-places.js"
    // Enable/disable the Tabs From Other Computers menu. Some of the menus handled
    // by HistoryMenu do not have this menuitem.
    let menuitem = this._rootElt.getElementsByClassName("syncTabsMenuItem")[0];
    if (!menuitem)
      return;

    // If Sync isn't configured yet, then don't show the menuitem.
    if (Weave.Status.checkSetup() == Weave.CLIENT_NOT_CONFIGURED ||
        Weave.Svc.Prefs.get("firstSync", "") == "notReady") {
      menuitem.setAttribute("hidden", true);
      return;
    }

    // The tabs engine might never be inited (if services.sync.registerEngines
    // is modified), so make sure we avoid undefined errors.
    let enabled = Weave.Service.isLoggedIn &&
                  Weave.Service.engineManager.get("tabs") &&
                  Weave.Service.engineManager.get("tabs").enabled;
    menuitem.setAttribute("disabled", !enabled);
    menuitem.setAttribute("hidden", false);
//@line 665 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-places.js"
  },

  _onPopupShowing: function HM__onPopupShowing(aEvent) {
    PlacesMenu.prototype._onPopupShowing.apply(this, arguments);

    // Don't handle events for submenus.
    if (aEvent.target != aEvent.currentTarget)
      return;

    this.toggleRecentlyClosedTabs();
    this.toggleRecentlyClosedWindows();
    this.toggleTabsFromOtherComputers();
  },

  _onCommand: function HM__onCommand(aEvent) {
    let placesNode = aEvent.target._placesNode;
    if (placesNode) {
      if (!PrivateBrowsingUtils.isWindowPrivate(window))
        PlacesUIUtils.markPageAsTyped(placesNode.uri);
      openUILink(placesNode.uri, aEvent, { ignoreAlt: true });
    }
  }
};

/**
 * Functions for handling events in the Bookmarks Toolbar and menu.
 */
var BookmarksEventHandler = {
  /**
   * Handler for click event for an item in the bookmarks toolbar or menu.
   * Menus and submenus from the folder buttons bubble up to this handler.
   * Left-click is handled in the onCommand function.
   * When items are middle-clicked (or clicked with modifier), open in tabs.
   * If the click came through a menu, close the menu.
   * @param aEvent
   *        DOMEvent for the click
   * @param aView
   *        The places view which aEvent should be associated with.
   */
  onClick: function BEH_onClick(aEvent, aView) {
    // Only handle middle-click or left-click with modifiers.
//@line 709 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-places.js"
    var modifKey = aEvent.ctrlKey || aEvent.shiftKey;
//@line 711 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-places.js"
    if (aEvent.button == 2 || (aEvent.button == 0 && !modifKey))
      return;

    var target = aEvent.originalTarget;
    // If this event bubbled up from a menu or menuitem, close the menus.
    // Do this before opening tabs, to avoid hiding the open tabs confirm-dialog.
    if (target.localName == "menu" || target.localName == "menuitem") {
      for (node = target.parentNode; node; node = node.parentNode) {
        if (node.localName == "menupopup")
          node.hidePopup();
        else if (node.localName != "menu" &&
                 node.localName != "splitmenu" &&
                 node.localName != "hbox" &&
                 node.localName != "vbox" )
          break;
      }
    }

    if (target._placesNode && PlacesUtils.nodeIsContainer(target._placesNode)) {
      // Don't open the root folder in tabs when the empty area on the toolbar
      // is middle-clicked or when a non-bookmark item except for Open in Tabs)
      // in a bookmarks menupopup is middle-clicked.
      if (target.localName == "menu" || target.localName == "toolbarbutton")
        PlacesUIUtils.openContainerNodeInTabs(target._placesNode, aEvent, aView);
    }
    else if (aEvent.button == 1) {
      // left-clicks with modifier are already served by onCommand
      this.onCommand(aEvent, aView);
    }
  },

  /**
   * Handler for command event for an item in the bookmarks toolbar.
   * Menus and submenus from the folder buttons bubble up to this handler.
   * Opens the item.
   * @param aEvent 
   *        DOMEvent for the command
   * @param aView
   *        The places view which aEvent should be associated with.
   */
  onCommand: function BEH_onCommand(aEvent, aView) {
    var target = aEvent.originalTarget;
    if (target._placesNode)
      PlacesUIUtils.openNodeWithEvent(target._placesNode, aEvent, aView);
  },

  fillInBHTooltip: function BEH_fillInBHTooltip(aDocument, aEvent) {
    var node;
    var cropped = false;
    var targetURI;

    if (aDocument.tooltipNode.localName == "treechildren") {
      var tree = aDocument.tooltipNode.parentNode;
      var row = {}, column = {};
      var tbo = tree.treeBoxObject;
      tbo.getCellAt(aEvent.clientX, aEvent.clientY, row, column, {});
      if (row.value == -1)
        return false;
      node = tree.view.nodeForTreeIndex(row.value);
      cropped = tbo.isCellCropped(row.value, column.value);
    }
    else {
      // Check whether the tooltipNode is a Places node.
      // In such a case use it, otherwise check for targetURI attribute.
      var tooltipNode = aDocument.tooltipNode;
      if (tooltipNode._placesNode)
        node = tooltipNode._placesNode;
      else {
        // This is a static non-Places node.
        targetURI = tooltipNode.getAttribute("targetURI");
      }
    }

    if (!node && !targetURI)
      return false;

    // Show node.label as tooltip's title for non-Places nodes.
    var title = node ? node.title : tooltipNode.label;

    // Show URL only for Places URI-nodes or nodes with a targetURI attribute.
    var url;
    if (targetURI || PlacesUtils.nodeIsURI(node))
      url = targetURI || node.uri;

    // Show tooltip for containers only if their title is cropped.
    if (!cropped && !url)
      return false;

    var tooltipTitle = aDocument.getElementById("bhtTitleText");
    tooltipTitle.hidden = (!title || (title == url));
    if (!tooltipTitle.hidden)
      tooltipTitle.textContent = title;

    var tooltipUrl = aDocument.getElementById("bhtUrlText");
    tooltipUrl.hidden = !url;
    if (!tooltipUrl.hidden)
      tooltipUrl.value = url;

    // Show tooltip.
    return true;
  }
};


// Handles special drag and drop functionality for Places menus that are not
// part of a Places view (e.g. the bookmarks menu in the menubar).
var PlacesMenuDNDHandler = {
  _springLoadDelay: 350, // milliseconds
  _loadTimer: null,
  _closerTimer: null,

  /**
   * Called when the user enters the <menu> element during a drag.
   * @param   event
   *          The DragEnter event that spawned the opening. 
   */
  onDragEnter: function PMDH_onDragEnter(event) {
    // Opening menus in a Places popup is handled by the view itself.
    if (!this._isStaticContainer(event.target))
      return;

    this._loadTimer = Cc["@mozilla.org/timer;1"].createInstance(Ci.nsITimer);
    this._loadTimer.initWithCallback(function() {
      PlacesMenuDNDHandler._loadTimer = null;
      event.target.lastChild.setAttribute("autoopened", "true");
      event.target.lastChild.showPopup(event.target.lastChild);
    }, this._springLoadDelay, Ci.nsITimer.TYPE_ONE_SHOT);
    event.preventDefault();
    event.stopPropagation();
  },

  /**
   * Handles dragexit on the <menu> element.
   * @returns true if the element is a container element (menu or 
   *          menu-toolbarbutton), false otherwise.
   */
  onDragExit: function PMDH_onDragExit(event) {
    // Closing menus in a Places popup is handled by the view itself.
    if (!this._isStaticContainer(event.target))
      return;

    if (this._loadTimer) {
      this._loadTimer.cancel();
      this._loadTimer = null;
    }
    this._closeTimer = Cc["@mozilla.org/timer;1"].createInstance(Ci.nsITimer);
    this._closeTimer.initWithCallback(function() {
      this._closeTimer = null;
      let node = PlacesControllerDragHelper.currentDropTarget;
      let inHierarchy = false;
      while (node && !inHierarchy) {
        inHierarchy = node == event.target;
        node = node.parentNode;
      }
      if (!inHierarchy && event.target.lastChild &&
          event.target.lastChild.hasAttribute("autoopened")) {
        event.target.lastChild.removeAttribute("autoopened");
        event.target.lastChild.hidePopup();
      }
    }, this._springLoadDelay, Ci.nsITimer.TYPE_ONE_SHOT);
  },

  /**
   * Determines if a XUL element represents a static container.
   * @returns true if the element is a container element (menu or 
   *`         menu-toolbarbutton), false otherwise.
   */
  _isStaticContainer: function PMDH__isContainer(node) {
    let isMenu = node.localName == "menu" ||
                 (node.localName == "toolbarbutton" &&
                  node.getAttribute("type") == "menu");
    let isStatic = !("_placesNode" in node) && node.lastChild &&
                   node.lastChild.hasAttribute("placespopup") &&
                   !node.parentNode.hasAttribute("placespopup");
    return isMenu && isStatic;
  },

  /**
   * Called when the user drags over the <menu> element.
   * @param   event
   *          The DragOver event. 
   */
  onDragOver: function PMDH_onDragOver(event) {
    let ip = new InsertionPoint(PlacesUtils.bookmarksMenuFolderId,
                                PlacesUtils.bookmarks.DEFAULT_INDEX,
                                Ci.nsITreeView.DROP_ON);
    if (ip && PlacesControllerDragHelper.canDrop(ip, event.dataTransfer))
      event.preventDefault();

    event.stopPropagation();
  },

  /**
   * Called when the user drops on the <menu> element.
   * @param   event
   *          The Drop event. 
   */
  onDrop: function PMDH_onDrop(event) {
    // Put the item at the end of bookmark menu.
    let ip = new InsertionPoint(PlacesUtils.bookmarksMenuFolderId,
                                PlacesUtils.bookmarks.DEFAULT_INDEX,
                                Ci.nsITreeView.DROP_ON);
    PlacesControllerDragHelper.onDrop(ip, event.dataTransfer);
    event.stopPropagation();
  }
};


var PlacesStarButton = {
  _hasBookmarksObserver: false,
  uninit: function PSB_uninit()
  {
    if (this._hasBookmarksObserver) {
      PlacesUtils.removeLazyBookmarkObserver(this);
    }
    if (this._pendingStmt) {
      this._pendingStmt.cancel();
      delete this._pendingStmt;
    }
  },

  QueryInterface: XPCOMUtils.generateQI([
    Ci.nsINavBookmarkObserver
  ]),

  get _starredTooltip()
  {
    delete this._starredTooltip;
    return this._starredTooltip =
      gNavigatorBundle.getString("starButtonOn.tooltip");
  },
  get _unstarredTooltip()
  {
    delete this._unstarredTooltip;
    return this._unstarredTooltip =
      gNavigatorBundle.getString("starButtonOff.tooltip");
  },

  updateState: function PSB_updateState()
  {
    this._starIcon = document.getElementById("star-button");
    if (!this._starIcon || (this._uri && gBrowser.currentURI.equals(this._uri))) {
      return;
    }

    // Reset tracked values.
    this._uri = gBrowser.currentURI;
    this._itemIds = [];

    if (this._pendingStmt) {
      this._pendingStmt.cancel();
      delete this._pendingStmt;
    }

    // We can load about:blank before the actual page, but there is no point in handling that page.
    if (isBlankPageURL(this._uri.spec)) {
      return;
    }

    this._pendingStmt = PlacesUtils.asyncGetBookmarkIds(this._uri, function (aItemIds, aURI) {
      // Safety check that the bookmarked URI equals the tracked one.
      if (!aURI.equals(this._uri)) {
        Components.utils.reportError("PlacesStarButton did not receive current URI");
        return;
      }

      // It's possible that onItemAdded gets called before the async statement
      // calls back.  For such an edge case, retain all unique entries from both
      // arrays.
      this._itemIds = this._itemIds.filter(
        function (id) aItemIds.indexOf(id) == -1
      ).concat(aItemIds);
      this._updateStateInternal();

      // Start observing bookmarks if needed.
      if (!this._hasBookmarksObserver) {
        try {
          PlacesUtils.addLazyBookmarkObserver(this);
          this._hasBookmarksObserver = true;
        } catch(ex) {
          Components.utils.reportError("PlacesStarButton failed adding a bookmarks observer: " + ex);
        }
      }

      delete this._pendingStmt;
    }, this);
  },

  _updateStateInternal: function PSB__updateStateInternal()
  {
    if (!this._starIcon) {
      return;
    }

    if (this._itemIds.length > 0) {
      this._starIcon.setAttribute("starred", "true");
      this._starIcon.setAttribute("tooltiptext", this._starredTooltip);
    }
    else {
      this._starIcon.removeAttribute("starred");
      this._starIcon.setAttribute("tooltiptext", this._unstarredTooltip);
    }
  },

  onClick: function PSB_onClick(aEvent)
  {
    // Ignore clicks on the star while we update its state.
    if (aEvent.button == 0 && !this._pendingStmt) {
      PlacesCommandHook.bookmarkCurrentPage(this._itemIds.length > 0);
    }
    // Don't bubble to the textbox, to avoid unwanted selection of the address.
    aEvent.stopPropagation();
  },

  // nsINavBookmarkObserver
  onItemAdded:
  function PSB_onItemAdded(aItemId, aFolder, aIndex, aItemType, aURI)
  {
    if (!this._starIcon) {
      return;
    }

    if (aURI && aURI.equals(this._uri)) {
      // If a new bookmark has been added to the tracked uri, register it.
      if (this._itemIds.indexOf(aItemId) == -1) {
        this._itemIds.push(aItemId);
        this._updateStateInternal();
      }
    }
  },

  onItemRemoved:
  function PSB_onItemRemoved(aItemId, aFolder, aIndex, aItemType)
  {
    if (!this._starIcon) {
      return;
    }

    let index = this._itemIds.indexOf(aItemId);
    // If one of the tracked bookmarks has been removed, unregister it.
    if (index != -1) {
      this._itemIds.splice(index, 1);
      this._updateStateInternal();
    }
  },

  onItemChanged:
  function PSB_onItemChanged(aItemId, aProperty, aIsAnnotationProperty,
                             aNewValue, aLastModified, aItemType)
  {
    if (!this._starIcon) {
      return;
    }

    if (aProperty == "uri") {
      let index = this._itemIds.indexOf(aItemId);
      // If the changed bookmark was tracked, check if it is now pointing to
      // a different uri and unregister it.
      if (index != -1 && aNewValue != this._uri.spec) {
        this._itemIds.splice(index, 1);
        this._updateStateInternal();
      }
      // If another bookmark is now pointing to the tracked uri, register it.
      else if (index == -1 && aNewValue == this._uri.spec) {
        this._itemIds.push(aItemId);
        this._updateStateInternal();
      }
    }
  },

  onBeginUpdateBatch: function () {},
  onEndUpdateBatch: function () {},
  onBeforeItemRemoved: function () {},
  onItemVisited: function () {},
  onItemMoved: function () {}
};


// This object handles the initialization and uninitialization of the bookmarks
// toolbar.  updateState is called when the browser window is opened and
// after closing the toolbar customization dialog.
let PlacesToolbarHelper = {
  _place: "place:folder=TOOLBAR",

  get _viewElt() {
    return document.getElementById("PlacesToolbar");
  },

  init: function PTH_init() {
    let viewElt = this._viewElt;
    if (!viewElt || viewElt._placesView)
      return;

    // If the bookmarks toolbar item is hidden because the parent toolbar is
    // collapsed or hidden (i.e. in a popup), spare the initialization.  Also,
    // there is no need to initialize the toolbar if customizing because
    // init() will be called when the customization is done.
    let toolbar = viewElt.parentNode.parentNode;
    if (toolbar.collapsed ||
        getComputedStyle(toolbar, "").display == "none" ||
        this._isCustomizing)
      return;

    new PlacesToolbar(this._place);
  },

  customizeStart: function PTH_customizeStart() {
    let viewElt = this._viewElt;
    if (viewElt && viewElt._placesView)
      viewElt._placesView.uninit();

    this._isCustomizing = true;
  },

  customizeDone: function PTH_customizeDone() {
    this._isCustomizing = false;
    this.init();
  }
};


// Handles the bookmarks menu button shown when the main menubar is hidden.
let BookmarksMenuButton = {
  get button() {
    return document.getElementById("bookmarks-menu-button");
  },

  get buttonContainer() {
    return document.getElementById("bookmarks-menu-button-container");
  },

  get personalToolbar() {
    delete this.personalToolbar;
    return this.personalToolbar = document.getElementById("PersonalToolbar");
  },

  get bookmarksToolbarItem() {
    return document.getElementById("personal-bookmarks");
  },

  init: function BMB_init() {
    this.updatePosition();

    // Any other stuff that does not regard the button itself should be
    // handled in the onPopupShowing handler, so it does not hit Ts.
  },

  _popupNeedsUpdate: {},
  onPopupShowing: function BMB_onPopupShowing(event) {
    // Don't handle events for submenus.
    if (event.target != event.currentTarget)
      return;

    let popup = event.target;
    let needsUpdate = this._popupNeedsUpdate[popup.id];

    // Check if popup contents need to be updated.  Note that if needsUpdate is
    // undefined we have never seen the popup, thus it should be updated.
    if (needsUpdate === false)
      return;
    this._popupNeedsUpdate[popup.id] = false;

    function getPlacesAnonymousElement(aAnonId)
      document.getAnonymousElementByAttribute(popup.parentNode,
                                              "placesanonid",
                                              aAnonId);

    let viewToolbarMenuitem = getPlacesAnonymousElement("view-toolbar");
    if (viewToolbarMenuitem) {
      // Update View bookmarks toolbar checkbox menuitem.
      viewToolbarMenuitem.setAttribute("checked",
                                       !this.personalToolbar.collapsed);
    }

    let toolbarMenuitem = getPlacesAnonymousElement("toolbar-autohide");
    if (toolbarMenuitem) {
      // If bookmarks items are visible, hide Bookmarks Toolbar menu and the
      // separator after it.
      toolbarMenuitem.collapsed = toolbarMenuitem.nextSibling.collapsed =
        isElementVisible(this.bookmarksToolbarItem);
    }
  },

  updatePosition: function BMB_updatePosition() {
    // Popups will have to be updated when the user customizes the UI, or
    // changes personal toolbar collapsed status.  Both of those location call
    // updatePosition(), so this is the only point asking for popup updates.
    for (let popupId in this._popupNeedsUpdate) {
      this._popupNeedsUpdate[popupId] = true;
    }

    let button = this.button;
    if (!button)
      return;

    // If the toolbar containing bookmarks is visible, we want to move the
    // button to bookmarksToolbarItem.
    let bookmarksToolbarItem = this.bookmarksToolbarItem;
    let bookmarksOnVisibleToolbar = bookmarksToolbarItem &&
                                    !bookmarksToolbarItem.parentNode.collapsed &&
                                    bookmarksToolbarItem.parentNode.getAttribute("autohide") != "true";

    // If the container has been moved by the user to the toolbar containing
    // bookmarks, we want to preserve the desired position.
    let container = this.buttonContainer;
    let containerNearBookmarks = container && bookmarksToolbarItem &&
                                 container.parentNode == bookmarksToolbarItem.parentNode;

    if (bookmarksOnVisibleToolbar && !containerNearBookmarks) {
      if (button.parentNode != bookmarksToolbarItem) {
        this._uninitView();
        bookmarksToolbarItem.appendChild(button);
      }
    }
    else {
      if (container && button.parentNode != container) {
        this._uninitView();
        container.appendChild(button);
      }
    }
    this._updateStyle();
  },

  _updateStyle: function BMB__updateStyle() {
    let button = this.button;
    if (!button)
      return;

    let container = this.buttonContainer;
    let containerOnPersonalToolbar = container &&
                                     (container.parentNode == this.personalToolbar ||
                                      container.parentNode.parentNode == this.personalToolbar);

    if (button.parentNode == this.bookmarksToolbarItem ||
        containerOnPersonalToolbar) {
      button.classList.add("bookmark-item");
      button.classList.remove("toolbarbutton-1");
    }
    else {
      button.classList.remove("bookmark-item");
      button.classList.add("toolbarbutton-1");
    }
  },

  _uninitView: function BMB__uninitView() {
    // When an element with a placesView attached is removed and re-inserted,
    // XBL reapplies the binding causing any kind of issues and possible leaks,
    // so kill current view and let popupshowing generate a new one.
    let button = this.button;
    if (button && button._placesView)
      button._placesView.uninit();
  },

  customizeStart: function BMB_customizeStart() {
    this._uninitView();
    let button = this.button;
    let container = this.buttonContainer;
    if (button && container && button.parentNode != container) {
      // Move button back to the container, so user can move or remove it.
      container.appendChild(button);
      this._updateStyle();
    }
  },

  customizeChange: function BMB_customizeChange() {
    this._updateStyle();
  },

  customizeDone: function BMB_customizeDone() {
    this.updatePosition();
  }
};
//@line 5 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

var gPluginHandler = {
  PLUGIN_SCRIPTED_STATE_NONE: 0,
  PLUGIN_SCRIPTED_STATE_FIRED: 1,
  PLUGIN_SCRIPTED_STATE_DONE: 2,

//@line 12 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
  get CrashSubmit() {
    delete this.CrashSubmit;
    Cu.import("resource://gre/modules/CrashSubmit.jsm", this);
    return this.CrashSubmit;
  },
//@line 18 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

  _getPluginInfo: function (pluginElement) {
    let tagMimetype;
    let pluginsPage;
    let pluginName = gNavigatorBundle.getString("pluginInfo.unknownPlugin");
    if (pluginElement instanceof HTMLAppletElement) {
      tagMimetype = "application/x-java-vm";
    } else {
      if (pluginElement instanceof HTMLObjectElement) {
        pluginsPage = pluginElement.getAttribute("codebase");
      } else {
        pluginsPage = pluginElement.getAttribute("pluginspage");
      }

      // only attempt if a pluginsPage is defined.
      if (pluginsPage) {
        let doc = pluginElement.ownerDocument;
        let docShell = findChildShell(doc, gBrowser.docShell, null);
        try {
          pluginsPage = makeURI(pluginsPage, doc.characterSet, docShell.currentURI).spec;
        } catch (ex) {
          pluginsPage = "";
        }
      }

      tagMimetype = pluginElement.QueryInterface(Ci.nsIObjectLoadingContent)
                                 .actualType;

      if (tagMimetype == "") {
        tagMimetype = pluginElement.type;
      }
    }

    if (tagMimetype) {
      let navMimeType = navigator.mimeTypes.namedItem(tagMimetype);
      if (navMimeType && navMimeType.enabledPlugin) {
        pluginName = navMimeType.enabledPlugin.name;
        pluginName = gPluginHandler.makeNicePluginName(pluginName);
      }
    }

    return { mimetype: tagMimetype,
             pluginsPage: pluginsPage,
             pluginName: pluginName };
  },

  // Map the plugin's name to a filtered version more suitable for user UI.
  makeNicePluginName : function (aName) {
    if (aName == "Shockwave Flash")
      return "Adobe Flash";

    // Clean up the plugin name by stripping off any trailing version numbers
    // or "plugin". EG, "Foo Bar Plugin 1.23_02" --> "Foo Bar"
    // Do this by first stripping the numbers, etc. off the end, and then
    // removing "Plugin" (and then trimming to get rid of any whitespace).
    // (Otherwise, something like "Java(TM) Plug-in 1.7.0_07" gets mangled)
    let newName = aName.replace(/[\s\d\.\-\_\(\)]+$/, "").replace(/\bplug-?in\b/i, "").trim();
    return newName;
  },

  isTooSmall : function (plugin, overlay) {
    // Is the <object>'s size too small to hold what we want to show?
    let pluginRect = plugin.getBoundingClientRect();
    // XXX bug 446693. The text-shadow on the submitted-report text at
    //     the bottom causes scrollHeight to be larger than it should be.
    let overflows = (overlay.scrollWidth > pluginRect.width) ||
                    (overlay.scrollHeight - 5 > pluginRect.height);
    return overflows;
  },

  addLinkClickCallback: function (linkNode, callbackName /*callbackArgs...*/) {
    // XXX just doing (callback)(arg) was giving a same-origin error. bug?
    let self = this;
    let callbackArgs = Array.prototype.slice.call(arguments).slice(2);
    linkNode.addEventListener("click",
                              function(evt) {
                                if (!evt.isTrusted)
                                  return;
                                evt.preventDefault();
                                if (callbackArgs.length == 0)
                                  callbackArgs = [ evt ];
                                (self[callbackName]).apply(self, callbackArgs);
                              },
                              true);

    linkNode.addEventListener("keydown",
                              function(evt) {
                                if (!evt.isTrusted)
                                  return;
                                if (evt.keyCode == evt.DOM_VK_RETURN) {
                                  evt.preventDefault();
                                  if (callbackArgs.length == 0)
                                    callbackArgs = [ evt ];
                                  evt.preventDefault();
                                  (self[callbackName]).apply(self, callbackArgs);
                                }
                              },
                              true);
  },

  // Helper to get the binding handler type from a plugin object
  _getBindingType : function(plugin) {
    if (!(plugin instanceof Ci.nsIObjectLoadingContent))
      return null;

    switch (plugin.pluginFallbackType) {
      case Ci.nsIObjectLoadingContent.PLUGIN_UNSUPPORTED:
        return "PluginNotFound";
      case Ci.nsIObjectLoadingContent.PLUGIN_DISABLED:
        return "PluginDisabled";
      case Ci.nsIObjectLoadingContent.PLUGIN_BLOCKLISTED:
        return "PluginBlocklisted";
      case Ci.nsIObjectLoadingContent.PLUGIN_OUTDATED:
        return "PluginOutdated";
      case Ci.nsIObjectLoadingContent.PLUGIN_CLICK_TO_PLAY:
        return "PluginClickToPlay";
      case Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_UPDATABLE:
        return "PluginVulnerableUpdatable";
      case Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_NO_UPDATE:
        return "PluginVulnerableNoUpdate";
      case Ci.nsIObjectLoadingContent.PLUGIN_PLAY_PREVIEW:
        return "PluginPlayPreview";
      default:
        // Not all states map to a handler
        return null;
    }
  },

  handleEvent : function(event) {
    let plugin = event.target;
    let doc = plugin.ownerDocument;

    // We're expecting the target to be a plugin.
    if (!(plugin instanceof Ci.nsIObjectLoadingContent))
      return;

    let eventType = event.type;
    if (eventType == "PluginBindingAttached") {
      // The plugin binding fires this event when it is created.
      // As an untrusted event, ensure that this object actually has a binding
      // and make sure we don't handle it twice
      let overlay = doc.getAnonymousElementByAttribute(plugin, "class", "mainBox");
      if (!overlay || overlay._bindingHandled) {
        return;
      }
      overlay._bindingHandled = true;

      // Lookup the handler for this binding
      eventType = this._getBindingType(plugin);
      if (!eventType) {
        // Not all bindings have handlers
        return;
      }
    }

    switch (eventType) {
      case "PluginCrashed":
        this.pluginInstanceCrashed(plugin, event);
        break;

      case "PluginNotFound":
        // For non-object plugin tags, register a click handler to install the
        // plugin. Object tags can, and often do, deal with that themselves,
        // so don't stomp on the page developers toes.
        if (!(plugin instanceof HTMLObjectElement)) {
          // We don't yet check to see if there's actually an installer available.
          let installStatus = doc.getAnonymousElementByAttribute(plugin, "class", "installStatus");
          installStatus.setAttribute("status", "ready");
          let iconStatus = doc.getAnonymousElementByAttribute(plugin, "class", "icon");
          iconStatus.setAttribute("status", "ready");

          let installLink = doc.getAnonymousElementByAttribute(plugin, "class", "installPluginLink");
          this.addLinkClickCallback(installLink, "installSinglePlugin", plugin);
        }
        /* FALLTHRU */

      case "PluginBlocklisted":
      case "PluginOutdated":
//@line 199 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
        this.pluginUnavailable(plugin, eventType);
        break;

      case "PluginVulnerableUpdatable":
        let updateLink = doc.getAnonymousElementByAttribute(plugin, "class", "checkForUpdatesLink");
        this.addLinkClickCallback(updateLink, "openPluginUpdatePage");
        /* FALLTHRU */

      case "PluginVulnerableNoUpdate":
      case "PluginClickToPlay":
        this._handleClickToPlayEvent(plugin);
        let overlay = doc.getAnonymousElementByAttribute(plugin, "class", "mainBox");
        let pluginName = this._getPluginInfo(plugin).pluginName;
        let messageString = gNavigatorBundle.getFormattedString("PluginClickToPlay", [pluginName]);
        let overlayText = doc.getAnonymousElementByAttribute(plugin, "class", "msg msgClickToPlay");
        overlayText.textContent = messageString;
        if (eventType == "PluginVulnerableUpdatable" ||
            eventType == "PluginVulnerableNoUpdate") {
          let vulnerabilityString = gNavigatorBundle.getString(eventType);
          let vulnerabilityText = doc.getAnonymousElementByAttribute(plugin, "anonid", "vulnerabilityStatus");
          vulnerabilityText.textContent = vulnerabilityString;
        }
        break;

      case "PluginPlayPreview":
        this._handlePlayPreviewEvent(plugin);
        break;

      case "PluginDisabled":
        let manageLink = doc.getAnonymousElementByAttribute(plugin, "class", "managePluginsLink");
        this.addLinkClickCallback(manageLink, "managePlugins");
        break;

      case "PluginScripted":
        let browser = gBrowser.getBrowserForDocument(doc.defaultView.top.document);
        if (browser._pluginScriptedState == this.PLUGIN_SCRIPTED_STATE_NONE) {
          browser._pluginScriptedState = this.PLUGIN_SCRIPTED_STATE_FIRED;
          setTimeout(function() {
            gPluginHandler.handlePluginScripted(this);
          }.bind(browser), 500);
        }
        break;
    }

    // Hide the in-content UI if it's too big. The crashed plugin handler already did this.
    if (eventType != "PluginCrashed") {
      let overlay = doc.getAnonymousElementByAttribute(plugin, "class", "mainBox");
      if (overlay != null && this.isTooSmall(plugin, overlay))
        overlay.style.visibility = "hidden";
    }
  },

  _notificationDisplayedOnce: false,
  handlePluginScripted: function PH_handlePluginScripted(aBrowser) {
    let contentWindow = aBrowser.contentWindow;
    if (!contentWindow)
      return;

    let cwu = contentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                            .getInterface(Ci.nsIDOMWindowUtils);
    let plugins = cwu.plugins.filter(function(plugin) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      return gPluginHandler.canActivatePlugin(objLoadingContent);
    });

    let haveVisibleCTPPlugin = plugins.some(function(plugin) {
      let doc = plugin.ownerDocument;
      let overlay = doc.getAnonymousElementByAttribute(plugin, "class", "mainBox");
      if (!overlay)
        return false;

      // if the plugin's style is 240x200, it's a good bet we set that in
      // toolkit/mozapps/plugins/content/pluginProblemContent.css
      // (meaning this plugin was never actually given a size, so it's really
      // not part of visible content)
      let computedStyle = contentWindow.getComputedStyle(plugin);
      let isInvisible = ((computedStyle.width == "240px" &&
                          computedStyle.height == "200px") ||
                         gPluginHandler.isTooSmall(plugin, overlay));
      return !isInvisible;
    });

    let notification = PopupNotifications.getNotification("click-to-play-plugins", aBrowser);
    if (notification && plugins.length > 0 && !haveVisibleCTPPlugin && !this._notificationDisplayedOnce) {
      notification.dismissed = false;
      PopupNotifications._update(notification.anchorElement);
      this._notificationDisplayedOnce = true;
    }

    aBrowser._pluginScriptedState = this.PLUGIN_SCRIPTED_STATE_DONE;
  },

  isKnownPlugin: function PH_isKnownPlugin(objLoadingContent) {
    return (objLoadingContent.getContentTypeForMIMEType(objLoadingContent.actualType) ==
            Ci.nsIObjectLoadingContent.TYPE_PLUGIN);
  },

  canActivatePlugin: function PH_canActivatePlugin(objLoadingContent) {
    // if this isn't a known plugin, we can't activate it
    // (this also guards pluginHost.getPermissionStringForType against
    // unexpected input)
    if (!gPluginHandler.isKnownPlugin(objLoadingContent))
      return false;

    let pluginHost = Cc["@mozilla.org/plugin/host;1"].getService(Ci.nsIPluginHost);
    let permissionString = pluginHost.getPermissionStringForType(objLoadingContent.actualType);
    let browser = gBrowser.getBrowserForDocument(objLoadingContent.ownerDocument.defaultView.top.document);
    let pluginPermission = Services.perms.testPermission(browser.currentURI, permissionString);

    return !objLoadingContent.activated &&
           pluginPermission != Ci.nsIPermissionManager.DENY_ACTION &&
           objLoadingContent.pluginFallbackType >= Ci.nsIObjectLoadingContent.PLUGIN_CLICK_TO_PLAY &&
           objLoadingContent.pluginFallbackType <= Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_NO_UPDATE;
  },

  activatePlugins: function PH_activatePlugins(aContentWindow) {
    let browser = gBrowser.getBrowserForDocument(aContentWindow.document);
    browser._clickToPlayAllPluginsActivated = true;
    let cwu = aContentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                            .getInterface(Ci.nsIDOMWindowUtils);
    let plugins = cwu.plugins;
    for (let plugin of plugins) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      if (gPluginHandler.canActivatePlugin(objLoadingContent))
        objLoadingContent.playPlugin();
    }
    let notification = PopupNotifications.getNotification("click-to-play-plugins", browser);
    if (notification)
      notification.remove();
  },

  activateSinglePlugin: function PH_activateSinglePlugin(aContentWindow, aPlugin) {
    let objLoadingContent = aPlugin.QueryInterface(Ci.nsIObjectLoadingContent);
    if (gPluginHandler.canActivatePlugin(objLoadingContent))
      objLoadingContent.playPlugin();

    let cwu = aContentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                            .getInterface(Ci.nsIDOMWindowUtils);
    let pluginNeedsActivation = gPluginHandler._pluginNeedsActivationExceptThese([aPlugin]);
    let browser = gBrowser.getBrowserForDocument(aContentWindow.document);
    let notification = PopupNotifications.getNotification("click-to-play-plugins", browser);
    if (notification) {
      notification.remove();
    }
    if (pluginNeedsActivation) {
      gPluginHandler._showClickToPlayNotification(browser);
    }
  },

  stopPlayPreview: function PH_stopPlayPreview(aPlugin, aPlayPlugin) {
    let objLoadingContent = aPlugin.QueryInterface(Ci.nsIObjectLoadingContent);
    if (objLoadingContent.activated)
      return;

    if (aPlayPlugin)
      objLoadingContent.playPlugin();
    else
      objLoadingContent.cancelPlayPreview();
  },

  newPluginInstalled : function(event) {
    // browser elements are anonymous so we can't just use target.
    var browser = event.originalTarget;
    // clear the plugin list, now that at least one plugin has been installed
    browser.missingPlugins = null;

    var notificationBox = gBrowser.getNotificationBox(browser);
    var notification = notificationBox.getNotificationWithValue("missing-plugins");
    if (notification)
      notificationBox.removeNotification(notification);

    // reload the browser to make the new plugin show.
    browser.reload();
  },

  // Callback for user clicking on a missing (unsupported) plugin.
  installSinglePlugin: function (plugin) {
    var missingPlugins = new Map();

    var pluginInfo = this._getPluginInfo(plugin);
    missingPlugins.set(pluginInfo.mimetype, pluginInfo);

    openDialog("chrome://mozapps/content/plugins/pluginInstallerWizard.xul",
               "PFSWindow", "chrome,centerscreen,resizable=yes",
               {plugins: missingPlugins, browser: gBrowser.selectedBrowser});
  },

  // Callback for user clicking on a disabled plugin
  managePlugins: function (aEvent) {
    BrowserOpenAddonsMgr("addons://list/plugin");
  },

  // Callback for user clicking on the link in a click-to-play plugin
  // (where the plugin has an update)
  openPluginUpdatePage: function (aEvent) {
    openURL(Services.urlFormatter.formatURLPref("plugins.update.url"));
  },

//@line 398 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
  // Callback for user clicking "submit a report" link
  submitReport : function(pluginDumpID, browserDumpID) {
    // The crash reporter wants a DOM element it can append an IFRAME to,
    // which it uses to submit a form. Let's just give it gBrowser.
    this.CrashSubmit.submit(pluginDumpID);
    if (browserDumpID)
      this.CrashSubmit.submit(browserDumpID);
  },
//@line 407 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

  // Callback for user clicking a "reload page" link
  reloadPage: function (browser) {
    browser.reload();
  },

  // Callback for user clicking the help icon
  openHelpPage: function () {
    openHelpLink("plugin-crashed", false);
  },

  // Event listener for click-to-play plugins.
  _handleClickToPlayEvent: function PH_handleClickToPlayEvent(aPlugin) {
    let doc = aPlugin.ownerDocument;
    let browser = gBrowser.getBrowserForDocument(doc.defaultView.top.document);
    let pluginHost = Cc["@mozilla.org/plugin/host;1"].getService(Ci.nsIPluginHost);
    let objLoadingContent = aPlugin.QueryInterface(Ci.nsIObjectLoadingContent);
    // guard against giving pluginHost.getPermissionStringForType a type
    // not associated with any known plugin
    if (!gPluginHandler.isKnownPlugin(objLoadingContent))
      return;
    let permissionString = pluginHost.getPermissionStringForType(objLoadingContent.actualType);
    let pluginPermission = Services.perms.testPermission(browser.currentURI, permissionString);

    let overlay = doc.getAnonymousElementByAttribute(aPlugin, "class", "mainBox");

    if (pluginPermission == Ci.nsIPermissionManager.DENY_ACTION) {
      if (overlay)
        overlay.style.visibility = "hidden";
      return;
    }

    let pluginInfo = this._getPluginInfo(aPlugin);
    if (browser._clickToPlayAllPluginsActivated ||
        browser._clickToPlayPluginsActivated.get(pluginInfo.pluginName)) {
      objLoadingContent.playPlugin();
      return;
    }

    if (overlay) {
      overlay.addEventListener("click", function(aEvent) {
        // Have to check that the target is not the link to update the plugin
        if (!(aEvent.originalTarget instanceof HTMLAnchorElement) &&
            aEvent.button == 0 && aEvent.isTrusted) {
          gPluginHandler.activateSinglePlugin(aEvent.target.ownerDocument.defaultView.top, aPlugin);
          aEvent.stopPropagation();
          aEvent.preventDefault();
        }
      }, true);
    }

    gPluginHandler._showClickToPlayNotification(browser);
  },

  _handlePlayPreviewEvent: function PH_handlePlayPreviewEvent(aPlugin) {
    let doc = aPlugin.ownerDocument;
    let previewContent = doc.getAnonymousElementByAttribute(aPlugin, "class", "previewPluginContent");
    let iframe = previewContent.getElementsByClassName("previewPluginContentFrame")[0];
    if (!iframe) {
      // lazy initialization of the iframe
      iframe = doc.createElementNS("http://www.w3.org/1999/xhtml", "iframe");
      iframe.className = "previewPluginContentFrame";
      previewContent.appendChild(iframe);

      // Force a style flush, so that we ensure our binding is attached.
      aPlugin.clientTop;
    }
    let pluginInfo = this._getPluginInfo(aPlugin);
    let playPreviewUri = "data:application/x-moz-playpreview;," + pluginInfo.mimetype;
    iframe.src = playPreviewUri;

    // MozPlayPlugin event can be dispatched from the extension chrome
    // code to replace the preview content with the native plugin
    previewContent.addEventListener("MozPlayPlugin", function playPluginHandler(aEvent) {
      if (!aEvent.isTrusted)
        return;

      previewContent.removeEventListener("MozPlayPlugin", playPluginHandler, true);

      let playPlugin = !aEvent.detail;
      gPluginHandler.stopPlayPreview(aPlugin, playPlugin);

      // cleaning up: removes overlay iframe from the DOM
      let iframe = previewContent.getElementsByClassName("previewPluginContentFrame")[0];
      if (iframe)
        previewContent.removeChild(iframe);
    }, true);
  },

  reshowClickToPlayNotification: function PH_reshowClickToPlayNotification() {
    let browser = gBrowser.selectedBrowser;
    if (gPluginHandler._pluginNeedsActivationExceptThese([]))
      gPluginHandler._showClickToPlayNotification(browser);
  },

  // returns true if there is a plugin on this page that needs activation
  // and isn't in the "except these" list
  _pluginNeedsActivationExceptThese: function PH_pluginNeedsActivationExceptThese(aExceptThese) {
    let contentWindow = gBrowser.selectedBrowser.contentWindow;
    let cwu = contentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                           .getInterface(Ci.nsIDOMWindowUtils);
    let pluginNeedsActivation = cwu.plugins.some(function(plugin) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      return (gPluginHandler.canActivatePlugin(objLoadingContent) &&
              aExceptThese.indexOf(plugin) < 0);
    });

    return pluginNeedsActivation;
  },

  /* Gets all plugins currently in the page of the given name */
  _getPluginsByName: function PH_getPluginsByName(aDOMWindowUtils, aName) {
    let plugins = [];
    for (let plugin of aDOMWindowUtils.plugins) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      if (gPluginHandler.canActivatePlugin(objLoadingContent)) {
        let pluginName = this._getPluginInfo(plugin).pluginName;
        if (aName == pluginName) {
          plugins.push(objLoadingContent);
        }
      }
    }
    return plugins;
  },

  _makeCenterActions: function PH_makeCenterActions(aBrowser) {
    let contentWindow = aBrowser.contentWindow;
    let cwu = contentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                           .getInterface(Ci.nsIDOMWindowUtils);
    let pluginsDictionary = new Map();
    for (let plugin of cwu.plugins) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      if (gPluginHandler.canActivatePlugin(objLoadingContent)) {
        let pluginName = this._getPluginInfo(plugin).pluginName;
        if (!pluginsDictionary.has(pluginName))
          pluginsDictionary.set(pluginName, []);
        pluginsDictionary.get(pluginName).push(objLoadingContent);
      }
    }

    let centerActions = [];
    for (let [pluginName, namedPluginArray] of pluginsDictionary) {
      let plugin = namedPluginArray[0];
      let warn = false;
      let warningText = "";
      let updateLink = Services.urlFormatter.formatURLPref("plugins.update.url");
      if (plugin.pluginFallbackType) {
        if (plugin.pluginFallbackType ==
              Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_UPDATABLE) {
          warn = true;
          warningText = gNavigatorBundle.getString("vulnerableUpdatablePluginWarning");
        }
        else if (plugin.pluginFallbackType ==
                   Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_NO_UPDATE) {
          warn = true;
          warningText = gNavigatorBundle.getString("vulnerableNoUpdatePluginWarning");
          updateLink = "";
        }
      }

      let action = {
        message: pluginName,
        warn: warn,
        warningText: warningText,
        updateLink: updateLink,
        label: gNavigatorBundle.getString("activateSinglePlugin"),
        callback: function() {
          let plugins = gPluginHandler._getPluginsByName(cwu, this.message);
          for (let objLoadingContent of plugins) {
            objLoadingContent.playPlugin();
          }
          aBrowser._clickToPlayPluginsActivated.set(this.message, true);

          let notification = PopupNotifications.getNotification("click-to-play-plugins", aBrowser);
          if (notification &&
              !gPluginHandler._pluginNeedsActivationExceptThese(plugins)) {
            notification.remove();
          }
        }
      };
      centerActions.push(action);
    }

    return centerActions;
  },

  _setPermissionForPlugins: function PH_setPermissionForPlugins(aBrowser, aPermission, aPluginList) {
    let pluginHost = Cc["@mozilla.org/plugin/host;1"].getService(Ci.nsIPluginHost);
    for (let plugin of aPluginList) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      // canActivatePlugin will return false if this isn't a known plugin type,
      // so the pluginHost.getPermissionStringForType call is protected
      if (gPluginHandler.canActivatePlugin(objLoadingContent)) {
        let permissionString = pluginHost.getPermissionStringForType(objLoadingContent.actualType);
        Services.perms.add(aBrowser.currentURI, permissionString, aPermission);
      }
    }
  },

  _showClickToPlayNotification: function PH_showClickToPlayNotification(aBrowser) {
    let contentWindow = aBrowser.contentWindow;
    let messageString = gNavigatorBundle.getString("activatePluginsMessage.message");
    let mainAction = {
      label: gNavigatorBundle.getString("activateAllPluginsMessage.label"),
      accessKey: gNavigatorBundle.getString("activatePluginsMessage.accesskey"),
      callback: function() { gPluginHandler.activatePlugins(contentWindow); }
    };
    let centerActions = gPluginHandler._makeCenterActions(aBrowser);
    let cwu = contentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                           .getInterface(Ci.nsIDOMWindowUtils);
    let haveVulnerablePlugin = cwu.plugins.some(function(plugin) {
      let objLoadingContent = plugin.QueryInterface(Ci.nsIObjectLoadingContent);
      return (gPluginHandler.canActivatePlugin(objLoadingContent) &&
              (objLoadingContent.pluginFallbackType == Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_UPDATABLE ||
               objLoadingContent.pluginFallbackType == Ci.nsIObjectLoadingContent.PLUGIN_VULNERABLE_NO_UPDATE));
    });
    if (haveVulnerablePlugin) {
      messageString = gNavigatorBundle.getString("vulnerablePluginsMessage");
    }
    let secondaryActions = [{
      label: gNavigatorBundle.getString("activatePluginsMessage.always"),
      accessKey: gNavigatorBundle.getString("activatePluginsMessage.always.accesskey"),
      callback: function () {
        gPluginHandler._setPermissionForPlugins(aBrowser, Ci.nsIPermissionManager.ALLOW_ACTION, cwu.plugins);
        gPluginHandler.activatePlugins(contentWindow);
      }
    },{
      label: gNavigatorBundle.getString("activatePluginsMessage.never"),
      accessKey: gNavigatorBundle.getString("activatePluginsMessage.never.accesskey"),
      callback: function () {
        gPluginHandler._setPermissionForPlugins(aBrowser, Ci.nsIPermissionManager.DENY_ACTION, cwu.plugins);
        let notification = PopupNotifications.getNotification("click-to-play-plugins", aBrowser);
        if (notification)
          notification.remove();
        gPluginHandler._removeClickToPlayOverlays(contentWindow);
      }
    }];
    let notification = PopupNotifications.getNotification("click-to-play-plugins", aBrowser);
    let dismissed = notification ? notification.dismissed : true;
    let options = { dismissed: dismissed, centerActions: centerActions };
    let icon = haveVulnerablePlugin ? "blocked-plugins-notification-icon" : "plugins-notification-icon"
    PopupNotifications.show(aBrowser, "click-to-play-plugins",
                            messageString, icon,
                            mainAction, secondaryActions, options);
  },

  _removeClickToPlayOverlays: function PH_removeClickToPlayOverlays(aContentWindow) {
    let doc = aContentWindow.document;
    let cwu = aContentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                            .getInterface(Ci.nsIDOMWindowUtils);
    for (let plugin of cwu.plugins) {
      let overlay = doc.getAnonymousElementByAttribute(plugin, "class", "mainBox");
      // for already activated plugins, there will be no overlay
      if (overlay)
        overlay.style.visibility = "hidden";
    }
  },

  // event listener for missing/blocklisted/outdated/carbonFailure plugins.
  pluginUnavailable: function (plugin, eventType) {
    let browser = gBrowser.getBrowserForDocument(plugin.ownerDocument
                                                       .defaultView.top.document);
    if (!browser.missingPlugins)
      browser.missingPlugins = new Map();

    var pluginInfo = this._getPluginInfo(plugin);
    browser.missingPlugins.set(pluginInfo.mimetype, pluginInfo);

    var notificationBox = gBrowser.getNotificationBox(browser);

    // Should only display one of these warnings per page.
    // In order of priority, they are: outdated > missing > blocklisted
    let outdatedNotification = notificationBox.getNotificationWithValue("outdated-plugins");
    let blockedNotification  = notificationBox.getNotificationWithValue("blocked-plugins");
    let missingNotification  = notificationBox.getNotificationWithValue("missing-plugins");


    function showBlocklistInfo() {
      var url = formatURL("extensions.blocklist.detailsURL", true);
      gBrowser.loadOneTab(url, {inBackground: false});
      return true;
    }

    function showOutdatedPluginsInfo() {
      gPrefService.setBoolPref("plugins.update.notifyUser", false);
      var url = formatURL("plugins.update.url", true);
      gBrowser.loadOneTab(url, {inBackground: false});
      return true;
    }

    function showPluginsMissing() {
      // get the urls of missing plugins
      var missingPlugins = gBrowser.selectedBrowser.missingPlugins;
      if (missingPlugins) {
        openDialog("chrome://mozapps/content/plugins/pluginInstallerWizard.xul",
                   "PFSWindow", "chrome,centerscreen,resizable=yes",
                   {plugins: missingPlugins, browser: gBrowser.selectedBrowser});
      }
    }

//@line 723 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

    let notifications = {
      PluginBlocklisted : {
                            barID   : "blocked-plugins",
                            iconURL : "chrome://mozapps/skin/plugins/notifyPluginBlocked.png",
                            message : gNavigatorBundle.getString("blockedpluginsMessage.title"),
                            buttons : [{
                                         label     : gNavigatorBundle.getString("blockedpluginsMessage.infoButton.label"),
                                         accessKey : gNavigatorBundle.getString("blockedpluginsMessage.infoButton.accesskey"),
                                         popup     : null,
                                         callback  : showBlocklistInfo
                                       },
                                       {
                                         label     : gNavigatorBundle.getString("blockedpluginsMessage.searchButton.label"),
                                         accessKey : gNavigatorBundle.getString("blockedpluginsMessage.searchButton.accesskey"),
                                         popup     : null,
                                         callback  : showOutdatedPluginsInfo
                                      }],
                          },
      PluginOutdated    : {
                            barID   : "outdated-plugins",
                            iconURL : "chrome://mozapps/skin/plugins/notifyPluginOutdated.png",
                            message : gNavigatorBundle.getString("outdatedpluginsMessage.title"),
                            buttons : [{
                                         label     : gNavigatorBundle.getString("outdatedpluginsMessage.updateButton.label"),
                                         accessKey : gNavigatorBundle.getString("outdatedpluginsMessage.updateButton.accesskey"),
                                         popup     : null,
                                         callback  : showOutdatedPluginsInfo
                                      }],
                          },
      PluginNotFound    : {
                            barID   : "missing-plugins",
                            iconURL : "chrome://mozapps/skin/plugins/notifyPluginGeneric.png",
                            message : gNavigatorBundle.getString("missingpluginsMessage.title"),
                            buttons : [{
                                         label     : gNavigatorBundle.getString("missingpluginsMessage.button.label"),
                                         accessKey : gNavigatorBundle.getString("missingpluginsMessage.button.accesskey"),
                                         popup     : null,
                                         callback  : showPluginsMissing
                                      }],
                            },
//@line 777 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
    };

    // If there is already an outdated plugin notification then do nothing
    if (outdatedNotification)
      return;

//@line 800 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

    if (eventType == "PluginBlocklisted") {
      if (gPrefService.getBoolPref("plugins.hide_infobar_for_missing_plugin")) // XXX add a new pref?
        return;

      if (blockedNotification || missingNotification)
        return;
    }
    else if (eventType == "PluginOutdated") {
      if (gPrefService.getBoolPref("plugins.hide_infobar_for_outdated_plugin"))
        return;

      // Cancel any notification about blocklisting/missing plugins
      if (blockedNotification)
        blockedNotification.close();
      if (missingNotification)
        missingNotification.close();
    }
    else if (eventType == "PluginNotFound") {
      if (gPrefService.getBoolPref("plugins.hide_infobar_for_missing_plugin"))
        return;

      if (missingNotification)
        return;

      // Cancel any notification about blocklisting plugins
      if (blockedNotification)
        blockedNotification.close();
    }

    let notify = notifications[eventType];
    notificationBox.appendNotification(notify.message, notify.barID, notify.iconURL,
                                       notificationBox.PRIORITY_WARNING_MEDIUM,
                                       notify.buttons);
  },

  // Crashed-plugin observer. Notified once per plugin crash, before events
  // are dispatched to individual plugin instances.
  pluginCrashed : function(subject, topic, data) {
    let propertyBag = subject;
    if (!(propertyBag instanceof Ci.nsIPropertyBag2) ||
        !(propertyBag instanceof Ci.nsIWritablePropertyBag2))
     return;

//@line 845 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
    let pluginDumpID = propertyBag.getPropertyAsAString("pluginDumpID");
    let browserDumpID= propertyBag.getPropertyAsAString("browserDumpID");
    let shouldSubmit = gCrashReporter.submitReports;
    let doPrompt     = true; // XXX followup to get via gCrashReporter

    // Submit automatically when appropriate.
    if (pluginDumpID && shouldSubmit && !doPrompt) {
      this.submitReport(pluginDumpID, browserDumpID);
      // Submission is async, so we can't easily show failure UI.
      propertyBag.setPropertyAsBool("submittedCrashReport", true);
    }
//@line 857 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
  },

  // Crashed-plugin event listener. Called for every instance of a
  // plugin in content.
  pluginInstanceCrashed: function (plugin, aEvent) {
    // Ensure the plugin and event are of the right type.
    if (!(aEvent instanceof Ci.nsIDOMDataContainerEvent))
      return;

    let submittedReport = aEvent.getData("submittedCrashReport");
    let doPrompt        = true; // XXX followup for .getData("doPrompt");
    let submitReports   = true; // XXX followup for .getData("submitReports");
    let pluginName      = aEvent.getData("pluginName");
    let pluginDumpID    = aEvent.getData("pluginDumpID");
    let browserDumpID   = aEvent.getData("browserDumpID");

    // Remap the plugin name to a more user-presentable form.
    pluginName = this.makeNicePluginName(pluginName);

    let messageString = gNavigatorBundle.getFormattedString("crashedpluginsMessage.title", [pluginName]);

    //
    // Configure the crashed-plugin placeholder.
    //

    // Force a layout flush so the binding is attached.
    plugin.clientTop;
    let doc = plugin.ownerDocument;
    let overlay = doc.getAnonymousElementByAttribute(plugin, "class", "mainBox");
    let statusDiv = doc.getAnonymousElementByAttribute(plugin, "class", "submitStatus");
//@line 888 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
    let status;

    // Determine which message to show regarding crash reports.
    if (submittedReport) { // submitReports && !doPrompt, handled in observer
      status = "submitted";
    }
    else if (!submitReports && !doPrompt) {
      status = "noSubmit";
    }
    else { // doPrompt
      status = "please";
      // XXX can we make the link target actually be blank?
      let pleaseLink = doc.getAnonymousElementByAttribute(
                            plugin, "class", "pleaseSubmitLink");
      this.addLinkClickCallback(pleaseLink, "submitReport",
                                pluginDumpID, browserDumpID);
    }

    // If we don't have a minidumpID, we can't (or didn't) submit anything.
    // This can happen if the plugin is killed from the task manager.
    if (!pluginDumpID) {
        status = "noReport";
    }

    statusDiv.setAttribute("status", status);

    let bottomLinks = doc.getAnonymousElementByAttribute(plugin, "class", "msg msgBottomLinks");
    bottomLinks.style.display = "block";
    let helpIcon = doc.getAnonymousElementByAttribute(plugin, "class", "helpIcon");
    this.addLinkClickCallback(helpIcon, "openHelpPage");

    // If we're showing the link to manually trigger report submission, we'll
    // want to be able to update all the instances of the UI for this crash to
    // show an updated message when a report is submitted.
    if (doPrompt) {
      let observer = {
        QueryInterface: XPCOMUtils.generateQI([Ci.nsIObserver,
                                               Ci.nsISupportsWeakReference]),
        observe : function(subject, topic, data) {
          let propertyBag = subject;
          if (!(propertyBag instanceof Ci.nsIPropertyBag2))
            return;
          // Ignore notifications for other crashes.
          if (propertyBag.get("minidumpID") != pluginDumpID)
            return;
          statusDiv.setAttribute("status", data);
        },

        handleEvent : function(event) {
            // Not expected to be called, just here for the closure.
        }
      }

      // Use a weak reference, so we don't have to remove it...
      Services.obs.addObserver(observer, "crash-report-status", true);
      // ...alas, now we need something to hold a strong reference to prevent
      // it from being GC. But I don't want to manually manage the reference's
      // lifetime (which should be no greater than the page).
      // Clever solution? Use a closue with an event listener on the document.
      // When the doc goes away, so do the listener references and the closure.
      doc.addEventListener("mozCleverClosureHack", observer, false);
    }
//@line 951 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

    let crashText = doc.getAnonymousElementByAttribute(plugin, "class", "msg msgCrashed");
    crashText.textContent = messageString;

    let browser = gBrowser.getBrowserForDocument(doc.defaultView.top.document);

    let link = doc.getAnonymousElementByAttribute(plugin, "class", "reloadLink");
    this.addLinkClickCallback(link, "reloadPage", browser);

    let notificationBox = gBrowser.getNotificationBox(browser);

    // Is the <object>'s size too small to hold what we want to show?
    if (this.isTooSmall(plugin, overlay)) {
        // Hide the overlay's contents. Use visibility style, so that it
        // doesn't collapse down to 0x0.
        overlay.style.visibility = "hidden";
        // If another plugin on the page was large enough to show our UI, we
        // don't want to show a notification bar.
        if (!doc.mozNoPluginCrashedNotification)
          showNotificationBar(pluginDumpID, browserDumpID);
    } else {
        // If a previous plugin on the page was too small and resulted in
        // adding a notification bar, then remove it because this plugin
        // instance it big enough to serve as in-content notification.
        hideNotificationBar();
        doc.mozNoPluginCrashedNotification = true;
    }

    function hideNotificationBar() {
      let notification = notificationBox.getNotificationWithValue("plugin-crashed");
      if (notification)
        notificationBox.removeNotification(notification, true);
    }

    function showNotificationBar(pluginDumpID, browserDumpID) {
      // If there's already an existing notification bar, don't do anything.
      let notification = notificationBox.getNotificationWithValue("plugin-crashed");
      if (notification)
        return;

      // Configure the notification bar
      let priority = notificationBox.PRIORITY_WARNING_MEDIUM;
      let iconURL = "chrome://mozapps/skin/plugins/notifyPluginCrashed.png";
      let reloadLabel = gNavigatorBundle.getString("crashedpluginsMessage.reloadButton.label");
      let reloadKey   = gNavigatorBundle.getString("crashedpluginsMessage.reloadButton.accesskey");
      let submitLabel = gNavigatorBundle.getString("crashedpluginsMessage.submitButton.label");
      let submitKey   = gNavigatorBundle.getString("crashedpluginsMessage.submitButton.accesskey");

      let buttons = [{
        label: reloadLabel,
        accessKey: reloadKey,
        popup: null,
        callback: function() { browser.reload(); },
      }];
//@line 1006 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"
      let submitButton = {
        label: submitLabel,
        accessKey: submitKey,
        popup: null,
          callback: function() { gPluginHandler.submitReport(pluginDumpID, browserDumpID); },
      };
      if (pluginDumpID)
        buttons.push(submitButton);
//@line 1015 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-plugins.js"

      let notification = notificationBox.appendNotification(messageString, "plugin-crashed",
                                                            iconURL, priority, buttons);

      // Add the "learn more" link.
      let XULNS = "http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul";
      let link = notification.ownerDocument.createElementNS(XULNS, "label");
      link.className = "text-link";
      link.setAttribute("value", gNavigatorBundle.getString("crashedpluginsMessage.learnMore"));
      let crashurl = formatURL("app.support.baseURL", true);
      crashurl += "plugin-crashed-notificationbar";
      link.href = crashurl;

      let description = notification.ownerDocument.getAnonymousElementByAttribute(notification, "anonid", "messageText");
      description.appendChild(link);

      // Remove the notfication when the page is reloaded.
      doc.defaultView.top.addEventListener("unload", function() {
        notificationBox.removeNotification(notification);
      }, false);
    }

  }
};
//@line 4 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-safebrowsing.js"

//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-safebrowsing.js"
var gSafeBrowsing = {

  setReportPhishingMenu: function() {

    // A phishing page will have a specific about:blocked content documentURI
    var isPhishingPage = content.document.documentURI.startsWith("about:blocked?e=phishingBlocked");

    // Show/hide the appropriate menu item.
    document.getElementById("menu_HelpPopup_reportPhishingtoolmenu")
            .hidden = isPhishingPage;
    document.getElementById("menu_HelpPopup_reportPhishingErrortoolmenu")
            .hidden = !isPhishingPage;

    var broadcasterId = isPhishingPage
                        ? "reportPhishingErrorBroadcaster"
                        : "reportPhishingBroadcaster";

    var broadcaster = document.getElementById(broadcasterId);
    if (!broadcaster)
      return;

    var uri = getBrowser().currentURI;
    if (uri && (uri.schemeIs("http") || uri.schemeIs("https")))
      broadcaster.removeAttribute("disabled");
    else
      broadcaster.setAttribute("disabled", true);
  },

  /**
   * Used to report a phishing page or a false positive
   * @param name String One of "Phish", "Error", "Malware" or "MalwareError"
   * @return String the report phishing URL.
   */
  getReportURL: function(name) {
    var reportUrl = SafeBrowsing.getReportURL(name);

    var pageUrl = gBrowser.currentURI.asciiSpec;
    reportUrl += "&url=" + encodeURIComponent(pageUrl);

    return reportUrl;
  }
}
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// The minimum sizes for the auto-resize panel code.
const PANEL_MIN_HEIGHT = 100;
const PANEL_MIN_WIDTH = 330;

XPCOMUtils.defineLazyModuleGetter(this, "SharedFrame",
  "resource:///modules/SharedFrame.jsm");

let SocialUI = {
  // Called on delayed startup to initialize the UI
  init: function SocialUI_init() {
    Services.obs.addObserver(this, "social:pref-changed", false);
    Services.obs.addObserver(this, "social:ambient-notification-changed", false);
    Services.obs.addObserver(this, "social:profile-changed", false);
    Services.obs.addObserver(this, "social:recommend-info-changed", false);
    Services.obs.addObserver(this, "social:frameworker-error", false);
    Services.obs.addObserver(this, "social:provider-set", false);
//@line 26 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"

    Services.prefs.addObserver("social.sidebar.open", this, false);
    Services.prefs.addObserver("social.toast-notifications.enabled", this, false);

    gBrowser.addEventListener("ActivateSocialFeature", this._activationEventHandler, true, true);

    // Called when we enter DOM full-screen mode.
    window.addEventListener("mozfullscreenchange", function () {
      SocialSidebar.update();
      SocialChatBar.update();
    });

    Social.init(this._providerReady.bind(this));
  },

  // Called on window unload
  uninit: function SocialUI_uninit() {
    Services.obs.removeObserver(this, "social:pref-changed");
    Services.obs.removeObserver(this, "social:ambient-notification-changed");
    Services.obs.removeObserver(this, "social:profile-changed");
    Services.obs.removeObserver(this, "social:recommend-info-changed");
    Services.obs.removeObserver(this, "social:frameworker-error");
    Services.obs.removeObserver(this, "social:provider-set");
//@line 52 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"

    Services.prefs.removeObserver("social.sidebar.open", this);
    Services.prefs.removeObserver("social.toast-notifications.enabled", this);
  },

  // Called once, after window load, once Social.jsm's provider has been set.
  _providerReady: function SocialUI_providerReady() {
    this._updateActiveUI();
    this._updateMenuItems();

    SocialChatBar.update();
    SocialShareButton.init();
    SocialMenu.populate();
    SocialToolbar.init();
    SocialSidebar.init();
  },

  // Social.provider has changed, update any state that depends on it.
  // Note: this method is not called when Social.provider is first set, during
  // the first window load.
  _updateProvider: function () {
    // XXX audit for handling nullness of social.provider
    this._updateActiveUI();
    this._updateMenuItems();

    SocialChatBar.update();
    SocialShareButton.updateProvider();
    SocialMenu.populate();
    SocialToolbar.updateProvider();
    SocialSidebar.update();
  },

  // The entire feature is being turned on/off.
  _updateEnabledState: function () {
    this._updateActiveUI();
    SocialChatBar.update();
    SocialSidebar.update();
    SocialShareButton.updateButtonHiddenState();
    SocialMenu.populate();
    SocialToolbar.updateButtonHiddenState();
    SocialToolbar.populateProviderMenus();
  },

  _matchesCurrentProvider: function (origin) {
    return Social.provider && Social.provider.origin == origin;
  },

  observe: function SocialUI_observe(subject, topic, data) {
    // Exceptions here sometimes don't get reported properly, report them
    // manually :(
    try {
      switch (topic) {
        case "social:provider-set":
          this._updateProvider();
          break;
        case "social:pref-changed":
          this._updateEnabledState();
          break;

        // Provider-specific notifications
        case "social:ambient-notification-changed":
          if (this._matchesCurrentProvider(data)) {
            SocialToolbar.updateButton();
            SocialMenu.populate();
          }
          break;
        case "social:profile-changed":
          if (this._matchesCurrentProvider(data)) {
            SocialToolbar.updateProfile();
            SocialShareButton.updateProfileInfo();
            SocialChatBar.update();
          }
          break;
        case "social:recommend-info-changed":
          if (this._matchesCurrentProvider(data)) {
            SocialShareButton.updateShareState();
          }
          break;
        case "social:frameworker-error":
          if (this.enabled && Social.provider.origin == data) {
            SocialSidebar.setSidebarErrorMessage("frameworker-error");
          }
          break;

        case "nsPref:changed":
          if (data == "social.sidebar.open") {
            SocialSidebar.update();
          } else if (data == "social.toast-notifications.enabled") {
            SocialToolbar.updateButton();
          }
          break;

//@line 151 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"
      }
    } catch (e) {
      Components.utils.reportError(e + "\n" + e.stack);
      throw e;
    }
  },

  nonBrowserWindowInit: function SocialUI_nonBrowserInit() {
    // Disable the social menu item in non-browser windows
    document.getElementById("menu_socialAmbientMenu").hidden = true;
  },

  // Miscellaneous helpers
  showProfile: function SocialUI_showProfile() {
    if (Social.haveLoggedInUser())
      openUILinkIn(Social.provider.profile.profileURL, "tab");
    else {
      // XXX Bug 789585 will implement an API for provider-specified login pages.
      openUILinkIn(Social.provider.origin, "tab");
    }
  },

  _updateActiveUI: function SocialUI_updateActiveUI() {
    // The "active" UI isn't dependent on there being a provider, just on
    // social being "active" (but also chromeless/PB)
    let enabled = Social.active && !this._chromeless
//@line 178 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"
                  && !PrivateBrowsingUtils.isWindowPrivate(window)
//@line 180 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"
        ;
    let broadcaster = document.getElementById("socialActiveBroadcaster");
    broadcaster.hidden = !enabled;

    let toggleCommand = document.getElementById("Social:Toggle");
    toggleCommand.setAttribute("hidden", enabled ? "false" : "true");

    if (enabled) {
      // We only need to update the command itself - all our menu items use it.
      let label = gNavigatorBundle.getFormattedString(Social.provider.enabled ?
                                                        "social.turnOff.label" :
                                                        "social.turnOn.label",
                                                      [Social.provider.name]);
      let accesskey = gNavigatorBundle.getString(Social.provider.enabled ?
                                                   "social.turnOff.accesskey" :
                                                   "social.turnOn.accesskey");
      toggleCommand.setAttribute("label", label);
      toggleCommand.setAttribute("accesskey", accesskey);
    }
  },

  _updateMenuItems: function () {
    if (!Social.provider)
      return;

    // The View->Sidebar and Menubar->Tools menu.
    for (let id of ["menu_socialSidebar", "menu_socialAmbientMenu"])
      document.getElementById(id).setAttribute("label", Social.provider.name);
  },

  // This handles "ActivateSocialFeature" events fired against content documents
  // in this window.
  _activationEventHandler: function SocialUI_activationHandler(e) {
    let targetDoc = e.target;

    // Event must be fired against the document
    if (!(targetDoc instanceof HTMLDocument))
      return;

    // Ignore events fired in background tabs
    if (targetDoc.defaultView.top != content)
      return;

    // Check that the associated document's origin is in our whitelist
    let providerOrigin = targetDoc.nodePrincipal.origin;
    let whitelist = Services.prefs.getCharPref("social.activation.whitelist");
    if (whitelist.split(",").indexOf(providerOrigin) == -1)
      return;

    // If we are in PB mode, we silently do nothing (bug 829404 exists to
    // do something sensible here...)
    if (PrivateBrowsingUtils.isWindowPrivate(window))
      return;

    // If the last event was received < 1s ago, ignore this one
    let now = Date.now();
    if (now - Social.lastEventReceived < 1000)
      return;
    Social.lastEventReceived = now;

    // Keep track of the old provider in case of undo
    let oldOrigin = Social.provider ? Social.provider.origin : "";

    // Enable the social functionality, and indicate that it was activated
    let provider = Social.activateFromOrigin(providerOrigin);

    // Provider to activate may not have been found
    if (!provider)
      return;

    // Show a warning, allow undoing the activation
    let description = document.getElementById("social-activation-message");
    let brandShortName = document.getElementById("bundle_brand").getString("brandShortName");
    let message = gNavigatorBundle.getFormattedString("social.activated.description",
                                                      [provider.name, brandShortName]);
    description.value = message;

    let notificationPanel = SocialUI.notificationPanel;
    // Set the origin being activated and the previously active one, to allow undo
    notificationPanel.setAttribute("origin", provider.origin);
    notificationPanel.setAttribute("oldorigin", oldOrigin);

    // Show the panel
    notificationPanel.hidden = false;
    setTimeout(function () {
      notificationPanel.openPopup(SocialToolbar.button, "bottomcenter topright");
    }, 0);
  },

  undoActivation: function SocialUI_undoActivation() {
    let origin = this.notificationPanel.getAttribute("origin");
    let oldOrigin = this.notificationPanel.getAttribute("oldorigin");
    Social.deactivateFromOrigin(origin, oldOrigin);
    this.notificationPanel.hidePopup();
  },

  get notificationPanel() {
    return document.getElementById("socialActivatedNotification");
  },

  closeSocialPanelForLinkTraversal: function (target, linkNode) {
    // No need to close the panel if this traversal was not retargeted
    if (target == "" || target == "_self")
      return;

    // Check to see whether this link traversal was in a social panel
    let win = linkNode.ownerDocument.defaultView;
    let container = win.QueryInterface(Ci.nsIInterfaceRequestor)
                                  .getInterface(Ci.nsIWebNavigation)
                                  .QueryInterface(Ci.nsIDocShell)
                                  .chromeEventHandler;
    let containerParent = container.parentNode;
    if (containerParent.classList.contains("social-panel") &&
        containerParent instanceof Ci.nsIDOMXULPopupElement) {
      containerParent.hidePopup();
    }
  },

  disableWithConfirmation: function SocialUI_disableWithConfirmation() {
    let brandShortName = document.getElementById("bundle_brand").getString("brandShortName");
    let dialogTitle = gNavigatorBundle.getFormattedString("social.remove.confirmationOK",
                                                          [Social.provider.name]);
    let text = gNavigatorBundle.getFormattedString("social.remove.confirmationLabel",
                                                   [Social.provider.name, brandShortName]);
    let okButtonText = dialogTitle;

    let ps = Services.prompt;
    let flags = ps.BUTTON_TITLE_IS_STRING * ps.BUTTON_POS_0 +
                ps.BUTTON_TITLE_CANCEL * ps.BUTTON_POS_1 +
                ps.BUTTON_POS_0_DEFAULT;

    let confirmationIndex = ps.confirmEx(null, dialogTitle, text, flags,
                                         okButtonText, null, null, null, {});
    if (confirmationIndex == 0) {
      Social.deactivateFromOrigin(Social.provider.origin);
    }
  },

  get _chromeless() {
    // Is this a popup window that doesn't want chrome shown?
    let docElem = document.documentElement;
    let chromeless = docElem.getAttribute("chromehidden").indexOf("extrachrome") >= 0;
    // This property is "fixed" for a window, so avoid doing the check above
    // multiple times...
    delete this._chromeless;
    this._chromeless = chromeless;
    return chromeless;
  },

  get enabled() {
    // Returns whether social is enabled *for this window*.
    if (this._chromeless
//@line 333 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"
        || PrivateBrowsingUtils.isWindowPrivate(window)
//@line 335 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-social.js"
       )
      return false;
    return !!(Social.active && Social.provider && Social.provider.enabled);
  },

}

let SocialChatBar = {
  get chatbar() {
    return document.getElementById("pinnedchats");
  },
  // Whether the chatbar is available for this window.  Note that in full-screen
  // mode chats are available, but not shown.
  get isAvailable() {
    return SocialUI.enabled && Social.haveLoggedInUser();
  },
  // Does this chatbar have any chats (whether minimized, collapsed or normal)
  get hasChats() {
    return !!this.chatbar.firstElementChild;
  },
  openChat: function(aProvider, aURL, aCallback, aMode) {
    if (this.isAvailable)
      this.chatbar.openChat(aProvider, aURL, aCallback, aMode);
  },
  update: function() {
    let command = document.getElementById("Social:FocusChat");
    if (!this.isAvailable) {
      this.chatbar.removeAll();
      command.hidden = true;
    } else {
      this.chatbar.hidden = command.hidden = document.mozFullScreen;
    }
    command.setAttribute("disabled", command.hidden ? "true" : "false");
  },
  focus: function SocialChatBar_focus() {
    this.chatbar.focus();
  }
}

function sizeSocialPanelToContent(panel, iframe) {
  // FIXME: bug 764787: Maybe we can use nsIDOMWindowUtils.getRootBounds() here?
  let doc = iframe.contentDocument;
  if (!doc || !doc.body) {
    return;
  }
  let body = doc.body;
  // offsetHeight/Width don't include margins, so account for that.
  let cs = doc.defaultView.getComputedStyle(body);
  let computedHeight = parseInt(cs.marginTop) + body.offsetHeight + parseInt(cs.marginBottom);
  let height = Math.max(computedHeight, PANEL_MIN_HEIGHT);
  let computedWidth = parseInt(cs.marginLeft) + body.offsetWidth + parseInt(cs.marginRight);
  let width = Math.max(computedWidth, PANEL_MIN_WIDTH);
  let wDiff = width - iframe.getBoundingClientRect().width;
  // A panel resize will move the right margin - if that is where the anchor
  // arrow is, the arrow will be mis-aligned from the anchor.  So we move the
  // popup to compensate for that.  See bug 799014.
  if (wDiff !== 0 && panel.getAttribute("side") == "right") {
    let box = panel.boxObject;
    panel.moveTo(box.screenX - wDiff, box.screenY);
  }
  iframe.style.height = height + "px";
  iframe.style.width = width + "px";
}

function DynamicResizeWatcher() {
  this._mutationObserver = null;
}

DynamicResizeWatcher.prototype = {
  start: function DynamicResizeWatcher_start(panel, iframe) {
    this.stop(); // just in case...
    let doc = iframe.contentDocument;
    this._mutationObserver = new iframe.contentWindow.MutationObserver(function(mutations) {
      sizeSocialPanelToContent(panel, iframe);
    });
    // Observe anything that causes the size to change.
    let config = {attributes: true, characterData: true, childList: true, subtree: true};
    this._mutationObserver.observe(doc, config);
    // and since this may be setup after the load event has fired we do an
    // initial resize now.
    sizeSocialPanelToContent(panel, iframe);
  },
  stop: function DynamicResizeWatcher_stop() {
    if (this._mutationObserver) {
      try {
        this._mutationObserver.disconnect();
      } catch (ex) {
        // may get "TypeError: can't access dead object" which seems strange,
        // but doesn't seem to indicate a real problem, so ignore it...
      }
      this._mutationObserver = null;
    }
  }
}

let SocialFlyout = {
  get panel() {
    return document.getElementById("social-flyout-panel");
  },

  dispatchPanelEvent: function(name) {
    let doc = this.panel.firstChild.contentDocument;
    let evt = doc.createEvent("CustomEvent");
    evt.initCustomEvent(name, true, true, {});
    doc.documentElement.dispatchEvent(evt);
  },

  _createFrame: function() {
    let panel = this.panel;
    if (!SocialUI.enabled || panel.firstChild)
      return;
    // create and initialize the panel for this window
    let iframe = document.createElement("iframe");
    iframe.setAttribute("type", "content");
    iframe.setAttribute("class", "social-panel-frame");
    iframe.setAttribute("flex", "1");
    iframe.setAttribute("origin", Social.provider.origin);
    panel.appendChild(iframe);
  },

  setUpProgressListener: function SF_setUpProgressListener() {
    if (!this._progressListenerSet) {
      this._progressListenerSet = true;
      // Force a layout flush by calling .clientTop so
      // that the docShell of this frame is created
      this.panel.firstChild.clientTop;
      this.panel.firstChild.docShell.QueryInterface(Ci.nsIInterfaceRequestor)
                                    .getInterface(Ci.nsIWebProgress)
                                    .addProgressListener(new SocialErrorListener("flyout"),
                                                         Ci.nsIWebProgress.NOTIFY_STATE_REQUEST |
                                                         Ci.nsIWebProgress.NOTIFY_LOCATION);
    }
  },

  setFlyoutErrorMessage: function SF_setFlyoutErrorMessage() {
    let iframe = this.panel.firstChild;
    if (!iframe)
      return;

    iframe.removeAttribute("src");
    iframe.webNavigation.loadURI("about:socialerror?mode=compactInfo", null, null, null, null);
    sizeSocialPanelToContent(this.panel, iframe);
  },

  unload: function() {
    let panel = this.panel;
    panel.hidePopup();
    if (!panel.firstChild)
      return
    panel.removeChild(panel.firstChild);
  },

  onShown: function(aEvent) {
    let panel = this.panel;
    let iframe = panel.firstChild;
    this._dynamicResizer = new DynamicResizeWatcher();
    iframe.docShell.isActive = true;
    iframe.docShell.isAppTab = true;
    if (iframe.contentDocument.readyState == "complete") {
      this._dynamicResizer.start(panel, iframe);
      this.dispatchPanelEvent("socialFrameShow");
    } else {
      // first time load, wait for load and dispatch after load
      iframe.addEventListener("load", function panelBrowserOnload(e) {
        iframe.removeEventListener("load", panelBrowserOnload, true);
        setTimeout(function() {
          if (SocialFlyout._dynamicResizer) { // may go null if hidden quickly
            SocialFlyout._dynamicResizer.start(panel, iframe);
            SocialFlyout.dispatchPanelEvent("socialFrameShow");
          }
        }, 0);
      }, true);
    }
  },

  onHidden: function(aEvent) {
    this._dynamicResizer.stop();
    this._dynamicResizer = null;
    this.panel.firstChild.docShell.isActive = false;
    this.dispatchPanelEvent("socialFrameHide");
  },

  open: function(aURL, yOffset, aCallback) {
    // Hide any other social panels that may be open.
    document.getElementById("social-notification-panel").hidePopup();

    if (!SocialUI.enabled)
      return;
    let panel = this.panel;
    if (!panel.firstChild)
      this._createFrame();
    panel.hidden = false;
    let iframe = panel.firstChild;

    let src = iframe.getAttribute("src");
    if (src != aURL) {
      iframe.addEventListener("load", function documentLoaded() {
        iframe.removeEventListener("load", documentLoaded, true);
        if (aCallback) {
          try {
            aCallback(iframe.contentWindow);
          } catch(e) {
            Cu.reportError(e);
          }
        }
      }, true);
      iframe.setAttribute("src", aURL);
    }
    else if (aCallback) {
      try {
        aCallback(iframe.contentWindow);
      } catch(e) {
        Cu.reportError(e);
      }
    }

    sizeSocialPanelToContent(panel, iframe);
    let anchor = document.getElementById("social-sidebar-browser");
    if (panel.state == "open") {
      // this is painful - there is no way to say "move to a new anchor offset",
      // only "move to new screen pos".  So we remember the last yOffset,
      // calculate the adjustment needed to the new yOffset, then calc the
      // screen Y position.
      let yAdjust = yOffset - this.yOffset;
      let box = panel.boxObject;
      panel.moveTo(box.screenX, box.screenY + yAdjust);
    } else {
      panel.openPopup(anchor, "start_before", 0, yOffset, false, false);
      this.setUpProgressListener();
    }
    this.yOffset = yOffset;
  }
}

let SocialShareButton = {
  // Called once, after window load, when the Social.provider object is initialized
  init: function SSB_init() {
    this.updateProvider();
  },

  // Called when the Social.provider changes
  updateProvider: function () {
    this.updateButtonHiddenState();
    if (!Social.provider)
      return;
    this.updateProfileInfo();
  },

  // Called when the provider's profile info changes (or when the provider
  // changes, via updateProvider)
  updateProfileInfo: function SSB_updateProfileInfo() {
    let profileRow = document.getElementById("unsharePopupHeader");
    let profile = SocialUI.enabled ? Social.provider.profile : null;
    if (profile && profile.displayName) {
      profileRow.hidden = false;
      let portrait = document.getElementById("socialUserPortrait");
      portrait.setAttribute("src", profile.portrait || "chrome://global/skin/icons/information-32.png");
      let displayName = document.getElementById("socialUserDisplayName");
      displayName.setAttribute("label", profile.displayName);
    } else {
      profileRow.hidden = true;
      this.updateButtonHiddenState();
    }
  },

  get shareButton() {
    return document.getElementById("share-button");
  },
  get unsharePopup() {
    return document.getElementById("unsharePopup");
  },

  dismissUnsharePopup: function SSB_dismissUnsharePopup() {
    this.unsharePopup.hidePopup();
  },

  canSharePage: function SSB_canSharePage(aURI) {
    // We only allow sharing of http or https
    return aURI && (aURI.schemeIs('http') || aURI.schemeIs('https'));
  },

  updateButtonHiddenState: function SSB_updateButtonHiddenState() {
    let shareButton = this.shareButton;
    if (shareButton)
      shareButton.hidden = !SocialUI.enabled || Social.provider.recommendInfo == null ||
                           !Social.haveLoggedInUser() ||
                           !this.canSharePage(gBrowser.currentURI);

    // also update the relevent command's disabled state so the keyboard
    // shortcut only works when available.
    let cmd = document.getElementById("Social:SharePage");
    cmd.setAttribute("disabled", shareButton.hidden ? "true" : "false");
  },

  onClick: function SSB_onClick(aEvent) {
    if (aEvent.button != 0)
      return;

    // Don't bubble to the textbox, to avoid unwanted selection of the address.
    aEvent.stopPropagation();

    this.sharePage();
  },

  panelShown: function SSB_panelShown(aEvent) {
    function updateElement(id, attrs) {
      let el = document.getElementById(id);
      Object.keys(attrs).forEach(function(attr) {
        el.setAttribute(attr, attrs[attr]);
      });
    }
    let continueSharingButton = document.getElementById("unsharePopupContinueSharingButton");
    continueSharingButton.focus();
    let recommendInfo = Social.provider.recommendInfo;
    updateElement("unsharePopupContinueSharingButton",
                  {label: recommendInfo.messages.unshareCancelLabel,
                   accesskey: recommendInfo.messages.unshareCancelAccessKey});
    updateElement("unsharePopupStopSharingButton",
                  {label: recommendInfo.messages.unshareConfirmLabel,
                  accesskey: recommendInfo.messages.unshareConfirmAccessKey});
    updateElement("socialUserPortrait",
                  {"aria-label": recommendInfo.messages.portraitLabel});
    updateElement("socialUserRecommendedText",
                  {value: recommendInfo.messages.unshareLabel});
  },

  sharePage: function SSB_sharePage() {
    this.unsharePopup.hidden = false;

    let uri = gBrowser.currentURI;
    if (!Social.isPageShared(uri)) {
      Social.sharePage(uri);
      this.updateShareState();
    } else {
      this.unsharePopup.openPopup(this.shareButton, "bottomcenter topright");
    }
  },

  unsharePage: function SSB_unsharePage() {
    Social.unsharePage(gBrowser.currentURI);
    this.updateShareState();
    this.dismissUnsharePopup();
  },

  updateShareState: function SSB_updateShareState() {
    this.updateButtonHiddenState();

    let shareButton = this.shareButton;
    let currentPageShared = shareButton && !shareButton.hidden && Social.isPageShared(gBrowser.currentURI);

    let recommendInfo = SocialUI.enabled ? Social.provider.recommendInfo : null;
    // Provide a11y-friendly notification of share.
    let status = document.getElementById("share-button-status");
    if (status) {
      // XXX - this should also be capable of reflecting that the page was
      // unshared (ie, it needs to manage three-states: (1) nothing done, (2)
      // shared, (3) shared then unshared)
      // Note that we *do* have an appropriate string from the provider for
      // this (recommendInfo.messages.unsharedLabel) but currently lack a way of
      // tracking this state)
      let statusString = currentPageShared && recommendInfo ?
                           recommendInfo.messages.sharedLabel : "";
      status.setAttribute("value", statusString);
    }

    // Update the share button, if present
    if (!shareButton || shareButton.hidden)
      return;

    let imageURL;
    if (currentPageShared) {
      shareButton.setAttribute("shared", "true");
      shareButton.setAttribute("tooltiptext", recommendInfo.messages.unshareTooltip);
      imageURL = recommendInfo.images.unshare;
    } else {
      shareButton.removeAttribute("shared");
      shareButton.setAttribute("tooltiptext", recommendInfo.messages.shareTooltip);
      imageURL = recommendInfo.images.share;
    }
    shareButton.src = imageURL;
  }
};

var SocialMenu = {
  populate: function SocialMenu_populate() {
    let submenu = document.getElementById("menu_social-statusarea-popup");
    let ambientMenuItems = submenu.getElementsByClassName("ambient-menuitem");
    while (ambientMenuItems.length)
      submenu.removeChild(ambientMenuItems.item(0));

    let separator = document.getElementById("socialAmbientMenuSeparator");
    separator.hidden = true;
    let provider = SocialUI.enabled ? Social.provider : null;
    if (!provider)
      return;

    let iconNames = Object.keys(provider.ambientNotificationIcons);
    for (let name of iconNames) {
      let icon = provider.ambientNotificationIcons[name];
      if (!icon.label || !icon.menuURL)
        continue;
      separator.hidden = false;
      let menuitem = document.createElement("menuitem");
      menuitem.setAttribute("label", icon.label);
      menuitem.classList.add("ambient-menuitem");
      menuitem.addEventListener("command", function() {
        openUILinkIn(icon.menuURL, "tab");
      }, false);
      submenu.insertBefore(menuitem, separator);
    }
  }
};

// XXX Need to audit that this is being initialized correctly
var SocialToolbar = {
  // Called once, after window load, when the Social.provider object is
  // initialized.
  init: function SocialToolbar_init() {
    let accesskey = gNavigatorBundle.getString("social.remove.accesskey");
    let removeCommand = document.getElementById("Social:Remove");
    removeCommand.setAttribute("accesskey", accesskey);

    this.updateProvider();
    this._dynamicResizer = new DynamicResizeWatcher();
  },

  // Called when the Social.provider changes
  updateProvider: function () {
    if (Social.provider) {
      let brandShortName = document.getElementById("bundle_brand").getString("brandShortName");
      let label = gNavigatorBundle.getFormattedString("social.remove.label",
                                                      [brandShortName]);
      let removeCommand = document.getElementById("Social:Remove");
      removeCommand.setAttribute("label", label);
      this.button.setAttribute("label", Social.provider.name);
      this.button.setAttribute("tooltiptext", Social.provider.name);
      this.button.style.listStyleImage = "url(" + Social.provider.iconURL + ")";

      this.updateProfile();
    }
    this.updateButton();
    this.populateProviderMenus();
  },

  get button() {
    return document.getElementById("social-provider-button");
  },

  // Note: this doesn't actually handle hiding the toolbar button,
  // socialActiveBroadcaster is responsible for that.
  updateButtonHiddenState: function SocialToolbar_updateButtonHiddenState() {
    let tbi = document.getElementById("social-toolbar-item");
    let socialEnabled = SocialUI.enabled;
    for (let className of ["social-statusarea-separator", "social-statusarea-user"]) {
      for (let element of document.getElementsByClassName(className))
        element.hidden = !socialEnabled;
    }
    let toggleNotificationsCommand = document.getElementById("Social:ToggleNotifications");
    toggleNotificationsCommand.setAttribute("hidden", !socialEnabled);

    if (!Social.haveLoggedInUser() || !socialEnabled) {
      let parent = document.getElementById("social-notification-panel");
      while (parent.hasChildNodes()) {
        let frame = parent.firstChild;
        SharedFrame.forgetGroup(frame.id);
        parent.removeChild(frame);
      }

      while (tbi.lastChild != tbi.firstChild)
        tbi.removeChild(tbi.lastChild);
    }
  },

  updateProfile: function SocialToolbar_updateProfile() {
    // Profile may not have been initialized yet, since it depends on a worker
    // response. In that case we'll be called again when it's available, via
    // social:profile-changed
    let profile = Social.provider.profile || {};
    let userPortrait = profile.portrait || "chrome://global/skin/icons/information-32.png";

    let userDetailsBroadcaster = document.getElementById("socialBroadcaster_userDetails");
    let loggedInStatusValue = profile.userName ||
                              userDetailsBroadcaster.getAttribute("notLoggedInLabel");

    // "image" and "label" are used by Mac's native menus that do not render the menuitem's children
    // elements. "src" and "value" are used by the image/label children on the other platforms.
    userDetailsBroadcaster.setAttribute("src", userPortrait);
    userDetailsBroadcaster.setAttribute("image", userPortrait);

    userDetailsBroadcaster.setAttribute("value", loggedInStatusValue);
    userDetailsBroadcaster.setAttribute("label", loggedInStatusValue);
  },

  // XXX doesn't this need to be called for profile changes, given its use of provider.profile?
  updateButton: function SocialToolbar_updateButton() {
    this.updateButtonHiddenState();
    let provider = Social.provider;
    let panel = document.getElementById("social-notification-panel");
    panel.hidden = !SocialUI.enabled;

    let command = document.getElementById("Social:ToggleNotifications");
    command.setAttribute("checked", Services.prefs.getBoolPref("social.toast-notifications.enabled"));

    const CACHE_PREF_NAME = "social.cached.ambientNotificationIcons";
    // provider.profile == undefined means no response yet from the provider
    // to tell us whether the user is logged in or not.
    if (!SocialUI.enabled ||
        (!Social.haveLoggedInUser() && provider.profile !== undefined)) {
      // Either no enabled provider, or there is a provider and it has
      // responded with a profile and the user isn't loggedin.  The icons
      // etc have already been removed by updateButtonHiddenState, so we want
      // to nuke any cached icons we have and get out of here!
      Services.prefs.clearUserPref(CACHE_PREF_NAME);
      return;
    }
    let icons = provider.ambientNotificationIcons;
    let iconNames = Object.keys(icons);
    if (Social.provider.profile === undefined) {
      // provider has not told us about the login state yet - see if we have
      // a cached version for this provider.
      let cached;
      try {
        cached = JSON.parse(Services.prefs.getComplexValue(CACHE_PREF_NAME,
                                                           Ci.nsISupportsString).data);
      } catch (ex) {}
      if (cached && cached.provider == Social.provider.origin && cached.data) {
        icons = cached.data;
        iconNames = Object.keys(icons);
        // delete the counter data as it is almost certainly stale.
        for each(let name in iconNames) {
          icons[name].counter = '';
        }
      }
    } else {
      // We have a logged in user - save the current set of icons back to the
      // "cache" so we can use them next startup.
      let str = Cc["@mozilla.org/supports-string;1"].createInstance(Ci.nsISupportsString);
      str.data = JSON.stringify({provider: Social.provider.origin, data: icons});
      Services.prefs.setComplexValue(CACHE_PREF_NAME,
                                     Ci.nsISupportsString,
                                     str);
    }

    let toolbarButtons = document.createDocumentFragment();

    let createdFrames = [];

    for each(let name in iconNames) {
      let icon = icons[name];

      let notificationFrameId = "social-status-" + icon.name;
      let notificationFrame = document.getElementById(notificationFrameId);

      if (!notificationFrame) {
        notificationFrame = SharedFrame.createFrame(
          notificationFrameId, /* frame name */
          panel, /* parent */
          {
            "type": "content",
            "mozbrowser": "true",
            "class": "social-panel-frame",
            "id": notificationFrameId,

            // work around bug 793057 - by making the panel roughly the final size
            // we are more likely to have the anchor in the correct position.
            "style": "width: " + PANEL_MIN_WIDTH + "px;",

            "origin": provider.origin,
            "src": icon.contentPanel
          }
        );

        createdFrames.push(notificationFrame);
      } else {
        notificationFrame.setAttribute("origin", provider.origin);
        SharedFrame.updateURL(notificationFrameId, icon.contentPanel);
      }

      let toolbarButtonContainerId = "social-notification-container-" + icon.name;
      let toolbarButtonId = "social-notification-icon-" + icon.name;
      let toolbarButtonContainer = document.getElementById(toolbarButtonContainerId);
      let toolbarButton = document.getElementById(toolbarButtonId);
      if (!toolbarButtonContainer) {
        // The container is used to fix an issue with position:absolute on
        // generated content not being constrained to the bounding box of a
        // parent toolbarbutton that has position:relative.
        toolbarButtonContainer = document.createElement("toolbaritem");
        toolbarButtonContainer.classList.add("social-notification-container");
        toolbarButtonContainer.setAttribute("id", toolbarButtonContainerId);

        toolbarButton = document.createElement("toolbarbutton");
        toolbarButton.classList.add("toolbarbutton-1");
        toolbarButton.setAttribute("id", toolbarButtonId);
        toolbarButton.setAttribute("notificationFrameId", notificationFrameId);
        toolbarButton.addEventListener("mousedown", function (event) {
          if (event.button == 0)
            SocialToolbar.showAmbientPopup(toolbarButton);
        });

        toolbarButtonContainer.appendChild(toolbarButton);
        toolbarButtons.appendChild(toolbarButtonContainer);
      }

      toolbarButton.style.listStyleImage = "url(" + icon.iconURL + ")";
      toolbarButton.setAttribute("label", icon.label);
      toolbarButton.setAttribute("tooltiptext", icon.label);

      let badge = icon.counter || "";
      if (toolbarButton.getAttribute("badge") != badge)
        toolbarButton.setAttribute("badge", badge);
    }
    let socialToolbarItem = document.getElementById("social-toolbar-item");
    socialToolbarItem.appendChild(toolbarButtons);

    for (let frame of createdFrames) {
      if (frame.docShell) {
        frame.docShell.isActive = false;
        frame.docShell.QueryInterface(Ci.nsIInterfaceRequestor)
                      .getInterface(Ci.nsIWebProgress)
                      .addProgressListener(new SocialErrorListener("notification-panel"),
                                           Ci.nsIWebProgress.NOTIFY_STATE_REQUEST |
                                           Ci.nsIWebProgress.NOTIFY_LOCATION);
      }
    }
  },

  showAmbientPopup: function SocialToolbar_showAmbientPopup(aToolbarButton) {
    // Hide any other social panels that may be open.
    SocialFlyout.panel.hidePopup();

    let panel = document.getElementById("social-notification-panel");
    let notificationFrameId = aToolbarButton.getAttribute("notificationFrameId");
    let notificationFrame = document.getElementById(notificationFrameId);

    let wasAlive = SharedFrame.isGroupAlive(notificationFrameId);
    SharedFrame.setOwner(notificationFrameId, notificationFrame);

    // Clear dimensions on all browsers so the panel size will
    // only use the selected browser.
    let frameIter = panel.firstElementChild;
    while (frameIter) {
      frameIter.collapsed = (frameIter != notificationFrame);
      frameIter = frameIter.nextElementSibling;
    }

    function dispatchPanelEvent(name) {
      let evt = notificationFrame.contentDocument.createEvent("CustomEvent");
      evt.initCustomEvent(name, true, true, {});
      notificationFrame.contentDocument.documentElement.dispatchEvent(evt);
    }

    let dynamicResizer = this._dynamicResizer;
    panel.addEventListener("popuphidden", function onpopuphiding() {
      panel.removeEventListener("popuphidden", onpopuphiding);
      aToolbarButton.removeAttribute("open");
      aToolbarButton.parentNode.removeAttribute("open");
      dynamicResizer.stop();
      notificationFrame.docShell.isActive = false;
      dispatchPanelEvent("socialFrameHide");
    });

    panel.addEventListener("popupshown", function onpopupshown() {
      panel.removeEventListener("popupshown", onpopupshown);
      // This attribute is needed on both the button and the
      // containing toolbaritem since the buttons on OS X have
      // moz-appearance:none, while their container gets
      // moz-appearance:toolbarbutton due to the way that toolbar buttons
      // get combined on OS X.
      aToolbarButton.setAttribute("open", "true");
      aToolbarButton.parentNode.setAttribute("open", "true");
      notificationFrame.docShell.isActive = true;
      notificationFrame.docShell.isAppTab = true;
      if (notificationFrame.contentDocument.readyState == "complete" && wasAlive) {
        dynamicResizer.start(panel, notificationFrame);
        dispatchPanelEvent("socialFrameShow");
      } else {
        // first time load, wait for load and dispatch after load
        notificationFrame.addEventListener("load", function panelBrowserOnload(e) {
          notificationFrame.removeEventListener("load", panelBrowserOnload, true);
          dynamicResizer.start(panel, notificationFrame);
          setTimeout(function() {
            dispatchPanelEvent("socialFrameShow");
          }, 0);
        }, true);
      }
    });

    let navBar = document.getElementById("nav-bar");
    let anchor = navBar.getAttribute("mode") == "text" ?
                   document.getAnonymousElementByAttribute(aToolbarButton, "class", "toolbarbutton-text") :
                   document.getAnonymousElementByAttribute(aToolbarButton, "class", "toolbarbutton-icon");
    panel.openPopup(anchor, "bottomcenter topright", 0, 0, false, false);
  },

  setPanelErrorMessage: function SocialToolbar_setPanelErrorMessage(aNotificationFrame) {
    if (!aNotificationFrame)
      return;

    let src = aNotificationFrame.getAttribute("src");
    aNotificationFrame.removeAttribute("src");
    aNotificationFrame.webNavigation.loadURI("about:socialerror?mode=tryAgainOnly&url=" +
                                             encodeURIComponent(src), null, null, null, null);
    let panel = aNotificationFrame.parentNode;
    sizeSocialPanelToContent(panel, aNotificationFrame);
  },

  populateProviderMenus: function SocialToolbar_renderProviderMenus() {
    let providerMenuSeps = document.getElementsByClassName("social-provider-menu");
    let activeProviders = [p for (p of Social.providers) if (p.active)];
    for (let providerMenuSep of providerMenuSeps)
      this._populateProviderMenu(providerMenuSep, activeProviders);
  },

  _populateProviderMenu: function SocialToolbar_renderProviderMenu(providerMenuSep, providers) {
    let menu = providerMenuSep.parentNode;
    // selectable providers are inserted before the provider-menu seperator,
    // remove any menuitems in that area
    while (providerMenuSep.previousSibling.nodeName == "menuitem") {
      menu.removeChild(providerMenuSep.previousSibling);
    }
    // only show a selection if enabled and there is more than one
    if (!SocialUI.enabled || providers.length < 2) {
      providerMenuSep.hidden = true;
      return;
    }
    for (let provider of providers) {
      let menuitem = document.createElement("menuitem");
      menuitem.className = "menuitem-iconic social-provider-menuitem";
      menuitem.setAttribute("image", provider.iconURL);
      menuitem.setAttribute("label", provider.name);
      menuitem.setAttribute("origin", provider.origin);
      if (provider == Social.provider) {
        menuitem.setAttribute("checked", "true");
      } else {
        menuitem.setAttribute("oncommand", "Social.setProviderByOrigin(this.getAttribute('origin'));");
      }
      menu.insertBefore(menuitem, providerMenuSep);
    }
    providerMenuSep.hidden = false;
  }
}

var SocialSidebar = {
  // Called once, after window load, when the Social.provider object is initialized
  init: function SocialSidebar_init() {
    let sbrowser = document.getElementById("social-sidebar-browser");
    this.errorListener = new SocialErrorListener("sidebar");
    this.configureSidebarDocShell(sbrowser.docShell);
    this.update();
  },

  configureSidebarDocShell: function SocialSidebar_configureDocShell(aDocShell) {
    // setting isAppTab causes clicks on untargeted links to open new tabs
    aDocShell.isAppTab = true;
    aDocShell.QueryInterface(Ci.nsIWebProgress)
             .addProgressListener(SocialSidebar.errorListener,
                                  Ci.nsIWebProgress.NOTIFY_STATE_REQUEST |
                                  Ci.nsIWebProgress.NOTIFY_LOCATION);
  },

  // Whether the sidebar can be shown for this window.
  get canShow() {
    return SocialUI.enabled && Social.provider.sidebarURL;
  },

  // Whether the user has toggled the sidebar on (for windows where it can appear)
  get opened() {
    return Services.prefs.getBoolPref("social.sidebar.open") && !document.mozFullScreen;
  },

  setSidebarVisibilityState: function(aEnabled) {
    let sbrowser = document.getElementById("social-sidebar-browser");
    // it's possible we'll be called twice with aEnabled=false so let's
    // just assume we may often be called with the same state.
    if (aEnabled == sbrowser.docShellIsActive)
      return;
    sbrowser.docShellIsActive = aEnabled;
    let evt = sbrowser.contentDocument.createEvent("CustomEvent");
    evt.initCustomEvent(aEnabled ? "socialFrameShow" : "socialFrameHide", true, true, {});
    sbrowser.contentDocument.documentElement.dispatchEvent(evt);
  },

  update: function SocialSidebar_update() {
    clearTimeout(this._unloadTimeoutId);
    // Hide the toggle menu item if the sidebar cannot appear
    let command = document.getElementById("Social:ToggleSidebar");
    command.setAttribute("hidden", this.canShow ? "false" : "true");

    // Hide the sidebar if it cannot appear, or has been toggled off.
    // Also set the command "checked" state accordingly.
    let hideSidebar = !this.canShow || !this.opened;
    let broadcaster = document.getElementById("socialSidebarBroadcaster");
    broadcaster.hidden = hideSidebar;
    command.setAttribute("checked", !hideSidebar);

    let sbrowser = document.getElementById("social-sidebar-browser");

    if (hideSidebar) {
      sbrowser.removeEventListener("load", SocialSidebar._loadListener, true);
      this.setSidebarVisibilityState(false);
      // If we've been disabled, unload the sidebar content immediately;
      // if the sidebar was just toggled to invisible, wait a timeout
      // before unloading.
      if (!this.canShow) {
        this.unloadSidebar();
      } else {
        this._unloadTimeoutId = setTimeout(
          this.unloadSidebar,
          Services.prefs.getIntPref("social.sidebar.unload_timeout_ms")
        );
      }
    } else {
      sbrowser.setAttribute("origin", Social.provider.origin);
      if (Social.provider.errorState == "frameworker-error") {
        SocialSidebar.setSidebarErrorMessage("frameworker-error");
        return;
      }

      // Make sure the right sidebar URL is loaded
      if (sbrowser.getAttribute("src") != Social.provider.sidebarURL) {
        sbrowser.setAttribute("src", Social.provider.sidebarURL);
        sbrowser.addEventListener("load", SocialSidebar._loadListener, true);
      } else {
        this.setSidebarVisibilityState(true);
      }
    }
  },

  _loadListener: function SocialSidebar_loadListener() {
    let sbrowser = document.getElementById("social-sidebar-browser");
    sbrowser.removeEventListener("load", SocialSidebar._loadListener, true);
    SocialSidebar.setSidebarVisibilityState(true);
  },

  unloadSidebar: function SocialSidebar_unloadSidebar() {
    let sbrowser = document.getElementById("social-sidebar-browser");
    if (!sbrowser.hasAttribute("origin"))
      return;

    sbrowser.stop();
    sbrowser.removeAttribute("origin");
    sbrowser.setAttribute("src", "about:blank");
    SocialFlyout.unload();
  },

  _unloadTimeoutId: 0,

  setSidebarErrorMessage: function(aType) {
    let sbrowser = document.getElementById("social-sidebar-browser");
    switch (aType) {
      case "sidebar-error":
        let url = encodeURIComponent(Social.provider.sidebarURL);
        sbrowser.loadURI("about:socialerror?mode=tryAgain&url=" + url, null, null);
        break;

      case "frameworker-error":
        sbrowser.setAttribute("src", "about:socialerror?mode=workerFailure");
        break;
    }
  }
}

// Error handling class used to listen for network errors in the social frames
// and replace them with a social-specific error page
function SocialErrorListener(aType) {
  this.type = aType;
}

SocialErrorListener.prototype = {
  QueryInterface: XPCOMUtils.generateQI([Ci.nsIWebProgressListener,
                                         Ci.nsISupportsWeakReference,
                                         Ci.nsISupports]),

  onStateChange: function SPL_onStateChange(aWebProgress, aRequest, aState, aStatus) {
    let failure = false;
    if ((aState & Ci.nsIWebProgressListener.STATE_STOP)) {
      if (aRequest instanceof Ci.nsIHttpChannel) {
        try {
          // Change the frame to an error page on 4xx (client errors)
          // and 5xx (server errors)
          failure = aRequest.responseStatus >= 400 &&
                    aRequest.responseStatus < 600;
        } catch (e) {}
      }
    }

    // Calling cancel() will raise some OnStateChange notifications by itself,
    // so avoid doing that more than once
    if (failure && aStatus != Components.results.NS_BINDING_ABORTED) {
      aRequest.cancel(Components.results.NS_BINDING_ABORTED);
      this.setErrorMessage(aWebProgress);
    }
  },

  onLocationChange: function SPL_onLocationChange(aWebProgress, aRequest, aLocation, aFlags) {
    let failure = aFlags & Ci.nsIWebProgressListener.LOCATION_CHANGE_ERROR_PAGE;
    if (failure && Social.provider.errorState != "frameworker-error") {
      aRequest.cancel(Components.results.NS_BINDING_ABORTED);
      window.setTimeout(function(self) {
        self.setErrorMessage(aWebProgress);
      }, 0, this);
    }
  },

  onProgressChange: function SPL_onProgressChange() {},
  onStatusChange: function SPL_onStatusChange() {},
  onSecurityChange: function SPL_onSecurityChange() {},

  setErrorMessage: function(aWebProgress) {
    switch (this.type) {
      case "flyout":
        SocialFlyout.setFlyoutErrorMessage();
        break;

      case "sidebar":
        // a frameworker error "trumps" a sidebar error.
        let reason = Social.provider.errorState || "sidebar-error";
        SocialSidebar.setSidebarErrorMessage(reason);
        break;

      case "notification-panel":
        let frame = aWebProgress.QueryInterface(Ci.nsIDocShell)
                                .chromeEventHandler;
        SocialToolbar.setPanelErrorMessage(frame);
        break;
    }
  }
};
/*
//@line 7 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-tabPreviews.js"
 */

/**
 * Tab previews utility, produces thumbnails
 */
var tabPreviews = {
  aspectRatio: 0.5625, // 16:9

  get width() {
    delete this.width;
    return this.width = Math.ceil(screen.availWidth / 5.75);
  },

  get height() {
    delete this.height;
    return this.height = Math.round(this.width * this.aspectRatio);
  },

  init: function tabPreviews_init() {
    if (this._selectedTab)
      return;
    this._selectedTab = gBrowser.selectedTab;

    gBrowser.tabContainer.addEventListener("TabSelect", this, false);
    gBrowser.tabContainer.addEventListener("SSTabRestored", this, false);
  },

  get: function tabPreviews_get(aTab) {
    let uri = aTab.linkedBrowser.currentURI.spec;

    if (aTab.__thumbnail_lastURI &&
        aTab.__thumbnail_lastURI != uri) {
      aTab.__thumbnail = null;
      aTab.__thumbnail_lastURI = null;
    }

    if (aTab.__thumbnail)
      return aTab.__thumbnail;

    if (aTab.getAttribute("pending") == "true") {
      let img = new Image;
      img.src = PageThumbs.getThumbnailURL(uri);
      return img;
    }

    return this.capture(aTab, !aTab.hasAttribute("busy"));
  },

  capture: function tabPreviews_capture(aTab, aStore) {
    var thumbnail = document.createElementNS("http://www.w3.org/1999/xhtml", "canvas");
    thumbnail.mozOpaque = true;
    thumbnail.height = this.height;
    thumbnail.width = this.width;

    var ctx = thumbnail.getContext("2d");
    var win = aTab.linkedBrowser.contentWindow;
    var snippetWidth = win.innerWidth * .6;
    var scale = this.width / snippetWidth;
    ctx.scale(scale, scale);
    ctx.drawWindow(win, win.scrollX, win.scrollY,
                   snippetWidth, snippetWidth * this.aspectRatio, "rgb(255,255,255)");

    if (aStore &&
        aTab.linkedBrowser /* bug 795608: the tab may got removed while drawing the thumbnail */) {
      aTab.__thumbnail = thumbnail;
      aTab.__thumbnail_lastURI = aTab.linkedBrowser.currentURI.spec;
    }

    return thumbnail;
  },

  handleEvent: function tabPreviews_handleEvent(event) {
    switch (event.type) {
      case "TabSelect":
        if (this._selectedTab &&
            this._selectedTab.parentNode &&
            !this._pendingUpdate) {
          // Generate a thumbnail for the tab that was selected.
          // The timeout keeps the UI snappy and prevents us from generating thumbnails
          // for tabs that will be closed. During that timeout, don't generate other
          // thumbnails in case multiple TabSelect events occur fast in succession.
          this._pendingUpdate = true;
          setTimeout(function (self, aTab) {
            self._pendingUpdate = false;
            if (aTab.parentNode &&
                !aTab.hasAttribute("busy") &&
                !aTab.hasAttribute("pending"))
              self.capture(aTab, true);
          }, 2000, this, this._selectedTab);
        }
        this._selectedTab = event.target;
        break;
      case "SSTabRestored":
        this.capture(event.target, true);
        break;
    }
  }
};

var tabPreviewPanelHelper = {
  opening: function (host) {
    host.panel.hidden = false;

    var handler = this._generateHandler(host);
    host.panel.addEventListener("popupshown", handler, false);
    host.panel.addEventListener("popuphiding", handler, false);

    host._prevFocus = document.commandDispatcher.focusedElement;
  },
  _generateHandler: function (host) {
    var self = this;
    return function (event) {
      if (event.target == host.panel) {
        host.panel.removeEventListener(event.type, arguments.callee, false);
        self["_" + event.type](host);
      }
    };
  },
  _popupshown: function (host) {
    if ("setupGUI" in host)
      host.setupGUI();
  },
  _popuphiding: function (host) {
    if ("suspendGUI" in host)
      host.suspendGUI();

    if (host._prevFocus) {
      Cc["@mozilla.org/focus-manager;1"]
        .getService(Ci.nsIFocusManager)
        .setFocus(host._prevFocus, Ci.nsIFocusManager.FLAG_NOSCROLL);
      host._prevFocus = null;
    } else
      gBrowser.selectedBrowser.focus();

    if (host.tabToSelect) {
      gBrowser.selectedTab = host.tabToSelect;
      host.tabToSelect = null;
    }
  }
};

/**
 * Ctrl-Tab panel
 */
var ctrlTab = {
  get panel () {
    delete this.panel;
    return this.panel = document.getElementById("ctrlTab-panel");
  },
  get showAllButton () {
    delete this.showAllButton;
    return this.showAllButton = document.getElementById("ctrlTab-showAll");
  },
  get previews () {
    delete this.previews;
    return this.previews = this.panel.getElementsByClassName("ctrlTab-preview");
  },
  get recentlyUsedLimit () {
    delete this.recentlyUsedLimit;
    return this.recentlyUsedLimit = gPrefService.getIntPref("browser.ctrlTab.recentlyUsedLimit");
  },
  get keys () {
    var keys = {};
    ["close", "find", "selectAll"].forEach(function (key) {
      keys[key] = document.getElementById("key_" + key)
                          .getAttribute("key")
                          .toLocaleLowerCase().charCodeAt(0);
    });
    delete this.keys;
    return this.keys = keys;
  },
  _selectedIndex: 0,
  get selected () this._selectedIndex < 0 ?
                    document.activeElement :
                    this.previews.item(this._selectedIndex),
  get isOpen   () this.panel.state == "open" || this.panel.state == "showing" || this._timer,
  get tabCount () this.tabList.length,
  get tabPreviewCount () Math.min(this.previews.length - 1, this.tabCount),
  get canvasWidth () Math.min(tabPreviews.width,
                              Math.ceil(screen.availWidth * .85 / this.tabPreviewCount)),
  get canvasHeight () Math.round(this.canvasWidth * tabPreviews.aspectRatio),

  get tabList () {
    if (this._tabList)
      return this._tabList;

    // Using gBrowser.tabs instead of gBrowser.visibleTabs, as the latter
    // exlcudes closing tabs, breaking the following loop in case the the
    // selected tab is closing.
    let list = Array.filter(gBrowser.tabs, function (tab) !tab.hidden);

    // Rotate the list until the selected tab is first
    while (!list[0].selected)
      list.push(list.shift());

    list = list.filter(function (tab) !tab.closing);

    if (this.recentlyUsedLimit != 0) {
      let recentlyUsedTabs = [];
      for (let tab of this._recentlyUsedTabs) {
        if (!tab.hidden && !tab.closing) {
          recentlyUsedTabs.push(tab);
          if (this.recentlyUsedLimit > 0 && recentlyUsedTabs.length >= this.recentlyUsedLimit)
            break;
        }
      }
      for (let i = recentlyUsedTabs.length - 1; i >= 0; i--) {
        list.splice(list.indexOf(recentlyUsedTabs[i]), 1);
        list.unshift(recentlyUsedTabs[i]);
      }
    }

    return this._tabList = list;
  },

  init: function ctrlTab_init() {
    if (!this._recentlyUsedTabs) {
      tabPreviews.init();

      this._recentlyUsedTabs = [gBrowser.selectedTab];
      this._init(true);
    }
  },

  uninit: function ctrlTab_uninit() {
    this._recentlyUsedTabs = null;
    this._init(false);
  },

  prefName: "browser.ctrlTab.previews",
  readPref: function ctrlTab_readPref() {
    var enable =
      gPrefService.getBoolPref(this.prefName) &&
      (!gPrefService.prefHasUserValue("browser.ctrlTab.disallowForScreenReaders") ||
       !gPrefService.getBoolPref("browser.ctrlTab.disallowForScreenReaders"));

    if (enable)
      this.init();
    else
      this.uninit();
  },
  observe: function (aSubject, aTopic, aPrefName) {
    this.readPref();
  },

  updatePreviews: function ctrlTab_updatePreviews() {
    for (let i = 0; i < this.previews.length; i++)
      this.updatePreview(this.previews[i], this.tabList[i]);

    var showAllLabel = gNavigatorBundle.getString("ctrlTab.showAll.label");
    this.showAllButton.label =
      PluralForm.get(this.tabCount, showAllLabel).replace("#1", this.tabCount);
  },

  updatePreview: function ctrlTab_updatePreview(aPreview, aTab) {
    if (aPreview == this.showAllButton)
      return;

    aPreview._tab = aTab;

    if (aPreview.firstChild)
      aPreview.removeChild(aPreview.firstChild);
    if (aTab) {
      let canvasWidth = this.canvasWidth;
      let canvasHeight = this.canvasHeight;
      aPreview.appendChild(tabPreviews.get(aTab));
      aPreview.setAttribute("label", aTab.label);
      aPreview.setAttribute("tooltiptext", aTab.label);
      aPreview.setAttribute("crop", aTab.crop);
      aPreview.setAttribute("canvaswidth", canvasWidth);
      aPreview.setAttribute("canvasstyle",
                            "max-width:" + canvasWidth + "px;" +
                            "min-width:" + canvasWidth + "px;" +
                            "max-height:" + canvasHeight + "px;" +
                            "min-height:" + canvasHeight + "px;");
      if (aTab.image)
        aPreview.setAttribute("image", aTab.image);
      else
        aPreview.removeAttribute("image");
      aPreview.hidden = false;
    } else {
      aPreview.hidden = true;
      aPreview.removeAttribute("label");
      aPreview.removeAttribute("tooltiptext");
      aPreview.removeAttribute("image");
    }
  },

  advanceFocus: function ctrlTab_advanceFocus(aForward) {
    if (this._selectedIndex == -1) {
      // No virtual selectedIndex, focus must be in the panel already.
      if (aForward)
        document.commandDispatcher.advanceFocus();
      else
        document.commandDispatcher.rewindFocus();
    } else {
      // Focus isn't in the panel yet, so we maintain a virtual selectedIndex.
      do {
        this._selectedIndex += aForward ? 1 : -1;
        if (this._selectedIndex < 0)
          this._selectedIndex = this.previews.length - 1;
        else if (this._selectedIndex >= this.previews.length)
          this._selectedIndex = 0;
      } while (this.selected.hidden);
    }

    if (this._timer) {
      clearTimeout(this._timer);
      this._timer = null;
      this._openPanel();
    }
  },

  _mouseOverFocus: function ctrlTab_mouseOverFocus(aPreview) {
    if (this._trackMouseOver)
      aPreview.focus();
  },

  pick: function ctrlTab_pick(aPreview) {
    if (!this.tabCount)
      return;

    var select = (aPreview || this.selected);

    if (select == this.showAllButton)
      this.showAllTabs();
    else
      this.close(select._tab);
  },

  showAllTabs: function ctrlTab_showAllTabs(aPreview) {
    this.close();
    document.getElementById("Browser:ShowAllTabs").doCommand();
  },

  remove: function ctrlTab_remove(aPreview) {
    if (aPreview._tab)
      gBrowser.removeTab(aPreview._tab);
  },

  attachTab: function ctrlTab_attachTab(aTab, aPos) {
    if (aPos == 0)
      this._recentlyUsedTabs.unshift(aTab);
    else if (aPos)
      this._recentlyUsedTabs.splice(aPos, 0, aTab);
    else
      this._recentlyUsedTabs.push(aTab);
  },
  detachTab: function ctrlTab_detachTab(aTab) {
    var i = this._recentlyUsedTabs.indexOf(aTab);
    if (i >= 0)
      this._recentlyUsedTabs.splice(i, 1);
  },

  open: function ctrlTab_open() {
    if (this.isOpen)
      return;

    allTabs.close();

    document.addEventListener("keyup", this, true);

    this.updatePreviews();
    this._selectedIndex = 1;

    // Add a slight delay before showing the UI, so that a quick
    // "ctrl-tab" keypress just flips back to the MRU tab.
    this._timer = setTimeout(function (self) {
      self._timer = null;
      self._openPanel();
    }, 200, this);
  },

  _openPanel: function ctrlTab_openPanel() {
    tabPreviewPanelHelper.opening(this);

    this.panel.width = Math.min(screen.availWidth * .99,
                                this.canvasWidth * 1.25 * this.tabPreviewCount);
    var estimateHeight = this.canvasHeight * 1.25 + 75;
    this.panel.openPopupAtScreen(screen.availLeft + (screen.availWidth - this.panel.width) / 2,
                                 screen.availTop + (screen.availHeight - estimateHeight) / 2,
                                 false);
  },

  close: function ctrlTab_close(aTabToSelect) {
    if (!this.isOpen)
      return;

    if (this._timer) {
      clearTimeout(this._timer);
      this._timer = null;
      this.suspendGUI();
      if (aTabToSelect)
        gBrowser.selectedTab = aTabToSelect;
      return;
    }

    this.tabToSelect = aTabToSelect;
    this.panel.hidePopup();
  },

  setupGUI: function ctrlTab_setupGUI() {
    this.selected.focus();
    this._selectedIndex = -1;

    // Track mouse movement after a brief delay so that the item that happens
    // to be under the mouse pointer initially won't be selected unintentionally.
    this._trackMouseOver = false;
    setTimeout(function (self) {
      if (self.isOpen)
        self._trackMouseOver = true;
    }, 0, this);
  },

  suspendGUI: function ctrlTab_suspendGUI() {
    document.removeEventListener("keyup", this, true);

    Array.forEach(this.previews, function (preview) {
      this.updatePreview(preview, null);
    }, this);

    this._tabList = null;
  },

  onKeyPress: function ctrlTab_onKeyPress(event) {
    var isOpen = this.isOpen;

    if (isOpen) {
      event.preventDefault();
      event.stopPropagation();
    }

    switch (event.keyCode) {
      case event.DOM_VK_TAB:
        if (event.ctrlKey && !event.altKey && !event.metaKey) {
          if (isOpen) {
            this.advanceFocus(!event.shiftKey);
          } else if (!event.shiftKey) {
            event.preventDefault();
            event.stopPropagation();
            let tabs = gBrowser.visibleTabs;
            if (tabs.length > 2) {
              this.open();
            } else if (tabs.length == 2) {
              let index = tabs[0].selected ? 1 : 0;
              gBrowser.selectedTab = tabs[index];
            }
          }
        }
        break;
      default:
        if (isOpen && event.ctrlKey) {
          if (event.keyCode == event.DOM_VK_DELETE) {
            this.remove(this.selected);
            break;
          }
          switch (event.charCode) {
            case this.keys.close:
              this.remove(this.selected);
              break;
            case this.keys.find:
            case this.keys.selectAll:
              this.showAllTabs();
              break;
          }
        }
    }
  },

  removeClosingTabFromUI: function ctrlTab_removeClosingTabFromUI(aTab) {
    if (this.tabCount == 2) {
      this.close();
      return;
    }

    this._tabList = null;
    this.updatePreviews();

    if (this.selected.hidden)
      this.advanceFocus(false);
    if (this.selected == this.showAllButton)
      this.advanceFocus(false);

    // If the current tab is removed, another tab can steal our focus.
    if (aTab.selected && this.panel.state == "open") {
      setTimeout(function (selected) {
        selected.focus();
      }, 0, this.selected);
    }
  },

  handleEvent: function ctrlTab_handleEvent(event) {
    switch (event.type) {
      case "TabAttrModified":
        // tab attribute modified (e.g. label, crop, busy, image, selected)
        for (let i = this.previews.length - 1; i >= 0; i--) {
          if (this.previews[i]._tab && this.previews[i]._tab == event.target) {
            this.updatePreview(this.previews[i], event.target);
            break;
          }
        }
        break;
      case "TabSelect":
        this.detachTab(event.target);
        this.attachTab(event.target, 0);
        break;
      case "TabOpen":
        this.attachTab(event.target, 1);
        break;
      case "TabClose":
        this.detachTab(event.target);
        if (this.isOpen)
          this.removeClosingTabFromUI(event.target);
        break;
      case "keypress":
        this.onKeyPress(event);
        break;
      case "keyup":
        if (event.keyCode == event.DOM_VK_CONTROL)
          this.pick();
        break;
    }
  },

  _init: function ctrlTab__init(enable) {
    var toggleEventListener = enable ? "addEventListener" : "removeEventListener";

    var tabContainer = gBrowser.tabContainer;
    tabContainer[toggleEventListener]("TabOpen", this, false);
    tabContainer[toggleEventListener]("TabAttrModified", this, false);
    tabContainer[toggleEventListener]("TabSelect", this, false);
    tabContainer[toggleEventListener]("TabClose", this, false);

    document[toggleEventListener]("keypress", this, false);
    gBrowser.mTabBox.handleCtrlTab = !enable;

    // If we're not running, hide the "Show All Tabs" menu item,
    // as Shift+Ctrl+Tab will be handled by the tab bar.
    document.getElementById("menu_showAllTabs").hidden = !enable;

    // Also disable the <key> to ensure Shift+Ctrl+Tab never triggers
    // Show All Tabs.
    var key_showAllTabs = document.getElementById("key_showAllTabs");
    if (enable)
      key_showAllTabs.removeAttribute("disabled");
    else
      key_showAllTabs.setAttribute("disabled", "true");
  }
};


/**
 * All Tabs panel
 */
var allTabs = {
  get panel () {
    delete this.panel;
    return this.panel = document.getElementById("allTabs-panel");
  },
  get filterField () {
    delete this.filterField;
    return this.filterField = document.getElementById("allTabs-filter");
  },
  get container () {
    delete this.container;
    return this.container = document.getElementById("allTabs-container");
  },
  get tabCloseButton () {
    delete this.tabCloseButton;
    return this.tabCloseButton = document.getElementById("allTabs-tab-close-button");
  },
  get toolbarButton() document.getElementById("alltabs-button"),
  get previews () this.container.getElementsByClassName("allTabs-preview"),
  get isOpen () this.panel.state == "open" || this.panel.state == "showing",

  init: function allTabs_init() {
    if (this._initiated)
      return;
    this._initiated = true;

    tabPreviews.init();

    Array.forEach(gBrowser.tabs, function (tab) {
      this._addPreview(tab);
    }, this);

    gBrowser.tabContainer.addEventListener("TabOpen", this, false);
    gBrowser.tabContainer.addEventListener("TabAttrModified", this, false);
    gBrowser.tabContainer.addEventListener("TabMove", this, false);
    gBrowser.tabContainer.addEventListener("TabClose", this, false);
  },

  uninit: function allTabs_uninit() {
    if (!this._initiated)
      return;

    gBrowser.tabContainer.removeEventListener("TabOpen", this, false);
    gBrowser.tabContainer.removeEventListener("TabAttrModified", this, false);
    gBrowser.tabContainer.removeEventListener("TabMove", this, false);
    gBrowser.tabContainer.removeEventListener("TabClose", this, false);

    while (this.container.hasChildNodes())
      this.container.removeChild(this.container.firstChild);

    this._initiated = false;
  },

  prefName: "browser.allTabs.previews",
  readPref: function allTabs_readPref() {
    var allTabsButton = this.toolbarButton;
    if (!allTabsButton)
      return;

    if (gPrefService.getBoolPref(this.prefName)) {
      allTabsButton.removeAttribute("type");
      allTabsButton.setAttribute("command", "Browser:ShowAllTabs");
    } else {
      allTabsButton.setAttribute("type", "menu");
      allTabsButton.removeAttribute("command");
      allTabsButton.removeAttribute("oncommand");
    }
  },
  observe: function (aSubject, aTopic, aPrefName) {
    this.readPref();
  },

  pick: function allTabs_pick(aPreview) {
    if (!aPreview)
      aPreview = this._firstVisiblePreview;
    if (aPreview)
      this.tabToSelect = aPreview._tab;

    this.close();
  },

  closeTab: function allTabs_closeTab(event) {
    this.filterField.focus();
    gBrowser.removeTab(event.currentTarget._targetPreview._tab);
  },

  filter: function allTabs_filter() {
    if (this._currentFilter == this.filterField.value)
      return;

    this._currentFilter = this.filterField.value;

    var filter = this._currentFilter.split(/\s+/g);
    this._visible = 0;
    Array.forEach(this.previews, function (preview) {
      var tab = preview._tab;
      var matches = 0;
      if (filter.length && !tab.hidden) {
        let tabstring = tab.linkedBrowser.currentURI.spec;
        try {
          tabstring = decodeURI(tabstring);
        } catch (e) {}
        tabstring = tab.label + " " + tab.label.toLocaleLowerCase() + " " + tabstring;
        for (let i = 0; i < filter.length; i++)
          matches += tabstring.contains(filter[i]);
      }
      if (matches < filter.length || tab.hidden) {
        preview.hidden = true;
      }
      else {
        this._visible++;
        this._updatePreview(preview);
        preview.hidden = false;
      }
    }, this);

    this._reflow();
  },

  open: function allTabs_open() {
    var allTabsButton = this.toolbarButton;
    if (allTabsButton &&
        allTabsButton.getAttribute("type") == "menu") {
      // Without setTimeout, the menupopup won't stay open when invoking
      // "View > Show All Tabs" and the menu bar auto-hides.
      setTimeout(function () {
        allTabsButton.open = true;
      }, 0);
      return;
    }

    this.init();

    if (this.isOpen)
      return;

    this._maxPanelHeight = Math.max(gBrowser.clientHeight, screen.availHeight / 2);
    this._maxPanelWidth = Math.max(gBrowser.clientWidth, screen.availWidth / 2);

    this.filter();

    tabPreviewPanelHelper.opening(this);

    this.panel.popupBoxObject.setConsumeRollupEvent(Ci.nsIPopupBoxObject.ROLLUP_NO_CONSUME);
    this.panel.openPopup(gBrowser, "overlap", 0, 0, false, true);
  },

  close: function allTabs_close() {
    this.panel.hidePopup();
  },

  setupGUI: function allTabs_setupGUI() {
    this.filterField.focus();
    this.filterField.placeholder = this.filterField.tooltipText;

    this.panel.addEventListener("keypress", this, false);
    this.panel.addEventListener("keypress", this, true);
    this._browserCommandSet.addEventListener("command", this, false);

    // When the panel is open, a second click on the all tabs button should
    // close the panel but not re-open it.
    document.getElementById("Browser:ShowAllTabs").setAttribute("disabled", "true");
  },

  suspendGUI: function allTabs_suspendGUI() {
    this.filterField.placeholder = "";
    this.filterField.value = "";
    this._currentFilter = null;

    this._updateTabCloseButton();

    this.panel.removeEventListener("keypress", this, false);
    this.panel.removeEventListener("keypress", this, true);
    this._browserCommandSet.removeEventListener("command", this, false);

    setTimeout(function () {
      document.getElementById("Browser:ShowAllTabs").removeAttribute("disabled");
    }, 300);
  },

  handleEvent: function allTabs_handleEvent(event) {
    if (event.type.startsWith("Tab")) {
      var tab = event.target;
      if (event.type != "TabOpen")
        var preview = this._getPreview(tab);
    }
    switch (event.type) {
      case "TabAttrModified":
        // tab attribute modified (e.g. label, crop, busy, image)
        if (!preview.hidden)
          this._updatePreview(preview);
        break;
      case "TabOpen":
        if (this.isOpen)
          this.close();
        this._addPreview(tab);
        break;
      case "TabMove":
        let siblingPreview = tab.nextSibling &&
                             this._getPreview(tab.nextSibling);
        if (siblingPreview)
          siblingPreview.parentNode.insertBefore(preview, siblingPreview);
        else
          this.container.lastChild.appendChild(preview);
        if (this.isOpen && !preview.hidden) {
          this._reflow();
          preview.focus();
        }
        break;
      case "TabClose":
        this._removePreview(preview);
        break;
      case "keypress":
        this._onKeyPress(event);
        break;
      case "command":
        if (event.target.id != "Browser:ShowAllTabs") {
          // Close the panel when there's a browser command executing in the background.
          this.close();
        }
        break;
    }
  },

  _visible: 0,
  _currentFilter: null,
  get _stack () {
    delete this._stack;
    return this._stack = document.getElementById("allTabs-stack");
  },
  get _browserCommandSet () {
    delete this._browserCommandSet;
    return this._browserCommandSet = document.getElementById("mainCommandSet");
  },
  get _previewLabelHeight () {
    delete this._previewLabelHeight;
    return this._previewLabelHeight = parseInt(getComputedStyle(this.previews[0], "").lineHeight);
  },

  get _visiblePreviews ()
    Array.filter(this.previews, function (preview) !preview.hidden),

  get _firstVisiblePreview () {
    if (this._visible == 0)
      return null;
    var previews = this.previews;
    for (let i = 0; i < previews.length; i++) {
      if (!previews[i].hidden)
        return previews[i];
    }
    return null;
  },

  _reflow: function allTabs_reflow() {
    this._updateTabCloseButton();

    const CONTAINER_MAX_WIDTH = this._maxPanelWidth * .95;
    const CONTAINER_MAX_HEIGHT = this._maxPanelHeight - 35;
    // the size of the whole preview relative to the thumbnail
    const REL_PREVIEW_THUMBNAIL = 1.2;
    const REL_PREVIEW_HEIGHT_WIDTH = tabPreviews.height / tabPreviews.width;
    const PREVIEW_MAX_WIDTH = tabPreviews.width * REL_PREVIEW_THUMBNAIL;

    var rows, previewHeight, previewWidth, outerHeight;
    this._columns = Math.floor(CONTAINER_MAX_WIDTH / PREVIEW_MAX_WIDTH);
    do {
      rows = Math.ceil(this._visible / this._columns);
      previewWidth = Math.min(PREVIEW_MAX_WIDTH,
                              Math.round(CONTAINER_MAX_WIDTH / this._columns));
      previewHeight = Math.round(previewWidth * REL_PREVIEW_HEIGHT_WIDTH);
      outerHeight = previewHeight + this._previewLabelHeight;
    } while (rows * outerHeight > CONTAINER_MAX_HEIGHT && ++this._columns);

    var outerWidth = previewWidth;
    {
      let innerWidth = Math.ceil(previewWidth / REL_PREVIEW_THUMBNAIL);
      let innerHeight = Math.ceil(previewHeight / REL_PREVIEW_THUMBNAIL);
      var canvasStyle = "max-width:" + innerWidth + "px;" +
                        "min-width:" + innerWidth + "px;" +
                        "max-height:" + innerHeight + "px;" +
                        "min-height:" + innerHeight + "px;";
    }

    var previews = Array.slice(this.previews);

    while (this.container.hasChildNodes())
      this.container.removeChild(this.container.firstChild);
    for (let i = rows || 1; i > 0; i--)
      this.container.appendChild(document.createElement("hbox"));

    var row = this.container.firstChild;
    var colCount = 0;
    previews.forEach(function (preview) {
      if (!preview.hidden &&
          ++colCount > this._columns) {
        row = row.nextSibling;
        colCount = 1;
      }
      preview.setAttribute("minwidth", outerWidth);
      preview.setAttribute("height", outerHeight);
      preview.setAttribute("canvasstyle", canvasStyle);
      preview.removeAttribute("closebuttonhover");
      row.appendChild(preview);
    }, this);

    this._stack.width = this._maxPanelWidth;
    this.container.width = Math.ceil(outerWidth * Math.min(this._columns, this._visible));
    this.container.left = Math.round((this._maxPanelWidth - this.container.width) / 2);
    this.container.maxWidth = this._maxPanelWidth - this.container.left;
    this.container.maxHeight = rows * outerHeight;
  },

  _addPreview: function allTabs_addPreview(aTab) {
    var preview = document.createElement("button");
    preview.className = "allTabs-preview";
    preview._tab = aTab;
    this.container.lastChild.appendChild(preview);
  },

  _removePreview: function allTabs_removePreview(aPreview) {
    var updateUI = (this.isOpen && !aPreview.hidden);
    aPreview._tab = null;
    aPreview.parentNode.removeChild(aPreview);
    if (updateUI) {
      this._visible--;
      this._reflow();
      this.filterField.focus();
    }
  },

  _getPreview: function allTabs_getPreview(aTab) {
    var previews = this.previews;
    for (let i = 0; i < previews.length; i++)
      if (previews[i]._tab == aTab)
        return previews[i];
    return null;
  },

  _updateTabCloseButton: function allTabs_updateTabCloseButton(event) {
    if (event && event.target == this.tabCloseButton)
      return;

    if (this.tabCloseButton._targetPreview) {
      if (event && event.target == this.tabCloseButton._targetPreview)
        return;

      this.tabCloseButton._targetPreview.removeAttribute("closebuttonhover");
    }

    if (event &&
        event.target.parentNode.parentNode == this.container &&
        (event.target._tab.previousSibling || event.target._tab.nextSibling)) {
      let canvas = event.target.firstChild.getBoundingClientRect();
      let container = this.container.getBoundingClientRect();
      let tabCloseButton = this.tabCloseButton.getBoundingClientRect();
      let alignLeft = getComputedStyle(this.panel, "").direction == "rtl";
//@line 920 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-tabPreviews.js"
      this.tabCloseButton.left = canvas.left -
                                 container.left +
                                 parseInt(this.container.left) +
                                 (alignLeft ? 0 :
                                  canvas.width - tabCloseButton.width);
      this.tabCloseButton.top = canvas.top - container.top;
      this.tabCloseButton._targetPreview = event.target;
      this.tabCloseButton.style.visibility = "visible";
      event.target.setAttribute("closebuttonhover", "true");
    } else {
      this.tabCloseButton.style.visibility = "hidden";
      this.tabCloseButton.left = this.tabCloseButton.top = 0;
      this.tabCloseButton._targetPreview = null;
    }
  },

  _updatePreview: function allTabs_updatePreview(aPreview) {
    aPreview.setAttribute("label", aPreview._tab.label);
    aPreview.setAttribute("tooltiptext", aPreview._tab.label);
    aPreview.setAttribute("crop", aPreview._tab.crop);
    if (aPreview._tab.image)
      aPreview.setAttribute("image", aPreview._tab.image);
    else
      aPreview.removeAttribute("image");

    var thumbnail = tabPreviews.get(aPreview._tab);
    if (aPreview.firstChild) {
      if (aPreview.firstChild == thumbnail)
        return;
      aPreview.removeChild(aPreview.firstChild);
    }
    aPreview.appendChild(thumbnail);
  },

  _onKeyPress: function allTabs_onKeyPress(event) {
    if (event.eventPhase == event.CAPTURING_PHASE) {
      this._onCapturingKeyPress(event);
      return;
    }

    if (event.keyCode == event.DOM_VK_ESCAPE) {
      this.close();
      event.preventDefault();
      event.stopPropagation();
      return;
    }

    if (event.target == this.filterField) {
      switch (event.keyCode) {
        case event.DOM_VK_UP:
          if (this._visible) {
            let previews = this._visiblePreviews;
            let columns = Math.min(previews.length, this._columns);
            previews[Math.floor(previews.length / columns) * columns - 1].focus();
            event.preventDefault();
            event.stopPropagation();
          }
          break;
        case event.DOM_VK_DOWN:
          if (this._visible) {
            this._firstVisiblePreview.focus();
            event.preventDefault();
            event.stopPropagation();
          }
          break;
      }
    }
  },

  _onCapturingKeyPress: function allTabs_onCapturingKeyPress(event) {
    switch (event.keyCode) {
      case event.DOM_VK_UP:
      case event.DOM_VK_DOWN:
        if (event.target != this.filterField)
          this._advanceFocusVertically(event);
        break;
      case event.DOM_VK_RETURN:
        if (event.target == this.filterField) {
          this.filter();
          this.pick();
          event.preventDefault();
          event.stopPropagation();
        }
        break;
    }
  },

  _advanceFocusVertically: function allTabs_advanceFocusVertically(event) {
    var preview = document.activeElement;
    if (!preview || preview.parentNode.parentNode != this.container)
      return;

    event.stopPropagation();

    var up = (event.keyCode == event.DOM_VK_UP);
    var previews = this._visiblePreviews;

    if (up && preview == previews[0]) {
      this.filterField.focus();
      return;
    }

    var i       = previews.indexOf(preview);
    var columns = Math.min(previews.length, this._columns);
    var column  = i % columns;
    var row     = Math.floor(i / columns);

    function newIndex()    row * columns + column;
    function outOfBounds() newIndex() >= previews.length;

    if (up) {
      row--;
      if (row < 0) {
        let rows = Math.ceil(previews.length / columns);
        row = rows - 1;
        column--;
        if (outOfBounds())
          row--;
      }
    } else {
      row++;
      if (outOfBounds()) {
        if (column == columns - 1) {
          this.filterField.focus();
          return;
        }
        row = 0;
        column++;
      }
    }
    previews[newIndex()].focus();
  }
};
//@line 4 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-tabview.js"

let TabView = {
  _deck: null,
  _iframe: null,
  _window: null,
  _initialized: false,
  _browserKeyHandlerInitialized: false,
  _closedLastVisibleTabBeforeFrameInitialized: false,
  _isFrameLoading: false,
  _initFrameCallbacks: [],
  PREF_BRANCH: "browser.panorama.",
  PREF_FIRST_RUN: "browser.panorama.experienced_first_run",
  PREF_STARTUP_PAGE: "browser.startup.page",
  PREF_RESTORE_ENABLED_ONCE: "browser.panorama.session_restore_enabled_once",
  GROUPS_IDENTIFIER: "tabview-groups",
  VISIBILITY_IDENTIFIER: "tabview-visibility",

  // ----------
  get windowTitle() {
    delete this.windowTitle;
    let brandBundle = document.getElementById("bundle_brand");
    let brandShortName = brandBundle.getString("brandShortName");
    let title = gNavigatorBundle.getFormattedString("tabview.title", [brandShortName]);
    return this.windowTitle = title;
  },

  // ----------
  get firstUseExperienced() {
    let pref = this.PREF_FIRST_RUN;
    if (Services.prefs.prefHasUserValue(pref))
      return Services.prefs.getBoolPref(pref);

    return false;
  },

  // ----------
  set firstUseExperienced(val) {
    Services.prefs.setBoolPref(this.PREF_FIRST_RUN, val);
  },

  // ----------
  get sessionRestoreEnabledOnce() {
    let pref = this.PREF_RESTORE_ENABLED_ONCE;
    if (Services.prefs.prefHasUserValue(pref))
      return Services.prefs.getBoolPref(pref);

    return false;
  },

  // ----------
  set sessionRestoreEnabledOnce(val) {
    Services.prefs.setBoolPref(this.PREF_RESTORE_ENABLED_ONCE, val);
  },

  // ----------
  init: function TabView_init() {
    // disable the ToggleTabView command for popup windows
    goSetCommandEnabled("Browser:ToggleTabView", window.toolbar.visible);
    if (!window.toolbar.visible)
      return;

    if (this._initialized)
      return;

    if (this.firstUseExperienced) {
      // ___ visibility
      let sessionstore =
        Cc["@mozilla.org/browser/sessionstore;1"].getService(Ci.nsISessionStore);

      let data = sessionstore.getWindowValue(window, this.VISIBILITY_IDENTIFIER);
      if (data && data == "true") {
        this.show();
      } else {
        try {
          data = sessionstore.getWindowValue(window, this.GROUPS_IDENTIFIER);
          if (data) {
            let parsedData = JSON.parse(data);
            this.updateGroupNumberBroadcaster(parsedData.totalNumber || 1);
          }
        } catch (e) { }

        let self = this;
        // if a tab is changed from hidden to unhidden and the iframe is not
        // initialized, load the iframe and setup the tab.
        this._tabShowEventListener = function(event) {
          if (!self._window)
            self._initFrame(function() {
              self._window.UI.onTabSelect(gBrowser.selectedTab);
              if (self._closedLastVisibleTabBeforeFrameInitialized) {
                self._closedLastVisibleTabBeforeFrameInitialized = false;
                self._window.UI.showTabView(false);
              }
            });
        };
        this._tabCloseEventListener = function(event) {
          if (!self._window && gBrowser.visibleTabs.length == 0)
            self._closedLastVisibleTabBeforeFrameInitialized = true;
        };
        gBrowser.tabContainer.addEventListener(
          "TabShow", this._tabShowEventListener, false);
        gBrowser.tabContainer.addEventListener(
          "TabClose", this._tabCloseEventListener, false);

       if (this._tabBrowserHasHiddenTabs()) {
         this._setBrowserKeyHandlers();
       } else {
         // for restoring last session and undoing recently closed window
         this._SSWindowStateReadyListener = function (event) {
           if (this._tabBrowserHasHiddenTabs())
             this._setBrowserKeyHandlers();
         }.bind(this);
         window.addEventListener(
           "SSWindowStateReady", this._SSWindowStateReadyListener, false);
        }
      }
    }

    Services.prefs.addObserver(this.PREF_BRANCH, this, false);

    this._initialized = true;
  },

  // ----------
  // Observes topic changes.
  observe: function TabView_observe(subject, topic, data) {
    if (data == this.PREF_FIRST_RUN && this.firstUseExperienced) {
      this._addToolbarButton();
      this.enableSessionRestore();
    }
  },

  // ----------
  // Uninitializes TabView.
  uninit: function TabView_uninit() {
    if (!this._initialized)
      return;

    Services.prefs.removeObserver(this.PREF_BRANCH, this);

    if (this._tabShowEventListener)
      gBrowser.tabContainer.removeEventListener(
        "TabShow", this._tabShowEventListener, false);

    if (this._tabCloseEventListener)
      gBrowser.tabContainer.removeEventListener(
        "TabClose", this._tabCloseEventListener, false);

    if (this._SSWindowStateReadyListener)
      window.removeEventListener(
        "SSWindowStateReady", this._SSWindowStateReadyListener, false);

    this._initialized = false;
  },

  // ----------
  // Creates the frame and calls the callback once it's loaded. 
  // If the frame already exists, calls the callback immediately. 
  _initFrame: function TabView__initFrame(callback) {
    let hasCallback = typeof callback == "function";

    // prevent frame to be initialized for popup windows
    if (!window.toolbar.visible)
      return;

    if (this._window) {
      if (hasCallback)
        callback();
      return;
    }

    if (hasCallback)
      this._initFrameCallbacks.push(callback);

    if (this._isFrameLoading)
      return;

    this._isFrameLoading = true;

    TelemetryStopwatch.start("PANORAMA_INITIALIZATION_TIME_MS");

    // ___ find the deck
    this._deck = document.getElementById("tab-view-deck");

    // ___ create the frame
    this._iframe = document.createElement("iframe");
    this._iframe.id = "tab-view";
    this._iframe.setAttribute("transparent", "true");
    this._iframe.setAttribute("tooltip", "tab-view-tooltip");
    this._iframe.flex = 1;

    let self = this;

    window.addEventListener("tabviewframeinitialized", function onInit() {
      window.removeEventListener("tabviewframeinitialized", onInit, false);

      TelemetryStopwatch.finish("PANORAMA_INITIALIZATION_TIME_MS");

      self._isFrameLoading = false;
      self._window = self._iframe.contentWindow;
      self._setBrowserKeyHandlers();

      if (self._tabShowEventListener) {
        gBrowser.tabContainer.removeEventListener(
          "TabShow", self._tabShowEventListener, false);
        self._tabShowEventListener = null;
      }
      if (self._tabCloseEventListener) {
        gBrowser.tabContainer.removeEventListener(
          "TabClose", self._tabCloseEventListener, false);
        self._tabCloseEventListener = null;
      }
      if (self._SSWindowStateReadyListener) {
        window.removeEventListener(
          "SSWindowStateReady", self._SSWindowStateReadyListener, false);
        self._SSWindowStateReadyListener = null;
      }

      self._initFrameCallbacks.forEach(function (cb) cb());
      self._initFrameCallbacks = [];
    }, false);

    this._iframe.setAttribute("src", "chrome://browser/content/tabview.html");
    this._deck.appendChild(this._iframe);

    // ___ create tooltip
    let tooltip = document.createElement("tooltip");
    tooltip.id = "tab-view-tooltip";
    tooltip.setAttribute("onpopupshowing", "return TabView.fillInTooltip(document.tooltipNode);");
    document.getElementById("mainPopupSet").appendChild(tooltip);
  },

  // ----------
  getContentWindow: function TabView_getContentWindow() {
    return this._window;
  },

  // ----------
  isVisible: function TabView_isVisible() {
    return (this._deck ? this._deck.selectedPanel == this._iframe : false);
  },

  // ----------
  show: function TabView_show() {
    if (this.isVisible())
      return;

    let self = this;
    this._initFrame(function() {
      self._window.UI.showTabView(true);
    });
  },

  // ----------
  hide: function TabView_hide() {
    if (!this.isVisible())
      return;

    this._window.UI.exit();
  },

  // ----------
  toggle: function TabView_toggle() {
    if (this.isVisible())
      this.hide();
    else 
      this.show();
  },

  // ----------
  _tabBrowserHasHiddenTabs: function TabView_tabBrowserHasHiddenTabs() {
    return (gBrowser.tabs.length - gBrowser.visibleTabs.length) > 0;
  },

  // ----------
  updateContextMenu: function TabView_updateContextMenu(tab, popup) {
    let separator = document.getElementById("context_tabViewNamedGroups");
    let isEmpty = true;

    while (popup.firstChild && popup.firstChild != separator)
      popup.removeChild(popup.firstChild);

    let self = this;
    this._initFrame(function() {
      let activeGroup = tab._tabViewTabItem.parent;
      let groupItems = self._window.GroupItems.groupItems;

      groupItems.forEach(function(groupItem) {
        // if group has title, it's not hidden and there is no active group or
        // the active group id doesn't match the group id, a group menu item
        // would be added.
        if (!groupItem.hidden &&
            (groupItem.getTitle().trim() || groupItem.getChildren().length) &&
            (!activeGroup || activeGroup.id != groupItem.id)) {
          let menuItem = self._createGroupMenuItem(groupItem);
          popup.insertBefore(menuItem, separator);
          isEmpty = false;
        }
      });
      separator.hidden = isEmpty;
    });
  },

  // ----------
  _createGroupMenuItem: function TabView__createGroupMenuItem(groupItem) {
    let menuItem = document.createElement("menuitem");
    let title = groupItem.getTitle();

    if (!title.trim()) {
      let topChildLabel = groupItem.getTopChild().tab.label;
      let childNum = groupItem.getChildren().length;

      if (childNum > 1) {
        let num = childNum - 1;
        title =
          gNavigatorBundle.getString("tabview.moveToUnnamedGroup.label");
        title = PluralForm.get(num, title).replace("#1", topChildLabel).replace("#2", num);
      } else {
        title = topChildLabel;
      }
    }

    menuItem.setAttribute("label", title);
    menuItem.setAttribute("tooltiptext", title);
    menuItem.setAttribute("crop", "center");
    menuItem.setAttribute("class", "tabview-menuitem");
    menuItem.setAttribute(
      "oncommand",
      "TabView.moveTabTo(TabContextMenu.contextTab,'" + groupItem.id + "')");

    return menuItem;
  },

  // ----------
  moveTabTo: function TabView_moveTabTo(tab, groupItemId) {
    if (this._window) {
      this._window.GroupItems.moveTabToGroupItem(tab, groupItemId);
    } else {
      let self = this;
      this._initFrame(function() {
        self._window.GroupItems.moveTabToGroupItem(tab, groupItemId);
      });
    }
  },

  // ----------
  // Adds new key commands to the browser, for invoking the Tab Candy UI
  // and for switching between groups of tabs when outside of the Tab Candy UI.
  _setBrowserKeyHandlers: function TabView__setBrowserKeyHandlers() {
    if (this._browserKeyHandlerInitialized)
      return;

    this._browserKeyHandlerInitialized = true;

    let self = this;
    window.addEventListener("keypress", function(event) {
      if (self.isVisible() || !self._tabBrowserHasHiddenTabs())
        return;

      let charCode = event.charCode;
      // Control (+ Shift) + `
      if (event.ctrlKey && !event.metaKey && !event.altKey &&
          (charCode == 96 || charCode == 126)) {
        event.stopPropagation();
        event.preventDefault();

        self._initFrame(function() {
          let groupItems = self._window.GroupItems;
          let tabItem = groupItems.getNextGroupItemTab(event.shiftKey);
          if (!tabItem)
            return;

          if (gBrowser.selectedTab.pinned)
            groupItems.updateActiveGroupItemAndTabBar(tabItem, {dontSetActiveTabInGroup: true});
          else
            gBrowser.selectedTab = tabItem.tab;
        });
      }
    }, true);
  },

  // ----------
  // Prepares the tab view for undo close tab.
  prepareUndoCloseTab: function TabView_prepareUndoCloseTab(blankTabToRemove) {
    if (this._window) {
      this._window.UI.restoredClosedTab = true;

      if (blankTabToRemove && blankTabToRemove._tabViewTabItem)
        blankTabToRemove._tabViewTabItem.isRemovedAfterRestore = true;
    }
  },

  // ----------
  // Cleans up the tab view after undo close tab.
  afterUndoCloseTab: function TabView_afterUndoCloseTab() {
    if (this._window)
      this._window.UI.restoredClosedTab = false;
  },

  // ----------
  // On move to group pop showing.
  moveToGroupPopupShowing: function TabView_moveToGroupPopupShowing(event) {
    // Update the context menu only if Panorama was already initialized or if
    // there are hidden tabs.
    let numHiddenTabs = gBrowser.tabs.length - gBrowser.visibleTabs.length;
    if (this._window || numHiddenTabs > 0)
      this.updateContextMenu(TabContextMenu.contextTab, event.target);
  },

  // ----------
  // Function: _addToolbarButton
  // Adds the TabView button to the TabsToolbar.
  _addToolbarButton: function TabView__addToolbarButton() {
    let buttonId = "tabview-button";

    if (document.getElementById(buttonId))
      return;

    let toolbar = document.getElementById("TabsToolbar");
    let currentSet = toolbar.currentSet.split(",");

    let alltabsPos = currentSet.indexOf("alltabs-button");
    if (-1 == alltabsPos)
      return;

    currentSet[alltabsPos] += "," + buttonId;
    currentSet = currentSet.join(",");
    toolbar.currentSet = currentSet;
    toolbar.setAttribute("currentset", currentSet);
    document.persist(toolbar.id, "currentset");
  },

  // ----------
  // Function: updateGroupNumberBroadcaster
  // Updates the group number broadcaster.
  updateGroupNumberBroadcaster: function TabView_updateGroupNumberBroadcaster(number) {
    let groupsNumber = document.getElementById("tabviewGroupsNumber");
    groupsNumber.setAttribute("groups", number);
  },

  // ----------
  // Function: enableSessionRestore
  // Enables automatic session restore when the browser is started. Does
  // nothing if we already did that once in the past.
  enableSessionRestore: function TabView_enableSessionRestore() {
    if (!this._window || !this.firstUseExperienced)
      return;

    // do nothing if we already enabled session restore once
    if (this.sessionRestoreEnabledOnce)
      return;

    this.sessionRestoreEnabledOnce = true;

    // enable session restore if necessary
    if (Services.prefs.getIntPref(this.PREF_STARTUP_PAGE) != 3) {
      Services.prefs.setIntPref(this.PREF_STARTUP_PAGE, 3);

      // show banner
      this._window.UI.notifySessionRestoreEnabled();
    }
  },

  // ----------
  // Function: fillInTooltip
  // Fills in the tooltip text.
  fillInTooltip: function fillInTooltip(tipElement) {
    let retVal = false;
    let titleText = null;
    let direction = tipElement.ownerDocument.dir;

    while (!titleText && tipElement) {
      if (tipElement.nodeType == Node.ELEMENT_NODE)
        titleText = tipElement.getAttribute("title");
      tipElement = tipElement.parentNode;
    }
    let tipNode = document.getElementById("tab-view-tooltip");
    tipNode.style.direction = direction;

    if (titleText) {
      tipNode.setAttribute("label", titleText);
      retVal = true;
    }

    return retVal;
  }
};
//@line 6 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-thumbnails.js"

/**
 * Keeps thumbnails of open web pages up-to-date.
 */
let gBrowserThumbnails = {
  /**
   * Pref that controls whether we can store SSL content on disk
   */
  PREF_DISK_CACHE_SSL: "browser.cache.disk_cache_ssl",

  _captureDelayMS: 1000,

  /**
   * Used to keep track of disk_cache_ssl preference
   */
  _sslDiskCacheEnabled: null,

  /**
   * Map of capture() timeouts assigned to their browsers.
   */
  _timeouts: null,

  /**
   * List of tab events we want to listen for.
   */
  _tabEvents: ["TabClose", "TabSelect"],

  init: function Thumbnails_init() {
    try {
      if (Services.prefs.getBoolPref("browser.pagethumbnails.capturing_disabled"))
        return;
    } catch (e) {}

    PageThumbs.addExpirationFilter(this);
    gBrowser.addTabsProgressListener(this);
    Services.prefs.addObserver(this.PREF_DISK_CACHE_SSL, this, false);

    this._sslDiskCacheEnabled =
      Services.prefs.getBoolPref(this.PREF_DISK_CACHE_SSL);

    this._tabEvents.forEach(function (aEvent) {
      gBrowser.tabContainer.addEventListener(aEvent, this, false);
    }, this);

    this._timeouts = new WeakMap();
  },

  uninit: function Thumbnails_uninit() {
    PageThumbs.removeExpirationFilter(this);
    gBrowser.removeTabsProgressListener(this);
    Services.prefs.removeObserver(this.PREF_DISK_CACHE_SSL, this);

    this._tabEvents.forEach(function (aEvent) {
      gBrowser.tabContainer.removeEventListener(aEvent, this, false);
    }, this);
  },

  handleEvent: function Thumbnails_handleEvent(aEvent) {
    switch (aEvent.type) {
      case "scroll":
        let browser = aEvent.currentTarget;
        if (this._timeouts.has(browser))
          this._delayedCapture(browser);
        break;
      case "TabSelect":
        this._delayedCapture(aEvent.target.linkedBrowser);
        break;
      case "TabClose": {
        this._clearTimeout(aEvent.target.linkedBrowser);
        break;
      }
    }
  },

  observe: function Thumbnails_observe() {
    this._sslDiskCacheEnabled =
      Services.prefs.getBoolPref(this.PREF_DISK_CACHE_SSL);
  },

  filterForThumbnailExpiration:
  function Thumbnails_filterForThumbnailExpiration(aCallback) {
    aCallback([browser.currentURI.spec for (browser of gBrowser.browsers)]);
  },

  /**
   * State change progress listener for all tabs.
   */
  onStateChange: function Thumbnails_onStateChange(aBrowser, aWebProgress,
                                                   aRequest, aStateFlags, aStatus) {
    if (aStateFlags & Ci.nsIWebProgressListener.STATE_STOP &&
        aStateFlags & Ci.nsIWebProgressListener.STATE_IS_NETWORK)
      this._delayedCapture(aBrowser);
  },

  _capture: function Thumbnails_capture(aBrowser) {
    if (this._shouldCapture(aBrowser))
      PageThumbs.captureAndStore(aBrowser);
  },

  _delayedCapture: function Thumbnails_delayedCapture(aBrowser) {
    if (this._timeouts.has(aBrowser))
      clearTimeout(this._timeouts.get(aBrowser));
    else
      aBrowser.addEventListener("scroll", this, true);

    let timeout = setTimeout(function () {
      this._clearTimeout(aBrowser);
      this._capture(aBrowser);
    }.bind(this), this._captureDelayMS);

    this._timeouts.set(aBrowser, timeout);
  },

  _shouldCapture: function Thumbnails_shouldCapture(aBrowser) {
    // Capture only if it's the currently selected tab.
    if (aBrowser != gBrowser.selectedBrowser)
      return false;

    // Don't capture in per-window private browsing mode.
    if (PrivateBrowsingUtils.isWindowPrivate(window))
      return false;

    let doc = aBrowser.contentDocument;

    // FIXME Bug 720575 - Don't capture thumbnails for SVG or XML documents as
    //       that currently regresses Talos SVG tests.
    if (doc instanceof SVGDocument || doc instanceof XMLDocument)
      return false;

    // There's no point in taking screenshot of loading pages.
    if (aBrowser.docShell.busyFlags != Ci.nsIDocShell.BUSY_FLAGS_NONE)
      return false;

    // Don't take screenshots of about: pages.
    if (aBrowser.currentURI.schemeIs("about"))
      return false;

    let channel = aBrowser.docShell.currentDocumentChannel;

    // No valid document channel. We shouldn't take a screenshot.
    if (!channel)
      return false;

    // Don't take screenshots of internally redirecting about: pages.
    // This includes error pages.
    let uri = channel.originalURI;
    if (uri.schemeIs("about"))
      return false;

    let httpChannel;
    try {
      httpChannel = channel.QueryInterface(Ci.nsIHttpChannel);
    } catch (e) { /* Not an HTTP channel. */ }

    if (httpChannel) {
      // Continue only if we have a 2xx status code.
      if (Math.floor(httpChannel.responseStatus / 100) != 2)
        return false;

      // Cache-Control: no-store.
      if (httpChannel.isNoStoreResponse())
        return false;

      // Don't capture HTTPS pages unless the user explicitly enabled it.
      if (uri.schemeIs("https") && !this._sslDiskCacheEnabled)
        return false;
    }

    return true;
  },

  _clearTimeout: function Thumbnails_clearTimeout(aBrowser) {
    if (this._timeouts.has(aBrowser)) {
      aBrowser.removeEventListener("scroll", this, false);
      clearTimeout(this._timeouts.get(aBrowser));
      this._timeouts.delete(aBrowser);
    }
  }
};
//@line 5 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-webrtcUI.js"

let WebrtcIndicator = {
  init: function () {
    let temp = {};
    Cu.import("resource:///modules/webrtcUI.jsm", temp);
    this.UIModule = temp.webrtcUI;

    this.updateButton();
  },

  get button() {
    delete this.button;
    return this.button = document.getElementById("webrtc-status-button");
  },

  updateButton: function () {
    this.button.hidden = !this.UIModule.showGlobalIndicator;
  },

  fillPopup: function (aPopup) {
    this._menuitemData = new WeakMap;
    for (let streamData of this.UIModule.activeStreams) {
      let menuitem = document.createElement("menuitem");
      menuitem.setAttribute("label", streamData.uri);
      menuitem.setAttribute("tooltiptext", streamData.uri);

      this._menuitemData.set(menuitem, streamData);

      aPopup.appendChild(menuitem);
    }
  },

  clearPopup: function (aPopup) {
    while (aPopup.lastChild)
      aPopup.removeChild(aPopup.lastChild);
  },

  menuCommand: function (aMenuitem) {
    let streamData = this._menuitemData.get(aMenuitem);
    if (!streamData)
      return;

    let tab = streamData.tab;
    let browserWindow = tab.ownerDocument.defaultView;
    browserWindow.gBrowser.selectedTab = tab;
    browserWindow.focus();
  }
}
//@line 160 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

//@line 4 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-data-submission-info-bar.js"

/**
 * Represents an info bar that shows a data submission notification.
 */
let gDataNotificationInfoBar = {
  _OBSERVERS: [
    "datareporting:notify-data-policy:request",
    "datareporting:notify-data-policy:close",
  ],

  _DATA_REPORTING_NOTIFICATION: "data-reporting",

  _notificationBox: null,

  get _log() {
    let log4moz = Cu.import("resource://services-common/log4moz.js", {}).Log4Moz;
    delete this._log;
    return this._log = log4moz.repository.getLogger("Services.DataReporting.InfoBar");
  },

  init: function() {
    window.addEventListener("unload", function onUnload() {
      window.removeEventListener("unload", onUnload, false);

      for (let o of this._OBSERVERS) {
        Services.obs.removeObserver(this, o);
      }
    }.bind(this), false);

    for (let o of this._OBSERVERS) {
      Services.obs.addObserver(this, o, true);
    }
  },

  _ensureNotificationBox: function () {
    if (this._notificationBox) {
      return;
    }

    let nb = document.createElementNS(
      "http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul",
      "notificationbox"
    );
    nb.id = "data-notification-notify-bar";
    nb.setAttribute("flex", "1");

    let bottombox = document.getElementById("browser-bottombox");
    bottombox.insertBefore(nb, bottombox.firstChild);

    this._notificationBox = nb;
  },

  _getDataReportingNotification: function (name=this._DATA_REPORTING_NOTIFICATION) {
    if (!this._notificationBox) {
      return undefined;
    }
    return this._notificationBox.getNotificationWithValue(name);
  },

  _displayDataPolicyInfoBar: function (request) {
    this._ensureNotificationBox();

    if (this._getDataReportingNotification()) {
      return;
    }

    let policy = Cc["@mozilla.org/datareporting/service;1"]
                   .getService(Ci.nsISupports)
                   .wrappedJSObject
                   .policy;

    let brandBundle = document.getElementById("bundle_brand");
    let appName = brandBundle.getString("brandShortName");
    let vendorName = brandBundle.getString("vendorShortName");

    let message = gNavigatorBundle.getFormattedString(
      "dataReportingNotification.message",
      [appName, vendorName]);

    let actionTaken = false;

    let buttons = [{
      label: gNavigatorBundle.getString("dataReportingNotification.button.label"),
      accessKey: gNavigatorBundle.getString("dataReportingNotification.button.accessKey"),
      popup: null,
      callback: function () {
        // Clicking the button to go to the preferences tab constitutes
        // acceptance of the data upload policy for Firefox Health Report.
        // This will ensure the checkbox is checked. The user has the option of
        // unchecking it.
        request.onUserAccept("info-bar-button-pressed");
        actionTaken = true;
        window.openAdvancedPreferences("dataChoicesTab");
      },
    }];

    this._log.info("Creating data reporting policy notification.");
    let notification = this._notificationBox.appendNotification(
      message,
      this._DATA_REPORTING_NOTIFICATION,
      null,
      this._notificationBox.PRIORITY_INFO_HIGH,
      buttons,
      function onEvent(event) {
        if (event == "removed") {
          if (!actionTaken) {
            request.onUserAccept("info-bar-dismissed");
          }

          Services.obs.notifyObservers(null, "datareporting:notify-data-policy:close", null);
        }
      }.bind(this)
    );

    // Keep open until user closes it.
    notification.persistence = -1;

    // Tell the notification request we have displayed the notification.
    request.onUserNotifyComplete();
  },

  _clearPolicyNotification: function () {
    let notification = this._getDataReportingNotification();
    if (notification) {
      notification.close();
    }
  },

  onNotifyDataPolicy: function (request) {
    try {
      this._displayDataPolicyInfoBar(request);
    } catch (ex) {
      request.onUserNotifyFailed(ex);
    }
  },

  observe: function(subject, topic, data) {
    switch (topic) {
      case "datareporting:notify-data-policy:request":
        this.onNotifyDataPolicy(subject.wrappedJSObject.object);
        break;

      case "datareporting:notify-data-policy:close":
        this._clearPolicyNotification();
        break;

      default:
    }
  },

  QueryInterface: XPCOMUtils.generateQI([
    Ci.nsIObserver,
    Ci.nsISupportsWeakReference,
  ]),
};

//@line 164 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

//@line 4 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser-syncui.js"

// gSyncUI handles updating the tools menu
let gSyncUI = {
  _obs: ["weave:service:sync:start",
         "weave:service:sync:delayed",
         "weave:service:quota:remaining",
         "weave:service:setup-complete",
         "weave:service:login:start",
         "weave:service:login:finish",
         "weave:service:logout:finish",
         "weave:service:start-over",
         "weave:ui:login:error",
         "weave:ui:sync:error",
         "weave:ui:sync:finish",
         "weave:ui:clear-error",
  ],

  _unloaded: false,

  init: function SUI_init() {
    // Proceed to set up the UI if Sync has already started up.
    // Otherwise we'll do it when Sync is firing up.
    if (Weave.Status.ready) {
      this.initUI();
      return;
    }

    Services.obs.addObserver(this, "weave:service:ready", true);

    // Remove the observer if the window is closed before the observer
    // was triggered.
    window.addEventListener("unload", function onUnload() {
      gSyncUI._unloaded = true;
      window.removeEventListener("unload", onUnload, false);
      Services.obs.removeObserver(gSyncUI, "weave:service:ready");

      if (Weave.Status.ready) {
        gSyncUI._obs.forEach(function(topic) {
          Services.obs.removeObserver(gSyncUI, topic);
        });
      }
    }, false);
  },

  initUI: function SUI_initUI() {
    // If this is a browser window?
    if (gBrowser) {
      this._obs.push("weave:notification:added");
    }

    this._obs.forEach(function(topic) {
      Services.obs.addObserver(this, topic, true);
    }, this);

    if (gBrowser && Weave.Notifications.notifications.length) {
      this.initNotifications();
    }
    this.updateUI();
  },

  initNotifications: function SUI_initNotifications() {
    const XULNS = "http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul";
    let notificationbox = document.createElementNS(XULNS, "notificationbox");
    notificationbox.id = "sync-notifications";
    notificationbox.setAttribute("flex", "1");

    let bottombox = document.getElementById("browser-bottombox");
    bottombox.insertBefore(notificationbox, bottombox.firstChild);

    // Force a style flush to ensure that our binding is attached.
    notificationbox.clientTop;

    // notificationbox will listen to observers from now on.
    Services.obs.removeObserver(this, "weave:notification:added");
  },

  _wasDelayed: false,

  _needsSetup: function SUI__needsSetup() {
    let firstSync = "";
    try {
      firstSync = Services.prefs.getCharPref("services.sync.firstSync");
    } catch (e) { }
    return Weave.Status.checkSetup() == Weave.CLIENT_NOT_CONFIGURED ||
           firstSync == "notReady";
  },

  updateUI: function SUI_updateUI() {
    let needsSetup = this._needsSetup();
    document.getElementById("sync-setup-state").hidden = !needsSetup;
    document.getElementById("sync-syncnow-state").hidden = needsSetup;

    if (!gBrowser)
      return;

    let button = document.getElementById("sync-button");
    if (!button)
      return;

    button.removeAttribute("status");
    this._updateLastSyncTime();
    if (needsSetup)
      button.removeAttribute("tooltiptext");
  },


  // Functions called by observers
  onActivityStart: function SUI_onActivityStart() {
    if (!gBrowser)
      return;

    let button = document.getElementById("sync-button");
    if (!button)
      return;

    button.setAttribute("status", "active");
  },

  onSyncDelay: function SUI_onSyncDelay() {
    // basically, we want to just inform users that stuff is going to take a while
    let title = this._stringBundle.GetStringFromName("error.sync.no_node_found.title");
    let description = this._stringBundle.GetStringFromName("error.sync.no_node_found");
    let buttons = [new Weave.NotificationButton(
      this._stringBundle.GetStringFromName("error.sync.serverStatusButton.label"),
      this._stringBundle.GetStringFromName("error.sync.serverStatusButton.accesskey"),
      function() { gSyncUI.openServerStatus(); return true; }
    )];
    let notification = new Weave.Notification(
      title, description, null, Weave.Notifications.PRIORITY_INFO, buttons);
    Weave.Notifications.replaceTitle(notification);
    this._wasDelayed = true;
  },

  onLoginFinish: function SUI_onLoginFinish() {
    // Clear out any login failure notifications
    let title = this._stringBundle.GetStringFromName("error.login.title");
    this.clearError(title);
  },

  onSetupComplete: function SUI_onSetupComplete() {
    this.onLoginFinish();
  },

  onLoginError: function SUI_onLoginError() {
    // if login fails, any other notifications are essentially moot
    Weave.Notifications.removeAll();

    // if we haven't set up the client, don't show errors
    if (this._needsSetup()) {
      this.updateUI();
      return;
    }

    let title = this._stringBundle.GetStringFromName("error.login.title");

    let description;
    if (Weave.Status.sync == Weave.PROLONGED_SYNC_FAILURE) {
      // Convert to days
      let lastSync =
        Services.prefs.getIntPref("services.sync.errorhandler.networkFailureReportTimeout") / 86400;
      description =
        this._stringBundle.formatStringFromName("error.sync.prolonged_failure", [lastSync], 1);
    } else {
      let reason = Weave.Utils.getErrorString(Weave.Status.login);
      description =
        this._stringBundle.formatStringFromName("error.sync.description", [reason], 1);
    }

    let buttons = [];
    buttons.push(new Weave.NotificationButton(
      this._stringBundle.GetStringFromName("error.login.prefs.label"),
      this._stringBundle.GetStringFromName("error.login.prefs.accesskey"),
      function() { gSyncUI.openPrefs(); return true; }
    ));

    let notification = new Weave.Notification(title, description, null,
                                              Weave.Notifications.PRIORITY_WARNING, buttons);
    Weave.Notifications.replaceTitle(notification);
    this.updateUI();
  },

  onLogout: function SUI_onLogout() {
    this.updateUI();
  },

  onStartOver: function SUI_onStartOver() {
    this.clearError();
  },

  onQuotaNotice: function onQuotaNotice(subject, data) {
    let title = this._stringBundle.GetStringFromName("warning.sync.quota.label");
    let description = this._stringBundle.GetStringFromName("warning.sync.quota.description");
    let buttons = [];
    buttons.push(new Weave.NotificationButton(
      this._stringBundle.GetStringFromName("error.sync.viewQuotaButton.label"),
      this._stringBundle.GetStringFromName("error.sync.viewQuotaButton.accesskey"),
      function() { gSyncUI.openQuotaDialog(); return true; }
    ));

    let notification = new Weave.Notification(
      title, description, null, Weave.Notifications.PRIORITY_WARNING, buttons);
    Weave.Notifications.replaceTitle(notification);
  },

  openServerStatus: function () {
    let statusURL = Services.prefs.getCharPref("services.sync.statusURL");
    window.openUILinkIn(statusURL, "tab");
  },

  // Commands
  doSync: function SUI_doSync() {
    setTimeout(function() Weave.Service.errorHandler.syncAndReportErrors(), 0);
  },

  handleToolbarButton: function SUI_handleStatusbarButton() {
    if (this._needsSetup())
      this.openSetup();
    else
      this.doSync();
  },

  //XXXzpao should be part of syncCommon.js - which we might want to make a module...
  //        To be fixed in a followup (bug 583366)

  /**
   * Invoke the Sync setup wizard.
   *
   * @param wizardType
   *        Indicates type of wizard to launch:
   *          null    -- regular set up wizard
   *          "pair"  -- pair a device first
   *          "reset" -- reset sync
   */

  openSetup: function SUI_openSetup(wizardType) {
    let win = Services.wm.getMostRecentWindow("Weave:AccountSetup");
    if (win)
      win.focus();
    else {
      window.openDialog("chrome://browser/content/sync/setup.xul",
                        "weaveSetup", "centerscreen,chrome,resizable=no",
                        wizardType);
    }
  },

  openAddDevice: function () {
    if (!Weave.Utils.ensureMPUnlocked())
      return;

    let win = Services.wm.getMostRecentWindow("Sync:AddDevice");
    if (win)
      win.focus();
    else
      window.openDialog("chrome://browser/content/sync/addDevice.xul",
                        "syncAddDevice", "centerscreen,chrome,resizable=no");
  },

  openQuotaDialog: function SUI_openQuotaDialog() {
    let win = Services.wm.getMostRecentWindow("Sync:ViewQuota");
    if (win)
      win.focus();
    else
      Services.ww.activeWindow.openDialog(
        "chrome://browser/content/sync/quota.xul", "",
        "centerscreen,chrome,dialog,modal");
  },

  openPrefs: function SUI_openPrefs() {
    openPreferences("paneSync");
  },


  // Helpers
  _updateLastSyncTime: function SUI__updateLastSyncTime() {
    if (!gBrowser)
      return;

    let syncButton = document.getElementById("sync-button");
    if (!syncButton)
      return;

    let lastSync;
    try {
      lastSync = Services.prefs.getCharPref("services.sync.lastSync");
    }
    catch (e) { };
    if (!lastSync || this._needsSetup()) {
      syncButton.removeAttribute("tooltiptext");
      return;
    }

    // Show the day-of-week and time (HH:MM) of last sync
    let lastSyncDate = new Date(lastSync).toLocaleFormat("%a %H:%M");
    let lastSyncLabel =
      this._stringBundle.formatStringFromName("lastSync2.label", [lastSyncDate], 1);

    syncButton.setAttribute("tooltiptext", lastSyncLabel);
  },

  clearError: function SUI_clearError(errorString) {
    Weave.Notifications.removeAll(errorString);
    this.updateUI();
  },

  onSyncFinish: function SUI_onSyncFinish() {
    let title = this._stringBundle.GetStringFromName("error.sync.title");

    // Clear out sync failures on a successful sync
    this.clearError(title);

    if (this._wasDelayed && Weave.Status.sync != Weave.NO_SYNC_NODE_FOUND) {
      title = this._stringBundle.GetStringFromName("error.sync.no_node_found.title");
      this.clearError(title);
      this._wasDelayed = false;
    }
  },

  onSyncError: function SUI_onSyncError() {
    let title = this._stringBundle.GetStringFromName("error.sync.title");

    if (Weave.Status.login != Weave.LOGIN_SUCCEEDED) {
      this.onLoginError();
      return;
    }

    let description;
    if (Weave.Status.sync == Weave.PROLONGED_SYNC_FAILURE) {
      // Convert to days
      let lastSync =
        Services.prefs.getIntPref("services.sync.errorhandler.networkFailureReportTimeout") / 86400;
      description =
        this._stringBundle.formatStringFromName("error.sync.prolonged_failure", [lastSync], 1);
    } else {
      let error = Weave.Utils.getErrorString(Weave.Status.sync);
      description =
        this._stringBundle.formatStringFromName("error.sync.description", [error], 1);
    }
    let priority = Weave.Notifications.PRIORITY_WARNING;
    let buttons = [];

    // Check if the client is outdated in some way
    let outdated = Weave.Status.sync == Weave.VERSION_OUT_OF_DATE;
    for (let [engine, reason] in Iterator(Weave.Status.engines))
      outdated = outdated || reason == Weave.VERSION_OUT_OF_DATE;

    if (outdated) {
      description = this._stringBundle.GetStringFromName(
        "error.sync.needUpdate.description");
      buttons.push(new Weave.NotificationButton(
        this._stringBundle.GetStringFromName("error.sync.needUpdate.label"),
        this._stringBundle.GetStringFromName("error.sync.needUpdate.accesskey"),
        function() { window.openUILinkIn("https://services.mozilla.com/update/", "tab"); return true; }
      ));
    }
    else if (Weave.Status.sync == Weave.OVER_QUOTA) {
      description = this._stringBundle.GetStringFromName(
        "error.sync.quota.description");
      buttons.push(new Weave.NotificationButton(
        this._stringBundle.GetStringFromName(
          "error.sync.viewQuotaButton.label"),
        this._stringBundle.GetStringFromName(
          "error.sync.viewQuotaButton.accesskey"),
        function() { gSyncUI.openQuotaDialog(); return true; } )
      );
    }
    else if (Weave.Status.enforceBackoff) {
      priority = Weave.Notifications.PRIORITY_INFO;
      buttons.push(new Weave.NotificationButton(
        this._stringBundle.GetStringFromName("error.sync.serverStatusButton.label"),
        this._stringBundle.GetStringFromName("error.sync.serverStatusButton.accesskey"),
        function() { gSyncUI.openServerStatus(); return true; }
      ));
    }
    else {
      priority = Weave.Notifications.PRIORITY_INFO;
      buttons.push(new Weave.NotificationButton(
        this._stringBundle.GetStringFromName("error.sync.tryAgainButton.label"),
        this._stringBundle.GetStringFromName("error.sync.tryAgainButton.accesskey"),
        function() { gSyncUI.doSync(); return true; }
      ));
    }

    let notification =
      new Weave.Notification(title, description, null, priority, buttons);
    Weave.Notifications.replaceTitle(notification);

    if (this._wasDelayed && Weave.Status.sync != Weave.NO_SYNC_NODE_FOUND) {
      title = this._stringBundle.GetStringFromName("error.sync.no_node_found.title");
      Weave.Notifications.removeAll(title);
      this._wasDelayed = false;
    }

    this.updateUI();
  },

  observe: function SUI_observe(subject, topic, data) {
    if (this._unloaded) {
      Cu.reportError("SyncUI observer called after unload: " + topic);
      return;
    }

    switch (topic) {
      case "weave:service:sync:start":
        this.onActivityStart();
        break;
      case "weave:ui:sync:finish":
        this.onSyncFinish();
        break;
      case "weave:ui:sync:error":
        this.onSyncError();
        break;
      case "weave:service:sync:delayed":
        this.onSyncDelay();
        break;
      case "weave:service:quota:remaining":
        this.onQuotaNotice();
        break;
      case "weave:service:setup-complete":
        this.onSetupComplete();
        break;
      case "weave:service:login:start":
        this.onActivityStart();
        break;
      case "weave:service:login:finish":
        this.onLoginFinish();
        break;
      case "weave:ui:login:error":
        this.onLoginError();
        break;
      case "weave:service:logout:finish":
        this.onLogout();
        break;
      case "weave:service:start-over":
        this.onStartOver();
        break;
      case "weave:service:ready":
        this.initUI();
        break;
      case "weave:notification:added":
        this.initNotifications();
        break;
      case "weave:ui:clear-error":
        this.clearError();
        break;
    }
  },

  QueryInterface: XPCOMUtils.generateQI([
    Ci.nsIObserver,
    Ci.nsISupportsWeakReference
  ])
};

XPCOMUtils.defineLazyGetter(gSyncUI, "_stringBundle", function() {
  //XXXzpao these strings should probably be moved from /services to /browser... (bug 583381)
  //        but for now just make it work
  return Cc["@mozilla.org/intl/stringbundle;1"].
         getService(Ci.nsIStringBundleService).
         createBundle("chrome://weave/locale/services/sync.properties");
});

//@line 168 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

XPCOMUtils.defineLazyGetter(this, "Win7Features", function () {
//@line 187 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  return null;
});

//@line 191 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
XPCOMUtils.defineLazyServiceGetter(this, "gCrashReporter",
                                   "@mozilla.org/xre/app-info;1",
                                   "nsICrashReporter");
//@line 195 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

XPCOMUtils.defineLazyGetter(this, "PageMenu", function() {
  let tmp = {};
  Cu.import("resource://gre/modules/PageMenu.jsm", tmp);
  return new tmp.PageMenu();
});

/**
* We can avoid adding multiple load event listeners and save some time by adding
* one listener that calls all real handlers.
*/
function pageShowEventHandlers(event) {
  charsetLoadListener();
  XULBrowserWindow.asyncUpdateUI();

  // The PluginClickToPlay events are not fired when navigating using the
  // BF cache. |event.persisted| is true when the page is loaded from the
  // BF cache, so this code reshows the notification if necessary.
  if (event.persisted)
    gPluginHandler.reshowClickToPlayNotification();
}

function UpdateBackForwardCommands(aWebNavigation) {
  var backBroadcaster = document.getElementById("Browser:Back");
  var forwardBroadcaster = document.getElementById("Browser:Forward");

  // Avoid setting attributes on broadcasters if the value hasn't changed!
  // Remember, guys, setting attributes on elements is expensive!  They
  // get inherited into anonymous content, broadcast to other widgets, etc.!
  // Don't do it if the value hasn't changed! - dwh

  var backDisabled = backBroadcaster.hasAttribute("disabled");
  var forwardDisabled = forwardBroadcaster.hasAttribute("disabled");
  if (backDisabled == aWebNavigation.canGoBack) {
    if (backDisabled)
      backBroadcaster.removeAttribute("disabled");
    else
      backBroadcaster.setAttribute("disabled", true);
  }

  if (forwardDisabled == aWebNavigation.canGoForward) {
    if (forwardDisabled)
      forwardBroadcaster.removeAttribute("disabled");
    else
      forwardBroadcaster.setAttribute("disabled", true);
  }
}

/**
 * Click-and-Hold implementation for the Back and Forward buttons
 * XXXmano: should this live in toolbarbutton.xml?
 */
function SetClickAndHoldHandlers() {
  var timer;

  function openMenu(aButton) {
    cancelHold(aButton);
    aButton.firstChild.hidden = false;
    aButton.open = true;
  }

  function mousedownHandler(aEvent) {
    if (aEvent.button != 0 ||
        aEvent.currentTarget.open ||
        aEvent.currentTarget.disabled)
      return;

    // Prevent the menupopup from opening immediately
    aEvent.currentTarget.firstChild.hidden = true;

    aEvent.currentTarget.addEventListener("mouseout", mouseoutHandler, false);
    aEvent.currentTarget.addEventListener("mouseup", mouseupHandler, false);
    timer = setTimeout(openMenu, 500, aEvent.currentTarget);
  }

  function mouseoutHandler(aEvent) {
    let buttonRect = aEvent.currentTarget.getBoundingClientRect();
    if (aEvent.clientX >= buttonRect.left &&
        aEvent.clientX <= buttonRect.right &&
        aEvent.clientY >= buttonRect.bottom)
      openMenu(aEvent.currentTarget);
    else
      cancelHold(aEvent.currentTarget);
  }

  function mouseupHandler(aEvent) {
    cancelHold(aEvent.currentTarget);
  }

  function cancelHold(aButton) {
    clearTimeout(timer);
    aButton.removeEventListener("mouseout", mouseoutHandler, false);
    aButton.removeEventListener("mouseup", mouseupHandler, false);
  }

  function clickHandler(aEvent) {
    if (aEvent.button == 0 &&
        aEvent.target == aEvent.currentTarget &&
        !aEvent.currentTarget.open &&
        !aEvent.currentTarget.disabled) {
      let cmdEvent = document.createEvent("xulcommandevent");
      cmdEvent.initCommandEvent("command", true, true, window, 0,
                                aEvent.ctrlKey, aEvent.altKey, aEvent.shiftKey,
                                aEvent.metaKey, null);
      aEvent.currentTarget.dispatchEvent(cmdEvent);
    }
  }

  function _addClickAndHoldListenersOnElement(aElm) {
    aElm.addEventListener("mousedown", mousedownHandler, true);
    aElm.addEventListener("click", clickHandler, true);
  }

  // Bug 414797: Clone unified-back-forward-button's context menu into both the
  // back and the forward buttons.
  var unifiedButton = document.getElementById("unified-back-forward-button");
  if (unifiedButton && !unifiedButton._clickHandlersAttached) {
    unifiedButton._clickHandlersAttached = true;

    let popup = document.getElementById("backForwardMenu").cloneNode(true);
    popup.removeAttribute("id");
    // Prevent the context attribute on unified-back-forward-button from being
    // inherited.
    popup.setAttribute("context", "");

    let backButton = document.getElementById("back-button");
    backButton.setAttribute("type", "menu");
    backButton.appendChild(popup);
    _addClickAndHoldListenersOnElement(backButton);

    let forwardButton = document.getElementById("forward-button");
    popup = popup.cloneNode(true);
    forwardButton.setAttribute("type", "menu");
    forwardButton.appendChild(popup);
    _addClickAndHoldListenersOnElement(forwardButton);
  }
}

const gSessionHistoryObserver = {
  observe: function(subject, topic, data)
  {
    if (topic != "browser:purge-session-history")
      return;

    var backCommand = document.getElementById("Browser:Back");
    backCommand.setAttribute("disabled", "true");
    var fwdCommand = document.getElementById("Browser:Forward");
    fwdCommand.setAttribute("disabled", "true");

    // Hide session restore button on about:home
    window.messageManager.broadcastAsyncMessage("Browser:HideSessionRestoreButton");

    if (gURLBar) {
      // Clear undo history of the URL bar
      gURLBar.editor.transactionManager.clear()
    }
  }
};

/**
 * Given a starting docshell and a URI to look up, find the docshell the URI
 * is loaded in.
 * @param   aDocument
 *          A document to find instead of using just a URI - this is more specific.
 * @param   aDocShell
 *          The doc shell to start at
 * @param   aSoughtURI
 *          The URI that we're looking for
 * @returns The doc shell that the sought URI is loaded in. Can be in
 *          subframes.
 */
function findChildShell(aDocument, aDocShell, aSoughtURI) {
  aDocShell.QueryInterface(Components.interfaces.nsIWebNavigation);
  aDocShell.QueryInterface(Components.interfaces.nsIInterfaceRequestor);
  var doc = aDocShell.getInterface(Components.interfaces.nsIDOMDocument);
  if ((aDocument && doc == aDocument) ||
      (aSoughtURI && aSoughtURI.spec == aDocShell.currentURI.spec))
    return aDocShell;

  var node = aDocShell.QueryInterface(Components.interfaces.nsIDocShellTreeNode);
  for (var i = 0; i < node.childCount; ++i) {
    var docShell = node.getChildAt(i);
    docShell = findChildShell(aDocument, docShell, aSoughtURI);
    if (docShell)
      return docShell;
  }
  return null;
}

var gPopupBlockerObserver = {
  _reportButton: null,

  onReportButtonClick: function (aEvent)
  {
    if (aEvent.button != 0 || aEvent.target != this._reportButton)
      return;

    document.getElementById("blockedPopupOptions")
            .openPopup(this._reportButton, "after_end", 0, 2, false, false, aEvent);
  },

  handleEvent: function (aEvent)
  {
    if (aEvent.originalTarget != gBrowser.selectedBrowser)
      return;

    if (!this._reportButton && gURLBar)
      this._reportButton = document.getElementById("page-report-button");

    if (!gBrowser.pageReport) {
      // Hide the icon in the location bar (if the location bar exists)
      if (gURLBar)
        this._reportButton.hidden = true;
      return;
    }

    if (gURLBar)
      this._reportButton.hidden = false;

    // Only show the notification again if we've not already shown it. Since
    // notifications are per-browser, we don't need to worry about re-adding
    // it.
    if (!gBrowser.pageReport.reported) {
      if (gPrefService.getBoolPref("privacy.popups.showBrowserMessage")) {
        var brandBundle = document.getElementById("bundle_brand");
        var brandShortName = brandBundle.getString("brandShortName");
        var message;
        var popupCount = gBrowser.pageReport.length;
//@line 427 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        var popupButtonText = gNavigatorBundle.getString("popupWarningButtonUnix");
        var popupButtonAccesskey = gNavigatorBundle.getString("popupWarningButtonUnix.accesskey");
//@line 430 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        if (popupCount > 1)
          message = gNavigatorBundle.getFormattedString("popupWarningMultiple", [brandShortName, popupCount]);
        else
          message = gNavigatorBundle.getFormattedString("popupWarning", [brandShortName]);

        var notificationBox = gBrowser.getNotificationBox();
        var notification = notificationBox.getNotificationWithValue("popup-blocked");
        if (notification) {
          notification.label = message;
        }
        else {
          var buttons = [{
            label: popupButtonText,
            accessKey: popupButtonAccesskey,
            popup: "blockedPopupOptions",
            callback: null
          }];

          const priority = notificationBox.PRIORITY_WARNING_MEDIUM;
          notificationBox.appendNotification(message, "popup-blocked",
                                             "chrome://browser/skin/Info.png",
                                             priority, buttons);
        }
      }

      // Record the fact that we've reported this blocked popup, so we don't
      // show it again.
      gBrowser.pageReport.reported = true;
    }
  },

  toggleAllowPopupsForSite: function (aEvent)
  {
    var pm = Services.perms;
    var shouldBlock = aEvent.target.getAttribute("block") == "true";
    var perm = shouldBlock ? pm.DENY_ACTION : pm.ALLOW_ACTION;
    pm.add(gBrowser.currentURI, "popup", perm);

    gBrowser.getNotificationBox().removeCurrentNotification();
  },

  fillPopupList: function (aEvent)
  {
    // XXXben - rather than using |currentURI| here, which breaks down on multi-framed sites
    //          we should really walk the pageReport and create a list of "allow for <host>"
    //          menuitems for the common subset of hosts present in the report, this will
    //          make us frame-safe.
    //
    // XXXjst - Note that when this is fixed to work with multi-framed sites,
    //          also back out the fix for bug 343772 where
    //          nsGlobalWindow::CheckOpenAllow() was changed to also
    //          check if the top window's location is whitelisted.
    var uri = gBrowser.currentURI;
    var blockedPopupAllowSite = document.getElementById("blockedPopupAllowSite");
    try {
      blockedPopupAllowSite.removeAttribute("hidden");

      var pm = Services.perms;
      if (pm.testPermission(uri, "popup") == pm.ALLOW_ACTION) {
        // Offer an item to block popups for this site, if a whitelist entry exists
        // already for it.
        let blockString = gNavigatorBundle.getFormattedString("popupBlock", [uri.host || uri.spec]);
        blockedPopupAllowSite.setAttribute("label", blockString);
        blockedPopupAllowSite.setAttribute("block", "true");
      }
      else {
        // Offer an item to allow popups for this site
        let allowString = gNavigatorBundle.getFormattedString("popupAllow", [uri.host || uri.spec]);
        blockedPopupAllowSite.setAttribute("label", allowString);
        blockedPopupAllowSite.removeAttribute("block");
      }
    }
    catch (e) {
      blockedPopupAllowSite.setAttribute("hidden", "true");
    }

    if (PrivateBrowsingUtils.isWindowPrivate(window))
      blockedPopupAllowSite.setAttribute("disabled", "true");
    else
      blockedPopupAllowSite.removeAttribute("disabled");

    var foundUsablePopupURI = false;
    var pageReports = gBrowser.pageReport;
    if (pageReports) {
      for (let pageReport of pageReports) {
        // popupWindowURI will be null if the file picker popup is blocked.
        // xxxdz this should make the option say "Show file picker" and do it (Bug 590306)
        if (!pageReport.popupWindowURI)
          continue;
        var popupURIspec = pageReport.popupWindowURI.spec;

        // Sometimes the popup URI that we get back from the pageReport
        // isn't useful (for instance, netscape.com's popup URI ends up
        // being "http://www.netscape.com", which isn't really the URI of
        // the popup they're trying to show).  This isn't going to be
        // useful to the user, so we won't create a menu item for it.
        if (popupURIspec == "" || popupURIspec == "about:blank" ||
            popupURIspec == uri.spec)
          continue;

        // Because of the short-circuit above, we may end up in a situation
        // in which we don't have any usable popup addresses to show in
        // the menu, and therefore we shouldn't show the separator.  However,
        // since we got past the short-circuit, we must've found at least
        // one usable popup URI and thus we'll turn on the separator later.
        foundUsablePopupURI = true;

        var menuitem = document.createElement("menuitem");
        var label = gNavigatorBundle.getFormattedString("popupShowPopupPrefix",
                                                        [popupURIspec]);
        menuitem.setAttribute("label", label);
        menuitem.setAttribute("popupWindowURI", popupURIspec);
        menuitem.setAttribute("popupWindowFeatures", pageReport.popupWindowFeatures);
        menuitem.setAttribute("popupWindowName", pageReport.popupWindowName);
        menuitem.setAttribute("oncommand", "gPopupBlockerObserver.showBlockedPopup(event);");
        menuitem.requestingWindow = pageReport.requestingWindow;
        menuitem.requestingDocument = pageReport.requestingDocument;
        aEvent.target.appendChild(menuitem);
      }
    }

    // Show or hide the separator, depending on whether we added any
    // showable popup addresses to the menu.
    var blockedPopupsSeparator =
      document.getElementById("blockedPopupsSeparator");
    if (foundUsablePopupURI)
      blockedPopupsSeparator.removeAttribute("hidden");
    else
      blockedPopupsSeparator.setAttribute("hidden", true);

    var blockedPopupDontShowMessage = document.getElementById("blockedPopupDontShowMessage");
    var showMessage = gPrefService.getBoolPref("privacy.popups.showBrowserMessage");
    blockedPopupDontShowMessage.setAttribute("checked", !showMessage);
    if (aEvent.target.anchorNode.id == "page-report-button") {
      aEvent.target.anchorNode.setAttribute("open", "true");
      blockedPopupDontShowMessage.setAttribute("label", gNavigatorBundle.getString("popupWarningDontShowFromLocationbar"));
    } else
      blockedPopupDontShowMessage.setAttribute("label", gNavigatorBundle.getString("popupWarningDontShowFromMessage"));
  },

  onPopupHiding: function (aEvent) {
    if (aEvent.target.anchorNode.id == "page-report-button")
      aEvent.target.anchorNode.removeAttribute("open");

    let item = aEvent.target.lastChild;
    while (item && item.getAttribute("observes") != "blockedPopupsSeparator") {
      let next = item.previousSibling;
      item.parentNode.removeChild(item);
      item = next;
    }
  },

  showBlockedPopup: function (aEvent)
  {
    var target = aEvent.target;
    var popupWindowURI = target.getAttribute("popupWindowURI");
    var features = target.getAttribute("popupWindowFeatures");
    var name = target.getAttribute("popupWindowName");

    var dwi = target.requestingWindow;

    // If we have a requesting window and the requesting document is
    // still the current document, open the popup.
    if (dwi && dwi.document == target.requestingDocument) {
      dwi.open(popupWindowURI, name, features);
    }
  },

  editPopupSettings: function ()
  {
    var host = "";
    try {
      host = gBrowser.currentURI.host;
    }
    catch (e) { }

    var bundlePreferences = document.getElementById("bundle_preferences");
    var params = { blockVisible   : false,
                   sessionVisible : false,
                   allowVisible   : true,
                   prefilledHost  : host,
                   permissionType : "popup",
                   windowTitle    : bundlePreferences.getString("popuppermissionstitle"),
                   introText      : bundlePreferences.getString("popuppermissionstext") };
    var existingWindow = Services.wm.getMostRecentWindow("Browser:Permissions");
    if (existingWindow) {
      existingWindow.initWithParams(params);
      existingWindow.focus();
    }
    else
      window.openDialog("chrome://browser/content/preferences/permissions.xul",
                        "_blank", "resizable,dialog=no,centerscreen", params);
  },

  dontShowMessage: function ()
  {
    var showMessage = gPrefService.getBoolPref("privacy.popups.showBrowserMessage");
    gPrefService.setBoolPref("privacy.popups.showBrowserMessage", !showMessage);
    gBrowser.getNotificationBox().removeCurrentNotification();
  }
};

const gFormSubmitObserver = {
  QueryInterface : XPCOMUtils.generateQI([Ci.nsIFormSubmitObserver]),

  panel: null,

  init: function()
  {
    this.panel = document.getElementById('invalid-form-popup');
  },

  notifyInvalidSubmit : function (aFormElement, aInvalidElements)
  {
    // We are going to handle invalid form submission attempt by focusing the
    // first invalid element and show the corresponding validation message in a
    // panel attached to the element.
    if (!aInvalidElements.length) {
      return;
    }

    // Don't show the popup if the current tab doesn't contain the invalid form.
    if (gBrowser.contentDocument !=
        aFormElement.ownerDocument.defaultView.top.document) {
      return;
    }

    let element = aInvalidElements.queryElementAt(0, Ci.nsISupports);

    if (!(element instanceof HTMLInputElement ||
          element instanceof HTMLTextAreaElement ||
          element instanceof HTMLSelectElement ||
          element instanceof HTMLButtonElement)) {
      return;
    }

    this.panel.firstChild.textContent = element.validationMessage;

    element.focus();

    // If the user interacts with the element and makes it valid or leaves it,
    // we want to remove the popup.
    // We could check for clicks but a click is already removing the popup.
    function blurHandler() {
      gFormSubmitObserver.panel.hidePopup();
    };
    function inputHandler(e) {
      if (e.originalTarget.validity.valid) {
        gFormSubmitObserver.panel.hidePopup();
      } else {
        // If the element is now invalid for a new reason, we should update the
        // error message.
        if (gFormSubmitObserver.panel.firstChild.textContent !=
            e.originalTarget.validationMessage) {
          gFormSubmitObserver.panel.firstChild.textContent =
            e.originalTarget.validationMessage;
        }
      }
    };
    element.addEventListener("input", inputHandler, false);
    element.addEventListener("blur", blurHandler, false);

    // One event to bring them all and in the darkness bind them.
    this.panel.addEventListener("popuphiding", function onPopupHiding(aEvent) {
      aEvent.target.removeEventListener("popuphiding", onPopupHiding, false);
      element.removeEventListener("input", inputHandler, false);
      element.removeEventListener("blur", blurHandler, false);
    }, false);

    this.panel.hidden = false;

    // We want to show the popup at the middle of checkbox and radio buttons
    // and where the content begin for the other elements.
    let offset = 0;
    let position = "";

    if (element.tagName == 'INPUT' &&
        (element.type == 'radio' || element.type == 'checkbox')) {
      position = "bottomcenter topleft";
    } else {
      let win = element.ownerDocument.defaultView;
      let style = win.getComputedStyle(element, null);
      let utils = win.QueryInterface(Components.interfaces.nsIInterfaceRequestor)
                     .getInterface(Components.interfaces.nsIDOMWindowUtils);

      if (style.direction == 'rtl') {
        offset = parseInt(style.paddingRight) + parseInt(style.borderRightWidth);
      } else {
        offset = parseInt(style.paddingLeft) + parseInt(style.borderLeftWidth);
      }

      offset = Math.round(offset * utils.fullZoom);

      position = "after_start";
    }

    this.panel.openPopup(element, position, offset, 0);
  }
};

// Simple gestures support
//
// As per bug #412486, web content must not be allowed to receive any
// simple gesture events.  Multi-touch gesture APIs are in their
// infancy and we do NOT want to be forced into supporting an API that
// will probably have to change in the future.  (The current Mac OS X
// API is undocumented and was reverse-engineered.)  Until support is
// implemented in the event dispatcher to keep these events as
// chrome-only, we must listen for the simple gesture events during
// the capturing phase and call stopPropagation on every event.

let gGestureSupport = {
  /**
   * Add or remove mouse gesture event listeners
   *
   * @param aAddListener
   *        True to add/init listeners and false to remove/uninit
   */
  init: function GS_init(aAddListener) {
    const gestureEvents = ["SwipeGesture",
      "MagnifyGestureStart", "MagnifyGestureUpdate", "MagnifyGesture",
      "RotateGestureStart", "RotateGestureUpdate", "RotateGesture",
      "TapGesture", "PressTapGesture"];

    let addRemove = aAddListener ? window.addEventListener :
      window.removeEventListener;

    gestureEvents.forEach(function (event) addRemove("Moz" + event, this, true),
                          this);
  },

  /**
   * Dispatch events based on the type of mouse gesture event. For now, make
   * sure to stop propagation of every gesture event so that web content cannot
   * receive gesture events.
   *
   * @param aEvent
   *        The gesture event to handle
   */
  handleEvent: function GS_handleEvent(aEvent) {
    aEvent.stopPropagation();

    // Create a preference object with some defaults
    let def = function(aThreshold, aLatched)
      ({ threshold: aThreshold, latched: !!aLatched });

    switch (aEvent.type) {
      case "MozSwipeGesture":
        aEvent.preventDefault();
        this.onSwipe(aEvent);
        break;
      case "MozMagnifyGestureStart":
        aEvent.preventDefault();
//@line 786 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        this._setupGesture(aEvent, "pinch", def(150, 1), "out", "in");
//@line 788 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        break;
      case "MozRotateGestureStart":
        aEvent.preventDefault();
        this._setupGesture(aEvent, "twist", def(25, 0), "right", "left");
        break;
      case "MozMagnifyGestureUpdate":
      case "MozRotateGestureUpdate":
        aEvent.preventDefault();
        this._doUpdate(aEvent);
        break;
      case "MozTapGesture":
        aEvent.preventDefault();
        this._doAction(aEvent, ["tap"]);
        break;
      /* case "MozPressTapGesture":
        break; */
    }
  },

  /**
   * Called at the start of "pinch" and "twist" gestures to setup all of the
   * information needed to process the gesture
   *
   * @param aEvent
   *        The continual motion start event to handle
   * @param aGesture
   *        Name of the gesture to handle
   * @param aPref
   *        Preference object with the names of preferences and defaults
   * @param aInc
   *        Command to trigger for increasing motion (without gesture name)
   * @param aDec
   *        Command to trigger for decreasing motion (without gesture name)
   */
  _setupGesture: function GS__setupGesture(aEvent, aGesture, aPref, aInc, aDec) {
    // Try to load user-set values from preferences
    for (let [pref, def] in Iterator(aPref))
      aPref[pref] = this._getPref(aGesture + "." + pref, def);

    // Keep track of the total deltas and latching behavior
    let offset = 0;
    let latchDir = aEvent.delta > 0 ? 1 : -1;
    let isLatched = false;

    // Create the update function here to capture closure state
    this._doUpdate = function GS__doUpdate(aEvent) {
      // Update the offset with new event data
      offset += aEvent.delta;

      // Check if the cumulative deltas exceed the threshold
      if (Math.abs(offset) > aPref["threshold"]) {
        // Trigger the action if we don't care about latching; otherwise, make
        // sure either we're not latched and going the same direction of the
        // initial motion; or we're latched and going the opposite way
        let sameDir = (latchDir ^ offset) >= 0;
        if (!aPref["latched"] || (isLatched ^ sameDir)) {
          this._doAction(aEvent, [aGesture, offset > 0 ? aInc : aDec]);

          // We must be getting latched or leaving it, so just toggle
          isLatched = !isLatched;
        }

        // Reset motion counter to prepare for more of the same gesture
        offset = 0;
      }
    };

    // The start event also contains deltas, so handle an update right away
    this._doUpdate(aEvent);
  },

  /**
   * Generator producing the powerset of the input array where the first result
   * is the complete set and the last result (before StopIteration) is empty.
   *
   * @param aArray
   *        Source array containing any number of elements
   * @yield Array that is a subset of the input array from full set to empty
   */
  _power: function GS__power(aArray) {
    // Create a bitmask based on the length of the array
    let num = 1 << aArray.length;
    while (--num >= 0) {
      // Only select array elements where the current bit is set
      yield aArray.reduce(function (aPrev, aCurr, aIndex) {
        if (num & 1 << aIndex)
          aPrev.push(aCurr);
        return aPrev;
      }, []);
    }
  },

  /**
   * Determine what action to do for the gesture based on which keys are
   * pressed and which commands are set
   *
   * @param aEvent
   *        The original gesture event to convert into a fake click event
   * @param aGesture
   *        Array of gesture name parts (to be joined by periods)
   */
  _doAction: function GS__doAction(aEvent, aGesture) {
    // Create an array of pressed keys in a fixed order so that a command for
    // "meta" is preferred over "ctrl" when both buttons are pressed (and a
    // command for both don't exist)
    let keyCombos = [];
    ["shift", "alt", "ctrl", "meta"].forEach(function (key) {
      if (aEvent[key + "Key"])
        keyCombos.push(key);
    });

    // Try each combination of key presses in decreasing order for commands
    for (let subCombo of this._power(keyCombos)) {
      // Convert a gesture and pressed keys into the corresponding command
      // action where the preference has the gesture before "shift" before
      // "alt" before "ctrl" before "meta" all separated by periods
      let command;
      try {
        command = this._getPref(aGesture.concat(subCombo).join("."));
      } catch (e) {}

      if (!command)
        continue;

      let node = document.getElementById(command);
      if (node) {
        if (node.getAttribute("disabled") != "true") {
          let cmdEvent = document.createEvent("xulcommandevent");
          cmdEvent.initCommandEvent("command", true, true, window, 0,
                                    aEvent.ctrlKey, aEvent.altKey, aEvent.shiftKey,
                                    aEvent.metaKey, null);
          node.dispatchEvent(cmdEvent);
        }
      } else {
        goDoCommand(command);
      }

      break;
    }
  },

  /**
   * Convert continual motion events into an action if it exceeds a threshold
   * in a given direction. This function will be set by _setupGesture to
   * capture state that needs to be shared across multiple gesture updates.
   *
   * @param aEvent
   *        The continual motion update event to handle
   */
  _doUpdate: function(aEvent) {},

  /**
   * Convert the swipe gesture into a browser action based on the direction
   *
   * @param aEvent
   *        The swipe event to handle
   */
  onSwipe: function GS_onSwipe(aEvent) {
    // Figure out which one (and only one) direction was triggered
    for (let dir of ["UP", "RIGHT", "DOWN", "LEFT"]) {
      if (aEvent.direction == aEvent["DIRECTION_" + dir]) {
        this._doAction(aEvent, ["swipe", dir.toLowerCase()]);
        break;
      }
    }
  },

  /**
   * Get a gesture preference or use a default if it doesn't exist
   *
   * @param aPref
   *        Name of the preference to load under the gesture branch
   * @param aDef
   *        Default value if the preference doesn't exist
   */
  _getPref: function GS__getPref(aPref, aDef) {
    // Preferences branch under which all gestures preferences are stored
    const branch = "browser.gesture.";

    try {
      // Determine what type of data to load based on default value's type
      let type = typeof aDef;
      let getFunc = "get" + (type == "boolean" ? "Bool" :
                             type == "number" ? "Int" : "Char") + "Pref";
      return gPrefService[getFunc](branch + aPref);
    }
    catch (e) {
      return aDef;
    }
  },
};

var gBrowserInit = {
  onLoad: function() {
    // window.arguments[0]: URI to load (string), or an nsISupportsArray of
    //                      nsISupportsStrings to load, or a xul:tab of
    //                      a tabbrowser, which will be replaced by this
    //                      window (for this case, all other arguments are
    //                      ignored).
    //                 [1]: character set (string)
    //                 [2]: referrer (nsIURI)
    //                 [3]: postData (nsIInputStream)
    //                 [4]: allowThirdPartyFixup (bool)
    if ("arguments" in window && window.arguments[0])
      var uriToLoad = window.arguments[0];

    var mustLoadSidebar = false;

    gBrowser.addEventListener("DOMUpdatePageReport", gPopupBlockerObserver, false);

    // Note that the XBL binding is untrusted
    gBrowser.addEventListener("PluginBindingAttached", gPluginHandler, true, true);
    gBrowser.addEventListener("PluginScripted",        gPluginHandler, true);
    gBrowser.addEventListener("PluginCrashed",         gPluginHandler, true);
    gBrowser.addEventListener("PluginOutdated",        gPluginHandler, true);

    gBrowser.addEventListener("NewPluginInstalled", gPluginHandler.newPluginInstalled, true);
//@line 1008 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    Services.obs.addObserver(gPluginHandler.pluginCrashed, "plugin-crashed", false);

    window.addEventListener("AppCommand", HandleAppCommandEvent, true);

    messageManager.loadFrameScript("chrome://browser/content/content.js", true);

    // initialize observers and listeners
    // and give C++ access to gBrowser
    gBrowser.init();
    XULBrowserWindow.init();
    window.QueryInterface(Ci.nsIInterfaceRequestor)
          .getInterface(nsIWebNavigation)
          .QueryInterface(Ci.nsIDocShellTreeItem).treeOwner
          .QueryInterface(Ci.nsIInterfaceRequestor)
          .getInterface(Ci.nsIXULWindow)
          .XULBrowserWindow = window.XULBrowserWindow;
    window.QueryInterface(Ci.nsIDOMChromeWindow).browserDOMWindow =
      new nsBrowserAccess();

    // set default character set if provided
    if ("arguments" in window && window.arguments.length > 1 && window.arguments[1]) {
      if (window.arguments[1].startsWith("charset=")) {
        var arrayArgComponents = window.arguments[1].split("=");
        if (arrayArgComponents) {
          //we should "inherit" the charset menu setting in a new window
          getMarkupDocumentViewer().defaultCharacterSet = arrayArgComponents[1];
        }
      }
    }

    // Manually hook up session and global history for the first browser
    // so that we don't have to load global history before bringing up a
    // window.
    // Wire up session and global history before any possible
    // progress notifications for back/forward button updating
    gBrowser.webNavigation.sessionHistory = Cc["@mozilla.org/browser/shistory;1"].
                                            createInstance(Ci.nsISHistory);
    Services.obs.addObserver(gBrowser.browsers[0], "browser:purge-session-history", false);

    // remove the disablehistory attribute so the browser cleans up, as
    // though it had done this work itself
    gBrowser.browsers[0].removeAttribute("disablehistory");

    // enable global history
    try {
      gBrowser.docShell.QueryInterface(Ci.nsIDocShellHistory).useGlobalHistory = true;
    } catch(ex) {
      Cu.reportError("Places database may be locked: " + ex);
    }

//@line 1062 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    // hook up UI through progress listener
    gBrowser.addProgressListener(window.XULBrowserWindow);
    gBrowser.addTabsProgressListener(window.TabsProgressListener);
//@line 1066 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    // setup our common DOMLinkAdded listener
    gBrowser.addEventListener("DOMLinkAdded", DOMLinkHandler, false);

    // setup our MozApplicationManifest listener
    gBrowser.addEventListener("MozApplicationManifest",
                              OfflineApps, false);

    // setup simple gestures support
    gGestureSupport.init(true);

    if (window.opener && !window.opener.closed) {
      let openerSidebarBox = window.opener.document.getElementById("sidebar-box");
      // If the opener had a sidebar, open the same sidebar in our window.
      // The opener can be the hidden window too, if we're coming from the state
      // where no windows are open, and the hidden window has no sidebar box.
      if (openerSidebarBox && !openerSidebarBox.hidden) {
        let sidebarCmd = openerSidebarBox.getAttribute("sidebarcommand");
        let sidebarCmdElem = document.getElementById(sidebarCmd);

        // dynamically generated sidebars will fail this check.
        if (sidebarCmdElem) {
          let sidebarBox = document.getElementById("sidebar-box");
          let sidebarTitle = document.getElementById("sidebar-title");

          sidebarTitle.setAttribute(
            "value", window.opener.document.getElementById("sidebar-title").getAttribute("value"));
          sidebarBox.setAttribute("width", openerSidebarBox.boxObject.width);

          sidebarBox.setAttribute("sidebarcommand", sidebarCmd);
          // Note: we're setting 'src' on sidebarBox, which is a <vbox>, not on
          // the <browser id="sidebar">. This lets us delay the actual load until
          // delayedStartup().
          sidebarBox.setAttribute(
            "src", window.opener.document.getElementById("sidebar").getAttribute("src"));
          mustLoadSidebar = true;

          sidebarBox.hidden = false;
          document.getElementById("sidebar-splitter").hidden = false;
          sidebarCmdElem.setAttribute("checked", "true");
        }
      }
    }
    else {
      let box = document.getElementById("sidebar-box");
      if (box.hasAttribute("sidebarcommand")) {
        let commandID = box.getAttribute("sidebarcommand");
        if (commandID) {
          let command = document.getElementById(commandID);
          if (command) {
            mustLoadSidebar = true;
            box.hidden = false;
            document.getElementById("sidebar-splitter").hidden = false;
            command.setAttribute("checked", "true");
          }
          else {
            // Remove the |sidebarcommand| attribute, because the element it
            // refers to no longer exists, so we should assume this sidebar
            // panel has been uninstalled. (249883)
            box.removeAttribute("sidebarcommand");
          }
        }
      }
    }

    // Certain kinds of automigration rely on this notification to complete their
    // tasks BEFORE the browser window is shown.
    Services.obs.notifyObservers(null, "browser-window-before-show", "");

    // Set a sane starting width/height for all resolutions on new profiles.
    if (!document.documentElement.hasAttribute("width")) {
      let defaultWidth = 994;
      let defaultHeight;
      if (screen.availHeight <= 600) {
        document.documentElement.setAttribute("sizemode", "maximized");
        defaultWidth = 610;
        defaultHeight = 450;
      }
      else {
        // Create a narrower window for large or wide-aspect displays, to suggest
        // side-by-side page view.
        if (screen.availWidth >= 1600)
          defaultWidth = (screen.availWidth / 2) - 20;
        defaultHeight = screen.availHeight - 10;
//@line 1151 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        // On X, we're not currently able to account for the size of the window
        // border.  Use 28px as a guess (titlebar + bottom window border)
        defaultHeight -= 28;
//@line 1155 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
      }
      document.documentElement.setAttribute("width", defaultWidth);
      document.documentElement.setAttribute("height", defaultHeight);
    }

    if (!gShowPageResizers)
      document.getElementById("status-bar").setAttribute("hideresizer", "true");

    if (!window.toolbar.visible) {
      // adjust browser UI for popups
      if (gURLBar) {
        gURLBar.setAttribute("readonly", "true");
        gURLBar.setAttribute("enablehistory", "false");
      }
      goSetCommandEnabled("cmd_newNavigatorTab", false);
    }

//@line 1173 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    updateAppButtonDisplay();
//@line 1175 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    // Misc. inits.
    CombinedStopReload.init();
    allTabs.readPref();
    TabsOnTop.init();
    BookmarksMenuButton.init();
    gPrivateBrowsingUI.init();
    TabsInTitlebar.init();
    retrieveToolbarIconsizesFromTheme();

    // Wait until chrome is painted before executing code not critical to making the window visible
    this._boundDelayedStartup = this._delayedStartup.bind(this, uriToLoad, mustLoadSidebar);
    window.addEventListener("MozAfterPaint", this._boundDelayedStartup);

    this._loadHandled = true;
  },

  _cancelDelayedStartup: function () {
    window.removeEventListener("MozAfterPaint", this._boundDelayedStartup);
    this._boundDelayedStartup = null;
  },

  _delayedStartup: function(uriToLoad, mustLoadSidebar) {
    let tmp = {};
    Cu.import("resource:///modules/TelemetryTimestamps.jsm", tmp);
    let TelemetryTimestamps = tmp.TelemetryTimestamps;
    TelemetryTimestamps.add("delayedStartupStarted");

    this._cancelDelayedStartup();

    var isLoadingBlank = isBlankPageURL(uriToLoad);

    if (uriToLoad && uriToLoad != "about:blank") {
      if (uriToLoad instanceof Ci.nsISupportsArray) {
        let count = uriToLoad.Count();
        let specs = [];
        for (let i = 0; i < count; i++) {
          let urisstring = uriToLoad.GetElementAt(i).QueryInterface(Ci.nsISupportsString);
          specs.push(urisstring.data);
        }

        // This function throws for certain malformed URIs, so use exception handling
        // so that we don't disrupt startup
        try {
          gBrowser.loadTabs(specs, false, true);
        } catch (e) {}
      }
      else if (uriToLoad instanceof XULElement) {
        // swap the given tab with the default about:blank tab and then close
        // the original tab in the other window.

        // Stop the about:blank load
        gBrowser.stop();
        // make sure it has a docshell
        gBrowser.docShell;

        gBrowser.swapBrowsersAndCloseOther(gBrowser.selectedTab, uriToLoad);
      }
      else if (window.arguments.length >= 3) {
        loadURI(uriToLoad, window.arguments[2], window.arguments[3] || null,
                window.arguments[4] || false);
        window.focus();
      }
      // Note: loadOneOrMoreURIs *must not* be called if window.arguments.length >= 3.
      // Such callers expect that window.arguments[0] is handled as a single URI.
      else
        loadOneOrMoreURIs(uriToLoad);
    }

//@line 1245 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    // Bug 778855 - Perf regression if we do this here. To be addressed in bug 779008.
    setTimeout(function() { SafeBrowsing.init(); }, 2000);
//@line 1248 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    Services.obs.addObserver(gSessionHistoryObserver, "browser:purge-session-history", false);
    Services.obs.addObserver(gXPInstallObserver, "addon-install-disabled", false);
    Services.obs.addObserver(gXPInstallObserver, "addon-install-started", false);
    Services.obs.addObserver(gXPInstallObserver, "addon-install-blocked", false);
    Services.obs.addObserver(gXPInstallObserver, "addon-install-failed", false);
    Services.obs.addObserver(gXPInstallObserver, "addon-install-complete", false);
    Services.obs.addObserver(gFormSubmitObserver, "invalidformsubmit", false);

    BrowserOffline.init();
    OfflineApps.init();
    IndexedDBPromptHelper.init();
    gFormSubmitObserver.init();
    SocialUI.init();
    AddonManager.addAddonListener(AddonsMgrListener);
    WebrtcIndicator.init();

    gBrowser.addEventListener("pageshow", function(event) {
      // Filter out events that are not about the document load we are interested in
      if (event.target == content.document)
        setTimeout(pageShowEventHandlers, 0, event);
    }, true);

    // Ensure login manager is up and running.
    Services.logins;

    if (mustLoadSidebar) {
      let sidebar = document.getElementById("sidebar");
      let sidebarBox = document.getElementById("sidebar-box");
      sidebar.setAttribute("src", sidebarBox.getAttribute("src"));
    }

    UpdateUrlbarSearchSplitterState();

    if (!isLoadingBlank || !focusAndSelectUrlBar())
      gBrowser.selectedBrowser.focus();

    gNavToolbox.customizeDone = BrowserToolboxCustomizeDone;
    gNavToolbox.customizeChange = BrowserToolboxCustomizeChange;

    // Set up Sanitize Item
    this._initializeSanitizer();

    // Enable/Disable auto-hide tabbar
    gBrowser.tabContainer.updateVisibility();

    gPrefService.addObserver(gHomeButton.prefDomain, gHomeButton, false);

    var homeButton = document.getElementById("home-button");
    gHomeButton.updateTooltip(homeButton);
    gHomeButton.updatePersonalToolbarStyle(homeButton);

    // BiDi UI
    gBidiUI = isBidiEnabled();
    if (gBidiUI) {
      document.getElementById("documentDirection-separator").hidden = false;
      document.getElementById("documentDirection-swap").hidden = false;
      document.getElementById("textfieldDirection-separator").hidden = false;
      document.getElementById("textfieldDirection-swap").hidden = false;
    }

    // Setup click-and-hold gestures access to the session history
    // menus if global click-and-hold isn't turned on
    if (!getBoolPref("ui.click_hold_context_menus", false))
      SetClickAndHoldHandlers();

    // Initialize the full zoom setting.
    // We do this before the session restore service gets initialized so we can
    // apply full zoom settings to tabs restored by the session restore service.
    FullZoom.init();

//@line 1322 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    let NP = {};
    Cu.import("resource:///modules/NetworkPrioritizer.jsm", NP);
    NP.trackBrowserWindow(window);
//@line 1326 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    // initialize the session-restore service (in case it's not already running)
    let ss = Cc["@mozilla.org/browser/sessionstore;1"].getService(Ci.nsISessionStore);
    ss.init(window);

    // Enable the Restore Last Session command if needed
    if (ss.canRestoreLastSession
//@line 1334 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        && !PrivateBrowsingUtils.isWindowPrivate(window)
//@line 1336 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        )
      goSetCommandEnabled("Browser:RestoreLastSession", true);

    PlacesToolbarHelper.init();

    ctrlTab.readPref();
    gPrefService.addObserver(ctrlTab.prefName, ctrlTab, false);
    gPrefService.addObserver(allTabs.prefName, allTabs, false);

    // Initialize the download manager some time after the app starts so that
    // auto-resume downloads begin (such as after crashing or quitting with
    // active downloads) and speeds up the first-load of the download manager UI.
    // If the user manually opens the download manager before the timeout, the
    // downloads will start right away, and getting the service again won't hurt.
    setTimeout(function() {
      Services.downloads;

//@line 1361 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    }, 10000);

    // The object handling the downloads indicator is also initialized here in the
    // delayed startup function, but the actual indicator element is not loaded
    // unless there are downloads to be displayed.
    DownloadsButton.initializeIndicator();

//@line 1369 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    updateEditUIVisibility();
    let placesContext = document.getElementById("placesContext");
    placesContext.addEventListener("popupshowing", updateEditUIVisibility, false);
    placesContext.addEventListener("popuphiding", updateEditUIVisibility, false);
//@line 1374 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    gBrowser.mPanelContainer.addEventListener("InstallBrowserTheme", LightWeightThemeWebInstaller, false, true);
    gBrowser.mPanelContainer.addEventListener("PreviewBrowserTheme", LightWeightThemeWebInstaller, false, true);
    gBrowser.mPanelContainer.addEventListener("ResetBrowserThemePreview", LightWeightThemeWebInstaller, false, true);

//@line 1382 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    if (Win7Features)
      Win7Features.onOpenWindow();
//@line 1385 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

   // called when we go into full screen, even if initiated by a web page script
    window.addEventListener("fullscreen", onFullScreen, true);

    // Called when we enter DOM full-screen mode. Note we can already be in browser
    // full-screen mode when we enter DOM full-screen mode.
    window.addEventListener("MozEnteredDomFullscreen", onMozEnteredDomFullscreen, true);

    if (window.fullScreen)
      onFullScreen();
    if (document.mozFullScreen)
      onMozEnteredDomFullscreen();

//@line 1399 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    // initialize the sync UI
    gSyncUI.init();
//@line 1402 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

//@line 1404 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    gDataNotificationInfoBar.init();
//@line 1406 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    gBrowserThumbnails.init();
    TabView.init();

    setUrlAndSearchBarWidthForConditionalForwardButton();
    window.addEventListener("resize", function resizeHandler(event) {
      if (event.target == window)
        setUrlAndSearchBarWidthForConditionalForwardButton();
    });

    // Enable developer toolbar?
    let devToolbarEnabled = gPrefService.getBoolPref("devtools.toolbar.enabled");
    if (devToolbarEnabled) {
      let cmd = document.getElementById("Tools:DevToolbar");
      cmd.removeAttribute("disabled");
      cmd.removeAttribute("hidden");
      document.getElementById("Tools:DevToolbarFocus").removeAttribute("disabled");

      // Show the toolbar if it was previously visible
      if (gPrefService.getBoolPref("devtools.toolbar.visible")) {
        DeveloperToolbar.show(false);
      }
    }

    // Enable Chrome Debugger?
    let enabled = gPrefService.getBoolPref("devtools.chrome.enabled") &&
                  gPrefService.getBoolPref("devtools.debugger.chrome-enabled") &&
                  gPrefService.getBoolPref("devtools.debugger.remote-enabled");
    if (enabled) {
      let cmd = document.getElementById("Tools:ChromeDebugger");
      cmd.removeAttribute("disabled");
      cmd.removeAttribute("hidden");
    }

    // Enable Error Console?
    // Temporarily enabled. See bug 798925.
    let consoleEnabled = true || gPrefService.getBoolPref("devtools.errorconsole.enabled") ||
                         gPrefService.getBoolPref("devtools.chrome.enabled");
    if (consoleEnabled) {
      let cmd = document.getElementById("Tools:ErrorConsole");
      cmd.removeAttribute("disabled");
      cmd.removeAttribute("hidden");
    }

    // Enable Scratchpad in the UI, if the preference allows this.
    let scratchpadEnabled = gPrefService.getBoolPref(Scratchpad.prefEnabledName);
    if (scratchpadEnabled) {
      let cmd = document.getElementById("Tools:Scratchpad");
      cmd.removeAttribute("disabled");
      cmd.removeAttribute("hidden");
    }

    // Enable DevTools connection screen, if the preference allows this.
    let devtoolsRemoteEnabled = gPrefService.getBoolPref("devtools.debugger.remote-enabled");
    if (devtoolsRemoteEnabled) {
      let cmd = document.getElementById("Tools:DevToolsConnect");
      cmd.removeAttribute("disabled");
      cmd.removeAttribute("hidden");
    }

//@line 1467 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    // If the user (or the locale) hasn't enabled the top-level "Character
    // Encoding" menu via the "browser.menu.showCharacterEncoding" preference,
    // hide it.
    if ("true" != gPrefService.getComplexValue("browser.menu.showCharacterEncoding",
                                               Ci.nsIPrefLocalizedString).data)
      document.getElementById("appmenu_charsetMenu").hidden = true;
//@line 1474 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    // Enable Responsive UI?
    let responsiveUIEnabled = gPrefService.getBoolPref("devtools.responsiveUI.enabled");
    if (responsiveUIEnabled) {
      let cmd = document.getElementById("Tools:ResponsiveUI");
      cmd.removeAttribute("disabled");
      cmd.removeAttribute("hidden");
    }

    // Add Devtools menuitems and listeners
    gDevToolsBrowser.registerBrowserWindow(window);

    let appMenuButton = document.getElementById("appmenu-button");
    let appMenuPopup = document.getElementById("appmenu-popup");
    if (appMenuButton && appMenuPopup) {
      let appMenuOpening = null;
      appMenuButton.addEventListener("mousedown", function(event) {
        if (event.button == 0)
          appMenuOpening = new Date();
      }, false);
      appMenuPopup.addEventListener("popupshown", function(event) {
        if (event.target != appMenuPopup || !appMenuOpening)
          return;
        let duration = new Date() - appMenuOpening;
        appMenuOpening = null;
        Services.telemetry.getHistogramById("FX_APP_MENU_OPEN_MS").add(duration);
      }, false);
    }

    window.addEventListener("mousemove", MousePosTracker, false);
    window.addEventListener("dragover", MousePosTracker, false);

    // End startup crash tracking after a delay to catch crashes while restoring
    // tabs and to postpone saving the pref to disk.
    try {
      const startupCrashEndDelay = 30 * 1000;
      setTimeout(Services.startup.trackStartupCrashEnd, startupCrashEndDelay);
    } catch (ex) {
      Cu.reportError("Could not end startup crash tracking: " + ex);
    }

    Services.obs.notifyObservers(window, "browser-delayed-startup-finished", "");
    TelemetryTimestamps.add("delayedStartupFinished");
  },

  onUnload: function() {
    // In certain scenarios it's possible for unload to be fired before onload,
    // (e.g. if the window is being closed after browser.js loads but before the
    // load completes). In that case, there's nothing to do here.
    if (!this._loadHandled)
      return;

    gDevToolsBrowser.forgetBrowserWindow(window);

    let desc = Object.getOwnPropertyDescriptor(window, "DeveloperToolbar");
    if (desc && !desc.get) {
      DeveloperToolbar.destroy();
    }

    // First clean up services initialized in gBrowserInit.onLoad (or those whose
    // uninit methods don't depend on the services having been initialized).
    allTabs.uninit();

    CombinedStopReload.uninit();

    gGestureSupport.init(false);

    FullScreen.cleanup();

    Services.obs.removeObserver(gPluginHandler.pluginCrashed, "plugin-crashed");

    try {
      gBrowser.removeProgressListener(window.XULBrowserWindow);
      gBrowser.removeTabsProgressListener(window.TabsProgressListener);
    } catch (ex) {
    }

    PlacesStarButton.uninit();

//@line 1556 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    TabsOnTop.uninit();

    TabsInTitlebar.uninit();

    var enumerator = Services.wm.getEnumerator(null);
    enumerator.getNext();
    if (!enumerator.hasMoreElements()) {
      document.persist("sidebar-box", "sidebarcommand");
      document.persist("sidebar-box", "width");
      document.persist("sidebar-box", "src");
      document.persist("sidebar-title", "value");
    }

    // Now either cancel delayedStartup, or clean up the services initialized from
    // it.
    if (this._boundDelayedStartup) {
      this._cancelDelayedStartup();
    } else {
      if (Win7Features)
        Win7Features.onCloseWindow();

      gPrefService.removeObserver(ctrlTab.prefName, ctrlTab);
      gPrefService.removeObserver(allTabs.prefName, allTabs);
      ctrlTab.uninit();
      TabView.uninit();
      gBrowserThumbnails.uninit();
      FullZoom.destroy();

      Services.obs.removeObserver(gSessionHistoryObserver, "browser:purge-session-history");
      Services.obs.removeObserver(gXPInstallObserver, "addon-install-disabled");
      Services.obs.removeObserver(gXPInstallObserver, "addon-install-started");
      Services.obs.removeObserver(gXPInstallObserver, "addon-install-blocked");
      Services.obs.removeObserver(gXPInstallObserver, "addon-install-failed");
      Services.obs.removeObserver(gXPInstallObserver, "addon-install-complete");
      Services.obs.removeObserver(gFormSubmitObserver, "invalidformsubmit");

      try {
        gPrefService.removeObserver(gHomeButton.prefDomain, gHomeButton);
      } catch (ex) {
        Cu.reportError(ex);
      }

      BrowserOffline.uninit();
      OfflineApps.uninit();
      IndexedDBPromptHelper.uninit();
      AddonManager.removeAddonListener(AddonsMgrListener);
      SocialUI.uninit();
    }

    // Final window teardown, do this last.
    window.XULBrowserWindow.destroy();
    window.XULBrowserWindow = null;
    window.QueryInterface(Ci.nsIInterfaceRequestor)
          .getInterface(Ci.nsIWebNavigation)
          .QueryInterface(Ci.nsIDocShellTreeItem).treeOwner
          .QueryInterface(Ci.nsIInterfaceRequestor)
          .getInterface(Ci.nsIXULWindow)
          .XULBrowserWindow = null;
    window.QueryInterface(Ci.nsIDOMChromeWindow).browserDOMWindow = null;
  },

//@line 1708 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

  _initializeSanitizer: function() {
    const kDidSanitizeDomain = "privacy.sanitize.didShutdownSanitize";
    if (gPrefService.prefHasUserValue(kDidSanitizeDomain)) {
      gPrefService.clearUserPref(kDidSanitizeDomain);
      // We need to persist this preference change, since we want to
      // check it at next app start even if the browser exits abruptly
      gPrefService.savePrefFile(null);
    }

    /**
     * Migrate Firefox 3.0 privacy.item prefs under one of these conditions:
     *
     * a) User has customized any privacy.item prefs
     * b) privacy.sanitize.sanitizeOnShutdown is set
     */
    if (!gPrefService.getBoolPref("privacy.sanitize.migrateFx3Prefs")) {
      let itemBranch = gPrefService.getBranch("privacy.item.");
      let itemArray = itemBranch.getChildList("");

      // See if any privacy.item prefs are set
      let doMigrate = itemArray.some(function (name) itemBranch.prefHasUserValue(name));
      // Or if sanitizeOnShutdown is set
      if (!doMigrate)
        doMigrate = gPrefService.getBoolPref("privacy.sanitize.sanitizeOnShutdown");

      if (doMigrate) {
        let cpdBranch = gPrefService.getBranch("privacy.cpd.");
        let clearOnShutdownBranch = gPrefService.getBranch("privacy.clearOnShutdown.");
        for (let name of itemArray) {
          try {
            // don't migrate password or offlineApps clearing in the CRH dialog since
            // there's no UI for those anymore. They default to false. bug 497656
            if (name != "passwords" && name != "offlineApps")
              cpdBranch.setBoolPref(name, itemBranch.getBoolPref(name));
            clearOnShutdownBranch.setBoolPref(name, itemBranch.getBoolPref(name));
          }
          catch(e) {
            Cu.reportError("Exception thrown during privacy pref migration: " + e);
          }
        }
      }

      gPrefService.setBoolPref("privacy.sanitize.migrateFx3Prefs", true);
    }
  },
}

/* Legacy global init functions */
var BrowserStartup        = gBrowserInit.onLoad.bind(gBrowserInit);
var BrowserShutdown       = gBrowserInit.onUnload.bind(gBrowserInit);
//@line 1764 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"


function HandleAppCommandEvent(evt) {
  switch (evt.command) {
  case "Back":
    BrowserBack();
    break;
  case "Forward":
    BrowserForward();
    break;
  case "Reload":
    BrowserReloadSkipCache();
    break;
  case "Stop":
    if (XULBrowserWindow.stopCommand.getAttribute("disabled") != "true")
      BrowserStop();
    break;
  case "Search":
    BrowserSearch.webSearch();
    break;
  case "Bookmarks":
    toggleSidebar('viewBookmarksSidebar');
    break;
  case "Home":
    BrowserHome();
    break;
  case "New":
    BrowserOpenTab();
    break;
  case "Close":
    BrowserCloseTabOrWindow();
    break;
  case "Find":
    gFindBar.onFindCommand();
    break;
  case "Help":
    openHelpLink('firefox-help');
    break;
  case "Open":
    BrowserOpenFileWindow();
    break;
  case "Print":
    PrintUtils.print();
    break;
  case "Save":
    saveDocument(window.content.document);
    break;
  case "SendMail":
    MailIntegration.sendLinkForWindow(window.content);
    break;
  default:
    return;
  }
  evt.stopPropagation();
  evt.preventDefault();
}

function gotoHistoryIndex(aEvent) {
  let index = aEvent.target.getAttribute("index");
  if (!index)
    return false;

  let where = whereToOpenLink(aEvent);

  if (where == "current") {
    // Normal click. Go there in the current tab and update session history.

    try {
      gBrowser.gotoIndex(index);
    }
    catch(ex) {
      return false;
    }
    return true;
  }
  // Modified click. Go there in a new tab/window.

  duplicateTabIn(gBrowser.selectedTab, where, index - gBrowser.sessionHistory.index);
  return true;
}

function BrowserForward(aEvent) {
  let where = whereToOpenLink(aEvent, false, true);

  if (where == "current") {
    try {
      gBrowser.goForward();
    }
    catch(ex) {
    }
  }
  else {
    duplicateTabIn(gBrowser.selectedTab, where, 1);
  }
}

function BrowserBack(aEvent) {
  let where = whereToOpenLink(aEvent, false, true);

  if (where == "current") {
    try {
      gBrowser.goBack();
    }
    catch(ex) {
    }
  }
  else {
    duplicateTabIn(gBrowser.selectedTab, where, -1);
  }
}

function BrowserHandleBackspace()
{
  switch (gPrefService.getIntPref("browser.backspace_action")) {
  case 0:
    BrowserBack();
    break;
  case 1:
    goDoCommand("cmd_scrollPageUp");
    break;
  }
}

function BrowserHandleShiftBackspace()
{
  switch (gPrefService.getIntPref("browser.backspace_action")) {
  case 0:
    BrowserForward();
    break;
  case 1:
    goDoCommand("cmd_scrollPageDown");
    break;
  }
}

function BrowserStop() {
  const stopFlags = nsIWebNavigation.STOP_ALL;
  gBrowser.webNavigation.stop(stopFlags);
}

function BrowserReloadOrDuplicate(aEvent) {
  var backgroundTabModifier = aEvent.button == 1 ||
//@line 1909 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    aEvent.ctrlKey;
//@line 1911 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  if (aEvent.shiftKey && !backgroundTabModifier) {
    BrowserReloadSkipCache();
    return;
  }

  let where = whereToOpenLink(aEvent, false, true);
  if (where == "current")
    BrowserReload();
  else
    duplicateTabIn(gBrowser.selectedTab, where);
}

function BrowserReload() {
  const reloadFlags = nsIWebNavigation.LOAD_FLAGS_NONE;
  BrowserReloadWithFlags(reloadFlags);
}

function BrowserReloadSkipCache() {
  // Bypass proxy and cache.
  const reloadFlags = nsIWebNavigation.LOAD_FLAGS_BYPASS_PROXY | nsIWebNavigation.LOAD_FLAGS_BYPASS_CACHE;
  BrowserReloadWithFlags(reloadFlags);
}

var BrowserHome = BrowserGoHome;
function BrowserGoHome(aEvent) {
  if (aEvent && "button" in aEvent &&
      aEvent.button == 2) // right-click: do nothing
    return;

  var homePage = gHomeButton.getHomePage();
  var where = whereToOpenLink(aEvent, false, true);
  var urls;

  // Home page should open in a new tab when current tab is an app tab
  if (where == "current" &&
      gBrowser &&
      gBrowser.selectedTab.pinned)
    where = "tab";

  // openUILinkIn in utilityOverlay.js doesn't handle loading multiple pages
  switch (where) {
  case "current":
    loadOneOrMoreURIs(homePage);
    break;
  case "tabshifted":
  case "tab":
    urls = homePage.split("|");
    var loadInBackground = getBoolPref("browser.tabs.loadBookmarksInBackground", false);
    gBrowser.loadTabs(urls, loadInBackground);
    break;
  case "window":
    OpenBrowserWindow();
    break;
  }
}

function loadOneOrMoreURIs(aURIString)
{
//@line 1977 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  // This function throws for certain malformed URIs, so use exception handling
  // so that we don't disrupt startup
  try {
    gBrowser.loadTabs(aURIString.split("|"), false, true);
  }
  catch (e) {
  }
}

function focusAndSelectUrlBar() {
  if (gURLBar) {
    if (window.fullScreen)
      FullScreen.mouseoverToggle(true);

    gURLBar.select();
    if (document.activeElement == gURLBar.inputField)
      return true;
  }
  return false;
}

function openLocation() {
  if (focusAndSelectUrlBar())
    return;

//@line 2019 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  openDialog("chrome://browser/content/openLocation.xul", "_blank",
             "chrome,modal,titlebar", window);
}

function openLocationCallback()
{
  // make sure the DOM is ready
  setTimeout(function() { this.openLocation(); }, 0);
}

function BrowserOpenTab()
{
  openUILinkIn(BROWSER_NEW_TAB_URL, "tab");
}

/* Called from the openLocation dialog. This allows that dialog to instruct
   its opener to open a new window and then step completely out of the way.
   Anything less byzantine is causing horrible crashes, rather believably,
   though oddly only on Linux. */
function delayedOpenWindow(chrome, flags, href, postData)
{
  // The other way to use setTimeout,
  // setTimeout(openDialog, 10, chrome, "_blank", flags, url),
  // doesn't work here.  The extra "magic" extra argument setTimeout adds to
  // the callback function would confuse gBrowserInit.onLoad() by making
  // window.arguments[1] be an integer instead of null.
  setTimeout(function() { openDialog(chrome, "_blank", flags, href, null, null, postData); }, 10);
}

/* Required because the tab needs time to set up its content viewers and get the load of
   the URI kicked off before becoming the active content area. */
function delayedOpenTab(aUrl, aReferrer, aCharset, aPostData, aAllowThirdPartyFixup)
{
  gBrowser.loadOneTab(aUrl, {
                      referrerURI: aReferrer,
                      charset: aCharset,
                      postData: aPostData,
                      inBackground: false,
                      allowThirdPartyFixup: aAllowThirdPartyFixup});
}

var gLastOpenDirectory = {
  _lastDir: null,
  get path() {
    if (!this._lastDir || !this._lastDir.exists()) {
      try {
        this._lastDir = gPrefService.getComplexValue("browser.open.lastDir",
                                                     Ci.nsILocalFile);
        if (!this._lastDir.exists())
          this._lastDir = null;
      }
      catch(e) {}
    }
    return this._lastDir;
  },
  set path(val) {
    try {
      if (!val || !val.isDirectory())
        return;
    } catch(e) {
      return;
    }
    this._lastDir = val.clone();

    // Don't save the last open directory pref inside the Private Browsing mode
    if (!PrivateBrowsingUtils.isWindowPrivate(window))
      gPrefService.setComplexValue("browser.open.lastDir", Ci.nsILocalFile,
                                   this._lastDir);
  },
  reset: function() {
    this._lastDir = null;
  }
};

function BrowserOpenFileWindow()
{
  // Get filepicker component.
  try {
    const nsIFilePicker = Ci.nsIFilePicker;
    let fp = Cc["@mozilla.org/filepicker;1"].createInstance(nsIFilePicker);
    let fpCallback = function fpCallback_done(aResult) {
      if (aResult == nsIFilePicker.returnOK) {
        try {
          if (fp.file) {
            gLastOpenDirectory.path =
              fp.file.parent.QueryInterface(Ci.nsILocalFile);
          }
        } catch (ex) {
        }
        openUILinkIn(fp.fileURL.spec, "current");
      }
    };

    fp.init(window, gNavigatorBundle.getString("openFile"),
            nsIFilePicker.modeOpen);
    fp.appendFilters(nsIFilePicker.filterAll | nsIFilePicker.filterText |
                     nsIFilePicker.filterImages | nsIFilePicker.filterXML |
                     nsIFilePicker.filterHTML);
    fp.displayDirectory = gLastOpenDirectory.path;
    fp.open(fpCallback);
  } catch (ex) {
  }
}

function BrowserCloseTabOrWindow() {
//@line 2131 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

  // If the current tab is the last one, this will close the window.
  gBrowser.removeCurrentTab({animate: true});
}

function BrowserTryToCloseWindow()
{
  if (WindowIsClosing())
    window.close();     // WindowIsClosing does all the necessary checks
}

function loadURI(uri, referrer, postData, allowThirdPartyFixup) {
  if (postData === undefined)
    postData = null;

  var flags = nsIWebNavigation.LOAD_FLAGS_NONE;
  if (allowThirdPartyFixup)
    flags |= nsIWebNavigation.LOAD_FLAGS_ALLOW_THIRD_PARTY_FIXUP;

  try {
    gBrowser.loadURIWithFlags(uri, flags, referrer, null, postData);
  } catch (e) {}
}

function getShortcutOrURI(aURL, aPostDataRef, aMayInheritPrincipal) {
  // Initialize outparam to false
  if (aMayInheritPrincipal)
    aMayInheritPrincipal.value = false;

  var shortcutURL = null;
  var keyword = aURL;
  var param = "";

  var offset = aURL.indexOf(" ");
  if (offset > 0) {
    keyword = aURL.substr(0, offset);
    param = aURL.substr(offset + 1);
  }

  if (!aPostDataRef)
    aPostDataRef = {};

  var engine = Services.search.getEngineByAlias(keyword);
  if (engine) {
    var submission = engine.getSubmission(param);
    aPostDataRef.value = submission.postData;
    return submission.uri.spec;
  }

  [shortcutURL, aPostDataRef.value] =
    PlacesUtils.getURLAndPostDataForKeyword(keyword);

  if (!shortcutURL)
    return aURL;

  var postData = "";
  if (aPostDataRef.value)
    postData = unescape(aPostDataRef.value);

  if (/%s/i.test(shortcutURL) || /%s/i.test(postData)) {
    var charset = "";
    const re = /^(.*)\&mozcharset=([a-zA-Z][_\-a-zA-Z0-9]+)\s*$/;
    var matches = shortcutURL.match(re);
    if (matches)
      [, shortcutURL, charset] = matches;
    else {
      // Try to get the saved character-set.
      try {
        // makeURI throws if URI is invalid.
        // Will return an empty string if character-set is not found.
        charset = PlacesUtils.history.getCharsetForURI(makeURI(shortcutURL));
      } catch (e) {}
    }

    // encodeURIComponent produces UTF-8, and cannot be used for other charsets.
    // escape() works in those cases, but it doesn't uri-encode +, @, and /.
    // Therefore we need to manually replace these ASCII characters by their
    // encodeURIComponent result, to match the behavior of nsEscape() with
    // url_XPAlphas
    var encodedParam = "";
    if (charset && charset != "UTF-8")
      encodedParam = escape(convertFromUnicode(charset, param)).
                     replace(/[+@\/]+/g, encodeURIComponent);
    else // Default charset is UTF-8
      encodedParam = encodeURIComponent(param);

    shortcutURL = shortcutURL.replace(/%s/g, encodedParam).replace(/%S/g, param);

    if (/%s/i.test(postData)) // POST keyword
      aPostDataRef.value = getPostDataStream(postData, param, encodedParam,
                                             "application/x-www-form-urlencoded");
  }
  else if (param) {
    // This keyword doesn't take a parameter, but one was provided. Just return
    // the original URL.
    aPostDataRef.value = null;

    return aURL;
  }

  // This URL came from a bookmark, so it's safe to let it inherit the current
  // document's principal.
  if (aMayInheritPrincipal)
    aMayInheritPrincipal.value = true;

  return shortcutURL;
}

function getPostDataStream(aStringData, aKeyword, aEncKeyword, aType) {
  var dataStream = Cc["@mozilla.org/io/string-input-stream;1"].
                   createInstance(Ci.nsIStringInputStream);
  aStringData = aStringData.replace(/%s/g, aEncKeyword).replace(/%S/g, aKeyword);
  dataStream.data = aStringData;

  var mimeStream = Cc["@mozilla.org/network/mime-input-stream;1"].
                   createInstance(Ci.nsIMIMEInputStream);
  mimeStream.addHeader("Content-Type", aType);
  mimeStream.addContentLength = true;
  mimeStream.setData(dataStream);
  return mimeStream.QueryInterface(Ci.nsIInputStream);
}

function getLoadContext() {
  return window.QueryInterface(Ci.nsIInterfaceRequestor)
               .getInterface(Ci.nsIWebNavigation)
               .QueryInterface(Ci.nsILoadContext);
}

function readFromClipboard()
{
  var url;

  try {
    // Create transferable that will transfer the text.
    var trans = Components.classes["@mozilla.org/widget/transferable;1"]
                          .createInstance(Components.interfaces.nsITransferable);
    trans.init(getLoadContext());

    trans.addDataFlavor("text/unicode");

    // If available, use selection clipboard, otherwise global one
    if (Services.clipboard.supportsSelectionClipboard())
      Services.clipboard.getData(trans, Services.clipboard.kSelectionClipboard);
    else
      Services.clipboard.getData(trans, Services.clipboard.kGlobalClipboard);

    var data = {};
    var dataLen = {};
    trans.getTransferData("text/unicode", data, dataLen);

    if (data) {
      data = data.value.QueryInterface(Components.interfaces.nsISupportsString);
      url = data.data.substring(0, dataLen.value / 2);
    }
  } catch (ex) {
  }

  return url;
}

function BrowserViewSourceOfDocument(aDocument)
{
  var pageCookie;
  var webNav;

  // Get the document charset
  var docCharset = "charset=" + aDocument.characterSet;

  // Get the nsIWebNavigation associated with the document
  try {
      var win;
      var ifRequestor;

      // Get the DOMWindow for the requested document.  If the DOMWindow
      // cannot be found, then just use the content window...
      //
      // XXX:  This is a bit of a hack...
      win = aDocument.defaultView;
      if (win == window) {
        win = content;
      }
      ifRequestor = win.QueryInterface(Components.interfaces.nsIInterfaceRequestor);

      webNav = ifRequestor.getInterface(nsIWebNavigation);
  } catch(err) {
      // If nsIWebNavigation cannot be found, just get the one for the whole
      // window...
      webNav = gBrowser.webNavigation;
  }
  //
  // Get the 'PageDescriptor' for the current document. This allows the
  // view-source to access the cached copy of the content rather than
  // refetching it from the network...
  //
  try{
    var PageLoader = webNav.QueryInterface(Components.interfaces.nsIWebPageDescriptor);

    pageCookie = PageLoader.currentDescriptor;
  } catch(err) {
    // If no page descriptor is available, just use the view-source URL...
  }

  top.gViewSourceUtils.viewSource(webNav.currentURI.spec, pageCookie, aDocument);
}

// doc - document to use for source, or null for this window's document
// initialTab - name of the initial tab to display, or null for the first tab
// imageElement - image to load in the Media Tab of the Page Info window; can be null/omitted
function BrowserPageInfo(doc, initialTab, imageElement) {
  var args = {doc: doc, initialTab: initialTab, imageElement: imageElement};
  var windows = Services.wm.getEnumerator("Browser:page-info");

  var documentURL = doc ? doc.location : window.content.document.location;

  // Check for windows matching the url
  while (windows.hasMoreElements()) {
    var currentWindow = windows.getNext();
    if (currentWindow.document.documentElement.getAttribute("relatedUrl") == documentURL) {
      currentWindow.focus();
      currentWindow.resetPageInfo(args);
      return currentWindow;
    }
  }

  // We didn't find a matching window, so open a new one.
  return openDialog("chrome://browser/content/pageinfo/pageInfo.xul", "",
                    "chrome,toolbar,dialog=no,resizable", args);
}

function URLBarSetURI(aURI) {
  var value = gBrowser.userTypedValue;
  var valid = false;

  if (value == null) {
    let uri = aURI || gBrowser.currentURI;
    // Strip off "wyciwyg://" and passwords for the location bar
    try {
      uri = Services.uriFixup.createExposableURI(uri);
    } catch (e) {}

    // Replace initial page URIs with an empty string
    // only if there's no opener (bug 370555).
    if (gInitialPages.indexOf(uri.spec) != -1)
      value = content.opener ? uri.spec : "";
    else
      value = losslessDecodeURI(uri);

    valid = !isBlankPageURL(uri.spec);
  }

  gURLBar.value = value;
  gURLBar.valueIsTyped = !valid;
  SetPageProxyState(valid ? "valid" : "invalid");
}

function losslessDecodeURI(aURI) {
  var value = aURI.spec;
  // Try to decode as UTF-8 if there's no encoding sequence that we would break.
  if (!/%25(?:3B|2F|3F|3A|40|26|3D|2B|24|2C|23)/i.test(value))
    try {
      value = decodeURI(value)
                // 1. decodeURI decodes %25 to %, which creates unintended
                //    encoding sequences. Re-encode it, unless it's part of
                //    a sequence that survived decodeURI, i.e. one for:
                //    ';', '/', '?', ':', '@', '&', '=', '+', '$', ',', '#'
                //    (RFC 3987 section 3.2)
                // 2. Re-encode whitespace so that it doesn't get eaten away
                //    by the location bar (bug 410726).
                .replace(/%(?!3B|2F|3F|3A|40|26|3D|2B|24|2C|23)|[\r\n\t]/ig,
                         encodeURIComponent);
    } catch (e) {}

  // Encode invisible characters (line and paragraph separator,
  // object replacement character) (bug 452979)
  value = value.replace(/[\v\x0c\x1c\x1d\x1e\x1f\u2028\u2029\ufffc]/g,
                        encodeURIComponent);

  // Encode default ignorable characters (bug 546013)
  // except ZWNJ (U+200C) and ZWJ (U+200D) (bug 582186).
  // This includes all bidirectional formatting characters.
  // (RFC 3987 sections 3.2 and 4.1 paragraph 6)
  value = value.replace(/[\u00ad\u034f\u115f-\u1160\u17b4-\u17b5\u180b-\u180d\u200b\u200e-\u200f\u202a-\u202e\u2060-\u206f\u3164\ufe00-\ufe0f\ufeff\uffa0\ufff0-\ufff8]|\ud834[\udd73-\udd7a]|[\udb40-\udb43][\udc00-\udfff]/g,
                        encodeURIComponent);
  return value;
}

function UpdateUrlbarSearchSplitterState()
{
  var splitter = document.getElementById("urlbar-search-splitter");
  var urlbar = document.getElementById("urlbar-container");
  var searchbar = document.getElementById("search-container");
  var stop = document.getElementById("stop-button");

  var ibefore = null;
  if (urlbar && searchbar) {
    if (urlbar.nextSibling == searchbar ||
        urlbar.getAttribute("combined") &&
        stop && stop.nextSibling == searchbar)
      ibefore = searchbar;
    else if (searchbar.nextSibling == urlbar)
      ibefore = urlbar;
  }

  if (ibefore) {
    if (!splitter) {
      splitter = document.createElement("splitter");
      splitter.id = "urlbar-search-splitter";
      splitter.setAttribute("resizebefore", "flex");
      splitter.setAttribute("resizeafter", "flex");
      splitter.setAttribute("skipintoolbarset", "true");
      splitter.className = "chromeclass-toolbar-additional";
    }
    urlbar.parentNode.insertBefore(splitter, ibefore);
  } else if (splitter)
    splitter.parentNode.removeChild(splitter);
}

function setUrlAndSearchBarWidthForConditionalForwardButton() {
  // Workaround for bug 694084: Showing/hiding the conditional forward button resizes
  // the search bar when the url/search bar splitter hasn't been used.
  var urlbarContainer = document.getElementById("urlbar-container");
  var searchbarContainer = document.getElementById("search-container");
  if (!urlbarContainer ||
      !searchbarContainer ||
      urlbarContainer.hasAttribute("width") ||
      searchbarContainer.hasAttribute("width") ||
      urlbarContainer.parentNode != searchbarContainer.parentNode)
    return;
  urlbarContainer.style.width = searchbarContainer.style.width = "";
  var urlbarWidth = urlbarContainer.clientWidth;
  var searchbarWidth = searchbarContainer.clientWidth;
  urlbarContainer.style.width = urlbarWidth + "px";
  searchbarContainer.style.width = searchbarWidth + "px";
}

function UpdatePageProxyState()
{
  if (gURLBar && gURLBar.value != gLastValidURLStr)
    SetPageProxyState("invalid");
}

function SetPageProxyState(aState)
{
  if (!gURLBar)
    return;

  if (!gProxyFavIcon)
    gProxyFavIcon = document.getElementById("page-proxy-favicon");

  gURLBar.setAttribute("pageproxystate", aState);
  gProxyFavIcon.setAttribute("pageproxystate", aState);

  // the page proxy state is set to valid via OnLocationChange, which
  // gets called when we switch tabs.
  if (aState == "valid") {
    gLastValidURLStr = gURLBar.value;
    gURLBar.addEventListener("input", UpdatePageProxyState, false);
  } else if (aState == "invalid") {
    gURLBar.removeEventListener("input", UpdatePageProxyState, false);
  }
}

function PageProxyClickHandler(aEvent)
{
  if (aEvent.button == 1 && gPrefService.getBoolPref("middlemouse.paste"))
    middleMousePaste(aEvent);
}

/**
 *  Handle load of some pages (about:*) so that we can make modifications
 *  to the DOM for unprivileged pages.
 */
function BrowserOnAboutPageLoad(document) {
  if (document.documentURI.toLowerCase() == "about:home") {
    // XXX bug 738646 - when Marketplace is launched, remove this statement and
    // the hidden attribute set on the apps button in aboutHome.xhtml
    if (getBoolPref("browser.aboutHome.apps", false))
      document.getElementById("apps").removeAttribute("hidden");

    let ss = Components.classes["@mozilla.org/browser/sessionstore;1"].
             getService(Components.interfaces.nsISessionStore);
    if (ss.canRestoreLastSession
//@line 2514 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        && !PrivateBrowsingUtils.isWindowPrivate(window)
//@line 2516 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
        )
      document.getElementById("launcher").setAttribute("session", "true");

    // Inject search engine and snippets URL.
    let docElt = document.documentElement;
    docElt.setAttribute("snippetsURL", AboutHomeUtils.snippetsURL);
    docElt.setAttribute("searchEngineName",
                        AboutHomeUtils.defaultSearchEngine.name);
    docElt.setAttribute("searchEngineURL",
                        AboutHomeUtils.defaultSearchEngine.searchURL);
  }
}

/**
 * Handle command events bubbling up from error page content
 */
let BrowserOnClick = {
  handleEvent: function BrowserOnClick_handleEvent(aEvent) {
    if (!aEvent.isTrusted || // Don't trust synthetic events
        aEvent.button == 2 || aEvent.target.localName != "button") {
      return;
    }

    let originalTarget = aEvent.originalTarget;
    let ownerDoc = originalTarget.ownerDocument;

    // If the event came from an ssl error page, it is probably either the "Add
    // Exception…" or "Get me out of here!" button
    if (ownerDoc.documentURI.startsWith("about:certerror")) {
      this.onAboutCertError(originalTarget, ownerDoc);
    }
    else if (ownerDoc.documentURI.startsWith("about:blocked")) {
      this.onAboutBlocked(originalTarget, ownerDoc);
    }
    else if (ownerDoc.documentURI.startsWith("about:neterror")) {
      this.onAboutNetError(originalTarget, ownerDoc);
    }
    else if (ownerDoc.documentURI.toLowerCase() == "about:home") {
      this.onAboutHome(originalTarget, ownerDoc);
    }
  },

  onAboutCertError: function BrowserOnClick_onAboutCertError(aTargetElm, aOwnerDoc) {
    let elmId = aTargetElm.getAttribute("id");
    let secHistogram = Services.telemetry.getHistogramById("SECURITY_UI");

    switch (elmId) {
      case "exceptionDialogButton":
        secHistogram.add(Ci.nsISecurityUITelemetry.WARNING_BAD_CERT_CLICK_ADD_EXCEPTION);
        let params = { exceptionAdded : false };

        try {
          switch (Services.prefs.getIntPref("browser.ssl_override_behavior")) {
            case 2 : // Pre-fetch & pre-populate
              params.prefetchCert = true;
            case 1 : // Pre-populate
              params.location = aOwnerDoc.location.href;
          }
        } catch (e) {
          Components.utils.reportError("Couldn't get ssl_override pref: " + e);
        }

        window.openDialog('chrome://pippki/content/exceptionDialog.xul',
                          '','chrome,centerscreen,modal', params);

        // If the user added the exception cert, attempt to reload the page
        if (params.exceptionAdded) {
          aOwnerDoc.location.reload();
        }
        break;

      case "getMeOutOfHereButton":
        secHistogram.add(Ci.nsISecurityUITelemetry.WARNING_BAD_CERT_GET_ME_OUT_OF_HERE);
        getMeOutOfHere();
        break;

      case "technicalContent":
        secHistogram.add(Ci.nsISecurityUITelemetry.WARNING_BAD_CERT_TECHNICAL_DETAILS);
        break;

      case "expertContent":
        secHistogram.add(Ci.nsISecurityUITelemetry.WARNING_BAD_CERT_UNDERSTAND_RISKS);
        break;

    }
  },

  onAboutBlocked: function BrowserOnClick_onAboutBlocked(aTargetElm, aOwnerDoc) {
    let elmId = aTargetElm.getAttribute("id");
    let secHistogram = Services.telemetry.getHistogramById("SECURITY_UI");

    // The event came from a button on a malware/phishing block page
    // First check whether it's malware or phishing, so that we can
    // use the right strings/links
    let isMalware = /e=malwareBlocked/.test(aOwnerDoc.documentURI);
    let bucketName = isMalware ? "WARNING_MALWARE_PAGE_":"WARNING_PHISHING_PAGE_";
    let nsISecTel = Ci.nsISecurityUITelemetry;

    switch (elmId) {
      case "getMeOutButton":
        secHistogram.add(nsISecTel[bucketName + "GET_ME_OUT_OF_HERE"]);
        getMeOutOfHere();
        break;

      case "reportButton":
        // This is the "Why is this site blocked" button.  For malware,
        // we can fetch a site-specific report, for phishing, we redirect
        // to the generic page describing phishing protection.

        // We log even if malware/phishing info URL couldn't be found: 
        // the measurement is for how many users clicked the WHY BLOCKED button
        secHistogram.add(nsISecTel[bucketName + "WHY_BLOCKED"]);

        if (isMalware) {
          // Get the stop badware "why is this blocked" report url,
          // append the current url, and go there.
          try {
            let reportURL = formatURL("browser.safebrowsing.malware.reportURL", true);
            reportURL += aOwnerDoc.location.href;
            content.location = reportURL;
          } catch (e) {
            Components.utils.reportError("Couldn't get malware report URL: " + e);
          }
        }
        else { // It's a phishing site, not malware
          try {
            content.location = formatURL("browser.safebrowsing.warning.infoURL", true);
          } catch (e) {
            Components.utils.reportError("Couldn't get phishing info URL: " + e);
          }
        }
        break;

      case "ignoreWarningButton":
        secHistogram.add(nsISecTel[bucketName + "IGNORE_WARNING"]);
        this.ignoreWarningButton(isMalware);
        break;
    }
  },

  ignoreWarningButton: function BrowserOnClick_ignoreWarningButton(aIsMalware) {
    // Allow users to override and continue through to the site,
    // but add a notify bar as a reminder, so that they don't lose
    // track after, e.g., tab switching.
    gBrowser.loadURIWithFlags(content.location.href,
                              nsIWebNavigation.LOAD_FLAGS_BYPASS_CLASSIFIER,
                              null, null, null);

    Services.perms.add(makeURI(content.location.href), "safe-browsing",
                       Ci.nsIPermissionManager.ALLOW_ACTION,
                       Ci.nsIPermissionManager.EXPIRE_SESSION);

    let buttons = [{
      label: gNavigatorBundle.getString("safebrowsing.getMeOutOfHereButton.label"),
      accessKey: gNavigatorBundle.getString("safebrowsing.getMeOutOfHereButton.accessKey"),
      callback: function() { getMeOutOfHere(); }
    }];

    let title;
    if (aIsMalware) {
      title = gNavigatorBundle.getString("safebrowsing.reportedAttackSite");
      buttons[1] = {
        label: gNavigatorBundle.getString("safebrowsing.notAnAttackButton.label"),
        accessKey: gNavigatorBundle.getString("safebrowsing.notAnAttackButton.accessKey"),
        callback: function() {
          openUILinkIn(gSafeBrowsing.getReportURL('MalwareError'), 'tab');
        }
      };
    } else {
      title = gNavigatorBundle.getString("safebrowsing.reportedWebForgery");
      buttons[1] = {
        label: gNavigatorBundle.getString("safebrowsing.notAForgeryButton.label"),
        accessKey: gNavigatorBundle.getString("safebrowsing.notAForgeryButton.accessKey"),
        callback: function() {
          openUILinkIn(gSafeBrowsing.getReportURL('Error'), 'tab');
        }
      };
    }

    let notificationBox = gBrowser.getNotificationBox();
    let value = "blocked-badware-page";

    let previousNotification = notificationBox.getNotificationWithValue(value);
    if (previousNotification) {
      notificationBox.removeNotification(previousNotification);
    }

    let notification = notificationBox.appendNotification(
      title,
      value,
      "chrome://global/skin/icons/blacklist_favicon.png",
      notificationBox.PRIORITY_CRITICAL_HIGH,
      buttons
    );
    // Persist the notification until the user removes so it
    // doesn't get removed on redirects.
    notification.persistence = -1;
  },

  onAboutNetError: function BrowserOnClick_onAboutNetError(aTargetElm, aOwnerDoc) {
    let elmId = aTargetElm.getAttribute("id");
    if (elmId != "errorTryAgain" || !/e=netOffline/.test(aOwnerDoc.documentURI))
      return;
    Services.io.offline = false;
  },

  onAboutHome: function BrowserOnClick_onAboutHome(aTargetElm, aOwnerDoc) {
    let elmId = aTargetElm.getAttribute("id");

    switch (elmId) {
      case "restorePreviousSession":
        let ss = Cc["@mozilla.org/browser/sessionstore;1"].
                 getService(Ci.nsISessionStore);
        if (ss.canRestoreLastSession) {
          ss.restoreLastSession();
        }
        aOwnerDoc.getElementById("launcher").removeAttribute("session");
        break;

      case "downloads":
        BrowserDownloadsUI();
        break;

      case "bookmarks":
        PlacesCommandHook.showPlacesOrganizer("AllBookmarks");
        break;

      case "history":
        PlacesCommandHook.showPlacesOrganizer("History");
        break;

      case "apps":
        openUILinkIn("https://marketplace.mozilla.org/", "tab");
        break;

      case "addons":
        BrowserOpenAddonsMgr();
        break;

      case "sync":
        openPreferences("paneSync");
        break;

      case "settings":
        openPreferences();
        break;
    }
  },
};

/**
 * Re-direct the browser to a known-safe page.  This function is
 * used when, for example, the user browses to a known malware page
 * and is presented with about:blocked.  The "Get me out of here!"
 * button should take the user to the default start page so that even
 * when their own homepage is infected, we can get them somewhere safe.
 */
function getMeOutOfHere() {
  // Get the start page from the *default* pref branch, not the user's
  var prefs = Services.prefs.getDefaultBranch(null);
  var url = BROWSER_NEW_TAB_URL;
  try {
    url = prefs.getComplexValue("browser.startup.homepage",
                                Ci.nsIPrefLocalizedString).data;
    // If url is a pipe-delimited set of pages, just take the first one.
    if (url.contains("|"))
      url = url.split("|")[0];
  } catch(e) {
    Components.utils.reportError("Couldn't get homepage pref: " + e);
  }
  content.location = url;
}

function BrowserFullScreen()
{
  window.fullScreen = !window.fullScreen;
}

function onFullScreen(event) {
  FullScreen.toggle(event);
}

function onMozEnteredDomFullscreen(event) {
  FullScreen.enterDomFullscreen(event);
}

function getWebNavigation()
{
  return gBrowser.webNavigation;
}

function BrowserReloadWithFlags(reloadFlags) {
  /* First, we'll try to use the session history object to reload so
   * that framesets are handled properly. If we're in a special
   * window (such as view-source) that has no session history, fall
   * back on using the web navigation's reload method.
   */

  var webNav = gBrowser.webNavigation;
  try {
    var sh = webNav.sessionHistory;
    if (sh)
      webNav = sh.QueryInterface(nsIWebNavigation);
  } catch (e) {
  }

  try {
    webNav.reload(reloadFlags);
  } catch (e) {
  }
}

var PrintPreviewListener = {
  _printPreviewTab: null,
  _tabBeforePrintPreview: null,

  getPrintPreviewBrowser: function () {
    if (!this._printPreviewTab) {
      this._tabBeforePrintPreview = gBrowser.selectedTab;
      this._printPreviewTab = gBrowser.loadOneTab("about:blank",
                                                  { inBackground: false });
      gBrowser.selectedTab = this._printPreviewTab;
    }
    return gBrowser.getBrowserForTab(this._printPreviewTab);
  },
  getSourceBrowser: function () {
    return this._tabBeforePrintPreview ?
      this._tabBeforePrintPreview.linkedBrowser : gBrowser.selectedBrowser;
  },
  getNavToolbox: function () {
    return gNavToolbox;
  },
  onEnter: function () {
    gInPrintPreviewMode = true;
    this._toggleAffectedChrome();
  },
  onExit: function () {
    gBrowser.selectedTab = this._tabBeforePrintPreview;
    this._tabBeforePrintPreview = null;
    gInPrintPreviewMode = false;
    this._toggleAffectedChrome();
    gBrowser.removeTab(this._printPreviewTab);
    this._printPreviewTab = null;
  },
  _toggleAffectedChrome: function () {
    gNavToolbox.collapsed = gInPrintPreviewMode;

    if (gInPrintPreviewMode)
      this._hideChrome();
    else
      this._showChrome();

    if (this._chromeState.sidebarOpen)
      toggleSidebar(this._sidebarCommand);

//@line 2872 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    updateAppButtonDisplay();
//@line 2874 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  },
  _hideChrome: function () {
    this._chromeState = {};

    var sidebar = document.getElementById("sidebar-box");
    this._chromeState.sidebarOpen = !sidebar.hidden;
    this._sidebarCommand = sidebar.getAttribute("sidebarcommand");

    var notificationBox = gBrowser.getNotificationBox();
    this._chromeState.notificationsOpen = !notificationBox.notificationsHidden;
    notificationBox.notificationsHidden = true;

    document.getElementById("sidebar").setAttribute("src", "about:blank");
    var addonBar = document.getElementById("addon-bar");
    this._chromeState.addonBarOpen = !addonBar.collapsed;
    addonBar.collapsed = true;
    gBrowser.updateWindowResizers();

    this._chromeState.findOpen = gFindBarInitialized && !gFindBar.hidden;
    if (gFindBarInitialized)
      gFindBar.close();

    this._chromeState.syncNotificationsOpen = false;
    var syncNotifications = document.getElementById("sync-notifications");
    if (syncNotifications) {
      this._chromeState.syncNotificationsOpen = !syncNotifications.notificationsHidden;
      syncNotifications.notificationsHidden = true;
    }
  },
  _showChrome: function () {
    if (this._chromeState.notificationsOpen)
      gBrowser.getNotificationBox().notificationsHidden = false;

    if (this._chromeState.addonBarOpen) {
      document.getElementById("addon-bar").collapsed = false;
      gBrowser.updateWindowResizers();
    }

    if (this._chromeState.findOpen)
      gFindBar.open();

    if (this._chromeState.syncNotificationsOpen)
      document.getElementById("sync-notifications").notificationsHidden = false;
  }
}

function getMarkupDocumentViewer()
{
  return gBrowser.markupDocumentViewer;
}

/**
 * Content area tooltip.
 * XXX - this must move into XBL binding/equiv! Do not want to pollute
 *       browser.js with functionality that can be encapsulated into
 *       browser widget. TEMPORARY!
 *
 * NOTE: Any changes to this routine need to be mirrored in DefaultTooltipTextProvider::GetNodeText()
 *       (located in mozilla/embedding/browser/webBrowser/nsDocShellTreeOwner.cpp)
 *       which performs the same function, but for embedded clients that
 *       don't use a XUL/JS layer. It is important that the logic of
 *       these two routines be kept more or less in sync.
 *       (pinkerton)
 **/
function FillInHTMLTooltip(tipElement)
{
  var retVal = false;
  // Don't show the tooltip if the tooltip node is a document or disconnected.
  if (!tipElement.ownerDocument ||
      (tipElement.ownerDocument.compareDocumentPosition(tipElement) & document.DOCUMENT_POSITION_DISCONNECTED))
    return retVal;

  const XLinkNS = "http://www.w3.org/1999/xlink";
  const XULNS = "http://www.mozilla.org/keymaster/gatekeeper/there.is.only.xul";

  var titleText = null;
  var XLinkTitleText = null;
  var SVGTitleText = null;
  var lookingForSVGTitle = true;
  var direction = tipElement.ownerDocument.dir;

  // If the element is invalid per HTML5 Forms specifications and has no title,
  // show the constraint validation error message.
  if ((tipElement instanceof HTMLInputElement ||
       tipElement instanceof HTMLTextAreaElement ||
       tipElement instanceof HTMLSelectElement ||
       tipElement instanceof HTMLButtonElement) &&
      !tipElement.hasAttribute('title') &&
      (!tipElement.form || !tipElement.form.noValidate)) {
    // If the element is barred from constraint validation or valid,
    // the validation message will be the empty string.
    titleText = tipElement.validationMessage;
  }

  while (!titleText && !XLinkTitleText && !SVGTitleText && tipElement) {
    if (tipElement.nodeType == Node.ELEMENT_NODE &&
        tipElement.namespaceURI != XULNS) {
      titleText = tipElement.getAttribute("title");
      if ((tipElement instanceof HTMLAnchorElement ||
           tipElement instanceof HTMLAreaElement ||
           tipElement instanceof HTMLLinkElement ||
           tipElement instanceof SVGAElement) && tipElement.href) {
        XLinkTitleText = tipElement.getAttributeNS(XLinkNS, "title");
      }
      if (lookingForSVGTitle &&
          (!(tipElement instanceof SVGElement) ||
           tipElement.parentNode.nodeType == Node.DOCUMENT_NODE)) {
        lookingForSVGTitle = false;
      }
      if (lookingForSVGTitle) {
        for (let childNode of tipElement.childNodes) {
          if (childNode instanceof SVGTitleElement) {
            SVGTitleText = childNode.textContent;
            break;
          }
        }
      }
      var defView = tipElement.ownerDocument.defaultView;
      // XXX Work around bug 350679:
      // "Tooltips can be fired in documents with no view".
      if (!defView)
        return retVal;
      direction = defView.getComputedStyle(tipElement, "")
        .getPropertyValue("direction");
    }
    tipElement = tipElement.parentNode;
  }

  var tipNode = document.getElementById("aHTMLTooltip");
  tipNode.style.direction = direction;

  [titleText, XLinkTitleText, SVGTitleText].forEach(function (t) {
    if (t && /\S/.test(t)) {
      // Make CRLF and CR render one line break each.
      t = t.replace(/\r\n?/g, '\n');

      tipNode.setAttribute("label", t);
      retVal = true;
    }
  });
  return retVal;
}

var browserDragAndDrop = {
  canDropLink: function (aEvent) Services.droppedLinkHandler.canDropLink(aEvent, true),

  dragOver: function (aEvent)
  {
    if (this.canDropLink(aEvent)) {
      aEvent.preventDefault();
    }
  },

  drop: function (aEvent, aName, aDisallowInherit) {
    return Services.droppedLinkHandler.dropLink(aEvent, aName, aDisallowInherit);
  }
};

var homeButtonObserver = {
  onDrop: function (aEvent)
    {
      // disallow setting home pages that inherit the principal
      let url = browserDragAndDrop.drop(aEvent, {}, true);
      setTimeout(openHomeDialog, 0, url);
    },

  onDragOver: function (aEvent)
    {
      browserDragAndDrop.dragOver(aEvent);
      aEvent.dropEffect = "link";
    },
  onDragExit: function (aEvent)
    {
    }
}

function openHomeDialog(aURL)
{
  var promptTitle = gNavigatorBundle.getString("droponhometitle");
  var promptMsg   = gNavigatorBundle.getString("droponhomemsg");
  var pressedVal  = Services.prompt.confirmEx(window, promptTitle, promptMsg,
                          Services.prompt.STD_YES_NO_BUTTONS,
                          null, null, null, null, {value:0});

  if (pressedVal == 0) {
    try {
      var str = Components.classes["@mozilla.org/supports-string;1"]
                          .createInstance(Components.interfaces.nsISupportsString);
      str.data = aURL;
      gPrefService.setComplexValue("browser.startup.homepage",
                                   Components.interfaces.nsISupportsString, str);
    } catch (ex) {
      dump("Failed to set the home page.\n"+ex+"\n");
    }
  }
}

var bookmarksButtonObserver = {
  onDrop: function (aEvent)
  {
    let name = { };
    let url = browserDragAndDrop.drop(aEvent, name);
    try {
      PlacesUIUtils.showBookmarkDialog({ action: "add"
                                       , type: "bookmark"
                                       , uri: makeURI(url)
                                       , title: name
                                       , hiddenRows: [ "description"
                                                     , "location"
                                                     , "loadInSidebar"
                                                     , "keyword" ]
                                       }, window);
    } catch(ex) { }
  },

  onDragOver: function (aEvent)
  {
    browserDragAndDrop.dragOver(aEvent);
    aEvent.dropEffect = "link";
  },

  onDragExit: function (aEvent)
  {
  }
}

var newTabButtonObserver = {
  onDragOver: function (aEvent)
  {
    browserDragAndDrop.dragOver(aEvent);
  },

  onDragExit: function (aEvent)
  {
  },

  onDrop: function (aEvent)
  {
    let url = browserDragAndDrop.drop(aEvent, { });
    var postData = {};
    url = getShortcutOrURI(url, postData);
    if (url) {
      // allow third-party services to fixup this URL
      openNewTabWith(url, null, postData.value, aEvent, true);
    }
  }
}

var newWindowButtonObserver = {
  onDragOver: function (aEvent)
  {
    browserDragAndDrop.dragOver(aEvent);
  },
  onDragExit: function (aEvent)
  {
  },
  onDrop: function (aEvent)
  {
    let url = browserDragAndDrop.drop(aEvent, { });
    var postData = {};
    url = getShortcutOrURI(url, postData);
    if (url) {
      // allow third-party services to fixup this URL
      openNewWindowWith(url, null, postData.value, true);
    }
  }
}

const DOMLinkHandler = {
  handleEvent: function (event) {
    switch (event.type) {
      case "DOMLinkAdded":
        this.onLinkAdded(event);
        break;
    }
  },
  getLinkIconURI: function(aLink) {
    let targetDoc = aLink.ownerDocument;
    var uri = makeURI(aLink.href, targetDoc.characterSet);

    // Verify that the load of this icon is legal.
    // Some error or special pages can load their favicon.
    // To be on the safe side, only allow chrome:// favicons.
    var isAllowedPage = [
      /^about:neterror\?/,
      /^about:blocked\?/,
      /^about:certerror\?/,
      /^about:home$/,
    ].some(function (re) re.test(targetDoc.documentURI));

    if (!isAllowedPage || !uri.schemeIs("chrome")) {
      var ssm = Services.scriptSecurityManager;
      try {
        ssm.checkLoadURIWithPrincipal(targetDoc.nodePrincipal, uri,
                                      Ci.nsIScriptSecurityManager.DISALLOW_SCRIPT);
      } catch(e) {
        return null;
      }
    }

    try {
      var contentPolicy = Cc["@mozilla.org/layout/content-policy;1"].
                          getService(Ci.nsIContentPolicy);
    } catch(e) {
      return null; // Refuse to load if we can't do a security check.
    }

    // Security says okay, now ask content policy
    if (contentPolicy.shouldLoad(Ci.nsIContentPolicy.TYPE_IMAGE,
                                 uri, targetDoc.documentURIObject,
                                 aLink, aLink.type, null)
                                 != Ci.nsIContentPolicy.ACCEPT)
      return null;
    
    try {
      uri.userPass = "";
    } catch(e) {
      // some URIs are immutable
    }
    return uri;
  },
  onLinkAdded: function (event) {
    var link = event.originalTarget;
    var rel = link.rel && link.rel.toLowerCase();
    if (!link || !link.ownerDocument || !rel || !link.href)
      return;

    var feedAdded = false;
    var iconAdded = false;
    var searchAdded = false;
    var rels = {};
    for (let relString of rel.split(/\s+/))
      rels[relString] = true;

    for (let relVal in rels) {
      switch (relVal) {
        case "feed":
        case "alternate":
          if (!feedAdded) {
            if (!rels.feed && rels.alternate && rels.stylesheet)
              break;

            if (isValidFeed(link, link.ownerDocument.nodePrincipal, rels.feed)) {
              FeedHandler.addFeed(link, link.ownerDocument);
              feedAdded = true;
            }
          }
          break;
        case "icon":
          if (!iconAdded) {
            if (!gPrefService.getBoolPref("browser.chrome.site_icons"))
              break;

            var uri = this.getLinkIconURI(link);
            if (!uri)
              break;

            if (gBrowser.isFailedIcon(uri))
              break;

            var browserIndex = gBrowser.getBrowserIndexForDocument(link.ownerDocument);
            // no browser? no favicon.
            if (browserIndex == -1)
              break;

            let tab = gBrowser.tabs[browserIndex];
            gBrowser.setIcon(tab, uri.spec);
            iconAdded = true;
          }
          break;
        case "search":
          if (!searchAdded) {
            var type = link.type && link.type.toLowerCase();
            type = type.replace(/^\s+|\s*(?:;.*)?$/g, "");

            if (type == "application/opensearchdescription+xml" && link.title &&
                /^(?:https?|ftp):/i.test(link.href) &&
                !PrivateBrowsingUtils.isWindowPrivate(window)) {
              var engine = { title: link.title, href: link.href };
              BrowserSearch.addEngine(engine, link.ownerDocument);
              searchAdded = true;
            }
          }
          break;
      }
    }
  }
}

const BrowserSearch = {
  addEngine: function(engine, targetDoc) {
    if (!this.searchBar)
      return;

    var browser = gBrowser.getBrowserForDocument(targetDoc);
    // ignore search engines from subframes (see bug 479408)
    if (!browser)
      return;

    // Check to see whether we've already added an engine with this title
    if (browser.engines) {
      if (browser.engines.some(function (e) e.title == engine.title))
        return;
    }

    // Append the URI and an appropriate title to the browser data.
    // Use documentURIObject in the check for shouldLoadFavIcon so that we
    // do the right thing with about:-style error pages.  Bug 453442
    var iconURL = null;
    if (gBrowser.shouldLoadFavIcon(targetDoc.documentURIObject))
      iconURL = targetDoc.documentURIObject.prePath + "/favicon.ico";

    var hidden = false;
    // If this engine (identified by title) is already in the list, add it
    // to the list of hidden engines rather than to the main list.
    // XXX This will need to be changed when engines are identified by URL;
    // see bug 335102.
    if (Services.search.getEngineByName(engine.title))
      hidden = true;

    var engines = (hidden ? browser.hiddenEngines : browser.engines) || [];

    engines.push({ uri: engine.href,
                   title: engine.title,
                   icon: iconURL });

    if (hidden)
      browser.hiddenEngines = engines;
    else
      browser.engines = engines;
  },

  /**
   * Gives focus to the search bar, if it is present on the toolbar, or loads
   * the default engine's search form otherwise. For Mac, opens a new window
   * or focuses an existing window, if necessary.
   */
  webSearch: function BrowserSearch_webSearch() {
//@line 3334 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    var searchBar = this.searchBar;
    if (searchBar && window.fullScreen)
      FullScreen.mouseoverToggle(true);
    if (searchBar)
      searchBar.select();
    if (!searchBar || document.activeElement != searchBar.textbox.inputField)
      openUILinkIn(Services.search.defaultEngine.searchForm, "current");
  },

  /**
   * Loads a search results page, given a set of search terms. Uses the current
   * engine if the search bar is visible, or the default engine otherwise.
   *
   * @param searchText
   *        The search terms to use for the search.
   *
   * @param useNewTab
   *        Boolean indicating whether or not the search should load in a new
   *        tab.
   *
   * @param responseType [optional]
   *        The MIME type that we'd like to receive in response
   *        to this submission.  If null or the the response type is not supported
   *        for the search engine, will fallback to "text/html".
   */
  loadSearch: function BrowserSearch_search(searchText, useNewTab, responseType) {
    var engine;

    // If the search bar is visible, use the current engine, otherwise, fall
    // back to the default engine.
    if (isElementVisible(this.searchBar))
      engine = Services.search.currentEngine;
    else
      engine = Services.search.defaultEngine;

    var submission = engine.getSubmission(searchText, responseType);

    // If a response type was specified and getSubmission returned null,
    // fallback to the default response type.
    if (!submission && responseType)
      submission = engine.getSubmission(searchText);

    // getSubmission can return null if the engine doesn't have a URL
    // with a text/html response type.  This is unlikely (since
    // SearchService._addEngineToStore() should fail for such an engine),
    // but let's be on the safe side.
    if (!submission)
      return;

    let inBackground = Services.prefs.getBoolPref("browser.search.context.loadInBackground");
    openLinkIn(submission.uri.spec,
               useNewTab ? "tab" : "current",
               { postData: submission.postData,
                 inBackground: inBackground,
                 relatedToCurrent: true });
  },

  /**
   * Returns the search bar element if it is present in the toolbar, null otherwise.
   */
  get searchBar() {
    return document.getElementById("searchbar");
  },

  loadAddEngines: function BrowserSearch_loadAddEngines() {
    var newWindowPref = gPrefService.getIntPref("browser.link.open_newwindow");
    var where = newWindowPref == 3 ? "tab" : "window";
    var searchEnginesURL = formatURL("browser.search.searchEnginesURL", true);
    openUILinkIn(searchEnginesURL, where);
  }
}

function FillHistoryMenu(aParent) {
  // Lazily add the hover listeners on first showing and never remove them
  if (!aParent.hasStatusListener) {
    // Show history item's uri in the status bar when hovering, and clear on exit
    aParent.addEventListener("DOMMenuItemActive", function(aEvent) {
      // Only the current page should have the checked attribute, so skip it
      if (!aEvent.target.hasAttribute("checked"))
        XULBrowserWindow.setOverLink(aEvent.target.getAttribute("uri"));
    }, false);
    aParent.addEventListener("DOMMenuItemInactive", function() {
      XULBrowserWindow.setOverLink("");
    }, false);

    aParent.hasStatusListener = true;
  }

  // Remove old entries if any
  var children = aParent.childNodes;
  for (var i = children.length - 1; i >= 0; --i) {
    if (children[i].hasAttribute("index"))
      aParent.removeChild(children[i]);
  }

  var webNav = gBrowser.webNavigation;
  var sessionHistory = webNav.sessionHistory;

  var count = sessionHistory.count;
  if (count <= 1) // don't display the popup for a single item
    return false;

  const MAX_HISTORY_MENU_ITEMS = 15;
  var index = sessionHistory.index;
  var half_length = Math.floor(MAX_HISTORY_MENU_ITEMS / 2);
  var start = Math.max(index - half_length, 0);
  var end = Math.min(start == 0 ? MAX_HISTORY_MENU_ITEMS : index + half_length + 1, count);
  if (end == count)
    start = Math.max(count - MAX_HISTORY_MENU_ITEMS, 0);

  var tooltipBack = gNavigatorBundle.getString("tabHistory.goBack");
  var tooltipCurrent = gNavigatorBundle.getString("tabHistory.current");
  var tooltipForward = gNavigatorBundle.getString("tabHistory.goForward");

  for (var j = end - 1; j >= start; j--) {
    let item = document.createElement("menuitem");
    let entry = sessionHistory.getEntryAtIndex(j, false);
    let uri = entry.URI.spec;

    item.setAttribute("uri", uri);
    item.setAttribute("label", entry.title || uri);
    item.setAttribute("index", j);

    if (j != index) {
      PlacesUtils.favicons.getFaviconURLForPage(entry.URI, function (aURI) {
        if (aURI) {
          let iconURL = PlacesUtils.favicons.getFaviconLinkForIcon(aURI).spec;
          item.style.listStyleImage = "url(" + iconURL + ")";
        }
      });
    }

    if (j < index) {
      item.className = "unified-nav-back menuitem-iconic menuitem-with-favicon";
      item.setAttribute("tooltiptext", tooltipBack);
    } else if (j == index) {
      item.setAttribute("type", "radio");
      item.setAttribute("checked", "true");
      item.className = "unified-nav-current";
      item.setAttribute("tooltiptext", tooltipCurrent);
    } else {
      item.className = "unified-nav-forward menuitem-iconic menuitem-with-favicon";
      item.setAttribute("tooltiptext", tooltipForward);
    }

    aParent.appendChild(item);
  }
  return true;
}

function addToUrlbarHistory(aUrlToAdd) {
  if (!PrivateBrowsingUtils.isWindowPrivate(window) &&
      aUrlToAdd &&
      !aUrlToAdd.contains(" ") &&
      !/[\x00-\x1F]/.test(aUrlToAdd))
    PlacesUIUtils.markPageAsTyped(aUrlToAdd);
}

function toJavaScriptConsole()
{
  toOpenWindowByType("global:console", "chrome://global/content/console.xul");
}

function BrowserDownloadsUI()
{
  Cc["@mozilla.org/download-manager-ui;1"].
  getService(Ci.nsIDownloadManagerUI).show(window);
}

function toOpenWindowByType(inType, uri, features)
{
  var topWindow = Services.wm.getMostRecentWindow(inType);

  if (topWindow)
    topWindow.focus();
  else if (features)
    window.open(uri, "_blank", features);
  else
    window.open(uri, "_blank", "chrome,extrachrome,menubar,resizable,scrollbars,status,toolbar");
}

function OpenBrowserWindow(options)
{
  var telemetryObj = {};
  TelemetryStopwatch.start("FX_NEW_WINDOW_MS", telemetryObj);

  function newDocumentShown(doc, topic, data) {
    if (topic == "document-shown" &&
        doc != document &&
        doc.defaultView == win) {
      Services.obs.removeObserver(newDocumentShown, "document-shown");
      TelemetryStopwatch.finish("FX_NEW_WINDOW_MS", telemetryObj);
    }
  };
  Services.obs.addObserver(newDocumentShown, "document-shown", false);

  var charsetArg = new String();
  var handler = Components.classes["@mozilla.org/browser/clh;1"]
                          .getService(Components.interfaces.nsIBrowserHandler);
  var defaultArgs = handler.defaultArgs;
  var wintype = document.documentElement.getAttribute('windowtype');

  var extraFeatures = "";
//@line 3538 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  if (options && options.private) {
//@line 3542 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    extraFeatures = ",private";
    if (!PrivateBrowsingUtils.permanentPrivateBrowsing) {
      // Force the new window to load about:privatebrowsing instead of the default home page
      defaultArgs = "about:privatebrowsing";
    }
  } else {
    extraFeatures = ",non-private";
  }

  // if and only if the current window is a browser window and it has a document with a character
  // set, then extract the current charset menu setting from the current document and use it to
  // initialize the new browser window...
  var win;
  if (window && (wintype == "navigator:browser") && window.content && window.content.document)
  {
    var DocCharset = window.content.document.characterSet;
    charsetArg = "charset="+DocCharset;

    //we should "inherit" the charset menu setting in a new window
    win = window.openDialog("chrome://browser/content/", "_blank", "chrome,all,dialog=no" + extraFeatures, defaultArgs, charsetArg);
  }
  else // forget about the charset information.
  {
    win = window.openDialog("chrome://browser/content/", "_blank", "chrome,all,dialog=no" + extraFeatures, defaultArgs);
  }

  return win;
}

var gCustomizeSheet = false;
function BrowserCustomizeToolbar() {
  // Disable the toolbar context menu items
  var menubar = document.getElementById("main-menubar");
  for (let childNode of menubar.childNodes)
    childNode.setAttribute("disabled", true);

  var cmd = document.getElementById("cmd_CustomizeToolbars");
  cmd.setAttribute("disabled", "true");

  var splitter = document.getElementById("urlbar-search-splitter");
  if (splitter)
    splitter.parentNode.removeChild(splitter);

  CombinedStopReload.uninit();

  PlacesToolbarHelper.customizeStart();
  BookmarksMenuButton.customizeStart();
  DownloadsButton.customizeStart();

  TabsInTitlebar.allowedBy("customizing-toolbars", false);

  var customizeURL = "chrome://global/content/customizeToolbar.xul";
  gCustomizeSheet = getBoolPref("toolbar.customization.usesheet", false);

  if (gCustomizeSheet) {
    let sheetFrame = document.createElement("iframe");
    let panel = document.getElementById("customizeToolbarSheetPopup");
    sheetFrame.id = "customizeToolbarSheetIFrame";
    sheetFrame.toolbox = gNavToolbox;
    sheetFrame.panel = panel;
    sheetFrame.setAttribute("style", panel.getAttribute("sheetstyle"));
    panel.appendChild(sheetFrame);

    // Open the panel, but make it invisible until the iframe has loaded so
    // that the user doesn't see a white flash.
    panel.style.visibility = "hidden";
    gNavToolbox.addEventListener("beforecustomization", function onBeforeCustomization() {
      gNavToolbox.removeEventListener("beforecustomization", onBeforeCustomization, false);
      panel.style.removeProperty("visibility");
    }, false);

    sheetFrame.setAttribute("src", customizeURL);

    panel.openPopup(gNavToolbox, "after_start", 0, 0);
  } else {
    window.openDialog(customizeURL,
                      "CustomizeToolbar",
                      "chrome,titlebar,toolbar,location,resizable,dependent",
                      gNavToolbox);
  }
}

function BrowserToolboxCustomizeDone(aToolboxChanged) {
  if (gCustomizeSheet) {
    document.getElementById("customizeToolbarSheetPopup").hidePopup();
    let iframe = document.getElementById("customizeToolbarSheetIFrame");
    iframe.parentNode.removeChild(iframe);
  }

  // Update global UI elements that may have been added or removed
  if (aToolboxChanged) {
    gURLBar = document.getElementById("urlbar");

    gProxyFavIcon = document.getElementById("page-proxy-favicon");
    gHomeButton.updateTooltip();
    gIdentityHandler._cacheElements();
    window.XULBrowserWindow.init();

//@line 3641 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    updateEditUIVisibility();
//@line 3643 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    // Hacky: update the PopupNotifications' object's reference to the iconBox,
    // if it already exists, since it may have changed if the URL bar was
    // added/removed.
    if (!__lookupGetter__("PopupNotifications"))
      PopupNotifications.iconBox = document.getElementById("notification-popup-box");
  }

  PlacesToolbarHelper.customizeDone();
  BookmarksMenuButton.customizeDone();
  DownloadsButton.customizeDone();

  // The url bar splitter state is dependent on whether stop/reload
  // and the location bar are combined, so we need this ordering
  CombinedStopReload.init();
  UpdateUrlbarSearchSplitterState();
  setUrlAndSearchBarWidthForConditionalForwardButton();

  // Update the urlbar
  if (gURLBar) {
    URLBarSetURI();
    XULBrowserWindow.asyncUpdateUI();
    PlacesStarButton.updateState();
    SocialShareButton.updateShareState();
  }

  TabsInTitlebar.allowedBy("customizing-toolbars", true);

  // Re-enable parts of the UI we disabled during the dialog
  var menubar = document.getElementById("main-menubar");
  for (let childNode of menubar.childNodes)
    childNode.setAttribute("disabled", false);
  var cmd = document.getElementById("cmd_CustomizeToolbars");
  cmd.removeAttribute("disabled");

  // make sure to re-enable click-and-hold
  if (!getBoolPref("ui.click_hold_context_menus", false))
    SetClickAndHoldHandlers();

  gBrowser.selectedBrowser.focus();
}

function BrowserToolboxCustomizeChange(aType) {
  switch (aType) {
    case "iconsize":
    case "mode":
      retrieveToolbarIconsizesFromTheme();
      break;
    default:
      gHomeButton.updatePersonalToolbarStyle();
      BookmarksMenuButton.customizeChange();
      allTabs.readPref();
  }
}

/**
 * Allows themes to override the "iconsize" attribute on toolbars.
 */
function retrieveToolbarIconsizesFromTheme() {
  function retrieveToolbarIconsize(aToolbar) {
    if (aToolbar.localName != "toolbar")
      return;

    // The theme indicates that it wants to override the "iconsize" attribute
    // by specifying a special value for the "counter-reset" property on the
    // toolbar. A custom property cannot be used because getComputedStyle can
    // only return the values of standard CSS properties.
    let counterReset = getComputedStyle(aToolbar).counterReset;
    if (counterReset == "smallicons 0")
      aToolbar.setAttribute("iconsize", "small");
    else if (counterReset == "largeicons 0")
      aToolbar.setAttribute("iconsize", "large");
  }

  Array.forEach(gNavToolbox.childNodes, retrieveToolbarIconsize);
  gNavToolbox.externalToolbars.forEach(retrieveToolbarIconsize);
}

/**
 * Update the global flag that tracks whether or not any edit UI (the Edit menu,
 * edit-related items in the context menu, and edit-related toolbar buttons
 * is visible, then update the edit commands' enabled state accordingly.  We use
 * this flag to skip updating the edit commands on focus or selection changes
 * when no UI is visible to improve performance (including pageload performance,
 * since focus changes when you load a new page).
 *
 * If UI is visible, we use goUpdateGlobalEditMenuItems to set the commands'
 * enabled state so the UI will reflect it appropriately.
 *
 * If the UI isn't visible, we enable all edit commands so keyboard shortcuts
 * still work and just lazily disable them as needed when the user presses a
 * shortcut.
 *
 * This doesn't work on Mac, since Mac menus flash when users press their
 * keyboard shortcuts, so edit UI is essentially always visible on the Mac,
 * and we need to always update the edit commands.  Thus on Mac this function
 * is a no op.
 */
function updateEditUIVisibility()
{
//@line 3744 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  let editMenuPopupState = document.getElementById("menu_EditPopup").state;
  let contextMenuPopupState = document.getElementById("contentAreaContextMenu").state;
  let placesContextMenuPopupState = document.getElementById("placesContext").state;
//@line 3748 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  let appMenuPopupState = document.getElementById("appmenu-popup").state;
//@line 3750 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

  // The UI is visible if the Edit menu is opening or open, if the context menu
  // is open, or if the toolbar has been customized to include the Cut, Copy,
  // or Paste toolbar buttons.
  gEditUIVisible = editMenuPopupState == "showing" ||
                   editMenuPopupState == "open" ||
                   contextMenuPopupState == "showing" ||
                   contextMenuPopupState == "open" ||
                   placesContextMenuPopupState == "showing" ||
                   placesContextMenuPopupState == "open" ||
//@line 3761 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
                   appMenuPopupState == "showing" ||
                   appMenuPopupState == "open" ||
//@line 3764 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
                   document.getElementById("cut-button") ||
                   document.getElementById("copy-button") ||
                   document.getElementById("paste-button") ? true : false;

  // If UI is visible, update the edit commands' enabled state to reflect
  // whether or not they are actually enabled for the current focus/selection.
  if (gEditUIVisible)
    goUpdateGlobalEditMenuItems();

  // Otherwise, enable all commands, so that keyboard shortcuts still work,
  // then lazily determine their actual enabled state when the user presses
  // a keyboard shortcut.
  else {
    goSetCommandEnabled("cmd_undo", true);
    goSetCommandEnabled("cmd_redo", true);
    goSetCommandEnabled("cmd_cut", true);
    goSetCommandEnabled("cmd_copy", true);
    goSetCommandEnabled("cmd_paste", true);
    goSetCommandEnabled("cmd_selectAll", true);
    goSetCommandEnabled("cmd_delete", true);
    goSetCommandEnabled("cmd_switchTextDirection", true);
  }
//@line 3787 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
}

/**
 * Returns true if |aMimeType| is text-based, false otherwise.
 *
 * @param aMimeType
 *        The MIME type to check.
 *
 * If adding types to this function, please also check the similar
 * function in findbar.xml
 */
function mimeTypeIsTextBased(aMimeType)
{
  return aMimeType.startsWith("text/") ||
         aMimeType.endsWith("+xml") ||
         aMimeType == "application/x-javascript" ||
         aMimeType == "application/javascript" ||
         aMimeType == "application/xml" ||
         aMimeType == "mozilla.application/cached-xul";
}

var XULBrowserWindow = {
  // Stored Status, Link and Loading values
  status: "",
  defaultStatus: "",
  jsStatus: "",
  jsDefaultStatus: "",
  overLink: "",
  startTime: 0,
  statusText: "",
  isBusy: false,
  inContentWhitelist: ["about:addons", "about:downloads", "about:permissions",
                       "about:sync-progress", "about:preferences"],

  QueryInterface: function (aIID) {
    if (aIID.equals(Ci.nsIWebProgressListener) ||
        aIID.equals(Ci.nsIWebProgressListener2) ||
        aIID.equals(Ci.nsISupportsWeakReference) ||
        aIID.equals(Ci.nsIXULBrowserWindow) ||
        aIID.equals(Ci.nsISupports))
      return this;
    throw Cr.NS_NOINTERFACE;
  },

  get stopCommand () {
    delete this.stopCommand;
    return this.stopCommand = document.getElementById("Browser:Stop");
  },
  get reloadCommand () {
    delete this.reloadCommand;
    return this.reloadCommand = document.getElementById("Browser:Reload");
  },
  get statusTextField () {
    delete this.statusTextField;
    return this.statusTextField = document.getElementById("statusbar-display");
  },
  get isImage () {
    delete this.isImage;
    return this.isImage = document.getElementById("isImage");
  },

  init: function () {
    this.throbberElement = document.getElementById("navigator-throbber");

//@line 3854 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    // Initialize the security button's state and tooltip text.  Remember to reset
    // _hostChanged, otherwise onSecurityChange will short circuit.
    var securityUI = gBrowser.securityUI;
    this._hostChanged = true;
    this.onSecurityChange(null, null, securityUI.state);
//@line 3860 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  },

  destroy: function () {
    // XXXjag to avoid leaks :-/, see bug 60729
    delete this.throbberElement;
    delete this.stopCommand;
    delete this.reloadCommand;
    delete this.statusTextField;
    delete this.statusText;
  },

  setJSStatus: function (status) {
    this.jsStatus = status;
    this.updateStatusField();
  },

  setJSDefaultStatus: function (status) {
    this.jsDefaultStatus = status;
    this.updateStatusField();
  },

  setDefaultStatus: function (status) {
    this.defaultStatus = status;
    this.updateStatusField();
  },

  setOverLink: function (url, anchorElt) {
    // Encode bidirectional formatting characters.
    // (RFC 3987 sections 3.2 and 4.1 paragraph 6)
    url = url.replace(/[\u200e\u200f\u202a\u202b\u202c\u202d\u202e]/g,
                      encodeURIComponent);

    if (gURLBar && gURLBar._mayTrimURLs /* corresponds to browser.urlbar.trimURLs */)
      url = trimURL(url);

    this.overLink = url;
    LinkTargetDisplay.update();
  },

  updateStatusField: function () {
    var text, type, types = ["overLink"];
    if (this._busyUI)
      types.push("status");
    types.push("jsStatus", "jsDefaultStatus", "defaultStatus");
    for (type of types) {
      text = this[type];
      if (text)
        break;
    }

    // check the current value so we don't trigger an attribute change
    // and cause needless (slow!) UI updates
    if (this.statusText != text) {
      let field = this.statusTextField;
      field.setAttribute("previoustype", field.getAttribute("type"));
      field.setAttribute("type", type);
      field.label = text;
      field.setAttribute("crop", type == "overLink" ? "center" : "end");
      this.statusText = text;
    }
  },

  // Called before links are navigated to to allow us to retarget them if needed.
  onBeforeLinkTraversal: function(originalTarget, linkURI, linkNode, isAppTab) {
    let target = this._onBeforeLinkTraversal(originalTarget, linkURI, linkNode, isAppTab);
    SocialUI.closeSocialPanelForLinkTraversal(target, linkNode);
    return target;
  },

  _onBeforeLinkTraversal: function(originalTarget, linkURI, linkNode, isAppTab) {
    // Don't modify non-default targets or targets that aren't in top-level app
    // tab docshells (isAppTab will be false for app tab subframes).
    if (originalTarget != "" || !isAppTab)
      return originalTarget;

    // External links from within app tabs should always open in new tabs
    // instead of replacing the app tab's page (Bug 575561)
    let linkHost;
    let docHost;
    try {
      linkHost = linkURI.host;
      docHost = linkNode.ownerDocument.documentURIObject.host;
    } catch(e) {
      // nsIURI.host can throw for non-nsStandardURL nsIURIs.
      // If we fail to get either host, just return originalTarget.
      return originalTarget;
    }

    if (docHost == linkHost)
      return originalTarget;

    // Special case: ignore "www" prefix if it is part of host string
    let [longHost, shortHost] =
      linkHost.length > docHost.length ? [linkHost, docHost] : [docHost, linkHost];
    if (longHost == "www." + shortHost)
      return originalTarget;

    return "_blank";
  },

  onProgressChange: function (aWebProgress, aRequest,
                              aCurSelfProgress, aMaxSelfProgress,
                              aCurTotalProgress, aMaxTotalProgress) {
    // Do nothing.
  },

  onProgressChange64: function (aWebProgress, aRequest,
                                aCurSelfProgress, aMaxSelfProgress,
                                aCurTotalProgress, aMaxTotalProgress) {
    return this.onProgressChange(aWebProgress, aRequest,
      aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress,
      aMaxTotalProgress);
  },

  onStateChange: function (aWebProgress, aRequest, aStateFlags, aStatus) {
    const nsIWebProgressListener = Ci.nsIWebProgressListener;
    const nsIChannel = Ci.nsIChannel;

    if (aStateFlags & nsIWebProgressListener.STATE_START &&
        aStateFlags & nsIWebProgressListener.STATE_IS_NETWORK) {

      if (aRequest && aWebProgress.DOMWindow == content)
        this.startDocumentLoad(aRequest);

      this.isBusy = true;

      if (!(aStateFlags & nsIWebProgressListener.STATE_RESTORING)) {
        this._busyUI = true;

        // Turn the throbber on.
        if (this.throbberElement)
          this.throbberElement.setAttribute("busy", "true");

        // XXX: This needs to be based on window activity...
        this.stopCommand.removeAttribute("disabled");
        CombinedStopReload.switchToStop();
      }
    }
    else if (aStateFlags & nsIWebProgressListener.STATE_STOP) {
      if (aStateFlags & nsIWebProgressListener.STATE_IS_NETWORK &&
          aWebProgress.DOMWindow == content &&
          aRequest)
        this.endDocumentLoad(aRequest, aStatus);

      // This (thanks to the filter) is a network stop or the last
      // request stop outside of loading the document, stop throbbers
      // and progress bars and such
      if (aRequest) {
        let msg = "";
        let location;
        // Get the URI either from a channel or a pseudo-object
        if (aRequest instanceof nsIChannel || "URI" in aRequest) {
          location = aRequest.URI;

          // For keyword URIs clear the user typed value since they will be changed into real URIs
          if (location.scheme == "keyword" && aWebProgress.DOMWindow == content)
            gBrowser.userTypedValue = null;

          if (location.spec != "about:blank") {
            switch (aStatus) {
              case Components.results.NS_ERROR_NET_TIMEOUT:
                msg = gNavigatorBundle.getString("nv_timeout");
                break;
            }
          }
        }

        this.status = "";
        this.setDefaultStatus(msg);

        // Disable menu entries for images, enable otherwise
        if (content.document && mimeTypeIsTextBased(content.document.contentType))
          this.isImage.removeAttribute('disabled');
        else
          this.isImage.setAttribute('disabled', 'true');
      }

      this.isBusy = false;

      if (this._busyUI) {
        this._busyUI = false;

        // Turn the throbber off.
        if (this.throbberElement)
          this.throbberElement.removeAttribute("busy");

        this.stopCommand.setAttribute("disabled", "true");
        CombinedStopReload.switchToReload(aRequest instanceof Ci.nsIRequest);
      }
    }
  },

  onLocationChange: function (aWebProgress, aRequest, aLocationURI, aFlags) {
    var location = aLocationURI ? aLocationURI.spec : "";
    this._hostChanged = true;

    // Hide the form invalid popup.
    if (gFormSubmitObserver.panel) {
      gFormSubmitObserver.panel.hidePopup();
    }

    if (document.tooltipNode) {
      // Optimise for the common case
      if (aWebProgress.DOMWindow == content) {
        document.getElementById("aHTMLTooltip").hidePopup();
        document.tooltipNode = null;
      }
      else {
        for (let tooltipWindow =
               document.tooltipNode.ownerDocument.defaultView;
             tooltipWindow != tooltipWindow.parent;
             tooltipWindow = tooltipWindow.parent) {
          if (tooltipWindow == aWebProgress.DOMWindow) {
            document.getElementById("aHTMLTooltip").hidePopup();
            document.tooltipNode = null;
            break;
          }
        }
      }
    }

    // This code here does not compare uris exactly when determining
    // whether or not the message should be hidden since the message
    // may be prematurely hidden when an install is invoked by a click
    // on a link that looks like this:
    //
    // <a href="#" onclick="return install();">Install Foo</a>
    //
    // - which fires a onLocationChange message to uri + '#'...
    var selectedBrowser = gBrowser.selectedBrowser;
    if (selectedBrowser.lastURI) {
      let oldSpec = selectedBrowser.lastURI.spec;
      let oldIndexOfHash = oldSpec.indexOf("#");
      if (oldIndexOfHash != -1)
        oldSpec = oldSpec.substr(0, oldIndexOfHash);
      let newSpec = location;
      let newIndexOfHash = newSpec.indexOf("#");
      if (newIndexOfHash != -1)
        newSpec = newSpec.substr(0, newIndexOfHash);
      if (newSpec != oldSpec) {
        // Remove all the notifications, except for those which want to
        // persist across the first location change.
        let nBox = gBrowser.getNotificationBox(selectedBrowser);
        nBox.removeTransientNotifications();
      }
    }

    // Disable menu entries for images, enable otherwise
    if (content.document && mimeTypeIsTextBased(content.document.contentType))
      this.isImage.removeAttribute('disabled');
    else
      this.isImage.setAttribute('disabled', 'true');

    this.hideOverLinkImmediately = true;
    this.setOverLink("", null);
    this.hideOverLinkImmediately = false;

    // We should probably not do this if the value has changed since the user
    // searched
    // Update urlbar only if a new page was loaded on the primary content area
    // Do not update urlbar if there was a subframe navigation

    var browser = gBrowser.selectedBrowser;
    if (aWebProgress.DOMWindow == content) {
      if ((location == "about:blank" && !content.opener) ||
          location == "") {  // Second condition is for new tabs, otherwise
                             // reload function is enabled until tab is refreshed.
        this.reloadCommand.setAttribute("disabled", "true");
      } else {
        this.reloadCommand.removeAttribute("disabled");
      }

      if (gURLBar) {
        URLBarSetURI(aLocationURI);

        // Update starring UI
        PlacesStarButton.updateState();
        SocialShareButton.updateShareState();
      }

      // Filter out anchor navigation, history.push/pop/replaceState and
      // tab switches.
      if (aRequest) {
        // Only need to call locationChange if the PopupNotifications object
        // for this window has already been initialized (i.e. its getter no
        // longer exists)
        // XXX bug 839445: We never tell PopupNotifications about location
        // changes in background tabs.
        if (!__lookupGetter__("PopupNotifications"))
          PopupNotifications.locationChange();
      }

      // Show or hide browser chrome based on the whitelist
      if (this.hideChromeForLocation(location)) {
        document.documentElement.setAttribute("disablechrome", "true");
      } else {
        let ss = Cc["@mozilla.org/browser/sessionstore;1"].getService(Ci.nsISessionStore);
        if (ss.getTabValue(gBrowser.selectedTab, "appOrigin"))
          document.documentElement.setAttribute("disablechrome", "true");
        else
          document.documentElement.removeAttribute("disablechrome");
      }

      // Utility functions for disabling find
      var shouldDisableFind = function shouldDisableFind(aDocument) {
        let docElt = aDocument.documentElement;
        return docElt && docElt.getAttribute("disablefastfind") == "true";
      }

      var disableFindCommands = function disableFindCommands(aDisable) {
        let findCommands = [document.getElementById("cmd_find"),
                            document.getElementById("cmd_findAgain"),
                            document.getElementById("cmd_findPrevious")];
        for (let elt of findCommands) {
          if (aDisable)
            elt.setAttribute("disabled", "true");
          else
            elt.removeAttribute("disabled");
        }
      }

      var onContentRSChange = function onContentRSChange(e) {
        if (e.target.readyState != "interactive" && e.target.readyState != "complete")
          return;

        e.target.removeEventListener("readystate", onContentRSChange);
        disableFindCommands(shouldDisableFind(e.target));
      }

      // Disable find commands in documents that ask for them to be disabled.
      if (aLocationURI &&
          (aLocationURI.schemeIs("about") || aLocationURI.schemeIs("chrome"))) {
        // Don't need to re-enable/disable find commands for same-document location changes
        // (e.g. the replaceStates in about:addons)
        if (!(aFlags & Ci.nsIWebProgressListener.LOCATION_CHANGE_SAME_DOCUMENT)) {
          if (content.document.readyState == "interactive" || content.document.readyState == "complete")
            disableFindCommands(shouldDisableFind(content.document));
          else {
            content.document.addEventListener("readystatechange", onContentRSChange);
          }
        }
      } else
        disableFindCommands(false);

      if (gFindBarInitialized) {
        if (gFindBar.findMode != gFindBar.FIND_NORMAL) {
          // Close the Find toolbar if we're in old-style TAF mode
          gFindBar.close();
        }

        // fix bug 253793 - turn off highlight when page changes
        gFindBar.getElement("highlight").checked = false;
      }
    }
    UpdateBackForwardCommands(gBrowser.webNavigation);

    // See bug 358202, when tabs are switched during a drag operation,
    // timers don't fire on windows (bug 203573)
    if (aRequest)
      setTimeout(function () { XULBrowserWindow.asyncUpdateUI(); }, 0);
    else
      this.asyncUpdateUI();
  },

  asyncUpdateUI: function () {
    FeedHandler.updateFeeds();
  },

  hideChromeForLocation: function(aLocation) {
    aLocation = aLocation.toLowerCase();
    return this.inContentWhitelist.some(function(aSpec) {
      return aSpec == aLocation;
    });
  },

  onStatusChange: function (aWebProgress, aRequest, aStatus, aMessage) {
    this.status = aMessage;
    this.updateStatusField();
  },

  // Properties used to cache security state used to update the UI
  _state: null,
  _hostChanged: false, // onLocationChange will flip this bit

  onSecurityChange: function (aWebProgress, aRequest, aState) {
    // Don't need to do anything if the data we use to update the UI hasn't
    // changed
    if (this._state == aState &&
        !this._hostChanged) {
//@line 4260 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
      return;
    }
    this._state = aState;

//@line 4271 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    this._hostChanged = false;

    // aState is defined as a bitmask that may be extended in the future.
    // We filter out any unknown bits before testing for known values.
    const wpl = Components.interfaces.nsIWebProgressListener;
    const wpl_security_bits = wpl.STATE_IS_SECURE |
                              wpl.STATE_IS_BROKEN |
                              wpl.STATE_IS_INSECURE;
    var level;

    switch (this._state & wpl_security_bits) {
      case wpl.STATE_IS_SECURE:
        level = "high";
        break;
      case wpl.STATE_IS_BROKEN:
        level = "broken";
        break;
    }

    if (level) {
      // We don't style the Location Bar based on the the 'level' attribute
      // anymore, but still set it for third-party themes.
      if (gURLBar)
        gURLBar.setAttribute("level", level);
    } else {
      if (gURLBar)
        gURLBar.removeAttribute("level");
    }

    // Don't pass in the actual location object, since it can cause us to
    // hold on to the window object too long.  Just pass in the fields we
    // care about. (bug 424829)
    var location = gBrowser.contentWindow.location;
    var locationObj = {};
    try {
      // about:blank can be used by webpages so pretend it is http
      locationObj.protocol = location == "about:blank" ? "http:" : location.protocol;
      locationObj.host = location.host;
      locationObj.hostname = location.hostname;
      locationObj.port = location.port;
    } catch (ex) {
      // Can sometimes throw if the URL being visited has no host/hostname,
      // e.g. about:blank. The _state for these pages means we won't need these
      // properties anyways, though.
    }
    gIdentityHandler.checkIdentity(this._state, locationObj);
  },

  // simulate all change notifications after switching tabs
  onUpdateCurrentBrowser: function XWB_onUpdateCurrentBrowser(aStateFlags, aStatus, aMessage, aTotalProgress) {
    if (FullZoom.updateBackgroundTabs)
      FullZoom.onLocationChange(gBrowser.currentURI, true);
    var nsIWebProgressListener = Components.interfaces.nsIWebProgressListener;
    var loadingDone = aStateFlags & nsIWebProgressListener.STATE_STOP;
    // use a pseudo-object instead of a (potentially nonexistent) channel for getting
    // a correct error message - and make sure that the UI is always either in
    // loading (STATE_START) or done (STATE_STOP) mode
    this.onStateChange(
      gBrowser.webProgress,
      { URI: gBrowser.currentURI },
      loadingDone ? nsIWebProgressListener.STATE_STOP : nsIWebProgressListener.STATE_START,
      aStatus
    );
    // status message and progress value are undefined if we're done with loading
    if (loadingDone)
      return;
    this.onStatusChange(gBrowser.webProgress, null, 0, aMessage);
  },

  startDocumentLoad: function XWB_startDocumentLoad(aRequest) {
    // clear out feed data
    gBrowser.selectedBrowser.feeds = null;

    // clear out search-engine data
    gBrowser.selectedBrowser.engines = null;

    var uri = aRequest.QueryInterface(Ci.nsIChannel).URI;
    try {
      Services.obs.notifyObservers(content, "StartDocumentLoad", uri.spec);
    } catch (e) {
    }
  },

  endDocumentLoad: function XWB_endDocumentLoad(aRequest, aStatus) {
    var urlStr = aRequest.QueryInterface(Ci.nsIChannel).originalURI.spec;

    var notification = Components.isSuccessCode(aStatus) ? "EndDocumentLoad" : "FailDocumentLoad";
    try {
      Services.obs.notifyObservers(content, notification, urlStr);
    } catch (e) {
    }
  }
};

var LinkTargetDisplay = {
  get DELAY_SHOW() {
     delete this.DELAY_SHOW;
     return this.DELAY_SHOW = Services.prefs.getIntPref("browser.overlink-delay");
  },

  DELAY_HIDE: 250,
  _timer: 0,

  get _isVisible () XULBrowserWindow.statusTextField.label != "",

  update: function () {
    clearTimeout(this._timer);
    window.removeEventListener("mousemove", this, true);

    if (!XULBrowserWindow.overLink) {
      if (XULBrowserWindow.hideOverLinkImmediately)
        this._hide();
      else
        this._timer = setTimeout(this._hide.bind(this), this.DELAY_HIDE);
      return;
    }

    if (this._isVisible) {
      XULBrowserWindow.updateStatusField();
    } else {
      // Let the display appear when the mouse doesn't move within the delay
      this._showDelayed();
      window.addEventListener("mousemove", this, true);
    }
  },

  handleEvent: function (event) {
    switch (event.type) {
      case "mousemove":
        // Restart the delay since the mouse was moved
        clearTimeout(this._timer);
        this._showDelayed();
        break;
    }
  },

  _showDelayed: function () {
    this._timer = setTimeout(function (self) {
      XULBrowserWindow.updateStatusField();
      window.removeEventListener("mousemove", self, true);
    }, this.DELAY_SHOW, this);
  },

  _hide: function () {
    clearTimeout(this._timer);

    XULBrowserWindow.updateStatusField();
  }
};

var CombinedStopReload = {
  init: function () {
    if (this._initialized)
      return;

    var urlbar = document.getElementById("urlbar-container");
    var reload = document.getElementById("reload-button");
    var stop = document.getElementById("stop-button");

    if (urlbar) {
      if (urlbar.parentNode.getAttribute("mode") != "icons" ||
          !reload || urlbar.nextSibling != reload ||
          !stop || reload.nextSibling != stop)
        urlbar.removeAttribute("combined");
      else {
        urlbar.setAttribute("combined", "true");
        reload = document.getElementById("urlbar-reload-button");
        stop = document.getElementById("urlbar-stop-button");
      }
    }
    if (!stop || !reload || reload.nextSibling != stop)
      return;

    this._initialized = true;
    if (XULBrowserWindow.stopCommand.getAttribute("disabled") != "true")
      reload.setAttribute("displaystop", "true");
    stop.addEventListener("click", this, false);
    this.reload = reload;
    this.stop = stop;
  },

  uninit: function () {
    if (!this._initialized)
      return;

    this._cancelTransition();
    this._initialized = false;
    this.stop.removeEventListener("click", this, false);
    this.reload = null;
    this.stop = null;
  },

  handleEvent: function (event) {
    // the only event we listen to is "click" on the stop button
    if (event.button == 0 &&
        !this.stop.disabled)
      this._stopClicked = true;
  },

  switchToStop: function () {
    if (!this._initialized)
      return;

    this._cancelTransition();
    this.reload.setAttribute("displaystop", "true");
  },

  switchToReload: function (aDelay) {
    if (!this._initialized)
      return;

    this.reload.removeAttribute("displaystop");

    if (!aDelay || this._stopClicked) {
      this._stopClicked = false;
      this._cancelTransition();
      this.reload.disabled = XULBrowserWindow.reloadCommand
                                             .getAttribute("disabled") == "true";
      return;
    }

    if (this._timer)
      return;

    // Temporarily disable the reload button to prevent the user from
    // accidentally reloading the page when intending to click the stop button
    this.reload.disabled = true;
    this._timer = setTimeout(function (self) {
      self._timer = 0;
      self.reload.disabled = XULBrowserWindow.reloadCommand
                                             .getAttribute("disabled") == "true";
    }, 650, this);
  },

  _cancelTransition: function () {
    if (this._timer) {
      clearTimeout(this._timer);
      this._timer = 0;
    }
  }
};

var TabsProgressListener = {
  onStateChange: function (aBrowser, aWebProgress, aRequest, aStateFlags, aStatus) {
//@line 4517 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    if (aRequest instanceof Ci.nsIChannel &&
        aStateFlags & Ci.nsIWebProgressListener.STATE_START &&
        aStateFlags & Ci.nsIWebProgressListener.STATE_IS_DOCUMENT &&
        gCrashReporter.enabled) {
      gCrashReporter.annotateCrashReport("URL", aRequest.URI.spec);
    }
//@line 4524 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    // Collect telemetry data about tab load times.
    if (aWebProgress.DOMWindow == aWebProgress.DOMWindow.top &&
        aStateFlags & Ci.nsIWebProgressListener.STATE_IS_WINDOW) {
      if (aStateFlags & Ci.nsIWebProgressListener.STATE_START)
        TelemetryStopwatch.start("FX_PAGE_LOAD_MS", aBrowser);
      else if (aStateFlags & Ci.nsIWebProgressListener.STATE_STOP)
        TelemetryStopwatch.finish("FX_PAGE_LOAD_MS", aBrowser);
    }

    // Attach a listener to watch for "click" events bubbling up from error
    // pages and other similar page. This lets us fix bugs like 401575 which
    // require error page UI to do privileged things, without letting error
    // pages have any privilege themselves.
    // We can't look for this during onLocationChange since at that point the
    // document URI is not yet the about:-uri of the error page.

    if (aStateFlags & Ci.nsIWebProgressListener.STATE_STOP &&
        Components.isSuccessCode(aStatus) &&
        aWebProgress.DOMWindow.document.documentURI.startsWith("about:")) {
      aBrowser.addEventListener("click", BrowserOnClick, true);
      aBrowser.addEventListener("pagehide", function onPageHide(event) {
        if (event.target.defaultView.frameElement)
          return;
        aBrowser.removeEventListener("click", BrowserOnClick, true);
        aBrowser.removeEventListener("pagehide", onPageHide, true);
      }, true);

      // We also want to make changes to page UI for unprivileged about pages.
      BrowserOnAboutPageLoad(aWebProgress.DOMWindow.document);
    }
  },

  onLocationChange: function (aBrowser, aWebProgress, aRequest, aLocationURI,
                              aFlags) {
    // Filter out any sub-frame loads
    if (aBrowser.contentWindow == aWebProgress.DOMWindow) {
      // Filter out any onLocationChanges triggered by anchor navigation
      // or history.push/pop/replaceState.
      if (aRequest) {
        // Initialize the click-to-play state.
        aBrowser._clickToPlayPluginsActivated = new Map();
        aBrowser._clickToPlayAllPluginsActivated = false;
        aBrowser._pluginScriptedState = gPluginHandler.PLUGIN_SCRIPTED_STATE_NONE;
      }
      FullZoom.onLocationChange(aLocationURI, false, aBrowser);
    }
  },

  onRefreshAttempted: function (aBrowser, aWebProgress, aURI, aDelay, aSameURI) {
    if (gPrefService.getBoolPref("accessibility.blockautorefresh")) {
      let brandBundle = document.getElementById("bundle_brand");
      let brandShortName = brandBundle.getString("brandShortName");
      let refreshButtonText =
        gNavigatorBundle.getString("refreshBlocked.goButton");
      let refreshButtonAccesskey =
        gNavigatorBundle.getString("refreshBlocked.goButton.accesskey");
      let message =
        gNavigatorBundle.getFormattedString(aSameURI ? "refreshBlocked.refreshLabel"
                                                     : "refreshBlocked.redirectLabel",
                                            [brandShortName]);
      let docShell = aWebProgress.DOMWindow
                                 .QueryInterface(Ci.nsIInterfaceRequestor)
                                 .getInterface(Ci.nsIWebNavigation)
                                 .QueryInterface(Ci.nsIDocShell);
      let notificationBox = gBrowser.getNotificationBox(aBrowser);
      let notification = notificationBox.getNotificationWithValue("refresh-blocked");
      if (notification) {
        notification.label = message;
        notification.refreshURI = aURI;
        notification.delay = aDelay;
        notification.docShell = docShell;
      } else {
        let buttons = [{
          label: refreshButtonText,
          accessKey: refreshButtonAccesskey,
          callback: function (aNotification, aButton) {
            var refreshURI = aNotification.docShell
                                          .QueryInterface(Ci.nsIRefreshURI);
            refreshURI.forceRefreshURI(aNotification.refreshURI,
                                       aNotification.delay, true);
          }
        }];
        notification =
          notificationBox.appendNotification(message, "refresh-blocked",
                                             "chrome://browser/skin/Info.png",
                                             notificationBox.PRIORITY_INFO_MEDIUM,
                                             buttons);
        notification.refreshURI = aURI;
        notification.delay = aDelay;
        notification.docShell = docShell;
      }
      return false;
    }
    return true;
  }
}

function nsBrowserAccess() { }

nsBrowserAccess.prototype = {
  QueryInterface: XPCOMUtils.generateQI([Ci.nsIBrowserDOMWindow, Ci.nsISupports]),

  openURI: function (aURI, aOpener, aWhere, aContext) {
    var newWindow = null;
    var isExternal = (aContext == Ci.nsIBrowserDOMWindow.OPEN_EXTERNAL);

    if (isExternal && aURI && aURI.schemeIs("chrome")) {
      dump("use -chrome command-line option to load external chrome urls\n");
      return null;
    }

    if (aWhere == Ci.nsIBrowserDOMWindow.OPEN_DEFAULTWINDOW) {
      if (isExternal &&
          gPrefService.prefHasUserValue("browser.link.open_newwindow.override.external"))
        aWhere = gPrefService.getIntPref("browser.link.open_newwindow.override.external");
      else
        aWhere = gPrefService.getIntPref("browser.link.open_newwindow");
    }
    switch (aWhere) {
      case Ci.nsIBrowserDOMWindow.OPEN_NEWWINDOW :
        // FIXME: Bug 408379. So how come this doesn't send the
        // referrer like the other loads do?
        var url = aURI ? aURI.spec : "about:blank";
        // Pass all params to openDialog to ensure that "url" isn't passed through
        // loadOneOrMoreURIs, which splits based on "|"
        newWindow = openDialog(getBrowserURL(), "_blank", "all,dialog=no", url, null, null, null);
        break;
      case Ci.nsIBrowserDOMWindow.OPEN_NEWTAB :
        let win, needToFocusWin;

        // try the current window.  if we're in a popup, fall back on the most recent browser window
        if (window.toolbar.visible)
          win = window;
        else {
          let isPrivate = PrivateBrowsingUtils.isWindowPrivate(aOpener || window);
          win = RecentWindow.getMostRecentBrowserWindow({private: isPrivate});
          needToFocusWin = true;
        }

        if (!win) {
          // we couldn't find a suitable window, a new one needs to be opened.
          return null;
        }

        if (isExternal && (!aURI || aURI.spec == "about:blank")) {
          win.BrowserOpenTab(); // this also focuses the location bar
          win.focus();
          newWindow = win.content;
          break;
        }

        let loadInBackground = gPrefService.getBoolPref("browser.tabs.loadDivertedInBackground");
        let referrer = aOpener ? makeURI(aOpener.location.href) : null;

        let tab = win.gBrowser.loadOneTab(aURI ? aURI.spec : "about:blank", {
                                          referrerURI: referrer,
                                          fromExternal: isExternal,
                                          inBackground: loadInBackground});
        let browser = win.gBrowser.getBrowserForTab(tab);

        newWindow = browser.contentWindow;
        if (needToFocusWin || (!loadInBackground && isExternal))
          newWindow.focus();
        break;
      default : // OPEN_CURRENTWINDOW or an illegal value
        newWindow = content;
        if (aURI) {
          let referrer = aOpener ? makeURI(aOpener.location.href) : null;
          let loadflags = isExternal ?
                            Ci.nsIWebNavigation.LOAD_FLAGS_FROM_EXTERNAL :
                            Ci.nsIWebNavigation.LOAD_FLAGS_NONE;
          gBrowser.loadURIWithFlags(aURI.spec, loadflags, referrer, null, null);
        }
        if (!gPrefService.getBoolPref("browser.tabs.loadDivertedInBackground"))
          window.focus();
    }
    return newWindow;
  },

  isTabContentWindow: function (aWindow) {
    return gBrowser.browsers.some(function (browser) browser.contentWindow == aWindow);
  }
}

function onViewToolbarsPopupShowing(aEvent, aInsertPoint) {
  var popup = aEvent.target;
  if (popup != aEvent.currentTarget)
    return;

  // Empty the menu
  for (var i = popup.childNodes.length-1; i >= 0; --i) {
    var deadItem = popup.childNodes[i];
    if (deadItem.hasAttribute("toolbarId"))
      popup.removeChild(deadItem);
  }

  var firstMenuItem = aInsertPoint || popup.firstChild;

  let toolbarNodes = Array.slice(gNavToolbox.childNodes);
  toolbarNodes.push(document.getElementById("addon-bar"));

  for (let toolbar of toolbarNodes) {
    let toolbarName = toolbar.getAttribute("toolbarname");
    if (toolbarName) {
      let menuItem = document.createElement("menuitem");
      let hidingAttribute = toolbar.getAttribute("type") == "menubar" ?
                            "autohide" : "collapsed";
      menuItem.setAttribute("id", "toggle_" + toolbar.id);
      menuItem.setAttribute("toolbarId", toolbar.id);
      menuItem.setAttribute("type", "checkbox");
      menuItem.setAttribute("label", toolbarName);
      menuItem.setAttribute("checked", toolbar.getAttribute(hidingAttribute) != "true");
      if (popup.id != "appmenu_customizeMenu")
        menuItem.setAttribute("accesskey", toolbar.getAttribute("accesskey"));
      if (popup.id != "toolbar-context-menu")
        menuItem.setAttribute("key", toolbar.getAttribute("key"));

      popup.insertBefore(menuItem, firstMenuItem);

      menuItem.addEventListener("command", onViewToolbarCommand, false);
    }
  }
}

function onViewToolbarCommand(aEvent) {
  var toolbarId = aEvent.originalTarget.getAttribute("toolbarId");
  var toolbar = document.getElementById(toolbarId);
  var isVisible = aEvent.originalTarget.getAttribute("checked") == "true";
  setToolbarVisibility(toolbar, isVisible);
}

function setToolbarVisibility(toolbar, isVisible) {
  var hidingAttribute = toolbar.getAttribute("type") == "menubar" ?
                        "autohide" : "collapsed";

  toolbar.setAttribute(hidingAttribute, !isVisible);
  document.persist(toolbar.id, hidingAttribute);

  PlacesToolbarHelper.init();
  BookmarksMenuButton.updatePosition();
  gBrowser.updateWindowResizers();

//@line 4768 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  updateAppButtonDisplay();
//@line 4770 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
}

var TabsOnTop = {
  init: function TabsOnTop_init() {
    Services.prefs.addObserver(this._prefName, this, false);

    // Only show the toggle UI if the user disabled tabs on top.
    if (Services.prefs.getBoolPref(this._prefName)) {
      for (let item of document.querySelectorAll("menuitem[command=cmd_ToggleTabsOnTop]"))
        item.parentNode.removeChild(item);
    }
  },

  uninit: function TabsOnTop_uninit() {
    Services.prefs.removeObserver(this._prefName, this);
  },

  toggle: function () {
    this.enabled = !Services.prefs.getBoolPref(this._prefName);
  },

  syncUI: function () {
    let userEnabled = Services.prefs.getBoolPref(this._prefName);
    let enabled = userEnabled && gBrowser.tabContainer.visible;

    document.getElementById("cmd_ToggleTabsOnTop")
            .setAttribute("checked", userEnabled);

    document.documentElement.setAttribute("tabsontop", enabled);
    document.getElementById("navigator-toolbox").setAttribute("tabsontop", enabled);
    document.getElementById("TabsToolbar").setAttribute("tabsontop", enabled);
    document.getElementById("nav-bar").setAttribute("tabsontop", enabled);
    gBrowser.tabContainer.setAttribute("tabsontop", enabled);
    TabsInTitlebar.allowedBy("tabs-on-top", enabled);
  },

  get enabled () {
    return gNavToolbox.getAttribute("tabsontop") == "true";
  },

  set enabled (val) {
    Services.prefs.setBoolPref(this._prefName, !!val);
    return val;
  },

  observe: function (subject, topic, data) {
    if (topic == "nsPref:changed")
      this.syncUI();
  },

  _prefName: "browser.tabs.onTop"
}

var TabsInTitlebar = {
  init: function () {
//@line 4835 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  },

  allowedBy: function (condition, allow) {
//@line 4851 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  },

  get enabled() {
    return document.documentElement.getAttribute("tabsintitlebar") == "true";
  },

//@line 4925 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

  uninit: function () {
//@line 4931 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  }
};

//@line 4935 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
function updateAppButtonDisplay() {
  var displayAppButton =
    !gInPrintPreviewMode &&
    window.menubar.visible &&
    document.getElementById("toolbar-menubar").getAttribute("autohide") == "true";

//@line 4951 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  document.getElementById("appmenu-toolbar-button").hidden =
    !displayAppButton;
//@line 4954 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
}
//@line 4956 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

//@line 4965 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

function displaySecurityInfo()
{
  BrowserPageInfo(null, "securityTab");
}

/**
 * Opens or closes the sidebar identified by commandID.
 *
 * @param commandID a string identifying the sidebar to toggle; see the
 *                  note below. (Optional if a sidebar is already open.)
 * @param forceOpen boolean indicating whether the sidebar should be
 *                  opened regardless of its current state (optional).
 * @note
 * We expect to find a xul:broadcaster element with the specified ID.
 * The following attributes on that element may be used and/or modified:
 *  - id           (required) the string to match commandID. The convention
 *                 is to use this naming scheme: 'view<sidebar-name>Sidebar'.
 *  - sidebarurl   (required) specifies the URL to load in this sidebar.
 *  - sidebartitle or label (in that order) specify the title to
 *                 display on the sidebar.
 *  - checked      indicates whether the sidebar is currently displayed.
 *                 Note that toggleSidebar updates this attribute when
 *                 it changes the sidebar's visibility.
 *  - group        this attribute must be set to "sidebar".
 */
function toggleSidebar(commandID, forceOpen) {

  var sidebarBox = document.getElementById("sidebar-box");
  if (!commandID)
    commandID = sidebarBox.getAttribute("sidebarcommand");

  var sidebarBroadcaster = document.getElementById(commandID);
  var sidebar = document.getElementById("sidebar"); // xul:browser
  var sidebarTitle = document.getElementById("sidebar-title");
  var sidebarSplitter = document.getElementById("sidebar-splitter");

  if (sidebarBroadcaster.getAttribute("checked") == "true") {
    if (!forceOpen) {
      // Replace the document currently displayed in the sidebar with about:blank
      // so that we can free memory by unloading the page. We need to explicitly
      // create a new content viewer because the old one doesn't get destroyed
      // until about:blank has loaded (which does not happen as long as the
      // element is hidden).
      sidebar.setAttribute("src", "about:blank");
      sidebar.docShell.createAboutBlankContentViewer(null);

      sidebarBroadcaster.removeAttribute("checked");
      sidebarBox.setAttribute("sidebarcommand", "");
      sidebarTitle.value = "";
      sidebarBox.hidden = true;
      sidebarSplitter.hidden = true;
      gBrowser.selectedBrowser.focus();
    } else {
      fireSidebarFocusedEvent();
    }
    return;
  }

  // now we need to show the specified sidebar

  // ..but first update the 'checked' state of all sidebar broadcasters
  var broadcasters = document.getElementsByAttribute("group", "sidebar");
  for (let broadcaster of broadcasters) {
    // skip elements that observe sidebar broadcasters and random
    // other elements
    if (broadcaster.localName != "broadcaster")
      continue;

    if (broadcaster != sidebarBroadcaster)
      broadcaster.removeAttribute("checked");
    else
      sidebarBroadcaster.setAttribute("checked", "true");
  }

  sidebarBox.hidden = false;
  sidebarSplitter.hidden = false;

  var url = sidebarBroadcaster.getAttribute("sidebarurl");
  var title = sidebarBroadcaster.getAttribute("sidebartitle");
  if (!title)
    title = sidebarBroadcaster.getAttribute("label");
  sidebar.setAttribute("src", url); // kick off async load
  sidebarBox.setAttribute("sidebarcommand", sidebarBroadcaster.id);
  sidebarTitle.value = title;

  // We set this attribute here in addition to setting it on the <browser>
  // element itself, because the code in gBrowserInit.onUnload persists this
  // attribute, not the "src" of the <browser id="sidebar">. The reason it
  // does that is that we want to delay sidebar load a bit when a browser
  // window opens. See delayedStartup().
  sidebarBox.setAttribute("src", url);

  if (sidebar.contentDocument.location.href != url)
    sidebar.addEventListener("load", sidebarOnLoad, true);
  else // older code handled this case, so we do it too
    fireSidebarFocusedEvent();
}

function sidebarOnLoad(event) {
  var sidebar = document.getElementById("sidebar");
  sidebar.removeEventListener("load", sidebarOnLoad, true);
  // We're handling the 'load' event before it bubbles up to the usual
  // (non-capturing) event handlers. Let it bubble up before firing the
  // SidebarFocused event.
  setTimeout(fireSidebarFocusedEvent, 0);
}

/**
 * Fire a "SidebarFocused" event on the sidebar's |window| to give the sidebar
 * a chance to adjust focus as needed. An additional event is needed, because
 * we don't want to focus the sidebar when it's opened on startup or in a new
 * window, only when the user opens the sidebar.
 */
function fireSidebarFocusedEvent() {
  var sidebar = document.getElementById("sidebar");
  var event = document.createEvent("Events");
  event.initEvent("SidebarFocused", true, false);
  sidebar.contentWindow.dispatchEvent(event);
}

var gHomeButton = {
  prefDomain: "browser.startup.homepage",
  observe: function (aSubject, aTopic, aPrefName)
  {
    if (aTopic != "nsPref:changed" || aPrefName != this.prefDomain)
      return;

    this.updateTooltip();
  },

  updateTooltip: function (homeButton)
  {
    if (!homeButton)
      homeButton = document.getElementById("home-button");
    if (homeButton) {
      var homePage = this.getHomePage();
      homePage = homePage.replace(/\|/g,', ');
      if (homePage.toLowerCase() == "about:home")
        homeButton.setAttribute("tooltiptext", homeButton.getAttribute("aboutHomeOverrideTooltip"));
      else
        homeButton.setAttribute("tooltiptext", homePage);
    }
  },

  getHomePage: function ()
  {
    var url;
    try {
      url = gPrefService.getComplexValue(this.prefDomain,
                                Components.interfaces.nsIPrefLocalizedString).data;
    } catch (e) {
    }

    // use this if we can't find the pref
    if (!url) {
      var configBundle = Services.strings
                                 .createBundle("chrome://branding/locale/browserconfig.properties");
      url = configBundle.GetStringFromName(this.prefDomain);
    }

    return url;
  },

  updatePersonalToolbarStyle: function (homeButton)
  {
    if (!homeButton)
      homeButton = document.getElementById("home-button");
    if (homeButton)
      homeButton.className = homeButton.parentNode.id == "PersonalToolbar"
                               || homeButton.parentNode.parentNode.id == "PersonalToolbar" ?
                             homeButton.className.replace("toolbarbutton-1", "bookmark-item") :
                             homeButton.className.replace("bookmark-item", "toolbarbutton-1");
  }
};

/**
 * Gets the selected text in the active browser. Leading and trailing
 * whitespace is removed, and consecutive whitespace is replaced by a single
 * space. A maximum of 150 characters will be returned, regardless of the value
 * of aCharLen.
 *
 * @param aCharLen
 *        The maximum number of characters to return.
 */
function getBrowserSelection(aCharLen) {
  // selections of more than 150 characters aren't useful
  const kMaxSelectionLen = 150;
  const charLen = Math.min(aCharLen || kMaxSelectionLen, kMaxSelectionLen);
  let commandDispatcher = document.commandDispatcher;

  var focusedWindow = commandDispatcher.focusedWindow;
  var selection = focusedWindow.getSelection().toString();
  // try getting a selected text in text input.
  if (!selection) {
    let element = commandDispatcher.focusedElement;
    var isOnTextInput = function isOnTextInput(elem) {
      // we avoid to return a value if a selection is in password field.
      // ref. bug 565717
      return elem instanceof HTMLTextAreaElement ||
             (elem instanceof HTMLInputElement && elem.mozIsTextField(true));
    };

    if (isOnTextInput(element)) {
      selection = element.QueryInterface(Ci.nsIDOMNSEditableElement)
                         .editor.selection.toString();
    }
  }

  if (selection) {
    if (selection.length > charLen) {
      // only use the first charLen important chars. see bug 221361
      var pattern = new RegExp("^(?:\\s*.){0," + charLen + "}");
      pattern.test(selection);
      selection = RegExp.lastMatch;
    }

    selection = selection.trim().replace(/\s+/g, " ");

    if (selection.length > charLen)
      selection = selection.substr(0, charLen);
  }
  return selection;
}

var gWebPanelURI;
function openWebPanel(aTitle, aURI)
{
    // Ensure that the web panels sidebar is open.
    toggleSidebar('viewWebPanelsSidebar', true);

    // Set the title of the panel.
    document.getElementById("sidebar-title").value = aTitle;

    // Tell the Web Panels sidebar to load the bookmark.
    var sidebar = document.getElementById("sidebar");
    if (sidebar.docShell && sidebar.contentDocument && sidebar.contentDocument.getElementById('web-panels-browser')) {
        sidebar.contentWindow.loadWebPanel(aURI);
        if (gWebPanelURI) {
            gWebPanelURI = "";
            sidebar.removeEventListener("load", asyncOpenWebPanel, true);
        }
    }
    else {
        // The panel is still being constructed.  Attach an onload handler.
        if (!gWebPanelURI)
            sidebar.addEventListener("load", asyncOpenWebPanel, true);
        gWebPanelURI = aURI;
    }
}

function asyncOpenWebPanel(event)
{
    var sidebar = document.getElementById("sidebar");
    if (gWebPanelURI && sidebar.contentDocument && sidebar.contentDocument.getElementById('web-panels-browser'))
        sidebar.contentWindow.loadWebPanel(gWebPanelURI);
    gWebPanelURI = "";
    sidebar.removeEventListener("load", asyncOpenWebPanel, true);
}

/*
 * - [ Dependencies ] ---------------------------------------------------------
 *  utilityOverlay.js:
 *    - gatherTextUnder
 */

/**
 * Extracts linkNode and href for the current click target.
 *
 * @param event
 *        The click event.
 * @return [href, linkNode].
 *
 * @note linkNode will be null if the click wasn't on an anchor
 *       element (or XLink).
 */
function hrefAndLinkNodeForClickEvent(event)
{
  function isHTMLLink(aNode)
  {
    // Be consistent with what nsContextMenu.js does.
    return ((aNode instanceof HTMLAnchorElement && aNode.href) ||
            (aNode instanceof HTMLAreaElement && aNode.href) ||
            aNode instanceof HTMLLinkElement);
  }

  let node = event.target;
  while (node && !isHTMLLink(node)) {
    node = node.parentNode;
  }

  if (node)
    return [node.href, node];

  // If there is no linkNode, try simple XLink.
  let href, baseURI;
  node = event.target;
  while (node && !href) {
    if (node.nodeType == Node.ELEMENT_NODE) {
      href = node.getAttributeNS("http://www.w3.org/1999/xlink", "href");
      if (href)
        baseURI = node.baseURI;
    }
    node = node.parentNode;
  }

  // In case of XLink, we don't return the node we got href from since
  // callers expect <a>-like elements.
  return [href ? makeURLAbsolute(baseURI, href) : null, null];
}

/**
 * Called whenever the user clicks in the content area.
 *
 * @param event
 *        The click event.
 * @param isPanelClick
 *        Whether the event comes from a web panel.
 * @note default event is prevented if the click is handled.
 */
function contentAreaClick(event, isPanelClick)
{
  if (!event.isTrusted || event.defaultPrevented || event.button == 2)
    return;

  let [href, linkNode] = hrefAndLinkNodeForClickEvent(event);
  if (!href) {
    // Not a link, handle middle mouse navigation.
    if (event.button == 1 &&
        gPrefService.getBoolPref("middlemouse.contentLoadURL") &&
        !gPrefService.getBoolPref("general.autoScroll")) {
      middleMousePaste(event);
      event.preventDefault();
    }
    return;
  }

  // This code only applies if we have a linkNode (i.e. clicks on real anchor
  // elements, as opposed to XLink).
  if (linkNode && event.button == 0 &&
      !event.ctrlKey && !event.shiftKey && !event.altKey && !event.metaKey) {
    // A Web panel's links should target the main content area.  Do this
    // if no modifier keys are down and if there's no target or the target
    // equals _main (the IE convention) or _content (the Mozilla convention).
    let target = linkNode.target;
    let mainTarget = !target || target == "_content" || target  == "_main";
    if (isPanelClick && mainTarget) {
      // javascript and data links should be executed in the current browser.
      if (linkNode.getAttribute("onclick") ||
          href.startsWith("javascript:") ||
          href.startsWith("data:"))
        return;

      try {
        urlSecurityCheck(href, linkNode.ownerDocument.nodePrincipal);
      }
      catch(ex) {
        // Prevent loading unsecure destinations.
        event.preventDefault();
        return;
      }

      loadURI(href, null, null, false);
      event.preventDefault();
      return;
    }

    if (linkNode.getAttribute("rel") == "sidebar") {
      // This is the Opera convention for a special link that, when clicked,
      // allows to add a sidebar panel.  The link's title attribute contains
      // the title that should be used for the sidebar panel.
      PlacesUIUtils.showBookmarkDialog({ action: "add"
                                       , type: "bookmark"
                                       , uri: makeURI(href)
                                       , title: linkNode.getAttribute("title")
                                       , loadBookmarkInSidebar: true
                                       , hiddenRows: [ "description"
                                                     , "location"
                                                     , "keyword" ]
                                       }, window);
      event.preventDefault();
      return;
    }
  }

  handleLinkClick(event, href, linkNode);

  // Mark the page as a user followed link.  This is done so that history can
  // distinguish automatic embed visits from user activated ones.  For example
  // pages loaded in frames are embed visits and lost with the session, while
  // visits across frames should be preserved.
  try {
    if (!PrivateBrowsingUtils.isWindowPrivate(window))
      PlacesUIUtils.markPageAsFollowedLink(href);
  } catch (ex) { /* Skip invalid URIs. */ }
}

/**
 * Handles clicks on links.
 *
 * @return true if the click event was handled, false otherwise.
 */
function handleLinkClick(event, href, linkNode) {
  if (event.button == 2) // right click
    return false;

  var where = whereToOpenLink(event);
  if (where == "current")
    return false;

  var doc = event.target.ownerDocument;

  if (where == "save") {
    saveURL(href, linkNode ? gatherTextUnder(linkNode) : "", null, true,
            true, doc.documentURIObject, doc);
    event.preventDefault();
    return true;
  }

  urlSecurityCheck(href, doc.nodePrincipal);
  openLinkIn(href, where, { referrerURI: doc.documentURIObject,
                            charset: doc.characterSet });
  event.preventDefault();
  return true;
}

function middleMousePaste(event) {
  let clipboard = readFromClipboard();
  if (!clipboard)
    return;

  // Strip embedded newlines and surrounding whitespace, to match the URL
  // bar's behavior (stripsurroundingwhitespace)
  clipboard = clipboard.replace(/\s*\n\s*/g, "");

  let mayInheritPrincipal = { value: false };
  let url = getShortcutOrURI(clipboard, mayInheritPrincipal);
  try {
    makeURI(url);
  } catch (ex) {
    // Not a valid URI.
    return;
  }

  try {
    addToUrlbarHistory(url);
  } catch (ex) {
    // Things may go wrong when adding url to session history,
    // but don't let that interfere with the loading of the url.
    Cu.reportError(ex);
  }

  openUILink(url, event,
             { ignoreButton: true,
               disallowInheritPrincipal: !mayInheritPrincipal.value });

  event.stopPropagation();
}

function handleDroppedLink(event, url, name)
{
  let postData = { };
  let uri = getShortcutOrURI(url, postData);
  if (uri)
    loadURI(uri, null, postData.value, false);

  // Keep the event from being handled by the dragDrop listeners
  // built-in to gecko if they happen to be above us.
  event.preventDefault();
};

function MultiplexHandler(event)
{ try {
    var node = event.target;
    var name = node.getAttribute('name');

    if (name == 'detectorGroup') {
        BrowserCharsetReload();
        SelectDetector(event, false);
    } else if (name == 'charsetGroup') {
        var charset = node.getAttribute('id');
        charset = charset.substring('charset.'.length, charset.length)
        BrowserSetForcedCharacterSet(charset);
    } else if (name == 'charsetCustomize') {
        //do nothing - please remove this else statement, once the charset prefs moves to the pref window
    } else {
        BrowserSetForcedCharacterSet(node.getAttribute('id'));
    }
    } catch(ex) { alert(ex); }
}

function SelectDetector(event, doReload)
{
    var uri =  event.target.getAttribute("id");
    var prefvalue = uri.substring('chardet.'.length, uri.length);
    if ("off" == prefvalue) { // "off" is special value to turn off the detectors
        prefvalue = "";
    }

    try {
        var str =  Cc["@mozilla.org/supports-string;1"].
                   createInstance(Ci.nsISupportsString);

        str.data = prefvalue;
        gPrefService.setComplexValue("intl.charset.detector", Ci.nsISupportsString, str);
        if (doReload)
          window.content.location.reload();
    }
    catch (ex) {
        dump("Failed to set the intl.charset.detector preference.\n");
    }
}

function BrowserSetForcedCharacterSet(aCharset)
{
  gBrowser.docShell.charset = aCharset;
  // Save the forced character-set
  if (!PrivateBrowsingUtils.isWindowPrivate(window))
    PlacesUtils.history.setCharsetForURI(getWebNavigation().currentURI, aCharset);
  BrowserCharsetReload();
}

function BrowserCharsetReload()
{
  BrowserReloadWithFlags(nsIWebNavigation.LOAD_FLAGS_CHARSET_CHANGE);
}

function charsetMenuGetElement(parent, id) {
  return parent.getElementsByAttribute("id", id)[0];
}

function UpdateCurrentCharset(target) {
    // extract the charset from DOM
    var wnd = document.commandDispatcher.focusedWindow;
    if ((window == wnd) || (wnd == null)) wnd = window.content;

    // Uncheck previous item
    if (gPrevCharset) {
        var pref_item = charsetMenuGetElement(target, "charset." + gPrevCharset);
        if (pref_item)
          pref_item.setAttribute('checked', 'false');
    }

    var menuitem = charsetMenuGetElement(target, "charset." + wnd.document.characterSet);
    if (menuitem) {
        menuitem.setAttribute('checked', 'true');
    }
}

function UpdateCharsetDetector(target) {
  var prefvalue;

  try {
    prefvalue = gPrefService.getComplexValue("intl.charset.detector", Ci.nsIPrefLocalizedString).data;
  }
  catch (ex) {}

  if (!prefvalue)
    prefvalue = "off";

  var menuitem = charsetMenuGetElement(target, "chardet." + prefvalue);
  if (menuitem)
    menuitem.setAttribute("checked", "true");
}

function UpdateMenus(event) {
  UpdateCurrentCharset(event.target);
  UpdateCharsetDetector(event.target);
}

function CreateMenu(node) {
  Services.obs.notifyObservers(null, "charsetmenu-selected", node);
}

function charsetLoadListener() {
  var charset = window.content.document.characterSet;

  if (charset.length > 0 && (charset != gLastBrowserCharset)) {
    if (!gCharsetMenu)
      gCharsetMenu = Cc['@mozilla.org/rdf/datasource;1?name=charset-menu'].getService(Ci.nsICurrentCharsetListener);
    gCharsetMenu.SetCurrentCharset(charset);
    gPrevCharset = gLastBrowserCharset;
    gLastBrowserCharset = charset;
  }
}


var gPageStyleMenu = {

  _getAllStyleSheets: function (frameset) {
    var styleSheetsArray = Array.slice(frameset.document.styleSheets);
    for (let i = 0; i < frameset.frames.length; i++) {
      let frameSheets = this._getAllStyleSheets(frameset.frames[i]);
      styleSheetsArray = styleSheetsArray.concat(frameSheets);
    }
    return styleSheetsArray;
  },

  fillPopup: function (menuPopup) {
    var noStyle = menuPopup.firstChild;
    var persistentOnly = noStyle.nextSibling;
    var sep = persistentOnly.nextSibling;
    while (sep.nextSibling)
      menuPopup.removeChild(sep.nextSibling);

    var styleSheets = this._getAllStyleSheets(window.content);
    var currentStyleSheets = {};
    var styleDisabled = getMarkupDocumentViewer().authorStyleDisabled;
    var haveAltSheets = false;
    var altStyleSelected = false;

    for (let currentStyleSheet of styleSheets) {
      if (!currentStyleSheet.title)
        continue;

      // Skip any stylesheets whose media attribute doesn't match.
      if (currentStyleSheet.media.length > 0) {
        let mediaQueryList = currentStyleSheet.media.mediaText;
        if (!window.content.matchMedia(mediaQueryList).matches)
          continue;
      }

      if (!currentStyleSheet.disabled)
        altStyleSelected = true;

      haveAltSheets = true;

      let lastWithSameTitle = null;
      if (currentStyleSheet.title in currentStyleSheets)
        lastWithSameTitle = currentStyleSheets[currentStyleSheet.title];

      if (!lastWithSameTitle) {
        let menuItem = document.createElement("menuitem");
        menuItem.setAttribute("type", "radio");
        menuItem.setAttribute("label", currentStyleSheet.title);
        menuItem.setAttribute("data", currentStyleSheet.title);
        menuItem.setAttribute("checked", !currentStyleSheet.disabled && !styleDisabled);
        menuItem.setAttribute("oncommand", "gPageStyleMenu.switchStyleSheet(this.getAttribute('data'));");
        menuPopup.appendChild(menuItem);
        currentStyleSheets[currentStyleSheet.title] = menuItem;
      } else if (currentStyleSheet.disabled) {
        lastWithSameTitle.removeAttribute("checked");
      }
    }

    noStyle.setAttribute("checked", styleDisabled);
    persistentOnly.setAttribute("checked", !altStyleSelected && !styleDisabled);
    persistentOnly.hidden = (window.content.document.preferredStyleSheetSet) ? haveAltSheets : false;
    sep.hidden = (noStyle.hidden && persistentOnly.hidden) || !haveAltSheets;
  },

  _stylesheetInFrame: function (frame, title) {
    return Array.some(frame.document.styleSheets,
                      function (stylesheet) stylesheet.title == title);
  },

  _stylesheetSwitchFrame: function (frame, title) {
    var docStyleSheets = frame.document.styleSheets;

    for (let i = 0; i < docStyleSheets.length; ++i) {
      let docStyleSheet = docStyleSheets[i];

      if (docStyleSheet.title)
        docStyleSheet.disabled = (docStyleSheet.title != title);
      else if (docStyleSheet.disabled)
        docStyleSheet.disabled = false;
    }
  },

  _stylesheetSwitchAll: function (frameset, title) {
    if (!title || this._stylesheetInFrame(frameset, title))
      this._stylesheetSwitchFrame(frameset, title);

    for (let i = 0; i < frameset.frames.length; i++)
      this._stylesheetSwitchAll(frameset.frames[i], title);
  },

  switchStyleSheet: function (title, contentWindow) {
    getMarkupDocumentViewer().authorStyleDisabled = false;
    this._stylesheetSwitchAll(contentWindow || content, title);
  },

  disableStyle: function () {
    getMarkupDocumentViewer().authorStyleDisabled = true;
  },
};

/* Legacy global page-style functions */
var getAllStyleSheets   = gPageStyleMenu._getAllStyleSheets.bind(gPageStyleMenu);
var stylesheetFillPopup = gPageStyleMenu.fillPopup.bind(gPageStyleMenu);
function stylesheetSwitchAll(contentWindow, title) {
  gPageStyleMenu.switchStyleSheet(title, contentWindow);
}
function setStyleDisabled(disabled) {
  if (disabled)
    gPageStyleMenu.disableStyle();
}


var BrowserOffline = {
  _inited: false,

  /////////////////////////////////////////////////////////////////////////////
  // BrowserOffline Public Methods
  init: function ()
  {
    if (!this._uiElement)
      this._uiElement = document.getElementById("workOfflineMenuitemState");

    Services.obs.addObserver(this, "network:offline-status-changed", false);

    this._updateOfflineUI(Services.io.offline);

    this._inited = true;
  },

  uninit: function ()
  {
    if (this._inited) {
      Services.obs.removeObserver(this, "network:offline-status-changed");
    }
  },

  toggleOfflineStatus: function ()
  {
    var ioService = Services.io;

    // Stop automatic management of the offline status
    try {
      ioService.manageOfflineStatus = false;
    } catch (ex) {
    }

    if (!ioService.offline && !this._canGoOffline()) {
      this._updateOfflineUI(false);
      return;
    }

    ioService.offline = !ioService.offline;
  },

  /////////////////////////////////////////////////////////////////////////////
  // nsIObserver
  observe: function (aSubject, aTopic, aState)
  {
    if (aTopic != "network:offline-status-changed")
      return;

    this._updateOfflineUI(aState == "offline");
  },

  /////////////////////////////////////////////////////////////////////////////
  // BrowserOffline Implementation Methods
  _canGoOffline: function ()
  {
    try {
      var cancelGoOffline = Cc["@mozilla.org/supports-PRBool;1"].createInstance(Ci.nsISupportsPRBool);
      Services.obs.notifyObservers(cancelGoOffline, "offline-requested", null);

      // Something aborted the quit process.
      if (cancelGoOffline.data)
        return false;
    }
    catch (ex) {
    }

    return true;
  },

  _uiElement: null,
  _updateOfflineUI: function (aOffline)
  {
    var offlineLocked = gPrefService.prefIsLocked("network.online");
    if (offlineLocked)
      this._uiElement.setAttribute("disabled", "true");

    this._uiElement.setAttribute("checked", aOffline);
  }
};

var OfflineApps = {
  /////////////////////////////////////////////////////////////////////////////
  // OfflineApps Public Methods
  init: function ()
  {
    Services.obs.addObserver(this, "offline-cache-update-completed", false);
  },

  uninit: function ()
  {
    Services.obs.removeObserver(this, "offline-cache-update-completed");
  },

  handleEvent: function(event) {
    if (event.type == "MozApplicationManifest") {
      this.offlineAppRequested(event.originalTarget.defaultView);
    }
  },

  /////////////////////////////////////////////////////////////////////////////
  // OfflineApps Implementation Methods

  // XXX: _getBrowserWindowForContentWindow and _getBrowserForContentWindow
  // were taken from browser/components/feeds/src/WebContentConverter.
  _getBrowserWindowForContentWindow: function(aContentWindow) {
    return aContentWindow.QueryInterface(Ci.nsIInterfaceRequestor)
                         .getInterface(Ci.nsIWebNavigation)
                         .QueryInterface(Ci.nsIDocShellTreeItem)
                         .rootTreeItem
                         .QueryInterface(Ci.nsIInterfaceRequestor)
                         .getInterface(Ci.nsIDOMWindow)
                         .wrappedJSObject;
  },

  _getBrowserForContentWindow: function(aBrowserWindow, aContentWindow) {
    // This depends on pseudo APIs of browser.js and tabbrowser.xml
    aContentWindow = aContentWindow.top;
    var browsers = aBrowserWindow.gBrowser.browsers;
    for (let browser of browsers) {
      if (browser.contentWindow == aContentWindow)
        return browser;
    }
    return null;
  },

  _getManifestURI: function(aWindow) {
    if (!aWindow.document.documentElement)
      return null;

    var attr = aWindow.document.documentElement.getAttribute("manifest");
    if (!attr)
      return null;

    try {
      var contentURI = makeURI(aWindow.location.href, null, null);
      return makeURI(attr, aWindow.document.characterSet, contentURI);
    } catch (e) {
      return null;
    }
  },

  // A cache update isn't tied to a specific window.  Try to find
  // the best browser in which to warn the user about space usage
  _getBrowserForCacheUpdate: function(aCacheUpdate) {
    // Prefer the current browser
    var uri = this._getManifestURI(content);
    if (uri && uri.equals(aCacheUpdate.manifestURI)) {
      return gBrowser.selectedBrowser;
    }

    var browsers = gBrowser.browsers;
    for (let browser of browsers) {
      uri = this._getManifestURI(browser.contentWindow);
      if (uri && uri.equals(aCacheUpdate.manifestURI)) {
        return browser;
      }
    }

    return null;
  },

  _warnUsage: function(aBrowser, aURI) {
    if (!aBrowser)
      return;

    var notificationBox = gBrowser.getNotificationBox(aBrowser);
    var notification = notificationBox.getNotificationWithValue("offline-app-usage");
    if (!notification) {
      var buttons = [{
          label: gNavigatorBundle.getString("offlineApps.manageUsage"),
          accessKey: gNavigatorBundle.getString("offlineApps.manageUsageAccessKey"),
          callback: OfflineApps.manage
        }];

      var warnQuota = gPrefService.getIntPref("offline-apps.quota.warn");
      const priority = notificationBox.PRIORITY_WARNING_MEDIUM;
      var message = gNavigatorBundle.getFormattedString("offlineApps.usage",
                                                        [ aURI.host,
                                                          warnQuota / 1024 ]);

      notificationBox.appendNotification(message, "offline-app-usage",
                                         "chrome://browser/skin/Info.png",
                                         priority, buttons);
    }

    // Now that we've warned once, prevent the warning from showing up
    // again.
    Services.perms.add(aURI, "offline-app",
                       Ci.nsIOfflineCacheUpdateService.ALLOW_NO_WARN);
  },

  // XXX: duplicated in preferences/advanced.js
  _getOfflineAppUsage: function (host, groups)
  {
    var cacheService = Cc["@mozilla.org/network/application-cache-service;1"].
                       getService(Ci.nsIApplicationCacheService);
    if (!groups)
      groups = cacheService.getGroups();

    var usage = 0;
    for (let group of groups) {
      var uri = Services.io.newURI(group, null, null);
      if (uri.asciiHost == host) {
        var cache = cacheService.getActiveCache(group);
        usage += cache.usage;
      }
    }

    return usage;
  },

  _checkUsage: function(aURI) {
    // if the user has already allowed excessive usage, don't bother checking
    if (Services.perms.testExactPermission(aURI, "offline-app") !=
        Ci.nsIOfflineCacheUpdateService.ALLOW_NO_WARN) {
      var usage = this._getOfflineAppUsage(aURI.asciiHost);
      var warnQuota = gPrefService.getIntPref("offline-apps.quota.warn");
      if (usage >= warnQuota * 1024) {
        return true;
      }
    }

    return false;
  },

  offlineAppRequested: function(aContentWindow) {
    if (!gPrefService.getBoolPref("browser.offline-apps.notify")) {
      return;
    }

    var browserWindow = this._getBrowserWindowForContentWindow(aContentWindow);
    var browser = this._getBrowserForContentWindow(browserWindow,
                                                   aContentWindow);

    var currentURI = aContentWindow.document.documentURIObject;

    // don't bother showing UI if the user has already made a decision
    if (Services.perms.testExactPermission(currentURI, "offline-app") != Services.perms.UNKNOWN_ACTION)
      return;

    try {
      if (gPrefService.getBoolPref("offline-apps.allow_by_default")) {
        // all pages can use offline capabilities, no need to ask the user
        return;
      }
    } catch(e) {
      // this pref isn't set by default, ignore failures
    }

    var host = currentURI.asciiHost;
    var notificationBox = gBrowser.getNotificationBox(browser);
    var notificationID = "offline-app-requested-" + host;
    var notification = notificationBox.getNotificationWithValue(notificationID);

    if (notification) {
      notification.documents.push(aContentWindow.document);
    } else {
      var buttons = [{
        label: gNavigatorBundle.getString("offlineApps.allow"),
        accessKey: gNavigatorBundle.getString("offlineApps.allowAccessKey"),
        callback: function() {
          for (let document of notification.documents) {
            OfflineApps.allowSite(document);
          }
        }
      },{
        label: gNavigatorBundle.getString("offlineApps.never"),
        accessKey: gNavigatorBundle.getString("offlineApps.neverAccessKey"),
        callback: function() {
          for (let document of notification.documents) {
            OfflineApps.disallowSite(document);
          }
        }
      },{
        label: gNavigatorBundle.getString("offlineApps.notNow"),
        accessKey: gNavigatorBundle.getString("offlineApps.notNowAccessKey"),
        callback: function() { /* noop */ }
      }];

      const priority = notificationBox.PRIORITY_INFO_LOW;
      var message = gNavigatorBundle.getFormattedString("offlineApps.available",
                                                        [ host ]);
      notification =
        notificationBox.appendNotification(message, notificationID,
                                           "chrome://browser/skin/Info.png",
                                           priority, buttons);
      notification.documents = [ aContentWindow.document ];
    }
  },

  allowSite: function(aDocument) {
    Services.perms.add(aDocument.documentURIObject, "offline-app", Services.perms.ALLOW_ACTION);

    // When a site is enabled while loading, manifest resources will
    // start fetching immediately.  This one time we need to do it
    // ourselves.
    this._startFetching(aDocument);
  },

  disallowSite: function(aDocument) {
    Services.perms.add(aDocument.documentURIObject, "offline-app", Services.perms.DENY_ACTION);
  },

  manage: function() {
    openAdvancedPreferences("networkTab");
  },

  _startFetching: function(aDocument) {
    if (!aDocument.documentElement)
      return;

    var manifest = aDocument.documentElement.getAttribute("manifest");
    if (!manifest)
      return;

    var manifestURI = makeURI(manifest, aDocument.characterSet,
                              aDocument.documentURIObject);

    var updateService = Cc["@mozilla.org/offlinecacheupdate-service;1"].
                        getService(Ci.nsIOfflineCacheUpdateService);
    updateService.scheduleUpdate(manifestURI, aDocument.documentURIObject, window);
  },

  /////////////////////////////////////////////////////////////////////////////
  // nsIObserver
  observe: function (aSubject, aTopic, aState)
  {
    if (aTopic == "offline-cache-update-completed") {
      var cacheUpdate = aSubject.QueryInterface(Ci.nsIOfflineCacheUpdate);

      var uri = cacheUpdate.manifestURI;
      if (OfflineApps._checkUsage(uri)) {
        var browser = this._getBrowserForCacheUpdate(cacheUpdate);
        if (browser) {
          OfflineApps._warnUsage(browser, cacheUpdate.manifestURI);
        }
      }
    }
  }
};

var IndexedDBPromptHelper = {
  _permissionsPrompt: "indexedDB-permissions-prompt",
  _permissionsResponse: "indexedDB-permissions-response",

  _quotaPrompt: "indexedDB-quota-prompt",
  _quotaResponse: "indexedDB-quota-response",
  _quotaCancel: "indexedDB-quota-cancel",

  _notificationIcon: "indexedDB-notification-icon",

  init:
  function IndexedDBPromptHelper_init() {
    Services.obs.addObserver(this, this._permissionsPrompt, false);
    Services.obs.addObserver(this, this._quotaPrompt, false);
    Services.obs.addObserver(this, this._quotaCancel, false);
  },

  uninit:
  function IndexedDBPromptHelper_uninit() {
    Services.obs.removeObserver(this, this._permissionsPrompt, false);
    Services.obs.removeObserver(this, this._quotaPrompt, false);
    Services.obs.removeObserver(this, this._quotaCancel, false);
  },

  observe:
  function IndexedDBPromptHelper_observe(subject, topic, data) {
    if (topic != this._permissionsPrompt &&
        topic != this._quotaPrompt &&
        topic != this._quotaCancel) {
      throw new Error("Unexpected topic!");
    }

    var requestor = subject.QueryInterface(Ci.nsIInterfaceRequestor);

    var contentWindow = requestor.getInterface(Ci.nsIDOMWindow);
    var contentDocument = contentWindow.document;
    var browserWindow =
      OfflineApps._getBrowserWindowForContentWindow(contentWindow);

    if (browserWindow != window) {
      // Must belong to some other window.
      return;
    }

    var browser =
      OfflineApps._getBrowserForContentWindow(browserWindow, contentWindow);

    var host = contentDocument.documentURIObject.asciiHost;

    var message;
    var responseTopic;
    if (topic == this._permissionsPrompt) {
      message = gNavigatorBundle.getFormattedString("offlineApps.available",
                                                    [ host ]);
      responseTopic = this._permissionsResponse;
    }
    else if (topic == this._quotaPrompt) {
      message = gNavigatorBundle.getFormattedString("indexedDB.usage",
                                                    [ host, data ]);
      responseTopic = this._quotaResponse;
    }
    else if (topic == this._quotaCancel) {
      responseTopic = this._quotaResponse;
    }

    const hiddenTimeoutDuration = 30000; // 30 seconds
    const firstTimeoutDuration = 360000; // 5 minutes

    var timeoutId;

    var observer = requestor.getInterface(Ci.nsIObserver);

    var mainAction = {
      label: gNavigatorBundle.getString("offlineApps.allow"),
      accessKey: gNavigatorBundle.getString("offlineApps.allowAccessKey"),
      callback: function() {
        clearTimeout(timeoutId);
        observer.observe(null, responseTopic,
                         Ci.nsIPermissionManager.ALLOW_ACTION);
      }
    };

    var secondaryActions = [
      {
        label: gNavigatorBundle.getString("offlineApps.never"),
        accessKey: gNavigatorBundle.getString("offlineApps.neverAccessKey"),
        callback: function() {
          clearTimeout(timeoutId);
          observer.observe(null, responseTopic,
                           Ci.nsIPermissionManager.DENY_ACTION);
        }
      }
    ];

    // This will be set to the result of PopupNotifications.show() below, or to
    // the result of PopupNotifications.getNotification() if this is a
    // quotaCancel notification.
    var notification;

    function timeoutNotification() {
      // Remove the notification.
      if (notification) {
        notification.remove();
      }

      // Clear all of our timeout stuff. We may be called directly, not just
      // when the timeout actually elapses.
      clearTimeout(timeoutId);

      // And tell the page that the popup timed out.
      observer.observe(null, responseTopic,
                       Ci.nsIPermissionManager.UNKNOWN_ACTION);
    }

    var options = {
      eventCallback: function(state) {
        // Don't do anything if the timeout has not been set yet.
        if (!timeoutId) {
          return;
        }

        // If the popup is being dismissed start the short timeout.
        if (state == "dismissed") {
          clearTimeout(timeoutId);
          timeoutId = setTimeout(timeoutNotification, hiddenTimeoutDuration);
          return;
        }

        // If the popup is being re-shown then clear the timeout allowing
        // unlimited waiting.
        if (state == "shown") {
          clearTimeout(timeoutId);
        }
      }
    };

    if (topic == this._quotaCancel) {
      notification = PopupNotifications.getNotification(this._quotaPrompt,
                                                        browser);
      timeoutNotification();
      return;
    }

    notification = PopupNotifications.show(browser, topic, message,
                                           this._notificationIcon, mainAction,
                                           secondaryActions, options);

    // Set the timeoutId after the popup has been created, and use the long
    // timeout value. If the user doesn't notice the popup after this amount of
    // time then it is most likely not visible and we want to alert the page.
    timeoutId = setTimeout(timeoutNotification, firstTimeoutDuration);
  }
};

function WindowIsClosing()
{
  if (TabView.isVisible()) {
    TabView.hide();
    return false;
  }

  if (!closeWindow(false, warnAboutClosingWindow))
    return false;

  for (let browser of gBrowser.browsers) {
    let ds = browser.docShell;
    if (ds.contentViewer && !ds.contentViewer.permitUnload())
      return false;
  }

  return true;
}

/**
 * Checks if this is the last full *browser* window around. If it is, this will
 * be communicated like quitting. Otherwise, we warn about closing multiple tabs.
 * @returns true if closing can proceed, false if it got cancelled.
 */
function warnAboutClosingWindow() {
  // Popups aren't considered full browser windows.
  let isPBWindow = PrivateBrowsingUtils.isWindowPrivate(window);
  if (!isPBWindow && !toolbar.visible)
    return gBrowser.warnAboutClosingTabs(true);

  // Figure out if there's at least one other browser window around.
  let e = Services.wm.getEnumerator("navigator:browser");
  let otherPBWindowExists = false;
  let nonPopupPresent = false;
  while (e.hasMoreElements()) {
    let win = e.getNext();
    if (win != window) {
      if (isPBWindow && PrivateBrowsingUtils.isWindowPrivate(win))
        otherPBWindowExists = true;
      if (win.toolbar.visible)
        nonPopupPresent = true;
      // If the current window is not in private browsing mode we don't need to 
      // look for other pb windows, we can leave the loop when finding the 
      // first non-popup window. If however the current window is in private 
      // browsing mode then we need at least one other pb and one non-popup 
      // window to break out early.
      if ((!isPBWindow || otherPBWindowExists) && nonPopupPresent)
        break;
    }
  }

  if (isPBWindow && !otherPBWindowExists) {
    let exitingCanceled = Cc["@mozilla.org/supports-PRBool;1"].
                          createInstance(Ci.nsISupportsPRBool);
    exitingCanceled.data = false;
    Services.obs.notifyObservers(exitingCanceled,
                                 "last-pb-context-exiting",
                                 null);
    if (exitingCanceled.data)
      return false;
  }

  if (!isPBWindow && nonPopupPresent)
    return gBrowser.warnAboutClosingTabs(true);

  let os = Services.obs;

  let closingCanceled = Cc["@mozilla.org/supports-PRBool;1"].
                        createInstance(Ci.nsISupportsPRBool);
  os.notifyObservers(closingCanceled,
                     "browser-lastwindow-close-requested", null);
  if (closingCanceled.data)
    return false;

  os.notifyObservers(null, "browser-lastwindow-close-granted", null);

//@line 6242 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  return true;
//@line 6244 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
}

var MailIntegration = {
  sendLinkForWindow: function (aWindow) {
    this.sendMessage(aWindow.location.href,
                     aWindow.document.title);
  },

  sendMessage: function (aBody, aSubject) {
    // generate a mailto url based on the url and the url's title
    var mailtoUrl = "mailto:";
    if (aBody) {
      mailtoUrl += "?body=" + encodeURIComponent(aBody);
      mailtoUrl += "&subject=" + encodeURIComponent(aSubject);
    }

    var uri = makeURI(mailtoUrl);

    // now pass this uri to the operating system
    this._launchExternalUrl(uri);
  },

  // a generic method which can be used to pass arbitrary urls to the operating
  // system.
  // aURL --> a nsIURI which represents the url to launch
  _launchExternalUrl: function (aURL) {
    var extProtocolSvc =
       Cc["@mozilla.org/uriloader/external-protocol-service;1"]
         .getService(Ci.nsIExternalProtocolService);
    if (extProtocolSvc)
      extProtocolSvc.loadUrl(aURL);
  }
};

function BrowserOpenAddonsMgr(aView) {
  if (aView) {
    let emWindow;
    let browserWindow;

    var receivePong = function receivePong(aSubject, aTopic, aData) {
      let browserWin = aSubject.QueryInterface(Ci.nsIInterfaceRequestor)
                               .getInterface(Ci.nsIWebNavigation)
                               .QueryInterface(Ci.nsIDocShellTreeItem)
                               .rootTreeItem
                               .QueryInterface(Ci.nsIInterfaceRequestor)
                               .getInterface(Ci.nsIDOMWindow);
      if (!emWindow || browserWin == window /* favor the current window */) {
        emWindow = aSubject;
        browserWindow = browserWin;
      }
    }
    Services.obs.addObserver(receivePong, "EM-pong", false);
    Services.obs.notifyObservers(null, "EM-ping", "");
    Services.obs.removeObserver(receivePong, "EM-pong");

    if (emWindow) {
      emWindow.loadView(aView);
      browserWindow.gBrowser.selectedTab =
        browserWindow.gBrowser._getTabForContentWindow(emWindow);
      emWindow.focus();
      return;
    }
  }

  var newLoad = !switchToTabHavingURI("about:addons", true);

  if (aView) {
    // This must be a new load, else the ping/pong would have
    // found the window above.
    Services.obs.addObserver(function observer(aSubject, aTopic, aData) {
      Services.obs.removeObserver(observer, aTopic);
      aSubject.loadView(aView);
    }, "EM-loaded", false);
  }
}

function AddKeywordForSearchField() {
  var node = document.popupNode;

  var charset = node.ownerDocument.characterSet;

  var docURI = makeURI(node.ownerDocument.URL,
                       charset);

  var formURI = makeURI(node.form.getAttribute("action"),
                        charset,
                        docURI);

  var spec = formURI.spec;

  var isURLEncoded =
               (node.form.method.toUpperCase() == "POST"
                && (node.form.enctype == "application/x-www-form-urlencoded" ||
                    node.form.enctype == ""));

  var title = gNavigatorBundle.getFormattedString("addKeywordTitleAutoFill",
                                                  [node.ownerDocument.title]);
  var description = PlacesUIUtils.getDescriptionFromDocument(node.ownerDocument);

  var formData = [];

  function escapeNameValuePair(aName, aValue, aIsFormUrlEncoded) {
    if (aIsFormUrlEncoded)
      return escape(aName + "=" + aValue);
    else
      return escape(aName) + "=" + escape(aValue);
  }

  for (let el of node.form.elements) {
    if (!el.type) // happens with fieldsets
      continue;

    if (el == node) {
      formData.push((isURLEncoded) ? escapeNameValuePair(el.name, "%s", true) :
                                     // Don't escape "%s", just append
                                     escapeNameValuePair(el.name, "", false) + "%s");
      continue;
    }

    let type = el.type.toLowerCase();

    if (((el instanceof HTMLInputElement && el.mozIsTextField(true)) ||
        type == "hidden" || type == "textarea") ||
        ((type == "checkbox" || type == "radio") && el.checked)) {
      formData.push(escapeNameValuePair(el.name, el.value, isURLEncoded));
    } else if (el instanceof HTMLSelectElement && el.selectedIndex >= 0) {
      for (var j=0; j < el.options.length; j++) {
        if (el.options[j].selected)
          formData.push(escapeNameValuePair(el.name, el.options[j].value,
                                            isURLEncoded));
      }
    }
  }

  var postData;

  if (isURLEncoded)
    postData = formData.join("&");
  else
    spec += "?" + formData.join("&");

  PlacesUIUtils.showBookmarkDialog({ action: "add"
                                   , type: "bookmark"
                                   , uri: makeURI(spec)
                                   , title: title
                                   , description: description
                                   , keyword: ""
                                   , postData: postData
                                   , charSet: charset
                                   , hiddenRows: [ "location"
                                                 , "description"
                                                 , "tags"
                                                 , "loadInSidebar" ]
                                   }, window);
}

function SwitchDocumentDirection(aWindow) {
  aWindow.document.dir = (aWindow.document.dir == "ltr" ? "rtl" : "ltr");
  for (var run = 0; run < aWindow.frames.length; run++)
    SwitchDocumentDirection(aWindow.frames[run]);
}

function convertFromUnicode(charset, str)
{
  try {
    var unicodeConverter = Components
       .classes["@mozilla.org/intl/scriptableunicodeconverter"]
       .createInstance(Components.interfaces.nsIScriptableUnicodeConverter);
    unicodeConverter.charset = charset;
    str = unicodeConverter.ConvertFromUnicode(str);
    return str + unicodeConverter.Finish();
  } catch(ex) {
    return null;
  }
}

/**
 * Re-open a closed tab.
 * @param aIndex
 *        The index of the tab (via nsSessionStore.getClosedTabData)
 * @returns a reference to the reopened tab.
 */
function undoCloseTab(aIndex) {
  // wallpaper patch to prevent an unnecessary blank tab (bug 343895)
  var blankTabToRemove = null;
  if (gBrowser.tabs.length == 1 &&
      !gPrefService.getBoolPref("browser.tabs.autoHide") &&
      isTabEmpty(gBrowser.selectedTab))
    blankTabToRemove = gBrowser.selectedTab;

  var tab = null;
  var ss = Cc["@mozilla.org/browser/sessionstore;1"].
           getService(Ci.nsISessionStore);
  if (ss.getClosedTabCount(window) > (aIndex || 0)) {
    TabView.prepareUndoCloseTab(blankTabToRemove);
    tab = ss.undoCloseTab(window, aIndex || 0);
    TabView.afterUndoCloseTab();

    if (blankTabToRemove)
      gBrowser.removeTab(blankTabToRemove);
  }

  return tab;
}

/**
 * Re-open a closed window.
 * @param aIndex
 *        The index of the window (via nsSessionStore.getClosedWindowData)
 * @returns a reference to the reopened window.
 */
function undoCloseWindow(aIndex) {
  let ss = Cc["@mozilla.org/browser/sessionstore;1"].
           getService(Ci.nsISessionStore);
  let window = null;
  if (ss.getClosedWindowCount() > (aIndex || 0))
    window = ss.undoCloseWindow(aIndex || 0);

  return window;
}

/*
 * Determines if a tab is "empty", usually used in the context of determining
 * if it's ok to close the tab.
 */
function isTabEmpty(aTab) {
  if (aTab.hasAttribute("busy"))
    return false;

  let browser = aTab.linkedBrowser;
  if (!isBlankPageURL(browser.currentURI.spec))
    return false;

  if (browser.contentWindow.opener)
    return false;

  if (browser.sessionHistory && browser.sessionHistory.count >= 2)
    return false;

  return true;
}

//@line 6487 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
function BrowserOpenSyncTabs() {
  switchToTabHavingURI("about:sync-tabs", true);
}
//@line 6491 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

/**
 * Format a URL
 * eg:
 * echo formatURL("https://addons.mozilla.org/%LOCALE%/%APP%/%VERSION%/");
 * > https://addons.mozilla.org/en-US/firefox/3.0a1/
 *
 * Currently supported built-ins are LOCALE, APP, and any value from nsIXULAppInfo, uppercased.
 */
function formatURL(aFormat, aIsPref) {
  var formatter = Cc["@mozilla.org/toolkit/URLFormatterService;1"].getService(Ci.nsIURLFormatter);
  return aIsPref ? formatter.formatURLPref(aFormat) : formatter.formatURL(aFormat);
}

/**
 * Utility object to handle manipulations of the identity indicators in the UI
 */
var gIdentityHandler = {
  // Mode strings used to control CSS display
  IDENTITY_MODE_IDENTIFIED       : "verifiedIdentity", // High-quality identity information
  IDENTITY_MODE_DOMAIN_VERIFIED  : "verifiedDomain",   // Minimal SSL CA-signed domain verification
  IDENTITY_MODE_UNKNOWN          : "unknownIdentity",  // No trusted identity information
  IDENTITY_MODE_MIXED_CONTENT    : "unknownIdentity mixedContent",  // SSL with unauthenticated content
  IDENTITY_MODE_CHROMEUI         : "chromeUI",         // Part of the product's UI

  // Cache the most recent SSLStatus and Location seen in checkIdentity
  _lastStatus : null,
  _lastLocation : null,
  _mode : "unknownIdentity",

  // smart getters
  get _encryptionLabel () {
    delete this._encryptionLabel;
    this._encryptionLabel = {};
    this._encryptionLabel[this.IDENTITY_MODE_DOMAIN_VERIFIED] =
      gNavigatorBundle.getString("identity.encrypted");
    this._encryptionLabel[this.IDENTITY_MODE_IDENTIFIED] =
      gNavigatorBundle.getString("identity.encrypted");
    this._encryptionLabel[this.IDENTITY_MODE_UNKNOWN] =
      gNavigatorBundle.getString("identity.unencrypted");
    this._encryptionLabel[this.IDENTITY_MODE_MIXED_CONTENT] =
      gNavigatorBundle.getString("identity.mixed_content");
    return this._encryptionLabel;
  },
  get _identityPopup () {
    delete this._identityPopup;
    return this._identityPopup = document.getElementById("identity-popup");
  },
  get _identityBox () {
    delete this._identityBox;
    return this._identityBox = document.getElementById("identity-box");
  },
  get _identityPopupContentBox () {
    delete this._identityPopupContentBox;
    return this._identityPopupContentBox =
      document.getElementById("identity-popup-content-box");
  },
  get _identityPopupContentHost () {
    delete this._identityPopupContentHost;
    return this._identityPopupContentHost =
      document.getElementById("identity-popup-content-host");
  },
  get _identityPopupContentOwner () {
    delete this._identityPopupContentOwner;
    return this._identityPopupContentOwner =
      document.getElementById("identity-popup-content-owner");
  },
  get _identityPopupContentSupp () {
    delete this._identityPopupContentSupp;
    return this._identityPopupContentSupp =
      document.getElementById("identity-popup-content-supplemental");
  },
  get _identityPopupContentVerif () {
    delete this._identityPopupContentVerif;
    return this._identityPopupContentVerif =
      document.getElementById("identity-popup-content-verifier");
  },
  get _identityPopupEncLabel () {
    delete this._identityPopupEncLabel;
    return this._identityPopupEncLabel =
      document.getElementById("identity-popup-encryption-label");
  },
  get _identityIconLabel () {
    delete this._identityIconLabel;
    return this._identityIconLabel = document.getElementById("identity-icon-label");
  },
  get _overrideService () {
    delete this._overrideService;
    return this._overrideService = Cc["@mozilla.org/security/certoverride;1"]
                                     .getService(Ci.nsICertOverrideService);
  },
  get _identityIconCountryLabel () {
    delete this._identityIconCountryLabel;
    return this._identityIconCountryLabel = document.getElementById("identity-icon-country-label");
  },
  get _identityIcon () {
    delete this._identityIcon;
    return this._identityIcon = document.getElementById("page-proxy-favicon");
  },

  /**
   * Rebuild cache of the elements that may or may not exist depending
   * on whether there's a location bar.
   */
  _cacheElements : function() {
    delete this._identityBox;
    delete this._identityIconLabel;
    delete this._identityIconCountryLabel;
    delete this._identityIcon;
    this._identityBox = document.getElementById("identity-box");
    this._identityIconLabel = document.getElementById("identity-icon-label");
    this._identityIconCountryLabel = document.getElementById("identity-icon-country-label");
    this._identityIcon = document.getElementById("page-proxy-favicon");
  },

  /**
   * Handler for mouseclicks on the "More Information" button in the
   * "identity-popup" panel.
   */
  handleMoreInfoClick : function(event) {
    displaySecurityInfo();
    event.stopPropagation();
  },

  /**
   * Helper to parse out the important parts of _lastStatus (of the SSL cert in
   * particular) for use in constructing identity UI strings
  */
  getIdentityData : function() {
    var result = {};
    var status = this._lastStatus.QueryInterface(Components.interfaces.nsISSLStatus);
    var cert = status.serverCert;

    // Human readable name of Subject
    result.subjectOrg = cert.organization;

    // SubjectName fields, broken up for individual access
    if (cert.subjectName) {
      result.subjectNameFields = {};
      cert.subjectName.split(",").forEach(function(v) {
        var field = v.split("=");
        this[field[0]] = field[1];
      }, result.subjectNameFields);

      // Call out city, state, and country specifically
      result.city = result.subjectNameFields.L;
      result.state = result.subjectNameFields.ST;
      result.country = result.subjectNameFields.C;
    }

    // Human readable name of Certificate Authority
    result.caOrg =  cert.issuerOrganization || cert.issuerCommonName;
    result.cert = cert;

    return result;
  },

  /**
   * Determine the identity of the page being displayed by examining its SSL cert
   * (if available) and, if necessary, update the UI to reflect this.  Intended to
   * be called by onSecurityChange
   *
   * @param PRUint32 state
   * @param JS Object location that mirrors an nsLocation (i.e. has .host and
   *                           .hostname and .port)
   */
  checkIdentity : function(state, location) {
    var currentStatus = gBrowser.securityUI
                                .QueryInterface(Components.interfaces.nsISSLStatusProvider)
                                .SSLStatus;
    this._lastStatus = currentStatus;
    this._lastLocation = location;

    let nsIWebProgressListener = Ci.nsIWebProgressListener;
    if (location.protocol == "chrome:" || location.protocol == "about:")
      this.setMode(this.IDENTITY_MODE_CHROMEUI);
    else if (state & nsIWebProgressListener.STATE_IDENTITY_EV_TOPLEVEL)
      this.setMode(this.IDENTITY_MODE_IDENTIFIED);
    else if (state & nsIWebProgressListener.STATE_IS_SECURE)
      this.setMode(this.IDENTITY_MODE_DOMAIN_VERIFIED);
    else if (state & nsIWebProgressListener.STATE_IS_BROKEN)
      this.setMode(this.IDENTITY_MODE_MIXED_CONTENT);
    else
      this.setMode(this.IDENTITY_MODE_UNKNOWN);
  },

  /**
   * Return the eTLD+1 version of the current hostname
   */
  getEffectiveHost : function() {
    if (!this._IDNService)
      this._IDNService = Cc["@mozilla.org/network/idn-service;1"]
                         .getService(Ci.nsIIDNService);
    try {
      let baseDomain =
        Services.eTLD.getBaseDomainFromHost(this._lastLocation.hostname);
      return this._IDNService.convertToDisplayIDN(baseDomain, {});
    } catch (e) {
      // If something goes wrong (e.g. hostname is an IP address) just fail back
      // to the full domain.
      return this._lastLocation.hostname;
    }
  },

  /**
   * Update the UI to reflect the specified mode, which should be one of the
   * IDENTITY_MODE_* constants.
   */
  setMode : function(newMode) {
    if (!this._identityBox) {
      // No identity box means the identity box is not visible, in which
      // case there's nothing to do.
      return;
    }

    this._identityBox.className = newMode;
    this.setIdentityMessages(newMode);

    // Update the popup too, if it's open
    if (this._identityPopup.state == "open")
      this.setPopupMessages(newMode);

    this._mode = newMode;
  },

  /**
   * Set up the messages for the primary identity UI based on the specified mode,
   * and the details of the SSL cert, where applicable
   *
   * @param newMode The newly set identity mode.  Should be one of the IDENTITY_MODE_* constants.
   */
  setIdentityMessages : function(newMode) {
    let icon_label = "";
    let tooltip = "";
    let icon_country_label = "";
    let icon_labels_dir = "ltr";

    switch (newMode) {
    case this.IDENTITY_MODE_DOMAIN_VERIFIED: {
      let iData = this.getIdentityData();

      // Verifier is either the CA Org, for a normal cert, or a special string
      // for certs that are trusted because of a security exception.
      tooltip = gNavigatorBundle.getFormattedString("identity.identified.verifier",
                                                    [iData.caOrg]);

      // Check whether this site is a security exception. XPConnect does the right
      // thing here in terms of converting _lastLocation.port from string to int, but
      // the overrideService doesn't like undefined ports, so make sure we have
      // something in the default case (bug 432241).
      // .hostname can return an empty string in some exceptional cases -
      // hasMatchingOverride does not handle that, so avoid calling it.
      // Updating the tooltip value in those cases isn't critical.
      // FIXME: Fixing bug 646690 would probably makes this check unnecessary
      if (this._lastLocation.hostname &&
          this._overrideService.hasMatchingOverride(this._lastLocation.hostname,
                                                    (this._lastLocation.port || 443),
                                                    iData.cert, {}, {}))
        tooltip = gNavigatorBundle.getString("identity.identified.verified_by_you");
      break; }
    case this.IDENTITY_MODE_IDENTIFIED: {
      // If it's identified, then we can populate the dialog with credentials
      let iData = this.getIdentityData();
      tooltip = gNavigatorBundle.getFormattedString("identity.identified.verifier",
                                                    [iData.caOrg]);
      icon_label = iData.subjectOrg;
      if (iData.country)
        icon_country_label = "(" + iData.country + ")";

      // If the organization name starts with an RTL character, then
      // swap the positions of the organization and country code labels.
      // The Unicode ranges reflect the definition of the UCS2_CHAR_IS_BIDI
      // macro in intl/unicharutil/util/nsBidiUtils.h. When bug 218823 gets
      // fixed, this test should be replaced by one adhering to the
      // Unicode Bidirectional Algorithm proper (at the paragraph level).
      icon_labels_dir = /^[\u0590-\u08ff\ufb1d-\ufdff\ufe70-\ufefc]/.test(icon_label) ?
                        "rtl" : "ltr";
      break; }
    case this.IDENTITY_MODE_CHROMEUI:
      break;
    default:
      tooltip = gNavigatorBundle.getString("identity.unknown.tooltip");
    }

    // Push the appropriate strings out to the UI
    this._identityBox.tooltipText = tooltip;
    this._identityIconLabel.value = icon_label;
    this._identityIconCountryLabel.value = icon_country_label;
    // Set cropping and direction
    this._identityIconLabel.crop = icon_country_label ? "end" : "center";
    this._identityIconLabel.parentNode.style.direction = icon_labels_dir;
    // Hide completely if the organization label is empty
    this._identityIconLabel.parentNode.collapsed = icon_label ? false : true;
  },

  /**
   * Set up the title and content messages for the identity message popup,
   * based on the specified mode, and the details of the SSL cert, where
   * applicable
   *
   * @param newMode The newly set identity mode.  Should be one of the IDENTITY_MODE_* constants.
   */
  setPopupMessages : function(newMode) {

    this._identityPopup.className = newMode;
    this._identityPopupContentBox.className = newMode;

    // Set the static strings up front
    this._identityPopupEncLabel.textContent = this._encryptionLabel[newMode];

    // Initialize the optional strings to empty values
    let supplemental = "";
    let verifier = "";
    let host = "";
    let owner = "";

    switch (newMode) {
    case this.IDENTITY_MODE_DOMAIN_VERIFIED:
      host = this.getEffectiveHost();
      owner = gNavigatorBundle.getString("identity.ownerUnknown2");
      verifier = this._identityBox.tooltipText;
      break;
    case this.IDENTITY_MODE_IDENTIFIED: {
      // If it's identified, then we can populate the dialog with credentials
      let iData = this.getIdentityData();
      host = this.getEffectiveHost();
      owner = iData.subjectOrg;
      verifier = this._identityBox.tooltipText;

      // Build an appropriate supplemental block out of whatever location data we have
      if (iData.city)
        supplemental += iData.city + "\n";
      if (iData.state && iData.country)
        supplemental += gNavigatorBundle.getFormattedString("identity.identified.state_and_country",
                                                            [iData.state, iData.country]);
      else if (iData.state) // State only
        supplemental += iData.state;
      else if (iData.country) // Country only
        supplemental += iData.country;
      break; }
    }

    // Push the appropriate strings out to the UI
    this._identityPopupContentHost.textContent = host;
    this._identityPopupContentOwner.textContent = owner;
    this._identityPopupContentSupp.textContent = supplemental;
    this._identityPopupContentVerif.textContent = verifier;
  },

  hideIdentityPopup : function() {
    this._identityPopup.hidePopup();
  },

  _popupOpenTime : null,

  /**
   * Click handler for the identity-box element in primary chrome.
   */
  handleIdentityButtonEvent : function(event) {
    this._popupOpenTime = new Date();
    event.stopPropagation();

    if ((event.type == "click" && event.button != 0) ||
        (event.type == "keypress" && event.charCode != KeyEvent.DOM_VK_SPACE &&
         event.keyCode != KeyEvent.DOM_VK_RETURN))
      return; // Left click, space or enter only

    // Don't allow left click, space or enter if the location
    // is chrome UI or the location has been modified.
    if (this._mode == this.IDENTITY_MODE_CHROMEUI ||
        gURLBar.getAttribute("pageproxystate") != "valid")
      return;

    // Make sure that the display:none style we set in xul is removed now that
    // the popup is actually needed
    this._identityPopup.hidden = false;

    // Update the popup strings
    this.setPopupMessages(this._identityBox.className);

    // Add the "open" attribute to the identity box for styling
    this._identityBox.setAttribute("open", "true");
    var self = this;
    this._identityPopup.addEventListener("popuphidden", function onPopupHidden(e) {
      e.currentTarget.removeEventListener("popuphidden", onPopupHidden, false);
      self._identityBox.removeAttribute("open");
    }, false);

    // Now open the popup, anchored off the primary chrome element
    this._identityPopup.openPopup(this._identityIcon, "bottomcenter topleft");
  },

  onPopupShown : function(event) {
    let openingDuration = new Date() - this._popupOpenTime;
    this._popupOpenTime = null;
    try {
      Services.telemetry.getHistogramById("FX_IDENTITY_POPUP_OPEN_MS").add(openingDuration);
    } catch (ex) {
      Components.utils.reportError("Unable to report telemetry for FX_IDENTITY_POPUP_OPEN_MS.");
    }
    document.getElementById('identity-popup-more-info-button').focus();
  },

  onDragStart: function (event) {
    if (gURLBar.getAttribute("pageproxystate") != "valid")
      return;

    var value = content.location.href;
    var urlString = value + "\n" + content.document.title;
    var htmlString = "<a href=\"" + value + "\">" + value + "</a>";

    var dt = event.dataTransfer;
    dt.setData("text/x-moz-url", urlString);
    dt.setData("text/uri-list", value);
    dt.setData("text/plain", value);
    dt.setData("text/html", htmlString);
    dt.setDragImage(gProxyFavIcon, 16, 16);
  }
};

function getNotificationBox(aWindow) {
  var foundBrowser = gBrowser.getBrowserForDocument(aWindow.document);
  if (foundBrowser)
    return gBrowser.getNotificationBox(foundBrowser)
  return null;
};

function getTabModalPromptBox(aWindow) {
  var foundBrowser = gBrowser.getBrowserForDocument(aWindow.document);
  if (foundBrowser)
    return gBrowser.getTabModalPromptBox(foundBrowser);
  return null;
};

/* DEPRECATED */
function getBrowser() gBrowser;
function getNavToolbox() gNavToolbox;

//@line 6930 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

//@line 6938 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
let gPrivateBrowsingUI = {
  init: function PBUI_init() {
    // Do nothing for normal windows
    if (!PrivateBrowsingUtils.isWindowPrivate(window)) {
      return;
    }

    // Disable the Clear Recent History... menu item when in PB mode
    // temporary fix until bug 463607 is fixed
    document.getElementById("Tools:Sanitize").setAttribute("disabled", "true");

    if (window.location.href == getBrowserURL()) {
//@line 6955 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

      // Adjust the window's title
      let docElement = document.documentElement;
      docElement.setAttribute("title",
        docElement.getAttribute("title_privatebrowsing"));
      docElement.setAttribute("titlemodifier",
        docElement.getAttribute("titlemodifier_privatebrowsing"));
      docElement.setAttribute("privatebrowsingmode",
        PrivateBrowsingUtils.permanentPrivateBrowsing ? "permanent" : "temporary");
      gBrowser.updateTitlebar();

      if (PrivateBrowsingUtils.permanentPrivateBrowsing) {
        // Adjust the New Window menu entries
        [
          { normal: "menu_newNavigator", private: "menu_newPrivateWindow" },
          { normal: "appmenu_newNavigator", private: "appmenu_newPrivateWindow" },
        ].forEach(function(menu) {
          let newWindow = document.getElementById(menu.normal);
          let newPrivateWindow = document.getElementById(menu.private);
          if (newWindow && newPrivateWindow) {
            newPrivateWindow.hidden = true;
            newWindow.label = newPrivateWindow.label;
            newWindow.accessKey = newPrivateWindow.accessKey;
            newWindow.command = newPrivateWindow.command;
          }
        });
      }
    }

    if (gURLBar) {
      // Disable switch to tab autocompletion for private windows
      gURLBar.setAttribute("autocompletesearchparam", "");
    }
  }
};

//@line 7227 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"


/**
 * Switch to a tab that has a given URI, and focusses its browser window.
 * If a matching tab is in this window, it will be switched to. Otherwise, other
 * windows will be searched.
 *
 * @param aURI
 *        URI to search for
 * @param aOpenNew
 *        True to open a new tab and switch to it, if no existing tab is found.
 *        If no suitable window is found, a new one will be opened.
 * @return True if an existing tab was found, false otherwise
 */
function switchToTabHavingURI(aURI, aOpenNew) {
  // This will switch to the tab in aWindow having aURI, if present.
  function switchIfURIInWindow(aWindow) {
//@line 7245 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
    // Only switch to the tab if neither the source and desination window are
    // private.
    if (PrivateBrowsingUtils.isWindowPrivate(window) ||
        PrivateBrowsingUtils.isWindowPrivate(aWindow)) {
      return false;
    }
//@line 7252 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"

    let browsers = aWindow.gBrowser.browsers;
    for (let i = 0; i < browsers.length; i++) {
      let browser = browsers[i];
      if (browser.currentURI.equals(aURI)) {
        // Focus the matching window & tab
        aWindow.focus();
        aWindow.gBrowser.tabContainer.selectedIndex = i;
        return true;
      }
    }
    return false;
  }

  // This can be passed either nsIURI or a string.
  if (!(aURI instanceof Ci.nsIURI))
    aURI = Services.io.newURI(aURI, null, null);

  let isBrowserWindow = !!window.gBrowser;

  // Prioritise this window.
  if (isBrowserWindow && switchIfURIInWindow(window))
    return true;

  let winEnum = Services.wm.getEnumerator("navigator:browser");
  while (winEnum.hasMoreElements()) {
    let browserWin = winEnum.getNext();
    // Skip closed (but not yet destroyed) windows,
    // and the current window (which was checked earlier).
    if (browserWin.closed || browserWin == window)
      continue;
    if (switchIfURIInWindow(browserWin))
      return true;
  }

  // No opened tab has that url.
  if (aOpenNew) {
    if (isBrowserWindow && isTabEmpty(gBrowser.selectedTab))
      gBrowser.selectedBrowser.loadURI(aURI.spec);
    else
      openUILinkIn(aURI.spec, "tab");
  }

  return false;
}

function restoreLastSession() {
  let ss = Cc["@mozilla.org/browser/sessionstore;1"].
           getService(Ci.nsISessionStore);
  ss.restoreLastSession();
}

var TabContextMenu = {
  contextTab: null,
  updateContextMenu: function updateContextMenu(aPopupMenu) {
    this.contextTab = aPopupMenu.triggerNode.localName == "tab" ?
                      aPopupMenu.triggerNode : gBrowser.selectedTab;
    let disabled = gBrowser.tabs.length == 1;

    // Enable the "Close Tab" menuitem when the window doesn't close with the last tab.
    document.getElementById("context_closeTab").disabled =
      disabled && gBrowser.tabContainer._closeWindowWithLastTab;

    var menuItems = aPopupMenu.getElementsByAttribute("tbattr", "tabbrowser-multiple");
    for (let menuItem of menuItems)
      menuItem.disabled = disabled;

    disabled = gBrowser.visibleTabs.length == 1;
    menuItems = aPopupMenu.getElementsByAttribute("tbattr", "tabbrowser-multiple-visible");
    for (let menuItem of menuItems)
      menuItem.disabled = disabled;

    // Session store
    document.getElementById("context_undoCloseTab").disabled =
      Cc["@mozilla.org/browser/sessionstore;1"].
      getService(Ci.nsISessionStore).
      getClosedTabCount(window) == 0;

    // Only one of pin/unpin should be visible
    document.getElementById("context_pinTab").hidden = this.contextTab.pinned;
    document.getElementById("context_unpinTab").hidden = !this.contextTab.pinned;

    // Disable "Close other Tabs" if there is only one unpinned tab and
    // hide it when the user rightclicked on a pinned tab.
    let unpinnedTabs = gBrowser.visibleTabs.length - gBrowser._numPinnedTabs;
    document.getElementById("context_closeOtherTabs").disabled = unpinnedTabs <= 1;
    document.getElementById("context_closeOtherTabs").hidden = this.contextTab.pinned;

    // Hide "Bookmark All Tabs" for a pinned tab.  Update its state if visible.
    let bookmarkAllTabs = document.getElementById("context_bookmarkAllTabs");
    bookmarkAllTabs.hidden = this.contextTab.pinned;
    if (!bookmarkAllTabs.hidden)
      PlacesCommandHook.updateBookmarkAllTabsCommand();

    // Hide "Move to Group" if it's a pinned tab.
    document.getElementById("context_tabViewMenu").hidden =
      (this.contextTab.pinned || !TabView.firstUseExperienced);
  }
};

XPCOMUtils.defineLazyModuleGetter(this, "gDevTools",
                                  "resource:///modules/devtools/gDevTools.jsm");

XPCOMUtils.defineLazyModuleGetter(this, "gDevToolsBrowser",
                                  "resource:///modules/devtools/gDevTools.jsm");

XPCOMUtils.defineLazyGetter(this, "HUDConsoleUI", function () {
  let tempScope = {};
  Cu.import("resource:///modules/HUDService.jsm", tempScope);
  try {
    return tempScope.HUDService.consoleUI;
  }
  catch (ex) {
    Components.utils.reportError(ex);
    return null;
  }
});

// Prompt user to restart the browser in safe mode
function safeModeRestart()
{
  // prompt the user to confirm
  let promptTitle = gNavigatorBundle.getString("safeModeRestartPromptTitle");
  let promptMessage =
    gNavigatorBundle.getString("safeModeRestartPromptMessage");
  let restartText = gNavigatorBundle.getString("safeModeRestartButton");
  let buttonFlags = (Services.prompt.BUTTON_POS_0 *
                     Services.prompt.BUTTON_TITLE_IS_STRING) +
                    (Services.prompt.BUTTON_POS_1 *
                     Services.prompt.BUTTON_TITLE_CANCEL) +
                    Services.prompt.BUTTON_POS_0_DEFAULT;

  let rv = Services.prompt.confirmEx(window, promptTitle, promptMessage,
                                     buttonFlags, restartText, null, null,
                                     null, {});
  if (rv == 0) {
    Services.startup.restartInSafeMode(Ci.nsIAppStartup.eAttemptQuit);
  }
}

/* duplicateTabIn duplicates tab in a place specified by the parameter |where|.
 *
 * |where| can be:
 *  "tab"         new tab
 *  "tabshifted"  same as "tab" but in background if default is to select new
 *                tabs, and vice versa
 *  "window"      new window
 *
 * delta is the offset to the history entry that you want to load.
 */
function duplicateTabIn(aTab, where, delta) {
  let newTab = Cc['@mozilla.org/browser/sessionstore;1']
                 .getService(Ci.nsISessionStore)
                 .duplicateTab(window, aTab, delta);

  switch (where) {
    case "window":
      gBrowser.hideTab(newTab);
      gBrowser.replaceTabWithWindow(newTab);
      break;
    case "tabshifted":
      // A background tab has been opened, nothing else to do here.
      break;
    case "tab":
      gBrowser.selectedTab = newTab;
      break;
  }
}

function toggleAddonBar() {
  let addonBar = document.getElementById("addon-bar");
  setToolbarVisibility(addonBar, addonBar.collapsed);
}

var Scratchpad = {
  prefEnabledName: "devtools.scratchpad.enabled",

  openScratchpad: function SP_openScratchpad() {
    return this.ScratchpadManager.openScratchpad();
  }
};

XPCOMUtils.defineLazyGetter(Scratchpad, "ScratchpadManager", function() {
  let tmp = {};
  Cu.import("resource:///modules/devtools/scratchpad-manager.jsm", tmp);
  return tmp.ScratchpadManager;
});

var ResponsiveUI = {
  toggle: function RUI_toggle() {
    this.ResponsiveUIManager.toggle(window, gBrowser.selectedTab);
  }
};

XPCOMUtils.defineLazyGetter(ResponsiveUI, "ResponsiveUIManager", function() {
  let tmp = {};
  Cu.import("resource:///modules/devtools/responsivedesign.jsm", tmp);
  return tmp.ResponsiveUIManager;
});

XPCOMUtils.defineLazyGetter(window, "gShowPageResizers", function () {
//@line 7457 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
  return false;
//@line 7459 "/home/txema/work/firefox-20.0+build1/browser/base/content/browser.js"
});

var MousePosTracker = {
  _listeners: [],
  _x: 0,
  _y: 0,
  get _windowUtils() {
    delete this._windowUtils;
    return this._windowUtils = window.getInterface(Ci.nsIDOMWindowUtils);
  },

  addListener: function (listener) {
    if (this._listeners.indexOf(listener) >= 0)
      return;

    listener._hover = false;
    this._listeners.push(listener);

    this._callListener(listener);
  },

  removeListener: function (listener) {
    var index = this._listeners.indexOf(listener);
    if (index < 0)
      return;

    this._listeners.splice(index, 1);
  },

  handleEvent: function (event) {
    var fullZoom = this._windowUtils.fullZoom;
    this._x = event.screenX / fullZoom - window.mozInnerScreenX;
    this._y = event.screenY / fullZoom - window.mozInnerScreenY;

    this._listeners.forEach(function (listener) {
      try {
        this._callListener(listener);
      } catch (e) {
        Cu.reportError(e);
      }
    }, this);
  },

  _callListener: function (listener) {
    let rect = listener.getMouseTargetRect();
    let hover = this._x >= rect.left &&
                this._x <= rect.right &&
                this._y >= rect.top &&
                this._y <= rect.bottom;

    if (hover == listener._hover)
      return;

    listener._hover = hover;

    if (hover) {
      if (listener.onMouseEnter)
        listener.onMouseEnter();
    } else {
      if (listener.onMouseLeave)
        listener.onMouseLeave();
    }
  }
};

function focusNextFrame(event) {
  let fm = Services.focus;
  let dir = event.shiftKey ? fm.MOVEFOCUS_BACKWARDDOC : fm.MOVEFOCUS_FORWARDDOC;
  let element = fm.moveFocus(window, null, dir, fm.FLAG_BYKEY);
  if (element.ownerDocument == document)
    focusAndSelectUrlBar();
}
