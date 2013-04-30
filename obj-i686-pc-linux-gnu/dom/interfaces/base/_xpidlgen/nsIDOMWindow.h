/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/base/nsIDOMWindow.idl
 */

#ifndef __gen_nsIDOMWindow_h__
#define __gen_nsIDOMWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFrameRequestCallback; /* forward declaration */

class nsIControllers; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

class nsIDOMLocation; /* forward declaration */

class nsIDOMMediaQueryList; /* forward declaration */

class nsIDOMOfflineResourceList; /* forward declaration */

class nsIDOMStorage; /* forward declaration */

class nsIPrompt; /* forward declaration */

class nsISelection; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMWindow */
#define NS_IDOMWINDOW_IID_STR "8d86d6b2-fc2c-416a-8085-f670d5a35832"

#define NS_IDOMWINDOW_IID \
  {0x8d86d6b2, 0xfc2c, 0x416a, \
    { 0x80, 0x85, 0xf6, 0x70, 0xd5, 0xa3, 0x58, 0x32 }}

class nsIDOMWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOW_IID)

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* readonly attribute nsIDOMWindow self; */
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) = 0;

  /* readonly attribute nsIDOMDocument document; */
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* readonly attribute nsIDOMLocation location; */
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) = 0;

  /* readonly attribute nsIDOMHistory history; */
  NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory) = 0;

  /* readonly attribute nsIDOMBarProp locationbar; */
  NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar) = 0;

  /* readonly attribute nsIDOMBarProp menubar; */
  NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar) = 0;

  /* readonly attribute nsIDOMBarProp personalbar; */
  NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar) = 0;

  /* readonly attribute nsIDOMBarProp scrollbars; */
  NS_IMETHOD GetScrollbars(nsIDOMBarProp * *aScrollbars) = 0;

  /* readonly attribute nsIDOMBarProp statusbar; */
  NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar) = 0;

  /* readonly attribute nsIDOMBarProp toolbar; */
  NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar) = 0;

  /* attribute DOMString status; */
  NS_IMETHOD GetStatus(nsAString & aStatus) = 0;
  NS_IMETHOD SetStatus(const nsAString & aStatus) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* void focus (); */
  NS_IMETHOD Focus(void) = 0;

  /* void blur (); */
  NS_IMETHOD Blur(void) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* [binaryname(ScriptableTop)] readonly attribute nsIDOMWindow top; */
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) = 0;

  /* [noscript] readonly attribute nsIDOMWindow realTop; */
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) = 0;

   nsresult GetTop(nsIDOMWindow **aWindow)
  {
    return GetRealTop(aWindow);
  }
    /* [binaryname(ScriptableParent)] readonly attribute nsIDOMWindow parent; */
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) = 0;

  /* [noscript] readonly attribute nsIDOMWindow realParent; */
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) = 0;

   inline nsresult GetParent(nsIDOMWindow **aWindow)
  {
    return GetRealParent(aWindow);
  }
    /* attribute nsIDOMWindow opener; */
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpener) = 0;
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpener) = 0;

  /* [binaryname(ScriptableFrameElement)] readonly attribute nsIDOMElement frameElement; */
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) = 0;

  /* [noscript] readonly attribute nsIDOMElement realFrameElement; */
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) = 0;

   inline nsresult GetFrameElement(nsIDOMElement **aElement)
  {
    return GetRealFrameElement(aElement);
  }
    /* readonly attribute nsIDOMNavigator navigator; */
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) = 0;

  /* readonly attribute nsIDOMOfflineResourceList applicationCache; */
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) = 0;

  /* void alert (in DOMString text); */
  NS_IMETHOD Alert(const nsAString & text) = 0;

  /* boolean confirm (in DOMString text); */
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) = 0;

  /* DOMString prompt ([optional] in DOMString aMessage, [optional] in DOMString aInitial); */
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) = 0;

  /* void print (); */
  NS_IMETHOD Print(void) = 0;

  /* nsIVariant showModalDialog (in DOMString aURI, [optional] in nsIVariant aArgs, [optional] in DOMString aOptions); */
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant * *_retval) = 0;

  /* [binaryname(PostMessageMoz),implicit_jscontext] void postMessage (in jsval message, in DOMString targetOrigin, [optional] in jsval transfer); */
  NS_IMETHOD PostMessageMoz(const JS::Value & message, const nsAString & targetOrigin, const JS::Value & transfer, JSContext* cx) = 0;

  /* DOMString atob (in DOMString aAsciiString); */
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) = 0;

  /* DOMString btoa (in DOMString aBase64Data); */
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) = 0;

  /* readonly attribute nsIDOMStorage sessionStorage; */
  NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage) = 0;

  /* readonly attribute nsIDOMStorage localStorage; */
  NS_IMETHOD GetLocalStorage(nsIDOMStorage * *aLocalStorage) = 0;

  /* nsISelection getSelection (); */
  NS_IMETHOD GetSelection(nsISelection * *_retval) = 0;

  /* nsIDOMMediaQueryList matchMedia (in DOMString media_query_list); */
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsIDOMMediaQueryList * *_retval) = 0;

  /* readonly attribute nsIDOMScreen screen; */
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) = 0;

  /* attribute long innerWidth; */
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) = 0;
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) = 0;

  /* attribute long innerHeight; */
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) = 0;
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) = 0;

  /* readonly attribute long scrollX; */
  NS_IMETHOD GetScrollX(int32_t *aScrollX) = 0;

  /* readonly attribute long pageXOffset; */
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) = 0;

  /* readonly attribute long scrollY; */
  NS_IMETHOD GetScrollY(int32_t *aScrollY) = 0;

  /* readonly attribute long pageYOffset; */
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) = 0;

  /* void scroll (in long xScroll, in long yScroll); */
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) = 0;

  /* void scrollTo (in long xScroll, in long yScroll); */
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) = 0;

  /* void scrollBy (in long xScrollDif, in long yScrollDif); */
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) = 0;

  /* attribute long screenX; */
  NS_IMETHOD GetScreenX(int32_t *aScreenX) = 0;
  NS_IMETHOD SetScreenX(int32_t aScreenX) = 0;

  /* attribute long screenY; */
  NS_IMETHOD GetScreenY(int32_t *aScreenY) = 0;
  NS_IMETHOD SetScreenY(int32_t aScreenY) = 0;

  /* attribute long outerWidth; */
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) = 0;
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) = 0;

  /* attribute long outerHeight; */
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) = 0;
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) = 0;

  /* nsIDOMCSSStyleDeclaration getComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) = 0;

  /* nsIDOMCSSStyleDeclaration getDefaultComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) = 0;

  /* [noscript] readonly attribute nsIDOMEventTarget windowRoot; */
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) = 0;

  /* [noscript] readonly attribute nsIDOMWindowCollection frames; */
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) = 0;

  /* [noscript] attribute float textZoom; */
  NS_IMETHOD GetTextZoom(float *aTextZoom) = 0;
  NS_IMETHOD SetTextZoom(float aTextZoom) = 0;

  /* void scrollByLines (in long numLines); */
  NS_IMETHOD ScrollByLines(int32_t numLines) = 0;

  /* void scrollByPages (in long numPages); */
  NS_IMETHOD ScrollByPages(int32_t numPages) = 0;

  /* void sizeToContent (); */
  NS_IMETHOD SizeToContent(void) = 0;

  /* readonly attribute nsIDOMWindow content; */
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) = 0;

  /* [noscript] readonly attribute nsIPrompt prompter; */
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) = 0;

  /* readonly attribute boolean closed; */
  NS_IMETHOD GetClosed(bool *aClosed) = 0;

  /* readonly attribute nsIControllers controllers; */
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) = 0;

  /* attribute DOMString defaultStatus; */
  NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus) = 0;
  NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus) = 0;

  /* readonly attribute float mozInnerScreenX; */
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) = 0;

  /* readonly attribute float mozInnerScreenY; */
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) = 0;

  /* readonly attribute float devicePixelRatio; */
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) = 0;

  /* readonly attribute long scrollMaxX; */
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) = 0;

  /* readonly attribute long scrollMaxY; */
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) = 0;

  /* attribute boolean fullScreen; */
  NS_IMETHOD GetFullScreen(bool *aFullScreen) = 0;
  NS_IMETHOD SetFullScreen(bool aFullScreen) = 0;

  /* void back (); */
  NS_IMETHOD Back(void) = 0;

  /* void forward (); */
  NS_IMETHOD Forward(void) = 0;

  /* void home (); */
  NS_IMETHOD Home(void) = 0;

  /* void moveTo (in long xPos, in long yPos); */
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) = 0;

  /* void moveBy (in long xDif, in long yDif); */
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) = 0;

  /* void resizeTo (in long width, in long height); */
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) = 0;

  /* void resizeBy (in long widthDif, in long heightDif); */
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) = 0;

  /* [noscript] nsIDOMWindow open (in DOMString url, in DOMString name, in DOMString options); */
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) = 0;

  /* [noscript] nsIDOMWindow openDialog (in DOMString url, in DOMString name, in DOMString options, in nsISupports aExtraArgument); */
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) = 0;

  /* void updateCommands (in DOMString action); */
  NS_IMETHOD UpdateCommands(const nsAString & action) = 0;

  /* boolean find ([optional] in DOMString str, [optional] in boolean caseSensitive, [optional] in boolean backwards, [optional] in boolean wrapAround, [optional] in boolean wholeWord, [optional] in boolean searchInFrames, [optional] in boolean showDialog); */
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) = 0;

  /* readonly attribute unsigned long long mozPaintCount; */
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) = 0;

  /* long mozRequestAnimationFrame ([optional] in nsIFrameRequestCallback aCallback); */
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) = 0;

  /* void mozCancelAnimationFrame (in long aHandle); */
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) = 0;

  /* void mozCancelRequestAnimationFrame (in long aHandle); */
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) = 0;

  /* readonly attribute long long mozAnimationStartTime; */
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) = 0;

  /* [implicit_jscontext] attribute jsval onafterprint; */
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint) = 0;
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint) = 0;

  /* [implicit_jscontext] attribute jsval onbeforeprint; */
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint) = 0;
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint) = 0;

  /* [implicit_jscontext] attribute jsval onbeforeunload; */
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload) = 0;
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload) = 0;

  /* [implicit_jscontext] attribute jsval onhashchange; */
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange) = 0;
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange) = 0;

  /* [implicit_jscontext] attribute jsval onmessage; */
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage) = 0;
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage) = 0;

  /* [implicit_jscontext] attribute jsval onoffline; */
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline) = 0;
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline) = 0;

  /* [implicit_jscontext] attribute jsval ononline; */
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline) = 0;
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline) = 0;

  /* [implicit_jscontext] attribute jsval onpopstate; */
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate) = 0;
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate) = 0;

  /* [implicit_jscontext] attribute jsval onpagehide; */
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide) = 0;
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide) = 0;

  /* [implicit_jscontext] attribute jsval onpageshow; */
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow) = 0;
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow) = 0;

  /* [implicit_jscontext] attribute jsval onresize; */
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize) = 0;
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize) = 0;

  /* [implicit_jscontext] attribute jsval onunload; */
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload) = 0;
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload) = 0;

  /* [implicit_jscontext] attribute jsval ondevicemotion; */
  NS_IMETHOD GetOndevicemotion(JSContext* cx, JS::Value *aOndevicemotion) = 0;
  NS_IMETHOD SetOndevicemotion(JSContext* cx, const JS::Value & aOndevicemotion) = 0;

  /* [implicit_jscontext] attribute jsval ondeviceorientation; */
  NS_IMETHOD GetOndeviceorientation(JSContext* cx, JS::Value *aOndeviceorientation) = 0;
  NS_IMETHOD SetOndeviceorientation(JSContext* cx, const JS::Value & aOndeviceorientation) = 0;

  /* [implicit_jscontext] attribute jsval ondeviceproximity; */
  NS_IMETHOD GetOndeviceproximity(JSContext* cx, JS::Value *aOndeviceproximity) = 0;
  NS_IMETHOD SetOndeviceproximity(JSContext* cx, const JS::Value & aOndeviceproximity) = 0;

  /* [implicit_jscontext] attribute jsval onuserproximity; */
  NS_IMETHOD GetOnuserproximity(JSContext* cx, JS::Value *aOnuserproximity) = 0;
  NS_IMETHOD SetOnuserproximity(JSContext* cx, const JS::Value & aOnuserproximity) = 0;

  /* [implicit_jscontext] attribute jsval ondevicelight; */
  NS_IMETHOD GetOndevicelight(JSContext* cx, JS::Value *aOndevicelight) = 0;
  NS_IMETHOD SetOndevicelight(JSContext* cx, const JS::Value & aOndevicelight) = 0;

  /* [implicit_jscontext] attribute jsval onmouseenter; */
  NS_IMETHOD GetOnmouseenter(JSContext* cx, JS::Value *aOnmouseenter) = 0;
  NS_IMETHOD SetOnmouseenter(JSContext* cx, const JS::Value & aOnmouseenter) = 0;

  /* [implicit_jscontext] attribute jsval onmouseleave; */
  NS_IMETHOD GetOnmouseleave(JSContext* cx, JS::Value *aOnmouseleave) = 0;
  NS_IMETHOD SetOnmouseleave(JSContext* cx, const JS::Value & aOnmouseleave) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindow, NS_IDOMWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOW \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow); \
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf); \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation); \
  NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory); \
  NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar); \
  NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar); \
  NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar); \
  NS_IMETHOD GetScrollbars(nsIDOMBarProp * *aScrollbars); \
  NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar); \
  NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar); \
  NS_IMETHOD GetStatus(nsAString & aStatus); \
  NS_IMETHOD SetStatus(const nsAString & aStatus); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Stop(void); \
  NS_IMETHOD Focus(void); \
  NS_IMETHOD Blur(void); \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop); \
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop); \
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent); \
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent); \
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpener); \
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpener); \
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement); \
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement); \
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator); \
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache); \
  NS_IMETHOD Alert(const nsAString & text); \
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval); \
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval); \
  NS_IMETHOD Print(void); \
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant * *_retval); \
  NS_IMETHOD PostMessageMoz(const JS::Value & message, const nsAString & targetOrigin, const JS::Value & transfer, JSContext* cx); \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval); \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval); \
  NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage); \
  NS_IMETHOD GetLocalStorage(nsIDOMStorage * *aLocalStorage); \
  NS_IMETHOD GetSelection(nsISelection * *_retval); \
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsIDOMMediaQueryList * *_retval); \
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen); \
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth); \
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth); \
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight); \
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight); \
  NS_IMETHOD GetScrollX(int32_t *aScrollX); \
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset); \
  NS_IMETHOD GetScrollY(int32_t *aScrollY); \
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset); \
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll); \
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll); \
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif); \
  NS_IMETHOD GetScreenX(int32_t *aScreenX); \
  NS_IMETHOD SetScreenX(int32_t aScreenX); \
  NS_IMETHOD GetScreenY(int32_t *aScreenY); \
  NS_IMETHOD SetScreenY(int32_t aScreenY); \
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth); \
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth); \
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight); \
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight); \
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval); \
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval); \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot); \
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames); \
  NS_IMETHOD GetTextZoom(float *aTextZoom); \
  NS_IMETHOD SetTextZoom(float aTextZoom); \
  NS_IMETHOD ScrollByLines(int32_t numLines); \
  NS_IMETHOD ScrollByPages(int32_t numPages); \
  NS_IMETHOD SizeToContent(void); \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent); \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter); \
  NS_IMETHOD GetClosed(bool *aClosed); \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers); \
  NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus); \
  NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus); \
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX); \
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY); \
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio); \
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX); \
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY); \
  NS_IMETHOD GetFullScreen(bool *aFullScreen); \
  NS_IMETHOD SetFullScreen(bool aFullScreen); \
  NS_IMETHOD Back(void); \
  NS_IMETHOD Forward(void); \
  NS_IMETHOD Home(void); \
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos); \
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif); \
  NS_IMETHOD ResizeTo(int32_t width, int32_t height); \
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif); \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval); \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval); \
  NS_IMETHOD UpdateCommands(const nsAString & action); \
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval); \
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount); \
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval); \
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle); \
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle); \
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime); \
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint); \
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint); \
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint); \
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint); \
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload); \
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload); \
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange); \
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange); \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage); \
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage); \
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline); \
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline); \
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline); \
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline); \
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate); \
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate); \
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide); \
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide); \
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow); \
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow); \
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize); \
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize); \
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload); \
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload); \
  NS_IMETHOD GetOndevicemotion(JSContext* cx, JS::Value *aOndevicemotion); \
  NS_IMETHOD SetOndevicemotion(JSContext* cx, const JS::Value & aOndevicemotion); \
  NS_IMETHOD GetOndeviceorientation(JSContext* cx, JS::Value *aOndeviceorientation); \
  NS_IMETHOD SetOndeviceorientation(JSContext* cx, const JS::Value & aOndeviceorientation); \
  NS_IMETHOD GetOndeviceproximity(JSContext* cx, JS::Value *aOndeviceproximity); \
  NS_IMETHOD SetOndeviceproximity(JSContext* cx, const JS::Value & aOndeviceproximity); \
  NS_IMETHOD GetOnuserproximity(JSContext* cx, JS::Value *aOnuserproximity); \
  NS_IMETHOD SetOnuserproximity(JSContext* cx, const JS::Value & aOnuserproximity); \
  NS_IMETHOD GetOndevicelight(JSContext* cx, JS::Value *aOndevicelight); \
  NS_IMETHOD SetOndevicelight(JSContext* cx, const JS::Value & aOndevicelight); \
  NS_IMETHOD GetOnmouseenter(JSContext* cx, JS::Value *aOnmouseenter); \
  NS_IMETHOD SetOnmouseenter(JSContext* cx, const JS::Value & aOnmouseenter); \
  NS_IMETHOD GetOnmouseleave(JSContext* cx, JS::Value *aOnmouseleave); \
  NS_IMETHOD SetOnmouseleave(JSContext* cx, const JS::Value & aOnmouseleave); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOW(_to) \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) { return _to GetSelf(aSelf); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) { return _to GetLocation(aLocation); } \
  NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory) { return _to GetHistory(aHistory); } \
  NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar) { return _to GetLocationbar(aLocationbar); } \
  NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar) { return _to GetMenubar(aMenubar); } \
  NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar) { return _to GetPersonalbar(aPersonalbar); } \
  NS_IMETHOD GetScrollbars(nsIDOMBarProp * *aScrollbars) { return _to GetScrollbars(aScrollbars); } \
  NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar) { return _to GetStatusbar(aStatusbar); } \
  NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar) { return _to GetToolbar(aToolbar); } \
  NS_IMETHOD GetStatus(nsAString & aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD SetStatus(const nsAString & aStatus) { return _to SetStatus(aStatus); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_IMETHOD Blur(void) { return _to Blur(); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) { return _to GetScriptableTop(aTop); } \
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) { return _to GetRealTop(aRealTop); } \
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) { return _to GetScriptableParent(aParent); } \
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) { return _to GetRealParent(aRealParent); } \
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpener) { return _to GetOpener(aOpener); } \
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpener) { return _to SetOpener(aOpener); } \
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) { return _to GetScriptableFrameElement(aFrameElement); } \
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) { return _to GetRealFrameElement(aRealFrameElement); } \
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) { return _to GetNavigator(aNavigator); } \
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) { return _to GetApplicationCache(aApplicationCache); } \
  NS_IMETHOD Alert(const nsAString & text) { return _to Alert(text); } \
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) { return _to Confirm(text, _retval); } \
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) { return _to Prompt(aMessage, aInitial, _retval); } \
  NS_IMETHOD Print(void) { return _to Print(); } \
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant * *_retval) { return _to ShowModalDialog(aURI, aArgs, aOptions, _retval); } \
  NS_IMETHOD PostMessageMoz(const JS::Value & message, const nsAString & targetOrigin, const JS::Value & transfer, JSContext* cx) { return _to PostMessageMoz(message, targetOrigin, transfer, cx); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) { return _to Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) { return _to Btoa(aBase64Data, _retval); } \
  NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage) { return _to GetSessionStorage(aSessionStorage); } \
  NS_IMETHOD GetLocalStorage(nsIDOMStorage * *aLocalStorage) { return _to GetLocalStorage(aLocalStorage); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) { return _to GetSelection(_retval); } \
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsIDOMMediaQueryList * *_retval) { return _to MatchMedia(media_query_list, _retval); } \
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) { return _to GetScreen(aScreen); } \
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) { return _to GetInnerWidth(aInnerWidth); } \
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) { return _to SetInnerWidth(aInnerWidth); } \
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) { return _to GetInnerHeight(aInnerHeight); } \
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) { return _to SetInnerHeight(aInnerHeight); } \
  NS_IMETHOD GetScrollX(int32_t *aScrollX) { return _to GetScrollX(aScrollX); } \
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) { return _to GetPageXOffset(aPageXOffset); } \
  NS_IMETHOD GetScrollY(int32_t *aScrollY) { return _to GetScrollY(aScrollY); } \
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) { return _to GetPageYOffset(aPageYOffset); } \
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) { return _to Scroll(xScroll, yScroll); } \
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) { return _to ScrollTo(xScroll, yScroll); } \
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) { return _to ScrollBy(xScrollDif, yScrollDif); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_IMETHOD SetScreenX(int32_t aScreenX) { return _to SetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_IMETHOD SetScreenY(int32_t aScreenY) { return _to SetScreenY(aScreenY); } \
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) { return _to GetOuterWidth(aOuterWidth); } \
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) { return _to SetOuterWidth(aOuterWidth); } \
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) { return _to GetOuterHeight(aOuterHeight); } \
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) { return _to SetOuterHeight(aOuterHeight); } \
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) { return _to GetComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) { return _to GetDefaultComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) { return _to GetWindowRoot(aWindowRoot); } \
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) { return _to GetFrames(aFrames); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) { return _to GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) { return _to SetTextZoom(aTextZoom); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return _to ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) { return _to ScrollByPages(numPages); } \
  NS_IMETHOD SizeToContent(void) { return _to SizeToContent(); } \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return _to GetContent(aContent); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) { return _to GetPrompter(aPrompter); } \
  NS_IMETHOD GetClosed(bool *aClosed) { return _to GetClosed(aClosed); } \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return _to GetControllers(aControllers); } \
  NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus) { return _to GetDefaultStatus(aDefaultStatus); } \
  NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus) { return _to SetDefaultStatus(aDefaultStatus); } \
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) { return _to GetMozInnerScreenX(aMozInnerScreenX); } \
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) { return _to GetMozInnerScreenY(aMozInnerScreenY); } \
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) { return _to GetDevicePixelRatio(aDevicePixelRatio); } \
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) { return _to GetScrollMaxX(aScrollMaxX); } \
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) { return _to GetScrollMaxY(aScrollMaxY); } \
  NS_IMETHOD GetFullScreen(bool *aFullScreen) { return _to GetFullScreen(aFullScreen); } \
  NS_IMETHOD SetFullScreen(bool aFullScreen) { return _to SetFullScreen(aFullScreen); } \
  NS_IMETHOD Back(void) { return _to Back(); } \
  NS_IMETHOD Forward(void) { return _to Forward(); } \
  NS_IMETHOD Home(void) { return _to Home(); } \
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) { return _to MoveTo(xPos, yPos); } \
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) { return _to MoveBy(xDif, yDif); } \
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) { return _to ResizeTo(width, height); } \
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) { return _to ResizeBy(widthDif, heightDif); } \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) { return _to Open(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) { return _to OpenDialog(url, name, options, aExtraArgument, _retval); } \
  NS_IMETHOD UpdateCommands(const nsAString & action) { return _to UpdateCommands(action); } \
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) { return _to Find(str, caseSensitive, backwards, wrapAround, wholeWord, searchInFrames, showDialog, _retval); } \
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) { return _to GetMozPaintCount(aMozPaintCount); } \
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) { return _to MozRequestAnimationFrame(aCallback, _retval); } \
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) { return _to MozCancelAnimationFrame(aHandle); } \
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) { return _to MozCancelRequestAnimationFrame(aHandle); } \
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) { return _to GetMozAnimationStartTime(aMozAnimationStartTime); } \
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint) { return _to GetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint) { return _to SetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint) { return _to GetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint) { return _to SetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload) { return _to GetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload) { return _to SetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange) { return _to GetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange) { return _to SetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage) { return _to GetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage) { return _to SetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline) { return _to GetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline) { return _to SetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline) { return _to GetOnonline(cx, aOnonline); } \
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline) { return _to SetOnonline(cx, aOnonline); } \
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate) { return _to GetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate) { return _to SetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide) { return _to GetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide) { return _to SetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow) { return _to GetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow) { return _to SetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize) { return _to GetOnresize(cx, aOnresize); } \
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize) { return _to SetOnresize(cx, aOnresize); } \
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload) { return _to GetOnunload(cx, aOnunload); } \
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload) { return _to SetOnunload(cx, aOnunload); } \
  NS_IMETHOD GetOndevicemotion(JSContext* cx, JS::Value *aOndevicemotion) { return _to GetOndevicemotion(cx, aOndevicemotion); } \
  NS_IMETHOD SetOndevicemotion(JSContext* cx, const JS::Value & aOndevicemotion) { return _to SetOndevicemotion(cx, aOndevicemotion); } \
  NS_IMETHOD GetOndeviceorientation(JSContext* cx, JS::Value *aOndeviceorientation) { return _to GetOndeviceorientation(cx, aOndeviceorientation); } \
  NS_IMETHOD SetOndeviceorientation(JSContext* cx, const JS::Value & aOndeviceorientation) { return _to SetOndeviceorientation(cx, aOndeviceorientation); } \
  NS_IMETHOD GetOndeviceproximity(JSContext* cx, JS::Value *aOndeviceproximity) { return _to GetOndeviceproximity(cx, aOndeviceproximity); } \
  NS_IMETHOD SetOndeviceproximity(JSContext* cx, const JS::Value & aOndeviceproximity) { return _to SetOndeviceproximity(cx, aOndeviceproximity); } \
  NS_IMETHOD GetOnuserproximity(JSContext* cx, JS::Value *aOnuserproximity) { return _to GetOnuserproximity(cx, aOnuserproximity); } \
  NS_IMETHOD SetOnuserproximity(JSContext* cx, const JS::Value & aOnuserproximity) { return _to SetOnuserproximity(cx, aOnuserproximity); } \
  NS_IMETHOD GetOndevicelight(JSContext* cx, JS::Value *aOndevicelight) { return _to GetOndevicelight(cx, aOndevicelight); } \
  NS_IMETHOD SetOndevicelight(JSContext* cx, const JS::Value & aOndevicelight) { return _to SetOndevicelight(cx, aOndevicelight); } \
  NS_IMETHOD GetOnmouseenter(JSContext* cx, JS::Value *aOnmouseenter) { return _to GetOnmouseenter(cx, aOnmouseenter); } \
  NS_IMETHOD SetOnmouseenter(JSContext* cx, const JS::Value & aOnmouseenter) { return _to SetOnmouseenter(cx, aOnmouseenter); } \
  NS_IMETHOD GetOnmouseleave(JSContext* cx, JS::Value *aOnmouseleave) { return _to GetOnmouseleave(cx, aOnmouseleave); } \
  NS_IMETHOD SetOnmouseleave(JSContext* cx, const JS::Value & aOnmouseleave) { return _to SetOnmouseleave(cx, aOnmouseleave); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOW(_to) \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelf(aSelf); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_IMETHOD GetHistory(nsIDOMHistory * *aHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistory(aHistory); } \
  NS_IMETHOD GetLocationbar(nsIDOMBarProp * *aLocationbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocationbar(aLocationbar); } \
  NS_IMETHOD GetMenubar(nsIDOMBarProp * *aMenubar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMenubar(aMenubar); } \
  NS_IMETHOD GetPersonalbar(nsIDOMBarProp * *aPersonalbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalbar(aPersonalbar); } \
  NS_IMETHOD GetScrollbars(nsIDOMBarProp * *aScrollbars) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollbars(aScrollbars); } \
  NS_IMETHOD GetStatusbar(nsIDOMBarProp * *aStatusbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusbar(aStatusbar); } \
  NS_IMETHOD GetToolbar(nsIDOMBarProp * *aToolbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToolbar(aToolbar); } \
  NS_IMETHOD GetStatus(nsAString & aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD SetStatus(const nsAString & aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatus(aStatus); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableTop(aTop); } \
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealTop(aRealTop); } \
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableParent(aParent); } \
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealParent(aRealParent); } \
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOpener(aOpener); } \
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOpener(aOpener); } \
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableFrameElement(aFrameElement); } \
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealFrameElement(aRealFrameElement); } \
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNavigator(aNavigator); } \
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCache(aApplicationCache); } \
  NS_IMETHOD Alert(const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->Alert(text); } \
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(text, _retval); } \
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(aMessage, aInitial, _retval); } \
  NS_IMETHOD Print(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(); } \
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowModalDialog(aURI, aArgs, aOptions, _retval); } \
  NS_IMETHOD PostMessageMoz(const JS::Value & message, const nsAString & targetOrigin, const JS::Value & transfer, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessageMoz(message, targetOrigin, transfer, cx); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Btoa(aBase64Data, _retval); } \
  NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorage(aSessionStorage); } \
  NS_IMETHOD GetLocalStorage(nsIDOMStorage * *aLocalStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStorage(aLocalStorage); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(_retval); } \
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsIDOMMediaQueryList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MatchMedia(media_query_list, _retval); } \
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreen(aScreen); } \
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerWidth(aInnerWidth); } \
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerWidth(aInnerWidth); } \
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHeight(aInnerHeight); } \
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerHeight(aInnerHeight); } \
  NS_IMETHOD GetScrollX(int32_t *aScrollX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollX(aScrollX); } \
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageXOffset(aPageXOffset); } \
  NS_IMETHOD GetScrollY(int32_t *aScrollY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollY(aScrollY); } \
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageYOffset(aPageYOffset); } \
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->Scroll(xScroll, yScroll); } \
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(xScroll, yScroll); } \
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollBy(xScrollDif, yScrollDif); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_IMETHOD SetScreenX(int32_t aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_IMETHOD SetScreenY(int32_t aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenY(aScreenY); } \
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWidth(aOuterWidth); } \
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterWidth(aOuterWidth); } \
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterHeight(aOuterHeight); } \
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterHeight(aOuterHeight); } \
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowRoot(aWindowRoot); } \
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrames(aFrames); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextZoom(aTextZoom); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByPages(numPages); } \
  NS_IMETHOD SizeToContent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeToContent(); } \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrompter(aPrompter); } \
  NS_IMETHOD GetClosed(bool *aClosed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosed(aClosed); } \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_IMETHOD GetDefaultStatus(nsAString & aDefaultStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultStatus(aDefaultStatus); } \
  NS_IMETHOD SetDefaultStatus(const nsAString & aDefaultStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultStatus(aDefaultStatus); } \
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozInnerScreenX(aMozInnerScreenX); } \
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozInnerScreenY(aMozInnerScreenY); } \
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDevicePixelRatio(aDevicePixelRatio); } \
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollMaxX(aScrollMaxX); } \
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollMaxY(aScrollMaxY); } \
  NS_IMETHOD GetFullScreen(bool *aFullScreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullScreen(aFullScreen); } \
  NS_IMETHOD SetFullScreen(bool aFullScreen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullScreen(aFullScreen); } \
  NS_IMETHOD Back(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Back(); } \
  NS_IMETHOD Forward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Forward(); } \
  NS_IMETHOD Home(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Home(); } \
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveTo(xPos, yPos); } \
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveBy(xDif, yDif); } \
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeTo(width, height); } \
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeBy(widthDif, heightDif); } \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(url, name, options, aExtraArgument, _retval); } \
  NS_IMETHOD UpdateCommands(const nsAString & action) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCommands(action); } \
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(str, caseSensitive, backwards, wrapAround, wholeWord, searchInFrames, showDialog, _retval); } \
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPaintCount(aMozPaintCount); } \
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRequestAnimationFrame(aCallback, _retval); } \
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCancelAnimationFrame(aHandle); } \
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCancelRequestAnimationFrame(aHandle); } \
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAnimationStartTime(aMozAnimationStartTime); } \
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnonline(cx, aOnonline); } \
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnonline(cx, aOnonline); } \
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnresize(cx, aOnresize); } \
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnresize(cx, aOnresize); } \
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnunload(cx, aOnunload); } \
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnunload(cx, aOnunload); } \
  NS_IMETHOD GetOndevicemotion(JSContext* cx, JS::Value *aOndevicemotion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndevicemotion(cx, aOndevicemotion); } \
  NS_IMETHOD SetOndevicemotion(JSContext* cx, const JS::Value & aOndevicemotion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndevicemotion(cx, aOndevicemotion); } \
  NS_IMETHOD GetOndeviceorientation(JSContext* cx, JS::Value *aOndeviceorientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeviceorientation(cx, aOndeviceorientation); } \
  NS_IMETHOD SetOndeviceorientation(JSContext* cx, const JS::Value & aOndeviceorientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeviceorientation(cx, aOndeviceorientation); } \
  NS_IMETHOD GetOndeviceproximity(JSContext* cx, JS::Value *aOndeviceproximity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeviceproximity(cx, aOndeviceproximity); } \
  NS_IMETHOD SetOndeviceproximity(JSContext* cx, const JS::Value & aOndeviceproximity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeviceproximity(cx, aOndeviceproximity); } \
  NS_IMETHOD GetOnuserproximity(JSContext* cx, JS::Value *aOnuserproximity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnuserproximity(cx, aOnuserproximity); } \
  NS_IMETHOD SetOnuserproximity(JSContext* cx, const JS::Value & aOnuserproximity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnuserproximity(cx, aOnuserproximity); } \
  NS_IMETHOD GetOndevicelight(JSContext* cx, JS::Value *aOndevicelight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndevicelight(cx, aOndevicelight); } \
  NS_IMETHOD SetOndevicelight(JSContext* cx, const JS::Value & aOndevicelight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndevicelight(cx, aOndevicelight); } \
  NS_IMETHOD GetOnmouseenter(JSContext* cx, JS::Value *aOnmouseenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseenter(cx, aOnmouseenter); } \
  NS_IMETHOD SetOnmouseenter(JSContext* cx, const JS::Value & aOnmouseenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseenter(cx, aOnmouseenter); } \
  NS_IMETHOD GetOnmouseleave(JSContext* cx, JS::Value *aOnmouseleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmouseleave(cx, aOnmouseleave); } \
  NS_IMETHOD SetOnmouseleave(JSContext* cx, const JS::Value & aOnmouseleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmouseleave(cx, aOnmouseleave); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindow : public nsIDOMWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOW

  nsDOMWindow();

private:
  ~nsDOMWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindow, nsIDOMWindow)

nsDOMWindow::nsDOMWindow()
{
  /* member initializers and constructor code */
}

nsDOMWindow::~nsDOMWindow()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsDOMWindow::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow self; */
NS_IMETHODIMP nsDOMWindow::GetSelf(nsIDOMWindow * *aSelf)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsDOMWindow::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMWindow::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLocation location; */
NS_IMETHODIMP nsDOMWindow::GetLocation(nsIDOMLocation * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHistory history; */
NS_IMETHODIMP nsDOMWindow::GetHistory(nsIDOMHistory * *aHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp locationbar; */
NS_IMETHODIMP nsDOMWindow::GetLocationbar(nsIDOMBarProp * *aLocationbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp menubar; */
NS_IMETHODIMP nsDOMWindow::GetMenubar(nsIDOMBarProp * *aMenubar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp personalbar; */
NS_IMETHODIMP nsDOMWindow::GetPersonalbar(nsIDOMBarProp * *aPersonalbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp scrollbars; */
NS_IMETHODIMP nsDOMWindow::GetScrollbars(nsIDOMBarProp * *aScrollbars)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp statusbar; */
NS_IMETHODIMP nsDOMWindow::GetStatusbar(nsIDOMBarProp * *aStatusbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMBarProp toolbar; */
NS_IMETHODIMP nsDOMWindow::GetToolbar(nsIDOMBarProp * *aToolbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString status; */
NS_IMETHODIMP nsDOMWindow::GetStatus(nsAString & aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetStatus(const nsAString & aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMWindow::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsDOMWindow::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMWindow::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMWindow::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMWindow::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableTop)] readonly attribute nsIDOMWindow top; */
NS_IMETHODIMP nsDOMWindow::GetScriptableTop(nsIDOMWindow * *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindow realTop; */
NS_IMETHODIMP nsDOMWindow::GetRealTop(nsIDOMWindow * *aRealTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableParent)] readonly attribute nsIDOMWindow parent; */
NS_IMETHODIMP nsDOMWindow::GetScriptableParent(nsIDOMWindow * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindow realParent; */
NS_IMETHODIMP nsDOMWindow::GetRealParent(nsIDOMWindow * *aRealParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow opener; */
NS_IMETHODIMP nsDOMWindow::GetOpener(nsIDOMWindow * *aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOpener(nsIDOMWindow *aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableFrameElement)] readonly attribute nsIDOMElement frameElement; */
NS_IMETHODIMP nsDOMWindow::GetScriptableFrameElement(nsIDOMElement * *aFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMElement realFrameElement; */
NS_IMETHODIMP nsDOMWindow::GetRealFrameElement(nsIDOMElement * *aRealFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNavigator navigator; */
NS_IMETHODIMP nsDOMWindow::GetNavigator(nsIDOMNavigator * *aNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMOfflineResourceList applicationCache; */
NS_IMETHODIMP nsDOMWindow::GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void alert (in DOMString text); */
NS_IMETHODIMP nsDOMWindow::Alert(const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirm (in DOMString text); */
NS_IMETHODIMP nsDOMWindow::Confirm(const nsAString & text, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString prompt ([optional] in DOMString aMessage, [optional] in DOMString aInitial); */
NS_IMETHODIMP nsDOMWindow::Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (); */
NS_IMETHODIMP nsDOMWindow::Print()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant showModalDialog (in DOMString aURI, [optional] in nsIVariant aArgs, [optional] in DOMString aOptions); */
NS_IMETHODIMP nsDOMWindow::ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(PostMessageMoz),implicit_jscontext] void postMessage (in jsval message, in DOMString targetOrigin, [optional] in jsval transfer); */
NS_IMETHODIMP nsDOMWindow::PostMessageMoz(const JS::Value & message, const nsAString & targetOrigin, const JS::Value & transfer, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString atob (in DOMString aAsciiString); */
NS_IMETHODIMP nsDOMWindow::Atob(const nsAString & aAsciiString, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString btoa (in DOMString aBase64Data); */
NS_IMETHODIMP nsDOMWindow::Btoa(const nsAString & aBase64Data, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorage sessionStorage; */
NS_IMETHODIMP nsDOMWindow::GetSessionStorage(nsIDOMStorage * *aSessionStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorage localStorage; */
NS_IMETHODIMP nsDOMWindow::GetLocalStorage(nsIDOMStorage * *aLocalStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (); */
NS_IMETHODIMP nsDOMWindow::GetSelection(nsISelection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMediaQueryList matchMedia (in DOMString media_query_list); */
NS_IMETHODIMP nsDOMWindow::MatchMedia(const nsAString & media_query_list, nsIDOMMediaQueryList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMScreen screen; */
NS_IMETHODIMP nsDOMWindow::GetScreen(nsIDOMScreen * *aScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long innerWidth; */
NS_IMETHODIMP nsDOMWindow::GetInnerWidth(int32_t *aInnerWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetInnerWidth(int32_t aInnerWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long innerHeight; */
NS_IMETHODIMP nsDOMWindow::GetInnerHeight(int32_t *aInnerHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetInnerHeight(int32_t aInnerHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollX; */
NS_IMETHODIMP nsDOMWindow::GetScrollX(int32_t *aScrollX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageXOffset; */
NS_IMETHODIMP nsDOMWindow::GetPageXOffset(int32_t *aPageXOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollY; */
NS_IMETHODIMP nsDOMWindow::GetScrollY(int32_t *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageYOffset; */
NS_IMETHODIMP nsDOMWindow::GetPageYOffset(int32_t *aPageYOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scroll (in long xScroll, in long yScroll); */
NS_IMETHODIMP nsDOMWindow::Scroll(int32_t xScroll, int32_t yScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollTo (in long xScroll, in long yScroll); */
NS_IMETHODIMP nsDOMWindow::ScrollTo(int32_t xScroll, int32_t yScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollBy (in long xScrollDif, in long yScrollDif); */
NS_IMETHODIMP nsDOMWindow::ScrollBy(int32_t xScrollDif, int32_t yScrollDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long screenX; */
NS_IMETHODIMP nsDOMWindow::GetScreenX(int32_t *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetScreenX(int32_t aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long screenY; */
NS_IMETHODIMP nsDOMWindow::GetScreenY(int32_t *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetScreenY(int32_t aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long outerWidth; */
NS_IMETHODIMP nsDOMWindow::GetOuterWidth(int32_t *aOuterWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOuterWidth(int32_t aOuterWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long outerHeight; */
NS_IMETHODIMP nsDOMWindow::GetOuterHeight(int32_t *aOuterHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOuterHeight(int32_t aOuterHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSStyleDeclaration getComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
NS_IMETHODIMP nsDOMWindow::GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSStyleDeclaration getDefaultComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
NS_IMETHODIMP nsDOMWindow::GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMEventTarget windowRoot; */
NS_IMETHODIMP nsDOMWindow::GetWindowRoot(nsIDOMEventTarget * *aWindowRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindowCollection frames; */
NS_IMETHODIMP nsDOMWindow::GetFrames(nsIDOMWindowCollection * *aFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute float textZoom; */
NS_IMETHODIMP nsDOMWindow::GetTextZoom(float *aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetTextZoom(float aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsDOMWindow::ScrollByLines(int32_t numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByPages (in long numPages); */
NS_IMETHODIMP nsDOMWindow::ScrollByPages(int32_t numPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeToContent (); */
NS_IMETHODIMP nsDOMWindow::SizeToContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow content; */
NS_IMETHODIMP nsDOMWindow::GetContent(nsIDOMWindow * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPrompt prompter; */
NS_IMETHODIMP nsDOMWindow::GetPrompter(nsIPrompt * *aPrompter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean closed; */
NS_IMETHODIMP nsDOMWindow::GetClosed(bool *aClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMWindow::GetControllers(nsIControllers * *aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString defaultStatus; */
NS_IMETHODIMP nsDOMWindow::GetDefaultStatus(nsAString & aDefaultStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetDefaultStatus(const nsAString & aDefaultStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float mozInnerScreenX; */
NS_IMETHODIMP nsDOMWindow::GetMozInnerScreenX(float *aMozInnerScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float mozInnerScreenY; */
NS_IMETHODIMP nsDOMWindow::GetMozInnerScreenY(float *aMozInnerScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float devicePixelRatio; */
NS_IMETHODIMP nsDOMWindow::GetDevicePixelRatio(float *aDevicePixelRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollMaxX; */
NS_IMETHODIMP nsDOMWindow::GetScrollMaxX(int32_t *aScrollMaxX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollMaxY; */
NS_IMETHODIMP nsDOMWindow::GetScrollMaxY(int32_t *aScrollMaxY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean fullScreen; */
NS_IMETHODIMP nsDOMWindow::GetFullScreen(bool *aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetFullScreen(bool aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void back (); */
NS_IMETHODIMP nsDOMWindow::Back()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forward (); */
NS_IMETHODIMP nsDOMWindow::Forward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void home (); */
NS_IMETHODIMP nsDOMWindow::Home()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveTo (in long xPos, in long yPos); */
NS_IMETHODIMP nsDOMWindow::MoveTo(int32_t xPos, int32_t yPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveBy (in long xDif, in long yDif); */
NS_IMETHODIMP nsDOMWindow::MoveBy(int32_t xDif, int32_t yDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resizeTo (in long width, in long height); */
NS_IMETHODIMP nsDOMWindow::ResizeTo(int32_t width, int32_t height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resizeBy (in long widthDif, in long heightDif); */
NS_IMETHODIMP nsDOMWindow::ResizeBy(int32_t widthDif, int32_t heightDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMWindow open (in DOMString url, in DOMString name, in DOMString options); */
NS_IMETHODIMP nsDOMWindow::Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMWindow openDialog (in DOMString url, in DOMString name, in DOMString options, in nsISupports aExtraArgument); */
NS_IMETHODIMP nsDOMWindow::OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCommands (in DOMString action); */
NS_IMETHODIMP nsDOMWindow::UpdateCommands(const nsAString & action)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean find ([optional] in DOMString str, [optional] in boolean caseSensitive, [optional] in boolean backwards, [optional] in boolean wrapAround, [optional] in boolean wholeWord, [optional] in boolean searchInFrames, [optional] in boolean showDialog); */
NS_IMETHODIMP nsDOMWindow::Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long mozPaintCount; */
NS_IMETHODIMP nsDOMWindow::GetMozPaintCount(uint64_t *aMozPaintCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long mozRequestAnimationFrame ([optional] in nsIFrameRequestCallback aCallback); */
NS_IMETHODIMP nsDOMWindow::MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozCancelAnimationFrame (in long aHandle); */
NS_IMETHODIMP nsDOMWindow::MozCancelAnimationFrame(int32_t aHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozCancelRequestAnimationFrame (in long aHandle); */
NS_IMETHODIMP nsDOMWindow::MozCancelRequestAnimationFrame(int32_t aHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long mozAnimationStartTime; */
NS_IMETHODIMP nsDOMWindow::GetMozAnimationStartTime(int64_t *aMozAnimationStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onafterprint; */
NS_IMETHODIMP nsDOMWindow::GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforeprint; */
NS_IMETHODIMP nsDOMWindow::GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforeunload; */
NS_IMETHODIMP nsDOMWindow::GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onhashchange; */
NS_IMETHODIMP nsDOMWindow::GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmessage; */
NS_IMETHODIMP nsDOMWindow::GetOnmessage(JSContext* cx, JS::Value *aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnmessage(JSContext* cx, const JS::Value & aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onoffline; */
NS_IMETHODIMP nsDOMWindow::GetOnoffline(JSContext* cx, JS::Value *aOnoffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnoffline(JSContext* cx, const JS::Value & aOnoffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ononline; */
NS_IMETHODIMP nsDOMWindow::GetOnonline(JSContext* cx, JS::Value *aOnonline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnonline(JSContext* cx, const JS::Value & aOnonline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpopstate; */
NS_IMETHODIMP nsDOMWindow::GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpagehide; */
NS_IMETHODIMP nsDOMWindow::GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpageshow; */
NS_IMETHODIMP nsDOMWindow::GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onresize; */
NS_IMETHODIMP nsDOMWindow::GetOnresize(JSContext* cx, JS::Value *aOnresize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnresize(JSContext* cx, const JS::Value & aOnresize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onunload; */
NS_IMETHODIMP nsDOMWindow::GetOnunload(JSContext* cx, JS::Value *aOnunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnunload(JSContext* cx, const JS::Value & aOnunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondevicemotion; */
NS_IMETHODIMP nsDOMWindow::GetOndevicemotion(JSContext* cx, JS::Value *aOndevicemotion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOndevicemotion(JSContext* cx, const JS::Value & aOndevicemotion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeviceorientation; */
NS_IMETHODIMP nsDOMWindow::GetOndeviceorientation(JSContext* cx, JS::Value *aOndeviceorientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOndeviceorientation(JSContext* cx, const JS::Value & aOndeviceorientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeviceproximity; */
NS_IMETHODIMP nsDOMWindow::GetOndeviceproximity(JSContext* cx, JS::Value *aOndeviceproximity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOndeviceproximity(JSContext* cx, const JS::Value & aOndeviceproximity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onuserproximity; */
NS_IMETHODIMP nsDOMWindow::GetOnuserproximity(JSContext* cx, JS::Value *aOnuserproximity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnuserproximity(JSContext* cx, const JS::Value & aOnuserproximity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondevicelight; */
NS_IMETHODIMP nsDOMWindow::GetOndevicelight(JSContext* cx, JS::Value *aOndevicelight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOndevicelight(JSContext* cx, const JS::Value & aOndevicelight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseenter; */
NS_IMETHODIMP nsDOMWindow::GetOnmouseenter(JSContext* cx, JS::Value *aOnmouseenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnmouseenter(JSContext* cx, const JS::Value & aOnmouseenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmouseleave; */
NS_IMETHODIMP nsDOMWindow::GetOnmouseleave(JSContext* cx, JS::Value *aOnmouseleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOnmouseleave(JSContext* cx, const JS::Value & aOnmouseleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMWindowPerformance */
#define NS_IDOMWINDOWPERFORMANCE_IID_STR "2146c906-57f7-486c-a1b4-8cdb57ef577f"

#define NS_IDOMWINDOWPERFORMANCE_IID \
  {0x2146c906, 0x57f7, 0x486c, \
    { 0xa1, 0xb4, 0x8c, 0xdb, 0x57, 0xef, 0x57, 0x7f }}

class NS_NO_VTABLE nsIDOMWindowPerformance : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWPERFORMANCE_IID)

  /* readonly attribute nsISupports performance; */
  NS_IMETHOD GetPerformance(nsISupports * *aPerformance) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowPerformance, NS_IDOMWINDOWPERFORMANCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWPERFORMANCE \
  NS_IMETHOD GetPerformance(nsISupports * *aPerformance); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWPERFORMANCE(_to) \
  NS_IMETHOD GetPerformance(nsISupports * *aPerformance) { return _to GetPerformance(aPerformance); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWPERFORMANCE(_to) \
  NS_IMETHOD GetPerformance(nsISupports * *aPerformance) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPerformance(aPerformance); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowPerformance : public nsIDOMWindowPerformance
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWPERFORMANCE

  nsDOMWindowPerformance();

private:
  ~nsDOMWindowPerformance();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindowPerformance, nsIDOMWindowPerformance)

nsDOMWindowPerformance::nsDOMWindowPerformance()
{
  /* member initializers and constructor code */
}

nsDOMWindowPerformance::~nsDOMWindowPerformance()
{
  /* destructor code */
}

/* readonly attribute nsISupports performance; */
NS_IMETHODIMP nsDOMWindowPerformance::GetPerformance(nsISupports * *aPerformance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWindowCrypto */
#define NS_IWINDOWCRYPTO_IID_STR "2ed9ace1-172c-443f-b92f-c4f74bf8f2c5"

#define NS_IWINDOWCRYPTO_IID \
  {0x2ed9ace1, 0x172c, 0x443f, \
    { 0xb9, 0x2f, 0xc4, 0xf7, 0x4b, 0xf8, 0xf2, 0xc5 }}

class NS_NO_VTABLE nsIWindowCrypto : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWCRYPTO_IID)

  /* readonly attribute nsIDOMCrypto crypto; */
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) = 0;

  /* readonly attribute nsIDOMPkcs11 pkcs11; */
  NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowCrypto, NS_IWINDOWCRYPTO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWCRYPTO \
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto); \
  NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWCRYPTO(_to) \
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) { return _to GetCrypto(aCrypto); } \
  NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11) { return _to GetPkcs11(aPkcs11); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWCRYPTO(_to) \
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrypto(aCrypto); } \
  NS_IMETHOD GetPkcs11(nsIDOMPkcs11 * *aPkcs11) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPkcs11(aPkcs11); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowCrypto : public nsIWindowCrypto
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWCRYPTO

  nsWindowCrypto();

private:
  ~nsWindowCrypto();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowCrypto, nsIWindowCrypto)

nsWindowCrypto::nsWindowCrypto()
{
  /* member initializers and constructor code */
}

nsWindowCrypto::~nsWindowCrypto()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCrypto crypto; */
NS_IMETHODIMP nsWindowCrypto::GetCrypto(nsIDOMCrypto * *aCrypto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMPkcs11 pkcs11; */
NS_IMETHODIMP nsWindowCrypto::GetPkcs11(nsIDOMPkcs11 * *aPkcs11)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMWindowInternal */
#define NS_IDOMWINDOWINTERNAL_IID_STR "a5cd0946-bac1-4606-9aaa-9e68dd0a3279"

#define NS_IDOMWINDOWINTERNAL_IID \
  {0xa5cd0946, 0xbac1, 0x4606, \
    { 0x9a, 0xaa, 0x9e, 0x68, 0xdd, 0x0a, 0x32, 0x79 }}

class NS_NO_VTABLE nsIDOMWindowInternal : public nsIDOMWindow {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWINTERNAL_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowInternal, NS_IDOMWINDOWINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWINTERNAL \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWINTERNAL(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWINTERNAL(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowInternal : public nsIDOMWindowInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWINTERNAL

  nsDOMWindowInternal();

private:
  ~nsDOMWindowInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindowInternal, nsIDOMWindowInternal)

nsDOMWindowInternal::nsDOMWindowInternal()
{
  /* member initializers and constructor code */
}

nsDOMWindowInternal::~nsDOMWindowInternal()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindow_h__ */
