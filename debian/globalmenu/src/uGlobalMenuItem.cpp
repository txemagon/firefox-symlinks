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
#include <nsIDocument.h>
#include <nsIAtom.h>
#include <nsIPrefBranch2.h>
#include <nsIDOMKeyEvent.h>
#include <nsCOMPtr.h>
#include <nsIDOMXULCommandEvent.h>
#include <nsPIDOMWindow.h>
#include <nsIDOMWindow.h>
#include <nsIDOMDocument.h>
#include <nsIDOMElement.h>
#include <nsIPrivateDOMEvent.h>
#include <nsIDOMEventTarget.h>
#include <nsIContent.h>

#include <glib-object.h>
#include <gdk/gdk.h>
#include <gdk/gdkkeysyms.h>
#include <gdk/gdkx.h>
#include <libdbusmenu-gtk/menuitem.h>

#include "uGlobalMenuService.h"
#include "uGlobalMenuItem.h"
#include "uGlobalMenuBar.h"
#include "uGlobalMenuUtils.h"
#include "uGlobalMenu.h"
#include "uWidgetAtoms.h"

#include "uDebug.h"

// XXX: Borrowed from content/xbl/src/nsXBLPrototypeHandler.cpp. This doesn't
// seem to be publicly available, and we need a way to map key names
// to key codes (so we can then map them to GDK key codes)

struct keyCodeData {
  const char* str;
  size_t strlength;
  PRUint32 keycode;
};

// All of these must be uppercase, since the function below does
// case-insensitive comparison by converting to uppercase.
// XXX: be sure to check this periodically for new symbol additions!
static struct keyCodeData gKeyCodes[] = {

#define KEYCODE_ENTRY(str) {#str, sizeof(#str) - 1, nsIDOMKeyEvent::DOM_##str}
#define KEYCODE_ENTRY2(str, code) {str, sizeof(str) - 1, code}

  KEYCODE_ENTRY(VK_CANCEL),
  KEYCODE_ENTRY2("VK_BACK", nsIDOMKeyEvent::DOM_VK_BACK_SPACE),
  KEYCODE_ENTRY(VK_TAB),
  KEYCODE_ENTRY(VK_CLEAR),
  KEYCODE_ENTRY(VK_RETURN),
  KEYCODE_ENTRY(VK_ENTER),
  KEYCODE_ENTRY(VK_SHIFT),
  KEYCODE_ENTRY(VK_CONTROL),
  KEYCODE_ENTRY(VK_ALT),
  KEYCODE_ENTRY(VK_PAUSE),
  KEYCODE_ENTRY(VK_CAPS_LOCK),
  KEYCODE_ENTRY(VK_ESCAPE),
  KEYCODE_ENTRY(VK_SPACE),
  KEYCODE_ENTRY(VK_PAGE_UP),
  KEYCODE_ENTRY(VK_PAGE_DOWN),
  KEYCODE_ENTRY(VK_END),
  KEYCODE_ENTRY(VK_HOME),
  KEYCODE_ENTRY(VK_LEFT),
  KEYCODE_ENTRY(VK_UP),
  KEYCODE_ENTRY(VK_RIGHT),
  KEYCODE_ENTRY(VK_DOWN),
  KEYCODE_ENTRY(VK_PRINTSCREEN),
  KEYCODE_ENTRY(VK_INSERT),
  KEYCODE_ENTRY(VK_HELP),
  KEYCODE_ENTRY(VK_DELETE),
  KEYCODE_ENTRY(VK_0),
  KEYCODE_ENTRY(VK_1),
  KEYCODE_ENTRY(VK_2),
  KEYCODE_ENTRY(VK_3),
  KEYCODE_ENTRY(VK_4),
  KEYCODE_ENTRY(VK_5),
  KEYCODE_ENTRY(VK_6),
  KEYCODE_ENTRY(VK_7),
  KEYCODE_ENTRY(VK_8),
  KEYCODE_ENTRY(VK_9),
  KEYCODE_ENTRY(VK_SEMICOLON),
  KEYCODE_ENTRY(VK_EQUALS),
  KEYCODE_ENTRY(VK_A),
  KEYCODE_ENTRY(VK_B),
  KEYCODE_ENTRY(VK_C),
  KEYCODE_ENTRY(VK_D),
  KEYCODE_ENTRY(VK_E),
  KEYCODE_ENTRY(VK_F),
  KEYCODE_ENTRY(VK_G),
  KEYCODE_ENTRY(VK_H),
  KEYCODE_ENTRY(VK_I),
  KEYCODE_ENTRY(VK_J),
  KEYCODE_ENTRY(VK_K),
  KEYCODE_ENTRY(VK_L),
  KEYCODE_ENTRY(VK_M),
  KEYCODE_ENTRY(VK_N),
  KEYCODE_ENTRY(VK_O),
  KEYCODE_ENTRY(VK_P),
  KEYCODE_ENTRY(VK_Q),
  KEYCODE_ENTRY(VK_R),
  KEYCODE_ENTRY(VK_S),
  KEYCODE_ENTRY(VK_T),
  KEYCODE_ENTRY(VK_U),
  KEYCODE_ENTRY(VK_V),
  KEYCODE_ENTRY(VK_W),
  KEYCODE_ENTRY(VK_X),
  KEYCODE_ENTRY(VK_Y),
  KEYCODE_ENTRY(VK_Z),
  KEYCODE_ENTRY(VK_NUMPAD0),
  KEYCODE_ENTRY(VK_NUMPAD1),
  KEYCODE_ENTRY(VK_NUMPAD2),
  KEYCODE_ENTRY(VK_NUMPAD3),
  KEYCODE_ENTRY(VK_NUMPAD4),
  KEYCODE_ENTRY(VK_NUMPAD5),
  KEYCODE_ENTRY(VK_NUMPAD6),
  KEYCODE_ENTRY(VK_NUMPAD7),
  KEYCODE_ENTRY(VK_NUMPAD8),
  KEYCODE_ENTRY(VK_NUMPAD9),
  KEYCODE_ENTRY(VK_MULTIPLY),
  KEYCODE_ENTRY(VK_ADD),
  KEYCODE_ENTRY(VK_SEPARATOR),
  KEYCODE_ENTRY(VK_SUBTRACT),
  KEYCODE_ENTRY(VK_DECIMAL),
  KEYCODE_ENTRY(VK_DIVIDE),
  KEYCODE_ENTRY(VK_F1),
  KEYCODE_ENTRY(VK_F2),
  KEYCODE_ENTRY(VK_F3),
  KEYCODE_ENTRY(VK_F4),
  KEYCODE_ENTRY(VK_F5),
  KEYCODE_ENTRY(VK_F6),
  KEYCODE_ENTRY(VK_F7),
  KEYCODE_ENTRY(VK_F8),
  KEYCODE_ENTRY(VK_F9),
  KEYCODE_ENTRY(VK_F10),
  KEYCODE_ENTRY(VK_F11),
  KEYCODE_ENTRY(VK_F12),
  KEYCODE_ENTRY(VK_F13),
  KEYCODE_ENTRY(VK_F14),
  KEYCODE_ENTRY(VK_F15),
  KEYCODE_ENTRY(VK_F16),
  KEYCODE_ENTRY(VK_F17),
  KEYCODE_ENTRY(VK_F18),
  KEYCODE_ENTRY(VK_F19),
  KEYCODE_ENTRY(VK_F20),
  KEYCODE_ENTRY(VK_F21),
  KEYCODE_ENTRY(VK_F22),
  KEYCODE_ENTRY(VK_F23),
  KEYCODE_ENTRY(VK_F24),
  KEYCODE_ENTRY(VK_NUM_LOCK),
  KEYCODE_ENTRY(VK_SCROLL_LOCK),
  KEYCODE_ENTRY(VK_COMMA),
  KEYCODE_ENTRY(VK_PERIOD),
  KEYCODE_ENTRY(VK_SLASH),
  KEYCODE_ENTRY(VK_BACK_QUOTE),
  KEYCODE_ENTRY(VK_OPEN_BRACKET),
  KEYCODE_ENTRY(VK_BACK_SLASH),
  KEYCODE_ENTRY(VK_CLOSE_BRACKET),
  KEYCODE_ENTRY(VK_QUOTE)

#undef KEYCODE_ENTRY
#undef KEYCODE_ENTRY2
};

PRUint32
uGlobalMenuItem::GetKeyCode(nsAString &aKeyName)
{
  nsAutoCString keyName;
  CopyUTF16toUTF8(aKeyName, keyName);
  ToUpperCase(keyName); // We want case-insensitive comparison with data
                        // stored as uppercase.

  PRUint32 keyNameLength = keyName.Length();
  const char* keyNameStr = keyName.get();
  for (PRUint16 i = 0; i < (sizeof(gKeyCodes) / sizeof(gKeyCodes[0])); ++i)
    if (keyNameLength == gKeyCodes[i].strlength &&
        !strcmp(gKeyCodes[i].str, keyNameStr))
      return gKeyCodes[i].keycode;

  return 0;
}

// XXX: Borrowed from widget/src/gtk2/nsGtkKeyUtils.cpp
struct nsKeyConverter {
    int vkCode; // Platform independent key code
    int keysym; // GDK keysym key code
};

//
// Netscape keycodes are defined in widget/public/nsGUIEvent.h
// GTK keycodes are defined in <gdk/gdkkeysyms.h>
//
static struct nsKeyConverter nsKeycodes[] = {
    { nsIDOMKeyEvent::DOM_VK_CANCEL,     GDK_Cancel },
    { nsIDOMKeyEvent::DOM_VK_BACK_SPACE, GDK_BackSpace },
    { nsIDOMKeyEvent::DOM_VK_TAB,        GDK_Tab },
    { nsIDOMKeyEvent::DOM_VK_TAB,        GDK_ISO_Left_Tab },
    { nsIDOMKeyEvent::DOM_VK_CLEAR,      GDK_Clear },
    { nsIDOMKeyEvent::DOM_VK_RETURN,     GDK_Return },
    { nsIDOMKeyEvent::DOM_VK_SHIFT,      GDK_Shift_L },
    { nsIDOMKeyEvent::DOM_VK_SHIFT,      GDK_Shift_R },
    { nsIDOMKeyEvent::DOM_VK_CONTROL,    GDK_Control_L },
    { nsIDOMKeyEvent::DOM_VK_CONTROL,    GDK_Control_R },
    { nsIDOMKeyEvent::DOM_VK_ALT,        GDK_Alt_L },
    { nsIDOMKeyEvent::DOM_VK_ALT,        GDK_Alt_R },
    { nsIDOMKeyEvent::DOM_VK_META,       GDK_Meta_L },
    { nsIDOMKeyEvent::DOM_VK_META,       GDK_Meta_R },
    { nsIDOMKeyEvent::DOM_VK_PAUSE,      GDK_Pause },
    { nsIDOMKeyEvent::DOM_VK_CAPS_LOCK,  GDK_Caps_Lock },
    { nsIDOMKeyEvent::DOM_VK_KANA,       GDK_Kana_Lock },
    { nsIDOMKeyEvent::DOM_VK_KANA,       GDK_Kana_Shift },
    { nsIDOMKeyEvent::DOM_VK_HANGUL,     GDK_Hangul },
    // { nsIDOMKeyEvent::DOM_VK_JUNJA,      GDK_XXX },
    // { nsIDOMKeyEvent::DOM_VK_FINAL,      GDK_XXX },
    { nsIDOMKeyEvent::DOM_VK_HANJA,      GDK_Hangul_Hanja },
    { nsIDOMKeyEvent::DOM_VK_KANJI,      GDK_Kanji },
    { nsIDOMKeyEvent::DOM_VK_ESCAPE,     GDK_Escape },
    { nsIDOMKeyEvent::DOM_VK_CONVERT,    GDK_Henkan },
    { nsIDOMKeyEvent::DOM_VK_NONCONVERT, GDK_Muhenkan },
    // { nsIDOMKeyEvent::DOM_VK_ACCEPT,     GDK_XXX },
    { nsIDOMKeyEvent::DOM_VK_MODECHANGE, GDK_Mode_switch },
    { nsIDOMKeyEvent::DOM_VK_SPACE,      GDK_space },
    { nsIDOMKeyEvent::DOM_VK_PAGE_UP,    GDK_Page_Up },
    { nsIDOMKeyEvent::DOM_VK_PAGE_DOWN,  GDK_Page_Down },
    { nsIDOMKeyEvent::DOM_VK_END,        GDK_End },
    { nsIDOMKeyEvent::DOM_VK_HOME,       GDK_Home },
    { nsIDOMKeyEvent::DOM_VK_LEFT,       GDK_Left },
    { nsIDOMKeyEvent::DOM_VK_UP,         GDK_Up },
    { nsIDOMKeyEvent::DOM_VK_RIGHT,      GDK_Right },
    { nsIDOMKeyEvent::DOM_VK_DOWN,       GDK_Down },
    { nsIDOMKeyEvent::DOM_VK_SELECT,     GDK_Select },
    { nsIDOMKeyEvent::DOM_VK_PRINT,      GDK_Print },
    { nsIDOMKeyEvent::DOM_VK_EXECUTE,    GDK_Execute },
    { nsIDOMKeyEvent::DOM_VK_PRINTSCREEN, GDK_Print },
    { nsIDOMKeyEvent::DOM_VK_INSERT,     GDK_Insert },
    { nsIDOMKeyEvent::DOM_VK_DELETE,     GDK_Delete },
    { nsIDOMKeyEvent::DOM_VK_HELP,       GDK_Help },

    // keypad keys
    { nsIDOMKeyEvent::DOM_VK_LEFT,       GDK_KP_Left },
    { nsIDOMKeyEvent::DOM_VK_RIGHT,      GDK_KP_Right },
    { nsIDOMKeyEvent::DOM_VK_UP,         GDK_KP_Up },
    { nsIDOMKeyEvent::DOM_VK_DOWN,       GDK_KP_Down },
    { nsIDOMKeyEvent::DOM_VK_PAGE_UP,    GDK_KP_Page_Up },
    // Not sure what these are
    //{ nsIDOMKeyEvent::DOM_VK_,       GDK_KP_Prior },
    //{ nsIDOMKeyEvent::DOM_VK_,        GDK_KP_Next },
    // GDK_KP_Begin is the 5 on the non-numlock keypad
    //{ nsIDOMKeyEvent::DOM_VK_,        GDK_KP_Begin },
    { nsIDOMKeyEvent::DOM_VK_PAGE_DOWN,  GDK_KP_Page_Down },
    { nsIDOMKeyEvent::DOM_VK_HOME,       GDK_KP_Home },
    { nsIDOMKeyEvent::DOM_VK_END,        GDK_KP_End },
    { nsIDOMKeyEvent::DOM_VK_INSERT,     GDK_KP_Insert },
    { nsIDOMKeyEvent::DOM_VK_DELETE,     GDK_KP_Delete },

    { nsIDOMKeyEvent::DOM_VK_MULTIPLY,   GDK_KP_Multiply },
    { nsIDOMKeyEvent::DOM_VK_ADD,        GDK_KP_Add },
    { nsIDOMKeyEvent::DOM_VK_SEPARATOR,  GDK_KP_Separator },
    { nsIDOMKeyEvent::DOM_VK_SUBTRACT,   GDK_KP_Subtract },
    { nsIDOMKeyEvent::DOM_VK_DECIMAL,    GDK_KP_Decimal },
    { nsIDOMKeyEvent::DOM_VK_DIVIDE,     GDK_KP_Divide },
    { nsIDOMKeyEvent::DOM_VK_RETURN,     GDK_KP_Enter },
    { nsIDOMKeyEvent::DOM_VK_NUM_LOCK,   GDK_Num_Lock },
    { nsIDOMKeyEvent::DOM_VK_SCROLL_LOCK,GDK_Scroll_Lock },

    { nsIDOMKeyEvent::DOM_VK_COMMA,      GDK_comma },
    { nsIDOMKeyEvent::DOM_VK_PERIOD,     GDK_period },
    { nsIDOMKeyEvent::DOM_VK_SLASH,      GDK_slash },
    { nsIDOMKeyEvent::DOM_VK_BACK_SLASH, GDK_backslash },
    { nsIDOMKeyEvent::DOM_VK_BACK_QUOTE, GDK_grave },
    { nsIDOMKeyEvent::DOM_VK_OPEN_BRACKET, GDK_bracketleft },
    { nsIDOMKeyEvent::DOM_VK_CLOSE_BRACKET, GDK_bracketright },
    { nsIDOMKeyEvent::DOM_VK_SEMICOLON, GDK_colon },
    { nsIDOMKeyEvent::DOM_VK_QUOTE, GDK_apostrophe },

    // context menu key, keysym 0xff67, typically keycode 117 on 105-key (Microsoft) 
    // x86 keyboards, located between right 'Windows' key and right Ctrl key
    { nsIDOMKeyEvent::DOM_VK_CONTEXT_MENU, GDK_Menu },
    { nsIDOMKeyEvent::DOM_VK_SLEEP,      GDK_Sleep },

    // NS doesn't have dash or equals distinct from the numeric keypad ones,
    // so we'll use those for now.  See bug 17008:
    { nsIDOMKeyEvent::DOM_VK_SUBTRACT, GDK_minus },
    { nsIDOMKeyEvent::DOM_VK_EQUALS, GDK_equal },

    // Some shifted keys, see bug 15463 as well as 17008.
    // These should be subject to different keyboard mappings.
    { nsIDOMKeyEvent::DOM_VK_QUOTE, GDK_quotedbl },
    { nsIDOMKeyEvent::DOM_VK_OPEN_BRACKET, GDK_braceleft },
    { nsIDOMKeyEvent::DOM_VK_CLOSE_BRACKET, GDK_braceright },
    { nsIDOMKeyEvent::DOM_VK_BACK_SLASH, GDK_bar },
    { nsIDOMKeyEvent::DOM_VK_SEMICOLON, GDK_semicolon },
    { nsIDOMKeyEvent::DOM_VK_BACK_QUOTE, GDK_asciitilde },
    { nsIDOMKeyEvent::DOM_VK_COMMA, GDK_less },
    { nsIDOMKeyEvent::DOM_VK_PERIOD, GDK_greater },
    { nsIDOMKeyEvent::DOM_VK_SLASH,      GDK_question },
    { nsIDOMKeyEvent::DOM_VK_1, GDK_exclam },
    { nsIDOMKeyEvent::DOM_VK_2, GDK_at },
    { nsIDOMKeyEvent::DOM_VK_3, GDK_numbersign },
    { nsIDOMKeyEvent::DOM_VK_4, GDK_dollar },
    { nsIDOMKeyEvent::DOM_VK_5, GDK_percent },
    { nsIDOMKeyEvent::DOM_VK_6, GDK_asciicircum },
    { nsIDOMKeyEvent::DOM_VK_7, GDK_ampersand },
    { nsIDOMKeyEvent::DOM_VK_8, GDK_asterisk },
    { nsIDOMKeyEvent::DOM_VK_9, GDK_parenleft },
    { nsIDOMKeyEvent::DOM_VK_0, GDK_parenright },
    { nsIDOMKeyEvent::DOM_VK_SUBTRACT, GDK_underscore },
    { nsIDOMKeyEvent::DOM_VK_EQUALS, GDK_plus }
};

PRUint32
uGlobalMenuItem::MozKeyCodeToGdkKeyCode(PRUint32 aMozKeyCode)
{
  if (aMozKeyCode >= nsIDOMKeyEvent::DOM_VK_A &&
      aMozKeyCode <= nsIDOMKeyEvent::DOM_VK_Z)
    return aMozKeyCode;

  if (aMozKeyCode >= nsIDOMKeyEvent::DOM_VK_0 &&
      aMozKeyCode <= nsIDOMKeyEvent::DOM_VK_9)
    return aMozKeyCode;

  if (aMozKeyCode >= nsIDOMKeyEvent::DOM_VK_NUMPAD0 &&
      aMozKeyCode <= nsIDOMKeyEvent::DOM_VK_NUMPAD9)
    return aMozKeyCode - nsIDOMKeyEvent::DOM_VK_NUMPAD0 + GDK_0;

  if (aMozKeyCode >= nsIDOMKeyEvent::DOM_VK_F1 &&
      aMozKeyCode <= nsIDOMKeyEvent::DOM_VK_F24)
    return aMozKeyCode - nsIDOMKeyEvent::DOM_VK_F1 + GDK_KEY_F1;

  for (PRUint32 i = 0; i < NS_ARRAY_LENGTH(nsKeycodes); i++) {
    if (nsKeycodes[i].vkCode == aMozKeyCode)
      return nsKeycodes[i].keysym;
  }

  return GDK_VoidSymbol;
}

void
uGlobalMenuItem::SyncAccelFromContent()
{
  if (!mKeyContent) {
    dbusmenu_menuitem_property_remove(mDbusMenuItem,
                                      DBUSMENU_MENUITEM_PROP_SHORTCUT);
    return;
  }

  nsAutoString modStr;
  mKeyContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::modifiers, modStr);

  PRUint32 modifier = 0;

  if (!modStr.IsEmpty()) {
    char* str = ToNewUTF8String(modStr);
    char *token = strtok(str, ", \t");
    while(token) {
      if (strcmp(token, "shift") == 0) {
        modifier |= GDK_SHIFT_MASK;
      } else if (strcmp(token, "alt") == 0) {
        modifier |= GDK_MOD1_MASK;
      } else if (strcmp(token, "meta") == 0) {
        modifier |= GDK_META_MASK;
      } else if (strcmp(token, "control") == 0) {
        modifier |= GDK_CONTROL_MASK;
      } else if (strcmp(token, "accel") == 0) {
        nsIPrefBranch *prefs = uGlobalMenuService::GetPrefService();
        PRInt32 accel;
        prefs->GetIntPref("ui.key.accelKey", &accel);
        if (accel == nsIDOMKeyEvent::DOM_VK_META) {
          modifier |= GDK_META_MASK;
        } else if (accel == nsIDOMKeyEvent::DOM_VK_ALT) {
          modifier |= GDK_MOD1_MASK;
        } else {
          modifier |= GDK_CONTROL_MASK;
        }
      }

      token = strtok(nullptr, ", \t");
    }

    nsMemory::Free(str);
  }

  nsAutoString keyStr;
  guint key = 0;
  mKeyContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::key, keyStr);

  nsAutoCString cKeyStr;
  CopyUTF16toUTF8(keyStr, cKeyStr);

  if (!cKeyStr.IsEmpty()) {
    key = gdk_keyval_from_name(cKeyStr.get());
  }

  if (key == 0 && !keyStr.IsEmpty()) {
    key = gdk_unicode_to_keyval(*keyStr.BeginReading());
  }

  if (key == 0) {
    mKeyContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::keycode, keyStr);
    if (!keyStr.IsEmpty())
      key = MozKeyCodeToGdkKeyCode(GetKeyCode(keyStr));
  }

  if (key == 0) {
    key = GDK_VoidSymbol;
  }

  if (key != GDK_VoidSymbol) {
    dbusmenu_menuitem_property_set_shortcut(mDbusMenuItem, key,
                                       static_cast<GdkModifierType>(modifier));
  } else {
    dbusmenu_menuitem_property_remove(mDbusMenuItem,
                                      DBUSMENU_MENUITEM_PROP_SHORTCUT);
  }
}

void
uGlobalMenuItem::SyncStateFromCommand()
{
  TRACETM()

  nsAutoString checked;
  if (mCommandContent && mCommandContent->GetAttr(kNameSpaceID_None,
                                                  uWidgetAtoms::checked,
                                                  checked)) {
    LOGTM("Copying checked state from command node");
    mContent->SetAttr(kNameSpaceID_None, uWidgetAtoms::checked, checked,
                      true);
  }
}

void
uGlobalMenuItem::SyncLabelFromCommand()
{
  TRACETM()

  nsAutoString label;
  if (mCommandContent && mCommandContent->GetAttr(kNameSpaceID_None,
                                                  uWidgetAtoms::label,
                                                  label)) {
    LOGTM("Copying label from command node");
    mContent->SetAttr(kNameSpaceID_None, uWidgetAtoms::label, label,
                      true);
  }
}

void
uGlobalMenuItem::SyncSensitivityFromCommand()
{
  TRACETM()

  if (mCommandContent) {
    if (mCommandContent->AttrValueIs(kNameSpaceID_None, uWidgetAtoms::disabled,
                                     uWidgetAtoms::_true, eCaseMatters)) {
      mContent->SetAttr(kNameSpaceID_None, uWidgetAtoms::disabled,
                        NS_LITERAL_STRING("true"), true);
    } else {
      mContent->UnsetAttr(kNameSpaceID_None, uWidgetAtoms::disabled, true);
    }
  }
}

void
uGlobalMenuItem::SyncStateFromContent()
{
  TRACETM()

  if (!IsCheckboxOrRadioItem()) {
    return;
  }

  SetCheckState(mContent->AttrValueIs(kNameSpaceID_None, uWidgetAtoms::checked,
                                      uWidgetAtoms::_true, eCaseMatters));
  dbusmenu_menuitem_property_set_int(mDbusMenuItem,
                                     DBUSMENU_MENUITEM_PROP_TOGGLE_STATE,
                                     IsChecked() ?
                                     DBUSMENU_MENUITEM_TOGGLE_STATE_CHECKED : 
                                      DBUSMENU_MENUITEM_TOGGLE_STATE_UNCHECKED);
}

void
uGlobalMenuItem::SyncTypeAndStateFromContent()
{
  TRACETM()

  static nsIContent::AttrValuesArray attrs[] =
    { &uWidgetAtoms::checkbox, &uWidgetAtoms::radio, nullptr };
  PRInt32 type = mContent->FindAttrValueIn(kNameSpaceID_None,
                                           uWidgetAtoms::type,
                                           attrs, eCaseMatters);

  if (type >= 0 && type < 2) {
    if (type == 0) {
      dbusmenu_menuitem_property_set(mDbusMenuItem,
                                     DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE,
                                     DBUSMENU_MENUITEM_TOGGLE_CHECK);
      SetMenuItemType(eCheckBox);
    } else if (type == 1) {
      dbusmenu_menuitem_property_set(mDbusMenuItem,
                                     DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE,
                                     DBUSMENU_MENUITEM_TOGGLE_RADIO);
      SetMenuItemType(eRadio);
    }

    SyncStateFromContent();

  } else {
    dbusmenu_menuitem_property_remove(mDbusMenuItem,
                                      DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE);
    dbusmenu_menuitem_property_remove(mDbusMenuItem,
                                      DBUSMENU_MENUITEM_PROP_TOGGLE_STATE);
    SetMenuItemType(eNormal);
  }
}

const char *types[] = {
  "Normal",
  "Checkbox",
  "Radio",
  NULL
};

void
uGlobalMenuItem::SetMenuItemType(uMenuItemType aType)
{
  ClearFlags(UNITY_MENUITEM_TYPE_MASK);
  SetFlags(aType << 8);

  LOGTM("Setting menuitem to type %s", types[aType]);
}

void
uGlobalMenuItem::Refresh(uMenuObjectRefreshMode aMode)
{
  TRACETM()

  if (aMode == eRefreshFull) {
    if (mCommandContent) {
      mListener->UnregisterForContentChanges(mCommandContent, this);
      mCommandContent = nullptr;
    }
    if (mKeyContent) {
      mListener->UnregisterForContentChanges(mKeyContent, this);
      mKeyContent = nullptr;
    }

    nsIDocument *doc = mContent->GetCurrentDoc();
    if (doc) {
      nsCOMPtr<nsIDOMDocument> domDoc = do_QueryInterface(doc);
      NS_ASSERTION(domDoc, "nsIDocument failed QI to nsIDOMDocument");
      if (domDoc) {
        nsAutoString value;
        mContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::command, value);
        if (!value.IsEmpty()) {
          nsCOMPtr<nsIDOMElement> elem;
          domDoc->GetElementById(value, getter_AddRefs(elem));
          if (elem) {
            mCommandContent = do_QueryInterface(elem);
            if (mCommandContent) {
              mListener->RegisterForContentChanges(mCommandContent, this);
            }
          }
        }
        mContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::key, value);
        if (!value.IsEmpty()) {
          nsCOMPtr<nsIDOMElement> elem;
          domDoc->GetElementById(value, getter_AddRefs(elem));
          if (elem) {
            mKeyContent = do_QueryInterface(elem);
            if (mKeyContent) {
              mListener->RegisterForContentChanges(mKeyContent, this);
            }
          }
        }
      }
    }
  }

  SyncStateFromCommand();
  SyncLabelFromCommand();
  SyncSensitivityFromCommand();

  if (aMode == eRefreshFull) {
    SyncTypeAndStateFromContent();
    SyncAccelFromContent();
    SyncLabelFromContent();
    SyncSensitivityFromContent();
  }

  SyncVisibilityFromContent();
  SyncIconFromContent();
}

/*static*/ void
uGlobalMenuItem::ItemActivatedCallback(DbusmenuMenuitem *menuItem,
                                       PRUint32 timeStamp,
                                       void *data)
{
  uMenuAutoSuspendMutationEvents as;

  uGlobalMenuItem *self = static_cast<uGlobalMenuItem *>(data);
  self->Activate(timeStamp);
}

void
uGlobalMenuItem::Activate(PRUint32 timeStamp)
{
  TRACETM()

  gdk_x11_window_set_user_time(gtk_widget_get_window(GetMenuBar()->TopLevelWindow()),
                               timeStamp);
  // This first bit seems backwards, but it's not really. If autocheck is
  // not set or autocheck==true, then the checkbox state is usually updated
  // by the input event that clicked on the menu item. In this case, we need
  // to manually update the checkbox state. If autocheck==false, then the input 
  // event doesn't toggle the checkbox state, and it is up  to the handler on
  // this node to do it instead. In this case, we leave it alone

  // XXX: it is important to update the checkbox state before dispatching
  //      the event, as the handler might check the new state
  if (!mContent->AttrValueIs(kNameSpaceID_None, uWidgetAtoms::autocheck,
                             uWidgetAtoms::_false, eCaseMatters) &&
      (GetMenuItemType() == eCheckBox ||
       (GetMenuItemType() == eRadio && !IsChecked()))) {
    mContent->SetAttr(kNameSpaceID_None, uWidgetAtoms::checked,
                      IsChecked() ?
                      NS_LITERAL_STRING("false") :  NS_LITERAL_STRING("true"),
                      true);
  }

  nsCOMPtr<nsIDOMEventTarget> target = do_QueryInterface(mContent);
  NS_ASSERTION(target, "Content failed QI to nsIDOMEventTarget");
  if (!target) {
    return;
  }

  nsCOMPtr<nsIDOMDocument> domDoc = do_QueryInterface(mContent->OwnerDoc());
  NS_ASSERTION(domDoc, "Document failed QI to nsIDOMDocument");
  if (!domDoc) {
    return;
  }

  nsCOMPtr<nsIDOMEvent> event;
  domDoc->CreateEvent(NS_LITERAL_STRING("xulcommandevent"),
                      getter_AddRefs(event));
  NS_ASSERTION(event, "Failed to create xulcommandevent");
  if (!event) {
    return;
  }

  nsCOMPtr<nsIDOMXULCommandEvent> cmdEvent = do_QueryInterface(event);
  NS_ASSERTION(cmdEvent, "Event failed QI to nsIDOMXULCommandEvent");
  if (!cmdEvent) {
    return;
  }

  nsCOMPtr<nsIDOMWindow> window;
  domDoc->GetDefaultView(getter_AddRefs(window));
  if (!window) {
    return;
  }

  cmdEvent->InitCommandEvent(NS_LITERAL_STRING("command"),
                             true, true, window, 0,
                             false, false, false,
                             false, nullptr);

  nsCOMPtr<nsIPrivateDOMEvent> priv = do_QueryInterface(event);
  NS_ASSERTION(priv, "Event failed QI to nsIPrivateDOMEvent");
  if (!priv) {
    return;
  }

  priv->SetTrusted(true);

  bool dummy;
  target->DispatchEvent(event, &dummy);
}

void
uGlobalMenuItem::InitializeDbusMenuItem()
{
  g_signal_connect(G_OBJECT(mDbusMenuItem), DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED,
                   G_CALLBACK(ItemActivatedCallback), this);
}

nsresult
uGlobalMenuItem::Init(uGlobalMenuObject *aParent,
                      uGlobalMenuDocListener *aListener,
                      nsIContent *aContent)
{
  NS_ENSURE_ARG(aParent);
  NS_ENSURE_ARG(aListener);
  NS_ENSURE_ARG(aContent);

  mParent = aParent;
  mListener = aListener;
  mContent = aContent;

  mListener->RegisterForContentChanges(mContent, this);

  return NS_OK;
}

void
uGlobalMenuItem::UncheckSiblings()
{
  TRACETM()

  if (GetMenuItemType() != eRadio) {
    // If we're not a radio button, we don't care
    return;
  }

  nsAutoString name;
  mContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::name, name);

  nsIContent *parent = mContent->GetParent();
  if (!parent) {
    return;
  }

  PRUint32 count = parent->GetChildCount();
  for (PRUint32 i = 0; i < count; i++) {
    nsIContent *sibling = parent->GetChildAt(i);

    nsAutoString otherName;
    sibling->GetAttr(kNameSpaceID_None, uWidgetAtoms::name, otherName);

    if (sibling != mContent && otherName == name && 
        sibling->AttrValueIs(kNameSpaceID_None, uWidgetAtoms::type,
                             uWidgetAtoms::radio, eCaseMatters)) {
      sibling->UnsetAttr(kNameSpaceID_None, uWidgetAtoms::checked, true);
    }
  }
}

uGlobalMenuItem::uGlobalMenuItem():
  uGlobalMenuObject()
{
  MOZ_COUNT_CTOR(uGlobalMenuItem);
}

uGlobalMenuItem::~uGlobalMenuItem()
{
  TRACETM();

  if (!IsDestroyed()) {
    Destroy();
  }

  MOZ_COUNT_DTOR(uGlobalMenuItem);
}

/*static*/ uGlobalMenuObject*
uGlobalMenuItem::Create(uGlobalMenuObject *aParent,
                        uGlobalMenuDocListener *aListener,
                        nsIContent *aContent)
{
  TRACEC(aContent);

  uGlobalMenuItem *menuitem = new uGlobalMenuItem();
  if (!menuitem) {
    return nullptr;
  }

  if (NS_FAILED(menuitem->Init(aParent, aListener, aContent))) {
    delete menuitem;
    return nullptr;
  }

  return static_cast<uGlobalMenuObject *>(menuitem);
}

void
uGlobalMenuItem::Destroy()
{
  NS_ASSERTION(!IsDestroyed(), "Menuitem is already destroyed");
  if (IsDestroyed()) {
    return;
  }

  if (mListener) {
    if (mCommandContent) {
      mListener->UnregisterForContentChanges(mCommandContent, this);
    }
    if (mKeyContent) {
      mListener->UnregisterForContentChanges(mKeyContent, this);
    }
  }

  if (mDbusMenuItem) {
    guint found = g_signal_handlers_disconnect_by_func(mDbusMenuItem,
                                                       uGlobalMenuUtils::FuncToVoidPtr(ItemActivatedCallback),
                                                       this);
    NS_ASSERTION(found == 1, "Failed to disconnect \"activated\" handler");
  }

  uGlobalMenuObject::Destroy();
}

void
uGlobalMenuItem::ObserveAttributeChanged(nsIContent *aContent,
                                         nsIAtom *aAttribute)
{
  TRACETM();
  NS_ASSERTION(aContent == mContent || aContent == mCommandContent ||
               aContent == mKeyContent,
               "Received an event that wasn't meant for us!");

  if (aContent == mContent && aAttribute == uWidgetAtoms::checked &&
      aContent->AttrValueIs(kNameSpaceID_None, uWidgetAtoms::checked,
                            uWidgetAtoms::_true, eCaseMatters)) {
    UncheckSiblings();
  }

  if (aContent == mContent) {
    if (aAttribute == uWidgetAtoms::command ||
        aAttribute == uWidgetAtoms::key) {
      Refresh(eRefreshFull);
    } else if (aAttribute == uWidgetAtoms::label) {
      SyncLabelFromContent();
    } else if (aAttribute == uWidgetAtoms::accesskey) {
      SyncLabelFromContent();
    } else if (aAttribute == uWidgetAtoms::disabled) {
      SyncSensitivityFromContent();
    } else if (aAttribute == uWidgetAtoms::type) {
      SyncTypeAndStateFromContent();
    } else if (aAttribute == uWidgetAtoms::checked) {
      SyncStateFromContent();
    } else if (aAttribute == uWidgetAtoms::image) {
      SyncIconFromContent();
    } else if (aAttribute == uWidgetAtoms::hidden ||
               aAttribute == uWidgetAtoms::collapsed) {
      SyncVisibilityFromContent();
    }
  } else if (aContent == mCommandContent) {
    if (aAttribute == uWidgetAtoms::label) {
      SyncLabelFromCommand();
    } else if (aAttribute == uWidgetAtoms::disabled) {
      SyncSensitivityFromCommand();
    } else if (aAttribute == uWidgetAtoms::checked) {
      SyncStateFromCommand();
    }
  } else if (aContent == mKeyContent) {
    SyncAccelFromContent();
  }
}
