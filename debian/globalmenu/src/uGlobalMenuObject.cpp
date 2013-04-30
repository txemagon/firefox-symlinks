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

#include <prtypes.h>
#include <nsStringGlue.h>
#include <nsIURI.h>
#include <nsILoadGroup.h>
#include <imgIContainer.h>
#if MOZILLA_BRANCH_VERSION < 17
# include <nsNetError.h>
#else
# include <nsError.h>
#endif
#include <nsNetUtil.h>
#include <nsIImageToPixbuf.h>
#include <nsIDOMDocument.h>
#include <nsIDOMWindow.h>
#include <nsIDOMElement.h>
#include <nsIDOMCSSStyleDeclaration.h>
#include <nsIDOMCSSValue.h>
#include <nsIDOMCSSPrimitiveValue.h>
#include <nsIDOMRect.h>
#include <nsICaseConversion.h>
#include <imgILoader.h>
#include <nsThreadUtils.h>
#include <nsIRunnable.h>

#include <libdbusmenu-gtk/menuitem.h>
#include <gtk/gtk.h>

#include "uGlobalMenuObject.h"
#include "uGlobalMenuService.h"
#include "uGlobalMenuBar.h"
#include "uWidgetAtoms.h"

#include "uDebug.h"

#define MAX_LABEL_NCHARS 40

typedef nsresult (nsIDOMRect::*GetRectSideMethod)(nsIDOMCSSPrimitiveValue**);

#if MOZILLA_BRANCH_VERSION >= 19
NS_IMPL_ISUPPORTS1(uGlobalMenuObject::IconLoader, imgINotificationObserver)
#else
NS_IMPL_ISUPPORTS2(uGlobalMenuObject::IconLoader, imgIDecoderObserver,
                   imgIContainerObserver)
#endif

unsigned char uGlobalMenuObject::sImagesInMenus = 0xFF;

// Must be kept in sync with uMenuObjectProperties
const char *properties[] = {
  DBUSMENU_MENUITEM_PROP_LABEL,
  DBUSMENU_MENUITEM_PROP_ENABLED,
  DBUSMENU_MENUITEM_PROP_VISIBLE,
  DBUSMENU_MENUITEM_PROP_ICON_DATA,
  DBUSMENU_MENUITEM_PROP_TYPE,
  DBUSMENU_MENUITEM_PROP_SHORTCUT,
  DBUSMENU_MENUITEM_PROP_TOGGLE_TYPE,
  DBUSMENU_MENUITEM_PROP_TOGGLE_STATE,
  DBUSMENU_MENUITEM_PROP_CHILD_DISPLAY,
  NULL
};

void
uGlobalMenuObject::IconLoader::ScheduleIconLoad()
{
  nsCOMPtr<nsIRunnable> event =
    NS_NewRunnableMethod(this, &uGlobalMenuObject::IconLoader::LoadIcon);
  NS_DispatchToCurrentThread(event);
}

static PRInt32
GetDOMRectSide(nsIDOMRect* aRect, GetRectSideMethod aMethod)
{
  nsCOMPtr<nsIDOMCSSPrimitiveValue> dimensionValue;
  (aRect->*aMethod)(getter_AddRefs(dimensionValue));
  if (!dimensionValue) {
    return -1;
  }

  PRUint16 type;
  nsresult rv = dimensionValue->GetPrimitiveType(&type);
  if (NS_FAILED(rv) || type != nsIDOMCSSPrimitiveValue::CSS_PX) {
    return -1;
  }

  float dimension = 0;
  rv = dimensionValue->GetFloatValue(nsIDOMCSSPrimitiveValue::CSS_PX,
                                     &dimension);
  if (NS_FAILED(rv)) {
    return -1;
  }

  return NSToIntRound(dimension);
}

void
uGlobalMenuObject::IconLoader::LoadIcon()
{
  // Some of this is borrowed from widget/src/cocoa/nsMenuItemIconX.mm
  TRACEM(mMenuItem);

  if (!mMenuItem) {
    // Our menu item got destroyed already
    return;
  }

  nsIDocument *doc = mMenuItem->GetContent()->GetCurrentDoc();
  if (!doc) {
    // We might have been removed from the menu, in which case we will
    // no longer be in a document
    return;
  }

  nsAutoString uriString;
  bool hasImage = mMenuItem->GetContent()->GetAttr(kNameSpaceID_None,
                                                   uWidgetAtoms::image,
                                                   uriString);

  nsresult rv;
  nsCOMPtr<nsIDOMRect> domRect;

  if (!hasImage) {
    nsCOMPtr<nsIDOMCSSStyleDeclaration> style;
    mMenuItem->GetComputedStyle(getter_AddRefs(style));

    if (style) {
      nsCOMPtr<nsIDOMCSSValue> value;
      style->GetPropertyCSSValue(NS_LITERAL_STRING("list-style-image"),
                                 getter_AddRefs(value));
      if (value) {
        nsCOMPtr<nsIDOMCSSPrimitiveValue> pval = do_QueryInterface(value);
        if (pval) {
          PRUint16 type;
          pval->GetPrimitiveType(&type);
          if (type == nsIDOMCSSPrimitiveValue::CSS_URI) {
            rv = pval->GetStringValue(uriString);
            if (NS_SUCCEEDED(rv)) {
              hasImage = true;
            }
          }
        }
      }
    }

    if (!hasImage) {
      LOGM(mMenuItem, "Menuitem does not have an image");
      mUriString.Truncate();
      mImageRect.SetEmpty();
      mMenuItem->ClearIcon();

      // Make sure we cancel any pending request to set the icon
      if (mIconRequest) {
        mIconRequest->CancelAndForgetObserver(NS_BINDING_ABORTED);
        mIconRequest = nullptr;
      }

      return;
    }

    nsCOMPtr<nsIDOMCSSValue> value;
    style->GetPropertyCSSValue(NS_LITERAL_STRING("-moz-image-region"),
                               getter_AddRefs(value));
    if (value) {
      nsCOMPtr<nsIDOMCSSPrimitiveValue> pval = do_QueryInterface(value);
      if (pval) {
        PRUint16 type;
        pval->GetPrimitiveType(&type);
        if (type == nsIDOMCSSPrimitiveValue::CSS_RECT) {
          pval->GetRectValue(getter_AddRefs(domRect));
        }
      }
    }
  }

  nsIntRect imageRect;

  if (domRect) {
    PRInt32 bottom = GetDOMRectSide(domRect, &nsIDOMRect::GetBottom);
    PRInt32 right = GetDOMRectSide(domRect, &nsIDOMRect::GetRight);
    PRInt32 top = GetDOMRectSide(domRect, &nsIDOMRect::GetTop);
    PRInt32 left = GetDOMRectSide(domRect, &nsIDOMRect::GetLeft);

    if (top < 0 || left < 0 || bottom <= top || right <= left) {
      return;
    }

    imageRect.SetRect(left, top, right - left, bottom - top);
  }

  if (mUriString.Equals(uriString) && mImageRect.IsEqualEdges(imageRect)) {
    LOGM(mMenuItem, "Icon has not changed");
    return;
  }

  LOGM(mMenuItem, "Icon URI: %s", NS_LossyConvertUTF16toASCII(uriString).get());

  if (mIconRequest) {
    mIconRequest->CancelAndForgetObserver(NS_BINDING_ABORTED);
    mIconRequest = nullptr;
  }

  mIconLoaded = false;

  nsCOMPtr<nsIURI> uri;
  rv = NS_NewURI(getter_AddRefs(uri), uriString);
  if (NS_FAILED(rv)) {
    NS_WARNING("Failed to create new URI");
    return;
  }

  nsCOMPtr<nsILoadGroup> loadGroup = doc->GetDocumentLoadGroup();
  imgILoader *loader = uGlobalMenuService::GetIconLoader();
  NS_ASSERTION(loader, "Failed to get image loader");
  if (!loader) {
    return;
  }

#if MOZILLA_BRANCH_VERSION >= 20
  rv = loader->LoadImageXPCOM(uri, nullptr, nullptr, nullptr, loadGroup, this,
#else
  rv = loader->LoadImage(uri, nullptr, nullptr, nullptr, loadGroup, this,
#endif
#if MOZILLA_BRANCH_VERSION >= 19
                         nullptr, nsIRequest::LOAD_NORMAL,
#else
                         nullptr, nsIRequest::LOAD_NORMAL, nullptr,
#endif
                         nullptr, nullptr, getter_AddRefs(mIconRequest));
  if (NS_FAILED(rv)) {
    NS_WARNING("Failed to load icon");
    return;
  }

  mIconRequest->RequestDecode();

  mUriString = uriString;
  mImageRect = imageRect;

  return;
}

nsresult
uGlobalMenuObject::IconLoader::OnStopFrame(imgIRequest *aRequest)
{
  TRACEM(mMenuItem);

  if (aRequest != mIconRequest) {
    return NS_ERROR_FAILURE;
  }

  if (mIconLoaded) {
    LOGM(mMenuItem, "Icon is already loaded");
    return NS_OK;
  }

  mIconLoaded = true;

  nsCOMPtr<imgIContainer> img;
  aRequest->GetImage(getter_AddRefs(img));
  if (!img) {
    NS_WARNING("Failed to get image");
    return NS_ERROR_FAILURE;
  }

  PRInt32 origWidth;
  PRInt32 origHeight;
  img->GetWidth(&origWidth);
  img->GetHeight(&origHeight);

  bool needsClip = false;

  if (!mImageRect.IsEmpty()) {
    if (mImageRect.XMost() > origWidth || mImageRect.YMost() > origHeight) {
      NS_WARNING("-moz-image-region is larger than image");
      return NS_ERROR_FAILURE;
    }

    if (!(mImageRect.x == 0 && mImageRect.y == 0 &&
         mImageRect.width == origWidth && mImageRect.height == origHeight)) {
      needsClip = true;
    }
  }

  if ((!needsClip && (origWidth > 100 || origHeight > 100)) ||
     (needsClip && (mImageRect.width > 100 || mImageRect.height > 100))) {
    /* The icon data needs to go across DBus. Make sure the icon
     * data isn't too large, else our connection gets terminated and
     * GDbus helpfully aborts the application. Thank you :)
     */
    NS_WARNING("Icon data too large");
    mMenuItem->ClearIcon();
    return NS_OK;
  }

  nsCOMPtr<imgIContainer> clippedImg;
  if (needsClip) {
    nsresult rv = img->ExtractFrame(0, mImageRect, 0,
                                    getter_AddRefs(clippedImg));
    if (NS_FAILED(rv)) {
      NS_WARNING("Failed to clip icon");
      return NS_ERROR_FAILURE;
    }
  }

  nsIImageToPixbuf *converter = uGlobalMenuService::GetImageToPixbufService();
  NS_ASSERTION(converter, "No image converter");
  if (!converter) {
    return NS_ERROR_FAILURE;
  }

  GdkPixbuf *pixbuf =
    converter->ConvertImageToPixbuf(clippedImg ? clippedImg : img);
  if (pixbuf) {
    dbusmenu_menuitem_property_set_image(mMenuItem->GetDbusMenuItem(),
                                         DBUSMENU_MENUITEM_PROP_ICON_DATA,
                                         pixbuf);
    g_object_unref(pixbuf);
  } else {
    NS_WARNING("Failed to create pixbuf");
    mMenuItem->ClearIcon();
  }

  return NS_OK;
}

void
uGlobalMenuObject::IconLoader::OnStopRequest()
{
  TRACEM(mMenuItem);

  if (mIconRequest) {
    mIconRequest->Cancel(NS_BINDING_ABORTED);
    mIconRequest = nullptr;
  }
}

#if MOZILLA_BRANCH_VERSION >= 19

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::Notify(imgIRequest *aProxy,
                                      int32_t aType,
                                      const nsIntRect *aRect)
{
  if (aType == imgINotificationObserver::FRAME_COMPLETE) {
    return OnStopFrame(aProxy);
  } else if (aType == imgINotificationObserver::LOAD_COMPLETE) {
    OnStopRequest();
  }

  return NS_OK;
}

#else

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStopFrame(imgIRequest *aRequest,
                                           PRUint32 aFrame)
{
  return OnStopFrame(aRequest);
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStopRequest(imgIRequest *aRequest,
                                             bool aIsLastPart)
{
  OnStopRequest();
  return NS_OK;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStartRequest(imgIRequest *aRequest)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStartDecode(imgIRequest *aRequest)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStartContainer(imgIRequest *aRequest,
                                                imgIContainer *aContainer)
{
  TRACEM(mMenuItem);
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStartFrame(imgIRequest *aRequest,
                                            PRUint32 aFrame)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnDataAvailable(imgIRequest *aRequest,
                                               bool aCurrentFrame,
                                               const nsIntRect *aRect)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}



NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStopContainer(imgIRequest *aRequest,
                                               imgIContainer *aContainer)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnStopDecode(imgIRequest *aRequest,
                                            nsresult status,
                                            const PRUnichar *statusArg)
{
  TRACEM(mMenuItem);
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnDiscard(imgIRequest *aRequest)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::FrameChanged(imgIRequest *aRequest,
                                            imgIContainer *aContainer,
                                            const nsIntRect *aDirtyRect)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
uGlobalMenuObject::IconLoader::OnImageIsAnimated(imgIRequest* aRequest)
{
  return NS_OK;
}

#endif

void
uGlobalMenuObject::IconLoader::Destroy()
{
  TRACEM(mMenuItem);

  if (mIconRequest) {
    mIconRequest->CancelAndForgetObserver(NS_BINDING_ABORTED);
    mIconRequest = nullptr;
  }

  mMenuItem = nullptr;
}

uGlobalMenuBar*
uGlobalMenuObject::GetMenuBar()
{
  uGlobalMenuObject *tmp = this;
  while (tmp) {
    if (tmp->GetType() == eMenuBar) {
      return static_cast<uGlobalMenuBar *>(tmp);
    }

    tmp = tmp->GetParent();
  }

  return nullptr;
}

void
uGlobalMenuObject::ClearIcon()
{
  dbusmenu_menuitem_property_remove(mDbusMenuItem,
                                    DBUSMENU_MENUITEM_PROP_ICON_DATA);
}

static bool
IsHTMLWhitespace(const PRUnichar c)
{
  return c == PRUnichar(0x0009) ||
         c == PRUnichar(0x000A) ||
         c == PRUnichar(0x000C) ||
         c == PRUnichar(0x000D) ||
         c == PRUnichar(0x0020);
}

bool
uGlobalMenuObject::ShouldShowIcon()
{
  // Ideally, we want to get the visibility of the XUL image in our menu item,
  // but that is anonymous content which is only created when the frame is drawn
  // (which obviously never happens here).
  // As an alternative, we get the user setting for menus-have-icons from
  // nsILookAndFeel. If menu icons are to be hidden, we hide everything except
  // for menuitems with the menuitem-with-favicon class. This is basically
  // how the visibility gets set anyway (see chrome://toolkit/content/xul.css),
  // which should work in most cases. But, I guess a theme could override this,
  // and then we ignore the users theme settings. Oh well......

  if (sImagesInMenus == 0xFF) {
    // We could get the correct GtkSettings by getting the GdkScreen that our
    // top-level window is on. However, I don't think this matters, as
    // nsILookAndFeel never had per-screen settings
    GtkSettings *settings = gtk_settings_get_default();
    gboolean menus_have_icons;
    g_object_get(settings, "gtk-menu-images", &menus_have_icons, NULL);

    sImagesInMenus = menus_have_icons ? 1 : 0;
  }

  if (sImagesInMenus) {
    return true;
  }

  nsAutoString value;
  mContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::_class, value);

  const PRUnichar *iter = value.BeginReading();
  const PRUnichar *end = value.EndReading();

  while (iter != end) {
    while (iter != end && IsHTMLWhitespace(*iter)) {
      ++iter;
    }

    const PRUnichar *start = iter;

    do {
      ++iter;
    } while (iter != end && !IsHTMLWhitespace(*iter));

    const nsDependentSubstring& sub = Substring(start, iter);

    if (sub.Equals(NS_LITERAL_STRING("menuitem-with-favicon"))) {
      return true;
    }
  }

  return false;
}

void
uGlobalMenuObject::SyncLabelFromContent()
{
  TRACETM();
  // Gecko stores the label and access key in separate attributes
  // so we need to convert label="Foo"/accesskey="F" in to
  // label="_Foo" for dbusmenu

  nsAutoString label;
  mContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::label, label);

  nsAutoString accesskey;
  mContent->GetAttr(kNameSpaceID_None, uWidgetAtoms::accesskey, accesskey);

  const PRUnichar *tmp = accesskey.BeginReading();
  nsICaseConversion *converter = uGlobalMenuService::GetCaseConverter();

  PRUnichar keyUpper;
  PRUnichar keyLower;
  if (converter) {
    converter->ToUpper(*tmp, &keyUpper);
    converter->ToLower(*tmp, &keyLower);
  } else {
    NS_WARNING("No case converter");
    keyUpper = *tmp;
    keyLower = *tmp;
  }

  PRUnichar *cur = label.BeginWriting();
  PRUnichar *end = label.EndWriting();
  int length = label.Length();
  int pos = 0;
  bool foundAccessKey = false;

  while (cur < end) {
    if (*cur != PRUnichar('_')) {
      if ((*cur != keyLower && *cur != keyUpper) || foundAccessKey) {
        cur++;
        pos++;
        continue;
      }
      foundAccessKey = true;
    }

    length += 1;
    label.SetLength(length);
    int newLength = label.Length();
    if (length != newLength)
      break; 
     
    cur = label.BeginWriting() + pos;
    end = label.EndWriting();
    memmove(cur + 1, cur, (length - 1 - pos) * sizeof(PRUnichar));
//                   \^/
    *cur = PRUnichar('_'); // Yeah!
//                    v

    cur += 2;
    pos += 2;
  }

  // Ellipsize long labels. I've picked an arbitrary length here
  if (length > MAX_LABEL_NCHARS) {
    cur = label.BeginWriting();
    for (PRUint32 i = 1; i < 4; i++) {
      *(cur + (MAX_LABEL_NCHARS - i)) = PRUnichar('.');
    }
    *(cur + MAX_LABEL_NCHARS) = 0;
    label.SetLength(MAX_LABEL_NCHARS);
  }

  nsAutoCString clabel;
  CopyUTF16toUTF8(label, clabel);
  LOGTM("Setting label to \"%s\"", clabel.get());
  dbusmenu_menuitem_property_set(mDbusMenuItem,
                                 DBUSMENU_MENUITEM_PROP_LABEL,
                                 clabel.get());
}

inline static void
GetCSSIdentValue(nsIDOMCSSStyleDeclaration *aStyle,
                 const nsAString& aProp, nsAString& aResult)
{
  nsCOMPtr<nsIDOMCSSValue> value;
  aStyle->GetPropertyCSSValue(aProp, getter_AddRefs(value));
  if (value) {
    nsCOMPtr<nsIDOMCSSPrimitiveValue> pval = do_QueryInterface(value);
    if (pval) {
      PRUint16 type;
      pval->GetPrimitiveType(&type);
      if (type == nsIDOMCSSPrimitiveValue::CSS_IDENT) {
        pval->GetStringValue(aResult);
      }
    }
  }
}

void
uGlobalMenuObject::SyncVisibilityFromContent()
{
  TRACETM();

  bool vis = true;
  nsCOMPtr<nsIDOMCSSStyleDeclaration> style;
  GetComputedStyle(getter_AddRefs(style));
  if (style) {
    // "display: none" nodes would normally have no frame. Setting the
    // XUL "hidden" attribute to true sets this
    nsAutoString display;
    GetCSSIdentValue(style, NS_LITERAL_STRING("display"), display);
    if (display.Equals(NS_LITERAL_STRING("none"))) {
      vis = false;
    } else {
      // "visibility: collapse" nodes would normally be hidden but keep its
      // frame, but we don't differentiate here. Setting the XUL "collapsed"
      // attribute to true sets this
      nsAutoString visibility;
      GetCSSIdentValue(style, NS_LITERAL_STRING("visibility"), visibility);
      if (visibility.Equals(NS_LITERAL_STRING("collapse"))) {
        vis = false;
      }
    }
  }

  LOGTM("Setting visibility to %s", vis ? "visible" : "hidden");
  dbusmenu_menuitem_property_set_bool(mDbusMenuItem,
                                      DBUSMENU_MENUITEM_PROP_VISIBLE,
                                      vis);
}

void
uGlobalMenuObject::SyncSensitivityFromContent()
{
  TRACETM();

  bool disabled = mContent->AttrValueIs(kNameSpaceID_None,
                                        uWidgetAtoms::disabled,
                                        uWidgetAtoms::_true,
                                        eCaseMatters);
  LOGTM("Setting %s", disabled ? "disabled" : "enabled");

  dbusmenu_menuitem_property_set_bool(mDbusMenuItem,
                                      DBUSMENU_MENUITEM_PROP_ENABLED,
                                      !disabled);
}

void
uGlobalMenuObject::SyncIconFromContent()
{
  TRACETM();
  if (ShouldShowIcon()) {
    if (!mIconLoader) {
      mIconLoader = new IconLoader(this);
    }

    mIconLoader->ScheduleIconLoad();
  } else {
    if (mIconLoader) {
      mIconLoader->Destroy();
      mIconLoader = nullptr;
    }

    ClearIcon();
  }
}

DbusmenuMenuitem*
uGlobalMenuObject::GetDbusMenuItem()
{
  if (IsDestroyed()) {
    return nullptr;
  }

  if (!mDbusMenuItem) {
    mDbusMenuItem = dbusmenu_menuitem_new();
    InitializeDbusMenuItem();
    Refresh(eRefreshFull);
  }

  return mDbusMenuItem;
}

void
uGlobalMenuObject::SetDbusMenuItem(DbusmenuMenuitem *aDbusMenuItem)
{
  NS_ASSERTION(!IsDestroyed(), "Menuobject has been destroyed");
  NS_ASSERTION(!mDbusMenuItem, "This node already has a corresponding DbusmenuMenuitem");
  if (mDbusMenuItem || IsDestroyed()) {
    return;
  }

  mDbusMenuItem = aDbusMenuItem;
  g_object_ref(mDbusMenuItem);

  OnlyKeepProperties(GetValidProperties());
  InitializeDbusMenuItem();
  Refresh(eRefreshFull);
}

void
uGlobalMenuObject::OnlyKeepProperties(uMenuObjectProperties aKeep)
{
  uMenuObjectProperties mask = static_cast<uMenuObjectProperties>(1);
  for (PRUint32 i = 0; properties[i] != NULL; i++) {
    if (!(mask & aKeep)) {
      dbusmenu_menuitem_property_remove(mDbusMenuItem, properties[i]);
    }
    mask = static_cast<uMenuObjectProperties>(mask << 1);
  }
}

void
uGlobalMenuObject::GetComputedStyle(nsIDOMCSSStyleDeclaration **aResult)
{
  *aResult = nullptr;

  nsIDocument *doc = mContent->GetCurrentDoc();
  if (!doc) {
    return;
  }

  nsCOMPtr<nsIDOMDocument> domDoc = do_QueryInterface(doc);
  if (!domDoc) {
    return;
  }

  nsCOMPtr<nsIDOMWindow> domWin;
  domDoc->GetDefaultView(getter_AddRefs(domWin));
  if (!domWin) {
    return;
  }

  nsCOMPtr<nsIDOMElement> domElement = do_QueryInterface(mContent);
  if (domElement) {
    domWin->GetComputedStyle(domElement, EmptyString(),
                             aResult);
  }
}

uGlobalMenuObject::~uGlobalMenuObject()
{
  TRACETM();

  if (!IsDestroyed()) {
    Destroy();
  }
}

void
uGlobalMenuObject::ContainerIsOpening()
{
  NS_ASSERTION(!IsDestroyed(), "Menuobject has been destroyed");
  if (IsDestroyed()) {
    return;
  }

  Refresh(eContainerOpeningRefresh);
}

void
uGlobalMenuObject::Destroy()
{
  TRACETM();

  NS_ASSERTION(!IsDestroyed(), "Menuobject is already destroyed");
  if (IsDestroyed()) {
    return;
  }

  if (mIconLoader) {
    mIconLoader->Destroy();
  }

  if (mListener) {
    mListener->UnregisterForContentChanges(mContent, this);
  }

  if (mDbusMenuItem) {
    g_object_unref(mDbusMenuItem);
    mDbusMenuItem = nullptr;
  }

  mParent = nullptr;

  SetFlags(UNITY_MENUOBJECT_DESTROYED);
}
