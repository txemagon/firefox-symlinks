/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGAnimateMotionElement.idl
 */

#ifndef __gen_nsIDOMSVGAnimateMotionElement_h__
#define __gen_nsIDOMSVGAnimateMotionElement_h__


#ifndef __gen_nsIDOMSVGAnimationElement_h__
#include "nsIDOMSVGAnimationElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimateMotionElement */
#define NS_IDOMSVGANIMATEMOTIONELEMENT_IID_STR "964cda18-c400-4d1e-b113-2000b4bf777e"

#define NS_IDOMSVGANIMATEMOTIONELEMENT_IID \
  {0x964cda18, 0xc400, 0x4d1e, \
    { 0xb1, 0x13, 0x20, 0x00, 0xb4, 0xbf, 0x77, 0x7e }}

class NS_NO_VTABLE nsIDOMSVGAnimateMotionElement : public nsIDOMSVGAnimationElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEMOTIONELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimateMotionElement, NS_IDOMSVGANIMATEMOTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEMOTIONELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEMOTIONELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEMOTIONELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimateMotionElement : public nsIDOMSVGAnimateMotionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEMOTIONELEMENT

  nsDOMSVGAnimateMotionElement();

private:
  ~nsDOMSVGAnimateMotionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimateMotionElement, nsIDOMSVGAnimateMotionElement)

nsDOMSVGAnimateMotionElement::nsDOMSVGAnimateMotionElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimateMotionElement::~nsDOMSVGAnimateMotionElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimateMotionElement_h__ */
