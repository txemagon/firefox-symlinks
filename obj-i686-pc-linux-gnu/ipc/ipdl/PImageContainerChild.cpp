//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/layers/PImageContainerChild.h"

#include "mozilla/layers/PGrallocBufferChild.h"
#include "mozilla/layers/PImageBridgeChild.h"

typedef IPC::Message Message;
typedef mozilla::ipc::RPCChannel Channel;
typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
typedef base::ProcessHandle ProcessHandle;
typedef mozilla::ipc::AsyncChannel AsyncChannel;
typedef mozilla::ipc::SharedMemory SharedMemory;
typedef mozilla::ipc::Trigger Trigger;
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
using mozilla::layers::PGrallocBufferChild;
using mozilla::layers::PImageBridgeChild;

namespace mozilla {
namespace layers {


void
PImageContainerChild::ActorDestroy(ActorDestroyReason why)
{
}

PImageContainerChild::PImageContainerChild() :
    mId(0),
    mState(PImageContainer::__Dead)
{
    MOZ_COUNT_CTOR(PImageContainerChild);
}

PImageContainerChild::~PImageContainerChild()
{
    MOZ_COUNT_DTOR(PImageContainerChild);
}

PImageBridgeChild*
PImageContainerChild::Manager() const
{
    return static_cast<PImageBridgeChild*>(mManager);
}

void
PImageContainerChild::ManagedPGrallocBufferChild(InfallibleTArray<PGrallocBufferChild*>& aArr) const
{
    aArr = mManagedPGrallocBufferChild;
}

const InfallibleTArray<PGrallocBufferChild*>&
PImageContainerChild::ManagedPGrallocBufferChild() const
{
    return mManagedPGrallocBufferChild;
}

PImageContainer::State
PImageContainerChild::state()
{
    return mState;
}

PGrallocBufferChild*
PImageContainerChild::SendPGrallocBufferConstructor(
        const gfxIntSize& size,
        const gfxContentType& content,
        MaybeMagicGrallocBufferHandle* handle)
{
    return SendPGrallocBufferConstructor(AllocPGrallocBuffer(size, content, handle), size, content, handle);
}

PGrallocBufferChild*
PImageContainerChild::SendPGrallocBufferConstructor(
        PGrallocBufferChild* actor,
        const gfxIntSize& size,
        const gfxContentType& content,
        MaybeMagicGrallocBufferHandle* handle)
{
    if ((!(actor))) {
        return 0;
    }
    (actor)->mId = Register(actor);
    (actor)->mManager = this;
    (actor)->mChannel = mChannel;
    (mManagedPGrallocBufferChild).InsertElementSorted(actor);
    (actor)->mState = mozilla::layers::PGrallocBuffer::__Start;

    PImageContainer::Msg_PGrallocBufferConstructor* __msg = new PImageContainer::Msg_PGrallocBufferConstructor();

    Write(actor, __msg, false);
    Write(size, __msg);
    Write(content, __msg);

    (__msg)->set_routing_id(mId);
    (__msg)->set_sync();


    Message __reply;

    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PImageContainerChild] Sending ", stderr);
    }
    if ((!(PImageContainer::Transition(mState, Trigger(Trigger::Recv, PImageContainer::Msg_PGrallocBufferConstructor__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg, (&(__reply)));
    if ((!(__sendok))) {
        (actor)->DestroySubtree(FailedConstructor);
        (actor)->DeallocSubtree();
        ((actor)->mManager)->RemoveManagee(PGrallocBufferMsgStart, actor);
        return 0;
    }

    if (mozilla::ipc::LoggingEnabled()) {
        (static_cast<const PImageContainer::Reply_PGrallocBufferConstructor*>((&(__reply))))->Log("[PImageContainerChild] Received reply ", stderr);
    }

    void* __iter = 0;
    if ((!(Read(handle, (&(__reply)), (&(__iter)))))) {
        if (true) {
            (actor)->DestroySubtree(FailedConstructor);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PGrallocBufferMsgStart, actor);
            return 0;
        }
    }
    (__reply).EndRead(__iter);
    return actor;
}

bool
PImageContainerChild::SendPublishImage(const SharedImage& image)
{
    PImageContainer::Msg_PublishImage* __msg = new PImageContainer::Msg_PublishImage();

    Write(image, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PImageContainerChild] Sending ", stderr);
    }
    if ((!(PImageContainer::Transition(mState, Trigger(Trigger::Recv, PImageContainer::Msg_PublishImage__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PImageContainerChild::SendFlush()
{
    PImageContainer::Msg_Flush* __msg = new PImageContainer::Msg_Flush();


    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PImageContainerChild] Sending ", stderr);
    }
    if ((!(PImageContainer::Transition(mState, Trigger(Trigger::Recv, PImageContainer::Msg_Flush__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PImageContainerChild::SendStop()
{
    PImageContainer::Msg_Stop* __msg = new PImageContainer::Msg_Stop();


    (__msg)->set_routing_id(mId);
    (__msg)->set_sync();


    Message __reply;

    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PImageContainerChild] Sending ", stderr);
    }
    if ((!(PImageContainer::Transition(mState, Trigger(Trigger::Recv, PImageContainer::Msg_Stop__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg, (&(__reply)));
    if ((!(__sendok))) {
        return false;
    }

    if (mozilla::ipc::LoggingEnabled()) {
        (static_cast<const PImageContainer::Reply_Stop*>((&(__reply))))->Log("[PImageContainerChild] Received reply ", stderr);
    }

    return true;
}

bool
PImageContainerChild::Send__delete__(PImageContainerChild* actor)
{
    if ((!(actor))) {
        return false;
    }

    PImageContainer::Msg___delete__* __msg = new PImageContainer::Msg___delete__();

    (actor)->Write(actor, __msg, false);

    (__msg)->set_routing_id((actor)->mId);
    (__msg)->set_sync();


    Message __reply;

    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PImageContainerChild] Sending ", stderr);
    }
    if ((!(PImageContainer::Transition((actor)->mState, Trigger(Trigger::Recv, PImageContainer::Msg___delete____ID), (&((actor)->mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = ((actor)->mChannel)->Send(__msg, (&(__reply)));
    if (false) {

        if (mozilla::ipc::LoggingEnabled()) {
            (static_cast<const PImageContainer::Reply___delete__*>((&(__reply))))->Log("[PImageContainerChild] Received reply ", stderr);
        }

        __sendok &= false;
    }
    (actor)->DestroySubtree(Deletion);
    (actor)->DeallocSubtree();
    ((actor)->mManager)->RemoveManagee(PImageContainerMsgStart, actor);

    return __sendok;
}

int32_t
PImageContainerChild::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PImageContainerChild::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PImageContainerChild::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PImageContainerChild::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PImageContainerChild::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    switch (aProtocolId) {
    case PGrallocBufferMsgStart:
        {
            PGrallocBufferChild* actor = static_cast<PGrallocBufferChild*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPGrallocBufferChild).NoIndex) != ((mManagedPGrallocBufferChild).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPGrallocBufferChild).RemoveElementSorted(actor);
            DeallocPGrallocBuffer(actor);
            return;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return;
        }
    }
}

Shmem::SharedMemory*
PImageContainerChild::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PImageContainerChild::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PImageContainerChild::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PImageContainerChild::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PImageContainerChild::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PImageContainerChild::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PImageContainerChild::GetIPCChannel()
{
    return mChannel;
}

PImageContainerChild::Result
PImageContainerChild::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PImageContainer::Msg_ReturnImage__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PImageContainer::Msg_ReturnImage");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PImageContainer::Msg_ReturnImage*>((&(__msg))))->Log("[PImageContainerChild] Received ", stderr);
            }

            void* __iter = 0;
            SharedImage image;

            if ((!(Read((&(image)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PImageContainer::Transition(mState, Trigger(Trigger::Send, PImageContainer::Msg_ReturnImage__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvReturnImage(image)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for ReturnImage returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    default:
        {
            return MsgNotKnown;
        }
    }
}

PImageContainerChild::Result
PImageContainerChild::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PImageContainerChild::Result
PImageContainerChild::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PImageContainerChild::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PImageContainerChild::GetProtocolTypeId()
{
    return PImageContainerMsgStart;
}

bool
PImageContainerChild::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PImageContainerChild::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PImageContainerChild::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PImageContainerChild::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PImageContainerChild::AllocShmem(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        Shmem* aMem)
{
    Shmem::id_t aId;
    nsAutoPtr<Shmem::SharedMemory> rawmem(CreateSharedMemory(aSize, aType, false, (&(aId))));
    if ((!(rawmem))) {
        return false;
    }

    (*(aMem)) = Shmem(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead(), (rawmem).forget(), aId);
    return true;
}

bool
PImageContainerChild::AllocUnsafeShmem(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        Shmem* aMem)
{
    Shmem::id_t aId;
    nsAutoPtr<Shmem::SharedMemory> rawmem(CreateSharedMemory(aSize, aType, true, (&(aId))));
    if ((!(rawmem))) {
        return false;
    }

    (*(aMem)) = Shmem(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead(), (rawmem).forget(), aId);
    return true;
}

bool
PImageContainerChild::AdoptShmem(
        Shmem& aMem,
        Shmem* aOutMem)
{
    Shmem::SharedMemory* rawmem = (aMem).Segment(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    if (((!(rawmem))) || (IsTrackingSharedMemory(rawmem))) {
        NS_RUNTIMEABORT("bad Shmem");
    }

    Shmem::id_t aId;
    if ((!(AdoptSharedMemory(rawmem, (&(aId)))))) {
        return false;
    }

    (*(aOutMem)) = Shmem(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead(), rawmem, aId);
    return true;
}

bool
PImageContainerChild::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PImageContainerChild::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_RUNTIMEABORT("[PImageContainerChild] abort()ing as a result");
}

void
PImageContainerChild::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    ActorDestroyReason subtreewhy = (((why) == (Deletion)) || ((why) == (FailedConstructor)) ? AncestorDeletion : why);

    {
        // Recursively shutting down PGrallocBuffer kids
        InfallibleTArray<PGrallocBufferChild*> kids(mManagedPGrallocBufferChild);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PImageContainerChild::DeallocSubtree()
{
    {
        // Recursively deleting PGrallocBuffer kids
        InfallibleTArray<PGrallocBufferChild*>& kids = mManagedPGrallocBufferChild;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPGrallocBuffer(kids[i]);
        }
        (mManagedPGrallocBufferChild).Clear();
    }
}

void
PImageContainerChild::Write(
        const SurfaceDescriptor& __v,
        Message* __msg)
{
    typedef SurfaceDescriptor __type;
    Write(int((__v).type()), __msg);

    switch ((__v).type()) {
    case __type::TShmem:
        {
            Write((__v).get_Shmem(), __msg);
            return;
        }
    case __type::TSurfaceDescriptorD3D10:
        {
            Write((__v).get_SurfaceDescriptorD3D10(), __msg);
            return;
        }
    case __type::TSurfaceDescriptorGralloc:
        {
            Write((__v).get_SurfaceDescriptorGralloc(), __msg);
            return;
        }
    case __type::TSurfaceDescriptorX11:
        {
            Write((__v).get_SurfaceDescriptorX11(), __msg);
            return;
        }
    case __type::TSharedTextureDescriptor:
        {
            Write((__v).get_SharedTextureDescriptor(), __msg);
            return;
        }
    default:
        {
            NS_RUNTIMEABORT("unknown union type");
            return;
        }
    }
}

bool
PImageContainerChild::Read(
        SurfaceDescriptor* __v,
        const Message* __msg,
        void** __iter)
{
    typedef SurfaceDescriptor __type;
    int type;
    if ((!(Read((&(type)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    switch (type) {
    case __type::TShmem:
        {
            Shmem tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_Shmem())), __msg, __iter);
        }
    case __type::TSurfaceDescriptorD3D10:
        {
            SurfaceDescriptorD3D10 tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_SurfaceDescriptorD3D10())), __msg, __iter);
        }
    case __type::TSurfaceDescriptorGralloc:
        {
            SurfaceDescriptorGralloc tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_SurfaceDescriptorGralloc())), __msg, __iter);
        }
    case __type::TSurfaceDescriptorX11:
        {
            SurfaceDescriptorX11 tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_SurfaceDescriptorX11())), __msg, __iter);
        }
    case __type::TSharedTextureDescriptor:
        {
            SharedTextureDescriptor tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_SharedTextureDescriptor())), __msg, __iter);
        }
    default:
        {
            mozilla::ipc::ProtocolErrorBreakpoint("unknown union type");
            return false;
        }
    }
}

void
PImageContainerChild::Write(
        const MaybeMagicGrallocBufferHandle& __v,
        Message* __msg)
{
    typedef MaybeMagicGrallocBufferHandle __type;
    Write(int((__v).type()), __msg);

    switch ((__v).type()) {
    case __type::TMagicGrallocBufferHandle:
        {
            Write((__v).get_MagicGrallocBufferHandle(), __msg);
            return;
        }
    case __type::Tnull_t:
        {
            Write((__v).get_null_t(), __msg);
            return;
        }
    default:
        {
            NS_RUNTIMEABORT("unknown union type");
            return;
        }
    }
}

bool
PImageContainerChild::Read(
        MaybeMagicGrallocBufferHandle* __v,
        const Message* __msg,
        void** __iter)
{
    typedef MaybeMagicGrallocBufferHandle __type;
    int type;
    if ((!(Read((&(type)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    switch (type) {
    case __type::TMagicGrallocBufferHandle:
        {
            MagicGrallocBufferHandle tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_MagicGrallocBufferHandle())), __msg, __iter);
        }
    case __type::Tnull_t:
        {
            null_t tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_null_t())), __msg, __iter);
        }
    default:
        {
            mozilla::ipc::ProtocolErrorBreakpoint("unknown union type");
            return false;
        }
    }
}

void
PImageContainerChild::Write(
        Shmem& __v,
        Message* __msg)
{
    IPC::WriteParam(__msg, __v);
    (__v).RevokeRights(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    (__v).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
}

bool
PImageContainerChild::Read(
        Shmem* __v,
        const Message* __msg,
        void** __iter)
{
    Shmem tmp;
    if ((!(IPC::ReadParam(__msg, __iter, (&(tmp)))))) {
        return false;
    }

    Shmem::id_t shmemid = (tmp).Id(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    Shmem::SharedMemory* rawmem = LookupSharedMemory(shmemid);
    if (rawmem) {
        (*(__v)) = Shmem(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead(), rawmem, shmemid);
        return true;
    }
    return false;
}

void
PImageContainerChild::Write(
        PImageContainerChild* __v,
        Message* __msg,
        bool __nullable)
{
    int32_t id;
    if ((!(__v))) {
        if ((!(__nullable))) {
            NS_RUNTIMEABORT("NULL actor value passed to non-nullable param");
        }
        id = 0;
    }
    else {
        id = (__v)->mId;
        if ((1) == (id)) {
            NS_RUNTIMEABORT("actor has been |delete|d");
        }
    }

    Write(id, __msg);
}

bool
PImageContainerChild::Read(
        PImageContainerChild** __v,
        const Message* __msg,
        void** __iter,
        bool __nullable)
{
    int32_t id;
    if ((!(Read((&(id)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if (((1) == (id)) || (((0) == (id)) && ((!(__nullable))))) {
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PImageContainer");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PImageContainer");
        return false;
    }

    if ((PImageContainerMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PImageContainer has different type");
        return false;
    }

    (*(__v)) = static_cast<PImageContainerChild*>(listener);
    return true;
}

void
PImageContainerChild::Write(
        const SharedImageID& __v,
        Message* __msg)
{
    Write((__v).id(), __msg);
}

bool
PImageContainerChild::Read(
        SharedImageID* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->id())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        const SharedImage& __v,
        Message* __msg)
{
    typedef SharedImage __type;
    Write(int((__v).type()), __msg);

    switch ((__v).type()) {
    case __type::TSurfaceDescriptor:
        {
            Write((__v).get_SurfaceDescriptor(), __msg);
            return;
        }
    case __type::TRGBImage:
        {
            Write((__v).get_RGBImage(), __msg);
            return;
        }
    case __type::TYCbCrImage:
        {
            Write((__v).get_YCbCrImage(), __msg);
            return;
        }
    case __type::TYUVImage:
        {
            Write((__v).get_YUVImage(), __msg);
            return;
        }
    case __type::TSharedImageID:
        {
            Write((__v).get_SharedImageID(), __msg);
            return;
        }
    case __type::Tnull_t:
        {
            Write((__v).get_null_t(), __msg);
            return;
        }
    default:
        {
            NS_RUNTIMEABORT("unknown union type");
            return;
        }
    }
}

bool
PImageContainerChild::Read(
        SharedImage* __v,
        const Message* __msg,
        void** __iter)
{
    typedef SharedImage __type;
    int type;
    if ((!(Read((&(type)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    switch (type) {
    case __type::TSurfaceDescriptor:
        {
            SurfaceDescriptor tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_SurfaceDescriptor())), __msg, __iter);
        }
    case __type::TRGBImage:
        {
            RGBImage tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_RGBImage())), __msg, __iter);
        }
    case __type::TYCbCrImage:
        {
            YCbCrImage tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_YCbCrImage())), __msg, __iter);
        }
    case __type::TYUVImage:
        {
            YUVImage tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_YUVImage())), __msg, __iter);
        }
    case __type::TSharedImageID:
        {
            SharedImageID tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_SharedImageID())), __msg, __iter);
        }
    case __type::Tnull_t:
        {
            null_t tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_null_t())), __msg, __iter);
        }
    default:
        {
            mozilla::ipc::ProtocolErrorBreakpoint("unknown union type");
            return false;
        }
    }
}

void
PImageContainerChild::Write(
        const SharedTextureDescriptor& __v,
        Message* __msg)
{
    Write((__v).shareType(), __msg);
    Write((__v).handle(), __msg);
    Write((__v).size(), __msg);
    Write((__v).inverted(), __msg);
}

bool
PImageContainerChild::Read(
        SharedTextureDescriptor* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->shareType())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->handle())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->size())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->inverted())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        const YCbCrImage& __v,
        Message* __msg)
{
    Write((__v).data(), __msg);
    Write((__v).offset(), __msg);
    Write((__v).picture(), __msg);
}

bool
PImageContainerChild::Read(
        YCbCrImage* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->data())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->offset())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->picture())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        const RGBImage& __v,
        Message* __msg)
{
    Write((__v).data(), __msg);
    Write((__v).picture(), __msg);
    Write((__v).rgbFormat(), __msg);
}

bool
PImageContainerChild::Read(
        RGBImage* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->data())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->picture())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->rgbFormat())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        const SurfaceDescriptorD3D10& __v,
        Message* __msg)
{
    Write((__v).handle(), __msg);
}

bool
PImageContainerChild::Read(
        SurfaceDescriptorD3D10* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->handle())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        const SurfaceDescriptorGralloc& __v,
        Message* __msg)
{
    // skipping actor field that's meaningless on this side
    Write((__v).bufferChild(), __msg, false);
    Write((__v).external(), __msg);
}

bool
PImageContainerChild::Read(
        SurfaceDescriptorGralloc* __v,
        const Message* __msg,
        void** __iter)
{
    // skipping actor field that's meaningless on this side
    if ((!(Read((&((__v)->bufferChild())), __msg, __iter, false)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->external())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        const YUVImage& __v,
        Message* __msg)
{
    Write((__v).Ydata(), __msg);
    Write((__v).Udata(), __msg);
    Write((__v).Vdata(), __msg);
    Write((__v).picture(), __msg);
}

bool
PImageContainerChild::Read(
        YUVImage* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->Ydata())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->Udata())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->Vdata())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->picture())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PImageContainerChild::Write(
        PGrallocBufferChild* __v,
        Message* __msg,
        bool __nullable)
{
    int32_t id;
    if ((!(__v))) {
        if ((!(__nullable))) {
            NS_RUNTIMEABORT("NULL actor value passed to non-nullable param");
        }
        id = 0;
    }
    else {
        id = (__v)->mId;
        if ((1) == (id)) {
            NS_RUNTIMEABORT("actor has been |delete|d");
        }
    }

    Write(id, __msg);
}

bool
PImageContainerChild::Read(
        PGrallocBufferChild** __v,
        const Message* __msg,
        void** __iter,
        bool __nullable)
{
    int32_t id;
    if ((!(Read((&(id)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if (((1) == (id)) || (((0) == (id)) && ((!(__nullable))))) {
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PImageContainer");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PGrallocBuffer");
        return false;
    }

    if ((PGrallocBufferMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PGrallocBuffer has different type");
        return false;
    }

    (*(__v)) = static_cast<PGrallocBufferChild*>(listener);
    return true;
}



} // namespace layers
} // namespace mozilla