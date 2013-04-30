#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


#
# We want to run the tests in our own (modified) harness.
#

DEPTH		= ../../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/testing/mochitest/tests/MochiKit-1.4.2/tests/SimpleTest
VPATH		= /home/txema/work/firefox-20.0+build1/testing/mochitest/tests/MochiKit-1.4.2/tests/SimpleTest
relativesrcdir  = testing/mochitest/tests/MochiKit-1.4.2/tests/SimpleTest

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_STUBS_FILES = \
	test.css \
	$(NULL)

libs:: $(_STUBS_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/$(relativesrcdir)
