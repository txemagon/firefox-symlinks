#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/rdf/tests/rdfcat
VPATH		= /home/txema/work/firefox-20.0+build1/rdf/tests/rdfcat

include $(DEPTH)/config/autoconf.mk

PROGRAM		= rdfcat$(BIN_SUFFIX)

CPPSRCS		= rdfcat.cpp

LIBS		= \
		$(DIST)/lib/$(LIB_PREFIX)xpcomglue_s.$(LIB_SUFFIX) \
		$(LIBS_DIR) \
		$(XPCOM_LIBS) \
		$(NSPR_LIBS) \
		$(NULL)

ifeq ($(OS_ARCH),WINNT)
MAPFILE=rdfcat.map
endif

include $(topsrcdir)/config/rules.mk

CXXFLAGS += $(TK_CFLAGS)
