# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/security/manager/ssl/tests/mochitest/stricttransportsecurity
VPATH		= /home/txema/work/firefox-20.0+build1/security/manager/ssl/tests/mochitest/stricttransportsecurity
relativesrcdir	= security/ssl/stricttransportsecurity

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = \
  plain_bootstrap.html \
  plain_bootstrap.html^headers^ \
  subdom_bootstrap.html \
  subdom_bootstrap.html^headers^ \
  nosts_bootstrap.html \
  nosts_bootstrap.html^headers^ \
  verify.sjs \
  test_stricttransportsecurity.html \
  $(NULL)

ifdef MOZ_PER_WINDOW_PRIVATE_BROWSING
MOCHITEST_CHROME_FILES += \
  test_sts_privatebrowsing_perwindowpb.html \
  page_blank.html \
  $(NULL)
else
MOCHITEST_FILES += \
  test_sts_privatebrowsing.html \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk
