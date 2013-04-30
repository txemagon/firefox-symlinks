#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/alerts
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/alerts

include $(DEPTH)/config/autoconf.mk

MODULE = alerts
XPIDLSRCS = nsIAlertsService.idl

LIBRARY_NAME = alerts_s
FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY = 1
CPPSRCS = \
  nsAlertsService.cpp \
  $(NULL)
LOCAL_INCLUDES += -I$(topsrcdir)/toolkit/components/build/

ifneq (,$(filter cocoa, $(MOZ_WIDGET_TOOLKIT)))
XPIDLSRCS += nsINotificationsList.idl
# mac/growl needs to be first for linking to work!
TOOL_DIRS += \
  mac/growl \
  mac \
  $(NULL)
endif

TEST_DIRS += test

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk

include $(topsrcdir)/config/rules.mk
