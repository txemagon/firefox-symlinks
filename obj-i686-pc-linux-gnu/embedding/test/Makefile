#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/embedding/test
VPATH		= /home/txema/work/firefox-20.0+build1/embedding/test
relativesrcdir  = embedding/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = \
	test_bug293834.html \
	bug293834_form.html \
	320x240.ogv \
	test_bug449141.html \
	bug449141_page.html \
	test_bug499115.html \
	test_nsFind.html \
	test_private_window_from_content.html \
	test_window_open_units.html \
	$(NULL)

include $(topsrcdir)/config/rules.mk
