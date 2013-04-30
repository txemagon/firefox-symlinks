/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/layout/inspector/public/inIDOMUtils.idl
 */

#ifndef __gen_inIDOMUtils_h__
#define __gen_inIDOMUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsISupportsArray; /* forward declaration */

class nsIDOMCharacterData; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMCSSStyleRule; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMNodeList; /* forward declaration */

class nsIDOMFontFaceList; /* forward declaration */

class nsIDOMRange; /* forward declaration */

class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    inIDOMUtils */
#define INIDOMUTILS_IID_STR "f7a37305-a963-4a2a-b951-2c97a6b27fb4"

#define INIDOMUTILS_IID \
  {0xf7a37305, 0xa963, 0x4a2a, \
    { 0xb9, 0x51, 0x2c, 0x97, 0xa6, 0xb2, 0x7f, 0xb4 }}

class NS_NO_VTABLE inIDOMUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDOMUTILS_IID)

  /* nsISupportsArray getCSSStyleRules (in nsIDOMElement aElement, [optional] in DOMString aPseudo); */
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) = 0;

  /* unsigned long getRuleLine (in nsIDOMCSSStyleRule aRule); */
  NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) = 0;

  /* bool isInheritedProperty (in AString aPropertyName); */
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) = 0;

  /* boolean isIgnorableWhitespace (in nsIDOMCharacterData aDataNode); */
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) = 0;

  /* nsIDOMNode getParentForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNodeList getChildrenForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) = 0;

  /* nsIArray getBindingURLs (in nsIDOMElement aElement); */
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) = 0;

  /* unsigned long long getContentState (in nsIDOMElement aElement); */
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) = 0;

  /* void setContentState (in nsIDOMElement aElement, in unsigned long long aState); */
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) = 0;

  /* nsIDOMFontFaceList getUsedFontFaces (in nsIDOMRange aRange); */
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) = 0;

  /* void addPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) = 0;

  /* void removePseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) = 0;

  /* bool hasPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) = 0;

  /* void clearPseudoClassLocks (in nsIDOMElement aElement); */
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) = 0;

  /* void parseStyleSheet (in nsIDOMCSSStyleSheet aSheet, in DOMString aInput); */
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDOMUtils, INIDOMUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDOMUTILS \
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval); \
  NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, uint32_t *_retval); \
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval); \
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval); \
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval); \
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval); \
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval); \
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval); \
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState); \
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval); \
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass); \
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass); \
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval); \
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement); \
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDOMUTILS(_to) \
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) { return _to GetCSSStyleRules(aElement, aPseudo, _retval); } \
  NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) { return _to GetRuleLine(aRule, _retval); } \
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) { return _to IsInheritedProperty(aPropertyName, _retval); } \
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) { return _to IsIgnorableWhitespace(aDataNode, _retval); } \
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) { return _to GetParentForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) { return _to GetChildrenForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) { return _to GetBindingURLs(aElement, _retval); } \
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) { return _to GetContentState(aElement, _retval); } \
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) { return _to SetContentState(aElement, aState); } \
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) { return _to GetUsedFontFaces(aRange, _retval); } \
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) { return _to AddPseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) { return _to RemovePseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) { return _to HasPseudoClassLock(aElement, aPseudoClass, _retval); } \
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) { return _to ClearPseudoClassLocks(aElement); } \
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) { return _to ParseStyleSheet(aSheet, aInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDOMUTILS(_to) \
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSStyleRules(aElement, aPseudo, _retval); } \
  NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRuleLine(aRule, _retval); } \
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInheritedProperty(aPropertyName, _retval); } \
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIgnorableWhitespace(aDataNode, _retval); } \
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildrenForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingURLs(aElement, _retval); } \
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentState(aElement, _retval); } \
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentState(aElement, aState); } \
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsedFontFaces(aRange, _retval); } \
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPseudoClassLock(aElement, aPseudoClass, _retval); } \
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearPseudoClassLocks(aElement); } \
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseStyleSheet(aSheet, aInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDOMUtils : public inIDOMUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDOMUTILS

  inDOMUtils();

private:
  ~inDOMUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inDOMUtils, inIDOMUtils)

inDOMUtils::inDOMUtils()
{
  /* member initializers and constructor code */
}

inDOMUtils::~inDOMUtils()
{
  /* destructor code */
}

/* nsISupportsArray getCSSStyleRules (in nsIDOMElement aElement, [optional] in DOMString aPseudo); */
NS_IMETHODIMP inDOMUtils::GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getRuleLine (in nsIDOMCSSStyleRule aRule); */
NS_IMETHODIMP inDOMUtils::GetRuleLine(nsIDOMCSSStyleRule *aRule, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isInheritedProperty (in AString aPropertyName); */
NS_IMETHODIMP inDOMUtils::IsInheritedProperty(const nsAString & aPropertyName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isIgnorableWhitespace (in nsIDOMCharacterData aDataNode); */
NS_IMETHODIMP inDOMUtils::IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getParentForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
NS_IMETHODIMP inDOMUtils::GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getChildrenForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
NS_IMETHODIMP inDOMUtils::GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getBindingURLs (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long getContentState (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetContentState(nsIDOMElement *aElement, uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContentState (in nsIDOMElement aElement, in unsigned long long aState); */
NS_IMETHODIMP inDOMUtils::SetContentState(nsIDOMElement *aElement, uint64_t aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMFontFaceList getUsedFontFaces (in nsIDOMRange aRange); */
NS_IMETHODIMP inDOMUtils::GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
NS_IMETHODIMP inDOMUtils::AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
NS_IMETHODIMP inDOMUtils::RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool hasPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
NS_IMETHODIMP inDOMUtils::HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearPseudoClassLocks (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::ClearPseudoClassLocks(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseStyleSheet (in nsIDOMCSSStyleSheet aSheet, in DOMString aInput); */
NS_IMETHODIMP inDOMUtils::ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIDOMUtils_h__ */
