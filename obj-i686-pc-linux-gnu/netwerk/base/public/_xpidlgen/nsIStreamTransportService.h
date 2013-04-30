/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/netwerk/base/public/nsIStreamTransportService.idl
 */

#ifndef __gen_nsIStreamTransportService_h__
#define __gen_nsIStreamTransportService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransport; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIStreamTransportService */
#define NS_ISTREAMTRANSPORTSERVICE_IID_STR "51cac889-abc6-4948-97a3-4f135a6e7630"

#define NS_ISTREAMTRANSPORTSERVICE_IID \
  {0x51cac889, 0xabc6, 0x4948, \
    { 0x97, 0xa3, 0x4f, 0x13, 0x5a, 0x6e, 0x76, 0x30 }}

class NS_NO_VTABLE nsIStreamTransportService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMTRANSPORTSERVICE_IID)

  /* nsITransport createInputTransport (in nsIInputStream aStream, in long long aStartOffset, in long long aReadLimit, in boolean aCloseWhenDone); */
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval) = 0;

  /* nsITransport createOutputTransport (in nsIOutputStream aStream, in long long aStartOffset, in long long aWriteLimit, in boolean aCloseWhenDone); */
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval) = 0;

  /* void raiseThreadLimit (); */
  NS_IMETHOD RaiseThreadLimit(void) = 0;

  /* void lowerThreadLimit (); */
  NS_IMETHOD LowerThreadLimit(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamTransportService, NS_ISTREAMTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMTRANSPORTSERVICE \
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval); \
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval); \
  NS_IMETHOD RaiseThreadLimit(void); \
  NS_IMETHOD LowerThreadLimit(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMTRANSPORTSERVICE(_to) \
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval) { return _to CreateInputTransport(aStream, aStartOffset, aReadLimit, aCloseWhenDone, _retval); } \
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval) { return _to CreateOutputTransport(aStream, aStartOffset, aWriteLimit, aCloseWhenDone, _retval); } \
  NS_IMETHOD RaiseThreadLimit(void) { return _to RaiseThreadLimit(); } \
  NS_IMETHOD LowerThreadLimit(void) { return _to LowerThreadLimit(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMTRANSPORTSERVICE(_to) \
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInputTransport(aStream, aStartOffset, aReadLimit, aCloseWhenDone, _retval); } \
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateOutputTransport(aStream, aStartOffset, aWriteLimit, aCloseWhenDone, _retval); } \
  NS_IMETHOD RaiseThreadLimit(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RaiseThreadLimit(); } \
  NS_IMETHOD LowerThreadLimit(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LowerThreadLimit(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamTransportService : public nsIStreamTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMTRANSPORTSERVICE

  nsStreamTransportService();

private:
  ~nsStreamTransportService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamTransportService, nsIStreamTransportService)

nsStreamTransportService::nsStreamTransportService()
{
  /* member initializers and constructor code */
}

nsStreamTransportService::~nsStreamTransportService()
{
  /* destructor code */
}

/* nsITransport createInputTransport (in nsIInputStream aStream, in long long aStartOffset, in long long aReadLimit, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsStreamTransportService::CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransport createOutputTransport (in nsIOutputStream aStream, in long long aStartOffset, in long long aWriteLimit, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsStreamTransportService::CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void raiseThreadLimit (); */
NS_IMETHODIMP nsStreamTransportService::RaiseThreadLimit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lowerThreadLimit (); */
NS_IMETHODIMP nsStreamTransportService::LowerThreadLimit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamTransportService_h__ */
