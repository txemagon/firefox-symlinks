#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/xslt
VPATH		= /home/txema/work/firefox-20.0+build1/content/xslt

include $(DEPTH)/config/autoconf.mk

PARALLEL_DIRS = public src

TEST_DIRS += tests/buster \
             tests/mochitest

include $(topsrcdir)/config/rules.mk
