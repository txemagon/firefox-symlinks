# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/toolkit/devtools/webconsole/test
VPATH          = /home/txema/work/firefox-20.0+build1/toolkit/devtools/webconsole/test
relativesrcdir = toolkit/devtools/webconsole/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_CHROME_FILES = \
    test_basics.html \
    test_cached_messages.html \
    test_page_errors.html \
    test_consoleapi.html \
    test_jsterm.html \
    test_object_actor.html \
    test_network_get.html \
    test_network_post.html \
    test_network_longstring.html \
    test_file_uri.html \
    test_bug819670_getter_throws.html \
    network_requests_iframe.html \
    data.json \
    data.json^headers^ \
    common.js \
    $(NULL)

include $(topsrcdir)/config/rules.mk
