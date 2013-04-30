# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/services/crypto
VPATH     = /home/txema/work/firefox-20.0+build1/services/crypto

include $(DEPTH)/config/autoconf.mk

modules := \
  utils.js \
  WeaveCrypto.js \
  $(NULL)

MODULE = services-crypto

EXTRA_COMPONENTS := \
  cryptoComponents.manifest \
  $(NULL)

CRYPTO_MODULE_FILES := $(addprefix modules/,$(modules))
CRYPTO_MODULE_DEST = $(FINAL_TARGET)/modules/services-crypto
INSTALL_TARGETS += CRYPTO_MODULE

TEST_DIRS += tests

DIRS += component

include $(topsrcdir)/config/rules.mk
