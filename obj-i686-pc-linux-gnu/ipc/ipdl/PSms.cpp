//
// Automatically generated by ipdlc.
// Edit at your own risk
//


#include "mozilla/dom/sms/PSms.h"

namespace mozilla {
namespace dom {
namespace sms {
namespace PSms {

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

} // namespace PSms
} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SmsFilterData|
//
namespace mozilla {
namespace dom {
namespace sms {
SmsFilterData::SmsFilterData()
{
    Init();
}

SmsFilterData::~SmsFilterData()
{
}

bool
SmsFilterData::operator==(const SmsFilterData& _o) const
{
    if ((!((startDate()) == ((_o).startDate())))) {
        return false;
    }
    if ((!((endDate()) == ((_o).endDate())))) {
        return false;
    }
    if ((!((numbers()) == ((_o).numbers())))) {
        return false;
    }
    if ((!((delivery()) == ((_o).delivery())))) {
        return false;
    }
    if ((!((read()) == ((_o).read())))) {
        return false;
    }
    return true;
}

void
SmsFilterData::Init()
{
}

void
SmsFilterData::Assign(
        const uint64_t& _startDate,
        const uint64_t& _endDate,
        const InfallibleTArray<nsString>& _numbers,
        const DeliveryState& _delivery,
        const ReadState& _read)
{
    startDate_ = _startDate;
    endDate_ = _endDate;
    numbers_ = _numbers;
    delivery_ = _delivery;
    read_ = _read;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct SendMessageRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
SendMessageRequest::SendMessageRequest()
{
    Init();
}

SendMessageRequest::~SendMessageRequest()
{
}

bool
SendMessageRequest::operator==(const SendMessageRequest& _o) const
{
    if ((!((number()) == ((_o).number())))) {
        return false;
    }
    if ((!((message()) == ((_o).message())))) {
        return false;
    }
    return true;
}

void
SendMessageRequest::Init()
{
}

void
SendMessageRequest::Assign(
        const nsString& _number,
        const nsString& _message)
{
    number_ = _number;
    message_ = _message;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetMessageRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
GetMessageRequest::GetMessageRequest()
{
    Init();
}

GetMessageRequest::~GetMessageRequest()
{
}

bool
GetMessageRequest::operator==(const GetMessageRequest& _o) const
{
    if ((!((messageId()) == ((_o).messageId())))) {
        return false;
    }
    return true;
}

void
GetMessageRequest::Init()
{
}

void
GetMessageRequest::Assign(const int32_t& _messageId)
{
    messageId_ = _messageId;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct DeleteMessageRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
DeleteMessageRequest::DeleteMessageRequest()
{
    Init();
}

DeleteMessageRequest::~DeleteMessageRequest()
{
}

bool
DeleteMessageRequest::operator==(const DeleteMessageRequest& _o) const
{
    if ((!((messageId()) == ((_o).messageId())))) {
        return false;
    }
    return true;
}

void
DeleteMessageRequest::Init()
{
}

void
DeleteMessageRequest::Assign(const int32_t& _messageId)
{
    messageId_ = _messageId;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct CreateMessageListRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
CreateMessageListRequest::CreateMessageListRequest()
{
    Init();
}

CreateMessageListRequest::~CreateMessageListRequest()
{
}

bool
CreateMessageListRequest::operator==(const CreateMessageListRequest& _o) const
{
    if ((!((filter()) == ((_o).filter())))) {
        return false;
    }
    if ((!((reverse()) == ((_o).reverse())))) {
        return false;
    }
    return true;
}

void
CreateMessageListRequest::Init()
{
}

void
CreateMessageListRequest::Assign(
        const SmsFilterData& _filter,
        const bool& _reverse)
{
    filter_ = _filter;
    reverse_ = _reverse;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetNextMessageInListRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
GetNextMessageInListRequest::GetNextMessageInListRequest()
{
    Init();
}

GetNextMessageInListRequest::~GetNextMessageInListRequest()
{
}

bool
GetNextMessageInListRequest::operator==(const GetNextMessageInListRequest& _o) const
{
    if ((!((aListId()) == ((_o).aListId())))) {
        return false;
    }
    return true;
}

void
GetNextMessageInListRequest::Init()
{
}

void
GetNextMessageInListRequest::Assign(const int32_t& _aListId)
{
    aListId_ = _aListId;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct MarkMessageReadRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
MarkMessageReadRequest::MarkMessageReadRequest()
{
    Init();
}

MarkMessageReadRequest::~MarkMessageReadRequest()
{
}

bool
MarkMessageReadRequest::operator==(const MarkMessageReadRequest& _o) const
{
    if ((!((messageId()) == ((_o).messageId())))) {
        return false;
    }
    if ((!((value()) == ((_o).value())))) {
        return false;
    }
    return true;
}

void
MarkMessageReadRequest::Init()
{
}

void
MarkMessageReadRequest::Assign(
        const int32_t& _messageId,
        const bool& _value)
{
    messageId_ = _messageId;
    value_ = _value;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |struct GetThreadListRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
GetThreadListRequest::~GetThreadListRequest()
{
}

bool
GetThreadListRequest::operator==(const GetThreadListRequest& _o) const
{
    return true;
}

void
GetThreadListRequest::Init()
{
}

void
GetThreadListRequest::Assign()
{
}

} // namespace sms
} // namespace dom
} // namespace mozilla

//-----------------------------------------------------------------------------
// Method definitions for the IPDL type |union IPCSmsRequest|
//
namespace mozilla {
namespace dom {
namespace sms {
bool
IPCSmsRequest::MaybeDestroy(Type aNewType)
{
    if ((mType) == (T__None)) {
        return true;
    }
    if ((mType) == (aNewType)) {
        return false;
    }
    switch (mType) {
    case TSendMessageRequest:
        {
            (ptr_SendMessageRequest())->~SendMessageRequest__tdef();
            break;
        }
    case TGetMessageRequest:
        {
            (ptr_GetMessageRequest())->~GetMessageRequest__tdef();
            break;
        }
    case TDeleteMessageRequest:
        {
            (ptr_DeleteMessageRequest())->~DeleteMessageRequest__tdef();
            break;
        }
    case TCreateMessageListRequest:
        {
            (ptr_CreateMessageListRequest())->~CreateMessageListRequest__tdef();
            break;
        }
    case TGetNextMessageInListRequest:
        {
            (ptr_GetNextMessageInListRequest())->~GetNextMessageInListRequest__tdef();
            break;
        }
    case TMarkMessageReadRequest:
        {
            (ptr_MarkMessageReadRequest())->~MarkMessageReadRequest__tdef();
            break;
        }
    case TGetThreadListRequest:
        {
            (ptr_GetThreadListRequest())->~GetThreadListRequest__tdef();
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

IPCSmsRequest::IPCSmsRequest(const SendMessageRequest& aOther)
{
    new (ptr_SendMessageRequest()) SendMessageRequest(aOther);
    mType = TSendMessageRequest;
}

IPCSmsRequest::IPCSmsRequest(const GetMessageRequest& aOther)
{
    new (ptr_GetMessageRequest()) GetMessageRequest(aOther);
    mType = TGetMessageRequest;
}

IPCSmsRequest::IPCSmsRequest(const DeleteMessageRequest& aOther)
{
    new (ptr_DeleteMessageRequest()) DeleteMessageRequest(aOther);
    mType = TDeleteMessageRequest;
}

IPCSmsRequest::IPCSmsRequest(const CreateMessageListRequest& aOther)
{
    new (ptr_CreateMessageListRequest()) CreateMessageListRequest(aOther);
    mType = TCreateMessageListRequest;
}

IPCSmsRequest::IPCSmsRequest(const GetNextMessageInListRequest& aOther)
{
    new (ptr_GetNextMessageInListRequest()) GetNextMessageInListRequest(aOther);
    mType = TGetNextMessageInListRequest;
}

IPCSmsRequest::IPCSmsRequest(const MarkMessageReadRequest& aOther)
{
    new (ptr_MarkMessageReadRequest()) MarkMessageReadRequest(aOther);
    mType = TMarkMessageReadRequest;
}

IPCSmsRequest::IPCSmsRequest(const GetThreadListRequest& aOther)
{
    new (ptr_GetThreadListRequest()) GetThreadListRequest(aOther);
    mType = TGetThreadListRequest;
}

IPCSmsRequest::IPCSmsRequest(const IPCSmsRequest& aOther)
{
    (aOther).AssertSanity();
    switch ((aOther).type()) {
    case TSendMessageRequest:
        {
            new (ptr_SendMessageRequest()) SendMessageRequest((aOther).get_SendMessageRequest());
            break;
        }
    case TGetMessageRequest:
        {
            new (ptr_GetMessageRequest()) GetMessageRequest((aOther).get_GetMessageRequest());
            break;
        }
    case TDeleteMessageRequest:
        {
            new (ptr_DeleteMessageRequest()) DeleteMessageRequest((aOther).get_DeleteMessageRequest());
            break;
        }
    case TCreateMessageListRequest:
        {
            new (ptr_CreateMessageListRequest()) CreateMessageListRequest((aOther).get_CreateMessageListRequest());
            break;
        }
    case TGetNextMessageInListRequest:
        {
            new (ptr_GetNextMessageInListRequest()) GetNextMessageInListRequest((aOther).get_GetNextMessageInListRequest());
            break;
        }
    case TMarkMessageReadRequest:
        {
            new (ptr_MarkMessageReadRequest()) MarkMessageReadRequest((aOther).get_MarkMessageReadRequest());
            break;
        }
    case TGetThreadListRequest:
        {
            new (ptr_GetThreadListRequest()) GetThreadListRequest((aOther).get_GetThreadListRequest());
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

IPCSmsRequest::~IPCSmsRequest()
{
    MaybeDestroy(T__None);
}

IPCSmsRequest&
IPCSmsRequest::operator=(const SendMessageRequest& aRhs)
{
    if (MaybeDestroy(TSendMessageRequest)) {
        new (ptr_SendMessageRequest()) SendMessageRequest;
    }
    (*(ptr_SendMessageRequest())) = aRhs;
    mType = TSendMessageRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const GetMessageRequest& aRhs)
{
    if (MaybeDestroy(TGetMessageRequest)) {
        new (ptr_GetMessageRequest()) GetMessageRequest;
    }
    (*(ptr_GetMessageRequest())) = aRhs;
    mType = TGetMessageRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const DeleteMessageRequest& aRhs)
{
    if (MaybeDestroy(TDeleteMessageRequest)) {
        new (ptr_DeleteMessageRequest()) DeleteMessageRequest;
    }
    (*(ptr_DeleteMessageRequest())) = aRhs;
    mType = TDeleteMessageRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const CreateMessageListRequest& aRhs)
{
    if (MaybeDestroy(TCreateMessageListRequest)) {
        new (ptr_CreateMessageListRequest()) CreateMessageListRequest;
    }
    (*(ptr_CreateMessageListRequest())) = aRhs;
    mType = TCreateMessageListRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const GetNextMessageInListRequest& aRhs)
{
    if (MaybeDestroy(TGetNextMessageInListRequest)) {
        new (ptr_GetNextMessageInListRequest()) GetNextMessageInListRequest;
    }
    (*(ptr_GetNextMessageInListRequest())) = aRhs;
    mType = TGetNextMessageInListRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const MarkMessageReadRequest& aRhs)
{
    if (MaybeDestroy(TMarkMessageReadRequest)) {
        new (ptr_MarkMessageReadRequest()) MarkMessageReadRequest;
    }
    (*(ptr_MarkMessageReadRequest())) = aRhs;
    mType = TMarkMessageReadRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const GetThreadListRequest& aRhs)
{
    if (MaybeDestroy(TGetThreadListRequest)) {
        new (ptr_GetThreadListRequest()) GetThreadListRequest;
    }
    (*(ptr_GetThreadListRequest())) = aRhs;
    mType = TGetThreadListRequest;
    return (*(this));
}

IPCSmsRequest&
IPCSmsRequest::operator=(const IPCSmsRequest& aRhs)
{
    (aRhs).AssertSanity();
    Type t = (aRhs).type();
    switch (t) {
    case TSendMessageRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_SendMessageRequest()) SendMessageRequest;
            }
            (*(ptr_SendMessageRequest())) = (aRhs).get_SendMessageRequest();
            break;
        }
    case TGetMessageRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetMessageRequest()) GetMessageRequest;
            }
            (*(ptr_GetMessageRequest())) = (aRhs).get_GetMessageRequest();
            break;
        }
    case TDeleteMessageRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_DeleteMessageRequest()) DeleteMessageRequest;
            }
            (*(ptr_DeleteMessageRequest())) = (aRhs).get_DeleteMessageRequest();
            break;
        }
    case TCreateMessageListRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_CreateMessageListRequest()) CreateMessageListRequest;
            }
            (*(ptr_CreateMessageListRequest())) = (aRhs).get_CreateMessageListRequest();
            break;
        }
    case TGetNextMessageInListRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetNextMessageInListRequest()) GetNextMessageInListRequest;
            }
            (*(ptr_GetNextMessageInListRequest())) = (aRhs).get_GetNextMessageInListRequest();
            break;
        }
    case TMarkMessageReadRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_MarkMessageReadRequest()) MarkMessageReadRequest;
            }
            (*(ptr_MarkMessageReadRequest())) = (aRhs).get_MarkMessageReadRequest();
            break;
        }
    case TGetThreadListRequest:
        {
            if (MaybeDestroy(t)) {
                new (ptr_GetThreadListRequest()) GetThreadListRequest;
            }
            (*(ptr_GetThreadListRequest())) = (aRhs).get_GetThreadListRequest();
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
IPCSmsRequest::operator==(const SendMessageRequest& aRhs) const
{
    return (get_SendMessageRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const GetMessageRequest& aRhs) const
{
    return (get_GetMessageRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const DeleteMessageRequest& aRhs) const
{
    return (get_DeleteMessageRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const CreateMessageListRequest& aRhs) const
{
    return (get_CreateMessageListRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const GetNextMessageInListRequest& aRhs) const
{
    return (get_GetNextMessageInListRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const MarkMessageReadRequest& aRhs) const
{
    return (get_MarkMessageReadRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const GetThreadListRequest& aRhs) const
{
    return (get_GetThreadListRequest()) == (aRhs);
}

bool
IPCSmsRequest::operator==(const IPCSmsRequest& aRhs) const
{
    if ((type()) != ((aRhs).type())) {
        return false;
    }

    switch (type()) {
    case TSendMessageRequest:
        {
            return (get_SendMessageRequest()) == ((aRhs).get_SendMessageRequest());
        }
    case TGetMessageRequest:
        {
            return (get_GetMessageRequest()) == ((aRhs).get_GetMessageRequest());
        }
    case TDeleteMessageRequest:
        {
            return (get_DeleteMessageRequest()) == ((aRhs).get_DeleteMessageRequest());
        }
    case TCreateMessageListRequest:
        {
            return (get_CreateMessageListRequest()) == ((aRhs).get_CreateMessageListRequest());
        }
    case TGetNextMessageInListRequest:
        {
            return (get_GetNextMessageInListRequest()) == ((aRhs).get_GetNextMessageInListRequest());
        }
    case TMarkMessageReadRequest:
        {
            return (get_MarkMessageReadRequest()) == ((aRhs).get_MarkMessageReadRequest());
        }
    case TGetThreadListRequest:
        {
            return (get_GetThreadListRequest()) == ((aRhs).get_GetThreadListRequest());
        }
    default:
        {
            NS_RUNTIMEABORT("unreached");
            return false;
        }
    }
}

} // namespace sms
} // namespace dom
} // namespace mozilla