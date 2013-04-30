#ifndef mozilla_dom_UnionConversions_h__
#define mozilla_dom_UnionConversions_h__

#include "HTMLElementBinding.h"
#include "HTMLImageElementBinding.h"
#include "XPCWrapper.h"
#include "jsfriendapi.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/UnionTypes.h"
#include "nsDOMQS.h"
#include "nsDebug.h"

namespace mozilla {
namespace dom {

class ArrayBufferOrLongArgument {
public:
  ArrayBufferOrLongArgument(const ArrayBufferOrLong& aUnion) : mUnion(const_cast<ArrayBufferOrLong&>(aUnion))
  {
  }

  bool TrySetToArrayBuffer(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    mArrayBufferHolder.construct(&value.toObject());
    if (!mArrayBufferHolder.ref().inited()) {
      tryNext = true;
      return true;
    }
    SetAsArrayBuffer() = mArrayBufferHolder.addr();
    return true;
  }

  bool TrySetToLong(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &SetAsLong())) {
      return false;
    }
    return true;
  }

private:
  NonNull<ArrayBuffer>& SetAsArrayBuffer()
  {
    mUnion.mType = mUnion.eArrayBuffer;
    return mUnion.mValue.mArrayBuffer.SetValue();
  }
  int32_t& SetAsLong()
  {
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  Maybe<ArrayBuffer> mArrayBufferHolder;

  ArrayBufferOrLong& mUnion;
};


class EventOrStringArgument {
public:
  EventOrStringArgument(const EventOrString& aUnion) : mUnion(const_cast<EventOrString&>(aUnion))
  {
  }

  bool TrySetToEvent(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    jsval tmpVal = value;
    nsIDOMEvent* tmp;
    if (NS_FAILED(xpc_qsUnwrapArg<nsIDOMEvent>(cx, value, &tmp, static_cast<nsIDOMEvent**>(getter_AddRefs(mEventHolder)), &tmpVal))) {
      if (mUnion.mType != mUnion.eUninitialized) {
        mUnion.DestroyEvent();
      }tryNext = true;
      return true;
    }
    MOZ_ASSERT(tmp);
    SetAsEvent() = tmp;
    return true;
  }

  bool TrySetToString(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, mStringHolder)) {
      return false;
    }
    const_cast<NonNull<nsAString>&>(SetAsString()) = &mStringHolder;
    return true;
  }

private:
  nsIDOMEvent*& SetAsEvent()
  {
    mUnion.mType = mUnion.eEvent;
    return mUnion.mValue.mEvent.SetValue();
  }
  NonNull<nsAString>& SetAsString()
  {
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  nsRefPtr<nsIDOMEvent> mEventHolder;
  FakeDependentString mStringHolder;

  EventOrString& mUnion;
};


class HTMLElementOrLongArgument {
public:
  HTMLElementOrLongArgument(const HTMLElementOrLong& aUnion) : mUnion(const_cast<HTMLElementOrLong&>(aUnion))
  {
  }

  bool TrySetToHTMLElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLElement, nsGenericHTMLElement>(cx, &value.toObject(), SetAsHTMLElement());
      if (NS_FAILED(rv)) {
        nsGenericHTMLElement *objPtr;
        xpc_qsSelfRef objRef;
        JS::Value val = JS::ObjectValue(*&value.toObject());
        nsresult rv = xpc_qsUnwrapArg<nsGenericHTMLElement>(cx, val, &objPtr, &objRef.ptr, &val);
        if (NS_FAILED(rv)) {
            if (mUnion.mType != mUnion.eUninitialized) {
              mUnion.DestroyHTMLElement();
            }tryNext = true;
            return true;
        }
        // We should be castable!
        MOZ_ASSERT(!objRef.ptr);
        // We should have an object, too!
        MOZ_ASSERT(objPtr);
        SetAsHTMLElement() = objPtr;
      }
    }
    return true;
  }

  bool TrySetToLong(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &SetAsLong())) {
      return false;
    }
    return true;
  }

private:
  NonNull<nsGenericHTMLElement>& SetAsHTMLElement()
  {
    mUnion.mType = mUnion.eHTMLElement;
    return mUnion.mValue.mHTMLElement.SetValue();
  }
  int32_t& SetAsLong()
  {
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  HTMLElementOrLong& mUnion;
};


class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument {
public:
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& aUnion) : mUnion(const_cast<HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&>(aUnion))
  {
  }

  bool TrySetToHTMLImageElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLImageElement, mozilla::dom::HTMLImageElement>(cx, &value.toObject(), SetAsHTMLImageElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLImageElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToHTMLCanvasElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    jsval tmpVal = value;
    mozilla::dom::HTMLCanvasElement* tmp;
    if (NS_FAILED(xpc_qsUnwrapArg<mozilla::dom::HTMLCanvasElement>(cx, value, &tmp, static_cast<mozilla::dom::HTMLCanvasElement**>(getter_AddRefs(mHTMLCanvasElementHolder)), &tmpVal))) {
      if (mUnion.mType != mUnion.eUninitialized) {
        mUnion.DestroyHTMLCanvasElement();
      }tryNext = true;
      return true;
    }
    MOZ_ASSERT(tmp);
    SetAsHTMLCanvasElement() = tmp;
    return true;
  }

  bool TrySetToHTMLVideoElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    jsval tmpVal = value;
    nsHTMLVideoElement* tmp;
    if (NS_FAILED(xpc_qsUnwrapArg<nsHTMLVideoElement>(cx, value, &tmp, static_cast<nsHTMLVideoElement**>(getter_AddRefs(mHTMLVideoElementHolder)), &tmpVal))) {
      if (mUnion.mType != mUnion.eUninitialized) {
        mUnion.DestroyHTMLVideoElement();
      }tryNext = true;
      return true;
    }
    MOZ_ASSERT(tmp);
    SetAsHTMLVideoElement() = tmp;
    return true;
  }

private:
  NonNull<mozilla::dom::HTMLImageElement>& SetAsHTMLImageElement()
  {
    mUnion.mType = mUnion.eHTMLImageElement;
    return mUnion.mValue.mHTMLImageElement.SetValue();
  }
  mozilla::dom::HTMLCanvasElement*& SetAsHTMLCanvasElement()
  {
    mUnion.mType = mUnion.eHTMLCanvasElement;
    return mUnion.mValue.mHTMLCanvasElement.SetValue();
  }
  nsHTMLVideoElement*& SetAsHTMLVideoElement()
  {
    mUnion.mType = mUnion.eHTMLVideoElement;
    return mUnion.mValue.mHTMLVideoElement.SetValue();
  }

  nsRefPtr<mozilla::dom::HTMLCanvasElement> mHTMLCanvasElementHolder;
  nsRefPtr<nsHTMLVideoElement> mHTMLVideoElementHolder;

  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& mUnion;
};


class HTMLOptionElementOrHTMLOptGroupElementArgument {
public:
  HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElement& aUnion) : mUnion(const_cast<HTMLOptionElementOrHTMLOptGroupElement&>(aUnion))
  {
  }

  bool TrySetToHTMLOptionElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    jsval tmpVal = value;
    nsHTMLOptionElement* tmp;
    if (NS_FAILED(xpc_qsUnwrapArg<nsHTMLOptionElement>(cx, value, &tmp, static_cast<nsHTMLOptionElement**>(getter_AddRefs(mHTMLOptionElementHolder)), &tmpVal))) {
      if (mUnion.mType != mUnion.eUninitialized) {
        mUnion.DestroyHTMLOptionElement();
      }tryNext = true;
      return true;
    }
    MOZ_ASSERT(tmp);
    SetAsHTMLOptionElement() = tmp;
    return true;
  }

  bool TrySetToHTMLOptGroupElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    jsval tmpVal = value;
    nsHTMLOptGroupElement* tmp;
    if (NS_FAILED(xpc_qsUnwrapArg<nsHTMLOptGroupElement>(cx, value, &tmp, static_cast<nsHTMLOptGroupElement**>(getter_AddRefs(mHTMLOptGroupElementHolder)), &tmpVal))) {
      if (mUnion.mType != mUnion.eUninitialized) {
        mUnion.DestroyHTMLOptGroupElement();
      }tryNext = true;
      return true;
    }
    MOZ_ASSERT(tmp);
    SetAsHTMLOptGroupElement() = tmp;
    return true;
  }

private:
  nsHTMLOptionElement*& SetAsHTMLOptionElement()
  {
    mUnion.mType = mUnion.eHTMLOptionElement;
    return mUnion.mValue.mHTMLOptionElement.SetValue();
  }
  nsHTMLOptGroupElement*& SetAsHTMLOptGroupElement()
  {
    mUnion.mType = mUnion.eHTMLOptGroupElement;
    return mUnion.mValue.mHTMLOptGroupElement.SetValue();
  }

  nsRefPtr<nsHTMLOptionElement> mHTMLOptionElementHolder;
  nsRefPtr<nsHTMLOptGroupElement> mHTMLOptGroupElementHolder;

  HTMLOptionElementOrHTMLOptGroupElement& mUnion;
};


class ObjectOrLongArgument {
public:
  ObjectOrLongArgument(const ObjectOrLong& aUnion) : mUnion(const_cast<ObjectOrLong&>(aUnion))
  {
  }

  void SetToObject(JSObject* obj)
  {
    mUnion.mValue.mObject.SetValue() = obj;
    mUnion.mType = mUnion.eObject;
  }

  bool TrySetToLong(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &SetAsLong())) {
      return false;
    }
    return true;
  }

private:
  NonNull<JSObject>& SetAsObject()
  {
    mUnion.mType = mUnion.eObject;
    return mUnion.mValue.mObject.SetValue();
  }
  int32_t& SetAsLong()
  {
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  ObjectOrLong& mUnion;
};


class ObjectOrNullOrLongArgument {
public:
  ObjectOrNullOrLongArgument(const ObjectOrNullOrLong& aUnion) : mUnion(const_cast<ObjectOrNullOrLong&>(aUnion))
  {
  }

  bool SetNull()
  {
    mUnion.mType = mUnion.eNull;
    return true;
  }

  void SetToObject(JSObject* obj)
  {
    mUnion.mValue.mObject.SetValue() = obj;
    mUnion.mType = mUnion.eObject;
  }

  bool TrySetToLong(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &SetAsLong())) {
      return false;
    }
    return true;
  }

private:
  NonNull<JSObject>& SetAsObject()
  {
    mUnion.mType = mUnion.eObject;
    return mUnion.mValue.mObject.SetValue();
  }
  int32_t& SetAsLong()
  {
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  ObjectOrNullOrLong& mUnion;
};


class StringOrObjectArgument {
public:
  StringOrObjectArgument(const StringOrObject& aUnion) : mUnion(const_cast<StringOrObject&>(aUnion))
  {
  }

  bool TrySetToString(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, mStringHolder)) {
      return false;
    }
    const_cast<NonNull<nsAString>&>(SetAsString()) = &mStringHolder;
    return true;
  }

  void SetToObject(JSObject* obj)
  {
    mUnion.mValue.mObject.SetValue() = obj;
    mUnion.mType = mUnion.eObject;
  }

private:
  NonNull<nsAString>& SetAsString()
  {
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
  NonNull<JSObject>& SetAsObject()
  {
    mUnion.mType = mUnion.eObject;
    return mUnion.mValue.mObject.SetValue();
  }

  FakeDependentString mStringHolder;

  StringOrObject& mUnion;
};


} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionConversions_h__
