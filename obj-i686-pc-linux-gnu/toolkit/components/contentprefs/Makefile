# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/contentprefs
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/contentprefs

include $(DEPTH)/config/autoconf.mk

MODULE = contentprefs

EXTRA_COMPONENTS = \
  nsContentPrefService.js \
  nsContentPrefService.manifest \
  $(NULL)

EXTRA_JS_MODULES = \
  ContentPrefInstance.jsm \
  ContentPrefService2.jsm \
  ContentPrefStore.jsm \
  $(NULL)

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk
