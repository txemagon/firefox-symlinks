/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/widget/nsIPrintOptions.idl
 */

#ifndef __gen_nsIPrintOptions_h__
#define __gen_nsIPrintOptions_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrintSettings_h__
#include "nsIPrintSettings.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct nsFont;
class nsIStringEnumerator; /* forward declaration */


/* starting interface:    nsIPrintOptions */
#define NS_IPRINTOPTIONS_IID_STR "92597c2b-109b-40bb-8f93-9b9acfa31de8"

#define NS_IPRINTOPTIONS_IID \
  {0x92597c2b, 0x109b, 0x40bb, \
    { 0x8f, 0x93, 0x9b, 0x9a, 0xcf, 0xa3, 0x1d, 0xe8 }}

class NS_NO_VTABLE nsIPrintOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTOPTIONS_IID)

  /* void ShowPrintSetupDialog (in nsIPrintSettings aThePrintSettings); */
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) = 0;

  /* nsIPrintSettings CreatePrintSettings (); */
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) = 0;

  /* int32_t getPrinterPrefInt (in nsIPrintSettings aPrintSettings, in wstring aPrefName); */
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const PRUnichar * aPrefName, int32_t *_retval) = 0;

  /* void displayJobProperties (in wstring aPrinter, in nsIPrintSettings aPrintSettings, out boolean aDisplayed); */
  NS_IMETHOD DisplayJobProperties(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) = 0;

  enum {
    kNativeDataPrintRecord = 0
  };

  /* [noscript] voidPtr GetNativeData (in short aDataType); */
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintOptions, NS_IPRINTOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTOPTIONS \
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings); \
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval); \
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const PRUnichar * aPrefName, int32_t *_retval); \
  NS_IMETHOD DisplayJobProperties(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed); \
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTOPTIONS(_to) \
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) { return _to ShowPrintSetupDialog(aThePrintSettings); } \
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) { return _to CreatePrintSettings(_retval); } \
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const PRUnichar * aPrefName, int32_t *_retval) { return _to GetPrinterPrefInt(aPrintSettings, aPrefName, _retval); } \
  NS_IMETHOD DisplayJobProperties(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) { return _to DisplayJobProperties(aPrinter, aPrintSettings, aDisplayed); } \
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) { return _to GetNativeData(aDataType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTOPTIONS(_to) \
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrintSetupDialog(aThePrintSettings); } \
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreatePrintSettings(_retval); } \
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const PRUnichar * aPrefName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrinterPrefInt(aPrintSettings, aPrefName, _retval); } \
  NS_IMETHOD DisplayJobProperties(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayJobProperties(aPrinter, aPrintSettings, aDisplayed); } \
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeData(aDataType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintOptions : public nsIPrintOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTOPTIONS

  nsPrintOptions();

private:
  ~nsPrintOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintOptions, nsIPrintOptions)

nsPrintOptions::nsPrintOptions()
{
  /* member initializers and constructor code */
}

nsPrintOptions::~nsPrintOptions()
{
  /* destructor code */
}

/* void ShowPrintSetupDialog (in nsIPrintSettings aThePrintSettings); */
NS_IMETHODIMP nsPrintOptions::ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrintSettings CreatePrintSettings (); */
NS_IMETHODIMP nsPrintOptions::CreatePrintSettings(nsIPrintSettings * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t getPrinterPrefInt (in nsIPrintSettings aPrintSettings, in wstring aPrefName); */
NS_IMETHODIMP nsPrintOptions::GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const PRUnichar * aPrefName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void displayJobProperties (in wstring aPrinter, in nsIPrintSettings aPrintSettings, out boolean aDisplayed); */
NS_IMETHODIMP nsPrintOptions::DisplayJobProperties(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] voidPtr GetNativeData (in short aDataType); */
NS_IMETHODIMP nsPrintOptions::GetNativeData(int16_t aDataType, void **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPrinterEnumerator */
#define NS_IPRINTERENUMERATOR_IID_STR "5e738fff-404c-4c94-9189-e8f2cce93e94"

#define NS_IPRINTERENUMERATOR_IID \
  {0x5e738fff, 0x404c, 0x4c94, \
    { 0x91, 0x89, 0xe8, 0xf2, 0xcc, 0xe9, 0x3e, 0x94 }}

class NS_NO_VTABLE nsIPrinterEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTERENUMERATOR_IID)

  /* readonly attribute wstring defaultPrinterName; */
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) = 0;

  /* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings) = 0;

  /* readonly attribute nsIStringEnumerator printerNameList; */
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) = 0;

  /* void displayPropertiesDlg (in wstring aPrinter, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD DisplayPropertiesDlg(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrinterEnumerator, NS_IPRINTERENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTERENUMERATOR \
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName); \
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings); \
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList); \
  NS_IMETHOD DisplayPropertiesDlg(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTERENUMERATOR(_to) \
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) { return _to GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings) { return _to InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) { return _to GetPrinterNameList(aPrinterNameList); } \
  NS_IMETHOD DisplayPropertiesDlg(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings) { return _to DisplayPropertiesDlg(aPrinter, aPrintSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTERENUMERATOR(_to) \
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrinterNameList(aPrinterNameList); } \
  NS_IMETHOD DisplayPropertiesDlg(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayPropertiesDlg(aPrinter, aPrintSettings); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrinterEnumerator : public nsIPrinterEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTERENUMERATOR

  nsPrinterEnumerator();

private:
  ~nsPrinterEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrinterEnumerator, nsIPrinterEnumerator)

nsPrinterEnumerator::nsPrinterEnumerator()
{
  /* member initializers and constructor code */
}

nsPrinterEnumerator::~nsPrinterEnumerator()
{
  /* destructor code */
}

/* readonly attribute wstring defaultPrinterName; */
NS_IMETHODIMP nsPrinterEnumerator::GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrinterEnumerator::InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStringEnumerator printerNameList; */
NS_IMETHODIMP nsPrinterEnumerator::GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void displayPropertiesDlg (in wstring aPrinter, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrinterEnumerator::DisplayPropertiesDlg(const PRUnichar * aPrinter, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintOptions_h__ */
