/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGAElement.idl
 */

#ifndef __gen_nsIDOMSVGAElement_h__
#define __gen_nsIDOMSVGAElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedString; /* forward declaration */


/* starting interface:    nsIDOMSVGAElement */
#define NS_IDOMSVGAELEMENT_IID_STR "6e0eff6e-ce35-4c01-ab3c-ae81b79b40ca"

#define NS_IDOMSVGAELEMENT_IID \
  {0x6e0eff6e, 0xce35, 0x4c01, \
    { 0xab, 0x3c, 0xae, 0x81, 0xb7, 0x9b, 0x40, 0xca }}

class NS_NO_VTABLE nsIDOMSVGAElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGAELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString target; */
  NS_IMETHOD GetTarget(nsIDOMSVGAnimatedString * *aTarget) = 0;

  /* attribute DOMString download; */
  NS_IMETHOD GetDownload(nsAString & aDownload) = 0;
  NS_IMETHOD SetDownload(const nsAString & aDownload) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAElement, NS_IDOMSVGAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGAELEMENT \
  NS_IMETHOD GetTarget(nsIDOMSVGAnimatedString * *aTarget); \
  NS_IMETHOD GetDownload(nsAString & aDownload); \
  NS_IMETHOD SetDownload(const nsAString & aDownload); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGAELEMENT(_to) \
  NS_IMETHOD GetTarget(nsIDOMSVGAnimatedString * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD GetDownload(nsAString & aDownload) { return _to GetDownload(aDownload); } \
  NS_IMETHOD SetDownload(const nsAString & aDownload) { return _to SetDownload(aDownload); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGAELEMENT(_to) \
  NS_IMETHOD GetTarget(nsIDOMSVGAnimatedString * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD GetDownload(nsAString & aDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownload(aDownload); } \
  NS_IMETHOD SetDownload(const nsAString & aDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDownload(aDownload); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAElement : public nsIDOMSVGAElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGAELEMENT

  nsDOMSVGAElement();

private:
  ~nsDOMSVGAElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAElement, nsIDOMSVGAElement)

nsDOMSVGAElement::nsDOMSVGAElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGAElement::~nsDOMSVGAElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString target; */
NS_IMETHODIMP nsDOMSVGAElement::GetTarget(nsIDOMSVGAnimatedString * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString download; */
NS_IMETHODIMP nsDOMSVGAElement::GetDownload(nsAString & aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAElement::SetDownload(const nsAString & aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAElement_h__ */
