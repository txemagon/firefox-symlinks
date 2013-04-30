//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/net/PRemoteOpenFileChild.h"

#include "mozilla/net/PNeckoChild.h"

typedef IPC::Message Message;
typedef mozilla::ipc::RPCChannel Channel;
typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
typedef base::ProcessHandle ProcessHandle;
typedef mozilla::ipc::AsyncChannel AsyncChannel;
typedef mozilla::ipc::SharedMemory SharedMemory;
typedef mozilla::ipc::Trigger Trigger;
typedef mozilla::ipc::ActorHandle ActorHandle;
typedef mozilla::ipc::FileDescriptor FileDescriptor;
typedef mozilla::ipc::Shmem Shmem;
using mozilla::net::PNeckoChild;

namespace mozilla {
namespace net {


void
PRemoteOpenFileChild::ActorDestroy(ActorDestroyReason why)
{
}

PRemoteOpenFileChild::PRemoteOpenFileChild() :
    mId(0),
    mState(PRemoteOpenFile::__Dead)
{
    MOZ_COUNT_CTOR(PRemoteOpenFileChild);
}

PRemoteOpenFileChild::~PRemoteOpenFileChild()
{
    MOZ_COUNT_DTOR(PRemoteOpenFileChild);
}

PNeckoChild*
PRemoteOpenFileChild::Manager() const
{
    return static_cast<PNeckoChild*>(mManager);
}

PRemoteOpenFile::State
PRemoteOpenFileChild::state()
{
    return mState;
}

bool
PRemoteOpenFileChild::SendAsyncOpenFile()
{
    PRemoteOpenFile::Msg_AsyncOpenFile* __msg = new PRemoteOpenFile::Msg_AsyncOpenFile();


    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PRemoteOpenFileChild] Sending ", stderr);
    }
    if ((!(PRemoteOpenFile::Transition(mState, Trigger(Trigger::Recv, PRemoteOpenFile::Msg_AsyncOpenFile__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PRemoteOpenFileChild::Send__delete__(PRemoteOpenFileChild* actor)
{
    if ((!(actor))) {
        return false;
    }

    if ((!(actor))) {
        return false;
    }

    PRemoteOpenFile::Msg___delete__* __msg = new PRemoteOpenFile::Msg___delete__();

    (actor)->Write(actor, __msg, false);

    (__msg)->set_routing_id((actor)->mId);


    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PRemoteOpenFileChild] Sending ", stderr);
    }
    if ((!(PRemoteOpenFile::Transition((actor)->mState, Trigger(Trigger::Recv, PRemoteOpenFile::Msg___delete____ID), (&((actor)->mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = ((actor)->mChannel)->Send(__msg);

    (actor)->DestroySubtree(Deletion);
    (actor)->DeallocSubtree();
    ((actor)->mManager)->RemoveManagee(PRemoteOpenFileMsgStart, actor);
    return __sendok;
}

int32_t
PRemoteOpenFileChild::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PRemoteOpenFileChild::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PRemoteOpenFileChild::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PRemoteOpenFileChild::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PRemoteOpenFileChild::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    NS_RUNTIMEABORT("unreached");
    return;
}

Shmem::SharedMemory*
PRemoteOpenFileChild::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PRemoteOpenFileChild::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PRemoteOpenFileChild::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PRemoteOpenFileChild::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PRemoteOpenFileChild::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PRemoteOpenFileChild::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PRemoteOpenFileChild::GetIPCChannel()
{
    return mChannel;
}

PRemoteOpenFileChild::Result
PRemoteOpenFileChild::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PRemoteOpenFile::Reply___delete____ID:
        {
            return MsgProcessed;
        }
    case PRemoteOpenFile::Msg_FileOpened__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PRemoteOpenFile::Msg_FileOpened");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PRemoteOpenFile::Msg_FileOpened*>((&(__msg))))->Log("[PRemoteOpenFileChild] Received ", stderr);
            }

            void* __iter = 0;
            FileDescriptor fd;
            nsresult rv;

            if ((!(Read((&(fd)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(rv)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PRemoteOpenFile::Transition(mState, Trigger(Trigger::Send, PRemoteOpenFile::Msg_FileOpened__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvFileOpened(fd, rv)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for FileOpened returned error code");
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

PRemoteOpenFileChild::Result
PRemoteOpenFileChild::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PRemoteOpenFileChild::Result
PRemoteOpenFileChild::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PRemoteOpenFileChild::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PRemoteOpenFileChild::GetProtocolTypeId()
{
    return PRemoteOpenFileMsgStart;
}

bool
PRemoteOpenFileChild::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PRemoteOpenFileChild::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PRemoteOpenFileChild::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PRemoteOpenFileChild::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PRemoteOpenFileChild::AllocShmem(
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
PRemoteOpenFileChild::AllocUnsafeShmem(
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
PRemoteOpenFileChild::AdoptShmem(
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
PRemoteOpenFileChild::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PRemoteOpenFileChild::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_RUNTIMEABORT("[PRemoteOpenFileChild] abort()ing as a result");
}

void
PRemoteOpenFileChild::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PRemoteOpenFileChild::DeallocSubtree()
{
}

void
PRemoteOpenFileChild::Write(
        PRemoteOpenFileChild* __v,
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
PRemoteOpenFileChild::Read(
        PRemoteOpenFileChild** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PRemoteOpenFile");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PRemoteOpenFile");
        return false;
    }

    if ((PRemoteOpenFileMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PRemoteOpenFile has different type");
        return false;
    }

    (*(__v)) = static_cast<PRemoteOpenFileChild*>(listener);
    return true;
}

void
PRemoteOpenFileChild::Write(
        const FileDescriptor& __v,
        Message* __msg)
{
    FileDescriptor::PickleType pfd = (__v).ShareTo(FileDescriptor::IPDLPrivate(), OtherProcess());
    IPC::WriteParam(__msg, pfd);
}

bool
PRemoteOpenFileChild::Read(
        FileDescriptor* __v,
        const Message* __msg,
        void** __iter)
{
    FileDescriptor::PickleType pfd;
    if ((!(IPC::ReadParam(__msg, __iter, (&(pfd)))))) {
        return false;
    }

    FileDescriptor fd = FileDescriptor(FileDescriptor::IPDLPrivate(), pfd);
    if ((!((fd).IsValid()))) {
        return false;
    }

    (*(__v)) = fd;
    return true;
}



} // namespace net
} // namespace mozilla