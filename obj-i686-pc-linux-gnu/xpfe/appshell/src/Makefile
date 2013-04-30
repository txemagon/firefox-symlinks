#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpfe/appshell/src
VPATH		= /home/txema/work/firefox-20.0+build1/xpfe/appshell/src

include $(DEPTH)/config/autoconf.mk

IS_COMPONENT=1
MODULE_NAME	= appshell
MODULE		= appshell
LIBRARY_NAME	= nsappshell
EXPORT_LIBRARY  = 1
SHORT_LIBNAME	= appshell
GRE_MODULE	= 1
LIBXUL_LIBRARY	= 1


CPPSRCS		= \
		nsChromeTreeOwner.cpp \
		nsContentTreeOwner.cpp \
		nsXULWindow.cpp \
		nsAppShellService.cpp \
		nsAppShellWindowEnumerator.cpp \
		nsWebShellWindow.cpp \
		nsWindowMediator.cpp \
		nsAppShellFactory.cpp \
		$(NULL)

PARALLEL_DIRS := test

include $(topsrcdir)/config/rules.mk

