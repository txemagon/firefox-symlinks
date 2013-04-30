/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGRectElement.idl
 */

#ifndef __gen_nsIDOMSVGRectElement_h__
#define __gen_nsIDOMSVGRectElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGRectElement */
#define NS_IDOMSVGRECTELEMENT_IID_STR "67f1f097-a2a8-40d4-a2b5-12a6e8d0455e"

#define NS_IDOMSVGRECTELEMENT_IID \
  {0x67f1f097, 0xa2a8, 0x40d4, \
    { 0xa2, 0xb5, 0x12, 0xa6, 0xe8, 0xd0, 0x45, 0x5e }}

class NS_NO_VTABLE nsIDOMSVGRectElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGRECTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength rx; */
  NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength ry; */
  NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGRectElement, NS_IDOMSVGRECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGRECTELEMENT \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx); \
  NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGRECTELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) { return _to GetRx(aRx); } \
  NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) { return _to GetRy(aRy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGRECTELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetRx(nsIDOMSVGAnimatedLength * *aRx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRx(aRx); } \
  NS_IMETHOD GetRy(nsIDOMSVGAnimatedLength * *aRy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRy(aRy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGRectElement : public nsIDOMSVGRectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGRECTELEMENT

  nsDOMSVGRectElement();

private:
  ~nsDOMSVGRectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGRectElement, nsIDOMSVGRectElement)

nsDOMSVGRectElement::nsDOMSVGRectElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGRectElement::~nsDOMSVGRectElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGRectElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGRectElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGRectElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGRectElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength rx; */
NS_IMETHODIMP nsDOMSVGRectElement::GetRx(nsIDOMSVGAnimatedLength * *aRx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength ry; */
NS_IMETHODIMP nsDOMSVGRectElement::GetRy(nsIDOMSVGAnimatedLength * *aRy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGRectElement_h__ */
