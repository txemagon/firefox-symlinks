#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/xul
VPATH		= /home/txema/work/firefox-20.0+build1/content/xul

include $(DEPTH)/config/autoconf.mk

# We need to build document even if XUL is disabled, for the nsIController[s]
# interfaces and implementations.
# Likewise for content, because of nsXULAtoms.

PARALLEL_DIRS	= document content

ifdef MOZ_XUL
PARALLEL_DIRS	+= templates
endif

include $(topsrcdir)/config/rules.mk

