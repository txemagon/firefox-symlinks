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

#ifndef _U_GLOBALMENUSERVICE_H
#define _U_GLOBALMENUSERVICE_H

#include <prtypes.h>
#include <nsTArray.h>
#include <nsCOMPtr.h>
#include <nsIWindowMediatorListener.h>
#include <nsIWindowMediator.h>

#include <glib.h>
#include <gio/gio.h>

#include "uGlobalMenuBar.h"
#include "uIGlobalMenuService.h"

#define U_GLOBALMENUSERVICE_CID \
{ 0xa9e41684, 0xbf71, 0x46e3, { 0x93, 0xbf, 0x3c, 0xda, 0x1e, 0xc6, 0x16, 0x49 } }

#define U_GLOBALMENUSERVICE_CONTRACTID "@canonical.com/globalmenu-service;1"

class nsIWidget;
class nsICaseConversion;
class imgILoader;
class nsIImageToPixbuf;
class nsIPrefBranch;
class nsIXBLService;
class nsIXPConnect;
class nsIAtomService;

class uGlobalMenuService: public uIGlobalMenuService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_UIGLOBALMENUSERVICE

  uGlobalMenuService() : mOnline(false),
                         mDbusProxy(NULL),
                         mCancellable(NULL) { };
  nsresult Init();

  ~uGlobalMenuService();

  static uGlobalMenuService* GetInstance();

  static void Shutdown();

  static bool RegisterGlobalMenuBar(uGlobalMenuBar *aMenuBar,
                                    GCancellable *aCancellable,
                                    PRUint32 aXID, nsACString& aPath);

#define SERVICE(Name, Interface, CID) \
  static Interface* Get##Name();
#include "uGlobalMenuServiceList.h"
#undef SERVICE

private:
  friend class Listener;

  class Listener: public nsIWindowMediatorListener
  {
  public:
    NS_DECL_ISUPPORTS
    NS_DECL_NSIWINDOWMEDIATORLISTENER

    Listener() { };
    virtual ~Listener() { };

    nsresult Init();
    void Destroy();
  };

  static bool InitService();
  void SetOnline(bool aOnline);
  static void ProxyCreatedCallback(GObject *object,
                                   GAsyncResult *res,
                                   gpointer userdata);
  static void NameOwnerChangedCallback(GObject *object,
                                       GParamSpec *pspec,
                                       gpointer userdata);
  static void RegisterWindowCallback(GObject *object,
                                     GAsyncResult *res,
                                     gpointer userdata);
  bool WidgetHasGlobalMenu(nsIWidget *aWidget);
  void DestroyMenus();
  void DestroyMenuForWidget(nsIWidget *aWidget);

  static uGlobalMenuService *sService;
#define SERVICE(Name, Interface, CID) \
  static Interface *s##Name;
#include "uGlobalMenuServiceList.h"
#undef SERVICE
  static bool sShutdown;

  bool mOnline;
  GDBusProxy *mDbusProxy;
  GCancellable *mCancellable;
  nsTArray<nsRefPtr<uGlobalMenuBar> > mMenus;
  nsTArray<nsCOMPtr<uIGlobalMenuServiceObserver> > mListeners;
  nsRefPtr<Listener> mWMListener;
};

#endif
