//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PObjectWrapper_h
#define PObjectWrapper_h

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
#include "mozilla/jsipc/CPOWTypes.h"

namespace mozilla {
namespace jsipc {
class PObjectWrapperParent;
} // namespace jsipc
} // namespace mozilla

namespace mozilla {
namespace jsipc {
class PObjectWrapperChild;
} // namespace jsipc
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union JSVariant|
//
namespace mozilla {
namespace jsipc {
class JSVariant MOZ_FINAL
{
public:
    enum Type {
        T__None,
        Tvoid_t = 1,
        TPObjectWrapperParent,
        TPObjectWrapperChild,
        TnsString,
        Tint,
        Tdouble,
        Tbool,
        T__Last = Tbool
    };

private:
    typedef mozilla::void_t void_t;
    typedef mozilla::jsipc::PObjectWrapperParent PObjectWrapperParent;
    typedef mozilla::jsipc::PObjectWrapperChild PObjectWrapperChild;
    typedef void_t void_t__tdef;
    typedef PObjectWrapperParent* PObjectWrapperParent__tdef;
    typedef PObjectWrapperChild* PObjectWrapperChild__tdef;
    typedef nsString nsString__tdef;
    typedef int int__tdef;
    typedef double double__tdef;
    typedef bool bool__tdef;

    union Value {
        char Vvoid_t[sizeof(void_t)];
        char VPObjectWrapperParent[sizeof(PObjectWrapperParent*)];
        char VPObjectWrapperChild[sizeof(PObjectWrapperChild*)];
        char VnsString[sizeof(nsString)];
        char Vint[sizeof(int)];
        char Vdouble[sizeof(double)];
        char Vbool[sizeof(bool)];
    };

    void_t*
    ptr_void_t()
    {
        return reinterpret_cast<void_t*>((&((mValue).Vvoid_t)));
    }
    const void_t* const
    constptr_void_t() const
    {
        return reinterpret_cast<const void_t* const>((&((mValue).Vvoid_t)));
    }
    PObjectWrapperParent**
    ptr_PObjectWrapperParent()
    {
        return reinterpret_cast<PObjectWrapperParent**>((&((mValue).VPObjectWrapperParent)));
    }
    PObjectWrapperParent* const*
    constptr_PObjectWrapperParent() const
    {
        return reinterpret_cast<PObjectWrapperParent* const*>((&((mValue).VPObjectWrapperParent)));
    }
    PObjectWrapperChild**
    ptr_PObjectWrapperChild()
    {
        return reinterpret_cast<PObjectWrapperChild**>((&((mValue).VPObjectWrapperChild)));
    }
    PObjectWrapperChild* const*
    constptr_PObjectWrapperChild() const
    {
        return reinterpret_cast<PObjectWrapperChild* const*>((&((mValue).VPObjectWrapperChild)));
    }
    nsString*
    ptr_nsString()
    {
        return reinterpret_cast<nsString*>((&((mValue).VnsString)));
    }
    const nsString* const
    constptr_nsString() const
    {
        return reinterpret_cast<const nsString* const>((&((mValue).VnsString)));
    }
    int*
    ptr_int()
    {
        return reinterpret_cast<int*>((&((mValue).Vint)));
    }
    const int* const
    constptr_int() const
    {
        return reinterpret_cast<const int* const>((&((mValue).Vint)));
    }
    double*
    ptr_double()
    {
        return reinterpret_cast<double*>((&((mValue).Vdouble)));
    }
    const double* const
    constptr_double() const
    {
        return reinterpret_cast<const double* const>((&((mValue).Vdouble)));
    }
    bool*
    ptr_bool()
    {
        return reinterpret_cast<bool*>((&((mValue).Vbool)));
    }
    const bool* const
    constptr_bool() const
    {
        return reinterpret_cast<const bool* const>((&((mValue).Vbool)));
    }

    bool
    MaybeDestroy(Type aNewType);

    void
    AssertSanity() const
    {
        NS_ABORT_IF_FALSE((T__None) <= (mType), "invalid type tag");
        NS_ABORT_IF_FALSE((mType) <= (T__Last), "invalid type tag");
    }
    void
    AssertSanity(Type aType) const
    {
        AssertSanity();
        NS_ABORT_IF_FALSE((mType) == (aType), "unexpected type tag");
    }

public:
    JSVariant() :
        mType(T__None)
    {
    }

    JSVariant(const void_t& aOther);

    JSVariant(PObjectWrapperParent* aOther);

    JSVariant(PObjectWrapperChild* aOther);

    JSVariant(const nsString& aOther);

    JSVariant(const int& aOther);

    JSVariant(const double& aOther);

    JSVariant(const bool& aOther);

    JSVariant(const JSVariant& aOther);

    ~JSVariant();

    Type
    type() const
    {
        return mType;
    }

    JSVariant&
    operator=(const void_t& aRhs);

    JSVariant&
    operator=(PObjectWrapperParent* aRhs);

    JSVariant&
    operator=(PObjectWrapperChild* aRhs);

    JSVariant&
    operator=(const nsString& aRhs);

    JSVariant&
    operator=(const int& aRhs);

    JSVariant&
    operator=(const double& aRhs);

    JSVariant&
    operator=(const bool& aRhs);

    JSVariant&
    operator=(const JSVariant& aRhs);

    bool
    operator==(const void_t& aRhs) const;

    bool
    operator==(PObjectWrapperParent* aRhs) const;

    bool
    operator==(PObjectWrapperChild* aRhs) const;

    bool
    operator==(const nsString& aRhs) const;

    bool
    operator==(const int& aRhs) const;

    bool
    operator==(const double& aRhs) const;

    bool
    operator==(const bool& aRhs) const;

    bool
    operator==(const JSVariant& aRhs) const;

    void_t&
    get_void_t()
    {
        AssertSanity(Tvoid_t);
        return (*(ptr_void_t()));
    }
    const void_t&
    get_void_t() const
    {
        AssertSanity(Tvoid_t);
        return (*(constptr_void_t()));
    }
    operator void_t&()
    {
        return get_void_t();
    }
    operator const void_t&() const
    {
        return get_void_t();
    }

    PObjectWrapperParent*&
    get_PObjectWrapperParent()
    {
        AssertSanity(TPObjectWrapperParent);
        return (*(ptr_PObjectWrapperParent()));
    }
    PObjectWrapperParent*
    get_PObjectWrapperParent() const
    {
        AssertSanity(TPObjectWrapperParent);
        return (*(constptr_PObjectWrapperParent()));
    }
    operator PObjectWrapperParent*&()
    {
        return get_PObjectWrapperParent();
    }
    operator PObjectWrapperParent*() const
    {
        return get_PObjectWrapperParent();
    }

    PObjectWrapperChild*&
    get_PObjectWrapperChild()
    {
        AssertSanity(TPObjectWrapperChild);
        return (*(ptr_PObjectWrapperChild()));
    }
    PObjectWrapperChild*
    get_PObjectWrapperChild() const
    {
        AssertSanity(TPObjectWrapperChild);
        return (*(constptr_PObjectWrapperChild()));
    }
    operator PObjectWrapperChild*&()
    {
        return get_PObjectWrapperChild();
    }
    operator PObjectWrapperChild*() const
    {
        return get_PObjectWrapperChild();
    }

    nsString&
    get_nsString()
    {
        AssertSanity(TnsString);
        return (*(ptr_nsString()));
    }
    const nsString&
    get_nsString() const
    {
        AssertSanity(TnsString);
        return (*(constptr_nsString()));
    }
    operator nsString&()
    {
        return get_nsString();
    }
    operator const nsString&() const
    {
        return get_nsString();
    }

    int&
    get_int()
    {
        AssertSanity(Tint);
        return (*(ptr_int()));
    }
    const int&
    get_int() const
    {
        AssertSanity(Tint);
        return (*(constptr_int()));
    }
    operator int&()
    {
        return get_int();
    }
    operator const int&() const
    {
        return get_int();
    }

    double&
    get_double()
    {
        AssertSanity(Tdouble);
        return (*(ptr_double()));
    }
    const double&
    get_double() const
    {
        AssertSanity(Tdouble);
        return (*(constptr_double()));
    }
    operator double&()
    {
        return get_double();
    }
    operator const double&() const
    {
        return get_double();
    }

    bool&
    get_bool()
    {
        AssertSanity(Tbool);
        return (*(ptr_bool()));
    }
    const bool&
    get_bool() const
    {
        AssertSanity(Tbool);
        return (*(constptr_bool()));
    }
    operator bool&()
    {
        return get_bool();
    }
    operator const bool&() const
    {
        return get_bool();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace jsipc
} // namespace mozilla

namespace mozilla {
namespace jsipc {
class JSVariant;
} // namespace jsipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union OperationStatus|
//
namespace mozilla {
namespace jsipc {
class OperationStatus MOZ_FINAL
{
public:
    enum Type {
        T__None,
        TJSBool = 1,
        TJSVariant,
        T__Last = TJSVariant
    };

private:
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef JSBool JSBool__tdef;
    typedef JSVariant JSVariant__tdef;

    union Value {
        char VJSBool[sizeof(JSBool)];
        char VJSVariant[sizeof(JSVariant)];
    };

    JSBool*
    ptr_JSBool()
    {
        return reinterpret_cast<JSBool*>((&((mValue).VJSBool)));
    }
    const JSBool* const
    constptr_JSBool() const
    {
        return reinterpret_cast<const JSBool* const>((&((mValue).VJSBool)));
    }
    JSVariant*
    ptr_JSVariant()
    {
        return reinterpret_cast<JSVariant*>((&((mValue).VJSVariant)));
    }
    const JSVariant* const
    constptr_JSVariant() const
    {
        return reinterpret_cast<const JSVariant* const>((&((mValue).VJSVariant)));
    }

    bool
    MaybeDestroy(Type aNewType);

    void
    AssertSanity() const
    {
        NS_ABORT_IF_FALSE((T__None) <= (mType), "invalid type tag");
        NS_ABORT_IF_FALSE((mType) <= (T__Last), "invalid type tag");
    }
    void
    AssertSanity(Type aType) const
    {
        AssertSanity();
        NS_ABORT_IF_FALSE((mType) == (aType), "unexpected type tag");
    }

public:
    OperationStatus() :
        mType(T__None)
    {
    }

    OperationStatus(const JSBool& aOther);

    OperationStatus(const JSVariant& aOther);

    OperationStatus(const OperationStatus& aOther);

    ~OperationStatus();

    Type
    type() const
    {
        return mType;
    }

    OperationStatus&
    operator=(const JSBool& aRhs);

    OperationStatus&
    operator=(const JSVariant& aRhs);

    OperationStatus&
    operator=(const OperationStatus& aRhs);

    bool
    operator==(const JSBool& aRhs) const;

    bool
    operator==(const JSVariant& aRhs) const;

    bool
    operator==(const OperationStatus& aRhs) const;

    JSBool&
    get_JSBool()
    {
        AssertSanity(TJSBool);
        return (*(ptr_JSBool()));
    }
    const JSBool&
    get_JSBool() const
    {
        AssertSanity(TJSBool);
        return (*(constptr_JSBool()));
    }
    operator JSBool&()
    {
        return get_JSBool();
    }
    operator const JSBool&() const
    {
        return get_JSBool();
    }

    JSVariant&
    get_JSVariant()
    {
        AssertSanity(TJSVariant);
        return (*(ptr_JSVariant()));
    }
    const JSVariant&
    get_JSVariant() const
    {
        AssertSanity(TJSVariant);
        return (*(constptr_JSVariant()));
    }
    operator JSVariant&()
    {
        return get_JSVariant();
    }
    operator const JSVariant&() const
    {
        return get_JSVariant();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace jsipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Code common to PObjectWrapperChild and PObjectWrapperParent
//
namespace mozilla {
namespace jsipc {
namespace PObjectWrapper {

enum State {
    __Dead,
    __Null,
    __Error,
    __Dying,
    __Start = __Null
};

enum MessageType {
    PObjectWrapperStart = PObjectWrapperMsgStart << 16,
    PObjectWrapperPreStart = (PObjectWrapperMsgStart << 16) - 1,
    Msg___delete____ID,
    Reply___delete____ID,
    Msg_AddProperty__ID,
    Reply_AddProperty__ID,
    Msg_GetProperty__ID,
    Reply_GetProperty__ID,
    Msg_SetProperty__ID,
    Reply_SetProperty__ID,
    Msg_DelProperty__ID,
    Reply_DelProperty__ID,
    Msg_NewEnumerateInit__ID,
    Reply_NewEnumerateInit__ID,
    Msg_NewEnumerateNext__ID,
    Reply_NewEnumerateNext__ID,
    Msg_NewEnumerateDestroy__ID,
    Msg_NewResolve__ID,
    Reply_NewResolve__ID,
    Msg_Convert__ID,
    Reply_Convert__ID,
    Msg_Call__ID,
    Reply_Call__ID,
    Msg_Construct__ID,
    Reply_Construct__ID,
    Msg_HasInstance__ID,
    Reply_HasInstance__ID,
    PObjectWrapperEnd
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
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg___delete____ID
    };
    Msg___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg___delete__")
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
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply___delete____ID
    };
    Reply___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply___delete__")
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

class Msg_AddProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_AddProperty__ID
    };
    Msg_AddProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_AddProperty")
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
        (__logmsg).append("Msg_AddProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_AddProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_AddProperty__ID
    };
    Reply_AddProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_AddProperty")
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
        (__logmsg).append("Reply_AddProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_GetProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_GetProperty__ID
    };
    Msg_GetProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_GetProperty")
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
        (__logmsg).append("Msg_GetProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_GetProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_GetProperty__ID
    };
    Reply_GetProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_GetProperty")
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
        (__logmsg).append("Reply_GetProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_SetProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_SetProperty__ID
    };
    Msg_SetProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_SetProperty")
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
        (__logmsg).append("Msg_SetProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_SetProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_SetProperty__ID
    };
    Reply_SetProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_SetProperty")
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
        (__logmsg).append("Reply_SetProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_DelProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_DelProperty__ID
    };
    Msg_DelProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_DelProperty")
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
        (__logmsg).append("Msg_DelProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_DelProperty :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_DelProperty__ID
    };
    Reply_DelProperty() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_DelProperty")
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
        (__logmsg).append("Reply_DelProperty(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_NewEnumerateInit :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_NewEnumerateInit__ID
    };
    Msg_NewEnumerateInit() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_NewEnumerateInit")
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
        (__logmsg).append("Msg_NewEnumerateInit(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_NewEnumerateInit :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_NewEnumerateInit__ID
    };
    Reply_NewEnumerateInit() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_NewEnumerateInit")
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
        (__logmsg).append("Reply_NewEnumerateInit(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_NewEnumerateNext :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_NewEnumerateNext__ID
    };
    Msg_NewEnumerateNext() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_NewEnumerateNext")
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
        (__logmsg).append("Msg_NewEnumerateNext(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_NewEnumerateNext :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_NewEnumerateNext__ID
    };
    Reply_NewEnumerateNext() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_NewEnumerateNext")
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
        (__logmsg).append("Reply_NewEnumerateNext(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_NewEnumerateDestroy :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_NewEnumerateDestroy__ID
    };
    Msg_NewEnumerateDestroy() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_NewEnumerateDestroy")
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
        (__logmsg).append("Msg_NewEnumerateDestroy(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_NewResolve :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_NewResolve__ID
    };
    Msg_NewResolve() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_NewResolve")
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
        (__logmsg).append("Msg_NewResolve(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_NewResolve :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_NewResolve__ID
    };
    Reply_NewResolve() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_NewResolve")
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
        (__logmsg).append("Reply_NewResolve(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_Convert :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_Convert__ID
    };
    Msg_Convert() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_Convert")
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
        (__logmsg).append("Msg_Convert(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_Convert :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_Convert__ID
    };
    Reply_Convert() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_Convert")
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
        (__logmsg).append("Reply_Convert(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_Call :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_Call__ID
    };
    Msg_Call() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_Call")
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
        (__logmsg).append("Msg_Call(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_Call :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_Call__ID
    };
    Reply_Call() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_Call")
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
        (__logmsg).append("Reply_Call(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_Construct :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_Construct__ID
    };
    Msg_Construct() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_Construct")
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
        (__logmsg).append("Msg_Construct(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_Construct :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_Construct__ID
    };
    Reply_Construct() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_Construct")
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
        (__logmsg).append("Reply_Construct(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Msg_HasInstance :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Msg_HasInstance__ID
    };
    Msg_HasInstance() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Msg_HasInstance")
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
        (__logmsg).append("Msg_HasInstance(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};

class Reply_HasInstance :
    public IPC::Message
{
private:
    typedef mozilla::ipc::ActorHandle ActorHandle;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::jsipc::JSVariant JSVariant;
    typedef mozilla::jsipc::OperationStatus OperationStatus;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::void_t void_t;

public:
    enum {
        ID = Reply_HasInstance__ID
    };
    Reply_HasInstance() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PObjectWrapper::Reply_HasInstance")
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
        (__logmsg).append("Reply_HasInstance(");

        (__logmsg).append("[TODO])\n");
        fputs((__logmsg).c_str(), __outf);
    }
};



} // namespace PObjectWrapper
} // namespace jsipc
} // namespace mozilla

#endif // ifndef PObjectWrapper_h