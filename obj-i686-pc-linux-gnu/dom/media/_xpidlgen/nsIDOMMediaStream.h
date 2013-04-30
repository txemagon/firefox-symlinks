/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/media/nsIDOMMediaStream.idl
 */

#ifndef __gen_nsIDOMMediaStream_h__
#define __gen_nsIDOMMediaStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMediaStream */
#define NS_IDOMMEDIASTREAM_IID_STR "f37c2871-4cb7-4672-bb28-c2d601f7cc9e"

#define NS_IDOMMEDIASTREAM_IID \
  {0xf37c2871, 0x4cb7, 0x4672, \
    { 0xbb, 0x28, 0xc2, 0xd6, 0x01, 0xf7, 0xcc, 0x9e }}

class NS_NO_VTABLE nsIDOMMediaStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMEDIASTREAM_IID)

  /* readonly attribute double currentTime; */
  NS_IMETHOD GetCurrentTime(double *aCurrentTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMediaStream, NS_IDOMMEDIASTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMEDIASTREAM \
  NS_IMETHOD GetCurrentTime(double *aCurrentTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMEDIASTREAM(_to) \
  NS_IMETHOD GetCurrentTime(double *aCurrentTime) { return _to GetCurrentTime(aCurrentTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMEDIASTREAM(_to) \
  NS_IMETHOD GetCurrentTime(double *aCurrentTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTime(aCurrentTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMediaStream : public nsIDOMMediaStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMEDIASTREAM

  nsDOMMediaStream();

private:
  ~nsDOMMediaStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMediaStream, nsIDOMMediaStream)

nsDOMMediaStream::nsDOMMediaStream()
{
  /* member initializers and constructor code */
}

nsDOMMediaStream::~nsDOMMediaStream()
{
  /* destructor code */
}

/* readonly attribute double currentTime; */
NS_IMETHODIMP nsDOMMediaStream::GetCurrentTime(double *aCurrentTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMLocalMediaStream */
#define NS_IDOMLOCALMEDIASTREAM_IID_STR "210a16e3-2a38-4ae9-b0f6-0fb5a8252814"

#define NS_IDOMLOCALMEDIASTREAM_IID \
  {0x210a16e3, 0x2a38, 0x4ae9, \
    { 0xb0, 0xf6, 0x0f, 0xb5, 0xa8, 0x25, 0x28, 0x14 }}

class NS_NO_VTABLE nsIDOMLocalMediaStream : public nsIDOMMediaStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLOCALMEDIASTREAM_IID)

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLocalMediaStream, NS_IDOMLOCALMEDIASTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLOCALMEDIASTREAM \
  NS_IMETHOD Stop(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLOCALMEDIASTREAM(_to) \
  NS_IMETHOD Stop(void) { return _to Stop(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLOCALMEDIASTREAM(_to) \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLocalMediaStream : public nsIDOMLocalMediaStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLOCALMEDIASTREAM

  nsDOMLocalMediaStream();

private:
  ~nsDOMLocalMediaStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLocalMediaStream, nsIDOMLocalMediaStream)

nsDOMLocalMediaStream::nsDOMLocalMediaStream()
{
  /* member initializers and constructor code */
}

nsDOMLocalMediaStream::~nsDOMLocalMediaStream()
{
  /* destructor code */
}

/* void stop (); */
NS_IMETHODIMP nsDOMLocalMediaStream::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMediaStream_h__ */
