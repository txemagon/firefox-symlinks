# -*- makefile -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.
#

PYTHON ?= python
PYTEST = $(PYTHON) -E

# python -B not supported by older interpreters
export PYTHONDONTWRITEBYTECODE=1

DEPTH     = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/config/tests/makefiles/autodeps
VPATH     = /home/txema/work/firefox-20.0+build1/config/tests/makefiles/autodeps

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/config.mk
include $(topsrcdir)/config/rules.mk

autotgt_tests = .deps/autotargets.mk.ts

tgts =\
  .deps/.mkdir.done\
  $(autotgt_tests)
  $(NULL)

export MAKE
export .PYMAKE

##------------------_##
##---]  TARGETS  [---##
##------------------_##
all::

check:: $(tgts)

# Only run unit test when autotargets.mk is modified
$(autotgt_tests): $(topsrcdir)/config/makefiles/autotargets.mk
	$(PYTEST) $(srcdir)/check_mkdir.tpy
	@$(TOUCH) $@
