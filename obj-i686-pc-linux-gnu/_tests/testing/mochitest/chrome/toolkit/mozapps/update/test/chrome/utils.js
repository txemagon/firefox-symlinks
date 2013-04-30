/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 */

/**
 * Test Definition
 *
 * Most tests can use an array named TESTS that will perform most if not all of
 * the necessary checks. Each element in the array must be an object with the
 * following possible properties. Additional properties besides the ones listed
 * below can be added as needed.
 *
 * overrideCallback (optional)
 *   The function to call for the next test. This is typically called when the
 *   wizard page changes but can also be called for other events by the previous
 *   test. If this property isn't defined then the defailtCallback function will
 *   be called. If this property is defined then all other properties are
 *   optional.
 *
 * pageid (required unless overrideCallback is specified)
 *   The expected pageid for the wizard. This property is required unless the
 *   overrideCallback property is defined.
 *
 * extraStartFunction (optional)
 *   The function to call at the beginning of the defaultCallback function. If
 *   the function returns true the defaultCallback function will return early
 *   which allows waiting for a specific condition to be evaluated in the
 *   function specified in the extraStartFunction property before continuing
 *   with the test.
 *
 * extraCheckFunction (optional)
 *   The function to call to perform extra checks in the defaultCallback
 *   function.
 *
 * extraDelayedCheckFunction (optional)
 *   The function to call to perform extra checks in the delayedDefaultCallback
 *   function.
 *
 * buttonStates (optional)
 *   A javascript object representing the expected hidden and disabled attribute
 *   values for the buttons of the current wizard page. The values are checked
 *   in the delayedDefaultCallback function. For information about the structure
 *   of this object refer to the getExpectedButtonStates and checkButtonStates
 *   functions.
 *
 * buttonClick (optional)
 *   The current wizard page button to click at the end of the
 *   delayedDefaultCallback function. If the buttonClick property is defined
 *   then the extraDelayedFinishFunction property can't be specified due to race
 *   conditions in some of the tests and if both of them are specified the test
 *   will intentionally throw.
 *
 * extraDelayedFinishFunction (optional)
 *   The function to call at the end of the delayedDefaultCallback function.
 *
 * ranTest (should not be specified)
 *   When delayedDefaultCallback is called a property named ranTest is added to
 *   the current test it is possible to verify that each test in the TESTS
 *   array has ran.
 *
 * prefHasUserValue (optional)
 *   For comparing the expected value defined by this property with the return
 *   value of prefHasUserValue using gPrefToCheck for the preference name in the
 *   checkPrefHasUserValue function.
 *
 * expectedRadioGroupSelectedIndex (optional)
 *   For comparing the expected selectedIndex attribute value of the wizard's
 *   license page radiogroup selectedIndex attribute in the
 *   checkRadioGroupSelectedIndex function.
 *
 * expectedRemoteContentState (optional)
 *   For comparing the expected remotecontent state attribute value of the
 *   wizard's billboard and license pages in the checkRemoteContentState and
 *   waitForRemoteContentLoaded functions.
 *
 *
 * Test Add-ons
 *
 * All tests include the test add-ons specified in the TEST_ADDONS array and
 * the only thing that can be configured is whether the noupdate test add-on is
 * disabled (see below). The add-on names are in the format of typename_X where
 * X is a number to make the add-on ID unique and typename is one of the values
 * specified below:
 *
 * appdisabled
 *   disabled by the application due to being incompatible with the current
 *   toolkit version.
 *
 * compatible
 *   compatible with the current toolkit version and the update's toolkit
 *   version.
 *
 * noupdate
 *   the add-on is compatible with the current toolkit version and does not have
 *   an update to make it compatible with the update's toolkit version. Tests
 *   that need to have all add-ons compatible for the application update can
 *   disable this add-on by setting the gDisableNoUpdateAddon variable to true.
 *
 * updatecompatibility
 *   the add-on is compatible with the current toolkit version and has a
 *   compatibility update to make it compatible with the update's toolkit
 *   version.
 *
 * updateversion
 *   the add-on is compatible with the current toolkit version and has a version
 *   update to make it compatible with the update's toolkit version.
 *
 * userdisabled
 *   disabled by the user and compatible with the current toolkit version but
 *   not the update's toolkit version. This add-on will be disabled after its
 *   install completes.
 */

Components.utils.import("resource://gre/modules/AddonManager.jsm");

// The tests have to use the pageid instead of the pageIndex due to the
// app update wizard's access method being random.
const PAGEID_DUMMY            = "dummy";                 // Done
const PAGEID_CHECKING         = "checking";              // Done
const PAGEID_PLUGIN_UPDATES   = "pluginupdatesfound";
const PAGEID_NO_UPDATES_FOUND = "noupdatesfound";        // Done
const PAGEID_MANUAL_UPDATE    = "manualUpdate"; // Tested on license load failure
const PAGEID_INCOMPAT_CHECK   = "incompatibleCheck";     // Done
const PAGEID_FOUND_BASIC      = "updatesfoundbasic";     // Done
const PAGEID_FOUND_BILLBOARD  = "updatesfoundbillboard"; // Done
const PAGEID_LICENSE          = "license";               // Done
const PAGEID_INCOMPAT_LIST    = "incompatibleList";      // Done
const PAGEID_DOWNLOADING      = "downloading";           // Done
const PAGEID_ERRORS           = "errors";                // Done
const PAGEID_ERROR_EXTRA      = "errorextra";            // Done
const PAGEID_ERROR_PATCHING   = "errorpatching";         // Done
const PAGEID_FINISHED         = "finished";              // Done
const PAGEID_FINISHED_BKGRD   = "finishedBackground";    // Done
const PAGEID_INSTALLED        = "installed";             // Done

const UPDATE_WINDOW_NAME = "Update:Wizard";

const URL_HOST   = "http://example.com/";
const URL_PATH   = "chrome/toolkit/mozapps/update/test/chrome";
const URL_UPDATE = URL_HOST + URL_PATH + "/update.sjs";

const URI_UPDATE_PROMPT_DIALOG  = "chrome://mozapps/content/update/updates.xul";

const ADDON_ID_SUFFIX = "@appupdatetest.mozilla.org";
const ADDON_PREP_DIR = "appupdateprep";
// Preference for storing add-ons that are disabled by the tests to prevent them
// from interefering with the tests.
const PREF_DISABLEDADDONS = "app.update.test.disabledAddons";
const PREF_EM_HOTFIX_ID = "extensions.hotfix.id";
const TEST_ADDONS = [ "appdisabled_1", "appdisabled_2",
                      "compatible_1", "compatible_2",
                      "noupdate_1", "noupdate_2",
                      "updatecompatibility_1", "updatecompatibility_2",
                      "updateversion_1", "updateversion_2",
                      "userdisabled_1", "userdisabled_2", "hotfix" ];


const TEST_TIMEOUT = 25000; // 25 seconds
var gTimeoutTimer;

// The number of SimpleTest.executeSoon calls to perform when waiting on an
// update window to close before giving up.
const CLOSE_WINDOW_TIMEOUT_MAXCOUNT = 10;
// Counter for the SimpleTest.executeSoon when waiting on an update window to
// close before giving up.
var gCloseWindowTimeoutCounter = 0;

// The following vars are for restoring previous preference values (if present)
// when the test finishes.
var gAppUpdateEnabled;    // app.update.enabled
var gAppUpdateURLDefault; // app.update.url (default prefbranch)
var gAppUpdateURL;        // app.update.url.override
var gExtUpdateURL;        // extensions.update.url

var gTestCounter = -1;
var gWin;
var gDocElem;
var gPrefToCheck;
var gDisableNoUpdateAddon = false;

// Set to true to log additional information for debugging. To log additional
// information for an individual test set DEBUG_AUS_TEST to true in the test's
// onload function.
var DEBUG_AUS_TEST = false;

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
//@line 187 "/home/txema/work/firefox-20.0+build1/toolkit/mozapps/update/test/chrome/utils.js"

/**
 * The current test in TESTS array.
 */
__defineGetter__("gTest", function() {
  return TESTS[gTestCounter];
});

/**
 * The current test's callback. This will either return the callback defined in
 * the test's overrideCallback property or defaultCallback if the
 * overrideCallback property is undefined.
 */
__defineGetter__("gCallback", function() {
  return gTest.overrideCallback ? gTest.overrideCallback
                                : defaultCallback;
});

/**
 * The remotecontent element for the current page if one exists or null if a
 * remotecontent element doesn't exist.
 */
__defineGetter__("gRemoteContent", function() {
  switch (gTest.pageid) {
    case PAGEID_FOUND_BILLBOARD:
      return gWin.document.getElementById("updateMoreInfoContent");
    case PAGEID_LICENSE:
      return gWin.document.getElementById("licenseContent");
  }
  return null;
});

/**
 * The state for the remotecontent element if one exists or null if a
 * remotecontent element doesn't exist.
 */
__defineGetter__("gRemoteContentState", function() {
  if (gRemoteContent) {
    return gRemoteContent.getAttribute("state");
  }
  return null;
});

/**
 * The radiogroup for the license page.
 */
__defineGetter__("gAcceptDeclineLicense", function() {
  return gWin.document.getElementById("acceptDeclineLicense");
});

/**
 * The listbox for the incompatibleList page.
 */
__defineGetter__("gIncompatibleListbox", function() {
  return gWin.document.getElementById("incompatibleListbox");
});

/**
 * Default test run function that can be used by most tests. This function uses
 * protective measures to prevent the test from failing provided by
 * |runTestDefaultWaitForWindowClosed| helper functions to prevent failure due
 * to a previous test failure.
 */
function runTestDefault() {
  debugDump("entering");

  if (!("@mozilla.org/zipwriter;1" in AUS_Cc)) {
    ok(false, "nsIZipWriter is required to run these tests");
    return;
  }

  SimpleTest.waitForExplicitFinish();

  runTestDefaultWaitForWindowClosed();
}

/**
 * If an update window is found SimpleTest.executeSoon can callback before the
 * update window is fully closed especially with debug builds. If an update
 * window is found this function will call itself using SimpleTest.executeSoon
 * up to the amount declared in CLOSE_WINDOW_TIMEOUT_MAXCOUNT until the update
 * window has closed before continuing the test.
 */
function runTestDefaultWaitForWindowClosed() {
  gCloseWindowTimeoutCounter++;
  if (gCloseWindowTimeoutCounter > CLOSE_WINDOW_TIMEOUT_MAXCOUNT) {
    try {
      finishTest();
    }
    catch (e) {
      finishTestDefault();
    }
    return;
  }

  // The update window should not be open at this time. If it is the call to
  // |closeUpdateWindow| will close it and cause the test to fail.
  if (closeUpdateWindow()) {
    SimpleTest.executeSoon(runTestDefaultWaitForWindowClosed);
  }
  else {
    Services.ww.registerNotification(gWindowObserver);

    gCloseWindowTimeoutCounter = 0;

    setupPrefs();
    removeUpdateDirsAndFiles();
    reloadUpdateManagerData();
    setupAddons(runTest);
  }
}

/**
 * Default test finish function that can be used by most tests. This function
 * uses protective measures to prevent the next test from failing provided by
 * |finishTestDefaultWaitForWindowClosed| helper functions to prevent failure
 * due to an update window being left open.
 */
function finishTestDefault() {
  debugDump("entering");
  if (gTimeoutTimer) {
    gTimeoutTimer.cancel();
    gTimeoutTimer = null;
  }

  if (gChannel) {
    debugDump("channel = " + gChannel);
    gChannel = null;
    gPrefRoot.removeObserver(PREF_APP_UPDATE_CHANNEL, observer);
  }

  verifyTestsRan();

  resetPrefs();
  removeUpdateDirsAndFiles();
  reloadUpdateManagerData();

  Services.ww.unregisterNotification(gWindowObserver);
  if (gDocElem) {
    gDocElem.removeEventListener("pageshow", onPageShowDefault, false);
  }

  finishTestDefaultWaitForWindowClosed();
}

/**
 * nsITimerCallback for the timeout timer to cleanly finish a test if the Update
 * Window doesn't close for a test. This allows the next test to run properly if
 * a previous test fails.
 *
 * @param  aTimer
 *         The nsITimer that fired.
 */
function finishTestTimeout(aTimer) {
  ok(false, "Test timed out. Maximum time allowed is " + (TEST_TIMEOUT / 1000) +
     " seconds");

  try {
    finishTest();
  }
  catch (e) {
    finishTestDefault();
  }
}

/**
 * If an update window is found SimpleTest.executeSoon can callback before the
 * update window is fully closed especially with debug builds. If an update
 * window is found this function will call itself using SimpleTest.executeSoon
 * up to the amount declared in CLOSE_WINDOW_TIMEOUT_MAXCOUNT until the update
 * window has closed before finishing the test.
 */
function finishTestDefaultWaitForWindowClosed() {
  gCloseWindowTimeoutCounter++;
  if (gCloseWindowTimeoutCounter > CLOSE_WINDOW_TIMEOUT_MAXCOUNT) {
    SimpleTest.finish();
    return;
  }

  // The update window should not be open at this time. If it is the call to
  // |closeUpdateWindow| will close it and cause the test to fail.
  if (closeUpdateWindow()) {
    SimpleTest.executeSoon(finishTestDefaultWaitForWindowClosed);
  }
  else {
    SimpleTest.finish();
  }
}

/**
 * Default callback for the wizard's documentElement pageshow listener. This
 * will return early for event's where the originalTarget's nodeName is not
 * wizardpage.
 */
function onPageShowDefault(aEvent) {
  if (!gTimeoutTimer) {
    debugDump("gTimeoutTimer is null... returning early");
    return;
  }

  // Return early if the event's original target isn't for a wizardpage element.
  // This check is necessary due to the remotecontent element firing pageshow.
  if (aEvent.originalTarget.nodeName != "wizardpage") {
    debugDump("only handles events with an originalTarget nodeName of " +
              "|wizardpage|. aEvent.originalTarget.nodeName = " +
              aEvent.originalTarget.nodeName + "... returning early");
    return;
  }

  gTestCounter++;
  gCallback(aEvent);
}

/**
 * Default callback that can be used by most tests.
 */
function defaultCallback(aEvent) {
  if (!gTimeoutTimer) {
    debugDump("gTimeoutTimer is null... returning early");
    return;
  }

  debugDump("entering - TESTS[" + gTestCounter + "], pageid: " + gTest.pageid +
            ", aEvent.originalTarget.nodeName: " +
            aEvent.originalTarget.nodeName);

  if (gTest && gTest.extraStartFunction) {
    debugDump("calling extraStartFunction " + gTest.extraStartFunction.name);
    if (gTest.extraStartFunction(aEvent)) {
      debugDump("extraStartFunction early return");
      return;
    }
  }

  is(gDocElem.currentPage.pageid, gTest.pageid,
     "Checking currentPage.pageid equals " + gTest.pageid + " in pageshow");

  // Perform extra checks if specified by the test
  if (gTest.extraCheckFunction) {
    debugDump("calling extraCheckFunction " + gTest.extraCheckFunction.name);
    gTest.extraCheckFunction();
  }

  // The wizard page buttons' disabled and hidden attributes are set after the
  // pageshow event so use executeSoon to allow them to be set so their disabled
  // and hidden attribute values can be checked.
  SimpleTest.executeSoon(delayedDefaultCallback);
}

/**
 * Delayed default callback called using executeSoon in defaultCallback which
 * allows the wizard page buttons' disabled and hidden attributes to be set
 * before checking their values.
 */
function delayedDefaultCallback() {
  if (!gTimeoutTimer) {
    debugDump("gTimeoutTimer is null... returning early");
    return;
  }

  debugDump("entering - TESTS[" + gTestCounter + "], pageid: " + gTest.pageid);

  // Verify the pageid hasn't changed after executeSoon was called.
  is(gDocElem.currentPage.pageid, gTest.pageid,
     "Checking currentPage.pageid equals " + gTest.pageid + " after " +
     "executeSoon");

  checkButtonStates();

  // Perform delayed extra checks if specified by the test
  if (gTest.extraDelayedCheckFunction) {
    debugDump("calling extraDelayedCheckFunction " +
              gTest.extraDelayedCheckFunction.name);
    gTest.extraDelayedCheckFunction();
  }

  // Used to verify that this test has been performed
  gTest.ranTest = true;

  if (gTest.buttonClick) {
    debugDump("clicking " + gTest.buttonClick + " button");
    if(gTest.extraDelayedFinishFunction) {
      throw("Tests cannot have a buttonClick and an extraDelayedFinishFunction property");
    }
    gDocElem.getButton(gTest.buttonClick).click();
  }
  else if (gTest.extraDelayedFinishFunction) {
    debugDump("calling extraDelayedFinishFunction " +
              gTest.extraDelayedFinishFunction.name);
    gTest.extraDelayedFinishFunction();
  }
}

/**
 * Checks the wizard page buttons' disabled and hidden attributes values are
 * correct. If an expected button id is not specified then the expected disabled
 * and hidden attribute value is true.
 */
function checkButtonStates() {
  debugDump("entering - TESTS[" + gTestCounter + "], pageid: " + gTest.pageid);

  const buttonNames = ["extra1", "extra2", "back", "next", "finish", "cancel"];
  let buttonStates = getExpectedButtonStates();
  buttonNames.forEach(function(aButtonName) {
    let button = gDocElem.getButton(aButtonName);
    let hasHidden = aButtonName in buttonStates &&
                    "hidden" in buttonStates[aButtonName];
    let hidden = hasHidden ? buttonStates[aButtonName].hidden : true;
    let hasDisabled = aButtonName in buttonStates &&
                      "disabled" in buttonStates[aButtonName];
    let disabled = hasDisabled ? buttonStates[aButtonName].disabled : true;
    is(button.hidden, hidden, "Checking " + aButtonName + " button " +
       "hidden attribute value equals " + (hidden ? "true" : "false"));
    is(button.disabled, disabled, "Checking " + aButtonName + " button " +
       "disabled attribute value equals " + (disabled ? "true" : "false"));
  });
}

/**
 * Returns the expected disabled and hidden attribute values for the buttons of
 * the current wizard page.
 */
function getExpectedButtonStates() {
  // Allow individual tests to override the expected button states.
  if (gTest.buttonStates) {
    return gTest.buttonStates;
  }

  switch (gTest.pageid) {
    case PAGEID_CHECKING:
    case PAGEID_INCOMPAT_CHECK:
      return { cancel: { disabled: false, hidden: false } };
    case PAGEID_FOUND_BASIC:
    case PAGEID_FOUND_BILLBOARD:
      if (gTest.neverButton) {
        return { extra1: { disabled: false, hidden: false },
                 extra2: { disabled: false, hidden: false },
                 next  : { disabled: false, hidden: false } }
      }
      return { extra1: { disabled: false, hidden: false },
               next  : { disabled: false, hidden: false } };
    case PAGEID_LICENSE:
      if (gRemoteContentState != "loaded" ||
          gAcceptDeclineLicense.selectedIndex != 0) {
        return { extra1: { disabled: false, hidden: false },
                 next  : { disabled: true, hidden: false } };
      }
      return { extra1: { disabled: false, hidden: false },
               next  : { disabled: false, hidden: false } };
    case PAGEID_INCOMPAT_LIST:
      return { extra1: { disabled: false, hidden: false },
               next  : { disabled: false, hidden: false } };
    case PAGEID_DOWNLOADING:
      return { extra1: { disabled: false, hidden: false } };
    case PAGEID_NO_UPDATES_FOUND:
    case PAGEID_MANUAL_UPDATE:
    case PAGEID_ERRORS:
    case PAGEID_ERROR_EXTRA:
    case PAGEID_INSTALLED:
      return { finish: { disabled: false, hidden: false } };
    case PAGEID_ERROR_PATCHING:
      return { next  : { disabled: false, hidden: false } };
    case PAGEID_FINISHED:
    case PAGEID_FINISHED_BKGRD:
      return { extra1: { disabled: false, hidden: false },
               finish: { disabled: false, hidden: false } };
  }
  return null;
}

/**
 * Adds a load event listener to the current remotecontent element.
 */
function addRemoteContentLoadListener() {
  debugDump("entering - TESTS[" + gTestCounter + "], pageid: " + gTest.pageid);

  gRemoteContent.addEventListener("load", remoteContentLoadListener, false);
}

/**
 * The nsIDOMEventListener for a remotecontent load event.
 */
function remoteContentLoadListener(aEvent) {
  // Return early if the event's original target's nodeName isn't remotecontent.
  if (aEvent.originalTarget.nodeName != "remotecontent") {
    debugDump("only handles events with an originalTarget nodeName of " +
              "|remotecontent|. aEvent.originalTarget.nodeName = " +
              aEvent.originalTarget.nodeName);
    return;
  }

  gTestCounter++;
  gCallback(aEvent);
}

/**
 * Waits until a remotecontent element to finish loading which is determined
 * by the current test's expectedRemoteContentState property and then removes
 * the event listener.
 *
 * Note: tests that use this function should not test the state of the
 *      remotecontent since this will check the expected state.
 *
 * @return false if the remotecontent has loaded and its state is the state
 *         specified in the current test's expectedRemoteContentState
 *         property... otherwise true.
 */
function waitForRemoteContentLoaded(aEvent) {
  // Return early until the remotecontent has loaded with the state that is
  // expected or isn't the event's originalTarget.
  if (gRemoteContentState != gTest.expectedRemoteContentState ||
      aEvent.originalTarget != gRemoteContent) {
    debugDump("returning early\n" +
              "gRemoteContentState: " + gRemoteContentState + "\n" +
              "expectedRemoteContentState: " +
              gTest.expectedRemoteContentState + "\n" +
              "aEvent.originalTarget.nodeName: " +
              aEvent.originalTarget.nodeName);
    return true;
  }

  gRemoteContent.removeEventListener("load", remoteContentLoadListener, false);
  return false;
}

/**
 * Compares the value of the remotecontent state attribute with the value
 * specified in the test's expectedRemoteContentState property.
 */
function checkRemoteContentState() {
  is(gRemoteContentState, gTest.expectedRemoteContentState, "Checking remote " +
     "content state equals " + gTest.expectedRemoteContentState + " - pageid " +
     gTest.pageid);
}

/**
 * Adds a select event listener to the license radiogroup element and clicks
 * the radio element specified in the current test's radioClick property.
 */
function addRadioGroupSelectListenerAndClick() {
  debugDump("entering - TESTS[" + gTestCounter + "], pageid: " + gTest.pageid);

  gAcceptDeclineLicense.addEventListener("select", radioGroupSelectListener,
                                         false);
  gWin.document.getElementById(gTest.radioClick).click();
}

/**
 * The nsIDOMEventListener for the license radiogroup select event.
 */
function radioGroupSelectListener(aEvent) {
  // Return early if the event's original target's nodeName isn't radiogroup.
  if (aEvent.originalTarget.nodeName != "radiogroup") {
    debugDump("only handles events with an originalTarget nodeName of " +
              "|radiogroup|. aEvent.originalTarget.nodeName = " +
              aEvent.originalTarget.nodeName);
    return;
  }

  gAcceptDeclineLicense.removeEventListener("select", radioGroupSelectListener,
                                            false);
  gTestCounter++;
  gCallback(aEvent);
}

/**
 * Compares the value of the License radiogroup's selectedIndex attribute with
 * the value specified in the test's expectedRadioGroupSelectedIndex property.
 */
function checkRadioGroupSelectedIndex() {
  is(gAcceptDeclineLicense.selectedIndex, gTest.expectedRadioGroupSelectedIndex,
     "Checking license radiogroup selectedIndex equals " +
     gTest.expectedRadioGroupSelectedIndex);
}

/**
 * Checks that only incompatible add-ons (e.g. noupdate_X add-ons) that don't
 * have an update are listed in the add-ons incompatible list.
 */
function checkIncompatbleList() {
  for (let i = 0; i < gIncompatibleListbox.itemCount; i++) {
    let label = gIncompatibleListbox.getItemAtIndex(i).label;
    // Use indexOf since locales can change the text displayed
    ok(label.indexOf("noupdate") != -1, "Checking that only incompatible " + 
       "add-ons that don't have an update are listed in the incompatible list");
  }
}

/**
 * Compares the return value of prefHasUserValue for the preference specified in
 * gPrefToCheck with the value passed in the aPrefHasValue parameter or the
 * value specified in the current test's prefHasUserValue property if
 * aPrefHasValue is undefined.
 *
 * @param  aPrefHasValue (optional)
 *         The expected value returned from prefHasUserValue for the preference
 *         specified in gPrefToCheck. If aPrefHasValue is undefined the value
 *         of the current test's prefHasUserValue property will be used.
 */
function checkPrefHasUserValue(aPrefHasValue) {
  let prefHasUserValue = aPrefHasValue === undefined ? gTest.prefHasUserValue
                                                     : aPrefHasValue;
  is(Services.prefs.prefHasUserValue(gPrefToCheck), prefHasUserValue,
     "Checking prefHasUserValue for preference " + gPrefToCheck + " equals " +
     (prefHasUserValue ? "true" : "false"));
}

/**
 * Checks whether the link is hidden (general background update check error or
 * a certificate attribute check error with an update) or not (certificate
 * attribute check error without an update) on the errorextra page and that the
 * app.update.cert.errors and app.update.backgroundErrors preferences do not
 & have a user value.
 *
 * @param  aShouldBeHidden (optional)
 *         The expected value for the label's hidden attribute for the link. If
 *         aShouldBeHidden is undefined the value of the current test's
 *         shouldBeHidden property will be used.
 */
function checkErrorExtraPage(aShouldBeHidden) {
  let shouldBeHidden = aShouldBeHidden === undefined ? gTest.shouldBeHidden
                                                     : aShouldBeHidden;
  is(gWin.document.getElementById("errorExtraLinkLabel").hidden, shouldBeHidden,
     "Checking errorExtraLinkLabel hidden attribute equals " +
     (shouldBeHidden ? "true" : "false"));

  is(gWin.document.getElementById(gTest.displayedTextElem).hidden, false,
     "Checking " + gTest.displayedTextElem + " should not be hidden");

  ok(!Services.prefs.prefHasUserValue(PREF_APP_UPDATE_CERT_ERRORS),
     "Preference " + PREF_APP_UPDATE_CERT_ERRORS + " should not have a " +
     "user value");

  ok(!Services.prefs.prefHasUserValue(PREF_APP_UPDATE_BACKGROUNDERRORS),
     "Preference " + PREF_APP_UPDATE_BACKGROUNDERRORS + " should not have a " +
     "user value");
}

/**
 * Gets the update version info for the update url parameters to send to
 * update.sjs.
 *
 * @param  aAppVersion (optional)
 *         The application version for the update snippet. If not specified the
 *         current application version will be used.
 * @param  aPlatformVersion (optional)
 *         The platform version for the update snippet. If not specified the
 *         current platform version will be used.
 * @return The url parameters for the application and platform version to send
 *         to update.sjs.
 */
function getVersionParams(aAppVersion, aPlatformVersion) {
  let appInfo = Services.appinfo;
  return "&appVersion=" + (aAppVersion ? aAppVersion : appInfo.version) +
         "&platformVersion=" + (aPlatformVersion ? aPlatformVersion
                                                 : appInfo.platformVersion);
}

/**
 * Gets an application version that is greater than the current application
 * version. The version is created by taking the first sequence from the current
 * application version and adding 1 to it.
 *
 * @return A version string greater than the current application version string.
 */
function getNewerAppVersion() {
  let appVersion = Services.appinfo.version.split(".")[0];
  appVersion++;
  return appVersion;
}

/**
 * Gets a platform version that is greater than the current platform version.
 * The version is created by taking the first sequence from the current platform
 * version and adding 1 to it.
 *
 * @return A version string greater than the current platform version string.
 */
function getNewerPlatformVersion() {
  let platformVersion = Services.appinfo.platformVersion.split(".")[0];
  platformVersion++;
  return platformVersion;
}

/**
 * Verifies that all tests ran.
 */
function verifyTestsRan() {
  debugDump("entering");

  // Return early if there are no tests defined.
  if (!TESTS) {
    return;
  }

  gTestCounter = -1;
  for (let i = 0; i < TESTS.length; ++i) {
    gTestCounter++;
    let test = TESTS[i];
    let msg = "Checking if TESTS[" + i + "] test was performed... " +
              "callback function name = " + gCallback.name + ", " +
              "pageid = " + test.pageid;
    ok(test.ranTest, msg);
  }
}

/**
 * Sets the most common preferences used by tests to values used by the tests
 * and saves some of the preference's original values if present so they can be
 * set back to the original values when each test has finished.
 */
function setupPrefs() {
  if (DEBUG_AUS_TEST) {
    Services.prefs.setBoolPref(PREF_APP_UPDATE_LOG, true)
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_URL_OVERRIDE)) {
    gAppUpdateURL = Services.prefs.getCharPref(PREF_APP_UPDATE_URL_OVERRIDE);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_ENABLED)) {
    gAppUpdateEnabled = Services.prefs.getBoolPref(PREF_APP_UPDATE_ENABLED);
  }
  Services.prefs.setBoolPref(PREF_APP_UPDATE_ENABLED, true)

  if (Services.prefs.prefHasUserValue(PREF_EXTENSIONS_UPDATE_URL)) {
    gExtUpdateURL = Services.prefs.getCharPref(PREF_EXTENSIONS_UPDATE_URL);
  }
  let extUpdateUrl = URL_UPDATE + "?addonID=%ITEM_ID%&platformVersion=" +
                     getNewerPlatformVersion();
  Services.prefs.setCharPref(PREF_EXTENSIONS_UPDATE_URL, extUpdateUrl);
  debugDump("extensions.update.url: " + extUpdateUrl);

  Services.prefs.setIntPref(PREF_APP_UPDATE_IDLETIME, 0);
  Services.prefs.setIntPref(PREF_APP_UPDATE_PROMPTWAITTIME, 0);
  Services.prefs.setBoolPref(PREF_EXTENSIONS_STRICT_COMPAT, true);
  Services.prefs.setCharPref(PREF_EM_HOTFIX_ID, "hotfix" + ADDON_ID_SUFFIX);
}

/**
 * Resets the most common preferences used by tests to their original values.
 */
function resetPrefs() {
  if (gAppUpdateURL !== undefined) {
    Services.prefs.setCharPref(PREF_APP_UPDATE_URL_OVERRIDE, gAppUpdateURL);
  }
  else if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_URL_OVERRIDE)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_URL_OVERRIDE);
  }

  if (gAppUpdateURLDefault) {
    gDefaultPrefBranch.setCharPref(PREF_APP_UPDATE_URL, gAppUpdateURLDefault);
  }

  if (gAppUpdateEnabled !== undefined) {
    Services.prefs.setBoolPref(PREF_APP_UPDATE_ENABLED, gAppUpdateEnabled);
  }
  else if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_ENABLED)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_ENABLED);
  }

  if (gExtUpdateURL !== undefined) {
    Services.prefs.setCharPref(PREF_EXTENSIONS_UPDATE_URL, gExtUpdateURL);
  }
  else if (Services.prefs.prefHasUserValue(PREF_EXTENSIONS_UPDATE_URL)) {
    Services.prefs.clearUserPref(PREF_EXTENSIONS_UPDATE_URL);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_IDLETIME)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_IDLETIME);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_PROMPTWAITTIME)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_PROMPTWAITTIME);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_URL_DETAILS)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_URL_DETAILS);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_SHOW_INSTALLED_UI)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_SHOW_INSTALLED_UI);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_LOG)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_LOG);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_CERT_ERRORS)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_CERT_ERRORS);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_CERT_MAXERRORS)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_CERT_MAXERRORS);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_BACKGROUNDERRORS)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_BACKGROUNDERRORS);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_BACKGROUNDMAXERRORS)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_BACKGROUNDMAXERRORS);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_CERT_INVALID_ATTR_NAME)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_CERT_INVALID_ATTR_NAME);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_CERT_REQUIREBUILTIN)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_CERT_REQUIREBUILTIN);
  }

  if (Services.prefs.prefHasUserValue(PREF_APP_UPDATE_CERT_CHECKATTRS)) {
    Services.prefs.clearUserPref(PREF_APP_UPDATE_CERT_CHECKATTRS);
  }

  try {
    CERT_ATTRS.forEach(function(aCertAttrName) {
      Services.prefs.clearUserPref(PREF_APP_UPDATE_CERTS_BRANCH + "1." +
                                   aCertAttrName);
    });
  }
  catch (e) {
  }

  try {
    Services.prefs.deleteBranch(PREF_APP_UPDATE_NEVER_BRANCH);
  }
  catch(e) {
  }

  if (Services.prefs.prefHasUserValue(PREF_EXTENSIONS_STRICT_COMPAT)) {
		Services.prefs.clearUserPref(PREF_EXTENSIONS_STRICT_COMPAT);
  }

  if (Services.prefs.prefHasUserValue(PREF_EM_HOTFIX_ID)) {
    Services.prefs.clearUserPref(PREF_EM_HOTFIX_ID);
  }
}

/**
 * Disables pre-existing add-ons so they don't interfere with the tests,
 * installs the test add-ons, sets the noupdate test add-ons' userDisabled value
 * for the test, and calls the callback specified in the aCallback parameter. If
 * the app.update.test.disabledAddons has a user value then setting the noupdate
 * test add-ons' userDisabled value for the test is the only thing that is done.
 *
 * @param  aCallback
 *         A callback to call after all operations have completed.
 */
function setupAddons(aCallback) {
  debugDump("entering");

  // Sets the appropriate userDisabled value for the noupdate test add-ons based
  // on the value of gDisableNoUpdateAddon and calls the callback specified in
  // setupAddons aCallback parameter.
  function setNoUpdateAddonsDisabledState() {
    AddonManager.getAllAddons(function(aAddons) {
      aAddons.forEach(function(aAddon) {
        if (aAddon.name.indexOf("noupdate") != 0)
          return;

        if (gDisableNoUpdateAddon) {
          if (!aAddon.userDisabled) {
            aAddon.userDisabled = true;
          }
        }
        else {
          if (aAddon.userDisabled) {
            aAddon.userDisabled = false;
          }
        }
      });
      // Start the timout timer before the update window is displayed so it can
      // clean up tests that don't successfully display the update window.
      gTimeoutTimer = AUS_Cc["@mozilla.org/timer;1"].
                      createInstance(AUS_Ci.nsITimer);
      gTimeoutTimer.initWithCallback(finishTestTimeout, TEST_TIMEOUT,
                                     AUS_Ci.nsITimer.TYPE_ONE_SHOT);
      aCallback();
    });
  }

  // If the app.update.test.disabledAddons preference exists the pre-existing
  // add-ons have already been disabled so they don't interfere with the tests,
  // the test add-ons have already been installed, and the only thing that needs
  // to be done is setting the appropriate userDisabled value for the noupdate
  // test add-ons.
  if (Services.prefs.prefHasUserValue(PREF_DISABLEDADDONS)) {
    setNoUpdateAddonsDisabledState();
    return;
  }

  // Disable all pre-existing enabled addons so they don't interfere with the
  // tests.
  AddonManager.getAllAddons(function(aAddons) {
    let disabledAddons = [];
    aAddons.forEach(function(aAddon) {
      // If an addon's type equals plugin it is skipped since
      // checking plugins compatibility information isn't supported at this
      // time (also see bug 566787). Also, SCOPE_APPLICATION add-ons are
      // excluded by app update so there is no reason to disable them.
      if (aAddon.type != "plugin" && !aAddon.appDisabled &&
          !aAddon.userDisabled &&
          aAddon.scope != AddonManager.SCOPE_APPLICATION) {
        disabledAddons.push(aAddon);
        aAddon.userDisabled = true;
      }
    });
    // If there are no pre-existing add-ons the preference value will be an
    // empty string.
    Services.prefs.setCharPref(PREF_DISABLEDADDONS, disabledAddons.join(" "));

    // Install the test add-ons.
    let xpiFiles = getTestAddonXPIFiles();
    let xpiCount = xpiFiles.length;
    let installs = [];
    xpiFiles.forEach(function(aFile) {
      AddonManager.getInstallForFile(aFile, function(aInstall) {
        if (!aInstall) {
          throw "No AddonInstall created for " + aFile.path;
        }

        installs.push(aInstall);

        if (--xpiCount == 0) {
          let installCount = installs.length;
          function installCompleted(aInstall) {
            aInstall.removeListener(listener);

            if (getAddonTestType(aInstall.addon.name) == "userdisabled") {
              aInstall.addon.userDisabled = true;
            }
            if (--installCount == 0) {
              setNoUpdateAddonsDisabledState();
            }
          }

          let listener = {
            onDownloadFailed: installCompleted,
            onDownloadCancelled: installCompleted,
            onInstallFailed: installCompleted,
            onInstallCancelled: installCompleted,
            onInstallEnded: installCompleted
          };

          installs.forEach(function(aInstall) {
            aInstall.addListener(listener);
            aInstall.install();
          });
        }
      });
    });
  });
}

/**
 * Uninstalls the test add-ons, enables add-ons that were disabled when the
 * test started, and calls the callback specified in the aCallback parameter.
 *
 * @param  aCallback
 *         A callback to call after all operations have completed.
 */
function resetAddons(aCallback) {
  debugDump("entering");
  // If test_9999_cleanup.xul is ran by itself then the test add-ons will not
  // have been installed and any pre-existing add-ons will not have been
  // disabled so return early.
  if (!Services.prefs.prefHasUserValue(PREF_DISABLEDADDONS)) {
    debugDump("preference " + PREF_DISABLEDADDONS + " doesn't exist... " +
              "returning early");
    aCallback();
    return;
  }

  // Uninstall the test add-ons.
  let count = TEST_ADDONS.length;
  function uninstallCompleted(aAddon) {
    if (--count == 0) {
      AddonManager.removeAddonListener(listener);

      // Enable the pre-existing add-ons that were disabled so they wouldn't
      // interfere with the tests.
      let disabledAddons = Services.prefs.getCharPref(PREF_DISABLEDADDONS).split(" ");
      Services.prefs.clearUserPref(PREF_DISABLEDADDONS);
      AddonManager.getAllAddons(function(aAddons) {
        aAddons.forEach(function(aAddon) {
          if (disabledAddons.indexOf(aAddon.id)) {
            aAddon.userDisabled = false;
          }
        });
        aCallback();
      });
    }
  }

  let listener = {
    onUninstalled: uninstallCompleted
  };

  AddonManager.addAddonListener(listener);
  TEST_ADDONS.forEach(function(aName) {
    AddonManager.getAddonByID(aName + ADDON_ID_SUFFIX, function(aAddon) {
      aAddon.uninstall();
    });
  });
}

/**
 * Helper function to get the string before the '_' character in an add-on's
 * name or id which is used to determine the add-on test type used by the tests.
 *
 * @param  aName
 *         The test add-on's name or id.
 * @return The string before the '_' character in the string passed in the aName
 *         parameter.
 */
function getAddonTestType(aName) {
  return aName.split("_")[0];
}

/**
 * Helper function to create add-on xpi files for the default test add-ons.
 *
 * @return An array with each member being an nsILocalFile for an add-on XPI
 *         file.
 */
function getTestAddonXPIFiles() {
  let addonPrepDir = Services.dirsvc.get(NS_APP_USER_PROFILE_50_DIR,
                                         AUS_Ci.nsILocalFile);
  addonPrepDir.append(ADDON_PREP_DIR);

  let bootstrap = addonPrepDir.clone();
  bootstrap.append("bootstrap.js");
  // If a previous test has already created bootstrap.js don't create it again.
  if (!bootstrap.exists()) {
    let bootstrapContents = "function install(data, reason){ }\n" +
                            "function startup(data, reason){ }\n" +
                            "function shutdown(data, reason){ }\n" +
                            "function uninstall(data, reason){ }\n";
    writeFile(bootstrap, bootstrapContents);
  }

  let installRDF = addonPrepDir.clone();
  installRDF.append("install.rdf");

  let xpiFiles = [];
  TEST_ADDONS.forEach(function(aName) {
    let xpiFile = addonPrepDir.clone();
    xpiFile.append(aName + ".xpi");

    if (installRDF.exists())
      installRDF.remove(false);
    writeFile(installRDF, getInstallRDFString(aName));
    gZipW.open(xpiFile, PR_RDWR | PR_CREATE_FILE | PR_TRUNCATE);
    gZipW.addEntryFile(installRDF.leafName,
                       AUS_Ci.nsIZipWriter.COMPRESSION_DEFAULT, installRDF,
                       false);
    gZipW.addEntryFile(bootstrap.leafName,
                       AUS_Ci.nsIZipWriter.COMPRESSION_DEFAULT, bootstrap,
                       false);
    gZipW.close();
    xpiFiles.push(xpiFile);
  });

  return xpiFiles;
}

/**
 * Helper function to gets the string representation of the contents of the
 * add-on's install.rdf file.
 *
 * @param  aName
 *         The string to use for the add-on's name which is also used to
 *         construct the local-part in RFC 5322 format of the add-on's ID.
 * @return A string representation of the contents of the add-on's install.rdf
 *         file.
 */
function getInstallRDFString(aName) {
  let maxVersion = Services.appinfo.platformVersion;
  switch (getAddonTestType(aName)) {
    case "compatible":
      maxVersion = getNewerPlatformVersion();
      break;
    case "appdisabled":
      maxVersion = "0.1";
      break;
  }

  return "<?xml version=\"1.0\"?>\n" +
         "<RDF xmlns=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\"\n" +
         "  xmlns:em=\"http://www.mozilla.org/2004/em-rdf#\">\n" +
         "  <Description about=\"urn:mozilla:install-manifest\">\n" +
         "    <em:id>" + aName + ADDON_ID_SUFFIX + "</em:id>\n" +
         "    <em:version>1.0</em:version>\n" +
         "    <em:bootstrap>true</em:bootstrap>\n" +
         "    <em:name>" + aName + "</em:name>\n" +
         "    <em:description>Test Description</em:description>\n" +
         "    <em:targetApplication>\n" +
         "      <Description>\n" +
         "        <em:id>toolkit@mozilla.org</em:id>\n" +
         "        <em:minVersion>undefined</em:minVersion>\n" +
         "        <em:maxVersion>" + maxVersion + "</em:maxVersion>\n" +
         "      </Description>\n" +
         "    </em:targetApplication>\n" +
         "  </Description>\n" +
         "</RDF>";
}

/**
 * Closes the update window if it is open and causes the test to fail if an
 * update window is found.
 *
 * @return true if an update window was found, otherwise false.
 */
function closeUpdateWindow() {
  let updateWindow = getUpdateWindow();
  if (!updateWindow)
    return false;

  ok(false, "Found an existing Update Window from the current or a previous " +
            "test... attempting to close it.");
  updateWindow.close();
  return true;
}

/**
 * Gets the update window.
 *
 * @return The nsIDOMWindow for the Update Window if it is open and null
 *         if it isn't.
 */
function getUpdateWindow() {
  return Services.wm.getMostRecentWindow(UPDATE_WINDOW_NAME);
}

/**
 * Helper for background check errors.
 */
var errorsPrefObserver = {
  observedPref: null,
  maxErrorPref: null,

  /**
   * Sets up a preference observer and sets the associated maximum errors
   * preference used for background notification.
   *
   * @param  aObservePref
   *         The preference to observe.
   * @param  aMaxErrorPref
   *         The maximum errors preference.
   * @param  aMaxErrorCount
   *         The value to set the app.update.cert.maxErrors preference to.
   */
  init: function(aObservePref, aMaxErrorPref, aMaxErrorCount) {
    this.observedPref = aObservePref;
    this.maxErrorPref = aMaxErrorPref;

    let maxErrors = aMaxErrorCount ? aMaxErrorCount : 2;
    Services.prefs.setIntPref(aMaxErrorPref, maxErrors);
    Services.prefs.addObserver(aObservePref, this, false);
  },

  /**
   * Preference observer for the preference specified in |this.observedPref|.
   */
  observe: function XPI_observe(aSubject, aTopic, aData) {
    if (aData == this.observedPref) {
      let errCount = Services.prefs.getIntPref(this.observedPref);
      let errMax = Services.prefs.getIntPref(this.maxErrorPref);
      if (errCount >= errMax) {
        debugDump("removing pref observer");
        Services.prefs.removeObserver(this.observedPref, this);
      }
      else {
        debugDump("notifying AUS");
        SimpleTest.executeSoon(function() {
          gAUS.notify(null);
        });
      }
    }
  }
};

/**
 * nsIObserver for receiving window open and close notifications.
 */
var gWindowObserver = {
  observe: function WO_observe(aSubject, aTopic, aData) {
    let win = aSubject.QueryInterface(AUS_Ci.nsIDOMEventTarget);

    if (aTopic == "domwindowclosed") {
      if (win.location != URI_UPDATE_PROMPT_DIALOG) {
        debugDump("domwindowclosed event for window not being tested - " +
                  "location: " + win.location + "... returning early");
        return;
      }
      // Allow tests the ability to provide their own function (it must be
      // named finishTest) for finishing the test.
      try {
        finishTest();
      }
      catch (e) {
        finishTestDefault();
      }
      return;
    }

    win.addEventListener("load", function WO_observe_onLoad() {
      win.removeEventListener("load", WO_observe_onLoad, false);
      // Ignore windows other than the update UI window.
      if (win.location != URI_UPDATE_PROMPT_DIALOG) {
        debugDump("load event for window not being tested - location: " +
                  win.location + "... returning early");
        return;
      }

      // The first wizard page should always be the dummy page.
      let pageid = win.document.documentElement.currentPage.pageid;
      if (pageid != PAGEID_DUMMY) {
        // This should never happen but if it does this will provide a clue
        // for diagnosing the cause.
        ok(false, "Unexpected load event - pageid got: " + pageid +
           ", expected: " + PAGEID_DUMMY + "... returning early");
        return;
      }

      gWin = win;
      gDocElem = gWin.document.documentElement;
      gDocElem.addEventListener("pageshow", onPageShowDefault, false);
    }, false);
  }
};
