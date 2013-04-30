# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/search/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/search/test
relativesrcdir  =  browser/components/search/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_BROWSER_FILES = \
  browser_405664.js \
  browser_addEngine.js \
  browser_contextmenu.js \
  testEngine.xml \
  testEngine_mozsearch.xml \
  testEngine.src \
  browser_426329.js \
  426329.xml \
  browser_483086.js \
  483086-1.xml \
  483086-2.xml \
  test.html \
  $(NULL)

ifdef MOZ_PER_WINDOW_PRIVATE_BROWSING
MOCHITEST_BROWSER_FILES += \
  browser_private_search_perwindowpb.js \
  $(NULL)
else
MOCHITEST_BROWSER_FILES += \
  browser_private_search.js \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk
