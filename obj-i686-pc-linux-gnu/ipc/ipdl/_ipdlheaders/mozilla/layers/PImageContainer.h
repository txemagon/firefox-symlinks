//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PImageContainer_h
#define PImageContainer_h

#include "mozilla/Attributes.h"
#include "base/basictypes.h"
#include "prtime.h"
#include "nscore.h"
#include "IPCMessageStart.h"
#include "ipc/IPCMessageUtils.h"
#include "nsAutoPtr.h"
#include "nsStringGlue.h"
#include "nsTArray.h"
#include "nsIFile.h"
#include "mozilla/ipc/ProtocolUtils.h"
#include "mozilla/layers/LayersSurfaces.h"

//-----------------------------------------------------------------------------
// Code common to PImageContainerChild and PImageContainerParent
//
namespace mozilla {
namespace layers {
namespace PImageContainer {

enum State {
    __Dead,
    __Null,
    __Error,
    __Dying,
    __Start = __Null
};

enum MessageType {
    PImageContainerStart = PImageContainerMsgStart << 16,
    PImageContainerPreStart = (PImageContainerMsgStart << 16) - 1,
    Msg_ReturnImage__ID,
    Msg_PGrallocBufferConstructor__ID,
    Reply_PGrallocBufferConstructor__ID,
    Msg_PublishImage__ID,
    Msg_Flush__ID,
    Msg_Stop__ID,
    Reply_Stop__ID,
    Msg___delete____ID,
    Reply___delete____ID,
    PImageContainerEnd
};

bool
Transition(
        State from,
        mozilla::ipc::Trigger trigger,
        State* next);

class Msg_ReturnImage :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Msg_ReturnImage__ID
    };
    Msg_ReturnImage() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Msg_ReturnImage")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_ReturnImage(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PGrallocBufferConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Msg_PGrallocBufferConstructor__ID
    };
    Msg_PGrallocBufferConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Msg_PGrallocBufferConstructor")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_PGrallocBufferConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PGrallocBufferConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Reply_PGrallocBufferConstructor__ID
    };
    Reply_PGrallocBufferConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Reply_PGrallocBufferConstructor")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Reply_PGrallocBufferConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PublishImage :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Msg_PublishImage__ID
    };
    Msg_PublishImage() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Msg_PublishImage")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_PublishImage(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_Flush :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Msg_Flush__ID
    };
    Msg_Flush() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Msg_Flush")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_Flush(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_Stop :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Msg_Stop__ID
    };
    Msg_Stop() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Msg_Stop")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_Stop(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_Stop :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Reply_Stop__ID
    };
    Reply_Stop() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Reply_Stop")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Reply_Stop(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg___delete__ :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Msg___delete____ID
    };
    Msg___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Msg___delete__")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg___delete__(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply___delete__ :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::layers::FrameMetrics FrameMetrics;
    typedef mozilla::GraphicsFilterType GraphicsFilterType;
    typedef mozilla::layers::MagicGrallocBufferHandle MagicGrallocBufferHandle;
    typedef mozilla::layers::MaybeMagicGrallocBufferHandle MaybeMagicGrallocBufferHandle;
    typedef mozilla::layers::RGBImage RGBImage;
    typedef mozilla::layers::SharedImage SharedImage;
    typedef mozilla::layers::SharedImageID SharedImageID;
    typedef mozilla::layers::SharedTextureDescriptor SharedTextureDescriptor;
    typedef mozilla::gl::SharedTextureHandle SharedTextureHandle;
    typedef mozilla::gl::GLContext::SharedTextureShareType SharedTextureShareType;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::layers::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::layers::SurfaceDescriptorD3D10 SurfaceDescriptorD3D10;
    typedef mozilla::layers::SurfaceDescriptorGralloc SurfaceDescriptorGralloc;
    typedef mozilla::layers::SurfaceDescriptorX11 SurfaceDescriptorX11;
    typedef mozilla::WindowsHandle WindowsHandle;
    typedef mozilla::layers::YCbCrImage YCbCrImage;
    typedef mozilla::layers::YUVImage YUVImage;
    typedef mozilla::gfxContentType gfxContentType;
    typedef mozilla::null_t null_t;

public:
    enum {
        ID = Reply___delete____ID
    };
    Reply___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PImageContainer::Reply___delete__")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Reply___delete__(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};



} // namespace PImageContainer
} // namespace layers
} // namespace mozilla

#endif // ifndef PImageContainer_h