# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           = ../../..
topsrcdir       = /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/intl/hyphenation/src
VPATH           = /home/txema/work/firefox-20.0+build1/intl/hyphenation/src

include $(DEPTH)/config/autoconf.mk

MODULE           = hyphenation
LIBRARY_NAME     = hyphenation_s
LIBXUL_LIBRARY   = 1

CSRCS            = hyphen.c \
                   $(NULL)

CPPSRCS          = nsHyphenator.cpp \
                   nsHyphenationManager.cpp \
                   hnjstdio.cpp \
                   $(NULL)

include $(topsrcdir)/config/rules.mk
