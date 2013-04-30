/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "PrimitiveConversions.h"
#include "TextEncoderBinding.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "jsfriendapi.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/TextEncoder.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/workers/bindings/TextEncoder.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

bool
TextEncodeOptionsWorkers::Init(JSContext* cx, JSObject* scopeObj, const JS::Value& val)
{
  // Passing a null JSContext is OK only if we're initing from null,
  // Since in that case we will not have to do any property gets
  MOZ_ASSERT_IF(!cx, val.isNull());
  JSBool found;
  JS::Value temp;
  bool isNull = val.isNullOrUndefined();
  if (!IsConvertibleToDictionary(cx, val)) {
    return ThrowErrorMessage(cx, MSG_NOT_DICTIONARY);
  }

  if (isNull) {
    found = false;
  } else if (!JS_HasProperty(cx, &val.toObject(), "stream", &found)) {
    return false;
  }
  if (found) {
    if (!JS_GetProperty(cx, &val.toObject(), "stream", &temp)) {
      return false;
    }
  }
  if (found) {
    if (!ValueToPrimitive<bool, eDefault>(cx, temp, &mStream)) {
      return false;
    }
  } else {
    mStream = false;
  }
  return true;
}

bool
TextEncodeOptionsWorkers::ToObject(JSContext* cx, JSObject* parentObject, JS::Value *vp)
{
  JSObject* obj = JS_NewObject(cx, nullptr, nullptr, nullptr);
  if (!obj) {
    return false;
  }
  *vp = JS::ObjectValue(*obj);

  {
    // scope for 'temp' and 'currentValue'
    JS::Value temp;
    bool& currentValue = mStream;
    temp = BOOLEAN_TO_JSVAL(currentValue);
    if (!JS_DefineProperty(cx, obj, "stream", temp, nullptr, nullptr, JSPROP_ENUMERATE)) {
      return false;
    }
  }

  return true;
}

bool TextEncodeOptions::initedIds = false;
jsid TextEncodeOptions::stream_id = JSID_VOID;

bool
TextEncodeOptions::InitIds(JSContext* cx)
{
  MOZ_ASSERT(!initedIds);
  if (!InternJSString(cx, stream_id, "stream")) {
    return false;
  }
  initedIds = true;
  return true;
}

bool
TextEncodeOptions::Init(JSContext* cx, JSObject* scopeObj, const JS::Value& val)
{
  // Passing a null JSContext is OK only if we're initing from null,
  // Since in that case we will not have to do any property gets
  MOZ_ASSERT_IF(!cx, val.isNull());
  if (cx && !initedIds && !InitIds(cx)) {
    return false;
  }
  JSBool found;
  JS::Value temp;
  bool isNull = val.isNullOrUndefined();
  if (!IsConvertibleToDictionary(cx, val)) {
    return ThrowErrorMessage(cx, MSG_NOT_DICTIONARY);
  }

  if (isNull) {
    found = false;
  } else if (!JS_HasPropertyById(cx, &val.toObject(), stream_id, &found)) {
    return false;
  }
  if (found) {
    if (!JS_GetPropertyById(cx, &val.toObject(), stream_id, &temp)) {
      return false;
    }
  }
  if (found) {
    if (!ValueToPrimitive<bool, eDefault>(cx, temp, &mStream)) {
      return false;
    }
  } else {
    mStream = false;
  }
  return true;
}

bool
TextEncodeOptions::ToObject(JSContext* cx, JSObject* parentObject, JS::Value *vp)
{
  if (!initedIds && !InitIds(cx)) {
    return false;
  }
  JSObject* obj = JS_NewObject(cx, nullptr, nullptr, nullptr);
  if (!obj) {
    return false;
  }
  *vp = JS::ObjectValue(*obj);

  {
    // scope for 'temp' and 'currentValue'
    JS::Value temp;
    bool& currentValue = mStream;
    temp = BOOLEAN_TO_JSVAL(currentValue);
    if (!JS_DefinePropertyById(cx, obj, stream_id, temp, nullptr, nullptr, JSPROP_ENUMERATE)) {
      return false;
    }
  }

  return true;
}

namespace TextEncoderBinding {

static bool
get_encoding(JSContext* cx, JSHandleObject obj, mozilla::dom::TextEncoder* self, JS::Value* vp)
{
  nsString result;
  self->GetEncoding(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo encoding_getterinfo = {
  (JSJitPropertyOp)get_encoding,
  prototypes::id::TextEncoder,
  PrototypeTraits<prototypes::id::TextEncoder>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  true,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

static bool
encode(JSContext* cx, JSHandleObject obj, mozilla::dom::TextEncoder* self, unsigned argc, JS::Value* vp)
{

  JS::Value* argv = JS_ARGV(cx, vp);

  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (0 < argc) {
    if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
      return false;
    }
  } else {
    static const PRUnichar data[] = { 0 };
    arg0_holder.SetData(data, ArrayLength(data) - 1);
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  const TextEncodeOptions arg1;
  if (!const_cast<TextEncodeOptions&>(arg1).Init(cx, obj, (1 < argc) ? argv[1] : JSVAL_NULL)) {
    return false;
  }
  ErrorResult rv;
  JSObject* result;
  result = self->Encode(cx, arg0, arg1, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "TextEncoder", "encode");
  }
  *vp = JS::ObjectValue(*result);
  if (!MaybeWrapValue(cx, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo encode_methodinfo = {
  (JSJitPropertyOp)encode,
  prototypes::id::TextEncoder,
  PrototypeTraits<prototypes::id::TextEncoder>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericMethod(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::TextEncoder* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::TextEncoder, mozilla::dom::TextEncoder>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "TextEncoder");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Method);
  JSJitMethodOp method = (JSJitMethodOp)info->op;
  return method(cx, obj, self, argc, vp);
}

static JSBool
genericGetter(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::TextEncoder* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::TextEncoder, mozilla::dom::TextEncoder>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "TextEncoder");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Getter);
  JSJitPropertyOp getter = info->op;
  return getter(cx, obj, self, vp);
}

static JSBool
_addProperty(JSContext* cx, JSHandleObject obj, JSHandleId id, JSMutableHandleValue vp)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::TextEncoder>::value), "Must be an nsISupports class");
  mozilla::dom::TextEncoder* self = UnwrapDOMObject<mozilla::dom::TextEncoder>(obj);
  nsContentUtils::PreserveWrapper(reinterpret_cast<nsISupports*>(self), self);
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::TextEncoder>::value), "Must be an nsISupports class");
  mozilla::dom::TextEncoder* self = UnwrapDOMObject<mozilla::dom::TextEncoder>(obj);
  if (self) {
    ClearWrapper(self, self);
    XPCJSRuntime *rt = nsXPConnect::GetRuntimeInstance();
    if (rt) {
      rt->DeferredRelease(reinterpret_cast<nsISupports*>(self));
    } else {
      NS_RELEASE(self);
    }
  }
}

static JSFunctionSpec sMethods_specs[] = {
  JS_FNINFO("encode", genericMethod, &encode_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FS_END
};

static Prefable<JSFunctionSpec> sMethods[] = {
  { true, &sMethods_specs[0] },
  { false, NULL }
};

static jsid sMethods_ids[2] = { JSID_VOID };

static JSFunctionSpec sChromeMethods_specs[] = {
  JS_FNINFO("QueryInterface", QueryInterface, nullptr, 1, 0),
  JS_FS_END
};

static Prefable<JSFunctionSpec> sChromeMethods[] = {
  { true, &sChromeMethods_specs[0] },
  { false, NULL }
};

static jsid sChromeMethods_ids[2] = { JSID_VOID };

static JSPropertySpec sAttributes_specs[] = {
  { "encoding", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &encoding_getterinfo }, JSOP_NULLWRAPPER},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};

static jsid sAttributes_ids[2] = { JSID_VOID };


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sMethods, sMethods_ids, sMethods_specs,
  sAttributes, sAttributes_ids, sAttributes_specs,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr
};

static const NativeProperties sChromeOnlyNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sChromeMethods, sChromeMethods_ids, sChromeMethods_specs,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr
};
const NativePropertyHooks sNativePropertyHooks = {
  nullptr,
  nullptr,
  { &sNativeProperties, &sChromeOnlyNativeProperties },
  prototypes::id::TextEncoder,
  constructors::id::TextEncoder,
  NULL
};

static JSBool
_constructor(JSContext* cx, unsigned argc, JS::Value* vp)
{

  JSObject* obj = JS_GetGlobalForObject(cx, JSVAL_TO_OBJECT(JS_CALLEE(cx, vp)));

  nsISupports* global;
  xpc_qsSelfRef globalRef;
  {
    nsresult rv;
    JS::Value val = OBJECT_TO_JSVAL(obj);
    rv = xpc_qsUnwrapArg<nsISupports>(cx, val, &global, &globalRef.ptr, &val);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_GLOBAL_NOT_NATIVE);
    }
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (0 < argc) {
    if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
      return false;
    }
  } else {
    static const PRUnichar data[] = { 'u', 't', 'f', '-', '8', 0 };
    arg0_holder.SetData(data, ArrayLength(data) - 1);
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  nsRefPtr<mozilla::dom::TextEncoder> result;
  result = mozilla::dom::TextEncoder::Constructor(global, arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "TextEncoder", "constructor");
  }
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}

JSNativeHolder _constructor_holder = {
  _constructor,
  &sNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "TextEncoderPrototype",
    JSCLASS_IS_DOMIFACEANDPROTOJSCLASS | JSCLASS_HAS_RESERVED_SLOTS(2),
    JS_PropertyStub,       /* addProperty */
    JS_PropertyStub,       /* delProperty */
    JS_PropertyStub,       /* getProperty */
    JS_StrictPropertyStub, /* setProperty */
    JS_EnumerateStub,
    JS_ResolveStub,
    JS_ConvertStub,
    nullptr,               /* finalize */
    nullptr,               /* checkAccess */
    nullptr,               /* call */
    nullptr,               /* hasInstance */
    nullptr,               /* construct */
    nullptr,               /* trace */
    JSCLASS_NO_INTERNAL_MEMBERS
  },
  eInterfacePrototype,
  &sNativePropertyHooks
};

void
CreateInterfaceObjects(JSContext* aCx, JSObject* aGlobal, JSObject** protoAndIfaceArray)
{
  JSObject* parentProto = JS_GetObjectPrototype(aCx, aGlobal);
  if (!parentProto) {
    return;
  }


  if (sChromeMethods_ids[0] == JSID_VOID &&
      (!InitIds(aCx, sChromeMethods, sChromeMethods_ids) ||
       !InitIds(aCx, sMethods, sMethods_ids) ||
       !InitIds(aCx, sAttributes, sAttributes_ids))) {
    sChromeMethods_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::TextEncoder],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::TextEncoder],
                              &Class.mClass,
                              &sNativeProperties,
                              xpc::AccessCheck::isChrome(aGlobal) ? &sChromeOnlyNativeProperties : nullptr,
                              "TextEncoder");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}


DOMJSClass Class = {
  { "TextEncoder",
    JSCLASS_IS_DOMJSCLASS | JSCLASS_HAS_RESERVED_SLOTS(3),
    _addProperty, /* addProperty */
    JS_PropertyStub,       /* delProperty */
    JS_PropertyStub,       /* getProperty */
    JS_StrictPropertyStub, /* setProperty */
    JS_EnumerateStub,
    JS_ResolveStub,
    JS_ConvertStub,
    _finalize, /* finalize */
    NULL,                  /* checkAccess */
    NULL,                  /* call */
    NULL,                  /* hasInstance */
    NULL,                  /* construct */
    NULL, /* trace */
    JSCLASS_NO_INTERNAL_MEMBERS
  },
  {
    { prototypes::id::TextEncoder, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    true,
    &sNativePropertyHooks,
    GetParentObject<mozilla::dom::TextEncoder>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::TextEncoder* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<mozilla::dom::TextEncoder*>(aObject) ==
             reinterpret_cast<mozilla::dom::TextEncoder*>(aObject));

  *aTriedToWrap = true;

  JSObject* parent = WrapNativeParent(aCx, aScope, aObject->GetParentObject());
  if (!parent) {
    return NULL;
  }

  // That might have ended up wrapping us already, due to the wonders
  // of XBL.  Check for that, and bail out as needed.  Scope so we don't
  // collide with the "obj" we declare in CreateBindingJSObject.
  {
    JSObject* obj = aCache->GetWrapper();
    if (obj) {
      return obj;
    }
  }

  JSAutoCompartment ac(aCx, parent);
  JSObject* global = JS_GetGlobalForObject(aCx, parent);

  JSObject* proto = GetProtoObject(aCx, global);
  if (!proto) {
    return NULL;
  }

  JSObject* obj = JS_NewObject(aCx, &Class.mBase, proto, parent);
  if (!obj) {
    return NULL;
  }

  js::SetReservedSlot(obj, DOM_OBJECT_SLOT, PRIVATE_TO_JSVAL(aObject));
  NS_ADDREF(aObject);


  aCache->SetWrapper(obj);

  return obj;
}

} // namespace TextEncoderBinding



namespace TextEncoderBinding_workers {

static bool
get_encoding(JSContext* cx, JSHandleObject obj, mozilla::dom::workers::TextEncoder* self, JS::Value* vp)
{
  nsString result;
  self->GetEncoding(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo encoding_getterinfo = {
  (JSJitPropertyOp)get_encoding,
  prototypes::id::TextEncoder_workers,
  PrototypeTraits<prototypes::id::TextEncoder_workers>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  true,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

static bool
encode(JSContext* cx, JSHandleObject obj, mozilla::dom::workers::TextEncoder* self, unsigned argc, JS::Value* vp)
{

  JS::Value* argv = JS_ARGV(cx, vp);

  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (0 < argc) {
    if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
      return false;
    }
  } else {
    static const PRUnichar data[] = { 0 };
    arg0_holder.SetData(data, ArrayLength(data) - 1);
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  const TextEncodeOptionsWorkers arg1;
  if (!const_cast<TextEncodeOptionsWorkers&>(arg1).Init(cx, obj, (1 < argc) ? argv[1] : JSVAL_NULL)) {
    return false;
  }
  ErrorResult rv;
  JSObject* result;
  result = self->Encode(cx, arg0, arg1, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "TextEncoder", "encode");
  }
  *vp = JS::ObjectValue(*result);
  if (!MaybeWrapValue(cx, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo encode_methodinfo = {
  (JSJitPropertyOp)encode,
  prototypes::id::TextEncoder_workers,
  PrototypeTraits<prototypes::id::TextEncoder_workers>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericMethod(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::workers::TextEncoder* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::TextEncoder_workers, mozilla::dom::workers::TextEncoder>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "TextEncoder_workers");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Method);
  JSJitMethodOp method = (JSJitMethodOp)info->op;
  return method(cx, obj, self, argc, vp);
}

static JSBool
genericGetter(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::workers::TextEncoder* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::TextEncoder_workers, mozilla::dom::workers::TextEncoder>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "TextEncoder_workers");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Getter);
  JSJitPropertyOp getter = info->op;
  return getter(cx, obj, self, vp);
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{

  mozilla::dom::workers::TextEncoder* self = UnwrapDOMObject<mozilla::dom::workers::TextEncoder>(obj);
  if (self) {
    self->_finalize(fop);
  }
}

static void
_trace(JSTracer* trc, JSObject* obj)
{

  mozilla::dom::workers::TextEncoder* self = UnwrapDOMObject<mozilla::dom::workers::TextEncoder>(obj);
  if (self) {
    self->_trace(trc);
  }
}

static JSFunctionSpec sMethods_specs[] = {
  JS_FNINFO("encode", genericMethod, &encode_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FS_END
};

static Prefable<JSFunctionSpec> sMethods[] = {
  { true, &sMethods_specs[0] },
  { false, NULL }
};

static JSPropertySpec sAttributes_specs[] = {
  { "encoding", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &encoding_getterinfo }, JSOP_NULLWRAPPER},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sMethods, nullptr, sMethods_specs,
  sAttributes, nullptr, sAttributes_specs,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr
};
static JSBool
_constructor(JSContext* cx, unsigned argc, JS::Value* vp)
{

  JSObject* obj = JS_GetGlobalForObject(cx, JSVAL_TO_OBJECT(JS_CALLEE(cx, vp)));

  JS::Value* argv = JS_ARGV(cx, vp);

  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (0 < argc) {
    if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
      return false;
    }
  } else {
    static const PRUnichar data[] = { 'u', 't', 'f', '-', '8', 0 };
    arg0_holder.SetData(data, ArrayLength(data) - 1);
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  mozilla::dom::workers::TextEncoder* result;
  result = mozilla::dom::workers::TextEncoder::Constructor(cx, obj, arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "TextEncoder", "constructor");
  }
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}

JSNativeHolder _constructor_holder = {
  _constructor,
  &sWorkerNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "TextEncoderPrototype",
    JSCLASS_IS_DOMIFACEANDPROTOJSCLASS | JSCLASS_HAS_RESERVED_SLOTS(2),
    JS_PropertyStub,       /* addProperty */
    JS_PropertyStub,       /* delProperty */
    JS_PropertyStub,       /* getProperty */
    JS_StrictPropertyStub, /* setProperty */
    JS_EnumerateStub,
    JS_ResolveStub,
    JS_ConvertStub,
    nullptr,               /* finalize */
    nullptr,               /* checkAccess */
    nullptr,               /* call */
    nullptr,               /* hasInstance */
    nullptr,               /* construct */
    nullptr,               /* trace */
    JSCLASS_NO_INTERNAL_MEMBERS
  },
  eInterfacePrototype,
  &sWorkerNativePropertyHooks
};

void
CreateInterfaceObjects(JSContext* aCx, JSObject* aGlobal, JSObject** protoAndIfaceArray)
{
  JSObject* parentProto = JS_GetObjectPrototype(aCx, aGlobal);
  if (!parentProto) {
    return;
  }


  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::TextEncoder_workers],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::TextEncoder_workers],
                              &Class.mClass,
                              &sNativeProperties,
                              nullptr,
                              "TextEncoder");
}


DOMJSClass Class = {
  { "TextEncoder",
    JSCLASS_IS_DOMJSCLASS | JSCLASS_HAS_RESERVED_SLOTS(3),
    JS_PropertyStub, /* addProperty */
    JS_PropertyStub,       /* delProperty */
    JS_PropertyStub,       /* getProperty */
    JS_StrictPropertyStub, /* setProperty */
    JS_EnumerateStub,
    JS_ResolveStub,
    JS_ConvertStub,
    _finalize, /* finalize */
    NULL,                  /* checkAccess */
    NULL,                  /* call */
    NULL,                  /* hasInstance */
    NULL,                  /* construct */
    _trace, /* trace */
    JSCLASS_NO_INTERNAL_MEMBERS
  },
  {
    { prototypes::id::TextEncoder_workers, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    false,
    &sWorkerNativePropertyHooks,
    GetParentObject<mozilla::dom::workers::TextEncoder>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::workers::TextEncoder* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  *aTriedToWrap = true;
  return aObject->GetJSObject();
}

} // namespace TextEncoderBinding_workers



} // namespace dom
} // namespace mozilla