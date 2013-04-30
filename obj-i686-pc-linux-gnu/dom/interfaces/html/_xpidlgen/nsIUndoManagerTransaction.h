/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/html/nsIUndoManagerTransaction.idl
 */

#ifndef __gen_nsIUndoManagerTransaction_h__
#define __gen_nsIUndoManagerTransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUndoManagerTransaction */
#define NS_IUNDOMANAGERTRANSACTION_IID_STR "3802f155-e0f5-49ba-9972-e1aadcf2fdf0"

#define NS_IUNDOMANAGERTRANSACTION_IID \
  {0x3802f155, 0xe0f5, 0x49ba, \
    { 0x99, 0x72, 0xe1, 0xaa, 0xdc, 0xf2, 0xfd, 0xf0 }}

class NS_NO_VTABLE nsIUndoManagerTransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNDOMANAGERTRANSACTION_IID)

  /* attribute DOMString label; */
  NS_IMETHOD GetLabel(nsAString & aLabel) = 0;
  NS_IMETHOD SetLabel(const nsAString & aLabel) = 0;

  /* void executeAutomatic (); */
  NS_IMETHOD ExecuteAutomatic(void) = 0;

  /* void execute (); */
  NS_IMETHOD Execute(void) = 0;

  /* void undo (); */
  NS_IMETHOD Undo(void) = 0;

  /* void redo (); */
  NS_IMETHOD Redo(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUndoManagerTransaction, NS_IUNDOMANAGERTRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNDOMANAGERTRANSACTION \
  NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_IMETHOD SetLabel(const nsAString & aLabel); \
  NS_IMETHOD ExecuteAutomatic(void); \
  NS_IMETHOD Execute(void); \
  NS_IMETHOD Undo(void); \
  NS_IMETHOD Redo(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNDOMANAGERTRANSACTION(_to) \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return _to SetLabel(aLabel); } \
  NS_IMETHOD ExecuteAutomatic(void) { return _to ExecuteAutomatic(); } \
  NS_IMETHOD Execute(void) { return _to Execute(); } \
  NS_IMETHOD Undo(void) { return _to Undo(); } \
  NS_IMETHOD Redo(void) { return _to Redo(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNDOMANAGERTRANSACTION(_to) \
  NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD SetLabel(const nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLabel(aLabel); } \
  NS_IMETHOD ExecuteAutomatic(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAutomatic(); } \
  NS_IMETHOD Execute(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Execute(); } \
  NS_IMETHOD Undo(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Undo(); } \
  NS_IMETHOD Redo(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Redo(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUndoManagerTransaction : public nsIUndoManagerTransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNDOMANAGERTRANSACTION

  nsUndoManagerTransaction();

private:
  ~nsUndoManagerTransaction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUndoManagerTransaction, nsIUndoManagerTransaction)

nsUndoManagerTransaction::nsUndoManagerTransaction()
{
  /* member initializers and constructor code */
}

nsUndoManagerTransaction::~nsUndoManagerTransaction()
{
  /* destructor code */
}

/* attribute DOMString label; */
NS_IMETHODIMP nsUndoManagerTransaction::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUndoManagerTransaction::SetLabel(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void executeAutomatic (); */
NS_IMETHODIMP nsUndoManagerTransaction::ExecuteAutomatic()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void execute (); */
NS_IMETHODIMP nsUndoManagerTransaction::Execute()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undo (); */
NS_IMETHODIMP nsUndoManagerTransaction::Undo()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redo (); */
NS_IMETHODIMP nsUndoManagerTransaction::Redo()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUndoManagerTransaction_h__ */
