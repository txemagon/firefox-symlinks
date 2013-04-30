/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/xpcom/ds/nsIAtom.idl
 */

#ifndef __gen_nsIAtom_h__
#define __gen_nsIAtom_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsStringGlue.h"
#include "nsCOMPtr.h"
#include "nsStringBuffer.h"

/* starting interface:    nsIAtom */
#define NS_IATOM_IID_STR "1f341018-521a-49de-b806-1bef5c9a00b0"

#define NS_IATOM_IID \
  {0x1f341018, 0x521a, 0x49de, \
    { 0xb8, 0x06, 0x1b, 0xef, 0x5c, 0x9a, 0x00, 0xb0 }}

class nsIAtom : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IATOM_IID)

  /* [binaryname(ScriptableToString)] AString toString (); */
  NS_IMETHOD ScriptableToString(nsAString & _retval) = 0;

  /* [noscript] AUTF8String toUTF8String (); */
  NS_IMETHOD ToUTF8String(nsACString & _retval) = 0;

  /* [binaryname(ScriptableEquals)] boolean equals (in AString aString); */
  NS_IMETHOD ScriptableEquals(const nsAString & aString, bool *_retval) = 0;

  /* [noscript,notxpcom] boolean equalsUTF8 (in AUTF8String aString); */
  NS_IMETHOD_(bool) EqualsUTF8(const nsACString & aString) = 0;

  /* [noscript,notxpcom] boolean isStaticAtom (); */
  NS_IMETHOD_(bool) IsStaticAtom(void) = 0;

   // note this is NOT virtual so this won't muck with the vtable!
  inline bool Equals(const nsAString& aString) {
    return aString.Equals(nsDependentString(mString, mLength));
  }
  inline const PRUnichar* GetUTF16String() {
    return mString;
  }
  inline const uint32_t GetLength() {
    return mLength;
  }
  inline void ToString(nsAString& aBuf) {
    nsStringBuffer::FromData(mString)->ToString(mLength, aBuf);
  }
  /**
   * A hashcode that is better distributed than the actual atom
   * pointer, for use in situations that need a well-distributed
   * hashcode.
   */
  inline uint32_t hash() const {
    return mHash;
  }
protected:
  uint32_t mLength;
  uint32_t mHash;
  PRUnichar* mString;
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAtom, NS_IATOM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIATOM \
  NS_IMETHOD ScriptableToString(nsAString & _retval); \
  NS_IMETHOD ToUTF8String(nsACString & _retval); \
  NS_IMETHOD ScriptableEquals(const nsAString & aString, bool *_retval); \
  NS_IMETHOD_(bool) EqualsUTF8(const nsACString & aString); \
  NS_IMETHOD_(bool) IsStaticAtom(void); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIATOM(_to) \
  NS_IMETHOD ScriptableToString(nsAString & _retval) { return _to ScriptableToString(_retval); } \
  NS_IMETHOD ToUTF8String(nsACString & _retval) { return _to ToUTF8String(_retval); } \
  NS_IMETHOD ScriptableEquals(const nsAString & aString, bool *_retval) { return _to ScriptableEquals(aString, _retval); } \
  NS_IMETHOD_(bool) EqualsUTF8(const nsACString & aString) { return _to EqualsUTF8(aString); } \
  NS_IMETHOD_(bool) IsStaticAtom(void) { return _to IsStaticAtom(); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIATOM(_to) \
  NS_IMETHOD ScriptableToString(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableToString(_retval); } \
  NS_IMETHOD ToUTF8String(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToUTF8String(_retval); } \
  NS_IMETHOD ScriptableEquals(const nsAString & aString, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableEquals(aString, _retval); } \
  NS_IMETHOD_(bool) EqualsUTF8(const nsACString & aString); \
  NS_IMETHOD_(bool) IsStaticAtom(void); \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAtom : public nsIAtom
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIATOM

  nsAtom();

private:
  ~nsAtom();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAtom, nsIAtom)

nsAtom::nsAtom()
{
  /* member initializers and constructor code */
}

nsAtom::~nsAtom()
{
  /* destructor code */
}

/* [binaryname(ScriptableToString)] AString toString (); */
NS_IMETHODIMP nsAtom::ScriptableToString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AUTF8String toUTF8String (); */
NS_IMETHODIMP nsAtom::ToUTF8String(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableEquals)] boolean equals (in AString aString); */
NS_IMETHODIMP nsAtom::ScriptableEquals(const nsAString & aString, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] boolean equalsUTF8 (in AUTF8String aString); */
NS_IMETHODIMP_(bool) nsAtom::EqualsUTF8(const nsACString & aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] boolean isStaticAtom (); */
NS_IMETHODIMP_(bool) nsAtom::IsStaticAtom()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/*
 * The three forms of NS_NewAtom and do_GetAtom (for use with
 * |nsCOMPtr<nsIAtom>|) return the atom for the string given.  At any
 * given time there will always be one atom representing a given string.
 * Atoms are intended to make string comparison cheaper by simplifying
 * it to pointer equality.  A pointer to the atom that does not own a
 * reference is not guaranteed to be valid.
 *
 * The three forms of NS_NewPermanentAtom and do_GetPermanentAtom return
 * the atom for the given string and ensure that the atom is permanent.
 * An atom that is permanent will exist (occupy space at a specific
 * location in memory) until XPCOM is shut down.  The advantage of
 * permanent atoms is that they do not need to maintain a reference
 * count, which requires locking and hurts performance.
 */
/**
 * Find an atom that matches the given UTF-8 string.
 * The string is assumed to be zero terminated.
 */
extern nsIAtom* NS_NewAtom(const char* aUTF8String);
inline already_AddRefed<nsIAtom> do_GetAtom(const char* aUTF8String)
    { return NS_NewAtom(aUTF8String); }
 
/**
 * Find an atom that matches the given UTF-8 string.
 */
extern nsIAtom* NS_NewAtom(const nsACString& aUTF8String);
inline already_AddRefed<nsIAtom> do_GetAtom(const nsACString& aUTF8String)
    { return NS_NewAtom(aUTF8String); }
/**
 * Find an atom that matches the given UTF-16 string.
 * The string is assumed to be zero terminated.
 */
extern nsIAtom* NS_NewAtom(const PRUnichar* aUTF16String);
inline already_AddRefed<nsIAtom> do_GetAtom(const PRUnichar* aUTF16String)
    { return NS_NewAtom(aUTF16String); }
/**
 * Find an atom that matches the given UTF-16 string.
 */
extern nsIAtom* NS_NewAtom(const nsAString& aUTF16String);
extern nsIAtom* NS_NewPermanentAtom(const nsAString& aUTF16String);
inline already_AddRefed<nsIAtom> do_GetAtom(const nsAString& aUTF16String)
    { return NS_NewAtom(aUTF16String); }
/**
 * Return a count of the total number of atoms currently
 * alive in the system.
 */
extern nsrefcnt NS_GetNumberOfAtoms(void);
/**
 * Return a pointer for a static atom for the string or null if there's 
 * no static atom for this string.
 */
extern nsIAtom* NS_GetStaticAtom(const nsAString& aUTF16String);
/**
 * Seal the static atom table
 */
extern void NS_SealStaticAtomTable();
class nsAtomString : public nsString
{
public:
  nsAtomString(nsIAtom* aAtom)
  {
    aAtom->ToString(*this);
  }
};
class nsAtomCString : public nsCString
{
public:
  nsAtomCString(nsIAtom* aAtom)
  {
    aAtom->ToUTF8String(*this);
  }
};
class nsDependentAtomString : public nsDependentString
{
public:
  nsDependentAtomString(nsIAtom* aAtom)
    : nsDependentString(aAtom->GetUTF16String(), aAtom->GetLength())
  {
  }
};

#endif /* __gen_nsIAtom_h__ */
