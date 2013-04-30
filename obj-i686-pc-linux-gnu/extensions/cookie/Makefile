#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/extensions/cookie
VPATH		= /home/txema/work/firefox-20.0+build1/extensions/cookie

include $(DEPTH)/config/autoconf.mk

MODULE		= cookie
LIBRARY_NAME	= cookie
EXPORT_LIBRARY = 1
IS_COMPONENT	= 1
MODULE_NAME	= nsCookieModule
GRE_MODULE	= 1
LIBXUL_LIBRARY = 1


CPPSRCS		= \
		nsCookieModule.cpp \
		nsPermission.cpp \
		nsPermissionManager.cpp \
		nsPopupWindowManager.cpp \
		nsCookiePromptService.cpp \
		nsCookiePermission.cpp \
		$(NULL)

XPIDLSRCS	= \
		nsICookieAcceptDialog.idl \
		nsICookiePromptService.idl \
		$(NULL)

ifdef ENABLE_TESTS
TOOL_DIRS		+= test
endif

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk
