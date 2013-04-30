#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


DEPTH=../../..
topsrcdir=/home/txema/work/firefox-20.0+build1
srcdir=/home/txema/work/firefox-20.0+build1/layout/inspector/public
VPATH=/home/txema/work/firefox-20.0+build1/layout/inspector/public

include $(DEPTH)/config/autoconf.mk

MODULE=inspector
XPIDL_MODULE=inspector

XPIDLSRCS = inIDOMView.idl \
            inIDeepTreeWalker.idl \
            inIFlasher.idl \
            inISearchProcess.idl \
            inISearchObserver.idl \
            inICSSValueSearch.idl \
            inIDOMUtils.idl \
            nsIDOMFontFace.idl \
            nsIDOMFontFaceList.idl \
	    $(NULL)

include $(topsrcdir)/config/rules.mk

