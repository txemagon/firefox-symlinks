#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/netwerk/streamconv/public
VPATH		= /home/txema/work/firefox-20.0+build1/netwerk/streamconv/public
FAIL_ON_WARNINGS := 1

include $(DEPTH)/config/autoconf.mk

MODULE		= necko
XPIDL_MODULE	= necko_strconv
GRE_MODULE	= 1

XPIDLSRCS	= \
		nsIStreamConverter.idl \
		nsIStreamConverterService.idl \
		mozITXTToHTMLConv.idl \
		nsITXTToHTMLConv.idl \
		nsIDirIndex.idl \
		nsIDirIndexListener.idl \
		$(NULL)

ifeq (cocoa,$(MOZ_WIDGET_TOOLKIT))
XPIDLSRCS += \
		nsIAppleFileDecoder.idl \
		$(NULL)
endif

include $(topsrcdir)/config/rules.mk

DEFINES += -DIMPL_NS_NET

XPIDL_FLAGS += -I$(topsrcdir)/netwerk/base/public
