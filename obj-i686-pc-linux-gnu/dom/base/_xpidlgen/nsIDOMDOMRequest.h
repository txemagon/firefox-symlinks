/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/base/nsIDOMDOMRequest.idl
 */

#ifndef __gen_nsIDOMDOMRequest_h__
#define __gen_nsIDOMDOMRequest_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMError; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIDOMDOMRequest */
#define NS_IDOMDOMREQUEST_IID_STR "d88998b7-ee30-4ae5-bbed-58f5711929de"

#define NS_IDOMDOMREQUEST_IID \
  {0xd88998b7, 0xee30, 0x4ae5, \
    { 0xbb, 0xed, 0x58, 0xf5, 0x71, 0x19, 0x29, 0xde }}

class NS_NO_VTABLE nsIDOMDOMRequest : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMREQUEST_IID)

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute jsval result; */
  NS_IMETHOD GetResult(JS::Value *aResult) = 0;

  /* readonly attribute nsIDOMDOMError error; */
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) = 0;

  /* [implicit_jscontext] attribute jsval onsuccess; */
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess) = 0;
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMRequest, NS_IDOMDOMREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMREQUEST \
  NS_IMETHOD GetReadyState(nsAString & aReadyState); \
  NS_IMETHOD GetResult(JS::Value *aResult); \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError); \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess); \
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMREQUEST(_to) \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetResult(JS::Value *aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess) { return _to GetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess) { return _to SetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMREQUEST(_to) \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetResult(JS::Value *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMRequest : public nsIDOMDOMRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMREQUEST

  nsDOMDOMRequest();

private:
  ~nsDOMDOMRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMRequest, nsIDOMDOMRequest)

nsDOMDOMRequest::nsDOMDOMRequest()
{
  /* member initializers and constructor code */
}

nsDOMDOMRequest::~nsDOMDOMRequest()
{
  /* destructor code */
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMDOMRequest::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval result; */
NS_IMETHODIMP nsDOMDOMRequest::GetResult(JS::Value *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMError error; */
NS_IMETHODIMP nsDOMDOMRequest::GetError(nsIDOMDOMError * *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsuccess; */
NS_IMETHODIMP nsDOMDOMRequest::GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDOMRequest::SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMDOMRequest::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDOMRequest::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMRequestService */
#define NS_IDOMREQUESTSERVICE_IID_STR "10996de9-e6f6-4058-97bd-45f1fe065eb5"

#define NS_IDOMREQUESTSERVICE_IID \
  {0x10996de9, 0xe6f6, 0x4058, \
    { 0x97, 0xbd, 0x45, 0xf1, 0xfe, 0x06, 0x5e, 0xb5 }}

class NS_NO_VTABLE nsIDOMRequestService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMREQUESTSERVICE_IID)

  /* nsIDOMDOMRequest createRequest (in nsIDOMWindow window); */
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval) = 0;

  /* void fireSuccess (in nsIDOMDOMRequest request, in jsval result); */
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, const JS::Value & result) = 0;

  /* void fireError (in nsIDOMDOMRequest request, in DOMString error); */
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error) = 0;

  /* void fireSuccessAsync (in nsIDOMDOMRequest request, in jsval result); */
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, const JS::Value & result) = 0;

  /* void fireErrorAsync (in nsIDOMDOMRequest request, in DOMString error); */
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRequestService, NS_IDOMREQUESTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMREQUESTSERVICE \
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, const JS::Value & result); \
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error); \
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, const JS::Value & result); \
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMREQUESTSERVICE(_to) \
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval) { return _to CreateRequest(window, _retval); } \
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, const JS::Value & result) { return _to FireSuccess(request, result); } \
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error) { return _to FireError(request, error); } \
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, const JS::Value & result) { return _to FireSuccessAsync(request, result); } \
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error) { return _to FireErrorAsync(request, error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMREQUESTSERVICE(_to) \
  NS_IMETHOD CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRequest(window, _retval); } \
  NS_IMETHOD FireSuccess(nsIDOMDOMRequest *request, const JS::Value & result) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireSuccess(request, result); } \
  NS_IMETHOD FireError(nsIDOMDOMRequest *request, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireError(request, error); } \
  NS_IMETHOD FireSuccessAsync(nsIDOMDOMRequest *request, const JS::Value & result) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireSuccessAsync(request, result); } \
  NS_IMETHOD FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireErrorAsync(request, error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRequestService : public nsIDOMRequestService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMREQUESTSERVICE

  nsDOMRequestService();

private:
  ~nsDOMRequestService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRequestService, nsIDOMRequestService)

nsDOMRequestService::nsDOMRequestService()
{
  /* member initializers and constructor code */
}

nsDOMRequestService::~nsDOMRequestService()
{
  /* destructor code */
}

/* nsIDOMDOMRequest createRequest (in nsIDOMWindow window); */
NS_IMETHODIMP nsDOMRequestService::CreateRequest(nsIDOMWindow *window, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireSuccess (in nsIDOMDOMRequest request, in jsval result); */
NS_IMETHODIMP nsDOMRequestService::FireSuccess(nsIDOMDOMRequest *request, const JS::Value & result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireError (in nsIDOMDOMRequest request, in DOMString error); */
NS_IMETHODIMP nsDOMRequestService::FireError(nsIDOMDOMRequest *request, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireSuccessAsync (in nsIDOMDOMRequest request, in jsval result); */
NS_IMETHODIMP nsDOMRequestService::FireSuccessAsync(nsIDOMDOMRequest *request, const JS::Value & result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireErrorAsync (in nsIDOMDOMRequest request, in DOMString error); */
NS_IMETHODIMP nsDOMRequestService::FireErrorAsync(nsIDOMDOMRequest *request, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMRequest_h__ */
