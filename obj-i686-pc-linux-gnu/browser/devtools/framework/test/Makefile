# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH			= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/devtools/framework/test
VPATH			= /home/txema/work/firefox-20.0+build1/browser/devtools/framework/test
relativesrcdir  = browser/devtools/framework/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_BROWSER_FILES = \
		head.js \
		browser_devtools_api.js \
		browser_new_activation_workflow.js \
		browser_toolbox_dynamic_registration.js \
		browser_toolbox_hosts.js \
		browser_toolbox_ready.js \
		browser_toolbox_select_event.js \
		browser_target_events.js \
		browser_toolbox_tool_ready.js \
		browser_toolbox_sidebar.js \
		browser_toolbox_window_shortcuts.js \
		$(NULL)

include $(topsrcdir)/config/rules.mk
