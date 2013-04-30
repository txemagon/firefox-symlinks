//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PBlobStreamParent_h
#define PBlobStreamParent_h

#include "mozilla/dom/PBlobStream.h"
namespace mozilla {
namespace dom {
class PBlobParent;
} // namespace dom
} // namespace mozilla

#ifdef DEBUG
#include "prenv.h"
#endif // DEBUG
#include "base/id_map.h"
#include "mozilla/ipc/RPCChannel.h"


namespace mozilla {
namespace dom {
class PBlobParent;
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {


class /*NS_ABSTRACT_CLASS*/ PBlobStreamParent :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::dom::PBlobParent;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::BufferedInputStreamParams BufferedInputStreamParams;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::FileInputStreamParams FileInputStreamParams;
    typedef mozilla::ipc::InputStreamParams InputStreamParams;
    typedef mozilla::ipc::MIMEInputStreamParams MIMEInputStreamParams;
    typedef mozilla::ipc::MultiplexInputStreamParams MultiplexInputStreamParams;
    typedef mozilla::ipc::OptionalInputStreamParams OptionalInputStreamParams;
    typedef mozilla::ipc::PartialFileInputStreamParams PartialFileInputStreamParams;
    typedef mozilla::ipc::RemoteInputStreamParams RemoteInputStreamParams;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::StringInputStreamParams StringInputStreamParams;
    typedef mozilla::void_t void_t;
    typedef mozilla::dom::PBlobParent PBlobParent;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PBlobStream::State State;

    virtual bool
    Recv__delete__(const InputStreamParams& params);

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
    PBlobStreamParent();

    virtual ~PBlobStreamParent();

    PBlobParent*
    Manager() const;

    PBlobStream::State
    state();

    static bool
    Send__delete__(
            PBlobStreamParent* actor,
            const InputStreamParams& params) NS_WARN_UNUSED_RESULT;

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
            const StringInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            StringInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const FileInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            FileInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const OptionalInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            OptionalInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const MultiplexInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            MultiplexInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const InfallibleTArray<InputStreamParams>& __v,
            Message* __msg);

    bool
    Read(
            InfallibleTArray<InputStreamParams>* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PBlobStreamParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PBlobStreamParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const MIMEInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            MIMEInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const InputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            InputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BufferedInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            BufferedInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const PartialFileInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            PartialFileInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PBlobParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PBlobParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const RemoteInputStreamParams& __v,
            Message* __msg);

    bool
    Read(
            RemoteInputStreamParams* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const FileDescriptor& __v,
            Message* __msg);

    bool
    Read(
            FileDescriptor* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    Channel* mChannel;
    mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>* mManager;
    int32_t mId;
    State mState;
};


} // namespace dom
} // namespace mozilla

#if 0

//-----------------------------------------------------------------------------
// Skeleton implementation of abstract actor class

// Header file contents
namespace mozilla {
namespace dom {
class BlobStreamParent :
    public PBlobStreamParent
{
    BlobStreamParent();
    virtual ~BlobStreamParent();
};
} // namespace dom
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace dom {
BlobStreamParent::BlobStreamParent()
{
    MOZ_COUNT_CTOR(BlobStreamParent);
}

BlobStreamParent::~BlobStreamParent()
{
    MOZ_COUNT_DTOR(BlobStreamParent);
}

} // namespace dom
} // namespace mozilla
#endif // if 0

#endif // ifndef PBlobStreamParent_h