/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/css/nsIDOMCSSValue.idl
 */

#ifndef __gen_nsIDOMCSSValue_h__
#define __gen_nsIDOMCSSValue_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSValue */
#define NS_IDOMCSSVALUE_IID_STR "009f7ea5-9e80-41be-b008-db62f10823f2"

#define NS_IDOMCSSVALUE_IID \
  {0x009f7ea5, 0x9e80, 0x41be, \
    { 0xb0, 0x08, 0xdb, 0x62, 0xf1, 0x08, 0x23, 0xf2 }}

class NS_NO_VTABLE nsIDOMCSSValue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSVALUE_IID)

  enum {
    CSS_INHERIT = 0U,
    CSS_PRIMITIVE_VALUE = 1U,
    CSS_VALUE_LIST = 2U,
    CSS_CUSTOM = 3U
  };

  /* attribute DOMString cssText; */
  NS_IMETHOD GetCssText(nsAString & aCssText) = 0;
  NS_IMETHOD SetCssText(const nsAString & aCssText) = 0;

  /* readonly attribute unsigned short cssValueType; */
  NS_IMETHOD GetCssValueType(uint16_t *aCssValueType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSValue, NS_IDOMCSSVALUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSVALUE \
  NS_IMETHOD GetCssText(nsAString & aCssText); \
  NS_IMETHOD SetCssText(const nsAString & aCssText); \
  NS_IMETHOD GetCssValueType(uint16_t *aCssValueType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSVALUE(_to) \
  NS_IMETHOD GetCssText(nsAString & aCssText) { return _to GetCssText(aCssText); } \
  NS_IMETHOD SetCssText(const nsAString & aCssText) { return _to SetCssText(aCssText); } \
  NS_IMETHOD GetCssValueType(uint16_t *aCssValueType) { return _to GetCssValueType(aCssValueType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSVALUE(_to) \
  NS_IMETHOD GetCssText(nsAString & aCssText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssText(aCssText); } \
  NS_IMETHOD SetCssText(const nsAString & aCssText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCssText(aCssText); } \
  NS_IMETHOD GetCssValueType(uint16_t *aCssValueType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssValueType(aCssValueType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSValue : public nsIDOMCSSValue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSVALUE

  nsDOMCSSValue();

private:
  ~nsDOMCSSValue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCSSValue, nsIDOMCSSValue)

nsDOMCSSValue::nsDOMCSSValue()
{
  /* member initializers and constructor code */
}

nsDOMCSSValue::~nsDOMCSSValue()
{
  /* destructor code */
}

/* attribute DOMString cssText; */
NS_IMETHODIMP nsDOMCSSValue::GetCssText(nsAString & aCssText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSValue::SetCssText(const nsAString & aCssText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short cssValueType; */
NS_IMETHODIMP nsDOMCSSValue::GetCssValueType(uint16_t *aCssValueType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSValue_h__ */
