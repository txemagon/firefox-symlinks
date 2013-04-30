//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef InputStreamParams_h
#define InputStreamParams_h

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
#include "ipc/IPCMessageUtils.h"


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct StringInputStreamParams|
//
namespace mozilla {
namespace ipc {
class StringInputStreamParams MOZ_FINAL
{
private:

public:
    StringInputStreamParams();

    StringInputStreamParams(const nsCString& _data)
    {
        Init();
        Assign(_data);
    }

    StringInputStreamParams(const StringInputStreamParams& _o)
    {
        Init();
        Assign((_o).data());
    }

    ~StringInputStreamParams();

    void
    operator=(const StringInputStreamParams& _o)
    {
        Assign((_o).data());
    }

    bool
    operator==(const StringInputStreamParams& _o) const;

    nsCString&
    data()
    {
        return data_;
    }
    const nsCString&
    data() const
    {
        return data_;
    }

private:
    void
    Init();

    void
    Assign(const nsCString& _data);

    nsCString data_;
};
} // namespace ipc
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct FileInputStreamParams|
//
namespace mozilla {
namespace ipc {
class FileInputStreamParams MOZ_FINAL
{
private:
    typedef mozilla::ipc::FileDescriptor FileDescriptor;

public:
    FileInputStreamParams();

    FileInputStreamParams(
            const FileDescriptor& _file,
            const int32_t& _behaviorFlags,
            const int32_t& _ioFlags)
    {
        Init();
        Assign(_file, _behaviorFlags, _ioFlags);
    }

    FileInputStreamParams(const FileInputStreamParams& _o)
    {
        Init();
        Assign((_o).file(), (_o).behaviorFlags(), (_o).ioFlags());
    }

    ~FileInputStreamParams();

    void
    operator=(const FileInputStreamParams& _o)
    {
        Assign((_o).file(), (_o).behaviorFlags(), (_o).ioFlags());
    }

    bool
    operator==(const FileInputStreamParams& _o) const;

    FileDescriptor&
    file()
    {
        return file_;
    }
    const FileDescriptor&
    file() const
    {
        return const_cast<FileDescriptor&>(file_);
    }

    int32_t&
    behaviorFlags()
    {
        return behaviorFlags_;
    }
    const int32_t&
    behaviorFlags() const
    {
        return behaviorFlags_;
    }

    int32_t&
    ioFlags()
    {
        return ioFlags_;
    }
    const int32_t&
    ioFlags() const
    {
        return ioFlags_;
    }

private:
    void
    Init();

    void
    Assign(
            const FileDescriptor& _file,
            const int32_t& _behaviorFlags,
            const int32_t& _ioFlags);

    FileDescriptor file_;
    int32_t behaviorFlags_;
    int32_t ioFlags_;
};
} // namespace ipc
} // namespace mozilla

namespace mozilla {
namespace ipc {
class FileInputStreamParams;
} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct PartialFileInputStreamParams|
//
namespace mozilla {
namespace ipc {
class PartialFileInputStreamParams MOZ_FINAL
{
private:
    typedef mozilla::ipc::FileInputStreamParams FileInputStreamParams;

public:
    PartialFileInputStreamParams();

    PartialFileInputStreamParams(
            const FileInputStreamParams& _fileStreamParams,
            const uint64_t& _begin,
            const uint64_t& _length)
    {
        Init();
        Assign(_fileStreamParams, _begin, _length);
    }

    PartialFileInputStreamParams(const PartialFileInputStreamParams& _o)
    {
        Init();
        Assign((_o).fileStreamParams(), (_o).begin(), (_o).length());
    }

    ~PartialFileInputStreamParams();

    void
    operator=(const PartialFileInputStreamParams& _o)
    {
        Assign((_o).fileStreamParams(), (_o).begin(), (_o).length());
    }

    bool
    operator==(const PartialFileInputStreamParams& _o) const;

    FileInputStreamParams&
    fileStreamParams()
    {
        return fileStreamParams_;
    }
    const FileInputStreamParams&
    fileStreamParams() const
    {
        return fileStreamParams_;
    }

    uint64_t&
    begin()
    {
        return begin_;
    }
    const uint64_t&
    begin() const
    {
        return begin_;
    }

    uint64_t&
    length()
    {
        return length_;
    }
    const uint64_t&
    length() const
    {
        return length_;
    }

private:
    void
    Init();

    void
    Assign(
            const FileInputStreamParams& _fileStreamParams,
            const uint64_t& _begin,
            const uint64_t& _length);

    FileInputStreamParams fileStreamParams_;
    uint64_t begin_;
    uint64_t length_;
};
} // namespace ipc
} // namespace mozilla

namespace mozilla {
namespace ipc {
class InputStreamParams;
} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct MultiplexInputStreamParams|
//
namespace mozilla {
namespace ipc {
class MultiplexInputStreamParams MOZ_FINAL
{
private:
    typedef mozilla::ipc::InputStreamParams InputStreamParams;

public:
    MultiplexInputStreamParams();

    MultiplexInputStreamParams(
            const InfallibleTArray<InputStreamParams>& _streams,
            const uint32_t& _currentStream,
            const nsresult& _status,
            const bool& _startedReadingCurrent)
    {
        Init();
        Assign(_streams, _currentStream, _status, _startedReadingCurrent);
    }

    MultiplexInputStreamParams(const MultiplexInputStreamParams& _o)
    {
        Init();
        Assign((_o).streams(), (_o).currentStream(), (_o).status(), (_o).startedReadingCurrent());
    }

    ~MultiplexInputStreamParams();

    void
    operator=(const MultiplexInputStreamParams& _o)
    {
        Assign((_o).streams(), (_o).currentStream(), (_o).status(), (_o).startedReadingCurrent());
    }

    bool
    operator==(const MultiplexInputStreamParams& _o) const;

    InfallibleTArray<InputStreamParams>&
    streams()
    {
        return (*(streams_));
    }
    const InfallibleTArray<InputStreamParams>&
    streams() const
    {
        return (*(streams_));
    }

    uint32_t&
    currentStream()
    {
        return currentStream_;
    }
    const uint32_t&
    currentStream() const
    {
        return currentStream_;
    }

    nsresult&
    status()
    {
        return status_;
    }
    const nsresult&
    status() const
    {
        return status_;
    }

    bool&
    startedReadingCurrent()
    {
        return startedReadingCurrent_;
    }
    const bool&
    startedReadingCurrent() const
    {
        return startedReadingCurrent_;
    }

private:
    void
    Init();

    void
    Assign(
            const InfallibleTArray<InputStreamParams>& _streams,
            const uint32_t& _currentStream,
            const nsresult& _status,
            const bool& _startedReadingCurrent);

    InfallibleTArray<InputStreamParams>* streams_;
    uint32_t currentStream_;
    nsresult status_;
    bool startedReadingCurrent_;
};
} // namespace ipc
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
// Declaration of the IPDL type |struct RemoteInputStreamParams|
//
namespace mozilla {
namespace ipc {
class RemoteInputStreamParams MOZ_FINAL
{
private:
    typedef mozilla::dom::PBlobParent PBlobParent;
    typedef mozilla::dom::PBlobChild PBlobChild;

public:
    RemoteInputStreamParams();

    RemoteInputStreamParams(
            PBlobParent* _remoteBlobParent,
            PBlobChild* _remoteBlobChild)
    {
        Init();
        Assign(_remoteBlobParent, _remoteBlobChild);
    }

    RemoteInputStreamParams(const RemoteInputStreamParams& _o)
    {
        Init();
        Assign(const_cast<PBlobParent*>((_o).remoteBlobParent()), const_cast<PBlobChild*>((_o).remoteBlobChild()));
    }

    ~RemoteInputStreamParams();

    void
    operator=(const RemoteInputStreamParams& _o)
    {
        Assign(const_cast<PBlobParent*>((_o).remoteBlobParent()), const_cast<PBlobChild*>((_o).remoteBlobChild()));
    }

    bool
    operator==(const RemoteInputStreamParams& _o) const;

    PBlobParent*&
    remoteBlobParent()
    {
        return remoteBlobParent_;
    }
    PBlobParent*
    remoteBlobParent() const
    {
        return remoteBlobParent_;
    }

    PBlobChild*&
    remoteBlobChild()
    {
        return remoteBlobChild_;
    }
    PBlobChild*
    remoteBlobChild() const
    {
        return remoteBlobChild_;
    }

private:
    void
    Init();

    void
    Assign(
            PBlobParent* _remoteBlobParent,
            PBlobChild* _remoteBlobChild);

    PBlobParent* remoteBlobParent_;
    PBlobChild* remoteBlobChild_;
};
} // namespace ipc
} // namespace mozilla

namespace mozilla {
namespace ipc {
class StringInputStreamParams;
} // namespace ipc
} // namespace mozilla
namespace mozilla {
namespace ipc {
class FileInputStreamParams;
} // namespace ipc
} // namespace mozilla
namespace mozilla {
namespace ipc {
class PartialFileInputStreamParams;
} // namespace ipc
} // namespace mozilla
namespace mozilla {
namespace ipc {
class BufferedInputStreamParams;
} // namespace ipc
} // namespace mozilla
namespace mozilla {
namespace ipc {
class MIMEInputStreamParams;
} // namespace ipc
} // namespace mozilla
namespace mozilla {
namespace ipc {
class MultiplexInputStreamParams;
} // namespace ipc
} // namespace mozilla
namespace mozilla {
namespace ipc {
class RemoteInputStreamParams;
} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union InputStreamParams|
//
namespace mozilla {
namespace ipc {
class InputStreamParams MOZ_FINAL
{
public:
    enum Type {
        T__None,
        TStringInputStreamParams = 1,
        TFileInputStreamParams,
        TPartialFileInputStreamParams,
        TBufferedInputStreamParams,
        TMIMEInputStreamParams,
        TMultiplexInputStreamParams,
        TRemoteInputStreamParams,
        T__Last = TRemoteInputStreamParams
    };

private:
    typedef mozilla::ipc::StringInputStreamParams StringInputStreamParams;
    typedef mozilla::ipc::FileInputStreamParams FileInputStreamParams;
    typedef mozilla::ipc::PartialFileInputStreamParams PartialFileInputStreamParams;
    typedef mozilla::ipc::BufferedInputStreamParams BufferedInputStreamParams;
    typedef mozilla::ipc::MIMEInputStreamParams MIMEInputStreamParams;
    typedef mozilla::ipc::MultiplexInputStreamParams MultiplexInputStreamParams;
    typedef mozilla::ipc::RemoteInputStreamParams RemoteInputStreamParams;
    typedef StringInputStreamParams StringInputStreamParams__tdef;
    typedef FileInputStreamParams FileInputStreamParams__tdef;
    typedef PartialFileInputStreamParams PartialFileInputStreamParams__tdef;
    typedef BufferedInputStreamParams* BufferedInputStreamParams__tdef;
    typedef MIMEInputStreamParams* MIMEInputStreamParams__tdef;
    typedef MultiplexInputStreamParams* MultiplexInputStreamParams__tdef;
    typedef RemoteInputStreamParams RemoteInputStreamParams__tdef;

    union Value {
        char VStringInputStreamParams[sizeof(StringInputStreamParams)];
        char VFileInputStreamParams[sizeof(FileInputStreamParams)];
        char VPartialFileInputStreamParams[sizeof(PartialFileInputStreamParams)];
        BufferedInputStreamParams* VBufferedInputStreamParams;
        MIMEInputStreamParams* VMIMEInputStreamParams;
        MultiplexInputStreamParams* VMultiplexInputStreamParams;
        char VRemoteInputStreamParams[sizeof(RemoteInputStreamParams)];
    };

    StringInputStreamParams*
    ptr_StringInputStreamParams()
    {
        return reinterpret_cast<StringInputStreamParams*>((&((mValue).VStringInputStreamParams)));
    }
    const StringInputStreamParams* const
    constptr_StringInputStreamParams() const
    {
        return reinterpret_cast<const StringInputStreamParams* const>((&((mValue).VStringInputStreamParams)));
    }
    FileInputStreamParams*
    ptr_FileInputStreamParams()
    {
        return reinterpret_cast<FileInputStreamParams*>((&((mValue).VFileInputStreamParams)));
    }
    const FileInputStreamParams* const
    constptr_FileInputStreamParams() const
    {
        return reinterpret_cast<const FileInputStreamParams* const>((&((mValue).VFileInputStreamParams)));
    }
    PartialFileInputStreamParams*
    ptr_PartialFileInputStreamParams()
    {
        return reinterpret_cast<PartialFileInputStreamParams*>((&((mValue).VPartialFileInputStreamParams)));
    }
    const PartialFileInputStreamParams* const
    constptr_PartialFileInputStreamParams() const
    {
        return reinterpret_cast<const PartialFileInputStreamParams* const>((&((mValue).VPartialFileInputStreamParams)));
    }
    BufferedInputStreamParams*&
    ptr_BufferedInputStreamParams()
    {
        return (mValue).VBufferedInputStreamParams;
    }
    const BufferedInputStreamParams* const
    constptr_BufferedInputStreamParams() const
    {
        return (mValue).VBufferedInputStreamParams;
    }
    MIMEInputStreamParams*&
    ptr_MIMEInputStreamParams()
    {
        return (mValue).VMIMEInputStreamParams;
    }
    const MIMEInputStreamParams* const
    constptr_MIMEInputStreamParams() const
    {
        return (mValue).VMIMEInputStreamParams;
    }
    MultiplexInputStreamParams*&
    ptr_MultiplexInputStreamParams()
    {
        return (mValue).VMultiplexInputStreamParams;
    }
    const MultiplexInputStreamParams* const
    constptr_MultiplexInputStreamParams() const
    {
        return (mValue).VMultiplexInputStreamParams;
    }
    RemoteInputStreamParams*
    ptr_RemoteInputStreamParams()
    {
        return reinterpret_cast<RemoteInputStreamParams*>((&((mValue).VRemoteInputStreamParams)));
    }
    const RemoteInputStreamParams* const
    constptr_RemoteInputStreamParams() const
    {
        return reinterpret_cast<const RemoteInputStreamParams* const>((&((mValue).VRemoteInputStreamParams)));
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
    InputStreamParams() :
        mType(T__None)
    {
    }

    InputStreamParams(const StringInputStreamParams& aOther);

    InputStreamParams(const FileInputStreamParams& aOther);

    InputStreamParams(const PartialFileInputStreamParams& aOther);

    InputStreamParams(const BufferedInputStreamParams& aOther);

    InputStreamParams(const MIMEInputStreamParams& aOther);

    InputStreamParams(const MultiplexInputStreamParams& aOther);

    InputStreamParams(const RemoteInputStreamParams& aOther);

    InputStreamParams(const InputStreamParams& aOther);

    ~InputStreamParams();

    Type
    type() const
    {
        return mType;
    }

    InputStreamParams&
    operator=(const StringInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const FileInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const PartialFileInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const BufferedInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const MIMEInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const MultiplexInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const RemoteInputStreamParams& aRhs);

    InputStreamParams&
    operator=(const InputStreamParams& aRhs);

    bool
    operator==(const StringInputStreamParams& aRhs) const;

    bool
    operator==(const FileInputStreamParams& aRhs) const;

    bool
    operator==(const PartialFileInputStreamParams& aRhs) const;

    bool
    operator==(const BufferedInputStreamParams& aRhs) const;

    bool
    operator==(const MIMEInputStreamParams& aRhs) const;

    bool
    operator==(const MultiplexInputStreamParams& aRhs) const;

    bool
    operator==(const RemoteInputStreamParams& aRhs) const;

    bool
    operator==(const InputStreamParams& aRhs) const;

    StringInputStreamParams&
    get_StringInputStreamParams()
    {
        AssertSanity(TStringInputStreamParams);
        return (*(ptr_StringInputStreamParams()));
    }
    const StringInputStreamParams&
    get_StringInputStreamParams() const
    {
        AssertSanity(TStringInputStreamParams);
        return (*(constptr_StringInputStreamParams()));
    }
    operator StringInputStreamParams&()
    {
        return get_StringInputStreamParams();
    }
    operator const StringInputStreamParams&() const
    {
        return get_StringInputStreamParams();
    }

    FileInputStreamParams&
    get_FileInputStreamParams()
    {
        AssertSanity(TFileInputStreamParams);
        return (*(ptr_FileInputStreamParams()));
    }
    const FileInputStreamParams&
    get_FileInputStreamParams() const
    {
        AssertSanity(TFileInputStreamParams);
        return (*(constptr_FileInputStreamParams()));
    }
    operator FileInputStreamParams&()
    {
        return get_FileInputStreamParams();
    }
    operator const FileInputStreamParams&() const
    {
        return get_FileInputStreamParams();
    }

    PartialFileInputStreamParams&
    get_PartialFileInputStreamParams()
    {
        AssertSanity(TPartialFileInputStreamParams);
        return (*(ptr_PartialFileInputStreamParams()));
    }
    const PartialFileInputStreamParams&
    get_PartialFileInputStreamParams() const
    {
        AssertSanity(TPartialFileInputStreamParams);
        return (*(constptr_PartialFileInputStreamParams()));
    }
    operator PartialFileInputStreamParams&()
    {
        return get_PartialFileInputStreamParams();
    }
    operator const PartialFileInputStreamParams&() const
    {
        return get_PartialFileInputStreamParams();
    }

    BufferedInputStreamParams&
    get_BufferedInputStreamParams()
    {
        AssertSanity(TBufferedInputStreamParams);
        return (*(ptr_BufferedInputStreamParams()));
    }
    const BufferedInputStreamParams&
    get_BufferedInputStreamParams() const
    {
        AssertSanity(TBufferedInputStreamParams);
        return (*(constptr_BufferedInputStreamParams()));
    }
    operator BufferedInputStreamParams&()
    {
        return get_BufferedInputStreamParams();
    }
    operator const BufferedInputStreamParams&() const
    {
        return get_BufferedInputStreamParams();
    }

    MIMEInputStreamParams&
    get_MIMEInputStreamParams()
    {
        AssertSanity(TMIMEInputStreamParams);
        return (*(ptr_MIMEInputStreamParams()));
    }
    const MIMEInputStreamParams&
    get_MIMEInputStreamParams() const
    {
        AssertSanity(TMIMEInputStreamParams);
        return (*(constptr_MIMEInputStreamParams()));
    }
    operator MIMEInputStreamParams&()
    {
        return get_MIMEInputStreamParams();
    }
    operator const MIMEInputStreamParams&() const
    {
        return get_MIMEInputStreamParams();
    }

    MultiplexInputStreamParams&
    get_MultiplexInputStreamParams()
    {
        AssertSanity(TMultiplexInputStreamParams);
        return (*(ptr_MultiplexInputStreamParams()));
    }
    const MultiplexInputStreamParams&
    get_MultiplexInputStreamParams() const
    {
        AssertSanity(TMultiplexInputStreamParams);
        return (*(constptr_MultiplexInputStreamParams()));
    }
    operator MultiplexInputStreamParams&()
    {
        return get_MultiplexInputStreamParams();
    }
    operator const MultiplexInputStreamParams&() const
    {
        return get_MultiplexInputStreamParams();
    }

    RemoteInputStreamParams&
    get_RemoteInputStreamParams()
    {
        AssertSanity(TRemoteInputStreamParams);
        return (*(ptr_RemoteInputStreamParams()));
    }
    const RemoteInputStreamParams&
    get_RemoteInputStreamParams() const
    {
        AssertSanity(TRemoteInputStreamParams);
        return (*(constptr_RemoteInputStreamParams()));
    }
    operator RemoteInputStreamParams&()
    {
        return get_RemoteInputStreamParams();
    }
    operator const RemoteInputStreamParams&() const
    {
        return get_RemoteInputStreamParams();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace ipc
} // namespace mozilla

namespace mozilla {
namespace ipc {
class InputStreamParams;
} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union OptionalInputStreamParams|
//
namespace mozilla {
namespace ipc {
class OptionalInputStreamParams MOZ_FINAL
{
public:
    enum Type {
        T__None,
        Tvoid_t = 1,
        TInputStreamParams,
        T__Last = TInputStreamParams
    };

private:
    typedef mozilla::void_t void_t;
    typedef mozilla::ipc::InputStreamParams InputStreamParams;
    typedef void_t void_t__tdef;
    typedef InputStreamParams* InputStreamParams__tdef;

    union Value {
        char Vvoid_t[sizeof(void_t)];
        InputStreamParams* VInputStreamParams;
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
    InputStreamParams*&
    ptr_InputStreamParams()
    {
        return (mValue).VInputStreamParams;
    }
    const InputStreamParams* const
    constptr_InputStreamParams() const
    {
        return (mValue).VInputStreamParams;
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
    OptionalInputStreamParams() :
        mType(T__None)
    {
    }

    OptionalInputStreamParams(const void_t& aOther);

    OptionalInputStreamParams(const InputStreamParams& aOther);

    OptionalInputStreamParams(const OptionalInputStreamParams& aOther);

    ~OptionalInputStreamParams();

    Type
    type() const
    {
        return mType;
    }

    OptionalInputStreamParams&
    operator=(const void_t& aRhs);

    OptionalInputStreamParams&
    operator=(const InputStreamParams& aRhs);

    OptionalInputStreamParams&
    operator=(const OptionalInputStreamParams& aRhs);

    bool
    operator==(const void_t& aRhs) const;

    bool
    operator==(const InputStreamParams& aRhs) const;

    bool
    operator==(const OptionalInputStreamParams& aRhs) const;

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

    InputStreamParams&
    get_InputStreamParams()
    {
        AssertSanity(TInputStreamParams);
        return (*(ptr_InputStreamParams()));
    }
    const InputStreamParams&
    get_InputStreamParams() const
    {
        AssertSanity(TInputStreamParams);
        return (*(constptr_InputStreamParams()));
    }
    operator InputStreamParams&()
    {
        return get_InputStreamParams();
    }
    operator const InputStreamParams&() const
    {
        return get_InputStreamParams();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace ipc
} // namespace mozilla

namespace mozilla {
namespace ipc {
class OptionalInputStreamParams;
} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct BufferedInputStreamParams|
//
namespace mozilla {
namespace ipc {
class BufferedInputStreamParams MOZ_FINAL
{
private:
    typedef mozilla::ipc::OptionalInputStreamParams OptionalInputStreamParams;

public:
    BufferedInputStreamParams();

    BufferedInputStreamParams(
            const OptionalInputStreamParams& _optionalStream,
            const uint32_t& _bufferSize)
    {
        Init();
        Assign(_optionalStream, _bufferSize);
    }

    BufferedInputStreamParams(const BufferedInputStreamParams& _o)
    {
        Init();
        Assign((_o).optionalStream(), (_o).bufferSize());
    }

    ~BufferedInputStreamParams();

    void
    operator=(const BufferedInputStreamParams& _o)
    {
        Assign((_o).optionalStream(), (_o).bufferSize());
    }

    bool
    operator==(const BufferedInputStreamParams& _o) const;

    OptionalInputStreamParams&
    optionalStream()
    {
        return (*(optionalStream_));
    }
    const OptionalInputStreamParams&
    optionalStream() const
    {
        return (*(optionalStream_));
    }

    uint32_t&
    bufferSize()
    {
        return bufferSize_;
    }
    const uint32_t&
    bufferSize() const
    {
        return bufferSize_;
    }

private:
    void
    Init();

    void
    Assign(
            const OptionalInputStreamParams& _optionalStream,
            const uint32_t& _bufferSize);

    OptionalInputStreamParams* optionalStream_;
    uint32_t bufferSize_;
};
} // namespace ipc
} // namespace mozilla

namespace mozilla {
namespace ipc {
class OptionalInputStreamParams;
} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct MIMEInputStreamParams|
//
namespace mozilla {
namespace ipc {
class MIMEInputStreamParams MOZ_FINAL
{
private:
    typedef mozilla::ipc::OptionalInputStreamParams OptionalInputStreamParams;

public:
    MIMEInputStreamParams();

    MIMEInputStreamParams(
            const OptionalInputStreamParams& _optionalStream,
            const nsCString& _headers,
            const nsCString& _contentLength,
            const bool& _startedReading,
            const bool& _addContentLength)
    {
        Init();
        Assign(_optionalStream, _headers, _contentLength, _startedReading, _addContentLength);
    }

    MIMEInputStreamParams(const MIMEInputStreamParams& _o)
    {
        Init();
        Assign((_o).optionalStream(), (_o).headers(), (_o).contentLength(), (_o).startedReading(), (_o).addContentLength());
    }

    ~MIMEInputStreamParams();

    void
    operator=(const MIMEInputStreamParams& _o)
    {
        Assign((_o).optionalStream(), (_o).headers(), (_o).contentLength(), (_o).startedReading(), (_o).addContentLength());
    }

    bool
    operator==(const MIMEInputStreamParams& _o) const;

    OptionalInputStreamParams&
    optionalStream()
    {
        return (*(optionalStream_));
    }
    const OptionalInputStreamParams&
    optionalStream() const
    {
        return (*(optionalStream_));
    }

    nsCString&
    headers()
    {
        return headers_;
    }
    const nsCString&
    headers() const
    {
        return headers_;
    }

    nsCString&
    contentLength()
    {
        return contentLength_;
    }
    const nsCString&
    contentLength() const
    {
        return contentLength_;
    }

    bool&
    startedReading()
    {
        return startedReading_;
    }
    const bool&
    startedReading() const
    {
        return startedReading_;
    }

    bool&
    addContentLength()
    {
        return addContentLength_;
    }
    const bool&
    addContentLength() const
    {
        return addContentLength_;
    }

private:
    void
    Init();

    void
    Assign(
            const OptionalInputStreamParams& _optionalStream,
            const nsCString& _headers,
            const nsCString& _contentLength,
            const bool& _startedReading,
            const bool& _addContentLength);

    OptionalInputStreamParams* optionalStream_;
    nsCString headers_;
    nsCString contentLength_;
    bool startedReading_;
    bool addContentLength_;
};
} // namespace ipc
} // namespace mozilla

#endif // ifndef InputStreamParams_h