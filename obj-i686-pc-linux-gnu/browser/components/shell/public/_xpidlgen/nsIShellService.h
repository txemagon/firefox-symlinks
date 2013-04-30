/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/browser/components/shell/public/nsIShellService.idl
 */

#ifndef __gen_nsIShellService_h__
#define __gen_nsIShellService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIShellService */
#define NS_ISHELLSERVICE_IID_STR "99d2e9f1-3c86-40f7-81fd-3060c18489f0"

#define NS_ISHELLSERVICE_IID \
  {0x99d2e9f1, 0x3c86, 0x40f7, \
    { 0x81, 0xfd, 0x30, 0x60, 0xc1, 0x84, 0x89, 0xf0 }}

class NS_NO_VTABLE nsIShellService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHELLSERVICE_IID)

  /* boolean isDefaultBrowser (in boolean aStartupCheck, [optional] in boolean aForAllTypes); */
  NS_IMETHOD IsDefaultBrowser(bool aStartupCheck, bool aForAllTypes, bool *_retval) = 0;

  /* void setDefaultBrowser (in boolean aClaimAllTypes, in boolean aForAllUsers); */
  NS_IMETHOD SetDefaultBrowser(bool aClaimAllTypes, bool aForAllUsers) = 0;

  /* attribute boolean shouldCheckDefaultBrowser; */
  NS_IMETHOD GetShouldCheckDefaultBrowser(bool *aShouldCheckDefaultBrowser) = 0;
  NS_IMETHOD SetShouldCheckDefaultBrowser(bool aShouldCheckDefaultBrowser) = 0;

  /* readonly attribute boolean canSetDesktopBackground; */
  NS_IMETHOD GetCanSetDesktopBackground(bool *aCanSetDesktopBackground) = 0;

  enum {
    BACKGROUND_TILE = 1,
    BACKGROUND_STRETCH = 2,
    BACKGROUND_CENTER = 3,
    BACKGROUND_FILL = 4,
    BACKGROUND_FIT = 5
  };

  /* void setDesktopBackground (in nsIDOMElement aElement, in long aPosition); */
  NS_IMETHOD SetDesktopBackground(nsIDOMElement *aElement, int32_t aPosition) = 0;

  enum {
    APPLICATION_MAIL = 0,
    APPLICATION_NEWS = 1
  };

  /* void openApplication (in long aApplication); */
  NS_IMETHOD OpenApplication(int32_t aApplication) = 0;

  /* attribute unsigned long desktopBackgroundColor; */
  NS_IMETHOD GetDesktopBackgroundColor(uint32_t *aDesktopBackgroundColor) = 0;
  NS_IMETHOD SetDesktopBackgroundColor(uint32_t aDesktopBackgroundColor) = 0;

  /* void openApplicationWithURI (in nsIFile aApplication, in ACString aURI); */
  NS_IMETHOD OpenApplicationWithURI(nsIFile *aApplication, const nsACString & aURI) = 0;

  /* readonly attribute nsIFile defaultFeedReader; */
  NS_IMETHOD GetDefaultFeedReader(nsIFile * *aDefaultFeedReader) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIShellService, NS_ISHELLSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHELLSERVICE \
  NS_IMETHOD IsDefaultBrowser(bool aStartupCheck, bool aForAllTypes, bool *_retval); \
  NS_IMETHOD SetDefaultBrowser(bool aClaimAllTypes, bool aForAllUsers); \
  NS_IMETHOD GetShouldCheckDefaultBrowser(bool *aShouldCheckDefaultBrowser); \
  NS_IMETHOD SetShouldCheckDefaultBrowser(bool aShouldCheckDefaultBrowser); \
  NS_IMETHOD GetCanSetDesktopBackground(bool *aCanSetDesktopBackground); \
  NS_IMETHOD SetDesktopBackground(nsIDOMElement *aElement, int32_t aPosition); \
  NS_IMETHOD OpenApplication(int32_t aApplication); \
  NS_IMETHOD GetDesktopBackgroundColor(uint32_t *aDesktopBackgroundColor); \
  NS_IMETHOD SetDesktopBackgroundColor(uint32_t aDesktopBackgroundColor); \
  NS_IMETHOD OpenApplicationWithURI(nsIFile *aApplication, const nsACString & aURI); \
  NS_IMETHOD GetDefaultFeedReader(nsIFile * *aDefaultFeedReader); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHELLSERVICE(_to) \
  NS_IMETHOD IsDefaultBrowser(bool aStartupCheck, bool aForAllTypes, bool *_retval) { return _to IsDefaultBrowser(aStartupCheck, aForAllTypes, _retval); } \
  NS_IMETHOD SetDefaultBrowser(bool aClaimAllTypes, bool aForAllUsers) { return _to SetDefaultBrowser(aClaimAllTypes, aForAllUsers); } \
  NS_IMETHOD GetShouldCheckDefaultBrowser(bool *aShouldCheckDefaultBrowser) { return _to GetShouldCheckDefaultBrowser(aShouldCheckDefaultBrowser); } \
  NS_IMETHOD SetShouldCheckDefaultBrowser(bool aShouldCheckDefaultBrowser) { return _to SetShouldCheckDefaultBrowser(aShouldCheckDefaultBrowser); } \
  NS_IMETHOD GetCanSetDesktopBackground(bool *aCanSetDesktopBackground) { return _to GetCanSetDesktopBackground(aCanSetDesktopBackground); } \
  NS_IMETHOD SetDesktopBackground(nsIDOMElement *aElement, int32_t aPosition) { return _to SetDesktopBackground(aElement, aPosition); } \
  NS_IMETHOD OpenApplication(int32_t aApplication) { return _to OpenApplication(aApplication); } \
  NS_IMETHOD GetDesktopBackgroundColor(uint32_t *aDesktopBackgroundColor) { return _to GetDesktopBackgroundColor(aDesktopBackgroundColor); } \
  NS_IMETHOD SetDesktopBackgroundColor(uint32_t aDesktopBackgroundColor) { return _to SetDesktopBackgroundColor(aDesktopBackgroundColor); } \
  NS_IMETHOD OpenApplicationWithURI(nsIFile *aApplication, const nsACString & aURI) { return _to OpenApplicationWithURI(aApplication, aURI); } \
  NS_IMETHOD GetDefaultFeedReader(nsIFile * *aDefaultFeedReader) { return _to GetDefaultFeedReader(aDefaultFeedReader); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHELLSERVICE(_to) \
  NS_IMETHOD IsDefaultBrowser(bool aStartupCheck, bool aForAllTypes, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDefaultBrowser(aStartupCheck, aForAllTypes, _retval); } \
  NS_IMETHOD SetDefaultBrowser(bool aClaimAllTypes, bool aForAllUsers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultBrowser(aClaimAllTypes, aForAllUsers); } \
  NS_IMETHOD GetShouldCheckDefaultBrowser(bool *aShouldCheckDefaultBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShouldCheckDefaultBrowser(aShouldCheckDefaultBrowser); } \
  NS_IMETHOD SetShouldCheckDefaultBrowser(bool aShouldCheckDefaultBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShouldCheckDefaultBrowser(aShouldCheckDefaultBrowser); } \
  NS_IMETHOD GetCanSetDesktopBackground(bool *aCanSetDesktopBackground) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanSetDesktopBackground(aCanSetDesktopBackground); } \
  NS_IMETHOD SetDesktopBackground(nsIDOMElement *aElement, int32_t aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDesktopBackground(aElement, aPosition); } \
  NS_IMETHOD OpenApplication(int32_t aApplication) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenApplication(aApplication); } \
  NS_IMETHOD GetDesktopBackgroundColor(uint32_t *aDesktopBackgroundColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDesktopBackgroundColor(aDesktopBackgroundColor); } \
  NS_IMETHOD SetDesktopBackgroundColor(uint32_t aDesktopBackgroundColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDesktopBackgroundColor(aDesktopBackgroundColor); } \
  NS_IMETHOD OpenApplicationWithURI(nsIFile *aApplication, const nsACString & aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenApplicationWithURI(aApplication, aURI); } \
  NS_IMETHOD GetDefaultFeedReader(nsIFile * *aDefaultFeedReader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultFeedReader(aDefaultFeedReader); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsShellService : public nsIShellService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHELLSERVICE

  nsShellService();

private:
  ~nsShellService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsShellService, nsIShellService)

nsShellService::nsShellService()
{
  /* member initializers and constructor code */
}

nsShellService::~nsShellService()
{
  /* destructor code */
}

/* boolean isDefaultBrowser (in boolean aStartupCheck, [optional] in boolean aForAllTypes); */
NS_IMETHODIMP nsShellService::IsDefaultBrowser(bool aStartupCheck, bool aForAllTypes, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultBrowser (in boolean aClaimAllTypes, in boolean aForAllUsers); */
NS_IMETHODIMP nsShellService::SetDefaultBrowser(bool aClaimAllTypes, bool aForAllUsers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean shouldCheckDefaultBrowser; */
NS_IMETHODIMP nsShellService::GetShouldCheckDefaultBrowser(bool *aShouldCheckDefaultBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsShellService::SetShouldCheckDefaultBrowser(bool aShouldCheckDefaultBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canSetDesktopBackground; */
NS_IMETHODIMP nsShellService::GetCanSetDesktopBackground(bool *aCanSetDesktopBackground)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDesktopBackground (in nsIDOMElement aElement, in long aPosition); */
NS_IMETHODIMP nsShellService::SetDesktopBackground(nsIDOMElement *aElement, int32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openApplication (in long aApplication); */
NS_IMETHODIMP nsShellService::OpenApplication(int32_t aApplication)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long desktopBackgroundColor; */
NS_IMETHODIMP nsShellService::GetDesktopBackgroundColor(uint32_t *aDesktopBackgroundColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsShellService::SetDesktopBackgroundColor(uint32_t aDesktopBackgroundColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openApplicationWithURI (in nsIFile aApplication, in ACString aURI); */
NS_IMETHODIMP nsShellService::OpenApplicationWithURI(nsIFile *aApplication, const nsACString & aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile defaultFeedReader; */
NS_IMETHODIMP nsShellService::GetDefaultFeedReader(nsIFile * *aDefaultFeedReader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIShellService_h__ */
