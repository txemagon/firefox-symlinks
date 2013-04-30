/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/network/interfaces/nsIDOMUSSDReceivedEvent.idl
 */

#ifndef __gen_nsIDOMUSSDReceivedEvent_h__
#define __gen_nsIDOMUSSDReceivedEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMUSSDReceivedEvent */
#define NS_IDOMUSSDRECEIVEDEVENT_IID_STR "56e18850-96f1-4898-a0de-47e0c994c4ab"

#define NS_IDOMUSSDRECEIVEDEVENT_IID \
  {0x56e18850, 0x96f1, 0x4898, \
    { 0xa0, 0xde, 0x47, 0xe0, 0xc9, 0x94, 0xc4, 0xab }}

class NS_NO_VTABLE nsIDOMUSSDReceivedEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMUSSDRECEIVEDEVENT_IID)

  /* readonly attribute DOMString message; */
  NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

  /* [infallible] readonly attribute boolean sessionEnded; */
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded) = 0;
  inline bool GetSessionEnded()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetSessionEnded(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMUSSDReceivedEvent, NS_IDOMUSSDRECEIVEDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMUSSDRECEIVEDEVENT \
  NS_IMETHOD GetMessage(nsAString & aMessage); \
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMUSSDRECEIVEDEVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } \
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded) { return _to GetSessionEnded(aSessionEnded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMUSSDRECEIVEDEVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_IMETHOD GetSessionEnded(bool *aSessionEnded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionEnded(aSessionEnded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMUSSDReceivedEvent : public nsIDOMUSSDReceivedEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMUSSDRECEIVEDEVENT

  nsDOMUSSDReceivedEvent();

private:
  ~nsDOMUSSDReceivedEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMUSSDReceivedEvent, nsIDOMUSSDReceivedEvent)

nsDOMUSSDReceivedEvent::nsDOMUSSDReceivedEvent()
{
  /* member initializers and constructor code */
}

nsDOMUSSDReceivedEvent::~nsDOMUSSDReceivedEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsDOMUSSDReceivedEvent::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean sessionEnded; */
NS_IMETHODIMP nsDOMUSSDReceivedEvent::GetSessionEnded(bool *aSessionEnded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMUSSDReceivedEvent_h__ */
