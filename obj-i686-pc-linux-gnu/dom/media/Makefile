# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/media
VPATH            = /home/txema/work/firefox-20.0+build1/dom/media
relativesrcdir   = dom/media

include $(DEPTH)/config/autoconf.mk

MODULE           = dom
XPIDL_MODULE     = dom_media
LIBRARY_NAME     = dom_media_s
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1
ifndef _MSC_VER
FAIL_ON_WARNINGS := 1
endif # !_MSC_VER

include $(topsrcdir)/dom/dom-config.mk

EXTRA_COMPONENTS = \
  PeerConnection.js \
  PeerConnection.manifest \
  $(NULL)

XPIDLSRCS = \
  nsIDOMMediaStream.idl \
  nsIDOMRTCPeerConnection.idl \
  nsIDOMNavigatorUserMedia.idl \
  nsIMediaManager.idl \
  $(NULL)

EXPORTS_NAMESPACE = mozilla

EXPORTS_mozilla = \
  MediaManager.h \
  $(NULL)

CPPSRCS = \
  MediaManager.cpp \
  $(NULL)

ifdef MOZ_WEBRTC
LOCAL_INCLUDES += \
  -I$(topsrcdir)/media/webrtc/trunk/src \
  -I$(topsrcdir)/media/webrtc/signaling/src/common \
  $(NULL)
DIRS += bridge
endif

TEST_DIRS += \
  tests/mochitest \
  $(NULL)

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/config/rules.mk
