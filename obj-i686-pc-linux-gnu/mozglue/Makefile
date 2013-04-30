# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/mozglue
VPATH		= /home/txema/work/firefox-20.0+build1/mozglue

include $(DEPTH)/config/autoconf.mk

DIRS =

ifdef MOZ_LINKER
DIRS += linker
endif

ifeq (android,$(MOZ_WIDGET_TOOLKIT))
DIRS += android
endif

DIRS += build

TEST_DIRS = tests

include $(topsrcdir)/config/rules.mk
