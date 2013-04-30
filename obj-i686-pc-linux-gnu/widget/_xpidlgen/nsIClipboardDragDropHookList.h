/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/widget/nsIClipboardDragDropHookList.idl
 */

#ifndef __gen_nsIClipboardDragDropHookList_h__
#define __gen_nsIClipboardDragDropHookList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIClipboardDragDropHooks; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIClipboardDragDropHookList */
#define NS_ICLIPBOARDDRAGDROPHOOKLIST_IID_STR "876a2015-6b66-11d7-8f18-0003938a9d96"

#define NS_ICLIPBOARDDRAGDROPHOOKLIST_IID \
  {0x876a2015, 0x6b66, 0x11d7, \
    { 0x8f, 0x18, 0x00, 0x03, 0x93, 0x8a, 0x9d, 0x96 }}

class NS_NO_VTABLE nsIClipboardDragDropHookList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDDRAGDROPHOOKLIST_IID)

  /* void addClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
  NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) = 0;

  /* void removeClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
  NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) = 0;

  /* nsISimpleEnumerator getHookEnumerator (); */
  NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardDragDropHookList, NS_ICLIPBOARDDRAGDROPHOOKLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDDRAGDROPHOOKLIST \
  NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks); \
  NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks); \
  NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDDRAGDROPHOOKLIST(_to) \
  NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return _to AddClipboardDragDropHooks(aHooks); } \
  NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return _to RemoveClipboardDragDropHooks(aHooks); } \
  NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator * *_retval) { return _to GetHookEnumerator(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDDRAGDROPHOOKLIST(_to) \
  NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddClipboardDragDropHooks(aHooks); } \
  NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveClipboardDragDropHooks(aHooks); } \
  NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHookEnumerator(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardDragDropHookList : public nsIClipboardDragDropHookList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDDRAGDROPHOOKLIST

  nsClipboardDragDropHookList();

private:
  ~nsClipboardDragDropHookList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClipboardDragDropHookList, nsIClipboardDragDropHookList)

nsClipboardDragDropHookList::nsClipboardDragDropHookList()
{
  /* member initializers and constructor code */
}

nsClipboardDragDropHookList::~nsClipboardDragDropHookList()
{
  /* destructor code */
}

/* void addClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
NS_IMETHODIMP nsClipboardDragDropHookList::AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
NS_IMETHODIMP nsClipboardDragDropHookList::RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getHookEnumerator (); */
NS_IMETHODIMP nsClipboardDragDropHookList::GetHookEnumerator(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClipboardDragDropHookList_h__ */
