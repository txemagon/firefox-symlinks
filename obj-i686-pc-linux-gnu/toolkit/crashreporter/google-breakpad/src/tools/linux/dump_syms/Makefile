# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/crashreporter/google-breakpad/src/tools/linux/dump_syms
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/crashreporter/google-breakpad/src/tools/linux/dump_syms

include $(DEPTH)/config/autoconf.mk

HOST_PROGRAM = dump_syms

LOCAL_INCLUDES 	= \
  -I$(srcdir)/../../.. \
  -I$(srcdir)/../../../common/linux \
  $(NULL)

HOST_CPPSRCS = \
  dump_syms.cc \
  $(NULL)

HOST_LIBS += \
  $(DEPTH)/toolkit/crashreporter/google-breakpad/src/common/linux/$(LIB_PREFIX)host_breakpad_linux_common_s.$(LIB_SUFFIX) \
  $(DEPTH)/toolkit/crashreporter/google-breakpad/src/common/$(LIB_PREFIX)host_breakpad_common_s.$(LIB_SUFFIX) \
  $(DEPTH)/toolkit/crashreporter/google-breakpad/src/common/dwarf/$(LIB_PREFIX)host_breakpad_dwarf_s.$(LIB_SUFFIX) \
  $(NULL)

include $(topsrcdir)/config/rules.mk
