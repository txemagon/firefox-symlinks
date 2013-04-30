# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/camera
VPATH            = /home/txema/work/firefox-20.0+build1/dom/camera

include $(DEPTH)/config/autoconf.mk

MODULE           = dom
LIBRARY_NAME     = domcamera_s
XPIDL_MODULE     = dom_camera
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1
FAIL_ON_WARNINGS := 1

include $(topsrcdir)/dom/dom-config.mk

CPPSRCS = \
  DOMCameraManager.cpp \
  DOMCameraControl.cpp \
  DOMCameraPreview.cpp \
  DOMCameraCapabilities.cpp \
  CameraControlImpl.cpp \
  CameraRecorderProfiles.cpp \
  $(NULL)

ifeq ($(MOZ_B2G_CAMERA),1)
CPPSRCS += \
  GonkCameraManager.cpp \
  GonkCameraControl.cpp \
  GonkCameraHwMgr.cpp \
  GonkNativeWindow.cpp \
  GonkRecorder.cpp \
  GonkCameraSource.cpp \
  AudioParameter.cpp \
  GonkRecorderProfiles.cpp \
  $(NULL)
else ifeq (gonk,$(MOZ_WIDGET_TOOLKIT))
CPPSRCS += \
  FallbackCameraManager.cpp \
  FallbackCameraControl.cpp \
  GonkNativeWindow.cpp \
  $(NULL)
else
CPPSRCS += \
  FallbackCameraManager.cpp \
  FallbackCameraControl.cpp \
  $(NULL)
endif

XPIDLSRCS = \
  nsIDOMNavigatorCamera.idl \
  nsIDOMCameraManager.idl \
  $(NULL)

EXPORTS = \
  CameraCommon.h \
  DOMCameraManager.h \
  GonkNativeWindow.h \
  $(NULL)

include $(topsrcdir)/config/rules.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/base \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/events \
  -I$(topsrcdir)/dom/media \
  $(NULL)
