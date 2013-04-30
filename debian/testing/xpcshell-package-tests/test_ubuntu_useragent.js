function run_test()
{
  createAppInfo();

  let ua = Services.io.newChannel("http://foo", null, null).QueryInterface(Ci.nsIHttpChannel).getRequestHeader("User-Agent");
  if (Services.prefs.getCharPref("app.update.channel") == "nightly") {
    var buildid = gXULAppInfo.appBuildID.slice(0, 8);
  } else {
    var buildid = "20100101";
  }
  let re = new RegExp("^Mozilla/5\\.0 \\(X11; Ubuntu; Linux [^;]*; rv:[0-9\\.]*\\) Gecko/" + buildid + " Firefox/[0-9\\.]*");
  do_check_eq(ua, ua.match(re));
}
