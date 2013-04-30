#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/layout
VPATH		= /home/txema/work/firefox-20.0+build1/layout

include $(DEPTH)/config/autoconf.mk

MODULE		= layout

PARALLEL_DIRS = \
		style \
		base \
		generic \
		forms \
		tables \
		svg \
		xul/base/public \
		xul/base/src \
		ipc \
		mathml \
		$(NULL)

ifdef NS_PRINTING
PARALLEL_DIRS += printing
endif

PARALLEL_DIRS += inspector/public inspector/src
ifdef ENABLE_TESTS
PARALLEL_DIRS += inspector/tests inspector/tests/chrome
endif

DIRS           += build
DIRS           += media

ifdef ENABLE_TESTS
PARALLEL_DIRS += \
  mathml/tests \
  xul/test \
  xul/base/test \
  $(NULL)

TOOL_DIRS      += tools/reftest reftests/fonts reftests/fonts/mplus

ifdef MOZ_DEBUG
DIRS            += tools/layout-debug
endif
endif

include $(topsrcdir)/config/rules.mk
