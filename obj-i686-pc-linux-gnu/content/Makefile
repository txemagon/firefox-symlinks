#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content
VPATH		= /home/txema/work/firefox-20.0+build1/content

include $(DEPTH)/config/autoconf.mk

MODULE		= content
PARALLEL_DIRS = base canvas events html mathml/content/src smil svg xml xul xbl xslt

ifdef MOZ_MEDIA
PARALLEL_DIRS	+= media
endif

ifdef ENABLE_TESTS
TOOL_DIRS += test
endif

include $(topsrcdir)/config/rules.mk
