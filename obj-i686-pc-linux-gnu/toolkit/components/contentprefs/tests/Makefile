#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/components/contentprefs/tests
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/components/contentprefs/tests
relativesrcdir = toolkit/components/contentprefs/tests

include $(DEPTH)/config/autoconf.mk

MODULE		= test_toolkit_contentprefs

XPCSHELL_TESTS = unit unit_cps2

# FIXME/bug 575918: out-of-process xpcshell is broken on OS X
ifneq ($(OS_ARCH),Darwin)
XPCSHELL_TESTS += unit_ipc
endif

include $(topsrcdir)/config/rules.mk
