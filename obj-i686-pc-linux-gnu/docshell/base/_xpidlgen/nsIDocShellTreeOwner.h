/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/docshell/base/nsIDocShellTreeOwner.idl
 */

#ifndef __gen_nsIDocShellTreeOwner_h__
#define __gen_nsIDocShellTreeOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeItem; /* forward declaration */


/* starting interface:    nsIDocShellTreeOwner */
#define NS_IDOCSHELLTREEOWNER_IID_STR "932f9f93-8e21-4728-a527-cafc64b4d831"

#define NS_IDOCSHELLTREEOWNER_IID \
  {0x932f9f93, 0x8e21, 0x4728, \
    { 0xa5, 0x27, 0xca, 0xfc, 0x64, 0xb4, 0xd8, 0x31 }}

class NS_NO_VTABLE nsIDocShellTreeOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREEOWNER_IID)

  /* nsIDocShellTreeItem findItemWithName (in wstring name, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) = 0;

  /* void contentShellAdded (in nsIDocShellTreeItem aContentShell, in boolean aPrimary, in boolean aTargetable, in AString aID); */
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) = 0;

  /* void contentShellRemoved (in nsIDocShellTreeItem aContentShell); */
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) = 0;

  /* readonly attribute nsIDocShellTreeItem primaryContentShell; */
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) = 0;

  /* void sizeShellTo (in nsIDocShellTreeItem shell, in long cx, in long cy); */
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) = 0;

  /* void setPersistence (in boolean aPersistPosition, in boolean aPersistSize, in boolean aPersistSizeMode); */
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) = 0;

  /* void getPersistence (out boolean aPersistPosition, out boolean aPersistSize, out boolean aPersistSizeMode); */
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) = 0;

  /* readonly attribute unsigned long targetableShellCount; */
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeOwner, NS_IDOCSHELLTREEOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREEOWNER \
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval); \
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID); \
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell); \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell); \
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy); \
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode); \
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode); \
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREEOWNER(_to) \
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) { return _to FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) { return _to ContentShellAdded(aContentShell, aPrimary, aTargetable, aID); } \
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) { return _to ContentShellRemoved(aContentShell); } \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) { return _to GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) { return _to SizeShellTo(shell, cx, cy); } \
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) { return _to SetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) { return _to GetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) { return _to GetTargetableShellCount(aTargetableShellCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREEOWNER(_to) \
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentShellAdded(aContentShell, aPrimary, aTargetable, aID); } \
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentShellRemoved(aContentShell); } \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeShellTo(shell, cx, cy); } \
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetableShellCount(aTargetableShellCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeOwner : public nsIDocShellTreeOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREEOWNER

  nsDocShellTreeOwner();

private:
  ~nsDocShellTreeOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellTreeOwner, nsIDocShellTreeOwner)

nsDocShellTreeOwner::nsDocShellTreeOwner()
{
  /* member initializers and constructor code */
}

nsDocShellTreeOwner::~nsDocShellTreeOwner()
{
  /* destructor code */
}

/* nsIDocShellTreeItem findItemWithName (in wstring name, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeOwner::FindItemWithName(const PRUnichar * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentShellAdded (in nsIDocShellTreeItem aContentShell, in boolean aPrimary, in boolean aTargetable, in AString aID); */
NS_IMETHODIMP nsDocShellTreeOwner::ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentShellRemoved (in nsIDocShellTreeItem aContentShell); */
NS_IMETHODIMP nsDocShellTreeOwner::ContentShellRemoved(nsIDocShellTreeItem *aContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem primaryContentShell; */
NS_IMETHODIMP nsDocShellTreeOwner::GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeShellTo (in nsIDocShellTreeItem shell, in long cx, in long cy); */
NS_IMETHODIMP nsDocShellTreeOwner::SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPersistence (in boolean aPersistPosition, in boolean aPersistSize, in boolean aPersistSizeMode); */
NS_IMETHODIMP nsDocShellTreeOwner::SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPersistence (out boolean aPersistPosition, out boolean aPersistSize, out boolean aPersistSizeMode); */
NS_IMETHODIMP nsDocShellTreeOwner::GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long targetableShellCount; */
NS_IMETHODIMP nsDocShellTreeOwner::GetTargetableShellCount(uint32_t *aTargetableShellCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeOwner_h__ */
