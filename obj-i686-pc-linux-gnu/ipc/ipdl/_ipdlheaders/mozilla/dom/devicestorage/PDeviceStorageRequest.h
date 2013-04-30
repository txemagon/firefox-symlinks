//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef PDeviceStorageRequest_h
#define PDeviceStorageRequest_h

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
// Declaration of the IPDL type |struct ErrorResponse|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class ErrorResponse MOZ_FINAL
{
private:

public:
    ErrorResponse();

    ErrorResponse(const nsString& _error)
    {
        Init();
        Assign(_error);
    }

    ErrorResponse(const ErrorResponse& _o)
    {
        Init();
        Assign((_o).error());
    }

    ~ErrorResponse();

    void
    operator=(const ErrorResponse& _o)
    {
        Assign((_o).error());
    }

    bool
    operator==(const ErrorResponse& _o) const;

    nsString&
    error()
    {
        return error_;
    }
    const nsString&
    error() const
    {
        return error_;
    }

private:
    void
    Init();

    void
    Assign(const nsString& _error);

    nsString error_;
};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct SuccessResponse|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class SuccessResponse MOZ_FINAL
{
private:

public:
    SuccessResponse()
    {
        Init();
        Assign();
    }

    SuccessResponse(const SuccessResponse& _o)
    {
        Init();
        Assign();
    }

    ~SuccessResponse();

    void
    operator=(const SuccessResponse& _o)
    {
        Assign();
    }

    bool
    operator==(const SuccessResponse& _o) const;

private:
    void
    Init();

    void
    Assign();

};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
class PBlobParent;
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
class PBlobChild;
} // namespace dom
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct BlobResponse|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class BlobResponse MOZ_FINAL
{
private:
    typedef mozilla::dom::PBlobParent PBlobParent;
    typedef mozilla::dom::PBlobChild PBlobChild;

public:
    BlobResponse();

    BlobResponse(
            PBlobParent* _blobParent,
            PBlobChild* _blobChild)
    {
        Init();
        Assign(_blobParent, _blobChild);
    }

    BlobResponse(const BlobResponse& _o)
    {
        Init();
        Assign(const_cast<PBlobParent*>((_o).blobParent()), const_cast<PBlobChild*>((_o).blobChild()));
    }

    ~BlobResponse();

    void
    operator=(const BlobResponse& _o)
    {
        Assign(const_cast<PBlobParent*>((_o).blobParent()), const_cast<PBlobChild*>((_o).blobChild()));
    }

    bool
    operator==(const BlobResponse& _o) const;

    PBlobParent*&
    blobParent()
    {
        return blobParent_;
    }
    PBlobParent*
    blobParent() const
    {
        return blobParent_;
    }

    PBlobChild*&
    blobChild()
    {
        return blobChild_;
    }
    PBlobChild*
    blobChild() const
    {
        return blobChild_;
    }

private:
    void
    Init();

    void
    Assign(
            PBlobParent* _blobParent,
            PBlobChild* _blobChild);

    PBlobParent* blobParent_;
    PBlobChild* blobChild_;
};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct DeviceStorageFileValue|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class DeviceStorageFileValue MOZ_FINAL
{
private:

public:
    DeviceStorageFileValue();

    DeviceStorageFileValue(
            const nsString& _type,
            const nsString& _name,
            const nsString& _fullpath)
    {
        Init();
        Assign(_type, _name, _fullpath);
    }

    DeviceStorageFileValue(const DeviceStorageFileValue& _o)
    {
        Init();
        Assign((_o).type(), (_o).name(), (_o).fullpath());
    }

    ~DeviceStorageFileValue();

    void
    operator=(const DeviceStorageFileValue& _o)
    {
        Assign((_o).type(), (_o).name(), (_o).fullpath());
    }

    bool
    operator==(const DeviceStorageFileValue& _o) const;

    nsString&
    type()
    {
        return type_;
    }
    const nsString&
    type() const
    {
        return type_;
    }

    nsString&
    name()
    {
        return name_;
    }
    const nsString&
    name() const
    {
        return name_;
    }

    nsString&
    fullpath()
    {
        return fullpath_;
    }
    const nsString&
    fullpath() const
    {
        return fullpath_;
    }

private:
    void
    Init();

    void
    Assign(
            const nsString& _type,
            const nsString& _name,
            const nsString& _fullpath);

    nsString type_;
    nsString name_;
    nsString fullpath_;
};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace devicestorage {
class DeviceStorageFileValue;
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct EnumerationResponse|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class EnumerationResponse MOZ_FINAL
{
private:
    typedef mozilla::dom::devicestorage::DeviceStorageFileValue DeviceStorageFileValue;

public:
    EnumerationResponse();

    EnumerationResponse(const InfallibleTArray<DeviceStorageFileValue>& _paths)
    {
        Init();
        Assign(_paths);
    }

    EnumerationResponse(const EnumerationResponse& _o)
    {
        Init();
        Assign((_o).paths());
    }

    ~EnumerationResponse();

    void
    operator=(const EnumerationResponse& _o)
    {
        Assign((_o).paths());
    }

    bool
    operator==(const EnumerationResponse& _o) const;

    InfallibleTArray<DeviceStorageFileValue>&
    paths()
    {
        return paths_;
    }
    const InfallibleTArray<DeviceStorageFileValue>&
    paths() const
    {
        return paths_;
    }

private:
    void
    Init();

    void
    Assign(const InfallibleTArray<DeviceStorageFileValue>& _paths);

    InfallibleTArray<DeviceStorageFileValue> paths_;
};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct StatStorageResponse|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class StatStorageResponse MOZ_FINAL
{
private:

public:
    StatStorageResponse();

    StatStorageResponse(
            const int64_t& _freeBytes,
            const int64_t& _totalBytes,
            const nsString& _mountState)
    {
        Init();
        Assign(_freeBytes, _totalBytes, _mountState);
    }

    StatStorageResponse(const StatStorageResponse& _o)
    {
        Init();
        Assign((_o).freeBytes(), (_o).totalBytes(), (_o).mountState());
    }

    ~StatStorageResponse();

    void
    operator=(const StatStorageResponse& _o)
    {
        Assign((_o).freeBytes(), (_o).totalBytes(), (_o).mountState());
    }

    bool
    operator==(const StatStorageResponse& _o) const;

    int64_t&
    freeBytes()
    {
        return freeBytes_;
    }
    const int64_t&
    freeBytes() const
    {
        return freeBytes_;
    }

    int64_t&
    totalBytes()
    {
        return totalBytes_;
    }
    const int64_t&
    totalBytes() const
    {
        return totalBytes_;
    }

    nsString&
    mountState()
    {
        return mountState_;
    }
    const nsString&
    mountState() const
    {
        return mountState_;
    }

private:
    void
    Init();

    void
    Assign(
            const int64_t& _freeBytes,
            const int64_t& _totalBytes,
            const nsString& _mountState);

    int64_t freeBytes_;
    int64_t totalBytes_;
    nsString mountState_;
};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace devicestorage {
class ErrorResponse;
} // namespace devicestorage
} // namespace dom
} // namespace mozilla
namespace mozilla {
namespace dom {
namespace devicestorage {
class SuccessResponse;
} // namespace devicestorage
} // namespace dom
} // namespace mozilla
namespace mozilla {
namespace dom {
namespace devicestorage {
class BlobResponse;
} // namespace devicestorage
} // namespace dom
} // namespace mozilla
namespace mozilla {
namespace dom {
namespace devicestorage {
class EnumerationResponse;
} // namespace devicestorage
} // namespace dom
} // namespace mozilla
namespace mozilla {
namespace dom {
namespace devicestorage {
class StatStorageResponse;
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union DeviceStorageResponseValue|
//
namespace mozilla {
namespace dom {
namespace devicestorage {
class DeviceStorageResponseValue MOZ_FINAL
{
public:
    enum Type {
        T__None,
        TErrorResponse = 1,
        TSuccessResponse,
        TBlobResponse,
        TEnumerationResponse,
        TStatStorageResponse,
        T__Last = TStatStorageResponse
    };

private:
    typedef mozilla::dom::devicestorage::ErrorResponse ErrorResponse;
    typedef mozilla::dom::devicestorage::SuccessResponse SuccessResponse;
    typedef mozilla::dom::devicestorage::BlobResponse BlobResponse;
    typedef mozilla::dom::devicestorage::EnumerationResponse EnumerationResponse;
    typedef mozilla::dom::devicestorage::StatStorageResponse StatStorageResponse;
    typedef ErrorResponse ErrorResponse__tdef;
    typedef SuccessResponse SuccessResponse__tdef;
    typedef BlobResponse BlobResponse__tdef;
    typedef EnumerationResponse EnumerationResponse__tdef;
    typedef StatStorageResponse StatStorageResponse__tdef;

    union Value {
        char VErrorResponse[sizeof(ErrorResponse)];
        char VSuccessResponse[sizeof(SuccessResponse)];
        char VBlobResponse[sizeof(BlobResponse)];
        char VEnumerationResponse[sizeof(EnumerationResponse)];
        char VStatStorageResponse[sizeof(StatStorageResponse)];
    };

    ErrorResponse*
    ptr_ErrorResponse()
    {
        return reinterpret_cast<ErrorResponse*>((&((mValue).VErrorResponse)));
    }
    const ErrorResponse* const
    constptr_ErrorResponse() const
    {
        return reinterpret_cast<const ErrorResponse* const>((&((mValue).VErrorResponse)));
    }
    SuccessResponse*
    ptr_SuccessResponse()
    {
        return reinterpret_cast<SuccessResponse*>((&((mValue).VSuccessResponse)));
    }
    const SuccessResponse* const
    constptr_SuccessResponse() const
    {
        return reinterpret_cast<const SuccessResponse* const>((&((mValue).VSuccessResponse)));
    }
    BlobResponse*
    ptr_BlobResponse()
    {
        return reinterpret_cast<BlobResponse*>((&((mValue).VBlobResponse)));
    }
    const BlobResponse* const
    constptr_BlobResponse() const
    {
        return reinterpret_cast<const BlobResponse* const>((&((mValue).VBlobResponse)));
    }
    EnumerationResponse*
    ptr_EnumerationResponse()
    {
        return reinterpret_cast<EnumerationResponse*>((&((mValue).VEnumerationResponse)));
    }
    const EnumerationResponse* const
    constptr_EnumerationResponse() const
    {
        return reinterpret_cast<const EnumerationResponse* const>((&((mValue).VEnumerationResponse)));
    }
    StatStorageResponse*
    ptr_StatStorageResponse()
    {
        return reinterpret_cast<StatStorageResponse*>((&((mValue).VStatStorageResponse)));
    }
    const StatStorageResponse* const
    constptr_StatStorageResponse() const
    {
        return reinterpret_cast<const StatStorageResponse* const>((&((mValue).VStatStorageResponse)));
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
    DeviceStorageResponseValue() :
        mType(T__None)
    {
    }

    DeviceStorageResponseValue(const ErrorResponse& aOther);

    DeviceStorageResponseValue(const SuccessResponse& aOther);

    DeviceStorageResponseValue(const BlobResponse& aOther);

    DeviceStorageResponseValue(const EnumerationResponse& aOther);

    DeviceStorageResponseValue(const StatStorageResponse& aOther);

    DeviceStorageResponseValue(const DeviceStorageResponseValue& aOther);

    ~DeviceStorageResponseValue();

    Type
    type() const
    {
        return mType;
    }

    DeviceStorageResponseValue&
    operator=(const ErrorResponse& aRhs);

    DeviceStorageResponseValue&
    operator=(const SuccessResponse& aRhs);

    DeviceStorageResponseValue&
    operator=(const BlobResponse& aRhs);

    DeviceStorageResponseValue&
    operator=(const EnumerationResponse& aRhs);

    DeviceStorageResponseValue&
    operator=(const StatStorageResponse& aRhs);

    DeviceStorageResponseValue&
    operator=(const DeviceStorageResponseValue& aRhs);

    bool
    operator==(const ErrorResponse& aRhs) const;

    bool
    operator==(const SuccessResponse& aRhs) const;

    bool
    operator==(const BlobResponse& aRhs) const;

    bool
    operator==(const EnumerationResponse& aRhs) const;

    bool
    operator==(const StatStorageResponse& aRhs) const;

    bool
    operator==(const DeviceStorageResponseValue& aRhs) const;

    ErrorResponse&
    get_ErrorResponse()
    {
        AssertSanity(TErrorResponse);
        return (*(ptr_ErrorResponse()));
    }
    const ErrorResponse&
    get_ErrorResponse() const
    {
        AssertSanity(TErrorResponse);
        return (*(constptr_ErrorResponse()));
    }
    operator ErrorResponse&()
    {
        return get_ErrorResponse();
    }
    operator const ErrorResponse&() const
    {
        return get_ErrorResponse();
    }

    SuccessResponse&
    get_SuccessResponse()
    {
        AssertSanity(TSuccessResponse);
        return (*(ptr_SuccessResponse()));
    }
    const SuccessResponse&
    get_SuccessResponse() const
    {
        AssertSanity(TSuccessResponse);
        return (*(constptr_SuccessResponse()));
    }
    operator SuccessResponse&()
    {
        return get_SuccessResponse();
    }
    operator const SuccessResponse&() const
    {
        return get_SuccessResponse();
    }

    BlobResponse&
    get_BlobResponse()
    {
        AssertSanity(TBlobResponse);
        return (*(ptr_BlobResponse()));
    }
    const BlobResponse&
    get_BlobResponse() const
    {
        AssertSanity(TBlobResponse);
        return (*(constptr_BlobResponse()));
    }
    operator BlobResponse&()
    {
        return get_BlobResponse();
    }
    operator const BlobResponse&() const
    {
        return get_BlobResponse();
    }

    EnumerationResponse&
    get_EnumerationResponse()
    {
        AssertSanity(TEnumerationResponse);
        return (*(ptr_EnumerationResponse()));
    }
    const EnumerationResponse&
    get_EnumerationResponse() const
    {
        AssertSanity(TEnumerationResponse);
        return (*(constptr_EnumerationResponse()));
    }
    operator EnumerationResponse&()
    {
        return get_EnumerationResponse();
    }
    operator const EnumerationResponse&() const
    {
        return get_EnumerationResponse();
    }

    StatStorageResponse&
    get_StatStorageResponse()
    {
        AssertSanity(TStatStorageResponse);
        return (*(ptr_StatStorageResponse()));
    }
    const StatStorageResponse&
    get_StatStorageResponse() const
    {
        AssertSanity(TStatStorageResponse);
        return (*(constptr_StatStorageResponse()));
    }
    operator StatStorageResponse&()
    {
        return get_StatStorageResponse();
    }
    operator const StatStorageResponse&() const
    {
        return get_StatStorageResponse();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Code common to PDeviceStorageRequestChild and PDeviceStorageRequestParent
//
namespace mozilla {
namespace dom {
namespace devicestorage {
namespace PDeviceStorageRequest {

enum State {
    __Dead,
    __Null,
    __Error,
    __Dying,
    __Start = __Null
};

enum MessageType {
    PDeviceStorageRequestStart = PDeviceStorageRequestMsgStart << 16,
    PDeviceStorageRequestPreStart = (PDeviceStorageRequestMsgStart << 16) - 1,
    Msg___delete____ID,
    Reply___delete____ID,
    PDeviceStorageRequestEnd
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
    typedef mozilla::dom::devicestorage::BlobResponse BlobResponse;
    typedef mozilla::dom::devicestorage::DeviceStorageFileValue DeviceStorageFileValue;
    typedef mozilla::dom::devicestorage::DeviceStorageResponseValue DeviceStorageResponseValue;
    typedef mozilla::dom::devicestorage::EnumerationResponse EnumerationResponse;
    typedef mozilla::dom::devicestorage::ErrorResponse ErrorResponse;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::dom::devicestorage::StatStorageResponse StatStorageResponse;
    typedef mozilla::dom::devicestorage::SuccessResponse SuccessResponse;

public:
    enum {
        ID = Msg___delete____ID
    };
    Msg___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PDeviceStorageRequest::Msg___delete__")
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
    typedef mozilla::dom::devicestorage::BlobResponse BlobResponse;
    typedef mozilla::dom::devicestorage::DeviceStorageFileValue DeviceStorageFileValue;
    typedef mozilla::dom::devicestorage::DeviceStorageResponseValue DeviceStorageResponseValue;
    typedef mozilla::dom::devicestorage::EnumerationResponse EnumerationResponse;
    typedef mozilla::dom::devicestorage::ErrorResponse ErrorResponse;
    typedef mozilla::ipc::FileDescriptor FileDescriptor;
    typedef mozilla::ipc::Shmem Shmem;
    typedef mozilla::dom::devicestorage::StatStorageResponse StatStorageResponse;
    typedef mozilla::dom::devicestorage::SuccessResponse SuccessResponse;

public:
    enum {
        ID = Reply___delete____ID
    };
    Reply___delete__() :
        IPC::Message(MSG_ROUTING_NONE, ID, PRIORITY_NORMAL, COMPRESSION_NONE, "PDeviceStorageRequest::Reply___delete__")
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



} // namespace PDeviceStorageRequest
} // namespace devicestorage
} // namespace dom
} // namespace mozilla

#endif // ifndef PDeviceStorageRequest_h