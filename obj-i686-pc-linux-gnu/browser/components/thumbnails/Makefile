# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/thumbnails
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/thumbnails

include $(DEPTH)/config/autoconf.mk

EXTRA_COMPONENTS = \
	BrowserPageThumbs.manifest \
	PageThumbsProtocol.js \
	$(NULL)

EXTRA_JS_MODULES = \
	PageThumbsWorker.js \
	PageThumbs.jsm \
	$(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += -I$(topsrcdir)/browser/components/
