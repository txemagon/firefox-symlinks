/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGSymbolElement.idl
 */

#ifndef __gen_nsIDOMSVGSymbolElement_h__
#define __gen_nsIDOMSVGSymbolElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGSymbolElement */
#define NS_IDOMSVGSYMBOLELEMENT_IID_STR "165a3430-f103-4472-a81f-072a3f59db76"

#define NS_IDOMSVGSYMBOLELEMENT_IID \
  {0x165a3430, 0xf103, 0x4472, \
    { 0xa8, 0x1f, 0x07, 0x2a, 0x3f, 0x59, 0xdb, 0x76 }}

class NS_NO_VTABLE nsIDOMSVGSymbolElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSYMBOLELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGSymbolElement, NS_IDOMSVGSYMBOLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSYMBOLELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSYMBOLELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSYMBOLELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGSymbolElement : public nsIDOMSVGSymbolElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSYMBOLELEMENT

  nsDOMSVGSymbolElement();

private:
  ~nsDOMSVGSymbolElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGSymbolElement, nsIDOMSVGSymbolElement)

nsDOMSVGSymbolElement::nsDOMSVGSymbolElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGSymbolElement::~nsDOMSVGSymbolElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGSymbolElement_h__ */
