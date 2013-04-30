# vim:set ts=8 sw=8 sts=8 noet:
# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           = ../..
topsrcdir       = /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/embedding/base
VPATH           = /home/txema/work/firefox-20.0+build1/embedding/base

MODULE          = embed_base
XPIDL_MODULE	= embed_base

include $(DEPTH)/config/autoconf.mk

SDK_HEADERS         = \
                nsEmbedCID.h \
                $(NULL)

SDK_XPIDLSRCS   = \
                nsIWindowCreator.idl \
                $(NULL)


XPIDLSRCS	    = \
                nsIWindowCreator2.idl \
                nsIWindowProvider.idl \
                nsIDialogCreator.idl \
                $(NULL)

include $(topsrcdir)/config/rules.mk
