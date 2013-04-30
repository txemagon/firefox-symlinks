//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PPluginInstanceParent_h
#define PPluginInstanceParent_h

#include "mozilla/plugins/PPluginInstance.h"
namespace mozilla {
namespace plugins {
class PPluginBackgroundDestroyerParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PPluginModuleParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PPluginScriptableObjectParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PBrowserStreamParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PPluginStreamParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PStreamNotifyParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {
class PPluginSurfaceParent;
} // namespace plugins
} // namespace mozilla

#ifdef DEBUG
#include "prenv.h"
#endif // DEBUG
#include "base/id_map.h"
#include "mozilla/ipc/RPCChannel.h"


namespace mozilla {
namespace plugins {
class PPluginStreamParent;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PPluginSurfaceParent;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PPluginBackgroundDestroyerParent;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PBrowserStreamParent;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PPluginModuleParent;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PStreamNotifyParent;
} // namespace plugins
} // namespace mozilla


namespace mozilla {
namespace plugins {
class PPluginScriptableObjectParent;
} // namespace plugins
} // namespace mozilla

namespace mozilla {
namespace plugins {


class /*NS_ABSTRACT_CLASS*/ PPluginInstanceParent :
    protected mozilla::ipc::RPCChannel::RPCListener,
    protected mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>
{
    friend class mozilla::plugins::PPluginStreamParent;

    friend class mozilla::plugins::PPluginSurfaceParent;

    friend class mozilla::plugins::PPluginBackgroundDestroyerParent;

    friend class mozilla::plugins::PBrowserStreamParent;

    friend class mozilla::plugins::PPluginModuleParent;

    friend class mozilla::plugins::PStreamNotifyParent;

    friend class mozilla::plugins::PPluginScriptableObjectParent;

protected:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::plugins::AsyncSurfaceDescriptor AsyncSurfaceDescriptor;
    typedef mozilla::CrossProcessMutexHandle CrossProcessMutexHandle;
    typedef mozilla::plugins::DXGISharedSurfaceHandle DXGISharedSurfaceHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::plugins::IOSurfaceDescriptor IOSurfaceDescriptor;
    typedef mozilla::plugins::NPRemoteAsyncSurface NPRemoteAsyncSurface;
    typedef mozilla::plugins::NativeWindowHandle NativeWindowHandle;
    typedef mozilla::plugins::OptionalShmem OptionalShmem;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::plugins::SurfaceDescriptor SurfaceDescriptor;
    typedef mozilla::plugins::WindowsSharedMemoryHandle WindowsSharedMemoryHandle;
    typedef mozilla::gfxSurfaceType gfxSurfaceType;
    typedef mozilla::null_t null_t;
    typedef mozilla::plugins::PPluginBackgroundDestroyerParent PPluginBackgroundDestroyerParent;
    typedef mozilla::plugins::PPluginModuleParent PPluginModuleParent;
    typedef mozilla::plugins::PPluginScriptableObjectParent PPluginScriptableObjectParent;
    typedef mozilla::plugins::PBrowserStreamParent PBrowserStreamParent;
    typedef mozilla::plugins::PPluginStreamParent PPluginStreamParent;
    typedef mozilla::plugins::PStreamNotifyParent PStreamNotifyParent;
    typedef mozilla::plugins::PPluginSurfaceParent PPluginSurfaceParent;
    typedef base::ProcessId ProcessId;
    typedef mozilla::ipc::ProtocolId ProtocolId;
    typedef mozilla::ipc::Transport Transport;
    typedef mozilla::ipc::TransportDescriptor TransportDescriptor;

    typedef PPluginInstance::State State;

    virtual bool
    AnswerNPN_GetValue_NPNVWindowNPObject(
            PPluginScriptableObjectParent** value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetValue_NPNVPluginElementNPObject(
            PPluginScriptableObjectParent** value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetValue_NPNVprivateModeBool(
            bool* value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetValue_NPNVnetscapeWindow(
            NativeWindowHandle* value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetValue_NPNVdocumentOrigin(
            nsCString* value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetValue_DrawingModelSupport(
            const NPNVariable& model,
            bool* value) = 0;
    virtual bool
    AnswerNPN_SetValue_NPPVpluginWindow(
            const bool& windowed,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_SetValue_NPPVpluginTransparent(
            const bool& transparent,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_SetValue_NPPVpluginUsesDOMForCursor(
            const bool& useDOMForCursor,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_SetValue_NPPVpluginDrawingModel(
            const int& drawingModel,
            OptionalShmem* remoteImageData,
            CrossProcessMutexHandle* mutex,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_SetValue_NPPVpluginEventModel(
            const int& eventModel,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetURL(
            const nsCString& url,
            const nsCString& target,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_PostURL(
            const nsCString& url,
            const nsCString& target,
            const nsCString& buffer,
            const bool& file,
            NPError* result) = 0;
    virtual bool
    AnswerPStreamNotifyConstructor(
            PStreamNotifyParent* actor,
            const nsCString& url,
            const nsCString& target,
            const bool& post,
            const nsCString& buffer,
            const bool& file,
            NPError* result);
    virtual bool
    RecvNPN_InvalidateRect(const NPRect& rect) = 0;
    virtual bool
    RecvShow(
            const NPRect& updatedRect,
            const SurfaceDescriptor& newSurface,
            SurfaceDescriptor* prevSurface) = 0;
    virtual bool
    RecvPPluginSurfaceConstructor(
            PPluginSurfaceParent* actor,
            const WindowsSharedMemoryHandle& handle,
            const gfxIntSize& size,
            const bool& transparent);
    virtual bool
    AnswerNPN_PushPopupsEnabledState(const bool& aState) = 0;
    virtual bool
    AnswerNPN_PopPopupsEnabledState() = 0;
    virtual bool
    AnswerNPN_GetValueForURL(
            const NPNURLVariable& variable,
            const nsCString& url,
            nsCString* value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_SetValueForURL(
            const NPNURLVariable& variable,
            const nsCString& url,
            const nsCString& value,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_GetAuthenticationInfo(
            const nsCString& protocol_,
            const nsCString& host,
            const int32_t& port,
            const nsCString& scheme,
            const nsCString& realm,
            nsCString* username,
            nsCString* password,
            NPError* result) = 0;
    virtual bool
    AnswerNPN_ConvertPoint(
            const double& sourceX,
            const bool& ignoreDestX,
            const double& sourceY,
            const bool& ignoreDestY,
            const NPCoordinateSpace& sourceSpace,
            const NPCoordinateSpace& destSpace,
            double* destX,
            double* destY,
            bool* result) = 0;
    virtual bool
    RecvRedrawPlugin() = 0;
    virtual bool
    AnswerNPN_InitAsyncSurface(
            const gfxIntSize& size,
            const NPImageFormat& format,
            NPRemoteAsyncSurface* surfData,
            bool* result) = 0;
    virtual bool
    RecvNegotiatedCarbon() = 0;
    virtual bool
    RecvReleaseDXGISharedSurface(const DXGISharedSurfaceHandle& handle) = 0;
    virtual bool
    RecvPPluginScriptableObjectConstructor(PPluginScriptableObjectParent* actor);
    virtual bool
    AnswerPPluginStreamConstructor(
            PPluginStreamParent* actor,
            const nsCString& mimeType,
            const nsCString& target,
            NPError* result);
    virtual bool
    AnswerPluginFocusChange(const bool& gotFocus) = 0;
    virtual PStreamNotifyParent*
    AllocPStreamNotify(
            const nsCString& url,
            const nsCString& target,
            const bool& post,
            const nsCString& buffer,
            const bool& file,
            NPError* result) = 0;
    virtual bool
    DeallocPStreamNotify(PStreamNotifyParent* actor) = 0;
    virtual PPluginSurfaceParent*
    AllocPPluginSurface(
            const WindowsSharedMemoryHandle& handle,
            const gfxIntSize& size,
            const bool& transparent) = 0;
    virtual bool
    DeallocPPluginSurface(PPluginSurfaceParent* actor) = 0;
    virtual PPluginScriptableObjectParent*
    AllocPPluginScriptableObject() = 0;
    virtual bool
    DeallocPPluginScriptableObject(PPluginScriptableObjectParent* actor) = 0;
    virtual PBrowserStreamParent*
    AllocPBrowserStream(
            const nsCString& url,
            const uint32_t& length,
            const uint32_t& lastmodified,
            PStreamNotifyParent* notifyData,
            const nsCString& headers,
            const nsCString& mimeType,
            const bool& seekable,
            NPError* rv,
            uint16_t* stype) = 0;
    virtual bool
    DeallocPBrowserStream(PBrowserStreamParent* actor) = 0;
    virtual PPluginStreamParent*
    AllocPPluginStream(
            const nsCString& mimeType,
            const nsCString& target,
            NPError* result) = 0;
    virtual bool
    DeallocPPluginStream(PPluginStreamParent* actor) = 0;
    virtual PPluginBackgroundDestroyerParent*
    AllocPPluginBackgroundDestroyer() = 0;
    virtual bool
    DeallocPPluginBackgroundDestroyer(PPluginBackgroundDestroyerParent* actor) = 0;

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
    PPluginInstanceParent();

    virtual ~PPluginInstanceParent();

    PPluginModuleParent*
    Manager() const;

    void
    ManagedPPluginBackgroundDestroyerParent(InfallibleTArray<PPluginBackgroundDestroyerParent*>& aArr) const;
    const InfallibleTArray<PPluginBackgroundDestroyerParent*>&
    ManagedPPluginBackgroundDestroyerParent() const;

    void
    ManagedPPluginScriptableObjectParent(InfallibleTArray<PPluginScriptableObjectParent*>& aArr) const;
    const InfallibleTArray<PPluginScriptableObjectParent*>&
    ManagedPPluginScriptableObjectParent() const;

    void
    ManagedPBrowserStreamParent(InfallibleTArray<PBrowserStreamParent*>& aArr) const;
    const InfallibleTArray<PBrowserStreamParent*>&
    ManagedPBrowserStreamParent() const;

    void
    ManagedPPluginStreamParent(InfallibleTArray<PPluginStreamParent*>& aArr) const;
    const InfallibleTArray<PPluginStreamParent*>&
    ManagedPPluginStreamParent() const;

    void
    ManagedPStreamNotifyParent(InfallibleTArray<PStreamNotifyParent*>& aArr) const;
    const InfallibleTArray<PStreamNotifyParent*>&
    ManagedPStreamNotifyParent() const;

    void
    ManagedPPluginSurfaceParent(InfallibleTArray<PPluginSurfaceParent*>& aArr) const;
    const InfallibleTArray<PPluginSurfaceParent*>&
    ManagedPPluginSurfaceParent() const;

    PPluginInstance::State
    state();

    static bool
    Call__delete__(PPluginInstanceParent* actor) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_SetWindow(const NPRemoteWindow& window) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_GetValue_NPPVpluginWantsAllNetworkStreams(
            bool* value,
            NPError* result) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_GetValue_NPPVpluginNeedsXEmbed(
            bool* value,
            NPError* result) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_GetValue_NPPVpluginScriptableNPObject(
            PPluginScriptableObjectParent** value,
            NPError* result) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_SetValue_NPNVprivateModeBool(
            const bool& value,
            NPError* result) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_GetValue_NPPVpluginNativeAccessibleAtkPlugId(
            nsCString* plug_id,
            NPError* result) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_HandleEvent(
            const NPRemoteEvent& event,
            int16_t* handled) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_HandleEvent_Shmem(
            const NPRemoteEvent& event,
            Shmem& buffer,
            int16_t* handled,
            Shmem* rtnbuffer) NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_HandleEvent_IOSurface(
            const NPRemoteEvent& event,
            const uint32_t& surfaceid,
            int16_t* handled) NS_WARN_UNUSED_RESULT;

    bool
    CallPaint(
            const NPRemoteEvent& event,
            int16_t* handled) NS_WARN_UNUSED_RESULT;

    bool
    SendWindowPosChanged(const NPRemoteEvent& event) NS_WARN_UNUSED_RESULT;

    bool
    SendContentsScaleFactorChanged(const double& aContentsScaleFactor) NS_WARN_UNUSED_RESULT;

    bool
    SendAsyncSetWindow(
            const gfxSurfaceType& surfaceType,
            const NPRemoteWindow& window) NS_WARN_UNUSED_RESULT;

    bool
    SendUpdateBackground(
            const SurfaceDescriptor& background,
            const nsIntRect& rect) NS_WARN_UNUSED_RESULT;

    bool
    CallHandleTextEvent(
            const nsTextEvent& event,
            bool* handled) NS_WARN_UNUSED_RESULT;

    bool
    CallHandleKeyEvent(
            const nsKeyEvent& event,
            bool* handled) NS_WARN_UNUSED_RESULT;

    bool
    SendNPP_DidComposite() NS_WARN_UNUSED_RESULT;

    bool
    CallNPP_Destroy(NPError* rv) NS_WARN_UNUSED_RESULT;

    PPluginScriptableObjectParent*
    SendPPluginScriptableObjectConstructor() NS_WARN_UNUSED_RESULT;

    PPluginScriptableObjectParent*
    SendPPluginScriptableObjectConstructor(PPluginScriptableObjectParent* actor) NS_WARN_UNUSED_RESULT;

    PBrowserStreamParent*
    CallPBrowserStreamConstructor(
            const nsCString& url,
            const uint32_t& length,
            const uint32_t& lastmodified,
            PStreamNotifyParent* notifyData,
            const nsCString& headers,
            const nsCString& mimeType,
            const bool& seekable,
            NPError* rv,
            uint16_t* stype) NS_WARN_UNUSED_RESULT;

    PBrowserStreamParent*
    CallPBrowserStreamConstructor(
            PBrowserStreamParent* actor,
            const nsCString& url,
            const uint32_t& length,
            const uint32_t& lastmodified,
            PStreamNotifyParent* notifyData,
            const nsCString& headers,
            const nsCString& mimeType,
            const bool& seekable,
            NPError* rv,
            uint16_t* stype) NS_WARN_UNUSED_RESULT;

    bool
    CallSetPluginFocus() NS_WARN_UNUSED_RESULT;

    bool
    CallUpdateWindow() NS_WARN_UNUSED_RESULT;

    PPluginBackgroundDestroyerParent*
    SendPPluginBackgroundDestroyerConstructor() NS_WARN_UNUSED_RESULT;

    PPluginBackgroundDestroyerParent*
    SendPPluginBackgroundDestroyerConstructor(PPluginBackgroundDestroyerParent* actor) NS_WARN_UNUSED_RESULT;

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
            const SurfaceDescriptor& __v,
            Message* __msg);

    bool
    Read(
            SurfaceDescriptor* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PPluginStreamParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginStreamParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const NPRemoteAsyncSurface& __v,
            Message* __msg);

    bool
    Read(
            NPRemoteAsyncSurface* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            Shmem& __v,
            Message* __msg);

    bool
    Read(
            Shmem* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

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

    void
    Write(
            PPluginBackgroundDestroyerParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginBackgroundDestroyerParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const IOSurfaceDescriptor& __v,
            Message* __msg);

    bool
    Read(
            IOSurfaceDescriptor* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PBrowserStreamParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PBrowserStreamParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PPluginInstanceParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginInstanceParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const OptionalShmem& __v,
            Message* __msg);

    bool
    Read(
            OptionalShmem* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PStreamNotifyParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PStreamNotifyParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    void
    Write(
            const AsyncSurfaceDescriptor& __v,
            Message* __msg);

    bool
    Read(
            AsyncSurfaceDescriptor* __v,
            const Message* __msg,
            void** __iter) NS_WARN_UNUSED_RESULT;

    void
    Write(
            PPluginScriptableObjectParent* __v,
            Message* __msg,
            bool __nullable);

    bool
    Read(
            PPluginScriptableObjectParent** __v,
            const Message* __msg,
            void** __iter,
            bool __nullable) NS_WARN_UNUSED_RESULT;

    Channel* mChannel;
    mozilla::ipc::IProtocolManager<mozilla::ipc::RPCChannel::RPCListener>* mManager;
    int32_t mId;
    State mState;
    // Sorted by pointer value
    InfallibleTArray<PPluginBackgroundDestroyerParent*> mManagedPPluginBackgroundDestroyerParent;
    // Sorted by pointer value
    InfallibleTArray<PPluginScriptableObjectParent*> mManagedPPluginScriptableObjectParent;
    // Sorted by pointer value
    InfallibleTArray<PBrowserStreamParent*> mManagedPBrowserStreamParent;
    // Sorted by pointer value
    InfallibleTArray<PPluginStreamParent*> mManagedPPluginStreamParent;
    // Sorted by pointer value
    InfallibleTArray<PStreamNotifyParent*> mManagedPStreamNotifyParent;
    // Sorted by pointer value
    InfallibleTArray<PPluginSurfaceParent*> mManagedPPluginSurfaceParent;
};


} // namespace plugins
} // namespace mozilla

#if 0

//-----------------------------------------------------------------------------
// Skeleton implementation of abstract actor class

// Header file contents
namespace mozilla {
namespace plugins {
class PluginInstanceParent :
    public PPluginInstanceParent
{
    virtual bool
    AnswerNPN_GetValue_NPNVWindowNPObject(
            PPluginScriptableObjectParent** value,
            NPError* result);

    virtual bool
    AnswerNPN_GetValue_NPNVPluginElementNPObject(
            PPluginScriptableObjectParent** value,
            NPError* result);

    virtual bool
    AnswerNPN_GetValue_NPNVprivateModeBool(
            bool* value,
            NPError* result);

    virtual bool
    AnswerNPN_GetValue_NPNVnetscapeWindow(
            NativeWindowHandle* value,
            NPError* result);

    virtual bool
    AnswerNPN_GetValue_NPNVdocumentOrigin(
            nsCString* value,
            NPError* result);

    virtual bool
    AnswerNPN_GetValue_DrawingModelSupport(
            const NPNVariable& model,
            bool* value);

    virtual bool
    AnswerNPN_SetValue_NPPVpluginWindow(
            const bool& windowed,
            NPError* result);

    virtual bool
    AnswerNPN_SetValue_NPPVpluginTransparent(
            const bool& transparent,
            NPError* result);

    virtual bool
    AnswerNPN_SetValue_NPPVpluginUsesDOMForCursor(
            const bool& useDOMForCursor,
            NPError* result);

    virtual bool
    AnswerNPN_SetValue_NPPVpluginDrawingModel(
            const int& drawingModel,
            OptionalShmem* remoteImageData,
            CrossProcessMutexHandle* mutex,
            NPError* result);

    virtual bool
    AnswerNPN_SetValue_NPPVpluginEventModel(
            const int& eventModel,
            NPError* result);

    virtual bool
    AnswerNPN_GetURL(
            const nsCString& url,
            const nsCString& target,
            NPError* result);

    virtual bool
    AnswerNPN_PostURL(
            const nsCString& url,
            const nsCString& target,
            const nsCString& buffer,
            const bool& file,
            NPError* result);

    virtual bool
    RecvNPN_InvalidateRect(const NPRect& rect);

    virtual bool
    RecvShow(
            const NPRect& updatedRect,
            const SurfaceDescriptor& newSurface,
            SurfaceDescriptor* prevSurface);

    virtual bool
    AnswerNPN_PushPopupsEnabledState(const bool& aState);

    virtual bool
    AnswerNPN_PopPopupsEnabledState();

    virtual bool
    AnswerNPN_GetValueForURL(
            const NPNURLVariable& variable,
            const nsCString& url,
            nsCString* value,
            NPError* result);

    virtual bool
    AnswerNPN_SetValueForURL(
            const NPNURLVariable& variable,
            const nsCString& url,
            const nsCString& value,
            NPError* result);

    virtual bool
    AnswerNPN_GetAuthenticationInfo(
            const nsCString& protocol_,
            const nsCString& host,
            const int32_t& port,
            const nsCString& scheme,
            const nsCString& realm,
            nsCString* username,
            nsCString* password,
            NPError* result);

    virtual bool
    AnswerNPN_ConvertPoint(
            const double& sourceX,
            const bool& ignoreDestX,
            const double& sourceY,
            const bool& ignoreDestY,
            const NPCoordinateSpace& sourceSpace,
            const NPCoordinateSpace& destSpace,
            double* destX,
            double* destY,
            bool* result);

    virtual bool
    RecvRedrawPlugin();

    virtual bool
    AnswerNPN_InitAsyncSurface(
            const gfxIntSize& size,
            const NPImageFormat& format,
            NPRemoteAsyncSurface* surfData,
            bool* result);

    virtual bool
    RecvNegotiatedCarbon();

    virtual bool
    RecvReleaseDXGISharedSurface(const DXGISharedSurfaceHandle& handle);

    virtual bool
    AnswerPluginFocusChange(const bool& gotFocus);

    virtual PStreamNotifyParent*
    AllocPStreamNotify(
            const nsCString& url,
            const nsCString& target,
            const bool& post,
            const nsCString& buffer,
            const bool& file,
            NPError* result);

    virtual bool
    DeallocPStreamNotify(PStreamNotifyParent* actor);

    virtual PPluginSurfaceParent*
    AllocPPluginSurface(
            const WindowsSharedMemoryHandle& handle,
            const gfxIntSize& size,
            const bool& transparent);

    virtual bool
    DeallocPPluginSurface(PPluginSurfaceParent* actor);

    virtual PPluginScriptableObjectParent*
    AllocPPluginScriptableObject();

    virtual bool
    DeallocPPluginScriptableObject(PPluginScriptableObjectParent* actor);

    virtual PBrowserStreamParent*
    AllocPBrowserStream(
            const nsCString& url,
            const uint32_t& length,
            const uint32_t& lastmodified,
            PStreamNotifyParent* notifyData,
            const nsCString& headers,
            const nsCString& mimeType,
            const bool& seekable,
            NPError* rv,
            uint16_t* stype);

    virtual bool
    DeallocPBrowserStream(PBrowserStreamParent* actor);

    virtual PPluginStreamParent*
    AllocPPluginStream(
            const nsCString& mimeType,
            const nsCString& target,
            NPError* result);

    virtual bool
    DeallocPPluginStream(PPluginStreamParent* actor);

    virtual PPluginBackgroundDestroyerParent*
    AllocPPluginBackgroundDestroyer();

    virtual bool
    DeallocPPluginBackgroundDestroyer(PPluginBackgroundDestroyerParent* actor);

    PluginInstanceParent();
    virtual ~PluginInstanceParent();
};
} // namespace plugins
} // namespace mozilla


// C++ file contents
namespace mozilla {
namespace plugins {
bool
PluginInstanceParent::AnswerNPN_GetValue_NPNVWindowNPObject(
        PPluginScriptableObjectParent** value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetValue_NPNVPluginElementNPObject(
        PPluginScriptableObjectParent** value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetValue_NPNVprivateModeBool(
        bool* value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetValue_NPNVnetscapeWindow(
        NativeWindowHandle* value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetValue_NPNVdocumentOrigin(
        nsCString* value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetValue_DrawingModelSupport(
        const NPNVariable& model,
        bool* value)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_SetValue_NPPVpluginWindow(
        const bool& windowed,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_SetValue_NPPVpluginTransparent(
        const bool& transparent,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_SetValue_NPPVpluginUsesDOMForCursor(
        const bool& useDOMForCursor,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_SetValue_NPPVpluginDrawingModel(
        const int& drawingModel,
        OptionalShmem* remoteImageData,
        CrossProcessMutexHandle* mutex,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_SetValue_NPPVpluginEventModel(
        const int& eventModel,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetURL(
        const nsCString& url,
        const nsCString& target,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_PostURL(
        const nsCString& url,
        const nsCString& target,
        const nsCString& buffer,
        const bool& file,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::RecvNPN_InvalidateRect(const NPRect& rect)
{
    return false;
}

bool
PluginInstanceParent::RecvShow(
        const NPRect& updatedRect,
        const SurfaceDescriptor& newSurface,
        SurfaceDescriptor* prevSurface)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_PushPopupsEnabledState(const bool& aState)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_PopPopupsEnabledState()
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetValueForURL(
        const NPNURLVariable& variable,
        const nsCString& url,
        nsCString* value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_SetValueForURL(
        const NPNURLVariable& variable,
        const nsCString& url,
        const nsCString& value,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_GetAuthenticationInfo(
        const nsCString& protocol_,
        const nsCString& host,
        const int32_t& port,
        const nsCString& scheme,
        const nsCString& realm,
        nsCString* username,
        nsCString* password,
        NPError* result)
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_ConvertPoint(
        const double& sourceX,
        const bool& ignoreDestX,
        const double& sourceY,
        const bool& ignoreDestY,
        const NPCoordinateSpace& sourceSpace,
        const NPCoordinateSpace& destSpace,
        double* destX,
        double* destY,
        bool* result)
{
    return false;
}

bool
PluginInstanceParent::RecvRedrawPlugin()
{
    return false;
}

bool
PluginInstanceParent::AnswerNPN_InitAsyncSurface(
        const gfxIntSize& size,
        const NPImageFormat& format,
        NPRemoteAsyncSurface* surfData,
        bool* result)
{
    return false;
}

bool
PluginInstanceParent::RecvNegotiatedCarbon()
{
    return false;
}

bool
PluginInstanceParent::RecvReleaseDXGISharedSurface(const DXGISharedSurfaceHandle& handle)
{
    return false;
}

bool
PluginInstanceParent::AnswerPluginFocusChange(const bool& gotFocus)
{
    return false;
}

PStreamNotifyParent*
PluginInstanceParent::AllocPStreamNotify(
        const nsCString& url,
        const nsCString& target,
        const bool& post,
        const nsCString& buffer,
        const bool& file,
        NPError* result)
{
    return 0;
}

bool
PluginInstanceParent::DeallocPStreamNotify(PStreamNotifyParent* actor)
{
    return false;
}

PPluginSurfaceParent*
PluginInstanceParent::AllocPPluginSurface(
        const WindowsSharedMemoryHandle& handle,
        const gfxIntSize& size,
        const bool& transparent)
{
    return 0;
}

bool
PluginInstanceParent::DeallocPPluginSurface(PPluginSurfaceParent* actor)
{
    return false;
}

PPluginScriptableObjectParent*
PluginInstanceParent::AllocPPluginScriptableObject()
{
    return 0;
}

bool
PluginInstanceParent::DeallocPPluginScriptableObject(PPluginScriptableObjectParent* actor)
{
    return false;
}

PBrowserStreamParent*
PluginInstanceParent::AllocPBrowserStream(
        const nsCString& url,
        const uint32_t& length,
        const uint32_t& lastmodified,
        PStreamNotifyParent* notifyData,
        const nsCString& headers,
        const nsCString& mimeType,
        const bool& seekable,
        NPError* rv,
        uint16_t* stype)
{
    return 0;
}

bool
PluginInstanceParent::DeallocPBrowserStream(PBrowserStreamParent* actor)
{
    return false;
}

PPluginStreamParent*
PluginInstanceParent::AllocPPluginStream(
        const nsCString& mimeType,
        const nsCString& target,
        NPError* result)
{
    return 0;
}

bool
PluginInstanceParent::DeallocPPluginStream(PPluginStreamParent* actor)
{
    return false;
}

PPluginBackgroundDestroyerParent*
PluginInstanceParent::AllocPPluginBackgroundDestroyer()
{
    return 0;
}

bool
PluginInstanceParent::DeallocPPluginBackgroundDestroyer(PPluginBackgroundDestroyerParent* actor)
{
    return false;
}

PluginInstanceParent::PluginInstanceParent()
{
    MOZ_COUNT_CTOR(PluginInstanceParent);
}

PluginInstanceParent::~PluginInstanceParent()
{
    MOZ_COUNT_DTOR(PluginInstanceParent);
}

} // namespace plugins
} // namespace mozilla
#endif // if 0

#endif // ifndef PPluginInstanceParent_h