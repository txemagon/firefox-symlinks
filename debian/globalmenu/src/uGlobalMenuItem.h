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

#ifndef _U_GLOBALMENUITEM_H
#define _U_GLOBALMENUITEM_H

#include <prtypes.h>
#include <nsCOMPtr.h>
#include <nsStringGlue.h>

#include <libdbusmenu-glib/server.h>

#include "uGlobalMenuObject.h"
#include "uWidgetAtoms.h"

#define UNITY_MENUITEM_TYPE_0             FLAG(8)
#define UNITY_MENUITEM_TYPE_1             FLAG(9)
#define UNITY_MENUITEM_TYPE_MASK          (UNITY_MENUITEM_TYPE_1 | UNITY_MENUITEM_TYPE_0)

// This menuitem is a checkbox or radioitem which is active
#define UNITY_MENUITEM_TOGGLE_IS_ACTIVE   FLAG(10)

class nsIContent;
class uGlobalMenuDocListener;

enum uMenuItemType {
  eNormal = 0,
  eCheckBox,
  eRadio
};

class uGlobalMenuItem: public uGlobalMenuObject
{
public:
  static uGlobalMenuObject* Create(uGlobalMenuObject *aParent,
                                   uGlobalMenuDocListener *aListener,
                                   nsIContent *aContent);
  virtual void Destroy();
  virtual ~uGlobalMenuItem();

  virtual uMenuObjectType GetType() { return eMenuItem; }

protected:
  virtual void ObserveAttributeChanged(nsIContent *aContent,
                                       nsIAtom *aAttribute);

private:
  uGlobalMenuItem();

  nsresult Init(uGlobalMenuObject *aParent,
                uGlobalMenuDocListener *aListener,
                nsIContent *aContent);

  PRUint32 GetKeyCode(nsAString &aKeyName);
  PRUint32 MozKeyCodeToGdkKeyCode(PRUint32 aMozKeyCode);
  void SyncStateFromCommand();
  void SyncLabelFromCommand();
  void SyncSensitivityFromCommand();
  void SyncAccelFromContent();
  void SyncTypeAndStateFromContent();
  void SyncStateFromContent();
  virtual void InitializeDbusMenuItem();
  virtual void Refresh(uMenuObjectRefreshMode aMode);
  virtual uMenuObjectProperties GetValidProperties()
  {
    return static_cast<uMenuObjectProperties>(eLabel | eEnabled | eVisible |
                                              eIconData | eShortcut |
                                              eToggleType | eToggleState);
  }
  static void ItemActivatedCallback(DbusmenuMenuitem *menuItem,
                                    PRUint32 timeStamp,
                                    void *data);
  void Activate(PRUint32 timeStamp);
  void UncheckSiblings();

  void SetMenuItemType(uMenuItemType aType);
  uMenuItemType GetMenuItemType()
  {
    return static_cast<uMenuItemType>((mFlags & UNITY_MENUITEM_TYPE_MASK) >> 8);
  }

  bool IsCheckboxOrRadioItem()
  {
    return GetMenuItemType() > eNormal;
  }

  void SetCheckState(bool aChecked)
  {
    NS_ASSERTION(IsCheckboxOrRadioItem(), "Not a checkbox or radio item");
    SetOrClearFlags(aChecked, UNITY_MENUITEM_TOGGLE_IS_ACTIVE);
    LOGTM("Setting check state to %s", aChecked ? "true" : "false");
  }

  bool IsChecked()
  {
    NS_ASSERTION(IsCheckboxOrRadioItem(), "Not a checkbox or radio item");
    return !!(mFlags & UNITY_MENUITEM_TOGGLE_IS_ACTIVE);
  }

  nsCOMPtr<nsIContent> mCommandContent;
  nsCOMPtr<nsIContent> mKeyContent;
};


#endif
