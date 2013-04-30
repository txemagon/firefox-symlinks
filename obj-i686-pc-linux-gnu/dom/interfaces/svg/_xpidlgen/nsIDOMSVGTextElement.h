/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGTextElement.idl
 */

#ifndef __gen_nsIDOMSVGTextElement_h__
#define __gen_nsIDOMSVGTextElement_h__


#ifndef __gen_nsIDOMSVGTextPositionElem_h__
#include "nsIDOMSVGTextPositionElem.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGTextElement */
#define NS_IDOMSVGTEXTELEMENT_IID_STR "e69f79f5-f6fe-4885-8f47-481ba88572c1"

#define NS_IDOMSVGTEXTELEMENT_IID \
  {0xe69f79f5, 0xf6fe, 0x4885, \
    { 0x8f, 0x47, 0x48, 0x1b, 0xa8, 0x85, 0x72, 0xc1 }}

class NS_NO_VTABLE nsIDOMSVGTextElement : public nsIDOMSVGTextPositioningElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTEXTELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTextElement, NS_IDOMSVGTEXTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTEXTELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTEXTELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTEXTELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTextElement : public nsIDOMSVGTextElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTEXTELEMENT

  nsDOMSVGTextElement();

private:
  ~nsDOMSVGTextElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTextElement, nsIDOMSVGTextElement)

nsDOMSVGTextElement::nsDOMSVGTextElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTextElement::~nsDOMSVGTextElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTextElement_h__ */
