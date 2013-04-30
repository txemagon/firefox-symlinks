#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH=../../..
topsrcdir=/home/txema/work/firefox-20.0+build1
srcdir=/home/txema/work/firefox-20.0+build1/layout/inspector/src
VPATH=/home/txema/work/firefox-20.0+build1/layout/inspector/src

include $(DEPTH)/config/autoconf.mk

MODULE = inspector
LIBRARY_NAME = inspector_s
LIBXUL_LIBRARY = 1
FAIL_ON_WARNINGS = 1

EXPORTS = \
  nsFontFace.h \
  nsFontFaceList.h \
  $(NULL)

CPPSRCS= \
  inDeepTreeWalker.cpp \
  inFlasher.cpp \
  inSearchLoop.cpp \
  inCSSValueSearch.cpp \
  inDOMUtils.cpp \
  inLayoutUtils.cpp \
  nsFontFace.cpp \
  nsFontFaceList.cpp \
	$(NULL)

ifdef MOZ_XUL
CPPSRCS += \
  inDOMView.cpp \
  $(NULL)
endif

FORCE_STATIC_LIB = 1

LOCAL_INCLUDES	+= \
		-I$(srcdir)/../../style \
		-I$(topsrcdir)/content/xbl/src \
		$(NULL)

include $(topsrcdir)/config/rules.mk
