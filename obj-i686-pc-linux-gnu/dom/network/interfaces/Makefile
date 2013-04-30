# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/network/interfaces
VPATH            = /home/txema/work/firefox-20.0+build1/dom/network/interfaces

include $(DEPTH)/config/autoconf.mk

XPIDL_MODULE = dom_network

include $(topsrcdir)/dom/dom-config.mk

XPIDLSRCS = \
  nsIDOMNavigatorNetwork.idl \
  nsIDOMConnection.idl \
  nsIDOMUSSDReceivedEvent.idl \
  nsIDOMTCPSocket.idl \
  nsITCPSocketParent.idl \
  nsITCPSocketChild.idl \
  nsIDOMDataErrorEvent.idl \
  $(NULL)

ifdef MOZ_B2G_RIL
XPIDLSRCS += \
  nsIDOMMobileConnection.idl \
  nsIMobileConnectionProvider.idl \
  nsINavigatorMobileConnection.idl \
  nsIDOMNetworkStatsManager.idl \
  nsIDOMNetworkStats.idl \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
