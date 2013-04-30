# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/services/crypto/component
VPATH     = /home/txema/work/firefox-20.0+build1/services/crypto/component

include $(DEPTH)/config/autoconf.mk

FAIL_ON_WARNINGS := 1

MODULE := services-crypto
XPIDL_MODULE := services-crypto-component

XPIDLSRCS := \
  nsISyncJPAKE.idl \
  $(NULL)

LIBRARY_NAME := services-crypto
EXPORT_LIBRARY := 1
IS_COMPONENT := 1
MODULE_NAME := nsServicesCryptoModule
LIBXUL_LIBRARY := 1
MOZILLA_INTERNAL_API := 1

CPPSRCS := \
  nsSyncJPAKE.cpp \
  $(NULL)

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk
