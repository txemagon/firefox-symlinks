/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/layout/inspector/public/inIFlasher.idl
 */

#ifndef __gen_inIFlasher_h__
#define __gen_inIFlasher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    inIFlasher */
#define INIFLASHER_IID_STR "7b4a099f-6f6e-4565-977b-fb622adbff49"

#define INIFLASHER_IID \
  {0x7b4a099f, 0x6f6e, 0x4565, \
    { 0x97, 0x7b, 0xfb, 0x62, 0x2a, 0xdb, 0xff, 0x49 }}

class NS_NO_VTABLE inIFlasher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIFLASHER_IID)

  /* attribute DOMString color; */
  NS_IMETHOD GetColor(nsAString & aColor) = 0;
  NS_IMETHOD SetColor(const nsAString & aColor) = 0;

  /* attribute boolean invert; */
  NS_IMETHOD GetInvert(bool *aInvert) = 0;
  NS_IMETHOD SetInvert(bool aInvert) = 0;

  /* attribute unsigned short thickness; */
  NS_IMETHOD GetThickness(uint16_t *aThickness) = 0;
  NS_IMETHOD SetThickness(uint16_t aThickness) = 0;

  /* void drawElementOutline (in nsIDOMElement aElement); */
  NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement) = 0;

  /* void repaintElement (in nsIDOMElement aElement); */
  NS_IMETHOD RepaintElement(nsIDOMElement *aElement) = 0;

  /* void scrollElementIntoView (in nsIDOMElement aElement); */
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIFlasher, INIFLASHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIFLASHER \
  NS_IMETHOD GetColor(nsAString & aColor); \
  NS_IMETHOD SetColor(const nsAString & aColor); \
  NS_IMETHOD GetInvert(bool *aInvert); \
  NS_IMETHOD SetInvert(bool aInvert); \
  NS_IMETHOD GetThickness(uint16_t *aThickness); \
  NS_IMETHOD SetThickness(uint16_t aThickness); \
  NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement); \
  NS_IMETHOD RepaintElement(nsIDOMElement *aElement); \
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIFLASHER(_to) \
  NS_IMETHOD GetColor(nsAString & aColor) { return _to GetColor(aColor); } \
  NS_IMETHOD SetColor(const nsAString & aColor) { return _to SetColor(aColor); } \
  NS_IMETHOD GetInvert(bool *aInvert) { return _to GetInvert(aInvert); } \
  NS_IMETHOD SetInvert(bool aInvert) { return _to SetInvert(aInvert); } \
  NS_IMETHOD GetThickness(uint16_t *aThickness) { return _to GetThickness(aThickness); } \
  NS_IMETHOD SetThickness(uint16_t aThickness) { return _to SetThickness(aThickness); } \
  NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement) { return _to DrawElementOutline(aElement); } \
  NS_IMETHOD RepaintElement(nsIDOMElement *aElement) { return _to RepaintElement(aElement); } \
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) { return _to ScrollElementIntoView(aElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIFLASHER(_to) \
  NS_IMETHOD GetColor(nsAString & aColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColor(aColor); } \
  NS_IMETHOD SetColor(const nsAString & aColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetColor(aColor); } \
  NS_IMETHOD GetInvert(bool *aInvert) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInvert(aInvert); } \
  NS_IMETHOD SetInvert(bool aInvert) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInvert(aInvert); } \
  NS_IMETHOD GetThickness(uint16_t *aThickness) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThickness(aThickness); } \
  NS_IMETHOD SetThickness(uint16_t aThickness) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThickness(aThickness); } \
  NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawElementOutline(aElement); } \
  NS_IMETHOD RepaintElement(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->RepaintElement(aElement); } \
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollElementIntoView(aElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inFlasher : public inIFlasher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIFLASHER

  inFlasher();

private:
  ~inFlasher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inFlasher, inIFlasher)

inFlasher::inFlasher()
{
  /* member initializers and constructor code */
}

inFlasher::~inFlasher()
{
  /* destructor code */
}

/* attribute DOMString color; */
NS_IMETHODIMP inFlasher::GetColor(nsAString & aColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inFlasher::SetColor(const nsAString & aColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean invert; */
NS_IMETHODIMP inFlasher::GetInvert(bool *aInvert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inFlasher::SetInvert(bool aInvert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short thickness; */
NS_IMETHODIMP inFlasher::GetThickness(uint16_t *aThickness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inFlasher::SetThickness(uint16_t aThickness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drawElementOutline (in nsIDOMElement aElement); */
NS_IMETHODIMP inFlasher::DrawElementOutline(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void repaintElement (in nsIDOMElement aElement); */
NS_IMETHODIMP inFlasher::RepaintElement(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollElementIntoView (in nsIDOMElement aElement); */
NS_IMETHODIMP inFlasher::ScrollElementIntoView(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIFlasher_h__ */
