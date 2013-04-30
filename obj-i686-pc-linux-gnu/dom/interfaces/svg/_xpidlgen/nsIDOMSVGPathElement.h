/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGPathElement.idl
 */

#ifndef __gen_nsIDOMSVGPathElement_h__
#define __gen_nsIDOMSVGPathElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedNumber; /* forward declaration */


/* starting interface:    nsIDOMSVGPathElement */
#define NS_IDOMSVGPATHELEMENT_IID_STR "89af3eae-1703-461a-a2e0-86d2131c11ac"

#define NS_IDOMSVGPATHELEMENT_IID \
  {0x89af3eae, 0x1703, 0x461a, \
    { 0xa2, 0xe0, 0x86, 0xd2, 0x13, 0x1c, 0x11, 0xac }}

class NS_NO_VTABLE nsIDOMSVGPathElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber pathLength; */
  NS_IMETHOD GetPathLength(nsIDOMSVGAnimatedNumber * *aPathLength) = 0;

  /* float getTotalLength (); */
  NS_IMETHOD GetTotalLength(float *_retval) = 0;

  /* nsISupports getPointAtLength (in float distance); */
  NS_IMETHOD GetPointAtLength(float distance, nsISupports * *_retval) = 0;

  /* unsigned long getPathSegAtLength (in float distance); */
  NS_IMETHOD GetPathSegAtLength(float distance, uint32_t *_retval) = 0;

  /* nsISupports createSVGPathSegClosePath (); */
  NS_IMETHOD CreateSVGPathSegClosePath(nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegMovetoAbs (in float x, in float y); */
  NS_IMETHOD CreateSVGPathSegMovetoAbs(float x, float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegMovetoRel (in float x, in float y); */
  NS_IMETHOD CreateSVGPathSegMovetoRel(float x, float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegLinetoAbs (in float x, in float y); */
  NS_IMETHOD CreateSVGPathSegLinetoAbs(float x, float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegLinetoRel (in float x, in float y); */
  NS_IMETHOD CreateSVGPathSegLinetoRel(float x, float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoCubicAbs (in float x, in float y, in float x1, in float y1, in float x2, in float y2); */
  NS_IMETHOD CreateSVGPathSegCurvetoCubicAbs(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoCubicRel (in float x, in float y, in float x1, in float y1, in float x2, in float y2); */
  NS_IMETHOD CreateSVGPathSegCurvetoCubicRel(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoQuadraticAbs (in float x, in float y, in float x1, in float y1); */
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticAbs(float x, float y, float x1, float y1, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoQuadraticRel (in float x, in float y, in float x1, in float y1); */
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticRel(float x, float y, float x1, float y1, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegArcAbs (in float x, in float y, in float r1, in float r2, in float angle, in boolean largeArcFlag, in boolean sweepFlag); */
  NS_IMETHOD CreateSVGPathSegArcAbs(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegArcRel (in float x, in float y, in float r1, in float r2, in float angle, in boolean largeArcFlag, in boolean sweepFlag); */
  NS_IMETHOD CreateSVGPathSegArcRel(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegLinetoHorizontalAbs (in float x); */
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalAbs(float x, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegLinetoHorizontalRel (in float x); */
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalRel(float x, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegLinetoVerticalAbs (in float y); */
  NS_IMETHOD CreateSVGPathSegLinetoVerticalAbs(float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegLinetoVerticalRel (in float y); */
  NS_IMETHOD CreateSVGPathSegLinetoVerticalRel(float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoCubicSmoothAbs (in float x, in float y, in float x2, in float y2); */
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothAbs(float x, float y, float x2, float y2, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoCubicSmoothRel (in float x, in float y, in float x2, in float y2); */
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothRel(float x, float y, float x2, float y2, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoQuadraticSmoothAbs (in float x, in float y); */
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothAbs(float x, float y, nsISupports * *_retval) = 0;

  /* nsISupports createSVGPathSegCurvetoQuadraticSmoothRel (in float x, in float y); */
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothRel(float x, float y, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathElement, NS_IDOMSVGPATHELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHELEMENT \
  NS_IMETHOD GetPathLength(nsIDOMSVGAnimatedNumber * *aPathLength); \
  NS_IMETHOD GetTotalLength(float *_retval); \
  NS_IMETHOD GetPointAtLength(float distance, nsISupports * *_retval); \
  NS_IMETHOD GetPathSegAtLength(float distance, uint32_t *_retval); \
  NS_IMETHOD CreateSVGPathSegClosePath(nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegMovetoAbs(float x, float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegMovetoRel(float x, float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegLinetoAbs(float x, float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegLinetoRel(float x, float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicAbs(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicRel(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticAbs(float x, float y, float x1, float y1, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticRel(float x, float y, float x1, float y1, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegArcAbs(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegArcRel(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalAbs(float x, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalRel(float x, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegLinetoVerticalAbs(float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegLinetoVerticalRel(float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothAbs(float x, float y, float x2, float y2, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothRel(float x, float y, float x2, float y2, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothAbs(float x, float y, nsISupports * *_retval); \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothRel(float x, float y, nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHELEMENT(_to) \
  NS_IMETHOD GetPathLength(nsIDOMSVGAnimatedNumber * *aPathLength) { return _to GetPathLength(aPathLength); } \
  NS_IMETHOD GetTotalLength(float *_retval) { return _to GetTotalLength(_retval); } \
  NS_IMETHOD GetPointAtLength(float distance, nsISupports * *_retval) { return _to GetPointAtLength(distance, _retval); } \
  NS_IMETHOD GetPathSegAtLength(float distance, uint32_t *_retval) { return _to GetPathSegAtLength(distance, _retval); } \
  NS_IMETHOD CreateSVGPathSegClosePath(nsISupports * *_retval) { return _to CreateSVGPathSegClosePath(_retval); } \
  NS_IMETHOD CreateSVGPathSegMovetoAbs(float x, float y, nsISupports * *_retval) { return _to CreateSVGPathSegMovetoAbs(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegMovetoRel(float x, float y, nsISupports * *_retval) { return _to CreateSVGPathSegMovetoRel(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoAbs(float x, float y, nsISupports * *_retval) { return _to CreateSVGPathSegLinetoAbs(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoRel(float x, float y, nsISupports * *_retval) { return _to CreateSVGPathSegLinetoRel(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicAbs(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoCubicAbs(x, y, x1, y1, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicRel(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoCubicRel(x, y, x1, y1, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticAbs(float x, float y, float x1, float y1, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoQuadraticAbs(x, y, x1, y1, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticRel(float x, float y, float x1, float y1, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoQuadraticRel(x, y, x1, y1, _retval); } \
  NS_IMETHOD CreateSVGPathSegArcAbs(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval) { return _to CreateSVGPathSegArcAbs(x, y, r1, r2, angle, largeArcFlag, sweepFlag, _retval); } \
  NS_IMETHOD CreateSVGPathSegArcRel(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval) { return _to CreateSVGPathSegArcRel(x, y, r1, r2, angle, largeArcFlag, sweepFlag, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalAbs(float x, nsISupports * *_retval) { return _to CreateSVGPathSegLinetoHorizontalAbs(x, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalRel(float x, nsISupports * *_retval) { return _to CreateSVGPathSegLinetoHorizontalRel(x, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoVerticalAbs(float y, nsISupports * *_retval) { return _to CreateSVGPathSegLinetoVerticalAbs(y, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoVerticalRel(float y, nsISupports * *_retval) { return _to CreateSVGPathSegLinetoVerticalRel(y, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothAbs(float x, float y, float x2, float y2, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoCubicSmoothAbs(x, y, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothRel(float x, float y, float x2, float y2, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoCubicSmoothRel(x, y, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothAbs(float x, float y, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoQuadraticSmoothAbs(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothRel(float x, float y, nsISupports * *_retval) { return _to CreateSVGPathSegCurvetoQuadraticSmoothRel(x, y, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHELEMENT(_to) \
  NS_IMETHOD GetPathLength(nsIDOMSVGAnimatedNumber * *aPathLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathLength(aPathLength); } \
  NS_IMETHOD GetTotalLength(float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalLength(_retval); } \
  NS_IMETHOD GetPointAtLength(float distance, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPointAtLength(distance, _retval); } \
  NS_IMETHOD GetPathSegAtLength(float distance, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathSegAtLength(distance, _retval); } \
  NS_IMETHOD CreateSVGPathSegClosePath(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegClosePath(_retval); } \
  NS_IMETHOD CreateSVGPathSegMovetoAbs(float x, float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegMovetoAbs(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegMovetoRel(float x, float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegMovetoRel(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoAbs(float x, float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegLinetoAbs(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoRel(float x, float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegLinetoRel(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicAbs(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoCubicAbs(x, y, x1, y1, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicRel(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoCubicRel(x, y, x1, y1, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticAbs(float x, float y, float x1, float y1, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoQuadraticAbs(x, y, x1, y1, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticRel(float x, float y, float x1, float y1, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoQuadraticRel(x, y, x1, y1, _retval); } \
  NS_IMETHOD CreateSVGPathSegArcAbs(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegArcAbs(x, y, r1, r2, angle, largeArcFlag, sweepFlag, _retval); } \
  NS_IMETHOD CreateSVGPathSegArcRel(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegArcRel(x, y, r1, r2, angle, largeArcFlag, sweepFlag, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalAbs(float x, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegLinetoHorizontalAbs(x, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoHorizontalRel(float x, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegLinetoHorizontalRel(x, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoVerticalAbs(float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegLinetoVerticalAbs(y, _retval); } \
  NS_IMETHOD CreateSVGPathSegLinetoVerticalRel(float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegLinetoVerticalRel(y, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothAbs(float x, float y, float x2, float y2, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoCubicSmoothAbs(x, y, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoCubicSmoothRel(float x, float y, float x2, float y2, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoCubicSmoothRel(x, y, x2, y2, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothAbs(float x, float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoQuadraticSmoothAbs(x, y, _retval); } \
  NS_IMETHOD CreateSVGPathSegCurvetoQuadraticSmoothRel(float x, float y, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSVGPathSegCurvetoQuadraticSmoothRel(x, y, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathElement : public nsIDOMSVGPathElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHELEMENT

  nsDOMSVGPathElement();

private:
  ~nsDOMSVGPathElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathElement, nsIDOMSVGPathElement)

nsDOMSVGPathElement::nsDOMSVGPathElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathElement::~nsDOMSVGPathElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber pathLength; */
NS_IMETHODIMP nsDOMSVGPathElement::GetPathLength(nsIDOMSVGAnimatedNumber * *aPathLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getTotalLength (); */
NS_IMETHODIMP nsDOMSVGPathElement::GetTotalLength(float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getPointAtLength (in float distance); */
NS_IMETHODIMP nsDOMSVGPathElement::GetPointAtLength(float distance, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getPathSegAtLength (in float distance); */
NS_IMETHODIMP nsDOMSVGPathElement::GetPathSegAtLength(float distance, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegClosePath (); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegClosePath(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegMovetoAbs (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegMovetoAbs(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegMovetoRel (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegMovetoRel(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegLinetoAbs (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegLinetoAbs(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegLinetoRel (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegLinetoRel(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoCubicAbs (in float x, in float y, in float x1, in float y1, in float x2, in float y2); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoCubicAbs(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoCubicRel (in float x, in float y, in float x1, in float y1, in float x2, in float y2); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoCubicRel(float x, float y, float x1, float y1, float x2, float y2, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoQuadraticAbs (in float x, in float y, in float x1, in float y1); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoQuadraticAbs(float x, float y, float x1, float y1, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoQuadraticRel (in float x, in float y, in float x1, in float y1); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoQuadraticRel(float x, float y, float x1, float y1, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegArcAbs (in float x, in float y, in float r1, in float r2, in float angle, in boolean largeArcFlag, in boolean sweepFlag); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegArcAbs(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegArcRel (in float x, in float y, in float r1, in float r2, in float angle, in boolean largeArcFlag, in boolean sweepFlag); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegArcRel(float x, float y, float r1, float r2, float angle, bool largeArcFlag, bool sweepFlag, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegLinetoHorizontalAbs (in float x); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegLinetoHorizontalAbs(float x, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegLinetoHorizontalRel (in float x); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegLinetoHorizontalRel(float x, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegLinetoVerticalAbs (in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegLinetoVerticalAbs(float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegLinetoVerticalRel (in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegLinetoVerticalRel(float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoCubicSmoothAbs (in float x, in float y, in float x2, in float y2); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoCubicSmoothAbs(float x, float y, float x2, float y2, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoCubicSmoothRel (in float x, in float y, in float x2, in float y2); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoCubicSmoothRel(float x, float y, float x2, float y2, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoQuadraticSmoothAbs (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoQuadraticSmoothAbs(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports createSVGPathSegCurvetoQuadraticSmoothRel (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGPathElement::CreateSVGPathSegCurvetoQuadraticSmoothRel(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPathElement_h__ */
