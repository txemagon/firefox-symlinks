#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/devtools/shared
VPATH		= /home/txema/work/firefox-20.0+build1/browser/devtools/shared

include $(DEPTH)/config/autoconf.mk

TEST_DIRS += test

include $(topsrcdir)/config/rules.mk

libs::
	$(NSINSTALL) $(srcdir)/*.jsm $(FINAL_TARGET)/modules/devtools
