ACDEFINES = -DSTATIC_EXPORTABLE_JS_API=1 -DD_INO=d_ino -DJS_CPU_X86=1 -DJS_NUNBOX32=1 -DJS_METHODJIT=1 -DJS_MONOIC=1 -DJS_POLYIC=1 -DJS_METHODJIT_TYPED_ARRAY=1 -DJS_ION=1 -DSTDC_HEADERS=1 -DHAVE_SSIZE_T=1 -DHAVE_ST_BLKSIZE=1 -DHAVE_SIGINFO_T=1 -DJS_BYTES_PER_WORD=4 -DJS_BITS_PER_WORD_LOG2=5 -DJS_ALIGN_OF_POINTER=4 -DJS_BYTES_PER_DOUBLE=8 -DHAVE_ENDIAN_H=1 -DJS_HAVE_ENDIAN_H=1 -DHAVE_UINT=1 -DHAVE_UNAME_DOMAINNAME_FIELD=1 -DHAVE_VISIBILITY_HIDDEN_ATTRIBUTE=1 -DHAVE_VISIBILITY_ATTRIBUTE=1 -DHAVE_DIRENT_H=1 -DHAVE_GETOPT_H=1 -DHAVE_SYS_BITYPES_H=1 -DHAVE_MEMORY_H=1 -DHAVE_UNISTD_H=1 -DHAVE_GNU_LIBC_VERSION_H=1 -DHAVE_NL_TYPES_H=1 -DHAVE_MALLOC_H=1 -DHAVE_X11_XKBLIB_H=1 -DHAVE_CPUID_H=1 -DHAVE_SYS_STATVFS_H=1 -DHAVE_SYS_STATFS_H=1 -DHAVE_SYS_VFS_H=1 -DHAVE_SYS_MOUNT_H=1 -DHAVE_SYS_QUOTA_H=1 -DHAVE_LINUX_QUOTA_H=1 -DNEW_H=\<new\> -DHAVE_SYS_CDEFS_H=1 -DHAVE_DLOPEN=1 -DHAVE_DLADDR=1 -D_REENTRANT=1 -DHAVE_FCHMOD=1 -DHAVE_FLOCKFILE=1 -DHAVE_GETC_UNLOCKED=1 -DHAVE_GETPAGESIZE=1 -DHAVE_LCHOWN=1 -DHAVE_LOCALTIME_R=1 -DHAVE_LSTAT64=1 -DHAVE_MEMMOVE=1 -DHAVE_RANDOM=1 -DHAVE_SBRK=1 -DHAVE_SNPRINTF=1 -DHAVE_STAT64=1 -DHAVE_STATVFS=1 -DHAVE_STATVFS64=1 -DHAVE_STRERROR=1 -DHAVE_STRTOK_R=1 -DHAVE_TRUNCATE64=1 -DHAVE_WCRTOMB=1 -DHAVE_MBRTOWC=1 -DHAVE_RES_NINIT=1 -DHAVE_GNU_GET_LIBC_VERSION=1 -DVA_COPY=va_copy -DHAVE_VA_COPY=1 -DHAVE_CPP_PARTIAL_SPECIALIZATION=1 -DHAVE_CPP_AMBIGUITY_RESOLVING_USING=1 -DHAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR=1 -DNEED_CPP_UNUSED_IMPLEMENTATIONS=1 -DHAVE_THREAD_TLS_KEYWORD=1 -DHAVE_I18N_LC_MESSAGES=1 -DHAVE_LOCALECONV=1 -DNS_ATTR_MALLOC=__attribute__\(\(malloc\)\) -DNS_WARN_UNUSED_RESULT=__attribute__\(\(warn_unused_result\)\) -DMOZ_UPDATE_CHANNEL=default -DMOZ_DEBUG_SYMBOLS=1 -DSIZEOF_INT_P=4 -DMOZ_MEMORY_SIZEOF_PTR_2POW=2 -DMOZ_MEMORY=1 -DMOZ_MEMORY_LINUX=1 -DJSGC_INCREMENTAL=1 -DHAVE___CXA_DEMANGLE=1 -DHAVE__UNWIND_BACKTRACE=1 -DJS_DEFAULT_JITREPORT_GRANULARITY=3 -DJS_HAS_XML_SUPPORT=1 -DHAVE_TM_ZONE_TM_GMTOFF=1 -DCPP_THROW_NEW=throw\(\) -DEDITLINE=1 -DJS_HAS_CTYPES=1 -DMOZ_DLL_SUFFIX=\".so\" -DHAVE_POSIX_FALLOCATE=1 -DXP_UNIX=1 -DJS_THREADSAFE=1 -DHAVE_SETLOCALE=1 -DHAVE_LOCALECONV=1
AIX_OBJMODEL = 
ANDROID_CPU_ARCH = 
ANDROID_NDK = 
ANDROID_PLATFORM = 
ANDROID_TOOLCHAIN = 
ANDROID_VERSION = 
AR = ar
AR_DELETE = $(AR) d
AR_EXTRACT = $(AR) x
AR_FLAGS = cr $@
AR_LIST = $(AR) t
AS = $(CC)
ASFLAGS =  -fPIC
ASM_SUFFIX = s
AS_DASH_C_FLAG = -c
AUTOCONF = /usr/bin/autoconf
AWK = mawk
BIN_FLAGS = 
BIN_SUFFIX = 
CC = gcc
CCACHE = no
CC_VERSION = gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5) 
CFLAGS = -pedantic -Wall -Wpointer-arith -Wdeclaration-after-statement -Werror=return-type -Wtype-limits -Wempty-body -Wno-unused -Wno-overlength-strings -Wcast-align -Wno-long-long -ffunction-sections -fdata-sections -pthread -pipe
CLANG_CXX = 
CL_INCLUDES_PREFIX = 
CPP = gcc -E
CPPFLAGS = 
CPU_ARCH = x86
CROSS_COMPILE = 
CROSS_LIB = /usr/i686-pc-linux-gnu
CXX = c++
CXXCPP = c++ -E
CXXFLAGS = -pedantic -Wall -Wpointer-arith -Woverloaded-virtual -Werror=return-type -Wtype-limits -Wempty-body -Werror=conversion-null -Wno-ctor-dtor-privacy -Wno-overlength-strings -Wno-invalid-offsetof -Wno-variadic-macros -Wcast-align -Wno-long-long -fno-rtti -ffunction-sections -fdata-sections -fno-exceptions -pthread -pipe
CXX_VERSION = gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5) 
DEFS = 
DEHYDRA_PATH = 
DLL_PREFIX = lib
DLL_SUFFIX = .so
DOXYGEN = /usr/bin/doxygen
DSO_CFLAGS = 
DSO_LDOPTS = -shared -Wl,-z,defs -Wl,--gc-sections
DSO_PIC_CFLAGS = -fPIC
EDITLINE_LIBS = $(DEPTH)/editline/$(LIB_PREFIX)editline.$(LIB_SUFFIX)
ENABLE_ION = 1
ENABLE_METHODJIT = 1
ENABLE_METHODJIT_SPEW = 
ENABLE_STRIP = 
ENABLE_TESTS = 1
ENABLE_TRACE_LOGGING = 
EXPAND_LIBS_LIST_STYLE = linkerscript
EXPAND_LIBS_ORDER_STYLE = linkerscript
FAIL_ON_WARNINGS = 
FFLAGS = 
FILTER = 
GCC_VERSION = 4.6
GMAKE = /usr/bin/make
GNU_AS = 1
GNU_CC = 1
GNU_CXX = 1
GNU_LD = 1
HAVE_64BIT_OS = 
HAVE_ARM_NEON = 
HAVE_ARM_SIMD = 
HAVE_DTRACE = 
HAVE_LINUX_PERF_EVENT_H = 1
HOST_AR = $(AR)
HOST_AR_FLAGS = $(AR_FLAGS)
HOST_BIN_SUFFIX = 
HOST_CC = $(CC)
HOST_CFLAGS = $(CFLAGS) -DXP_UNIX
HOST_CXX = $(CXX)
HOST_CXXFLAGS = $(CXXFLAGS)
HOST_LD = 
HOST_LDFLAGS = $(LDFLAGS)
HOST_NSPR_MDCPUCFG = \"md/_linux.cfg\"
HOST_OPTIMIZE_FLAGS = -O3
HOST_OS_ARCH = Linux
HOST_RANLIB = $(RANLIB)
IMPLIB = 
IMPORT_LIB_SUFFIX = 
INCREMENTAL_LINKER = 
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
INTEL_ARCHITECTURE = 1
INTEL_CC = 
INTEL_CXX = 
JS_DISABLE_SHELL = 
JS_HAS_CTYPES = 1
JS_NATIVE_EDITLINE = 1
JS_SHARED_LIBRARY = 
LD = ld
LDFLAGS = -lpthread  -Wl,--build-id
LD_PRINT_ICF_SECTIONS = 
LIBICONV = 
LIBOBJS = 
LIBS = -ldl 
LIBS_DESC_SUFFIX = desc
LIB_PREFIX = lib
LIB_SUFFIX = a
LINUX_HEADERS_INCLUDES = 
LN_S = ln -s
MACOSX_DEPLOYMENT_TARGET = 
MACOS_SDK_DIR = 
MC = mc.exe
MKCSHLIB = $(CC) $(CFLAGS) $(DSO_PIC_CFLAGS) $(DSO_LDOPTS) -Wl,-h,$@ -o $@
MKSHLIB = $(CXX) $(CXXFLAGS) $(DSO_PIC_CFLAGS) $(DSO_LDOPTS) -Wl,-h,$@ -o $@
MKSHLIB_FORCE_ALL = -Wl,--whole-archive
MKSHLIB_UNFORCE_ALL = -Wl,--no-whole-archive
MOZILLA_OFFICIAL = 
MOZILLA_VERSION = 
MOZ_APP_DISPLAYNAME = 
MOZ_APP_NAME = firefox
MOZ_APP_VERSION = 
MOZ_ASAN = 
MOZ_BROWSE_INFO = 
MOZ_BUILD_ROOT = /home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/js/src
MOZ_CALLGRIND = 
MOZ_CAN_RUN_PROGRAMS = 
MOZ_COMPONENTS_VERSION_SCRIPT_LDFLAGS = -Wl,--version-script -Wl,$(BUILD_TOOLS)/gnu-ld-scripts/components-version-script
MOZ_COMPONENT_NSPR_LIBS = -L$(LIBXUL_DIST)/bin $(NSPR_LIBS)
MOZ_DEBUG = 
MOZ_DEBUG_DISABLE_DEFS = -DNDEBUG -DTRIMMED
MOZ_DEBUG_ENABLE_DEFS = -DDEBUG -D_DEBUG -DTRACING
MOZ_DEBUG_FLAGS = -g
MOZ_DEBUG_LDFLAGS = 
MOZ_DEBUG_SYMBOLS = 1
MOZ_DEMANGLE_SYMBOLS = 
MOZ_ETW = 
MOZ_FFI_CFLAGS = 
MOZ_FFI_LIBS = 
MOZ_FIX_LINK_PATHS = -Wl,-rpath-link,$(LIBXUL_DIST)/bin -Wl,-rpath-link,$(prefix)/lib
MOZ_FRAMEPTR_FLAGS = -fomit-frame-pointer
MOZ_GLUE_LDFLAGS = 
MOZ_GLUE_PROGRAM_LDFLAGS = $(MKSHLIB_FORCE_ALL) $(call EXPAND_LIBNAME_PATH,mozglue,$(LIBXUL_DIST)/lib) $(call EXPAND_LIBNAME_PATH,memory,$(LIBXUL_DIST)/lib) $(MKSHLIB_UNFORCE_ALL) -rdynamic
MOZ_JPROF = 
MOZ_JS_LIBS = -L$(libdir) -lmozjs
MOZ_MAPINFO = 
MOZ_MEMORY = 1
MOZ_METRO = 
MOZ_NATIVE_FFI = 
MOZ_NATIVE_NSPR = 
MOZ_NATIVE_ZLIB = 
MOZ_OPTIMIZE = 1
MOZ_OPTIMIZE_FLAGS = -O3 -freorder-blocks 
MOZ_OPTIMIZE_LDFLAGS = 
MOZ_OPTIMIZE_SIZE_TWEAK = 
MOZ_OS2_HIGH_MEMORY = 1
MOZ_OS2_TOOLS = 
MOZ_PGO_OPTIMIZE_FLAGS = -O3
MOZ_PKG_SPECIAL = 
MOZ_POST_DSO_LIB_COMMAND = 
MOZ_POST_PROGRAM_COMMAND = 
MOZ_PROFILING = 
MOZ_SHARK = 
MOZ_THUMB2 = 
MOZ_TOOLS_DIR = 
MOZ_UI_LOCALE = 
MOZ_UPDATE_CHANNEL = default
MOZ_USING_CCACHE = 
MOZ_VALGRIND = 
MOZ_VTUNE = 
MOZ_ZLIB_CFLAGS = 
MOZ_ZLIB_LIBS = $(call EXPAND_LIBNAME_PATH,mozz,/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/modules/zlib/src)
MSMANIFEST_TOOL = 
NEXT_ROOT = 
NO_LD_ARCHIVE_FLAGS = 
NSINSTALL_BIN = 
NSPR_CFLAGS = -I/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist/include/nspr
NSPR_CONFIG = 
NSPR_LIBS = -L/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist/lib -lnspr4 -lplc4 -lplds4
NS_TRACE_MALLOC = 
OBJ_SUFFIX = o
OS_ARCH = Linux
OS_CFLAGS = -pedantic -Wall -Wpointer-arith -Wdeclaration-after-statement -Werror=return-type -Wtype-limits -Wempty-body -Wno-unused -Wno-overlength-strings -Wcast-align -Wno-long-long -ffunction-sections -fdata-sections -pthread -pipe
OS_COMPILE_CFLAGS = -include $(DEPTH)/js-confdefs.h -DMOZILLA_CLIENT $(filter-out %/.pp,-MD -MF $(MDDEPDIR)/$(@F).pp)
OS_COMPILE_CXXFLAGS = -DMOZILLA_CLIENT -include $(DEPTH)/js-confdefs.h $(filter-out %/.pp,-MD -MF $(MDDEPDIR)/$(@F).pp)
OS_CPPFLAGS = 
OS_CXXFLAGS = -pedantic -Wall -Wpointer-arith -Woverloaded-virtual -Werror=return-type -Wtype-limits -Wempty-body -Werror=conversion-null -Wno-ctor-dtor-privacy -Wno-overlength-strings -Wno-invalid-offsetof -Wno-variadic-macros -Wcast-align -Wno-long-long -fno-rtti -ffunction-sections -fdata-sections -fno-exceptions -pthread -pipe
OS_LDFLAGS = -lpthread  -Wl,--build-id
OS_LIBS = -ldl 
OS_RELEASE = 3.2.0-40-generic-pae
OS_TARGET = Linux
OS_TEST = i686
PBBUILD_BIN = 
PERL = /usr/bin/perl
PKG_CONFIG = 
PKG_SKIP_STRIP = 
PROFILE_GEN_CFLAGS = -fprofile-generate
PROFILE_GEN_LDFLAGS = -fprofile-generate
PROFILE_USE_CFLAGS = -fprofile-use -fprofile-correction -Wcoverage-mismatch
PROFILE_USE_LDFLAGS = -fprofile-use
PYTHON = /usr/bin/python2.7
QEMU_CANT_RUN_JS_SHELL = 
QEMU_EXE = 
RANLIB = ranlib
RC = 
RCFLAGS = 
SBCONF = 
SDP = 
SHELL = /bin/sh
SOLARIS_SUNPRO_CC = 
SOLARIS_SUNPRO_CXX = 
STLPORT_SOURCES = 
STRIP = strip
TARGET_CPU = i686
TARGET_MD_ARCH = unix
TARGET_NSPR_MDCPUCFG = \"md/_linux.cfg\"
TARGET_OS = linux-gnu
TARGET_VENDOR = pc
TARGET_XPCOM_ABI = x86-gcc3
TOP_DIST = ../../dist
UNIVERSAL_BINARY = 
USE_DEPENDENT_LIBS = 1
USE_N32 = 
VISIBILITY_FLAGS = -I$(DIST)/system_wrappers_js -include $(topsrcdir)/config/gcc_hidden.h
WARNINGS_AS_ERRORS = 
WINDRES = :
WIN_TOP_SRC = 
WRAP_LDFLAGS = 
WRAP_SYSTEM_INCLUDES = 1
XARGS = /usr/bin/xargs
X_CFLAGS = 
X_EXTRA_LIBS = 
X_LIBS = 
X_PRE_LIBS =  -lSM -lICE
_MSC_VER = 
ac_configure_args =  --enable-threadsafe --enable-ctypes --disable-shared-js --with-nspr-cflags=-I/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist/include/nspr '--with-nspr-libs=-L/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist/lib -lnspr4 -lplc4 -lplds4' --with-dist-dir=../../dist --prefix=/home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist --enable-jemalloc --cache-file=../.././config.cache --srcdir=/home/txema/work/firefox-20.0+build1/js/src
bindir = ${exec_prefix}/bin
build = i686-pc-linux-gnu
build_alias = i686-pc-linux-gnu
build_cpu = i686
build_os = linux-gnu
build_vendor = pc
datadir = ${prefix}/share
exec_prefix = ${prefix}
host = i686-pc-linux-gnu
host_alias = i686-pc-linux-gnu
host_cpu = i686
host_os = linux-gnu
host_vendor = pc
includedir = ${prefix}/include
infodir = ${prefix}/info
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localstatedir = ${prefix}/var
mandir = ${prefix}/man
oldincludedir = /usr/include
prefix = /home/txema/work/firefox-20.0+build1/obj-i686-pc-linux-gnu/dist
program_transform_name = s,x,x,
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
sysconfdir = ${prefix}/etc
target = i686-pc-linux-gnu
target_alias = i686-pc-linux-gnu
target_cpu = i686
target_os = linux-gnu
target_vendor = pc
top_srcdir = /home/txema/work/firefox-20.0+build1/js/src
include $(topsrcdir)/config/baseconfig.mk