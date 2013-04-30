/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/sms/interfaces/nsISmsDatabaseService.idl
 */

#ifndef __gen_nsISmsDatabaseService_h__
#define __gen_nsISmsDatabaseService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define SMS_DATABASE_SERVICE_CID \
{ 0x2454c2a1, 0xefdd, 0x4d96,    \
{ 0x83, 0xbd, 0x51, 0xa2, 0x9a, 0x21, 0xf5, 0xab } }
#define SMS_DATABASE_SERVICE_CONTRACTID "@mozilla.org/sms/smsdatabaseservice;1"
class nsIDOMMozSmsFilter; /* forward declaration */

class nsISmsRequest; /* forward declaration */


/* starting interface:    nsISmsDatabaseService */
#define NS_ISMSDATABASESERVICE_IID_STR "b1311c6d-d863-4da1-8755-2fd59eb0f386"

#define NS_ISMSDATABASESERVICE_IID \
  {0xb1311c6d, 0xd863, 0x4da1, \
    { 0x87, 0x55, 0x2f, 0xd5, 0x9e, 0xb0, 0xf3, 0x86 }}

class NS_NO_VTABLE nsISmsDatabaseService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMSDATABASESERVICE_IID)

  /* [binaryname(GetMessageMoz)] void getMessage (in long messageId, in nsISmsRequest request); */
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsISmsRequest *request) = 0;

  /* void deleteMessage (in long messageId, in nsISmsRequest request); */
  NS_IMETHOD DeleteMessage(int32_t messageId, nsISmsRequest *request) = 0;

  /* void createMessageList (in nsIDOMMozSmsFilter filter, in boolean reverse, in nsISmsRequest request); */
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsISmsRequest *request) = 0;

  /* void getNextMessageInList (in long listId, in nsISmsRequest request); */
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsISmsRequest *request) = 0;

  /* void clearMessageList (in long listId); */
  NS_IMETHOD ClearMessageList(int32_t listId) = 0;

  /* void markMessageRead (in long messageId, in boolean value, in nsISmsRequest request); */
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsISmsRequest *request) = 0;

  /* void getThreadList (in nsISmsRequest request); */
  NS_IMETHOD GetThreadList(nsISmsRequest *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISmsDatabaseService, NS_ISMSDATABASESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMSDATABASESERVICE \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsISmsRequest *request); \
  NS_IMETHOD DeleteMessage(int32_t messageId, nsISmsRequest *request); \
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsISmsRequest *request); \
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsISmsRequest *request); \
  NS_IMETHOD ClearMessageList(int32_t listId); \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsISmsRequest *request); \
  NS_IMETHOD GetThreadList(nsISmsRequest *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMSDATABASESERVICE(_to) \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsISmsRequest *request) { return _to GetMessageMoz(messageId, request); } \
  NS_IMETHOD DeleteMessage(int32_t messageId, nsISmsRequest *request) { return _to DeleteMessage(messageId, request); } \
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsISmsRequest *request) { return _to CreateMessageList(filter, reverse, request); } \
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsISmsRequest *request) { return _to GetNextMessageInList(listId, request); } \
  NS_IMETHOD ClearMessageList(int32_t listId) { return _to ClearMessageList(listId); } \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsISmsRequest *request) { return _to MarkMessageRead(messageId, value, request); } \
  NS_IMETHOD GetThreadList(nsISmsRequest *request) { return _to GetThreadList(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMSDATABASESERVICE(_to) \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsISmsRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(messageId, request); } \
  NS_IMETHOD DeleteMessage(int32_t messageId, nsISmsRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteMessage(messageId, request); } \
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsISmsRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateMessageList(filter, reverse, request); } \
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsISmsRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextMessageInList(listId, request); } \
  NS_IMETHOD ClearMessageList(int32_t listId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMessageList(listId); } \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsISmsRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkMessageRead(messageId, value, request); } \
  NS_IMETHOD GetThreadList(nsISmsRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadList(request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSmsDatabaseService : public nsISmsDatabaseService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISMSDATABASESERVICE

  nsSmsDatabaseService();

private:
  ~nsSmsDatabaseService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSmsDatabaseService, nsISmsDatabaseService)

nsSmsDatabaseService::nsSmsDatabaseService()
{
  /* member initializers and constructor code */
}

nsSmsDatabaseService::~nsSmsDatabaseService()
{
  /* destructor code */
}

/* [binaryname(GetMessageMoz)] void getMessage (in long messageId, in nsISmsRequest request); */
NS_IMETHODIMP nsSmsDatabaseService::GetMessageMoz(int32_t messageId, nsISmsRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteMessage (in long messageId, in nsISmsRequest request); */
NS_IMETHODIMP nsSmsDatabaseService::DeleteMessage(int32_t messageId, nsISmsRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createMessageList (in nsIDOMMozSmsFilter filter, in boolean reverse, in nsISmsRequest request); */
NS_IMETHODIMP nsSmsDatabaseService::CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsISmsRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNextMessageInList (in long listId, in nsISmsRequest request); */
NS_IMETHODIMP nsSmsDatabaseService::GetNextMessageInList(int32_t listId, nsISmsRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMessageList (in long listId); */
NS_IMETHODIMP nsSmsDatabaseService::ClearMessageList(int32_t listId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markMessageRead (in long messageId, in boolean value, in nsISmsRequest request); */
NS_IMETHODIMP nsSmsDatabaseService::MarkMessageRead(int32_t messageId, bool value, nsISmsRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getThreadList (in nsISmsRequest request); */
NS_IMETHODIMP nsSmsDatabaseService::GetThreadList(nsISmsRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISmsDatabaseService_h__ */
