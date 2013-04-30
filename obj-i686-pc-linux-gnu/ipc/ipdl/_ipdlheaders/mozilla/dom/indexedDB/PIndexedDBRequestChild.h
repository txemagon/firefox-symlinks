//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PIndexedDBRequestChild_h
#define PIndexedDBRequestChild_h

#include "mozilla/dom/indexedDB/PIndexedDBRequest.h"
namespace mozilla {
namespace dom {
class PBlobChild;
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBCursorChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBIndexChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBObjectStoreChild;
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
class PIndexedDBIndexChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBObjectStoreChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {
namespace indexedDB {
class PIndexedDBCursorChild;
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace indexedDB {


class /*NS_ABSTRACT_CLASS*/ PIndexedDBRequestChild :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::dom::indexedDB::PIndexedDBIndexChild;

    friend class mozilla::dom::indexedDB::PIndexedDBObjectStoreChild;

    friend class mozilla::dom::indexedDB::PIndexedDBCursorChild;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::dom::indexedDB::ipc::AddResponse AddResponse;
    typedef mozilla::dom::indexedDB::ipc::BlobArray BlobArray;
    typedef mozilla::dom::indexedDB::ipc::ClearResponse ClearResponse;
    typedef mozilla::dom::indexedDB::ipc::ContinueResponse ContinueResponse;
    typedef mozilla::dom::indexedDB::ipc::CountResponse CountResponse;
    typedef mozilla::dom::indexedDB::ipc::DeleteResponse DeleteResponse;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::dom::indexedDB::ipc::GetAllKeysResponse GetAllKeysResponse;
    typedef mozilla::dom::indexedDB::ipc::GetAllResponse GetAllResponse;
    typedef mozilla::dom::indexedDB::ipc::GetKeyResponse GetKeyResponse;
    typedef mozilla::dom::indexedDB::ipc::GetResponse GetResponse;
    typedef mozilla::dom::indexedDB::Key Key;
    typedef mozilla::dom::indexedDB::ipc::OpenCursorResponse OpenCursorResponse;
    typedef mozilla::dom::indexedDB::ipc::PutResponse PutResponse;
    typedef mozilla::dom::indexedDB::ipc::ResponseValue ResponseValue;
    typedef mozilla::dom::indexedDB::SerializedStructuredCloneReadInfo SerializedStructuredCloneReadInfo;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;
    typedef mozilla::dom::PBlobChild PBlobChild;
    typedef mozilla::dom::indexedDB::PIndexedDBCursorChild PIndexedDBCursorChild;
    typedef mozilla::dom::indexedDB::PIndexedDBIndexChild PIndexedDBIndexChild;
    typedef mozilla::dom::indexedDB::PIndexedDBObjectStoreChild PIndexedDBObjectStoreChild;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PIndexedDBRequest::State State;

    virtual bool
    Recv__delete__(const ResponseValue& response);

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
    PIndexedDBRequestChild();

    virtual ~PIndexedDBRequestChild();

    PIndexedDBRequest::State
    state();

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
            const CountResponse& __v,
            Message* __msg);

    bool
    Read(
            CountResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const GetAllKeysResponse& __v,
            Message* __msg);

    bool
    Read(
            GetAllKeysResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const DeleteResponse& __v,
            Message* __msg);

    bool
    Read(
            DeleteResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const ResponseValue& __v,
            Message* __msg);

    bool
    Read(
            ResponseValue* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const OpenCursorResponse& __v,
            Message* __msg);

    bool
    Read(
            OpenCursorResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const AddResponse& __v,
            Message* __msg);

    bool
    Read(
            AddResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const InfallibleTArray<PBlobChild*>& __v,
            Message* __msg);

    bool
    Read(
            InfallibleTArray<PBlobChild*>* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const InfallibleTArray<BlobArray>& __v,
            Message* __msg);

    bool
    Read(
            InfallibleTArray<BlobArray>* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const GetResponse& __v,
            Message* __msg);

    bool
    Read(
            GetResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BlobArray& __v,
            Message* __msg);

    bool
    Read(
            BlobArray* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PIndexedDBRequestChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PIndexedDBRequestChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const ContinueResponse& __v,
            Message* __msg);

    bool
    Read(
            ContinueResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const ClearResponse& __v,
            Message* __msg);

    bool
    Read(
            ClearResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const PutResponse& __v,
            Message* __msg);

    bool
    Read(
            PutResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PBlobChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PBlobChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PIndexedDBCursorChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PIndexedDBCursorChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const GetAllResponse& __v,
            Message* __msg);

    bool
    Read(
            GetAllResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const GetKeyResponse& __v,
            Message* __msg);

    bool
    Read(
            GetKeyResponse* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    Channel* mChannel;
    mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>* mManager;
    int32_t mId;
    State mState;
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
class IndexedDBRequestChild :
    public PIndexedDBRequestChild
{
    IndexedDBRequestChild();
    virtual ~IndexedDBRequestChild();
};
} // namespace indexedDB
} // namespace dom
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace dom {
namespace indexedDB {
IndexedDBRequestChild::IndexedDBRequestChild()
{
    MOZ_COUNT_CTOR(IndexedDBRequestChild);
}

IndexedDBRequestChild::~IndexedDBRequestChild()
{
    MOZ_COUNT_DTOR(IndexedDBRequestChild);
}

} // namespace indexedDB
} // namespace dom
} // namespace mozilla
#endif // if 0

#endif // ifndef PIndexedDBRequestChild_h