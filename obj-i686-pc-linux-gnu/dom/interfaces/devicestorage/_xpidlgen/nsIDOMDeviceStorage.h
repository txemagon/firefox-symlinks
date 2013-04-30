/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/devicestorage/nsIDOMDeviceStorage.idl
 */

#ifndef __gen_nsIDOMDeviceStorage_h__
#define __gen_nsIDOMDeviceStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBlob; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMDeviceStorageCursor; /* forward declaration */

class nsIDOMDeviceStorageChangeEvent; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIDOMDeviceStorage */
#define NS_IDOMDEVICESTORAGE_IID_STR "7f69936f-2948-4733-ba41-c7e1d657a88b"

#define NS_IDOMDEVICESTORAGE_IID \
  {0x7f69936f, 0x2948, 0x4733, \
    { 0xba, 0x41, 0xc7, 0xe1, 0xd6, 0x57, 0xa8, 0x8b }}

class NS_NO_VTABLE nsIDOMDeviceStorage : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICESTORAGE_IID)

  /* [implicit_jscontext] attribute jsval onchange; */
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) = 0;
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) = 0;

  /* nsIDOMDOMRequest add (in nsIDOMBlob aBlob); */
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest addNamed (in nsIDOMBlob aBlob, in DOMString aName); */
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMDOMRequest get (in jsval aName); */
  NS_IMETHOD Get(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMDOMRequest getEditable (in jsval aName); */
  NS_IMETHOD GetEditable(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMDOMRequest delete (in jsval aName); */
  NS_IMETHOD Delete(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIDOMDeviceStorageCursor enumerate ([optional] in jsval aName, [optional] in jsval options); */
  NS_IMETHOD Enumerate(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIDOMDeviceStorageCursor enumerateEditable ([optional] in jsval aName, [optional] in jsval options); */
  NS_IMETHOD EnumerateEditable(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval) = 0;

  /* nsIDOMDOMRequest stat (); */
  NS_IMETHOD Stat(nsIDOMDOMRequest * *_retval) = 0;

  /* [noscript] readonly attribute nsIFile rootDirectory; */
  NS_IMETHOD GetRootDirectory(nsIFile * *aRootDirectory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceStorage, NS_IDOMDEVICESTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICESTORAGE \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange); \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange); \
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Get(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetEditable(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Delete(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Enumerate(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval); \
  NS_IMETHOD EnumerateEditable(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval); \
  NS_IMETHOD Stat(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetRootDirectory(nsIFile * *aRootDirectory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICESTORAGE(_to) \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) { return _to GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) { return _to SetOnchange(cx, aOnchange); } \
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval) { return _to Add(aBlob, _retval); } \
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval) { return _to AddNamed(aBlob, aName, _retval); } \
  NS_IMETHOD Get(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) { return _to Get(aName, cx, _retval); } \
  NS_IMETHOD GetEditable(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) { return _to GetEditable(aName, cx, _retval); } \
  NS_IMETHOD Delete(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) { return _to Delete(aName, cx, _retval); } \
  NS_IMETHOD Enumerate(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval) { return _to Enumerate(aName, options, cx, _argc, _retval); } \
  NS_IMETHOD EnumerateEditable(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval) { return _to EnumerateEditable(aName, options, cx, _argc, _retval); } \
  NS_IMETHOD Stat(nsIDOMDOMRequest * *_retval) { return _to Stat(_retval); } \
  NS_IMETHOD GetRootDirectory(nsIFile * *aRootDirectory) { return _to GetRootDirectory(aRootDirectory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICESTORAGE(_to) \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchange(cx, aOnchange); } \
  NS_IMETHOD Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(aBlob, _retval); } \
  NS_IMETHOD AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNamed(aBlob, aName, _retval); } \
  NS_IMETHOD Get(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, cx, _retval); } \
  NS_IMETHOD GetEditable(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aName, cx, _retval); } \
  NS_IMETHOD Delete(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(aName, cx, _retval); } \
  NS_IMETHOD Enumerate(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enumerate(aName, options, cx, _argc, _retval); } \
  NS_IMETHOD EnumerateEditable(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateEditable(aName, options, cx, _argc, _retval); } \
  NS_IMETHOD Stat(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stat(_retval); } \
  NS_IMETHOD GetRootDirectory(nsIFile * *aRootDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootDirectory(aRootDirectory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceStorage : public nsIDOMDeviceStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICESTORAGE

  nsDOMDeviceStorage();

private:
  ~nsDOMDeviceStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceStorage, nsIDOMDeviceStorage)

nsDOMDeviceStorage::nsDOMDeviceStorage()
{
  /* member initializers and constructor code */
}

nsDOMDeviceStorage::~nsDOMDeviceStorage()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval onchange; */
NS_IMETHODIMP nsDOMDeviceStorage::GetOnchange(JSContext* cx, JS::Value *aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDeviceStorage::SetOnchange(JSContext* cx, const JS::Value & aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest add (in nsIDOMBlob aBlob); */
NS_IMETHODIMP nsDOMDeviceStorage::Add(nsIDOMBlob *aBlob, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest addNamed (in nsIDOMBlob aBlob, in DOMString aName); */
NS_IMETHODIMP nsDOMDeviceStorage::AddNamed(nsIDOMBlob *aBlob, const nsAString & aName, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMDOMRequest get (in jsval aName); */
NS_IMETHODIMP nsDOMDeviceStorage::Get(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMDOMRequest getEditable (in jsval aName); */
NS_IMETHODIMP nsDOMDeviceStorage::GetEditable(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMDOMRequest delete (in jsval aName); */
NS_IMETHODIMP nsDOMDeviceStorage::Delete(const JS::Value & aName, JSContext* cx, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIDOMDeviceStorageCursor enumerate ([optional] in jsval aName, [optional] in jsval options); */
NS_IMETHODIMP nsDOMDeviceStorage::Enumerate(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIDOMDeviceStorageCursor enumerateEditable ([optional] in jsval aName, [optional] in jsval options); */
NS_IMETHODIMP nsDOMDeviceStorage::EnumerateEditable(const JS::Value & aName, const JS::Value & options, JSContext* cx, uint8_t _argc, nsIDOMDeviceStorageCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest stat (); */
NS_IMETHODIMP nsDOMDeviceStorage::Stat(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIFile rootDirectory; */
NS_IMETHODIMP nsDOMDeviceStorage::GetRootDirectory(nsIFile * *aRootDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceStorage_h__ */
