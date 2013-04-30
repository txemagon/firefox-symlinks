//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PTestShell_h
#define PTestShell_h

#include "mozilla/Attributes.h"
#include "base/basictypes.h"
#include "prtime.h"
#include "nscore.h"
#include "IPCMessageStart.h"
#include "ipc/IPCMessageUtils.h"
#include "nsAutoPtr.h"
#include "nsStringGlue.h"
#include "nsTArray.h"
#include "nsIFile.h"
#include "mozilla/ipc/ProtocolUtils.h"

//-----------------------------------------------------------------------------
// Code common to PTestShellChild and PTestShellParent
//
namespace mozilla {
namespace ipc {
namespace PTestShell {

enum State {
    __Dead,
    __Null,
    __Error,
    __Dying,
    __Start = __Null
};

enum MessageType {
    PTestShellStart = PTestShellMsgStart << 16,
    PTestShellPreStart = (PTestShellMsgStart << 16) - 1,
    Msg___delete____ID,
    Reply___delete____ID,
    Msg_ExecuteCommand__ID,
    Msg_PTestShellCommandConstructor__ID,
    Reply_PTestShellCommandConstructor__ID,
    Msg_PContextWrapperConstructor__ID,
    Reply_PContextWrapperConstructor__ID,
    PTestShellEnd
};

bool
Transition(
        State from,
        mozilla::ipc::Trigger trigger,
        State* next);

class Msg___delete__ :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Msg___delete____ID
    };
    Msg___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Msg___delete__")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg___delete__(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply___delete__ :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Reply___delete____ID
    };
    Reply___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Reply___delete__")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Reply___delete__(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_ExecuteCommand :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Msg_ExecuteCommand__ID
    };
    Msg_ExecuteCommand() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Msg_ExecuteCommand")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_ExecuteCommand(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PTestShellCommandConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Msg_PTestShellCommandConstructor__ID
    };
    Msg_PTestShellCommandConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Msg_PTestShellCommandConstructor")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_PTestShellCommandConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PTestShellCommandConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Reply_PTestShellCommandConstructor__ID
    };
    Reply_PTestShellCommandConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Reply_PTestShellCommandConstructor")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Reply_PTestShellCommandConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PContextWrapperConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Msg_PContextWrapperConstructor__ID
    };
    Msg_PContextWrapperConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Msg_PContextWrapperConstructor")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Msg_PContextWrapperConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PContextWrapperConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;

public:
    enum {
        ID = Reply_PContextWrapperConstructor__ID
    };
    Reply_PContextWrapperConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PTestShell::Reply_PContextWrapperConstructor")
    {
    }

    void
    Log(
            const std::string& __pfx,
            FILE* __outf) const
    {
        std::string __logmsg;
        StringAppendF((&(__logmsg)), "[time:%" PRId64 "][%d]", PR_Now(), base::GetCurrentProcId());
        (__logmsg).append(__pfx);
        (__logmsg).append("Reply_PContextWrapperConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};



} // namespace PTestShell
} // namespace ipc
} // namespace mozilla

#endif // ifndef PTestShell_h