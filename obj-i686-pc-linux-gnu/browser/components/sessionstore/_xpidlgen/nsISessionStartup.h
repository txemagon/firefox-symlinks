/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/browser/components/sessionstore/nsISessionStartup.idl
 */

#ifndef __gen_nsISessionStartup_h__
#define __gen_nsISessionStartup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISessionStartup */
#define NS_ISESSIONSTARTUP_IID_STR "35235b39-7098-4b3b-8e28-cd004a88b06f"

#define NS_ISESSIONSTARTUP_IID \
  {0x35235b39, 0x7098, 0x4b3b, \
    { 0x8e, 0x28, 0xcd, 0x00, 0x4a, 0x88, 0xb0, 0x6f }}

class NS_NO_VTABLE nsISessionStartup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISESSIONSTARTUP_IID)

  /* readonly attribute jsval onceInitialized; */
  NS_IMETHOD GetOnceInitialized(JS::Value *aOnceInitialized) = 0;

  /* readonly attribute jsval state; */
  NS_IMETHOD GetState(JS::Value *aState) = 0;

  /* boolean doRestore (); */
  NS_IMETHOD DoRestore(bool *_retval) = 0;

  enum {
    NO_SESSION = 0U,
    RECOVER_SESSION = 1U,
    RESUME_SESSION = 2U,
    DEFER_SESSION = 3U
  };

  /* readonly attribute unsigned long sessionType; */
  NS_IMETHOD GetSessionType(uint32_t *aSessionType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISessionStartup, NS_ISESSIONSTARTUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISESSIONSTARTUP \
  NS_IMETHOD GetOnceInitialized(JS::Value *aOnceInitialized); \
  NS_IMETHOD GetState(JS::Value *aState); \
  NS_IMETHOD DoRestore(bool *_retval); \
  NS_IMETHOD GetSessionType(uint32_t *aSessionType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISESSIONSTARTUP(_to) \
  NS_IMETHOD GetOnceInitialized(JS::Value *aOnceInitialized) { return _to GetOnceInitialized(aOnceInitialized); } \
  NS_IMETHOD GetState(JS::Value *aState) { return _to GetState(aState); } \
  NS_IMETHOD DoRestore(bool *_retval) { return _to DoRestore(_retval); } \
  NS_IMETHOD GetSessionType(uint32_t *aSessionType) { return _to GetSessionType(aSessionType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISESSIONSTARTUP(_to) \
  NS_IMETHOD GetOnceInitialized(JS::Value *aOnceInitialized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnceInitialized(aOnceInitialized); } \
  NS_IMETHOD GetState(JS::Value *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD DoRestore(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoRestore(_retval); } \
  NS_IMETHOD GetSessionType(uint32_t *aSessionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionType(aSessionType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSessionStartup : public nsISessionStartup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISESSIONSTARTUP

  nsSessionStartup();

private:
  ~nsSessionStartup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSessionStartup, nsISessionStartup)

nsSessionStartup::nsSessionStartup()
{
  /* member initializers and constructor code */
}

nsSessionStartup::~nsSessionStartup()
{
  /* destructor code */
}

/* readonly attribute jsval onceInitialized; */
NS_IMETHODIMP nsSessionStartup::GetOnceInitialized(JS::Value *aOnceInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval state; */
NS_IMETHODIMP nsSessionStartup::GetState(JS::Value *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean doRestore (); */
NS_IMETHODIMP nsSessionStartup::DoRestore(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long sessionType; */
NS_IMETHODIMP nsSessionStartup::GetSessionType(uint32_t *aSessionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISessionStartup_h__ */
