# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/services/aitc
VPATH     = /home/txema/work/firefox-20.0+build1/services/aitc

include $(DEPTH)/config/autoconf.mk

aitc_modules := \
  browserid.js \
  client.js \
  main.js \
  manager.js \
  storage.js \
  $(NULL)

EXTRA_COMPONENTS = \
  AitcComponents.manifest \
  Aitc.js \
  $(NULL)

PREF_JS_EXPORTS = $(srcdir)/services-aitc.js

AITC_MODULE_FILES := $(addprefix modules/,$(aitc_modules))
AITC_MODULE_DEST = $(FINAL_TARGET)/modules/services-aitc
INSTALL_TARGETS += AITC_MODULE

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk
