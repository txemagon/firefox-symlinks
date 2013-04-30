#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpcom/typelib/xpt/tests
VPATH		= /home/txema/work/firefox-20.0+build1/xpcom/typelib/xpt/tests

include $(DEPTH)/config/autoconf.mk

MODULE		= xpcom

SIMPLE_PROGRAMS	= PrimitiveTest$(BIN_SUFFIX) SimpleTypeLib$(BIN_SUFFIX)

CSRCS		= PrimitiveTest.c SimpleTypeLib.c

LIBS		= \
		$(DIST)/lib/$(LIB_PREFIX)xpt.$(LIB_SUFFIX) \
		$(NULL)

include $(topsrcdir)/config/rules.mk

DEFINES += -DEXPORT_XPT_API
