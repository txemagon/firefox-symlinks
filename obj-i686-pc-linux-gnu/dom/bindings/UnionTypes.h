#ifndef mozilla_dom_UnionTypes_h__
#define mozilla_dom_UnionTypes_h__

#include "jsfriendapi.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/TypedArray.h"

namespace mozilla {
namespace dom {
class HTMLCanvasElement;
class HTMLImageElement;
} // namespace dom
} // namespace mozilla
class nsGenericHTMLElement;
class nsHTMLOptGroupElement;
class nsHTMLOptionElement;
class nsHTMLVideoElement;
class nsIDOMEvent;

namespace mozilla {
namespace dom {

class ArrayBufferOrLong {
public:
  ArrayBufferOrLong() : mType(eUninitialized)
  {
  }
  ~ArrayBufferOrLong()
  {
    switch (mType) {
      case eArrayBuffer:
         DestroyArrayBuffer();
         break;
      case eLong:
         DestroyLong();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }
  ArrayBuffer& GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return const_cast<NonNull<ArrayBuffer>&>(mValue.mArrayBuffer.Value());
  }
  NonNull<ArrayBuffer>& SetAsArrayBuffer()
  {
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue();
  }

  bool IsLong() const
  {
    return mType == eLong;
  }
  int32_t GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }
  int32_t& SetAsLong()
  {
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class ArrayBufferOrLongArgument;

  void DestroyArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    mValue.mArrayBuffer.Destroy();
    mType = eUninitialized;
  }
  void DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eArrayBuffer,
    eLong
  };
  union Value {
    UnionMember<NonNull<ArrayBuffer> > mArrayBuffer;
    UnionMember<int32_t > mLong;
  };

  Type mType;
  Value mValue;
};



class EventOrString {
public:
  EventOrString() : mType(eUninitialized)
  {
  }
  ~EventOrString()
  {
    switch (mType) {
      case eEvent:
         DestroyEvent();
         break;
      case eString:
         DestroyString();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsEvent() const
  {
    return mType == eEvent;
  }
  nsIDOMEvent* GetAsEvent() const
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    return const_cast<nsIDOMEvent*&>(mValue.mEvent.Value());
  }
  nsIDOMEvent*& SetAsEvent()
  {
    mType = eEvent;
    return mValue.mEvent.SetValue();
  }

  bool IsString() const
  {
    return mType == eString;
  }
  const nsAString& GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<NonNull<nsAString>&>(mValue.mString.Value());
  }
  NonNull<nsAString>& SetAsString()
  {
    mType = eString;
    return mValue.mString.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class EventOrStringArgument;

  void DestroyEvent()
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    mValue.mEvent.Destroy();
    mType = eUninitialized;
  }
  void DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eEvent,
    eString
  };
  union Value {
    UnionMember<nsIDOMEvent* > mEvent;
    UnionMember<NonNull<nsAString> > mString;
  };

  Type mType;
  Value mValue;
};



class HTMLElementOrLong {
public:
  HTMLElementOrLong() : mType(eUninitialized)
  {
  }
  ~HTMLElementOrLong()
  {
    switch (mType) {
      case eHTMLElement:
         DestroyHTMLElement();
         break;
      case eLong:
         DestroyLong();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsHTMLElement() const
  {
    return mType == eHTMLElement;
  }
  nsGenericHTMLElement& GetAsHTMLElement() const
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return const_cast<NonNull<nsGenericHTMLElement>&>(mValue.mHTMLElement.Value());
  }
  NonNull<nsGenericHTMLElement>& SetAsHTMLElement()
  {
    mType = eHTMLElement;
    return mValue.mHTMLElement.SetValue();
  }

  bool IsLong() const
  {
    return mType == eLong;
  }
  int32_t GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }
  int32_t& SetAsLong()
  {
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class HTMLElementOrLongArgument;

  void DestroyHTMLElement()
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    mValue.mHTMLElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eHTMLElement,
    eLong
  };
  union Value {
    UnionMember<NonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;
  };

  Type mType;
  Value mValue;
};



class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement {
public:
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement() : mType(eUninitialized)
  {
  }
  ~HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement()
  {
    switch (mType) {
      case eHTMLImageElement:
         DestroyHTMLImageElement();
         break;
      case eHTMLCanvasElement:
         DestroyHTMLCanvasElement();
         break;
      case eHTMLVideoElement:
         DestroyHTMLVideoElement();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsHTMLImageElement() const
  {
    return mType == eHTMLImageElement;
  }
  mozilla::dom::HTMLImageElement& GetAsHTMLImageElement() const
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLImageElement>&>(mValue.mHTMLImageElement.Value());
  }
  NonNull<mozilla::dom::HTMLImageElement>& SetAsHTMLImageElement()
  {
    mType = eHTMLImageElement;
    return mValue.mHTMLImageElement.SetValue();
  }

  bool IsHTMLCanvasElement() const
  {
    return mType == eHTMLCanvasElement;
  }
  mozilla::dom::HTMLCanvasElement* GetAsHTMLCanvasElement() const
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    return const_cast<mozilla::dom::HTMLCanvasElement*&>(mValue.mHTMLCanvasElement.Value());
  }
  mozilla::dom::HTMLCanvasElement*& SetAsHTMLCanvasElement()
  {
    mType = eHTMLCanvasElement;
    return mValue.mHTMLCanvasElement.SetValue();
  }

  bool IsHTMLVideoElement() const
  {
    return mType == eHTMLVideoElement;
  }
  nsHTMLVideoElement* GetAsHTMLVideoElement() const
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    return const_cast<nsHTMLVideoElement*&>(mValue.mHTMLVideoElement.Value());
  }
  nsHTMLVideoElement*& SetAsHTMLVideoElement()
  {
    mType = eHTMLVideoElement;
    return mValue.mHTMLVideoElement.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument;

  void DestroyHTMLImageElement()
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    mValue.mHTMLImageElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyHTMLCanvasElement()
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    mValue.mHTMLCanvasElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyHTMLVideoElement()
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    mValue.mHTMLVideoElement.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eHTMLImageElement,
    eHTMLCanvasElement,
    eHTMLVideoElement
  };
  union Value {
    UnionMember<NonNull<mozilla::dom::HTMLImageElement> > mHTMLImageElement;
    UnionMember<mozilla::dom::HTMLCanvasElement* > mHTMLCanvasElement;
    UnionMember<nsHTMLVideoElement* > mHTMLVideoElement;
  };

  Type mType;
  Value mValue;
};



class HTMLOptionElementOrHTMLOptGroupElement {
public:
  HTMLOptionElementOrHTMLOptGroupElement() : mType(eUninitialized)
  {
  }
  ~HTMLOptionElementOrHTMLOptGroupElement()
  {
    switch (mType) {
      case eHTMLOptionElement:
         DestroyHTMLOptionElement();
         break;
      case eHTMLOptGroupElement:
         DestroyHTMLOptGroupElement();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsHTMLOptionElement() const
  {
    return mType == eHTMLOptionElement;
  }
  nsHTMLOptionElement* GetAsHTMLOptionElement() const
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return const_cast<nsHTMLOptionElement*&>(mValue.mHTMLOptionElement.Value());
  }
  nsHTMLOptionElement*& SetAsHTMLOptionElement()
  {
    mType = eHTMLOptionElement;
    return mValue.mHTMLOptionElement.SetValue();
  }

  bool IsHTMLOptGroupElement() const
  {
    return mType == eHTMLOptGroupElement;
  }
  nsHTMLOptGroupElement* GetAsHTMLOptGroupElement() const
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return const_cast<nsHTMLOptGroupElement*&>(mValue.mHTMLOptGroupElement.Value());
  }
  nsHTMLOptGroupElement*& SetAsHTMLOptGroupElement()
  {
    mType = eHTMLOptGroupElement;
    return mValue.mHTMLOptGroupElement.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class HTMLOptionElementOrHTMLOptGroupElementArgument;

  void DestroyHTMLOptionElement()
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    mValue.mHTMLOptionElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyHTMLOptGroupElement()
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    mValue.mHTMLOptGroupElement.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };
  union Value {
    UnionMember<nsHTMLOptionElement* > mHTMLOptionElement;
    UnionMember<nsHTMLOptGroupElement* > mHTMLOptGroupElement;
  };

  Type mType;
  Value mValue;
};



class ObjectOrLong {
public:
  ObjectOrLong() : mType(eUninitialized)
  {
  }
  ~ObjectOrLong()
  {
    switch (mType) {
      case eObject:
         DestroyObject();
         break;
      case eLong:
         DestroyLong();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsObject() const
  {
    return mType == eObject;
  }
  JSObject& GetAsObject() const
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    return const_cast<NonNull<JSObject>&>(mValue.mObject.Value());
  }
  NonNull<JSObject>& SetAsObject()
  {
    mType = eObject;
    return mValue.mObject.SetValue();
  }

  bool IsLong() const
  {
    return mType == eLong;
  }
  int32_t GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }
  int32_t& SetAsLong()
  {
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class ObjectOrLongArgument;

  void DestroyObject()
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    mValue.mObject.Destroy();
    mType = eUninitialized;
  }
  void DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eObject,
    eLong
  };
  union Value {
    UnionMember<NonNull<JSObject> > mObject;
    UnionMember<int32_t > mLong;
  };

  Type mType;
  Value mValue;
};



class ObjectOrNullOrLong {
public:
  ObjectOrNullOrLong() : mType(eUninitialized)
  {
  }
  ~ObjectOrNullOrLong()
  {
    switch (mType) {
      case eNull:
        break;
      case eObject:
         DestroyObject();
         break;
      case eLong:
         DestroyLong();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsNull() const
  {
    return mType == eNull;
  }

  bool IsObject() const
  {
    return mType == eObject;
  }
  JSObject& GetAsObject() const
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    return const_cast<NonNull<JSObject>&>(mValue.mObject.Value());
  }
  NonNull<JSObject>& SetAsObject()
  {
    mType = eObject;
    return mValue.mObject.SetValue();
  }

  bool IsLong() const
  {
    return mType == eLong;
  }
  int32_t GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }
  int32_t& SetAsLong()
  {
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class ObjectOrNullOrLongArgument;

  void DestroyObject()
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    mValue.mObject.Destroy();
    mType = eUninitialized;
  }
  void DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eNull,
    eObject,
    eLong
  };
  union Value {
    UnionMember<NonNull<JSObject> > mObject;
    UnionMember<int32_t > mLong;
  };

  Type mType;
  Value mValue;
};



class StringOrObject {
public:
  StringOrObject() : mType(eUninitialized)
  {
  }
  ~StringOrObject()
  {
    switch (mType) {
      case eString:
         DestroyString();
         break;
      case eObject:
         DestroyObject();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsString() const
  {
    return mType == eString;
  }
  const nsAString& GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<NonNull<nsAString>&>(mValue.mString.Value());
  }
  NonNull<nsAString>& SetAsString()
  {
    mType = eString;
    return mValue.mString.SetValue();
  }

  bool IsObject() const
  {
    return mType == eObject;
  }
  JSObject& GetAsObject() const
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    return const_cast<NonNull<JSObject>&>(mValue.mObject.Value());
  }
  NonNull<JSObject>& SetAsObject()
  {
    mType = eObject;
    return mValue.mObject.SetValue();
  }

  bool ToJSVal(JSContext* cx, JSObject* scopeObj, JS::Value* vp) const;

private:
  friend class StringOrObjectArgument;

  void DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }
  void DestroyObject()
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    mValue.mObject.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eString,
    eObject
  };
  union Value {
    UnionMember<NonNull<nsAString> > mString;
    UnionMember<NonNull<JSObject> > mObject;
  };

  Type mType;
  Value mValue;
};

} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionTypes_h__
