# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/sms/interfaces
VPATH            = /home/txema/work/firefox-20.0+build1/dom/sms/interfaces

include $(DEPTH)/config/autoconf.mk

XPIDL_MODULE = dom_sms

include $(topsrcdir)/dom/dom-config.mk

XPIDLSRCS = \
  nsIDOMNavigatorSms.idl \
  nsIDOMSmsManager.idl \
  nsIDOMSmsMessage.idl \
  nsIDOMSmsEvent.idl \
  nsIDOMSmsRequest.idl \
  nsIDOMSmsFilter.idl \
  nsIDOMSmsCursor.idl \
  nsIDOMSmsSegmentInfo.idl \
  nsISmsDatabaseService.idl \
  nsISmsRequest.idl \
  nsISmsService.idl \
  $(NULL)

ifdef MOZ_B2G_RIL
XPIDLSRCS += \
  nsIRilSmsDatabaseService.idl \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/base \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
