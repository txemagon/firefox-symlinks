/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 */

/**
 * Server side http server script for application update tests.
 *
 * !IMPORTANT - Since xpcshell used by the http server is launched with -v 170
 * this file must not use features greater than JavaScript 1.7.
 */

const AUS_Cc = Components.classes;
const AUS_Ci = Components.interfaces;

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

const URL_HOST = "http://example.com/";
const URL_PATH = "chrome/toolkit/mozapps/update/test/chrome/";
const URL_UPDATE = URL_HOST + URL_PATH + "update.sjs";
const SERVICE_URL = URL_HOST + URL_PATH + FILE_SIMPLE_MAR;

const SLOW_MAR_DOWNLOAD_INTERVAL = 100;
var gTimer;

function handleRequest(aRequest, aResponse) {
  var params = { };
  if (aRequest.queryString)
    params = parseQueryString(aRequest.queryString);

  var statusCode = params.statusCode ? parseInt(params.statusCode) : 200;
  var statusReason = params.statusReason ? params.statusReason : "OK";
  aResponse.setStatusLine(aRequest.httpVersion, statusCode, statusReason);
  aResponse.setHeader("Cache-Control", "no-cache", false);
  
  if (params.addonID) {
    aResponse.write(getUpdateRDF(params));
    return;
  }

  // When a mar download is started by the update service it can finish
  // downloading before the ui has loaded. By specifying a serviceURL for the
  // update patch that points to this file and has a slowDownloadMar param the
  // mar will be downloaded asynchronously which will allow the ui to load
  // before the download completes.
  if (params.slowDownloadMar) {
    aResponse.processAsync();
    aResponse.setHeader("Content-Type", "binary/octet-stream");
    aResponse.setHeader("Content-Length", SIZE_SIMPLE_MAR);
    var marFile = AUS_Cc["@mozilla.org/file/directory_service;1"].
                  getService(AUS_Ci.nsIProperties).
                  get("CurWorkD", AUS_Ci.nsILocalFile);
    var path = URL_PATH + FILE_SIMPLE_MAR;
    var pathParts = path.split("/");
    for(var i = 0; i < pathParts.length; ++i)
      marFile.append(pathParts[i]);
    var contents = readFileBytes(marFile);
    gTimer = AUS_Cc["@mozilla.org/timer;1"].
             createInstance(AUS_Ci.nsITimer);
    gTimer.initWithCallback(function(aTimer) {
      aResponse.write(contents);
      aResponse.finish();
    }, SLOW_MAR_DOWNLOAD_INTERVAL, AUS_Ci.nsITimer.TYPE_ONE_SHOT);
    return;
  }

  if (params.uiURL) {
    var remoteType = "";
    if (!params.remoteNoTypeAttr &&
        (params.uiURL == "BILLBOARD" || params.uiURL == "LICENSE")) {
      remoteType = " " + params.uiURL.toLowerCase() + "=\"1\"";
    }
    aResponse.write("<html><head><meta http-equiv=\"content-type\" content=" +
                    "\"text/html; charset=utf-8\"></head><body" +
                    remoteType + ">" + params.uiURL +
                    "<br><br>this is a test mar that will not affect your " +
                    "build.</body></html>");
    return;
  }

  if (params.xmlMalformed) {
    aResponse.write("xml error");
    return;
  }

  if (params.noUpdates) {
    aResponse.write(getRemoteUpdatesXMLString(""));
    return;
  }

  var hash;
  var patches = "";
  if (!params.partialPatchOnly) {
    hash = SHA512_HASH_SIMPLE_MAR + (params.invalidCompleteHash ? "e" : "");
    patches += getRemotePatchString("complete", SERVICE_URL, "SHA512",
                                    hash, SIZE_SIMPLE_MAR);
  }

  if (!params.completePatchOnly) {
    hash = SHA512_HASH_SIMPLE_MAR + (params.invalidPartialHash ? "e" : "");
    patches += getRemotePatchString("partial", SERVICE_URL, "SHA512",
                                    hash, SIZE_SIMPLE_MAR);
  }

  var type = params.type ? params.type : "major";
  var name = params.name ? params.name : "App Update Test";
  var appVersion = params.appVersion ? params.appVersion : "99.9";
  var displayVersion = params.displayVersion ? params.displayVersion
                                             : "version " + appVersion;
  var platformVersion = params.platformVersion ? params.platformVersion : "99.8";
  var buildID = params.buildID ? params.buildID : "01234567890123";
  // XXXrstrong - not specifying a detailsURL will cause a leak due to bug 470244
//  var detailsURL = params.showDetails ? URL_UPDATE + "?uiURL=DETAILS" : null;
  var detailsURL = URL_UPDATE + "?uiURL=DETAILS";
  var billboardURL = params.showBillboard ? URL_UPDATE + "?uiURL=BILLBOARD" : null;
  if (billboardURL && params.remoteNoTypeAttr)
    billboardURL += "&amp;remoteNoTypeAttr=1";
  if (params.billboard404)
    billboardURL = URL_HOST + URL_PATH + "missing.html";
  var licenseURL = params.showLicense ? URL_UPDATE + "?uiURL=LICENSE" : null;
  if (licenseURL && params.remoteNoTypeAttr)
    licenseURL += "&amp;remoteNoTypeAttr=1";
  if (params.license404)
    licenseURL = URL_HOST + URL_PATH + "missing.html";
  var showPrompt = params.showPrompt ? "true" : null;
  var showNever = params.showNever ? "true" : null;
  var promptWaitTime = params.promptWaitTime ? params.promptWaitTime : null;
  var showSurvey = params.showSurvey ? "true" : null;

  // For testing the deprecated update xml format
  if (params.oldFormat) {
    appVersion = null;
    displayVersion = null;
    billboardURL = null;
    showPrompt = null;
    showNever = null;
    showSurvey = null;
    detailsURL = URL_UPDATE + "?uiURL=BILLBOARD";
    if (params.remoteNoTypeAttr)
      detailsURL += "&amp;remoteNoTypeAttr=1";
    var extensionVersion = params.appVersion ? params.appVersion : "99.9";
    var version = params.displayVersion ? params.displayVersion
                                        : "version " + extensionVersion;
  }

  var updates = getRemoteUpdateString(patches, type, "App Update Test",
                                      displayVersion, appVersion,
                                      platformVersion, buildID, detailsURL,
                                      billboardURL, licenseURL, showPrompt,
                                      showNever, promptWaitTime, showSurvey,
                                      version, extensionVersion);

  aResponse.write(getRemoteUpdatesXMLString(updates));
}

/**
 * Helper function to create a JS object representing the url parameters from
 * the request's queryString.
 *
 * @param  aQueryString
 *         The request's query string.
 * @return A JS object representing the url parameters from the request's
 *         queryString.
 */
function parseQueryString(aQueryString) {
  var paramArray = aQueryString.split("&");
  var regex = /^([^=]+)=(.*)$/;
  var params = {};
  for (var i = 0, sz = paramArray.length; i < sz; i++) {
    var match = regex.exec(paramArray[i]);
    if (!match)
      throw "Bad parameter in queryString!  '" + paramArray[i] + "'";
    params[decodeURIComponent(match[1])] = decodeURIComponent(match[2]);
  }

  return params;
}

/**
 * Helper function to gets the string representation of the contents of the
 * add-on's update manifest file.
 *
 * @param  aParams
 *         A JS object representing the url parameters from the request's
 *         queryString.
 * @return A string representation of the contents of the add-on's update
 *         manifest file.
 */
function getUpdateRDF(aParams) {
  var addonVersion;
  var addonID = aParams.addonID;
  var addonUpdateType = addonID.split("_")[0];
  var maxVersion = aParams.platformVersion;

  switch (addonUpdateType) {
    case "updatecompatibility":
      // Use "1.0" for the add-on version for the compatibility update case since
      // the tests create all add-ons with "1.0" for the version.
      addonVersion = "1.0";
      break;
    case "updateversion":
      // Use "2.0" for the add-on version for the version update case since the
      // tests create all add-ons with "1.0" for the version.
      addonVersion = "2.0";
      break;
    default:
      return "<?xml version=\"1.0\"?>\n" +
             "<RDF:RDF xmlns:RDF=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" " +
             "         xmlns:em=\"http://www.mozilla.org/2004/em-rdf#\">\n" +
             "</RDF:RDF>\n";
  }

  return "<?xml version=\"1.0\"?>\n" +
         "<RDF:RDF xmlns:RDF=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\" " +
         "         xmlns:em=\"http://www.mozilla.org/2004/em-rdf#\">\n" +
         "  <RDF:Description about=\"urn:mozilla:extension:" + addonID + "\">\n" +
         "    <em:updates>\n" +
         "      <RDF:Seq>\n" +
         "        <RDF:li resource=\"urn:mozilla:extension:" + addonID + ":" + addonVersion + "\"/>\n" +
         "      </RDF:Seq>\n" +
         "    </em:updates>\n" +
         "  </RDF:Description>\n" +
         "  <RDF:Description about=\"urn:mozilla:extension:" + addonID + ":" + addonVersion + "\">\n" +
         "    <em:version>" + addonVersion + "</em:version>\n" +
         "    <em:targetApplication>\n" +
         "      <RDF:Description>\n" +
         "        <em:id>toolkit@mozilla.org</em:id>\n" +
         "        <em:minVersion>0</em:minVersion>\n" +
         "        <em:maxVersion>" + maxVersion + "</em:maxVersion>\n" +
         "        <em:updateLink>" + URL_HOST + URL_PATH + "</em:updateLink>\n" +
         "        <em:updateHash>sha256:0</em:updateHash>\n" + 
         "      </RDF:Description>\n" +
         "    </em:targetApplication>\n" +
         "  </RDF:Description>\n" +
         "</RDF:RDF>\n";
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
