/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGDefsElement.idl
 */

#ifndef __gen_nsIDOMSVGDefsElement_h__
#define __gen_nsIDOMSVGDefsElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGDefsElement */
#define NS_IDOMSVGDEFSELEMENT_IID_STR "3f8d6b9c-cf03-45a6-b8a5-57ecbb7655da"

#define NS_IDOMSVGDEFSELEMENT_IID \
  {0x3f8d6b9c, 0xcf03, 0x45a6, \
    { 0xb8, 0xa5, 0x57, 0xec, 0xbb, 0x76, 0x55, 0xda }}

class NS_NO_VTABLE nsIDOMSVGDefsElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGDEFSELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGDefsElement, NS_IDOMSVGDEFSELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGDEFSELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGDEFSELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGDEFSELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGDefsElement : public nsIDOMSVGDefsElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGDEFSELEMENT

  nsDOMSVGDefsElement();

private:
  ~nsDOMSVGDefsElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGDefsElement, nsIDOMSVGDefsElement)

nsDOMSVGDefsElement::nsDOMSVGDefsElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGDefsElement::~nsDOMSVGDefsElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGDefsElement_h__ */
