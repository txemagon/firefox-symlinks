#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH      = ../../..
topsrcdir  = /home/txema/work/firefox-20.0+build1
srcdir     = /home/txema/work/firefox-20.0+build1/widget/shared/x11
VPATH      = /home/txema/work/firefox-20.0+build1/widget/shared/x11

include $(DEPTH)/config/autoconf.mk

MODULE     = widget
LIBRARY_NAME   = widget_shared_x11
LIBXUL_LIBRARY  = 1


CSRCS      = \
       keysym2ucs.c \
       $(NULL)

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/config/rules.mk

CXXFLAGS   += $(TK_CFLAGS)
