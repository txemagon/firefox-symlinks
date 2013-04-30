# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH      = ../../..
topsrcdir  = /home/txema/work/firefox-20.0+build1
srcdir     = /home/txema/work/firefox-20.0+build1/toolkit/components/startup
VPATH      = /home/txema/work/firefox-20.0+build1/toolkit/components/startup
relativesrcdir = toolkit/components/startup

include $(DEPTH)/config/autoconf.mk

DIRS = public

MODULE = toolkitcomps
LIBRARY_NAME = appstartup_s
FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY = 1

CPPSRCS = \
  nsAppStartup.cpp \
  StartupTimeline.cpp \
  $(NULL)

EXPORTS_NAMESPACES = mozilla
EXPORTS_mozilla = StartupTimeline.h

ifeq (os2,$(MOZ_WIDGET_TOOLKIT))
CPPSRCS += nsUserInfoOS2.cpp
else
ifeq ($(OS_ARCH),WINNT)
CPPSRCS += nsUserInfoWin.cpp
else
ifeq (cocoa,$(MOZ_WIDGET_TOOLKIT))
CMMSRCS += nsUserInfoMac.mm
else
CPPSRCS += nsUserInfoUnix.cpp
endif
endif
endif

XPCSHELL_TESTS = tests/unit

TEST_DIRS += tests/browser

include $(topsrcdir)/config/rules.mk
