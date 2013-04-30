//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PBluetoothRequestChild_h
#define PBluetoothRequestChild_h

#include "mozilla/dom/bluetooth/PBluetoothRequest.h"
namespace mozilla {
namespace dom {
namespace bluetooth {
class PBluetoothChild;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

#ifdef DEBUG
#include "prenv.h"
#endif // DEBUG
#include "base/id_map.h"
#include "mozilla/ipc/RPCChannel.h"


namespace mozilla {
namespace dom {
namespace bluetooth {
class PBluetoothChild;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace bluetooth {


class /*NS_ABSTRACT_CLASS*/ PBluetoothRequestChild :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::dom::bluetooth::PBluetoothChild;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::dom::bluetooth::BluetoothNamedValue BluetoothNamedValue;
    typedef mozilla::dom::bluetooth::BluetoothReply BluetoothReply;
    typedef mozilla::dom::bluetooth::BluetoothReplyError BluetoothReplyError;
    typedef mozilla::dom::bluetooth::BluetoothReplySuccess BluetoothReplySuccess;
    typedef mozilla::dom::bluetooth::BluetoothSignal BluetoothSignal;
    typedef mozilla::dom::bluetooth::BluetoothValue BluetoothValue;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::dom::bluetooth::PBluetoothChild PBluetoothChild;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PBluetoothRequest::State State;

    virtual bool
    Recv__delete__(const BluetoothReply& response);

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
    PBluetoothRequestChild();

    virtual ~PBluetoothRequestChild();

    PBluetoothChild*
    Manager() const;

    PBluetoothRequest::State
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
            const InfallibleTArray<BluetoothNamedValue>& __v,
            Message* __msg);

    bool
    Read(
            InfallibleTArray<BluetoothNamedValue>* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BluetoothNamedValue& __v,
            Message* __msg);

    bool
    Read(
            BluetoothNamedValue* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BluetoothReplySuccess& __v,
            Message* __msg);

    bool
    Read(
            BluetoothReplySuccess* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BluetoothReply& __v,
            Message* __msg);

    bool
    Read(
            BluetoothReply* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BluetoothReplyError& __v,
            Message* __msg);

    bool
    Read(
            BluetoothReplyError* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const BluetoothValue& __v,
            Message* __msg);

    bool
    Read(
            BluetoothValue* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PBluetoothRequestChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PBluetoothRequestChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    Channel* mChannel;
    mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>* mManager;
    int32_t mId;
    State mState;
};


} // namespace bluetooth
} // namespace dom
} // namespace mozilla

#if 0

//-----------------------------------------------------------------------------
// Skeleton implementation of abstract actor class

// Header file contents
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothRequestChild :
    public PBluetoothRequestChild
{
    BluetoothRequestChild();
    virtual ~BluetoothRequestChild();
};
} // namespace bluetooth
} // namespace dom
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace dom {
namespace bluetooth {
BluetoothRequestChild::BluetoothRequestChild()
{
    MOZ_COUNT_CTOR(BluetoothRequestChild);
}

BluetoothRequestChild::~BluetoothRequestChild()
{
    MOZ_COUNT_DTOR(BluetoothRequestChild);
}

} // namespace bluetooth
} // namespace dom
} // namespace mozilla
#endif // if 0

#endif // ifndef PBluetoothRequestChild_h