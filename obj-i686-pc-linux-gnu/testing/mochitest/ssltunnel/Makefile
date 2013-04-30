#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/testing/mochitest/ssltunnel
VPATH		= /home/txema/work/firefox-20.0+build1/testing/mochitest/ssltunnel

include $(DEPTH)/config/autoconf.mk

# This isn't XPCOM code, but it wants to use STL, so disable the STL
# wrappers
STL_FLAGS =

PROGRAM = ssltunnel$(BIN_SUFFIX)

CPPSRCS = ssltunnel.cpp

LIBS = \
  $(NSPR_LIBS) \
  $(NSS_LIBS) \
  $(MOZALLOC_LIB) \
  $(NULL)

include $(topsrcdir)/config/rules.mk
