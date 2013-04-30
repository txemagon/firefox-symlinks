/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/html/nsIDOMHTMLHtmlElement.idl
 */

#ifndef __gen_nsIDOMHTMLHtmlElement_h__
#define __gen_nsIDOMHTMLHtmlElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLHtmlElement */
#define NS_IDOMHTMLHTMLELEMENT_IID_STR "73706343-ba89-4c80-932e-e636e5e8d8e2"

#define NS_IDOMHTMLHTMLELEMENT_IID \
  {0x73706343, 0xba89, 0x4c80, \
    { 0x93, 0x2e, 0xe6, 0x36, 0xe5, 0xe8, 0xd8, 0xe2 }}

class NS_NO_VTABLE nsIDOMHTMLHtmlElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLHTMLELEMENT_IID)

  /* attribute DOMString version; */
  NS_IMETHOD GetVersion(nsAString & aVersion) = 0;
  NS_IMETHOD SetVersion(const nsAString & aVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLHtmlElement, NS_IDOMHTMLHTMLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLHTMLELEMENT \
  NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_IMETHOD SetVersion(const nsAString & aVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLHTMLELEMENT(_to) \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(const nsAString & aVersion) { return _to SetVersion(aVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLHTMLELEMENT(_to) \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(const nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLHtmlElement : public nsIDOMHTMLHtmlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLHTMLELEMENT

  nsDOMHTMLHtmlElement();

private:
  ~nsDOMHTMLHtmlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLHtmlElement, nsIDOMHTMLHtmlElement)

nsDOMHTMLHtmlElement::nsDOMHTMLHtmlElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLHtmlElement::~nsDOMHTMLHtmlElement()
{
  /* destructor code */
}

/* attribute DOMString version; */
NS_IMETHODIMP nsDOMHTMLHtmlElement::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLHtmlElement::SetVersion(const nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLHtmlElement_h__ */
