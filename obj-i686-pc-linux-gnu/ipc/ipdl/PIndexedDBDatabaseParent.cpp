//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/indexedDB/PIndexedDBDatabaseParent.h"

#include "mozilla/dom/indexedDB/PIndexedDBParent.h"
#include "mozilla/dom/indexedDB/PIndexedDBTransactionParent.h"

typedef IPC::Message Message;
typedef mozilla::ipc::RPCChannel Channel;
typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
typedef base::ProcessHandle ProcessHandle;
typedef mozilla::ipc::AsyncChannel AsyncChannel;
typedef mozilla::ipc::SharedMemory SharedMemory;
typedef mozilla::ipc::Trigger Trigger;
typedef mozilla::ipc::ActorHandle ActorHandle;
typedef mozilla::dom::indexedDB::DatabaseInfoGuts DatabaseInfoGuts;
typedef mozilla::ipc::FileDescriptor FileDescriptor;
typedef mozilla::dom::indexedDB::IDBTransaction::Mode Mode;
typedef mozilla::dom::indexedDB::ipc::NormalTransactionParams NormalTransactionParams;
typedef mozilla::dom::indexedDB::ObjectStoreInfoGuts ObjectStoreInfoGuts;
typedef mozilla::ipc::Shmem Shmem;
typedef mozilla::dom::indexedDB::ipc::TransactionParams TransactionParams;
typedef mozilla::dom::indexedDB::ipc::VersionChangeTransactionParams VersionChangeTransactionParams;
using mozilla::dom::indexedDB::PIndexedDBParent;
using mozilla::dom::indexedDB::PIndexedDBTransactionParent;

namespace mozilla {
namespace dom {
namespace indexedDB {


bool
PIndexedDBDatabaseParent::Recv__delete__()
{
    return true;
}

bool
PIndexedDBDatabaseParent::RecvPIndexedDBTransactionConstructor(
        PIndexedDBTransactionParent* actor,
        const TransactionParams& params)
{
    return true;
}

void
PIndexedDBDatabaseParent::ActorDestroy(ActorDestroyReason why)
{
}

PIndexedDBDatabaseParent::PIndexedDBDatabaseParent() :
    mId(0),
    mState(PIndexedDBDatabase::__Dead)
{
    MOZ_COUNT_CTOR(PIndexedDBDatabaseParent);
}

PIndexedDBDatabaseParent::~PIndexedDBDatabaseParent()
{
    MOZ_COUNT_DTOR(PIndexedDBDatabaseParent);
}

PIndexedDBParent*
PIndexedDBDatabaseParent::Manager() const
{
    return static_cast<PIndexedDBParent*>(mManager);
}

void
PIndexedDBDatabaseParent::ManagedPIndexedDBTransactionParent(InfallibleTArray<PIndexedDBTransactionParent*>& aArr) const
{
    aArr = mManagedPIndexedDBTransactionParent;
}

const InfallibleTArray<PIndexedDBTransactionParent*>&
PIndexedDBDatabaseParent::ManagedPIndexedDBTransactionParent() const
{
    return mManagedPIndexedDBTransactionParent;
}

PIndexedDBDatabase::State
PIndexedDBDatabaseParent::state()
{
    return mState;
}

bool
PIndexedDBDatabaseParent::SendSuccess(
        const DatabaseInfoGuts& dbInfo,
        const InfallibleTArray<ObjectStoreInfoGuts>& osInfo)
{
    PIndexedDBDatabase::Msg_Success* __msg = new PIndexedDBDatabase::Msg_Success();

    Write(dbInfo, __msg);
    Write(osInfo, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBDatabaseParent] Sending ", stderr);
    }
    if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Send, PIndexedDBDatabase::Msg_Success__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PIndexedDBDatabaseParent::SendError(const nsresult& rv)
{
    PIndexedDBDatabase::Msg_Error* __msg = new PIndexedDBDatabase::Msg_Error();

    Write(rv, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBDatabaseParent] Sending ", stderr);
    }
    if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Send, PIndexedDBDatabase::Msg_Error__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PIndexedDBDatabaseParent::SendBlocked(const uint64_t& oldVersion)
{
    PIndexedDBDatabase::Msg_Blocked* __msg = new PIndexedDBDatabase::Msg_Blocked();

    Write(oldVersion, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBDatabaseParent] Sending ", stderr);
    }
    if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Send, PIndexedDBDatabase::Msg_Blocked__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PIndexedDBDatabaseParent::SendVersionChange(
        const uint64_t& oldVersion,
        const uint64_t& newVersion)
{
    PIndexedDBDatabase::Msg_VersionChange* __msg = new PIndexedDBDatabase::Msg_VersionChange();

    Write(oldVersion, __msg);
    Write(newVersion, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBDatabaseParent] Sending ", stderr);
    }
    if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Send, PIndexedDBDatabase::Msg_VersionChange__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PIndexedDBDatabaseParent::SendInvalidate()
{
    PIndexedDBDatabase::Msg_Invalidate* __msg = new PIndexedDBDatabase::Msg_Invalidate();


    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBDatabaseParent] Sending ", stderr);
    }
    if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Send, PIndexedDBDatabase::Msg_Invalidate__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

PIndexedDBTransactionParent*
PIndexedDBDatabaseParent::SendPIndexedDBTransactionConstructor(const TransactionParams& params)
{
    return SendPIndexedDBTransactionConstructor(AllocPIndexedDBTransaction(params), params);
}

PIndexedDBTransactionParent*
PIndexedDBDatabaseParent::SendPIndexedDBTransactionConstructor(
        PIndexedDBTransactionParent* actor,
        const TransactionParams& params)
{
    if ((!(actor))) {
        return 0;
    }
    (actor)->mId = Register(actor);
    (actor)->mManager = this;
    (actor)->mChannel = mChannel;
    (mManagedPIndexedDBTransactionParent).InsertElementSorted(actor);
    (actor)->mState = mozilla::dom::indexedDB::PIndexedDBTransaction::__Start;

    PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor* __msg = new PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor();

    Write(actor, __msg, false);
    Write(params, __msg);

    (__msg)->set_routing_id(mId);


    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBDatabaseParent] Sending ", stderr);
    }
    if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Send, PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    if ((!(__sendok))) {
        (actor)->DestroySubtree(FailedConstructor);
        (actor)->DeallocSubtree();
        ((actor)->mManager)->RemoveManagee(PIndexedDBTransactionMsgStart, actor);
        return 0;
    }
    return actor;
}

int32_t
PIndexedDBDatabaseParent::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PIndexedDBDatabaseParent::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PIndexedDBDatabaseParent::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PIndexedDBDatabaseParent::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PIndexedDBDatabaseParent::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    switch (aProtocolId) {
    case PIndexedDBTransactionMsgStart:
        {
            PIndexedDBTransactionParent* actor = static_cast<PIndexedDBTransactionParent*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPIndexedDBTransactionParent).NoIndex) != ((mManagedPIndexedDBTransactionParent).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPIndexedDBTransactionParent).RemoveElementSorted(actor);
            DeallocPIndexedDBTransaction(actor);
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
PIndexedDBDatabaseParent::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PIndexedDBDatabaseParent::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PIndexedDBDatabaseParent::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PIndexedDBDatabaseParent::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PIndexedDBDatabaseParent::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PIndexedDBDatabaseParent::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PIndexedDBDatabaseParent::GetIPCChannel()
{
    return mChannel;
}

PIndexedDBDatabaseParent::Result
PIndexedDBDatabaseParent::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PIndexedDBDatabase::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBDatabase::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBDatabase::Msg___delete__*>((&(__msg))))->Log("[PIndexedDBDatabaseParent] Received ", stderr);
            }

            void* __iter = 0;
            PIndexedDBDatabaseParent* actor;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Recv, PIndexedDBDatabase::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Recv__delete__()))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PIndexedDBDatabaseMsgStart, actor);


            return MsgProcessed;
        }
    case PIndexedDBDatabase::Msg_Close__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBDatabase::Msg_Close");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBDatabase::Msg_Close*>((&(__msg))))->Log("[PIndexedDBDatabaseParent] Received ", stderr);
            }

            void* __iter = 0;
            bool unlinked;

            if ((!(Read((&(unlinked)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Recv, PIndexedDBDatabase::Msg_Close__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvClose(unlinked)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for Close returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PIndexedDBDatabase::Reply_PIndexedDBTransactionConstructor__ID:
        {
            return MsgProcessed;
        }
    case PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor*>((&(__msg))))->Log("[PIndexedDBDatabaseParent] Received ", stderr);
            }

            void* __iter = 0;
            ActorHandle __handle;
            PIndexedDBTransactionParent* actor;
            TransactionParams params;

            if ((!(Read((&(__handle)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(params)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBDatabase::Transition(mState, Trigger(Trigger::Recv, PIndexedDBDatabase::Msg_PIndexedDBTransactionConstructor__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            actor = AllocPIndexedDBTransaction(params);
            if ((!(actor))) {
                return MsgValueError;
            }
            (actor)->mId = RegisterID(actor, (__handle).mId);
            (actor)->mManager = this;
            (actor)->mChannel = mChannel;
            (mManagedPIndexedDBTransactionParent).InsertElementSorted(actor);
            (actor)->mState = mozilla::dom::indexedDB::PIndexedDBTransaction::__Start;

            if ((!(RecvPIndexedDBTransactionConstructor(actor, params)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for PIndexedDBTransaction returned error code");
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

PIndexedDBDatabaseParent::Result
PIndexedDBDatabaseParent::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PIndexedDBDatabaseParent::Result
PIndexedDBDatabaseParent::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PIndexedDBDatabaseParent::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PIndexedDBDatabaseParent::GetProtocolTypeId()
{
    return PIndexedDBDatabaseMsgStart;
}

bool
PIndexedDBDatabaseParent::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PIndexedDBDatabaseParent::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PIndexedDBDatabaseParent::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PIndexedDBDatabaseParent::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PIndexedDBDatabaseParent::AllocShmem(
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
PIndexedDBDatabaseParent::AllocUnsafeShmem(
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
PIndexedDBDatabaseParent::AdoptShmem(
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
PIndexedDBDatabaseParent::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PIndexedDBDatabaseParent::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_ERROR("[PIndexedDBDatabaseParent] killing child side as a result");

    if ((!(base::KillProcess(OtherProcess(), base::PROCESS_END_KILLED_BY_USER, false)))) {
        NS_ERROR("  may have failed to kill child!");
    }
}

void
PIndexedDBDatabaseParent::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    ActorDestroyReason subtreewhy = (((why) == (Deletion)) || ((why) == (FailedConstructor)) ? AncestorDeletion : why);

    {
        // Recursively shutting down PIndexedDBTransaction kids
        InfallibleTArray<PIndexedDBTransactionParent*> kids(mManagedPIndexedDBTransactionParent);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PIndexedDBDatabaseParent::DeallocSubtree()
{
    {
        // Recursively deleting PIndexedDBTransaction kids
        InfallibleTArray<PIndexedDBTransactionParent*>& kids = mManagedPIndexedDBTransactionParent;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPIndexedDBTransaction(kids[i]);
        }
        (mManagedPIndexedDBTransactionParent).Clear();
    }
}

void
PIndexedDBDatabaseParent::Write(
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
PIndexedDBDatabaseParent::Read(
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDBDatabase");
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
PIndexedDBDatabaseParent::Write(
        PIndexedDBTransactionParent* __v,
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
PIndexedDBDatabaseParent::Read(
        PIndexedDBTransactionParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDBDatabase");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PIndexedDBTransaction");
        return false;
    }

    if ((PIndexedDBTransactionMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PIndexedDBTransaction has different type");
        return false;
    }

    (*(__v)) = static_cast<PIndexedDBTransactionParent*>(listener);
    return true;
}

void
PIndexedDBDatabaseParent::Write(
        const NormalTransactionParams& __v,
        Message* __msg)
{
    Write((__v).names(), __msg);
    Write((__v).mode(), __msg);
}

bool
PIndexedDBDatabaseParent::Read(
        NormalTransactionParams* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->names())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->mode())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PIndexedDBDatabaseParent::Write(
        const TransactionParams& __v,
        Message* __msg)
{
    typedef TransactionParams __type;
    Write(int((__v).type()), __msg);

    switch ((__v).type()) {
    case __type::TNormalTransactionParams:
        {
            Write((__v).get_NormalTransactionParams(), __msg);
            return;
        }
    case __type::TVersionChangeTransactionParams:
        {
            Write((__v).get_VersionChangeTransactionParams(), __msg);
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
PIndexedDBDatabaseParent::Read(
        TransactionParams* __v,
        const Message* __msg,
        void** __iter)
{
    typedef TransactionParams __type;
    int type;
    if ((!(Read((&(type)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    switch (type) {
    case __type::TNormalTransactionParams:
        {
            NormalTransactionParams tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_NormalTransactionParams())), __msg, __iter);
        }
    case __type::TVersionChangeTransactionParams:
        {
            VersionChangeTransactionParams tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_VersionChangeTransactionParams())), __msg, __iter);
        }
    default:
        {
            mozilla::ipc::ProtocolErrorBreakpoint("unknown union type");
            return false;
        }
    }
}

void
PIndexedDBDatabaseParent::Write(
        const VersionChangeTransactionParams& __v,
        Message* __msg)
{
    Write((__v).dbInfo(), __msg);
    Write((__v).osInfo(), __msg);
    Write((__v).oldVersion(), __msg);
}

bool
PIndexedDBDatabaseParent::Read(
        VersionChangeTransactionParams* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->dbInfo())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->osInfo())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->oldVersion())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}



} // namespace indexedDB
} // namespace dom
} // namespace mozilla