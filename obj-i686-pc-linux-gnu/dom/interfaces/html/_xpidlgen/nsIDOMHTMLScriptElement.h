/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/html/nsIDOMHTMLScriptElement.idl
 */

#ifndef __gen_nsIDOMHTMLScriptElement_h__
#define __gen_nsIDOMHTMLScriptElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLScriptElement */
#define NS_IDOMHTMLSCRIPTELEMENT_IID_STR "e2f548f6-9955-4820-a9e6-3a9fd43c7111"

#define NS_IDOMHTMLSCRIPTELEMENT_IID \
  {0xe2f548f6, 0x9955, 0x4820, \
    { 0xa9, 0xe6, 0x3a, 0x9f, 0xd4, 0x3c, 0x71, 0x11 }}

class NS_NO_VTABLE nsIDOMHTMLScriptElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSCRIPTELEMENT_IID)

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute boolean async; */
  NS_IMETHOD GetAsync(bool *aAsync) = 0;
  NS_IMETHOD SetAsync(bool aAsync) = 0;

  /* attribute boolean defer; */
  NS_IMETHOD GetDefer(bool *aDefer) = 0;
  NS_IMETHOD SetDefer(bool aDefer) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString charset; */
  NS_IMETHOD GetCharset(nsAString & aCharset) = 0;
  NS_IMETHOD SetCharset(const nsAString & aCharset) = 0;

  /* attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_IMETHOD SetText(const nsAString & aText) = 0;

  /* attribute DOMString htmlFor; */
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) = 0;
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) = 0;

  /* attribute DOMString event; */
  NS_IMETHOD GetEvent(nsAString & aEvent) = 0;
  NS_IMETHOD SetEvent(const nsAString & aEvent) = 0;

  /* attribute DOMString crossOrigin; */
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) = 0;
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLScriptElement, NS_IDOMHTMLSCRIPTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSCRIPTELEMENT \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_IMETHOD GetAsync(bool *aAsync); \
  NS_IMETHOD SetAsync(bool aAsync); \
  NS_IMETHOD GetDefer(bool *aDefer); \
  NS_IMETHOD SetDefer(bool aDefer); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetCharset(nsAString & aCharset); \
  NS_IMETHOD SetCharset(const nsAString & aCharset); \
  NS_IMETHOD GetText(nsAString & aText); \
  NS_IMETHOD SetText(const nsAString & aText); \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor); \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor); \
  NS_IMETHOD GetEvent(nsAString & aEvent); \
  NS_IMETHOD SetEvent(const nsAString & aEvent); \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin); \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSCRIPTELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetAsync(bool *aAsync) { return _to GetAsync(aAsync); } \
  NS_IMETHOD SetAsync(bool aAsync) { return _to SetAsync(aAsync); } \
  NS_IMETHOD GetDefer(bool *aDefer) { return _to GetDefer(aDefer); } \
  NS_IMETHOD SetDefer(bool aDefer) { return _to SetDefer(aDefer); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) { return _to GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) { return _to SetCharset(aCharset); } \
  NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return _to SetText(aText); } \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) { return _to GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) { return _to SetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetEvent(nsAString & aEvent) { return _to GetEvent(aEvent); } \
  NS_IMETHOD SetEvent(const nsAString & aEvent) { return _to SetEvent(aEvent); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return _to GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return _to SetCrossOrigin(aCrossOrigin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSCRIPTELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetAsync(bool *aAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsync(aAsync); } \
  NS_IMETHOD SetAsync(bool aAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsync(aAsync); } \
  NS_IMETHOD GetDefer(bool *aDefer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefer(aDefer); } \
  NS_IMETHOD SetDefer(bool aDefer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefer(aDefer); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetEvent(nsAString & aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvent(aEvent); } \
  NS_IMETHOD SetEvent(const nsAString & aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEvent(aEvent); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrossOrigin(aCrossOrigin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLScriptElement : public nsIDOMHTMLScriptElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSCRIPTELEMENT

  nsDOMHTMLScriptElement();

private:
  ~nsDOMHTMLScriptElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLScriptElement, nsIDOMHTMLScriptElement)

nsDOMHTMLScriptElement::nsDOMHTMLScriptElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLScriptElement::~nsDOMHTMLScriptElement()
{
  /* destructor code */
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean async; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetAsync(bool *aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetAsync(bool aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean defer; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetDefer(bool *aDefer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetDefer(bool aDefer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString charset; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetCharset(nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetCharset(const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString text; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString htmlFor; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetHtmlFor(nsAString & aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetHtmlFor(const nsAString & aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString event; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetEvent(nsAString & aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetEvent(const nsAString & aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crossOrigin; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetCrossOrigin(nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetCrossOrigin(const nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLScriptElement_h__ */
