//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/PCrashReporterParent.h"

#include "mozilla/dom/PContentParent.h"
#include "mozilla/plugins/PPluginModuleParent.h"

typedef IPC::Message Message;
typedef mozilla::ipc::RPCChannel Channel;
typedef mozilla::ipc::RPCChannel::RPCListener ChannelListener;
typedef base::ProcessHandle ProcessHandle;
typedef mozilla::ipc::AsyncChannel AsyncChannel;
typedef mozilla::ipc::SharedMemory SharedMemory;
typedef mozilla::ipc::Trigger Trigger;
typedef mozilla::ipc::ActorHandle ActorHandle;
typedef mozilla::ipc::FileDescriptor FileDescriptor;
typedef mozilla::dom::Mapping Mapping;
typedef mozilla::ipc::Shmem Shmem;
using mozilla::dom::PContentParent;
using mozilla::plugins::PPluginModuleParent;

namespace mozilla {
namespace dom {


bool
PCrashReporterParent::Recv__delete__()
{
    return true;
}

void
PCrashReporterParent::ActorDestroy(ActorDestroyReason why)
{
}

PCrashReporterParent::PCrashReporterParent() :
    mId(0),
    mState(PCrashReporter::__Dead)
{
    MOZ_COUNT_CTOR(PCrashReporterParent);
}

PCrashReporterParent::~PCrashReporterParent()
{
    MOZ_COUNT_DTOR(PCrashReporterParent);
}

PCrashReporter::State
PCrashReporterParent::state()
{
    return mState;
}

int32_t
PCrashReporterParent::Register(ChannelListener* aRouted)
{
    return (mManager)->Register(aRouted);
}

int32_t
PCrashReporterParent::RegisterID(
        ChannelListener* aRouted,
        int32_t aId)
{
    return (mManager)->RegisterID(aRouted, aId);
}

ChannelListener*
PCrashReporterParent::Lookup(int32_t aId)
{
    return (mManager)->Lookup(aId);
}

void
PCrashReporterParent::Unregister(int32_t aId)
{
    return (mManager)->Unregister(aId);
}

void
PCrashReporterParent::RemoveManagee(
        int32_t aProtocolId,
        ChannelListener* aListener)
{
    NS_RUNTIMEABORT("unreached");
    return;
}

Shmem::SharedMemory*
PCrashReporterParent::CreateSharedMemory(
        size_t aSize,
        Shmem::SharedMemory::SharedMemoryType aType,
        bool aUnsafe,
        Shmem::id_t* aId)
{
    return (mManager)->CreateSharedMemory(aSize, aType, aUnsafe, aId);
}

bool
PCrashReporterParent::AdoptSharedMemory(
        Shmem::SharedMemory* segment,
        Shmem::id_t* aId)
{
    return (mManager)->AdoptSharedMemory(segment, aId);
}

Shmem::SharedMemory*
PCrashReporterParent::LookupSharedMemory(Shmem::id_t aId)
{
    return (mManager)->LookupSharedMemory(aId);
}

bool
PCrashReporterParent::IsTrackingSharedMemory(Shmem::SharedMemory* segment)
{
    return (mManager)->IsTrackingSharedMemory(segment);
}

bool
PCrashReporterParent::DestroySharedMemory(Shmem& shmem)
{
    return (mManager)->DestroySharedMemory(shmem);
}

ProcessHandle
PCrashReporterParent::OtherProcess() const
{
    return (mManager)->OtherProcess();
}

AsyncChannel*
PCrashReporterParent::GetIPCChannel()
{
    return mChannel;
}

PCrashReporterParent::Result
PCrashReporterParent::OnMessageReceived(const Message& __msg)
{
    switch ((__msg).type()) {
    case PCrashReporter::Msg_AddLibraryMappings__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PCrashReporter::Msg_AddLibraryMappings");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PCrashReporter::Msg_AddLibraryMappings*>((&(__msg))))->Log("[PCrashReporterParent] Received ", stderr);
            }

            void* __iter = 0;
            InfallibleTArray<Mapping> m;

            if ((!(Read((&(m)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PCrashReporter::Transition(mState, Trigger(Trigger::Recv, PCrashReporter::Msg_AddLibraryMappings__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvAddLibraryMappings(m)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for AddLibraryMappings returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PCrashReporter::Msg_AnnotateCrashReport__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PCrashReporter::Msg_AnnotateCrashReport");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PCrashReporter::Msg_AnnotateCrashReport*>((&(__msg))))->Log("[PCrashReporterParent] Received ", stderr);
            }

            void* __iter = 0;
            nsCString key;
            nsCString data;

            if ((!(Read((&(key)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            if ((!(Read((&(data)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PCrashReporter::Transition(mState, Trigger(Trigger::Recv, PCrashReporter::Msg_AnnotateCrashReport__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvAnnotateCrashReport(key, data)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for AnnotateCrashReport returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PCrashReporter::Msg_AppendAppNotes__ID:
        {
            (const_cast<Message&>(__msg)).set_name("PCrashReporter::Msg_AppendAppNotes");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PCrashReporter::Msg_AppendAppNotes*>((&(__msg))))->Log("[PCrashReporterParent] Received ", stderr);
            }

            void* __iter = 0;
            nsCString data;

            if ((!(Read((&(data)), (&(__msg)), (&(__iter)))))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PCrashReporter::Transition(mState, Trigger(Trigger::Recv, PCrashReporter::Msg_AppendAppNotes__ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(RecvAppendAppNotes(data)))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for AppendAppNotes returned error code");
                return MsgProcessingError;
            }

            return MsgProcessed;
        }
    case PCrashReporter::Msg___delete____ID:
        {
            (const_cast<Message&>(__msg)).set_name("PCrashReporter::Msg___delete__");
            if (mozilla::ipc::LoggingEnabled()) {
                (static_cast<const PCrashReporter::Msg___delete__*>((&(__msg))))->Log("[PCrashReporterParent] Received ", stderr);
            }

            void* __iter = 0;
            PCrashReporterParent* actor;

            if ((!(Read((&(actor)), (&(__msg)), (&(__iter)), false)))) {
                FatalError("error deserializing (better message TODO)");
                return MsgValueError;
            }
            (__msg).EndRead(__iter);
            if ((!(PCrashReporter::Transition(mState, Trigger(Trigger::Recv, PCrashReporter::Msg___delete____ID), (&(mState)))))) {
                NS_WARNING("bad state transition!");
            }
            if ((!(Recv__delete__()))) {
                mozilla::ipc::ProtocolErrorBreakpoint("Handler for __delete__ returned error code");
                return MsgProcessingError;
            }

            (actor)->DestroySubtree(Deletion);
            (actor)->DeallocSubtree();
            ((actor)->mManager)->RemoveManagee(PCrashReporterMsgStart, actor);


            return MsgProcessed;
        }
    default:
        {
            return MsgNotKnown;
        }
    }
}

PCrashReporterParent::Result
PCrashReporterParent::OnMessageReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

PCrashReporterParent::Result
PCrashReporterParent::OnCallReceived(
        const Message& __msg,
        Message*& __reply)
{
    return MsgNotKnown;
}

void
PCrashReporterParent::OnProcessingError(Result code)
{
    NS_RUNTIMEABORT("`OnProcessingError' called on non-toplevel actor");
}

int32_t
PCrashReporterParent::GetProtocolTypeId()
{
    return PCrashReporterMsgStart;
}

bool
PCrashReporterParent::OnReplyTimeout()
{
    NS_RUNTIMEABORT("`OnReplyTimeout' called on non-toplevel actor");
    return false;
}

void
PCrashReporterParent::OnChannelClose()
{
    NS_RUNTIMEABORT("`OnClose' called on non-toplevel actor");
}

void
PCrashReporterParent::OnChannelError()
{
    NS_RUNTIMEABORT("`OnError' called on non-toplevel actor");
}

void
PCrashReporterParent::OnChannelConnected(int32_t pid)
{
    NS_RUNTIMEABORT("'OnConnected' called on non-toplevel actor");
}

bool
PCrashReporterParent::AllocShmem(
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
PCrashReporterParent::AllocUnsafeShmem(
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
PCrashReporterParent::AdoptShmem(
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
PCrashReporterParent::DeallocShmem(Shmem& aMem)
{
    bool ok = DestroySharedMemory(aMem);
    (aMem).forget(Shmem::IHadBetterBeIPDLCodeCallingThis_OtherwiseIAmADoodyhead());
    return ok;
}

void
PCrashReporterParent::FatalError(const char* const msg) const
{
    // Virtual method to prevent inlining.
    // This give us better error reporting.
    // See bug 589371

    NS_ERROR("IPDL error:");
    NS_ERROR(msg);
    mozilla::ipc::ProtocolErrorBreakpoint(msg);

    NS_ERROR("[PCrashReporterParent] killing child side as a result");

    if ((!(base::KillProcess(OtherProcess(), base::PROCESS_END_KILLED_BY_USER, false)))) {
        NS_ERROR("  may have failed to kill child!");
    }
}

void
PCrashReporterParent::DestroySubtree(ActorDestroyReason why)
{
    // Unregister from our manager.
    Unregister(mId);
    mId = 1;

    // Finally, destroy "us".
    ActorDestroy(why);
}

void
PCrashReporterParent::DeallocSubtree()
{
}

void
PCrashReporterParent::Write(
        const InfallibleTArray<Mapping>& __v,
        Message* __msg)
{
    uint32_t length = (__v).Length();
    Write(length, __msg);

    for (uint32_t i = 0; (i) < (length); (++(i))) {
        Write(__v[i], __msg);
    }
}

bool
PCrashReporterParent::Read(
        InfallibleTArray<Mapping>* __v,
        const Message* __msg,
        void** __iter)
{
    InfallibleTArray<Mapping>& a = (*(__v));
    uint32_t length;
    if ((!(Read((&(length)), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }

    (__v)->SetLength(length);
    for (uint32_t i = 0; (i) < (length); (++(i))) {
        if ((!(Read((&(a[i])), __msg, __iter)))) {
            mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
            return false;
        }
    }
    return true;
}

void
PCrashReporterParent::Write(
        PCrashReporterParent* __v,
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
PCrashReporterParent::Read(
        PCrashReporterParent** __v,
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
        mozilla::ipc::ProtocolErrorBreakpoint("bad ID for PCrashReporter");
        return false;
    }

    if ((0) == (id)) {
        (*(__v)) = 0;
        return true;
    }

    ChannelListener* listener = Lookup(id);
    if ((!(listener))) {
        mozilla::ipc::ProtocolErrorBreakpoint("could not look up PCrashReporter");
        return false;
    }

    if ((PCrashReporterMsgStart) != ((listener)->GetProtocolTypeId())) {
        mozilla::ipc::ProtocolErrorBreakpoint("actor that should be of type PCrashReporter has different type");
        return false;
    }

    (*(__v)) = static_cast<PCrashReporterParent*>(listener);
    return true;
}

void
PCrashReporterParent::Write(
        const Mapping& __v,
        Message* __msg)
{
    Write((__v).library_name(), __msg);
    Write((__v).file_id(), __msg);
    Write((__v).start_address(), __msg);
    Write((__v).mapping_length(), __msg);
    Write((__v).file_offset(), __msg);
}

bool
PCrashReporterParent::Read(
        Mapping* __v,
        const Message* __msg,
        void** __iter)
{
    if ((!(Read((&((__v)->library_name())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->file_id())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->start_address())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->mapping_length())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    if ((!(Read((&((__v)->file_offset())), __msg, __iter)))) {
        mozilla::ipc::ProtocolErrorBreakpoint("error deserializing (better message TODO)");
        return false;
    }
    return true;
}



} // namespace dom
} // namespace mozilla