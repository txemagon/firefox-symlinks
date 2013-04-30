/* -*- Mode: javascript; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
/* ***** BEGIN LICENSE BLOCK *****
 *	 Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is globalmenu-extension.
 *
 * The Initial Developer of the Original Code is
 * Canonical Ltd.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 * Chris Coulson <chris.coulson@canonical.com>
 * Nils Maier <maierman@web.de>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 * 
 * ***** END LICENSE BLOCK ***** */

(function unity_init() {
  "use strict";

  const {classes: Cc, interfaces: Ci, utils: Cu} = Components;

  Cu.import("resource://gre/modules/Services.jsm");

  var menuObserver = null;
  var fx13 = Services.vc.compare(Services.appinfo.version, "13.0a1") >= 0;

  function enablePlacesNativeViewMenu(name) {
    try {
      // store the original ctor
      var menuCtor = window[name];

      // Override the original ctor, so that nativeView = true gets set
      // Note that somebody might have had the same stupid idea to override the ctor. ;)
      // So, try to interfere the least
      window[name] = function(aEvent) {
        let rootElt = aEvent.target;
        if (rootElt.parentNode.parentNode.localName == "menubar") {
          this._nativeView = true;
          if (!fx13) {
            rootElt._startMarker = -1;
            rootElt._endMarker = -1;
          }
        }
        menuCtor.apply(this, arguments);
      }
      // rewrite the prototype
      window[name].prototype = menuCtor.prototype;
    } catch(e) {
      Cu.reportError("Failed to override ctor for " + name + ": " + e);
    }
  }

  function $(id) document.getElementById(id);

  function uGlobalMenuObserver() {
    var menuservice = Cc["@canonical.com/globalmenu-service;1"]
                      .getService(Ci.uIGlobalMenuService);
    var online = false;
    var autohideSaved;
    var toolbarNameSaved;

    this.handleEvent = function uGMO_handleEvent(aEvent) {
      let target = aEvent.target;
      if (online && target.getAttribute("autohide") != "false") {
        autohideSaved = target.getAttribute("autohide");
        target.setAttribute("autohide", "false");
      }
    };

    this.onMenuServiceOnlineChange = function uGMO_observe(aOnline) {
      if (aOnline) {
        // XXX: localstore.rdf is re-applied when additional overlays are loaded
        //      (https://bugzilla.mozilla.org/show_bug.cgi?id=640158), which
        //      causes this to be undone and the bookmark button to reappear
        $("toolbar-menubar").addEventListener("DOMAttrModified", this);

        autohideSaved = $("toolbar-menubar").getAttribute("autohide");
        toolbarNameSaved = $("toolbar-menubar").getAttribute("toolbarname");
        $("toolbar-menubar").setAttribute("autohide", "false");
        $("toolbar-menubar").removeAttribute("toolbarname");
      } else {
        $("toolbar-menubar").removeEventListener("DOMAttrModified", this);

        if (autohideSaved !== undefined) {
          $("toolbar-menubar").setAttribute("autohide", autohideSaved);
        }
        if (toolbarNameSaved !== undefined) {
          $("toolbar-menubar").setAttribute("toolbarname", toolbarNameSaved);
        }
      }

      online = aOnline;
      updateAppButtonDisplay();
    };

    this.shutdown = function uGMO_shutdown() {
      menuservice.unregisterNotification(this);
      if (online) {
        $("toolbar-menubar").removeEventListener("DOMAttrModified", this);
      }
    };

    menuservice.registerNotification(this);
    this.onMenuServiceOnlineChange(menuservice.online);
  }

  enablePlacesNativeViewMenu("PlacesMenu");
  enablePlacesNativeViewMenu("HistoryMenu");

  addEventListener("load", function onLoad() {
    removeEventListener("load", onLoad, false);

    try {
      if (!menuObserver) {
        menuObserver = new uGlobalMenuObserver();
      }
    } catch(e) {
      Cu.reportError("Failed to set up observer on menu service: " + e);
    }
  }, false);

  addEventListener("unload", function onUnload() {
    removeEventListener("unload", onUnload, false);

    if (menuObserver) {
      menuObserver.shutdown();
      menuObserver = null;
    }
  }, false);

})();
