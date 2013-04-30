//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/indexedDB/PIndexedDBTransaction.h"

namespace mozilla {
namespace dom {
namespace indexedDB {
namespace PIndexedDBTransaction {

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

} // namespace PIndexedDBTransaction
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct CreateObjectStoreParams|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
CreateObjectStoreParams::CreateObjectStoreParams()
{
    Init();
}

CreateObjectStoreParams::~CreateObjectStoreParams()
{
}

bool
CreateObjectStoreParams::operator==(const CreateObjectStoreParams& _o) const
{
    if ((!((info()) == ((_o).info())))) {
        return false;
    }
    return true;
}

void
CreateObjectStoreParams::Init()
{
}

void
CreateObjectStoreParams::Assign(const ObjectStoreInfoGuts& _info)
{
    info_ = _info;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetObjectStoreParams|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
GetObjectStoreParams::GetObjectStoreParams()
{
    Init();
}

GetObjectStoreParams::~GetObjectStoreParams()
{
}

bool
GetObjectStoreParams::operator==(const GetObjectStoreParams& _o) const
{
    if ((!((name()) == ((_o).name())))) {
        return false;
    }
    return true;
}

void
GetObjectStoreParams::Init()
{
}

void
GetObjectStoreParams::Assign(const nsString& _name)
{
    name_ = _name;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union ObjectStoreConstructorParams|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
bool
ObjectStoreConstructorParams::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TCreateObjectStoreParams:
        {
            (ptr_CreateObjectStoreParams())->~CreateObjectStoreParams__tdef();
            break;
        }
    case TGetObjectStoreParams:
        {
            (ptr_GetObjectStoreParams())->~GetObjectStoreParams__tdef();
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

ObjectStoreConstructorParams::ObjectStoreConstructorParams(const CreateObjectStoreParams& aOther)
{
    new (ptr_CreateObjectStoreParams()) CreateObjectStoreParams(aOther);
    mType = TCreateObjectStoreParams;
}

ObjectStoreConstructorParams::ObjectStoreConstructorParams(const GetObjectStoreParams& aOther)
{
    new (ptr_GetObjectStoreParams()) GetObjectStoreParams(aOther);
    mType = TGetObjectStoreParams;
}

ObjectStoreConstructorParams::ObjectStoreConstructorParams(const ObjectStoreConstructorParams& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TCreateObjectStoreParams:
        {
            new (ptr_CreateObjectStoreParams()) CreateObjectStoreParams((aOther).get_CreateObjectStoreParams());
            break;
        }
    case TGetObjectStoreParams:
        {
            new (ptr_GetObjectStoreParams()) GetObjectStoreParams((aOther).get_GetObjectStoreParams());
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

ObjectStoreConstructorParams::~ObjectStoreConstructorParams()
{
    MaybeDestroy(T__None);
}

ObjectStoreConstructorParams&
ObjectStoreConstructorParams::operator=(const CreateObjectStoreParams& aRhs)
{
    if (MaybeDestroy(TCreateObjectStoreParams)) {
        new (ptr_CreateObjectStoreParams()) CreateObjectStoreParams;
    }
    (*(ptr_CreateObjectStoreParams())) = aRhs;
    mType = TCreateObjectStoreParams;
    return (*(this));
}

ObjectStoreConstructorParams&
ObjectStoreConstructorParams::operator=(const GetObjectStoreParams& aRhs)
{
    if (MaybeDestroy(TGetObjectStoreParams)) {
        new (ptr_GetObjectStoreParams()) GetObjectStoreParams;
    }
    (*(ptr_GetObjectStoreParams())) = aRhs;
    mType = TGetObjectStoreParams;
    return (*(this));
}

ObjectStoreConstructorParams&
ObjectStoreConstructorParams::operator=(const ObjectStoreConstructorParams& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TCreateObjectStoreParams:
        {
            if (MaybeDestroy(t)) {
                new (ptr_CreateObjectStoreParams()) CreateObjectStoreParams;
            }
            (*(ptr_CreateObjectStoreParams())) = (aRhs).get_CreateObjectStoreParams();
            break;
        }
    case TGetObjectStoreParams:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetObjectStoreParams()) GetObjectStoreParams;
            }
            (*(ptr_GetObjectStoreParams())) = (aRhs).get_GetObjectStoreParams();
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
ObjectStoreConstructorParams::operator==(const CreateObjectStoreParams& aRhs) const
{
    return (get_CreateObjectStoreParams()) == (aRhs);
}

bool
ObjectStoreConstructorParams::operator==(const GetObjectStoreParams& aRhs) const
{
    return (get_GetObjectStoreParams()) == (aRhs);
}

bool
ObjectStoreConstructorParams::operator==(const ObjectStoreConstructorParams& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TCreateObjectStoreParams:
        {
            return (get_CreateObjectStoreParams()) == ((aRhs).get_CreateObjectStoreParams());
        }
    case TGetObjectStoreParams:
        {
            return (get_GetObjectStoreParams()) == ((aRhs).get_GetObjectStoreParams());
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
// Method definitions for the IPDL type |struct CompleteResult|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
CompleteResult::~CompleteResult()
{
}

bool
CompleteResult::operator==(const CompleteResult& _o) const
{
    return true;
}

void
CompleteResult::Init()
{
}

void
CompleteResult::Assign()
{
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct AbortResult|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
AbortResult::AbortResult()
{
    Init();
}

AbortResult::~AbortResult()
{
}

bool
AbortResult::operator==(const AbortResult& _o) const
{
    if ((!((errorCode()) == ((_o).errorCode())))) {
        return false;
    }
    return true;
}

void
AbortResult::Init()
{
}

void
AbortResult::Assign(const nsresult& _errorCode)
{
    errorCode_ = _errorCode;
}

} // namespace ipc
} // namespace indexedDB
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union CompleteParams|
//
namespace mozilla {
namespace dom {
namespace indexedDB {
namespace ipc {
bool
CompleteParams::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TCompleteResult:
        {
            (ptr_CompleteResult())->~CompleteResult__tdef();
            break;
        }
    case TAbortResult:
        {
            (ptr_AbortResult())->~AbortResult__tdef();
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

CompleteParams::CompleteParams(const CompleteResult& aOther)
{
    new (ptr_CompleteResult()) CompleteResult(aOther);
    mType = TCompleteResult;
}

CompleteParams::CompleteParams(const AbortResult& aOther)
{
    new (ptr_AbortResult()) AbortResult(aOther);
    mType = TAbortResult;
}

CompleteParams::CompleteParams(const CompleteParams& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TCompleteResult:
        {
            new (ptr_CompleteResult()) CompleteResult((aOther).get_CompleteResult());
            break;
        }
    case TAbortResult:
        {
            new (ptr_AbortResult()) AbortResult((aOther).get_AbortResult());
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

CompleteParams::~CompleteParams()
{
    MaybeDestroy(T__None);
}

CompleteParams&
CompleteParams::operator=(const CompleteResult& aRhs)
{
    if (MaybeDestroy(TCompleteResult)) {
        new (ptr_CompleteResult()) CompleteResult;
    }
    (*(ptr_CompleteResult())) = aRhs;
    mType = TCompleteResult;
    return (*(this));
}

CompleteParams&
CompleteParams::operator=(const AbortResult& aRhs)
{
    if (MaybeDestroy(TAbortResult)) {
        new (ptr_AbortResult()) AbortResult;
    }
    (*(ptr_AbortResult())) = aRhs;
    mType = TAbortResult;
    return (*(this));
}

CompleteParams&
CompleteParams::operator=(const CompleteParams& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TCompleteResult:
        {
            if (MaybeDestroy(t)) {
                new (ptr_CompleteResult()) CompleteResult;
            }
            (*(ptr_CompleteResult())) = (aRhs).get_CompleteResult();
            break;
        }
    case TAbortResult:
        {
            if (MaybeDestroy(t)) {
                new (ptr_AbortResult()) AbortResult;
            }
            (*(ptr_AbortResult())) = (aRhs).get_AbortResult();
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
CompleteParams::operator==(const CompleteResult& aRhs) const
{
    return (get_CompleteResult()) == (aRhs);
}

bool
CompleteParams::operator==(const AbortResult& aRhs) const
{
    return (get_AbortResult()) == (aRhs);
}

bool
CompleteParams::operator==(const CompleteParams& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TCompleteResult:
        {
            return (get_CompleteResult()) == ((aRhs).get_CompleteResult());
        }
    case TAbortResult:
        {
            return (get_AbortResult()) == ((aRhs).get_AbortResult());
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