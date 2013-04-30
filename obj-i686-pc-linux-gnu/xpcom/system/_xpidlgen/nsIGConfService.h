/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/system/nsIGConfService.idl
 */

#ifndef __gen_nsIGConfService_h__
#define __gen_nsIGConfService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIGConfService */
#define NS_IGCONFSERVICE_IID_STR "5009acae-6973-48c3-b6d6-52c692cc5d9d"

#define NS_IGCONFSERVICE_IID \
  {0x5009acae, 0x6973, 0x48c3, \
    { 0xb6, 0xd6, 0x52, 0xc6, 0x92, 0xcc, 0x5d, 0x9d }}

class NS_NO_VTABLE nsIGConfService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGCONFSERVICE_IID)

  /* boolean getBool (in AUTF8String key); */
  NS_IMETHOD GetBool(const nsACString & key, bool *_retval) = 0;

  /* AUTF8String getString (in AUTF8String key); */
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval) = 0;

  /* long getInt (in AUTF8String key); */
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval) = 0;

  /* float getFloat (in AUTF8String key); */
  NS_IMETHOD GetFloat(const nsACString & key, float *_retval) = 0;

  /* nsIArray getStringList (in AUTF8String key); */
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval) = 0;

  /* void setBool (in AUTF8String key, in boolean value); */
  NS_IMETHOD SetBool(const nsACString & key, bool value) = 0;

  /* void setString (in AUTF8String key, in AUTF8String value); */
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value) = 0;

  /* void setInt (in AUTF8String key, in long value); */
  NS_IMETHOD SetInt(const nsACString & key, int32_t value) = 0;

  /* void setFloat (in AUTF8String key, in float value); */
  NS_IMETHOD SetFloat(const nsACString & key, float value) = 0;

  /* AUTF8String getAppForProtocol (in AUTF8String scheme, out boolean enabled); */
  NS_IMETHOD GetAppForProtocol(const nsACString & scheme, bool *enabled, nsACString & _retval) = 0;

  /* boolean handlerRequiresTerminal (in AUTF8String scheme); */
  NS_IMETHOD HandlerRequiresTerminal(const nsACString & scheme, bool *_retval) = 0;

  /* void setAppForProtocol (in AUTF8String scheme, in AUTF8String command); */
  NS_IMETHOD SetAppForProtocol(const nsACString & scheme, const nsACString & command) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGConfService, NS_IGCONFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGCONFSERVICE \
  NS_IMETHOD GetBool(const nsACString & key, bool *_retval); \
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval); \
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval); \
  NS_IMETHOD GetFloat(const nsACString & key, float *_retval); \
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval); \
  NS_IMETHOD SetBool(const nsACString & key, bool value); \
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value); \
  NS_IMETHOD SetInt(const nsACString & key, int32_t value); \
  NS_IMETHOD SetFloat(const nsACString & key, float value); \
  NS_IMETHOD GetAppForProtocol(const nsACString & scheme, bool *enabled, nsACString & _retval); \
  NS_IMETHOD HandlerRequiresTerminal(const nsACString & scheme, bool *_retval); \
  NS_IMETHOD SetAppForProtocol(const nsACString & scheme, const nsACString & command); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGCONFSERVICE(_to) \
  NS_IMETHOD GetBool(const nsACString & key, bool *_retval) { return _to GetBool(key, _retval); } \
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval) { return _to GetString(key, _retval); } \
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval) { return _to GetInt(key, _retval); } \
  NS_IMETHOD GetFloat(const nsACString & key, float *_retval) { return _to GetFloat(key, _retval); } \
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval) { return _to GetStringList(key, _retval); } \
  NS_IMETHOD SetBool(const nsACString & key, bool value) { return _to SetBool(key, value); } \
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value) { return _to SetString(key, value); } \
  NS_IMETHOD SetInt(const nsACString & key, int32_t value) { return _to SetInt(key, value); } \
  NS_IMETHOD SetFloat(const nsACString & key, float value) { return _to SetFloat(key, value); } \
  NS_IMETHOD GetAppForProtocol(const nsACString & scheme, bool *enabled, nsACString & _retval) { return _to GetAppForProtocol(scheme, enabled, _retval); } \
  NS_IMETHOD HandlerRequiresTerminal(const nsACString & scheme, bool *_retval) { return _to HandlerRequiresTerminal(scheme, _retval); } \
  NS_IMETHOD SetAppForProtocol(const nsACString & scheme, const nsACString & command) { return _to SetAppForProtocol(scheme, command); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGCONFSERVICE(_to) \
  NS_IMETHOD GetBool(const nsACString & key, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBool(key, _retval); } \
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(key, _retval); } \
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt(key, _retval); } \
  NS_IMETHOD GetFloat(const nsACString & key, float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFloat(key, _retval); } \
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringList(key, _retval); } \
  NS_IMETHOD SetBool(const nsACString & key, bool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBool(key, value); } \
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetString(key, value); } \
  NS_IMETHOD SetInt(const nsACString & key, int32_t value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInt(key, value); } \
  NS_IMETHOD SetFloat(const nsACString & key, float value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFloat(key, value); } \
  NS_IMETHOD GetAppForProtocol(const nsACString & scheme, bool *enabled, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppForProtocol(scheme, enabled, _retval); } \
  NS_IMETHOD HandlerRequiresTerminal(const nsACString & scheme, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandlerRequiresTerminal(scheme, _retval); } \
  NS_IMETHOD SetAppForProtocol(const nsACString & scheme, const nsACString & command) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppForProtocol(scheme, command); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGConfService : public nsIGConfService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGCONFSERVICE

  nsGConfService();

private:
  ~nsGConfService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGConfService, nsIGConfService)

nsGConfService::nsGConfService()
{
  /* member initializers and constructor code */
}

nsGConfService::~nsGConfService()
{
  /* destructor code */
}

/* boolean getBool (in AUTF8String key); */
NS_IMETHODIMP nsGConfService::GetBool(const nsACString & key, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getString (in AUTF8String key); */
NS_IMETHODIMP nsGConfService::GetString(const nsACString & key, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getInt (in AUTF8String key); */
NS_IMETHODIMP nsGConfService::GetInt(const nsACString & key, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getFloat (in AUTF8String key); */
NS_IMETHODIMP nsGConfService::GetFloat(const nsACString & key, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getStringList (in AUTF8String key); */
NS_IMETHODIMP nsGConfService::GetStringList(const nsACString & key, nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBool (in AUTF8String key, in boolean value); */
NS_IMETHODIMP nsGConfService::SetBool(const nsACString & key, bool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setString (in AUTF8String key, in AUTF8String value); */
NS_IMETHODIMP nsGConfService::SetString(const nsACString & key, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setInt (in AUTF8String key, in long value); */
NS_IMETHODIMP nsGConfService::SetInt(const nsACString & key, int32_t value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFloat (in AUTF8String key, in float value); */
NS_IMETHODIMP nsGConfService::SetFloat(const nsACString & key, float value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getAppForProtocol (in AUTF8String scheme, out boolean enabled); */
NS_IMETHODIMP nsGConfService::GetAppForProtocol(const nsACString & scheme, bool *enabled, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handlerRequiresTerminal (in AUTF8String scheme); */
NS_IMETHODIMP nsGConfService::HandlerRequiresTerminal(const nsACString & scheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAppForProtocol (in AUTF8String scheme, in AUTF8String command); */
NS_IMETHODIMP nsGConfService::SetAppForProtocol(const nsACString & scheme, const nsACString & command)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_GCONFSERVICE_CONTRACTID "@mozilla.org/gnome-gconf-service;1"

#endif /* __gen_nsIGConfService_h__ */
