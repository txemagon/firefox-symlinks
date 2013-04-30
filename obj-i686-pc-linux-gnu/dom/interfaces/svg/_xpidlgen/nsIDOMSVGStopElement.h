/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGStopElement.idl
 */

#ifndef __gen_nsIDOMSVGStopElement_h__
#define __gen_nsIDOMSVGStopElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedNumber; /* forward declaration */


/* starting interface:    nsIDOMSVGStopElement */
#define NS_IDOMSVGSTOPELEMENT_IID_STR "b3a7410b-0066-404d-9ddc-ad212d97891f"

#define NS_IDOMSVGSTOPELEMENT_IID \
  {0xb3a7410b, 0x0066, 0x404d, \
    { 0x9d, 0xdc, 0xad, 0x21, 0x2d, 0x97, 0x89, 0x1f }}

class NS_NO_VTABLE nsIDOMSVGStopElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSTOPELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber offset; */
  NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGStopElement, NS_IDOMSVGSTOPELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSTOPELEMENT \
  NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSTOPELEMENT(_to) \
  NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return _to GetOffset(aOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSTOPELEMENT(_to) \
  NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffset(aOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGStopElement : public nsIDOMSVGStopElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSTOPELEMENT

  nsDOMSVGStopElement();

private:
  ~nsDOMSVGStopElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGStopElement, nsIDOMSVGStopElement)

nsDOMSVGStopElement::nsDOMSVGStopElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGStopElement::~nsDOMSVGStopElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber offset; */
NS_IMETHODIMP nsDOMSVGStopElement::GetOffset(nsIDOMSVGAnimatedNumber * *aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGStopElement_h__ */
