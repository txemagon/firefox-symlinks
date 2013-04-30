/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGLocatable.idl
 */

#ifndef __gen_nsIDOMSVGLocatable_h__
#define __gen_nsIDOMSVGLocatable_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGRect; /* forward declaration */

class nsIDOMSVGElement; /* forward declaration */


/* starting interface:    nsIDOMSVGLocatable */
#define NS_IDOMSVGLOCATABLE_IID_STR "9cf4fc9c-90b2-4d66-88f5-35049b558aee"

#define NS_IDOMSVGLOCATABLE_IID \
  {0x9cf4fc9c, 0x90b2, 0x4d66, \
    { 0x88, 0xf5, 0x35, 0x04, 0x9b, 0x55, 0x8a, 0xee }}

class NS_NO_VTABLE nsIDOMSVGLocatable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGLOCATABLE_IID)

  /* readonly attribute nsIDOMSVGElement nearestViewportElement; */
  NS_IMETHOD GetNearestViewportElement(nsIDOMSVGElement * *aNearestViewportElement) = 0;

  /* readonly attribute nsIDOMSVGElement farthestViewportElement; */
  NS_IMETHOD GetFarthestViewportElement(nsIDOMSVGElement * *aFarthestViewportElement) = 0;

  /* nsIDOMSVGRect getBBox (); */
  NS_IMETHOD GetBBox(nsIDOMSVGRect * *_retval) = 0;

  /* nsISupports getCTM (); */
  NS_IMETHOD GetCTM(nsISupports * *_retval) = 0;

  /* nsISupports getScreenCTM (); */
  NS_IMETHOD GetScreenCTM(nsISupports * *_retval) = 0;

  /* nsISupports getTransformToElement (in nsIDOMSVGElement element); */
  NS_IMETHOD GetTransformToElement(nsIDOMSVGElement *element, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGLocatable, NS_IDOMSVGLOCATABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGLOCATABLE \
  NS_IMETHOD GetNearestViewportElement(nsIDOMSVGElement * *aNearestViewportElement); \
  NS_IMETHOD GetFarthestViewportElement(nsIDOMSVGElement * *aFarthestViewportElement); \
  NS_IMETHOD GetBBox(nsIDOMSVGRect * *_retval); \
  NS_IMETHOD GetCTM(nsISupports * *_retval); \
  NS_IMETHOD GetScreenCTM(nsISupports * *_retval); \
  NS_IMETHOD GetTransformToElement(nsIDOMSVGElement *element, nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGLOCATABLE(_to) \
  NS_IMETHOD GetNearestViewportElement(nsIDOMSVGElement * *aNearestViewportElement) { return _to GetNearestViewportElement(aNearestViewportElement); } \
  NS_IMETHOD GetFarthestViewportElement(nsIDOMSVGElement * *aFarthestViewportElement) { return _to GetFarthestViewportElement(aFarthestViewportElement); } \
  NS_IMETHOD GetBBox(nsIDOMSVGRect * *_retval) { return _to GetBBox(_retval); } \
  NS_IMETHOD GetCTM(nsISupports * *_retval) { return _to GetCTM(_retval); } \
  NS_IMETHOD GetScreenCTM(nsISupports * *_retval) { return _to GetScreenCTM(_retval); } \
  NS_IMETHOD GetTransformToElement(nsIDOMSVGElement *element, nsISupports * *_retval) { return _to GetTransformToElement(element, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGLOCATABLE(_to) \
  NS_IMETHOD GetNearestViewportElement(nsIDOMSVGElement * *aNearestViewportElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNearestViewportElement(aNearestViewportElement); } \
  NS_IMETHOD GetFarthestViewportElement(nsIDOMSVGElement * *aFarthestViewportElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFarthestViewportElement(aFarthestViewportElement); } \
  NS_IMETHOD GetBBox(nsIDOMSVGRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBBox(_retval); } \
  NS_IMETHOD GetCTM(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCTM(_retval); } \
  NS_IMETHOD GetScreenCTM(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenCTM(_retval); } \
  NS_IMETHOD GetTransformToElement(nsIDOMSVGElement *element, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransformToElement(element, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGLocatable : public nsIDOMSVGLocatable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGLOCATABLE

  nsDOMSVGLocatable();

private:
  ~nsDOMSVGLocatable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGLocatable, nsIDOMSVGLocatable)

nsDOMSVGLocatable::nsDOMSVGLocatable()
{
  /* member initializers and constructor code */
}

nsDOMSVGLocatable::~nsDOMSVGLocatable()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGElement nearestViewportElement; */
NS_IMETHODIMP nsDOMSVGLocatable::GetNearestViewportElement(nsIDOMSVGElement * *aNearestViewportElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGElement farthestViewportElement; */
NS_IMETHODIMP nsDOMSVGLocatable::GetFarthestViewportElement(nsIDOMSVGElement * *aFarthestViewportElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGRect getBBox (); */
NS_IMETHODIMP nsDOMSVGLocatable::GetBBox(nsIDOMSVGRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getCTM (); */
NS_IMETHODIMP nsDOMSVGLocatable::GetCTM(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getScreenCTM (); */
NS_IMETHODIMP nsDOMSVGLocatable::GetScreenCTM(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getTransformToElement (in nsIDOMSVGElement element); */
NS_IMETHODIMP nsDOMSVGLocatable::GetTransformToElement(nsIDOMSVGElement *element, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGLocatable_h__ */
