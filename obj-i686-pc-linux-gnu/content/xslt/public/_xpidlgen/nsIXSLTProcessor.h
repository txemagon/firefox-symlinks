/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/content/xslt/public/nsIXSLTProcessor.idl
 */

#ifndef __gen_nsIXSLTProcessor_h__
#define __gen_nsIXSLTProcessor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIXSLTProcessor */
#define NS_IXSLTPROCESSOR_IID_STR "4a91aeb3-4100-43ee-a21e-9866268757c5"

#define NS_IXSLTPROCESSOR_IID \
  {0x4a91aeb3, 0x4100, 0x43ee, \
    { 0xa2, 0x1e, 0x98, 0x66, 0x26, 0x87, 0x57, 0xc5 }}

class NS_NO_VTABLE nsIXSLTProcessor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXSLTPROCESSOR_IID)

  /* void importStylesheet (in nsIDOMNode style); */
  NS_IMETHOD ImportStylesheet(nsIDOMNode *style) = 0;

  /* nsIDOMDocumentFragment transformToFragment (in nsIDOMNode source, in nsIDOMDocument output); */
  NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment * *_retval) = 0;

  /* nsIDOMDocument transformToDocument (in nsIDOMNode source); */
  NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument * *_retval) = 0;

  /* void setParameter (in DOMString namespaceURI, in DOMString localName, in nsIVariant value); */
  NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value) = 0;

  /* nsIVariant getParameter (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant * *_retval) = 0;

  /* void removeParameter (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName) = 0;

  /* void clearParameters (); */
  NS_IMETHOD ClearParameters(void) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXSLTProcessor, NS_IXSLTPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXSLTPROCESSOR \
  NS_IMETHOD ImportStylesheet(nsIDOMNode *style); \
  NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment * *_retval); \
  NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument * *_retval); \
  NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value); \
  NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant * *_retval); \
  NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName); \
  NS_IMETHOD ClearParameters(void); \
  NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXSLTPROCESSOR(_to) \
  NS_IMETHOD ImportStylesheet(nsIDOMNode *style) { return _to ImportStylesheet(style); } \
  NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment * *_retval) { return _to TransformToFragment(source, output, _retval); } \
  NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument * *_retval) { return _to TransformToDocument(source, _retval); } \
  NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value) { return _to SetParameter(namespaceURI, localName, value); } \
  NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant * *_retval) { return _to GetParameter(namespaceURI, localName, _retval); } \
  NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName) { return _to RemoveParameter(namespaceURI, localName); } \
  NS_IMETHOD ClearParameters(void) { return _to ClearParameters(); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXSLTPROCESSOR(_to) \
  NS_IMETHOD ImportStylesheet(nsIDOMNode *style) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportStylesheet(style); } \
  NS_IMETHOD TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TransformToFragment(source, output, _retval); } \
  NS_IMETHOD TransformToDocument(nsIDOMNode *source, nsIDOMDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TransformToDocument(source, _retval); } \
  NS_IMETHOD SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParameter(namespaceURI, localName, value); } \
  NS_IMETHOD GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(namespaceURI, localName, _retval); } \
  NS_IMETHOD RemoveParameter(const nsAString & namespaceURI, const nsAString & localName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveParameter(namespaceURI, localName); } \
  NS_IMETHOD ClearParameters(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearParameters(); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXSLTProcessor : public nsIXSLTProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXSLTPROCESSOR

  nsXSLTProcessor();

private:
  ~nsXSLTProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXSLTProcessor, nsIXSLTProcessor)

nsXSLTProcessor::nsXSLTProcessor()
{
  /* member initializers and constructor code */
}

nsXSLTProcessor::~nsXSLTProcessor()
{
  /* destructor code */
}

/* void importStylesheet (in nsIDOMNode style); */
NS_IMETHODIMP nsXSLTProcessor::ImportStylesheet(nsIDOMNode *style)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment transformToFragment (in nsIDOMNode source, in nsIDOMDocument output); */
NS_IMETHODIMP nsXSLTProcessor::TransformToFragment(nsIDOMNode *source, nsIDOMDocument *output, nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument transformToDocument (in nsIDOMNode source); */
NS_IMETHODIMP nsXSLTProcessor::TransformToDocument(nsIDOMNode *source, nsIDOMDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setParameter (in DOMString namespaceURI, in DOMString localName, in nsIVariant value); */
NS_IMETHODIMP nsXSLTProcessor::SetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getParameter (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsXSLTProcessor::GetParameter(const nsAString & namespaceURI, const nsAString & localName, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeParameter (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsXSLTProcessor::RemoveParameter(const nsAString & namespaceURI, const nsAString & localName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearParameters (); */
NS_IMETHODIMP nsXSLTProcessor::ClearParameters()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsXSLTProcessor::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXSLTProcessor_h__ */
