//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/plugins/PPluginStreamParent.h"

#include "mozilla/plugins/PPluginInstanceParent.h"

typedef IPC::Message Message;
typedef mozilla::ipc::RPCChannel Channel;
typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
typedef base::ProcessHandle ProcessHandle;
typedef mozilla::ipc::AsyncChannel AsyncChannel;
typedef mozilla::ipc::SharedMemory SharedMemory;
typedef mozilla::ipc::Trigger Trigger;
typedef mozilla::ipc::ActorHandle ActorHandle;
typedef mozilla::plugins::Buffer Buffer;
typedef mozilla::ipc::FileDescriptor FileDescriptor;
typedef mozilla::ipc::Shmem Shmem;
using mozilla::plugins::PPluginInstanceParent;

namespace mozilla {
namespace plugins {


bool
PPluginStreamParent::Answer__delete__(
        const NPReason& reason,
        const bool& artificial)
{
    return true;
}

void
PPluginStreamParent::ActorDestroy(ActorDestroyReason why)
{
}

PPluginStreamParent::PPluginStreamParent() :
    mId(0),
    mState(PPluginStream::__Dead)
{
    MOZ_COUNT_CTOR(PPluginStreamParent);
}

PPluginStreamParent::~PPluginStreamParent()
{
    MOZ_COUNT_DTOR(PPluginStreamParent);
}

PPluginInstanceParent*
PPluginStreamParent::Manager() const
{
    return static_cast<PPluginInstanceParent*>(mManager);
}

PPluginStream::State
PPluginStreamParent::state()
{
    return mState;
}

bool
PPluginStreamParent::Call__delete__(
        PPluginStreamParent* actor,
        const NPReason& reason,
        const bool& artificial)
{
    if ((!(actor))) {
        return false;
    }

    PPluginStream::Msg___delete__* __msg = new PPluginStream::Msg___delete__();

    (actor)->Write(actor, __msg, false);
    (actor)->Write(reason, __msg);
    (actor)->Write(artificial, __msg);

    (__msg)->set_routing_id((actor)->mId);
    (__msg)->set_rpc();


    Message __reply;

    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PPluginStreamParent] Sending ", stderr);
    }
    if ((!(PPluginStream::Transition((actor)->mState, Trigger(Trigger::Send, PPluginStream::Msg___delete____ID), (&((actor)->mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = ((actor)->mChannel)->Call(__msg, (&(__reply)));
    if (false) {

        if (mozilla::ipc::LoggingEnabled()) {
            (static_cast<const PPluginStream::Reply___delete__*>((&(__reply))))->Log("[PPluginStreamParent] Received reply ", stderr);
        }

        __sendok &= false;
    }
    if ((!(PPluginStream::Transition((actor)->mState, Trigger(Trigger::Recv, PPluginStream::Reply___delete____ID), (&((actor)->mState)))))) {
        NS_WARNING("bad state transition!");
    }
    (actor)->DestroySubtree(Deletion);
    (actor)->DeallocSubtree();
    ((actor)->mManager)->RemoveManagee(PPluginStreamMsgStart, actor);

    return __sendok;
}

int32_t
PPluginStreamParent::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PPluginStreamParent::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PPluginStreamParent::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PPluginStreamParent::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PPluginStreamParent::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    NS_RUNTIMEABORT("unreached");
    return;
}

Shmem::SharedMemory*
PPluginStreamParent::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PPluginStreamParent::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PPluginStreamParent::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PPluginStreamParent::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PPluginStreamParent::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PPluginStreamParent::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PPluginStreamParent::GetIPCChannel()
{
    return mChannel;
}

PPluginStreamParent::Result
PPluginStreamParent::OnMessageReceived(const Message& __msg)
{
    if (((mState) == (PPluginStream::__Dying)) && ((((__msg).is_reply()) != (true)) || (((__msg).is_rpc()) != (true)))) {
        FatalError("incoming message racing with actor deletion");
        return MsgProcessed;
    }
    return MsgNotKnown;
}

PPluginStreamParent::Result
PPluginStreamParent::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    if (((mState) == (PPluginStream::__Dying)) && ((((__msg).is_reply()) != (true)) || (((__msg).is_rpc()) != (true)))) {
        FatalError("incoming message racing with actor deletion");
        return MsgProcessed;
    }
    return MsgNotKnown;
}

PPluginStreamParent::Result
PPluginStreamParent::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    if (((mState) == (PPluginStream::__Dying)) && ((((__msg).is_reply()) != (true)) || (((__msg).is_rpc()) != (true)))) {
        FatalError("incoming message racing with actor deletion");
        return MsgProcessed;
    }
    switch ((__msg).type()) {
    case PPluginStream::Msg_NPN_Write__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PPluginStream::Msg_NPN_Write");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PPluginStream::Msg_NPN_Write*>((&(__msg))))->Log("[PPluginStreamParent] Received ", stderr);
            }

            void* __iter = 0;
            Buffer data;

            if ((!(Read((&(data)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PPluginStream::Transition(mState, Trigger(Trigger::Recv, PPluginStream::Msg_NPN_Write__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            int32_t written;
            int32_t __id = mId;
            if ((!(AnswerNPN_Write(data, (&(written)))))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for NPN_Write returned error code");
                return MsgProcessingError;
            }

            __reply = new PPluginStream::Reply_NPN_Write();

            Write(written, __reply);
            (__reply)->set_routing_id(__id);
            (__reply)->set_rpc();
            (__reply)->set_reply();

            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PPluginStream::Reply_NPN_Write*>(__reply))->Log("[PPluginStreamParent] Sending reply ", stderr);
            }
            return MsgProcessed;
        }
    case PPluginStream::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PPluginStream::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PPluginStream::Msg___delete__*>((&(__msg))))->Log("[PPluginStreamParent] Received ", stderr);
            }

            void* __iter = 0;
            PPluginStreamParent* actor;
            NPReason reason;
            bool artificial;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(reason)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(artificial)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PPluginStream::Transition(mState, Trigger(Trigger::Recv, PPluginStream::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Answer__delete__(reason, artificial)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            int32_t __id = mId;
            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PPluginStreamMsgStart, actor);

            __reply = new PPluginStream::Reply___delete__();

            (__reply)->set_routing_id(__id);
            (__reply)->set_rpc();
            (__reply)->set_reply();

            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PPluginStream::Reply___delete__*>(__reply))->Log("[PPluginStreamParent] Sending reply ", stderr);
            }

            return MsgProcessed;
        }
    default:
        {
            return MsgNotKnown;
        }
    }
}

void
PPluginStreamParent::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PPluginStreamParent::GetProtocolTypeId()
{
    return PPluginStreamMsgStart;
}

bool
PPluginStreamParent::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PPluginStreamParent::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PPluginStreamParent::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PPluginStreamParent::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PPluginStreamParent::AllocShmem(
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
PPluginStreamParent::AllocUnsafeShmem(
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
PPluginStreamParent::AdoptShmem(
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
PPluginStreamParent::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PPluginStreamParent::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_ERROR("[PPluginStreamParent] killing child side as a result");

    if ((!(base::KillProcess(OtherProcess(), base::PROCESS_END_KILLED_BY_USER, false)))) {
        NS_ERROR("  may have failed to kill child!");
    }
}

void
PPluginStreamParent::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PPluginStreamParent::DeallocSubtree()
{
}

void
PPluginStreamParent::Write(
        PPluginStreamParent* __v,
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
PPluginStreamParent::Read(
        PPluginStreamParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PPluginStream");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PPluginStream");
        return false;
    }

    if ((PPluginStreamMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PPluginStream has different type");
        return false;
    }

    (*(__v)) = static_cast<PPluginStreamParent*>(listener);
    return true;
}



} // namespace plugins
} // namespace mozilla