# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/identity
VPATH            = /home/txema/work/firefox-20.0+build1/dom/identity

relativesrcdir   = dom/identity

include $(DEPTH)/config/autoconf.mk

EXTRA_COMPONENTS = \
    nsDOMIdentity.js \
    nsIDService.js \
    Identity.manifest \
    $(NULL)

EXTRA_PP_JS_MODULES = \
    DOMIdentity.jsm \
    $(NULL)

EXTRA_JS_MODULES = \
    $(NULL)

ifdef ENABLE_TESTS
DIRS += tests
endif

include $(topsrcdir)/config/rules.mk
