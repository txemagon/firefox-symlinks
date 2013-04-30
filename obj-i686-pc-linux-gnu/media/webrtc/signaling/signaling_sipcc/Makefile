# This makefile was automatically generated from /home/txema/work/firefox-20.0+build1/media/webrtc/signaling/signaling.gyp. Please do not edit it directly.
DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/media/webrtc/signaling/
VPATH           = /home/txema/work/firefox-20.0+build1/media/webrtc/signaling/

LIBRARY_NAME = sipcc
DEFINES_Debug =  \
  -D_FILE_OFFSET_BITS=64 \
  -DCHROMIUM_BUILD \
  -DUSE_NSS=1 \
  -DENABLE_ONE_CLICK_SIGNIN \
  -DGTK_DISABLE_SINGLE_INCLUDES=1 \
  -D_ISOC99_SOURCE=1 \
  -DENABLE_REMOTING=1 \
  -DENABLE_WEBRTC=1 \
  -DENABLE_CONFIGURATION_POLICY \
  -DENABLE_INPUT_SPEECH \
  -DENABLE_NOTIFICATIONS \
  -DENABLE_GPU=1 \
  -DENABLE_EGLIMAGE=1 \
  -DUSE_SKIA=1 \
  -DENABLE_TASK_MANAGER=1 \
  -DENABLE_WEB_INTENTS=1 \
  -DENABLE_EXTENSIONS=1 \
  -DENABLE_PLUGIN_INSTALLATION=1 \
  -DENABLE_PROTECTOR_SERVICE=1 \
  -DENABLE_SESSION_SERVICE=1 \
  -DENABLE_THEMES=1 \
  -DENABLE_BACKGROUND=1 \
  -DENABLE_AUTOMATION=1 \
  -DENABLE_PRINTING=1 \
  -DENABLE_CAPTIVE_PORTAL_DETECTION=1 \
  -DSIP_OS_LINUX \
  -D_GNU_SOURCE \
  -DCPR_MEMORY_LITTLE_ENDIAN \
  -DNO_SOCKET_POLLING \
  -DUSE_TIMER_SELECT_BASED \
  -DFULL_BUILD \
  -DSTUBBED_OUT \
  -DUSE_PRINTFLINUX \
  -D__STDC_FORMAT_MACROS \
  -DDYNAMIC_ANNOTATIONS_ENABLED=1 \
  -DWTF_USE_DYNAMIC_ANNOTATIONS=1 \
  -D_DEBUG
INCLUDES_Debug =  \
  -I$(srcdir)/./src/common/browser_logging \
  -I$(srcdir)/./src/sipcc/include \
  -I$(srcdir)/./src/sipcc/core/includes \
  -I$(srcdir)/./src/sipcc/cpr/include \
  -I$(srcdir)/./src/sipcc/core/common \
  -I$(srcdir)/./src/sipcc/core/sipstack/h \
  -I$(srcdir)/./src/sipcc/core/ccapp \
  -I$(srcdir)/./src/sipcc/core/sdp \
  -I$(srcdir)/./src/sipcc/core/gsm/h \
  -I$(srcdir)/./src/sipcc/plat/common \
  -I$(srcdir)/../../../media/mtransport \
  -I$(srcdir)/../../../dom/base \
  -I$(srcdir)/../trunk/third_party/libsrtp/srtp/include \
  -I$(srcdir)/../trunk/third_party/libsrtp/srtp/crypto/include \
  -I$(DEPTH)/dist/include \
  -I$(srcdir)/../trunk/third_party/libsrtp/config
FORCE_STATIC_LIB = 1
CSRCS =  \
  ./src/sipcc/core/ccapp/call_logger.c \
  ./src/sipcc/core/ccapp/capability_set.c \
  ./src/sipcc/core/ccapp/cc_blf.c \
  ./src/sipcc/core/ccapp/cc_call_feature.c \
  ./src/sipcc/core/ccapp/cc_config.c \
  ./src/sipcc/core/ccapp/cc_device_feature.c \
  ./src/sipcc/core/ccapp/cc_device_manager.c \
  ./src/sipcc/core/ccapp/cc_info.c \
  ./src/sipcc/core/ccapp/cc_service.c \
  ./src/sipcc/core/ccapp/ccapi_call.c \
  ./src/sipcc/core/ccapp/ccapi_call_info.c \
  ./src/sipcc/core/ccapp/ccapi_config.c \
  ./src/sipcc/core/ccapp/ccapi_device.c \
  ./src/sipcc/core/ccapp/ccapi_device_info.c \
  ./src/sipcc/core/ccapp/ccapi_feature_info.c \
  ./src/sipcc/core/ccapp/ccapi_line.c \
  ./src/sipcc/core/ccapp/ccapi_line_info.c \
  ./src/sipcc/core/ccapp/ccapi_service.c \
  ./src/sipcc/core/ccapp/ccapi_snapshot.c \
  ./src/sipcc/core/ccapp/ccapp_task.c \
  ./src/sipcc/core/ccapp/ccprovider.c \
  ./src/sipcc/core/ccapp/conf_roster.c \
  ./src/sipcc/core/ccapp/sessionHash.c \
  ./src/sipcc/core/common/cfgfile_utils.c \
  ./src/sipcc/core/common/config_api.c \
  ./src/sipcc/core/common/config_parser.c \
  ./src/sipcc/core/common/init.c \
  ./src/sipcc/core/common/logger.c \
  ./src/sipcc/core/common/misc.c \
  ./src/sipcc/core/common/plat.c \
  ./src/sipcc/core/common/platform_api.c \
  ./src/sipcc/core/common/prot_configmgr.c \
  ./src/sipcc/core/common/resource_manager.c \
  ./src/sipcc/core/common/sip_socket_api.c \
  ./src/sipcc/core/common/subscription_handler.c \
  ./src/sipcc/core/common/text_strings.c \
  ./src/sipcc/core/common/thread_monitor.c \
  ./src/sipcc/core/common/ui.c \
  ./src/sipcc/core/gsm/ccapi.c \
  ./src/sipcc/core/gsm/ccapi_strings.c \
  ./src/sipcc/core/gsm/dcsm.c \
  ./src/sipcc/core/gsm/fim.c \
  ./src/sipcc/core/gsm/fsm.c \
  ./src/sipcc/core/gsm/fsmb2bcnf.c \
  ./src/sipcc/core/gsm/fsmcac.c \
  ./src/sipcc/core/gsm/fsmcnf.c \
  ./src/sipcc/core/gsm/fsmdef.c \
  ./src/sipcc/core/gsm/fsmxfr.c \
  ./src/sipcc/core/gsm/gsm.c \
  ./src/sipcc/core/gsm/gsm_sdp.c \
  ./src/sipcc/core/gsm/gsm_sdp_crypto.c \
  ./src/sipcc/core/gsm/lsm.c \
  ./src/sipcc/core/gsm/media_cap_tbl.c \
  ./src/sipcc/core/gsm/sm.c \
  ./src/sipcc/core/gsm/subapi.c \
  ./src/sipcc/core/sdp/ccsdp.c \
  ./src/sipcc/core/sdp/sdp_access.c \
  ./src/sipcc/core/sdp/sdp_attr.c \
  ./src/sipcc/core/sdp/sdp_attr_access.c \
  ./src/sipcc/core/sdp/sdp_base64.c \
  ./src/sipcc/core/sdp/sdp_config.c \
  ./src/sipcc/core/sdp/sdp_main.c \
  ./src/sipcc/core/sdp/sdp_token.c \
  ./src/sipcc/core/sdp/sdp_utils.c \
  ./src/sipcc/core/sdp/sdp_services_unix.c \
  ./src/sipcc/core/sipstack/ccsip_callinfo.c \
  ./src/sipcc/core/sipstack/ccsip_cc.c \
  ./src/sipcc/core/sipstack/ccsip_common_util.c \
  ./src/sipcc/core/sipstack/ccsip_core.c \
  ./src/sipcc/core/sipstack/ccsip_debug.c \
  ./src/sipcc/core/sipstack/ccsip_info.c \
  ./src/sipcc/core/sipstack/ccsip_messaging.c \
  ./src/sipcc/core/sipstack/ccsip_platform.c \
  ./src/sipcc/core/sipstack/ccsip_platform_tcp.c \
  ./src/sipcc/core/sipstack/ccsip_platform_timers.c \
  ./src/sipcc/core/sipstack/ccsip_platform_tls.c \
  ./src/sipcc/core/sipstack/ccsip_platform_udp.c \
  ./src/sipcc/core/sipstack/ccsip_pmh.c \
  ./src/sipcc/core/sipstack/ccsip_publish.c \
  ./src/sipcc/core/sipstack/ccsip_register.c \
  ./src/sipcc/core/sipstack/ccsip_reldev.c \
  ./src/sipcc/core/sipstack/ccsip_sdp.c \
  ./src/sipcc/core/sipstack/ccsip_spi_utils.c \
  ./src/sipcc/core/sipstack/ccsip_subsmanager.c \
  ./src/sipcc/core/sipstack/ccsip_task.c \
  ./src/sipcc/core/sipstack/httpish.c \
  ./src/sipcc/core/sipstack/pmhutils.c \
  ./src/sipcc/core/sipstack/sip_common_regmgr.c \
  ./src/sipcc/core/sipstack/sip_common_transport.c \
  ./src/sipcc/core/sipstack/sip_csps_transport.c \
  ./src/sipcc/core/sipstack/sip_interface_regmgr.c \
  ./src/sipcc/core/src-common/configapp.c \
  ./src/sipcc/core/src-common/dialplan.c \
  ./src/sipcc/core/src-common/dialplanint.c \
  ./src/sipcc/core/src-common/digcalc.c \
  ./src/sipcc/core/src-common/kpml_common_util.c \
  ./src/sipcc/core/src-common/kpmlmap.c \
  ./src/sipcc/core/src-common/md5.c \
  ./src/sipcc/core/src-common/misc_apps_task.c \
  ./src/sipcc/core/src-common/pres_sub_not_handler.c \
  ./src/sipcc/core/src-common/publish_int.c \
  ./src/sipcc/core/src-common/singly_link_list.c \
  ./src/sipcc/core/src-common/sll_lite.c \
  ./src/sipcc/core/src-common/string_lib.c \
  ./src/sipcc/core/src-common/util_ios_queue.c \
  ./src/sipcc/core/src-common/util_parse.c \
  ./src/sipcc/core/src-common/util_string.c \
  ./src/sipcc/cpr/common/cpr_string.c \
  ./src/sipcc/plat/csf2g/model.c \
  ./src/sipcc/plat/csf2g/reset_api.c \
  ./src/sipcc/core/sipstack/sip_platform_task.c \
  ./src/sipcc/plat/common/dns_utils.c \
  ./src/sipcc/cpr/linux/cpr_linux_errno.c \
  ./src/sipcc/cpr/linux/cpr_linux_init.c \
  ./src/sipcc/cpr/linux/cpr_linux_ipc.c \
  ./src/sipcc/cpr/linux/cpr_linux_locks.c \
  ./src/sipcc/cpr/linux/cpr_linux_socket.c \
  ./src/sipcc/cpr/linux/cpr_linux_stdio.c \
  ./src/sipcc/cpr/linux/cpr_linux_string.c \
  ./src/sipcc/cpr/linux/cpr_linux_threads.c \
  ./src/sipcc/cpr/linux/cpr_linux_timers_using_select.c
DEFINES_Release =  \
  -D_FILE_OFFSET_BITS=64 \
  -DCHROMIUM_BUILD \
  -DUSE_NSS=1 \
  -DENABLE_ONE_CLICK_SIGNIN \
  -DGTK_DISABLE_SINGLE_INCLUDES=1 \
  -D_ISOC99_SOURCE=1 \
  -DENABLE_REMOTING=1 \
  -DENABLE_WEBRTC=1 \
  -DENABLE_CONFIGURATION_POLICY \
  -DENABLE_INPUT_SPEECH \
  -DENABLE_NOTIFICATIONS \
  -DENABLE_GPU=1 \
  -DENABLE_EGLIMAGE=1 \
  -DUSE_SKIA=1 \
  -DENABLE_TASK_MANAGER=1 \
  -DENABLE_WEB_INTENTS=1 \
  -DENABLE_EXTENSIONS=1 \
  -DENABLE_PLUGIN_INSTALLATION=1 \
  -DENABLE_PROTECTOR_SERVICE=1 \
  -DENABLE_SESSION_SERVICE=1 \
  -DENABLE_THEMES=1 \
  -DENABLE_BACKGROUND=1 \
  -DENABLE_AUTOMATION=1 \
  -DENABLE_PRINTING=1 \
  -DENABLE_CAPTIVE_PORTAL_DETECTION=1 \
  -DSIP_OS_LINUX \
  -D_GNU_SOURCE \
  -DCPR_MEMORY_LITTLE_ENDIAN \
  -DNO_SOCKET_POLLING \
  -DUSE_TIMER_SELECT_BASED \
  -DFULL_BUILD \
  -DSTUBBED_OUT \
  -DUSE_PRINTFLINUX \
  -D__STDC_FORMAT_MACROS \
  -DNDEBUG \
  -DNVALGRIND \
  -DDYNAMIC_ANNOTATIONS_ENABLED=0
CPPFLAGS_Debug =  \
  $(NSPR_CFLAGS) \
  -m32 \
  -mmmx
CPPFLAGS_Release =  \
  $(NSPR_CFLAGS) \
  -m32 \
  -mmmx
INCLUDES_Release =  \
  -I$(srcdir)/./src/common/browser_logging \
  -I$(srcdir)/./src/sipcc/include \
  -I$(srcdir)/./src/sipcc/core/includes \
  -I$(srcdir)/./src/sipcc/cpr/include \
  -I$(srcdir)/./src/sipcc/core/common \
  -I$(srcdir)/./src/sipcc/core/sipstack/h \
  -I$(srcdir)/./src/sipcc/core/ccapp \
  -I$(srcdir)/./src/sipcc/core/sdp \
  -I$(srcdir)/./src/sipcc/core/gsm/h \
  -I$(srcdir)/./src/sipcc/plat/common \
  -I$(srcdir)/../../../media/mtransport \
  -I$(srcdir)/../../../dom/base \
  -I$(srcdir)/../trunk/third_party/libsrtp/srtp/include \
  -I$(srcdir)/../trunk/third_party/libsrtp/srtp/crypto/include \
  -I$(DEPTH)/dist/include \
  -I$(srcdir)/../trunk/third_party/libsrtp/config

# Skip rules that deal with regenerating Makefiles from Makefile.in files.
NO_MAKEFILE_RULE = 1
NO_SUBMAKEFILES_RULE = 1

include $(topsrcdir)/config/rules.mk
include $(DEPTH)/media/webrtc/signaling/common.mk
