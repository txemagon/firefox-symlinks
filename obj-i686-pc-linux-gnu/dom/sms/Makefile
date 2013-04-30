# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/sms
VPATH            = /home/txema/work/firefox-20.0+build1/dom/sms

relativesrcdir   = dom/sms

include $(DEPTH)/config/autoconf.mk

DIRS = interfaces src

TEST_DIRS += tests
ifdef ENABLE_TESTS
XPCSHELL_TESTS = tests
endif

include $(topsrcdir)/config/rules.mk
