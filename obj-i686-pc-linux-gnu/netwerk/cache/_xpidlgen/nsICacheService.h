/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/netwerk/cache/nsICacheService.idl
 */

#ifndef __gen_nsICacheService_h__
#define __gen_nsICacheService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICache_h__
#include "nsICache.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsICacheListener; /* forward declaration */

class nsICacheSession; /* forward declaration */

class nsICacheVisitor; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsICacheService */
#define NS_ICACHESERVICE_IID_STR "14dbe1e9-f3bc-45af-92f4-2c574fcd4e39"

#define NS_ICACHESERVICE_IID \
  {0x14dbe1e9, 0xf3bc, 0x45af, \
    { 0x92, 0xf4, 0x2c, 0x57, 0x4f, 0xcd, 0x4e, 0x39 }}

class NS_NO_VTABLE nsICacheService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESERVICE_IID)

  /* nsICacheSession createSession (in string clientID, in nsCacheStoragePolicy storagePolicy, in boolean streamBased); */
  NS_IMETHOD CreateSession(const char * clientID, nsCacheStoragePolicy storagePolicy, bool streamBased, nsICacheSession * *_retval) = 0;

  /* void visitEntries (in nsICacheVisitor visitor); */
  NS_IMETHOD VisitEntries(nsICacheVisitor *visitor) = 0;

  /* void evictEntries (in nsCacheStoragePolicy storagePolicy); */
  NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy) = 0;

  /* readonly attribute nsIEventTarget cacheIOTarget; */
  NS_IMETHOD GetCacheIOTarget(nsIEventTarget * *aCacheIOTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheService, NS_ICACHESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESERVICE \
  NS_IMETHOD CreateSession(const char * clientID, nsCacheStoragePolicy storagePolicy, bool streamBased, nsICacheSession * *_retval); \
  NS_IMETHOD VisitEntries(nsICacheVisitor *visitor); \
  NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy); \
  NS_IMETHOD GetCacheIOTarget(nsIEventTarget * *aCacheIOTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESERVICE(_to) \
  NS_IMETHOD CreateSession(const char * clientID, nsCacheStoragePolicy storagePolicy, bool streamBased, nsICacheSession * *_retval) { return _to CreateSession(clientID, storagePolicy, streamBased, _retval); } \
  NS_IMETHOD VisitEntries(nsICacheVisitor *visitor) { return _to VisitEntries(visitor); } \
  NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy) { return _to EvictEntries(storagePolicy); } \
  NS_IMETHOD GetCacheIOTarget(nsIEventTarget * *aCacheIOTarget) { return _to GetCacheIOTarget(aCacheIOTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESERVICE(_to) \
  NS_IMETHOD CreateSession(const char * clientID, nsCacheStoragePolicy storagePolicy, bool streamBased, nsICacheSession * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSession(clientID, storagePolicy, streamBased, _retval); } \
  NS_IMETHOD VisitEntries(nsICacheVisitor *visitor) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitEntries(visitor); } \
  NS_IMETHOD EvictEntries(nsCacheStoragePolicy storagePolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictEntries(storagePolicy); } \
  NS_IMETHOD GetCacheIOTarget(nsIEventTarget * *aCacheIOTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheIOTarget(aCacheIOTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheService : public nsICacheService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESERVICE

  nsCacheService();

private:
  ~nsCacheService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheService, nsICacheService)

nsCacheService::nsCacheService()
{
  /* member initializers and constructor code */
}

nsCacheService::~nsCacheService()
{
  /* destructor code */
}

/* nsICacheSession createSession (in string clientID, in nsCacheStoragePolicy storagePolicy, in boolean streamBased); */
NS_IMETHODIMP nsCacheService::CreateSession(const char * clientID, nsCacheStoragePolicy storagePolicy, bool streamBased, nsICacheSession * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitEntries (in nsICacheVisitor visitor); */
NS_IMETHODIMP nsCacheService::VisitEntries(nsICacheVisitor *visitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictEntries (in nsCacheStoragePolicy storagePolicy); */
NS_IMETHODIMP nsCacheService::EvictEntries(nsCacheStoragePolicy storagePolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIEventTarget cacheIOTarget; */
NS_IMETHODIMP nsCacheService::GetCacheIOTarget(nsIEventTarget * *aCacheIOTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * Observer service notification that is sent when
 * nsICacheService::evictEntries() or nsICacheSession::evictEntries()
 * is called.
 */
#define NS_CACHESERVICE_EMPTYCACHE_TOPIC_ID "cacheservice:empty-cache"

#endif /* __gen_nsICacheService_h__ */
