/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/netwerk/test/httpserver/nsIHttpServer.idl
 */

#ifndef __gen_nsIHttpServer_h__
#define __gen_nsIHttpServer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIHttpServer; /* forward declaration */

class nsIHttpServerStoppedCallback; /* forward declaration */

class nsIHttpRequestHandler; /* forward declaration */

class nsIHttpRequest; /* forward declaration */

class nsIHttpResponse; /* forward declaration */

class nsIHttpServerIdentity; /* forward declaration */


/* starting interface:    nsIHttpServer */
#define NS_IHTTPSERVER_IID_STR "cea8812e-faa6-4013-9396-f9936cbb74ec"

#define NS_IHTTPSERVER_IID \
  {0xcea8812e, 0xfaa6, 0x4013, \
    { 0x93, 0x96, 0xf9, 0x93, 0x6c, 0xbb, 0x74, 0xec }}

class NS_NO_VTABLE nsIHttpServer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPSERVER_IID)

  /* void start (in long port); */
  NS_IMETHOD Start(int32_t port) = 0;

  /* void stop (in nsIHttpServerStoppedCallback callback); */
  NS_IMETHOD Stop(nsIHttpServerStoppedCallback *callback) = 0;

  /* void registerFile (in string path, in nsIFile file); */
  NS_IMETHOD RegisterFile(const char * path, nsIFile *file) = 0;

  /* void registerPathHandler (in string path, in nsIHttpRequestHandler handler); */
  NS_IMETHOD RegisterPathHandler(const char * path, nsIHttpRequestHandler *handler) = 0;

  /* void registerPrefixHandler (in string prefix, in nsIHttpRequestHandler handler); */
  NS_IMETHOD RegisterPrefixHandler(const char * prefix, nsIHttpRequestHandler *handler) = 0;

  /* void registerErrorHandler (in unsigned long code, in nsIHttpRequestHandler handler); */
  NS_IMETHOD RegisterErrorHandler(uint32_t code, nsIHttpRequestHandler *handler) = 0;

  /* void registerDirectory (in string path, in nsIFile dir); */
  NS_IMETHOD RegisterDirectory(const char * path, nsIFile *dir) = 0;

  /* void registerContentType (in string extension, in string type); */
  NS_IMETHOD RegisterContentType(const char * extension, const char * type) = 0;

  /* void setIndexHandler (in nsIHttpRequestHandler handler); */
  NS_IMETHOD SetIndexHandler(nsIHttpRequestHandler *handler) = 0;

  /* readonly attribute nsIHttpServerIdentity identity; */
  NS_IMETHOD GetIdentity(nsIHttpServerIdentity * *aIdentity) = 0;

  /* AString getState (in AString path, in AString key); */
  NS_IMETHOD GetState(const nsAString & path, const nsAString & key, nsAString & _retval) = 0;

  /* void setState (in AString path, in AString key, in AString value); */
  NS_IMETHOD SetState(const nsAString & path, const nsAString & key, const nsAString & value) = 0;

  /* AString getSharedState (in AString key); */
  NS_IMETHOD GetSharedState(const nsAString & key, nsAString & _retval) = 0;

  /* void setSharedState (in AString key, in AString value); */
  NS_IMETHOD SetSharedState(const nsAString & key, const nsAString & value) = 0;

  /* nsISupports getObjectState (in AString key); */
  NS_IMETHOD GetObjectState(const nsAString & key, nsISupports * *_retval) = 0;

  /* void setObjectState (in AString key, in nsISupports value); */
  NS_IMETHOD SetObjectState(const nsAString & key, nsISupports *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpServer, NS_IHTTPSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPSERVER \
  NS_IMETHOD Start(int32_t port); \
  NS_IMETHOD Stop(nsIHttpServerStoppedCallback *callback); \
  NS_IMETHOD RegisterFile(const char * path, nsIFile *file); \
  NS_IMETHOD RegisterPathHandler(const char * path, nsIHttpRequestHandler *handler); \
  NS_IMETHOD RegisterPrefixHandler(const char * prefix, nsIHttpRequestHandler *handler); \
  NS_IMETHOD RegisterErrorHandler(uint32_t code, nsIHttpRequestHandler *handler); \
  NS_IMETHOD RegisterDirectory(const char * path, nsIFile *dir); \
  NS_IMETHOD RegisterContentType(const char * extension, const char * type); \
  NS_IMETHOD SetIndexHandler(nsIHttpRequestHandler *handler); \
  NS_IMETHOD GetIdentity(nsIHttpServerIdentity * *aIdentity); \
  NS_IMETHOD GetState(const nsAString & path, const nsAString & key, nsAString & _retval); \
  NS_IMETHOD SetState(const nsAString & path, const nsAString & key, const nsAString & value); \
  NS_IMETHOD GetSharedState(const nsAString & key, nsAString & _retval); \
  NS_IMETHOD SetSharedState(const nsAString & key, const nsAString & value); \
  NS_IMETHOD GetObjectState(const nsAString & key, nsISupports * *_retval); \
  NS_IMETHOD SetObjectState(const nsAString & key, nsISupports *value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPSERVER(_to) \
  NS_IMETHOD Start(int32_t port) { return _to Start(port); } \
  NS_IMETHOD Stop(nsIHttpServerStoppedCallback *callback) { return _to Stop(callback); } \
  NS_IMETHOD RegisterFile(const char * path, nsIFile *file) { return _to RegisterFile(path, file); } \
  NS_IMETHOD RegisterPathHandler(const char * path, nsIHttpRequestHandler *handler) { return _to RegisterPathHandler(path, handler); } \
  NS_IMETHOD RegisterPrefixHandler(const char * prefix, nsIHttpRequestHandler *handler) { return _to RegisterPrefixHandler(prefix, handler); } \
  NS_IMETHOD RegisterErrorHandler(uint32_t code, nsIHttpRequestHandler *handler) { return _to RegisterErrorHandler(code, handler); } \
  NS_IMETHOD RegisterDirectory(const char * path, nsIFile *dir) { return _to RegisterDirectory(path, dir); } \
  NS_IMETHOD RegisterContentType(const char * extension, const char * type) { return _to RegisterContentType(extension, type); } \
  NS_IMETHOD SetIndexHandler(nsIHttpRequestHandler *handler) { return _to SetIndexHandler(handler); } \
  NS_IMETHOD GetIdentity(nsIHttpServerIdentity * *aIdentity) { return _to GetIdentity(aIdentity); } \
  NS_IMETHOD GetState(const nsAString & path, const nsAString & key, nsAString & _retval) { return _to GetState(path, key, _retval); } \
  NS_IMETHOD SetState(const nsAString & path, const nsAString & key, const nsAString & value) { return _to SetState(path, key, value); } \
  NS_IMETHOD GetSharedState(const nsAString & key, nsAString & _retval) { return _to GetSharedState(key, _retval); } \
  NS_IMETHOD SetSharedState(const nsAString & key, const nsAString & value) { return _to SetSharedState(key, value); } \
  NS_IMETHOD GetObjectState(const nsAString & key, nsISupports * *_retval) { return _to GetObjectState(key, _retval); } \
  NS_IMETHOD SetObjectState(const nsAString & key, nsISupports *value) { return _to SetObjectState(key, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPSERVER(_to) \
  NS_IMETHOD Start(int32_t port) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(port); } \
  NS_IMETHOD Stop(nsIHttpServerStoppedCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(callback); } \
  NS_IMETHOD RegisterFile(const char * path, nsIFile *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterFile(path, file); } \
  NS_IMETHOD RegisterPathHandler(const char * path, nsIHttpRequestHandler *handler) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPathHandler(path, handler); } \
  NS_IMETHOD RegisterPrefixHandler(const char * prefix, nsIHttpRequestHandler *handler) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPrefixHandler(prefix, handler); } \
  NS_IMETHOD RegisterErrorHandler(uint32_t code, nsIHttpRequestHandler *handler) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterErrorHandler(code, handler); } \
  NS_IMETHOD RegisterDirectory(const char * path, nsIFile *dir) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterDirectory(path, dir); } \
  NS_IMETHOD RegisterContentType(const char * extension, const char * type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterContentType(extension, type); } \
  NS_IMETHOD SetIndexHandler(nsIHttpRequestHandler *handler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIndexHandler(handler); } \
  NS_IMETHOD GetIdentity(nsIHttpServerIdentity * *aIdentity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdentity(aIdentity); } \
  NS_IMETHOD GetState(const nsAString & path, const nsAString & key, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(path, key, _retval); } \
  NS_IMETHOD SetState(const nsAString & path, const nsAString & key, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetState(path, key, value); } \
  NS_IMETHOD GetSharedState(const nsAString & key, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedState(key, _retval); } \
  NS_IMETHOD SetSharedState(const nsAString & key, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSharedState(key, value); } \
  NS_IMETHOD GetObjectState(const nsAString & key, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectState(key, _retval); } \
  NS_IMETHOD SetObjectState(const nsAString & key, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObjectState(key, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpServer : public nsIHttpServer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPSERVER

  nsHttpServer();

private:
  ~nsHttpServer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpServer, nsIHttpServer)

nsHttpServer::nsHttpServer()
{
  /* member initializers and constructor code */
}

nsHttpServer::~nsHttpServer()
{
  /* destructor code */
}

/* void start (in long port); */
NS_IMETHODIMP nsHttpServer::Start(int32_t port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (in nsIHttpServerStoppedCallback callback); */
NS_IMETHODIMP nsHttpServer::Stop(nsIHttpServerStoppedCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerFile (in string path, in nsIFile file); */
NS_IMETHODIMP nsHttpServer::RegisterFile(const char * path, nsIFile *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPathHandler (in string path, in nsIHttpRequestHandler handler); */
NS_IMETHODIMP nsHttpServer::RegisterPathHandler(const char * path, nsIHttpRequestHandler *handler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPrefixHandler (in string prefix, in nsIHttpRequestHandler handler); */
NS_IMETHODIMP nsHttpServer::RegisterPrefixHandler(const char * prefix, nsIHttpRequestHandler *handler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerErrorHandler (in unsigned long code, in nsIHttpRequestHandler handler); */
NS_IMETHODIMP nsHttpServer::RegisterErrorHandler(uint32_t code, nsIHttpRequestHandler *handler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerDirectory (in string path, in nsIFile dir); */
NS_IMETHODIMP nsHttpServer::RegisterDirectory(const char * path, nsIFile *dir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerContentType (in string extension, in string type); */
NS_IMETHODIMP nsHttpServer::RegisterContentType(const char * extension, const char * type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIndexHandler (in nsIHttpRequestHandler handler); */
NS_IMETHODIMP nsHttpServer::SetIndexHandler(nsIHttpRequestHandler *handler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIHttpServerIdentity identity; */
NS_IMETHODIMP nsHttpServer::GetIdentity(nsIHttpServerIdentity * *aIdentity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getState (in AString path, in AString key); */
NS_IMETHODIMP nsHttpServer::GetState(const nsAString & path, const nsAString & key, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setState (in AString path, in AString key, in AString value); */
NS_IMETHODIMP nsHttpServer::SetState(const nsAString & path, const nsAString & key, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getSharedState (in AString key); */
NS_IMETHODIMP nsHttpServer::GetSharedState(const nsAString & key, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSharedState (in AString key, in AString value); */
NS_IMETHODIMP nsHttpServer::SetSharedState(const nsAString & key, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getObjectState (in AString key); */
NS_IMETHODIMP nsHttpServer::GetObjectState(const nsAString & key, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setObjectState (in AString key, in nsISupports value); */
NS_IMETHODIMP nsHttpServer::SetObjectState(const nsAString & key, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpServerStoppedCallback */
#define NS_IHTTPSERVERSTOPPEDCALLBACK_IID_STR "925a6d33-9937-4c63-abe1-a1c56a986455"

#define NS_IHTTPSERVERSTOPPEDCALLBACK_IID \
  {0x925a6d33, 0x9937, 0x4c63, \
    { 0xab, 0xe1, 0xa1, 0xc5, 0x6a, 0x98, 0x64, 0x55 }}

class NS_NO_VTABLE nsIHttpServerStoppedCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPSERVERSTOPPEDCALLBACK_IID)

  /* void onStopped (); */
  NS_IMETHOD OnStopped(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpServerStoppedCallback, NS_IHTTPSERVERSTOPPEDCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPSERVERSTOPPEDCALLBACK \
  NS_IMETHOD OnStopped(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPSERVERSTOPPEDCALLBACK(_to) \
  NS_IMETHOD OnStopped(void) { return _to OnStopped(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPSERVERSTOPPEDCALLBACK(_to) \
  NS_IMETHOD OnStopped(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopped(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpServerStoppedCallback : public nsIHttpServerStoppedCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPSERVERSTOPPEDCALLBACK

  nsHttpServerStoppedCallback();

private:
  ~nsHttpServerStoppedCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpServerStoppedCallback, nsIHttpServerStoppedCallback)

nsHttpServerStoppedCallback::nsHttpServerStoppedCallback()
{
  /* member initializers and constructor code */
}

nsHttpServerStoppedCallback::~nsHttpServerStoppedCallback()
{
  /* destructor code */
}

/* void onStopped (); */
NS_IMETHODIMP nsHttpServerStoppedCallback::OnStopped()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpServerIdentity */
#define NS_IHTTPSERVERIDENTITY_IID_STR "a89de175-ae8e-4c46-91a5-0dba99bbd284"

#define NS_IHTTPSERVERIDENTITY_IID \
  {0xa89de175, 0xae8e, 0x4c46, \
    { 0x91, 0xa5, 0x0d, 0xba, 0x99, 0xbb, 0xd2, 0x84 }}

class NS_NO_VTABLE nsIHttpServerIdentity : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPSERVERIDENTITY_IID)

  /* readonly attribute string primaryScheme; */
  NS_IMETHOD GetPrimaryScheme(char * *aPrimaryScheme) = 0;

  /* readonly attribute string primaryHost; */
  NS_IMETHOD GetPrimaryHost(char * *aPrimaryHost) = 0;

  /* readonly attribute long primaryPort; */
  NS_IMETHOD GetPrimaryPort(int32_t *aPrimaryPort) = 0;

  /* void add (in string scheme, in string host, in long port); */
  NS_IMETHOD Add(const char * scheme, const char * host, int32_t port) = 0;

  /* boolean remove (in string scheme, in string host, in long port); */
  NS_IMETHOD Remove(const char * scheme, const char * host, int32_t port, bool *_retval) = 0;

  /* boolean has (in string scheme, in string host, in long port); */
  NS_IMETHOD Has(const char * scheme, const char * host, int32_t port, bool *_retval) = 0;

  /* string getScheme (in string host, in long port); */
  NS_IMETHOD GetScheme(const char * host, int32_t port, char * *_retval) = 0;

  /* void setPrimary (in string scheme, in string host, in long port); */
  NS_IMETHOD SetPrimary(const char * scheme, const char * host, int32_t port) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpServerIdentity, NS_IHTTPSERVERIDENTITY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPSERVERIDENTITY \
  NS_IMETHOD GetPrimaryScheme(char * *aPrimaryScheme); \
  NS_IMETHOD GetPrimaryHost(char * *aPrimaryHost); \
  NS_IMETHOD GetPrimaryPort(int32_t *aPrimaryPort); \
  NS_IMETHOD Add(const char * scheme, const char * host, int32_t port); \
  NS_IMETHOD Remove(const char * scheme, const char * host, int32_t port, bool *_retval); \
  NS_IMETHOD Has(const char * scheme, const char * host, int32_t port, bool *_retval); \
  NS_IMETHOD GetScheme(const char * host, int32_t port, char * *_retval); \
  NS_IMETHOD SetPrimary(const char * scheme, const char * host, int32_t port); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPSERVERIDENTITY(_to) \
  NS_IMETHOD GetPrimaryScheme(char * *aPrimaryScheme) { return _to GetPrimaryScheme(aPrimaryScheme); } \
  NS_IMETHOD GetPrimaryHost(char * *aPrimaryHost) { return _to GetPrimaryHost(aPrimaryHost); } \
  NS_IMETHOD GetPrimaryPort(int32_t *aPrimaryPort) { return _to GetPrimaryPort(aPrimaryPort); } \
  NS_IMETHOD Add(const char * scheme, const char * host, int32_t port) { return _to Add(scheme, host, port); } \
  NS_IMETHOD Remove(const char * scheme, const char * host, int32_t port, bool *_retval) { return _to Remove(scheme, host, port, _retval); } \
  NS_IMETHOD Has(const char * scheme, const char * host, int32_t port, bool *_retval) { return _to Has(scheme, host, port, _retval); } \
  NS_IMETHOD GetScheme(const char * host, int32_t port, char * *_retval) { return _to GetScheme(host, port, _retval); } \
  NS_IMETHOD SetPrimary(const char * scheme, const char * host, int32_t port) { return _to SetPrimary(scheme, host, port); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPSERVERIDENTITY(_to) \
  NS_IMETHOD GetPrimaryScheme(char * *aPrimaryScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryScheme(aPrimaryScheme); } \
  NS_IMETHOD GetPrimaryHost(char * *aPrimaryHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryHost(aPrimaryHost); } \
  NS_IMETHOD GetPrimaryPort(int32_t *aPrimaryPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryPort(aPrimaryPort); } \
  NS_IMETHOD Add(const char * scheme, const char * host, int32_t port) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(scheme, host, port); } \
  NS_IMETHOD Remove(const char * scheme, const char * host, int32_t port, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(scheme, host, port, _retval); } \
  NS_IMETHOD Has(const char * scheme, const char * host, int32_t port, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(scheme, host, port, _retval); } \
  NS_IMETHOD GetScheme(const char * host, int32_t port, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScheme(host, port, _retval); } \
  NS_IMETHOD SetPrimary(const char * scheme, const char * host, int32_t port) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrimary(scheme, host, port); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpServerIdentity : public nsIHttpServerIdentity
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPSERVERIDENTITY

  nsHttpServerIdentity();

private:
  ~nsHttpServerIdentity();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpServerIdentity, nsIHttpServerIdentity)

nsHttpServerIdentity::nsHttpServerIdentity()
{
  /* member initializers and constructor code */
}

nsHttpServerIdentity::~nsHttpServerIdentity()
{
  /* destructor code */
}

/* readonly attribute string primaryScheme; */
NS_IMETHODIMP nsHttpServerIdentity::GetPrimaryScheme(char * *aPrimaryScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string primaryHost; */
NS_IMETHODIMP nsHttpServerIdentity::GetPrimaryHost(char * *aPrimaryHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long primaryPort; */
NS_IMETHODIMP nsHttpServerIdentity::GetPrimaryPort(int32_t *aPrimaryPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in string scheme, in string host, in long port); */
NS_IMETHODIMP nsHttpServerIdentity::Add(const char * scheme, const char * host, int32_t port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean remove (in string scheme, in string host, in long port); */
NS_IMETHODIMP nsHttpServerIdentity::Remove(const char * scheme, const char * host, int32_t port, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in string scheme, in string host, in long port); */
NS_IMETHODIMP nsHttpServerIdentity::Has(const char * scheme, const char * host, int32_t port, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getScheme (in string host, in long port); */
NS_IMETHODIMP nsHttpServerIdentity::GetScheme(const char * host, int32_t port, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPrimary (in string scheme, in string host, in long port); */
NS_IMETHODIMP nsHttpServerIdentity::SetPrimary(const char * scheme, const char * host, int32_t port)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpRequestHandler */
#define NS_IHTTPREQUESTHANDLER_IID_STR "2bbb4db7-d285-42b3-a3ce-142b8cc7e139"

#define NS_IHTTPREQUESTHANDLER_IID \
  {0x2bbb4db7, 0xd285, 0x42b3, \
    { 0xa3, 0xce, 0x14, 0x2b, 0x8c, 0xc7, 0xe1, 0x39 }}

class NS_NO_VTABLE nsIHttpRequestHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPREQUESTHANDLER_IID)

  /* void handle (in nsIHttpRequest request, in nsIHttpResponse response); */
  NS_IMETHOD Handle(nsIHttpRequest *request, nsIHttpResponse *response) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpRequestHandler, NS_IHTTPREQUESTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPREQUESTHANDLER \
  NS_IMETHOD Handle(nsIHttpRequest *request, nsIHttpResponse *response); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPREQUESTHANDLER(_to) \
  NS_IMETHOD Handle(nsIHttpRequest *request, nsIHttpResponse *response) { return _to Handle(request, response); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPREQUESTHANDLER(_to) \
  NS_IMETHOD Handle(nsIHttpRequest *request, nsIHttpResponse *response) { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(request, response); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpRequestHandler : public nsIHttpRequestHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPREQUESTHANDLER

  nsHttpRequestHandler();

private:
  ~nsHttpRequestHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpRequestHandler, nsIHttpRequestHandler)

nsHttpRequestHandler::nsHttpRequestHandler()
{
  /* member initializers and constructor code */
}

nsHttpRequestHandler::~nsHttpRequestHandler()
{
  /* destructor code */
}

/* void handle (in nsIHttpRequest request, in nsIHttpResponse response); */
NS_IMETHODIMP nsHttpRequestHandler::Handle(nsIHttpRequest *request, nsIHttpResponse *response)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpRequest */
#define NS_IHTTPREQUEST_IID_STR "978cf30e-ad73-42ee-8f22-fe0aaf1bf5d2"

#define NS_IHTTPREQUEST_IID \
  {0x978cf30e, 0xad73, 0x42ee, \
    { 0x8f, 0x22, 0xfe, 0x0a, 0xaf, 0x1b, 0xf5, 0xd2 }}

class NS_NO_VTABLE nsIHttpRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPREQUEST_IID)

  /* readonly attribute string method; */
  NS_IMETHOD GetMethod(char * *aMethod) = 0;

  /* readonly attribute string scheme; */
  NS_IMETHOD GetScheme(char * *aScheme) = 0;

  /* readonly attribute string host; */
  NS_IMETHOD GetHost(char * *aHost) = 0;

  /* readonly attribute unsigned long port; */
  NS_IMETHOD GetPort(uint32_t *aPort) = 0;

  /* readonly attribute string path; */
  NS_IMETHOD GetPath(char * *aPath) = 0;

  /* readonly attribute string queryString; */
  NS_IMETHOD GetQueryString(char * *aQueryString) = 0;

  /* readonly attribute string httpVersion; */
  NS_IMETHOD GetHttpVersion(char * *aHttpVersion) = 0;

  /* string getHeader (in string fieldName); */
  NS_IMETHOD GetHeader(const char * fieldName, char * *_retval) = 0;

  /* boolean hasHeader (in string fieldName); */
  NS_IMETHOD HasHeader(const char * fieldName, bool *_retval) = 0;

  /* readonly attribute nsISimpleEnumerator headers; */
  NS_IMETHOD GetHeaders(nsISimpleEnumerator * *aHeaders) = 0;

  /* readonly attribute nsIInputStream bodyInputStream; */
  NS_IMETHOD GetBodyInputStream(nsIInputStream * *aBodyInputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpRequest, NS_IHTTPREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPREQUEST \
  NS_IMETHOD GetMethod(char * *aMethod); \
  NS_IMETHOD GetScheme(char * *aScheme); \
  NS_IMETHOD GetHost(char * *aHost); \
  NS_IMETHOD GetPort(uint32_t *aPort); \
  NS_IMETHOD GetPath(char * *aPath); \
  NS_IMETHOD GetQueryString(char * *aQueryString); \
  NS_IMETHOD GetHttpVersion(char * *aHttpVersion); \
  NS_IMETHOD GetHeader(const char * fieldName, char * *_retval); \
  NS_IMETHOD HasHeader(const char * fieldName, bool *_retval); \
  NS_IMETHOD GetHeaders(nsISimpleEnumerator * *aHeaders); \
  NS_IMETHOD GetBodyInputStream(nsIInputStream * *aBodyInputStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPREQUEST(_to) \
  NS_IMETHOD GetMethod(char * *aMethod) { return _to GetMethod(aMethod); } \
  NS_IMETHOD GetScheme(char * *aScheme) { return _to GetScheme(aScheme); } \
  NS_IMETHOD GetHost(char * *aHost) { return _to GetHost(aHost); } \
  NS_IMETHOD GetPort(uint32_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetPath(char * *aPath) { return _to GetPath(aPath); } \
  NS_IMETHOD GetQueryString(char * *aQueryString) { return _to GetQueryString(aQueryString); } \
  NS_IMETHOD GetHttpVersion(char * *aHttpVersion) { return _to GetHttpVersion(aHttpVersion); } \
  NS_IMETHOD GetHeader(const char * fieldName, char * *_retval) { return _to GetHeader(fieldName, _retval); } \
  NS_IMETHOD HasHeader(const char * fieldName, bool *_retval) { return _to HasHeader(fieldName, _retval); } \
  NS_IMETHOD GetHeaders(nsISimpleEnumerator * *aHeaders) { return _to GetHeaders(aHeaders); } \
  NS_IMETHOD GetBodyInputStream(nsIInputStream * *aBodyInputStream) { return _to GetBodyInputStream(aBodyInputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPREQUEST(_to) \
  NS_IMETHOD GetMethod(char * *aMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethod(aMethod); } \
  NS_IMETHOD GetScheme(char * *aScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScheme(aScheme); } \
  NS_IMETHOD GetHost(char * *aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetPort(uint32_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetPath(char * *aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_IMETHOD GetQueryString(char * *aQueryString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryString(aQueryString); } \
  NS_IMETHOD GetHttpVersion(char * *aHttpVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHttpVersion(aHttpVersion); } \
  NS_IMETHOD GetHeader(const char * fieldName, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeader(fieldName, _retval); } \
  NS_IMETHOD HasHeader(const char * fieldName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasHeader(fieldName, _retval); } \
  NS_IMETHOD GetHeaders(nsISimpleEnumerator * *aHeaders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaders(aHeaders); } \
  NS_IMETHOD GetBodyInputStream(nsIInputStream * *aBodyInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBodyInputStream(aBodyInputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpRequest : public nsIHttpRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPREQUEST

  nsHttpRequest();

private:
  ~nsHttpRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpRequest, nsIHttpRequest)

nsHttpRequest::nsHttpRequest()
{
  /* member initializers and constructor code */
}

nsHttpRequest::~nsHttpRequest()
{
  /* destructor code */
}

/* readonly attribute string method; */
NS_IMETHODIMP nsHttpRequest::GetMethod(char * *aMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string scheme; */
NS_IMETHODIMP nsHttpRequest::GetScheme(char * *aScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string host; */
NS_IMETHODIMP nsHttpRequest::GetHost(char * *aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long port; */
NS_IMETHODIMP nsHttpRequest::GetPort(uint32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string path; */
NS_IMETHODIMP nsHttpRequest::GetPath(char * *aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string queryString; */
NS_IMETHODIMP nsHttpRequest::GetQueryString(char * *aQueryString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string httpVersion; */
NS_IMETHODIMP nsHttpRequest::GetHttpVersion(char * *aHttpVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getHeader (in string fieldName); */
NS_IMETHODIMP nsHttpRequest::GetHeader(const char * fieldName, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasHeader (in string fieldName); */
NS_IMETHODIMP nsHttpRequest::HasHeader(const char * fieldName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator headers; */
NS_IMETHODIMP nsHttpRequest::GetHeaders(nsISimpleEnumerator * *aHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIInputStream bodyInputStream; */
NS_IMETHODIMP nsHttpRequest::GetBodyInputStream(nsIInputStream * *aBodyInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpResponse */
#define NS_IHTTPRESPONSE_IID_STR "1acd16c2-dc59-42fa-9160-4f26c43c1c21"

#define NS_IHTTPRESPONSE_IID \
  {0x1acd16c2, 0xdc59, 0x42fa, \
    { 0x91, 0x60, 0x4f, 0x26, 0xc4, 0x3c, 0x1c, 0x21 }}

class NS_NO_VTABLE nsIHttpResponse : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPRESPONSE_IID)

  /* void setStatusLine (in string httpVersion, in unsigned short statusCode, in string description); */
  NS_IMETHOD SetStatusLine(const char * httpVersion, uint16_t statusCode, const char * description) = 0;

  /* void setHeader (in string name, in string value, in boolean merge); */
  NS_IMETHOD SetHeader(const char * name, const char * value, bool merge) = 0;

  /* readonly attribute nsIOutputStream bodyOutputStream; */
  NS_IMETHOD GetBodyOutputStream(nsIOutputStream * *aBodyOutputStream) = 0;

  /* void write (in string data); */
  NS_IMETHOD Write(const char * data) = 0;

  /* void processAsync (); */
  NS_IMETHOD ProcessAsync(void) = 0;

  /* void seizePower (); */
  NS_IMETHOD SeizePower(void) = 0;

  /* void finish (); */
  NS_IMETHOD Finish(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpResponse, NS_IHTTPRESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPRESPONSE \
  NS_IMETHOD SetStatusLine(const char * httpVersion, uint16_t statusCode, const char * description); \
  NS_IMETHOD SetHeader(const char * name, const char * value, bool merge); \
  NS_IMETHOD GetBodyOutputStream(nsIOutputStream * *aBodyOutputStream); \
  NS_IMETHOD Write(const char * data); \
  NS_IMETHOD ProcessAsync(void); \
  NS_IMETHOD SeizePower(void); \
  NS_IMETHOD Finish(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPRESPONSE(_to) \
  NS_IMETHOD SetStatusLine(const char * httpVersion, uint16_t statusCode, const char * description) { return _to SetStatusLine(httpVersion, statusCode, description); } \
  NS_IMETHOD SetHeader(const char * name, const char * value, bool merge) { return _to SetHeader(name, value, merge); } \
  NS_IMETHOD GetBodyOutputStream(nsIOutputStream * *aBodyOutputStream) { return _to GetBodyOutputStream(aBodyOutputStream); } \
  NS_IMETHOD Write(const char * data) { return _to Write(data); } \
  NS_IMETHOD ProcessAsync(void) { return _to ProcessAsync(); } \
  NS_IMETHOD SeizePower(void) { return _to SeizePower(); } \
  NS_IMETHOD Finish(void) { return _to Finish(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPRESPONSE(_to) \
  NS_IMETHOD SetStatusLine(const char * httpVersion, uint16_t statusCode, const char * description) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatusLine(httpVersion, statusCode, description); } \
  NS_IMETHOD SetHeader(const char * name, const char * value, bool merge) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeader(name, value, merge); } \
  NS_IMETHOD GetBodyOutputStream(nsIOutputStream * *aBodyOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBodyOutputStream(aBodyOutputStream); } \
  NS_IMETHOD Write(const char * data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(data); } \
  NS_IMETHOD ProcessAsync(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessAsync(); } \
  NS_IMETHOD SeizePower(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SeizePower(); } \
  NS_IMETHOD Finish(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpResponse : public nsIHttpResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPRESPONSE

  nsHttpResponse();

private:
  ~nsHttpResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpResponse, nsIHttpResponse)

nsHttpResponse::nsHttpResponse()
{
  /* member initializers and constructor code */
}

nsHttpResponse::~nsHttpResponse()
{
  /* destructor code */
}

/* void setStatusLine (in string httpVersion, in unsigned short statusCode, in string description); */
NS_IMETHODIMP nsHttpResponse::SetStatusLine(const char * httpVersion, uint16_t statusCode, const char * description)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setHeader (in string name, in string value, in boolean merge); */
NS_IMETHODIMP nsHttpResponse::SetHeader(const char * name, const char * value, bool merge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIOutputStream bodyOutputStream; */
NS_IMETHODIMP nsHttpResponse::GetBodyOutputStream(nsIOutputStream * *aBodyOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write (in string data); */
NS_IMETHODIMP nsHttpResponse::Write(const char * data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processAsync (); */
NS_IMETHODIMP nsHttpResponse::ProcessAsync()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void seizePower (); */
NS_IMETHODIMP nsHttpResponse::SeizePower()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (); */
NS_IMETHODIMP nsHttpResponse::Finish()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpServer_h__ */
