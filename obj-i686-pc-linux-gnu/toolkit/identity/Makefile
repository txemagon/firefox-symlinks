# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/identity
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/identity

include $(DEPTH)/config/autoconf.mk

FAIL_ON_WARNINGS := 1

MODULE = identity
MODULE_NAME = identity
XPIDL_MODULE = identity
LIBRARY_NAME = identity
FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY = 1
IS_COMPONENT = 1
GRE_MODULE = 1
EXPORT_LIBRARY = 1

XPIDLSRCS = \
  nsIIdentityCryptoService.idl \
  $(NULL)

CPPSRCS = \
  IdentityCryptoService.cpp \
  $(NULL)

EXTRA_JS_MODULES = \
	IdentityUtils.jsm \
	Identity.jsm \
	IdentityProvider.jsm \
	IdentityStore.jsm \
	jwcrypto.jsm \
	LogUtils.jsm \
	MinimalIdentity.jsm \
	RelyingParty.jsm \
	Sandbox.jsm \
	$(NULL)

JS_MODULES_PATH = $(FINAL_TARGET)/modules/identity

ifdef ENABLE_TESTS
    DIRS += tests
endif

include $(topsrcdir)/config/rules.mk
