#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/extensions/spellcheck/tests/chrome
VPATH		= /home/txema/work/firefox-20.0+build1/extensions/spellcheck/tests/chrome
relativesrcdir  = extensions/spellcheck/tests/chrome

include $(DEPTH)/config/autoconf.mk

DIRS = base map

MOCHITEST_CHROME_FILES = 	test_add_remove_dictionaries.xul \
				$(NULL)

include $(topsrcdir)/config/rules.mk
