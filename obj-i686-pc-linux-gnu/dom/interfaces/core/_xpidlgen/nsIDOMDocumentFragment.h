/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/core/nsIDOMDocumentFragment.idl
 */

#ifndef __gen_nsIDOMDocumentFragment_h__
#define __gen_nsIDOMDocumentFragment_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentFragment */
#define NS_IDOMDOCUMENTFRAGMENT_IID_STR "4a15eb0c-d5bc-4902-9d50-21b12cab47e7"

#define NS_IDOMDOCUMENTFRAGMENT_IID \
  {0x4a15eb0c, 0xd5bc, 0x4902, \
    { 0x9d, 0x50, 0x21, 0xb1, 0x2c, 0xab, 0x47, 0xe7 }}

class NS_NO_VTABLE nsIDOMDocumentFragment : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTFRAGMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentFragment, NS_IDOMDOCUMENTFRAGMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTFRAGMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTFRAGMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTFRAGMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentFragment : public nsIDOMDocumentFragment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTFRAGMENT

  nsDOMDocumentFragment();

private:
  ~nsDOMDocumentFragment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentFragment, nsIDOMDocumentFragment)

nsDOMDocumentFragment::nsDOMDocumentFragment()
{
  /* member initializers and constructor code */
}

nsDOMDocumentFragment::~nsDOMDocumentFragment()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentFragment_h__ */
