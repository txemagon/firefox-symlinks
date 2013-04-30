# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/xpcom/system
VPATH     = /home/txema/work/firefox-20.0+build1/xpcom/system

include $(DEPTH)/config/autoconf.mk

MODULE          = xpcom
XPIDL_MODULE    = xpcom_system

XPIDLSRCS = \
        nsIXULAppInfo.idl \
        nsIXULRuntime.idl \
        nsIGConfService.idl \
        nsIGnomeVFSService.idl \
        nsIBlocklistService.idl \
        nsIGIOService.idl \
        nsIGSettingsService.idl \
        nsIDeviceSensors.idl \
        nsIGeolocationProvider.idl \
        nsIHapticFeedback.idl \
        $(NULL)

ifdef MOZ_CRASHREPORTER
XPIDLSRCS += nsICrashReporter.idl
endif

include $(topsrcdir)/config/rules.mk
