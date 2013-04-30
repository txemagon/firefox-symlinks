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

#ifndef _U_GLOBALMENUBASE_H
#define _U_GLOBALMENUBASE_H

#include <nsIContent.h>
#include <nsCOMPtr.h>
#include <nsAutoPtr.h>
#include <imgIRequest.h>
#if MOZILLA_BRANCH_VERSION >= 19
# include <imgINotificationObserver.h>
#else
# include <imgIDecoderObserver.h>
# include <imgIContainerObserver.h>
#endif

#include <libdbusmenu-glib/server.h>

#include "uGlobalMenuDocListener.h"

#include "uDebug.h"

#define FLAG(val) (1 << val)

#define UNITY_MENUOBJECT_DESTROYED              FLAG(0)

enum uMenuObjectType {
  eMenuBar,
  eMenu,
  eMenuItem,
  eMenuSeparator,
  eMenuDummy
};

enum uMenuObjectProperties {
  eLabel = (1 << 0),
  eEnabled = (1 << 1),
  eVisible = (1 << 2),
  eIconData = (1 << 3),
  eType = (1 << 4),
  eShortcut = (1 << 5),
  eToggleType = (1 << 6),
  eToggleState = (1 << 7),
  eChildDisplay = (1 << 8)
};

enum uMenuObjectRefreshMode {
  eRefreshFull,
  eContainerOpeningRefresh
};

class uGlobalMenuObject;
class uGlobalMenuBar;
class nsIDOMCSSStyleDeclaration;

class uGlobalMenuObject
{
public:
  NS_INLINE_DECL_REFCOUNTING(uGlobalMenuObject)

  uGlobalMenuObject (): mDbusMenuItem(nullptr), mListener(nullptr),
                        mParent(nullptr), mFlags(0) { };

  DbusmenuMenuitem* GetDbusMenuItem();
  void SetDbusMenuItem(DbusmenuMenuitem *aDbusMenuItem);
  uGlobalMenuObject* GetParent() { return mParent; }
  virtual uMenuObjectType GetType()=0;
  nsIContent* GetContent() { return mContent; }
  void ContainerIsOpening();
  virtual void Destroy();
  virtual ~uGlobalMenuObject();

protected:
  void SyncLabelFromContent();
  void SyncVisibilityFromContent();
  void SyncSensitivityFromContent();
  void SyncIconFromContent();

  void SetFlags(PRUint16 aFlags) { mFlags = mFlags | aFlags; }
  void ClearFlags(PRUint16 aFlags) { mFlags = mFlags & ~aFlags; }

  void SetOrClearFlags(bool aSet, PRUint16 aFlags)
  {
    if (aSet) {
      SetFlags(aFlags);
    } else {
      ClearFlags(aFlags);
    }
  }

  bool IsDestroyed() { return !!(mFlags & UNITY_MENUOBJECT_DESTROYED); }

  uGlobalMenuBar* GetMenuBar();

  nsCOMPtr<nsIContent> mContent;
  DbusmenuMenuitem *mDbusMenuItem;
  nsRefPtr<uGlobalMenuDocListener> mListener;
  uGlobalMenuObject *mParent;

protected:
  friend class uGlobalMenuDocListener;

  virtual void ObserveAttributeChanged(nsIContent *aContent,
                                       nsIAtom *aAttribute)
  {
    NS_ERROR("Unhandled AttributeChanged notification");
  };

  virtual void ObserveContentRemoved(nsIContent *aContainer,
                                     nsIContent *aChild)
  {
    NS_ERROR("Unhandled ContentRemoved notification");
  };

  virtual void ObserveContentInserted(nsIContent *aContainer,
                                      nsIContent *aChild,
                                      nsIContent *aPrevSibling)
  {
    NS_ERROR("Unhandled ContentInserted notification");
  };

  PRUint16 mFlags;

protected:
  friend class IconLoader;

  void ClearIcon();

private:

  class IconLoader:
#if MOZILLA_BRANCH_VERSION >= 19
    public imgINotificationObserver
#else
    public imgIDecoderObserver
#endif
  {
  public:
    NS_DECL_ISUPPORTS
#if MOZILLA_BRANCH_VERSION >= 19
    NS_DECL_IMGINOTIFICATIONOBSERVER
#else
    NS_DECL_IMGIDECODEROBSERVER
    NS_DECL_IMGICONTAINEROBSERVER
#endif

    void ScheduleIconLoad();
    void LoadIcon();
    void Destroy();

    IconLoader(uGlobalMenuObject *aMenuItem): mMenuItem(aMenuItem) { };
    ~IconLoader() { };

  private:
    nsresult OnStopFrame(imgIRequest *aRequest);
    void OnStopRequest();

    bool mIconLoaded;
    uGlobalMenuObject *mMenuItem;
    nsCOMPtr<imgIRequest> mIconRequest;
    nsIntRect mImageRect;
    nsString mUriString;
  };

  virtual void InitializeDbusMenuItem() { };
  virtual void Refresh(uMenuObjectRefreshMode aMode) { };
  virtual uMenuObjectProperties GetValidProperties()
  {
    return static_cast<uMenuObjectProperties>(0);
  }
  void GetComputedStyle(nsIDOMCSSStyleDeclaration **aResult);
  bool ShouldShowIcon();
  void OnlyKeepProperties(uMenuObjectProperties aKeep);

  nsRefPtr<IconLoader> mIconLoader;
  static unsigned char sImagesInMenus;
};

#endif
