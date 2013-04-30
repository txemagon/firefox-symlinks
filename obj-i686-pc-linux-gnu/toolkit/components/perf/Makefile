# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/perf
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/perf

include $(DEPTH)/config/autoconf.mk

MODULE = jsperf
MODULE_NAME = jsperf
GRE_MODULE = 1

EXTRA_JS_MODULES = \
    PerfMeasurement.jsm \
    $(NULL)

LIBRARY_NAME = jsperf
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1
IS_COMPONENT = 1
FAIL_ON_WARNINGS = 1

CPPSRCS = \
    PerfMeasurement.cpp \
    $(NULL)

LOCAL_INCLUDES := \
  -I$(topsrcdir)/js/xpconnect/loader \
  $(NULL)

ifdef ENABLE_TESTS
MOCHITEST_CHROME_FILES = \
    test_pm.xul \
    $(NULL)
endif

include $(topsrcdir)/config/rules.mk
