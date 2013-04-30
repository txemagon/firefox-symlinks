/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGSVGElement.idl
 */

#ifndef __gen_nsIDOMSVGSVGElement_h__
#define __gen_nsIDOMSVGSVGElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGRect; /* forward declaration */

class nsIDOMSVGViewSpec; /* forward declaration */

class nsIDOMSVGNumber; /* forward declaration */

class nsIDOMSVGLength; /* forward declaration */

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

/* starting interface:    nsIDOMSVGSVGElement */
#define NS_IDOMSVGSVGELEMENT_IID_STR "4670a204-4ef1-455f-9595-9847b077c624"

#define NS_IDOMSVGSVGELEMENT_IID \
  {0x4670a204, 0x4ef1, 0x455f, \
    { 0x95, 0x95, 0x98, 0x47, 0xb0, 0x77, 0xc6, 0x24 }}

class NS_NO_VTABLE nsIDOMSVGSVGElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSVGELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGRect viewport; */
  NS_IMETHOD GetViewport(nsIDOMSVGRect * *aViewport) = 0;

  /* readonly attribute float pixelUnitToMillimeterX; */
  NS_IMETHOD GetPixelUnitToMillimeterX(float *aPixelUnitToMillimeterX) = 0;

  /* readonly attribute float pixelUnitToMillimeterY; */
  NS_IMETHOD GetPixelUnitToMillimeterY(float *aPixelUnitToMillimeterY) = 0;

  /* readonly attribute float screenPixelToMillimeterX; */
  NS_IMETHOD GetScreenPixelToMillimeterX(float *aScreenPixelToMillimeterX) = 0;

  /* readonly attribute float screenPixelToMillimeterY; */
  NS_IMETHOD GetScreenPixelToMillimeterY(float *aScreenPixelToMillimeterY) = 0;

  /* readonly attribute boolean useCurrentView; */
  NS_IMETHOD GetUseCurrentView(bool *aUseCurrentView) = 0;

  /* readonly attribute nsIDOMSVGViewSpec currentView; */
  NS_IMETHOD GetCurrentView(nsIDOMSVGViewSpec * *aCurrentView) = 0;

  /* attribute float currentScale; */
  NS_IMETHOD GetCurrentScale(float *aCurrentScale) = 0;
  NS_IMETHOD SetCurrentScale(float aCurrentScale) = 0;

  /* readonly attribute nsISupports currentTranslate; */
  NS_IMETHOD GetCurrentTranslate(nsISupports * *aCurrentTranslate) = 0;

  /* unsigned long suspendRedraw (in unsigned long max_wait_milliseconds); */
  NS_IMETHOD SuspendRedraw(uint32_t max_wait_milliseconds, uint32_t *_retval) = 0;

  /* void unsuspendRedraw (in unsigned long suspend_handle_id); */
  NS_IMETHOD UnsuspendRedraw(uint32_t suspend_handle_id) = 0;

  /* void unsuspendRedrawAll (); */
  NS_IMETHOD UnsuspendRedrawAll(void) = 0;

  /* void forceRedraw (); */
  NS_IMETHOD ForceRedraw(void) = 0;

  /* void pauseAnimations (); */
  NS_IMETHOD PauseAnimations(void) = 0;

  /* void unpauseAnimations (); */
  NS_IMETHOD UnpauseAnimations(void) = 0;

  /* boolean animationsPaused (); */
  NS_IMETHOD AnimationsPaused(bool *_retval) = 0;

  /* float getCurrentTime (); */
  NS_IMETHOD GetCurrentTime(float *_retval) = 0;

  /* void setCurrentTime (in float seconds); */
  NS_IMETHOD SetCurrentTime(float seconds) = 0;

  /* nsIDOMNodeList getIntersectionList (in nsIDOMSVGRect rect, in nsIDOMSVGElement referenceElement); */
  NS_IMETHOD GetIntersectionList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval) = 0;

  /* nsIDOMNodeList getEnclosureList (in nsIDOMSVGRect rect, in nsIDOMSVGElement referenceElement); */
  NS_IMETHOD GetEnclosureList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval) = 0;

  /* boolean checkIntersection (in nsIDOMSVGElement element, in nsIDOMSVGRect rect); */
  NS_IMETHOD CheckIntersection(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval) = 0;

  /* boolean checkEnclosure (in nsIDOMSVGElement element, in nsIDOMSVGRect rect); */
  NS_IMETHOD CheckEnclosure(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval) = 0;

  /* void deSelectAll (); */
  NS_IMETHOD DeSelectAll(void) = 0;

  /* nsIDOMSVGNumber createSVGNumber (); */
  NS_IMETHOD CreateSVGNumber(nsIDOMSVGNumber * *_retval) = 0;

  /* nsIDOMSVGLength createSVGLength (); */
  NS_IMETHOD CreateSVGLength(nsIDOMSVGLength * *_retval) = 0;

  /* nsISupports createSVGAngle (); */
  NS_IMETHOD CreateSVGAngle(nsISupports * *_retval) = 0;

  /* nsISupports createSVGPoint (); */
  NS_IMETHOD CreateSVGPoint(nsISupports * *_retval) = 0;

  /* nsISupports createSVGMatrix (); */
  NS_IMETHOD CreateSVGMatrix(nsISupports * *_retval) = 0;

  /* nsIDOMSVGRect createSVGRect (); */
  NS_IMETHOD CreateSVGRect(nsIDOMSVGRect * *_retval) = 0;

  /* nsISupports createSVGTransform (); */
  NS_IMETHOD CreateSVGTransform(nsISupports * *_retval) = 0;

  /* nsISupports createSVGTransformFromMatrix (in nsISupports matrix); */
  NS_IMETHOD CreateSVGTransformFromMatrix(nsISupports *matrix, nsISupports * *_retval) = 0;

  /* nsIDOMElement getElementById (in DOMString elementId); */
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGSVGElement, NS_IDOMSVGSVGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSVGELEMENT \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_IMETHOD GetViewport(nsIDOMSVGRect * *aViewport); \
  NS_IMETHOD GetPixelUnitToMillimeterX(float *aPixelUnitToMillimeterX); \
  NS_IMETHOD GetPixelUnitToMillimeterY(float *aPixelUnitToMillimeterY); \
  NS_IMETHOD GetScreenPixelToMillimeterX(float *aScreenPixelToMillimeterX); \
  NS_IMETHOD GetScreenPixelToMillimeterY(float *aScreenPixelToMillimeterY); \
  NS_IMETHOD GetUseCurrentView(bool *aUseCurrentView); \
  NS_IMETHOD GetCurrentView(nsIDOMSVGViewSpec * *aCurrentView); \
  NS_IMETHOD GetCurrentScale(float *aCurrentScale); \
  NS_IMETHOD SetCurrentScale(float aCurrentScale); \
  NS_IMETHOD GetCurrentTranslate(nsISupports * *aCurrentTranslate); \
  NS_IMETHOD SuspendRedraw(uint32_t max_wait_milliseconds, uint32_t *_retval); \
  NS_IMETHOD UnsuspendRedraw(uint32_t suspend_handle_id); \
  NS_IMETHOD UnsuspendRedrawAll(void); \
  NS_IMETHOD ForceRedraw(void); \
  NS_IMETHOD PauseAnimations(void); \
  NS_IMETHOD UnpauseAnimations(void); \
  NS_IMETHOD AnimationsPaused(bool *_retval); \
  NS_IMETHOD GetCurrentTime(float *_retval); \
  NS_IMETHOD SetCurrentTime(float seconds); \
  NS_IMETHOD GetIntersectionList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval); \
  NS_IMETHOD GetEnclosureList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval); \
  NS_IMETHOD CheckIntersection(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval); \
  NS_IMETHOD CheckEnclosure(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval); \
  NS_IMETHOD DeSelectAll(void); \
  NS_IMETHOD CreateSVGNumber(nsIDOMSVGNumber * *_retval); \
  NS_IMETHOD CreateSVGLength(nsIDOMSVGLength * *_retval); \
  NS_IMETHOD CreateSVGAngle(nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPoint(nsISupports * *_retval); \
  NS_IMETHOD CreateSVGMatrix(nsISupports * *_retval); \
  NS_IMETHOD CreateSVGRect(nsIDOMSVGRect * *_retval); \
  NS_IMETHOD CreateSVGTransform(nsISupports * *_retval); \
  NS_IMETHOD CreateSVGTransformFromMatrix(nsISupports *matrix, nsISupports * *_retval); \
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSVGELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetViewport(nsIDOMSVGRect * *aViewport) { return _to GetViewport(aViewport); } \
  NS_IMETHOD GetPixelUnitToMillimeterX(float *aPixelUnitToMillimeterX) { return _to GetPixelUnitToMillimeterX(aPixelUnitToMillimeterX); } \
  NS_IMETHOD GetPixelUnitToMillimeterY(float *aPixelUnitToMillimeterY) { return _to GetPixelUnitToMillimeterY(aPixelUnitToMillimeterY); } \
  NS_IMETHOD GetScreenPixelToMillimeterX(float *aScreenPixelToMillimeterX) { return _to GetScreenPixelToMillimeterX(aScreenPixelToMillimeterX); } \
  NS_IMETHOD GetScreenPixelToMillimeterY(float *aScreenPixelToMillimeterY) { return _to GetScreenPixelToMillimeterY(aScreenPixelToMillimeterY); } \
  NS_IMETHOD GetUseCurrentView(bool *aUseCurrentView) { return _to GetUseCurrentView(aUseCurrentView); } \
  NS_IMETHOD GetCurrentView(nsIDOMSVGViewSpec * *aCurrentView) { return _to GetCurrentView(aCurrentView); } \
  NS_IMETHOD GetCurrentScale(float *aCurrentScale) { return _to GetCurrentScale(aCurrentScale); } \
  NS_IMETHOD SetCurrentScale(float aCurrentScale) { return _to SetCurrentScale(aCurrentScale); } \
  NS_IMETHOD GetCurrentTranslate(nsISupports * *aCurrentTranslate) { return _to GetCurrentTranslate(aCurrentTranslate); } \
  NS_IMETHOD SuspendRedraw(uint32_t max_wait_milliseconds, uint32_t *_retval) { return _to SuspendRedraw(max_wait_milliseconds, _retval); } \
  NS_IMETHOD UnsuspendRedraw(uint32_t suspend_handle_id) { return _to UnsuspendRedraw(suspend_handle_id); } \
  NS_IMETHOD UnsuspendRedrawAll(void) { return _to UnsuspendRedrawAll(); } \
  NS_IMETHOD ForceRedraw(void) { return _to ForceRedraw(); } \
  NS_IMETHOD PauseAnimations(void) { return _to PauseAnimations(); } \
  NS_IMETHOD UnpauseAnimations(void) { return _to UnpauseAnimations(); } \
  NS_IMETHOD AnimationsPaused(bool *_retval) { return _to AnimationsPaused(_retval); } \
  NS_IMETHOD GetCurrentTime(float *_retval) { return _to GetCurrentTime(_retval); } \
  NS_IMETHOD SetCurrentTime(float seconds) { return _to SetCurrentTime(seconds); } \
  NS_IMETHOD GetIntersectionList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval) { return _to GetIntersectionList(rect, referenceElement, _retval); } \
  NS_IMETHOD GetEnclosureList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval) { return _to GetEnclosureList(rect, referenceElement, _retval); } \
  NS_IMETHOD CheckIntersection(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval) { return _to CheckIntersection(element, rect, _retval); } \
  NS_IMETHOD CheckEnclosure(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval) { return _to CheckEnclosure(element, rect, _retval); } \
  NS_IMETHOD DeSelectAll(void) { return _to DeSelectAll(); } \
  NS_IMETHOD CreateSVGNumber(nsIDOMSVGNumber * *_retval) { return _to CreateSVGNumber(_retval); } \
  NS_IMETHOD CreateSVGLength(nsIDOMSVGLength * *_retval) { return _to CreateSVGLength(_retval); } \
  NS_IMETHOD CreateSVGAngle(nsISupports * *_retval) { return _to CreateSVGAngle(_retval); } \
  NS_IMETHOD CreateSVGPoint(nsISupports * *_retval) { return _to CreateSVGPoint(_retval); } \
  NS_IMETHOD CreateSVGMatrix(nsISupports * *_retval) { return _to CreateSVGMatrix(_retval); } \
  NS_IMETHOD CreateSVGRect(nsIDOMSVGRect * *_retval) { return _to CreateSVGRect(_retval); } \
  NS_IMETHOD CreateSVGTransform(nsISupports * *_retval) { return _to CreateSVGTransform(_retval); } \
  NS_IMETHOD CreateSVGTransformFromMatrix(nsISupports *matrix, nsISupports * *_retval) { return _to CreateSVGTransformFromMatrix(matrix, _retval); } \
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) { return _to GetElementById(elementId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSVGELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetViewport(nsIDOMSVGRect * *aViewport) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewport(aViewport); } \
  NS_IMETHOD GetPixelUnitToMillimeterX(float *aPixelUnitToMillimeterX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPixelUnitToMillimeterX(aPixelUnitToMillimeterX); } \
  NS_IMETHOD GetPixelUnitToMillimeterY(float *aPixelUnitToMillimeterY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPixelUnitToMillimeterY(aPixelUnitToMillimeterY); } \
  NS_IMETHOD GetScreenPixelToMillimeterX(float *aScreenPixelToMillimeterX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenPixelToMillimeterX(aScreenPixelToMillimeterX); } \
  NS_IMETHOD GetScreenPixelToMillimeterY(float *aScreenPixelToMillimeterY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenPixelToMillimeterY(aScreenPixelToMillimeterY); } \
  NS_IMETHOD GetUseCurrentView(bool *aUseCurrentView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseCurrentView(aUseCurrentView); } \
  NS_IMETHOD GetCurrentView(nsIDOMSVGViewSpec * *aCurrentView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentView(aCurrentView); } \
  NS_IMETHOD GetCurrentScale(float *aCurrentScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentScale(aCurrentScale); } \
  NS_IMETHOD SetCurrentScale(float aCurrentScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentScale(aCurrentScale); } \
  NS_IMETHOD GetCurrentTranslate(nsISupports * *aCurrentTranslate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTranslate(aCurrentTranslate); } \
  NS_IMETHOD SuspendRedraw(uint32_t max_wait_milliseconds, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendRedraw(max_wait_milliseconds, _retval); } \
  NS_IMETHOD UnsuspendRedraw(uint32_t suspend_handle_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnsuspendRedraw(suspend_handle_id); } \
  NS_IMETHOD UnsuspendRedrawAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnsuspendRedrawAll(); } \
  NS_IMETHOD ForceRedraw(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceRedraw(); } \
  NS_IMETHOD PauseAnimations(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PauseAnimations(); } \
  NS_IMETHOD UnpauseAnimations(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnpauseAnimations(); } \
  NS_IMETHOD AnimationsPaused(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AnimationsPaused(_retval); } \
  NS_IMETHOD GetCurrentTime(float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTime(_retval); } \
  NS_IMETHOD SetCurrentTime(float seconds) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentTime(seconds); } \
  NS_IMETHOD GetIntersectionList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntersectionList(rect, referenceElement, _retval); } \
  NS_IMETHOD GetEnclosureList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnclosureList(rect, referenceElement, _retval); } \
  NS_IMETHOD CheckIntersection(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckIntersection(element, rect, _retval); } \
  NS_IMETHOD CheckEnclosure(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckEnclosure(element, rect, _retval); } \
  NS_IMETHOD DeSelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeSelectAll(); } \
  NS_IMETHOD CreateSVGNumber(nsIDOMSVGNumber * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGNumber(_retval); } \
  NS_IMETHOD CreateSVGLength(nsIDOMSVGLength * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGLength(_retval); } \
  NS_IMETHOD CreateSVGAngle(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGAngle(_retval); } \
  NS_IMETHOD CreateSVGPoint(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPoint(_retval); } \
  NS_IMETHOD CreateSVGMatrix(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGMatrix(_retval); } \
  NS_IMETHOD CreateSVGRect(nsIDOMSVGRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGRect(_retval); } \
  NS_IMETHOD CreateSVGTransform(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGTransform(_retval); } \
  NS_IMETHOD CreateSVGTransformFromMatrix(nsISupports *matrix, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGTransformFromMatrix(matrix, _retval); } \
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementById(elementId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGSVGElement : public nsIDOMSVGSVGElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSVGELEMENT

  nsDOMSVGSVGElement();

private:
  ~nsDOMSVGSVGElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGSVGElement, nsIDOMSVGSVGElement)

nsDOMSVGSVGElement::nsDOMSVGSVGElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGSVGElement::~nsDOMSVGSVGElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGRect viewport; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetViewport(nsIDOMSVGRect * *aViewport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float pixelUnitToMillimeterX; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetPixelUnitToMillimeterX(float *aPixelUnitToMillimeterX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float pixelUnitToMillimeterY; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetPixelUnitToMillimeterY(float *aPixelUnitToMillimeterY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float screenPixelToMillimeterX; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetScreenPixelToMillimeterX(float *aScreenPixelToMillimeterX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float screenPixelToMillimeterY; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetScreenPixelToMillimeterY(float *aScreenPixelToMillimeterY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean useCurrentView; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetUseCurrentView(bool *aUseCurrentView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGViewSpec currentView; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetCurrentView(nsIDOMSVGViewSpec * *aCurrentView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float currentScale; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetCurrentScale(float *aCurrentScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGSVGElement::SetCurrentScale(float aCurrentScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports currentTranslate; */
NS_IMETHODIMP nsDOMSVGSVGElement::GetCurrentTranslate(nsISupports * *aCurrentTranslate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long suspendRedraw (in unsigned long max_wait_milliseconds); */
NS_IMETHODIMP nsDOMSVGSVGElement::SuspendRedraw(uint32_t max_wait_milliseconds, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unsuspendRedraw (in unsigned long suspend_handle_id); */
NS_IMETHODIMP nsDOMSVGSVGElement::UnsuspendRedraw(uint32_t suspend_handle_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unsuspendRedrawAll (); */
NS_IMETHODIMP nsDOMSVGSVGElement::UnsuspendRedrawAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceRedraw (); */
NS_IMETHODIMP nsDOMSVGSVGElement::ForceRedraw()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pauseAnimations (); */
NS_IMETHODIMP nsDOMSVGSVGElement::PauseAnimations()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unpauseAnimations (); */
NS_IMETHODIMP nsDOMSVGSVGElement::UnpauseAnimations()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean animationsPaused (); */
NS_IMETHODIMP nsDOMSVGSVGElement::AnimationsPaused(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getCurrentTime (); */
NS_IMETHODIMP nsDOMSVGSVGElement::GetCurrentTime(float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurrentTime (in float seconds); */
NS_IMETHODIMP nsDOMSVGSVGElement::SetCurrentTime(float seconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getIntersectionList (in nsIDOMSVGRect rect, in nsIDOMSVGElement referenceElement); */
NS_IMETHODIMP nsDOMSVGSVGElement::GetIntersectionList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getEnclosureList (in nsIDOMSVGRect rect, in nsIDOMSVGElement referenceElement); */
NS_IMETHODIMP nsDOMSVGSVGElement::GetEnclosureList(nsIDOMSVGRect *rect, nsIDOMSVGElement *referenceElement, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkIntersection (in nsIDOMSVGElement element, in nsIDOMSVGRect rect); */
NS_IMETHODIMP nsDOMSVGSVGElement::CheckIntersection(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkEnclosure (in nsIDOMSVGElement element, in nsIDOMSVGRect rect); */
NS_IMETHODIMP nsDOMSVGSVGElement::CheckEnclosure(nsIDOMSVGElement *element, nsIDOMSVGRect *rect, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deSelectAll (); */
NS_IMETHODIMP nsDOMSVGSVGElement::DeSelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGNumber createSVGNumber (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGNumber(nsIDOMSVGNumber * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGLength createSVGLength (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGLength(nsIDOMSVGLength * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGAngle (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGAngle(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPoint (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGPoint(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGMatrix (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGMatrix(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGRect createSVGRect (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGRect(nsIDOMSVGRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGTransform (); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGTransform(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGTransformFromMatrix (in nsISupports matrix); */
NS_IMETHODIMP nsDOMSVGSVGElement::CreateSVGTransformFromMatrix(nsISupports *matrix, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getElementById (in DOMString elementId); */
NS_IMETHODIMP nsDOMSVGSVGElement::GetElementById(const nsAString & elementId, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGSVGElement_h__ */
