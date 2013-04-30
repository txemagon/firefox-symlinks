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

#include <nsIWindowMediatorListener.h>
#include <nsIWebProgressListener.h>
#include <nsWeakReference.h>

#include "uIGlobalMenuService.h"

#define U_GLOBALMENULOADER_CID \
{ 0x1e8f2f48, 0xe0a8, 0x4649, { 0x98, 0xef, 0x13, 0x22, 0xc0, 0x3f, 0xf0, 0x8e } }

#define U_GLOBALMENULOADER_CONTRACTID "@canonical.com/globalmenu-loader;1"

class nsIXULWindow;
class nsIDocShell;
class nsIWidget;

class uGlobalMenuLoader: public nsIWebProgressListener,
                         public nsSupportsWeakReference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBPROGRESSLISTENER

  uGlobalMenuLoader() { };
  virtual ~uGlobalMenuLoader();
  nsresult Init();

private:
  friend class Listener;

  class Listener: public uIGlobalMenuServiceObserver,
                  public nsIWindowMediatorListener
  {
  public:
    NS_DECL_ISUPPORTS
    NS_DECL_UIGLOBALMENUSERVICEOBSERVER
    NS_DECL_NSIWINDOWMEDIATORLISTENER

    Listener(uGlobalMenuLoader *aLoader): mLoader(aLoader) { };
    virtual ~Listener() { };

    nsresult Init();
    void Destroy();

  private:
    uGlobalMenuLoader *mLoader;
  };

  void RegisterAllMenus();
  bool RegisterMenuFromDS(nsIDocShell *aDocShell);

  nsRefPtr<Listener> mListener;
};
