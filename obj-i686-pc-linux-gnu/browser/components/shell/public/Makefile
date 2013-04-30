#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH   = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/browser/components/shell/public
VPATH   = /home/txema/work/firefox-20.0+build1/browser/components/shell/public

include $(DEPTH)/config/autoconf.mk

MODULE = shellservice
XPIDL_MODULE  = shellservice

XPIDLSRCS = nsIShellService.idl

ifeq ($(OS_ARCH),WINNT)
XPIDLSRCS += nsIWindowsShellService.idl
endif

ifeq (cocoa,$(MOZ_WIDGET_TOOLKIT))
XPIDLSRCS += nsIMacShellService.idl
endif

include $(topsrcdir)/config/rules.mk
