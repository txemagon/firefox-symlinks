/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/content/base/public/nsIScriptLoaderObserver.idl
 */

#ifndef __gen_nsIScriptLoaderObserver_h__
#define __gen_nsIScriptLoaderObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIScriptElement; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIScriptLoaderObserver */
#define NS_ISCRIPTLOADEROBSERVER_IID_STR "7b787204-76fb-4764-96f1-fb7a666db4f4"

#define NS_ISCRIPTLOADEROBSERVER_IID \
  {0x7b787204, 0x76fb, 0x4764, \
    { 0x96, 0xf1, 0xfb, 0x7a, 0x66, 0x6d, 0xb4, 0xf4 }}

class NS_NO_VTABLE nsIScriptLoaderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTLOADEROBSERVER_IID)

  /* void scriptAvailable (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline, in nsIURI aURI, in int32_t aLineNo); */
  NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, bool aIsInline, nsIURI *aURI, int32_t aLineNo) = 0;

  /* void scriptEvaluated (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline); */
  NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, bool aIsInline) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptLoaderObserver, NS_ISCRIPTLOADEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTLOADEROBSERVER \
  NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, bool aIsInline, nsIURI *aURI, int32_t aLineNo); \
  NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, bool aIsInline); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTLOADEROBSERVER(_to) \
  NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, bool aIsInline, nsIURI *aURI, int32_t aLineNo) { return _to ScriptAvailable(aResult, aElement, aIsInline, aURI, aLineNo); } \
  NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, bool aIsInline) { return _to ScriptEvaluated(aResult, aElement, aIsInline); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTLOADEROBSERVER(_to) \
  NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, bool aIsInline, nsIURI *aURI, int32_t aLineNo) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptAvailable(aResult, aElement, aIsInline, aURI, aLineNo); } \
  NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, bool aIsInline) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptEvaluated(aResult, aElement, aIsInline); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptLoaderObserver : public nsIScriptLoaderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTLOADEROBSERVER

  nsScriptLoaderObserver();

private:
  ~nsScriptLoaderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptLoaderObserver, nsIScriptLoaderObserver)

nsScriptLoaderObserver::nsScriptLoaderObserver()
{
  /* member initializers and constructor code */
}

nsScriptLoaderObserver::~nsScriptLoaderObserver()
{
  /* destructor code */
}

/* void scriptAvailable (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline, in nsIURI aURI, in int32_t aLineNo); */
NS_IMETHODIMP nsScriptLoaderObserver::ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, bool aIsInline, nsIURI *aURI, int32_t aLineNo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scriptEvaluated (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline); */
NS_IMETHODIMP nsScriptLoaderObserver::ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, bool aIsInline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptLoaderObserver_h__ */
