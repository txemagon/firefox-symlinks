# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/components/social/test/browser
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/components/social/test/browser
relativesrcdir  = toolkit/components/social/test/browser

MODULE = test_socialapi

include $(DEPTH)/config/autoconf.mk

MOCHITEST_BROWSER_FILES = \
  head.js \
  data.json \
  worker_xhr.js \
  browser_frameworker.js \
  worker_relative.js \
  relative_import.js \
  browser_workerAPI.js \
  worker_social.js \
  browser_SocialProvider.js \
  browser_notifications.js \
  $(NULL)

include $(topsrcdir)/config/rules.mk
