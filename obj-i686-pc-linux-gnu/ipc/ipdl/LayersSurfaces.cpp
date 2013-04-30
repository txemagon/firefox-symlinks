//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/layers/LayersSurfaces.h"


//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union MaybeMagicGrallocBufferHandle|
//
namespace mozilla {
namespace layers {
bool
MaybeMagicGrallocBufferHandle::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TMagicGrallocBufferHandle:
        {
            (ptr_MagicGrallocBufferHandle())->~MagicGrallocBufferHandle__tdef();
            break;
        }
    case Tnull_t:
        {
            (ptr_null_t())->~null_t__tdef();
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("not reached");
            break;
        }
    }
    return true;
}

MaybeMagicGrallocBufferHandle::MaybeMagicGrallocBufferHandle(const MagicGrallocBufferHandle& aOther)
{
    new (ptr_MagicGrallocBufferHandle()) MagicGrallocBufferHandle(aOther);
    mType = TMagicGrallocBufferHandle;
}

MaybeMagicGrallocBufferHandle::MaybeMagicGrallocBufferHandle(const null_t& aOther)
{
    new (ptr_null_t()) null_t(aOther);
    mType = Tnull_t;
}

MaybeMagicGrallocBufferHandle::MaybeMagicGrallocBufferHandle(const MaybeMagicGrallocBufferHandle& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TMagicGrallocBufferHandle:
        {
            new (ptr_MagicGrallocBufferHandle()) MagicGrallocBufferHandle((aOther).get_MagicGrallocBufferHandle());
            break;
        }
    case Tnull_t:
        {
            new (ptr_null_t()) null_t((aOther).get_null_t());
            break;
        }
    case T__None:
        {
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return;
        }
    }
    mType = (aOther).type();
}

MaybeMagicGrallocBufferHandle::~MaybeMagicGrallocBufferHandle()
{
    MaybeDestroy(T__None);
}

MaybeMagicGrallocBufferHandle&
MaybeMagicGrallocBufferHandle::operator=(const MagicGrallocBufferHandle& aRhs)
{
    if (MaybeDestroy(TMagicGrallocBufferHandle)) {
        new (ptr_MagicGrallocBufferHandle()) MagicGrallocBufferHandle;
    }
    (*(ptr_MagicGrallocBufferHandle())) = aRhs;
    mType = TMagicGrallocBufferHandle;
    return (*(this));
}

MaybeMagicGrallocBufferHandle&
MaybeMagicGrallocBufferHandle::operator=(const null_t& aRhs)
{
    if (MaybeDestroy(Tnull_t)) {
        new (ptr_null_t()) null_t;
    }
    (*(ptr_null_t())) = aRhs;
    mType = Tnull_t;
    return (*(this));
}

MaybeMagicGrallocBufferHandle&
MaybeMagicGrallocBufferHandle::operator=(const MaybeMagicGrallocBufferHandle& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TMagicGrallocBufferHandle:
        {
            if (MaybeDestroy(t)) {
                new (ptr_MagicGrallocBufferHandle()) MagicGrallocBufferHandle;
            }
            (*(ptr_MagicGrallocBufferHandle())) = (aRhs).get_MagicGrallocBufferHandle();
            break;
        }
    case Tnull_t:
        {
            if (MaybeDestroy(t)) {
                new (ptr_null_t()) null_t;
            }
            (*(ptr_null_t())) = (aRhs).get_null_t();
            break;
        }
    case T__None:
        {
            MaybeDestroy(t);
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            break;
        }
    }
    mType = t;
    return (*(this));
}

bool
MaybeMagicGrallocBufferHandle::operator==(const MagicGrallocBufferHandle& aRhs) const
{
    return (get_MagicGrallocBufferHandle()) == (aRhs);
}

bool
MaybeMagicGrallocBufferHandle::operator==(const null_t& aRhs) const
{
    return (get_null_t()) == (aRhs);
}

bool
MaybeMagicGrallocBufferHandle::operator==(const MaybeMagicGrallocBufferHandle& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TMagicGrallocBufferHandle:
        {
            return (get_MagicGrallocBufferHandle()) == ((aRhs).get_MagicGrallocBufferHandle());
        }
    case Tnull_t:
        {
            return (get_null_t()) == ((aRhs).get_null_t());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SurfaceDescriptorD3D10|
//
namespace mozilla {
namespace layers {
SurfaceDescriptorD3D10::SurfaceDescriptorD3D10()
{
    Init();
}

SurfaceDescriptorD3D10::~SurfaceDescriptorD3D10()
{
}

bool
SurfaceDescriptorD3D10::operator==(const SurfaceDescriptorD3D10& _o) const
{
    if ((!((handle()) == ((_o).handle())))) {
        return false;
    }
    return true;
}

void
SurfaceDescriptorD3D10::Init()
{
}

void
SurfaceDescriptorD3D10::Assign(const WindowsHandle& _handle)
{
    handle_ = _handle;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SharedTextureDescriptor|
//
namespace mozilla {
namespace layers {
SharedTextureDescriptor::SharedTextureDescriptor()
{
    Init();
}

SharedTextureDescriptor::~SharedTextureDescriptor()
{
}

bool
SharedTextureDescriptor::operator==(const SharedTextureDescriptor& _o) const
{
    if ((!((shareType()) == ((_o).shareType())))) {
        return false;
    }
    if ((!((handle()) == ((_o).handle())))) {
        return false;
    }
    if ((!((size()) == ((_o).size())))) {
        return false;
    }
    if ((!((inverted()) == ((_o).inverted())))) {
        return false;
    }
    return true;
}

void
SharedTextureDescriptor::Init()
{
}

void
SharedTextureDescriptor::Assign(
        const SharedTextureShareType& _shareType,
        const SharedTextureHandle& _handle,
        const nsIntSize& _size,
        const bool& _inverted)
{
    shareType_ = _shareType;
    handle_ = _handle;
    size_ = _size;
    inverted_ = _inverted;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SurfaceDescriptorGralloc|
//
namespace mozilla {
namespace layers {
SurfaceDescriptorGralloc::SurfaceDescriptorGralloc()
{
    Init();
}

SurfaceDescriptorGralloc::~SurfaceDescriptorGralloc()
{
}

bool
SurfaceDescriptorGralloc::operator==(const SurfaceDescriptorGralloc& _o) const
{
    if ((!((bufferParent()) == ((_o).bufferParent())))) {
        return false;
    }
    if ((!((bufferChild()) == ((_o).bufferChild())))) {
        return false;
    }
    if ((!((external()) == ((_o).external())))) {
        return false;
    }
    return true;
}

void
SurfaceDescriptorGralloc::Init()
{
    bufferParent_ = 0;
    bufferChild_ = 0;
}

void
SurfaceDescriptorGralloc::Assign(
        PGrallocBufferParent* _bufferParent,
        PGrallocBufferChild* _bufferChild,
        const bool& _external)
{
    bufferParent_ = _bufferParent;
    bufferChild_ = _bufferChild;
    external_ = _external;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SharedImageID|
//
namespace mozilla {
namespace layers {
SharedImageID::SharedImageID()
{
    Init();
}

SharedImageID::~SharedImageID()
{
}

bool
SharedImageID::operator==(const SharedImageID& _o) const
{
    if ((!((id()) == ((_o).id())))) {
        return false;
    }
    return true;
}

void
SharedImageID::Init()
{
}

void
SharedImageID::Assign(const uint64_t& _id)
{
    id_ = _id;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union SurfaceDescriptor|
//
namespace mozilla {
namespace layers {
bool
SurfaceDescriptor::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TShmem:
        {
            (ptr_Shmem())->~Shmem__tdef();
            break;
        }
    case TSurfaceDescriptorD3D10:
        {
            (ptr_SurfaceDescriptorD3D10())->~SurfaceDescriptorD3D10__tdef();
            break;
        }
    case TSurfaceDescriptorGralloc:
        {
            (ptr_SurfaceDescriptorGralloc())->~SurfaceDescriptorGralloc__tdef();
            break;
        }
    case TSurfaceDescriptorX11:
        {
            (ptr_SurfaceDescriptorX11())->~SurfaceDescriptorX11__tdef();
            break;
        }
    case TSharedTextureDescriptor:
        {
            (ptr_SharedTextureDescriptor())->~SharedTextureDescriptor__tdef();
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("not reached");
            break;
        }
    }
    return true;
}

SurfaceDescriptor::SurfaceDescriptor(Shmem& aOther)
{
    new (ptr_Shmem()) Shmem(aOther);
    mType = TShmem;
}

SurfaceDescriptor::SurfaceDescriptor(const SurfaceDescriptorD3D10& aOther)
{
    new (ptr_SurfaceDescriptorD3D10()) SurfaceDescriptorD3D10(aOther);
    mType = TSurfaceDescriptorD3D10;
}

SurfaceDescriptor::SurfaceDescriptor(const SurfaceDescriptorGralloc& aOther)
{
    new (ptr_SurfaceDescriptorGralloc()) SurfaceDescriptorGralloc(aOther);
    mType = TSurfaceDescriptorGralloc;
}

SurfaceDescriptor::SurfaceDescriptor(const SurfaceDescriptorX11& aOther)
{
    new (ptr_SurfaceDescriptorX11()) SurfaceDescriptorX11(aOther);
    mType = TSurfaceDescriptorX11;
}

SurfaceDescriptor::SurfaceDescriptor(const SharedTextureDescriptor& aOther)
{
    new (ptr_SharedTextureDescriptor()) SharedTextureDescriptor(aOther);
    mType = TSharedTextureDescriptor;
}

SurfaceDescriptor::SurfaceDescriptor(const SurfaceDescriptor& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TShmem:
        {
            new (ptr_Shmem()) Shmem((aOther).get_Shmem());
            break;
        }
    case TSurfaceDescriptorD3D10:
        {
            new (ptr_SurfaceDescriptorD3D10()) SurfaceDescriptorD3D10((aOther).get_SurfaceDescriptorD3D10());
            break;
        }
    case TSurfaceDescriptorGralloc:
        {
            new (ptr_SurfaceDescriptorGralloc()) SurfaceDescriptorGralloc((aOther).get_SurfaceDescriptorGralloc());
            break;
        }
    case TSurfaceDescriptorX11:
        {
            new (ptr_SurfaceDescriptorX11()) SurfaceDescriptorX11((aOther).get_SurfaceDescriptorX11());
            break;
        }
    case TSharedTextureDescriptor:
        {
            new (ptr_SharedTextureDescriptor()) SharedTextureDescriptor((aOther).get_SharedTextureDescriptor());
            break;
        }
    case T__None:
        {
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return;
        }
    }
    mType = (aOther).type();
}

SurfaceDescriptor::~SurfaceDescriptor()
{
    MaybeDestroy(T__None);
}

SurfaceDescriptor&
SurfaceDescriptor::operator=(Shmem& aRhs)
{
    if (MaybeDestroy(TShmem)) {
        new (ptr_Shmem()) Shmem;
    }
    (*(ptr_Shmem())) = aRhs;
    mType = TShmem;
    return (*(this));
}

SurfaceDescriptor&
SurfaceDescriptor::operator=(const SurfaceDescriptorD3D10& aRhs)
{
    if (MaybeDestroy(TSurfaceDescriptorD3D10)) {
        new (ptr_SurfaceDescriptorD3D10()) SurfaceDescriptorD3D10;
    }
    (*(ptr_SurfaceDescriptorD3D10())) = aRhs;
    mType = TSurfaceDescriptorD3D10;
    return (*(this));
}

SurfaceDescriptor&
SurfaceDescriptor::operator=(const SurfaceDescriptorGralloc& aRhs)
{
    if (MaybeDestroy(TSurfaceDescriptorGralloc)) {
        new (ptr_SurfaceDescriptorGralloc()) SurfaceDescriptorGralloc;
    }
    (*(ptr_SurfaceDescriptorGralloc())) = aRhs;
    mType = TSurfaceDescriptorGralloc;
    return (*(this));
}

SurfaceDescriptor&
SurfaceDescriptor::operator=(const SurfaceDescriptorX11& aRhs)
{
    if (MaybeDestroy(TSurfaceDescriptorX11)) {
        new (ptr_SurfaceDescriptorX11()) SurfaceDescriptorX11;
    }
    (*(ptr_SurfaceDescriptorX11())) = aRhs;
    mType = TSurfaceDescriptorX11;
    return (*(this));
}

SurfaceDescriptor&
SurfaceDescriptor::operator=(const SharedTextureDescriptor& aRhs)
{
    if (MaybeDestroy(TSharedTextureDescriptor)) {
        new (ptr_SharedTextureDescriptor()) SharedTextureDescriptor;
    }
    (*(ptr_SharedTextureDescriptor())) = aRhs;
    mType = TSharedTextureDescriptor;
    return (*(this));
}

SurfaceDescriptor&
SurfaceDescriptor::operator=(const SurfaceDescriptor& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TShmem:
        {
            if (MaybeDestroy(t)) {
                new (ptr_Shmem()) Shmem;
            }
            (*(ptr_Shmem())) = (aRhs).get_Shmem();
            break;
        }
    case TSurfaceDescriptorD3D10:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SurfaceDescriptorD3D10()) SurfaceDescriptorD3D10;
            }
            (*(ptr_SurfaceDescriptorD3D10())) = (aRhs).get_SurfaceDescriptorD3D10();
            break;
        }
    case TSurfaceDescriptorGralloc:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SurfaceDescriptorGralloc()) SurfaceDescriptorGralloc;
            }
            (*(ptr_SurfaceDescriptorGralloc())) = (aRhs).get_SurfaceDescriptorGralloc();
            break;
        }
    case TSurfaceDescriptorX11:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SurfaceDescriptorX11()) SurfaceDescriptorX11;
            }
            (*(ptr_SurfaceDescriptorX11())) = (aRhs).get_SurfaceDescriptorX11();
            break;
        }
    case TSharedTextureDescriptor:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SharedTextureDescriptor()) SharedTextureDescriptor;
            }
            (*(ptr_SharedTextureDescriptor())) = (aRhs).get_SharedTextureDescriptor();
            break;
        }
    case T__None:
        {
            MaybeDestroy(t);
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            break;
        }
    }
    mType = t;
    return (*(this));
}

bool
SurfaceDescriptor::operator==(Shmem& aRhs) const
{
    return (get_Shmem()) == (aRhs);
}

bool
SurfaceDescriptor::operator==(const SurfaceDescriptorD3D10& aRhs) const
{
    return (get_SurfaceDescriptorD3D10()) == (aRhs);
}

bool
SurfaceDescriptor::operator==(const SurfaceDescriptorGralloc& aRhs) const
{
    return (get_SurfaceDescriptorGralloc()) == (aRhs);
}

bool
SurfaceDescriptor::operator==(const SurfaceDescriptorX11& aRhs) const
{
    return (get_SurfaceDescriptorX11()) == (aRhs);
}

bool
SurfaceDescriptor::operator==(const SharedTextureDescriptor& aRhs) const
{
    return (get_SharedTextureDescriptor()) == (aRhs);
}

bool
SurfaceDescriptor::operator==(const SurfaceDescriptor& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TShmem:
        {
            return (get_Shmem()) == ((aRhs).get_Shmem());
        }
    case TSurfaceDescriptorD3D10:
        {
            return (get_SurfaceDescriptorD3D10()) == ((aRhs).get_SurfaceDescriptorD3D10());
        }
    case TSurfaceDescriptorGralloc:
        {
            return (get_SurfaceDescriptorGralloc()) == ((aRhs).get_SurfaceDescriptorGralloc());
        }
    case TSurfaceDescriptorX11:
        {
            return (get_SurfaceDescriptorX11()) == ((aRhs).get_SurfaceDescriptorX11());
        }
    case TSharedTextureDescriptor:
        {
            return (get_SharedTextureDescriptor()) == ((aRhs).get_SharedTextureDescriptor());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct YCbCrImage|
//
namespace mozilla {
namespace layers {
YCbCrImage::YCbCrImage()
{
    Init();
}

YCbCrImage::~YCbCrImage()
{
}

bool
YCbCrImage::operator==(const YCbCrImage& _o) const
{
    if ((!((data()) == ((_o).data())))) {
        return false;
    }
    if ((!((offset()) == ((_o).offset())))) {
        return false;
    }
    if ((!((picture()) == ((_o).picture())))) {
        return false;
    }
    return true;
}

void
YCbCrImage::Init()
{
}

void
YCbCrImage::Assign(
        Shmem& _data,
        const size_t& _offset,
        const nsIntRect& _picture)
{
    data_ = _data;
    offset_ = _offset;
    picture_ = _picture;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct RGBImage|
//
namespace mozilla {
namespace layers {
RGBImage::RGBImage()
{
    Init();
}

RGBImage::~RGBImage()
{
}

bool
RGBImage::operator==(const RGBImage& _o) const
{
    if ((!((data()) == ((_o).data())))) {
        return false;
    }
    if ((!((picture()) == ((_o).picture())))) {
        return false;
    }
    if ((!((rgbFormat()) == ((_o).rgbFormat())))) {
        return false;
    }
    return true;
}

void
RGBImage::Init()
{
}

void
RGBImage::Assign(
        Shmem& _data,
        const nsIntRect& _picture,
        const uint32_t& _rgbFormat)
{
    data_ = _data;
    picture_ = _picture;
    rgbFormat_ = _rgbFormat;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct YUVImage|
//
namespace mozilla {
namespace layers {
YUVImage::YUVImage()
{
    Init();
}

YUVImage::~YUVImage()
{
}

bool
YUVImage::operator==(const YUVImage& _o) const
{
    if ((!((Ydata()) == ((_o).Ydata())))) {
        return false;
    }
    if ((!((Udata()) == ((_o).Udata())))) {
        return false;
    }
    if ((!((Vdata()) == ((_o).Vdata())))) {
        return false;
    }
    if ((!((picture()) == ((_o).picture())))) {
        return false;
    }
    return true;
}

void
YUVImage::Init()
{
}

void
YUVImage::Assign(
        Shmem& _Ydata,
        Shmem& _Udata,
        Shmem& _Vdata,
        const nsIntRect& _picture)
{
    Ydata_ = _Ydata;
    Udata_ = _Udata;
    Vdata_ = _Vdata;
    picture_ = _picture;
}

} // namespace layers
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union SharedImage|
//
namespace mozilla {
namespace layers {
bool
SharedImage::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TSurfaceDescriptor:
        {
            (ptr_SurfaceDescriptor())->~SurfaceDescriptor__tdef();
            break;
        }
    case TRGBImage:
        {
            (ptr_RGBImage())->~RGBImage__tdef();
            break;
        }
    case TYCbCrImage:
        {
            (ptr_YCbCrImage())->~YCbCrImage__tdef();
            break;
        }
    case TYUVImage:
        {
            (ptr_YUVImage())->~YUVImage__tdef();
            break;
        }
    case TSharedImageID:
        {
            (ptr_SharedImageID())->~SharedImageID__tdef();
            break;
        }
    case Tnull_t:
        {
            (ptr_null_t())->~null_t__tdef();
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("not reached");
            break;
        }
    }
    return true;
}

SharedImage::SharedImage(const SurfaceDescriptor& aOther)
{
    new (ptr_SurfaceDescriptor()) SurfaceDescriptor(aOther);
    mType = TSurfaceDescriptor;
}

SharedImage::SharedImage(const RGBImage& aOther)
{
    new (ptr_RGBImage()) RGBImage(aOther);
    mType = TRGBImage;
}

SharedImage::SharedImage(const YCbCrImage& aOther)
{
    new (ptr_YCbCrImage()) YCbCrImage(aOther);
    mType = TYCbCrImage;
}

SharedImage::SharedImage(const YUVImage& aOther)
{
    new (ptr_YUVImage()) YUVImage(aOther);
    mType = TYUVImage;
}

SharedImage::SharedImage(const SharedImageID& aOther)
{
    new (ptr_SharedImageID()) SharedImageID(aOther);
    mType = TSharedImageID;
}

SharedImage::SharedImage(const null_t& aOther)
{
    new (ptr_null_t()) null_t(aOther);
    mType = Tnull_t;
}

SharedImage::SharedImage(const SharedImage& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TSurfaceDescriptor:
        {
            new (ptr_SurfaceDescriptor()) SurfaceDescriptor((aOther).get_SurfaceDescriptor());
            break;
        }
    case TRGBImage:
        {
            new (ptr_RGBImage()) RGBImage((aOther).get_RGBImage());
            break;
        }
    case TYCbCrImage:
        {
            new (ptr_YCbCrImage()) YCbCrImage((aOther).get_YCbCrImage());
            break;
        }
    case TYUVImage:
        {
            new (ptr_YUVImage()) YUVImage((aOther).get_YUVImage());
            break;
        }
    case TSharedImageID:
        {
            new (ptr_SharedImageID()) SharedImageID((aOther).get_SharedImageID());
            break;
        }
    case Tnull_t:
        {
            new (ptr_null_t()) null_t((aOther).get_null_t());
            break;
        }
    case T__None:
        {
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return;
        }
    }
    mType = (aOther).type();
}

SharedImage::~SharedImage()
{
    MaybeDestroy(T__None);
}

SharedImage&
SharedImage::operator=(const SurfaceDescriptor& aRhs)
{
    if (MaybeDestroy(TSurfaceDescriptor)) {
        new (ptr_SurfaceDescriptor()) SurfaceDescriptor;
    }
    (*(ptr_SurfaceDescriptor())) = aRhs;
    mType = TSurfaceDescriptor;
    return (*(this));
}

SharedImage&
SharedImage::operator=(const RGBImage& aRhs)
{
    if (MaybeDestroy(TRGBImage)) {
        new (ptr_RGBImage()) RGBImage;
    }
    (*(ptr_RGBImage())) = aRhs;
    mType = TRGBImage;
    return (*(this));
}

SharedImage&
SharedImage::operator=(const YCbCrImage& aRhs)
{
    if (MaybeDestroy(TYCbCrImage)) {
        new (ptr_YCbCrImage()) YCbCrImage;
    }
    (*(ptr_YCbCrImage())) = aRhs;
    mType = TYCbCrImage;
    return (*(this));
}

SharedImage&
SharedImage::operator=(const YUVImage& aRhs)
{
    if (MaybeDestroy(TYUVImage)) {
        new (ptr_YUVImage()) YUVImage;
    }
    (*(ptr_YUVImage())) = aRhs;
    mType = TYUVImage;
    return (*(this));
}

SharedImage&
SharedImage::operator=(const SharedImageID& aRhs)
{
    if (MaybeDestroy(TSharedImageID)) {
        new (ptr_SharedImageID()) SharedImageID;
    }
    (*(ptr_SharedImageID())) = aRhs;
    mType = TSharedImageID;
    return (*(this));
}

SharedImage&
SharedImage::operator=(const null_t& aRhs)
{
    if (MaybeDestroy(Tnull_t)) {
        new (ptr_null_t()) null_t;
    }
    (*(ptr_null_t())) = aRhs;
    mType = Tnull_t;
    return (*(this));
}

SharedImage&
SharedImage::operator=(const SharedImage& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TSurfaceDescriptor:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SurfaceDescriptor()) SurfaceDescriptor;
            }
            (*(ptr_SurfaceDescriptor())) = (aRhs).get_SurfaceDescriptor();
            break;
        }
    case TRGBImage:
        {
            if (MaybeDestroy(t)) {
                new (ptr_RGBImage()) RGBImage;
            }
            (*(ptr_RGBImage())) = (aRhs).get_RGBImage();
            break;
        }
    case TYCbCrImage:
        {
            if (MaybeDestroy(t)) {
                new (ptr_YCbCrImage()) YCbCrImage;
            }
            (*(ptr_YCbCrImage())) = (aRhs).get_YCbCrImage();
            break;
        }
    case TYUVImage:
        {
            if (MaybeDestroy(t)) {
                new (ptr_YUVImage()) YUVImage;
            }
            (*(ptr_YUVImage())) = (aRhs).get_YUVImage();
            break;
        }
    case TSharedImageID:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SharedImageID()) SharedImageID;
            }
            (*(ptr_SharedImageID())) = (aRhs).get_SharedImageID();
            break;
        }
    case Tnull_t:
        {
            if (MaybeDestroy(t)) {
                new (ptr_null_t()) null_t;
            }
            (*(ptr_null_t())) = (aRhs).get_null_t();
            break;
        }
    case T__None:
        {
            MaybeDestroy(t);
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            break;
        }
    }
    mType = t;
    return (*(this));
}

bool
SharedImage::operator==(const SurfaceDescriptor& aRhs) const
{
    return (get_SurfaceDescriptor()) == (aRhs);
}

bool
SharedImage::operator==(const RGBImage& aRhs) const
{
    return (get_RGBImage()) == (aRhs);
}

bool
SharedImage::operator==(const YCbCrImage& aRhs) const
{
    return (get_YCbCrImage()) == (aRhs);
}

bool
SharedImage::operator==(const YUVImage& aRhs) const
{
    return (get_YUVImage()) == (aRhs);
}

bool
SharedImage::operator==(const SharedImageID& aRhs) const
{
    return (get_SharedImageID()) == (aRhs);
}

bool
SharedImage::operator==(const null_t& aRhs) const
{
    return (get_null_t()) == (aRhs);
}

bool
SharedImage::operator==(const SharedImage& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TSurfaceDescriptor:
        {
            return (get_SurfaceDescriptor()) == ((aRhs).get_SurfaceDescriptor());
        }
    case TRGBImage:
        {
            return (get_RGBImage()) == ((aRhs).get_RGBImage());
        }
    case TYCbCrImage:
        {
            return (get_YCbCrImage()) == ((aRhs).get_YCbCrImage());
        }
    case TYUVImage:
        {
            return (get_YUVImage()) == ((aRhs).get_YUVImage());
        }
    case TSharedImageID:
        {
            return (get_SharedImageID()) == ((aRhs).get_SharedImageID());
        }
    case Tnull_t:
        {
            return (get_null_t()) == ((aRhs).get_null_t());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace layers
} // namespace mozilla