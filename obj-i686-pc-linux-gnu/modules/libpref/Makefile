#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/modules/libpref
VPATH		= /home/txema/work/firefox-20.0+build1/modules/libpref

include $(DEPTH)/config/autoconf.mk

ifdef ENABLE_TESTS
TOOL_DIRS += test
endif

MODULE		= pref
DIRS		= public src

include $(topsrcdir)/config/rules.mk

