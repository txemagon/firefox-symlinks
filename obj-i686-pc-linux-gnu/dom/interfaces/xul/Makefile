#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/dom/interfaces/xul
VPATH		= /home/txema/work/firefox-20.0+build1/dom/interfaces/xul

include $(DEPTH)/config/autoconf.mk

MODULE		= dom
XPIDL_MODULE	= dom_xul
GRE_MODULE	= 1

XPIDLSRCS =					\
	nsIDOMXULButtonElement.idl              \
	nsIDOMXULCheckboxElement.idl          \
	nsIDOMXULCommandDispatcher.idl		\
	nsIDOMXULCommandEvent.idl \
	nsIDOMXULControlElement.idl          \
	nsIDOMXULDescriptionElement.idl         \
	nsIDOMXULDocument.idl			\
	nsIDOMXULElement.idl			\
	nsIDOMXULContainerElement.idl \
	nsIDOMXULImageElement.idl               \
	nsIDOMXULLabelElement.idl               \
	nsIDOMXULLabeledControlEl.idl          \
	nsIDOMXULMenuListElement.idl     \
	nsIDOMXULPopupElement.idl          \
	nsIDOMXULRelatedElement.idl \
	nsIDOMXULSelectCntrlEl.idl       \
	nsIDOMXULSelectCntrlItemEl.idl   \
	nsIDOMXULMultSelectCntrlEl.idl \
	nsIDOMXULTextboxElement.idl \
	nsIDOMXULTreeElement.idl \
	$(NULL)

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/core \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
