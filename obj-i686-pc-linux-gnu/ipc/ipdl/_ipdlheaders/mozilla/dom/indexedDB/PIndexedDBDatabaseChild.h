//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PIndexedDBDatabaseChild_h
#define PIndexedDBDatabaseChild_h

#include "mozilla/dom/indexedDB/PIndexedDBDatabase.h"
namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBTransactionChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

#ifdef DEBUG
#include "prenv.h"
#endif // DEBUG
#include "base/id_map.h"
#include "mozilla/ipc/RPCChannel.h"


namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBTransactionChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace indexedDB {


class /*NS_ABSTRACT_CLASS*/ PIndexedDBDatabaseChild :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::dom::indexedDB::PIndexedDBTransactionChild;

    friend class mozilla::dom::indexedDB::PIndexedDBChild;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::dom::indexedDB::DatabaseInfoGuts DatabaseInfoGuts;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::dom::indexedDB::IDBTransaction::Mode Mode;
    typedef mozilla::dom::indexedDB::ipc::NormalTransactionParams NormalTransactionParams;
    typedef mozilla::dom::indexedDB::ObjectStoreInfoGuts ObjectStoreInfoGuts;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::dom::indexedDB::ipc::TransactionParams TransactionParams;
    typedef mozilla::dom::indexedDB::ipc::VersionChangeTransactionParams VersionChangeTransactionParams;
    typedef mozilla::dom::indexedDB::PIndexedDBChild PIndexedDBChild;
    typedef mozilla::dom::indexedDB::PIndexedDBTransactionChild PIndexedDBTransactionChild;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PIndexedDBDatabase::State State;

    virtual bool
    RecvSuccess(
            const DatabaseInfoGuts& dbInfo,
            const InfallibleTArray<ObjectStoreInfoGuts>& osInfo) = 0;
    virtual bool
    RecvError(const nsresult& rv) = 0;
    virtual bool
    RecvBlocked(const uint64_t& oldVersion) = 0;
    virtual bool
    RecvVersionChange(
            const uint64_t& oldVersion,
            const uint64_t& newVersion) = 0;
    virtual bool
    RecvInvalidate() = 0;
    virtual bool
    RecvPIndexedDBTransactionConstructor(
            PIndexedDBTransactionChild* actor,
            const TransactionParams& params);
    virtual PIndexedDBTransactionChild*
    AllocPIndexedDBTransaction(const TransactionParams& params) = 0;
    virtual bool
    DeallocPIndexedDBTransaction(PIndexedDBTransactionChild* actor) = 0;

    virtual void
    ActorDestroy(ActorDestroyReason why);

public:
    typedef IPC::Message Message;
    typedef mozilla::ipc::RPCChannel Channel;
    typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
    typedef base::ProcessHandle ProcessHandle;
    typedef mozilla::ipc::AsyncChannel AsyncChannel;
    typedef mozilla::ipc::SharedMemory SharedMemory;
    typedef mozilla::ipc::Trigger Trigger;

public:
    PIndexedDBDatabaseChild();

    virtual ~PIndexedDBDatabaseChild();

    PIndexedDBChild*
    Manager() const;

    void
    ManagedPIndexedDBTransactionChild(InfallibleTArray<PIndexedDBTransactionChild*>& aArr) const;
    const InfallibleTArray<PIndexedDBTransactionChild*>&
    ManagedPIndexedDBTransactionChild() const;

    PIndexedDBDatabase::State
    state();

    static bool
    Send__delete__(PIndexedDBDatabaseChild* actor);

    bool
    SendClose(const bool& unlinked);

    PIndexedDBTransactionChild*
    SendPIndexedDBTransactionConstructor(const TransactionParams& params);

    PIndexedDBTransactionChild*
    SendPIndexedDBTransactionConstructor(
            PIndexedDBTransactionChild* actor,
            const TransactionParams& params);

    virtual int32_t
    Register(ChannelListener* aRouted);
    virtual int32_t
    RegisterID(
            ChannelListener* aRouted,
            int32_t aId);
    virtual ChannelListener*
    Lookup(int32_t aId);
    virtual void
    Unregister(int32_t aId);
    virtual void
    RemoveManagee(
            int32_t aProtocolId,
            ChannelListener* aListener);
    virtual Shmem::SharedMemory*
    CreateSharedMemory(
            size_t aSize,
            Shmem::SharedMemory::SharedMemoryType aType,
            bool aUnsafe,
            Shmem::id_t* aId);
    virtual bool
    AdoptSharedMemory(
            Shmem::SharedMemory* segment,
            Shmem::id_t* aId);
    virtual Shmem::SharedMemory*
    LookupSharedMemory(Shmem::id_t aId);
    virtual bool
    IsTrackingSharedMemory(Shmem::SharedMemory* segment);
    virtual bool
    DestroySharedMemory(Shmem& shmem);
    virtual ProcessHandle
    OtherProcess() const;
    virtual AsyncChannel*
    GetIPCChannel();

    virtual Result
    OnMessageReceived(const Message& __msg);

    virtual Result
    OnMessageReceived(
            const Message& __msg,
            Message*& __reply);

    virtual Result
    OnCallReceived(
            const Message& __msg,
            Message*& __reply);

    void
    OnProcessingError(Result code);

    int32_t
    GetProtocolTypeId();

    bool
    OnReplyTimeout();

    void
    OnChannelClose();

    void
    OnChannelError();

    void
    OnChannelConnected(int32_t pid);

    // Methods for managing shmem
    bool
    AllocShmem(
            size_t aSize,
            Shmem::SharedMemory::SharedMemoryType aType,
            Shmem* aMem);

    bool
    AllocUnsafeShmem(
            size_t aSize,
            Shmem::SharedMemory::SharedMemoryType aType,
            Shmem* aMem);

    bool
    AdoptShmem(
            Shmem& aMem,
            Shmem* aOutMem);

    bool
    DeallocShmem(Shmem& aMem);

private:
    virtual void
    FatalError(const char* const msg) const;

    void
    DestroySubtree(ActorDestroyReason why);

    void
    DeallocSubtree();

    template<typename T>
    void
    Write(
            const T& __v,
            Message* __msg)
    {
        IPC::WriteParam(__msg, __v);
    }

    template<typename T>
    bool
    Read(
            T* __v,
            const Message* __msg,
            void** __iter)
    {
        return IPC::ReadParam(__msg, __iter, __v);
    }

    void
    Write(
            PIndexedDBDatabaseChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PIndexedDBDatabaseChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PIndexedDBTransactionChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PIndexedDBTransactionChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const NormalTransactionParams& __v,
            Message* __msg);

    bool
    Read(
            NormalTransactionParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const TransactionParams& __v,
            Message* __msg);

    bool
    Read(
            TransactionParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const VersionChangeTransactionParams& __v,
            Message* __msg);

    bool
    Read(
            VersionChangeTransactionParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    Channel* mChannel;
    mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>* mManager;
    int32_t mId;
    State mState;
    // Sorted by pointer value
    InfallibleTArray<PIndexedDBTransactionChild*> mManagedPIndexedDBTransactionChild;
};


} // namespace indexedDB
} // namespace dom
} // namespace mozilla

#if 0

//-----------------------------------------------------------------------------
// Skeleton implementation of abstract actor class

// Header file contents
namespace mozilla {
namespace dom {
namespace indexedDB {
class IndexedDBDatabaseChild :
    public PIndexedDBDatabaseChild
{
    virtual bool
    RecvSuccess(
            const DatabaseInfoGuts& dbInfo,
            const InfallibleTArray<ObjectStoreInfoGuts>& osInfo);

    virtual bool
    RecvError(const nsresult& rv);

    virtual bool
    RecvBlocked(const uint64_t& oldVersion);

    virtual bool
    RecvVersionChange(
            const uint64_t& oldVersion,
            const uint64_t& newVersion);

    virtual bool
    RecvInvalidate();

    virtual PIndexedDBTransactionChild*
    AllocPIndexedDBTransaction(const TransactionParams& params);

    virtual bool
    DeallocPIndexedDBTransaction(PIndexedDBTransactionChild* actor);

    IndexedDBDatabaseChild();
    virtual ~IndexedDBDatabaseChild();
};
} // namespace indexedDB
} // namespace dom
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace dom {
namespace indexedDB {
bool
IndexedDBDatabaseChild::RecvSuccess(
        const DatabaseInfoGuts& dbInfo,
        const InfallibleTArray<ObjectStoreInfoGuts>& osInfo)
{
    return false;
}

bool
IndexedDBDatabaseChild::RecvError(const nsresult& rv)
{
    return false;
}

bool
IndexedDBDatabaseChild::RecvBlocked(const uint64_t& oldVersion)
{
    return false;
}

bool
IndexedDBDatabaseChild::RecvVersionChange(
        const uint64_t& oldVersion,
        const uint64_t& newVersion)
{
    return false;
}

bool
IndexedDBDatabaseChild::RecvInvalidate()
{
    return false;
}

PIndexedDBTransactionChild*
IndexedDBDatabaseChild::AllocPIndexedDBTransaction(const TransactionParams& params)
{
    return 0;
}

bool
IndexedDBDatabaseChild::DeallocPIndexedDBTransaction(PIndexedDBTransactionChild* actor)
{
    return false;
}

IndexedDBDatabaseChild::IndexedDBDatabaseChild()
{
    MOZ_COUNT_CTOR(IndexedDBDatabaseChild);
}

IndexedDBDatabaseChild::~IndexedDBDatabaseChild()
{
    MOZ_COUNT_DTOR(IndexedDBDatabaseChild);
}

} // namespace indexedDB
} // namespace dom
} // namespace mozilla
#endif // if 0

#endif // ifndef PIndexedDBDatabaseChild_h