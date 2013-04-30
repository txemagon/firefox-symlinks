#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/layout/tables
VPATH		= /home/txema/work/firefox-20.0+build1/layout/tables

include $(DEPTH)/config/autoconf.mk

MODULE		= layout
LIBRARY_NAME	= gktable_s
LIBXUL_LIBRARY	= 1
ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER



EXPORTS		= \
		nsITableCellLayout.h \
		$(NULL)

CPPSRCS		= \
		BasicTableLayoutStrategy.cpp \
		FixedTableLayoutStrategy.cpp \
		SpanningCellSorter.cpp \
		nsCellMap.cpp \
		nsTableCellFrame.cpp \
		nsTableColFrame.cpp \
		nsTableColGroupFrame.cpp \
		nsTableFrame.cpp \
		nsTableOuterFrame.cpp \
		nsTableRowFrame.cpp \
		nsTableRowGroupFrame.cpp \
		nsTablePainter.cpp \
		$(NULL)

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

TEST_DIRS += test


include $(topsrcdir)/config/rules.mk

DEFINES         += -DDEBUG_TABLE_STRATEGY_off -D_IMPL_NS_LAYOUT

LOCAL_INCLUDES	= \
		-I$(srcdir)/../base \
		-I$(srcdir)/../generic \
		-I$(srcdir)/../style \
		-I$(srcdir)/../xul/base/src \
		-I$(srcdir)/../../content/html/content/src \
		-I$(srcdir)/../../content/base/src \
		-I$(srcdir)/../../intl/unicharutil/util \
		$(NULL)
