#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/js/xpconnect
VPATH		= /home/txema/work/firefox-20.0+build1/js/xpconnect

include $(DEPTH)/config/autoconf.mk

MODULE		= xpconnect
DIRS		= public idl wrappers loader src

TOOL_DIRS    += shell

ifdef ENABLE_TESTS
TOOL_DIRS    += tests
endif

ifdef MOZ_XPCTOOLS
TOOL_DIRS    +=  tools 
endif

include $(topsrcdir)/config/rules.mk
