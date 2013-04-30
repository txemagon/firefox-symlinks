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

#ifndef _U_GLOBALMENU_H
#define _U_GLOBALMENU_H

#include <prtypes.h>
#include <nsTArray.h>
#include <nsAutoPtr.h>
#include <nsCOMPtr.h>
#include <nsIContent.h>
#include <nsThreadUtils.h>

#include <libdbusmenu-glib/server.h>

#include "uGlobalMenuObject.h"
#include "uWidgetAtoms.h"

#define UNITY_MENU_POPUP_STATE_0          FLAG(8)
#define UNITY_MENU_POPUP_STATE_1          FLAG(9)
#define UNITY_MENU_POPUP_STATE_2          FLAG(10)
#define UNITY_MENU_POPUP_STATE_MASK       (UNITY_MENU_POPUP_STATE_2 | UNITY_MENU_POPUP_STATE_1 | UNITY_MENU_POPUP_STATE_0)

// The menu needs rebuilding
#define UNITY_MENU_NEEDS_REBUILDING       FLAG(11)

// The shell sent the first "AboutToOpen" event
#define UNITY_MENU_READY                  FLAG(12)

class uGlobalMenuItem;
class uGlobalMenuDocListener;
class nsITimer;

enum uMenuPopupState {
  ePopupClosed = 0,
  ePopupShowing,
  ePopupOpen1, // Menu was opened with an "about-to-show" signal
  ePopupOpen2, // Menu was opened with an "opened" event
  ePopupHiding
};

class uGlobalMenu: public uGlobalMenuObject
{
public:
  static uGlobalMenuObject* Create(uGlobalMenuObject *aParent,
                                   uGlobalMenuDocListener *aListener,
                                   nsIContent *aContent);
  virtual void Destroy();
  virtual ~uGlobalMenu();

  virtual uMenuObjectType GetType() { return eMenu; }

  bool CanOpen();
  void OpenMenuDelayed();
  
protected:
  virtual void ObserveAttributeChanged(nsIContent *aContent,
                                       nsIAtom *aAttribute);
  virtual void ObserveContentRemoved(nsIContent *aContainer,
                                     nsIContent *aChild);
  virtual void ObserveContentInserted(nsIContent *aContainer,
                                      nsIContent *aChild,
                                      nsIContent *aPrevSibling);

private:
  uGlobalMenu();

  // Initialize the menu structure
  nsresult Init(uGlobalMenuObject *aParent,
                uGlobalMenuDocListener *aListener,
                nsIContent *aContent);

  uint32_t IndexOf(nsIContent *aContent);
  bool InsertMenuObjectAfterContent(uGlobalMenuObject *menuObj,
                                    nsIContent *aPrevSibling);
  bool AppendMenuObject(uGlobalMenuObject *menuObj);
  bool RemoveMenuObjectAt(uint32_t index, bool recycle);
  bool RemoveMenuObjectForContent(nsIContent *aContent, bool recycle);
  virtual void InitializeDbusMenuItem();
  virtual void Refresh(uMenuObjectRefreshMode aMode);
  virtual uMenuObjectProperties GetValidProperties()
  {
    return static_cast<uMenuObjectProperties>(eLabel | eEnabled | eVisible |
                                              eIconData | eChildDisplay);
  }
  nsresult Build();
  void InitializePopup();
  static bool MenuAboutToOpenCallback(DbusmenuMenuitem *menu,
                                      void *data);
  static bool MenuEventCallback(DbusmenuMenuitem *menu,
                                const gchar *name,
                                GVariant *value,
                                guint timestamp,
                                void *data);
  static void DoOpen(nsITimer *aTimer, void *aClosure);
  void AboutToOpen(bool aOpenedEvent, bool aWantPopupShownEvent = true);
  void FirePopupShownEvent();
  void OnClose();
  void FirePopupHidingEvent();
  void SetNeedsRebuild() { mFlags = mFlags | UNITY_MENU_NEEDS_REBUILDING; }
  void ClearNeedsRebuild() { mFlags = mFlags & ~UNITY_MENU_NEEDS_REBUILDING; }
  bool DoesNeedRebuild() { return !!(mFlags & UNITY_MENU_NEEDS_REBUILDING); }
  void FlushRecycleList() { mRecycleList = nullptr; }
  uMenuPopupState GetPopupState()
  {
    return static_cast<uMenuPopupState>((mFlags & UNITY_MENU_POPUP_STATE_MASK) >> 8);
  }
  void SetPopupState(uMenuPopupState aState);

  struct RecycleList
  {
  public:
    RecycleList(uGlobalMenu *aMenu);
    ~RecycleList();

    DbusmenuMenuitem* RecycleForAppend(uGlobalMenuObject *aMenuObj);
    DbusmenuMenuitem* RecycleForInsert(uGlobalMenuObject *aMenuObj,
                                       uint32_t aIndex,
                                       uint32_t *aCorrectedIndex);
    void TakeItem(DbusmenuMenuitem *aMenuObj, uint32_t aIndex);

  private:
    void Flush();
    DbusmenuMenuitem* Shift(uGlobalMenuObject *aMenuObj = nullptr);

    uint32_t mMarker;
    nsTArray<DbusmenuMenuitem *> mList;
    uGlobalMenu *mMenu;
    nsRefPtr<nsRunnableMethod<uGlobalMenu, void, false> > mFreeEvent;
  };

  nsCOMPtr<nsIContent> mPopupContent;
  nsTArray< nsRefPtr<uGlobalMenuObject> > mMenuObjects;
  nsAutoPtr<RecycleList> mRecycleList;
};

#endif
