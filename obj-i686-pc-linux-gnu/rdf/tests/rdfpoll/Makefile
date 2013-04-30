#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/rdf/tests/rdfpoll
VPATH		= /home/txema/work/firefox-20.0+build1/rdf/tests/rdfpoll

include $(DEPTH)/config/autoconf.mk

PROGRAM		= rdfpoll$(BIN_SUFFIX)
CPPSRCS		= rdfpoll.cpp


LIBS		= \
		$(DIST)/lib/$(LIB_PREFIX)xpcomglue_s.$(LIB_SUFFIX) \
		$(LIBS_DIR) \
		$(XPCOM_LIBS) \
		$(NSPR_LIBS) \
		$(NULL)

include $(topsrcdir)/config/config.mk

include $(topsrcdir)/config/rules.mk

