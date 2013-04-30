# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/power
VPATH            = /home/txema/work/firefox-20.0+build1/dom/power

include $(DEPTH)/config/autoconf.mk

LIBRARY_NAME     = dom_power_s
XPIDL_MODULE     = dom_power
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1
ifndef _MSC_VER
FAIL_ON_WARNINGS := 1
endif # !_MSC_VER

include $(topsrcdir)/dom/dom-config.mk

EXPORTS_NAMESPACES = mozilla/dom/power

EXPORTS_mozilla/dom/power = \
  PowerManagerService.h \
  Types.h \
  $(NULL)

CPPSRCS = \
  PowerManager.cpp \
  PowerManagerService.cpp \
  WakeLock.cpp \
  $(NULL)

XPIDLSRCS = \
  nsIDOMPowerManager.idl \
  nsIDOMWakeLock.idl \
  nsIDOMWakeLockListener.idl \
  nsIPowerManagerService.idl \
  $(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk
