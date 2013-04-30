SERVICE(CaseConverter, nsICaseConversion, NS_UNICHARUTIL_CONTRACTID)
SERVICE(IconLoader, imgILoader, "@mozilla.org/image/loader;1")
SERVICE(ImageToPixbufService, nsIImageToPixbuf, "@mozilla.org/widget/image-to-gdk-pixbuf;1")
SERVICE(PrefService, nsIPrefBranch, NS_PREFSERVICE_CONTRACTID)
#if MOZILLA_BRANCH_VERSION < 15
SERVICE(XBLService, nsIXBLService, "@mozilla.org/xbl;1")
#endif
SERVICE(XPConnect, nsIXPConnect, nsIXPConnect::GetCID())
SERVICE(AtomService, nsIAtomService, "@mozilla.org/atom-service;1")
