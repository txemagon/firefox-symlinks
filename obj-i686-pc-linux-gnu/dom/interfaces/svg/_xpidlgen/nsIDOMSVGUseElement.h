/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGUseElement.idl
 */

#ifndef __gen_nsIDOMSVGUseElement_h__
#define __gen_nsIDOMSVGUseElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGUseElement */
#define NS_IDOMSVGUSEELEMENT_IID_STR "1c2f17cf-3abf-4e03-94af-e0a3b93ceebb"

#define NS_IDOMSVGUSEELEMENT_IID \
  {0x1c2f17cf, 0x3abf, 0x4e03, \
    { 0x94, 0xaf, 0xe0, 0xa3, 0xb9, 0x3c, 0xee, 0xbb }}

class NS_NO_VTABLE nsIDOMSVGUseElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGUSEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGUseElement, NS_IDOMSVGUSEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGUSEELEMENT \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGUSEELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGUSEELEMENT(_to) \
  NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGUseElement : public nsIDOMSVGUseElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGUSEELEMENT

  nsDOMSVGUseElement();

private:
  ~nsDOMSVGUseElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGUseElement, nsIDOMSVGUseElement)

nsDOMSVGUseElement::nsDOMSVGUseElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGUseElement::~nsDOMSVGUseElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGUseElement::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGUseElement::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGUseElement::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGUseElement::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGUseElement_h__ */
