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

#include <nsIContent.h>
#include <nsIAtom.h>
#include <nsIWidget.h>

#include <gdk/gdk.h>

#include "uGlobalMenuUtils.h"
#include "uGlobalMenu.h"
#include "uGlobalMenuItem.h"
#include "uGlobalMenuSeparator.h"
#include "uGlobalMenuDocListener.h"
#include "uWidgetAtoms.h"

#include "uDebug.h"

typedef uGlobalMenuObject* (*uMenuObjectConstructor)(uGlobalMenuObject*,
                                                     uGlobalMenuDocListener*,
                                                     nsIContent*);
struct uMenuObjectConstructorMapEntry {
  nsIAtom **tag;
  uMenuObjectConstructor constructor;
};

static const uMenuObjectConstructorMapEntry kConstructorMap[] = {
  { &uWidgetAtoms::menu, uGlobalMenu::Create },
  { &uWidgetAtoms::menuitem, uGlobalMenuItem::Create },
  { &uWidgetAtoms::menuseparator, uGlobalMenuSeparator::Create }
};

static uMenuObjectConstructor
GetMenuObjectConstructor(nsIContent *aContent)
{
  if (!aContent->IsXUL()) {
    return nullptr;
  }

  for (uint32_t i = 0; i < mozilla::ArrayLength(kConstructorMap); i++) {
    if (aContent->Tag() == *kConstructorMap[i].tag) {
      return kConstructorMap[i].constructor;
    }
  }

  return nullptr;
}

static bool
ContentIsSupported(nsIContent *aContent)
{
  TRACEC(aContent);

  return GetMenuObjectConstructor(aContent) ? true : false;
}

nsIContent*
uGlobalMenuUtils::GetPreviousSupportedSibling(nsIContent *aContent)
{
  while (aContent && !ContentIsSupported(aContent)) {
    aContent = aContent->GetPreviousSibling();
  }

  return aContent;
}

uGlobalMenuObject*
uGlobalMenuUtils::CreateMenuObject(uGlobalMenuObject *aParent,
                                   uGlobalMenuDocListener *aListener,
                                   nsIContent *aContent,
                                   bool *aFailed)
{
  TRACEC(aContent);

  if (aFailed) {
    *aFailed = false;
  }

  uMenuObjectConstructor constructor = GetMenuObjectConstructor(aContent);
  if (!constructor) {
    return nullptr;
  }

  uGlobalMenuObject *res = constructor(aParent, aListener, aContent);
  if (!res && aFailed) {
    *aFailed = true;
  }

  return res;
}

GtkWidget*
uGlobalMenuUtils::WidgetToGTKWindow(nsIWidget *aWidget)
{
  // Get the main GDK drawing window from our nsIWidget
  GdkWindow *window = static_cast<GdkWindow *>(aWidget->GetNativeData(NS_NATIVE_WINDOW));
  if (!window) {
    return nullptr;
  }

  // Get the widget for the main drawing window, which should be a MozContainer
  gpointer user_data = nullptr;
  gdk_window_get_user_data(window, &user_data);
  if (!user_data || !GTK_IS_CONTAINER(user_data)) {
    return nullptr;
  }

  return gtk_widget_get_toplevel(GTK_WIDGET(user_data));
}
