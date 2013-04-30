# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/addon-sdk
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/addon-sdk

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/config.mk

DIRS += \
  promise \
  $(NULL)

JS_MODULES_PATH := $(FINAL_TARGET)/modules/commonjs

EXTRA_JS_MODULES := \
  loader.js \
  $(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/rules.mk
