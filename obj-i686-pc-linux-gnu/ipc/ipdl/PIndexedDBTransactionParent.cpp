//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/indexedDB/PIndexedDBTransactionParent.h"

#include "mozilla/dom/indexedDB/PIndexedDBDatabaseParent.h"
#include "mozilla/dom/indexedDB/PIndexedDBObjectStoreParent.h"

typedef IPC::Message Message;
typedef mozilla::ipc::RPCChannel Channel;
typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
typedef base::ProcessHandle ProcessHandle;
typedef mozilla::ipc::AsyncChannel AsyncChannel;
typedef mozilla::ipc::SharedMemory SharedMemory;
typedef mozilla::ipc::Trigger Trigger;
typedef mozilla::dom::indexedDB::ipc::AbortResult AbortResult;
typedef mozilla::ipc::ActorHandle ActorHandle;
typedef mozilla::dom::indexedDB::ipc::CompleteParams CompleteParams;
typedef mozilla::dom::indexedDB::ipc::CompleteResult CompleteResult;
typedef mozilla::dom::indexedDB::ipc::CreateObjectStoreParams CreateObjectStoreParams;
typedef mozilla::ipc::FileDescriptor FileDescriptor;
typedef mozilla::dom::indexedDB::ipc::GetObjectStoreParams GetObjectStoreParams;
typedef mozilla::dom::indexedDB::ipc::ObjectStoreConstructorParams ObjectStoreConstructorParams;
typedef mozilla::dom::indexedDB::ObjectStoreInfoGuts ObjectStoreInfoGuts;
typedef mozilla::ipc::Shmem Shmem;
using mozilla::dom::indexedDB::PIndexedDBDatabaseParent;
using mozilla::dom::indexedDB::PIndexedDBObjectStoreParent;

namespace mozilla {
namespace dom {
namespace indexedDB {


bool
PIndexedDBTransactionParent::Recv__delete__()
{
    return true;
}

bool
PIndexedDBTransactionParent::RecvPIndexedDBObjectStoreConstructor(
        PIndexedDBObjectStoreParent* actor,
        const ObjectStoreConstructorParams& params)
{
    return true;
}

void
PIndexedDBTransactionParent::ActorDestroy(ActorDestroyReason why)
{
}

PIndexedDBTransactionParent::PIndexedDBTransactionParent() :
    mId(0),
    mState(PIndexedDBTransaction::__Dead)
{
    MOZ_COUNT_CTOR(PIndexedDBTransactionParent);
}

PIndexedDBTransactionParent::~PIndexedDBTransactionParent()
{
    MOZ_COUNT_DTOR(PIndexedDBTransactionParent);
}

PIndexedDBDatabaseParent*
PIndexedDBTransactionParent::Manager() const
{
    return static_cast<PIndexedDBDatabaseParent*>(mManager);
}

void
PIndexedDBTransactionParent::ManagedPIndexedDBObjectStoreParent(InfallibleTArray<PIndexedDBObjectStoreParent*>& aArr) const
{
    aArr = mManagedPIndexedDBObjectStoreParent;
}

const InfallibleTArray<PIndexedDBObjectStoreParent*>&
PIndexedDBTransactionParent::ManagedPIndexedDBObjectStoreParent() const
{
    return mManagedPIndexedDBObjectStoreParent;
}

PIndexedDBTransaction::State
PIndexedDBTransactionParent::state()
{
    return mState;
}

bool
PIndexedDBTransactionParent::SendComplete(const CompleteParams& params)
{
    PIndexedDBTransaction::Msg_Complete* __msg = new PIndexedDBTransaction::Msg_Complete();

    Write(params, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBTransactionParent] Sending ", stderr);
    }
    if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Send, PIndexedDBTransaction::Msg_Complete__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

int32_t
PIndexedDBTransactionParent::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PIndexedDBTransactionParent::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PIndexedDBTransactionParent::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PIndexedDBTransactionParent::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PIndexedDBTransactionParent::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    switch (aProtocolId) {
    case PIndexedDBObjectStoreMsgStart:
        {
            PIndexedDBObjectStoreParent* actor = static_cast<PIndexedDBObjectStoreParent*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPIndexedDBObjectStoreParent).NoIndex) != ((mManagedPIndexedDBObjectStoreParent).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPIndexedDBObjectStoreParent).RemoveElementSorted(actor);
            DeallocPIndexedDBObjectStore(actor);
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
PIndexedDBTransactionParent::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PIndexedDBTransactionParent::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PIndexedDBTransactionParent::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PIndexedDBTransactionParent::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PIndexedDBTransactionParent::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PIndexedDBTransactionParent::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PIndexedDBTransactionParent::GetIPCChannel()
{
    return mChannel;
}

PIndexedDBTransactionParent::Result
PIndexedDBTransactionParent::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PIndexedDBTransaction::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBTransaction::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBTransaction::Msg___delete__*>((&(__msg))))->Log("[PIndexedDBTransactionParent] Received ", stderr);
            }

            void* __iter = 0;
            PIndexedDBTransactionParent* actor;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Recv__delete__()))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PIndexedDBTransactionMsgStart, actor);


            return MsgProcessed;
        }
    case PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor*>((&(__msg))))->Log("[PIndexedDBTransactionParent] Received ", stderr);
            }

            void* __iter = 0;
            ActorHandle __handle;
            PIndexedDBObjectStoreParent* actor;
            ObjectStoreConstructorParams params;

            if ((!(Read((&(__handle)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(params)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            actor = AllocPIndexedDBObjectStore(params);
            if ((!(actor))) {
                return MsgValueError;
            }
            (actor)->mId = RegisterID(actor, (__handle).mId);
            (actor)->mManager = this;
            (actor)->mChannel = mChannel;
            (mManagedPIndexedDBObjectStoreParent).InsertElementSorted(actor);
            (actor)->mState = mozilla::dom::indexedDB::PIndexedDBObjectStore::__Start;

            if ((!(RecvPIndexedDBObjectStoreConstructor(actor, params)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for PIndexedDBObjectStore returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PIndexedDBTransaction::Msg_Abort__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBTransaction::Msg_Abort");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBTransaction::Msg_Abort*>((&(__msg))))->Log("[PIndexedDBTransactionParent] Received ", stderr);
            }

            void* __iter = 0;
            nsresult abortCode;

            if ((!(Read((&(abortCode)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_Abort__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvAbort(abortCode)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for Abort returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PIndexedDBTransaction::Msg_AllRequestsFinished__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBTransaction::Msg_AllRequestsFinished");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBTransaction::Msg_AllRequestsFinished*>((&(__msg))))->Log("[PIndexedDBTransactionParent] Received ", stderr);
            }

            if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_AllRequestsFinished__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvAllRequestsFinished()))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for AllRequestsFinished returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PIndexedDBTransaction::Msg_DeleteObjectStore__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBTransaction::Msg_DeleteObjectStore");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBTransaction::Msg_DeleteObjectStore*>((&(__msg))))->Log("[PIndexedDBTransactionParent] Received ", stderr);
            }

            void* __iter = 0;
            nsString name;

            if ((!(Read((&(name)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_DeleteObjectStore__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvDeleteObjectStore(name)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for DeleteObjectStore returned error code");
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

PIndexedDBTransactionParent::Result
PIndexedDBTransactionParent::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PIndexedDBTransactionParent::Result
PIndexedDBTransactionParent::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PIndexedDBTransactionParent::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PIndexedDBTransactionParent::GetProtocolTypeId()
{
    return PIndexedDBTransactionMsgStart;
}

bool
PIndexedDBTransactionParent::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PIndexedDBTransactionParent::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PIndexedDBTransactionParent::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PIndexedDBTransactionParent::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PIndexedDBTransactionParent::AllocShmem(
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
PIndexedDBTransactionParent::AllocUnsafeShmem(
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
PIndexedDBTransactionParent::AdoptShmem(
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
PIndexedDBTransactionParent::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PIndexedDBTransactionParent::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_ERROR("[PIndexedDBTransactionParent] killing child side as a result");

    if ((!(base::KillProcess(OtherProcess(), base::PROCESS_END_KILLED_BY_USER, false)))) {
        NS_ERROR("  may have failed to kill child!");
    }
}

void
PIndexedDBTransactionParent::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    ActorDestroyReason subtreewhy = (((why) == (Deletion)) || ((why) == (FailedConstructor)) ? AncestorDeletion : why);

    {
        // Recursively shutting down PIndexedDBObjectStore kids
        InfallibleTArray<PIndexedDBObjectStoreParent*> kids(mManagedPIndexedDBObjectStoreParent);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PIndexedDBTransactionParent::DeallocSubtree()
{
    {
        // Recursively deleting PIndexedDBObjectStore kids
        InfallibleTArray<PIndexedDBObjectStoreParent*>& kids = mManagedPIndexedDBObjectStoreParent;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPIndexedDBObjectStore(kids[i]);
        }
        (mManagedPIndexedDBObjectStoreParent).Clear();
    }
}

void
PIndexedDBTransactionParent::Write(
        const AbortResult& __v,
        Message* __msg)
{
    Write((__v).errorCode(), __msg);
}

bool
PIndexedDBTransactionParent::Read(
        AbortResult* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->errorCode())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PIndexedDBTransactionParent::Write(
        const CompleteParams& __v,
        Message* __msg)
{
    typedef CompleteParams __type;
    Write(int((__v).type()), __msg);

    switch ((__v).type()) {
    case __type::TCompleteResult:
        {
            Write((__v).get_CompleteResult(), __msg);
            return;
        }
    case __type::TAbortResult:
        {
            Write((__v).get_AbortResult(), __msg);
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
PIndexedDBTransactionParent::Read(
        CompleteParams* __v,
        const Message* __msg,
        void** __iter)
{
    typedef CompleteParams __type;
    int type;
    if ((!(Read((&(type)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    switch (type) {
    case __type::TCompleteResult:
        {
            CompleteResult tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_CompleteResult())), __msg, __iter);
        }
    case __type::TAbortResult:
        {
            AbortResult tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_AbortResult())), __msg, __iter);
        }
    default:
        {
            mozilla::ipc::ProtocolErrorBreakpoint("unknown union type");
            return false;
        }
    }
}

void
PIndexedDBTransactionParent::Write(
        const CompleteResult& __v,
        Message* __msg)
{
}

bool
PIndexedDBTransactionParent::Read(
        CompleteResult* __v,
        const Message* __msg,
        void** __iter)
{
    return true;
}

void
PIndexedDBTransactionParent::Write(
        const ObjectStoreConstructorParams& __v,
        Message* __msg)
{
    typedef ObjectStoreConstructorParams __type;
    Write(int((__v).type()), __msg);

    switch ((__v).type()) {
    case __type::TCreateObjectStoreParams:
        {
            Write((__v).get_CreateObjectStoreParams(), __msg);
            return;
        }
    case __type::TGetObjectStoreParams:
        {
            Write((__v).get_GetObjectStoreParams(), __msg);
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
PIndexedDBTransactionParent::Read(
        ObjectStoreConstructorParams* __v,
        const Message* __msg,
        void** __iter)
{
    typedef ObjectStoreConstructorParams __type;
    int type;
    if ((!(Read((&(type)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    switch (type) {
    case __type::TCreateObjectStoreParams:
        {
            CreateObjectStoreParams tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_CreateObjectStoreParams())), __msg, __iter);
        }
    case __type::TGetObjectStoreParams:
        {
            GetObjectStoreParams tmp;
            (*(__v)) = tmp;
            return Read((&((__v)->get_GetObjectStoreParams())), __msg, __iter);
        }
    default:
        {
            mozilla::ipc::ProtocolErrorBreakpoint("unknown union type");
            return false;
        }
    }
}

void
PIndexedDBTransactionParent::Write(
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
PIndexedDBTransactionParent::Read(
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDBTransaction");
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
PIndexedDBTransactionParent::Write(
        const GetObjectStoreParams& __v,
        Message* __msg)
{
    Write((__v).name(), __msg);
}

bool
PIndexedDBTransactionParent::Read(
        GetObjectStoreParams* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->name())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PIndexedDBTransactionParent::Write(
        const CreateObjectStoreParams& __v,
        Message* __msg)
{
    Write((__v).info(), __msg);
}

bool
PIndexedDBTransactionParent::Read(
        CreateObjectStoreParams* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->info())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}

void
PIndexedDBTransactionParent::Write(
        PIndexedDBObjectStoreParent* __v,
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
PIndexedDBTransactionParent::Read(
        PIndexedDBObjectStoreParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PIndexedDBTransaction");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PIndexedDBObjectStore");
        return false;
    }

    if ((PIndexedDBObjectStoreMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PIndexedDBObjectStore has different type");
        return false;
    }

    (*(__v)) = static_cast<PIndexedDBObjectStoreParent*>(listener);
    return true;
}



} // namespace indexedDB
} // namespace dom
} // namespace mozilla