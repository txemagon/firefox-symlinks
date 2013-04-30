#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/startupcache/test
VPATH		= /home/txema/work/firefox-20.0+build1/startupcache/test

include $(DEPTH)/config/autoconf.mk

MODULE		= test_startupcache

CPP_UNIT_TESTS = TestStartupCache.cpp

EXTRA_DSO_LIBS += xul
LIBS += $(MOZ_COMPONENT_LIBS)

include $(topsrcdir)/config/rules.mk
