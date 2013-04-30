# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/other-licenses/snappy

VPATH = \
  /home/txema/work/firefox-20.0+build1/other-licenses/snappy \
  $(topsrcdir)/other-licenses/snappy/src
  $(NULL)

include $(DEPTH)/config/autoconf.mk

LIBRARY_NAME = snappy_s

FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1

CPPSRCS = \
  snappy.cc \
  snappy-sinksource.cc \
  snappy-stubs-internal.cc \
  snappy-c.cc \
  $(NULL)

EXPORTS_NAMESPACES = snappy

EXPORTS_snappy = \
  snappy.h \
  snappy-c.h \
  snappy-stubs-public.h \
  $(NULL)

include $(topsrcdir)/config/rules.mk
