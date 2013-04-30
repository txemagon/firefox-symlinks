# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/battery
VPATH            = /home/txema/work/firefox-20.0+build1/dom/battery

include $(DEPTH)/config/autoconf.mk

LIBRARY_NAME     = dom_battery_s
XPIDL_MODULE     = dom_battery
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1
FAIL_ON_WARNINGS := 1

include $(topsrcdir)/dom/dom-config.mk

EXPORTS_NAMESPACES = mozilla/dom/battery

EXPORTS_mozilla/dom/battery = \
  Constants.h \
  Types.h \
  $(NULL)

CPPSRCS = \
  BatteryManager.cpp \
  $(NULL)

LOCAL_INCLUDES = \
  -I$(topsrcdir)/content/events/src \
  $(NULL)

XPIDLSRCS = \
  nsIDOMBatteryManager.idl \
  nsINavigatorBattery.idl \
  $(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
