/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/workers/test/extensions/traditional/nsIWorkerTest.idl
 */

#ifndef __gen_nsIWorkerTest_h__
#define __gen_nsIWorkerTest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWorkerTestCallback */
#define NS_IWORKERTESTCALLBACK_IID_STR "10f8ebdf-1373-4640-9c34-53dee99f526f"

#define NS_IWORKERTESTCALLBACK_IID \
  {0x10f8ebdf, 0x1373, 0x4640, \
    { 0x9c, 0x34, 0x53, 0xde, 0xe9, 0x9f, 0x52, 0x6f }}

class NS_NO_VTABLE nsIWorkerTestCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERTESTCALLBACK_IID)

  /* void onmessage (in DOMString data); */
  NS_IMETHOD Onmessage(const nsAString & data) = 0;

  /* void onerror (in DOMString data); */
  NS_IMETHOD Onerror(const nsAString & data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerTestCallback, NS_IWORKERTESTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERTESTCALLBACK \
  NS_IMETHOD Onmessage(const nsAString & data); \
  NS_IMETHOD Onerror(const nsAString & data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERTESTCALLBACK(_to) \
  NS_IMETHOD Onmessage(const nsAString & data) { return _to Onmessage(data); } \
  NS_IMETHOD Onerror(const nsAString & data) { return _to Onerror(data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERTESTCALLBACK(_to) \
  NS_IMETHOD Onmessage(const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Onmessage(data); } \
  NS_IMETHOD Onerror(const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Onerror(data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerTestCallback : public nsIWorkerTestCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERTESTCALLBACK

  nsWorkerTestCallback();

private:
  ~nsWorkerTestCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerTestCallback, nsIWorkerTestCallback)

nsWorkerTestCallback::nsWorkerTestCallback()
{
  /* member initializers and constructor code */
}

nsWorkerTestCallback::~nsWorkerTestCallback()
{
  /* destructor code */
}

/* void onmessage (in DOMString data); */
NS_IMETHODIMP nsWorkerTestCallback::Onmessage(const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onerror (in DOMString data); */
NS_IMETHODIMP nsWorkerTestCallback::Onerror(const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerTest */
#define NS_IWORKERTEST_IID_STR "887a0614-a0f0-4c0e-80e0-cf31e6d4e286"

#define NS_IWORKERTEST_IID \
  {0x887a0614, 0xa0f0, 0x4c0e, \
    { 0x80, 0xe0, 0xcf, 0x31, 0xe6, 0xd4, 0xe2, 0x86 }}

class NS_NO_VTABLE nsIWorkerTest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERTEST_IID)

  /* void postMessage (in DOMString data); */
  NS_IMETHOD PostMessage(const nsAString & data) = 0;

  /* void terminate (); */
  NS_IMETHOD Terminate(void) = 0;

  /* attribute nsIWorkerTestCallback callback; */
  NS_IMETHOD GetCallback(nsIWorkerTestCallback * *aCallback) = 0;
  NS_IMETHOD SetCallback(nsIWorkerTestCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerTest, NS_IWORKERTEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERTEST \
  NS_IMETHOD PostMessage(const nsAString & data); \
  NS_IMETHOD Terminate(void); \
  NS_IMETHOD GetCallback(nsIWorkerTestCallback * *aCallback); \
  NS_IMETHOD SetCallback(nsIWorkerTestCallback *aCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERTEST(_to) \
  NS_IMETHOD PostMessage(const nsAString & data) { return _to PostMessage(data); } \
  NS_IMETHOD Terminate(void) { return _to Terminate(); } \
  NS_IMETHOD GetCallback(nsIWorkerTestCallback * *aCallback) { return _to GetCallback(aCallback); } \
  NS_IMETHOD SetCallback(nsIWorkerTestCallback *aCallback) { return _to SetCallback(aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERTEST(_to) \
  NS_IMETHOD PostMessage(const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessage(data); } \
  NS_IMETHOD Terminate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Terminate(); } \
  NS_IMETHOD GetCallback(nsIWorkerTestCallback * *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallback(aCallback); } \
  NS_IMETHOD SetCallback(nsIWorkerTestCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCallback(aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerTest : public nsIWorkerTest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERTEST

  nsWorkerTest();

private:
  ~nsWorkerTest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerTest, nsIWorkerTest)

nsWorkerTest::nsWorkerTest()
{
  /* member initializers and constructor code */
}

nsWorkerTest::~nsWorkerTest()
{
  /* destructor code */
}

/* void postMessage (in DOMString data); */
NS_IMETHODIMP nsWorkerTest::PostMessage(const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void terminate (); */
NS_IMETHODIMP nsWorkerTest::Terminate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWorkerTestCallback callback; */
NS_IMETHODIMP nsWorkerTest::GetCallback(nsIWorkerTestCallback * *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWorkerTest::SetCallback(nsIWorkerTestCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWorkerTest_h__ */
