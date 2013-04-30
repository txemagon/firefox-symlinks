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

#include <nsDebug.h>
#include <nsIObserver.h>
#include <nsIWidget.h>
#include <nsIDOMWindow.h>
#include <nsIXULWindow.h>
#include <nsIInterfaceRequestorUtils.h>
#include <nsIDocShell.h>
#if MOZILLA_BRANCH_VERSION < 17
# include <nsIDOMNSEvent.h>
#endif
#include <nsIPrefBranch.h>
#include <nsIDOMKeyEvent.h>
#include <nsIDOMEventListener.h>
#include <nsICaseConversion.h>
#include <nsIContent.h>
#include <nsIDOMDocument.h>
#include <nsIDOMEventTarget.h>
#include <nsIDOMEvent.h>

#include <glib-object.h>
#include <gdk/gdkx.h>

#include "uGlobalMenuBar.h"
#include "uGlobalMenu.h"
#include "uGlobalMenuUtils.h"
#include "uGlobalMenuService.h"
#include "uWidgetAtoms.h"

#include "uDebug.h"

#define MODIFIER_SHIFT    1
#define MODIFIER_CONTROL  2
#define MODIFIER_ALT      4
#define MODIFIER_META     8

NS_IMPL_ISUPPORTS1(uGlobalMenuBar::EventListener, nsIDOMEventListener)

NS_IMETHODIMP
uGlobalMenuBar::EventListener::HandleEvent(nsIDOMEvent *aEvent)
{
  nsAutoString type;
  nsresult rv = aEvent->GetType(type);
  if (NS_FAILED(rv)) {
    NS_WARNING("Failed to determine type of event");
    return rv;
  }

  if (type.EqualsLiteral("focus")) {
    mMenuBar->Focus();
  } else if (type.EqualsLiteral("blur")) {
    mMenuBar->Blur();
  } else if (type.EqualsLiteral("keypress")) {
    rv = mMenuBar->KeyPress(aEvent);
  } else if (type.EqualsLiteral("keydown")) {
    rv = mMenuBar->KeyDown(aEvent);
  } else if (type.EqualsLiteral("keyup")) {
    rv = mMenuBar->KeyUp(aEvent);
  }

  return rv;
}

/*static*/ gboolean
uGlobalMenuBar::MapEventCallback(GtkWidget *widget,
                                 GdkEvent *event,
                                 gpointer user_data)
{
  uGlobalMenuBar *menubar = static_cast<uGlobalMenuBar *>(user_data);
  menubar->Register();

  return FALSE;
}

void
uGlobalMenuBar::Register()
{
  if (mCancellable) {
    // Registration in progress
    return;
  }

  mCancellable = g_cancellable_new();

  PRUint32 xidn = (PRUint32) GDK_WINDOW_XID(gtk_widget_get_window(mTopLevel));
  uGlobalMenuService::RegisterGlobalMenuBar(this, mCancellable, xidn, mPath);
}

uint32_t
uGlobalMenuBar::IndexOf(nsIContent *aContent)
{
  if (!aContent) {
    return -1;
  }

  for (uint32_t i = 0; i < mMenuObjects.Length(); i++) {
    if (mMenuObjects[i]->GetContent() == aContent) {
      return i;
    }
  }

  return -1;
}

bool
uGlobalMenuBar::AppendMenuObject(uGlobalMenuObject *menu)
{
  gboolean res = dbusmenu_menuitem_child_append(mDbusMenuItem,
                                                menu->GetDbusMenuItem());
  return res && mMenuObjects.AppendElement(menu);
}

bool
uGlobalMenuBar::InsertMenuObjectAfterContent(uGlobalMenuObject *menu,
                                             nsIContent *aPrevSibling)
{
  int32_t index = IndexOf(aPrevSibling);
  NS_ASSERTION(index >= 0 || !aPrevSibling, "Previous sibling not found");
  if (index < 0 && aPrevSibling) {
    return false;
  }

  index++;

  gboolean res = dbusmenu_menuitem_child_add_position(mDbusMenuItem,
                                                      menu->GetDbusMenuItem(),
                                                      index);
  return res && mMenuObjects.InsertElementAt(index, menu);
}

bool
uGlobalMenuBar::RemoveMenuObjectForContent(nsIContent *aContent)
{
  int32_t index = IndexOf(aContent);
  NS_ASSERTION(index >= 0, "Previous sibling not found");
  if (index < 0) {
    return false;
  }

  gboolean res = dbusmenu_menuitem_child_delete(mDbusMenuItem,
                                       mMenuObjects[index]->GetDbusMenuItem());
  mMenuObjects[index]->Destroy();
  mMenuObjects.RemoveElementAt(index);

  return !!res;
}

nsresult
uGlobalMenuBar::Build()
{
  PRUint32 count = mContent->GetChildCount();

  for (PRUint32 i = 0; i < count; i++) {
    nsIContent *menuContent = mContent->GetChildAt(i);

    bool failed = false;
    nsRefPtr<uGlobalMenuObject> newItem =
      uGlobalMenuUtils::CreateMenuObject(this, mListener, menuContent, &failed);

    if (newItem) {
      failed = !(AppendMenuObject(newItem));
    }

    NS_ASSERTION(!failed, "Failed to append item to menubar");
    if (failed) {
      // XXX: Is there anything else we should do here?
      return NS_ERROR_FAILURE;
    }
  }

  return NS_OK;
}

nsresult
uGlobalMenuBar::Init(nsIWidget *aWindow,
                     nsIContent *aMenuBar)
{
  NS_ENSURE_ARG(aWindow);
  NS_ENSURE_ARG(aMenuBar);

  mContent = aMenuBar;

  mTopLevel = uGlobalMenuUtils::WidgetToGTKWindow(aWindow);
  if (!GTK_IS_WINDOW(mTopLevel)) {
    return NS_ERROR_FAILURE;
  }

  g_object_ref(mTopLevel);

  mPath = NS_LITERAL_CSTRING("/com/canonical/menu/");
  char xid[10];
  sprintf(xid, "%X", (PRUint32) GDK_WINDOW_XID(gtk_widget_get_window(mTopLevel)));
  mPath.Append(xid);

  mServer = dbusmenu_server_new(mPath.get());

  GetDbusMenuItem();
  dbusmenu_server_set_root(mServer, mDbusMenuItem);

  mListener = new uGlobalMenuDocListener();

  nsresult rv = mListener->Init(mContent);
  if (NS_FAILED(rv)) {
    NS_ERROR("Failed to initialize doc listener");
    return rv;
  }

  rv = Build();
  if (NS_FAILED(rv)) {
    NS_ERROR("Failed to build menubar");
    return rv;
  }

  mEventListener = new EventListener(this);

  mDocument = mContent->OwnerDoc();
  NS_ASSERTION(mDocument, "Menubar has no owner document!");
  if (!mDocument) {
    return NS_ERROR_FAILURE;
  }

  nsCOMPtr<nsIDOMEventTarget> docTarget = do_QueryInterface(mDocument);
  NS_ASSERTION(docTarget, "Document failed QI to nsIDOMEventTarget");
  if (!docTarget) {
    return NS_ERROR_FAILURE;
  }

  docTarget->AddEventListener(NS_LITERAL_STRING("focus"),
                              mEventListener,
                              true);
  docTarget->AddEventListener(NS_LITERAL_STRING("blur"),
                              mEventListener,
                              true);
  docTarget->AddEventListener(NS_LITERAL_STRING("keypress"),
                              mEventListener,
                              false);
  docTarget->AddEventListener(NS_LITERAL_STRING("keydown"),
                              mEventListener,
                              false);
  docTarget->AddEventListener(NS_LITERAL_STRING("keyup"),
                              mEventListener,
                              false);

  nsIPrefBranch *prefs = uGlobalMenuService::GetPrefService();
  NS_ASSERTION(prefs, "Failed to get pref service");
  if (!prefs) {
    return NS_ERROR_FAILURE;
  }

  prefs->GetIntPref("ui.key.menuAccessKey", &mAccessKey);
  if (mAccessKey == nsIDOMKeyEvent::DOM_VK_SHIFT) {
    mAccessKeyMask = MODIFIER_SHIFT;
  } else if (mAccessKey == nsIDOMKeyEvent::DOM_VK_CONTROL) {
    mAccessKeyMask = MODIFIER_CONTROL;
  } else if (mAccessKey == nsIDOMKeyEvent::DOM_VK_ALT) {
    mAccessKeyMask = MODIFIER_ALT;
  } else if (mAccessKey == nsIDOMKeyEvent::DOM_VK_META) {
    mAccessKeyMask = MODIFIER_META;
  } else {
    mAccessKeyMask = MODIFIER_ALT;
  }

  /* Do this before registering for content changes, so that we
   * don't handle the subsequent event */
  nsCOMPtr<nsIDOMElement> self = do_QueryInterface(mContent);
  NS_ASSERTION(self, "Content failed QI to nsIDOMElement");
  if (!self) {
    return NS_ERROR_FAILURE;
  }

  self->SetAttribute(NS_LITERAL_STRING("openedwithkey"),
                     NS_LITERAL_STRING("false"));

  mListener->RegisterForContentChanges(mContent, this);

  // Unity forgets our window if it is unmapped by the application, which
  // happens with some extensions that add "minimize to tray" type
  // functionality. We hook on to the MapNotify event to re-register our menu
  // with Unity
  g_signal_connect(G_OBJECT(mTopLevel), "map-event",
                   G_CALLBACK(MapEventCallback), this);

  if (gtk_widget_get_mapped(mTopLevel)) {
    Register();
  }

  nsCOMPtr<nsIDOMDocument> domDoc = do_QueryInterface(mDocument);
  NS_ASSERTION(domDoc, "Document failed QI to nsIDOMDocument");
  if (!domDoc) {
    return NS_ERROR_FAILURE;
  }

  nsCOMPtr<nsIDOMElement> windowElem;
  domDoc->GetDocumentElement(getter_AddRefs(windowElem));
  NS_ASSERTION(windowElem, "Document has no documentElement");
  if (!windowElem) {
    return NS_ERROR_FAILURE;
  }

  return windowElem->SetAttribute(NS_LITERAL_STRING("shellshowingmenubar"),
                                  NS_LITERAL_STRING("true"));
}

PRUint32
uGlobalMenuBar::GetModifiersFromEvent(nsIDOMKeyEvent *aKeyEvent)
{
  PRUint32 modifiers = 0;
  bool modifier;

  aKeyEvent->GetAltKey(&modifier);
  if (modifier) {
    modifiers |= MODIFIER_ALT;
  }

  aKeyEvent->GetShiftKey(&modifier);
  if (modifier) {
    modifiers |= MODIFIER_SHIFT;
  }

  aKeyEvent->GetCtrlKey(&modifier);
  if (modifier) {
    modifiers |= MODIFIER_CONTROL;
  }

  aKeyEvent->GetMetaKey(&modifier);
  if (modifier) {
    modifiers |= MODIFIER_META;
  }

  return modifiers;
}

uGlobalMenuBar::uGlobalMenuBar():
  uGlobalMenuObject(), mServer(nullptr), mTopLevel(nullptr),
  mCancellable(nullptr)
{
  MOZ_COUNT_CTOR(uGlobalMenuBar);
}

uGlobalMenuBar::~uGlobalMenuBar()
{
  TRACETM();

  if (!IsDestroyed()) {
    Destroy();
  }

  MOZ_COUNT_DTOR(uGlobalMenuBar);
}

/*static*/ uGlobalMenuBar*
uGlobalMenuBar::Create(nsIWidget *aWindow,
                       nsIContent *aMenuBar)
{
  TRACEC(aMenuBar);

  uGlobalMenuBar *menubar = new uGlobalMenuBar();
  if (!menubar) {
    return nullptr;
  }

  if (NS_FAILED(menubar->Init(aWindow, aMenuBar))) {
    delete menubar;
    return nullptr;
  }

  return menubar;
}

void
uGlobalMenuBar::Destroy()
{
  TRACETM();

  NS_ASSERTION(!IsDestroyed(), "Menubar is already destroyed");
  if (IsDestroyed()) {
    return;
  }

  if (mTopLevel) {
    g_signal_handlers_disconnect_by_func(mTopLevel,
                                         uGlobalMenuUtils::FuncToVoidPtr(MapEventCallback),
                                         this);
  }

  if (mCancellable) {
    g_cancellable_cancel(mCancellable);
    g_object_unref(mCancellable);
    mCancellable = nullptr;
  }

  if (mDocument) {
    nsCOMPtr<nsIDOMDocument> domDoc = do_QueryInterface(mDocument);
    if (domDoc) {
      nsCOMPtr<nsIDOMElement> windowElem;
      domDoc->GetDocumentElement(getter_AddRefs(windowElem));
      if (windowElem) {
        windowElem->SetAttribute(NS_LITERAL_STRING("shellshowingmenubar"),
                                 NS_LITERAL_STRING("false"));
      }
    }

    nsCOMPtr<nsIDOMEventTarget> docTarget = do_QueryInterface(mDocument);
    if (docTarget) {
      docTarget->RemoveEventListener(NS_LITERAL_STRING("focus"),
                                     mEventListener,
                                     true);
      docTarget->RemoveEventListener(NS_LITERAL_STRING("blur"),
                                     mEventListener,
                                     true);
      docTarget->RemoveEventListener(NS_LITERAL_STRING("keypress"),
                                     mEventListener,
                                     false);
      docTarget->RemoveEventListener(NS_LITERAL_STRING("keydown"),
                                     mEventListener,
                                     false);
      docTarget->RemoveEventListener(NS_LITERAL_STRING("keyup"),
                                     mEventListener,
                                     false);
    }
  }

  if (mTopLevel) {
    g_object_unref(mTopLevel);
    mTopLevel = nullptr;
  }

  if (mServer) {
    g_object_unref(mServer);
    mServer = nullptr;
  }

  if (mListener) {
    mListener->Destroy();
  }

  uGlobalMenuObject::Destroy();
}

void
uGlobalMenuBar::Blur()
{
  dbusmenu_server_set_status(mServer, DBUSMENU_STATUS_NORMAL);
}

void
uGlobalMenuBar::Focus()
{
  nsCOMPtr<nsIDOMElement> self = do_QueryInterface(mContent);
#if DEBUG_GLOBALMENU >= 2
  nsAutoString old;
  self->GetAttribute(NS_LITERAL_STRING("openedwithkey"), old);
  if (old.Equals(NS_LITERAL_STRING("true"))) {
    LOG("Received focus - unsetting \"openedwithkey\"");
  }
#endif
  self->SetAttribute(NS_LITERAL_STRING("openedwithkey"),
                     NS_LITERAL_STRING("false"));
}

bool
uGlobalMenuBar::ShouldHandleKeyEvent(nsIDOMEvent *aKeyEvent)
{
#if MOZILLA_BRANCH_VERSION < 17
  nsCOMPtr<nsIDOMNSEvent> event = do_QueryInterface(aKeyEvent);
  if (!event) {
    return false;
  }
#else
  nsIDOMEvent *event = aKeyEvent;
#endif

  bool handled, trusted;
  event->GetPreventDefault(&handled);
  event->GetIsTrusted(&trusted);

  if (handled || !trusted) {
    return false;
  }

  return true;
}

nsresult
uGlobalMenuBar::KeyDown(nsIDOMEvent *aKeyEvent)
{
  if (!ShouldHandleKeyEvent(aKeyEvent)) {
    return NS_OK;
  }

  nsCOMPtr<nsIDOMKeyEvent> keyEvent = do_QueryInterface(aKeyEvent);
  if (keyEvent) {
    PRUint32 keyCode;
    keyEvent->GetKeyCode(&keyCode);
    PRUint32 modifiers = GetModifiersFromEvent(keyEvent);
    if ((keyCode == static_cast<PRUint32>(mAccessKey)) &&
        ((modifiers & ~mAccessKeyMask) == 0)) {
      dbusmenu_server_set_status(mServer, DBUSMENU_STATUS_NOTICE);
    }
  }

  return NS_OK;
}

nsresult
uGlobalMenuBar::KeyUp(nsIDOMEvent *aKeyEvent)
{
  if (!ShouldHandleKeyEvent(aKeyEvent)) {
    return NS_OK;
  }

  nsCOMPtr<nsIDOMKeyEvent> keyEvent = do_QueryInterface(aKeyEvent);
  if (keyEvent) {
    PRUint32 keyCode;
    keyEvent->GetKeyCode(&keyCode);
    if (keyCode == static_cast<PRUint32>(mAccessKey)) {
      dbusmenu_server_set_status(mServer, DBUSMENU_STATUS_NORMAL);
    }
  }

  return NS_OK;
}

nsresult
uGlobalMenuBar::KeyPress(nsIDOMEvent *aKeyEvent)
{
  if (!ShouldHandleKeyEvent(aKeyEvent)) {
    return NS_OK;
  }

  nsCOMPtr<nsIDOMKeyEvent> keyEvent = do_QueryInterface(aKeyEvent);
  uGlobalMenuObject *found = nullptr;

  if (keyEvent) {
    PRUint32 keyCode;
    keyEvent->GetKeyCode(&keyCode);
    PRUint32 count = mMenuObjects.Length();
    PRUint32 modifiers = GetModifiersFromEvent(keyEvent);
    if ((modifiers & mAccessKeyMask) && ((modifiers & ~mAccessKeyMask) == 0)) {
      // The menu access modifier is pressed
      PRUint32 charCode;
      keyEvent->GetCharCode(&charCode);
      if (charCode != 0) {
        PRUnichar ch = PRUnichar(charCode);

        nsICaseConversion *converter= uGlobalMenuService::GetCaseConverter();

        PRUnichar chu;
        PRUnichar chl;
        if (converter) {
          converter->ToUpper(ch, &chu);
          converter->ToLower(ch, &chl);
        } else {
          NS_WARNING("No case converter");
          chu = ch;
          chl = ch;
        }

        for (PRUint32 i = 0; i < count; i++) {
          nsIContent *content = mMenuObjects[i]->GetContent();
          if (content) {
            nsAutoString accessKey;
            content->GetAttr(kNameSpaceID_None, uWidgetAtoms::accesskey,
                             accessKey);
            const PRUnichar *key = accessKey.BeginReading();
            if (*key == chl || *key == chu) {
              found = mMenuObjects[i];
              break;
            }
          }
        }
      }
    } else if (keyCode == nsIDOMKeyEvent::DOM_VK_F10) {
      // Go through each mMenuObject, and find the first one
      // that is both visible and sensitive, and mark it found
      // for opening.
      for (PRUint32 i = 0; i < count; i++) {
        uGlobalMenu *menu = static_cast<uGlobalMenu *>((uGlobalMenuObject *)mMenuObjects[i]);
        if (menu->CanOpen()) {
          found = mMenuObjects[i];
          break;
        }
      }
    }
  }

  if (found) {
    nsCOMPtr<nsIDOMElement> self = do_QueryInterface(mContent);
    self->SetAttribute(NS_LITERAL_STRING("openedwithkey"),
                       NS_LITERAL_STRING("true"));
    uGlobalMenu *menu = static_cast<uGlobalMenu *>(found);
    menu->OpenMenuDelayed();
    aKeyEvent->StopPropagation();
    aKeyEvent->PreventDefault();
  }

  return NS_OK;
}

void
uGlobalMenuBar::NotifyMenuBarRegistered()
{
  g_object_unref(mCancellable);
  mCancellable = nullptr;

  SetFlags(UNITY_MENUBAR_IS_REGISTERED);
}

void
uGlobalMenuBar::ObserveAttributeChanged(nsIContent *aContent,
                                        nsIAtom *aAttribute)
{

}

void
uGlobalMenuBar::ObserveContentRemoved(nsIContent *aContainer,
                                      nsIContent *aChild)
{
  TRACETM();
  NS_ASSERTION(aContainer == mContent,
               "Received an event that wasn't meant for us!");

  RemoveMenuObjectForContent(aChild);
}

void
uGlobalMenuBar::ObserveContentInserted(nsIContent *aContainer,
                                       nsIContent *aChild,
                                       nsIContent *aPrevSibling)
{
  TRACETM();
  NS_ASSERTION(aContainer == mContent,
               "Received an event that wasn't meant for us!");

  aPrevSibling = uGlobalMenuUtils::GetPreviousSupportedSibling(aPrevSibling);

  bool failed = false;
  nsRefPtr<uGlobalMenuObject> newItem =
    uGlobalMenuUtils::CreateMenuObject(this, mListener, aChild, &failed);

  if (newItem) {
    failed = !(InsertMenuObjectAfterContent(newItem, aPrevSibling));
  }

  NS_ASSERTION(!failed, "Failed to insert item in to menubar");
}
