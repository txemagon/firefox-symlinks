#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/dom/interfaces/css
VPATH		= /home/txema/work/firefox-20.0+build1/dom/interfaces/css

include $(DEPTH)/config/autoconf.mk

MODULE		= dom
XPIDL_MODULE	= dom_css
GRE_MODULE	= 1

SDK_XPIDLSRCS = 				\
	nsIDOMCSSPrimitiveValue.idl		\
	nsIDOMCSSRule.idl			\
	nsIDOMCSSRuleList.idl			\
	nsIDOMCSSStyleDeclaration.idl		\
	nsIDOMCSSStyleSheet.idl			\
	nsIDOMCSSValue.idl			\
	nsIDOMCSSValueList.idl			\
	nsIDOMElementCSSInlineStyle.idl		\
	$(NULL)

XPIDLSRCS =					\
	nsIDOMCSSCharsetRule.idl		\
	nsIDOMCSSConditionRule.idl		\
	nsIDOMCSSFontFaceRule.idl		\
	nsIDOMCSSGroupingRule.idl		\
	nsIDOMCSSImportRule.idl			\
	nsIDOMCSSMediaRule.idl			\
	nsIDOMCSSMozDocumentRule.idl		\
	nsIDOMCSSSupportsRule.idl		\
	nsIDOMMozCSSKeyframeRule.idl		\
	nsIDOMMozCSSKeyframesRule.idl		\
	nsIDOMCSSPageRule.idl			\
	nsIDOMCSSStyleRule.idl			\
	nsIDOMCSSUnknownRule.idl		\
	nsIDOMCounter.idl			\
	nsIDOMRect.idl				\
	$(NULL)

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/stylesheets \
  $(NULL)
