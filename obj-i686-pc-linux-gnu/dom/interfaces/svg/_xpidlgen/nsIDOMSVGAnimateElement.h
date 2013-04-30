/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGAnimateElement.idl
 */

#ifndef __gen_nsIDOMSVGAnimateElement_h__
#define __gen_nsIDOMSVGAnimateElement_h__


#ifndef __gen_nsIDOMSVGAnimationElement_h__
#include "nsIDOMSVGAnimationElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimateElement */
#define NS_IDOMSVGANIMATEELEMENT_IID_STR "11e98ea0-c8d2-4471-88b0-a3e6708021e4"

#define NS_IDOMSVGANIMATEELEMENT_IID \
  {0x11e98ea0, 0xc8d2, 0x4471, \
    { 0x88, 0xb0, 0xa3, 0xe6, 0x70, 0x80, 0x21, 0xe4 }}

class NS_NO_VTABLE nsIDOMSVGAnimateElement : public nsIDOMSVGAnimationElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimateElement, NS_IDOMSVGANIMATEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimateElement : public nsIDOMSVGAnimateElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEELEMENT

  nsDOMSVGAnimateElement();

private:
  ~nsDOMSVGAnimateElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimateElement, nsIDOMSVGAnimateElement)

nsDOMSVGAnimateElement::nsDOMSVGAnimateElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimateElement::~nsDOMSVGAnimateElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimateElement_h__ */
