#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpcom/typelib/xpidl
VPATH		= /home/txema/work/firefox-20.0+build1/xpcom/typelib/xpidl

include $(topsrcdir)/config/config.mk

MODULE		= xpcom

SDK_BINARY = \
  $(topsrcdir)/xpcom/idl-parser/xpidl.py \
  $(topsrcdir)/xpcom/idl-parser/header.py \
  $(topsrcdir)/xpcom/idl-parser/typelib.py \
  $(DEPTH)/xpcom/idl-parser/xpidllex.py \
  $(DEPTH)/xpcom/idl-parser/xpidlyacc.py \
  $(NULL)

ifndef MOZ_SYSTEM_PLY
$(SDK_BIN_DIR)/ply::
	$(NSINSTALL) -D $@

PLY_SRCS = \
  $(topsrcdir)/other-licenses/ply/ply/__init__.py \
  $(topsrcdir)/other-licenses/ply/ply/lex.py \
  $(topsrcdir)/other-licenses/ply/ply/yacc.py \
  $(NULL)

export:: $(PLY_SRCS) $(SDK_BIN_DIR)/ply
	$(INSTALL) $(IFLAGS2) $^
endif

include $(topsrcdir)/config/rules.mk

export::
	@$(MAKE) libs
