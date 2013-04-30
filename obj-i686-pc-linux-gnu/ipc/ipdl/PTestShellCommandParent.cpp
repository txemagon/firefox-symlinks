//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/ipc/PTestShellCommandParent.h"

#include "mozilla/ipc/PTestShellParent.h"

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
using mozilla::ipc::PTestShellParent;

namespace mozilla {
namespace ipc {


bool
PTestShellCommandParent::Recv__delete__(const nsString& aResponse)
{
    return true;
}

void
PTestShellCommandParent::ActorDestroy(ActorDestroyReason why)
{
}

PTestShellCommandParent::PTestShellCommandParent() :
    mId(0),
    mState(PTestShellCommand::__Dead)
{
    MOZ_COUNT_CTOR(PTestShellCommandParent);
}

PTestShellCommandParent::~PTestShellCommandParent()
{
    MOZ_COUNT_DTOR(PTestShellCommandParent);
}

PTestShellParent*
PTestShellCommandParent::Manager() const
{
    return static_cast<PTestShellParent*>(mManager);
}

PTestShellCommand::State
PTestShellCommandParent::state()
{
    return mState;
}

int32_t
PTestShellCommandParent::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PTestShellCommandParent::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PTestShellCommandParent::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PTestShellCommandParent::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PTestShellCommandParent::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    NS_RUNTIMEABORT("unreached");
    return;
}

Shmem::SharedMemory*
PTestShellCommandParent::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PTestShellCommandParent::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PTestShellCommandParent::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PTestShellCommandParent::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PTestShellCommandParent::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PTestShellCommandParent::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PTestShellCommandParent::GetIPCChannel()
{
    return mChannel;
}

PTestShellCommandParent::Result
PTestShellCommandParent::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PTestShellCommand::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PTestShellCommand::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PTestShellCommand::Msg___delete__*>((&(__msg))))->Log("[PTestShellCommandParent] Received ", stderr);
            }

            void* __iter = 0;
            PTestShellCommandParent* actor;
            nsString aResponse;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(aResponse)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PTestShellCommand::Transition(mState, Trigger(Trigger::Recv, PTestShellCommand::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Recv__delete__(aResponse)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PTestShellCommandMsgStart, actor);


            return MsgProcessed;
        }
    default:
        {
            return MsgNotKnown;
        }
    }
}

PTestShellCommandParent::Result
PTestShellCommandParent::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PTestShellCommandParent::Result
PTestShellCommandParent::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PTestShellCommandParent::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PTestShellCommandParent::GetProtocolTypeId()
{
    return PTestShellCommandMsgStart;
}

bool
PTestShellCommandParent::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PTestShellCommandParent::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PTestShellCommandParent::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PTestShellCommandParent::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PTestShellCommandParent::AllocShmem(
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
PTestShellCommandParent::AllocUnsafeShmem(
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
PTestShellCommandParent::AdoptShmem(
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
PTestShellCommandParent::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PTestShellCommandParent::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_ERROR("[PTestShellCommandParent] killing child side as a result");

    if ((!(base::KillProcess(OtherProcess(), base::PROCESS_END_KILLED_BY_USER, false)))) {
        NS_ERROR("  may have failed to kill child!");
    }
}

void
PTestShellCommandParent::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PTestShellCommandParent::DeallocSubtree()
{
}

void
PTestShellCommandParent::Write(
        PTestShellCommandParent* __v,
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
PTestShellCommandParent::Read(
        PTestShellCommandParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PTestShellCommand");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PTestShellCommand");
        return false;
    }

    if ((PTestShellCommandMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PTestShellCommand has different type");
        return false;
    }

    (*(__v)) = static_cast<PTestShellCommandParent*>(listener);
    return true;
}



} // namespace ipc
} // namespace mozilla