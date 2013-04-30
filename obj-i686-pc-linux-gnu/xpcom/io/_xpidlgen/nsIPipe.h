/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/io/nsIPipe.idl
 */

#ifndef __gen_nsIPipe_h__
#define __gen_nsIPipe_h__


#ifndef __gen_nsIAsyncInputStream_h__
#include "nsIAsyncInputStream.h"
#endif

#ifndef __gen_nsIAsyncOutputStream_h__
#include "nsIAsyncOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMemory; /* forward declaration */


/* starting interface:    nsIPipe */
#define NS_IPIPE_IID_STR "f4211abc-61b3-11d4-9877-00c04fa0cf4a"

#define NS_IPIPE_IID \
  {0xf4211abc, 0x61b3, 0x11d4, \
    { 0x98, 0x77, 0x00, 0xc0, 0x4f, 0xa0, 0xcf, 0x4a }}

class NS_NO_VTABLE nsIPipe : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPIPE_IID)

  /* void init (in boolean nonBlockingInput, in boolean nonBlockingOutput, in unsigned long segmentSize, in unsigned long segmentCount, in nsIMemory segmentAllocator); */
  NS_IMETHOD Init(bool nonBlockingInput, bool nonBlockingOutput, uint32_t segmentSize, uint32_t segmentCount, nsIMemory *segmentAllocator) = 0;

  /* readonly attribute nsIAsyncInputStream inputStream; */
  NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream) = 0;

  /* readonly attribute nsIAsyncOutputStream outputStream; */
  NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPipe, NS_IPIPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPIPE \
  NS_IMETHOD Init(bool nonBlockingInput, bool nonBlockingOutput, uint32_t segmentSize, uint32_t segmentCount, nsIMemory *segmentAllocator); \
  NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream); \
  NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPIPE(_to) \
  NS_IMETHOD Init(bool nonBlockingInput, bool nonBlockingOutput, uint32_t segmentSize, uint32_t segmentCount, nsIMemory *segmentAllocator) { return _to Init(nonBlockingInput, nonBlockingOutput, segmentSize, segmentCount, segmentAllocator); } \
  NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream) { return _to GetInputStream(aInputStream); } \
  NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream) { return _to GetOutputStream(aOutputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPIPE(_to) \
  NS_IMETHOD Init(bool nonBlockingInput, bool nonBlockingOutput, uint32_t segmentSize, uint32_t segmentCount, nsIMemory *segmentAllocator) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(nonBlockingInput, nonBlockingOutput, segmentSize, segmentCount, segmentAllocator); } \
  NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(aInputStream); } \
  NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(aOutputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPipe : public nsIPipe
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPIPE

  nsPipe();

private:
  ~nsPipe();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPipe, nsIPipe)

nsPipe::nsPipe()
{
  /* member initializers and constructor code */
}

nsPipe::~nsPipe()
{
  /* destructor code */
}

/* void init (in boolean nonBlockingInput, in boolean nonBlockingOutput, in unsigned long segmentSize, in unsigned long segmentCount, in nsIMemory segmentAllocator); */
NS_IMETHODIMP nsPipe::Init(bool nonBlockingInput, bool nonBlockingOutput, uint32_t segmentSize, uint32_t segmentCount, nsIMemory *segmentAllocator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncInputStream inputStream; */
NS_IMETHODIMP nsPipe::GetInputStream(nsIAsyncInputStream * *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncOutputStream outputStream; */
NS_IMETHODIMP nsPipe::GetOutputStream(nsIAsyncOutputStream * *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISearchableInputStream */
#define NS_ISEARCHABLEINPUTSTREAM_IID_STR "8c39ef62-f7c9-11d4-98f5-001083010e9b"

#define NS_ISEARCHABLEINPUTSTREAM_IID \
  {0x8c39ef62, 0xf7c9, 0x11d4, \
    { 0x98, 0xf5, 0x00, 0x10, 0x83, 0x01, 0x0e, 0x9b }}

class NS_NO_VTABLE nsISearchableInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHABLEINPUTSTREAM_IID)

  /* void search (in string forString, in boolean ignoreCase, out boolean found, out unsigned long offsetSearchedTo); */
  NS_IMETHOD Search(const char * forString, bool ignoreCase, bool *found, uint32_t *offsetSearchedTo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchableInputStream, NS_ISEARCHABLEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHABLEINPUTSTREAM \
  NS_IMETHOD Search(const char * forString, bool ignoreCase, bool *found, uint32_t *offsetSearchedTo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHABLEINPUTSTREAM(_to) \
  NS_IMETHOD Search(const char * forString, bool ignoreCase, bool *found, uint32_t *offsetSearchedTo) { return _to Search(forString, ignoreCase, found, offsetSearchedTo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHABLEINPUTSTREAM(_to) \
  NS_IMETHOD Search(const char * forString, bool ignoreCase, bool *found, uint32_t *offsetSearchedTo) { return !_to ? NS_ERROR_NULL_POINTER : _to->Search(forString, ignoreCase, found, offsetSearchedTo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchableInputStream : public nsISearchableInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHABLEINPUTSTREAM

  nsSearchableInputStream();

private:
  ~nsSearchableInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSearchableInputStream, nsISearchableInputStream)

nsSearchableInputStream::nsSearchableInputStream()
{
  /* member initializers and constructor code */
}

nsSearchableInputStream::~nsSearchableInputStream()
{
  /* destructor code */
}

/* void search (in string forString, in boolean ignoreCase, out boolean found, out unsigned long offsetSearchedTo); */
NS_IMETHODIMP nsSearchableInputStream::Search(const char * forString, bool ignoreCase, bool *found, uint32_t *offsetSearchedTo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/**
 * NS_NewPipe2
 *
 * This function supersedes NS_NewPipe.  It differs from NS_NewPipe in two
 * major ways:
 *  (1) returns nsIAsyncInputStream and nsIAsyncOutputStream, so it is
 *      not necessary to QI in order to access these interfaces.
 *  (2) the size of the pipe is determined by the number of segments
 *      times the size of each segment.
 *
 * @param pipeIn
 *        resulting input end of the pipe
 * @param pipeOut
 *        resulting output end of the pipe
 * @param nonBlockingInput
 *        true specifies non-blocking input stream behavior
 * @param nonBlockingOutput
 *        true specifies non-blocking output stream behavior
 * @param segmentSize
 *        specifies the segment size in bytes (pass 0 to use default value)
 * @param segmentCount
 *        specifies the max number of segments (pass 0 to use default value)
 *        passing UINT32_MAX here causes the pipe to have "infinite" space.
 *        this mode can be useful in some cases, but should always be used with
 *        caution.  the default value for this parameter is a finite value.
 * @param segmentAlloc
 *        pass reference to nsIMemory to have all pipe allocations use this
 *        allocator (pass null to use the default allocator)
 */
extern nsresult
NS_NewPipe2(nsIAsyncInputStream **pipeIn,
            nsIAsyncOutputStream **pipeOut,
            bool nonBlockingInput = false,
            bool nonBlockingOutput = false,
            uint32_t segmentSize = 0,
            uint32_t segmentCount = 0,
            nsIMemory *segmentAlloc = nullptr);
/**
 * NS_NewPipe
 *
 * Preserved for backwards compatibility.  Plus, this interface is more
 * amiable in certain contexts (e.g., when you don't need the pipe's async
 * capabilities).
 *
 * @param pipeIn
 *        resulting input end of the pipe
 * @param pipeOut
 *        resulting output end of the pipe
 * @param segmentSize
 *        specifies the segment size in bytes (pass 0 to use default value)
 * @param maxSize
 *        specifies the max size of the pipe (pass 0 to use default value)
 *        number of segments is maxSize / segmentSize, and maxSize must be a
 *        multiple of segmentSize.  passing UINT32_MAX here causes the
 *        pipe to have "infinite" space.  this mode can be useful in some
 *        cases, but should always be used with caution.  the default value
 *        for this parameter is a finite value.
 * @param nonBlockingInput
 *        true specifies non-blocking input stream behavior
 * @param nonBlockingOutput
 *        true specifies non-blocking output stream behavior
 * @param segmentAlloc
 *        pass reference to nsIMemory to have all pipe allocations use this
 *        allocator (pass null to use the default allocator)
 */
extern nsresult
NS_NewPipe(nsIInputStream **pipeIn,
           nsIOutputStream **pipeOut,
           uint32_t segmentSize = 0,
           uint32_t maxSize = 0,
           bool nonBlockingInput = false,
           bool nonBlockingOutput = false,
           nsIMemory *segmentAlloc = nullptr);

#endif /* __gen_nsIPipe_h__ */
