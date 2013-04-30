/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGScriptElement.idl
 */

#ifndef __gen_nsIDOMSVGScriptElement_h__
#define __gen_nsIDOMSVGScriptElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGScriptElement */
#define NS_IDOMSVGSCRIPTELEMENT_IID_STR "b3314a7d-9909-4367-bbdb-9fafb069cdfd"

#define NS_IDOMSVGSCRIPTELEMENT_IID \
  {0xb3314a7d, 0x9909, 0x4367, \
    { 0xbb, 0xdb, 0x9f, 0xaf, 0xb0, 0x69, 0xcd, 0xfd }}

class NS_NO_VTABLE nsIDOMSVGScriptElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSCRIPTELEMENT_IID)

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString crossOrigin; */
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) = 0;
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGScriptElement, NS_IDOMSVGSCRIPTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSCRIPTELEMENT \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin); \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSCRIPTELEMENT(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return _to GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return _to SetCrossOrigin(aCrossOrigin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSCRIPTELEMENT(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrossOrigin(aCrossOrigin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGScriptElement : public nsIDOMSVGScriptElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSCRIPTELEMENT

  nsDOMSVGScriptElement();

private:
  ~nsDOMSVGScriptElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGScriptElement, nsIDOMSVGScriptElement)

nsDOMSVGScriptElement::nsDOMSVGScriptElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGScriptElement::~nsDOMSVGScriptElement()
{
  /* destructor code */
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMSVGScriptElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGScriptElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crossOrigin; */
NS_IMETHODIMP nsDOMSVGScriptElement::GetCrossOrigin(nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGScriptElement::SetCrossOrigin(const nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGScriptElement_h__ */
