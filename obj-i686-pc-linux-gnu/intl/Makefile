#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/intl
VPATH     = /home/txema/work/firefox-20.0+build1/intl

include $(DEPTH)/config/autoconf.mk

PARALLEL_DIRS = \
  hyphenation \
  locale \
  locales \
  lwbrk \
  strres \
  unicharutil \
  $(NULL)

DIRS = \
  uconv \
  build \
  $(NULL)

include $(topsrcdir)/config/rules.mk
