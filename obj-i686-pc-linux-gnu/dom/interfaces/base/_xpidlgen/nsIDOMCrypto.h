/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/base/nsIDOMCrypto.idl
 */

#ifndef __gen_nsIDOMCrypto_h__
#define __gen_nsIDOMCrypto_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCrypto */
#define NS_IDOMCRYPTO_IID_STR "12b6d899-2aed-4ea9-8c02-2223ab7ab592"

#define NS_IDOMCRYPTO_IID \
  {0x12b6d899, 0x2aed, 0x4ea9, \
    { 0x8c, 0x02, 0x22, 0x23, 0xab, 0x7a, 0xb5, 0x92 }}

class NS_NO_VTABLE nsIDOMCrypto : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCRYPTO_IID)

  /* readonly attribute DOMString version; */
  NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /* attribute boolean enableSmartCardEvents; */
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents) = 0;
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents) = 0;

  /* nsIDOMCRMFObject generateCRMFRequest (); */
  NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject * *_retval) = 0;

  /* DOMString importUserCertificates (in DOMString nickname, in DOMString cmmfResponse, in boolean doForcedBackup); */
  NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, bool doForcedBackup, nsAString & _retval) = 0;

  /* DOMString popChallengeResponse (in DOMString challenge); */
  NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval) = 0;

  /* DOMString random (in long numBytes); */
  NS_IMETHOD Random(int32_t numBytes, nsAString & _retval) = 0;

  /* DOMString signText (in DOMString stringToSign, in DOMString caOption); */
  NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval) = 0;

  /* void logout (); */
  NS_IMETHOD Logout(void) = 0;

  /* void disableRightClick (); */
  NS_IMETHOD DisableRightClick(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCrypto, NS_IDOMCRYPTO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCRYPTO \
  NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents); \
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents); \
  NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject * *_retval); \
  NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, bool doForcedBackup, nsAString & _retval); \
  NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval); \
  NS_IMETHOD Random(int32_t numBytes, nsAString & _retval); \
  NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval); \
  NS_IMETHOD Logout(void); \
  NS_IMETHOD DisableRightClick(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCRYPTO(_to) \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents) { return _to GetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents) { return _to SetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject * *_retval) { return _to GenerateCRMFRequest(_retval); } \
  NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, bool doForcedBackup, nsAString & _retval) { return _to ImportUserCertificates(nickname, cmmfResponse, doForcedBackup, _retval); } \
  NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval) { return _to PopChallengeResponse(challenge, _retval); } \
  NS_IMETHOD Random(int32_t numBytes, nsAString & _retval) { return _to Random(numBytes, _retval); } \
  NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval) { return _to SignText(stringToSign, caOption, _retval); } \
  NS_IMETHOD Logout(void) { return _to Logout(); } \
  NS_IMETHOD DisableRightClick(void) { return _to DisableRightClick(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCRYPTO(_to) \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD GetEnableSmartCardEvents(bool *aEnableSmartCardEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_IMETHOD SetEnableSmartCardEvents(bool aEnableSmartCardEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnableSmartCardEvents(aEnableSmartCardEvents); } \
  NS_IMETHOD GenerateCRMFRequest(nsIDOMCRMFObject * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateCRMFRequest(_retval); } \
  NS_IMETHOD ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, bool doForcedBackup, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportUserCertificates(nickname, cmmfResponse, doForcedBackup, _retval); } \
  NS_IMETHOD PopChallengeResponse(const nsAString & challenge, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PopChallengeResponse(challenge, _retval); } \
  NS_IMETHOD Random(int32_t numBytes, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Random(numBytes, _retval); } \
  NS_IMETHOD SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SignText(stringToSign, caOption, _retval); } \
  NS_IMETHOD Logout(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Logout(); } \
  NS_IMETHOD DisableRightClick(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableRightClick(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCrypto : public nsIDOMCrypto
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRYPTO

  nsDOMCrypto();

private:
  ~nsDOMCrypto();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCrypto, nsIDOMCrypto)

nsDOMCrypto::nsDOMCrypto()
{
  /* member initializers and constructor code */
}

nsDOMCrypto::~nsDOMCrypto()
{
  /* destructor code */
}

/* readonly attribute DOMString version; */
NS_IMETHODIMP nsDOMCrypto::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enableSmartCardEvents; */
NS_IMETHODIMP nsDOMCrypto::GetEnableSmartCardEvents(bool *aEnableSmartCardEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCrypto::SetEnableSmartCardEvents(bool aEnableSmartCardEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCRMFObject generateCRMFRequest (); */
NS_IMETHODIMP nsDOMCrypto::GenerateCRMFRequest(nsIDOMCRMFObject * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString importUserCertificates (in DOMString nickname, in DOMString cmmfResponse, in boolean doForcedBackup); */
NS_IMETHODIMP nsDOMCrypto::ImportUserCertificates(const nsAString & nickname, const nsAString & cmmfResponse, bool doForcedBackup, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString popChallengeResponse (in DOMString challenge); */
NS_IMETHODIMP nsDOMCrypto::PopChallengeResponse(const nsAString & challenge, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString random (in long numBytes); */
NS_IMETHODIMP nsDOMCrypto::Random(int32_t numBytes, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString signText (in DOMString stringToSign, in DOMString caOption); */
NS_IMETHODIMP nsDOMCrypto::SignText(const nsAString & stringToSign, const nsAString & caOption, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logout (); */
NS_IMETHODIMP nsDOMCrypto::Logout()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableRightClick (); */
NS_IMETHODIMP nsDOMCrypto::DisableRightClick()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCrypto_h__ */
