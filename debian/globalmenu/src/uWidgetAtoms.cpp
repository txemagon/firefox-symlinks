/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
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
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Original Author: Mike Pinkerton (pinkerton@netscape.com)
 *   Chris Coulson <chris.coulson@canonical.com>
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
#include <nsIAtomService.h>
#include <nsIAtom.h>
#include <nsServiceManagerUtils.h>
#include <nsStringGlue.h>
#include <nsMemory.h>

#include "uGlobalMenuService.h"
#include "uWidgetAtoms.h"

#define WIDGET_ATOM(_name) nsIAtom* uWidgetAtoms::_name = 0;
#define WIDGET_ATOM2(_name, _value) nsIAtom* uWidgetAtoms::_name = 0;
#include "uWidgetAtomList.h"
#undef WIDGET_ATOM
#undef WIDGET_ATOM2

struct uWidgetAtom {
  const char *raw;
  nsIAtom **atom;
};

static const uWidgetAtom atoms[] = {
#define WIDGET_ATOM(_name) { #_name, &uWidgetAtoms::_name },
#define WIDGET_ATOM2(_name, _value) { _value, &uWidgetAtoms::_name },
#include "uWidgetAtomList.h"
#undef WIDGET_ATOM
#undef WIDGET_ATOM2
};

nsresult
uWidgetAtoms::RegisterAtoms()
{
  nsIAtomService *as = uGlobalMenuService::GetAtomService();
  if (!as) {
    NS_WARNING("No atom service, which means it's game over already");
    return NS_ERROR_FAILURE;
  }

  nsAutoString aAtomStr;
  nsAutoCString cAtomStr;

  for (PRUint32 i = 0; i < NS_ARRAY_LENGTH(atoms); i++) {
    cAtomStr = atoms[i].raw;
    CopyUTF8toUTF16(cAtomStr, aAtomStr);
    nsresult rv = as->GetAtom(aAtomStr, atoms[i].atom);
    if (NS_FAILED(rv)) {
      NS_WARNING("Failed to get atom");
      return rv;
    }
  }

  return NS_OK;
}

void
uWidgetAtoms::UnregisterAtoms()
{
  nsIAtomService *as = uGlobalMenuService::GetAtomService();
  if (!as) {
    return;
  }

  for (PRUint32 i = 0; i < NS_ARRAY_LENGTH(atoms); i++) {
    NS_IF_RELEASE(*atoms[i].atom);
  }
}
