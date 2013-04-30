#!/usr/bin/make -f

# Various build defaults
# 1 = Enable crashreporter (if supported)
MOZ_ENABLE_BREAKPAD	?= 0
# 1 = Disable official branding and crash reporter (the crash reporter builds but is not enabled in application.ini)
MOZ_BUILD_UNOFFICIAL	?= 1
# 1 = Build without jemalloc suitable for valgrind debugging
MOZ_VALGRIND		?= 0
# 1 = Profile guided build
MOZ_BUILD_PGO		?= 0
# 1 = Build and run the testsuite
MOZ_WANT_UNIT_TESTS	?= 0
# 1 = Turn on debugging bits and disable optimizations
MOZ_DEBUG		?= 0
# 1 = Disable optimizations
MOZ_NO_OPTIMIZE		?= 0

# We need this to execute before the debian/control target gets called
clean::
	cp debian/control debian/control.old
ifneq (1, $(MOZ_DISABLE_CLEAN_CHECKS))
	touch debian/control.in
else
	touch debian/control
endif

-include /usr/share/cdbs/1/rules/debhelper.mk
-include /usr/share/cdbs/1/rules/patchsys-quilt.mk
-include /usr/share/cdbs/1/class/makefile.mk

MOZ_OBJDIR		:= $(DEB_BUILDDIR)/obj-$(DEB_HOST_GNU_TYPE)
MOZ_DISTDIR		:= $(MOZ_OBJDIR)/$(MOZ_MOZDIR)/dist

# The package name
MOZ_PKG_NAME		:= $(shell dpkg-parsechangelog | sed -n 's/^Source: *\(.*\)$$/\1/ p')
# The binary name to use (derived from the package name by default)
MOZ_APP_NAME		?= $(MOZ_PKG_NAME)

# Define other variables used throughout the build
# The value of "Name" to use in application.ini, which the profile location is based on.
# Derived from the desired MOZ_APP_NAME, but can be overridden
MOZ_APP_BASENAME	?= $(shell echo $(MOZ_APP_NAME) | sed -n 's/\-.\|\<./\U&/g p')
# The default value of "Name" in the application.ini, derived from the upstream build system
# It is used for the profile location. This should be set manually if not provided
MOZ_DEFAULT_APP_BASENAME ?= $(shell . ./$(DEB_SRCDIR)/$(MOZ_APP)/confvars.sh; echo $$MOZ_APP_BASENAME)
# Equal to upstreams default MOZ_APP_NAME. If not a lower case version of the "Name"
# in application.ini, then this should be manually overridden
MOZ_DEFAULT_APP_NAME	?= $(MOZ_DEFAULT_APP_BASENAME_L)
# Location for searchplugins
MOZ_SEARCHPLUGIN_DIR	?= $(MOZ_LIBDIR)/distribution/searchplugins

MOZ_APP_BASENAME_L	:= $(shell echo $(MOZ_APP_BASENAME) | tr A-Z a-z)
MOZ_DEFAULT_APP_BASENAME_L := $(shell echo $(MOZ_DEFAULT_APP_BASENAME) | tr A-Z a-z)

ifeq (,$(MOZ_APP))
$(error "Need to set MOZ_APP")
endif
ifeq (,$(MOZ_APP_NAME))
$(error "Need to set MOZ_APP_NAME")
endif
ifeq (,$(MOZ_PKG_NAME))
$(error "Need to set MOZ_PKG_NAME")
endif

MOZ_PKG_NAMES = $(shell sed -n 's/Package\: \(.*\)/\1/ p' < debian/control)

DEB_MAKE_MAKEFILE	:= client.mk
# Without this, CDBS passes CFLAGS and CXXFLAGS options to client.mk, which breaks the build
DEB_MAKE_EXTRA_ARGS	:=
# These normally come from autotools.mk, which we no longer include (because we
# don't want to run configure)
DEB_MAKE_INSTALL_TARGET	:= install DESTDIR=$(CURDIR)/debian/tmp
DEB_MAKE_CLEAN_TARGET	:= cleansrcdir
DEB_DH_STRIP_ARGS	:= --dbg-package=$(MOZ_PKG_NAME)-dbg
# We don't want build-tree/mozilla/README to be shipped as a doc
DEB_INSTALL_DOCS_ALL 	:= $(NULL)
# scour breaks the testsuite
DEB_DH_SCOUR_ARGS := -N$(MOZ_PKG_NAME)-testsuite

MOZ_VERSION		:= $(shell cat $(DEB_SRCDIR)/$(MOZ_APP)/config/version.txt)
MOZ_LIBDIR		:= usr/lib/$(MOZ_APP_NAME)
MOZ_INCDIR		:= usr/include/$(MOZ_APP_NAME)
MOZ_IDLDIR		:= usr/share/idl/$(MOZ_APP_NAME)
MOZ_SDKDIR		:= usr/lib/$(MOZ_APP_NAME)-devel
MOZ_ADDONDIR		:= usr/lib/$(MOZ_APP_NAME)-addons
MOZ_TESTDIR		:= usr/lib/$(MOZ_APP_NAME)-testsuite

# The profile directory is determined from the Vendor and Name fields of
# the application.ini
ifeq (,$(MOZ_VENDOR))
PROFILE_BASE =
else
PROFILE_BASE = $(shell echo $(MOZ_VENDOR) | tr A-Z a-z)/
endif
MOZ_PROFILEDIR		:= .$(PROFILE_BASE)$(MOZ_APP_BASENAME_L)
MOZ_DEFAULT_PROFILEDIR	:= .$(PROFILE_BASE)$(MOZ_DEFAULT_APP_BASENAME_L)

DEB_AUTO_UPDATE_DEBIAN_CONTROL	= no

MOZ_PYTHON		:= $(shell which python)
DISTRIB 		:= $(shell lsb_release -i -s)

CFLAGS			:= -g
CXXFLAGS		:= -g
LDFLAGS 		:= $(shell echo $$LDFLAGS | sed -e 's/-Wl,-Bsymbolic-functions//')

ifneq (,$(findstring nocheck,$(DEB_BUILD_OPTIONS)))
MOZ_WANT_UNIT_TESTS = 0
endif

ifeq (1,$(MOZ_VALGRIND))
MOZ_BUILD_UNOFFICIAL = 1
endif

ifneq (,$(findstring noopt,$(DEB_BUILD_OPTIONS)))
MOZ_BUILD_PGO = 0
MOZ_NO_OPTIMIZE	= 1
endif

ifneq (,$(findstring debug,$(DEB_BUILD_OPTIONS)))
MOZ_NO_OPTIMIZE = 1
MOZ_DEBUG = 1
MOZ_BUILD_UNOFFICIAL = 1
endif

include $(CURDIR)/debian/build/testsuite.mk

ifneq ($(MOZ_APP_NAME)$(MOZ_APP_BASENAME),$(MOZ_DEFAULT_APP_NAME)$(MOZ_DEFAULT_APP_BASENAME))
# If we change MOZ_APP_NAME or MOZ_APP_BASENAME, don't use official branding
MOZ_BUILD_UNOFFICIAL = 1
endif

# enable the crash reporter only on i386, amd64 and armel
ifeq (,$(filter lucid maverick natty oneiric,$(DISTRIB_CODENAME)))
SUPPORTED_ARM = armhf
else
SUPPORTED_ARM = armel
endif
ifeq (,$(filter i386 amd64 $(SUPPORTED_ARM),$(DEB_HOST_ARCH)))
MOZ_ENABLE_BREAKPAD = 0
endif

# powerpc sucks
ifneq (,$(filter powerpc,$(DEB_HOST_ARCH)))
MOZ_WANT_UNIT_TESTS = 0
endif

# Ensure the crash reporter gets disabled for derivatives
ifneq (Ubuntu, $(DISTRIB))
MOZ_ENABLE_BREAKPAD = 0
endif

MOZ_DISPLAY_NAME = $(shell cat $(DEB_SRCDIR)/$(MOZ_BRANDING_DIR)/locales/en-US/brand.properties \
		    | grep brandShortName | sed -e 's/brandShortName\=//')

ifeq (,$(filter 4.7, $(shell $(CC) -dumpversion)))
MOZ_BUILD_PGO = 0
endif

ifeq (,$(filter i386 amd64, $(DEB_HOST_ARCH)))
MOZ_BUILD_PGO = 0
endif

ifneq (,$(wildcard $(CURDIR)/debian/globalmenu))
HAVE_GLOBALMENU = 1
endif

ifeq (1,$(HAVE_GLOBALMENU))
ifeq (,$(filter lucid maverick, $(DISTRIB_CODENAME)))
MOZ_ENABLE_GLOBALMENU = 1
endif
endif

export NO_PNG_PKG_MANGLE=1
export LDFLAGS
export DEB_BUILD_HARDENING=1
export MOZCONFIG=$(CURDIR)/debian/config/mozconfig
ifeq (Ubuntu, $(DISTRIB))
export MOZ_UA_VENDOR=Ubuntu
endif
ifneq (1,$(MOZ_BUILD_UNOFFICIAL))
export BUILD_OFFICIAL=1
endif
ifeq (1,$(MOZ_ENABLE_BREAKPAD))
# Needed to enable crashreported in application.ini
export MOZILLA_OFFICIAL=1
endif

ifeq (linux-gnu, $(DEB_HOST_GNU_SYSTEM))
LANGPACK_DIR := linux-$(DEB_HOST_GNU_CPU)/xpi
else
LANGPACK_DIR := $(DEB_HOST_GNU_SYSTEM)-$(DEB_HOST_GNU_CPU)/xpi
endif

ifeq (1,$(MOZ_ENABLE_GLOBALMENU))
MOZ_PKG_SUPPORT_RECOMMENDS ?= $(MOZ_PKG_NAME)-globalmenu
endif
MOZ_PKG_SUPPORT_SUGGESTS ?= $(MOZ_PKG_NAME)-gnome-support

# Defines used for the Mozilla text preprocessor
MOZ_DEFINES += 	-DMOZ_LIBDIR="$(MOZ_LIBDIR)" -DMOZ_APP_NAME="$(MOZ_APP_NAME)" -DMOZ_APP_BASENAME="$(MOZ_APP_BASENAME)" \
		-DMOZ_INCDIR="$(MOZ_INCDIR)" -DMOZ_IDLDIR="$(MOZ_IDLDIR)" -DMOZ_VERSION="$(MOZ_VERSION)" -DDEB_HOST_ARCH="$(DEB_HOST_ARCH)" \
		-DMOZ_DISPLAY_NAME="$(MOZ_DISPLAY_NAME)" -DMOZ_PKG_NAME="$(MOZ_PKG_NAME)" \
		-DMOZ_BRANDING_OPTION="$(MOZ_BRANDING_OPTION)" -DTOPSRCDIR="$(CURDIR)" -DDEB_HOST_GNU_TYPE="$(DEB_HOST_GNU_TYPE)" \
		-DMOZ_ADDONDIR="$(MOZ_ADDONDIR)" -DMOZ_SDKDIR="$(MOZ_SDKDIR)" -DMOZ_DISTDIR="$(MOZ_DISTDIR)" -DMOZ_UPDATE_CHANNEL="$(CHANNEL)" \
		-DMOZ_OBJDIR="$(MOZ_OBJDIR)" -DDEB_BUILDDIR="$(DEB_BUILDDIR)" -DMOZ_PYTHON="$(MOZ_PYTHON)" -DMOZ_PROFILEDIR="$(MOZ_PROFILEDIR)" \
		-DMOZ_PKG_BASENAME="$(MOZ_PKG_BASENAME)" -DMOZ_DEFAULT_PROFILEDIR="$(MOZ_DEFAULT_PROFILEDIR)" \
		-DMOZ_DEFAULT_APP_NAME="$(MOZ_DEFAULT_APP_NAME)" -DMOZ_DEFAULT_APP_BASENAME="$(MOZ_DEFAULT_APP_BASENAME)" \
		-DDISTRIB_VERSION="$(DISTRIB_VERSION_MAJOR)$(DISTRIB_VERSION_MINOR)" -DMOZ_TESTDIR="$(MOZ_TESTDIR)"

ifeq (1, $(MOZ_ENABLE_BREAKPAD))
MOZ_DEFINES += -DMOZ_ENABLE_BREAKPAD
endif
ifeq (1, $(MOZ_VALGRIND))
MOZ_DEFINES += -DMOZ_VALGRIND
endif
ifeq (1,$(MOZ_NO_OPTIMIZE))
MOZ_DEFINES += -DMOZ_NO_OPTIMIZE
endif
ifeq (1,$(MOZ_WANT_UNIT_TESTS))
MOZ_DEFINES += -DMOZ_WANT_UNIT_TESTS
endif
ifneq ($(DEB_BUILD_GNU_TYPE),$(DEB_HOST_GNU_TYPE))
MOZ_DEFINES += -DDEB_BUILD_GNU_TYPE="$(DEB_BUILD_GNU_TYPE)"
endif
ifeq (1,$(MOZ_BUILD_PGO))
MOZ_DEFINES += -DMOZ_BUILD_PGO
endif
ifeq (1,$(MOZ_DEBUG))
MOZ_DEFINES += -DMOZ_DEBUG
endif
ifeq (1,$(MOZ_ENABLE_GLOBALMENU))
MOZ_DEFINES += -DMOZ_ENABLE_GLOBALMENU
endif
ifeq (official, $(MOZ_BRANDING))
MOZ_DEFINES += -DMOZ_OFFICIAL_BRANDING
endif
ifneq (,$(DEB_PARALLEL_JOBS))
MOZ_DEFINES += -DDEB_PARALLEL_JOBS=$(DEB_PARALLEL_JOBS)
endif

MOZ_EXECUTABLES_$(MOZ_PKG_NAME) +=	$(MOZ_LIBDIR)/$(MOZ_PKG_BASENAME).sh \
					$(NULL)

pkgname_subst_files = \
	debian/config/mozconfig \
	$(MOZ_PKGNAME_SUBST_FILES) \
	$(NULL)

$(foreach pkg,$(MOZ_PKG_NAMES), \
	$(foreach dhfile, install dirs links manpages postinst preinst postrm prerm lintian-overrides, $(eval pkgname_subst_files += \
	$(shell if [ -f $(CURDIR)/$(subst $(MOZ_PKG_NAME),$(MOZ_PKG_BASENAME),debian/$(pkg).$(dhfile).in) ]; then \
		echo debian/$(pkg).$(dhfile); fi))))

appname_subst_files = \
	debian/$(MOZ_APP_NAME).desktop \
	$(MOZ_APPNAME_SUBST_FILES) \
	$(NULL)

pkgconfig_files = \
	$(MOZ_PKGCONFIG_FILES) \
	$(NULL)

debian/control:: debian/control.in debian/control.langpacks debian/control.langpacks.unavail debian/config/locales.shipped debian/config/locales.all
	@echo ""
	@echo "*****************************"
	@echo "* Refreshing debian/control *"
	@echo "*****************************"
	@echo ""

	sed -e 's/@MOZ_PKG_NAME@/$(MOZ_PKG_NAME)/g' < debian/control.in > debian/control
	perl debian/build/dump-langpack-control-entries.pl > debian/control.tmp
	sed -e 's/@MOZ_PKG_NAME@/$(MOZ_PKG_NAME)/g' < debian/control.tmp >> debian/control && rm -f debian/control.tmp

$(pkgname_subst_files): $(foreach file,$(pkgname_subst_files),$(subst $(MOZ_PKG_NAME),$(MOZ_PKG_BASENAME),$(file).in))
	$(MOZ_PYTHON) $(CURDIR)/debian/build/Preprocessor.py -Fsubstitution --marker="%%" $(MOZ_DEFINES) $(CURDIR)/$(subst $(MOZ_PKG_NAME),$(MOZ_PKG_BASENAME),$@.in) > $(CURDIR)/$@

$(appname_subst_files): $(foreach file,$(appname_subst_files),$(subst $(MOZ_APP_NAME),$(MOZ_PKG_BASENAME),$(file).in))
	$(MOZ_PYTHON) $(CURDIR)/debian/build/Preprocessor.py -Fsubstitution --marker="%%" $(MOZ_DEFINES) $(CURDIR)/$(subst $(MOZ_APP_NAME),$(MOZ_PKG_BASENAME),$@.in) > $(CURDIR)/$@

%.pc: WCHAR_CFLAGS = $(shell cat $(MOZ_OBJDIR)/config/autoconf.mk | grep WCHAR_CFLAGS | sed 's/^[^=]*=[[:space:]]*\(.*\)$$/\1/')
%.pc: %.pc.in debian/stamp-makefile-build
	$(MOZ_PYTHON) $(CURDIR)/debian/build/Preprocessor.py -Fsubstitution --marker="%%" $(MOZ_DEFINES) -DWCHAR_CFLAGS="$(WCHAR_CFLAGS)" $(CURDIR)/$< > $(CURDIR)/$@

make-buildsymbols: debian/stamp-makebuildsymbols
debian/stamp-makebuildsymbols: debian/stamp-makefile-build
ifeq (1, $(MOZ_ENABLE_BREAKPAD))
	$(MAKE) -C $(MOZ_OBJDIR) buildsymbols MOZ_SYMBOLS_EXTRA_BUILDID=$(shell date -d "`dpkg-parsechangelog | grep Date: | sed -e 's/^Date: //'`" +%y%m%d%H%M%S)-$(DEB_HOST_GNU_CPU)
endif
	@touch $@

make-testsuite: debian/stamp-maketestsuite
debian/stamp-maketestsuite: debian/stamp-makefile-build
	$(MAKE) -C $(MOZ_OBJDIR) package-tests
	@touch $@

make-langpack-xpis: $(foreach target,$(shell sed -n 's/\#.*//;/^$$/d;s/\([^\:]*\)\:\?.*/\1/ p' < $(CURDIR)/debian/config/locales.shipped),debian/stamp-make-langpack-xpi-$(target))
debian/stamp-make-langpack-xpi-%:
	@echo ""
	@echo ""
	@echo "* Building language pack xpi for $*"
	@echo ""

	rm -rf $(CURDIR)/debian/l10n-mergedirs/$*
	mkdir -p $(CURDIR)/debian/l10n-mergedirs/$*

	@export PATH=$(CURDIR)/compare-locales/scripts/:$$PATH ; \
	export PYTHONPATH=$(CURDIR)/compare-locales/lib ; \
	cd $(MOZ_OBJDIR)/$(MOZ_APP)/locales ; \
		$(MAKE) merge-$* LOCALE_MERGEDIR=$(CURDIR)/debian/l10n-mergedirs/$* || exit 1 ; \
		$(MAKE) langpack-$* LOCALE_MERGEDIR=$(CURDIR)/debian/l10n-mergedirs/$* || exit 1;
	@touch $@

common-build-arch:: make-langpack-xpis $(pkgconfig_files) make-testsuite run-tests

install/$(MOZ_PKG_NAME)::
	@echo "Adding suggests / recommends on support packages"
	@echo "$(MOZ_PKG_SUPPORT_SUGGESTS)" | perl -0 -ne 's/[ \t\n]+/ /g; /\w/ and print "support:Suggests=$$_\n"' >> debian/$(MOZ_PKG_NAME).substvars
	@echo "$(MOZ_PKG_SUPPORT_RECOMMENDS)" | perl -0 -ne 's/[ \t\n]+/ /g; /\w/ and print "support:Recommends=$$_\n"' >> debian/$(MOZ_PKG_NAME).substvars

install/$(MOZ_PKG_NAME)-gnome-support::
ifneq (,$(filter lucid maverick natty, $(DISTRIB_CODENAME)))
	@echo "Adding libgconf2-4 dependency"
	@echo "gconf:Depends=libgconf2-4" >> debian/$(MOZ_PKG_NAME)-gnome-support.substvars
endif

ifneq ($(MOZ_PKG_NAME),$(MOZ_APP_NAME))
install/%::
	@echo "Adding conflicts / provides for renamed package"
	@echo "app:Conflicts=$(subst $(subst $(MOZ_APP_NAME),,$(MOZ_PKG_NAME)),,$*)" >> debian/$*.substvars
	@echo "app:Provides=$(subst $(subst $(MOZ_APP_NAME),,$(MOZ_PKG_NAME)),,$*)" >> debian/$*.substvars
endif

common-install-arch common-install-indep::
	$(foreach dir,$(MOZ_LIBDIR) $(MOZ_INCDIR) $(MOZ_IDLDIR) $(MOZ_SDKDIR), \
		if [ -d debian/tmp/$(dir)-$(MOZ_VERSION) ]; \
		then \
			mv debian/tmp/$(dir)-$(MOZ_VERSION) debian/tmp/$(dir); \
		fi; )

common-binary-arch:: make-buildsymbols

binary-install/$(MOZ_PKG_NAME)::
	install -m 0644 $(CURDIR)/debian/apport/blacklist $(CURDIR)/debian/$(MOZ_PKG_NAME)/etc/apport/blacklist.d/$(MOZ_PKG_NAME)
	install -m 0644 $(CURDIR)/debian/apport/native-origins $(CURDIR)/debian/$(MOZ_PKG_NAME)/etc/apport/native-origins.d/$(MOZ_PKG_NAME)

ifeq (1, $(MOZ_ENABLE_GLOBALMENU))
binary-install/$(MOZ_PKG_NAME)-globalmenu::
	unzip -o -d debian/$(MOZ_PKG_NAME)-globalmenu/$(MOZ_ADDONDIR)/extensions/globalmenu@ubuntu.com/ $(MOZ_DISTDIR)/xpi-stage/globalmenu.xpi
endif

GNOME_SUPPORT_FILES = libmozgnome.so
binary-post-install/$(MOZ_PKG_NAME):: install-searchplugins-,$(MOZ_PKG_NAME)
	$(foreach file,$(GNOME_SUPPORT_FILES),rm -fv debian/$(MOZ_PKG_NAME)/$(MOZ_LIBDIR)/components/$(file);) true

MOZ_LANGPACK_TARGETS := $(shell sed -n 's/[^\:]*\:\?\(.*\)/\1/ p' < debian/config/locales.shipped | uniq)
$(patsubst %,binary-post-install/$(MOZ_PKG_NAME)-locale-%,$(MOZ_LANGPACK_TARGETS)):: binary-post-install/$(MOZ_PKG_NAME)-locale-%: install-langpack-xpis-% install-searchplugins-%

binary-post-install/$(MOZ_PKG_NAME)-dev::
	rm -f debian/$(MOZ_PKG_NAME)-dev/$(MOZ_INCDIR)/nspr/md/_linux.cfg
	dh_link -p$(MOZ_PKG_NAME)-dev $(MOZ_INCDIR)/nspr/prcpucfg.h $(MOZ_INCDIR)/nspr/md/_linux.cfg

binary-post-install/%::
	find debian/$* -name .mkdir.done -delete

install-langpack-xpis-%:
	@echo ""
	@echo "Installing language pack xpis for $(MOZ_PKG_NAME)-locale-$*"
	dh_installdirs -p$(MOZ_PKG_NAME)-locale-$* $(MOZ_ADDONDIR)/extensions
	@for lang in $(shell grep $*$$ debian/config/locales.shipped | sed -n 's/\([^\:]*\)\:\?.*/\1/ p' | tr '\n' ' '); \
	do \
		id=`python $(CURDIR)/debian/build/get-xpi-id.py $(CURDIR)/$(MOZ_DISTDIR)/$(LANGPACK_DIR)/$(MOZ_APP_NAME)-$(MOZ_VERSION).$$lang.langpack.xpi 2>/dev/null`; \
		echo "Installing $(MOZ_APP_NAME)-$(MOZ_VERSION).$$lang.langpack.xpi to $$id.xpi in to $(MOZ_PKG_NAME)-locale-$*"; \
		install -m 0644 $(CURDIR)/$(MOZ_DISTDIR)/$(LANGPACK_DIR)/$(MOZ_APP_NAME)-$(MOZ_VERSION).$$lang.langpack.xpi \
			$(CURDIR)/debian/$(MOZ_PKG_NAME)-locale-$*/$(MOZ_ADDONDIR)/extensions/$$id.xpi; \
	done

CUSTOMIZE_SEARCHPLUGINS = \
	echo ""; \
	echo "Applying search customizations for $(2)"; \
	for lang in $(1); do \
		echo "Applying customizations to $$lang"; \
		list=debian/searchplugins/$$lang/list.txt; \
		if [ ! -f $$list ]; then \
			list=debian/searchplugins/list.txt; \
		fi; \
		overrides=`sed -n '/^\[Overrides\]/,/^\[/{/^\[/d;/^$$/d; p}' < $$list`; \
		additions=`sed -n '/^\[Additions\]/,/^\[/{/^\[/d;/^$$/d; p}' < $$list`; \
		for o in $$overrides; do \
			f=`ls -1 debian/searchplugins/$$lang/$$o.xml 2>/dev/null | head -n1`; \
			if [ -z $$f ]; then \
				f=`ls -1 debian/searchplugins/en-US/$$o.xml 2>/dev/null | head -n1`; \
			fi; \
			if [ -z $$f ]; then \
				echo "Cannot find source plugin for $$o"; \
				exit 1; \
			fi; \
			if [ ! -f debian/$(2)/$(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang/`basename $$f` ]; then \
				echo "No plugin `basename $$f` to override"; \
				exit 1; \
			fi; \
			echo "Overriding `basename $$f`"; \
			dh_install -p$(2) $$f $(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang; \
		done; \
		for a in $$additions; do \
			f=`ls -1 debian/searchplugins/$$lang/$$a.xml 2>/dev/null | head -n1`; \
			if [ -z $$f ]; then \
				f=`ls -1 debian/searchplugins/en-US/$$a.xml 2>/dev/null | head -n1`; \
			fi; \
			if [ -z $$f ]; then \
				echo "Cannot find source plugin for $$a"; \
				exit 1; \
			fi; \
			if [ -f debian/$(2)/$(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang/`basename $$f` ]; then \
				echo "Plugin `basename $$f` already exists"; \
				exit 1; \
			fi; \
			echo "Adding `basename $$f`"; \
			dh_install -p$(2) $$f $(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang; \
		done; \
	done

install-searchplugins-%: P1 = $(shell echo $* | sed 's/\([^,]*\),\?\([^,]*\)/\1/')
install-searchplugins-%: P2 = $(shell echo $* | sed 's/\([^,]*\),\?\([^,]*\)/\2/')
install-searchplugins-%: LANGUAGES = $(if $(P1),$(shell grep $(P1)$$ debian/config/locales.shipped | sed -n 's/\([^\:]*\)\:\?.*/\1/ p' | tr '\n' ' '),en-US)
install-searchplugins-%: PKGNAME = $(if $(P2),$(P2),$(MOZ_PKG_NAME)-locale-$(P1))
install-searchplugins-%:
	@echo ""
	@echo "Installing searchplugins for $(PKGNAME)"
	@for lang in $(LANGUAGES); do \
		echo "Installing searchplugins for $$lang"; \
		rm -rf debian/$(PKGNAME)/$(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang; \
		src=$(MOZ_DISTDIR)/xpi-stage/locale-$$lang; \
		if [ ! -d $$src ]; then \
			src=debian/tmp/$(MOZ_LIBDIR); \
		fi; \
		dh_installdirs -p$(PKGNAME) $(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang; \
		dh_install -p$(PKGNAME) $$src/searchplugins/*.xml $(MOZ_SEARCHPLUGIN_DIR)/locale/$$lang; \
	done
	@$(if $(wildcard debian/searchplugins),$(call CUSTOMIZE_SEARCHPLUGINS,$(LANGUAGES),$(PKGNAME)))
	@echo ""

binary-predeb/$(MOZ_PKG_NAME)::
	$(foreach lib,libsoftokn3.so libfreebl3.so libnssdbm3.so, \
	        LD_LIBRARY_PATH=debian/$(MOZ_PKG_NAME)/$(MOZ_LIBDIR):$$LD_LIBRARY_PATH \
	        $(MOZ_DISTDIR)/bin/shlibsign -v -i debian/$(MOZ_PKG_NAME)/$(MOZ_LIBDIR)/$(lib);)

common-binary-predeb-arch::
	$(foreach pkg,$(MOZ_PKG_NAMES),$(foreach file,$(MOZ_EXECUTABLES_$(pkg)),chmod a+x debian/$(pkg)/$(file);))
	# we want the gnome dependencies not to be in the main package at shlibdeps runtime, hence we dont
	# install them at binary-install/* stage, but copy them over _after_ the shlibdeps had been generated
	$(foreach file,$(GNOME_SUPPORT_FILES),mv debian/$(MOZ_PKG_NAME)-gnome-support/$(MOZ_LIBDIR)/components/$(file) debian/$(MOZ_PKG_NAME)/$(MOZ_LIBDIR)/components/;) true

pre-build:: auto-refresh-supported-locales $(pkgname_subst_files) $(appname_subst_files) enable-dist-patches
	cp $(CURDIR)/debian/syspref.js $(CURDIR)/debian/$(MOZ_PKG_BASENAME).js
ifeq (1,$(HAVE_GLOBALMENU))
	mkdir -p $(DEB_SRCDIR)/$(MOZ_MOZDIR)/extensions/globalmenu
	(cd debian/globalmenu && tar -cvhf - .) | (cd $(DEB_SRCDIR)/$(MOZ_MOZDIR)/extensions/globalmenu && tar -xf -)
endif
ifeq (,$(MOZ_DEFAULT_APP_BASENAME))
	$(error "Need to set MOZ_DEFAULT_APP_BASENAME")
endif
ifeq (,$(MOZ_BRANDING_OPTION))
	$(error "Need to set MOZ_BRANDING_OPTION")
endif
ifeq (,$(MOZ_BRANDING_DIR))
	$(error "Need to set MOZ_BRANDING_DIR")
endif

EXTRACT_TARBALL = $(firstword $(shell TMPDIR=`mktemp -d`; tar -jxf $(1) -C $$TMPDIR > /dev/null 2>&1; echo $$TMPDIR/`ls $$TMPDIR/ | head -n1`))

ifdef LANGPACK_O_MATIC
refresh-supported-locales:: LPOM_OPT = -l $(LANGPACK_O_MATIC)
endif
refresh-supported-locales:: EXTRACTED := $(if $(wildcard $(MOZ_APP)/locales/shipped-locales),,$(call EXTRACT_TARBALL,$(TARBALL)))
refresh-supported-locales:: SHIPPED_LOCALES = $(firstword $(wildcard $(CURDIR)/$(MOZ_APP)/locales/shipped-locales) $(wildcard $(EXTRACTED)/$(MOZ_APP)/locales/shipped-locales))
refresh-supported-locales::
	@echo ""
	@echo "****************************************"
	@echo "* Refreshing list of shipped languages *"
	@echo "****************************************"
	@echo ""

	perl debian/build/refresh-supported-locales.pl -s $(SHIPPED_LOCALES) $(LPOM_OPT)

refresh-supported-locales:: debian/control
	$(if $(EXTRACTED),rm -rf $(dir $(EXTRACTED)))

auto-refresh-supported-locales::
	cp debian/config/locales.shipped debian/config/locales.shipped.old

auto-refresh-supported-locales:: refresh-supported-locales
auto-refresh-supported-locales::
	@if ! cmp -s debian/config/locales.shipped debian/config/locales.shipped.old ; \
	then \
		echo "" ; \
		echo "****************************************************************************" ; \
		echo "* List of shipped locales is out of date. Please refresh and try again     *" ; \
		echo "* To refresh, run \"debian/rules refresh-supported-locales\" in the source   *" ; \
		echo "* directory. If you are in bzr, you will need to pass the location of the  *" ; \
		echo "* upstream tarball, using \"TARBALL=/path/to/tarball\". If extra information *" ; \
		echo "* is required for new locales, you will also need to pass the location of  *" ; \
		echo "* langpack-o-matic, using \"LANGPACK_O_MATIC=/path/to/langpack-o-matic\"     *" ; \
		echo "****************************************************************************" ; \
		echo "" ; \
		mv debian/config/locales.shipped.old debian/config/locales.shipped ; \
		exit 1 ; \
	fi
	rm -f debian/config/locales.shipped.old

ifneq (1, $(MOZ_DISABLE_CLEAN_CHECKS))
clean:: auto-refresh-supported-locales
endif

ifdef PATCHES_DIST
CODENAME = $(PATCHES_DIST)
else
CODENAME = $(DISTRIB_CODENAME)
endif

ifdef PATCHES_ARCH
ARCH = $(PATCHES_ARCH)
else
ARCH = $(DEB_HOST_ARCH)
endif

enable-dist-patches:
	perl $(CURDIR)/debian/build/enable-dist-patches.pl $(CODENAME) $(ARCH)

RESTORE_BACKUP = $(shell if [ -f $(1).bak ] ; then rm -f $(1); mv $(1).bak $(1); fi)

get-orig-source: ARGS = -r $(MOZILLA_REPO) -l $(L10N_REPO) -n $(MOZ_PKG_NAME) -a $(MOZ_APP)
ifdef DEBIAN_TAG
get-orig-source: ARGS += -t $(DEBIAN_TAG)
endif
ifdef LOCAL_BRANCH
get-orig-source: ARGS += -c $(LOCAL_BRANCH)
endif
get-orig-source:
	python $(CURDIR)/debian/build/create-tarball.py $(ARGS)

echo-%:
	@echo "$($*)"

clean::
	@if ! cmp -s debian/control debian/control.old ; \
	then \
		echo "" ; \
		echo "*************************************************************************" ; \
		echo "* debian/control file is out of date. Please refresh and try again      *" ; \
		echo "* To refresh, run \"debian/rules debian/control\" in the source directory *" ; \
		echo "*************************************************************************" ; \
		echo "" ; \
		rm -f debian/control.old ; \
		exit 1 ; \
	fi
	rm -f debian/control.old
	perl $(CURDIR)/debian/build/enable-dist-patches.pl --clean $(CURDIR)/debian/patches/series
	rm -f $(pkgname_subst_files) $(appname_subst_files)
	rm -f debian/stamp-*
	rm -rf debian/l10n-mergedirs
	rm -f debian/$(MOZ_PKG_BASENAME).js
	rm -rf $(MOZ_OBJDIR)
	rm -f debian/searchplugin*.list
	find debian -name *.pyc -delete
	find compare-locales -name *.pyc -delete

.PHONY: make-buildsymbols make-testsuite make-langpack-xpis refresh-supported-locales auto-refresh-supported-locales enable-dist-patches get-orig-source
