/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/browser/components/migration/public/nsIBrowserProfileMigrator.idl
 */

#ifndef __gen_nsIBrowserProfileMigrator_h__
#define __gen_nsIBrowserProfileMigrator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIProfileStartup; /* forward declaration */


/* starting interface:    nsIBrowserProfileMigrator */
#define NS_IBROWSERPROFILEMIGRATOR_IID_STR "44993e0e-74e8-4bec-9d66-ad8156e0a274"

#define NS_IBROWSERPROFILEMIGRATOR_IID \
  {0x44993e0e, 0x74e8, 0x4bec, \
    { 0x9d, 0x66, 0xad, 0x81, 0x56, 0xe0, 0xa2, 0x74 }}

class NS_NO_VTABLE nsIBrowserProfileMigrator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERPROFILEMIGRATOR_IID)

  enum {
    ALL = 0U,
    SETTINGS = 1U,
    COOKIES = 2U,
    HISTORY = 4U,
    FORMDATA = 8U,
    PASSWORDS = 16U,
    BOOKMARKS = 32U,
    OTHERDATA = 64U
  };

  /* void migrate (in unsigned short aItems, in nsIProfileStartup aStartup, in wstring aProfile); */
  NS_IMETHOD Migrate(uint16_t aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile) = 0;

  /* unsigned short getMigrateData (in wstring aProfile, in boolean aDoingStartup); */
  NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, uint16_t *_retval) = 0;

  /* readonly attribute boolean sourceExists; */
  NS_IMETHOD GetSourceExists(bool *aSourceExists) = 0;

  /* readonly attribute jsval sourceProfiles; */
  NS_IMETHOD GetSourceProfiles(JS::Value *aSourceProfiles) = 0;

  /* readonly attribute AUTF8String sourceHomePageURL; */
  NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserProfileMigrator, NS_IBROWSERPROFILEMIGRATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERPROFILEMIGRATOR \
  NS_IMETHOD Migrate(uint16_t aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile); \
  NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, uint16_t *_retval); \
  NS_IMETHOD GetSourceExists(bool *aSourceExists); \
  NS_IMETHOD GetSourceProfiles(JS::Value *aSourceProfiles); \
  NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERPROFILEMIGRATOR(_to) \
  NS_IMETHOD Migrate(uint16_t aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile) { return _to Migrate(aItems, aStartup, aProfile); } \
  NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, uint16_t *_retval) { return _to GetMigrateData(aProfile, aDoingStartup, _retval); } \
  NS_IMETHOD GetSourceExists(bool *aSourceExists) { return _to GetSourceExists(aSourceExists); } \
  NS_IMETHOD GetSourceProfiles(JS::Value *aSourceProfiles) { return _to GetSourceProfiles(aSourceProfiles); } \
  NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL) { return _to GetSourceHomePageURL(aSourceHomePageURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERPROFILEMIGRATOR(_to) \
  NS_IMETHOD Migrate(uint16_t aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Migrate(aItems, aStartup, aProfile); } \
  NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, uint16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMigrateData(aProfile, aDoingStartup, _retval); } \
  NS_IMETHOD GetSourceExists(bool *aSourceExists) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceExists(aSourceExists); } \
  NS_IMETHOD GetSourceProfiles(JS::Value *aSourceProfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceProfiles(aSourceProfiles); } \
  NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceHomePageURL(aSourceHomePageURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserProfileMigrator : public nsIBrowserProfileMigrator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERPROFILEMIGRATOR

  nsBrowserProfileMigrator();

private:
  ~nsBrowserProfileMigrator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserProfileMigrator, nsIBrowserProfileMigrator)

nsBrowserProfileMigrator::nsBrowserProfileMigrator()
{
  /* member initializers and constructor code */
}

nsBrowserProfileMigrator::~nsBrowserProfileMigrator()
{
  /* destructor code */
}

/* void migrate (in unsigned short aItems, in nsIProfileStartup aStartup, in wstring aProfile); */
NS_IMETHODIMP nsBrowserProfileMigrator::Migrate(uint16_t aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short getMigrateData (in wstring aProfile, in boolean aDoingStartup); */
NS_IMETHODIMP nsBrowserProfileMigrator::GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean sourceExists; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceExists(bool *aSourceExists)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval sourceProfiles; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceProfiles(JS::Value *aSourceProfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String sourceHomePageURL; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceHomePageURL(nsACString & aSourceHomePageURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserProfileMigrator_h__ */
