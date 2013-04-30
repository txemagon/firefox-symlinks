/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/network/interfaces/nsIDOMDataErrorEvent.idl
 */

#ifndef __gen_nsIDOMDataErrorEvent_h__
#define __gen_nsIDOMDataErrorEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDataErrorEvent */
#define NS_IDOMDATAERROREVENT_IID_STR "494cf68f-0ca8-4cf9-924b-84cf379c9631"

#define NS_IDOMDATAERROREVENT_IID \
  {0x494cf68f, 0x0ca8, 0x4cf9, \
    { 0x92, 0x4b, 0x84, 0xcf, 0x37, 0x9c, 0x96, 0x31 }}

class NS_NO_VTABLE nsIDOMDataErrorEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATAERROREVENT_IID)

  /* readonly attribute DOMString message; */
  NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataErrorEvent, NS_IDOMDATAERROREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATAERROREVENT \
  NS_IMETHOD GetMessage(nsAString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATAERROREVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATAERROREVENT(_to) \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataErrorEvent : public nsIDOMDataErrorEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATAERROREVENT

  nsDOMDataErrorEvent();

private:
  ~nsDOMDataErrorEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataErrorEvent, nsIDOMDataErrorEvent)

nsDOMDataErrorEvent::nsDOMDataErrorEvent()
{
  /* member initializers and constructor code */
}

nsDOMDataErrorEvent::~nsDOMDataErrorEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsDOMDataErrorEvent::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataErrorEvent_h__ */
