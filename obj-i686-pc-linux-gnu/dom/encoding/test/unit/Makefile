# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/dom/encoding/test/unit
VPATH = /home/txema/work/firefox-20.0+build1/dom/encoding/test/unit
relativesrcdir = dom/encoding/test/unit

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = \
  test_big5.js \
  test_euc-jp.js \
  test_euc-kr.js \
  test_gbk.js \
  test_hz-gb-2312.js \
  test_iso-2022-jp.js \
  test_iso-2022-kr.js \
  test_shift_jis.js \
  test_singlebytes.js \
  $(NULL)

include $(topsrcdir)/config/rules.mk

