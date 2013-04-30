/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGTests.idl
 */

#ifndef __gen_nsIDOMSVGTests_h__
#define __gen_nsIDOMSVGTests_h__


#ifndef __gen_nsIDOMSVGStringList_h__
#include "nsIDOMSVGStringList.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGTests */
#define NS_IDOMSVGTESTS_IID_STR "b6186ed0-0861-11e1-be50-0800200c9a66"

#define NS_IDOMSVGTESTS_IID \
  {0xb6186ed0, 0x0861, 0x11e1, \
    { 0xbe, 0x50, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDOMSVGTests : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTESTS_IID)

  /* readonly attribute nsIDOMSVGStringList requiredFeatures; */
  NS_IMETHOD GetRequiredFeatures(nsIDOMSVGStringList * *aRequiredFeatures) = 0;

  /* readonly attribute nsIDOMSVGStringList requiredExtensions; */
  NS_IMETHOD GetRequiredExtensions(nsIDOMSVGStringList * *aRequiredExtensions) = 0;

  /* readonly attribute nsIDOMSVGStringList systemLanguage; */
  NS_IMETHOD GetSystemLanguage(nsIDOMSVGStringList * *aSystemLanguage) = 0;

  /* boolean hasExtension (in DOMString extension); */
  NS_IMETHOD HasExtension(const nsAString & extension, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTests, NS_IDOMSVGTESTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTESTS \
  NS_IMETHOD GetRequiredFeatures(nsIDOMSVGStringList * *aRequiredFeatures); \
  NS_IMETHOD GetRequiredExtensions(nsIDOMSVGStringList * *aRequiredExtensions); \
  NS_IMETHOD GetSystemLanguage(nsIDOMSVGStringList * *aSystemLanguage); \
  NS_IMETHOD HasExtension(const nsAString & extension, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTESTS(_to) \
  NS_IMETHOD GetRequiredFeatures(nsIDOMSVGStringList * *aRequiredFeatures) { return _to GetRequiredFeatures(aRequiredFeatures); } \
  NS_IMETHOD GetRequiredExtensions(nsIDOMSVGStringList * *aRequiredExtensions) { return _to GetRequiredExtensions(aRequiredExtensions); } \
  NS_IMETHOD GetSystemLanguage(nsIDOMSVGStringList * *aSystemLanguage) { return _to GetSystemLanguage(aSystemLanguage); } \
  NS_IMETHOD HasExtension(const nsAString & extension, bool *_retval) { return _to HasExtension(extension, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTESTS(_to) \
  NS_IMETHOD GetRequiredFeatures(nsIDOMSVGStringList * *aRequiredFeatures) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequiredFeatures(aRequiredFeatures); } \
  NS_IMETHOD GetRequiredExtensions(nsIDOMSVGStringList * *aRequiredExtensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequiredExtensions(aRequiredExtensions); } \
  NS_IMETHOD GetSystemLanguage(nsIDOMSVGStringList * *aSystemLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemLanguage(aSystemLanguage); } \
  NS_IMETHOD HasExtension(const nsAString & extension, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasExtension(extension, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTests : public nsIDOMSVGTests
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTESTS

  nsDOMSVGTests();

private:
  ~nsDOMSVGTests();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTests, nsIDOMSVGTests)

nsDOMSVGTests::nsDOMSVGTests()
{
  /* member initializers and constructor code */
}

nsDOMSVGTests::~nsDOMSVGTests()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGStringList requiredFeatures; */
NS_IMETHODIMP nsDOMSVGTests::GetRequiredFeatures(nsIDOMSVGStringList * *aRequiredFeatures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGStringList requiredExtensions; */
NS_IMETHODIMP nsDOMSVGTests::GetRequiredExtensions(nsIDOMSVGStringList * *aRequiredExtensions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGStringList systemLanguage; */
NS_IMETHODIMP nsDOMSVGTests::GetSystemLanguage(nsIDOMSVGStringList * *aSystemLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasExtension (in DOMString extension); */
NS_IMETHODIMP nsDOMSVGTests::HasExtension(const nsAString & extension, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTests_h__ */
