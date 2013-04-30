#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


DEPTH     = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/components/url-classifier/tests
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/components/url-classifier/tests
relativesrcdir  = toolkit/components/url-classifier/tests

include $(DEPTH)/config/autoconf.mk

MODULE = test_url-classifier

MOZILLA_INTERNAL_API = 1


# mochitest tests
DIRS += mochitest \
	$(NULL)

# xpcshell tests
XPCSHELL_TESTS=unit

# XXX Get this to work in libxul builds.
## simple c++ tests (no xpcom)
#CPP_UNIT_TESTS = \
#	TestUrlClassifierUtils.cpp \
#	$(NULL)

include $(topsrcdir)/config/rules.mk
