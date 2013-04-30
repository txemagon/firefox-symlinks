# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/ipc
VPATH = /home/txema/work/firefox-20.0+build1/ipc

include $(DEPTH)/config/autoconf.mk

DIRS += chromium glue ipdl testshell

ifdef MOZ_B2G_RIL #{
DIRS += ril
endif #}

ifdef MOZ_B2G_BT #{
DIRS += dbus
endif #}

ifeq (gonk,$(MOZ_WIDGET_TOOLKIT))
DIRS += netd unixsocket
endif

ifeq ($(OS_ARCH),Linux)
DIRS += unixsocket
endif

TOOL_DIRS = app

include $(topsrcdir)/config/rules.mk
