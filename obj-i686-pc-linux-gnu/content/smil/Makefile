#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/smil
VPATH		= /home/txema/work/firefox-20.0+build1/content/smil

include $(DEPTH)/config/autoconf.mk

MODULE		= content
LIBRARY_NAME	= gkconsmil_s
LIBXUL_LIBRARY	= 1
ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER

EXPORTS	= \
	nsISMILAnimationElement.h \
	nsISMILAttr.h \
	nsISMILType.h \
	nsSMILAnimationController.h \
	nsSMILAnimationFunction.h \
	nsSMILCompositorTable.h \
	nsSMILCSSProperty.h \
	nsSMILInstanceTime.h \
	nsSMILInterval.h \
	nsSMILKeySpline.h \
	nsSMILMappedAttribute.h \
	nsSMILMilestone.h \
	nsSMILNullType.h \
	nsSMILRepeatCount.h \
	nsSMILSetAnimationFunction.h \
	nsSMILTargetIdentifier.h \
	nsSMILTimeContainer.h \
	nsSMILTimedElement.h \
	nsSMILTimeValue.h \
	nsSMILTimeValueSpec.h \
	nsSMILTimeValueSpecParams.h \
	nsSMILTypes.h \
	nsSMILValue.h \
	$(NULL)

CPPSRCS	= \
	nsDOMTimeEvent.cpp \
	nsSMILAnimationController.cpp \
	nsSMILAnimationFunction.cpp \
	nsSMILCompositor.cpp \
	nsSMILCSSProperty.cpp \
	nsSMILCSSValueType.cpp \
	nsSMILFloatType.cpp \
	nsSMILInstanceTime.cpp \
	nsSMILInterval.cpp \
	nsSMILKeySpline.cpp \
	nsSMILMappedAttribute.cpp \
	nsSMILNullType.cpp \
	nsSMILParserUtils.cpp \
	nsSMILRepeatCount.cpp \
	nsSMILSetAnimationFunction.cpp \
	nsSMILTimeContainer.cpp \
	nsSMILTimedElement.cpp \
	nsSMILTimeValue.cpp \
	nsSMILTimeValueSpec.cpp \
	nsSMILValue.cpp \
	SMILBoolType.cpp \
	SMILEnumType.cpp \
	SMILIntegerType.cpp \
	SMILStringType.cpp \
	$(NULL)

include $(topsrcdir)/config/config.mk

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

ifdef ENABLE_TESTS
TOOL_DIRS		+= test
endif # ENABLE_TESTS

INCLUDES += 	\
		-I$(srcdir)/../base/src \
		-I$(srcdir)/../../layout/style \
		-I$(srcdir)/../events/src \
		$(NULL)

include $(topsrcdir)/config/rules.mk

DEFINES += -D_IMPL_NS_LAYOUT
