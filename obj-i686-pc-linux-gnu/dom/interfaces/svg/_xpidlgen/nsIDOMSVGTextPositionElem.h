/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGTextPositionElem.idl
 */

#ifndef __gen_nsIDOMSVGTextPositionElem_h__
#define __gen_nsIDOMSVGTextPositionElem_h__


#ifndef __gen_nsIDOMSVGTextContentElement_h__
#include "nsIDOMSVGTextContentElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGTextPositioningElement */
#define NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID_STR "5d04c053-db94-468e-bfd6-588569851a6b"

#define NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID \
  {0x5d04c053, 0xdb94, 0x468e, \
    { 0xbf, 0xd6, 0x58, 0x85, 0x69, 0x85, 0x1a, 0x6b }}

class NS_NO_VTABLE nsIDOMSVGTextPositioningElement : public nsIDOMSVGTextContentElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID)

  /* readonly attribute nsISupports x; */
  NS_IMETHOD GetX(nsISupports * *aX) = 0;

  /* readonly attribute nsISupports y; */
  NS_IMETHOD GetY(nsISupports * *aY) = 0;

  /* readonly attribute nsISupports dx; */
  NS_IMETHOD GetDx(nsISupports * *aDx) = 0;

  /* readonly attribute nsISupports dy; */
  NS_IMETHOD GetDy(nsISupports * *aDy) = 0;

  /* readonly attribute nsISupports rotate; */
  NS_IMETHOD GetRotate(nsISupports * *aRotate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTextPositioningElement, NS_IDOMSVGTEXTPOSITIONINGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTEXTPOSITIONINGELEMENT \
  NS_IMETHOD GetX(nsISupports * *aX); \
  NS_IMETHOD GetY(nsISupports * *aY); \
  NS_IMETHOD GetDx(nsISupports * *aDx); \
  NS_IMETHOD GetDy(nsISupports * *aDy); \
  NS_IMETHOD GetRotate(nsISupports * *aRotate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTEXTPOSITIONINGELEMENT(_to) \
  NS_IMETHOD GetX(nsISupports * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsISupports * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetDx(nsISupports * *aDx) { return _to GetDx(aDx); } \
  NS_IMETHOD GetDy(nsISupports * *aDy) { return _to GetDy(aDy); } \
  NS_IMETHOD GetRotate(nsISupports * *aRotate) { return _to GetRotate(aRotate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTEXTPOSITIONINGELEMENT(_to) \
  NS_IMETHOD GetX(nsISupports * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsISupports * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetDx(nsISupports * *aDx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDx(aDx); } \
  NS_IMETHOD GetDy(nsISupports * *aDy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDy(aDy); } \
  NS_IMETHOD GetRotate(nsISupports * *aRotate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotate(aRotate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTextPositioningElement : public nsIDOMSVGTextPositioningElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTEXTPOSITIONINGELEMENT

  nsDOMSVGTextPositioningElement();

private:
  ~nsDOMSVGTextPositioningElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTextPositioningElement, nsIDOMSVGTextPositioningElement)

nsDOMSVGTextPositioningElement::nsDOMSVGTextPositioningElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTextPositioningElement::~nsDOMSVGTextPositioningElement()
{
  /* destructor code */
}

/* readonly attribute nsISupports x; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetX(nsISupports * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports y; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetY(nsISupports * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports dx; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetDx(nsISupports * *aDx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports dy; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetDy(nsISupports * *aDy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports rotate; */
NS_IMETHODIMP nsDOMSVGTextPositioningElement::GetRotate(nsISupports * *aRotate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTextPositionElem_h__ */
