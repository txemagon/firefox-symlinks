# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/mediasniffer
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/mediasniffer

include $(DEPTH)/config/autoconf.mk

MODULE = mediasniffer
LIBRARY_NAME = mediasniffer
LIBXUL_LIBRARY  = 1
EXPORT_LIBRARY = 1
MODULE_NAME = nsMediaSnifferModule
IS_COMPONENT = 1


CPPSRCS = \
    nsMediaSniffer.cpp \
    nsMediaSnifferModule.cpp \
    $(NULL)

EXPORTS = \
    nsMediaSniffer.h \
    $(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/config/rules.mk
