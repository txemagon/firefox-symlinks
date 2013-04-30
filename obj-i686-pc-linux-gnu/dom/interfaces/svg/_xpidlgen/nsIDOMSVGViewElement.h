/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGViewElement.idl
 */

#ifndef __gen_nsIDOMSVGViewElement_h__
#define __gen_nsIDOMSVGViewElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

#ifndef __gen_nsIDOMSVGStringList_h__
#include "nsIDOMSVGStringList.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGViewElement */
#define NS_IDOMSVGVIEWELEMENT_IID_STR "4b02f970-a916-4b9d-b83f-eecef658266b"

#define NS_IDOMSVGVIEWELEMENT_IID \
  {0x4b02f970, 0xa916, 0x4b9d, \
    { 0xb8, 0x3f, 0xee, 0xce, 0xf6, 0x58, 0x26, 0x6b }}

class NS_NO_VTABLE nsIDOMSVGViewElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGVIEWELEMENT_IID)

  /* readonly attribute nsIDOMSVGStringList viewTarget; */
  NS_IMETHOD GetViewTarget(nsIDOMSVGStringList * *aViewTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGViewElement, NS_IDOMSVGVIEWELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGVIEWELEMENT \
  NS_IMETHOD GetViewTarget(nsIDOMSVGStringList * *aViewTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGVIEWELEMENT(_to) \
  NS_IMETHOD GetViewTarget(nsIDOMSVGStringList * *aViewTarget) { return _to GetViewTarget(aViewTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGVIEWELEMENT(_to) \
  NS_IMETHOD GetViewTarget(nsIDOMSVGStringList * *aViewTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewTarget(aViewTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGViewElement : public nsIDOMSVGViewElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGVIEWELEMENT

  nsDOMSVGViewElement();

private:
  ~nsDOMSVGViewElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGViewElement, nsIDOMSVGViewElement)

nsDOMSVGViewElement::nsDOMSVGViewElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGViewElement::~nsDOMSVGViewElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGStringList viewTarget; */
NS_IMETHODIMP nsDOMSVGViewElement::GetViewTarget(nsIDOMSVGStringList * *aViewTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGViewElement_h__ */
