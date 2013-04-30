# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/devtools/markupview/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/devtools/markupview/test
relativesrcdir  = browser/devtools/markupview/test

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_BROWSER_FILES = \
		browser_inspector_markup_navigation.html \
		browser_inspector_markup_navigation.js \
		browser_inspector_markup_mutation.html \
		browser_inspector_markup_mutation.js \
		browser_inspector_markup_edit.html \
    browser_inspector_markup_edit.js \
    browser_inspector_markup_subset.html \
    browser_inspector_markup_subset.js \
		head.js \
		$(NULL)

libs::	$(_BROWSER_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/testing/mochitest/browser/$(relativesrcdir)
