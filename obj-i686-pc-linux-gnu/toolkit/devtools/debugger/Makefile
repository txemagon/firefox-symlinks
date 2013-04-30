# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/devtools/debugger
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/devtools/debugger

include $(DEPTH)/config/autoconf.mk

MODULE = jsinspector
MODULE_NAME = jsinspector
GRE_MODULE = 1

LIBRARY_NAME = jsinspector
XPIDL_MODULE = jsinspector
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1
IS_COMPONENT = 1

CPPSRCS = \
    nsJSInspector.cpp \
    $(NULL)

EXTRA_DSO_LDOPTS += \
    $(MOZ_COMPONENT_LIBS) \
    $(MOZ_JS_LIBS) \
    $(NULL)

XPIDLSRCS = \
	nsIJSInspector.idl \
	$(NULL)

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk

libs::
	$(INSTALL) $(IFLAGS1) $(srcdir)/*.jsm $(FINAL_TARGET)/modules/devtools
	$(INSTALL) $(IFLAGS1) $(srcdir)/server/*.jsm $(FINAL_TARGET)/modules/devtools
