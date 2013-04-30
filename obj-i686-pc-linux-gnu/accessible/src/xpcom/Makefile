#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/accessible/src/xpcom
VPATH = /home/txema/work/firefox-20.0+build1/accessible/src/xpcom

include $(DEPTH)/config/autoconf.mk

MODULE = accessibility
LIBRARY_NAME = accessibility_xpcom_s
LIBXUL_LIBRARY = 1

CPPSRCS = \
  nsAccEvent.cpp \
  nsAccessibleRelation.cpp \
  xpcAccessibleTable.cpp \
  xpcAccessibleTableCell.cpp \
  $(NULL)

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

LOCAL_INCLUDES = \
  -I$(srcdir)/../base \
  -I$(srcdir)/../generic \
  $(NULL)

ifeq ($(MOZ_WIDGET_TOOLKIT),gtk2)
LOCAL_INCLUDES += \
  -I$(srcdir)/../atk \
  $(NULL)
else
ifeq ($(MOZ_WIDGET_TOOLKIT),windows)
LOCAL_INCLUDES += \
  -I$(srcdir)/../msaa \
  $(NULL)
else
ifeq ($(MOZ_WIDGET_TOOLKIT),cocoa)
LOCAL_INCLUDES += \
  -I$(srcdir)/../mac \
  $(NULL)
else
LOCAL_INCLUDES += \
  -I$(srcdir)/../other \
  $(NULL)
endif
endif
endif

ifneq ($(A11Y_LOG),0)
  DEFINES += -DA11Y_LOG
endif
