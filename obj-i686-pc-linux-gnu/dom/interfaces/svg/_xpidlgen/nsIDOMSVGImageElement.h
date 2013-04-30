/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGImageElement.idl
 */

#ifndef __gen_nsIDOMSVGImageElement_h__
#define __gen_nsIDOMSVGImageElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGImageElement */
#define NS_IDOMSVGIMAGEELEMENT_IID_STR "2268aad3-7e88-4f7b-89a3-f5294c89514d"

#define NS_IDOMSVGIMAGEELEMENT_IID \
  {0x2268aad3, 0x7e88, 0x4f7b, \
    { 0x89, 0xa3, 0xf5, 0x29, 0x4c, 0x89, 0x51, 0x4d }}

class NS_NO_VTABLE nsIDOMSVGImageElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGIMAGEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsISupports preserveAspectRatio; */
  NS_IMETHOD GetPreserveAspectRatio(nsISupports * *aPreserveAspectRatio) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGImageElement, NS_IDOMSVGIMAGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGIMAGEELEMENT \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_IMETHOD GetPreserveAspectRatio(nsISupports * *aPreserveAspectRatio); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGIMAGEELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetPreserveAspectRatio(nsISupports * *aPreserveAspectRatio) { return _to GetPreserveAspectRatio(aPreserveAspectRatio); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGIMAGEELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetPreserveAspectRatio(nsISupports * *aPreserveAspectRatio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreserveAspectRatio(aPreserveAspectRatio); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGImageElement : public nsIDOMSVGImageElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGIMAGEELEMENT

  nsDOMSVGImageElement();

private:
  ~nsDOMSVGImageElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGImageElement, nsIDOMSVGImageElement)

nsDOMSVGImageElement::nsDOMSVGImageElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGImageElement::~nsDOMSVGImageElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGImageElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGImageElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGImageElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGImageElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports preserveAspectRatio; */
NS_IMETHODIMP nsDOMSVGImageElement::GetPreserveAspectRatio(nsISupports * *aPreserveAspectRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGImageElement_h__ */
