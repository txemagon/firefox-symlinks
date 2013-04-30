/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/storage/nsIDOMStorageIndexedDB.idl
 */

#ifndef __gen_nsIDOMStorageIndexedDB_h__
#define __gen_nsIDOMStorageIndexedDB_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBFactory; /* forward declaration */


/* starting interface:    nsIDOMStorageIndexedDB */
#define NS_IDOMSTORAGEINDEXEDDB_IID_STR "94ca74e8-9cff-456e-a7a4-a4071a32ff58"

#define NS_IDOMSTORAGEINDEXEDDB_IID \
  {0x94ca74e8, 0x9cff, 0x456e, \
    { 0xa7, 0xa4, 0xa4, 0x07, 0x1a, 0x32, 0xff, 0x58 }}

class NS_NO_VTABLE nsIDOMStorageIndexedDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEINDEXEDDB_IID)

  /* readonly attribute nsIIDBFactory indexedDB; */
  NS_IMETHOD GetIndexedDB(nsIIDBFactory * *aIndexedDB) = 0;

  /* readonly attribute nsIIDBFactory mozIndexedDB; */
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory * *aMozIndexedDB) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageIndexedDB, NS_IDOMSTORAGEINDEXEDDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEINDEXEDDB \
  NS_IMETHOD GetIndexedDB(nsIIDBFactory * *aIndexedDB); \
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory * *aMozIndexedDB); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEINDEXEDDB(_to) \
  NS_IMETHOD GetIndexedDB(nsIIDBFactory * *aIndexedDB) { return _to GetIndexedDB(aIndexedDB); } \
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory * *aMozIndexedDB) { return _to GetMozIndexedDB(aMozIndexedDB); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEINDEXEDDB(_to) \
  NS_IMETHOD GetIndexedDB(nsIIDBFactory * *aIndexedDB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexedDB(aIndexedDB); } \
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory * *aMozIndexedDB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozIndexedDB(aMozIndexedDB); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageIndexedDB : public nsIDOMStorageIndexedDB
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEINDEXEDDB

  nsDOMStorageIndexedDB();

private:
  ~nsDOMStorageIndexedDB();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageIndexedDB, nsIDOMStorageIndexedDB)

nsDOMStorageIndexedDB::nsDOMStorageIndexedDB()
{
  /* member initializers and constructor code */
}

nsDOMStorageIndexedDB::~nsDOMStorageIndexedDB()
{
  /* destructor code */
}

/* readonly attribute nsIIDBFactory indexedDB; */
NS_IMETHODIMP nsDOMStorageIndexedDB::GetIndexedDB(nsIIDBFactory * *aIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBFactory mozIndexedDB; */
NS_IMETHODIMP nsDOMStorageIndexedDB::GetMozIndexedDB(nsIIDBFactory * *aMozIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageIndexedDB_h__ */
