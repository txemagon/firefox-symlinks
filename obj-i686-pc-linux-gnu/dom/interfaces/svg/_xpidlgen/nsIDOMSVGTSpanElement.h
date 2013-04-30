/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGTSpanElement.idl
 */

#ifndef __gen_nsIDOMSVGTSpanElement_h__
#define __gen_nsIDOMSVGTSpanElement_h__


#ifndef __gen_nsIDOMSVGTextPositionElem_h__
#include "nsIDOMSVGTextPositionElem.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGTSpanElement */
#define NS_IDOMSVGTSPANELEMENT_IID_STR "b209767f-b902-4831-8614-40cefb788042"

#define NS_IDOMSVGTSPANELEMENT_IID \
  {0xb209767f, 0xb902, 0x4831, \
    { 0x86, 0x14, 0x40, 0xce, 0xfb, 0x78, 0x80, 0x42 }}

class NS_NO_VTABLE nsIDOMSVGTSpanElement : public nsIDOMSVGTextPositioningElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTSPANELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTSpanElement, NS_IDOMSVGTSPANELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTSPANELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTSPANELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTSPANELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTSpanElement : public nsIDOMSVGTSpanElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTSPANELEMENT

  nsDOMSVGTSpanElement();

private:
  ~nsDOMSVGTSpanElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTSpanElement, nsIDOMSVGTSpanElement)

nsDOMSVGTSpanElement::nsDOMSVGTSpanElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTSpanElement::~nsDOMSVGTSpanElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTSpanElement_h__ */
