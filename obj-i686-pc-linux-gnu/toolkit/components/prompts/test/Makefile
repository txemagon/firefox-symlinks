#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/toolkit/components/prompts/test
VPATH          = /home/txema/work/firefox-20.0+build1/toolkit/components/prompts/test
relativesrcdir = toolkit/components/prompts/test

include $(DEPTH)/config/autoconf.mk

# Module name for xpcshell tests.
MODULE = test_prompter

# Mochitest tests
MOCHITEST_FILES = \
    test_modal_select.html \
    test_modal_prompts.html \
    test_bug619644.html \
    test_bug620145.html \
    test_bug625187.html \
    prompt_common.js \
    bug619644_inner.html \
    bug625187_iframe.html \
    $(NULL)

include $(topsrcdir)/config/rules.mk
