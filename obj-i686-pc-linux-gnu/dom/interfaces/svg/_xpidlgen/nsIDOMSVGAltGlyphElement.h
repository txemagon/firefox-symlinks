/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGAltGlyphElement.idl
 */

#ifndef __gen_nsIDOMSVGAltGlyphElement_h__
#define __gen_nsIDOMSVGAltGlyphElement_h__


#ifndef __gen_nsIDOMSVGTextPositionElem_h__
#include "nsIDOMSVGTextPositionElem.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAltGlyphElement */
#define NS_IDOMSVGALTGLYPHELEMENT_IID_STR "d7274f91-0fc7-42f1-ad56-3c58af2b0113"

#define NS_IDOMSVGALTGLYPHELEMENT_IID \
  {0xd7274f91, 0x0fc7, 0x42f1, \
    { 0xad, 0x56, 0x3c, 0x58, 0xaf, 0x2b, 0x01, 0x13 }}

class NS_NO_VTABLE nsIDOMSVGAltGlyphElement : public nsIDOMSVGTextPositioningElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGALTGLYPHELEMENT_IID)

  /* attribute DOMString glyphRef; */
  NS_IMETHOD GetGlyphRef(nsAString & aGlyphRef) = 0;
  NS_IMETHOD SetGlyphRef(const nsAString & aGlyphRef) = 0;

  /* attribute DOMString format; */
  NS_IMETHOD GetFormat(nsAString & aFormat) = 0;
  NS_IMETHOD SetFormat(const nsAString & aFormat) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAltGlyphElement, NS_IDOMSVGALTGLYPHELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGALTGLYPHELEMENT \
  NS_IMETHOD GetGlyphRef(nsAString & aGlyphRef); \
  NS_IMETHOD SetGlyphRef(const nsAString & aGlyphRef); \
  NS_IMETHOD GetFormat(nsAString & aFormat); \
  NS_IMETHOD SetFormat(const nsAString & aFormat); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGALTGLYPHELEMENT(_to) \
  NS_IMETHOD GetGlyphRef(nsAString & aGlyphRef) { return _to GetGlyphRef(aGlyphRef); } \
  NS_IMETHOD SetGlyphRef(const nsAString & aGlyphRef) { return _to SetGlyphRef(aGlyphRef); } \
  NS_IMETHOD GetFormat(nsAString & aFormat) { return _to GetFormat(aFormat); } \
  NS_IMETHOD SetFormat(const nsAString & aFormat) { return _to SetFormat(aFormat); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGALTGLYPHELEMENT(_to) \
  NS_IMETHOD GetGlyphRef(nsAString & aGlyphRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlyphRef(aGlyphRef); } \
  NS_IMETHOD SetGlyphRef(const nsAString & aGlyphRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGlyphRef(aGlyphRef); } \
  NS_IMETHOD GetFormat(nsAString & aFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormat(aFormat); } \
  NS_IMETHOD SetFormat(const nsAString & aFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFormat(aFormat); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAltGlyphElement : public nsIDOMSVGAltGlyphElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGALTGLYPHELEMENT

  nsDOMSVGAltGlyphElement();

private:
  ~nsDOMSVGAltGlyphElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAltGlyphElement, nsIDOMSVGAltGlyphElement)

nsDOMSVGAltGlyphElement::nsDOMSVGAltGlyphElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGAltGlyphElement::~nsDOMSVGAltGlyphElement()
{
  /* destructor code */
}

/* attribute DOMString glyphRef; */
NS_IMETHODIMP nsDOMSVGAltGlyphElement::GetGlyphRef(nsAString & aGlyphRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAltGlyphElement::SetGlyphRef(const nsAString & aGlyphRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString format; */
NS_IMETHODIMP nsDOMSVGAltGlyphElement::GetFormat(nsAString & aFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAltGlyphElement::SetFormat(const nsAString & aFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAltGlyphElement_h__ */
