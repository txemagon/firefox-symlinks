//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PPluginSurfaceParent_h
#define PPluginSurfaceParent_h

#include "mozilla/plugins/PPluginSurface.h"
namespace mozilla {
namespace plugins {
class PPluginInstanceParent;
} // namespace plugins
} // namespace mozilla

#ifdef DEBUG
#include "prenv.h"
#endif // DEBUG
#include "base/id_map.h"
#include "mozilla/ipc/RPCChannel.h"


namespace mozilla {
namespace plugins {
class PPluginInstanceParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {


class /*NS_ABSTRACT_CLASS*/ PPluginSurfaceParent :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::plugins::PPluginInstanceParent;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::plugins::PPluginInstanceParent PPluginInstanceParent;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PPluginSurface::State State;

    virtual bool
    Recv__delete__();

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
    PPluginSurfaceParent();

    virtual ~PPluginSurfaceParent();

    PPluginInstanceParent*
    Manager() const;

    PPluginSurface::State
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
            PPluginSurfaceParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginSurfaceParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    Channel* mChannel;
    mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>* mManager;
    int32_t mId;
    State mState;
};


} // namespace plugins
} // namespace mozilla

#if 0

//-----------------------------------------------------------------------------
// Skeleton implementation of abstract actor class

// Header file contents
namespace mozilla {
namespace plugins {
class PluginSurfaceParent :
    public PPluginSurfaceParent
{
    PluginSurfaceParent();
    virtual ~PluginSurfaceParent();
};
} // namespace plugins
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace plugins {
PluginSurfaceParent::PluginSurfaceParent()
{
    MOZ_COUNT_CTOR(PluginSurfaceParent);
}

PluginSurfaceParent::~PluginSurfaceParent()
{
    MOZ_COUNT_DTOR(PluginSurfaceParent);
}

} // namespace plugins
} // namespace mozilla
#endif // if 0

#endif // ifndef PPluginSurfaceParent_h