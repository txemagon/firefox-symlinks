/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/ds/nsISupportsIterators.idl
 */

#ifndef __gen_nsISupportsIterators_h__
#define __gen_nsISupportsIterators_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIOutputIterator */
#define NS_IOUTPUTITERATOR_IID_STR "7330650e-1dd2-11b2-a0c2-9ff86ee97bed"

#define NS_IOUTPUTITERATOR_IID \
  {0x7330650e, 0x1dd2, 0x11b2, \
    { 0xa0, 0xc2, 0x9f, 0xf8, 0x6e, 0xe9, 0x7b, 0xed }}

class NS_NO_VTABLE nsIOutputIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOUTPUTITERATOR_IID)

  /* void putElement (in nsISupports anElementToPut); */
  NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /* void stepForward (); */
  NS_IMETHOD StepForward(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOutputIterator, NS_IOUTPUTITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOUTPUTITERATOR \
  NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_IMETHOD StepForward(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOUTPUTITERATOR(_to) \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_IMETHOD StepForward(void) { return _to StepForward(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOUTPUTITERATOR(_to) \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOutputIterator : public nsIOutputIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOUTPUTITERATOR

  nsOutputIterator();

private:
  ~nsOutputIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOutputIterator, nsIOutputIterator)

nsOutputIterator::nsOutputIterator()
{
  /* member initializers and constructor code */
}

nsOutputIterator::~nsOutputIterator()
{
  /* destructor code */
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsOutputIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsOutputIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInputIterator */
#define NS_IINPUTITERATOR_IID_STR "85585e12-1dd2-11b2-a930-f6929058269a"

#define NS_IINPUTITERATOR_IID \
  {0x85585e12, 0x1dd2, 0x11b2, \
    { 0xa9, 0x30, 0xf6, 0x92, 0x90, 0x58, 0x26, 0x9a }}

class NS_NO_VTABLE nsIInputIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTITERATOR_IID)

  /* nsISupports getElement (); */
  NS_IMETHOD GetElement(nsISupports * *_retval) = 0;

  /* void stepForward (); */
  NS_IMETHOD StepForward(void) = 0;

  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) = 0;

  /* nsISupports clone (); */
  NS_IMETHOD Clone(nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputIterator, NS_IINPUTITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTITERATOR \
  NS_IMETHOD GetElement(nsISupports * *_retval); \
  NS_IMETHOD StepForward(void); \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval); \
  NS_IMETHOD Clone(nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return _to GetElement(_retval); } \
  NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputIterator : public nsIInputIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTITERATOR

  nsInputIterator();

private:
  ~nsInputIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputIterator, nsIInputIterator)

nsInputIterator::nsInputIterator()
{
  /* member initializers and constructor code */
}

nsInputIterator::~nsInputIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsInputIterator::GetElement(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsInputIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsInputIterator::IsEqualTo(nsISupports *anotherIterator, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsInputIterator::Clone(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIForwardIterator */
#define NS_IFORWARDITERATOR_IID_STR "8da01646-1dd2-11b2-98a7-c7009045be7e"

#define NS_IFORWARDITERATOR_IID \
  {0x8da01646, 0x1dd2, 0x11b2, \
    { 0x98, 0xa7, 0xc7, 0x00, 0x90, 0x45, 0xbe, 0x7e }}

class NS_NO_VTABLE nsIForwardIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORWARDITERATOR_IID)

  /* nsISupports getElement (); */
  NS_IMETHOD GetElement(nsISupports * *_retval) = 0;

  /* void putElement (in nsISupports anElementToPut); */
  NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /* void stepForward (); */
  NS_IMETHOD StepForward(void) = 0;

  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) = 0;

  /* nsISupports clone (); */
  NS_IMETHOD Clone(nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIForwardIterator, NS_IFORWARDITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORWARDITERATOR \
  NS_IMETHOD GetElement(nsISupports * *_retval); \
  NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_IMETHOD StepForward(void); \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval); \
  NS_IMETHOD Clone(nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORWARDITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return _to GetElement(_retval); } \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORWARDITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsForwardIterator : public nsIForwardIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORWARDITERATOR

  nsForwardIterator();

private:
  ~nsForwardIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsForwardIterator, nsIForwardIterator)

nsForwardIterator::nsForwardIterator()
{
  /* member initializers and constructor code */
}

nsForwardIterator::~nsForwardIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsForwardIterator::GetElement(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsForwardIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsForwardIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsForwardIterator::IsEqualTo(nsISupports *anotherIterator, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsForwardIterator::Clone(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBidirectionalIterator */
#define NS_IBIDIRECTIONALITERATOR_IID_STR "948defaa-1dd1-11b2-89f6-8ce81f5ebda9"

#define NS_IBIDIRECTIONALITERATOR_IID \
  {0x948defaa, 0x1dd1, 0x11b2, \
    { 0x89, 0xf6, 0x8c, 0xe8, 0x1f, 0x5e, 0xbd, 0xa9 }}

class NS_NO_VTABLE nsIBidirectionalIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBIDIRECTIONALITERATOR_IID)

  /* nsISupports getElement (); */
  NS_IMETHOD GetElement(nsISupports * *_retval) = 0;

  /* void putElement (in nsISupports anElementToPut); */
  NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /* void stepForward (); */
  NS_IMETHOD StepForward(void) = 0;

  /* void stepBackward (); */
  NS_IMETHOD StepBackward(void) = 0;

  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) = 0;

  /* nsISupports clone (); */
  NS_IMETHOD Clone(nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBidirectionalIterator, NS_IBIDIRECTIONALITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBIDIRECTIONALITERATOR \
  NS_IMETHOD GetElement(nsISupports * *_retval); \
  NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_IMETHOD StepForward(void); \
  NS_IMETHOD StepBackward(void); \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval); \
  NS_IMETHOD Clone(nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBIDIRECTIONALITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return _to GetElement(_retval); } \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_IMETHOD StepBackward(void) { return _to StepBackward(); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBIDIRECTIONALITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_IMETHOD StepBackward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepBackward(); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBidirectionalIterator : public nsIBidirectionalIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBIDIRECTIONALITERATOR

  nsBidirectionalIterator();

private:
  ~nsBidirectionalIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBidirectionalIterator, nsIBidirectionalIterator)

nsBidirectionalIterator::nsBidirectionalIterator()
{
  /* member initializers and constructor code */
}

nsBidirectionalIterator::~nsBidirectionalIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsBidirectionalIterator::GetElement(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsBidirectionalIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsBidirectionalIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepBackward (); */
NS_IMETHODIMP nsBidirectionalIterator::StepBackward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsBidirectionalIterator::IsEqualTo(nsISupports *anotherIterator, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsBidirectionalIterator::Clone(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRandomAccessIterator */
#define NS_IRANDOMACCESSITERATOR_IID_STR "9bd6fdb0-1dd1-11b2-9101-d15375968230"

#define NS_IRANDOMACCESSITERATOR_IID \
  {0x9bd6fdb0, 0x1dd1, 0x11b2, \
    { 0x91, 0x01, 0xd1, 0x53, 0x75, 0x96, 0x82, 0x30 }}

class NS_NO_VTABLE nsIRandomAccessIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRANDOMACCESSITERATOR_IID)

  /* nsISupports getElement (); */
  NS_IMETHOD GetElement(nsISupports * *_retval) = 0;

  /* nsISupports getElementAt (in int32_t anOffset); */
  NS_IMETHOD GetElementAt(int32_t anOffset, nsISupports * *_retval) = 0;

  /* void putElement (in nsISupports anElementToPut); */
  NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /* void putElementAt (in int32_t anOffset, in nsISupports anElementToPut); */
  NS_IMETHOD PutElementAt(int32_t anOffset, nsISupports *anElementToPut) = 0;

  /* void stepForward (); */
  NS_IMETHOD StepForward(void) = 0;

  /* void stepForwardBy (in int32_t anOffset); */
  NS_IMETHOD StepForwardBy(int32_t anOffset) = 0;

  /* void stepBackward (); */
  NS_IMETHOD StepBackward(void) = 0;

  /* void stepBackwardBy (in int32_t anOffset); */
  NS_IMETHOD StepBackwardBy(int32_t anOffset) = 0;

  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) = 0;

  /* nsISupports clone (); */
  NS_IMETHOD Clone(nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRandomAccessIterator, NS_IRANDOMACCESSITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRANDOMACCESSITERATOR \
  NS_IMETHOD GetElement(nsISupports * *_retval); \
  NS_IMETHOD GetElementAt(int32_t anOffset, nsISupports * *_retval); \
  NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_IMETHOD PutElementAt(int32_t anOffset, nsISupports *anElementToPut); \
  NS_IMETHOD StepForward(void); \
  NS_IMETHOD StepForwardBy(int32_t anOffset); \
  NS_IMETHOD StepBackward(void); \
  NS_IMETHOD StepBackwardBy(int32_t anOffset); \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval); \
  NS_IMETHOD Clone(nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRANDOMACCESSITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return _to GetElement(_retval); } \
  NS_IMETHOD GetElementAt(int32_t anOffset, nsISupports * *_retval) { return _to GetElementAt(anOffset, _retval); } \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_IMETHOD PutElementAt(int32_t anOffset, nsISupports *anElementToPut) { return _to PutElementAt(anOffset, anElementToPut); } \
  NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_IMETHOD StepForwardBy(int32_t anOffset) { return _to StepForwardBy(anOffset); } \
  NS_IMETHOD StepBackward(void) { return _to StepBackward(); } \
  NS_IMETHOD StepBackwardBy(int32_t anOffset) { return _to StepBackwardBy(anOffset); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRANDOMACCESSITERATOR(_to) \
  NS_IMETHOD GetElement(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_IMETHOD GetElementAt(int32_t anOffset, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementAt(anOffset, _retval); } \
  NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_IMETHOD PutElementAt(int32_t anOffset, nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElementAt(anOffset, anElementToPut); } \
  NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_IMETHOD StepForwardBy(int32_t anOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForwardBy(anOffset); } \
  NS_IMETHOD StepBackward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepBackward(); } \
  NS_IMETHOD StepBackwardBy(int32_t anOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepBackwardBy(anOffset); } \
  NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_IMETHOD Clone(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRandomAccessIterator : public nsIRandomAccessIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRANDOMACCESSITERATOR

  nsRandomAccessIterator();

private:
  ~nsRandomAccessIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRandomAccessIterator, nsIRandomAccessIterator)

nsRandomAccessIterator::nsRandomAccessIterator()
{
  /* member initializers and constructor code */
}

nsRandomAccessIterator::~nsRandomAccessIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsRandomAccessIterator::GetElement(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getElementAt (in int32_t anOffset); */
NS_IMETHODIMP nsRandomAccessIterator::GetElementAt(int32_t anOffset, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsRandomAccessIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElementAt (in int32_t anOffset, in nsISupports anElementToPut); */
NS_IMETHODIMP nsRandomAccessIterator::PutElementAt(int32_t anOffset, nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsRandomAccessIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForwardBy (in int32_t anOffset); */
NS_IMETHODIMP nsRandomAccessIterator::StepForwardBy(int32_t anOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepBackward (); */
NS_IMETHODIMP nsRandomAccessIterator::StepBackward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepBackwardBy (in int32_t anOffset); */
NS_IMETHODIMP nsRandomAccessIterator::StepBackwardBy(int32_t anOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsRandomAccessIterator::IsEqualTo(nsISupports *anotherIterator, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsRandomAccessIterator::Clone(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISupportsIterators_h__ */
