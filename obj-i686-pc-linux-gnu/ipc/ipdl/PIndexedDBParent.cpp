//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/indexedDB/PIndexedDBParent.h"

#include "mozilla/dom/PBrowserParent.h"
#include "mozilla/dom/PContentParent.h"
#include "mozilla/dom/indexedDB/PIndexedDBDatabaseParent.h"
#include "mozilla/dom/indexedDB/PIndexedDBDeleteDatabaseRequestParent.h"

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
using mozilla::dom::PBrowserParent;
using mozilla::dom::PContentParent;
using mozilla::dom::indexedDB::PIndexedDBDatabaseParent;
using mozilla::dom::indexedDB::PIndexedDBDeleteDatabaseRequestParent;

namespace mozilla {
namespace dom {
namespace indexedDB {


bool
PIndexedDBParent::Recv__delete__()
{
    return true;
}

bool
PIndexedDBParent::RecvPIndexedDBDatabaseConstructor(
        PIndexedDBDatabaseParent* actor,
        const nsString& name,
        const uint64_t& version)
{
    return true;
}

bool
PIndexedDBParent::RecvPIndexedDBDeleteDatabaseRequestConstructor(
        PIndexedDBDeleteDatabaseRequestParent* actor,
        const nsString& name)
{
    return true;
}

void
PIndexedDBParent::ActorDestroy(ActorDestroyReason why)
{
}

PIndexedDBParent::PIndexedDBParent() :
    mId(0),
    mState(PIndexedDB::__Dead)
{
    MOZ_COUNT_CTOR(PIndexedDBParent);
}

PIndexedDBParent::~PIndexedDBParent()
{
    MOZ_COUNT_DTOR(PIndexedDBParent);
}

void
PIndexedDBParent::ManagedPIndexedDBDatabaseParent(InfallibleTArray<PIndexedDBDatabaseParent*>& aArr) const
{
    aArr = mManagedPIndexedDBDatabaseParent;
}

const InfallibleTArray<PIndexedDBDatabaseParent*>&
PIndexedDBParent::ManagedPIndexedDBDatabaseParent() const
{
    return mManagedPIndexedDBDatabaseParent;
}

void
PIndexedDBParent::ManagedPIndexedDBDeleteDatabaseRequestParent(InfallibleTArray<PIndexedDBDeleteDatabaseRequestParent*>& aArr) const
{
    aArr = mManagedPIndexedDBDeleteDatabaseRequestParent;
}

const InfallibleTArray<PIndexedDBDeleteDatabaseRequestParent*>&
PIndexedDBParent::ManagedPIndexedDBDeleteDatabaseRequestParent() const
{
    return mManagedPIndexedDBDeleteDatabaseRequestParent;
}

PIndexedDB::State
PIndexedDBParent::state()
{
    return mState;
}

int32_t
PIndexedDBParent::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PIndexedDBParent::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PIndexedDBParent::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PIndexedDBParent::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PIndexedDBParent::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    switch (aProtocolId) {
    case PIndexedDBDatabaseMsgStart:
        {
            PIndexedDBDatabaseParent* actor = static_cast<PIndexedDBDatabaseParent*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPIndexedDBDatabaseParent).NoIndex) != ((mManagedPIndexedDBDatabaseParent).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPIndexedDBDatabaseParent).RemoveElementSorted(actor);
            DeallocPIndexedDBDatabase(actor);
            return;
        }
    case PIndexedDBDeleteDatabaseRequestMsgStart:
        {
            PIndexedDBDeleteDatabaseRequestParent* actor = static_cast<PIndexedDBDeleteDatabaseRequestParent*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPIndexedDBDeleteDatabaseRequestParent).NoIndex) != ((mManagedPIndexedDBDeleteDatabaseRequestParent).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPIndexedDBDeleteDatabaseRequestParent).RemoveElementSorted(actor);
            DeallocPIndexedDBDeleteDatabaseRequest(actor);
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
PIndexedDBParent::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PIndexedDBParent::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PIndexedDBParent::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PIndexedDBParent::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PIndexedDBParent::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PIndexedDBParent::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PIndexedDBParent::GetIPCChannel()
{
    return mChannel;
}

PIndexedDBParent::Result
PIndexedDBParent::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PIndexedDB::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDB::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDB::Msg___delete__*>((&(__msg))))->Log("[PIndexedDBParent] Received ", stderr);
            }

            void* __iter = 0;
            PIndexedDBParent* actor;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDB::Transition(mState, Trigger(Trigger::Recv, PIndexedDB::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Recv__delete__()))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PIndexedDBMsgStart, actor);


            return MsgProcessed;
        }
    case PIndexedDB::Msg_PIndexedDBDatabaseConstructor__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDB::Msg_PIndexedDBDatabaseConstructor");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDB::Msg_PIndexedDBDatabaseConstructor*>((&(__msg))))->Log("[PIndexedDBParent] Received ", stderr);
            }

            void* __iter = 0;
            ActorHandle __handle;
            PIndexedDBDatabaseParent* actor;
            nsString name;
            uint64_t version;

            if ((!(Read((&(__handle)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(name)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(version)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDB::Transition(mState, Trigger(Trigger::Recv, PIndexedDB::Msg_PIndexedDBDatabaseConstructor__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            actor = AllocPIndexedDBDatabase(name, version);
            if ((!(actor))) {
                return MsgValueError;
            }
            (actor)->mId = RegisterID(actor, (__handle).mId);
            (actor)->mManager = this;
            (actor)->mChannel = mChannel;
            (mManagedPIndexedDBDatabaseParent).InsertElementSorted(actor);
            (actor)->mState = mozilla::dom::indexedDB::PIndexedDBDatabase::__Start;

            if ((!(RecvPIndexedDBDatabaseConstructor(actor, name, version)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for PIndexedDBDatabase returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PIndexedDB::Msg_PIndexedDBDeleteDatabaseRequestConstructor__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDB::Msg_PIndexedDBDeleteDatabaseRequestConstructor");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDB::Msg_PIndexedDBDeleteDatabaseRequestConstructor*>((&(__msg))))->Log("[PIndexedDBParent] Received ", stderr);
            }

            void* __iter = 0;
            ActorHandle __handle;
            PIndexedDBDeleteDatabaseRequestParent* actor;
            nsString name;

            if ((!(Read((&(__handle)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(name)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDB::Transition(mState, Trigger(Trigger::Recv, PIndexedDB::Msg_PIndexedDBDeleteDatabaseRequestConstructor__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            actor = AllocPIndexedDBDeleteDatabaseRequest(name);
            if ((!(actor))) {
                return MsgValueError;
            }
            (actor)->mId = RegisterID(actor, (__handle).mId);
            (actor)->mManager = this;
            (actor)->mChannel = mChannel;
            (mManagedPIndexedDBDeleteDatabaseRequestParent).InsertElementSorted(actor);
            (actor)->mState = mozilla::dom::indexedDB::PIndexedDBDeleteDatabaseRequest::__Start;

            if ((!(RecvPIndexedDBDeleteDatabaseRequestConstructor(actor, name)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for PIndexedDBDeleteDatabaseRequest returned error code");
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

PIndexedDBParent::Result
PIndexedDBParent::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PIndexedDBParent::Result
PIndexedDBParent::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PIndexedDBParent::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PIndexedDBParent::GetProtocolTypeId()
{
    return PIndexedDBMsgStart;
}

bool
PIndexedDBParent::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PIndexedDBParent::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PIndexedDBParent::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PIndexedDBParent::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PIndexedDBParent::AllocShmem(
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
PIndexedDBParent::AllocUnsafeShmem(
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
PIndexedDBParent::AdoptShmem(
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
PIndexedDBParent::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PIndexedDBParent::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_ERROR("[PIndexedDBParent] killing child side as a result");

    if ((!(base::KillProcess(OtherProcess(), base::PROCESS_END_KILLED_BY_USER, false)))) {
        NS_ERROR("  may have failed to kill child!");
    }
}

void
PIndexedDBParent::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    ActorDestroyReason subtreewhy = (((why) == (Deletion)) || ((why) == (FailedConstructor)) ? AncestorDeletion : why);

    {
        // Recursively shutting down PIndexedDBDatabase kids
        InfallibleTArray<PIndexedDBDatabaseParent*> kids(mManagedPIndexedDBDatabaseParent);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }
    {
        // Recursively shutting down PIndexedDBDeleteDatabaseRequest kids
        InfallibleTArray<PIndexedDBDeleteDatabaseRequestParent*> kids(mManagedPIndexedDBDeleteDatabaseRequestParent);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PIndexedDBParent::DeallocSubtree()
{
    {
        // Recursively deleting PIndexedDBDatabase kids
        InfallibleTArray<PIndexedDBDatabaseParent*>& kids = mManagedPIndexedDBDatabaseParent;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPIndexedDBDatabase(kids[i]);
        }
        (mManagedPIndexedDBDatabaseParent).Clear();
    }
    {
        // Recursively deleting PIndexedDBDeleteDatabaseRequest kids
        InfallibleTArray<PIndexedDBDeleteDatabaseRequestParent*>& kids = mManagedPIndexedDBDeleteDatabaseRequestParent;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPIndexedDBDeleteDatabaseRequest(kids[i]);
        }
        (mManagedPIndexedDBDeleteDatabaseRequestParent).Clear();
    }
}

void
PIndexedDBParent::Write(
        PIndexedDBDatabaseParent* __v,
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
PIndexedDBParent::Read(
        PIndexedDBDatabaseParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDB");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PIndexedDBDatabase");
        return false;
    }

    if ((PIndexedDBDatabaseMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PIndexedDBDatabase has different type");
        return false;
    }

    (*(__v)) = static_cast<PIndexedDBDatabaseParent*>(listener);
    return true;
}

void
PIndexedDBParent::Write(
        PIndexedDBDeleteDatabaseRequestParent* __v,
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
PIndexedDBParent::Read(
        PIndexedDBDeleteDatabaseRequestParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDB");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PIndexedDBDeleteDatabaseRequest");
        return false;
    }

    if ((PIndexedDBDeleteDatabaseRequestMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PIndexedDBDeleteDatabaseRequest has different type");
        return false;
    }

    (*(__v)) = static_cast<PIndexedDBDeleteDatabaseRequestParent*>(listener);
    return true;
}

void
PIndexedDBParent::Write(
        PIndexedDBParent* __v,
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
PIndexedDBParent::Read(
        PIndexedDBParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDB");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PIndexedDB");
        return false;
    }

    if ((PIndexedDBMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PIndexedDB has different type");
        return false;
    }

    (*(__v)) = static_cast<PIndexedDBParent*>(listener);
    return true;
}



} // namespace indexedDB
} // namespace dom
} // namespace mozilla