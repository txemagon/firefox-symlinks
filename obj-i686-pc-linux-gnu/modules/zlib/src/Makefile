#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/modules/zlib/src
VPATH		= /home/txema/work/firefox-20.0+build1/modules/zlib/src

include $(DEPTH)/config/autoconf.mk
include $(srcdir)/objs.mk

MODULE		= zlib
LIBRARY_NAME	= mozz

CSRCS		= $(MODULES_ZLIB_SRC_LCSRCS)

EXPORTS		= zlib.h zconf.h mozzconf.h


include $(topsrcdir)/config/rules.mk
