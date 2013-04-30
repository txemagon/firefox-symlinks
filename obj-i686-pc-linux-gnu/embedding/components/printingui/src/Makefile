#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/embedding/components/printingui/src
VPATH		= /home/txema/work/firefox-20.0+build1/embedding/components/printingui/src

include $(DEPTH)/config/autoconf.mk

ifdef MOZ_PDF_PRINTING
PLATFORM_DIR += unixshared
endif

ifeq ($(MOZ_WIDGET_TOOLKIT),os2)
PLATFORM_DIR = os2
endif

ifeq ($(MOZ_WIDGET_TOOLKIT),windows)
PLATFORM_DIR = win
endif

ifeq (cocoa,$(MOZ_WIDGET_TOOLKIT))
PLATFORM_DIR = mac
endif

DIRS = $(PLATFORM_DIR)

include $(topsrcdir)/config/rules.mk
