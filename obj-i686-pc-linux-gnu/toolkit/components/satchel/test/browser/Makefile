# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/toolkit/components/satchel/test/browser
VPATH          = /home/txema/work/firefox-20.0+build1/toolkit/components/satchel/test/browser
relativesrcdir = toolkit/components/satchel/test/browser

include $(DEPTH)/config/autoconf.mk

MOCHITEST_BROWSER_FILES = \
  head.js \
  ../subtst_privbrowsing.html \
  $(NULL)

ifdef MOZ_PER_WINDOW_PRIVATE_BROWSING
MOCHITEST_BROWSER_FILES += \
  browser_privbrowsing_perwindowpb.js \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk

