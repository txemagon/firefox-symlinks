/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/io/nsIConverterInputStream.idl
 */

#ifndef __gen_nsIConverterInputStream_h__
#define __gen_nsIConverterInputStream_h__


#ifndef __gen_nsIUnicharInputStream_h__
#include "nsIUnicharInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIConverterInputStream */
#define NS_ICONVERTERINPUTSTREAM_IID_STR "fc66ffb6-5404-4908-a4a3-27f92fa0579d"

#define NS_ICONVERTERINPUTSTREAM_IID \
  {0xfc66ffb6, 0x5404, 0x4908, \
    { 0xa4, 0xa3, 0x27, 0xf9, 0x2f, 0xa0, 0x57, 0x9d }}

class NS_NO_VTABLE nsIConverterInputStream : public nsIUnicharInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONVERTERINPUTSTREAM_IID)

  enum {
    DEFAULT_REPLACEMENT_CHARACTER = 65533U
  };

  /* void init (in nsIInputStream aStream, in string aCharset, in long aBufferSize, in PRUnichar aReplacementChar); */
  NS_IMETHOD Init(nsIInputStream *aStream, const char * aCharset, int32_t aBufferSize, PRUnichar aReplacementChar) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConverterInputStream, NS_ICONVERTERINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONVERTERINPUTSTREAM \
  NS_IMETHOD Init(nsIInputStream *aStream, const char * aCharset, int32_t aBufferSize, PRUnichar aReplacementChar); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONVERTERINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIInputStream *aStream, const char * aCharset, int32_t aBufferSize, PRUnichar aReplacementChar) { return _to Init(aStream, aCharset, aBufferSize, aReplacementChar); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONVERTERINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIInputStream *aStream, const char * aCharset, int32_t aBufferSize, PRUnichar aReplacementChar) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aStream, aCharset, aBufferSize, aReplacementChar); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConverterInputStream : public nsIConverterInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONVERTERINPUTSTREAM

  nsConverterInputStream();

private:
  ~nsConverterInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConverterInputStream, nsIConverterInputStream)

nsConverterInputStream::nsConverterInputStream()
{
  /* member initializers and constructor code */
}

nsConverterInputStream::~nsConverterInputStream()
{
  /* destructor code */
}

/* void init (in nsIInputStream aStream, in string aCharset, in long aBufferSize, in PRUnichar aReplacementChar); */
NS_IMETHODIMP nsConverterInputStream::Init(nsIInputStream *aStream, const char * aCharset, int32_t aBufferSize, PRUnichar aReplacementChar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIConverterInputStream_h__ */
