# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/browser/fuel/test
VPATH          = /home/txema/work/firefox-20.0+build1/browser/fuel/test
relativesrcdir = browser/fuel/test

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_BROWSER_FILES =browser_Application.js \
		browser_ApplicationPrefs.js \
		browser_ApplicationStorage.js \
		browser_ApplicationQuitting.js \
		browser_Bookmarks.js \
		browser_Browser.js \
		ContentA.html \
		ContentB.html \
		ContentWithFrames.html \
		$(NULL)

libs::	$(_BROWSER_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/testing/mochitest/browser/$(relativesrcdir)
