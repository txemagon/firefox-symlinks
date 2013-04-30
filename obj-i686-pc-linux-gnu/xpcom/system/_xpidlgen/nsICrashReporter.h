/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/system/nsICrashReporter.idl
 */

#ifndef __gen_nsICrashReporter_h__
#define __gen_nsICrashReporter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIURL; /* forward declaration */


/* starting interface:    nsICrashReporter */
#define NS_ICRASHREPORTER_IID_STR "56761088-57ad-4f5c-bd61-f678c2807fe0"

#define NS_ICRASHREPORTER_IID \
  {0x56761088, 0x57ad, 0x4f5c, \
    { 0xbd, 0x61, 0xf6, 0x78, 0xc2, 0x80, 0x7f, 0xe0 }}

class NS_NO_VTABLE nsICrashReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRASHREPORTER_IID)

  /* attribute boolean enabled; */
  NS_IMETHOD GetEnabled(bool *aEnabled) = 0;
  NS_IMETHOD SetEnabled(bool aEnabled) = 0;

  /* attribute nsIURL serverURL; */
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) = 0;
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) = 0;

  /* attribute nsIFile minidumpPath; */
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) = 0;
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) = 0;

  /* void annotateCrashReport (in ACString key, in ACString data); */
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) = 0;

  /* void appendAppNotesToCrashReport (in ACString data); */
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) = 0;

  /* void registerAppMemory (in unsigned long long ptr, in unsigned long long size); */
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) = 0;

  /* [noscript] void writeMinidumpForException (in voidPtr aExceptionInfo); */
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) = 0;

  /* [noscript] void appendObjCExceptionInfoToAppNotes (in voidPtr aException); */
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) = 0;

  /* attribute boolean submitReports; */
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) = 0;
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICrashReporter, NS_ICRASHREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRASHREPORTER \
  NS_IMETHOD GetEnabled(bool *aEnabled); \
  NS_IMETHOD SetEnabled(bool aEnabled); \
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL); \
  NS_IMETHOD SetServerURL(nsIURL *aServerURL); \
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath); \
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath); \
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data); \
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data); \
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size); \
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo); \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException); \
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports); \
  NS_IMETHOD SetSubmitReports(bool aSubmitReports); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRASHREPORTER(_to) \
  NS_IMETHOD GetEnabled(bool *aEnabled) { return _to GetEnabled(aEnabled); } \
  NS_IMETHOD SetEnabled(bool aEnabled) { return _to SetEnabled(aEnabled); } \
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) { return _to GetServerURL(aServerURL); } \
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) { return _to SetServerURL(aServerURL); } \
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) { return _to GetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) { return _to SetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) { return _to AnnotateCrashReport(key, data); } \
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) { return _to AppendAppNotesToCrashReport(data); } \
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) { return _to RegisterAppMemory(ptr, size); } \
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) { return _to WriteMinidumpForException(aExceptionInfo); } \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) { return _to AppendObjCExceptionInfoToAppNotes(aException); } \
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) { return _to GetSubmitReports(aSubmitReports); } \
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) { return _to SetSubmitReports(aSubmitReports); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRASHREPORTER(_to) \
  NS_IMETHOD GetEnabled(bool *aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabled(aEnabled); } \
  NS_IMETHOD SetEnabled(bool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnabled(aEnabled); } \
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerURL(aServerURL); } \
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServerURL(aServerURL); } \
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->AnnotateCrashReport(key, data); } \
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendAppNotesToCrashReport(data); } \
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterAppMemory(ptr, size); } \
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteMinidumpForException(aExceptionInfo); } \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendObjCExceptionInfoToAppNotes(aException); } \
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubmitReports(aSubmitReports); } \
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSubmitReports(aSubmitReports); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCrashReporter : public nsICrashReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRASHREPORTER

  nsCrashReporter();

private:
  ~nsCrashReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCrashReporter, nsICrashReporter)

nsCrashReporter::nsCrashReporter()
{
  /* member initializers and constructor code */
}

nsCrashReporter::~nsCrashReporter()
{
  /* destructor code */
}

/* attribute boolean enabled; */
NS_IMETHODIMP nsCrashReporter::GetEnabled(bool *aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetEnabled(bool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURL serverURL; */
NS_IMETHODIMP nsCrashReporter::GetServerURL(nsIURL * *aServerURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetServerURL(nsIURL *aServerURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFile minidumpPath; */
NS_IMETHODIMP nsCrashReporter::GetMinidumpPath(nsIFile * *aMinidumpPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetMinidumpPath(nsIFile *aMinidumpPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void annotateCrashReport (in ACString key, in ACString data); */
NS_IMETHODIMP nsCrashReporter::AnnotateCrashReport(const nsACString & key, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendAppNotesToCrashReport (in ACString data); */
NS_IMETHODIMP nsCrashReporter::AppendAppNotesToCrashReport(const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerAppMemory (in unsigned long long ptr, in unsigned long long size); */
NS_IMETHODIMP nsCrashReporter::RegisterAppMemory(uint64_t ptr, uint64_t size)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeMinidumpForException (in voidPtr aExceptionInfo); */
NS_IMETHODIMP nsCrashReporter::WriteMinidumpForException(void *aExceptionInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void appendObjCExceptionInfoToAppNotes (in voidPtr aException); */
NS_IMETHODIMP nsCrashReporter::AppendObjCExceptionInfoToAppNotes(void *aException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean submitReports; */
NS_IMETHODIMP nsCrashReporter::GetSubmitReports(bool *aSubmitReports)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetSubmitReports(bool aSubmitReports)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICrashReporter_h__ */
