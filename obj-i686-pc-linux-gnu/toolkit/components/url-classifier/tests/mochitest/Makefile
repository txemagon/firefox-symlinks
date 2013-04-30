#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/components/url-classifier/tests/mochitest
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/components/url-classifier/tests/mochitest
relativesrcdir  = toolkit/components/url-classifier/tests/mochitest

MODULE = test_url-classifier

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = \
		test_classifier.html \
		test_classifier_worker.html \
		classifierFrame.html \
		workerFrame.html \
		cleanWorker.js \
		evil.js \
		evilWorker.js \
		evil.css \
		import.css \
		$(NULL)

MOCHITEST_CHROME_FILES = \
  test_lookup_system_principal.html \
  $(NULL)


include $(topsrcdir)/config/rules.mk
