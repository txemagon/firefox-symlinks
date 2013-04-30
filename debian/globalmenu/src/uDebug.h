/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 *	 Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is globalmenu-extension.
 *
 * The Initial Developer of the Original Code is
 * Canonical Ltd.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 * Chris Coulson <chris.coulson@canonical.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 * 
 * ***** END LICENSE BLOCK ***** */

#ifndef _U_DEBUG_H
#define _U_DEBUG_H

#include <nsStringGlue.h>
#include <nsXPCOM.h>

#if DEBUG_GLOBALMENU >= 1 && !defined DEBUG
#undef NS_ASSERTION
#undef NS_WARN_IF_FALSE
#undef NS_WARNING
#undef NS_ERROR

#define NS_ASSERTION(expr, str)                               \
  do {                                                        \
    if (!(expr)) {                                            \
      NS_DebugBreak(NS_DEBUG_ASSERTION, str, #expr, __FILE__, __LINE__); \
    }                                                         \
  } while(0)

#define NS_WARN_IF_FALSE(_expr,_msg)                          \
  do {                                                        \
    if (!(_expr)) {                                           \
      NS_DebugBreak(NS_DEBUG_WARNING, _msg, #_expr, __FILE__, __LINE__); \
    }                                                         \
  } while(0)

#define NS_WARNING(str)                                       \
  NS_DebugBreak(NS_DEBUG_WARNING, str, nullptr, __FILE__, __LINE__)

#define NS_ERROR(str)                                         \
  NS_DebugBreak(NS_DEBUG_ASSERTION, str, "Error", __FILE__, __LINE__)
#endif

#if defined DEBUG && !defined DEBUG_GLOBALMENU
#define DEBUG_GLOBALMENU 2
#endif

#if DEBUG_GLOBALMENU >= 2
#include <stdarg.h>
#include <stdio.h>
# define LOG_LENGTH 1024

#if DEBUG_GLOBALMENU == 2
# define DEBUG_DEPTH 0
#else
# define DEBUG_DEPTH FunctionTracer::sDepth * 2
#endif

#define LOGTM(format...)                                      \
  LOGM(this, format)

#define LOGM(object, format...)                               \
  if (getenv("GLOBAL_MENU_LOGGING")) {                        \
    nsAutoString id;                                          \
    if (object) object->GetContent()->GetAttr(kNameSpaceID_None, uWidgetAtoms::id, id); \
    char str[LOG_LENGTH+1];                                   \
    snprintf(str, LOG_LENGTH, format);                        \
    printf("%*s %s [menuobject: %p (id: %s)]: %s\n", DEBUG_DEPTH, "", str, (void *)object, NS_LossyConvertUTF16toASCII(id).get(), __PRETTY_FUNCTION__); \
  }

#define LOGC(content, format...)                              \
  if (getenv("GLOBAL_MENU_LOGGING")) {                        \
    nsAutoString id;                                          \
    content->GetAttr(kNameSpaceID_None, uWidgetAtoms::id, id); \
    char str[LOG_LENGTH+1];                                   \
    snprintf(str, LOG_LENGTH, format);                        \
    printf("%*s %s [content: %p (id: %s)]: %s\n", DEBUG_DEPTH, "", str, (void *)content, NS_LossyConvertUTF16toASCII(id).get(), __PRETTY_FUNCTION__); \
  }

#define LOG(format...)                                        \
  if (getenv("GLOBAL_MENU_LOGGING")) {                        \
    char str[LOG_LENGTH+1];                                   \
    snprintf(str, LOG_LENGTH, format);                        \
    printf("%*s %s: %s\n", DEBUG_DEPTH, "", str, __PRETTY_FUNCTION__); \
  }

#else
#define LOGTM(format...)
#define LOGM(object, format...)
#define LOGC(content, format...)
#define LOG(format...)
#endif

#if DEBUG_GLOBALMENU >= 3
class FunctionTracer
{
public:
  FunctionTracer(const char *s, ...)
  {

    if (getenv("GLOBAL_MENU_TRACING")) {
      va_list ap;
      va_start(ap, s);
      vsnprintf(mString, LOG_LENGTH, s, ap);
      va_end(ap);

      printf("%*s=== Entering %s ===\n", sDepth * 2, "", mString);
      sDepth++;
    }
  }

  ~FunctionTracer()
  {
    if (getenv("GLOBAL_MENU_TRACING")) {
      sDepth--;
      printf("%*s=== Leaving %s ===\n", sDepth * 2, "", mString);
    }
  }

  static PRUint32 sDepth;

private:
  char mString[LOG_LENGTH+1];
};

#define TRACETM()                                             \
  TRACEM(this)

#define TRACEM(object)                                        \
  nsAutoString _id;                                           \
  if (object) object->GetContent()->GetAttr(kNameSpaceID_None, uWidgetAtoms::id, _id); \
  FunctionTracer _marker("%s [menuobject: %p (id: %s)]", __PRETTY_FUNCTION__, (void *)object, NS_LossyConvertUTF16toASCII(_id).get()); \

#define TRACEC(content)                                       \
  nsAutoString _id;                                           \
  content->GetAttr(kNameSpaceID_None, uWidgetAtoms::id, _id); \
  FunctionTracer _marker("%s [content: %p (id: %s)]", __PRETTY_FUNCTION__, (void *)content, NS_LossyConvertUTF16toASCII(_id).get()); \

#define TRACE()                                               \
  FunctionTracer _marker("%s", __PRETTY_FUNCTION__);

#else
#define TRACETM()
#define TRACEM(object)
#define TRACEC(content)
#define TRACE()
#endif

#endif
