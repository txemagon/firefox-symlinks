/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/threads/nsIEnvironment.idl
 */

#ifndef __gen_nsIEnvironment_h__
#define __gen_nsIEnvironment_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEnvironment */
#define NS_IENVIRONMENT_IID_STR "101d5941-d820-4e85-a266-9a3469940807"

#define NS_IENVIRONMENT_IID \
  {0x101d5941, 0xd820, 0x4e85, \
    { 0xa2, 0x66, 0x9a, 0x34, 0x69, 0x94, 0x08, 0x07 }}

class NS_NO_VTABLE nsIEnvironment : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IENVIRONMENT_IID)

  /* void set (in AString aName, in AString aValue); */
  NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue) = 0;

  /* AString get (in AString aName); */
  NS_IMETHOD Get(const nsAString & aName, nsAString & _retval) = 0;

  /* boolean exists (in AString aName); */
  NS_IMETHOD Exists(const nsAString & aName, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEnvironment, NS_IENVIRONMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIENVIRONMENT \
  NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue); \
  NS_IMETHOD Get(const nsAString & aName, nsAString & _retval); \
  NS_IMETHOD Exists(const nsAString & aName, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIENVIRONMENT(_to) \
  NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue) { return _to Set(aName, aValue); } \
  NS_IMETHOD Get(const nsAString & aName, nsAString & _retval) { return _to Get(aName, _retval); } \
  NS_IMETHOD Exists(const nsAString & aName, bool *_retval) { return _to Exists(aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIENVIRONMENT(_to) \
  NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue); } \
  NS_IMETHOD Get(const nsAString & aName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, _retval); } \
  NS_IMETHOD Exists(const nsAString & aName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exists(aName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEnvironment : public nsIEnvironment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIENVIRONMENT

  nsEnvironment();

private:
  ~nsEnvironment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEnvironment, nsIEnvironment)

nsEnvironment::nsEnvironment()
{
  /* member initializers and constructor code */
}

nsEnvironment::~nsEnvironment()
{
  /* destructor code */
}

/* void set (in AString aName, in AString aValue); */
NS_IMETHODIMP nsEnvironment::Set(const nsAString & aName, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString get (in AString aName); */
NS_IMETHODIMP nsEnvironment::Get(const nsAString & aName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean exists (in AString aName); */
NS_IMETHODIMP nsEnvironment::Exists(const nsAString & aName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEnvironment_h__ */
