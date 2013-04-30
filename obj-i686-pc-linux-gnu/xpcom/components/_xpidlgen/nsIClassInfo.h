/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/components/nsIClassInfo.idl
 */

#ifndef __gen_nsIClassInfo_h__
#define __gen_nsIClassInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
/**
 * Calling QueryInterface with this special IID will return a null-terminated
 * table of QITableEntry's. Not all objects support this.
 * Note that this breaks XPCOM rules a bit (the table doesn't derive from
 * nsISupports).
 */
#define NS_THISPTROFFSETS_SID \
    { 0x23e017cc, 0x5d6f, 0x430c, \
      { 0xb3, 0xe6, 0x9d, 0x32, 0x65, 0x70, 0xd6, 0xb8 } }

/* starting interface:    nsIClassInfo */
#define NS_ICLASSINFO_IID_STR "986c11d0-f340-11d4-9075-0010a4e73d9a"

#define NS_ICLASSINFO_IID \
  {0x986c11d0, 0xf340, 0x11d4, \
    { 0x90, 0x75, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIClassInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLASSINFO_IID)

  /* void getInterfaces (out uint32_t count, [array, size_is (count), retval] out nsIIDPtr array); */
  NS_IMETHOD GetInterfaces(uint32_t *count, nsIID ***array) = 0;

  /* nsISupports getHelperForLanguage (in uint32_t language); */
  NS_IMETHOD GetHelperForLanguage(uint32_t language, nsISupports * *_retval) = 0;

  /* readonly attribute string contractID; */
  NS_IMETHOD GetContractID(char * *aContractID) = 0;

  /* readonly attribute string classDescription; */
  NS_IMETHOD GetClassDescription(char * *aClassDescription) = 0;

  /* readonly attribute nsCIDPtr classID; */
  NS_IMETHOD GetClassID(nsCID **aClassID) = 0;

  /* readonly attribute uint32_t implementationLanguage; */
  NS_IMETHOD GetImplementationLanguage(uint32_t *aImplementationLanguage) = 0;

  enum {
    SINGLETON = 1U,
    THREADSAFE = 2U,
    MAIN_THREAD_ONLY = 4U,
    DOM_OBJECT = 8U,
    PLUGIN_OBJECT = 16U,
    SINGLETON_CLASSINFO = 32U,
    CONTENT_NODE = 64U,
    RESERVED = 2147483648U
  };

  /* readonly attribute uint32_t flags; */
  NS_IMETHOD GetFlags(uint32_t *aFlags) = 0;

  /* [noscript] readonly attribute nsCID classIDNoAlloc; */
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClassInfo, NS_ICLASSINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLASSINFO \
  NS_IMETHOD GetInterfaces(uint32_t *count, nsIID ***array); \
  NS_IMETHOD GetHelperForLanguage(uint32_t language, nsISupports * *_retval); \
  NS_IMETHOD GetContractID(char * *aContractID); \
  NS_IMETHOD GetClassDescription(char * *aClassDescription); \
  NS_IMETHOD GetClassID(nsCID **aClassID); \
  NS_IMETHOD GetImplementationLanguage(uint32_t *aImplementationLanguage); \
  NS_IMETHOD GetFlags(uint32_t *aFlags); \
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLASSINFO(_to) \
  NS_IMETHOD GetInterfaces(uint32_t *count, nsIID ***array) { return _to GetInterfaces(count, array); } \
  NS_IMETHOD GetHelperForLanguage(uint32_t language, nsISupports * *_retval) { return _to GetHelperForLanguage(language, _retval); } \
  NS_IMETHOD GetContractID(char * *aContractID) { return _to GetContractID(aContractID); } \
  NS_IMETHOD GetClassDescription(char * *aClassDescription) { return _to GetClassDescription(aClassDescription); } \
  NS_IMETHOD GetClassID(nsCID **aClassID) { return _to GetClassID(aClassID); } \
  NS_IMETHOD GetImplementationLanguage(uint32_t *aImplementationLanguage) { return _to GetImplementationLanguage(aImplementationLanguage); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return _to GetFlags(aFlags); } \
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc) { return _to GetClassIDNoAlloc(aClassIDNoAlloc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLASSINFO(_to) \
  NS_IMETHOD GetInterfaces(uint32_t *count, nsIID ***array) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaces(count, array); } \
  NS_IMETHOD GetHelperForLanguage(uint32_t language, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelperForLanguage(language, _retval); } \
  NS_IMETHOD GetContractID(char * *aContractID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContractID(aContractID); } \
  NS_IMETHOD GetClassDescription(char * *aClassDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassDescription(aClassDescription); } \
  NS_IMETHOD GetClassID(nsCID **aClassID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassID(aClassID); } \
  NS_IMETHOD GetImplementationLanguage(uint32_t *aImplementationLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImplementationLanguage(aImplementationLanguage); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD GetClassIDNoAlloc(nsCID *aClassIDNoAlloc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassIDNoAlloc(aClassIDNoAlloc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClassInfo : public nsIClassInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLASSINFO

  nsClassInfo();

private:
  ~nsClassInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClassInfo, nsIClassInfo)

nsClassInfo::nsClassInfo()
{
  /* member initializers and constructor code */
}

nsClassInfo::~nsClassInfo()
{
  /* destructor code */
}

/* void getInterfaces (out uint32_t count, [array, size_is (count), retval] out nsIIDPtr array); */
NS_IMETHODIMP nsClassInfo::GetInterfaces(uint32_t *count, nsIID ***array)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getHelperForLanguage (in uint32_t language); */
NS_IMETHODIMP nsClassInfo::GetHelperForLanguage(uint32_t language, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string contractID; */
NS_IMETHODIMP nsClassInfo::GetContractID(char * *aContractID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string classDescription; */
NS_IMETHODIMP nsClassInfo::GetClassDescription(char * *aClassDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsCIDPtr classID; */
NS_IMETHODIMP nsClassInfo::GetClassID(nsCID **aClassID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t implementationLanguage; */
NS_IMETHODIMP nsClassInfo::GetImplementationLanguage(uint32_t *aImplementationLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t flags; */
NS_IMETHODIMP nsClassInfo::GetFlags(uint32_t *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsCID classIDNoAlloc; */
NS_IMETHODIMP nsClassInfo::GetClassIDNoAlloc(nsCID *aClassIDNoAlloc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClassInfo_h__ */
