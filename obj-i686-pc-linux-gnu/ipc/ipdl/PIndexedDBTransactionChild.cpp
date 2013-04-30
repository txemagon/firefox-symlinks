//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/indexedDB/PIndexedDBTransactionChild.h"

#include "mozilla/dom/indexedDB/PIndexedDBDatabaseChild.h"
#include "mozilla/dom/indexedDB/PIndexedDBObjectStoreChild.h"

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
using mozilla::dom::indexedDB::PIndexedDBDatabaseChild;
using mozilla::dom::indexedDB::PIndexedDBObjectStoreChild;

namespace mozilla {
namespace dom {
namespace indexedDB {


void
PIndexedDBTransactionChild::ActorDestroy(ActorDestroyReason why)
{
}

PIndexedDBTransactionChild::PIndexedDBTransactionChild() :
    mId(0),
    mState(PIndexedDBTransaction::__Dead)
{
    MOZ_COUNT_CTOR(PIndexedDBTransactionChild);
}

PIndexedDBTransactionChild::~PIndexedDBTransactionChild()
{
    MOZ_COUNT_DTOR(PIndexedDBTransactionChild);
}

PIndexedDBDatabaseChild*
PIndexedDBTransactionChild::Manager() const
{
    return static_cast<PIndexedDBDatabaseChild*>(mManager);
}

void
PIndexedDBTransactionChild::ManagedPIndexedDBObjectStoreChild(InfallibleTArray<PIndexedDBObjectStoreChild*>& aArr) const
{
    aArr = mManagedPIndexedDBObjectStoreChild;
}

const InfallibleTArray<PIndexedDBObjectStoreChild*>&
PIndexedDBTransactionChild::ManagedPIndexedDBObjectStoreChild() const
{
    return mManagedPIndexedDBObjectStoreChild;
}

PIndexedDBTransaction::State
PIndexedDBTransactionChild::state()
{
    return mState;
}

bool
PIndexedDBTransactionChild::Send__delete__(PIndexedDBTransactionChild* actor)
{
    if ((!(actor))) {
        return false;
    }

    if ((!(actor))) {
        return false;
    }

    PIndexedDBTransaction::Msg___delete__* __msg = new PIndexedDBTransaction::Msg___delete__();

    (actor)->Write(actor, __msg, false);

    (__msg)->set_routing_id((actor)->mId);


    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBTransactionChild] Sending ", stderr);
    }
    if ((!(PIndexedDBTransaction::Transition((actor)->mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg___delete____ID), (&((actor)->mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = ((actor)->mChannel)->Send(__msg);

    (actor)->DestroySubtree(Deletion);
    (actor)->DeallocSubtree();
    ((actor)->mManager)->RemoveManagee(PIndexedDBTransactionMsgStart, actor);
    return __sendok;
}

PIndexedDBObjectStoreChild*
PIndexedDBTransactionChild::SendPIndexedDBObjectStoreConstructor(const ObjectStoreConstructorParams& params)
{
    return SendPIndexedDBObjectStoreConstructor(AllocPIndexedDBObjectStore(params), params);
}

PIndexedDBObjectStoreChild*
PIndexedDBTransactionChild::SendPIndexedDBObjectStoreConstructor(
        PIndexedDBObjectStoreChild* actor,
        const ObjectStoreConstructorParams& params)
{
    if ((!(actor))) {
        return 0;
    }
    (actor)->mId = Register(actor);
    (actor)->mManager = this;
    (actor)->mChannel = mChannel;
    (mManagedPIndexedDBObjectStoreChild).InsertElementSorted(actor);
    (actor)->mState = mozilla::dom::indexedDB::PIndexedDBObjectStore::__Start;

    PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor* __msg = new PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor();

    Write(actor, __msg, false);
    Write(params, __msg);

    (__msg)->set_routing_id(mId);


    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBTransactionChild] Sending ", stderr);
    }
    if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_PIndexedDBObjectStoreConstructor__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    if ((!(__sendok))) {
        (actor)->DestroySubtree(FailedConstructor);
        (actor)->DeallocSubtree();
        ((actor)->mManager)->RemoveManagee(PIndexedDBObjectStoreMsgStart, actor);
        return 0;
    }
    return actor;
}

bool
PIndexedDBTransactionChild::SendAbort(const nsresult& abortCode)
{
    PIndexedDBTransaction::Msg_Abort* __msg = new PIndexedDBTransaction::Msg_Abort();

    Write(abortCode, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBTransactionChild] Sending ", stderr);
    }
    if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_Abort__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PIndexedDBTransactionChild::SendAllRequestsFinished()
{
    PIndexedDBTransaction::Msg_AllRequestsFinished* __msg = new PIndexedDBTransaction::Msg_AllRequestsFinished();


    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBTransactionChild] Sending ", stderr);
    }
    if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_AllRequestsFinished__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

bool
PIndexedDBTransactionChild::SendDeleteObjectStore(const nsString& name)
{
    PIndexedDBTransaction::Msg_DeleteObjectStore* __msg = new PIndexedDBTransaction::Msg_DeleteObjectStore();

    Write(name, __msg);

    (__msg)->set_routing_id(mId);



    if (mozilla::ipc::LoggingEnabled()) {
        (__msg)->Log("[PIndexedDBTransactionChild] Sending ", stderr);
    }
    if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Recv, PIndexedDBTransaction::Msg_DeleteObjectStore__ID), (&(mState)))))) {
        NS_WARNING("bad state transition!");
    }

    bool __sendok = (mChannel)->Send(__msg);
    return __sendok;
}

int32_t
PIndexedDBTransactionChild::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PIndexedDBTransactionChild::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PIndexedDBTransactionChild::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PIndexedDBTransactionChild::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PIndexedDBTransactionChild::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    switch (aProtocolId) {
    case PIndexedDBObjectStoreMsgStart:
        {
            PIndexedDBObjectStoreChild* actor = static_cast<PIndexedDBObjectStoreChild*>(aListener);
            NS_ABORT_IF_FALSE(((mManagedPIndexedDBObjectStoreChild).NoIndex) != ((mManagedPIndexedDBObjectStoreChild).BinaryIndexOf(actor)), "actor not managed by this!");

            (mManagedPIndexedDBObjectStoreChild).RemoveElementSorted(actor);
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
PIndexedDBTransactionChild::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PIndexedDBTransactionChild::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PIndexedDBTransactionChild::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PIndexedDBTransactionChild::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PIndexedDBTransactionChild::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PIndexedDBTransactionChild::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PIndexedDBTransactionChild::GetIPCChannel()
{
    return mChannel;
}

PIndexedDBTransactionChild::Result
PIndexedDBTransactionChild::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PIndexedDBTransaction::Reply___delete____ID:
        {
            return MsgProcessed;
        }
    case PIndexedDBTransaction::Reply_PIndexedDBObjectStoreConstructor__ID:
        {
            return MsgProcessed;
        }
    case PIndexedDBTransaction::Msg_Complete__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PIndexedDBTransaction::Msg_Complete");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PIndexedDBTransaction::Msg_Complete*>((&(__msg))))->Log("[PIndexedDBTransactionChild] Received ", stderr);
            }

            void* __iter = 0;
            CompleteParams params;

            if ((!(Read((&(params)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PIndexedDBTransaction::Transition(mState, Trigger(Trigger::Send, PIndexedDBTransaction::Msg_Complete__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvComplete(params)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for Complete returned error code");
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

PIndexedDBTransactionChild::Result
PIndexedDBTransactionChild::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PIndexedDBTransactionChild::Result
PIndexedDBTransactionChild::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PIndexedDBTransactionChild::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PIndexedDBTransactionChild::GetProtocolTypeId()
{
    return PIndexedDBTransactionMsgStart;
}

bool
PIndexedDBTransactionChild::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PIndexedDBTransactionChild::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PIndexedDBTransactionChild::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PIndexedDBTransactionChild::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PIndexedDBTransactionChild::AllocShmem(
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
PIndexedDBTransactionChild::AllocUnsafeShmem(
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
PIndexedDBTransactionChild::AdoptShmem(
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
PIndexedDBTransactionChild::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PIndexedDBTransactionChild::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_RUNTIMEABORT("[PIndexedDBTransactionChild] abort()ing as a result");
}

void
PIndexedDBTransactionChild::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    ActorDestroyReason subtreewhy = (((why) == (Deletion)) || ((why) == (FailedConstructor)) ? AncestorDeletion : why);

    {
        // Recursively shutting down PIndexedDBObjectStore kids
        InfallibleTArray<PIndexedDBObjectStoreChild*> kids(mManagedPIndexedDBObjectStoreChild);
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DestroySubtree(subtreewhy);
        }
    }

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PIndexedDBTransactionChild::DeallocSubtree()
{
    {
        // Recursively deleting PIndexedDBObjectStore kids
        InfallibleTArray<PIndexedDBObjectStoreChild*>& kids = mManagedPIndexedDBObjectStoreChild;
        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            (kids[i])->DeallocSubtree();
        }

        for (uint32_t i = 0; (i) < ((kids).Length()); (++(i))) {
            DeallocPIndexedDBObjectStore(kids[i]);
        }
        (mManagedPIndexedDBObjectStoreChild).Clear();
    }
}

void
PIndexedDBTransactionChild::Write(
        const AbortResult& __v,
        Message* __msg)
{
    Write((__v).errorCode(), __msg);
}

bool
PIndexedDBTransactionChild::Read(
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
PIndexedDBTransactionChild::Write(
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
PIndexedDBTransactionChild::Read(
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
PIndexedDBTransactionChild::Write(
        const CompleteResult& __v,
        Message* __msg)
{
}

bool
PIndexedDBTransactionChild::Read(
        CompleteResult* __v,
        const Message* __msg,
        void** __iter)
{
    return true;
}

void
PIndexedDBTransactionChild::Write(
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
PIndexedDBTransactionChild::Read(
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
PIndexedDBTransactionChild::Write(
        PIndexedDBTransactionChild* __v,
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
PIndexedDBTransactionChild::Read(
        PIndexedDBTransactionChild** __v,
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

    (*(__v)) = static_cast<PIndexedDBTransactionChild*>(listener);
    return true;
}

void
PIndexedDBTransactionChild::Write(
        const GetObjectStoreParams& __v,
        Message* __msg)
{
    Write((__v).name(), __msg);
}

bool
PIndexedDBTransactionChild::Read(
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
PIndexedDBTransactionChild::Write(
        const CreateObjectStoreParams& __v,
        Message* __msg)
{
    Write((__v).info(), __msg);
}

bool
PIndexedDBTransactionChild::Read(
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
PIndexedDBTransactionChild::Write(
        PIndexedDBObjectStoreChild* __v,
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
PIndexedDBTransactionChild::Read(
        PIndexedDBObjectStoreChild** __v,
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

    (*(__v)) = static_cast<PIndexedDBObjectStoreChild*>(listener);
    return true;
}



} // namespace indexedDB
} // namespace dom
} // namespace mozilla