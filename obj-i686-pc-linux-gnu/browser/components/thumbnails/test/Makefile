# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/thumbnails/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/thumbnails/test
relativesrcdir  = browser/components/thumbnails/test

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_BROWSER_FILES = \
	browser_thumbnails_capture.js \
	browser_thumbnails_expiration.js \
	browser_thumbnails_privacy.js \
	browser_thumbnails_redirect.js \
	browser_thumbnails_storage.js \
	browser_thumbnails_bug726727.js \
	head.js \
	background_red.html \
	background_red_redirect.sjs \
	privacy_cache_control.sjs \
	$(NULL)

libs::	$(_BROWSER_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/testing/mochitest/browser/$(relativesrcdir)
