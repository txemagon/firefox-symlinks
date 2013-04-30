/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/plugins/base/nsIPluginHost.idl
 */

#ifndef __gen_nsIPluginHost_h__
#define __gen_nsIPluginHost_h__


#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginTag_h__
#include "nsIPluginTag.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define MOZ_PLUGIN_HOST_CONTRACTID \
  "@mozilla.org/plugin/host;1"

/* starting interface:    nsIPluginHost */
#define NS_IPLUGINHOST_IID_STR "3ac8fe33-c38c-4123-b2f0-0e8a2824b9c5"

#define NS_IPLUGINHOST_IID \
  {0x3ac8fe33, 0xc38c, 0x4123, \
    { 0xb2, 0xf0, 0x0e, 0x8a, 0x28, 0x24, 0xb9, 0xc5 }}

class NS_NO_VTABLE nsIPluginHost : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINHOST_IID)

  /* void reloadPlugins (in boolean reloadPages); */
  NS_IMETHOD ReloadPlugins(bool reloadPages) = 0;

  /* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) = 0;

  enum {
    FLAG_CLEAR_ALL = 0U,
    FLAG_CLEAR_CACHE = 1U
  };

  /* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in uint64_t flags, in int64_t maxAge); */
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) = 0;

  /* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) = 0;

  /* void registerPlayPreviewMimeType (in AUTF8String mimeType); */
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType) = 0;

  /* void unregisterPlayPreviewMimeType (in AUTF8String mimeType); */
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) = 0;

  /* ACString getPermissionStringForType (in AUTF8String mimeType); */
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval) = 0;

  /* bool isPluginClickToPlayForType (in AUTF8String mimeType); */
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginHost, NS_IPLUGINHOST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINHOST \
  NS_IMETHOD ReloadPlugins(bool reloadPages); \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults); \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge); \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval); \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType); \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType); \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval); \
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINHOST(_to) \
  NS_IMETHOD ReloadPlugins(bool reloadPages) { return _to ReloadPlugins(reloadPages); } \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) { return _to GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) { return _to ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) { return _to SiteHasData(plugin, domain, _retval); } \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType) { return _to RegisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) { return _to UnregisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval) { return _to GetPermissionStringForType(mimeType, _retval); } \
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval) { return _to IsPluginClickToPlayForType(mimeType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINHOST(_to) \
  NS_IMETHOD ReloadPlugins(bool reloadPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadPlugins(reloadPages); } \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SiteHasData(plugin, domain, _retval); } \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermissionStringForType(mimeType, _retval); } \
  NS_IMETHOD IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPluginClickToPlayForType(mimeType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginHost : public nsIPluginHost
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINHOST

  nsPluginHost();

private:
  ~nsPluginHost();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginHost, nsIPluginHost)

nsPluginHost::nsPluginHost()
{
  /* member initializers and constructor code */
}

nsPluginHost::~nsPluginHost()
{
  /* destructor code */
}

/* void reloadPlugins (in boolean reloadPages); */
NS_IMETHODIMP nsPluginHost::ReloadPlugins(bool reloadPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
NS_IMETHODIMP nsPluginHost::GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in uint64_t flags, in int64_t maxAge); */
NS_IMETHODIMP nsPluginHost::ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
NS_IMETHODIMP nsPluginHost::SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPlayPreviewMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::RegisterPlayPreviewMimeType(const nsACString & mimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterPlayPreviewMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::UnregisterPlayPreviewMimeType(const nsACString & mimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getPermissionStringForType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::GetPermissionStringForType(const nsACString & mimeType, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isPluginClickToPlayForType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::IsPluginClickToPlayForType(const nsACString & mimeType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginHost_h__ */
