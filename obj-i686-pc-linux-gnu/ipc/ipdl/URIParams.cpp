//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/ipc/URIParams.h"


//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SimpleURIParams|
//
namespace mozilla {
namespace ipc {
SimpleURIParams::SimpleURIParams()
{
    Init();
}

SimpleURIParams::~SimpleURIParams()
{
}

bool
SimpleURIParams::operator==(const SimpleURIParams& _o) const
{
    if ((!((scheme()) == ((_o).scheme())))) {
        return false;
    }
    if ((!((path()) == ((_o).path())))) {
        return false;
    }
    if ((!((ref()) == ((_o).ref())))) {
        return false;
    }
    if ((!((isMutable()) == ((_o).isMutable())))) {
        return false;
    }
    return true;
}

void
SimpleURIParams::Init()
{
}

void
SimpleURIParams::Assign(
        const nsCString& _scheme,
        const nsCString& _path,
        const nsCString& _ref,
        const bool& _isMutable)
{
    scheme_ = _scheme;
    path_ = _path;
    ref_ = _ref;
    isMutable_ = _isMutable;
}

} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct StandardURLSegment|
//
namespace mozilla {
namespace ipc {
StandardURLSegment::StandardURLSegment()
{
    Init();
}

StandardURLSegment::~StandardURLSegment()
{
}

bool
StandardURLSegment::operator==(const StandardURLSegment& _o) const
{
    if ((!((position()) == ((_o).position())))) {
        return false;
    }
    if ((!((length()) == ((_o).length())))) {
        return false;
    }
    return true;
}

void
StandardURLSegment::Init()
{
}

void
StandardURLSegment::Assign(
        const uint32_t& _position,
        const int32_t& _length)
{
    position_ = _position;
    length_ = _length;
}

} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct StandardURLParams|
//
namespace mozilla {
namespace ipc {
StandardURLParams::StandardURLParams()
{
    Init();
}

StandardURLParams::~StandardURLParams()
{
}

bool
StandardURLParams::operator==(const StandardURLParams& _o) const
{
    if ((!((urlType()) == ((_o).urlType())))) {
        return false;
    }
    if ((!((port()) == ((_o).port())))) {
        return false;
    }
    if ((!((defaultPort()) == ((_o).defaultPort())))) {
        return false;
    }
    if ((!((spec()) == ((_o).spec())))) {
        return false;
    }
    if ((!((scheme()) == ((_o).scheme())))) {
        return false;
    }
    if ((!((authority()) == ((_o).authority())))) {
        return false;
    }
    if ((!((username()) == ((_o).username())))) {
        return false;
    }
    if ((!((password()) == ((_o).password())))) {
        return false;
    }
    if ((!((host()) == ((_o).host())))) {
        return false;
    }
    if ((!((path()) == ((_o).path())))) {
        return false;
    }
    if ((!((filePath()) == ((_o).filePath())))) {
        return false;
    }
    if ((!((directory()) == ((_o).directory())))) {
        return false;
    }
    if ((!((baseName()) == ((_o).baseName())))) {
        return false;
    }
    if ((!((extension()) == ((_o).extension())))) {
        return false;
    }
    if ((!((query()) == ((_o).query())))) {
        return false;
    }
    if ((!((ref()) == ((_o).ref())))) {
        return false;
    }
    if ((!((originCharset()) == ((_o).originCharset())))) {
        return false;
    }
    if ((!((isMutable()) == ((_o).isMutable())))) {
        return false;
    }
    if ((!((supportsFileURL()) == ((_o).supportsFileURL())))) {
        return false;
    }
    if ((!((hostEncoding()) == ((_o).hostEncoding())))) {
        return false;
    }
    return true;
}

void
StandardURLParams::Init()
{
}

void
StandardURLParams::Assign(
        const uint32_t& _urlType,
        const int32_t& _port,
        const int32_t& _defaultPort,
        const nsCString& _spec,
        const StandardURLSegment& _scheme,
        const StandardURLSegment& _authority,
        const StandardURLSegment& _username,
        const StandardURLSegment& _password,
        const StandardURLSegment& _host,
        const StandardURLSegment& _path,
        const StandardURLSegment& _filePath,
        const StandardURLSegment& _directory,
        const StandardURLSegment& _baseName,
        const StandardURLSegment& _extension,
        const StandardURLSegment& _query,
        const StandardURLSegment& _ref,
        const nsCString& _originCharset,
        const bool& _isMutable,
        const bool& _supportsFileURL,
        const uint32_t& _hostEncoding)
{
    urlType_ = _urlType;
    port_ = _port;
    defaultPort_ = _defaultPort;
    spec_ = _spec;
    scheme_ = _scheme;
    authority_ = _authority;
    username_ = _username;
    password_ = _password;
    host_ = _host;
    path_ = _path;
    filePath_ = _filePath;
    directory_ = _directory;
    baseName_ = _baseName;
    extension_ = _extension;
    query_ = _query;
    ref_ = _ref;
    originCharset_ = _originCharset;
    isMutable_ = _isMutable;
    supportsFileURL_ = _supportsFileURL;
    hostEncoding_ = _hostEncoding;
}

} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct JARURIParams|
//
namespace mozilla {
namespace ipc {
JARURIParams::JARURIParams()
{
    Init();
}

JARURIParams::~JARURIParams()
{
    delete jarFile_;
    delete jarEntry_;
}

bool
JARURIParams::operator==(const JARURIParams& _o) const
{
    if ((!((jarFile()) == ((_o).jarFile())))) {
        return false;
    }
    if ((!((jarEntry()) == ((_o).jarEntry())))) {
        return false;
    }
    if ((!((charset()) == ((_o).charset())))) {
        return false;
    }
    return true;
}

void
JARURIParams::Init()
{
    jarFile_ = new URIParams();
    jarEntry_ = new URIParams();
}

void
JARURIParams::Assign(
        const URIParams& _jarFile,
        const URIParams& _jarEntry,
        const nsCString& _charset)
{
    (*(jarFile_)) = _jarFile;
    (*(jarEntry_)) = _jarEntry;
    charset_ = _charset;
}

} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GenericURIParams|
//
namespace mozilla {
namespace ipc {
GenericURIParams::GenericURIParams()
{
    Init();
}

GenericURIParams::~GenericURIParams()
{
}

bool
GenericURIParams::operator==(const GenericURIParams& _o) const
{
    if ((!((spec()) == ((_o).spec())))) {
        return false;
    }
    if ((!((charset()) == ((_o).charset())))) {
        return false;
    }
    return true;
}

void
GenericURIParams::Init()
{
}

void
GenericURIParams::Assign(
        const nsCString& _spec,
        const nsCString& _charset)
{
    spec_ = _spec;
    charset_ = _charset;
}

} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union URIParams|
//
namespace mozilla {
namespace ipc {
bool
URIParams::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TSimpleURIParams:
        {
            (ptr_SimpleURIParams())->~SimpleURIParams__tdef();
            break;
        }
    case TStandardURLParams:
        {
            (ptr_StandardURLParams())->~StandardURLParams__tdef();
            break;
        }
    case TJARURIParams:
        {
            delete ptr_JARURIParams();
            break;
        }
    case TGenericURIParams:
        {
            (ptr_GenericURIParams())->~GenericURIParams__tdef();
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("not reached");
            break;
        }
    }
    return true;
}

URIParams::URIParams(const SimpleURIParams& aOther)
{
    new (ptr_SimpleURIParams()) SimpleURIParams(aOther);
    mType = TSimpleURIParams;
}

URIParams::URIParams(const StandardURLParams& aOther)
{
    new (ptr_StandardURLParams()) StandardURLParams(aOther);
    mType = TStandardURLParams;
}

URIParams::URIParams(const JARURIParams& aOther)
{
    ptr_JARURIParams() = new JARURIParams(aOther);
    mType = TJARURIParams;
}

URIParams::URIParams(const GenericURIParams& aOther)
{
    new (ptr_GenericURIParams()) GenericURIParams(aOther);
    mType = TGenericURIParams;
}

URIParams::URIParams(const URIParams& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TSimpleURIParams:
        {
            new (ptr_SimpleURIParams()) SimpleURIParams((aOther).get_SimpleURIParams());
            break;
        }
    case TStandardURLParams:
        {
            new (ptr_StandardURLParams()) StandardURLParams((aOther).get_StandardURLParams());
            break;
        }
    case TJARURIParams:
        {
            ptr_JARURIParams() = new JARURIParams((aOther).get_JARURIParams());
            break;
        }
    case TGenericURIParams:
        {
            new (ptr_GenericURIParams()) GenericURIParams((aOther).get_GenericURIParams());
            break;
        }
    case T__None:
        {
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return;
        }
    }
    mType = (aOther).type();
}

URIParams::~URIParams()
{
    MaybeDestroy(T__None);
}

URIParams&
URIParams::operator=(const SimpleURIParams& aRhs)
{
    if (MaybeDestroy(TSimpleURIParams)) {
        new (ptr_SimpleURIParams()) SimpleURIParams;
    }
    (*(ptr_SimpleURIParams())) = aRhs;
    mType = TSimpleURIParams;
    return (*(this));
}

URIParams&
URIParams::operator=(const StandardURLParams& aRhs)
{
    if (MaybeDestroy(TStandardURLParams)) {
        new (ptr_StandardURLParams()) StandardURLParams;
    }
    (*(ptr_StandardURLParams())) = aRhs;
    mType = TStandardURLParams;
    return (*(this));
}

URIParams&
URIParams::operator=(const JARURIParams& aRhs)
{
    if (MaybeDestroy(TJARURIParams)) {
        ptr_JARURIParams() = new JARURIParams;
    }
    (*(ptr_JARURIParams())) = aRhs;
    mType = TJARURIParams;
    return (*(this));
}

URIParams&
URIParams::operator=(const GenericURIParams& aRhs)
{
    if (MaybeDestroy(TGenericURIParams)) {
        new (ptr_GenericURIParams()) GenericURIParams;
    }
    (*(ptr_GenericURIParams())) = aRhs;
    mType = TGenericURIParams;
    return (*(this));
}

URIParams&
URIParams::operator=(const URIParams& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TSimpleURIParams:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SimpleURIParams()) SimpleURIParams;
            }
            (*(ptr_SimpleURIParams())) = (aRhs).get_SimpleURIParams();
            break;
        }
    case TStandardURLParams:
        {
            if (MaybeDestroy(t)) {
                new (ptr_StandardURLParams()) StandardURLParams;
            }
            (*(ptr_StandardURLParams())) = (aRhs).get_StandardURLParams();
            break;
        }
    case TJARURIParams:
        {
            if (MaybeDestroy(t)) {
                ptr_JARURIParams() = new JARURIParams;
            }
            (*(ptr_JARURIParams())) = (aRhs).get_JARURIParams();
            break;
        }
    case TGenericURIParams:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GenericURIParams()) GenericURIParams;
            }
            (*(ptr_GenericURIParams())) = (aRhs).get_GenericURIParams();
            break;
        }
    case T__None:
        {
            MaybeDestroy(t);
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            break;
        }
    }
    mType = t;
    return (*(this));
}

bool
URIParams::operator==(const SimpleURIParams& aRhs) const
{
    return (get_SimpleURIParams()) == (aRhs);
}

bool
URIParams::operator==(const StandardURLParams& aRhs) const
{
    return (get_StandardURLParams()) == (aRhs);
}

bool
URIParams::operator==(const JARURIParams& aRhs) const
{
    return (get_JARURIParams()) == (aRhs);
}

bool
URIParams::operator==(const GenericURIParams& aRhs) const
{
    return (get_GenericURIParams()) == (aRhs);
}

bool
URIParams::operator==(const URIParams& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TSimpleURIParams:
        {
            return (get_SimpleURIParams()) == ((aRhs).get_SimpleURIParams());
        }
    case TStandardURLParams:
        {
            return (get_StandardURLParams()) == ((aRhs).get_StandardURLParams());
        }
    case TJARURIParams:
        {
            return (get_JARURIParams()) == ((aRhs).get_JARURIParams());
        }
    case TGenericURIParams:
        {
            return (get_GenericURIParams()) == ((aRhs).get_GenericURIParams());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace ipc
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union OptionalURIParams|
//
namespace mozilla {
namespace ipc {
bool
OptionalURIParams::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case Tvoid_t:
        {
            (ptr_void_t())->~void_t__tdef();
            break;
        }
    case TURIParams:
        {
            (ptr_URIParams())->~URIParams__tdef();
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("not reached");
            break;
        }
    }
    return true;
}

OptionalURIParams::OptionalURIParams(const void_t& aOther)
{
    new (ptr_void_t()) void_t(aOther);
    mType = Tvoid_t;
}

OptionalURIParams::OptionalURIParams(const URIParams& aOther)
{
    new (ptr_URIParams()) URIParams(aOther);
    mType = TURIParams;
}

OptionalURIParams::OptionalURIParams(const OptionalURIParams& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case Tvoid_t:
        {
            new (ptr_void_t()) void_t((aOther).get_void_t());
            break;
        }
    case TURIParams:
        {
            new (ptr_URIParams()) URIParams((aOther).get_URIParams());
            break;
        }
    case T__None:
        {
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return;
        }
    }
    mType = (aOther).type();
}

OptionalURIParams::~OptionalURIParams()
{
    MaybeDestroy(T__None);
}

OptionalURIParams&
OptionalURIParams::operator=(const void_t& aRhs)
{
    if (MaybeDestroy(Tvoid_t)) {
        new (ptr_void_t()) void_t;
    }
    (*(ptr_void_t())) = aRhs;
    mType = Tvoid_t;
    return (*(this));
}

OptionalURIParams&
OptionalURIParams::operator=(const URIParams& aRhs)
{
    if (MaybeDestroy(TURIParams)) {
        new (ptr_URIParams()) URIParams;
    }
    (*(ptr_URIParams())) = aRhs;
    mType = TURIParams;
    return (*(this));
}

OptionalURIParams&
OptionalURIParams::operator=(const OptionalURIParams& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case Tvoid_t:
        {
            if (MaybeDestroy(t)) {
                new (ptr_void_t()) void_t;
            }
            (*(ptr_void_t())) = (aRhs).get_void_t();
            break;
        }
    case TURIParams:
        {
            if (MaybeDestroy(t)) {
                new (ptr_URIParams()) URIParams;
            }
            (*(ptr_URIParams())) = (aRhs).get_URIParams();
            break;
        }
    case T__None:
        {
            MaybeDestroy(t);
            break;
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            break;
        }
    }
    mType = t;
    return (*(this));
}

bool
OptionalURIParams::operator==(const void_t& aRhs) const
{
    return (get_void_t()) == (aRhs);
}

bool
OptionalURIParams::operator==(const URIParams& aRhs) const
{
    return (get_URIParams()) == (aRhs);
}

bool
OptionalURIParams::operator==(const OptionalURIParams& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case Tvoid_t:
        {
            return (get_void_t()) == ((aRhs).get_void_t());
        }
    case TURIParams:
        {
            return (get_URIParams()) == ((aRhs).get_URIParams());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace ipc
} // namespace mozilla