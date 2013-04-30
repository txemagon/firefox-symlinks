//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/indexedDB/PIndexedDBRequest.h"

namespace mozilla {
namespace dom {
namespace indexedDB {
namespace PIndexedDBRequest {

bool
Transition(
        State from,
        mozilla::ipc::Trigger trigger,
        State* next)
{
    switch (from) {
    case __Null:
    case __Error:
        if ((Msg___delete____ID) == ((trigger).mMsg)) {
            (*(next)) = __Dead;
            return true;
        }
        return (__Null) == (from);
    case __Dead:
        NS_RUNTIMEABORT("__delete__()d actor");
        return false;
    case __Dying:
        NS_RUNTIMEABORT("__delete__()d (and unexpectedly dying) actor");
        return false;
    default:
        NS_RUNTIMEABORT("corrupted actor state");
        return false;
    }
    (*(next)) = __Error;
    return false;
}

} // namespace PIndexedDBRequest
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
GetResponse::GetResponse()
{
    Init();
}

GetResponse::~GetResponse()
{
}

bool
GetResponse::operator==(const GetResponse& _o) const
{
    if ((!((cloneInfo()) == ((_o).cloneInfo())))) {
        return false;
    }
    if ((!((blobsParent()) == ((_o).blobsParent())))) {
        return false;
    }
    if ((!((blobsChild()) == ((_o).blobsChild())))) {
        return false;
    }
    return true;
}

void
GetResponse::Init()
{
}

void
GetResponse::Assign(
        const SerializedStructuredCloneReadInfo& _cloneInfo,
        const InfallibleTArray<PBlobParent*>& _blobsParent,
        const InfallibleTArray<PBlobChild*>& _blobsChild)
{
    cloneInfo_ = _cloneInfo;
    blobsParent_ = _blobsParent;
    blobsChild_ = _blobsChild;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetKeyResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
GetKeyResponse::GetKeyResponse()
{
    Init();
}

GetKeyResponse::~GetKeyResponse()
{
}

bool
GetKeyResponse::operator==(const GetKeyResponse& _o) const
{
    if ((!((key()) == ((_o).key())))) {
        return false;
    }
    return true;
}

void
GetKeyResponse::Init()
{
}

void
GetKeyResponse::Assign(const Key& _key)
{
    key_ = _key;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct BlobArray|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
BlobArray::BlobArray()
{
    Init();
}

BlobArray::~BlobArray()
{
}

bool
BlobArray::operator==(const BlobArray& _o) const
{
    if ((!((blobsParent()) == ((_o).blobsParent())))) {
        return false;
    }
    if ((!((blobsChild()) == ((_o).blobsChild())))) {
        return false;
    }
    return true;
}

void
BlobArray::Init()
{
}

void
BlobArray::Assign(
        const InfallibleTArray<PBlobParent*>& _blobsParent,
        const InfallibleTArray<PBlobChild*>& _blobsChild)
{
    blobsParent_ = _blobsParent;
    blobsChild_ = _blobsChild;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetAllResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
GetAllResponse::GetAllResponse()
{
    Init();
}

GetAllResponse::~GetAllResponse()
{
}

bool
GetAllResponse::operator==(const GetAllResponse& _o) const
{
    if ((!((cloneInfos()) == ((_o).cloneInfos())))) {
        return false;
    }
    if ((!((blobs()) == ((_o).blobs())))) {
        return false;
    }
    return true;
}

void
GetAllResponse::Init()
{
}

void
GetAllResponse::Assign(
        const InfallibleTArray<SerializedStructuredCloneReadInfo>& _cloneInfos,
        const InfallibleTArray<BlobArray>& _blobs)
{
    cloneInfos_ = _cloneInfos;
    blobs_ = _blobs;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetAllKeysResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
GetAllKeysResponse::GetAllKeysResponse()
{
    Init();
}

GetAllKeysResponse::~GetAllKeysResponse()
{
}

bool
GetAllKeysResponse::operator==(const GetAllKeysResponse& _o) const
{
    if ((!((keys()) == ((_o).keys())))) {
        return false;
    }
    return true;
}

void
GetAllKeysResponse::Init()
{
}

void
GetAllKeysResponse::Assign(const InfallibleTArray<Key>& _keys)
{
    keys_ = _keys;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct AddResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
AddResponse::AddResponse()
{
    Init();
}

AddResponse::~AddResponse()
{
}

bool
AddResponse::operator==(const AddResponse& _o) const
{
    if ((!((key()) == ((_o).key())))) {
        return false;
    }
    return true;
}

void
AddResponse::Init()
{
}

void
AddResponse::Assign(const Key& _key)
{
    key_ = _key;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct PutResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
PutResponse::PutResponse()
{
    Init();
}

PutResponse::~PutResponse()
{
}

bool
PutResponse::operator==(const PutResponse& _o) const
{
    if ((!((key()) == ((_o).key())))) {
        return false;
    }
    return true;
}

void
PutResponse::Init()
{
}

void
PutResponse::Assign(const Key& _key)
{
    key_ = _key;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct DeleteResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
DeleteResponse::DeleteResponse()
{
    Init();
}

DeleteResponse::~DeleteResponse()
{
}

bool
DeleteResponse::operator==(const DeleteResponse& _o) const
{
    if ((!((FIXME_Bug_753159()) == ((_o).FIXME_Bug_753159())))) {
        return false;
    }
    return true;
}

void
DeleteResponse::Init()
{
}

void
DeleteResponse::Assign(const void_t& _FIXME_Bug_753159)
{
    FIXME_Bug_753159_ = _FIXME_Bug_753159;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct ClearResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
ClearResponse::ClearResponse()
{
    Init();
}

ClearResponse::~ClearResponse()
{
}

bool
ClearResponse::operator==(const ClearResponse& _o) const
{
    if ((!((FIXME_Bug_753159()) == ((_o).FIXME_Bug_753159())))) {
        return false;
    }
    return true;
}

void
ClearResponse::Init()
{
}

void
ClearResponse::Assign(const void_t& _FIXME_Bug_753159)
{
    FIXME_Bug_753159_ = _FIXME_Bug_753159;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct CountResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
CountResponse::CountResponse()
{
    Init();
}

CountResponse::~CountResponse()
{
}

bool
CountResponse::operator==(const CountResponse& _o) const
{
    if ((!((count()) == ((_o).count())))) {
        return false;
    }
    return true;
}

void
CountResponse::Init()
{
}

void
CountResponse::Assign(const uint64_t& _count)
{
    count_ = _count;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union OpenCursorResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
bool
OpenCursorResponse::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TPIndexedDBCursorParent:
        {
            (ptr_PIndexedDBCursorParent())->~PIndexedDBCursorParent__tdef();
            break;
        }
    case TPIndexedDBCursorChild:
        {
            (ptr_PIndexedDBCursorChild())->~PIndexedDBCursorChild__tdef();
            break;
        }
    case Tvoid_t:
        {
            (ptr_void_t())->~void_t__tdef();
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

OpenCursorResponse::OpenCursorResponse(PIndexedDBCursorParent* aOther)
{
    new (ptr_PIndexedDBCursorParent()) PIndexedDBCursorParent*(const_cast<PIndexedDBCursorParent*>(aOther));
    mType = TPIndexedDBCursorParent;
}

OpenCursorResponse::OpenCursorResponse(PIndexedDBCursorChild* aOther)
{
    new (ptr_PIndexedDBCursorChild()) PIndexedDBCursorChild*(const_cast<PIndexedDBCursorChild*>(aOther));
    mType = TPIndexedDBCursorChild;
}

OpenCursorResponse::OpenCursorResponse(const void_t& aOther)
{
    new (ptr_void_t()) void_t(aOther);
    mType = Tvoid_t;
}

OpenCursorResponse::OpenCursorResponse(const OpenCursorResponse& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TPIndexedDBCursorParent:
        {
            new (ptr_PIndexedDBCursorParent()) PIndexedDBCursorParent*(const_cast<PIndexedDBCursorParent*>((aOther).get_PIndexedDBCursorParent()));
            break;
        }
    case TPIndexedDBCursorChild:
        {
            new (ptr_PIndexedDBCursorChild()) PIndexedDBCursorChild*(const_cast<PIndexedDBCursorChild*>((aOther).get_PIndexedDBCursorChild()));
            break;
        }
    case Tvoid_t:
        {
            new (ptr_void_t()) void_t((aOther).get_void_t());
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

OpenCursorResponse::~OpenCursorResponse()
{
    MaybeDestroy(T__None);
}

OpenCursorResponse&
OpenCursorResponse::operator=(PIndexedDBCursorParent* aRhs)
{
    if (MaybeDestroy(TPIndexedDBCursorParent)) {
        new (ptr_PIndexedDBCursorParent()) PIndexedDBCursorParent*;
    }
    (*(ptr_PIndexedDBCursorParent())) = const_cast<PIndexedDBCursorParent*>(aRhs);
    mType = TPIndexedDBCursorParent;
    return (*(this));
}

OpenCursorResponse&
OpenCursorResponse::operator=(PIndexedDBCursorChild* aRhs)
{
    if (MaybeDestroy(TPIndexedDBCursorChild)) {
        new (ptr_PIndexedDBCursorChild()) PIndexedDBCursorChild*;
    }
    (*(ptr_PIndexedDBCursorChild())) = const_cast<PIndexedDBCursorChild*>(aRhs);
    mType = TPIndexedDBCursorChild;
    return (*(this));
}

OpenCursorResponse&
OpenCursorResponse::operator=(const void_t& aRhs)
{
    if (MaybeDestroy(Tvoid_t)) {
        new (ptr_void_t()) void_t;
    }
    (*(ptr_void_t())) = aRhs;
    mType = Tvoid_t;
    return (*(this));
}

OpenCursorResponse&
OpenCursorResponse::operator=(const OpenCursorResponse& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TPIndexedDBCursorParent:
        {
            if (MaybeDestroy(t)) {
                new (ptr_PIndexedDBCursorParent()) PIndexedDBCursorParent*;
            }
            (*(ptr_PIndexedDBCursorParent())) = const_cast<PIndexedDBCursorParent*>((aRhs).get_PIndexedDBCursorParent());
            break;
        }
    case TPIndexedDBCursorChild:
        {
            if (MaybeDestroy(t)) {
                new (ptr_PIndexedDBCursorChild()) PIndexedDBCursorChild*;
            }
            (*(ptr_PIndexedDBCursorChild())) = const_cast<PIndexedDBCursorChild*>((aRhs).get_PIndexedDBCursorChild());
            break;
        }
    case Tvoid_t:
        {
            if (MaybeDestroy(t)) {
                new (ptr_void_t()) void_t;
            }
            (*(ptr_void_t())) = (aRhs).get_void_t();
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
OpenCursorResponse::operator==(PIndexedDBCursorParent* aRhs) const
{
    return (get_PIndexedDBCursorParent()) == (aRhs);
}

bool
OpenCursorResponse::operator==(PIndexedDBCursorChild* aRhs) const
{
    return (get_PIndexedDBCursorChild()) == (aRhs);
}

bool
OpenCursorResponse::operator==(const void_t& aRhs) const
{
    return (get_void_t()) == (aRhs);
}

bool
OpenCursorResponse::operator==(const OpenCursorResponse& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TPIndexedDBCursorParent:
        {
            return (get_PIndexedDBCursorParent()) == ((aRhs).get_PIndexedDBCursorParent());
        }
    case TPIndexedDBCursorChild:
        {
            return (get_PIndexedDBCursorChild()) == ((aRhs).get_PIndexedDBCursorChild());
        }
    case Tvoid_t:
        {
            return (get_void_t()) == ((aRhs).get_void_t());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct ContinueResponse|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
ContinueResponse::ContinueResponse()
{
    Init();
}

ContinueResponse::~ContinueResponse()
{
}

bool
ContinueResponse::operator==(const ContinueResponse& _o) const
{
    if ((!((key()) == ((_o).key())))) {
        return false;
    }
    if ((!((objectKey()) == ((_o).objectKey())))) {
        return false;
    }
    if ((!((cloneInfo()) == ((_o).cloneInfo())))) {
        return false;
    }
    if ((!((blobsParent()) == ((_o).blobsParent())))) {
        return false;
    }
    if ((!((blobsChild()) == ((_o).blobsChild())))) {
        return false;
    }
    return true;
}

void
ContinueResponse::Init()
{
}

void
ContinueResponse::Assign(
        const Key& _key,
        const Key& _objectKey,
        const SerializedStructuredCloneReadInfo& _cloneInfo,
        const InfallibleTArray<PBlobParent*>& _blobsParent,
        const InfallibleTArray<PBlobChild*>& _blobsChild)
{
    key_ = _key;
    objectKey_ = _objectKey;
    cloneInfo_ = _cloneInfo;
    blobsParent_ = _blobsParent;
    blobsChild_ = _blobsChild;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union ResponseValue|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
bool
ResponseValue::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case Tnsresult:
        {
            (ptr_nsresult())->~nsresult__tdef();
            break;
        }
    case TGetResponse:
        {
            (ptr_GetResponse())->~GetResponse__tdef();
            break;
        }
    case TGetKeyResponse:
        {
            (ptr_GetKeyResponse())->~GetKeyResponse__tdef();
            break;
        }
    case TGetAllResponse:
        {
            (ptr_GetAllResponse())->~GetAllResponse__tdef();
            break;
        }
    case TGetAllKeysResponse:
        {
            (ptr_GetAllKeysResponse())->~GetAllKeysResponse__tdef();
            break;
        }
    case TAddResponse:
        {
            (ptr_AddResponse())->~AddResponse__tdef();
            break;
        }
    case TPutResponse:
        {
            (ptr_PutResponse())->~PutResponse__tdef();
            break;
        }
    case TDeleteResponse:
        {
            (ptr_DeleteResponse())->~DeleteResponse__tdef();
            break;
        }
    case TClearResponse:
        {
            (ptr_ClearResponse())->~ClearResponse__tdef();
            break;
        }
    case TCountResponse:
        {
            (ptr_CountResponse())->~CountResponse__tdef();
            break;
        }
    case TOpenCursorResponse:
        {
            (ptr_OpenCursorResponse())->~OpenCursorResponse__tdef();
            break;
        }
    case TContinueResponse:
        {
            (ptr_ContinueResponse())->~ContinueResponse__tdef();
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

ResponseValue::ResponseValue(const nsresult& aOther)
{
    new (ptr_nsresult()) nsresult(aOther);
    mType = Tnsresult;
}

ResponseValue::ResponseValue(const GetResponse& aOther)
{
    new (ptr_GetResponse()) GetResponse(aOther);
    mType = TGetResponse;
}

ResponseValue::ResponseValue(const GetKeyResponse& aOther)
{
    new (ptr_GetKeyResponse()) GetKeyResponse(aOther);
    mType = TGetKeyResponse;
}

ResponseValue::ResponseValue(const GetAllResponse& aOther)
{
    new (ptr_GetAllResponse()) GetAllResponse(aOther);
    mType = TGetAllResponse;
}

ResponseValue::ResponseValue(const GetAllKeysResponse& aOther)
{
    new (ptr_GetAllKeysResponse()) GetAllKeysResponse(aOther);
    mType = TGetAllKeysResponse;
}

ResponseValue::ResponseValue(const AddResponse& aOther)
{
    new (ptr_AddResponse()) AddResponse(aOther);
    mType = TAddResponse;
}

ResponseValue::ResponseValue(const PutResponse& aOther)
{
    new (ptr_PutResponse()) PutResponse(aOther);
    mType = TPutResponse;
}

ResponseValue::ResponseValue(const DeleteResponse& aOther)
{
    new (ptr_DeleteResponse()) DeleteResponse(aOther);
    mType = TDeleteResponse;
}

ResponseValue::ResponseValue(const ClearResponse& aOther)
{
    new (ptr_ClearResponse()) ClearResponse(aOther);
    mType = TClearResponse;
}

ResponseValue::ResponseValue(const CountResponse& aOther)
{
    new (ptr_CountResponse()) CountResponse(aOther);
    mType = TCountResponse;
}

ResponseValue::ResponseValue(const OpenCursorResponse& aOther)
{
    new (ptr_OpenCursorResponse()) OpenCursorResponse(aOther);
    mType = TOpenCursorResponse;
}

ResponseValue::ResponseValue(const ContinueResponse& aOther)
{
    new (ptr_ContinueResponse()) ContinueResponse(aOther);
    mType = TContinueResponse;
}

ResponseValue::ResponseValue(const ResponseValue& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case Tnsresult:
        {
            new (ptr_nsresult()) nsresult((aOther).get_nsresult());
            break;
        }
    case TGetResponse:
        {
            new (ptr_GetResponse()) GetResponse((aOther).get_GetResponse());
            break;
        }
    case TGetKeyResponse:
        {
            new (ptr_GetKeyResponse()) GetKeyResponse((aOther).get_GetKeyResponse());
            break;
        }
    case TGetAllResponse:
        {
            new (ptr_GetAllResponse()) GetAllResponse((aOther).get_GetAllResponse());
            break;
        }
    case TGetAllKeysResponse:
        {
            new (ptr_GetAllKeysResponse()) GetAllKeysResponse((aOther).get_GetAllKeysResponse());
            break;
        }
    case TAddResponse:
        {
            new (ptr_AddResponse()) AddResponse((aOther).get_AddResponse());
            break;
        }
    case TPutResponse:
        {
            new (ptr_PutResponse()) PutResponse((aOther).get_PutResponse());
            break;
        }
    case TDeleteResponse:
        {
            new (ptr_DeleteResponse()) DeleteResponse((aOther).get_DeleteResponse());
            break;
        }
    case TClearResponse:
        {
            new (ptr_ClearResponse()) ClearResponse((aOther).get_ClearResponse());
            break;
        }
    case TCountResponse:
        {
            new (ptr_CountResponse()) CountResponse((aOther).get_CountResponse());
            break;
        }
    case TOpenCursorResponse:
        {
            new (ptr_OpenCursorResponse()) OpenCursorResponse((aOther).get_OpenCursorResponse());
            break;
        }
    case TContinueResponse:
        {
            new (ptr_ContinueResponse()) ContinueResponse((aOther).get_ContinueResponse());
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

ResponseValue::~ResponseValue()
{
    MaybeDestroy(T__None);
}

ResponseValue&
ResponseValue::operator=(const nsresult& aRhs)
{
    if (MaybeDestroy(Tnsresult)) {
        new (ptr_nsresult()) nsresult;
    }
    (*(ptr_nsresult())) = aRhs;
    mType = Tnsresult;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const GetResponse& aRhs)
{
    if (MaybeDestroy(TGetResponse)) {
        new (ptr_GetResponse()) GetResponse;
    }
    (*(ptr_GetResponse())) = aRhs;
    mType = TGetResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const GetKeyResponse& aRhs)
{
    if (MaybeDestroy(TGetKeyResponse)) {
        new (ptr_GetKeyResponse()) GetKeyResponse;
    }
    (*(ptr_GetKeyResponse())) = aRhs;
    mType = TGetKeyResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const GetAllResponse& aRhs)
{
    if (MaybeDestroy(TGetAllResponse)) {
        new (ptr_GetAllResponse()) GetAllResponse;
    }
    (*(ptr_GetAllResponse())) = aRhs;
    mType = TGetAllResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const GetAllKeysResponse& aRhs)
{
    if (MaybeDestroy(TGetAllKeysResponse)) {
        new (ptr_GetAllKeysResponse()) GetAllKeysResponse;
    }
    (*(ptr_GetAllKeysResponse())) = aRhs;
    mType = TGetAllKeysResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const AddResponse& aRhs)
{
    if (MaybeDestroy(TAddResponse)) {
        new (ptr_AddResponse()) AddResponse;
    }
    (*(ptr_AddResponse())) = aRhs;
    mType = TAddResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const PutResponse& aRhs)
{
    if (MaybeDestroy(TPutResponse)) {
        new (ptr_PutResponse()) PutResponse;
    }
    (*(ptr_PutResponse())) = aRhs;
    mType = TPutResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const DeleteResponse& aRhs)
{
    if (MaybeDestroy(TDeleteResponse)) {
        new (ptr_DeleteResponse()) DeleteResponse;
    }
    (*(ptr_DeleteResponse())) = aRhs;
    mType = TDeleteResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const ClearResponse& aRhs)
{
    if (MaybeDestroy(TClearResponse)) {
        new (ptr_ClearResponse()) ClearResponse;
    }
    (*(ptr_ClearResponse())) = aRhs;
    mType = TClearResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const CountResponse& aRhs)
{
    if (MaybeDestroy(TCountResponse)) {
        new (ptr_CountResponse()) CountResponse;
    }
    (*(ptr_CountResponse())) = aRhs;
    mType = TCountResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const OpenCursorResponse& aRhs)
{
    if (MaybeDestroy(TOpenCursorResponse)) {
        new (ptr_OpenCursorResponse()) OpenCursorResponse;
    }
    (*(ptr_OpenCursorResponse())) = aRhs;
    mType = TOpenCursorResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const ContinueResponse& aRhs)
{
    if (MaybeDestroy(TContinueResponse)) {
        new (ptr_ContinueResponse()) ContinueResponse;
    }
    (*(ptr_ContinueResponse())) = aRhs;
    mType = TContinueResponse;
    return (*(this));
}

ResponseValue&
ResponseValue::operator=(const ResponseValue& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case Tnsresult:
        {
            if (MaybeDestroy(t)) {
                new (ptr_nsresult()) nsresult;
            }
            (*(ptr_nsresult())) = (aRhs).get_nsresult();
            break;
        }
    case TGetResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetResponse()) GetResponse;
            }
            (*(ptr_GetResponse())) = (aRhs).get_GetResponse();
            break;
        }
    case TGetKeyResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetKeyResponse()) GetKeyResponse;
            }
            (*(ptr_GetKeyResponse())) = (aRhs).get_GetKeyResponse();
            break;
        }
    case TGetAllResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetAllResponse()) GetAllResponse;
            }
            (*(ptr_GetAllResponse())) = (aRhs).get_GetAllResponse();
            break;
        }
    case TGetAllKeysResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetAllKeysResponse()) GetAllKeysResponse;
            }
            (*(ptr_GetAllKeysResponse())) = (aRhs).get_GetAllKeysResponse();
            break;
        }
    case TAddResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_AddResponse()) AddResponse;
            }
            (*(ptr_AddResponse())) = (aRhs).get_AddResponse();
            break;
        }
    case TPutResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_PutResponse()) PutResponse;
            }
            (*(ptr_PutResponse())) = (aRhs).get_PutResponse();
            break;
        }
    case TDeleteResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_DeleteResponse()) DeleteResponse;
            }
            (*(ptr_DeleteResponse())) = (aRhs).get_DeleteResponse();
            break;
        }
    case TClearResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_ClearResponse()) ClearResponse;
            }
            (*(ptr_ClearResponse())) = (aRhs).get_ClearResponse();
            break;
        }
    case TCountResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_CountResponse()) CountResponse;
            }
            (*(ptr_CountResponse())) = (aRhs).get_CountResponse();
            break;
        }
    case TOpenCursorResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_OpenCursorResponse()) OpenCursorResponse;
            }
            (*(ptr_OpenCursorResponse())) = (aRhs).get_OpenCursorResponse();
            break;
        }
    case TContinueResponse:
        {
            if (MaybeDestroy(t)) {
                new (ptr_ContinueResponse()) ContinueResponse;
            }
            (*(ptr_ContinueResponse())) = (aRhs).get_ContinueResponse();
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
ResponseValue::operator==(const nsresult& aRhs) const
{
    return (get_nsresult()) == (aRhs);
}

bool
ResponseValue::operator==(const GetResponse& aRhs) const
{
    return (get_GetResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const GetKeyResponse& aRhs) const
{
    return (get_GetKeyResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const GetAllResponse& aRhs) const
{
    return (get_GetAllResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const GetAllKeysResponse& aRhs) const
{
    return (get_GetAllKeysResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const AddResponse& aRhs) const
{
    return (get_AddResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const PutResponse& aRhs) const
{
    return (get_PutResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const DeleteResponse& aRhs) const
{
    return (get_DeleteResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const ClearResponse& aRhs) const
{
    return (get_ClearResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const CountResponse& aRhs) const
{
    return (get_CountResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const OpenCursorResponse& aRhs) const
{
    return (get_OpenCursorResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const ContinueResponse& aRhs) const
{
    return (get_ContinueResponse()) == (aRhs);
}

bool
ResponseValue::operator==(const ResponseValue& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case Tnsresult:
        {
            return (get_nsresult()) == ((aRhs).get_nsresult());
        }
    case TGetResponse:
        {
            return (get_GetResponse()) == ((aRhs).get_GetResponse());
        }
    case TGetKeyResponse:
        {
            return (get_GetKeyResponse()) == ((aRhs).get_GetKeyResponse());
        }
    case TGetAllResponse:
        {
            return (get_GetAllResponse()) == ((aRhs).get_GetAllResponse());
        }
    case TGetAllKeysResponse:
        {
            return (get_GetAllKeysResponse()) == ((aRhs).get_GetAllKeysResponse());
        }
    case TAddResponse:
        {
            return (get_AddResponse()) == ((aRhs).get_AddResponse());
        }
    case TPutResponse:
        {
            return (get_PutResponse()) == ((aRhs).get_PutResponse());
        }
    case TDeleteResponse:
        {
            return (get_DeleteResponse()) == ((aRhs).get_DeleteResponse());
        }
    case TClearResponse:
        {
            return (get_ClearResponse()) == ((aRhs).get_ClearResponse());
        }
    case TCountResponse:
        {
            return (get_CountResponse()) == ((aRhs).get_CountResponse());
        }
    case TOpenCursorResponse:
        {
            return (get_OpenCursorResponse()) == ((aRhs).get_OpenCursorResponse());
        }
    case TContinueResponse:
        {
            return (get_ContinueResponse()) == ((aRhs).get_ContinueResponse());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla