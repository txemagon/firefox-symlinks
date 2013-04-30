/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/toolkit/components/places/nsIBrowserHistory.idl
 */

#ifndef __gen_nsIBrowserHistory_h__
#define __gen_nsIBrowserHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIGlobalHistory2_h__
#include "nsIGlobalHistory2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBrowserHistory */
#define NS_IBROWSERHISTORY_IID_STR "d176f8e8-383f-4109-812d-cce015e2d804"

#define NS_IBROWSERHISTORY_IID \
  {0xd176f8e8, 0x383f, 0x4109, \
    { 0x81, 0x2d, 0xcc, 0xe0, 0x15, 0xe2, 0xd8, 0x04 }}

class NS_NO_VTABLE nsIBrowserHistory : public nsIGlobalHistory2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERHISTORY_IID)

  /* void removePage (in nsIURI aURI); */
  NS_IMETHOD RemovePage(nsIURI *aURI) = 0;

  /* void removePages ([array, size_is (aLength)] in nsIURI aURIs, in unsigned long aLength); */
  NS_IMETHOD RemovePages(nsIURI **aURIs, uint32_t aLength) = 0;

  /* void removePagesFromHost (in AUTF8String aHost, in boolean aEntireDomain); */
  NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, bool aEntireDomain) = 0;

  /* void removePagesByTimeframe (in PRTime aBeginTime, in PRTime aEndTime); */
  NS_IMETHOD RemovePagesByTimeframe(PRTime aBeginTime, PRTime aEndTime) = 0;

  /* void removeVisitsByTimeframe (in PRTime aBeginTime, in PRTime aEndTime); */
  NS_IMETHOD RemoveVisitsByTimeframe(PRTime aBeginTime, PRTime aEndTime) = 0;

  /* void removeAllPages (); */
  NS_IMETHOD RemoveAllPages(void) = 0;

  /* void markPageAsTyped (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) = 0;

  /* void markPageAsFollowedLink (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserHistory, NS_IBROWSERHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERHISTORY \
  NS_IMETHOD RemovePage(nsIURI *aURI); \
  NS_IMETHOD RemovePages(nsIURI **aURIs, uint32_t aLength); \
  NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, bool aEntireDomain); \
  NS_IMETHOD RemovePagesByTimeframe(PRTime aBeginTime, PRTime aEndTime); \
  NS_IMETHOD RemoveVisitsByTimeframe(PRTime aBeginTime, PRTime aEndTime); \
  NS_IMETHOD RemoveAllPages(void); \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI); \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERHISTORY(_to) \
  NS_IMETHOD RemovePage(nsIURI *aURI) { return _to RemovePage(aURI); } \
  NS_IMETHOD RemovePages(nsIURI **aURIs, uint32_t aLength) { return _to RemovePages(aURIs, aLength); } \
  NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, bool aEntireDomain) { return _to RemovePagesFromHost(aHost, aEntireDomain); } \
  NS_IMETHOD RemovePagesByTimeframe(PRTime aBeginTime, PRTime aEndTime) { return _to RemovePagesByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD RemoveVisitsByTimeframe(PRTime aBeginTime, PRTime aEndTime) { return _to RemoveVisitsByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD RemoveAllPages(void) { return _to RemoveAllPages(); } \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) { return _to MarkPageAsTyped(aURI); } \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) { return _to MarkPageAsFollowedLink(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERHISTORY(_to) \
  NS_IMETHOD RemovePage(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePage(aURI); } \
  NS_IMETHOD RemovePages(nsIURI **aURIs, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePages(aURIs, aLength); } \
  NS_IMETHOD RemovePagesFromHost(const nsACString & aHost, bool aEntireDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePagesFromHost(aHost, aEntireDomain); } \
  NS_IMETHOD RemovePagesByTimeframe(PRTime aBeginTime, PRTime aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePagesByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD RemoveVisitsByTimeframe(PRTime aBeginTime, PRTime aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveVisitsByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD RemoveAllPages(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllPages(); } \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsTyped(aURI); } \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsFollowedLink(aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserHistory : public nsIBrowserHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERHISTORY

  nsBrowserHistory();

private:
  ~nsBrowserHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserHistory, nsIBrowserHistory)

nsBrowserHistory::nsBrowserHistory()
{
  /* member initializers and constructor code */
}

nsBrowserHistory::~nsBrowserHistory()
{
  /* destructor code */
}

/* void removePage (in nsIURI aURI); */
NS_IMETHODIMP nsBrowserHistory::RemovePage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePages ([array, size_is (aLength)] in nsIURI aURIs, in unsigned long aLength); */
NS_IMETHODIMP nsBrowserHistory::RemovePages(nsIURI **aURIs, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePagesFromHost (in AUTF8String aHost, in boolean aEntireDomain); */
NS_IMETHODIMP nsBrowserHistory::RemovePagesFromHost(const nsACString & aHost, bool aEntireDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePagesByTimeframe (in PRTime aBeginTime, in PRTime aEndTime); */
NS_IMETHODIMP nsBrowserHistory::RemovePagesByTimeframe(PRTime aBeginTime, PRTime aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeVisitsByTimeframe (in PRTime aBeginTime, in PRTime aEndTime); */
NS_IMETHODIMP nsBrowserHistory::RemoveVisitsByTimeframe(PRTime aBeginTime, PRTime aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllPages (); */
NS_IMETHODIMP nsBrowserHistory::RemoveAllPages()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsTyped (in nsIURI aURI); */
NS_IMETHODIMP nsBrowserHistory::MarkPageAsTyped(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsFollowedLink (in nsIURI aURI); */
NS_IMETHODIMP nsBrowserHistory::MarkPageAsFollowedLink(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserHistory_h__ */
