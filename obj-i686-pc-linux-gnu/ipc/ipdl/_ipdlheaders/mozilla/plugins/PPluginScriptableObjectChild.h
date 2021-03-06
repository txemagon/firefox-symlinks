//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PPluginScriptableObjectChild_h
#define PPluginScriptableObjectChild_h

#include "mozilla/plugins/PPluginScriptableObject.h"
namespace mozilla {
namespace plugins {
class PPluginInstanceChild;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PPluginIdentifierChild;
} // namespace plugins
} // namespace mozilla

#ifdef DEBUG
#include "prenv.h"
#endif // DEBUG
#include "base/id_map.h"
#include "mozilla/ipc/RPCChannel.h"


namespace mozilla {
namespace plugins {
class PPluginInstanceChild;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PPluginModuleChild;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {


class /*NS_ABSTRACT_CLASS*/ PPluginScriptableObjectChild :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::plugins::PPluginInstanceChild;

    friend class mozilla::plugins::PPluginModuleChild;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::plugins::Variant Variant;
    typedef mozilla::null_t null_t;
    typedef mozilla::void_t void_t;
    typedef mozilla::plugins::PPluginInstanceChild PPluginInstanceChild;
    typedef mozilla::plugins::PPluginIdentifierChild PPluginIdentifierChild;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PPluginScriptableObject::State State;

    virtual bool
    Recv__delete__();
    virtual bool
    AnswerInvalidate() = 0;
    virtual bool
    AnswerHasMethod(
            PPluginIdentifierChild* aId,
            bool* aHasMethod) = 0;
    virtual bool
    AnswerInvoke(
            PPluginIdentifierChild* aId,
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess) = 0;
    virtual bool
    AnswerInvokeDefault(
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess) = 0;
    virtual bool
    AnswerHasProperty(
            PPluginIdentifierChild* aId,
            bool* aHasProperty) = 0;
    virtual bool
    AnswerSetProperty(
            PPluginIdentifierChild* aId,
            const Variant& aValue,
            bool* aSuccess) = 0;
    virtual bool
    AnswerRemoveProperty(
            PPluginIdentifierChild* aId,
            bool* aSuccess) = 0;
    virtual bool
    AnswerEnumerate(
            InfallibleTArray<PPluginIdentifierChild*>* aProperties,
            bool* aSuccess) = 0;
    virtual bool
    AnswerConstruct(
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess) = 0;
    virtual bool
    RecvProtect() = 0;
    virtual bool
    RecvUnprotect() = 0;
    virtual bool
    AnswerGetChildProperty(
            PPluginIdentifierChild* aId,
            bool* aHasProperty,
            bool* aHasMethod,
            Variant* aResult,
            bool* aSuccess) = 0;

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
    PPluginScriptableObjectChild();

    virtual ~PPluginScriptableObjectChild();

    PPluginInstanceChild*
    Manager() const;

    PPluginScriptableObject::State
    state();

    static bool
    Send__delete__(PPluginScriptableObjectChild* actor);

    bool
    CallNPN_Evaluate(
            const nsCString& aScript,
            Variant* aResult,
            bool* aSuccess);

    bool
    CallHasMethod(
            PPluginIdentifierChild* aId,
            bool* aHasMethod);

    bool
    CallInvoke(
            PPluginIdentifierChild* aId,
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess);

    bool
    CallInvokeDefault(
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess);

    bool
    CallHasProperty(
            PPluginIdentifierChild* aId,
            bool* aHasProperty);

    bool
    CallSetProperty(
            PPluginIdentifierChild* aId,
            const Variant& aValue,
            bool* aSuccess);

    bool
    CallRemoveProperty(
            PPluginIdentifierChild* aId,
            bool* aSuccess);

    bool
    CallEnumerate(
            InfallibleTArray<PPluginIdentifierChild*>* aProperties,
            bool* aSuccess);

    bool
    CallConstruct(
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess);

    bool
    SendProtect();

    bool
    SendUnprotect();

    bool
    CallGetParentProperty(
            PPluginIdentifierChild* aId,
            Variant* aResult,
            bool* aSuccess);

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
            const InfallibleTArray<Variant>& __v,
            Message* __msg);

    bool
    Read(
            InfallibleTArray<Variant>* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PPluginScriptableObjectChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginScriptableObjectChild** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const InfallibleTArray<PPluginIdentifierChild*>& __v,
            Message* __msg);

    bool
    Read(
            InfallibleTArray<PPluginIdentifierChild*>* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const Variant& __v,
            Message* __msg);

    bool
    Read(
            Variant* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PPluginIdentifierChild* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginIdentifierChild** __v,
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
class PluginScriptableObjectChild :
    public PPluginScriptableObjectChild
{
    virtual bool
    AnswerInvalidate();

    virtual bool
    AnswerHasMethod(
            PPluginIdentifierChild* aId,
            bool* aHasMethod);

    virtual bool
    AnswerInvoke(
            PPluginIdentifierChild* aId,
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess);

    virtual bool
    AnswerInvokeDefault(
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess);

    virtual bool
    AnswerHasProperty(
            PPluginIdentifierChild* aId,
            bool* aHasProperty);

    virtual bool
    AnswerSetProperty(
            PPluginIdentifierChild* aId,
            const Variant& aValue,
            bool* aSuccess);

    virtual bool
    AnswerRemoveProperty(
            PPluginIdentifierChild* aId,
            bool* aSuccess);

    virtual bool
    AnswerEnumerate(
            InfallibleTArray<PPluginIdentifierChild*>* aProperties,
            bool* aSuccess);

    virtual bool
    AnswerConstruct(
            const InfallibleTArray<Variant>& aArgs,
            Variant* aResult,
            bool* aSuccess);

    virtual bool
    RecvProtect();

    virtual bool
    RecvUnprotect();

    virtual bool
    AnswerGetChildProperty(
            PPluginIdentifierChild* aId,
            bool* aHasProperty,
            bool* aHasMethod,
            Variant* aResult,
            bool* aSuccess);

    PluginScriptableObjectChild();
    virtual ~PluginScriptableObjectChild();
};
} // namespace plugins
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace plugins {
bool
PluginScriptableObjectChild::AnswerInvalidate()
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerHasMethod(
        PPluginIdentifierChild* aId,
        bool* aHasMethod)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerInvoke(
        PPluginIdentifierChild* aId,
        const InfallibleTArray<Variant>& aArgs,
        Variant* aResult,
        bool* aSuccess)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerInvokeDefault(
        const InfallibleTArray<Variant>& aArgs,
        Variant* aResult,
        bool* aSuccess)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerHasProperty(
        PPluginIdentifierChild* aId,
        bool* aHasProperty)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerSetProperty(
        PPluginIdentifierChild* aId,
        const Variant& aValue,
        bool* aSuccess)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerRemoveProperty(
        PPluginIdentifierChild* aId,
        bool* aSuccess)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerEnumerate(
        InfallibleTArray<PPluginIdentifierChild*>* aProperties,
        bool* aSuccess)
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerConstruct(
        const InfallibleTArray<Variant>& aArgs,
        Variant* aResult,
        bool* aSuccess)
{
    return false;
}

bool
PluginScriptableObjectChild::RecvProtect()
{
    return false;
}

bool
PluginScriptableObjectChild::RecvUnprotect()
{
    return false;
}

bool
PluginScriptableObjectChild::AnswerGetChildProperty(
        PPluginIdentifierChild* aId,
        bool* aHasProperty,
        bool* aHasMethod,
        Variant* aResult,
        bool* aSuccess)
{
    return false;
}

PluginScriptableObjectChild::PluginScriptableObjectChild()
{
    MOZ_COUNT_CTOR(PluginScriptableObjectChild);
}

PluginScriptableObjectChild::~PluginScriptableObjectChild()
{
    MOZ_COUNT_DTOR(PluginScriptableObjectChild);
}

} // namespace plugins
} // namespace mozilla
#endif // if 0

#endif // ifndef PPluginScriptableObjectChild_h
