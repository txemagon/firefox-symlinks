//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/jsipc/PContextWrapperChild.h"

#include "mozilla/ipc/PTestShellChild.h"
#include "mozilla/jsipc/PObjectWrapperChild.h"

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
using mozilla::ipc::PTestShellChild;
using mozilla::jsipc::PObjectWrapperChild;

namespace mozilla {
namespace jsipc {


void
PContextWrapperChild::ActorDestroy(ActorDestroyReason why)
{
}

PContextWrapperChild::PContextWrapperChild() :
    mId(0),
    mState(PContextWrapper::__Dead)
{
    MOZ_COUNT_CTOR(PContextWrapperChild);
}

PContextWrapperChild::~PContextWrapperChild()
{
    MOZ_COUNT_DTOR(PContextWrapperChild);
}

PTestShellChild*
PContextWrapperChild::Manager() const
{
    return static_cast<PTestShellChild*>(mManager);
}

void
PContextWrapperChild::ManagedPObjectWrapperChild(InfallibleTArray<PObjectWrapperChild*>& aArr) const
{
    aArr = mManagedPObjectWrapperChild;
}

const InfallibleTArray<PObjectWrapperChild*>&
PContextWrapperChild::ManagedPObjectWrapperChild() const
{
    return mManagedPObjectWrapperChild;
}

PContextWrapper::State
PContextWrapperChild::state()
{
    return mState;
}

bool
PContextWrapperChild::Send__delete__(PContextWrapperChild* actor)
{
    if ((!(actor))) {
        return false;
    }

    if ((!(actor))) {
        return false;
    }

    PContextWrapper::Msg___delete__* __msg = new PContextWrapper::Msg___delete__();

    (actor)->Write(actor, __msg, false);

    (__msg)->set_routing_id((actor)->mId);


    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PContextWrapperChild] Sending ", stderr);
    }
    if ((!(PContextWrapper::Transition((actor)->mState, Trigger(Trigger::Recv, PContextWrapper::Msg___delete____ID), (&((actor)->mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = ((actor)->mChannel)->Send(__msg);

    (actor)->DestroySubtree(Deletion);
    (actor)->DeallocSubtree();
    ((actor)->mManager)->RemoveManagee(PContextWrapperMsgStart, actor);
    return __sendok;
}

PObjectWrapperChild*
PContextWrapperChild::SendPObjectWrapperConstructor(const bool& makeGlobal)
{
    return SendPObjectWrapperConstructor(AllocPObjectWrapper(makeGlobal), makeGlobal);
}

PObjectWrapperChild*
PContextWrapperChild::SendPObjectWrapperConstructor(
        PObjectWrapperChild* actor,
        const bool& makeGlobal)
{
    if ((!(actor))) {
        return 0;
    }
    (actor)->mId = Register(actor);
    (actor)->mManager = this;
    (actor)->mChannel = mChannel;
    (mManagedPObjectWrapperChild).InsertElementSorted(actor);
    (actor)->mState = mozilla::jsipc::PObjectWrapper::__Start;

    PContextWrapper::Msg_PObjectWrapperConstructor* __msg = new PContextWrapper::Msg_PObjectWrapperConstructor();

    Write(actor, __msg, false);
    Write(makeGlobal, __msg);

    (__msg)->set_routing_id(mId);


    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PContextWrapperChild] Sending ", stderr);
    }
    if ((!(PContextWrapper::Transition(mState, Trigger(Trigger::Recv, PContextWrapper::Msg_PObjectWrapperConstructor__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    if ((!(__sendok))) {
        (actor)->DestroySubtree(FailedConstructor);
        (actor)->DeallocSubtree();
        ((actor)->mManager)->RemoveManagee(PObjectWrapperMsgStart, actor);
        return 0;
    }
    return actor;
}

int32_t
PContextWrapperChild::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PContextWrapperChild::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PContextWrapperChild::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PContextWrapperChild::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PContextWrapperChild::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    switch (aProtocolId) {
    case PObjectWrapperMsgStart:
        {
            PObjectWrapperChild* actor = static_cast<PObjectWrapperChild*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPObjectWrapperChild).NoIndex) != ((mManagedPObjectWrapperChild).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPObjectWrapperChild).RemoveElementSorted(actor);
            DeallocPObjectWrapper(actor);
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
PContextWrapperChild::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PContextWrapperChild::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PContextWrapperChild::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PContextWrapperChild::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PContextWrapperChild::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PContextWrapperChild::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PContextWrapperChild::GetIPCChannel()
{
    return mChannel;
}

PContextWrapperChild::Result
PContextWrapperChild::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PContextWrapper::Reply___delete____ID:
        {
            return MsgProcessed;
        }
    case PContextWrapper::Reply_PObjectWrapperConstructor__ID:
        {
            return MsgProcessed;
        }
    default:
        {
            return MsgNotKnown;
        }
    }
}

PContextWrapperChild::Result
PContextWrapperChild::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PContextWrapperChild::Result
PContextWrapperChild::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PContextWrapperChild::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PContextWrapperChild::GetProtocolTypeId()
{
    return PContextWrapperMsgStart;
}

bool
PContextWrapperChild::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PContextWrapperChild::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PContextWrapperChild::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PContextWrapperChild::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PContextWrapperChild::AllocShmem(
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
PContextWrapperChild::AllocUnsafeShmem(
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
PContextWrapperChild::AdoptShmem(
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
PContextWrapperChild::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PContextWrapperChild::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_RUNTIMEABORT("[PContextWrapperChild] abort()ing as a result");
}

void
PContextWrapperChild::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    ActorDestroyReason subtreewhy = (((why) == (Deletion)) || ((why) == (FailedConstructor)) ? AncestorDeletion : why);

    {
        // Recursively shutting down PObjectWrapper kids
        InfallibleTArray<PObjectWrapperChild*> kids(mManagedPObjectWrapperChild);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PContextWrapperChild::DeallocSubtree()
{
    {
        // Recursively deleting PObjectWrapper kids
        InfallibleTArray<PObjectWrapperChild*>& kids = mManagedPObjectWrapperChild;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPObjectWrapper(kids[i]);
        }
        (mManagedPObjectWrapperChild).Clear();
    }
}

void
PContextWrapperChild::Write(
        PObjectWrapperChild* __v,
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
PContextWrapperChild::Read(
        PObjectWrapperChild** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PContextWrapper");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PObjectWrapper");
        return false;
    }

    if ((PObjectWrapperMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PObjectWrapper has different type");
        return false;
    }

    (*(__v)) = static_cast<PObjectWrapperChild*>(listener);
    return true;
}

void
PContextWrapperChild::Write(
        PContextWrapperChild* __v,
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
PContextWrapperChild::Read(
        PContextWrapperChild** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PContextWrapper");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PContextWrapper");
        return false;
    }

    if ((PContextWrapperMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PContextWrapper has different type");
        return false;
    }

    (*(__v)) = static_cast<PContextWrapperChild*>(listener);
    return true;
}



} // namespace jsipc
} // namespace mozilla