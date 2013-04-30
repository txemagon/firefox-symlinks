/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/content/base/public/nsISelectionPrivate.idl
 */

#ifndef __gen_nsISelectionPrivate_h__
#define __gen_nsISelectionPrivate_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISelectionListener_h__
#include "nsISelectionListener.h"
#endif

#ifndef __gen_nsIEnumerator_h__
#include "nsIEnumerator.h"
#endif

#ifndef __gen_nsISelection_h__
#include "nsISelection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsRange; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsISelectionListener; /* forward declaration */

class nsIContent; /* forward declaration */

class nsINode; /* forward declaration */

class nsFrameSelection;
class nsIPresShell;
struct nsTextRangeStyle;
struct nsPoint;
struct ScrollAxis;
#include "nsTArray.h"
#include "nsIFrame.h"

/* starting interface:    nsISelectionPrivate */
#define NS_ISELECTIONPRIVATE_IID_STR "3a1a6d3b-3698-4561-ba00-ba648cb2b0d4"

#define NS_ISELECTIONPRIVATE_IID \
  {0x3a1a6d3b, 0x3698, 0x4561, \
    { 0xba, 0x00, 0xba, 0x64, 0x8c, 0xb2, 0xb0, 0xd4 }}

class NS_NO_VTABLE nsISelectionPrivate : public nsISelection {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONPRIVATE_IID)

  enum {
    ENDOFPRECEDINGLINE = 0,
    STARTOFNEXTLINE = 1
  };

  /* attribute boolean interlinePosition; */
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) = 0;
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) = 0;

  /* void startBatchChanges (); */
  NS_IMETHOD StartBatchChanges(void) = 0;

  /* void endBatchChanges (); */
  NS_IMETHOD EndBatchChanges(void) = 0;

  /* nsIEnumerator getEnumerator (); */
  NS_IMETHOD GetEnumerator(nsIEnumerator * *_retval) = 0;

  /* DOMString toStringWithFormat (in string formatType, in unsigned long flags, in int32_t wrapColumn); */
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) = 0;

  /* void addSelectionListener (in nsISelectionListener newListener); */
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) = 0;

  /* void removeSelectionListener (in nsISelectionListener listenerToRemove); */
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) = 0;

  enum {
    TABLESELECTION_NONE = 0,
    TABLESELECTION_CELL = 1,
    TABLESELECTION_ROW = 2,
    TABLESELECTION_COLUMN = 3,
    TABLESELECTION_TABLE = 4,
    TABLESELECTION_ALLCELLS = 5
  };

  /* long getTableSelectionType (in nsIDOMRange range); */
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) = 0;

  /* [noscript] void setPresShell (in nsIPresShell aPresShell); */
  NS_IMETHOD SetPresShell(nsIPresShell *aPresShell) = 0;

  /* [noscript] attribute boolean canCacheFrameOffset; */
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) = 0;
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) = 0;

  /* [noscript] void getCachedFrameOffset (in nsIFrame aFrame, in int32_t inOffset, in nsPointRef aPoint); */
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) = 0;

  /* [noscript] nsFrameSelection getFrameSelection (); */
  NS_IMETHOD GetFrameSelection(nsFrameSelection **_retval) = 0;

  /* [noscript] void setAncestorLimiter (in nsIContent aContent); */
  NS_IMETHOD SetAncestorLimiter(nsIContent *aContent) = 0;

  /* [noscript] void setTextRangeStyle (in nsIDOMRange range, in constTextRangeStyleRef textRangeStyle); */
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const nsTextRangeStyle & textRangeStyle) = 0;

  /* [noscript,notxpcom] nsDirection getSelectionDirection (); */
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void) = 0;

  /* [noscript,notxpcom] void setSelectionDirection (in nsDirection aDirection); */
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection) = 0;

  /* readonly attribute short type; */
  NS_IMETHOD GetType(int16_t *aType) = 0;

  /* void GetRangesForInterval (in nsIDOMNode beginNode, in int32_t beginOffset, in nsIDOMNode endNode, in int32_t endOffset, in boolean allowAdjacent, out uint32_t resultCount, [array, size_is (resultCount), retval] out nsIDOMRange results); */
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) = 0;

  /* [noscript] void GetRangesForIntervalArray (in nsINode beginNode, in int32_t beginOffset, in nsINode endNode, in int32_t endOffset, in boolean allowAdjacent, in RangeArray results); */
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) = 0;

  /* void scrollIntoView (in short aRegion, in boolean aIsSynchronous, in int16_t aVPercent, in int16_t aHPercent); */
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) = 0;

  /* [noscript] void scrollIntoViewInternal (in short aRegion, in boolean aIsSynchronous, in ScrollAxis aVertical, in ScrollAxis aHorizontal); */
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionPrivate, NS_ISELECTIONPRIVATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONPRIVATE \
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition); \
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition); \
  NS_IMETHOD StartBatchChanges(void); \
  NS_IMETHOD EndBatchChanges(void); \
  NS_IMETHOD GetEnumerator(nsIEnumerator * *_retval); \
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval); \
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener); \
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove); \
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval); \
  NS_IMETHOD SetPresShell(nsIPresShell *aPresShell); \
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset); \
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset); \
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint); \
  NS_IMETHOD GetFrameSelection(nsFrameSelection **_retval); \
  NS_IMETHOD SetAncestorLimiter(nsIContent *aContent); \
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const nsTextRangeStyle & textRangeStyle); \
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void); \
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection); \
  NS_IMETHOD GetType(int16_t *aType); \
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results); \
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results); \
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent); \
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONPRIVATE(_to) \
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) { return _to GetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) { return _to SetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD StartBatchChanges(void) { return _to StartBatchChanges(); } \
  NS_IMETHOD EndBatchChanges(void) { return _to EndBatchChanges(); } \
  NS_IMETHOD GetEnumerator(nsIEnumerator * *_retval) { return _to GetEnumerator(_retval); } \
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) { return _to ToStringWithFormat(formatType, flags, wrapColumn, _retval); } \
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) { return _to AddSelectionListener(newListener); } \
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) { return _to RemoveSelectionListener(listenerToRemove); } \
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) { return _to GetTableSelectionType(range, _retval); } \
  NS_IMETHOD SetPresShell(nsIPresShell *aPresShell) { return _to SetPresShell(aPresShell); } \
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) { return _to GetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) { return _to SetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) { return _to GetCachedFrameOffset(aFrame, inOffset, aPoint); } \
  NS_IMETHOD GetFrameSelection(nsFrameSelection **_retval) { return _to GetFrameSelection(_retval); } \
  NS_IMETHOD SetAncestorLimiter(nsIContent *aContent) { return _to SetAncestorLimiter(aContent); } \
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const nsTextRangeStyle & textRangeStyle) { return _to SetTextRangeStyle(range, textRangeStyle); } \
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void) { return _to GetSelectionDirection(); } \
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection) { return _to SetSelectionDirection(aDirection); } \
  NS_IMETHOD GetType(int16_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) { return _to GetRangesForInterval(beginNode, beginOffset, endNode, endOffset, allowAdjacent, resultCount, results); } \
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) { return _to GetRangesForIntervalArray(beginNode, beginOffset, endNode, endOffset, allowAdjacent, results); } \
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) { return _to ScrollIntoView(aRegion, aIsSynchronous, aVPercent, aHPercent); } \
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) { return _to ScrollIntoViewInternal(aRegion, aIsSynchronous, aVertical, aHorizontal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONPRIVATE(_to) \
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD StartBatchChanges(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartBatchChanges(); } \
  NS_IMETHOD EndBatchChanges(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndBatchChanges(); } \
  NS_IMETHOD GetEnumerator(nsIEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(_retval); } \
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToStringWithFormat(formatType, flags, wrapColumn, _retval); } \
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSelectionListener(newListener); } \
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSelectionListener(listenerToRemove); } \
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTableSelectionType(range, _retval); } \
  NS_IMETHOD SetPresShell(nsIPresShell *aPresShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPresShell(aPresShell); } \
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedFrameOffset(aFrame, inOffset, aPoint); } \
  NS_IMETHOD GetFrameSelection(nsFrameSelection **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameSelection(_retval); } \
  NS_IMETHOD SetAncestorLimiter(nsIContent *aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAncestorLimiter(aContent); } \
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const nsTextRangeStyle & textRangeStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextRangeStyle(range, textRangeStyle); } \
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void); \
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection); \
  NS_IMETHOD GetType(int16_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangesForInterval(beginNode, beginOffset, endNode, endOffset, allowAdjacent, resultCount, results); } \
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangesForIntervalArray(beginNode, beginOffset, endNode, endOffset, allowAdjacent, results); } \
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(aRegion, aIsSynchronous, aVPercent, aHPercent); } \
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoViewInternal(aRegion, aIsSynchronous, aVertical, aHorizontal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionPrivate : public nsISelectionPrivate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONPRIVATE

  nsSelectionPrivate();

private:
  ~nsSelectionPrivate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelectionPrivate, nsISelectionPrivate)

nsSelectionPrivate::nsSelectionPrivate()
{
  /* member initializers and constructor code */
}

nsSelectionPrivate::~nsSelectionPrivate()
{
  /* destructor code */
}

/* attribute boolean interlinePosition; */
NS_IMETHODIMP nsSelectionPrivate::GetInterlinePosition(bool *aInterlinePosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSelectionPrivate::SetInterlinePosition(bool aInterlinePosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startBatchChanges (); */
NS_IMETHODIMP nsSelectionPrivate::StartBatchChanges()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endBatchChanges (); */
NS_IMETHODIMP nsSelectionPrivate::EndBatchChanges()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator getEnumerator (); */
NS_IMETHODIMP nsSelectionPrivate::GetEnumerator(nsIEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toStringWithFormat (in string formatType, in unsigned long flags, in int32_t wrapColumn); */
NS_IMETHODIMP nsSelectionPrivate::ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSelectionListener (in nsISelectionListener newListener); */
NS_IMETHODIMP nsSelectionPrivate::AddSelectionListener(nsISelectionListener *newListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSelectionListener (in nsISelectionListener listenerToRemove); */
NS_IMETHODIMP nsSelectionPrivate::RemoveSelectionListener(nsISelectionListener *listenerToRemove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getTableSelectionType (in nsIDOMRange range); */
NS_IMETHODIMP nsSelectionPrivate::GetTableSelectionType(nsIDOMRange *range, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPresShell (in nsIPresShell aPresShell); */
NS_IMETHODIMP nsSelectionPrivate::SetPresShell(nsIPresShell *aPresShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute boolean canCacheFrameOffset; */
NS_IMETHODIMP nsSelectionPrivate::GetCanCacheFrameOffset(bool *aCanCacheFrameOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSelectionPrivate::SetCanCacheFrameOffset(bool aCanCacheFrameOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getCachedFrameOffset (in nsIFrame aFrame, in int32_t inOffset, in nsPointRef aPoint); */
NS_IMETHODIMP nsSelectionPrivate::GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsFrameSelection getFrameSelection (); */
NS_IMETHODIMP nsSelectionPrivate::GetFrameSelection(nsFrameSelection **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setAncestorLimiter (in nsIContent aContent); */
NS_IMETHODIMP nsSelectionPrivate::SetAncestorLimiter(nsIContent *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setTextRangeStyle (in nsIDOMRange range, in constTextRangeStyleRef textRangeStyle); */
NS_IMETHODIMP nsSelectionPrivate::SetTextRangeStyle(nsIDOMRange *range, const nsTextRangeStyle & textRangeStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsDirection getSelectionDirection (); */
NS_IMETHODIMP_(nsDirection) nsSelectionPrivate::GetSelectionDirection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void setSelectionDirection (in nsDirection aDirection); */
NS_IMETHODIMP_(void) nsSelectionPrivate::SetSelectionDirection(nsDirection aDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short type; */
NS_IMETHODIMP nsSelectionPrivate::GetType(int16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetRangesForInterval (in nsIDOMNode beginNode, in int32_t beginOffset, in nsIDOMNode endNode, in int32_t endOffset, in boolean allowAdjacent, out uint32_t resultCount, [array, size_is (resultCount), retval] out nsIDOMRange results); */
NS_IMETHODIMP nsSelectionPrivate::GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetRangesForIntervalArray (in nsINode beginNode, in int32_t beginOffset, in nsINode endNode, in int32_t endOffset, in boolean allowAdjacent, in RangeArray results); */
NS_IMETHODIMP nsSelectionPrivate::GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollIntoView (in short aRegion, in boolean aIsSynchronous, in int16_t aVPercent, in int16_t aHPercent); */
NS_IMETHODIMP nsSelectionPrivate::ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void scrollIntoViewInternal (in short aRegion, in boolean aIsSynchronous, in ScrollAxis aVertical, in ScrollAxis aHorizontal); */
NS_IMETHODIMP nsSelectionPrivate::ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelectionPrivate_h__ */
