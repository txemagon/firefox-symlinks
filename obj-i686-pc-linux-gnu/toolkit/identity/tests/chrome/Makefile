# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/toolkit/identity/tests/chrome
VPATH          = /home/txema/work/firefox-20.0+build1/toolkit/identity/tests/chrome
relativesrcdir = toolkit/identity/tests/chrome

include $(DEPTH)/config/autoconf.mk

MOCHITEST_CHROME_FILES = \
		sandbox_content.html \
		sandbox_content_alert.html \
		sandbox_content_framed.html \
		sandbox_content_perms.html \
		sandbox_content_popup.html \
		sandbox_content_redirect.html \
		sandbox_content_redirect.html^headers^ \
		sandbox_content.sjs \
		test_sandbox.xul \
		$(NULL)

include $(topsrcdir)/config/rules.mk
