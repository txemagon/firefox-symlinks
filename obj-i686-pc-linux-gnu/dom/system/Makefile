# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH       = ../..
topsrcdir   = /home/txema/work/firefox-20.0+build1
srcdir      = /home/txema/work/firefox-20.0+build1/dom/system
VPATH       = /home/txema/work/firefox-20.0+build1/dom/system

include $(DEPTH)/config/autoconf.mk

MODULE          = dom
XPIDL_MODULE    = dom_system
LIBRARY_NAME    = domsystem_s
LIBXUL_LIBRARY  = 1
FAIL_ON_WARNINGS := 1

ifneq (,$(filter qt gtk2,$(MOZ_WIDGET_TOOLKIT)))
DIRS = unix
endif

ifneq (,$(filter windows,$(MOZ_WIDGET_TOOLKIT)))
DIRS = windows
endif

ifneq (,$(filter android,$(MOZ_WIDGET_TOOLKIT)))
DIRS = android
endif

ifdef MOZ_B2G_RIL
DIRS += gonk
endif

DEFINES += -DDLL_PREFIX=\"$(DLL_PREFIX)\" -DDLL_SUFFIX=\"$(DLL_SUFFIX)\"

XPIDLSRCS = \
  nsIOSFileConstantsService.idl \
  $(NULL)

CPPSRCS     = \
  nsDeviceSensors.cpp \
  OSFileConstants.cpp \
  $(NULL)

# We fire the nsDOMDeviceAcceleration
LOCAL_INCLUDES += \
  -I$(topsrcdir)/content/events/src \
  -I$(topsrcdir)/dom/base \
  -I$(topsrcdir)/dom/bindings \
  $(NULL)

# On Systems that have build in geolocation providers,
# we really do not need these.
ifneq (Android,$(OS_TARGET))
EXTRA_COMPONENTS = \
  NetworkGeolocationProvider.js \
  NetworkGeolocationProvider.manifest \
  GPSDGeolocationProvider.js \
  GPSDGeolocationProvider.manifest \
  $(NULL)
endif

ifeq (gonk,$(MOZ_WIDGET_TOOLKIT))
EXTRA_COMPONENTS = \
  NetworkGeolocationProvider.js \
  NetworkGeolocationProvider.manifest \
  $(NULL)
endif

EXPORTS_NAMESPACES = mozilla

EXPORTS     = \
  nsDeviceSensors.h \
  $(NULL)

EXPORTS_mozilla = \
  OSFileConstants.h \
  $(NULL)

# We fire the nsDOMDeviceAcceleration
LOCAL_INCLUDES += \
  -I$(topsrcdir)/content/events/src \
  -I$(topsrcdir)/js/xpconnect/loader \
  $(NULL)

ifdef ENABLE_TESTS
DIRS += tests
endif

include $(topsrcdir)/config/config.mk

# we don't want the shared lib, but we want to force the creation of a static lib.
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1
EXPORT_LIBRARY = 1
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

