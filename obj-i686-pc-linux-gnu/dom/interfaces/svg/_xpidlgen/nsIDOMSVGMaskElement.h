/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGMaskElement.idl
 */

#ifndef __gen_nsIDOMSVGMaskElement_h__
#define __gen_nsIDOMSVGMaskElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedEnumeration; /* forward declaration */


/* starting interface:    nsIDOMSVGMaskElement */
#define NS_IDOMSVGMASKELEMENT_IID_STR "d9fe9060-de7e-4841-a33b-5601ec133982"

#define NS_IDOMSVGMASKELEMENT_IID \
  {0xd9fe9060, 0xde7e, 0x4841, \
    { 0xa3, 0x3b, 0x56, 0x01, 0xec, 0x13, 0x39, 0x82 }}

class NS_NO_VTABLE nsIDOMSVGMaskElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGMASKELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedEnumeration maskUnits; */
  NS_IMETHOD GetMaskUnits(nsIDOMSVGAnimatedEnumeration * *aMaskUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration maskContentUnits; */
  NS_IMETHOD GetMaskContentUnits(nsIDOMSVGAnimatedEnumeration * *aMaskContentUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGMaskElement, NS_IDOMSVGMASKELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGMASKELEMENT \
  NS_IMETHOD GetMaskUnits(nsIDOMSVGAnimatedEnumeration * *aMaskUnits); \
  NS_IMETHOD GetMaskContentUnits(nsIDOMSVGAnimatedEnumeration * *aMaskContentUnits); \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGMASKELEMENT(_to) \
  NS_IMETHOD GetMaskUnits(nsIDOMSVGAnimatedEnumeration * *aMaskUnits) { return _to GetMaskUnits(aMaskUnits); } \
  NS_IMETHOD GetMaskContentUnits(nsIDOMSVGAnimatedEnumeration * *aMaskContentUnits) { return _to GetMaskContentUnits(aMaskContentUnits); } \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGMASKELEMENT(_to) \
  NS_IMETHOD GetMaskUnits(nsIDOMSVGAnimatedEnumeration * *aMaskUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaskUnits(aMaskUnits); } \
  NS_IMETHOD GetMaskContentUnits(nsIDOMSVGAnimatedEnumeration * *aMaskContentUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaskContentUnits(aMaskContentUnits); } \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGMaskElement : public nsIDOMSVGMaskElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGMASKELEMENT

  nsDOMSVGMaskElement();

private:
  ~nsDOMSVGMaskElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGMaskElement, nsIDOMSVGMaskElement)

nsDOMSVGMaskElement::nsDOMSVGMaskElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGMaskElement::~nsDOMSVGMaskElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration maskUnits; */
NS_IMETHODIMP nsDOMSVGMaskElement::GetMaskUnits(nsIDOMSVGAnimatedEnumeration * *aMaskUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration maskContentUnits; */
NS_IMETHODIMP nsDOMSVGMaskElement::GetMaskContentUnits(nsIDOMSVGAnimatedEnumeration * *aMaskContentUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGMaskElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGMaskElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGMaskElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGMaskElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGMaskElement_h__ */
