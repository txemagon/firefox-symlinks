#!/usr/bin/make -f

# These are used for cross-compiling and for saving the configure script
# from having to guess our platform (since we know it already)
DEB_HOST_GNU_TYPE	:= $(shell dpkg-architecture -qDEB_HOST_GNU_TYPE)
DEB_BUILD_GNU_TYPE	:= $(shell dpkg-architecture -qDEB_BUILD_GNU_TYPE)
DEB_HOST_ARCH		:= $(shell dpkg-architecture -qDEB_HOST_ARCH)
DEB_HOST_GNU_CPU	:= $(shell dpkg-architecture -qDEB_HOST_GNU_CPU)
DEB_HOST_GNU_SYSTEM	:= $(shell dpkg-architecture -qDEB_HOST_GNU_SYSTEM)

DISTRIB_VERSION_MAJOR 	:= $(shell lsb_release -s -r | cut -d '.' -f 1)
DISTRIB_VERSION_MINOR 	:= $(shell lsb_release -s -r | cut -d '.' -f 2)
DISTRIB_CODENAME	:= $(shell lsb_release -s -c)

include $(CURDIR)/debian/config/branch.mk
