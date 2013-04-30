#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/netwerk/protocol/data
VPATH     = /home/txema/work/firefox-20.0+build1/netwerk/protocol/data
FAIL_ON_WARNINGS = 1

include $(DEPTH)/config/autoconf.mk

MODULE         = necko
LIBRARY_NAME   = nkdata_s
LIBXUL_LIBRARY = 1

FORCE_STATIC_LIB = 1

CPPSRCS = \
  nsDataHandler.cpp \
  nsDataChannel.cpp \
  $(NULL)

LOCAL_INCLUDES = \
  -I$(srcdir)/../../base/src \
  $(NULL)

include $(topsrcdir)/config/rules.mk
