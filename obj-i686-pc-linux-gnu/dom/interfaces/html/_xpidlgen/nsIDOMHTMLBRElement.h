/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/html/nsIDOMHTMLBRElement.idl
 */

#ifndef __gen_nsIDOMHTMLBRElement_h__
#define __gen_nsIDOMHTMLBRElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLBRElement */
#define NS_IDOMHTMLBRELEMENT_IID_STR "11d1c93a-9538-4be3-8e90-372e25ab9d61"

#define NS_IDOMHTMLBRELEMENT_IID \
  {0x11d1c93a, 0x9538, 0x4be3, \
    { 0x8e, 0x90, 0x37, 0x2e, 0x25, 0xab, 0x9d, 0x61 }}

class NS_NO_VTABLE nsIDOMHTMLBRElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLBRELEMENT_IID)

  /* attribute DOMString clear; */
  NS_IMETHOD GetClear(nsAString & aClear) = 0;
  NS_IMETHOD SetClear(const nsAString & aClear) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLBRElement, NS_IDOMHTMLBRELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLBRELEMENT \
  NS_IMETHOD GetClear(nsAString & aClear); \
  NS_IMETHOD SetClear(const nsAString & aClear); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLBRELEMENT(_to) \
  NS_IMETHOD GetClear(nsAString & aClear) { return _to GetClear(aClear); } \
  NS_IMETHOD SetClear(const nsAString & aClear) { return _to SetClear(aClear); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLBRELEMENT(_to) \
  NS_IMETHOD GetClear(nsAString & aClear) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClear(aClear); } \
  NS_IMETHOD SetClear(const nsAString & aClear) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClear(aClear); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLBRElement : public nsIDOMHTMLBRElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLBRELEMENT

  nsDOMHTMLBRElement();

private:
  ~nsDOMHTMLBRElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLBRElement, nsIDOMHTMLBRElement)

nsDOMHTMLBRElement::nsDOMHTMLBRElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLBRElement::~nsDOMHTMLBRElement()
{
  /* destructor code */
}

/* attribute DOMString clear; */
NS_IMETHODIMP nsDOMHTMLBRElement::GetClear(nsAString & aClear)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBRElement::SetClear(const nsAString & aClear)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLBRElement_h__ */
