/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/js/xpconnect/tests/idl/xpctest_params.idl
 */

#ifndef __gen_xpctest_params_h__
#define __gen_xpctest_params_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXPCTestInterfaceA; /* forward declaration */

class nsIXPCTestInterfaceB; /* forward declaration */


/* starting interface:    nsIXPCTestParams */
#define NS_IXPCTESTPARAMS_IID_STR "fe2b7433-ac3b-49ef-9344-b67228bfdd46"

#define NS_IXPCTESTPARAMS_IID \
  {0xfe2b7433, 0xac3b, 0x49ef, \
    { 0x93, 0x44, 0xb6, 0x72, 0x28, 0xbf, 0xdd, 0x46 }}

class NS_NO_VTABLE nsIXPCTestParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCTESTPARAMS_IID)

  /* boolean testBoolean (in boolean a, inout boolean b); */
  NS_IMETHOD TestBoolean(bool a, bool *b, bool *_retval) = 0;

  /* octet testOctet (in octet a, inout octet b); */
  NS_IMETHOD TestOctet(uint8_t a, uint8_t *b, uint8_t *_retval) = 0;

  /* short testShort (in short a, inout short b); */
  NS_IMETHOD TestShort(int16_t a, int16_t *b, int16_t *_retval) = 0;

  /* long testLong (in long a, inout long b); */
  NS_IMETHOD TestLong(int32_t a, int32_t *b, int32_t *_retval) = 0;

  /* long long testLongLong (in long long a, inout long long b); */
  NS_IMETHOD TestLongLong(int64_t a, int64_t *b, int64_t *_retval) = 0;

  /* unsigned short testUnsignedShort (in unsigned short a, inout unsigned short b); */
  NS_IMETHOD TestUnsignedShort(uint16_t a, uint16_t *b, uint16_t *_retval) = 0;

  /* unsigned long testUnsignedLong (in unsigned long a, inout unsigned long b); */
  NS_IMETHOD TestUnsignedLong(uint32_t a, uint32_t *b, uint32_t *_retval) = 0;

  /* unsigned long long testUnsignedLongLong (in unsigned long long a, inout unsigned long long b); */
  NS_IMETHOD TestUnsignedLongLong(uint64_t a, uint64_t *b, uint64_t *_retval) = 0;

  /* float testFloat (in float a, inout float b); */
  NS_IMETHOD TestFloat(float a, float *b, float *_retval) = 0;

  /* double testDouble (in double a, inout float b); */
  NS_IMETHOD TestDouble(double a, float *b, double *_retval) = 0;

  /* char testChar (in char a, inout char b); */
  NS_IMETHOD TestChar(char a, char *b, char *_retval) = 0;

  /* string testString (in string a, inout string b); */
  NS_IMETHOD TestString(const char * a, char * *b, char * *_retval) = 0;

  /* wchar testWchar (in wchar a, inout wchar b); */
  NS_IMETHOD TestWchar(PRUnichar a, PRUnichar *b, PRUnichar *_retval) = 0;

  /* wstring testWstring (in wstring a, inout wstring b); */
  NS_IMETHOD TestWstring(const PRUnichar * a, PRUnichar * *b, PRUnichar * *_retval) = 0;

  /* DOMString testDOMString (in DOMString a, inout DOMString b); */
  NS_IMETHOD TestDOMString(const nsAString & a, nsAString & b, nsAString & _retval) = 0;

  /* AString testAString (in AString a, inout AString b); */
  NS_IMETHOD TestAString(const nsAString & a, nsAString & b, nsAString & _retval) = 0;

  /* AUTF8String testAUTF8String (in AUTF8String a, inout AUTF8String b); */
  NS_IMETHOD TestAUTF8String(const nsACString & a, nsACString & b, nsACString & _retval) = 0;

  /* ACString testACString (in ACString a, inout ACString b); */
  NS_IMETHOD TestACString(const nsACString & a, nsACString & b, nsACString & _retval) = 0;

  /* jsval testJsval (in jsval a, inout jsval b); */
  NS_IMETHOD TestJsval(const JS::Value & a, JS::Value & b, JS::Value *_retval) = 0;

  /* void testShortArray (in unsigned long aLength, [array, size_is (aLength)] in short a, inout unsigned long bLength, [array, size_is (bLength)] inout short b, out unsigned long rvLength, [array, size_is (rvLength), retval] out short rv); */
  NS_IMETHOD TestShortArray(uint32_t aLength, int16_t *a, uint32_t *bLength, int16_t **b, uint32_t *rvLength, int16_t **rv) = 0;

  /* void testDoubleArray (in unsigned long aLength, [array, size_is (aLength)] in double a, inout unsigned long bLength, [array, size_is (bLength)] inout double b, out unsigned long rvLength, [array, size_is (rvLength), retval] out double rv); */
  NS_IMETHOD TestDoubleArray(uint32_t aLength, double *a, uint32_t *bLength, double **b, uint32_t *rvLength, double **rv) = 0;

  /* void testStringArray (in unsigned long aLength, [array, size_is (aLength)] in string a, inout unsigned long bLength, [array, size_is (bLength)] inout string b, out unsigned long rvLength, [array, size_is (rvLength), retval] out string rv); */
  NS_IMETHOD TestStringArray(uint32_t aLength, const char * *a, uint32_t *bLength, char * **b, uint32_t *rvLength, char * **rv) = 0;

  /* void testWstringArray (in unsigned long aLength, [array, size_is (aLength)] in wstring a, inout unsigned long bLength, [array, size_is (bLength)] inout wstring b, out unsigned long rvLength, [array, size_is (rvLength), retval] out wstring rv); */
  NS_IMETHOD TestWstringArray(uint32_t aLength, const PRUnichar * *a, uint32_t *bLength, PRUnichar * **b, uint32_t *rvLength, PRUnichar * **rv) = 0;

  /* void testInterfaceArray (in unsigned long aLength, [array, size_is (aLength)] in nsIXPCTestInterfaceA a, inout unsigned long bLength, [array, size_is (bLength)] inout nsIXPCTestInterfaceA b, out unsigned long rvLength, [array, size_is (rvLength), retval] out nsIXPCTestInterfaceA rv); */
  NS_IMETHOD TestInterfaceArray(uint32_t aLength, nsIXPCTestInterfaceA **a, uint32_t *bLength, nsIXPCTestInterfaceA * **b, uint32_t *rvLength, nsIXPCTestInterfaceA * **rv) = 0;

  /* void testSizedString (in unsigned long aLength, [size_is (aLength)] in string a, inout unsigned long bLength, [size_is (bLength)] inout string b, out unsigned long rvLength, [size_is (rvLength), retval] out string rv); */
  NS_IMETHOD TestSizedString(uint32_t aLength, const char * a, uint32_t *bLength, char * *b, uint32_t *rvLength, char * *rv) = 0;

  /* void testSizedWstring (in unsigned long aLength, [size_is (aLength)] in wstring a, inout unsigned long bLength, [size_is (bLength)] inout wstring b, out unsigned long rvLength, [size_is (rvLength), retval] out wstring rv); */
  NS_IMETHOD TestSizedWstring(uint32_t aLength, const PRUnichar * a, uint32_t *bLength, PRUnichar * *b, uint32_t *rvLength, PRUnichar * *rv) = 0;

  /* void testInterfaceIs (in nsIIDPtr aIID, [iid_is (aIID)] in nsQIResult a, inout nsIIDPtr bIID, [iid_is (bIID)] inout nsQIResult b, out nsIIDPtr rvIID, [iid_is (rvIID), retval] out nsQIResult rv); */
  NS_IMETHOD TestInterfaceIs(const nsIID *aIID, void *a, nsIID **bIID, void **b, nsIID **rvIID, void **rv) = 0;

  /* void testInterfaceIsArray (in unsigned long aLength, in nsIIDPtr aIID, [array, size_is (aLength), iid_is (aIID)] in nsQIResult a, inout unsigned long bLength, inout nsIIDPtr bIID, [array, size_is (bLength), iid_is (bIID)] inout nsQIResult b, out unsigned long rvLength, out nsIIDPtr rvIID, [retval, array, size_is (rvLength), iid_is (rvIID)] out nsQIResult rv); */
  NS_IMETHOD TestInterfaceIsArray(uint32_t aLength, const nsIID *aIID, void **a, uint32_t *bLength, nsIID **bIID, void ***b, uint32_t *rvLength, nsIID **rvIID, void ***rv) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCTestParams, NS_IXPCTESTPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCTESTPARAMS \
  NS_IMETHOD TestBoolean(bool a, bool *b, bool *_retval); \
  NS_IMETHOD TestOctet(uint8_t a, uint8_t *b, uint8_t *_retval); \
  NS_IMETHOD TestShort(int16_t a, int16_t *b, int16_t *_retval); \
  NS_IMETHOD TestLong(int32_t a, int32_t *b, int32_t *_retval); \
  NS_IMETHOD TestLongLong(int64_t a, int64_t *b, int64_t *_retval); \
  NS_IMETHOD TestUnsignedShort(uint16_t a, uint16_t *b, uint16_t *_retval); \
  NS_IMETHOD TestUnsignedLong(uint32_t a, uint32_t *b, uint32_t *_retval); \
  NS_IMETHOD TestUnsignedLongLong(uint64_t a, uint64_t *b, uint64_t *_retval); \
  NS_IMETHOD TestFloat(float a, float *b, float *_retval); \
  NS_IMETHOD TestDouble(double a, float *b, double *_retval); \
  NS_IMETHOD TestChar(char a, char *b, char *_retval); \
  NS_IMETHOD TestString(const char * a, char * *b, char * *_retval); \
  NS_IMETHOD TestWchar(PRUnichar a, PRUnichar *b, PRUnichar *_retval); \
  NS_IMETHOD TestWstring(const PRUnichar * a, PRUnichar * *b, PRUnichar * *_retval); \
  NS_IMETHOD TestDOMString(const nsAString & a, nsAString & b, nsAString & _retval); \
  NS_IMETHOD TestAString(const nsAString & a, nsAString & b, nsAString & _retval); \
  NS_IMETHOD TestAUTF8String(const nsACString & a, nsACString & b, nsACString & _retval); \
  NS_IMETHOD TestACString(const nsACString & a, nsACString & b, nsACString & _retval); \
  NS_IMETHOD TestJsval(const JS::Value & a, JS::Value & b, JS::Value *_retval); \
  NS_IMETHOD TestShortArray(uint32_t aLength, int16_t *a, uint32_t *bLength, int16_t **b, uint32_t *rvLength, int16_t **rv); \
  NS_IMETHOD TestDoubleArray(uint32_t aLength, double *a, uint32_t *bLength, double **b, uint32_t *rvLength, double **rv); \
  NS_IMETHOD TestStringArray(uint32_t aLength, const char * *a, uint32_t *bLength, char * **b, uint32_t *rvLength, char * **rv); \
  NS_IMETHOD TestWstringArray(uint32_t aLength, const PRUnichar * *a, uint32_t *bLength, PRUnichar * **b, uint32_t *rvLength, PRUnichar * **rv); \
  NS_IMETHOD TestInterfaceArray(uint32_t aLength, nsIXPCTestInterfaceA **a, uint32_t *bLength, nsIXPCTestInterfaceA * **b, uint32_t *rvLength, nsIXPCTestInterfaceA * **rv); \
  NS_IMETHOD TestSizedString(uint32_t aLength, const char * a, uint32_t *bLength, char * *b, uint32_t *rvLength, char * *rv); \
  NS_IMETHOD TestSizedWstring(uint32_t aLength, const PRUnichar * a, uint32_t *bLength, PRUnichar * *b, uint32_t *rvLength, PRUnichar * *rv); \
  NS_IMETHOD TestInterfaceIs(const nsIID *aIID, void *a, nsIID **bIID, void **b, nsIID **rvIID, void **rv); \
  NS_IMETHOD TestInterfaceIsArray(uint32_t aLength, const nsIID *aIID, void **a, uint32_t *bLength, nsIID **bIID, void ***b, uint32_t *rvLength, nsIID **rvIID, void ***rv); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCTESTPARAMS(_to) \
  NS_IMETHOD TestBoolean(bool a, bool *b, bool *_retval) { return _to TestBoolean(a, b, _retval); } \
  NS_IMETHOD TestOctet(uint8_t a, uint8_t *b, uint8_t *_retval) { return _to TestOctet(a, b, _retval); } \
  NS_IMETHOD TestShort(int16_t a, int16_t *b, int16_t *_retval) { return _to TestShort(a, b, _retval); } \
  NS_IMETHOD TestLong(int32_t a, int32_t *b, int32_t *_retval) { return _to TestLong(a, b, _retval); } \
  NS_IMETHOD TestLongLong(int64_t a, int64_t *b, int64_t *_retval) { return _to TestLongLong(a, b, _retval); } \
  NS_IMETHOD TestUnsignedShort(uint16_t a, uint16_t *b, uint16_t *_retval) { return _to TestUnsignedShort(a, b, _retval); } \
  NS_IMETHOD TestUnsignedLong(uint32_t a, uint32_t *b, uint32_t *_retval) { return _to TestUnsignedLong(a, b, _retval); } \
  NS_IMETHOD TestUnsignedLongLong(uint64_t a, uint64_t *b, uint64_t *_retval) { return _to TestUnsignedLongLong(a, b, _retval); } \
  NS_IMETHOD TestFloat(float a, float *b, float *_retval) { return _to TestFloat(a, b, _retval); } \
  NS_IMETHOD TestDouble(double a, float *b, double *_retval) { return _to TestDouble(a, b, _retval); } \
  NS_IMETHOD TestChar(char a, char *b, char *_retval) { return _to TestChar(a, b, _retval); } \
  NS_IMETHOD TestString(const char * a, char * *b, char * *_retval) { return _to TestString(a, b, _retval); } \
  NS_IMETHOD TestWchar(PRUnichar a, PRUnichar *b, PRUnichar *_retval) { return _to TestWchar(a, b, _retval); } \
  NS_IMETHOD TestWstring(const PRUnichar * a, PRUnichar * *b, PRUnichar * *_retval) { return _to TestWstring(a, b, _retval); } \
  NS_IMETHOD TestDOMString(const nsAString & a, nsAString & b, nsAString & _retval) { return _to TestDOMString(a, b, _retval); } \
  NS_IMETHOD TestAString(const nsAString & a, nsAString & b, nsAString & _retval) { return _to TestAString(a, b, _retval); } \
  NS_IMETHOD TestAUTF8String(const nsACString & a, nsACString & b, nsACString & _retval) { return _to TestAUTF8String(a, b, _retval); } \
  NS_IMETHOD TestACString(const nsACString & a, nsACString & b, nsACString & _retval) { return _to TestACString(a, b, _retval); } \
  NS_IMETHOD TestJsval(const JS::Value & a, JS::Value & b, JS::Value *_retval) { return _to TestJsval(a, b, _retval); } \
  NS_IMETHOD TestShortArray(uint32_t aLength, int16_t *a, uint32_t *bLength, int16_t **b, uint32_t *rvLength, int16_t **rv) { return _to TestShortArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestDoubleArray(uint32_t aLength, double *a, uint32_t *bLength, double **b, uint32_t *rvLength, double **rv) { return _to TestDoubleArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestStringArray(uint32_t aLength, const char * *a, uint32_t *bLength, char * **b, uint32_t *rvLength, char * **rv) { return _to TestStringArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestWstringArray(uint32_t aLength, const PRUnichar * *a, uint32_t *bLength, PRUnichar * **b, uint32_t *rvLength, PRUnichar * **rv) { return _to TestWstringArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestInterfaceArray(uint32_t aLength, nsIXPCTestInterfaceA **a, uint32_t *bLength, nsIXPCTestInterfaceA * **b, uint32_t *rvLength, nsIXPCTestInterfaceA * **rv) { return _to TestInterfaceArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestSizedString(uint32_t aLength, const char * a, uint32_t *bLength, char * *b, uint32_t *rvLength, char * *rv) { return _to TestSizedString(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestSizedWstring(uint32_t aLength, const PRUnichar * a, uint32_t *bLength, PRUnichar * *b, uint32_t *rvLength, PRUnichar * *rv) { return _to TestSizedWstring(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestInterfaceIs(const nsIID *aIID, void *a, nsIID **bIID, void **b, nsIID **rvIID, void **rv) { return _to TestInterfaceIs(aIID, a, bIID, b, rvIID, rv); } \
  NS_IMETHOD TestInterfaceIsArray(uint32_t aLength, const nsIID *aIID, void **a, uint32_t *bLength, nsIID **bIID, void ***b, uint32_t *rvLength, nsIID **rvIID, void ***rv) { return _to TestInterfaceIsArray(aLength, aIID, a, bLength, bIID, b, rvLength, rvIID, rv); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCTESTPARAMS(_to) \
  NS_IMETHOD TestBoolean(bool a, bool *b, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestBoolean(a, b, _retval); } \
  NS_IMETHOD TestOctet(uint8_t a, uint8_t *b, uint8_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestOctet(a, b, _retval); } \
  NS_IMETHOD TestShort(int16_t a, int16_t *b, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestShort(a, b, _retval); } \
  NS_IMETHOD TestLong(int32_t a, int32_t *b, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestLong(a, b, _retval); } \
  NS_IMETHOD TestLongLong(int64_t a, int64_t *b, int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestLongLong(a, b, _retval); } \
  NS_IMETHOD TestUnsignedShort(uint16_t a, uint16_t *b, uint16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestUnsignedShort(a, b, _retval); } \
  NS_IMETHOD TestUnsignedLong(uint32_t a, uint32_t *b, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestUnsignedLong(a, b, _retval); } \
  NS_IMETHOD TestUnsignedLongLong(uint64_t a, uint64_t *b, uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestUnsignedLongLong(a, b, _retval); } \
  NS_IMETHOD TestFloat(float a, float *b, float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestFloat(a, b, _retval); } \
  NS_IMETHOD TestDouble(double a, float *b, double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestDouble(a, b, _retval); } \
  NS_IMETHOD TestChar(char a, char *b, char *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestChar(a, b, _retval); } \
  NS_IMETHOD TestString(const char * a, char * *b, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestString(a, b, _retval); } \
  NS_IMETHOD TestWchar(PRUnichar a, PRUnichar *b, PRUnichar *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestWchar(a, b, _retval); } \
  NS_IMETHOD TestWstring(const PRUnichar * a, PRUnichar * *b, PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestWstring(a, b, _retval); } \
  NS_IMETHOD TestDOMString(const nsAString & a, nsAString & b, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestDOMString(a, b, _retval); } \
  NS_IMETHOD TestAString(const nsAString & a, nsAString & b, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestAString(a, b, _retval); } \
  NS_IMETHOD TestAUTF8String(const nsACString & a, nsACString & b, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestAUTF8String(a, b, _retval); } \
  NS_IMETHOD TestACString(const nsACString & a, nsACString & b, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestACString(a, b, _retval); } \
  NS_IMETHOD TestJsval(const JS::Value & a, JS::Value & b, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestJsval(a, b, _retval); } \
  NS_IMETHOD TestShortArray(uint32_t aLength, int16_t *a, uint32_t *bLength, int16_t **b, uint32_t *rvLength, int16_t **rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestShortArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestDoubleArray(uint32_t aLength, double *a, uint32_t *bLength, double **b, uint32_t *rvLength, double **rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestDoubleArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestStringArray(uint32_t aLength, const char * *a, uint32_t *bLength, char * **b, uint32_t *rvLength, char * **rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestStringArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestWstringArray(uint32_t aLength, const PRUnichar * *a, uint32_t *bLength, PRUnichar * **b, uint32_t *rvLength, PRUnichar * **rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestWstringArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestInterfaceArray(uint32_t aLength, nsIXPCTestInterfaceA **a, uint32_t *bLength, nsIXPCTestInterfaceA * **b, uint32_t *rvLength, nsIXPCTestInterfaceA * **rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestInterfaceArray(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestSizedString(uint32_t aLength, const char * a, uint32_t *bLength, char * *b, uint32_t *rvLength, char * *rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestSizedString(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestSizedWstring(uint32_t aLength, const PRUnichar * a, uint32_t *bLength, PRUnichar * *b, uint32_t *rvLength, PRUnichar * *rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestSizedWstring(aLength, a, bLength, b, rvLength, rv); } \
  NS_IMETHOD TestInterfaceIs(const nsIID *aIID, void *a, nsIID **bIID, void **b, nsIID **rvIID, void **rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestInterfaceIs(aIID, a, bIID, b, rvIID, rv); } \
  NS_IMETHOD TestInterfaceIsArray(uint32_t aLength, const nsIID *aIID, void **a, uint32_t *bLength, nsIID **bIID, void ***b, uint32_t *rvLength, nsIID **rvIID, void ***rv) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestInterfaceIsArray(aLength, aIID, a, bLength, bIID, b, rvLength, rvIID, rv); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCTestParams : public nsIXPCTestParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCTESTPARAMS

  nsXPCTestParams();

private:
  ~nsXPCTestParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCTestParams, nsIXPCTestParams)

nsXPCTestParams::nsXPCTestParams()
{
  /* member initializers and constructor code */
}

nsXPCTestParams::~nsXPCTestParams()
{
  /* destructor code */
}

/* boolean testBoolean (in boolean a, inout boolean b); */
NS_IMETHODIMP nsXPCTestParams::TestBoolean(bool a, bool *b, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* octet testOctet (in octet a, inout octet b); */
NS_IMETHODIMP nsXPCTestParams::TestOctet(uint8_t a, uint8_t *b, uint8_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short testShort (in short a, inout short b); */
NS_IMETHODIMP nsXPCTestParams::TestShort(int16_t a, int16_t *b, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long testLong (in long a, inout long b); */
NS_IMETHODIMP nsXPCTestParams::TestLong(int32_t a, int32_t *b, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long testLongLong (in long long a, inout long long b); */
NS_IMETHODIMP nsXPCTestParams::TestLongLong(int64_t a, int64_t *b, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short testUnsignedShort (in unsigned short a, inout unsigned short b); */
NS_IMETHODIMP nsXPCTestParams::TestUnsignedShort(uint16_t a, uint16_t *b, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long testUnsignedLong (in unsigned long a, inout unsigned long b); */
NS_IMETHODIMP nsXPCTestParams::TestUnsignedLong(uint32_t a, uint32_t *b, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long testUnsignedLongLong (in unsigned long long a, inout unsigned long long b); */
NS_IMETHODIMP nsXPCTestParams::TestUnsignedLongLong(uint64_t a, uint64_t *b, uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float testFloat (in float a, inout float b); */
NS_IMETHODIMP nsXPCTestParams::TestFloat(float a, float *b, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double testDouble (in double a, inout float b); */
NS_IMETHODIMP nsXPCTestParams::TestDouble(double a, float *b, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* char testChar (in char a, inout char b); */
NS_IMETHODIMP nsXPCTestParams::TestChar(char a, char *b, char *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string testString (in string a, inout string b); */
NS_IMETHODIMP nsXPCTestParams::TestString(const char * a, char * *b, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wchar testWchar (in wchar a, inout wchar b); */
NS_IMETHODIMP nsXPCTestParams::TestWchar(PRUnichar a, PRUnichar *b, PRUnichar *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring testWstring (in wstring a, inout wstring b); */
NS_IMETHODIMP nsXPCTestParams::TestWstring(const PRUnichar * a, PRUnichar * *b, PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString testDOMString (in DOMString a, inout DOMString b); */
NS_IMETHODIMP nsXPCTestParams::TestDOMString(const nsAString & a, nsAString & b, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString testAString (in AString a, inout AString b); */
NS_IMETHODIMP nsXPCTestParams::TestAString(const nsAString & a, nsAString & b, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String testAUTF8String (in AUTF8String a, inout AUTF8String b); */
NS_IMETHODIMP nsXPCTestParams::TestAUTF8String(const nsACString & a, nsACString & b, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString testACString (in ACString a, inout ACString b); */
NS_IMETHODIMP nsXPCTestParams::TestACString(const nsACString & a, nsACString & b, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval testJsval (in jsval a, inout jsval b); */
NS_IMETHODIMP nsXPCTestParams::TestJsval(const JS::Value & a, JS::Value & b, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testShortArray (in unsigned long aLength, [array, size_is (aLength)] in short a, inout unsigned long bLength, [array, size_is (bLength)] inout short b, out unsigned long rvLength, [array, size_is (rvLength), retval] out short rv); */
NS_IMETHODIMP nsXPCTestParams::TestShortArray(uint32_t aLength, int16_t *a, uint32_t *bLength, int16_t **b, uint32_t *rvLength, int16_t **rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testDoubleArray (in unsigned long aLength, [array, size_is (aLength)] in double a, inout unsigned long bLength, [array, size_is (bLength)] inout double b, out unsigned long rvLength, [array, size_is (rvLength), retval] out double rv); */
NS_IMETHODIMP nsXPCTestParams::TestDoubleArray(uint32_t aLength, double *a, uint32_t *bLength, double **b, uint32_t *rvLength, double **rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testStringArray (in unsigned long aLength, [array, size_is (aLength)] in string a, inout unsigned long bLength, [array, size_is (bLength)] inout string b, out unsigned long rvLength, [array, size_is (rvLength), retval] out string rv); */
NS_IMETHODIMP nsXPCTestParams::TestStringArray(uint32_t aLength, const char * *a, uint32_t *bLength, char * **b, uint32_t *rvLength, char * **rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testWstringArray (in unsigned long aLength, [array, size_is (aLength)] in wstring a, inout unsigned long bLength, [array, size_is (bLength)] inout wstring b, out unsigned long rvLength, [array, size_is (rvLength), retval] out wstring rv); */
NS_IMETHODIMP nsXPCTestParams::TestWstringArray(uint32_t aLength, const PRUnichar * *a, uint32_t *bLength, PRUnichar * **b, uint32_t *rvLength, PRUnichar * **rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testInterfaceArray (in unsigned long aLength, [array, size_is (aLength)] in nsIXPCTestInterfaceA a, inout unsigned long bLength, [array, size_is (bLength)] inout nsIXPCTestInterfaceA b, out unsigned long rvLength, [array, size_is (rvLength), retval] out nsIXPCTestInterfaceA rv); */
NS_IMETHODIMP nsXPCTestParams::TestInterfaceArray(uint32_t aLength, nsIXPCTestInterfaceA **a, uint32_t *bLength, nsIXPCTestInterfaceA * **b, uint32_t *rvLength, nsIXPCTestInterfaceA * **rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testSizedString (in unsigned long aLength, [size_is (aLength)] in string a, inout unsigned long bLength, [size_is (bLength)] inout string b, out unsigned long rvLength, [size_is (rvLength), retval] out string rv); */
NS_IMETHODIMP nsXPCTestParams::TestSizedString(uint32_t aLength, const char * a, uint32_t *bLength, char * *b, uint32_t *rvLength, char * *rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testSizedWstring (in unsigned long aLength, [size_is (aLength)] in wstring a, inout unsigned long bLength, [size_is (bLength)] inout wstring b, out unsigned long rvLength, [size_is (rvLength), retval] out wstring rv); */
NS_IMETHODIMP nsXPCTestParams::TestSizedWstring(uint32_t aLength, const PRUnichar * a, uint32_t *bLength, PRUnichar * *b, uint32_t *rvLength, PRUnichar * *rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testInterfaceIs (in nsIIDPtr aIID, [iid_is (aIID)] in nsQIResult a, inout nsIIDPtr bIID, [iid_is (bIID)] inout nsQIResult b, out nsIIDPtr rvIID, [iid_is (rvIID), retval] out nsQIResult rv); */
NS_IMETHODIMP nsXPCTestParams::TestInterfaceIs(const nsIID *aIID, void *a, nsIID **bIID, void **b, nsIID **rvIID, void **rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testInterfaceIsArray (in unsigned long aLength, in nsIIDPtr aIID, [array, size_is (aLength), iid_is (aIID)] in nsQIResult a, inout unsigned long bLength, inout nsIIDPtr bIID, [array, size_is (bLength), iid_is (bIID)] inout nsQIResult b, out unsigned long rvLength, out nsIIDPtr rvIID, [retval, array, size_is (rvLength), iid_is (rvIID)] out nsQIResult rv); */
NS_IMETHODIMP nsXPCTestParams::TestInterfaceIsArray(uint32_t aLength, const nsIID *aIID, void **a, uint32_t *bLength, nsIID **bIID, void ***b, uint32_t *rvLength, nsIID **rvIID, void ***rv)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpctest_params_h__ */
