#include "UnionTypes.h"
#include "mozilla/dom/HTMLCanvasElement.h"
#include "mozilla/dom/HTMLImageElement.h"
#include "nsGenericHTMLElement.h"
#include "nsHTMLOptGroupElement.h"
#include "nsHTMLOptionElement.h"
#include "nsHTMLVideoElement.h"
#include "nsIDOMEvent.h"

namespace mozilla {
namespace dom {
} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
bool
ArrayBufferOrLong::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eArrayBuffer:
    {
      *vp = JS::ObjectValue(*mValue.mArrayBuffer.Value().get()->Obj());
      if (!MaybeWrapValue(cx, vp)) {
        return false;
      }
      return true;
    }

    case eLong:
    {
      *vp = INT_TO_JSVAL(int32_t(mValue.mLong.Value()));
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
EventOrString::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eEvent:
    {
      if (!WrapObject(cx, scopeObj, mValue.mEvent.Value(), vp)) {
        return false;
      }
      return true;
    }

    case eString:
    {
      nsString mutableStr(mValue.mString.Value());
      if (!xpc::NonVoidStringToJsval(cx, mutableStr, vp)) {
        return false;
      }
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
HTMLElementOrLong::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eHTMLElement:
    {
      if (!WrapNewBindingObject(cx, scopeObj, mValue.mHTMLElement.Value(), vp)) {
        if (!HandleNewBindingWrappingFailure(cx, scopeObj, mValue.mHTMLElement.Value(), vp)) {
          return false;
        }
        return true;
      }
      return true;
    }

    case eLong:
    {
      *vp = INT_TO_JSVAL(int32_t(mValue.mLong.Value()));
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eHTMLImageElement:
    {
      if (!WrapNewBindingObject(cx, scopeObj, mValue.mHTMLImageElement.Value(), vp)) {
        MOZ_ASSERT(JS_IsExceptionPending(cx));
        return false;
      }
      return true;
    }

    case eHTMLCanvasElement:
    {
      if (!WrapObject(cx, scopeObj, mValue.mHTMLCanvasElement.Value(), vp)) {
        return false;
      }
      return true;
    }

    case eHTMLVideoElement:
    {
      if (!WrapObject(cx, scopeObj, mValue.mHTMLVideoElement.Value(), vp)) {
        return false;
      }
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
HTMLOptionElementOrHTMLOptGroupElement::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eHTMLOptionElement:
    {
      if (!WrapObject(cx, scopeObj, mValue.mHTMLOptionElement.Value(), vp)) {
        return false;
      }
      return true;
    }

    case eHTMLOptGroupElement:
    {
      if (!WrapObject(cx, scopeObj, mValue.mHTMLOptGroupElement.Value(), vp)) {
        return false;
      }
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
ObjectOrLong::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eObject:
    {
      *vp = JS::ObjectValue(*mValue.mObject.Value().get());
      if (!MaybeWrapValue(cx, vp)) {
        return false;
      }
      return true;
    }

    case eLong:
    {
      *vp = INT_TO_JSVAL(int32_t(mValue.mLong.Value()));
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
ObjectOrNullOrLong::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eNull:
    {
      *vp = JS::NullValue();
      return true;
    }

    case eObject:
    {
      *vp = JS::ObjectValue(*mValue.mObject.Value().get());
      if (!MaybeWrapValue(cx, vp)) {
        return false;
      }
      return true;
    }

    case eLong:
    {
      *vp = INT_TO_JSVAL(int32_t(mValue.mLong.Value()));
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}

bool
StringOrObject::ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const
{
  switch (mType) {
    case eString:
    {
      nsString mutableStr(mValue.mString.Value());
      if (!xpc::NonVoidStringToJsval(cx, mutableStr, vp)) {
        return false;
      }
      return true;
    }

    case eObject:
    {
      *vp = JS::ObjectValue(*mValue.mObject.Value().get());
      if (!MaybeWrapValue(cx, vp)) {
        return false;
      }
      return true;
    }

    case eUninitialized:
    {
      break;
    }
  }
  return false;
}
} // namespace dom
} // namespace mozilla

