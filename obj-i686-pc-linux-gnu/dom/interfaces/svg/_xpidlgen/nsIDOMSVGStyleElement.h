/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGStyleElement.idl
 */

#ifndef __gen_nsIDOMSVGStyleElement_h__
#define __gen_nsIDOMSVGStyleElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGStyleElement */
#define NS_IDOMSVGSTYLEELEMENT_IID_STR "53da8f96-e2f0-45ac-b8ae-3cacc5981383"

#define NS_IDOMSVGSTYLEELEMENT_IID \
  {0x53da8f96, 0xe2f0, 0x45ac, \
    { 0xb8, 0xae, 0x3c, 0xac, 0xc5, 0x98, 0x13, 0x83 }}

class NS_NO_VTABLE nsIDOMSVGStyleElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSTYLEELEMENT_IID)

  /* attribute DOMString xmlspace; */
  NS_IMETHOD GetXmlspace(nsAString & aXmlspace) = 0;
  NS_IMETHOD SetXmlspace(const nsAString & aXmlspace) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;
  NS_IMETHOD SetMedia(const nsAString & aMedia) = 0;

  /* attribute DOMString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGStyleElement, NS_IDOMSVGSTYLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSTYLEELEMENT \
  NS_IMETHOD GetXmlspace(nsAString & aXmlspace); \
  NS_IMETHOD SetXmlspace(const nsAString & aXmlspace); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetMedia(nsAString & aMedia); \
  NS_IMETHOD SetMedia(const nsAString & aMedia); \
  NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_IMETHOD SetTitle(const nsAString & aTitle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSTYLEELEMENT(_to) \
  NS_IMETHOD GetXmlspace(nsAString & aXmlspace) { return _to GetXmlspace(aXmlspace); } \
  NS_IMETHOD SetXmlspace(const nsAString & aXmlspace) { return _to SetXmlspace(aXmlspace); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return _to GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return _to SetMedia(aMedia); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSTYLEELEMENT(_to) \
  NS_IMETHOD GetXmlspace(nsAString & aXmlspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXmlspace(aXmlspace); } \
  NS_IMETHOD SetXmlspace(const nsAString & aXmlspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetXmlspace(aXmlspace); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMedia(aMedia); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGStyleElement : public nsIDOMSVGStyleElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSTYLEELEMENT

  nsDOMSVGStyleElement();

private:
  ~nsDOMSVGStyleElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGStyleElement, nsIDOMSVGStyleElement)

nsDOMSVGStyleElement::nsDOMSVGStyleElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGStyleElement::~nsDOMSVGStyleElement()
{
  /* destructor code */
}

/* attribute DOMString xmlspace; */
NS_IMETHODIMP nsDOMSVGStyleElement::GetXmlspace(nsAString & aXmlspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGStyleElement::SetXmlspace(const nsAString & aXmlspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMSVGStyleElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGStyleElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString media; */
NS_IMETHODIMP nsDOMSVGStyleElement::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGStyleElement::SetMedia(const nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMSVGStyleElement::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGStyleElement::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGStyleElement_h__ */
