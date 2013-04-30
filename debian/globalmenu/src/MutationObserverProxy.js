const { classes: Cc, interfaces: Ci, results: Cr, utils: Cu } = Components;

Cu.import("resource://gre/modules/XPCOMUtils.jsm");

function MutationObserverInit()
{
  this.childList = false;
  this.attributes = false;
  this.characterData = false;
  this.subtree = false;
  this.attributeOldValue = false;
  this.characterDataOldValue = false;

  this.wrappedJSObject = this;
}

MutationObserverInit.prototype = {
  classDescription: "XPCOM MutationObserverInit",
  classID: Components.ID("{eb2cf0b6-b438-49a4-a8d4-225fcd8edb62}"),
  contractID: "@canonical.com/globalmenu-mutation-observer-init;1",

  QueryInterface: XPCOMUtils.generateQI([
    Ci.uIGlobalMenuMutationObserverInit
  ])
};

function MutationRecord(aRecord)
{
  this.type = aRecord.type;
  this.target = aRecord.target;
  this.addedNodes = aRecord.addedNodes;
  this.removedNodes = aRecord.removedNodes;
  this.previousSibling = aRecord.previousSibling;
  this.attributeName = aRecord.attributeName;
}

MutationRecord.prototype = {
  QueryInterface: XPCOMUtils.generateQI([
    Ci.uIGlobalMenuMutationRecord
  ])
};

function MutationObserver() {}

MutationObserver.prototype = {
  classDescription: "XPCOM MutationObserver",
  classID: Components.ID("{2084d756-7c14-4aec-8238-93e2b17a581d}"),
  contractID: "@canonical.com/globalmenu-mutation-observer;1",

  QueryInterface: XPCOMUtils.generateQI([
    Ci.uIGlobalMenuMutationObserver
  ]),

  init: function MO_init(aWindow, aCallback) {
    if (this.obs) {
      throw Components.Exception("Called init more than once",
                                 Cr.NS_ERROR_FAILURE);
    }

    if (!(aCallback instanceof Ci.uIGlobalMenuMutationObserverCallback)) {
      throw Components.Exception("Invalid callback", Cr.NS_ERROR_FAILURE);
    }

    this.obs = new aWindow.MutationObserver(function(mutations) {
      let records = Cc["@mozilla.org/array;1"].createInstance(Ci.nsIMutableArray);
      mutations.forEach(function(mutation) {
        records.appendElement(new MutationRecord(mutation), false);
      });

      aCallback.handleMutations(records);
    });
  },

  observe: function MO_observe(aTarget, aOptions) {
    if (!this.obs) {
      throw Components.Exception("Called observe before init",
                                 Cr.NS_ERROR_FAILURE);
    }

    if (!(aOptions instanceof Ci.uIGlobalMenuMutationObserverInit)) {
      throw Components.Exception("Invalid options", Cr.NS_ERROR_FAILURE);
    }

    this.obs.observe(aTarget, aOptions.wrappedJSObject);
  },

  disconnect: function MO_disconnect() {
    if (!this.obs) {
      throw Components.Exception("Called disconnect before init",
                                 Cr.NS_ERROR_FAILURE);
    }

    this.obs.disconnect();
  }
};

var NSGetFactory = XPCOMUtils.generateNSGetFactory([MutationObserver, MutationObserverInit]);
