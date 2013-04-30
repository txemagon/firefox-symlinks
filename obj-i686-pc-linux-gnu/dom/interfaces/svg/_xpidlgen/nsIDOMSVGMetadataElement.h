/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGMetadataElement.idl
 */

#ifndef __gen_nsIDOMSVGMetadataElement_h__
#define __gen_nsIDOMSVGMetadataElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGMetadataElement */
#define NS_IDOMSVGMETADATAELEMENT_IID_STR "749982a4-743b-4ec6-8bb2-fa602976ea58"

#define NS_IDOMSVGMETADATAELEMENT_IID \
  {0x749982a4, 0x743b, 0x4ec6, \
    { 0x8b, 0xb2, 0xfa, 0x60, 0x29, 0x76, 0xea, 0x58 }}

class NS_NO_VTABLE nsIDOMSVGMetadataElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGMETADATAELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGMetadataElement, NS_IDOMSVGMETADATAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGMETADATAELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGMETADATAELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGMETADATAELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGMetadataElement : public nsIDOMSVGMetadataElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGMETADATAELEMENT

  nsDOMSVGMetadataElement();

private:
  ~nsDOMSVGMetadataElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGMetadataElement, nsIDOMSVGMetadataElement)

nsDOMSVGMetadataElement::nsDOMSVGMetadataElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGMetadataElement::~nsDOMSVGMetadataElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGMetadataElement_h__ */
