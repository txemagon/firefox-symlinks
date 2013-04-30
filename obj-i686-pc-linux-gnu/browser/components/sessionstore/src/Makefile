# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/browser/components/sessionstore/src
VPATH     = /home/txema/work/firefox-20.0+build1/browser/components/sessionstore/src

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/config.mk

EXTRA_COMPONENTS = \
  nsSessionStore.manifest \
  nsSessionStore.js \
  $(NULL)

EXTRA_PP_COMPONENTS := nsSessionStartup.js

JS_MODULES_PATH := $(FINAL_TARGET)/modules/sessionstore

EXTRA_JS_MODULES := \
  DocumentUtils.jsm \
  SessionStorage.jsm \
  XPathGenerator.jsm \
  _SessionFile.jsm \
  $(NULL)

EXTRA_PP_JS_MODULES := \
	SessionStore.jsm \
	$(NULL)

include $(topsrcdir)/config/rules.mk
