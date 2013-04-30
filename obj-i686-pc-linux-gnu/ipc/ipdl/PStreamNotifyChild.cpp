//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/plugins/PStreamNotifyChild.h"

#include "mozilla/plugins/PPluginInstanceChild.h"

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
using mozilla::plugins::PPluginInstanceChild;

namespace mozilla {
namespace plugins {


bool
PStreamNotifyChild::Recv__delete__(const NPReason& reason)
{
    return true;
}

void
PStreamNotifyChild::ActorDestroy(ActorDestroyReason why)
{
}

PStreamNotifyChild::PStreamNotifyChild() :
    mId(0),
    mState(PStreamNotify::__Dead)
{
    MOZ_COUNT_CTOR(PStreamNotifyChild);
}

PStreamNotifyChild::~PStreamNotifyChild()
{
    MOZ_COUNT_DTOR(PStreamNotifyChild);
}

PPluginInstanceChild*
PStreamNotifyChild::Manager() const
{
    return static_cast<PPluginInstanceChild*>(mManager);
}

PStreamNotify::State
PStreamNotifyChild::state()
{
    return mState;
}

bool
PStreamNotifyChild::SendRedirectNotifyResponse(const bool& allow)
{
    PStreamNotify::Msg_RedirectNotifyResponse* __msg = new PStreamNotify::Msg_RedirectNotifyResponse();

    Write(allow, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PStreamNotifyChild] Sending ", stderr);
    }
    if ((!(PStreamNotify::Transition(mState, Trigger(Trigger::Recv, PStreamNotify::Msg_RedirectNotifyResponse__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

int32_t
PStreamNotifyChild::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PStreamNotifyChild::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PStreamNotifyChild::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PStreamNotifyChild::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PStreamNotifyChild::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    NS_RUNTIMEABORT("unreached");
    return;
}

Shmem::SharedMemory*
PStreamNotifyChild::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PStreamNotifyChild::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PStreamNotifyChild::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PStreamNotifyChild::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PStreamNotifyChild::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PStreamNotifyChild::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PStreamNotifyChild::GetIPCChannel()
{
    return mChannel;
}

PStreamNotifyChild::Result
PStreamNotifyChild::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PStreamNotify::Msg_RedirectNotify__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PStreamNotify::Msg_RedirectNotify");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PStreamNotify::Msg_RedirectNotify*>((&(__msg))))->Log("[PStreamNotifyChild] Received ", stderr);
            }

            void* __iter = 0;
            nsCString url;
            int32_t status;

            if ((!(Read((&(url)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(status)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PStreamNotify::Transition(mState, Trigger(Trigger::Send, PStreamNotify::Msg_RedirectNotify__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvRedirectNotify(url, status)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for RedirectNotify returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PStreamNotify::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PStreamNotify::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PStreamNotify::Msg___delete__*>((&(__msg))))->Log("[PStreamNotifyChild] Received ", stderr);
            }

            void* __iter = 0;
            PStreamNotifyChild* actor;
            NPReason reason;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(reason)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PStreamNotify::Transition(mState, Trigger(Trigger::Send, PStreamNotify::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Recv__delete__(reason)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PStreamNotifyMsgStart, actor);


            return MsgProcessed;
        }
    default:
        {
            return MsgNotKnown;
        }
    }
}

PStreamNotifyChild::Result
PStreamNotifyChild::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PStreamNotifyChild::Result
PStreamNotifyChild::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PStreamNotifyChild::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PStreamNotifyChild::GetProtocolTypeId()
{
    return PStreamNotifyMsgStart;
}

bool
PStreamNotifyChild::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PStreamNotifyChild::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PStreamNotifyChild::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PStreamNotifyChild::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PStreamNotifyChild::AllocShmem(
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
PStreamNotifyChild::AllocUnsafeShmem(
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
PStreamNotifyChild::AdoptShmem(
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
PStreamNotifyChild::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PStreamNotifyChild::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_RUNTIMEABORT("[PStreamNotifyChild] abort()ing as a result");
}

void
PStreamNotifyChild::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PStreamNotifyChild::DeallocSubtree()
{
}

void
PStreamNotifyChild::Write(
        PStreamNotifyChild* __v,
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
PStreamNotifyChild::Read(
        PStreamNotifyChild** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PStreamNotify");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PStreamNotify");
        return false;
    }

    if ((PStreamNotifyMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PStreamNotify has different type");
        return false;
    }

    (*(__v)) = static_cast<PStreamNotifyChild*>(listener);
    return true;
}



} // namespace plugins
} // namespace mozilla