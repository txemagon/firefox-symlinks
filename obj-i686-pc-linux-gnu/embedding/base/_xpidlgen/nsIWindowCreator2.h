/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/embedding/base/nsIWindowCreator2.idl
 */

#ifndef __gen_nsIWindowCreator2_h__
#define __gen_nsIWindowCreator2_h__


#ifndef __gen_nsIWindowCreator_h__
#include "nsIWindowCreator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIWebBrowserChrome; /* forward declaration */


/* starting interface:    nsIWindowCreator2 */
#define NS_IWINDOWCREATOR2_IID_STR "f673ec81-a4b0-11d6-964b-eb5a2bf216fc"

#define NS_IWINDOWCREATOR2_IID \
  {0xf673ec81, 0xa4b0, 0x11d6, \
    { 0x96, 0x4b, 0xeb, 0x5a, 0x2b, 0xf2, 0x16, 0xfc }}

class NS_NO_VTABLE nsIWindowCreator2 : public nsIWindowCreator {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWCREATOR2_IID)

  enum {
    PARENT_IS_LOADING_OR_RUNNING_TIMEOUT = 1U
  };

  /* nsIWebBrowserChrome createChromeWindow2 (in nsIWebBrowserChrome parent, in uint32_t chromeFlags, in uint32_t contextFlags, in nsIURI uri, out boolean cancel); */
  NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, uint32_t chromeFlags, uint32_t contextFlags, nsIURI *uri, bool *cancel, nsIWebBrowserChrome * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowCreator2, NS_IWINDOWCREATOR2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWCREATOR2 \
  NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, uint32_t chromeFlags, uint32_t contextFlags, nsIURI *uri, bool *cancel, nsIWebBrowserChrome * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWCREATOR2(_to) \
  NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, uint32_t chromeFlags, uint32_t contextFlags, nsIURI *uri, bool *cancel, nsIWebBrowserChrome * *_retval) { return _to CreateChromeWindow2(parent, chromeFlags, contextFlags, uri, cancel, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWCREATOR2(_to) \
  NS_IMETHOD CreateChromeWindow2(nsIWebBrowserChrome *parent, uint32_t chromeFlags, uint32_t contextFlags, nsIURI *uri, bool *cancel, nsIWebBrowserChrome * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateChromeWindow2(parent, chromeFlags, contextFlags, uri, cancel, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowCreator2 : public nsIWindowCreator2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWCREATOR2

  nsWindowCreator2();

private:
  ~nsWindowCreator2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowCreator2, nsIWindowCreator2)

nsWindowCreator2::nsWindowCreator2()
{
  /* member initializers and constructor code */
}

nsWindowCreator2::~nsWindowCreator2()
{
  /* destructor code */
}

/* nsIWebBrowserChrome createChromeWindow2 (in nsIWebBrowserChrome parent, in uint32_t chromeFlags, in uint32_t contextFlags, in nsIURI uri, out boolean cancel); */
NS_IMETHODIMP nsWindowCreator2::CreateChromeWindow2(nsIWebBrowserChrome *parent, uint32_t chromeFlags, uint32_t contextFlags, nsIURI *uri, bool *cancel, nsIWebBrowserChrome * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowCreator2_h__ */
