/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* diagnostic reporting for CSS style sheet parser */

#ifndef mozilla_css_ErrorReporter_h_
#define mozilla_css_ErrorReporter_h_

// XXX turn this off for minimo builds
#define CSS_REPORT_PARSE_ERRORS

#include "nsString.h"

struct nsCSSToken;
class nsCSSStyleSheet;
class nsCSSScanner;
class nsIURI;

namespace mozilla {
namespace css {

class Loader;

// If CSS_REPORT_PARSE_ERRORS is not defined, all of this class's
// methods become inline stubs.
class NS_STACK_CLASS ErrorReporter {
public:
  ErrorReporter(const nsCSSScanner &aScanner,
                const nsCSSStyleSheet *aSheet,
                const Loader *aLoader,
                nsIURI *aURI);
  ~ErrorReporter();

  static void ReleaseGlobals();

  void OutputError();
  void ClearError();

  // In all overloads of ReportUnexpected, aMessage is a stringbundle
  // name, which will be processed as a format string with the
  // indicated number of parameters.

  // no parameters
  void ReportUnexpected(const char *aMessage);
  // one parameter, a string
  void ReportUnexpected(const char *aMessage, const nsString& aParam);
  // one parameter, a token
  void ReportUnexpected(const char *aMessage, const nsCSSToken& aToken);
  // two parameters, a token and a character, in that order
  void ReportUnexpected(const char *aMessage, const nsCSSToken& aToken,
                        PRUnichar aChar);

  // for ReportUnexpectedEOF, aExpected can be either a stringbundle
  // name or a single character.  In the former case there may not be
  // any format parameters.
  void ReportUnexpectedEOF(const char *aExpected);
  void ReportUnexpectedEOF(PRUnichar aExpected);

private:
  void AddToError(const nsString &aErrorText);

#ifdef CSS_REPORT_PARSE_ERRORS
  nsAutoString mError;
  nsString mFileName;
  const nsCSSScanner *mScanner;
  const nsCSSStyleSheet *mSheet;
  const Loader *mLoader;
  nsIURI *mURI;
  uint64_t mInnerWindowID;
  uint32_t mErrorLineNumber;
  uint32_t mErrorColNumber;
#endif
};

#ifndef CSS_REPORT_PARSE_ERRORS
inline ErrorReporter::ErrorReporter(const nsCSSScanner&,
                                    const nsCSSStyleSheet*,
                                    const Loader*,
                                    nsIURI*) {}
inline ErrorReporter::~ErrorReporter() {}

inline void ErrorReporter::ReleaseGlobals() {}

inline void ErrorReporter::OutputError() {}
inline void ErrorReporter::ClearError() {}

inline void ErrorReporter::ReportUnexpected(const char *) {}
inline void ErrorReporter::ReportUnexpected(const char *, const nsString &) {}
inline void ErrorReporter::ReportUnexpected(const char *, const nsCSSToken &) {}
inline void ErrorReporter::ReportUnexpected(const char *, const nsCSSToken &,
                                            PRUnichar) {}

inline void ErrorReporter::ReportUnexpectedEOF(const char *) {}
inline void ErrorReporter::ReportUnexpectedEOF(PRUnichar) {}

inline void ErrorReporter::AddToError(const nsString &) {}
#endif

} // namespace css
} // namespace mozilla

#endif // mozilla_css_ErrorReporter_h_
