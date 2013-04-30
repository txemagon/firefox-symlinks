/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/uriloader/exthandler/nsIContentDispatchChooser.idl
 */

#ifndef __gen_nsIContentDispatchChooser_h__
#define __gen_nsIContentDispatchChooser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHandlerInfo; /* forward declaration */

class nsIHelperAppLauncher; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIContentDispatchChooser */
#define NS_ICONTENTDISPATCHCHOOSER_IID_STR "456ca3b2-02be-4f97-89a2-08c08d3ad88f"

#define NS_ICONTENTDISPATCHCHOOSER_IID \
  {0x456ca3b2, 0x02be, 0x4f97, \
    { 0x89, 0xa2, 0x08, 0xc0, 0x8d, 0x3a, 0xd8, 0x8f }}

class NS_NO_VTABLE nsIContentDispatchChooser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTDISPATCHCHOOSER_IID)

  enum {
    REASON_CANNOT_HANDLE = 0U
  };

  /* void ask (in nsIHandlerInfo aHandler, in nsIInterfaceRequestor aWindowContext, in nsIURI aURI, in unsigned long aReason); */
  NS_IMETHOD Ask(nsIHandlerInfo *aHandler, nsIInterfaceRequestor *aWindowContext, nsIURI *aURI, uint32_t aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentDispatchChooser, NS_ICONTENTDISPATCHCHOOSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTDISPATCHCHOOSER \
  NS_IMETHOD Ask(nsIHandlerInfo *aHandler, nsIInterfaceRequestor *aWindowContext, nsIURI *aURI, uint32_t aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTDISPATCHCHOOSER(_to) \
  NS_IMETHOD Ask(nsIHandlerInfo *aHandler, nsIInterfaceRequestor *aWindowContext, nsIURI *aURI, uint32_t aReason) { return _to Ask(aHandler, aWindowContext, aURI, aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTDISPATCHCHOOSER(_to) \
  NS_IMETHOD Ask(nsIHandlerInfo *aHandler, nsIInterfaceRequestor *aWindowContext, nsIURI *aURI, uint32_t aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Ask(aHandler, aWindowContext, aURI, aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentDispatchChooser : public nsIContentDispatchChooser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTDISPATCHCHOOSER

  nsContentDispatchChooser();

private:
  ~nsContentDispatchChooser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentDispatchChooser, nsIContentDispatchChooser)

nsContentDispatchChooser::nsContentDispatchChooser()
{
  /* member initializers and constructor code */
}

nsContentDispatchChooser::~nsContentDispatchChooser()
{
  /* destructor code */
}

/* void ask (in nsIHandlerInfo aHandler, in nsIInterfaceRequestor aWindowContext, in nsIURI aURI, in unsigned long aReason); */
NS_IMETHODIMP nsContentDispatchChooser::Ask(nsIHandlerInfo *aHandler, nsIInterfaceRequestor *aWindowContext, nsIURI *aURI, uint32_t aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentDispatchChooser_h__ */
