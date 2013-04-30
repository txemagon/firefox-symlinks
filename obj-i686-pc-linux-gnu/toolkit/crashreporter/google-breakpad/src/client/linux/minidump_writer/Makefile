# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/crashreporter/google-breakpad/src/client/linux/minidump_writer
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/crashreporter/google-breakpad/src/client/linux/minidump_writer

include $(DEPTH)/config/autoconf.mk

MODULE		= writer
LIBRARY_NAME	= minidump_writer_s
XPI_NAME 	= crashreporter

LOCAL_INCLUDES = \
  -I$(topsrcdir)/toolkit/crashreporter/google-breakpad/src \
  $(NULL)

CPPSRCS	= \
  linux_dumper.cc \
  linux_ptrace_dumper.cc \
  minidump_writer.cc \
  $(NULL)

# need static lib
FORCE_STATIC_LIB = 1

ifeq ($(OS_TARGET),Android)
LOCAL_INCLUDES += -I$(topsrcdir)/toolkit/crashreporter/google-breakpad/src/common/android/include/
endif

ifeq (gonk,$(MOZ_WIDGET_TOOLKIT))
DEFINES += -DELFSIZE=32
endif

include $(topsrcdir)/config/rules.mk
