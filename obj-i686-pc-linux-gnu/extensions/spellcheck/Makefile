# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/extensions/spellcheck
VPATH		= /home/txema/work/firefox-20.0+build1/extensions/spellcheck

include $(DEPTH)/config/autoconf.mk

MODULE		= spellchecker
DIRS		= idl locales hunspell src

TEST_DIRS += tests/chrome

include $(topsrcdir)/config/rules.mk
