#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/devtools/webconsole
VPATH		= /home/txema/work/firefox-20.0+build1/browser/devtools/webconsole

include $(DEPTH)/config/autoconf.mk

EXTRA_JS_MODULES = \
		HUDService.jsm \
		PropertyPanel.jsm \
		NetworkPanel.jsm \
		AutocompletePopup.jsm \
		WebConsolePanel.jsm \
		$(NULL)

TEST_DIRS = test

include $(topsrcdir)/config/rules.mk
