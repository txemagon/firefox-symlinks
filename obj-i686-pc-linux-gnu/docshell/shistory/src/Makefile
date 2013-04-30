#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/docshell/shistory/src
VPATH		= /home/txema/work/firefox-20.0+build1/docshell/shistory/src

include $(DEPTH)/config/autoconf.mk

MODULE		= shistory
LIBRARY_NAME	= shistory_s
FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY	= 1

EXPORTS		= nsSHEntryShared.h \
		  $(NULL)

CPPSRCS		= nsSHEntry.cpp        \
            nsSHTransaction.cpp   \
            nsSHistory.cpp \
	    nsSHEntryShared.cpp \
            $(NULL)

include $(topsrcdir)/config/rules.mk

LOCAL_INCLUDES += -I$(srcdir)/../../base
