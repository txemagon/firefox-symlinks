# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/media/webrtc
VPATH		= /home/txema/work/firefox-20.0+build1/content/media/webrtc

include $(DEPTH)/config/autoconf.mk

MODULE = content
LIBRARY_NAME = gkconwebrtc_s
LIBXUL_LIBRARY = 1

EXPORTS	+= \
  MediaEngine.h \
  MediaEngineDefault.h \
  $(NULL)

CPPSRCS	= \
  MediaEngineDefault.cpp \
  $(NULL)

ifdef MOZ_WEBRTC
EXPORTS += \
  MediaEngineWebRTC.h \
  $(NULL)

CPPSRCS += \
  MediaEngineWebRTC.cpp \
  MediaEngineWebRTCVideo.cpp \
  MediaEngineWebRTCAudio.cpp \
  $(NULL)
endif

FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

ifdef MOZ_WEBRTC
LOCAL_INCLUDES += \
  -I$(topsrcdir)/media/webrtc/trunk/src \
  -I$(topsrcdir)/media/webrtc/signaling/src/common \
  $(NULL)
endif
