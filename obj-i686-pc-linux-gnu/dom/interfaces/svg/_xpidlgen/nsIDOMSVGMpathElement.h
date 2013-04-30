/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGMpathElement.idl
 */

#ifndef __gen_nsIDOMSVGMpathElement_h__
#define __gen_nsIDOMSVGMpathElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGMpathElement */
#define NS_IDOMSVGMPATHELEMENT_IID_STR "67db3f0c-2a3f-4d56-984f-3d30752faf37"

#define NS_IDOMSVGMPATHELEMENT_IID \
  {0x67db3f0c, 0x2a3f, 0x4d56, \
    { 0x98, 0x4f, 0x3d, 0x30, 0x75, 0x2f, 0xaf, 0x37 }}

class NS_NO_VTABLE nsIDOMSVGMpathElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGMPATHELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGMpathElement, NS_IDOMSVGMPATHELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGMPATHELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGMPATHELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGMPATHELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGMpathElement : public nsIDOMSVGMpathElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGMPATHELEMENT

  nsDOMSVGMpathElement();

private:
  ~nsDOMSVGMpathElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGMpathElement, nsIDOMSVGMpathElement)

nsDOMSVGMpathElement::nsDOMSVGMpathElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGMpathElement::~nsDOMSVGMpathElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGMpathElement_h__ */
