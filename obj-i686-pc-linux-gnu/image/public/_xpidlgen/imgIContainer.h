/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/image/public/imgIContainer.idl
 */

#ifndef __gen_imgIContainer_h__
#define __gen_imgIContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "gfxImageSurface.h"
#include "gfxContext.h"
#include "gfxMatrix.h"
#include "gfxRect.h"
#include "gfxPattern.h"
#include "gfxASurface.h"
#include "nsRect.h"
#include "nsSize.h"
#include "limits.h"
namespace mozilla {
namespace layers {
class LayerManager;
class ImageContainer;
}
}
class nsIFrame;
namespace mozilla {
class TimeStamp;
}

/* starting interface:    imgIContainer */
#define IMGICONTAINER_IID_STR "01e12ac9-7d9f-40d9-9ec1-70b64c53ce7a"

#define IMGICONTAINER_IID \
  {0x01e12ac9, 0x7d9f, 0x40d9, \
    { 0x9e, 0xc1, 0x70, 0xb6, 0x4c, 0x53, 0xce, 0x7a }}

class NS_NO_VTABLE imgIContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICONTAINER_IID)

  /* readonly attribute int32_t width; */
  NS_IMETHOD GetWidth(int32_t *aWidth) = 0;

  /* readonly attribute int32_t height; */
  NS_IMETHOD GetHeight(int32_t *aHeight) = 0;

  enum {
    TYPE_RASTER = 0U,
    TYPE_VECTOR = 1U
  };

  /* readonly attribute unsigned short type; */
  NS_IMETHOD GetType(uint16_t *aType) = 0;

  /* [noscript,notxpcom] uint16_t GetType (); */
  NS_IMETHOD_(uint16_t) GetType(void) = 0;

  /* readonly attribute boolean animated; */
  NS_IMETHOD GetAnimated(bool *aAnimated) = 0;

  /* readonly attribute boolean currentFrameIsOpaque; */
  NS_IMETHOD GetCurrentFrameIsOpaque(bool *aCurrentFrameIsOpaque) = 0;

  enum {
    FLAG_NONE = 0,
    FLAG_SYNC_DECODE = 1,
    FLAG_DECODE_NO_PREMULTIPLY_ALPHA = 2,
    FLAG_DECODE_NO_COLORSPACE_CONVERSION = 4,
    FLAG_CLAMP = 8,
    FRAME_FIRST = 0U,
    FRAME_CURRENT = 1U,
    FRAME_MAX_VALUE = 1U
  };

  /* [noscript] gfxASurface getFrame (in uint32_t aWhichFrame, in uint32_t aFlags); */
  NS_IMETHOD GetFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxASurface **_retval) = 0;

  /* [noscript] ImageContainer getImageContainer (in LayerManager aManager); */
  NS_IMETHOD GetImageContainer(mozilla::layers::LayerManager *aManager, mozilla::layers::ImageContainer **_retval) = 0;

  /* [noscript] gfxImageSurface copyFrame (in uint32_t aWhichFrame, in uint32_t aFlags); */
  NS_IMETHOD CopyFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxImageSurface **_retval) = 0;

  /* [noscript] imgIContainer extractFrame (in uint32_t aWhichFrame, [const] in nsIntRect aRect, in uint32_t aFlags); */
  NS_IMETHOD ExtractFrame(uint32_t aWhichFrame, const nsIntRect & aRect, uint32_t aFlags, imgIContainer * *_retval) = 0;

  /* [noscript] void draw (in gfxContext aContext, in gfxGraphicsFilter aFilter, [const] in gfxMatrix aUserSpaceToImageSpace, [const] in gfxRect aFill, [const] in nsIntRect aSubimage, [const] in nsIntSize aViewportSize, in uint32_t aFlags); */
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, uint32_t aFlags) = 0;

  /* [notxpcom] nsIFrame GetRootLayoutFrame (); */
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void) = 0;

  /* void requestDecode (); */
  NS_IMETHOD RequestDecode(void) = 0;

  /* [noscript] void startDecoding (); */
  NS_IMETHOD StartDecoding(void) = 0;

  /* void lockImage (); */
  NS_IMETHOD LockImage(void) = 0;

  /* void unlockImage (); */
  NS_IMETHOD UnlockImage(void) = 0;

  /* void requestDiscard (); */
  NS_IMETHOD RequestDiscard(void) = 0;

  /* [notxpcom] void requestRefresh ([const] in TimeStamp aTime); */
  NS_IMETHOD_(void) RequestRefresh(const mozilla::TimeStamp & aTime) = 0;

  enum {
    kNormalAnimMode = 0,
    kDontAnimMode = 1,
    kLoopOnceAnimMode = 2
  };

  /* attribute unsigned short animationMode; */
  NS_IMETHOD GetAnimationMode(uint16_t *aAnimationMode) = 0;
  NS_IMETHOD SetAnimationMode(uint16_t aAnimationMode) = 0;

  /* void resetAnimation (); */
  NS_IMETHOD ResetAnimation(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIContainer, IMGICONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICONTAINER \
  NS_IMETHOD GetWidth(int32_t *aWidth); \
  NS_IMETHOD GetHeight(int32_t *aHeight); \
  NS_IMETHOD GetType(uint16_t *aType); \
  NS_IMETHOD_(uint16_t) GetType(void); \
  NS_IMETHOD GetAnimated(bool *aAnimated); \
  NS_IMETHOD GetCurrentFrameIsOpaque(bool *aCurrentFrameIsOpaque); \
  NS_IMETHOD GetFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxASurface **_retval); \
  NS_IMETHOD GetImageContainer(mozilla::layers::LayerManager *aManager, mozilla::layers::ImageContainer **_retval); \
  NS_IMETHOD CopyFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxImageSurface **_retval); \
  NS_IMETHOD ExtractFrame(uint32_t aWhichFrame, const nsIntRect & aRect, uint32_t aFlags, imgIContainer * *_retval); \
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, uint32_t aFlags); \
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void); \
  NS_IMETHOD RequestDecode(void); \
  NS_IMETHOD StartDecoding(void); \
  NS_IMETHOD LockImage(void); \
  NS_IMETHOD UnlockImage(void); \
  NS_IMETHOD RequestDiscard(void); \
  NS_IMETHOD_(void) RequestRefresh(const mozilla::TimeStamp & aTime); \
  NS_IMETHOD GetAnimationMode(uint16_t *aAnimationMode); \
  NS_IMETHOD SetAnimationMode(uint16_t aAnimationMode); \
  NS_IMETHOD ResetAnimation(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICONTAINER(_to) \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetType(uint16_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD_(uint16_t) GetType(void) { return _to GetType(); } \
  NS_IMETHOD GetAnimated(bool *aAnimated) { return _to GetAnimated(aAnimated); } \
  NS_IMETHOD GetCurrentFrameIsOpaque(bool *aCurrentFrameIsOpaque) { return _to GetCurrentFrameIsOpaque(aCurrentFrameIsOpaque); } \
  NS_IMETHOD GetFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxASurface **_retval) { return _to GetFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD GetImageContainer(mozilla::layers::LayerManager *aManager, mozilla::layers::ImageContainer **_retval) { return _to GetImageContainer(aManager, _retval); } \
  NS_IMETHOD CopyFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxImageSurface **_retval) { return _to CopyFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD ExtractFrame(uint32_t aWhichFrame, const nsIntRect & aRect, uint32_t aFlags, imgIContainer * *_retval) { return _to ExtractFrame(aWhichFrame, aRect, aFlags, _retval); } \
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, uint32_t aFlags) { return _to Draw(aContext, aFilter, aUserSpaceToImageSpace, aFill, aSubimage, aViewportSize, aFlags); } \
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void) { return _to GetRootLayoutFrame(); } \
  NS_IMETHOD RequestDecode(void) { return _to RequestDecode(); } \
  NS_IMETHOD StartDecoding(void) { return _to StartDecoding(); } \
  NS_IMETHOD LockImage(void) { return _to LockImage(); } \
  NS_IMETHOD UnlockImage(void) { return _to UnlockImage(); } \
  NS_IMETHOD RequestDiscard(void) { return _to RequestDiscard(); } \
  NS_IMETHOD_(void) RequestRefresh(const mozilla::TimeStamp & aTime) { return _to RequestRefresh(aTime); } \
  NS_IMETHOD GetAnimationMode(uint16_t *aAnimationMode) { return _to GetAnimationMode(aAnimationMode); } \
  NS_IMETHOD SetAnimationMode(uint16_t aAnimationMode) { return _to SetAnimationMode(aAnimationMode); } \
  NS_IMETHOD ResetAnimation(void) { return _to ResetAnimation(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICONTAINER(_to) \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetType(uint16_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD_(uint16_t) GetType(void); \
  NS_IMETHOD GetAnimated(bool *aAnimated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimated(aAnimated); } \
  NS_IMETHOD GetCurrentFrameIsOpaque(bool *aCurrentFrameIsOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentFrameIsOpaque(aCurrentFrameIsOpaque); } \
  NS_IMETHOD GetFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxASurface **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD GetImageContainer(mozilla::layers::LayerManager *aManager, mozilla::layers::ImageContainer **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageContainer(aManager, _retval); } \
  NS_IMETHOD CopyFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxImageSurface **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyFrame(aWhichFrame, aFlags, _retval); } \
  NS_IMETHOD ExtractFrame(uint32_t aWhichFrame, const nsIntRect & aRect, uint32_t aFlags, imgIContainer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractFrame(aWhichFrame, aRect, aFlags, _retval); } \
  NS_IMETHOD Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Draw(aContext, aFilter, aUserSpaceToImageSpace, aFill, aSubimage, aViewportSize, aFlags); } \
  NS_IMETHOD_(nsIFrame *) GetRootLayoutFrame(void); \
  NS_IMETHOD RequestDecode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDecode(); } \
  NS_IMETHOD StartDecoding(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDecoding(); } \
  NS_IMETHOD LockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockImage(); } \
  NS_IMETHOD UnlockImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockImage(); } \
  NS_IMETHOD RequestDiscard(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDiscard(); } \
  NS_IMETHOD_(void) RequestRefresh(const mozilla::TimeStamp & aTime); \
  NS_IMETHOD GetAnimationMode(uint16_t *aAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnimationMode(aAnimationMode); } \
  NS_IMETHOD SetAnimationMode(uint16_t aAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnimationMode(aAnimationMode); } \
  NS_IMETHOD ResetAnimation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetAnimation(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICONTAINER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIContainer)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute int32_t width; */
NS_IMETHODIMP _MYCLASS_::GetWidth(int32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t height; */
NS_IMETHODIMP _MYCLASS_::GetHeight(int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short type; */
NS_IMETHODIMP _MYCLASS_::GetType(uint16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] uint16_t GetType (); */
NS_IMETHODIMP_(uint16_t) _MYCLASS_::GetType()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean animated; */
NS_IMETHODIMP _MYCLASS_::GetAnimated(bool *aAnimated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean currentFrameIsOpaque; */
NS_IMETHODIMP _MYCLASS_::GetCurrentFrameIsOpaque(bool *aCurrentFrameIsOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] gfxASurface getFrame (in uint32_t aWhichFrame, in uint32_t aFlags); */
NS_IMETHODIMP _MYCLASS_::GetFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxASurface **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] ImageContainer getImageContainer (in LayerManager aManager); */
NS_IMETHODIMP _MYCLASS_::GetImageContainer(mozilla::layers::LayerManager *aManager, mozilla::layers::ImageContainer **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] gfxImageSurface copyFrame (in uint32_t aWhichFrame, in uint32_t aFlags); */
NS_IMETHODIMP _MYCLASS_::CopyFrame(uint32_t aWhichFrame, uint32_t aFlags, gfxImageSurface **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] imgIContainer extractFrame (in uint32_t aWhichFrame, [const] in nsIntRect aRect, in uint32_t aFlags); */
NS_IMETHODIMP _MYCLASS_::ExtractFrame(uint32_t aWhichFrame, const nsIntRect & aRect, uint32_t aFlags, imgIContainer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void draw (in gfxContext aContext, in gfxGraphicsFilter aFilter, [const] in gfxMatrix aUserSpaceToImageSpace, [const] in gfxRect aFill, [const] in nsIntRect aSubimage, [const] in nsIntSize aViewportSize, in uint32_t aFlags); */
NS_IMETHODIMP _MYCLASS_::Draw(gfxContext *aContext, gfxPattern::GraphicsFilter aFilter, const gfxMatrix & aUserSpaceToImageSpace, const gfxRect & aFill, const nsIntRect & aSubimage, const nsIntSize & aViewportSize, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsIFrame GetRootLayoutFrame (); */
NS_IMETHODIMP_(nsIFrame *) _MYCLASS_::GetRootLayoutFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestDecode (); */
NS_IMETHODIMP _MYCLASS_::RequestDecode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void startDecoding (); */
NS_IMETHODIMP _MYCLASS_::StartDecoding()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockImage (); */
NS_IMETHODIMP _MYCLASS_::LockImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockImage (); */
NS_IMETHODIMP _MYCLASS_::UnlockImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestDiscard (); */
NS_IMETHODIMP _MYCLASS_::RequestDiscard()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void requestRefresh ([const] in TimeStamp aTime); */
NS_IMETHODIMP_(void) _MYCLASS_::RequestRefresh(const mozilla::TimeStamp & aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short animationMode; */
NS_IMETHODIMP _MYCLASS_::GetAnimationMode(uint16_t *aAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetAnimationMode(uint16_t aAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetAnimation (); */
NS_IMETHODIMP _MYCLASS_::ResetAnimation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIContainer_h__ */
