/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGFilterElement.idl
 */

#ifndef __gen_nsIDOMSVGFilterElement_h__
#define __gen_nsIDOMSVGFilterElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGAnimatedInteger; /* forward declaration */


/* starting interface:    nsIDOMSVGFilterElement */
#define NS_IDOMSVGFILTERELEMENT_IID_STR "974c7633-0258-4be7-b1ae-e0ed1964c87f"

#define NS_IDOMSVGFILTERELEMENT_IID \
  {0x974c7633, 0x0258, 0x4be7, \
    { 0xb1, 0xae, 0xe0, 0xed, 0x19, 0x64, 0xc8, 0x7f }}

class NS_NO_VTABLE nsIDOMSVGFilterElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFILTERELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedEnumeration filterUnits; */
  NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration primitiveUnits; */
  NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger filterResX; */
  NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger filterResY; */
  NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY) = 0;

  /* void setFilterRes (in unsigned long filterResX, in unsigned long filterResY); */
  NS_IMETHOD SetFilterRes(uint32_t filterResX, uint32_t filterResY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFilterElement, NS_IDOMSVGFILTERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFILTERELEMENT \
  NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits); \
  NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits); \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX); \
  NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY); \
  NS_IMETHOD SetFilterRes(uint32_t filterResX, uint32_t filterResY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFILTERELEMENT(_to) \
  NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits) { return _to GetFilterUnits(aFilterUnits); } \
  NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits) { return _to GetPrimitiveUnits(aPrimitiveUnits); } \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX) { return _to GetFilterResX(aFilterResX); } \
  NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY) { return _to GetFilterResY(aFilterResY); } \
  NS_IMETHOD SetFilterRes(uint32_t filterResX, uint32_t filterResY) { return _to SetFilterRes(filterResX, filterResY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFILTERELEMENT(_to) \
  NS_IMETHOD GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterUnits(aFilterUnits); } \
  NS_IMETHOD GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimitiveUnits(aPrimitiveUnits); } \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterResX(aFilterResX); } \
  NS_IMETHOD GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterResY(aFilterResY); } \
  NS_IMETHOD SetFilterRes(uint32_t filterResX, uint32_t filterResY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterRes(filterResX, filterResY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFilterElement : public nsIDOMSVGFilterElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFILTERELEMENT

  nsDOMSVGFilterElement();

private:
  ~nsDOMSVGFilterElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFilterElement, nsIDOMSVGFilterElement)

nsDOMSVGFilterElement::nsDOMSVGFilterElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFilterElement::~nsDOMSVGFilterElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration filterUnits; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetFilterUnits(nsIDOMSVGAnimatedEnumeration * *aFilterUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration primitiveUnits; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetPrimitiveUnits(nsIDOMSVGAnimatedEnumeration * *aPrimitiveUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger filterResX; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetFilterResX(nsIDOMSVGAnimatedInteger * *aFilterResX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger filterResY; */
NS_IMETHODIMP nsDOMSVGFilterElement::GetFilterResY(nsIDOMSVGAnimatedInteger * *aFilterResY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFilterRes (in unsigned long filterResX, in unsigned long filterResY); */
NS_IMETHODIMP nsDOMSVGFilterElement::SetFilterRes(uint32_t filterResX, uint32_t filterResY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGFilterElement_h__ */
