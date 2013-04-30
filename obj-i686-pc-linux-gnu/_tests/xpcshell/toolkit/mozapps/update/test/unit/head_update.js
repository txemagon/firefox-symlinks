/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

const INSTALL_LOCALE = "en-US";
const APP_BIN_NAME = "firefox";
const BIN_SUFFIX = "";

//@line 10 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const APP_BIN_SUFFIX = "-bin";
//@line 14 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

//@line 18 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const IS_WIN = false;
//@line 20 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

//@line 24 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const IS_OS2 = false;
//@line 26 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

//@line 35 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const IS_MACOSX = false;
//@line 37 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

//@line 39 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const IS_UNIX = true;
//@line 43 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

//@line 47 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const IS_ANDROID = false;
//@line 49 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

const USE_EXECV = IS_UNIX && !IS_MACOSX;

//@line 55 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const IS_MAR_CHECKS_ENABLED = false;
//@line 57 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

const URL_HOST = "http://localhost:4444/";
const URL_PATH = "data";

const APPLY_TO_DIR_SUFFIX = "_applyToDir/";
//@line 65 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const UPDATED_DIR_SUFFIX = "updated/";
//@line 67 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const HELPER_BIN_FILE = "TestAUSHelper" + BIN_SUFFIX;
const MAR_COMPLETE_FILE = "data/complete.mar";
const MAR_PARTIAL_FILE = "data/partial.mar";
const MAR_OLD_VERSION_FILE = "data/old_version_mar.mar";
const MAR_WRONG_CHANNEL_FILE = "data/wrong_product_channel_mar.mar";
const UPDATER_BIN_FILE = "updater" + BIN_SUFFIX;
const MAINTENANCE_SERVICE_BIN_FILE = "maintenanceservice.exe";
const MAINTENANCE_SERVICE_INSTALLER_BIN_FILE = "maintenanceservice_installer.exe";
const UPDATE_SETTINGS_INI_FILE = "update-settings.ini";
const UPDATE_SETTINGS_CONTENTS = "[Settings]\n" +
                                 "ACCEPTED_MAR_CHANNEL_IDS=xpcshell-test\n"
const UPDATES_DIR_SUFFIX = "_mar";

const LOG_COMPLETE_SUCCESS = "data/complete_log_success";
const LOG_COMPLETE_SWITCH_SUCCESS = "data/complete_log_switch_success"
const LOG_COMPLETE_CC_SUCCESS = "data/complete_cc_log_success";
const LOG_COMPLETE_CC_SWITCH_SUCCESS = "data/complete_cc_log_switch_success";

const LOG_PARTIAL_SUCCESS = "data/partial_log_success";
const LOG_PARTIAL_SWITCH_SUCCESS = "data/partial_log_switch_success";
const LOG_PARTIAL_FAILURE = "data/partial_log_failure";

const ERR_CALLBACK_FILE_IN_USE = "NS_main: file in use - failed to " +
                                 "exclusively open executable file:"

const ERR_RENAME_FILE = "rename_file: failed to rename file";
const ERR_UNABLE_OPEN_DEST = "unable to open destination file";
const ERR_BACKUP_DISCARD = "backup_discard: unable to remove";

const LOG_SVC_SUCCESSFUL_LAUNCH = "Process was started... waiting on result.";

// variables are used instead of contants so tests can override these values
var gCallbackBinFile = "callback_app" + BIN_SUFFIX;
var gCallbackArgs = ["./", "callback.log", "Test Arg 2", "Test Arg 3"];
var gBackgroundUpdate = false;
var gSwitchApp = false;
var gDisableReplaceFallback = false;

// Time to wait for the test helper process before continuing the test
const TEST_HELPER_TIMEOUT = 2000;

// Use a copy of the main application executable for the test to avoid main
// executable in use errors.
const FILE_WIN_TEST_EXE = "_aus_test_app.exe";

var gTestserver;

var gXHR;
var gXHRCallback;

var gUpdatePrompt;
var gUpdatePromptCallback;

var gCheckFunc;
var gResponseBody;
var gResponseStatusCode = 200;
var gRequestURL;
var gUpdateCount;
var gUpdates;
var gStatusCode;
var gStatusText;

/**
 * The mar files used for the updater tests contain the following remove
 * operations.
 *
 * partial and complete test mar remove operations
 * -----------------------------------------------
 * remove "text1"
 * remove "text0"
 * rmrfdir "9/99/"
 * rmdir "9/99/"
 * rmrfdir "9/98/"
 * rmrfdir "9/97/"
 * rmrfdir "9/96/"
 * rmrfdir "9/95/"
 * rmrfdir "9/95/"
 * rmrfdir "9/94/"
 * rmdir "9/94/"
 * rmdir "9/93/"
 * rmdir "9/92/"
 * rmdir "9/91/"
 * rmdir "9/90/"
 * rmdir "9/90/"
 * rmrfdir "8/89/"
 * rmdir "8/89/"
 * rmrfdir "8/88/"
 * rmrfdir "8/87/"
 * rmrfdir "8/86/"
 * rmrfdir "8/85/"
 * rmrfdir "8/85/"
 * rmrfdir "8/84/"
 * rmdir "8/84/"
 * rmdir "8/83/"
 * rmdir "8/82/"
 * rmdir "8/81/"
 * rmdir "8/80/"
 * rmdir "8/80/"
 * rmrfdir "7/"
 * rmdir "6/"
 * remove "5/text1"
 * remove "5/text0"
 * rmrfdir "5/"
 * remove "4/text1"
 * remove "4/text0"
 * remove "4/exe0.exe"
 * rmdir "4/"
 * remove "3/text1"
 * remove "3/text0"
 *
 * partial test mar additional remove operations
 * ---------------------------------------------
 * remove "0/00/00text1"
 * remove "1/10/10text0"
 * rmdir "1/10/"
 * rmdir "1/"
 */
var TEST_DIRS = [
{
  relPathDir   : "a/b/3/",
  dirRemoved   : false,
  files        : ["3text0", "3text1"],
  filesRemoved : true
}, {
  relPathDir   : "a/b/4/",
  dirRemoved   : true,
  files        : ["4text0", "4text1"],
  filesRemoved : true
}, {
  relPathDir   : "a/b/5/",
  dirRemoved   : true,
  files        : ["5test.exe", "5text0", "5text1"],
  filesRemoved : true
}, {
  relPathDir   : "a/b/6/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/7/",
  dirRemoved   : true,
  files        : ["7text0", "7text1"],
  subDirs      : ["70/", "71/"],
  subDirFiles  : ["7xtest.exe", "7xtext0", "7xtext1"]
}, {
  relPathDir   : "a/b/8/",
  dirRemoved   : false
}, {
  relPathDir   : "a/b/8/80/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/8/81/",
  dirRemoved   : false,
  files        : ["81text0", "81text1"]
}, {
  relPathDir   : "a/b/8/82/",
  dirRemoved   : false,
  subDirs      : ["820/", "821/"]
}, {
  relPathDir   : "a/b/8/83/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/8/84/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/8/85/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/8/86/",
  dirRemoved   : true,
  files        : ["86text0", "86text1"]
}, {
  relPathDir   : "a/b/8/87/",
  dirRemoved   : true,
  subDirs      : ["870/", "871/"],
  subDirFiles  : ["87xtext0", "87xtext1"]
}, {
  relPathDir   : "a/b/8/88/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/8/89/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/9/90/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/9/91/",
  dirRemoved   : false,
  files        : ["91text0", "91text1"]
}, {
  relPathDir   : "a/b/9/92/",
  dirRemoved   : false,
  subDirs      : ["920/", "921/"]
}, {
  relPathDir   : "a/b/9/93/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/9/94/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/9/95/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/9/96/",
  dirRemoved   : true,
  files        : ["96text0", "96text1"]
}, {
  relPathDir   : "a/b/9/97/",
  dirRemoved   : true,
  subDirs      : ["970/", "971/"],
  subDirFiles  : ["97xtext0", "97xtext1"]
}, {
  relPathDir   : "a/b/9/98/",
  dirRemoved   : true
}, {
  relPathDir   : "a/b/9/99/",
  dirRemoved   : true
}];

// Populated by tests if needed.
var ADDITIONAL_TEST_DIRS = [];

// Set to true to log additional information for debugging. To log additional
// information for an individual test set DEBUG_AUS_TEST to true in the test's
// run_test function.
var DEBUG_AUS_TEST = true;

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* Shared code for xpcshell and mochitests-chrome */

// const Cc, Ci, and Cr are defined in netwerk/test/httpserver/httpd.js so we
// need to define unique ones.
const AUS_Cc = Components.classes;
const AUS_Ci = Components.interfaces;
const AUS_Cr = Components.results;
const AUS_Cu = Components.utils;
const AUS_Cm = Components.manager;

const PREF_APP_UPDATE_AUTO                = "app.update.auto";
const PREF_APP_UPDATE_STAGE_ENABLED       = "app.update.staging.enabled";
const PREF_APP_UPDATE_BACKGROUNDERRORS    = "app.update.backgroundErrors";
const PREF_APP_UPDATE_BACKGROUNDMAXERRORS = "app.update.backgroundMaxErrors";
const PREF_APP_UPDATE_CERTS_BRANCH        = "app.update.certs.";
const PREF_APP_UPDATE_CERT_CHECKATTRS     = "app.update.cert.checkAttributes";
const PREF_APP_UPDATE_CERT_ERRORS         = "app.update.cert.errors";
const PREF_APP_UPDATE_CERT_MAXERRORS      = "app.update.cert.maxErrors";
const PREF_APP_UPDATE_CERT_REQUIREBUILTIN = "app.update.cert.requireBuiltIn";
const PREF_APP_UPDATE_CHANNEL             = "app.update.channel";
const PREF_APP_UPDATE_ENABLED             = "app.update.enabled";
const PREF_APP_UPDATE_IDLETIME            = "app.update.idletime";
const PREF_APP_UPDATE_LOG                 = "app.update.log";
const PREF_APP_UPDATE_NEVER_BRANCH        = "app.update.never.";
const PREF_APP_UPDATE_PROMPTWAITTIME      = "app.update.promptWaitTime";
const PREF_APP_UPDATE_SERVICE_ENABLED     = "app.update.service.enabled";
const PREF_APP_UPDATE_SHOW_INSTALLED_UI   = "app.update.showInstalledUI";
const PREF_APP_UPDATE_SILENT              = "app.update.silent";
const PREF_APP_UPDATE_URL                 = "app.update.url";
const PREF_APP_UPDATE_URL_DETAILS         = "app.update.url.details";
const PREF_APP_UPDATE_URL_OVERRIDE        = "app.update.url.override";
const PREF_APP_UPDATE_SOCKET_ERRORS       = "app.update.socket.maxErrors";
const PREF_APP_UPDATE_RETRY_TIMEOUT       = "app.update.socket.retryTimeout";

const PREF_APP_UPDATE_CERT_INVALID_ATTR_NAME = PREF_APP_UPDATE_CERTS_BRANCH +
                                               "1.invalidName";

const PREF_APP_PARTNER_BRANCH             = "app.partner.";
const PREF_DISTRIBUTION_ID                = "distribution.id";
const PREF_DISTRIBUTION_VERSION           = "distribution.version";

const PREF_EXTENSIONS_UPDATE_URL          = "extensions.update.url";
const PREF_EXTENSIONS_STRICT_COMPAT       = "extensions.strictCompatibility";

const NS_APP_PROFILE_DIR_STARTUP   = "ProfDS";
const NS_APP_USER_PROFILE_50_DIR   = "ProfD";
const NS_GRE_DIR                   = "GreD";
const NS_XPCOM_CURRENT_PROCESS_DIR = "XCurProcD";
const XRE_UPDATE_ROOT_DIR          = "UpdRootD";

const CRC_ERROR   = 4;
const WRITE_ERROR = 7;

const FILE_BACKUP_LOG     = "backup-update.log";
const FILE_LAST_LOG       = "last-update.log";
const FILE_UPDATER_INI    = "updater.ini";
const FILE_UPDATES_DB     = "updates.xml";
const FILE_UPDATE_ACTIVE  = "active-update.xml";
const FILE_UPDATE_ARCHIVE = "update.mar";
const FILE_UPDATE_LOG     = "update.log";
const FILE_UPDATE_STATUS  = "update.status";
const FILE_UPDATE_VERSION = "update.version";

const MODE_RDONLY   = 0x01;
const MODE_WRONLY   = 0x02;
const MODE_CREATE   = 0x08;
const MODE_APPEND   = 0x10;
const MODE_TRUNCATE = 0x20;

const PR_RDWR        = 0x04;
const PR_CREATE_FILE = 0x08;
const PR_APPEND      = 0x10;
const PR_TRUNCATE    = 0x20;
const PR_SYNC        = 0x40;
const PR_EXCL        = 0x80;

const PERMS_FILE      = 0644;
const PERMS_DIRECTORY = 0755;

const DEFAULT_UPDATE_VERSION = "999999.0";

var gChannel;

/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 */

/**
 * Helper functions for creating xml strings used by application update tests.
 *
 * !IMPORTANT - This file contains everything needed (along with dependencies)
 * by the updates.sjs file used by the mochitest-chrome tests. Since xpcshell
 * used by the http server is launched with -v 170 this file must not use
 * features greater than JavaScript 1.7.
 */

const FILE_SIMPLE_MAR = "simple_no_pib.mar";

const SIZE_SIMPLE_MAR = "351";

const MD5_HASH_SIMPLE_MAR    = "d0a7f84dacc55a252ab916668a7cb216";
const SHA1_HASH_SIMPLE_MAR   = "f5053f9552d087c6c6ed83f9b19405eccf1436fc";
const SHA256_HASH_SIMPLE_MAR = "663c7cbd11fe45b0a71438387db924d205997ab85ccf5" +
                               "b40aebbdaef179796ab";
const SHA384_HASH_SIMPLE_MAR = "a57250554755a9f42b91932993599bb6b05e063dcbd71" +
                               "846e350232945dbad2b0c83208a07810cf798b3d11393" +
                               "99c453";
const SHA512_HASH_SIMPLE_MAR = "55d3e2a86acaeb0abb7a444c13bba748846fcbac7ff05" +
                               "8f8ee9c9260ba01e6aef86fa4a6c46a3016b675ef94e7" +
                               "7e63fbe912f64d155bed9b1c341dd56e575a26";

const STATE_NONE            = "null";
const STATE_DOWNLOADING     = "downloading";
const STATE_PENDING         = "pending";
const STATE_PENDING_SVC     = "pending-service";
const STATE_APPLYING        = "applying";
const STATE_APPLIED         = "applied";
const STATE_APPLIED_SVC     = "applied-service";
const STATE_SUCCEEDED       = "succeeded";
const STATE_DOWNLOAD_FAILED = "download-failed";
const STATE_FAILED          = "failed";

/**
 * Constructs a string representing a remote update xml file.
 *
 * @param  aUpdates
 *         The string representing the update elements.
 * @return The string representing a remote update xml file.
 */
function getRemoteUpdatesXMLString(aUpdates) {
  return "<?xml version=\"1.0\"?>\n" +
         "<updates>\n" +
           aUpdates +
         "</updates>\n";
}

/**
 * Constructs a string representing an update element for a remote update xml
 * file. See getUpdateString for parameter information not provided below.
 *
 * @param  aPatches
 *         String representing the application update patches.
 * @return The string representing an update element for an update xml file.
 */
function getRemoteUpdateString(aPatches, aType, aName, aDisplayVersion,
                               aAppVersion, aPlatformVersion, aBuildID,
                               aDetailsURL, aBillboardURL, aLicenseURL,
                               aShowPrompt, aShowNeverForVersion, aPromptWaitTime,
                               aShowSurvey, aVersion, aExtensionVersion, aCustom1,
                               aCustom2) {
  return getUpdateString(aType, aName, aDisplayVersion, aAppVersion,
                         aPlatformVersion, aBuildID, aDetailsURL,
                         aBillboardURL, aLicenseURL, aShowPrompt,
                         aShowNeverForVersion, aPromptWaitTime, aShowSurvey,
                         aVersion, aExtensionVersion, aCustom1, aCustom2) + ">\n" +
              aPatches +
         "  </update>\n";
}

/**
 * Constructs a string representing a patch element for a remote update xml
 * file. See getPatchString for parameter information not provided below.
 *
 * @return The string representing a patch element for a remote update xml file.
 */
function getRemotePatchString(aType, aURL, aHashFunction, aHashValue, aSize) {
  return getPatchString(aType, aURL, aHashFunction, aHashValue, aSize) +
         "/>\n";
}

/**
 * Constructs a string representing a local update xml file.
 *
 * @param  aUpdates
 *         The string representing the update elements.
 * @return The string representing a local update xml file.
 */
function getLocalUpdatesXMLString(aUpdates) {
  if (!aUpdates || aUpdates == "")
    return "<updates xmlns=\"http://www.mozilla.org/2005/app-update\"/>"
  return ("<updates xmlns=\"http://www.mozilla.org/2005/app-update\">" +
            aUpdates +
          "</updates>").replace(/>\s+\n*</g,'><');
}

/**
 * Constructs a string representing an update element for a local update xml
 * file. See getUpdateString for parameter information not provided below.
 *
 * @param  aPatches
 *         String representing the application update patches.
 * @param  aServiceURL (optional)
 *         The update's xml url.
 *         If not specified it will default to 'http://test_service/'.
 * @param  aIsCompleteUpdate (optional)
 *         The string 'true' if this update was a complete update or the string
 *         'false' if this update was a partial update.
 *         If not specified it will default to 'true'.
 * @param  aChannel (optional)
 *         The update channel name.
 *         If not specified it will default to the default preference value of
 *         app.update.channel.
 * @param  aForegroundDownload (optional)
 *         The string 'true' if this update was manually downloaded or the
 *         string 'false' if this update was automatically downloaded.
 *         If not specified it will default to 'true'.
 * @param  aPreviousAppVersion (optional)
 *         The application version prior to applying the update.
 *         If not specified it will not be present.
 * @return The string representing an update element for an update xml file.
 */
function getLocalUpdateString(aPatches, aType, aName, aDisplayVersion,
                              aAppVersion, aPlatformVersion, aBuildID,
                              aDetailsURL, aBillboardURL, aLicenseURL,
                              aServiceURL, aInstallDate, aStatusText,
                              aIsCompleteUpdate, aChannel, aForegroundDownload,
                              aShowPrompt, aShowNeverForVersion, aPromptWaitTime,
                              aShowSurvey, aVersion, aExtensionVersion,
                              aPreviousAppVersion, aCustom1, aCustom2) {
  let serviceURL = aServiceURL ? aServiceURL : "http://test_service/";
  let installDate = aInstallDate ? aInstallDate : "1238441400314";
  let statusText = aStatusText ? aStatusText : "Install Pending";
  let isCompleteUpdate =
    typeof(aIsCompleteUpdate) == "string" ? aIsCompleteUpdate : "true";
  let channel = aChannel ? aChannel
                         : gDefaultPrefBranch.getCharPref(PREF_APP_UPDATE_CHANNEL);
  let foregroundDownload =
    typeof(aForegroundDownload) == "string" ? aForegroundDownload : "true";
  let previousAppVersion = aPreviousAppVersion ? "previousAppVersion=\"" +
                                                 aPreviousAppVersion + "\" "
                                               : "";
  return getUpdateString(aType, aName, aDisplayVersion, aAppVersion,
                         aPlatformVersion, aBuildID, aDetailsURL, aBillboardURL,
                         aLicenseURL, aShowPrompt, aShowNeverForVersion,
                         aPromptWaitTime, aShowSurvey, aVersion, aExtensionVersion,
                         aCustom1, aCustom2) +
                   " " +
                   previousAppVersion +
                   "serviceURL=\"" + serviceURL + "\" " +
                   "installDate=\"" + installDate + "\" " +
                   "statusText=\"" + statusText + "\" " +
                   "isCompleteUpdate=\"" + isCompleteUpdate + "\" " +
                   "channel=\"" + channel + "\" " +
                   "foregroundDownload=\"" + foregroundDownload + "\">"  +
              aPatches +
         "  </update>";
}

/**
 * Constructs a string representing a patch element for a local update xml file.
 * See getPatchString for parameter information not provided below.
 *
 * @param  aSelected (optional)
 *         Whether this patch is selected represented or not. The string 'true'
 *         denotes selected and the string 'false' denotes not selected.
 *         If not specified it will default to the string 'true'.
 * @param  aState (optional)
 *         The patch's state.
 *         If not specified it will default to STATE_SUCCEEDED.
 * @return The string representing a patch element for a local update xml file.
 */
function getLocalPatchString(aType, aURL, aHashFunction, aHashValue, aSize,
                             aSelected, aState) {
  let selected = typeof(aSelected) == "string" ? aSelected : "true";
  let state = aState ? aState : STATE_SUCCEEDED;
  return getPatchString(aType, aURL, aHashFunction, aHashValue, aSize) + " " +
         "selected=\"" + selected + "\" " +
         "state=\"" + state + "\"/>\n";
}

/**
 * Constructs a string representing an update element for a remote update xml
 * file.
 *
 * @param  aType (optional)
 *         The update's type which should be major or minor. If not specified it
 *         will default to 'major'.
 * @param  aName (optional)
 *         The update's name.
 *         If not specified it will default to 'App Update Test'.
 * @param  aDisplayVersion (optional)
 *         The update's display version.
 *         If not specified it will default to 'version #' where # is the value
 *         of DEFAULT_UPDATE_VERSION.
 * @param  aAppVersion (optional)
 *         The update's application version.
 *         If not specified it will default to the value of
 *         DEFAULT_UPDATE_VERSION.
 * @param  aPlatformVersion (optional)
 *         The update's platform version.
 *         If not specified it will default to the value of
 *         DEFAULT_UPDATE_VERSION.
 * @param  aBuildID (optional)
 *         The update's build id.
 *         If not specified it will default to '20080811053724'.
 * @param  aDetailsURL (optional)
 *         The update's details url.
 *         If not specified it will default to 'http://test_details/' due to due
 *         to bug 470244.
 * @param  aBillboardURL (optional)
 *         The update's billboard url.
 *         If not specified it will not be present.
 * @param  aLicenseURL (optional)
 *         The update's license url.
 *         If not specified it will not be present.
 * @param  aShowPrompt (optional)
 *         Whether to show the prompt for the update when auto update is
 *         enabled.
 *         If not specified it will not be present and the update service will
 *         default to false.
 * @param  aShowNeverForVersion (optional)
 *         Whether to show the 'No Thanks' button in the update prompt.
 *         If not specified it will not be present and the update service will
 *         default to false.
 * @param  aPromptWaitTime (optional)
 *         Override for the app.update.promptWaitTime preference.
 * @param  aShowSurvey (optional)
 *         Whether to show the 'No Thanks' button in the update prompt.
 *         If not specified it will not be present and the update service will
 *         default to false.
 * @param  aVersion (optional)
 *         The update's application version from 1.9.2.
 *         If not specified it will not be present.
 * @param  aExtensionVersion (optional)
 *         The update's application version from 1.9.2.
 *         If not specified it will not be present.
 * @param  aCustom1 (optional)
 *         A custom attribute name and attribute value to add to the xml.
 *         Example: custom1_attribute="custom1 value"
 *         If not specified it will not be present.
 * @param  aCustom2 (optional)
 *         A custom attribute name and attribute value to add to the xml.
 *         Example: custom2_attribute="custom2 value"
 *         If not specified it will not be present.
 * @return The string representing an update element for an update xml file.
 */
function getUpdateString(aType, aName, aDisplayVersion, aAppVersion,
                         aPlatformVersion, aBuildID, aDetailsURL, aBillboardURL,
                         aLicenseURL, aShowPrompt, aShowNeverForVersion,
                         aPromptWaitTime, aShowSurvey, aVersion, aExtensionVersion,
                         aCustom1, aCustom2) {
  let type = aType ? aType : "major";
  let name = aName ? aName : "App Update Test";
  let displayVersion = "";
  if (aDisplayVersion || !aVersion) {
    displayVersion = "displayVersion=\"" +
                     (aDisplayVersion ? aDisplayVersion
                                      : "version " + DEFAULT_UPDATE_VERSION) +
                     "\" ";
  }
  // version has been deprecated in favor of displayVersion but it still needs
  // to be tested for forward compatibility.
  let version = aVersion ? "version=\"" + aVersion + "\" " : "";
  let appVersion = "";
  if (aAppVersion || !aExtensionVersion) {
    appVersion = "appVersion=\"" +
                 (aAppVersion ? aAppVersion : DEFAULT_UPDATE_VERSION) +
                 "\" ";
  }
  // extensionVersion has been deprecated in favor of appVersion but it still
  // needs to be tested for forward compatibility.
  let extensionVersion = aExtensionVersion ? "extensionVersion=\"" +
                                             aExtensionVersion + "\" "
                                           : "";
  let platformVersion = "";
  if (aPlatformVersion) {
    platformVersion = "platformVersion=\"" +
                      (aPlatformVersion ? aPlatformVersion
                                        : DEFAULT_UPDATE_VERSION) + "\" ";
  }
  let buildID = aBuildID ? aBuildID : "20080811053724";
  // XXXrstrong - not specifying a detailsURL will cause a leak due to bug 470244
//   let detailsURL = aDetailsURL ? "detailsURL=\"" + aDetailsURL + "\" " : "";
  let detailsURL = "detailsURL=\"" +
                   (aDetailsURL ? aDetailsURL
                                : "http://test_details/") + "\" ";
  let billboardURL = aBillboardURL ? "billboardURL=\"" +
                                     aBillboardURL + "\" "
                                   : "";
  let licenseURL = aLicenseURL ? "licenseURL=\"" + aLicenseURL + "\" " : "";
  let showPrompt = aShowPrompt ? "showPrompt=\"" + aShowPrompt + "\" " : "";
  let showNeverForVersion = aShowNeverForVersion ? "showNeverForVersion=\"" +
                                                   aShowNeverForVersion + "\" "
                                                 : "";
  let promptWaitTime = aPromptWaitTime ? "promptWaitTime=\"" + aPromptWaitTime +
                                         "\" "
                                       : "";
  let showSurvey = aShowSurvey ? "showSurvey=\"" + aShowSurvey + "\" " : "";
  let custom1 = aCustom1 ? aCustom1 + " " : "";
  let custom2 = aCustom2 ? aCustom2 + " " : "";
  return "  <update type=\"" + type + "\" " +
                   "name=\"" + name + "\" " +
                    displayVersion +
                    version +
                    appVersion +
                    extensionVersion +
                    platformVersion +
                    detailsURL +
                    billboardURL +
                    licenseURL +
                    showPrompt +
                    showNeverForVersion +
                    promptWaitTime +
                    showSurvey +
                    custom1 +
                    custom2 +
                   "buildID=\"" + buildID + "\"";
}

/**
 * Constructs a string representing a patch element for an update xml file.
 *
 * @param  aType (optional)
 *         The patch's type which should be complete or partial.
 *         If not specified it will default to 'complete'.
 * @param  aURL (optional)
 *         The patch's url to the mar file.
 *         If not specified it will default to the value of:
 *         URL_HOST + URL_PATH + "/" + FILE_SIMPLE_MAR
 * @param  aHashFunction (optional)
 *         The patch's hash function used to verify the mar file.
 *         If not specified it will default to 'MD5'.
 * @param  aHashValue (optional)
 *         The patch's hash value used to verify the mar file.
 *         If not specified it will default to the value of MD5_HASH_SIMPLE_MAR
 *         which is the MD5 hash value for the file specified by FILE_SIMPLE_MAR.
 * @param  aSize (optional)
 *         The patch's file size for the mar file.
 *         If not specified it will default to the file size for FILE_SIMPLE_MAR
 *         specified by SIZE_SIMPLE_MAR.
 * @return The string representing a patch element for an update xml file.
 */
function getPatchString(aType, aURL, aHashFunction, aHashValue, aSize) {
  let type = aType ? aType : "complete";
  let url = aURL ? aURL : URL_HOST + URL_PATH + "/" + FILE_SIMPLE_MAR;
  let hashFunction = aHashFunction ? aHashFunction : "MD5";
  let hashValue = aHashValue ? aHashValue : MD5_HASH_SIMPLE_MAR;
  let size = aSize ? aSize : SIZE_SIMPLE_MAR;
  return "    <patch type=\"" + type + "\" " +
                     "URL=\"" + url + "\" " +
                     "hashFunction=\"" + hashFunction + "\" " +
                     "hashValue=\"" + hashValue + "\" " +
                     "size=\"" + size + "\"";
}
//@line 89 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/shared.js"

AUS_Cu.import("resource://gre/modules/Services.jsm");
AUS_Cu.import("resource://gre/modules/XPCOMUtils.jsm");

const URI_UPDATES_PROPERTIES = "chrome://mozapps/locale/update/updates.properties";
const gUpdateBundle = Services.strings.createBundle(URI_UPDATES_PROPERTIES);

XPCOMUtils.defineLazyGetter(this, "gAUS", function test_gAUS() {
  return AUS_Cc["@mozilla.org/updates/update-service;1"].
         getService(AUS_Ci.nsIApplicationUpdateService).
         QueryInterface(AUS_Ci.nsITimerCallback).
         QueryInterface(AUS_Ci.nsIObserver).
         QueryInterface(AUS_Ci.nsIUpdateCheckListener);
});

XPCOMUtils.defineLazyServiceGetter(this, "gUpdateManager",
                                   "@mozilla.org/updates/update-manager;1",
                                   "nsIUpdateManager");

XPCOMUtils.defineLazyGetter(this, "gUpdateChecker", function test_gUC() {
  return AUS_Cc["@mozilla.org/updates/update-checker;1"].
         createInstance(AUS_Ci.nsIUpdateChecker);
});

XPCOMUtils.defineLazyGetter(this, "gUP", function test_gUP() {
  return AUS_Cc["@mozilla.org/updates/update-prompt;1"].
         createInstance(AUS_Ci.nsIUpdatePrompt);
});

XPCOMUtils.defineLazyGetter(this, "gDefaultPrefBranch", function test_gDPB() {
  return Services.prefs.getDefaultBranch(null);
});

XPCOMUtils.defineLazyGetter(this, "gPrefRoot", function test_gPR() {
  return Services.prefs.getBranch(null);
});

XPCOMUtils.defineLazyGetter(this, "gZipW", function test_gZipW() {
  return AUS_Cc["@mozilla.org/zipwriter;1"].
         createInstance(AUS_Ci.nsIZipWriter);
});

/* Initializes the update service stub */
function initUpdateServiceStub() {
  AUS_Cc["@mozilla.org/updates/update-service-stub;1"].
  createInstance(AUS_Ci.nsISupports);
}

/* Reloads the update metadata from disk */
function reloadUpdateManagerData() {
  gUpdateManager.QueryInterface(AUS_Ci.nsIObserver).
  observe(null, "um-reload-update-data", "");
}

/**
 * Sets the app.update.channel preference.
 *
 * @param  aChannel
 *         The update channel.
 */
function setUpdateChannel(aChannel) {
  gChannel = aChannel;
  debugDump("setting default pref " + PREF_APP_UPDATE_CHANNEL + " to " + gChannel);
  gDefaultPrefBranch.setCharPref(PREF_APP_UPDATE_CHANNEL, gChannel);
  gPrefRoot.addObserver(PREF_APP_UPDATE_CHANNEL, observer, false);
}

var observer = {
  observe: function(aSubject, aTopic, aData) {
    if (aTopic == "nsPref:changed" && aData == PREF_APP_UPDATE_CHANNEL) {
      var channel = gDefaultPrefBranch.getCharPref(PREF_APP_UPDATE_CHANNEL);
      if (channel != gChannel) {
        debugDump("Changing channel from " + channel + " to " + gChannel);
        gDefaultPrefBranch.setCharPref(PREF_APP_UPDATE_CHANNEL, gChannel);
      }
    }
  },
  QueryInterface: XPCOMUtils.generateQI([AUS_Ci.nsIObserver])
};

/**
 * Sets the app.update.url.override preference.
 *
 * @param  aURL
 *         The update url. If not specified 'URL_HOST + "update.xml"' will be
 *         used.
 */
function setUpdateURLOverride(aURL) {
  let url = aURL ? aURL : URL_HOST + "update.xml";
  debugDump("setting " + PREF_APP_UPDATE_URL_OVERRIDE + " to " + url);
  Services.prefs.setCharPref(PREF_APP_UPDATE_URL_OVERRIDE, url);
}

/**
 * Returns either the active or regular update database XML file.
 *
 * @param  isActiveUpdate
 *         If true this will return the active-update.xml otherwise it will
 *         return the updates.xml file.
 */
function getUpdatesXMLFile(aIsActiveUpdate) {
  var file = getUpdatesRootDir();
  file.append(aIsActiveUpdate ? FILE_UPDATE_ACTIVE : FILE_UPDATES_DB);
  return file;
}

/**
 * Writes the updates specified to either the active-update.xml or the
 * updates.xml.
 *
 * @param  aContent
 *         The updates represented as a string to write to the XML file.
 * @param  isActiveUpdate
 *         If true this will write to the active-update.xml otherwise it will
 *         write to the updates.xml file.
 */
function writeUpdatesToXMLFile(aContent, aIsActiveUpdate) {
  writeFile(getUpdatesXMLFile(aIsActiveUpdate), aContent);
}

/**
 * Writes the current update operation/state to a file in the patch
 * directory, indicating to the patching system that operations need
 * to be performed.
 *
 * @param  aStatus
 *         The status value to write.
 */
function writeStatusFile(aStatus) {
  var file = getUpdatesDir();
  file.append("0");
  file.append(FILE_UPDATE_STATUS);
  aStatus += "\n";
  writeFile(file, aStatus);
}

/**
 * Writes the current update version to a file in the patch directory,
 * indicating to the patching system the version of the update.
 *
 * @param  aVersion
 *         The version value to write.
 */
function writeVersionFile(aVersion) {
  var file = getUpdatesDir();
  file.append("0");
  file.append(FILE_UPDATE_VERSION);
  aVersion += "\n";
  writeFile(file, aVersion);
}

/**
 * Gets the updates root directory.
 *
 * @return nsIFile for the updates root directory.
 */
function getUpdatesRootDir() {
  try {
    return Services.dirsvc.get(XRE_UPDATE_ROOT_DIR, AUS_Ci.nsIFile);
  } catch (e) {
    // Fall back on the current process directory
    return getCurrentProcessDir();
  }
}

/**
 * Gets the updates directory.
 *
 * @return nsIFile for the updates directory.
 */
function getUpdatesDir() {
  var dir = getUpdatesRootDir();
  dir.append("updates");
  return dir;
}

/**
 * Writes text to a file. This will replace existing text if the file exists
 * and create the file if it doesn't exist.
 *
 * @param  aFile
 *         The file to write to. Will be created if it doesn't exist.
 * @param  aText
 *         The text to write to the file. If there is existing text it will be
 *         replaced.
 */
function writeFile(aFile, aText) {
  var fos = AUS_Cc["@mozilla.org/network/file-output-stream;1"].
            createInstance(AUS_Ci.nsIFileOutputStream);
  if (!aFile.exists())
    aFile.create(AUS_Ci.nsILocalFile.NORMAL_FILE_TYPE, PERMS_FILE);
  fos.init(aFile, MODE_WRONLY | MODE_CREATE | MODE_TRUNCATE, PERMS_FILE, 0);
  fos.write(aText, aText.length);
  fos.close();
}

/**
 * Reads the current update operation/state in a file in the patch
 * directory.
 *
 * @param  aFile (optional)
 *         nsIFile to read the update status from. If not provided the
 *         application's update status file will be used.
 * @return The status value.
 */
function readStatusFile(aFile) {
  var file;
  if (aFile) {
    file = aFile.clone();
    file.append(FILE_UPDATE_STATUS);
  }
  else {
    file = getUpdatesDir();
    file.append("0");
    file.append(FILE_UPDATE_STATUS);
  }
  return readFile(file).split("\n")[0];
}

/**
 * Reads text from a file and returns the string.
 *
 * @param  aFile
 *         The file to read from.
 * @return The string of text read from the file.
 */
function readFile(aFile) {
  var fis = AUS_Cc["@mozilla.org/network/file-input-stream;1"].
            createInstance(AUS_Ci.nsIFileInputStream);
  if (!aFile.exists())
    return null;
  fis.init(aFile, MODE_RDONLY, PERMS_FILE, 0);
  var sis = AUS_Cc["@mozilla.org/scriptableinputstream;1"].
            createInstance(AUS_Ci.nsIScriptableInputStream);
  sis.init(fis);
  var text = sis.read(sis.available());
  sis.close();
  return text;
}

/**
 * Reads the binary contents of a file and returns it as a string.
 *
 * @param  aFile
 *         The file to read from.
 * @return The contents of the file as a string.
 */
function readFileBytes(aFile) {
  var fis = AUS_Cc["@mozilla.org/network/file-input-stream;1"].
            createInstance(AUS_Ci.nsIFileInputStream);
  fis.init(aFile, -1, -1, false);
  var bis = AUS_Cc["@mozilla.org/binaryinputstream;1"].
            createInstance(AUS_Ci.nsIBinaryInputStream);
  bis.setInputStream(fis);
  var data = [];
  var count = fis.available();
  while (count > 0) {
    var bytes = bis.readByteArray(Math.min(65535, count));
    data.push(String.fromCharCode.apply(null, bytes));
    count -= bytes.length;
    if (bytes.length == 0)
      throw "Nothing read from input stream!";
  }
  data.join('');
  fis.close();
  return data.toString();
}

/* Returns human readable status text from the updates.properties bundle */
function getStatusText(aErrCode) {
  return getString("check_error-" + aErrCode);
}

/* Returns a string from the updates.properties bundle */
function getString(aName) {
  try {
    return gUpdateBundle.GetStringFromName(aName);
  }
  catch (e) {
  }
  return null;
}

/**
 * Gets the file extension for an nsIFile.
 *
 * @param  aFile
 *         The file to get the file extension for.
 * @return The file extension.
 */
function getFileExtension(aFile) {
  return Services.io.newFileURI(aFile).QueryInterface(AUS_Ci.nsIURL).
         fileExtension;
}

/**
 * Removes the updates.xml file, active-update.xml file, and all files and
 * sub-directories in the updates directory except for the "0" sub-directory.
 * This prevents some tests from failing due to files being left behind when the
 * tests are interrupted.
 */
function removeUpdateDirsAndFiles() {
  var file = getUpdatesXMLFile(true);
  try {
    if (file.exists())
      file.remove(false);
  }
  catch (e) {
    dump("Unable to remove file\npath: " + file.path +
         "\nException: " + e + "\n");
  }

  file = getUpdatesXMLFile(false);
  try {
    if (file.exists())
      file.remove(false);
  }
  catch (e) {
    dump("Unable to remove file\npath: " + file.path +
         "\nException: " + e + "\n");
  }

  // This fails sporadically on Mac OS X so wrap it in a try catch
  var updatesDir = getUpdatesDir();
  try {
    cleanUpdatesDir(updatesDir);
  }
  catch (e) {
    dump("Unable to remove files / directories from directory\npath: " +
         updatesDir.path + "\nException: " + e + "\n");
  }
}

/**
 * Removes all files and sub-directories in the updates directory except for
 * the "0" sub-directory.
 *
 * @param  aDir
 *         nsIFile for the directory to be deleted.
 */
function cleanUpdatesDir(aDir) {
  if (!aDir.exists())
    return;

  var dirEntries = aDir.directoryEntries;
  while (dirEntries.hasMoreElements()) {
    var entry = dirEntries.getNext().QueryInterface(AUS_Ci.nsIFile);

    if (entry.isDirectory()) {
      if (entry.leafName == "0" && entry.parent.leafName == "updates") {
        cleanUpdatesDir(entry);
        entry.permissions = PERMS_DIRECTORY;
      }
      else {
        try {
          entry.remove(true);
          return;
        }
        catch (e) {
        }
        cleanUpdatesDir(entry);
        entry.permissions = PERMS_DIRECTORY;
        try {
          entry.remove(true);
        }
        catch (e) {
          dump("cleanUpdatesDir: unable to remove directory\npath: " +
               entry.path + "\nException: " + e + "\n");
          throw(e);
        }
      }
    }
    else {
      entry.permissions = PERMS_FILE;
      try {
        entry.remove(false);
      }
      catch (e) {
        dump("cleanUpdatesDir: unable to remove file\npath: " + entry.path +
             "\nException: " + e + "\n");
        throw(e);
      }
    }
  }
}

/**
 * Deletes a directory and its children. First it tries nsIFile::Remove(true).
 * If that fails it will fall back to recursing, setting the appropriate
 * permissions, and deleting the current entry.
 *
 * @param  aDir
 *         nsIFile for the directory to be deleted.
 */
function removeDirRecursive(aDir) {
  if (!aDir.exists())
    return;
  try {
    aDir.remove(true);
    return;
  }
  catch (e) {
  }

  var dirEntries = aDir.directoryEntries;
  while (dirEntries.hasMoreElements()) {
    var entry = dirEntries.getNext().QueryInterface(AUS_Ci.nsIFile);

    if (entry.isDirectory()) {
      removeDirRecursive(entry);
    }
    else {
      entry.permissions = PERMS_FILE;
      try {
        entry.remove(false);
      }
      catch (e) {
        dump("removeDirRecursive: unable to remove file\npath: " + entry.path +
             "\nException: " + e + "\n");
        throw(e);
      }
    }
  }

  aDir.permissions = PERMS_DIRECTORY;
  try {
    aDir.remove(true);
  }
  catch (e) {
    dump("removeDirRecursive: unable to remove directory\npath: " + entry.path +
         "\nException: " + e + "\n");
    throw(e);
  }
}

/**
 * Returns the directory for the currently running process. This is used to
 * clean up after the tests and to locate the active-update.xml and updates.xml
 * files.
 *
 * @return nsIFile for the current process directory.
 */
function getCurrentProcessDir() {
  return Services.dirsvc.get(NS_XPCOM_CURRENT_PROCESS_DIR, AUS_Ci.nsIFile);
}

/**
 * Returns the Gecko Runtime Engine directory. This is used to locate the the
 * updater binary (Windows and Linux) or updater package (Mac OS X). For
 * XULRunner applications this is different than the currently running process
 * directory.
 *
 * @return nsIFile for the Gecko Runtime Engine directory.
 */
function getGREDir() {
  return Services.dirsvc.get(NS_GRE_DIR, AUS_Ci.nsIFile);
}

/**
 * Logs TEST-INFO messages.
 *
 * @param  aText
 *         The text to log.
 * @param  aCaller (optional)
 *         An optional Components.stack.caller. If not specified
 *         Components.stack.caller will be used.
 */
function logTestInfo(aText, aCaller) {
  let caller = (aCaller ? aCaller : Components.stack.caller);
  dump("TEST-INFO | " + caller.filename + " | [" + caller.name + " : " +
       caller.lineNumber + "] " + aText + "\n");
}

/**
 * Logs TEST-INFO messages when DEBUG_AUS_TEST evaluates to true.
 *
 * @param  aText
 *         The text to log.
 * @param  aCaller (optional)
 *         An optional Components.stack.caller. If not specified
 *         Components.stack.caller will be used.
 */
function debugDump(aText, aCaller) {
  if (DEBUG_AUS_TEST) {
    let caller = aCaller ? aCaller : Components.stack.caller;
    logTestInfo(aText, caller);
  }
}
//@line 293 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

//@line 297 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
const STATE_APPLIED_PLATFORM = STATE_APPLIED;
//@line 299 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"

// This makes it possible to run most tests on xulrunner where the update
// channel default preference is not set.
if (APP_BIN_NAME == "xulrunner") {
  try {
    gDefaultPrefBranch.getCharPref(PREF_APP_UPDATE_CHANNEL);
  }
  catch (e) {
    setUpdateChannel("test_channel");
  }
}

/**
 * Nulls out the most commonly used global vars used by tests as appropriate.
 */
function cleanUp() {
  removeUpdateDirsAndFiles();

  // Force the update manager to reload the update data to prevent it from
  // writing the old data to the files that have just been removed.
  reloadUpdateManagerData();

  if (gChannel) {
    gPrefRoot.removeObserver(PREF_APP_UPDATE_CHANNEL, observer);
  }

  // Call app update's observe method passing xpcom-shutdown to test that the
  // shutdown of app update runs without throwing or leaking. The observer
  // method is used directly instead of calling notifyObservers so components
  // outside of the scope of this test don't assert and thereby cause app update
  // tests to fail.
  gAUS.observe(null, "xpcom-shutdown", "");

  if (gXHR) {
    gXHRCallback     = null;

    gXHR.responseXML = null;
    // null out the event handlers to prevent a mFreeCount leak of 1
    gXHR.onerror     = null;
    gXHR.onload      = null;
    gXHR.onprogress  = null;

    gXHR             = null;
  }

  gTestserver = null;
}

/**
 * Sets the most commonly used preferences used by tests
 */
function setDefaultPrefs() {
  Services.prefs.setBoolPref(PREF_APP_UPDATE_ENABLED, true);
  // Don't display UI for a successful installation. Some apps may not set this
  // pref to false like Firefox does.
  Services.prefs.setBoolPref(PREF_APP_UPDATE_SHOW_INSTALLED_UI, false);
  // Enable Update logging
  Services.prefs.setBoolPref(PREF_APP_UPDATE_LOG, true);
}

/**
 * Initializes the most commonly used settings and creates an instance of the
 * update service stub.
 */
function standardInit() {
  createAppInfo("xpcshell@tests.mozilla.org", "XPCShell", "1.0", "2.0");
  setDefaultPrefs();
  // Initialize the update service stub component
  initUpdateServiceStub();
}

/* Custom path handler for the http server */
function pathHandler(metadata, response) {
  response.setHeader("Content-Type", "text/xml", false);
  response.setStatusLine(metadata.httpVersion, gResponseStatusCode, "OK");
  response.bodyOutputStream.write(gResponseBody, gResponseBody.length);
}

/**
 * Helper function for getting the relative path to the directory where the
 * update will be applied.
 *
 * The main files in the update are located two directories below the apply to
 * directory since Mac OS X sets the last modified time for the root directory
 * to the current time and if the update changes any files in the root directory
 * then it wouldn't be possible to test (bug 600098).
 *
 * @return  The relative path to the directory where the update will be applied.
 */
function getApplyDirPath() {
  return TEST_ID + APPLY_TO_DIR_SUFFIX;
}

/**
 * Helper function for getting the nsIFile for the directory where the update
 * will be applied.
 *
 * The main files in the update are located two directories below the apply to
 * directory since Mac OS X sets the last modified time for the root directory
 * to the current time and if the update changes any files in the root directory
 * then it wouldn't be possible to test (bug 600098).
 *
 * @return  The nsIFile for the directory where the update will be applied.
 */
function getApplyDirFile(aRelPath, allowNonexistent) {
  let relpath = getApplyDirPath() + (aRelPath ? aRelPath : "");
  return do_get_file(relpath, allowNonexistent);
}

/**
 * Helper function for getting the updated directory.
 */
function getUpdatedDirPath() {
  let suffix = "";
  if (gBackgroundUpdate) {
    suffix = UPDATED_DIR_SUFFIX;
  }
  return getApplyDirPath() + suffix;
}

/**
 * Helper function for getting the nsIFile for the directory where the update
 * has been applied.
 *
 * This will be the same as getApplyDirFile for foreground updates, but will
 * point to a different file for the case of background updates.
 *
 * Functions which attempt to access the files in the updated directory should
 * be using this instead of getApplyDirFile.
 *
 * @return  The nsIFile for the directory where the update has been applied.
 */
function getTargetDirFile(aRelPath, allowNonexistent) {
  let relpath = getUpdatedDirPath() + (aRelPath ? aRelPath : "");
  return do_get_file(relpath, allowNonexistent);
}

if (IS_WIN) {
  const kLockFileName = "updated.update_in_progress.lock";
  /**
   * Helper function for locking a directory on Windows.
   */
  function lockDirectory(aDir) {
    var file = aDir.clone();
    file.append(kLockFileName);
    file.create(file.NORMAL_FILE_TYPE, 0444);
    file.QueryInterface(AUS_Ci.nsILocalFileWin);
    file.fileAttributesWin |= file.WFA_READONLY;
    file.fileAttributesWin &= ~file.WFA_READWRITE;
    logTestInfo("testing the successful creation of the lock file");
    do_check_true(file.exists());
    do_check_false(file.isWritable());
  }
  /**
   * Helper function for unlocking a directory on Windows.
   */
  function unlockDirectory(aDir) {
    var file = aDir.clone();
    file.append(kLockFileName);
    file.QueryInterface(AUS_Ci.nsILocalFileWin);
    file.fileAttributesWin |= file.WFA_READWRITE;
    file.fileAttributesWin &= ~file.WFA_READONLY;
    logTestInfo("removing and testing the successful removal of the lock file");
    file.remove(false);
    do_check_false(file.exists());
  }
}

/**
 * Copies a directory and its children. First it tries nsIFile::CopyTo on the
 * source directory and if that fails it will fall back to recursing.
 *
 * @param  aSrcDir
 *         nsIFile for the source directory to be copied from.
 * @param  aDestDir
 *         nsIFile for the destination directory parent.
 * @param  aDestLeafName
 *         the destination directory name.
 */
function copyDirRecursive(aSrcDir, aDestDir, aDestLeafName) {
  try {
    aSrcDir.copyTo(aDestDir, aDestLeafName);
    return;
  }
  catch (e) {
    logTestInfo("copyTo error - src path: " + aSrcDir.path + ", dest path: " +
                aDestDir.path + ", dir name: " + aDestLeafName +
                ", exception: " + e);
  }

  let destDir = aDestDir.clone();
  destDir.append(aDestLeafName);
  if (!destDir.exists()) {
    try {
      destDir.create(AUS_Ci.nsIFile.DIRECTORY_TYPE, PERMS_DIRECTORY);
    }
    catch (e) {
      logTestInfo("unable to create directory, path: " + destDir.path +
                  ", exception: " + e);
      do_throw(e);
    }
  }
  var dirEntries = aSrcDir.directoryEntries;
  while (dirEntries.hasMoreElements()) {
    let entry = dirEntries.getNext().QueryInterface(AUS_Ci.nsIFile);

    if (entry.isDirectory()) {
      copyDirRecursive(entry, destDir, entry.leafName);
    }
    else {
      let destFile = destDir.clone();
      destFile.append(entry.leafName);
      if (destFile.exists()) {
        try {
          destFile.remove(false);
        }
        catch (e) {
          logTestInfo("unable to remove file, path: " + destFile.path +
                      ", exception: " + e);
          let bakFile = destDir.clone();
          bakFile.append(entry.leafName + ".bak");
          logTestInfo("attempting moveTo of file, src path: " + destFile.path +
                      ", dest path: " + bakFile.path + ", exception: " + e);
          try {
            destFile.moveTo(destDir, bakFile.leafName);
          }
          catch (e) {
            logTestInfo("unable to move file, src path: " + destFile.path +
                        ", dest path: " + bakFile.path + ", exception: " + e);
            do_throw(e);
          }
        }
      }
      try {
        entry.copyTo(destDir, entry.leafName);
      }
      catch (e) {
        logTestInfo("unable to copy file, src path: " + entry.path +
                    ", dest path: " + destFile.path + ", exception: " + e);
        do_throw(e);
      }
    }
  }
}

/**
 * Helper function for updater tests for launching the updater binary to apply
 * a mar file.
 *
 * @return  The exit value returned from the updater binary.
 */
function runUpdate() {
  // Copy the updater binary to the updates directory.
  let binDir = getGREDir();
  let updater = binDir.clone();
  updater.append("updater.app");
  if (!updater.exists()) {
    updater = binDir.clone();
    updater.append(UPDATER_BIN_FILE);
    if (!updater.exists()) {
      do_throw("Unable to find updater binary!");
    }
  }

  let updatesDir = do_get_file(TEST_ID + UPDATES_DIR_SUFFIX, true);
  updater.copyTo(updatesDir, updater.leafName);
  let updateBin = updatesDir.clone();
  updateBin.append(updater.leafName);
  if (updateBin.leafName == "updater.app") {
    updateBin.append("Contents");
    updateBin.append("MacOS");
    updateBin.append("updater");
    if (!updateBin.exists())
      do_throw("Unable to find the updater executable!");
  }

  let updatesDirPath = updatesDir.path;
  if (/ /.test(updatesDirPath))
    updatesDirPath = '"' + updatesDirPath + '"';

  let applyToDir = getApplyDirFile();
  let applyToDirPath = applyToDir.path;
  if (gBackgroundUpdate || gSwitchApp) {
    applyToDirPath += "/" + UPDATED_DIR_SUFFIX;
  }
  if (IS_WIN) {
    // Convert to native path
    applyToDirPath = applyToDirPath.replace(/\//g, "\\");
  }
  if (/ /.test(applyToDirPath))
    applyToDirPath = '"' + applyToDirPath + '"';

  let callbackApp = getApplyDirFile("a/b/" + gCallbackBinFile);
  callbackApp.permissions = PERMS_DIRECTORY;

  let cwdPath = callbackApp.parent.path;
  if (/ /.test(cwdPath))
    cwdPath = '"' + cwdPath + '"';

  let callbackAppPath = callbackApp.path;
  if (/ /.test(callbackAppPath))
    callbackAppPath = '"' + callbackAppPath + '"';

  let updateSettingsIni = getApplyDirFile(null, true);
  updateSettingsIni.append(UPDATE_SETTINGS_INI_FILE);
  writeFile(updateSettingsIni, UPDATE_SETTINGS_CONTENTS);

  let args = [updatesDirPath, applyToDirPath, 0];
  if (gBackgroundUpdate) {
    args[2] = -1;
  } else {
    if (gSwitchApp) {
      args[2] = "0/replace";
    }
    args = args.concat([cwdPath, callbackAppPath]);
    args = args.concat(gCallbackArgs);
  }
  logTestInfo("Running the updater: " + updateBin.path + " " + args.join(" "));

  let env = AUS_Cc["@mozilla.org/process/environment;1"].
            getService(AUS_Ci.nsIEnvironment);
  if (gDisableReplaceFallback) {
    env.set("MOZ_NO_REPLACE_FALLBACK", "1");
  }

  let process = AUS_Cc["@mozilla.org/process/util;1"].
                createInstance(AUS_Ci.nsIProcess);
  process.init(updateBin);
  process.run(true, args, args.length);

  if (gDisableReplaceFallback) {
    env.set("MOZ_NO_REPLACE_FALLBACK", "");
  }

  return process.exitValue;
}

let gServiceLaunchedCallbackLog = null;
let gServiceLaunchedCallbackArgs = null;

/**
 * Helper function to check whether the maintenance service updater tests should
 * run. See bug 711660 for more details.
 *
 * @return true if the test should run and false if it shouldn't.
 */
function shouldRunServiceTest(aFirstTest) {
  // In case the machine is running an old maintenance service or if it
  // is not installed, and permissions exist to install it.  Then install
  // the newer bin that we have.
  attemptServiceInstall();

  const REG_PATH = "SOFTWARE\\Mozilla\\MaintenanceService\\" +
                   "3932ecacee736d366d6436db0f55bce4";

  let key = AUS_Cc["@mozilla.org/windows-registry-key;1"].
            createInstance(AUS_Ci.nsIWindowsRegKey);
  try {
    key.open(AUS_Ci.nsIWindowsRegKey.ROOT_KEY_LOCAL_MACHINE, REG_PATH,
             AUS_Ci.nsIWindowsRegKey.ACCESS_READ | key.WOW64_64);
  }
  catch (e) {
    logTestInfo("this test can only run on the buildbot build system at this " +
                "time.");
    return false;
  }

  let binDir = getGREDir();
  let updaterBin = binDir.clone();
  updaterBin.append(UPDATER_BIN_FILE);
  if (!updaterBin.exists()) {
    do_throw("Unable to find updater binary!");
  }

  let updaterBinPath = updaterBin.path;
  if (/ /.test(updaterBinPath)) {
    updaterBinPath = '"' + updaterBinPath + '"';
  }

  // Check to make sure the service is installed
  let helperBin = do_get_file(HELPER_BIN_FILE);
  let args = ["wait-for-service-stop", "MozillaMaintenance", "10"];
  let process = AUS_Cc["@mozilla.org/process/util;1"].
                createInstance(AUS_Ci.nsIProcess);
  process.init(helperBin);
  logTestInfo("Checking if the service exists on this machine.");
  process.run(true, args, args.length);
  if (process.exitValue == 0xEE) {
    logTestInfo("this test can only run when the service is installed.");
    return false;
  } else {
    logTestInfo("Service exists, return value: " + process.exitValue);
  }

  // If this is the first test in the series, then there is no reason the
  // service should be anything but stopped, so be strict here and throw
  // an error.
  if (aFirstTest && process.exitValue != 0) {
    do_throw("First test, check for service stopped state returned error " + 
             process.exitValue);
  }

//@line 705 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
  // Make sure the binaries are signed
  args = ["check-signature", updaterBinPath];
  process = AUS_Cc["@mozilla.org/process/util;1"].
            createInstance(AUS_Ci.nsIProcess);
  process.init(helperBin);
  process.run(true, args, args.length);
  if (process.exitValue == 0) {
    return true;
  }
  logTestInfo("this test can only run on builds with signed binaries. " +
              HELPER_BIN_FILE + " returned " + process.exitValue)
  return false;
//@line 718 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
}

/**
 * Copies the specified filename from the dist/bin
 * directory into the apply-to directory.
 *
 * @param filename The name of the file to copy
*/
function copyBinToApplyToDir(filename) {
  let binDir = getGREDir();
  let fileToCopy = binDir.clone();
  fileToCopy.append(filename);
  if (!fileToCopy.exists()) {
    do_throw("Unable to copy binary: " + filename);
  }
  let applyToUpdater = getApplyDirFile(null, true);
  if (applyToUpdater.path != binDir.path) {
    do_print("copying " + fileToCopy.path + " to: " + applyToUpdater.path);
    fileToCopy.copyTo(applyToUpdater, filename);
  }
}

/**
 * Attempts to upgrade the maintenance service if permissions are allowed.
 * This is useful for XP where we have permission to upgrade in case an
 * older service installer exists.  Also if the user manually installed into
 * a unprivileged location.
*/
function attemptServiceInstall() {
  var version = AUS_Cc["@mozilla.org/system-info;1"]
                .getService(AUS_Ci.nsIPropertyBag2)
                .getProperty("version");
  var isVistaOrHigher = (parseFloat(version) >= 6.0);
  if (isVistaOrHigher) {
    return;
  }
  
  let binDir = getGREDir();
  let installerFile = binDir.clone();
  installerFile.append(MAINTENANCE_SERVICE_INSTALLER_BIN_FILE);
  if (!installerFile.exists()) {
    do_throw(MAINTENANCE_SERVICE_INSTALLER_BIN_FILE + " not found.");
  }
  let installerProcess = AUS_Cc["@mozilla.org/process/util;1"].
                         createInstance(AUS_Ci.nsIProcess);
  installerProcess.init(installerFile);
  logTestInfo("Starting installer process...");
  installerProcess.run(true, [], 0);
}

/**
 * Helper function for updater tests for launching the updater using the
 * maintenance service to apply a mar file.
 *
 * @param aInitialStatus  the initial value of update.status
 * @param aExpectedStatus the expected value of update.status when the test finishes
 * @param aCallback       the function to be called when the update is finished
 * @param aUpdatesDir     the updates root directory to use (optional)
 * @param aCheckSvcLog    whether the service log should be checked (optional)
 */
function runUpdateUsingService(aInitialStatus, aExpectedStatus,
                               aCallback, aUpdatesDir, aCheckSvcLog) {
  // Check the service logs for a successful update
  function checkServiceLogs(aOriginalContents) {
    let contents = readServiceLogFile();
    logTestInfo("The contents of maintenanceservice.log:\n" + contents + "\n");
    do_check_neq(contents, aOriginalContents);
    do_check_neq(contents.indexOf(LOG_SVC_SUCCESSFUL_LAUNCH), -1);
  }
  function readServiceLogFile() {
    let file = AUS_Cc["@mozilla.org/file/directory_service;1"].
               getService(AUS_Ci.nsIProperties).
               get("CmAppData", AUS_Ci.nsIFile);
    file.append("Mozilla");
    file.append("logs");
    file.append("maintenanceservice.log");
    return readFile(file);
  }
  function waitServiceApps() {
    // maintenanceservice_installer.exe is started async during updates.
    waitForApplicationStop("maintenanceservice_installer.exe");
    // maintenanceservice_tmp.exe is started async from the service installer.
    waitForApplicationStop("maintenanceservice_tmp.exe");
    // In case the SCM thinks the service is stopped, but process still exists.
    waitForApplicationStop("maintenanceservice.exe");
  }
  function waitForServiceStop(aFailTest) {
    waitServiceApps(); 
    logTestInfo("Waiting for service to stop if necessary...");
    // Use the helper bin to ensure the service is stopped. If not
    // stopped then wait for the service to be stopped (at most 120 seconds)
    let helperBin = do_get_file(HELPER_BIN_FILE);
    let helperBinArgs = ["wait-for-service-stop", 
                         "MozillaMaintenance", 
                         "120"];
    let helperBinProcess = AUS_Cc["@mozilla.org/process/util;1"].
                           createInstance(AUS_Ci.nsIProcess);
    helperBinProcess.init(helperBin);
    logTestInfo("Stopping service...");
    helperBinProcess.run(true, helperBinArgs, helperBinArgs.length);
    if (helperBinProcess.exitValue == 0xEE) {
      do_throw("The service does not exist on this machine.  Return value: " +
               helperBinProcess.exitValue);
    } else if (helperBinProcess.exitValue != 0) {
      if (aFailTest) {
        do_throw("maintenance service did not stop, last state: " +
                 helperBinProcess.exitValue + ". Forcing test failure.");
      } else {
        logTestInfo("maintenance service did not stop, last state: " + 
                    helperBinProcess.exitValue + ".  May cause failures.");
      }
    } else {
      logTestInfo("Service stopped.");
    }
    waitServiceApps(); 
  }
  function waitForApplicationStop(application) {
    logTestInfo("Waiting for " + application + " to stop if " + 
                "necessary...");
    // Use the helper bin to ensure the application is stopped. 
    // If not, then wait for it to be stopped (at most 120 seconds)
    let helperBin = do_get_file(HELPER_BIN_FILE);
    let helperBinArgs = ["wait-for-application-exit", 
                         application, 
                         "120"];
    let helperBinProcess = AUS_Cc["@mozilla.org/process/util;1"].
                           createInstance(AUS_Ci.nsIProcess);
    helperBinProcess.init(helperBin);
    helperBinProcess.run(true, helperBinArgs, helperBinArgs.length);
    if (helperBinProcess.exitValue != 0) {
      do_throw(application + " did not stop, last state: " +
               helperBinProcess.exitValue + ". Forcing test failure.");
    }
  }

  // Make sure the service from the previous test is already stopped.
  waitForServiceStop(true);

  // Prevent the cleanup function from begin run more than once
  if (typeof(gRegisteredServiceCleanup) === "undefined") {
    gRegisteredServiceCleanup = true;

    do_register_cleanup(function serviceCleanup() {
      resetEnvironment();

      // This will delete the app console log file if it exists.
      try {
        getAppConsoleLogPath();
      }
      catch (e) {
        logTestInfo("unable to remove file during cleanup. Exception: " + e);
      }

      // This will delete the app arguments log file if it exists.
      try {
        getAppArgsLogPath();
      }
      catch (e) {
        logTestInfo("unable to remove file during cleanup. Exception: " + e);
      }
    });
  }

  if (aCheckSvcLog === undefined) {
    aCheckSvcLog = true; // default to true
  }

  let svcOriginalLog;
  if (aCheckSvcLog) {
    svcOriginalLog = readServiceLogFile();
  }

  let appArgsLogPath = getAppArgsLogPath();
  gServiceLaunchedCallbackLog = appArgsLogPath.replace(/^"|"$/g, "");

  let updatesDir = aUpdatesDir || do_get_file(TEST_ID + UPDATES_DIR_SUFFIX);
  let file = updatesDir.clone();
  file.append(FILE_UPDATE_STATUS);
  writeFile(file, aInitialStatus + "\n");

  // sanity check
  do_check_eq(readStatusFile(updatesDir), aInitialStatus);

  file = updatesDir.clone();
  file.append(FILE_UPDATE_VERSION);
  writeFile(file, DEFAULT_UPDATE_VERSION + "\n");

  gServiceLaunchedCallbackArgs = [
    "-no-remote",
    "-process-updates",
    "-dump-args",
    appArgsLogPath
  ];

  let launchBin = getLaunchBin();
  let args = getProcessArgs(["-dump-args", appArgsLogPath]);
  logTestInfo("launching " + launchBin.path + " " + args.join(" "));

  let process = AUS_Cc["@mozilla.org/process/util;1"].
                   createInstance(AUS_Ci.nsIProcess);
  process.init(launchBin);

  // Override the update root directory
  gEnvUpdateRootOverride = updatesDir.path;
  gEnvAppDirOverride = getApplyDirFile(null).path;

  if (gSwitchApp) {
    // We want to set the env vars again
    gShouldResetEnv = undefined;
  }

  setEnvironment();

  // There is a security check done by the service to make sure the updater 
  // we are executing is the same as the one in the apply-to dir. 
  // To make sure they match from tests we copy updater.exe to the apply-to dir.
  copyBinToApplyToDir(UPDATER_BIN_FILE);

  // The service will execute maintenanceservice_installer.exe and
  // will copy maintenanceservice.exe out of the same directory from
  // the installation directory.  So we need to make sure both of those
  // bins always exist in the installation directory.
  copyBinToApplyToDir(MAINTENANCE_SERVICE_BIN_FILE);
  copyBinToApplyToDir(MAINTENANCE_SERVICE_INSTALLER_BIN_FILE);

  let updateSettingsIni = getApplyDirFile(null, true);
  updateSettingsIni.append(UPDATE_SETTINGS_INI_FILE);
  writeFile(updateSettingsIni, UPDATE_SETTINGS_CONTENTS);

  // Firefox does not wait for the service command to finish, but
  // we still launch the process sync to avoid intermittent failures with
  // the log file not being written out yet.
  // We will rely on watching the update.status file and waiting for the service
  // to stop to know the service command is done.
  process.run(true, args, args.length);

  resetEnvironment();

  function timerCallback(timer) {
    // Wait for the expected status
    let status = readStatusFile(updatesDir);
    // For failed status, we don't care what the failure code is
    if (aExpectedStatus == STATE_FAILED) {
      status = status.split(": ")[0];
    }
    // status will probably always be equal to STATE_APPLYING but there is a
    // race condition where it would be possible on slower machines where status
    // could be equal to STATE_PENDING_SVC.
    if (status == STATE_APPLYING || 
        status == STATE_PENDING_SVC) {
      logTestInfo("Still waiting to see the " + aExpectedStatus +
                  " status, got " + status + " for now...");
      return;
    }
    
    // Make sure all of the logs are written out.
    waitForServiceStop(false);

    do_check_eq(status, aExpectedStatus);

    timer.cancel();
    timer = null;

    if (aCheckSvcLog) {
      checkServiceLogs(svcOriginalLog);
    } 
    aCallback();
  }

  let timer = AUS_Cc["@mozilla.org/timer;1"].createInstance(AUS_Ci.nsITimer);
  timer.initWithCallback(timerCallback, 1000, timer.TYPE_REPEATING_SLACK);
}

/**
 * Gets the platform specific shell binary that is launched using nsIProcess and
 * in turn launches the updater.
 *
 * @return  nsIFile for the shell binary to launch using nsIProcess.
 * @throws  if the shell binary doesn't exist.
 */
function getLaunchBin() {
  let launchBin;
  if (IS_WIN) {
    launchBin = Services.dirsvc.get("WinD", AUS_Ci.nsIFile);
    launchBin.append("System32");
    launchBin.append("cmd.exe");
  }
  else {
    launchBin = AUS_Cc["@mozilla.org/file/local;1"].
                createInstance(AUS_Ci.nsILocalFile);
    launchBin.initWithPath("/bin/sh");
  }

  if (!launchBin.exists())
    do_throw(launchBin.path + " must exist to run this test!");

  return launchBin;
}

function waitForHelperSleep() {
  // Give the lock file process time to lock the file before updating otherwise
  // this test can fail intermittently on Windows debug builds.
  let output = getApplyDirFile("a/b/output", true);
  if (readFile(output) != "sleeping\n") {
    do_timeout(TEST_HELPER_TIMEOUT, waitForHelperSleep);
    return;
  }
  output.remove(false);
  do_timeout(TEST_HELPER_TIMEOUT, doUpdate);
}

function waitForHelperFinished() {
  // Give the lock file process time to lock the file before updating otherwise
  // this test can fail intermittently on Windows debug builds.
  let output = getApplyDirFile("a/b/output", true);
  if (readFile(output) != "finished\n") {
    do_timeout(TEST_HELPER_TIMEOUT, waitForHelperFinished);
    return;
  }
  // Give the lock file process time to unlock the file before deleting the
  // input and output files.
  do_timeout(TEST_HELPER_TIMEOUT, waitForHelperFinishFileUnlock);
}

function waitForHelperFinishFileUnlock() {
  try {
    let output = getApplyDirFile("a/b/output", true);
    if (output.exists()) {
      output.remove(false);
    }
    let input = getApplyDirFile("a/b/input", true);
    if (input.exists()) {
      input.remove(false);
    }
  }
  catch (e) {
    // Give the lock file process time to unlock the file before deleting the
    // input and output files.
    do_timeout(TEST_HELPER_TIMEOUT, waitForHelperFinishFileUnlock);
    return;
  }
  do_timeout(TEST_HELPER_TIMEOUT, checkUpdate);
}

function setupHelperFinish() {
  let input = getApplyDirFile("a/b/input", true);
  writeFile(input, "finish\n");
  do_timeout(TEST_HELPER_TIMEOUT, waitForHelperFinished);
}

/**
 * Helper function for updater binary tests for setting up the files and
 * directories used by the test.
 *
 * @param   aMarFile
 *          The mar file for the update test.
 */
function setupUpdaterTest(aMarFile) {
  // Remove the directory where the updater, mar file, etc. will be copied to
  let updatesDir = do_get_file(TEST_ID + UPDATES_DIR_SUFFIX, true);
  try {
    removeDirRecursive(updatesDir);
  }
  catch (e) {
    dump("Unable to remove directory\n" +
         "path: " + updatesDir.path + "\n" +
         "Exception: " + e + "\n");
  }
  if (!updatesDir.exists()) {
    updatesDir.create(AUS_Ci.nsIFile.DIRECTORY_TYPE, PERMS_DIRECTORY);
  }

  // Remove the directory where the update will be applied if it exists.
  let applyToDir = getApplyDirFile(null, true);
  try {
    removeDirRecursive(applyToDir);
  }
  catch (e) {
    dump("Unable to remove directory\n" +
         "path: " + applyToDir.path + "\n" +
         "Exception: " + e + "\n");
  }
  logTestInfo("testing successful removal of the directory used to apply the " +
              "mar file");
  do_check_false(applyToDir.exists());

  // Add the test files that will be updated for a successful update or left in
  // the initial state for a failed update.
  TEST_FILES.forEach(function SUT_TF_FE(aTestFile) {
    if (aTestFile.originalFile || aTestFile.originalContents) {
      let testDir = getApplyDirFile(aTestFile.relPathDir, true);
      if (!testDir.exists())
        testDir.create(AUS_Ci.nsIFile.DIRECTORY_TYPE, PERMS_DIRECTORY);

      let testFile;
      if (aTestFile.originalFile) {
        testFile = do_get_file(aTestFile.originalFile);
        testFile.copyTo(testDir, aTestFile.fileName);
        testFile = getApplyDirFile(aTestFile.relPathDir + aTestFile.fileName);
      }
      else {
        testFile = getApplyDirFile(aTestFile.relPathDir + aTestFile.fileName, true);
        writeFile(testFile, aTestFile.originalContents);
      }

      // Skip these tests on Windows and OS/2 since their
      // implementaions of chmod doesn't really set permissions.
      if (!IS_WIN && !IS_OS2 && aTestFile.originalPerms) {
        testFile.permissions = aTestFile.originalPerms;
        // Store the actual permissions on the file for reference later after
        // setting the permissions.
        if (!aTestFile.comparePerms)
          aTestFile.comparePerms = testFile.permissions;
      }
    }
  });

  let helperBin = do_get_file(HELPER_BIN_FILE);
  let afterApplyBinDir = getApplyDirFile("a/b/", true);
  helperBin.copyTo(afterApplyBinDir, gCallbackBinFile);

  if (!gBackgroundUpdate && !gSwitchApp) {
    let updaterIniContents = "[Strings]\n" +
                             "Title=Update XPCShell Test\n" +
                             "Info=Application Update Test - " + TEST_ID + "\n";
    let updaterIni = updatesDir.clone();
    updaterIni.append(FILE_UPDATER_INI);
    writeFile(updaterIni, updaterIniContents);
    updaterIni.copyTo(afterApplyBinDir, FILE_UPDATER_INI);
  }

  // Copy the mar that will be applied
  let mar = do_get_file(aMarFile);
  mar.copyTo(updatesDir, FILE_UPDATE_ARCHIVE);

  // Add the test directory that will be updated for a successful update or left in
  // the initial state for a failed update.
  var testDirs = TEST_DIRS.concat(ADDITIONAL_TEST_DIRS);
  testDirs.forEach(function SUT_TD_FE(aTestDir) {
    let testDir = getApplyDirFile(aTestDir.relPathDir, true);
    if (!testDir.exists()) {
      testDir.create(AUS_Ci.nsIFile.DIRECTORY_TYPE, PERMS_DIRECTORY);
    }

    if (aTestDir.files) {
      aTestDir.files.forEach(function SUT_TD_F_FE(aTestFile) {
        let testFile = getApplyDirFile(aTestDir.relPathDir + aTestFile, true);
        if (!testFile.exists()) {
          testFile.create(AUS_Ci.nsIFile.FILE_TYPE, PERMS_FILE);
        }
      });
    }

    if (aTestDir.subDirs) {
      aTestDir.subDirs.forEach(function SUT_TD_SD_FE(aSubDir) {
        let testSubDir = getApplyDirFile(aTestDir.relPathDir + aSubDir, true);
        if (!testSubDir.exists()) {
          testSubDir.create(AUS_Ci.nsIFile.DIRECTORY_TYPE, PERMS_DIRECTORY);
        }

        if (aTestDir.subDirFiles) {
          aTestDir.subDirFiles.forEach(function SUT_TD_SDF_FE(aTestFile) {
            let testFile = getApplyDirFile(aTestDir.relPathDir + aSubDir + aTestFile, true);
            if (!testFile.exists()) {
              testFile.create(AUS_Ci.nsIFile.FILE_TYPE, PERMS_FILE);
            }
          });
        }
      });
    }
  });
}

/**
 * Helper function for updater binary tests to clean up the state after the test
 * has finished.
 */
function cleanupUpdaterTest() {
  let updatesDir = do_get_file(TEST_ID + UPDATES_DIR_SUFFIX, true);
  try {
    removeDirRecursive(updatesDir);
  }
  catch (e) {
    dump("Unable to remove directory\n" +
         "path: " + updatesDir.path + "\n" +
         "Exception: " + e + "\n");
  }

  // Try to remove the updates and the apply to directories.
  let applyToDir = getApplyDirFile(null, true);
  try {
    removeDirRecursive(applyToDir);
  }
  catch (e) {
    dump("Unable to remove directory\n" +
         "path: " + applyToDir.path + "\n" +
         "Exception: " + e + "\n");
  }

  cleanUp();
}

/**
 * Helper function for updater binary tests for verifying the contents of the
 * update log after a successful update.
 */
function checkUpdateLogContents(aCompareLogFile) {
  let updateLog = do_get_file(TEST_ID + UPDATES_DIR_SUFFIX, true);
  updateLog.append(FILE_UPDATE_LOG);
  let updateLogContents = readFileBytes(updateLog);
  if (gBackgroundUpdate) {
    // Skip the background update messages
    updateLogContents = updateLogContents.replace(/Performing a background update/, "");
  } else if (gSwitchApp) {
    // Skip the switch app request messages
    updateLogContents = updateLogContents.replace(/Performing a background update/, "");
    updateLogContents = updateLogContents.replace(/Performing a replace request/, "");
  }
  // Skip the source/destination lines since they contain absolute paths.
  updateLogContents = updateLogContents.replace(/SOURCE DIRECTORY.*/g, "");
  updateLogContents = updateLogContents.replace(/DESTINATION DIRECTORY.*/g, "");
  // Skip lines that log failed attempts to open the callback executable.
  updateLogContents = updateLogContents.replace(/NS_main: callback app open attempt .*/g, "");
  if (gSwitchApp) {
    // Remove the lines which contain absolute paths
    updateLogContents = updateLogContents.replace(/^Begin moving.*$/mg, "");
//@line 1251 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
  }
  updateLogContents = updateLogContents.replace(/\r/g, "");
  // Replace error codes since they are different on each platform.
  updateLogContents = updateLogContents.replace(/, err:.*\n/g, "\n");
  // Replace to make the log parsing happy.
  updateLogContents = updateLogContents.replace(/non-fatal error /g, "");
  // The FindFile results when enumerating the filesystem on Windows is not
  // determistic so the results matching the following need to be ignored.
  updateLogContents = updateLogContents.replace(/.* a\/b\/7\/7text.*\n/g, "");
  // Remove consecutive newlines
  updateLogContents = updateLogContents.replace(/\n+/g, "\n");
  // Remove leading and trailing newlines
  updateLogContents = updateLogContents.replace(/^\n|\n$/g, "");

  let compareLog = do_get_file(aCompareLogFile);
  let compareLogContents = readFileBytes(compareLog);
  // Remove leading and trailing newlines
  compareLogContents = compareLogContents.replace(/^\n|\n$/g, "");

  do_check_eq(compareLogContents, updateLogContents);
}

function checkUpdateLogContains(aCheckString) {
  let updateLog = do_get_file(TEST_ID + UPDATES_DIR_SUFFIX, true);
  updateLog.append(FILE_UPDATE_LOG);
  let updateLogContents = readFileBytes(updateLog);
  logTestInfo("log file contents:\n" + updateLogContents + "\n");
  do_check_true(updateLogContents.indexOf(aCheckString) != -1);
}

/**
 * Helper function for updater binary tests for verifying the state of files and
 * directories after a successful update.
 */
function checkFilesAfterUpdateSuccess() {
  logTestInfo("testing contents of files after a successful update");
  TEST_FILES.forEach(function CFAUS_TF_FE(aTestFile) {
    let testFile = getTargetDirFile(aTestFile.relPathDir + aTestFile.fileName, true);
    logTestInfo("testing file: " + testFile.path);
    if (aTestFile.compareFile || aTestFile.compareContents) {
      do_check_true(testFile.exists());

      // Skip these tests on Windows and OS/2 since their
      // implementaions of chmod doesn't really set permissions.
      if (!IS_WIN && !IS_OS2 && aTestFile.comparePerms) {
        // Check if the permssions as set in the complete mar file are correct.
        let logPerms = "testing file permissions - ";
        if (aTestFile.originalPerms) {
          logPerms += "original permissions: " + aTestFile.originalPerms.toString(8) + ", ";
        }
        logPerms += "compare permissions : " + aTestFile.comparePerms.toString(8) + ", ";
        logPerms += "updated permissions : " + testFile.permissions.toString(8);
        logTestInfo(logPerms);
        do_check_eq(testFile.permissions & 0xfff, aTestFile.comparePerms & 0xfff);
      }

      if (aTestFile.compareFile) {
        do_check_eq(readFileBytes(testFile),
                    readFileBytes(do_get_file(aTestFile.compareFile)));
      }
      else {
        do_check_eq(readFileBytes(testFile), aTestFile.compareContents);
      }
    }
    else {
      do_check_false(testFile.exists());
    }
  });

  logTestInfo("testing operations specified in removed-files were performed " +
              "after a successful update");
  var testDirs = TEST_DIRS.concat(ADDITIONAL_TEST_DIRS);
  testDirs.forEach(function CFAUS_TD_FE(aTestDir) {
    let testDir = getTargetDirFile(aTestDir.relPathDir, true);
    logTestInfo("testing directory: " + testDir.path);
    if (aTestDir.dirRemoved) {
      do_check_false(testDir.exists());
    }
    else {
      do_check_true(testDir.exists());

      if (aTestDir.files) {
        aTestDir.files.forEach(function CFAUS_TD_F_FE(aTestFile) {
          let testFile = getTargetDirFile(aTestDir.relPathDir + aTestFile, true);
          logTestInfo("testing directory file: " + testFile.path);
          if (aTestDir.filesRemoved) {
            do_check_false(testFile.exists());
          }
          else {
            do_check_true(testFile.exists());
          }
        });
      }

      if (aTestDir.subDirs) {
        aTestDir.subDirs.forEach(function CFAUS_TD_SD_FE(aSubDir) {
          let testSubDir = getTargetDirFile(aTestDir.relPathDir + aSubDir, true);
          logTestInfo("testing sub-directory: " + testSubDir.path);
          do_check_true(testSubDir.exists());
          if (aTestDir.subDirFiles) {
            aTestDir.subDirFiles.forEach(function CFAUS_TD_SDF_FE(aTestFile) {
              let testFile = getTargetDirFile(aTestDir.relPathDir + aSubDir + aTestFile, true);
              logTestInfo("testing sub-directory file: " + testFile.path);
              do_check_true(testFile.exists());
            });
          }
        });
      }
    }
  });

  checkFilesAfterUpdateCommon();
}

/**
 * Helper function for updater binary tests for verifying the state of files and
 * directories after a failed update.
 *
 * @param aGetDirectory: the function used to get the files in the target directory.
 * Pass getApplyDirFile if you want to test the case of a failed switch request.
 */
function checkFilesAfterUpdateFailure(aGetDirectory) {
  let getdir = aGetDirectory || getTargetDirFile;
  logTestInfo("testing contents of files after a failed update");
  TEST_FILES.forEach(function CFAUF_TF_FE(aTestFile) {
    let testFile = getdir(aTestFile.relPathDir + aTestFile.fileName, true);
    logTestInfo("testing file: " + testFile.path);
    if (aTestFile.compareFile || aTestFile.compareContents) {
      do_check_true(testFile.exists());

      // Skip these tests on Windows and OS/2 since their
      // implementaions of chmod doesn't really set permissions.
      if (!IS_WIN && !IS_OS2 && aTestFile.comparePerms) {
        // Check the original permssions are retained on the file.
        let logPerms = "testing file permissions - ";
        if (aTestFile.originalPerms) {
          logPerms += "original permissions: " + aTestFile.originalPerms.toString(8) + ", ";
        }
        logPerms += "compare permissions : " + aTestFile.comparePerms.toString(8) + ", ";
        logPerms += "updated permissions : " + testFile.permissions.toString(8);
        logTestInfo(logPerms);
        do_check_eq(testFile.permissions & 0xfff, aTestFile.comparePerms & 0xfff);
      }

      if (aTestFile.compareFile) {
        do_check_eq(readFileBytes(testFile),
                    readFileBytes(do_get_file(aTestFile.compareFile)));
      }
      else {
        do_check_eq(readFileBytes(testFile), aTestFile.compareContents);
      }
    }
    else {
      do_check_false(testFile.exists());
    }
  });

  logTestInfo("testing operations specified in removed-files were not " +
              "performed after a failed update");
  TEST_DIRS.forEach(function CFAUF_TD_FE(aTestDir) {
    let testDir = getdir(aTestDir.relPathDir, true);
    logTestInfo("testing directory file: " + testDir.path);
    do_check_true(testDir.exists());

    if (aTestDir.files) {
      aTestDir.files.forEach(function CFAUS_TD_F_FE(aTestFile) {
        let testFile = getdir(aTestDir.relPathDir + aTestFile, true);
        logTestInfo("testing directory file: " + testFile.path);
        do_check_true(testFile.exists());
      });
    }

    if (aTestDir.subDirs) {
      aTestDir.subDirs.forEach(function CFAUS_TD_SD_FE(aSubDir) {
        let testSubDir = getdir(aTestDir.relPathDir + aSubDir, true);
        logTestInfo("testing sub-directory: " + testSubDir.path);
        do_check_true(testSubDir.exists());
        if (aTestDir.subDirFiles) {
          aTestDir.subDirFiles.forEach(function CFAUS_TD_SDF_FE(aTestFile) {
            let testFile = getdir(aTestDir.relPathDir + aSubDir + aTestFile, true);
            logTestInfo("testing sub-directory file: " + testFile.path);
            do_check_true(testFile.exists());
          });
        }
      });
    }
  });

  checkFilesAfterUpdateCommon();
}

/**
 * Helper function for updater binary tests for verifying patch files and
 * moz-backup files aren't left behind after a successful or failed update.
 */
function checkFilesAfterUpdateCommon() {
  logTestInfo("testing patch files should not be left behind");
  let updatesDir = do_get_file(TEST_ID + UPDATES_DIR_SUFFIX, true);
  let entries = updatesDir.QueryInterface(AUS_Ci.nsIFile).directoryEntries;
  while (entries.hasMoreElements()) {
    let entry = entries.getNext().QueryInterface(AUS_Ci.nsIFile);
    do_check_neq(getFileExtension(entry), "patch");
  }

  logTestInfo("testing backup files should not be left behind");
  let applyToDir = getTargetDirFile(null, true);
  checkFilesInDirRecursive(applyToDir, checkForBackupFiles);
}

/**
 * Helper function for updater binary tests for verifying the contents of the
 * updater callback application log which should contain the arguments passed to
 * the callback application.
 */
function checkCallbackAppLog() {
  let appLaunchLog = getApplyDirFile("a/b/" + gCallbackArgs[1], true);
  if (!appLaunchLog.exists()) {
    do_timeout(TEST_HELPER_TIMEOUT, checkCallbackAppLog);
    return;
  }

  let expectedLogContents = gCallbackArgs.join("\n") + "\n";
  let logContents = readFile(appLaunchLog);
  // It is possible for the log file contents check to occur before the log file
  // contents are completely written so wait until the contents are the expected
  // value. If the contents are never the expected value then the test will
  // fail by timing out.
  if (logContents != expectedLogContents) {
    do_timeout(TEST_HELPER_TIMEOUT, checkCallbackAppLog);
    return;
  }

  logTestInfo("testing that the callback application successfully launched " +
              "and the expected command line arguments passed to it");
  do_check_eq(logContents, expectedLogContents);

  removeCallbackCopy();
}

/**
 * Helper function for updater service tests for verifying the contents of the
 * updater callback application log which should contain the arguments passed to
 * the callback application.
 */
function checkCallbackServiceLog() {
  do_check_neq(gServiceLaunchedCallbackLog, null);

  let expectedLogContents = gServiceLaunchedCallbackArgs.join("\n") + "\n";
  let logFile = AUS_Cc["@mozilla.org/file/local;1"].createInstance(AUS_Ci.nsILocalFile);
  logFile.initWithPath(gServiceLaunchedCallbackLog);
  let logContents = readFile(logFile);
 
  // It is possible for the log file contents check to occur before the log file
  // contents are completely written so wait until the contents are the expected
  // value. If the contents are never the expected value then the test will
  // fail by timing out.
  if (logContents != expectedLogContents) {
    logTestInfo("callback service log not expected value, waiting longer");
    do_timeout(TEST_HELPER_TIMEOUT, checkCallbackServiceLog);
    return;
  }

  logTestInfo("testing that the callback application successfully launched " +
              "and the expected command line arguments passed to it");
  do_check_eq(logContents, expectedLogContents);

  removeCallbackCopy();
}

function removeCallbackCopy() {
  // Remove the copy of the application executable used for the test on
  // Windows if it exists.
  let appBinCopy = getAppDir();
  appBinCopy.append(TEST_ID + FILE_WIN_TEST_EXE);
  if (appBinCopy.exists()) {
    try {
      logTestInfo("attempting removal of file: " + appBinCopy.path);
      appBinCopy.remove(false);
    }
    catch (e) {
      logTestInfo("non-fatal error removing file during cleanup (will try " +
                  "again). File: " + appBinCopy.path + " Exception: " + e);
      do_timeout(TEST_HELPER_TIMEOUT, removeCallbackCopy);
      return;
    }
  }
  // Use a timeout to give any files that were in use additional 
  // time to close.  Same as updater.exe without service tests.
  do_timeout(TEST_HELPER_TIMEOUT, do_test_finished);
}

// Waits until files that are in use that break tests are no longer in use and
// then calls removeCallbackCopy.
function waitForFilesInUse() {
  let maintSvcInstaller = getAppDir();
  maintSvcInstaller.append("MAINTENANCE_SERVICE_INSTALLER_BIN_FILE");

  let helper = getAppDir();
  helper.append("uninstall");
  helper.append("helper.exe");

  let files = [maintSvcInstaller, helper];
  for (let i = 0; i < files.length; ++i) {
    let file = files[i];
    let fileBak = file.parent.clone();
    if (file.exists()) {
      fileBak.append(file.leafName + ".bak");
      try {
        if (fileBak.exists()) {
          fileBak.remove(false);
        }
        file.copyTo(fileBak.parent, fileBak.leafName);
        file.remove(false);
        fileBak.moveTo(file.parent, file.leafName);
        logTestInfo("file is not in use. path: " + file.path);
      }
      catch (e) {
        logTestInfo("file in use, will try again after " + CHECK_TIMEOUT_MILLI +
                    " ms, path: " + file.path + ", exception: " + e);
        try {
          if (fileBak.exists()) {
            fileBak.remove(false);
          }
        }
        catch (e) {
          logTestInfo("unable to remove file, this should never happen! " +
                      "path: " + fileBak.path + ", exception: " + e);
        }
        do_timeout(CHECK_TIMEOUT_MILLI, waitForFilesInUse);
        return;
      }
    }
  }

  removeCallbackCopy();
}

/**
 * Helper function for updater binary tests for verifying there are no update
 * backup files left behind after an update.
 *
 * @param   aFile
 *          An nsIFile to check if it has moz-backup for its extension.
 */
function checkForBackupFiles(aFile) {
  do_check_neq(getFileExtension(aFile), "moz-backup");
}

/**
 * Helper function for updater binary tests for recursively enumerating a
 * directory and calling a callback function with the file as a parameter for
 * each file found.
 *
 * @param   aDir
 *          A nsIFile for the directory to be deleted
 * @param   aCallback
 *          A callback function that will be called with the file as a
 *          parameter for each file found.
 */
function checkFilesInDirRecursive(aDir, aCallback) {
  if (!aDir.exists())
    do_throw("Directory must exist!");

  let dirEntries = aDir.directoryEntries;
  while (dirEntries.hasMoreElements()) {
    let entry = dirEntries.getNext().QueryInterface(AUS_Ci.nsIFile);

    if (entry.isDirectory()) {
      checkFilesInDirRecursive(entry, aCallback);
    }
    else {
      aCallback(entry);
    }
  }
}

/**
 * Sets up the bare bones XMLHttpRequest implementation below. 
 *
 * @param   callback
 *          The callback function that will call the nsIDomEventListener's
 *          handleEvent method.
 *
 *          Example of the callback function
 *
 *            function callHandleEvent() {
 *              gXHR.status = gExpectedStatus;
 *              var e = { target: gXHR };
 *              gXHR.onload.handleEvent(e);
 *            }
 */
function overrideXHR(callback) {
  gXHRCallback = callback;
  gXHR = new xhr();
  var registrar = Components.manager.QueryInterface(AUS_Ci.nsIComponentRegistrar);
  registrar.registerFactory(gXHR.classID, gXHR.classDescription,
                            gXHR.contractID, gXHR);
}


/**
 * Bare bones XMLHttpRequest implementation for testing onprogress, onerror,
 * and onload nsIDomEventListener handleEvent.
 */
function makeHandler(val) {
  if (typeof val == "function")
    return ({ handleEvent: val });
  return val;
}
function xhr() {
}
xhr.prototype = {
  overrideMimeType: function(mimetype) { },
  setRequestHeader: function(header, value) { },
  status: null,
  channel: { set notificationCallbacks(val) { } },
  _url: null,
  _method: null,
  open: function (method, url) {
    gXHR.channel.originalURI = Services.io.newURI(url, null, null);
    gXHR._method = method; gXHR._url = url;
  },
  responseXML: null,
  responseText: null,
  send: function(body) {
    do_execute_soon(gXHRCallback); // Use a timeout so the XHR completes
  },
  _onprogress: null,
  set onprogress(val) { gXHR._onprogress = makeHandler(val); },
  get onprogress() { return gXHR._onprogress; },
  _onerror: null,
  set onerror(val) { gXHR._onerror = makeHandler(val); },
  get onerror() { return gXHR._onerror; },
  _onload: null,
  set onload(val) { gXHR._onload = makeHandler(val); },
  get onload() { return gXHR._onload; },
  addEventListener: function(event, val, capturing) {
    eval("gXHR._on" + event + " = val");
  },
  flags: AUS_Ci.nsIClassInfo.SINGLETON,
  implementationLanguage: AUS_Ci.nsIProgrammingLanguage.JAVASCRIPT,
  getHelperForLanguage: function(language) null,
  getInterfaces: function(count) {
    var interfaces = [AUS_Ci.nsISupports];
    count.value = interfaces.length;
    return interfaces;
  },
  classDescription: "XMLHttpRequest",
  contractID: "@mozilla.org/xmlextras/xmlhttprequest;1",
  classID: Components.ID("{c9b37f43-4278-4304-a5e0-600991ab08cb}"),
  createInstance: function (outer, aIID) {
    if (outer == null)
      return gXHR.QueryInterface(aIID);
    throw AUS_Cr.NS_ERROR_NO_AGGREGATION;
  },
  QueryInterface: function(aIID) {
    if (aIID.equals(AUS_Ci.nsIClassInfo) ||
        aIID.equals(AUS_Ci.nsISupports))
      return gXHR;
    throw AUS_Cr.NS_ERROR_NO_INTERFACE;
  },
  get wrappedJSObject() { return this; }
};

function overrideUpdatePrompt(callback) {
  var registrar = Components.manager.QueryInterface(AUS_Ci.nsIComponentRegistrar);
  gUpdatePrompt = new UpdatePrompt();
  gUpdatePromptCallback = callback;
  registrar.registerFactory(gUpdatePrompt.classID, gUpdatePrompt.classDescription,
                            gUpdatePrompt.contractID, gUpdatePrompt);
}

function UpdatePrompt() {
  var fns = ["checkForUpdates", "showUpdateAvailable", "showUpdateDownloaded",
             "showUpdateError", "showUpdateHistory", "showUpdateInstalled"];

  fns.forEach(function(promptFn) {
    UpdatePrompt.prototype[promptFn] = function() {
      if (!gUpdatePromptCallback) {
        return;
      }

      var callback = gUpdatePromptCallback[promptFn];
      if (!callback) {
        return;
      }

      callback.apply(gUpdatePromptCallback,
                     Array.prototype.slice.call(arguments));
    }
  });
}

UpdatePrompt.prototype = {
  flags: AUS_Ci.nsIClassInfo.SINGLETON,
  implementationLanguage: AUS_Ci.nsIProgrammingLanguage.JAVASCRIPT,
  getHelperForLanguage: function(language) null,
  getInterfaces: function(count) {
    var interfaces = [AUS_Ci.nsISupports, AUS_Ci.nsIUpdatePrompt];
    count.value = interfaces.length;
    return interfaces;
  },
  classDescription: "UpdatePrompt",
  contractID: "@mozilla.org/updates/update-prompt;1",
  classID: Components.ID("{8c350a15-9b90-4622-93a1-4d320308664b}"),
  createInstance: function (outer, aIID) {
    if (outer == null)
      return gUpdatePrompt.QueryInterface(aIID);
    throw AUS_Cr.NS_ERROR_NO_AGGREGATION;
  },
  QueryInterface: function(aIID) {
    if (aIID.equals(AUS_Ci.nsIClassInfo) ||
        aIID.equals(AUS_Ci.nsISupports) ||
        aIID.equals(AUS_Ci.nsIUpdatePrompt))
      return gUpdatePrompt;
    throw AUS_Cr.NS_ERROR_NO_INTERFACE;
  },
};



/* Update check listener */
const updateCheckListener = {
  onProgress: function UCL_onProgress(request, position, totalSize) {
  },

  onCheckComplete: function UCL_onCheckComplete(request, updates, updateCount) {
    gRequestURL = request.channel.originalURI.spec;
    gUpdateCount = updateCount;
    gUpdates = updates;
    logTestInfo("url = " + gRequestURL + ", " +
                "request.status = " + request.status + ", " +
                "update.statusText = " + request.statusText + ", " +
                "updateCount = " + updateCount);
    // Use a timeout to allow the XHR to complete
    do_execute_soon(gCheckFunc);
  },

  onError: function UCL_onError(request, update) {
    gRequestURL = request.channel.originalURI.spec;
    gStatusCode = request.status;

    gStatusText = update.statusText;
    logTestInfo("url = " + gRequestURL + ", " +
                "request.status = " + gStatusCode + ", " +
                "update.statusText = " + gStatusText);
    // Use a timeout to allow the XHR to complete
    do_execute_soon(gCheckFunc.bind(null, request, update));
  },

  QueryInterface: function(aIID) {
    if (!aIID.equals(AUS_Ci.nsIUpdateCheckListener) &&
        !aIID.equals(AUS_Ci.nsISupports))
      throw AUS_Cr.NS_ERROR_NO_INTERFACE;
    return this;
  }
};

/**
 * Helper for starting the http server used by the tests
 *
 * @param   aRelativeDirName
 *          The directory name to register relative to
 *          toolkit/mozapps/update/test/unit/
 */
function start_httpserver(aRelativeDirName) {
  var dir = do_get_file(aRelativeDirName);
  if (!dir.exists())
    do_throw("The directory used by HttpServer does not exist! path: " +
             dir.path + "\n");

  if (!dir.isDirectory())
    do_throw("A file instead of a directory was specified for HttpServer " +
             "registerDirectory! path: " + dir.path + "\n");

  Components.utils.import("resource://testing-common/httpd.js");
  gTestserver = new HttpServer();
  gTestserver.registerDirectory("/data/", dir);
  gTestserver.start(4444);
}

/* Helper for stopping the http server used by the tests */
function stop_httpserver(callback) {
  do_check_true(!!callback);
  gTestserver.stop(callback);
}

/**
 * Creates an nsIXULAppInfo
 *
 * @param   id
 *          The ID of the test application
 * @param   name
 *          A name for the test application
 * @param   version
 *          The version of the application
 * @param   platformVersion
 *          The gecko version of the application
 */
function createAppInfo(id, name, version, platformVersion) {
  const XULAPPINFO_CONTRACTID = "@mozilla.org/xre/app-info;1";
  const XULAPPINFO_CID = Components.ID("{c763b610-9d49-455a-bbd2-ede71682a1ac}");
  var XULAppInfo = {
    vendor: "Mozilla",
    name: name,
    ID: id,
    version: version,
    appBuildID: "2007010101",
    platformVersion: platformVersion,
    platformBuildID: "2007010101",
    inSafeMode: false,
    logConsoleErrors: true,
    OS: "XPCShell",
    XPCOMABI: "noarch-spidermonkey",

    QueryInterface: function QueryInterface(iid) {
      if (iid.equals(AUS_Ci.nsIXULAppInfo) ||
          iid.equals(AUS_Ci.nsIXULRuntime) ||
//@line 1872 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/unit/head_update.js.in"
          iid.equals(AUS_Ci.nsISupports))
        return this;
      throw AUS_Cr.NS_ERROR_NO_INTERFACE;
    }
  };
  
  var XULAppInfoFactory = {
    createInstance: function (outer, iid) {
      if (outer == null)
        return XULAppInfo.QueryInterface(iid);
      throw AUS_Cr.NS_ERROR_NO_AGGREGATION;
    }
  };

  var registrar = Components.manager.QueryInterface(AUS_Ci.nsIComponentRegistrar);
  registrar.registerFactory(XULAPPINFO_CID, "XULAppInfo",
                            XULAPPINFO_CONTRACTID, XULAppInfoFactory);
}

/**
 * Returns the platform specific arguments used by nsIProcess when launching
 * the application.
 *
 * @param aExtraArgs optional array of extra arguments
 * @return  an array of arguments to be passed to nsIProcess.
 *
 * Notes:
 * 1. Mozilla universal binaries that contain both i386 and x86_64 on Mac OS X
 *    10.5.x must be launched using the i386 architecture.
 * 2. A shell is necessary to pipe the application's console output which
 *    would otherwise pollute the xpcshell log.
 *
 * Command line arguments used when launching the application:
 * -no-remote prevents shell integration from being affected by an existing
 * application process.
 * -process-updates makes the application exits after being relaunched by the
 * updater.
 * 1> pipes stdout to a file.
 * appConsoleLogPath is the file path to pipe the output from the shell.
 * Otherwise the output from the application will end up in the xpchsell log.
 * 2>&1 pipes stderr to sdout.
 */
function getProcessArgs(aExtraArgs) {
  if (!aExtraArgs) {
    aExtraArgs = [];
  }

  // Pipe the output from the launched application to a file so the output from
  // its console isn't present in the xpcshell log.
  let appConsoleLogPath = getAppConsoleLogPath();

  let args;
  if (IS_UNIX) {
    let launchScript = getLaunchScript();
    // Precreate the script with executable permissions
    launchScript.create(AUS_Ci.nsILocalFile.NORMAL_FILE_TYPE, PERMS_DIRECTORY);

    let scriptContents = "#! /bin/sh\n";
    // On Mac OS X versions prior to 10.6 the i386 acrhitecture must be used.
    if (gIsLessThanMacOSX_10_6) {
      scriptContents += "arch -arch i386 ";
    }
    scriptContents += gAppBinPath + " -no-remote -process-updates " +
                      aExtraArgs.join(" ") + " 1> " +
                      appConsoleLogPath + " 2>&1";
    writeFile(launchScript, scriptContents);
    logTestInfo("created " + launchScript.path + " containing:\n" +
                scriptContents);
    args = [launchScript.path];
  }
  else {
    args = ["/D", "/Q", "/C", gAppBinPath, "-no-remote", "-process-updates"].
           concat(aExtraArgs).
           concat(["1>", appConsoleLogPath, "2>&1"]);
  }
  return args;
}

/**
 * Gets a file path for piping the console output from the application so it
 * doesn't appear in the xpcshell log file.
 *
 * @return  path to the file for piping the console output from the application.
 */
function getAppConsoleLogPath() {
  let appConsoleLog = do_get_file("/", true);
  appConsoleLog.append(TEST_ID + "_app_console_log");
  if (appConsoleLog.exists()) {
    appConsoleLog.remove(false);
  }
  let appConsoleLogPath = appConsoleLog.path;
  if (/ /.test(appConsoleLogPath)) {
    appConsoleLogPath = '"' + appConsoleLogPath + '"';
  }
  return appConsoleLogPath;
}

/**
 * Gets a file path for the application to dump its arguments into.  This is used
 * to verify that a callback application is launched.
 *
 * @return  the file for the application to dump its arguments into.
 */
function getAppArgsLogPath() {
  let appArgsLog = do_get_file("/", true);
  appArgsLog.append("app_args_log");
  if (appArgsLog.exists()) {
    appArgsLog.remove(false);
  }
  let appArgsLogPath = appArgsLog.path;
  if (/ /.test(appArgsLogPath)) {
    appArgsLogPath = '"' + appArgsLogPath + '"';
  }
  return appArgsLogPath;
}

/**
 * Gets the nsIFile reference for the shell script to launch the application. If
 * the file exists it will be removed by this function.
 *
 * @return  the nsIFile for the shell script to launch the application.
 */
function getLaunchScript() {
  let launchScript = do_get_file("/", true);
  launchScript.append("launch.sh");
  if (launchScript.exists()) {
    launchScript.remove(false);
  }
  return launchScript;
}

// A shell script is used to get the OS version due to nsSystemInfo not
// returning the actual OS version. It is possible to get the actual OS version
// using ctypes but it would be more complicated than using a shell script.
XPCOMUtils.defineLazyGetter(this, "gIsLessThanMacOSX_10_6", function test_gMacVer() {
  if (!IS_MACOSX) {
    return false;
  }

  let [versionScript, versionFile] = getVersionScriptAndFile();
  // Precreate the script with executable permissions
  versionScript.create(AUS_Ci.nsILocalFile.NORMAL_FILE_TYPE, PERMS_DIRECTORY);
  let scriptContents = "#! /bin/sh\nsw_vers -productVersion >> " + versionFile.path;
  writeFile(versionScript, scriptContents);
  logTestInfo("created " + versionScript.path + " shell script containing:\n" +
              scriptContents);

  let versionScriptPath = versionScript.path;
  if (/ /.test(versionScriptPath)) {
    versionScriptPath = '"' + versionScriptPath + '"';
  }


  let launchBin = getLaunchBin();
  let args = [versionScriptPath];
  let process = AUS_Cc["@mozilla.org/process/util;1"].
                createInstance(AUS_Ci.nsIProcess);
  process.init(launchBin);
  process.run(true, args, args.length);
  if (process.exitValue != 0) {
    do_throw("Version script exited with " + process.exitValue + "... unable " +
             "to get Mac OS X version!");
  }

  let version = readFile(versionFile).split("\n")[0];
  logTestInfo("executing on Mac OS X verssion " + version);

  return (Services.vc.compare(version, "10.6") < 0)
});

/**
 * Checks for the existence of a platform specific application binary that can
 * be used for the test and gets its path if it is found.
 *
 * Note: The application shell scripts for launching the application work on all
 * platforms that provide a launch shell script except for Mac OS X 10.5 which
 * is why this test uses the binaries to launch the application.
 */
XPCOMUtils.defineLazyGetter(this, "gAppBinPath", function test_gAppBinPath() {
  let processDir = getAppDir();
  let appBin = processDir.clone();
  appBin.append(APP_BIN_NAME + APP_BIN_SUFFIX);
  if (appBin.exists()) {
    if (IS_WIN) {
      let appBinCopy = processDir.clone();
      appBinCopy.append(TEST_ID + FILE_WIN_TEST_EXE);
      if (appBinCopy.exists()) {
        appBinCopy.remove(false);
      }
      appBin.copyTo(processDir, TEST_ID + FILE_WIN_TEST_EXE);
      appBin = processDir.clone();
      appBin.append(TEST_ID + FILE_WIN_TEST_EXE);
    }
    let appBinPath = appBin.path;
    if (/ /.test(appBinPath)) {
      appBinPath = '"' + appBinPath + '"';
    }
    return appBinPath;
  }
  return null;
});

let gWindowsBinDir = null;

/**
 * This dummy function just returns false.  Tests which wish to adjust the app
 * directory on Mac OS X should define a real version of this function.
 */
function shouldAdjustPathsOnMac() {
  return false;
}

/**
 * This function returns the current process directory on Windows and Linux, and
 * the application bundle directory on Mac.
 */
function getAppDir() {
  let dir = getCurrentProcessDir();
  if (shouldAdjustPathsOnMac()) {
    // objdir/dist/bin/../NightlyDebug.app/Contents/MacOS
    dir = dir.parent;
    dir.append(BUNDLE_NAME);
    dir.append("Contents");
    dir.append("MacOS");
  } else if (IS_WIN && gWindowsBinDir) {
    dir = gWindowsBinDir.clone();
  }
  return dir;
}

/**
 * Gets the nsIFile references for the shell script to retrieve the Mac OS X
 * version and the nsIFile to pipe the output of the shell script. If either of
 * these files exist they will be removed by this function.
 *
 * @return  array containing two nsIFile references. The first array member is
 *          the nsIFile for the shell script to launch to get the Mac OS X
 *          version and the second array member is the nsIFile for the piped
 *          output from the shell script.
 */
function getVersionScriptAndFile() {
  let versionScript = do_get_file("/", true);
  let versionFile = versionScript.clone();
  versionScript.append("get_version.sh");
  if (versionScript.exists()) {
    versionScript.remove(false);
  }
  versionFile.append("version.out");
  if (versionFile.exists()) {
    versionFile.remove(false);
  }
  return [versionScript, versionFile];
}

// Environment related globals
let gShouldResetEnv = undefined;
let gAddedEnvXRENoWindowsCrashDialog = false;
let gEnvXPCOMDebugBreak;
let gEnvXPCOMMemLeakLog;
let gEnvDyldLibraryPath;
let gEnvLdLibraryPath;
let gEnvUpdateRootOverride = null;
let gEnvAppDirOverride = null;

/**
 * Sets the environment that will be used by the application process when it is
 * launched.
 */
function setEnvironment() {
  // Prevent setting the environment more than once.
  if (gShouldResetEnv !== undefined)
    return;

  gShouldResetEnv = true;

  let env = AUS_Cc["@mozilla.org/process/environment;1"].
            getService(AUS_Ci.nsIEnvironment);
  if (IS_WIN && !env.exists("XRE_NO_WINDOWS_CRASH_DIALOG")) {
    gAddedEnvXRENoWindowsCrashDialog = true;
    logTestInfo("setting the XRE_NO_WINDOWS_CRASH_DIALOG environment " +
                "variable to 1... previously it didn't exist");
    env.set("XRE_NO_WINDOWS_CRASH_DIALOG", "1");
  }

  if (IS_UNIX) {
    let appGreDir = Services.dirsvc.get("GreD", AUS_Ci.nsIFile);
    let envGreDir = AUS_Cc["@mozilla.org/file/local;1"].
                    createInstance(AUS_Ci.nsILocalFile);
    let shouldSetEnv = true;
    if (IS_MACOSX) {
      if (env.exists("DYLD_LIBRARY_PATH")) {
        gEnvDyldLibraryPath = env.get("DYLD_LIBRARY_PATH");
        envGreDir.initWithPath(gEnvDyldLibraryPath);
        if (envGreDir.path == appGreDir.path) {
          gEnvDyldLibraryPath = null;
          shouldSetEnv = false;
        }
      }

      if (shouldSetEnv) {
        logTestInfo("setting DYLD_LIBRARY_PATH environment variable value to " +
                    appGreDir.path);
        env.set("DYLD_LIBRARY_PATH", appGreDir.path);
      }
    }
    else {
      if (env.exists("LD_LIBRARY_PATH")) {
        gEnvLdLibraryPath = env.get("LD_LIBRARY_PATH");
        envGreDir.initWithPath(gEnvLdLibraryPath);
        if (envGreDir.path == appGreDir.path) {
          gEnvLdLibraryPath = null;
          shouldSetEnv = false;
        }
      }

      if (shouldSetEnv) {
        logTestInfo("setting LD_LIBRARY_PATH environment variable value to " +
                    appGreDir.path);
        env.set("LD_LIBRARY_PATH", appGreDir.path);
      }
    }
  }

  if (env.exists("XPCOM_MEM_LEAK_LOG")) {
    gEnvXPCOMMemLeakLog = env.get("XPCOM_MEM_LEAK_LOG");
    logTestInfo("removing the XPCOM_MEM_LEAK_LOG environment variable... " +
                "previous value " + gEnvXPCOMMemLeakLog);
    env.set("XPCOM_MEM_LEAK_LOG", "");
  }

  if (env.exists("XPCOM_DEBUG_BREAK")) {
    gEnvXPCOMDebugBreak = env.get("XPCOM_DEBUG_BREAK");
    logTestInfo("setting the XPCOM_DEBUG_BREAK environment variable to " +
                "warn... previous value " + gEnvXPCOMDebugBreak);
  }
  else {
    logTestInfo("setting the XPCOM_DEBUG_BREAK environment variable to " +
                "warn... previously it didn't exist");
  }

  env.set("XPCOM_DEBUG_BREAK", "warn");

  if (gEnvUpdateRootOverride) {
    logTestInfo("setting the MOZ_UPDATE_ROOT_OVERRIDE environment variable to " +
                gEnvUpdateRootOverride + "\n");
    env.set("MOZ_UPDATE_ROOT_OVERRIDE", gEnvUpdateRootOverride);
  }

  if (gEnvAppDirOverride) {
    logTestInfo("setting the MOZ_UPDATE_APPDIR_OVERRIDE environment variable to " +
                gEnvAppDirOverride + "\n");
    env.set("MOZ_UPDATE_APPDIR_OVERRIDE", gEnvAppDirOverride);
  }

  if (gBackgroundUpdate) {
    logTestInfo("setting the MOZ_UPDATE_BACKGROUND environment variable to 1\n");
    env.set("MOZ_UPDATE_BACKGROUND", "1");
  }

  logTestInfo("setting MOZ_NO_SERVICE_FALLBACK environment variable to 1");
  env.set("MOZ_NO_SERVICE_FALLBACK", "1");
}

/**
 * Sets the environment back to the original values after launching the
 * application.
 */
function resetEnvironment() {
  // Prevent resetting the environment more than once.
  if (gShouldResetEnv !== true)
    return;

  gShouldResetEnv = false;

  let env = AUS_Cc["@mozilla.org/process/environment;1"].
            getService(AUS_Ci.nsIEnvironment);

  if (gEnvXPCOMMemLeakLog) {
    logTestInfo("setting the XPCOM_MEM_LEAK_LOG environment variable back to " +
                gEnvXPCOMMemLeakLog);
    env.set("XPCOM_MEM_LEAK_LOG", gEnvXPCOMMemLeakLog);
  }

  if (gEnvXPCOMDebugBreak) {
    logTestInfo("setting the XPCOM_DEBUG_BREAK environment variable back to " +
                gEnvXPCOMDebugBreak);
    env.set("XPCOM_DEBUG_BREAK", gEnvXPCOMDebugBreak);
  }
  else {
    logTestInfo("clearing the XPCOM_DEBUG_BREAK environment variable");
    env.set("XPCOM_DEBUG_BREAK", "");
  }

  if (IS_UNIX) {
    if (IS_MACOSX) {
      if (gEnvDyldLibraryPath) {
        logTestInfo("setting DYLD_LIBRARY_PATH environment variable value " +
                    "back to " + gEnvDyldLibraryPath);
        env.set("DYLD_LIBRARY_PATH", gEnvDyldLibraryPath);
      }
      else {
        logTestInfo("removing DYLD_LIBRARY_PATH environment variable");
        env.set("DYLD_LIBRARY_PATH", "");
      }
    }
    else {
      if (gEnvLdLibraryPath) {
        logTestInfo("setting LD_LIBRARY_PATH environment variable value back " +
                    "to " + gEnvLdLibraryPath);
        env.set("LD_LIBRARY_PATH", gEnvLdLibraryPath);
      }
      else {
        logTestInfo("removing LD_LIBRARY_PATH environment variable");
        env.set("LD_LIBRARY_PATH", "");
      }
    }
  }

  if (IS_WIN && gAddedEnvXRENoWindowsCrashDialog) {
    logTestInfo("removing the XRE_NO_WINDOWS_CRASH_DIALOG environment " +
                "variable");
    env.set("XRE_NO_WINDOWS_CRASH_DIALOG", "");
  }

  if (gEnvUpdateRootOverride) {
    logTestInfo("removing the MOZ_UPDATE_ROOT_OVERRIDE environment variable\n");
    env.set("MOZ_UPDATE_ROOT_OVERRIDE", "");
    gEnvUpdateRootOverride = null;
  }

  if (gEnvAppDirOverride) {
    logTestInfo("removing the MOZ_UPDATE_APPDIR_OVERRIDE environment variable\n");
    env.set("MOZ_UPDATE_APPDIR_OVERRIDE", "");
    gEnvAppDirOverride = null;
  }

  if (gBackgroundUpdate) {
    logTestInfo("removing the MOZ_UPDATE_BACKGROUND environment variable\n");
    env.set("MOZ_UPDATE_BACKGROUND", "");
  }

  logTestInfo("removing MOZ_NO_SERVICE_FALLBACK environment variable");
  env.set("MOZ_NO_SERVICE_FALLBACK", "");
}
