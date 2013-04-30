/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGDescElement.idl
 */

#ifndef __gen_nsIDOMSVGDescElement_h__
#define __gen_nsIDOMSVGDescElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGDescElement */
#define NS_IDOMSVGDESCELEMENT_IID_STR "ed14ba6a-090d-4096-a225-08bd56678fe6"

#define NS_IDOMSVGDESCELEMENT_IID \
  {0xed14ba6a, 0x090d, 0x4096, \
    { 0xa2, 0x25, 0x08, 0xbd, 0x56, 0x67, 0x8f, 0xe6 }}

class NS_NO_VTABLE nsIDOMSVGDescElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGDESCELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGDescElement, NS_IDOMSVGDESCELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGDESCELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGDESCELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGDESCELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGDescElement : public nsIDOMSVGDescElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGDESCELEMENT

  nsDOMSVGDescElement();

private:
  ~nsDOMSVGDescElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGDescElement, nsIDOMSVGDescElement)

nsDOMSVGDescElement::nsDOMSVGDescElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGDescElement::~nsDOMSVGDescElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGDescElement_h__ */
