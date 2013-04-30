#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/dom/interfaces/base
VPATH		= /home/txema/work/firefox-20.0+build1/dom/interfaces/base

include $(DEPTH)/config/autoconf.mk

MODULE		= dom
XPIDL_MODULE	= dom_base
GRE_MODULE	= 1

SDK_XPIDLSRCS =                                 \
	domstubs.idl				\
	nsIDOMBarProp.idl			\
	nsIDOMWindow.idl			\
	nsIDOMWindowCollection.idl		\
	nsIDOMWindowUtils.idl			\
	$(NULL)

XPIDLSRCS =					\
	nsIFrameRequestCallback.idl             \
	nsIBrowserDOMWindow.idl			\
	nsIContentPermissionPrompt.idl  \
	nsIContentPrefService.idl		\
	nsIContentPrefService2.idl		\
	nsIContentURIGrouper.idl		\
	nsIDOMClientInformation.idl		\
	nsIDOMConstructor.idl			\
	nsIDOMCRMFObject.idl			\
	nsIDOMCrypto.idl			\
	nsIDOMHistory.idl			\
	nsIDOMLocation.idl			\
	nsIDOMMediaQueryList.idl		\
	nsIDOMMimeType.idl			\
	nsIDOMMimeTypeArray.idl			\
	nsIDOMNavigator.idl			\
	nsIDOMPkcs11.idl			\
	nsIDOMPlugin.idl			\
	nsIDOMPluginArray.idl			\
	nsIDOMScreen.idl			\
	nsIDOMJSWindow.idl			\
	nsIDOMModalContentWindow.idl		\
	nsIDOMChromeWindow.idl			\
        nsIDOMClientRect.idl			\
        nsIDOMClientRectList.idl		\
	nsIFocusManager.idl			\
	nsIQueryContentEventResult.idl		\
	nsITabChild.idl				\
	nsITabParent.idl			\
	nsIDOMGlobalPropertyInitializer.idl	\
	nsIDOMGlobalObjectConstructor.idl \
	nsIStructuredCloneContainer.idl		\
	nsIIdleObserver.idl			\
	$(NULL)

ifdef MOZ_B2G
XPIDLSRCS += \
  nsIDOMWindowB2G.idl \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
