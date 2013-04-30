# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           = ../../../../..
topsrcdir       = /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/toolkit/components/osfile/tests/mochi
VPATH           = /home/txema/work/firefox-20.0+build1/toolkit/components/osfile/tests/mochi
relativesrcdir  = toolkit/components/osfile/tests/mochi

include $(DEPTH)/config/autoconf.mk

MODULE          = osfile

MOCHITEST_CHROME_FILES := \
  test_osfile_back.xul \
  worker_handler.js \
  worker_test_osfile_shared.js \
  worker_test_osfile_unix.js \
  worker_test_osfile_win.js \
  test_osfile_front.xul \
  worker_test_osfile_front.js \
  test_osfile_comms.xul \
  worker_test_osfile_comms.js \
  test_osfile_async.xul \
  main_test_osfile_async.js \
  $(NULL)

include $(topsrcdir)/config/rules.mk
