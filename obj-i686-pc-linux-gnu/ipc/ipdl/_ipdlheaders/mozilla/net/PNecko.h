//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PNecko_h
#define PNecko_h

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
#include "SerializedLoadContext.h"
#include "mozilla/ipc/URIParams.h"

//-----------------------------------------------------------------------------
// Code common to PNeckoChild and PNeckoParent
//
namespace mozilla {
namespace net {
namespace PNecko {

enum State {
    __Dead,
    __Null,
    __Error,
    __Dying,
    __Start = __Null
};

enum MessageType {
    PNeckoStart = PNeckoMsgStart << 16,
    PNeckoPreStart = (PNeckoMsgStart << 16) - 1,
    Msg___delete____ID,
    Reply___delete____ID,
    Msg_PCookieServiceConstructor__ID,
    Reply_PCookieServiceConstructor__ID,
    Msg_PHttpChannelConstructor__ID,
    Reply_PHttpChannelConstructor__ID,
    Msg_PWyciwygChannelConstructor__ID,
    Reply_PWyciwygChannelConstructor__ID,
    Msg_PFTPChannelConstructor__ID,
    Reply_PFTPChannelConstructor__ID,
    Msg_PWebSocketConstructor__ID,
    Reply_PWebSocketConstructor__ID,
    Msg_PTCPSocketConstructor__ID,
    Reply_PTCPSocketConstructor__ID,
    Msg_PRemoteOpenFileConstructor__ID,
    Reply_PRemoteOpenFileConstructor__ID,
    Msg_HTMLDNSPrefetch__ID,
    Msg_CancelHTMLDNSPrefetch__ID,
    PNeckoEnd
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
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg___delete____ID
    };
    Msg___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg___delete__")
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
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply___delete____ID
    };
    Reply___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply___delete__")
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

class Msg_PCookieServiceConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PCookieServiceConstructor__ID
    };
    Msg_PCookieServiceConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PCookieServiceConstructor")
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
        (__logmsg).append("Msg_PCookieServiceConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PCookieServiceConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PCookieServiceConstructor__ID
    };
    Reply_PCookieServiceConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PCookieServiceConstructor")
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
        (__logmsg).append("Reply_PCookieServiceConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PHttpChannelConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PHttpChannelConstructor__ID
    };
    Msg_PHttpChannelConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PHttpChannelConstructor")
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
        (__logmsg).append("Msg_PHttpChannelConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PHttpChannelConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PHttpChannelConstructor__ID
    };
    Reply_PHttpChannelConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PHttpChannelConstructor")
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
        (__logmsg).append("Reply_PHttpChannelConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PWyciwygChannelConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PWyciwygChannelConstructor__ID
    };
    Msg_PWyciwygChannelConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PWyciwygChannelConstructor")
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
        (__logmsg).append("Msg_PWyciwygChannelConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PWyciwygChannelConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PWyciwygChannelConstructor__ID
    };
    Reply_PWyciwygChannelConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PWyciwygChannelConstructor")
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
        (__logmsg).append("Reply_PWyciwygChannelConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PFTPChannelConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PFTPChannelConstructor__ID
    };
    Msg_PFTPChannelConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PFTPChannelConstructor")
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
        (__logmsg).append("Msg_PFTPChannelConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PFTPChannelConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PFTPChannelConstructor__ID
    };
    Reply_PFTPChannelConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PFTPChannelConstructor")
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
        (__logmsg).append("Reply_PFTPChannelConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PWebSocketConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PWebSocketConstructor__ID
    };
    Msg_PWebSocketConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PWebSocketConstructor")
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
        (__logmsg).append("Msg_PWebSocketConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PWebSocketConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PWebSocketConstructor__ID
    };
    Reply_PWebSocketConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PWebSocketConstructor")
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
        (__logmsg).append("Reply_PWebSocketConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PTCPSocketConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PTCPSocketConstructor__ID
    };
    Msg_PTCPSocketConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PTCPSocketConstructor")
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
        (__logmsg).append("Msg_PTCPSocketConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PTCPSocketConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PTCPSocketConstructor__ID
    };
    Reply_PTCPSocketConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PTCPSocketConstructor")
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
        (__logmsg).append("Reply_PTCPSocketConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_PRemoteOpenFileConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_PRemoteOpenFileConstructor__ID
    };
    Msg_PRemoteOpenFileConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_PRemoteOpenFileConstructor")
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
        (__logmsg).append("Msg_PRemoteOpenFileConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_PRemoteOpenFileConstructor :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_PRemoteOpenFileConstructor__ID
    };
    Reply_PRemoteOpenFileConstructor() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Reply_PRemoteOpenFileConstructor")
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
        (__logmsg).append("Reply_PRemoteOpenFileConstructor(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_HTMLDNSPrefetch :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_HTMLDNSPrefetch__ID
    };
    Msg_HTMLDNSPrefetch() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_HTMLDNSPrefetch")
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
        (__logmsg).append("Msg_HTMLDNSPrefetch(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_CancelHTMLDNSPrefetch :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::GenericURIParams GenericURIParams;
    typedef mozilla::ipc::JARURIParams JARURIParams;
    typedef mozilla::ipc::OptionalURIParams OptionalURIParams;
    typedef IPC::SerializedLoadContext SerializedLoadContext;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::ipc::SimpleURIParams SimpleURIParams;
    typedef mozilla::ipc::StandardURLParams StandardURLParams;
    typedef mozilla::ipc::StandardURLSegment StandardURLSegment;
    typedef mozilla::ipc::URIParams URIParams;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_CancelHTMLDNSPrefetch__ID
    };
    Msg_CancelHTMLDNSPrefetch() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PNecko::Msg_CancelHTMLDNSPrefetch")
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
        (__logmsg).append("Msg_CancelHTMLDNSPrefetch(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};



} // namespace PNecko
} // namespace net
} // namespace mozilla

#endif // ifndef PNecko_h