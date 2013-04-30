/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGAnimatedPathData.idl
 */

#ifndef __gen_nsIDOMSVGAnimatedPathData_h__
#define __gen_nsIDOMSVGAnimatedPathData_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimatedPathData */
#define NS_IDOMSVGANIMATEDPATHDATA_IID_STR "6ef2b400-dbf4-4c12-8787-fe15caac5648"

#define NS_IDOMSVGANIMATEDPATHDATA_IID \
  {0x6ef2b400, 0xdbf4, 0x4c12, \
    { 0x87, 0x87, 0xfe, 0x15, 0xca, 0xac, 0x56, 0x48 }}

class NS_NO_VTABLE nsIDOMSVGAnimatedPathData : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATEDPATHDATA_IID)

  /* readonly attribute nsISupports pathSegList; */
  NS_IMETHOD GetPathSegList(nsISupports * *aPathSegList) = 0;

  /* readonly attribute nsISupports normalizedPathSegList; */
  NS_IMETHOD GetNormalizedPathSegList(nsISupports * *aNormalizedPathSegList) = 0;

  /* readonly attribute nsISupports animatedPathSegList; */
  NS_IMETHOD GetAnimatedPathSegList(nsISupports * *aAnimatedPathSegList) = 0;

  /* readonly attribute nsISupports animatedNormalizedPathSegList; */
  NS_IMETHOD GetAnimatedNormalizedPathSegList(nsISupports * *aAnimatedNormalizedPathSegList) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimatedPathData, NS_IDOMSVGANIMATEDPATHDATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATEDPATHDATA \
  NS_IMETHOD GetPathSegList(nsISupports * *aPathSegList); \
  NS_IMETHOD GetNormalizedPathSegList(nsISupports * *aNormalizedPathSegList); \
  NS_IMETHOD GetAnimatedPathSegList(nsISupports * *aAnimatedPathSegList); \
  NS_IMETHOD GetAnimatedNormalizedPathSegList(nsISupports * *aAnimatedNormalizedPathSegList); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATEDPATHDATA(_to) \
  NS_IMETHOD GetPathSegList(nsISupports * *aPathSegList) { return _to GetPathSegList(aPathSegList); } \
  NS_IMETHOD GetNormalizedPathSegList(nsISupports * *aNormalizedPathSegList) { return _to GetNormalizedPathSegList(aNormalizedPathSegList); } \
  NS_IMETHOD GetAnimatedPathSegList(nsISupports * *aAnimatedPathSegList) { return _to GetAnimatedPathSegList(aAnimatedPathSegList); } \
  NS_IMETHOD GetAnimatedNormalizedPathSegList(nsISupports * *aAnimatedNormalizedPathSegList) { return _to GetAnimatedNormalizedPathSegList(aAnimatedNormalizedPathSegList); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATEDPATHDATA(_to) \
  NS_IMETHOD GetPathSegList(nsISupports * *aPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathSegList(aPathSegList); } \
  NS_IMETHOD GetNormalizedPathSegList(nsISupports * *aNormalizedPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNormalizedPathSegList(aNormalizedPathSegList); } \
  NS_IMETHOD GetAnimatedPathSegList(nsISupports * *aAnimatedPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimatedPathSegList(aAnimatedPathSegList); } \
  NS_IMETHOD GetAnimatedNormalizedPathSegList(nsISupports * *aAnimatedNormalizedPathSegList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimatedNormalizedPathSegList(aAnimatedNormalizedPathSegList); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimatedPathData : public nsIDOMSVGAnimatedPathData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATEDPATHDATA

  nsDOMSVGAnimatedPathData();

private:
  ~nsDOMSVGAnimatedPathData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimatedPathData, nsIDOMSVGAnimatedPathData)

nsDOMSVGAnimatedPathData::nsDOMSVGAnimatedPathData()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimatedPathData::~nsDOMSVGAnimatedPathData()
{
  /* destructor code */
}

/* readonly attribute nsISupports pathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetPathSegList(nsISupports * *aPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports normalizedPathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetNormalizedPathSegList(nsISupports * *aNormalizedPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports animatedPathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetAnimatedPathSegList(nsISupports * *aAnimatedPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports animatedNormalizedPathSegList; */
NS_IMETHODIMP nsDOMSVGAnimatedPathData::GetAnimatedNormalizedPathSegList(nsISupports * *aAnimatedNormalizedPathSegList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimatedPathData_h__ */
