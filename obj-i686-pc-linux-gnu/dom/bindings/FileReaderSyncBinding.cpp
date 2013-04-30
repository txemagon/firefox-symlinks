/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "FileReaderSyncBinding.h"
#include "PrimitiveConversions.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "jsapi.h"
#include "jsfriendapi.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/workers/bindings/FileReaderSync.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace FileReaderSyncBinding_workers {

static bool
readAsArrayBuffer(JSContext* cx, JSHandleObject obj, mozilla::dom::workers::FileReaderSync* self, unsigned argc, JS::Value* vp)
{

  if (argc < 1) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "FileReaderSync.readAsArrayBuffer");
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  JSObject* arg0;
  if (argv[0].isObject()) {
    arg0 = &argv[0].toObject();
  } else {
    ThrowErrorMessage(cx, MSG_NOT_OBJECT);
    return false;
  }
  ErrorResult rv;
  JSObject* result;
  result = self->ReadAsArrayBuffer(cx, arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "FileReaderSync", "readAsArrayBuffer");
  }
  *vp = JS::ObjectValue(*result);
  if (!MaybeWrapValue(cx, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo readAsArrayBuffer_methodinfo = {
  (JSJitPropertyOp)readAsArrayBuffer,
  prototypes::id::FileReaderSync_workers,
  PrototypeTraits<prototypes::id::FileReaderSync_workers>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
readAsBinaryString(JSContext* cx, JSHandleObject obj, mozilla::dom::workers::FileReaderSync* self, unsigned argc, JS::Value* vp)
{

  if (argc < 1) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "FileReaderSync.readAsBinaryString");
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  JSObject* arg0;
  if (argv[0].isObject()) {
    arg0 = &argv[0].toObject();
  } else {
    ThrowErrorMessage(cx, MSG_NOT_OBJECT);
    return false;
  }
  ErrorResult rv;
  nsString result;
  self->ReadAsBinaryString(arg0, result, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "FileReaderSync", "readAsBinaryString");
  }
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo readAsBinaryString_methodinfo = {
  (JSJitPropertyOp)readAsBinaryString,
  prototypes::id::FileReaderSync_workers,
  PrototypeTraits<prototypes::id::FileReaderSync_workers>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

static bool
readAsText(JSContext* cx, JSHandleObject obj, mozilla::dom::workers::FileReaderSync* self, unsigned argc, JS::Value* vp)
{

  if (argc < 1) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "FileReaderSync.readAsText");
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  JSObject* arg0;
  if (argv[0].isObject()) {
    arg0 = &argv[0].toObject();
  } else {
    ThrowErrorMessage(cx, MSG_NOT_OBJECT);
    return false;
  }
  FakeDependentString arg1_holder;
  const Optional<nsAString> arg1;
  if (1 < argc) {
    if (!ConvertJSValueToString(cx, argv[1], &argv[1], eStringify, eStringify, arg1_holder)) {
      return false;
    }
    const_cast<Optional<nsAString>&>(arg1) = &arg1_holder;
  }
  ErrorResult rv;
  nsString result;
  self->ReadAsText(arg0, arg1, result, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "FileReaderSync", "readAsText");
  }
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo readAsText_methodinfo = {
  (JSJitPropertyOp)readAsText,
  prototypes::id::FileReaderSync_workers,
  PrototypeTraits<prototypes::id::FileReaderSync_workers>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

static bool
readAsDataURL(JSContext* cx, JSHandleObject obj, mozilla::dom::workers::FileReaderSync* self, unsigned argc, JS::Value* vp)
{

  if (argc < 1) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "FileReaderSync.readAsDataURL");
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  JSObject* arg0;
  if (argv[0].isObject()) {
    arg0 = &argv[0].toObject();
  } else {
    ThrowErrorMessage(cx, MSG_NOT_OBJECT);
    return false;
  }
  ErrorResult rv;
  nsString result;
  self->ReadAsDataURL(arg0, result, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "FileReaderSync", "readAsDataURL");
  }
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}


const JSJitInfo readAsDataURL_methodinfo = {
  (JSJitPropertyOp)readAsDataURL,
  prototypes::id::FileReaderSync_workers,
  PrototypeTraits<prototypes::id::FileReaderSync_workers>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericMethod(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::workers::FileReaderSync* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::FileReaderSync_workers, mozilla::dom::workers::FileReaderSync>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "FileReaderSync_workers");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Method);
  JSJitMethodOp method = (JSJitMethodOp)info->op;
  return method(cx, obj, self, argc, vp);
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{

  mozilla::dom::workers::FileReaderSync* self = UnwrapDOMObject<mozilla::dom::workers::FileReaderSync>(obj);
  if (self) {
    self->_finalize(fop);
  }
}

static void
_trace(JSTracer* trc, JSObject* obj)
{

  mozilla::dom::workers::FileReaderSync* self = UnwrapDOMObject<mozilla::dom::workers::FileReaderSync>(obj);
  if (self) {
    self->_trace(trc);
  }
}

static JSFunctionSpec sMethods_specs[] = {
  JS_FNINFO("readAsArrayBuffer", genericMethod, &readAsArrayBuffer_methodinfo, 1, JSPROP_ENUMERATE),
  JS_FNINFO("readAsBinaryString", genericMethod, &readAsBinaryString_methodinfo, 1, JSPROP_ENUMERATE),
  JS_FNINFO("readAsText", genericMethod, &readAsText_methodinfo, 1, JSPROP_ENUMERATE),
  JS_FNINFO("readAsDataURL", genericMethod, &readAsDataURL_methodinfo, 1, JSPROP_ENUMERATE),
  JS_FS_END
};

static Prefable<JSFunctionSpec> sMethods[] = {
  { true, &sMethods_specs[0] },
  { false, NULL }
};


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sMethods, nullptr, sMethods_specs,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr
};
static JSBool
_constructor(JSContext* cx, unsigned argc, JS::Value* vp)
{

  JSObject* obj = JS_GetGlobalForObject(cx, JSVAL_TO_OBJECT(JS_CALLEE(cx, vp)));
  ErrorResult rv;
  mozilla::dom::workers::FileReaderSync* result;
  result = mozilla::dom::workers::FileReaderSync::Constructor(cx, obj, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<false>(cx, rv, "FileReaderSync", "constructor");
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
    "FileReaderSyncPrototype",
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
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::FileReaderSync_workers],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::FileReaderSync_workers],
                              &Class.mClass,
                              &sNativeProperties,
                              nullptr,
                              "FileReaderSync");
}


DOMJSClass Class = {
  { "FileReaderSync",
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
    { prototypes::id::FileReaderSync_workers, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    false,
    &sWorkerNativePropertyHooks,
    GetParentObject<mozilla::dom::workers::FileReaderSync>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::workers::FileReaderSync* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  *aTriedToWrap = true;
  return aObject->GetJSObject();
}

} // namespace FileReaderSyncBinding_workers



} // namespace dom
} // namespace mozilla