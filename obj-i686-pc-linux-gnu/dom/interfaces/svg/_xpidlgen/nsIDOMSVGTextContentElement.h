/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGTextContentElement.idl
 */

#ifndef __gen_nsIDOMSVGTextContentElement_h__
#define __gen_nsIDOMSVGTextContentElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGRect; /* forward declaration */


/* starting interface:    nsIDOMSVGTextContentElement */
#define NS_IDOMSVGTEXTCONTENTELEMENT_IID_STR "8a884160-db64-4bf7-b932-15398e536a8d"

#define NS_IDOMSVGTEXTCONTENTELEMENT_IID \
  {0x8a884160, 0xdb64, 0x4bf7, \
    { 0xb9, 0x32, 0x15, 0x39, 0x8e, 0x53, 0x6a, 0x8d }}

class NS_NO_VTABLE nsIDOMSVGTextContentElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTEXTCONTENTELEMENT_IID)

  enum {
    LENGTHADJUST_UNKNOWN = 0U,
    LENGTHADJUST_SPACING = 1U,
    LENGTHADJUST_SPACINGANDGLYPHS = 2U
  };

  /* readonly attribute nsIDOMSVGAnimatedLength textLength; */
  NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration lengthAdjust; */
  NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust) = 0;

  /* long getNumberOfChars (); */
  NS_IMETHOD GetNumberOfChars(int32_t *_retval) = 0;

  /* float getComputedTextLength (); */
  NS_IMETHOD GetComputedTextLength(float *_retval) = 0;

  /* float getSubStringLength (in unsigned long charnum, in unsigned long nchars); */
  NS_IMETHOD GetSubStringLength(uint32_t charnum, uint32_t nchars, float *_retval) = 0;

  /* nsISupports getStartPositionOfChar (in unsigned long charnum); */
  NS_IMETHOD GetStartPositionOfChar(uint32_t charnum, nsISupports * *_retval) = 0;

  /* nsISupports getEndPositionOfChar (in unsigned long charnum); */
  NS_IMETHOD GetEndPositionOfChar(uint32_t charnum, nsISupports * *_retval) = 0;

  /* nsIDOMSVGRect getExtentOfChar (in unsigned long charnum); */
  NS_IMETHOD GetExtentOfChar(uint32_t charnum, nsIDOMSVGRect * *_retval) = 0;

  /* float getRotationOfChar (in unsigned long charnum); */
  NS_IMETHOD GetRotationOfChar(uint32_t charnum, float *_retval) = 0;

  /* long getCharNumAtPosition (in nsISupports point); */
  NS_IMETHOD GetCharNumAtPosition(nsISupports *point, int32_t *_retval) = 0;

  /* void selectSubString (in unsigned long charnum, in unsigned long nchars); */
  NS_IMETHOD SelectSubString(uint32_t charnum, uint32_t nchars) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTextContentElement, NS_IDOMSVGTEXTCONTENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTEXTCONTENTELEMENT \
  NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength); \
  NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust); \
  NS_IMETHOD GetNumberOfChars(int32_t *_retval); \
  NS_IMETHOD GetComputedTextLength(float *_retval); \
  NS_IMETHOD GetSubStringLength(uint32_t charnum, uint32_t nchars, float *_retval); \
  NS_IMETHOD GetStartPositionOfChar(uint32_t charnum, nsISupports * *_retval); \
  NS_IMETHOD GetEndPositionOfChar(uint32_t charnum, nsISupports * *_retval); \
  NS_IMETHOD GetExtentOfChar(uint32_t charnum, nsIDOMSVGRect * *_retval); \
  NS_IMETHOD GetRotationOfChar(uint32_t charnum, float *_retval); \
  NS_IMETHOD GetCharNumAtPosition(nsISupports *point, int32_t *_retval); \
  NS_IMETHOD SelectSubString(uint32_t charnum, uint32_t nchars); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTEXTCONTENTELEMENT(_to) \
  NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust) { return _to GetLengthAdjust(aLengthAdjust); } \
  NS_IMETHOD GetNumberOfChars(int32_t *_retval) { return _to GetNumberOfChars(_retval); } \
  NS_IMETHOD GetComputedTextLength(float *_retval) { return _to GetComputedTextLength(_retval); } \
  NS_IMETHOD GetSubStringLength(uint32_t charnum, uint32_t nchars, float *_retval) { return _to GetSubStringLength(charnum, nchars, _retval); } \
  NS_IMETHOD GetStartPositionOfChar(uint32_t charnum, nsISupports * *_retval) { return _to GetStartPositionOfChar(charnum, _retval); } \
  NS_IMETHOD GetEndPositionOfChar(uint32_t charnum, nsISupports * *_retval) { return _to GetEndPositionOfChar(charnum, _retval); } \
  NS_IMETHOD GetExtentOfChar(uint32_t charnum, nsIDOMSVGRect * *_retval) { return _to GetExtentOfChar(charnum, _retval); } \
  NS_IMETHOD GetRotationOfChar(uint32_t charnum, float *_retval) { return _to GetRotationOfChar(charnum, _retval); } \
  NS_IMETHOD GetCharNumAtPosition(nsISupports *point, int32_t *_retval) { return _to GetCharNumAtPosition(point, _retval); } \
  NS_IMETHOD SelectSubString(uint32_t charnum, uint32_t nchars) { return _to SelectSubString(charnum, nchars); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTEXTCONTENTELEMENT(_to) \
  NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLengthAdjust(aLengthAdjust); } \
  NS_IMETHOD GetNumberOfChars(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfChars(_retval); } \
  NS_IMETHOD GetComputedTextLength(float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComputedTextLength(_retval); } \
  NS_IMETHOD GetSubStringLength(uint32_t charnum, uint32_t nchars, float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubStringLength(charnum, nchars, _retval); } \
  NS_IMETHOD GetStartPositionOfChar(uint32_t charnum, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartPositionOfChar(charnum, _retval); } \
  NS_IMETHOD GetEndPositionOfChar(uint32_t charnum, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndPositionOfChar(charnum, _retval); } \
  NS_IMETHOD GetExtentOfChar(uint32_t charnum, nsIDOMSVGRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtentOfChar(charnum, _retval); } \
  NS_IMETHOD GetRotationOfChar(uint32_t charnum, float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotationOfChar(charnum, _retval); } \
  NS_IMETHOD GetCharNumAtPosition(nsISupports *point, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharNumAtPosition(point, _retval); } \
  NS_IMETHOD SelectSubString(uint32_t charnum, uint32_t nchars) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectSubString(charnum, nchars); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTextContentElement : public nsIDOMSVGTextContentElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTEXTCONTENTELEMENT

  nsDOMSVGTextContentElement();

private:
  ~nsDOMSVGTextContentElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTextContentElement, nsIDOMSVGTextContentElement)

nsDOMSVGTextContentElement::nsDOMSVGTextContentElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTextContentElement::~nsDOMSVGTextContentElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength textLength; */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration lengthAdjust; */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getNumberOfChars (); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetNumberOfChars(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getComputedTextLength (); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetComputedTextLength(float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getSubStringLength (in unsigned long charnum, in unsigned long nchars); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetSubStringLength(uint32_t charnum, uint32_t nchars, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getStartPositionOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetStartPositionOfChar(uint32_t charnum, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getEndPositionOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetEndPositionOfChar(uint32_t charnum, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGRect getExtentOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetExtentOfChar(uint32_t charnum, nsIDOMSVGRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getRotationOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetRotationOfChar(uint32_t charnum, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getCharNumAtPosition (in nsISupports point); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetCharNumAtPosition(nsISupports *point, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectSubString (in unsigned long charnum, in unsigned long nchars); */
NS_IMETHODIMP nsDOMSVGTextContentElement::SelectSubString(uint32_t charnum, uint32_t nchars)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTextContentElement_h__ */
