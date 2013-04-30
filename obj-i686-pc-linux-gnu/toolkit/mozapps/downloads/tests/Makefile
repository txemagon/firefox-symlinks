#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/toolkit/mozapps/downloads/tests
VPATH          = /home/txema/work/firefox-20.0+build1/toolkit/mozapps/downloads/tests
relativesrcdir = toolkit/mozapps/downloads/tests

include $(DEPTH)/config/autoconf.mk

MODULE = test_downloads

XPCSHELL_TESTS = \
  unit \
  $(NULL)

DIRS += chrome

include $(topsrcdir)/config/rules.mk

libs:: 
	$(INSTALL) $(topsrcdir)/testing/specialpowers/content/MockFilePicker.jsm $(DEPTH)/_tests/xpcshell/$(relativesrcdir)/unit
