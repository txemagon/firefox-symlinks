# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/xbl/builtin
VPATH		= /home/txema/work/firefox-20.0+build1/content/xbl/builtin

include $(DEPTH)/config/autoconf.mk

ifneq (,$(filter OS2 WINNT,$(OS_ARCH)))
DIRS	= win
else
ifeq (cocoa,$(MOZ_WIDGET_TOOLKIT))
DIRS	= mac
else
ifneq (,$(filter qt gtk2,$(MOZ_WIDGET_TOOLKIT)))
DIRS	= unix
else
DIRS	= emacs
endif
endif
endif

include $(topsrcdir)/config/rules.mk
