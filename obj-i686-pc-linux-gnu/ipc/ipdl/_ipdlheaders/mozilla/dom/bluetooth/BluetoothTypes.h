//
// Automatically generated by ipdlc.
// Edit at your own risk
//

#ifndef BluetoothTypes_h
#define BluetoothTypes_h

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

namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothNamedValue;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union BluetoothValue|
//
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothValue MOZ_FINAL
{
public:
    enum Type {
        T__None,
        Tuint32_t = 1,
        TnsString,
        Tbool,
        TArrayOfnsString,
        TArrayOfuint8_t,
        TArrayOfBluetoothNamedValue,
        T__Last = TArrayOfBluetoothNamedValue
    };

private:
    typedef mozilla::dom::bluetooth::BluetoothNamedValue BluetoothNamedValue;
    typedef uint32_t uint32_t__tdef;
    typedef nsString nsString__tdef;
    typedef bool bool__tdef;
    typedef InfallibleTArray<nsString> ArrayOfnsString__tdef;
    typedef InfallibleTArray<uint8_t> ArrayOfuint8_t__tdef;
    typedef InfallibleTArray<BluetoothNamedValue>* ArrayOfBluetoothNamedValue__tdef;

    union Value {
        char Vuint32_t[sizeof(uint32_t)];
        char VnsString[sizeof(nsString)];
        char Vbool[sizeof(bool)];
        char VArrayOfnsString[sizeof(InfallibleTArray<nsString>)];
        char VArrayOfuint8_t[sizeof(InfallibleTArray<uint8_t>)];
        InfallibleTArray<BluetoothNamedValue>* VArrayOfBluetoothNamedValue;
    };

    uint32_t*
    ptr_uint32_t()
    {
        return reinterpret_cast<uint32_t*>((&((mValue).Vuint32_t)));
    }
    const uint32_t* const
    constptr_uint32_t() const
    {
        return reinterpret_cast<const uint32_t* const>((&((mValue).Vuint32_t)));
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
    InfallibleTArray<nsString>*
    ptr_ArrayOfnsString()
    {
        return reinterpret_cast<InfallibleTArray<nsString>*>((&((mValue).VArrayOfnsString)));
    }
    const InfallibleTArray<nsString>* const
    constptr_ArrayOfnsString() const
    {
        return reinterpret_cast<const InfallibleTArray<nsString>* const>((&((mValue).VArrayOfnsString)));
    }
    InfallibleTArray<uint8_t>*
    ptr_ArrayOfuint8_t()
    {
        return reinterpret_cast<InfallibleTArray<uint8_t>*>((&((mValue).VArrayOfuint8_t)));
    }
    const InfallibleTArray<uint8_t>* const
    constptr_ArrayOfuint8_t() const
    {
        return reinterpret_cast<const InfallibleTArray<uint8_t>* const>((&((mValue).VArrayOfuint8_t)));
    }
    InfallibleTArray<BluetoothNamedValue>*&
    ptr_ArrayOfBluetoothNamedValue()
    {
        return (mValue).VArrayOfBluetoothNamedValue;
    }
    const InfallibleTArray<BluetoothNamedValue>* const
    constptr_ArrayOfBluetoothNamedValue() const
    {
        return (mValue).VArrayOfBluetoothNamedValue;
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
    BluetoothValue() :
        mType(T__None)
    {
    }

    BluetoothValue(const uint32_t& aOther);

    BluetoothValue(const nsString& aOther);

    BluetoothValue(const bool& aOther);

    BluetoothValue(const InfallibleTArray<nsString>& aOther);

    BluetoothValue(const InfallibleTArray<uint8_t>& aOther);

    BluetoothValue(const InfallibleTArray<BluetoothNamedValue>& aOther);

    BluetoothValue(const BluetoothValue& aOther);

    ~BluetoothValue();

    Type
    type() const
    {
        return mType;
    }

    BluetoothValue&
    operator=(const uint32_t& aRhs);

    BluetoothValue&
    operator=(const nsString& aRhs);

    BluetoothValue&
    operator=(const bool& aRhs);

    BluetoothValue&
    operator=(const InfallibleTArray<nsString>& aRhs);

    BluetoothValue&
    operator=(const InfallibleTArray<uint8_t>& aRhs);

    BluetoothValue&
    operator=(const InfallibleTArray<BluetoothNamedValue>& aRhs);

    BluetoothValue&
    operator=(const BluetoothValue& aRhs);

    bool
    operator==(const uint32_t& aRhs) const;

    bool
    operator==(const nsString& aRhs) const;

    bool
    operator==(const bool& aRhs) const;

    bool
    operator==(const InfallibleTArray<nsString>& aRhs) const;

    bool
    operator==(const InfallibleTArray<uint8_t>& aRhs) const;

    bool
    operator==(const InfallibleTArray<BluetoothNamedValue>& aRhs) const;

    bool
    operator==(const BluetoothValue& aRhs) const;

    uint32_t&
    get_uint32_t()
    {
        AssertSanity(Tuint32_t);
        return (*(ptr_uint32_t()));
    }
    const uint32_t&
    get_uint32_t() const
    {
        AssertSanity(Tuint32_t);
        return (*(constptr_uint32_t()));
    }
    operator uint32_t&()
    {
        return get_uint32_t();
    }
    operator const uint32_t&() const
    {
        return get_uint32_t();
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

    InfallibleTArray<nsString>&
    get_ArrayOfnsString()
    {
        AssertSanity(TArrayOfnsString);
        return (*(ptr_ArrayOfnsString()));
    }
    const InfallibleTArray<nsString>&
    get_ArrayOfnsString() const
    {
        AssertSanity(TArrayOfnsString);
        return (*(constptr_ArrayOfnsString()));
    }
    operator InfallibleTArray<nsString>&()
    {
        return get_ArrayOfnsString();
    }
    operator const InfallibleTArray<nsString>&() const
    {
        return get_ArrayOfnsString();
    }

    InfallibleTArray<uint8_t>&
    get_ArrayOfuint8_t()
    {
        AssertSanity(TArrayOfuint8_t);
        return (*(ptr_ArrayOfuint8_t()));
    }
    const InfallibleTArray<uint8_t>&
    get_ArrayOfuint8_t() const
    {
        AssertSanity(TArrayOfuint8_t);
        return (*(constptr_ArrayOfuint8_t()));
    }
    operator InfallibleTArray<uint8_t>&()
    {
        return get_ArrayOfuint8_t();
    }
    operator const InfallibleTArray<uint8_t>&() const
    {
        return get_ArrayOfuint8_t();
    }

    InfallibleTArray<BluetoothNamedValue>&
    get_ArrayOfBluetoothNamedValue()
    {
        AssertSanity(TArrayOfBluetoothNamedValue);
        return (*(ptr_ArrayOfBluetoothNamedValue()));
    }
    const InfallibleTArray<BluetoothNamedValue>&
    get_ArrayOfBluetoothNamedValue() const
    {
        AssertSanity(TArrayOfBluetoothNamedValue);
        return (*(constptr_ArrayOfBluetoothNamedValue()));
    }
    operator InfallibleTArray<BluetoothNamedValue>&()
    {
        return get_ArrayOfBluetoothNamedValue();
    }
    operator const InfallibleTArray<BluetoothNamedValue>&() const
    {
        return get_ArrayOfBluetoothNamedValue();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothValue;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct BluetoothNamedValue|
//
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothNamedValue MOZ_FINAL
{
private:
    typedef mozilla::dom::bluetooth::BluetoothValue BluetoothValue;

public:
    BluetoothNamedValue();

    BluetoothNamedValue(
            const nsString& _name,
            const BluetoothValue& _value)
    {
        Init();
        Assign(_name, _value);
    }

    BluetoothNamedValue(const BluetoothNamedValue& _o)
    {
        Init();
        Assign((_o).name(), (_o).value());
    }

    ~BluetoothNamedValue();

    void
    operator=(const BluetoothNamedValue& _o)
    {
        Assign((_o).name(), (_o).value());
    }

    bool
    operator==(const BluetoothNamedValue& _o) const;

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

    BluetoothValue&
    value()
    {
        return (*(value_));
    }
    const BluetoothValue&
    value() const
    {
        return (*(value_));
    }

private:
    void
    Init();

    void
    Assign(
            const nsString& _name,
            const BluetoothValue& _value);

    nsString name_;
    BluetoothValue* value_;
};
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothValue;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct BluetoothSignal|
//
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothSignal MOZ_FINAL
{
private:
    typedef mozilla::dom::bluetooth::BluetoothValue BluetoothValue;

public:
    BluetoothSignal();

    BluetoothSignal(
            const nsString& _name,
            const nsString& _path,
            const BluetoothValue& _value)
    {
        Init();
        Assign(_name, _path, _value);
    }

    BluetoothSignal(const BluetoothSignal& _o)
    {
        Init();
        Assign((_o).name(), (_o).path(), (_o).value());
    }

    ~BluetoothSignal();

    void
    operator=(const BluetoothSignal& _o)
    {
        Assign((_o).name(), (_o).path(), (_o).value());
    }

    bool
    operator==(const BluetoothSignal& _o) const;

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
    path()
    {
        return path_;
    }
    const nsString&
    path() const
    {
        return path_;
    }

    BluetoothValue&
    value()
    {
        return value_;
    }
    const BluetoothValue&
    value() const
    {
        return value_;
    }

private:
    void
    Init();

    void
    Assign(
            const nsString& _name,
            const nsString& _path,
            const BluetoothValue& _value);

    nsString name_;
    nsString path_;
    BluetoothValue value_;
};
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothValue;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct BluetoothReplySuccess|
//
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothReplySuccess MOZ_FINAL
{
private:
    typedef mozilla::dom::bluetooth::BluetoothValue BluetoothValue;

public:
    BluetoothReplySuccess();

    BluetoothReplySuccess(const BluetoothValue& _value)
    {
        Init();
        Assign(_value);
    }

    BluetoothReplySuccess(const BluetoothReplySuccess& _o)
    {
        Init();
        Assign((_o).value());
    }

    ~BluetoothReplySuccess();

    void
    operator=(const BluetoothReplySuccess& _o)
    {
        Assign((_o).value());
    }

    bool
    operator==(const BluetoothReplySuccess& _o) const;

    BluetoothValue&
    value()
    {
        return value_;
    }
    const BluetoothValue&
    value() const
    {
        return value_;
    }

private:
    void
    Init();

    void
    Assign(const BluetoothValue& _value);

    BluetoothValue value_;
};
} // namespace bluetooth
} // namespace dom
} // namespace mozilla


//-----------------------------------------------------------------------------
// Declaration of the IPDL type |struct BluetoothReplyError|
//
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothReplyError MOZ_FINAL
{
private:

public:
    BluetoothReplyError();

    BluetoothReplyError(const nsString& _error)
    {
        Init();
        Assign(_error);
    }

    BluetoothReplyError(const BluetoothReplyError& _o)
    {
        Init();
        Assign((_o).error());
    }

    ~BluetoothReplyError();

    void
    operator=(const BluetoothReplyError& _o)
    {
        Assign((_o).error());
    }

    bool
    operator==(const BluetoothReplyError& _o) const;

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
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothReplySuccess;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothReplyError;
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Declaration of the IPDL type |union BluetoothReply|
//
namespace mozilla {
namespace dom {
namespace bluetooth {
class BluetoothReply MOZ_FINAL
{
public:
    enum Type {
        T__None,
        TBluetoothReplySuccess = 1,
        TBluetoothReplyError,
        T__Last = TBluetoothReplyError
    };

private:
    typedef mozilla::dom::bluetooth::BluetoothReplySuccess BluetoothReplySuccess;
    typedef mozilla::dom::bluetooth::BluetoothReplyError BluetoothReplyError;
    typedef BluetoothReplySuccess BluetoothReplySuccess__tdef;
    typedef BluetoothReplyError BluetoothReplyError__tdef;

    union Value {
        char VBluetoothReplySuccess[sizeof(BluetoothReplySuccess)];
        char VBluetoothReplyError[sizeof(BluetoothReplyError)];
    };

    BluetoothReplySuccess*
    ptr_BluetoothReplySuccess()
    {
        return reinterpret_cast<BluetoothReplySuccess*>((&((mValue).VBluetoothReplySuccess)));
    }
    const BluetoothReplySuccess* const
    constptr_BluetoothReplySuccess() const
    {
        return reinterpret_cast<const BluetoothReplySuccess* const>((&((mValue).VBluetoothReplySuccess)));
    }
    BluetoothReplyError*
    ptr_BluetoothReplyError()
    {
        return reinterpret_cast<BluetoothReplyError*>((&((mValue).VBluetoothReplyError)));
    }
    const BluetoothReplyError* const
    constptr_BluetoothReplyError() const
    {
        return reinterpret_cast<const BluetoothReplyError* const>((&((mValue).VBluetoothReplyError)));
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
    BluetoothReply() :
        mType(T__None)
    {
    }

    BluetoothReply(const BluetoothReplySuccess& aOther);

    BluetoothReply(const BluetoothReplyError& aOther);

    BluetoothReply(const BluetoothReply& aOther);

    ~BluetoothReply();

    Type
    type() const
    {
        return mType;
    }

    BluetoothReply&
    operator=(const BluetoothReplySuccess& aRhs);

    BluetoothReply&
    operator=(const BluetoothReplyError& aRhs);

    BluetoothReply&
    operator=(const BluetoothReply& aRhs);

    bool
    operator==(const BluetoothReplySuccess& aRhs) const;

    bool
    operator==(const BluetoothReplyError& aRhs) const;

    bool
    operator==(const BluetoothReply& aRhs) const;

    BluetoothReplySuccess&
    get_BluetoothReplySuccess()
    {
        AssertSanity(TBluetoothReplySuccess);
        return (*(ptr_BluetoothReplySuccess()));
    }
    const BluetoothReplySuccess&
    get_BluetoothReplySuccess() const
    {
        AssertSanity(TBluetoothReplySuccess);
        return (*(constptr_BluetoothReplySuccess()));
    }
    operator BluetoothReplySuccess&()
    {
        return get_BluetoothReplySuccess();
    }
    operator const BluetoothReplySuccess&() const
    {
        return get_BluetoothReplySuccess();
    }

    BluetoothReplyError&
    get_BluetoothReplyError()
    {
        AssertSanity(TBluetoothReplyError);
        return (*(ptr_BluetoothReplyError()));
    }
    const BluetoothReplyError&
    get_BluetoothReplyError() const
    {
        AssertSanity(TBluetoothReplyError);
        return (*(constptr_BluetoothReplyError()));
    }
    operator BluetoothReplyError&()
    {
        return get_BluetoothReplyError();
    }
    operator const BluetoothReplyError&() const
    {
        return get_BluetoothReplyError();
    }

private:
    Value mValue;
    Type mType;
};
} // namespace bluetooth
} // namespace dom
} // namespace mozilla

#endif // ifndef BluetoothTypes_h