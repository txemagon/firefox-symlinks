#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/intl/uconv/idl
VPATH		= /home/txema/work/firefox-20.0+build1/intl/uconv/idl

include $(DEPTH)/config/autoconf.mk

MODULE		= uconv
GRE_MODULE	= 1

XPIDLSRCS	= \
	nsITextToSubURI.idl \
	nsICurrentCharsetListener.idl \
	nsICharsetConverterManager.idl \
	nsIScriptableUConv.idl \
	nsIUTF8ConverterService.idl \
	$(NULL)

include $(topsrcdir)/config/rules.mk
