/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/xul/nsIDOMXULLabelElement.idl
 */

#ifndef __gen_nsIDOMXULLabelElement_h__
#define __gen_nsIDOMXULLabelElement_h__


#ifndef __gen_nsIDOMXULDescriptionElement_h__
#include "nsIDOMXULDescriptionElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULLabelElement */
#define NS_IDOMXULLABELELEMENT_IID_STR "042fb07f-afeb-454e-809c-532a5a8557d0"

#define NS_IDOMXULLABELELEMENT_IID \
  {0x042fb07f, 0xafeb, 0x454e, \
    { 0x80, 0x9c, 0x53, 0x2a, 0x5a, 0x85, 0x57, 0xd0 }}

class NS_NO_VTABLE nsIDOMXULLabelElement : public nsIDOMXULDescriptionElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULLABELELEMENT_IID)

  /* attribute DOMString accessKey; */
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* attribute DOMString control; */
  NS_IMETHOD GetControl(nsAString & aControl) = 0;
  NS_IMETHOD SetControl(const nsAString & aControl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULLabelElement, NS_IDOMXULLABELELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULLABELELEMENT \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_IMETHOD GetControl(nsAString & aControl); \
  NS_IMETHOD SetControl(const nsAString & aControl); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULLABELELEMENT(_to) \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetControl(nsAString & aControl) { return _to GetControl(aControl); } \
  NS_IMETHOD SetControl(const nsAString & aControl) { return _to SetControl(aControl); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULLABELELEMENT(_to) \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetControl(nsAString & aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControl(aControl); } \
  NS_IMETHOD SetControl(const nsAString & aControl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetControl(aControl); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULLabelElement : public nsIDOMXULLabelElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULLABELELEMENT

  nsDOMXULLabelElement();

private:
  ~nsDOMXULLabelElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULLabelElement, nsIDOMXULLabelElement)

nsDOMXULLabelElement::nsDOMXULLabelElement()
{
  /* member initializers and constructor code */
}

nsDOMXULLabelElement::~nsDOMXULLabelElement()
{
  /* destructor code */
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMXULLabelElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabelElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString control; */
NS_IMETHODIMP nsDOMXULLabelElement::GetControl(nsAString & aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULLabelElement::SetControl(const nsAString & aControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULLabelElement_h__ */
