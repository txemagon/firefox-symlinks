/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/html/nsIDOMHTMLModElement.idl
 */

#ifndef __gen_nsIDOMHTMLModElement_h__
#define __gen_nsIDOMHTMLModElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLModElement */
#define NS_IDOMHTMLMODELEMENT_IID_STR "4564c9ef-795b-4080-ae48-c4527855390c"

#define NS_IDOMHTMLMODELEMENT_IID \
  {0x4564c9ef, 0x795b, 0x4080, \
    { 0xae, 0x48, 0xc4, 0x52, 0x78, 0x55, 0x39, 0x0c }}

class NS_NO_VTABLE nsIDOMHTMLModElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMODELEMENT_IID)

  /* attribute DOMString cite; */
  NS_IMETHOD GetCite(nsAString & aCite) = 0;
  NS_IMETHOD SetCite(const nsAString & aCite) = 0;

  /* attribute DOMString dateTime; */
  NS_IMETHOD GetDateTime(nsAString & aDateTime) = 0;
  NS_IMETHOD SetDateTime(const nsAString & aDateTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLModElement, NS_IDOMHTMLMODELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMODELEMENT \
  NS_IMETHOD GetCite(nsAString & aCite); \
  NS_IMETHOD SetCite(const nsAString & aCite); \
  NS_IMETHOD GetDateTime(nsAString & aDateTime); \
  NS_IMETHOD SetDateTime(const nsAString & aDateTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMODELEMENT(_to) \
  NS_IMETHOD GetCite(nsAString & aCite) { return _to GetCite(aCite); } \
  NS_IMETHOD SetCite(const nsAString & aCite) { return _to SetCite(aCite); } \
  NS_IMETHOD GetDateTime(nsAString & aDateTime) { return _to GetDateTime(aDateTime); } \
  NS_IMETHOD SetDateTime(const nsAString & aDateTime) { return _to SetDateTime(aDateTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMODELEMENT(_to) \
  NS_IMETHOD GetCite(nsAString & aCite) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCite(aCite); } \
  NS_IMETHOD SetCite(const nsAString & aCite) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCite(aCite); } \
  NS_IMETHOD GetDateTime(nsAString & aDateTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDateTime(aDateTime); } \
  NS_IMETHOD SetDateTime(const nsAString & aDateTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDateTime(aDateTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLModElement : public nsIDOMHTMLModElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMODELEMENT

  nsDOMHTMLModElement();

private:
  ~nsDOMHTMLModElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLModElement, nsIDOMHTMLModElement)

nsDOMHTMLModElement::nsDOMHTMLModElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLModElement::~nsDOMHTMLModElement()
{
  /* destructor code */
}

/* attribute DOMString cite; */
NS_IMETHODIMP nsDOMHTMLModElement::GetCite(nsAString & aCite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLModElement::SetCite(const nsAString & aCite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dateTime; */
NS_IMETHODIMP nsDOMHTMLModElement::GetDateTime(nsAString & aDateTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLModElement::SetDateTime(const nsAString & aDateTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLModElement_h__ */
