#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/toolkit/content/tests/browser
VPATH          = /home/txema/work/firefox-20.0+build1/toolkit/content/tests/browser
relativesrcdir = toolkit/content/tests/browser

include $(DEPTH)/config/autoconf.mk

DIRS = \
  common \
  data \
  $(NULL)


MOCHITEST_BROWSER_FILES = \
  browser_keyevents_during_autoscrolling.js \
  browser_bug295977_autoscroll_overflow.js \
  browser_bug594509.js \
  browser_Geometry.js \
  browser_InlineSpellChecker.js \
  browser_save_resend_postdata.js \
  browser_browserDrop.js \
  browser_Services.js \
  browser_DeferredTask.js \
  browser_default_image_filename.js \
  browser_Troubleshoot.js \
  $(NULL)

include $(topsrcdir)/config/rules.mk
