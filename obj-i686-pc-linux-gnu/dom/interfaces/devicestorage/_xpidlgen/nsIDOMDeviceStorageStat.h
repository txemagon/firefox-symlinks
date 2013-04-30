/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/devicestorage/nsIDOMDeviceStorageStat.idl
 */

#ifndef __gen_nsIDOMDeviceStorageStat_h__
#define __gen_nsIDOMDeviceStorageStat_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDeviceStorageStat */
#define NS_IDOMDEVICESTORAGESTAT_IID_STR "0e22289a-469d-42c0-98dd-ae9831bd6a6d"

#define NS_IDOMDEVICESTORAGESTAT_IID \
  {0x0e22289a, 0x469d, 0x42c0, \
    { 0x98, 0xdd, 0xae, 0x98, 0x31, 0xbd, 0x6a, 0x6d }}

class NS_NO_VTABLE nsIDOMDeviceStorageStat : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICESTORAGESTAT_IID)

  /* readonly attribute uint64_t totalBytes; */
  NS_IMETHOD GetTotalBytes(uint64_t *aTotalBytes) = 0;

  /* readonly attribute uint64_t freeBytes; */
  NS_IMETHOD GetFreeBytes(uint64_t *aFreeBytes) = 0;

  /* readonly attribute DOMString state; */
  NS_IMETHOD GetState(nsAString & aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceStorageStat, NS_IDOMDEVICESTORAGESTAT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICESTORAGESTAT \
  NS_IMETHOD GetTotalBytes(uint64_t *aTotalBytes); \
  NS_IMETHOD GetFreeBytes(uint64_t *aFreeBytes); \
  NS_IMETHOD GetState(nsAString & aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICESTORAGESTAT(_to) \
  NS_IMETHOD GetTotalBytes(uint64_t *aTotalBytes) { return _to GetTotalBytes(aTotalBytes); } \
  NS_IMETHOD GetFreeBytes(uint64_t *aFreeBytes) { return _to GetFreeBytes(aFreeBytes); } \
  NS_IMETHOD GetState(nsAString & aState) { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICESTORAGESTAT(_to) \
  NS_IMETHOD GetTotalBytes(uint64_t *aTotalBytes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalBytes(aTotalBytes); } \
  NS_IMETHOD GetFreeBytes(uint64_t *aFreeBytes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFreeBytes(aFreeBytes); } \
  NS_IMETHOD GetState(nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceStorageStat : public nsIDOMDeviceStorageStat
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICESTORAGESTAT

  nsDOMDeviceStorageStat();

private:
  ~nsDOMDeviceStorageStat();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceStorageStat, nsIDOMDeviceStorageStat)

nsDOMDeviceStorageStat::nsDOMDeviceStorageStat()
{
  /* member initializers and constructor code */
}

nsDOMDeviceStorageStat::~nsDOMDeviceStorageStat()
{
  /* destructor code */
}

/* readonly attribute uint64_t totalBytes; */
NS_IMETHODIMP nsDOMDeviceStorageStat::GetTotalBytes(uint64_t *aTotalBytes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint64_t freeBytes; */
NS_IMETHODIMP nsDOMDeviceStorageStat::GetFreeBytes(uint64_t *aFreeBytes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString state; */
NS_IMETHODIMP nsDOMDeviceStorageStat::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceStorageStat_h__ */
