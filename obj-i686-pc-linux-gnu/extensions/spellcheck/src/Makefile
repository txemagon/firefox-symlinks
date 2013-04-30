# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/extensions/spellcheck/src
VPATH		= /home/txema/work/firefox-20.0+build1/extensions/spellcheck/src

include $(DEPTH)/config/autoconf.mk

MODULE		= spellchecker
LIBRARY_NAME	= spellchecker
MODULE_NAME     = mozSpellCheckerModule
SHORT_LIBNAME   = spellchk
EXPORT_LIBRARY  = 1
IS_COMPONENT	= 1
LIBXUL_LIBRARY  = 1


CPPSRCS		= \
		mozSpellCheckerFactory.cpp	\
		mozSpellChecker.cpp		\
		mozPersonalDictionary.cpp	\
		mozEnglishWordUtils.cpp		\
		mozGenericWordUtils.cpp		\
		mozSpellI18NManager.cpp		\
		mozInlineSpellChecker.cpp	\
		mozInlineSpellWordUtil.cpp      \
		$(NULL)

SHARED_LIBRARY_LIBS += ../hunspell/src/$(LIB_PREFIX)hunspell_s.$(LIB_SUFFIX)

include $(topsrcdir)/config/rules.mk

LOCAL_INCLUDES += \
	-I$(srcdir)/../hunspell/src \
	-I$(topsrcdir)/content/base/src \
	-I$(topsrcdir)/editor/libeditor/base \
	$(NULL)
