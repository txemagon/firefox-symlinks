# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/workers/test/extensions/traditional
VPATH            = /home/txema/work/firefox-20.0+build1/dom/workers/test/extensions/traditional

include $(DEPTH)/config/autoconf.mk

XPI_NAME = worker
XPIDL_MODULE = WorkerTest

XPIDLSRCS = \
  nsIWorkerTest.idl \
  $(NULL)

EXTRA_COMPONENTS = \
  WorkerTest.js \
  WorkerTest.manifest \
  $(NULL)

DIST_FILES = \
  install.rdf \
  worker.js \
  $(NULL)

TEST_EXTENSIONS_DIR = $(DEPTH)/_tests/testing/mochitest/extensions

GENERATED_DIRS = $(TEST_EXTENSIONS_DIR)

include $(topsrcdir)/config/rules.mk

libs::
	@(cd $(DIST)/xpi-stage && tar $(TAR_CREATE_FLAGS) - $(XPI_NAME)) | (cd $(TEST_EXTENSIONS_DIR) && tar -xf -)
