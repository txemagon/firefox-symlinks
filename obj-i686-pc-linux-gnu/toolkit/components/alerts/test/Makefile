#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH   = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/components/alerts/test
VPATH   = /home/txema/work/firefox-20.0+build1/toolkit/components/alerts/test
relativesrcdir  = toolkit/components/alerts/test

include $(DEPTH)/config/autoconf.mk

# Mochitest tests
# Synchronous tests like test_alerts.html must come before
# asynchronous tests like test_alerts_noobserve.html!
MOCHITEST_FILES = \
		test_alerts.html \
		test_alerts_noobserve.html \
		$(NULL)

include $(topsrcdir)/config/rules.mk
