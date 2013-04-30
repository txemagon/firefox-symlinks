/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/browser/components/nsIBrowserHandler.idl
 */

#ifndef __gen_nsIBrowserHandler_h__
#define __gen_nsIBrowserHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICommandLine; /* forward declaration */


/* starting interface:    nsIBrowserHandler */
#define NS_IBROWSERHANDLER_IID_STR "8d3f5a9d-118d-4548-a137-cf7718679069"

#define NS_IBROWSERHANDLER_IID \
  {0x8d3f5a9d, 0x118d, 0x4548, \
    { 0xa1, 0x37, 0xcf, 0x77, 0x18, 0x67, 0x90, 0x69 }}

class NS_NO_VTABLE nsIBrowserHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERHANDLER_IID)

  /* attribute AUTF8String startPage; */
  NS_IMETHOD GetStartPage(nsACString & aStartPage) = 0;
  NS_IMETHOD SetStartPage(const nsACString & aStartPage) = 0;

  /* attribute AUTF8String defaultArgs; */
  NS_IMETHOD GetDefaultArgs(nsACString & aDefaultArgs) = 0;
  NS_IMETHOD SetDefaultArgs(const nsACString & aDefaultArgs) = 0;

  /* AUTF8String getFeatures (in nsICommandLine aCmdLine); */
  NS_IMETHOD GetFeatures(nsICommandLine *aCmdLine, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserHandler, NS_IBROWSERHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERHANDLER \
  NS_IMETHOD GetStartPage(nsACString & aStartPage); \
  NS_IMETHOD SetStartPage(const nsACString & aStartPage); \
  NS_IMETHOD GetDefaultArgs(nsACString & aDefaultArgs); \
  NS_IMETHOD SetDefaultArgs(const nsACString & aDefaultArgs); \
  NS_IMETHOD GetFeatures(nsICommandLine *aCmdLine, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERHANDLER(_to) \
  NS_IMETHOD GetStartPage(nsACString & aStartPage) { return _to GetStartPage(aStartPage); } \
  NS_IMETHOD SetStartPage(const nsACString & aStartPage) { return _to SetStartPage(aStartPage); } \
  NS_IMETHOD GetDefaultArgs(nsACString & aDefaultArgs) { return _to GetDefaultArgs(aDefaultArgs); } \
  NS_IMETHOD SetDefaultArgs(const nsACString & aDefaultArgs) { return _to SetDefaultArgs(aDefaultArgs); } \
  NS_IMETHOD GetFeatures(nsICommandLine *aCmdLine, nsACString & _retval) { return _to GetFeatures(aCmdLine, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERHANDLER(_to) \
  NS_IMETHOD GetStartPage(nsACString & aStartPage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartPage(aStartPage); } \
  NS_IMETHOD SetStartPage(const nsACString & aStartPage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartPage(aStartPage); } \
  NS_IMETHOD GetDefaultArgs(nsACString & aDefaultArgs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultArgs(aDefaultArgs); } \
  NS_IMETHOD SetDefaultArgs(const nsACString & aDefaultArgs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultArgs(aDefaultArgs); } \
  NS_IMETHOD GetFeatures(nsICommandLine *aCmdLine, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatures(aCmdLine, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserHandler : public nsIBrowserHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERHANDLER

  nsBrowserHandler();

private:
  ~nsBrowserHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserHandler, nsIBrowserHandler)

nsBrowserHandler::nsBrowserHandler()
{
  /* member initializers and constructor code */
}

nsBrowserHandler::~nsBrowserHandler()
{
  /* destructor code */
}

/* attribute AUTF8String startPage; */
NS_IMETHODIMP nsBrowserHandler::GetStartPage(nsACString & aStartPage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBrowserHandler::SetStartPage(const nsACString & aStartPage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String defaultArgs; */
NS_IMETHODIMP nsBrowserHandler::GetDefaultArgs(nsACString & aDefaultArgs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBrowserHandler::SetDefaultArgs(const nsACString & aDefaultArgs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getFeatures (in nsICommandLine aCmdLine); */
NS_IMETHODIMP nsBrowserHandler::GetFeatures(nsICommandLine *aCmdLine, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserHandler_h__ */
