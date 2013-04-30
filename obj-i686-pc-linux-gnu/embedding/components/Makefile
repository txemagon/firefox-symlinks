# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/embedding/components
VPATH		= /home/txema/work/firefox-20.0+build1/embedding/components

include $(DEPTH)/config/autoconf.mk

# You'd think we could skip building ui if XUL is disabled,
# but we need to export interface headers from those directories.

DIRS = windowwatcher appstartup/src find webbrowserpersist commandhandler

ifdef MOZ_XUL
ifdef NS_PRINTING
DIRS += printingui/src
endif
endif

DIRS += build

include $(topsrcdir)/config/rules.mk
