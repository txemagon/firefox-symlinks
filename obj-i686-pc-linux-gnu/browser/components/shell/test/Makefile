# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/shell/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/shell/test
relativesrcdir  = browser/components/shell/test

include $(DEPTH)/config/autoconf.mk

MODULE		= test_browser_shell
XPCSHELL_TESTS	= unit


MOCHITEST_BROWSER_FILES = browser_420786.js \
    browser_633221.js \
	$(NULL)

include $(topsrcdir)/config/rules.mk
