#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/xpcom/idl-parser
VPATH = /home/txema/work/firefox-20.0+build1/xpcom/idl-parser

include $(DEPTH)/config/autoconf.mk

PARSER_SRCS = \
  header.py \
  typelib.py \
  xpidl.py \
  $(NULL)

ifndef MOZ_SYSTEM_PLY
PLY_PROGS = \
  $(topsrcdir)/other-licenses/ply/ply/lex.py \
  $(topsrcdir)/other-licenses/ply/ply/yacc.py \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk

# Generate the PLY lexer and parser.
export:: $(PARSER_SRCS) $(PLY_PROGS)
	$(PYTHON_PATH) \
	  $(PLY_INCLUDE) \
	  $(srcdir)/header.py --cachedir=. --regen

check::
	$(PYTHON_PATH) \
	  $(PLY_INCLUDE) \
	  -I. \
	  $(srcdir)/runtests.py

GARBAGE += \
  xpidllex.py \
  xpidllex.pyc \
  xpidlyacc.py \
  xpidlyacc.pyc \
  xpidl_debug \
  $(NULL)
