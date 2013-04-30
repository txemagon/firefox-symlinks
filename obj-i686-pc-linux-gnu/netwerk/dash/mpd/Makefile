# -*- Mode: makefile; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- #
# vim: set ts=2 et sw=2 tw=80: #
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
# Contributor(s):
#     Steve Workman <sworkman@mozilla.com>

DEPTH     := ../../..
topsrcdir := /home/txema/work/firefox-20.0+build1
srcdir    := /home/txema/work/firefox-20.0+build1/netwerk/dash/mpd
VPATH     := /home/txema/work/firefox-20.0+build1/netwerk/dash/mpd

include $(DEPTH)/config/autoconf.mk

MODULE         := necko
LIBRARY_NAME   := nkdashmpd_s
LIBXUL_LIBRARY := 1
FORCE_STATIC_LIB := 1

CPPSRCS := \
  nsDASHMPDParser.cpp \
  IMPDManager.cpp \
  nsDASHWebMODManager.cpp \
  nsDASHWebMODParser.cpp \
  MPD.cpp \
  Period.cpp \
  AdaptationSet.cpp \
  Representation.cpp \
  SegmentBase.cpp \
  $(NULL)


LOCAL_INCLUDES := \
  -I$(topsrcdir)/content/base/src \
  -I$(topsrcdir)/content/html/content/public \
  -I$(topsrcdir)/content/html/content/src \
  $(NULL)

include $(topsrcdir)/config/rules.mk

DEFINES += -DIMPL_NS_NET
