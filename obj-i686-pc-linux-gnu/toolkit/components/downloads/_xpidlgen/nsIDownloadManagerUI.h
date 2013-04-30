/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/toolkit/components/downloads/nsIDownloadManagerUI.idl
 */

#ifndef __gen_nsIDownloadManagerUI_h__
#define __gen_nsIDownloadManagerUI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIDownloadManagerUI */
#define NS_IDOWNLOADMANAGERUI_IID_STR "bc54ef90-5215-11e2-bcfd-0800200c9a66"

#define NS_IDOWNLOADMANAGERUI_IID \
  {0xbc54ef90, 0x5215, 0x11e2, \
    { 0xbc, 0xfd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDownloadManagerUI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADMANAGERUI_IID)

  enum {
    REASON_USER_INTERACTED = 0,
    REASON_NEW_DOWNLOAD = 1
  };

  /* void show ([optional] in nsIInterfaceRequestor aWindowContext, [optional] in unsigned long aID, [optional] in short aReason, [optional] in boolean aUsePrivateUI); */
  NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, uint32_t aID, int16_t aReason, bool aUsePrivateUI) = 0;

  /* readonly attribute boolean visible; */
  NS_IMETHOD GetVisible(bool *aVisible) = 0;

  /* void getAttention (); */
  NS_IMETHOD GetAttention(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadManagerUI, NS_IDOWNLOADMANAGERUI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADMANAGERUI \
  NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, uint32_t aID, int16_t aReason, bool aUsePrivateUI); \
  NS_IMETHOD GetVisible(bool *aVisible); \
  NS_IMETHOD GetAttention(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADMANAGERUI(_to) \
  NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, uint32_t aID, int16_t aReason, bool aUsePrivateUI) { return _to Show(aWindowContext, aID, aReason, aUsePrivateUI); } \
  NS_IMETHOD GetVisible(bool *aVisible) { return _to GetVisible(aVisible); } \
  NS_IMETHOD GetAttention(void) { return _to GetAttention(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADMANAGERUI(_to) \
  NS_IMETHOD Show(nsIInterfaceRequestor *aWindowContext, uint32_t aID, int16_t aReason, bool aUsePrivateUI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(aWindowContext, aID, aReason, aUsePrivateUI); } \
  NS_IMETHOD GetVisible(bool *aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_IMETHOD GetAttention(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttention(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadManagerUI : public nsIDownloadManagerUI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADMANAGERUI

  nsDownloadManagerUI();

private:
  ~nsDownloadManagerUI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadManagerUI, nsIDownloadManagerUI)

nsDownloadManagerUI::nsDownloadManagerUI()
{
  /* member initializers and constructor code */
}

nsDownloadManagerUI::~nsDownloadManagerUI()
{
  /* destructor code */
}

/* void show ([optional] in nsIInterfaceRequestor aWindowContext, [optional] in unsigned long aID, [optional] in short aReason, [optional] in boolean aUsePrivateUI); */
NS_IMETHODIMP nsDownloadManagerUI::Show(nsIInterfaceRequestor *aWindowContext, uint32_t aID, int16_t aReason, bool aUsePrivateUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean visible; */
NS_IMETHODIMP nsDownloadManagerUI::GetVisible(bool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttention (); */
NS_IMETHODIMP nsDownloadManagerUI::GetAttention()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadManagerUI_h__ */
