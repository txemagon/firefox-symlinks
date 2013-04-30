#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/netwerk
VPATH		= /home/txema/work/firefox-20.0+build1/netwerk

include $(DEPTH)/config/autoconf.mk

MODULE		= necko

PARALLEL_DIRS = \
  base \
  cookie \
  dns \
  socket \
  mime \
  streamconv \
  cache \
  protocol \
  system \
  ipc  \
  $(NULL)

ifdef MOZ_SRTP
PARALLEL_DIRS += \
  srtp/src \
  $(NULL)
endif

ifdef MOZ_SCTP
PARALLEL_DIRS += \
  sctp/src \
  sctp/datachannel \
  $(NULL)
endif

ifdef NECKO_WIFI
PARALLEL_DIRS += wifi
endif

PARALLEL_DIRS += locales

ifdef MOZ_DASH
PARALLEL_DIRS += dash
endif

DIRS = build

ifdef ENABLE_TESTS
TOOL_DIRS  += test
endif

EXPORTS     = necko-config.h

include $(topsrcdir)/config/rules.mk

DEFINES += -DIMPL_NS_NET
