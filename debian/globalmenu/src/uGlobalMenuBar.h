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

#ifndef _U_GLOBALMENUBAR_H
#define _U_GLOBALMENUBAR_H

#include <prtypes.h>
#include <nsTArray.h>
#include <nsAutoPtr.h>
#include <nsStringGlue.h>
#include <nsIDOMEventListener.h>
#include <nsIDocument.h>

#include <libdbusmenu-glib/server.h>
#include <gio/gio.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include "uGlobalMenuObject.h"

// The menubar has been registered with the shell
#define UNITY_MENUBAR_IS_REGISTERED           FLAG(8)

// Meh. X.h defines this
#ifdef KeyPress
# undef KeyPress
#endif

class nsIObserver;
class nsIWidget;
class nsIDOMEvent;
class uGlobalMenuService;
class uGlobalMenu;
class uGlobalMenuBar;
class nsIDOMKeyEvent;
class nsIContent;

class uGlobalMenuBar: public uGlobalMenuObject
{
public:
  static uGlobalMenuBar* Create(nsIWidget *aWindow,
                                nsIContent *aMenuBar);
  virtual void Destroy();
  virtual ~uGlobalMenuBar();

  virtual uMenuObjectType GetType() { return eMenuBar; }

  bool IsRegistered() { return !!(mFlags & UNITY_MENUBAR_IS_REGISTERED); }

  GtkWidget* TopLevelWindow() { return mTopLevel; }

protected:
  virtual void ObserveAttributeChanged(nsIContent *aContent,
                                       nsIAtom *aAttribute);
  virtual void ObserveContentRemoved(nsIContent *aContainer,
                                     nsIContent *aChild);
  virtual void ObserveContentInserted(nsIContent *aContainer,
                                      nsIContent *aChild,
                                      nsIContent *aPrevSibling);

protected:
  friend class uGlobalMenuService;

  void NotifyMenuBarRegistered();

private:

  class EventListener: public nsIDOMEventListener
  {
  public:
    NS_DECL_ISUPPORTS
    NS_DECL_NSIDOMEVENTLISTENER

    EventListener(uGlobalMenuBar *aMenuBar): mMenuBar(aMenuBar) { };
    virtual ~EventListener() { };

  private:
    uGlobalMenuBar *mMenuBar;
  };

  uGlobalMenuBar();
  // Initialize the menu structure
  nsresult Init(nsIWidget *aWindow,
                nsIContent *aMenuBar);

  nsresult Build();
  PRUint32 GetModifiersFromEvent(nsIDOMKeyEvent *aKeyEvent);
  bool ShouldHandleKeyEvent(nsIDOMEvent *aKeyEvent);

  uint32_t IndexOf(nsIContent *aContent);
  bool RemoveMenuObjectForContent(nsIContent *aContent);
  bool InsertMenuObjectAfterContent(uGlobalMenuObject *menu,
                                    nsIContent *aPrevSibling);
  bool AppendMenuObject(uGlobalMenuObject *menu);
  void Focus();
  void Blur();
  nsresult KeyPress(nsIDOMEvent *aKeyEvent);
  nsresult KeyUp(nsIDOMEvent *aKeyEvent);
  nsresult KeyDown(nsIDOMEvent *aKeyEvent);
  void Register();
  static gboolean MapEventCallback(GtkWidget *widget,
                                   GdkEvent *event,
                                   gpointer user_data);

  DbusmenuServer *mServer;
  GtkWidget *mTopLevel;

  nsCOMPtr<nsIDocument> mDocument;
  bool mXULMenuHidden;
  nsRefPtr<EventListener> mEventListener;
  PRInt32 mAccessKey;
  PRUint32 mAccessKeyMask;
  GCancellable *mCancellable;
  nsCString mPath;

  // Should probably have a container class and subclass that
  nsTArray< nsRefPtr<uGlobalMenuObject> > mMenuObjects;
};

#endif
