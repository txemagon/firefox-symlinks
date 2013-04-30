/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGGradientElement.idl
 */

#ifndef __gen_nsIDOMSVGGradientElement_h__
#define __gen_nsIDOMSVGGradientElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedEnumeration; /* forward declaration */


/* starting interface:    nsIDOMSVGGradientElement */
#define NS_IDOMSVGGRADIENTELEMENT_IID_STR "5056512e-2ace-4b68-8f52-124e24cf0f55"

#define NS_IDOMSVGGRADIENTELEMENT_IID \
  {0x5056512e, 0x2ace, 0x4b68, \
    { 0x8f, 0x52, 0x12, 0x4e, 0x24, 0xcf, 0x0f, 0x55 }}

class NS_NO_VTABLE nsIDOMSVGGradientElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGGRADIENTELEMENT_IID)

  enum {
    SVG_SPREADMETHOD_UNKNOWN = 0U,
    SVG_SPREADMETHOD_PAD = 1U,
    SVG_SPREADMETHOD_REFLECT = 2U,
    SVG_SPREADMETHOD_REPEAT = 3U
  };

  /* readonly attribute nsIDOMSVGAnimatedEnumeration gradientUnits; */
  NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits) = 0;

  /* readonly attribute nsISupports gradientTransform; */
  NS_IMETHOD GetGradientTransform(nsISupports * *aGradientTransform) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration spreadMethod; */
  NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGGradientElement, NS_IDOMSVGGRADIENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGGRADIENTELEMENT \
  NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits); \
  NS_IMETHOD GetGradientTransform(nsISupports * *aGradientTransform); \
  NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGGRADIENTELEMENT(_to) \
  NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits) { return _to GetGradientUnits(aGradientUnits); } \
  NS_IMETHOD GetGradientTransform(nsISupports * *aGradientTransform) { return _to GetGradientTransform(aGradientTransform); } \
  NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod) { return _to GetSpreadMethod(aSpreadMethod); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGGRADIENTELEMENT(_to) \
  NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGradientUnits(aGradientUnits); } \
  NS_IMETHOD GetGradientTransform(nsISupports * *aGradientTransform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGradientTransform(aGradientTransform); } \
  NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpreadMethod(aSpreadMethod); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGGradientElement : public nsIDOMSVGGradientElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGGRADIENTELEMENT

  nsDOMSVGGradientElement();

private:
  ~nsDOMSVGGradientElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGGradientElement, nsIDOMSVGGradientElement)

nsDOMSVGGradientElement::nsDOMSVGGradientElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGGradientElement::~nsDOMSVGGradientElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration gradientUnits; */
NS_IMETHODIMP nsDOMSVGGradientElement::GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports gradientTransform; */
NS_IMETHODIMP nsDOMSVGGradientElement::GetGradientTransform(nsISupports * *aGradientTransform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration spreadMethod; */
NS_IMETHODIMP nsDOMSVGGradientElement::GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGLinearGradientElement */
#define NS_IDOMSVGLINEARGRADIENTELEMENT_IID_STR "ac3e0464-5b49-4323-850d-563573f754ec"

#define NS_IDOMSVGLINEARGRADIENTELEMENT_IID \
  {0xac3e0464, 0x5b49, 0x4323, \
    { 0x85, 0x0d, 0x56, 0x35, 0x73, 0xf7, 0x54, 0xec }}

class NS_NO_VTABLE nsIDOMSVGLinearGradientElement : public nsIDOMSVGGradientElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGLINEARGRADIENTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x1; */
  NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y1; */
  NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x2; */
  NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y2; */
  NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGLinearGradientElement, NS_IDOMSVGLINEARGRADIENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGLINEARGRADIENTELEMENT \
  NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1); \
  NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1); \
  NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2); \
  NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGLINEARGRADIENTELEMENT(_to) \
  NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) { return _to GetX1(aX1); } \
  NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) { return _to GetY1(aY1); } \
  NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) { return _to GetX2(aX2); } \
  NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) { return _to GetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGLINEARGRADIENTELEMENT(_to) \
  NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGLinearGradientElement : public nsIDOMSVGLinearGradientElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGLINEARGRADIENTELEMENT

  nsDOMSVGLinearGradientElement();

private:
  ~nsDOMSVGLinearGradientElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGLinearGradientElement, nsIDOMSVGLinearGradientElement)

nsDOMSVGLinearGradientElement::nsDOMSVGLinearGradientElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGLinearGradientElement::~nsDOMSVGLinearGradientElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x1; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetX1(nsIDOMSVGAnimatedLength * *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y1; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetY1(nsIDOMSVGAnimatedLength * *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x2; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetX2(nsIDOMSVGAnimatedLength * *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y2; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetY2(nsIDOMSVGAnimatedLength * *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGRadialGradientElement */
#define NS_IDOMSVGRADIALGRADIENTELEMENT_IID_STR "7300fbab-84ae-425e-bb3b-cf8c1e584ccd"

#define NS_IDOMSVGRADIALGRADIENTELEMENT_IID \
  {0x7300fbab, 0x84ae, 0x425e, \
    { 0xbb, 0x3b, 0xcf, 0x8c, 0x1e, 0x58, 0x4c, 0xcd }}

class NS_NO_VTABLE nsIDOMSVGRadialGradientElement : public nsIDOMSVGGradientElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGRADIALGRADIENTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength cx; */
  NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength cy; */
  NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength r; */
  NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength fx; */
  NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength fy; */
  NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGRadialGradientElement, NS_IDOMSVGRADIALGRADIENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGRADIALGRADIENTELEMENT \
  NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx); \
  NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy); \
  NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR); \
  NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx); \
  NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGRADIALGRADIENTELEMENT(_to) \
  NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return _to GetCx(aCx); } \
  NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return _to GetCy(aCy); } \
  NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) { return _to GetR(aR); } \
  NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx) { return _to GetFx(aFx); } \
  NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy) { return _to GetFy(aFy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGRADIALGRADIENTELEMENT(_to) \
  NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCx(aCx); } \
  NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCy(aCy); } \
  NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR(aR); } \
  NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFx(aFx); } \
  NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFy(aFy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGRadialGradientElement : public nsIDOMSVGRadialGradientElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGRADIALGRADIENTELEMENT

  nsDOMSVGRadialGradientElement();

private:
  ~nsDOMSVGRadialGradientElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGRadialGradientElement, nsIDOMSVGRadialGradientElement)

nsDOMSVGRadialGradientElement::nsDOMSVGRadialGradientElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGRadialGradientElement::~nsDOMSVGRadialGradientElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength cx; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetCx(nsIDOMSVGAnimatedLength * *aCx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength cy; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetCy(nsIDOMSVGAnimatedLength * *aCy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength r; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetR(nsIDOMSVGAnimatedLength * *aR)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength fx; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetFx(nsIDOMSVGAnimatedLength * *aFx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength fy; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetFy(nsIDOMSVGAnimatedLength * *aFy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGGradientElement_h__ */
