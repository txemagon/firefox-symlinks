#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/mathml/content/src
VPATH		= /home/txema/work/firefox-20.0+build1/content/mathml/content/src

include $(DEPTH)/config/autoconf.mk

MODULE		= content
LIBRARY_NAME	= gkcontentmathml_s
LIBXUL_LIBRARY	= 1
ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER

CPPSRCS		= \
		nsMathMLElement.cpp               \
		nsMathMLElementFactory.cpp        \
		$(NULL)

include $(topsrcdir)/config/config.mk

# we don't want the shared lib, but we want to force the creation of a static 
# lib.
FORCE_STATIC_LIB = 1

EXPORTS = \
	$(NULL)


include $(topsrcdir)/config/rules.mk

INCLUDES += 	\
		-I$(srcdir)/../../../base/src \
		$(NULL)

DEFINES += -D_IMPL_NS_LAYOUT
