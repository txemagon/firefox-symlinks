/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/netwerk/base/public/nsINetAddr.idl
 */

#ifndef __gen_nsINetAddr_h__
#define __gen_nsINetAddr_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINetAddr */
#define NS_INETADDR_IID_STR "c407ab6c-c3ca-4cb2-a99b-a7dfbb88af33"

#define NS_INETADDR_IID \
  {0xc407ab6c, 0xc3ca, 0x4cb2, \
    { 0xa9, 0x9b, 0xa7, 0xdf, 0xbb, 0x88, 0xaf, 0x33 }}

class NS_NO_VTABLE nsINetAddr : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETADDR_IID)

  /* readonly attribute unsigned short family; */
  NS_IMETHOD GetFamily(uint16_t *aFamily) = 0;

  /* readonly attribute AUTF8String address; */
  NS_IMETHOD GetAddress(nsACString & aAddress) = 0;

  /* readonly attribute unsigned short port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;

  /* readonly attribute unsigned long flow; */
  NS_IMETHOD GetFlow(uint32_t *aFlow) = 0;

  /* readonly attribute unsigned long scope; */
  NS_IMETHOD GetScope(uint32_t *aScope) = 0;

  enum {
    FAMILY_INET = 1U,
    FAMILY_INET6 = 2U,
    FAMILY_LOCAL = 3U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetAddr, NS_INETADDR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETADDR \
  NS_IMETHOD GetFamily(uint16_t *aFamily); \
  NS_IMETHOD GetAddress(nsACString & aAddress); \
  NS_IMETHOD GetPort(uint16_t *aPort); \
  NS_IMETHOD GetFlow(uint32_t *aFlow); \
  NS_IMETHOD GetScope(uint32_t *aScope); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETADDR(_to) \
  NS_IMETHOD GetFamily(uint16_t *aFamily) { return _to GetFamily(aFamily); } \
  NS_IMETHOD GetAddress(nsACString & aAddress) { return _to GetAddress(aAddress); } \
  NS_IMETHOD GetPort(uint16_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetFlow(uint32_t *aFlow) { return _to GetFlow(aFlow); } \
  NS_IMETHOD GetScope(uint32_t *aScope) { return _to GetScope(aScope); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETADDR(_to) \
  NS_IMETHOD GetFamily(uint16_t *aFamily) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFamily(aFamily); } \
  NS_IMETHOD GetAddress(nsACString & aAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(aAddress); } \
  NS_IMETHOD GetPort(uint16_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetFlow(uint32_t *aFlow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlow(aFlow); } \
  NS_IMETHOD GetScope(uint32_t *aScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScope(aScope); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetAddr : public nsINetAddr
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETADDR

  nsNetAddr();

private:
  ~nsNetAddr();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNetAddr, nsINetAddr)

nsNetAddr::nsNetAddr()
{
  /* member initializers and constructor code */
}

nsNetAddr::~nsNetAddr()
{
  /* destructor code */
}

/* readonly attribute unsigned short family; */
NS_IMETHODIMP nsNetAddr::GetFamily(uint16_t *aFamily)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String address; */
NS_IMETHODIMP nsNetAddr::GetAddress(nsACString & aAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short port; */
NS_IMETHODIMP nsNetAddr::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long flow; */
NS_IMETHODIMP nsNetAddr::GetFlow(uint32_t *aFlow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long scope; */
NS_IMETHODIMP nsNetAddr::GetScope(uint32_t *aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetAddr_h__ */
