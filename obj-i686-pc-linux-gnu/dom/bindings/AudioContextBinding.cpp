/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "AudioBufferBinding.h"
#include "AudioBufferSourceNodeBinding.h"
#include "AudioContext.h"
#include "AudioContextBinding.h"
#include "AudioDestinationNodeBinding.h"
#include "AudioListenerBinding.h"
#include "BiquadFilterNodeBinding.h"
#include "DelayNodeBinding.h"
#include "DynamicsCompressorNodeBinding.h"
#include "GainNodeBinding.h"
#include "PannerNodeBinding.h"
#include "PrimitiveConversions.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/FloatingPoint.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/AudioBuffer.h"
#include "mozilla/dom/AudioBufferSourceNode.h"
#include "mozilla/dom/AudioDestinationNode.h"
#include "mozilla/dom/AudioListener.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/BiquadFilterNode.h"
#include "mozilla/dom/DelayNode.h"
#include "mozilla/dom/DynamicsCompressorNode.h"
#include "mozilla/dom/GainNode.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/PannerNode.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace mozAudioContextBinding {

static bool
get_destination(JSContext* cx, JSHandleObject obj, AudioContext* self, JS::Value* vp)
{
  mozilla::dom::AudioDestinationNode* result;
  result = self->Destination();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo destination_getterinfo = {
  (JSJitPropertyOp)get_destination,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_sampleRate(JSContext* cx, JSHandleObject obj, AudioContext* self, JS::Value* vp)
{
  float result;
  result = self->SampleRate();
  *vp = JS_NumberValue(double(result));
  return true;
}


const JSJitInfo sampleRate_getterinfo = {
  (JSJitPropertyOp)get_sampleRate,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Getter,
  true,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_DOUBLE   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_listener(JSContext* cx, JSHandleObject obj, AudioContext* self, JS::Value* vp)
{
  mozilla::dom::AudioListener* result;
  result = self->Listener();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo listener_getterinfo = {
  (JSJitPropertyOp)get_listener,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createBuffer(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{

  if (argc < 3) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "mozAudioContext.createBuffer");
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  uint32_t arg0;
  if (!ValueToPrimitive<uint32_t, eDefault>(cx, argv[0], &arg0)) {
    return false;
  }
  uint32_t arg1;
  if (!ValueToPrimitive<uint32_t, eDefault>(cx, argv[1], &arg1)) {
    return false;
  }
  float arg2;
  if (!ValueToPrimitive<float, eDefault>(cx, argv[2], &arg2)) {
    return false;
  } else if (!MOZ_DOUBLE_IS_FINITE(arg2)) {
    // Note: MOZ_DOUBLE_IS_FINITE will do the right thing
    //       when passed a non-finite float too.
    ThrowErrorMessage(cx, MSG_NOT_FINITE);
    return false;
  }
  ErrorResult rv;
  nsRefPtr<mozilla::dom::AudioBuffer> result;
  result = self->CreateBuffer(cx, arg0, arg1, arg2, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "mozAudioContext", "createBuffer");
  }
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createBuffer_methodinfo = {
  (JSJitPropertyOp)createBuffer,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createBufferSource(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{
  nsRefPtr<mozilla::dom::AudioBufferSourceNode> result;
  result = self->CreateBufferSource();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createBufferSource_methodinfo = {
  (JSJitPropertyOp)createBufferSource,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createGain(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{
  nsRefPtr<mozilla::dom::GainNode> result;
  result = self->CreateGain();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createGain_methodinfo = {
  (JSJitPropertyOp)createGain,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createDelay(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{

  JS::Value* argv = JS_ARGV(cx, vp);

  double arg0;
  if (0 < argc) {
    if (!ValueToPrimitive<double, eDefault>(cx, argv[0], &arg0)) {
      return false;
    } else if (!MOZ_DOUBLE_IS_FINITE(arg0)) {
      // Note: MOZ_DOUBLE_IS_FINITE will do the right thing
      //       when passed a non-finite float too.
      ThrowErrorMessage(cx, MSG_NOT_FINITE);
      return false;
    }
  } else {
    arg0 = 1.0;
  }
  ErrorResult rv;
  nsRefPtr<mozilla::dom::DelayNode> result;
  result = self->CreateDelay(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "mozAudioContext", "createDelay");
  }
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createDelay_methodinfo = {
  (JSJitPropertyOp)createDelay,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createBiquadFilter(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{
  nsRefPtr<mozilla::dom::BiquadFilterNode> result;
  result = self->CreateBiquadFilter();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createBiquadFilter_methodinfo = {
  (JSJitPropertyOp)createBiquadFilter,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createPanner(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{
  nsRefPtr<mozilla::dom::PannerNode> result;
  result = self->CreatePanner();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createPanner_methodinfo = {
  (JSJitPropertyOp)createPanner,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
createDynamicsCompressor(JSContext* cx, JSHandleObject obj, AudioContext* self, unsigned argc, JS::Value* vp)
{
  nsRefPtr<mozilla::dom::DynamicsCompressorNode> result;
  result = self->CreateDynamicsCompressor();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo createDynamicsCompressor_methodinfo = {
  (JSJitPropertyOp)createDynamicsCompressor,
  prototypes::id::mozAudioContext,
  PrototypeTraits<prototypes::id::mozAudioContext>::Depth,
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

  AudioContext* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::mozAudioContext, AudioContext>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "mozAudioContext");
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

  AudioContext* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::mozAudioContext, AudioContext>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "mozAudioContext");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Getter);
  JSJitPropertyOp getter = info->op;
  return getter(cx, obj, self, vp);
}

nsTArray<nsRefPtr<AudioContext> >* sDeferredFinalizePointers;

static void*
GetDeferredFinalizePointers()
{
  nsTArray<nsRefPtr<AudioContext> >* pointers = sDeferredFinalizePointers;
  sDeferredFinalizePointers = nullptr;
  return pointers;
}

static bool
DeferredFinalize(uint32_t slice, void* data)
{
  MOZ_ASSERT(slice > 0, "nonsensical/useless call with slice == 0");
  nsTArray<nsRefPtr<AudioContext> >* pointers = static_cast<nsTArray<nsRefPtr<AudioContext> >*>(data);
  uint32_t oldLen = pointers->Length();
  slice = NS_MIN(oldLen, slice);
  uint32_t newLen = oldLen - slice;
  pointers->RemoveElementsAt(newLen, slice);
  if (newLen == 0) {
    delete pointers;
    return true;
  }
  return false;
}

static JSBool
_addProperty(JSContext* cx, JSHandleObject obj, JSHandleId id, JSMutableHandleValue vp)
{

  AudioContext* self = UnwrapDOMObject<AudioContext>(obj);
  nsContentUtils::PreserveWrapper(self, self, NS_CYCLE_COLLECTION_PARTICIPANT(AudioContext));
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{

  AudioContext* self = UnwrapDOMObject<AudioContext>(obj);
  if (self) {
    ClearWrapper(self, self);
    static bool registered = false;
    if (!registered) {
      XPCJSRuntime *rt = nsXPConnect::GetRuntimeInstance();
      if (!rt) {
        nsRefPtr<AudioContext> dying;
        Take(dying, self);
        return;
      }
      rt->RegisterDeferredFinalize(GetDeferredFinalizePointers, DeferredFinalize);
      registered = true;
    }
    if (!sDeferredFinalizePointers) {
      sDeferredFinalizePointers = new nsAutoTArray<nsRefPtr<AudioContext>, 16>();
    }
    nsRefPtr<AudioContext>* defer = sDeferredFinalizePointers->AppendElement();
    if (!defer) {
      nsRefPtr<AudioContext> dying;
      Take(dying, self);
      return;
    }
    Take(*defer, self);
  }
}

static JSFunctionSpec sMethods_specs[] = {
  JS_FNINFO("createBuffer", genericMethod, &createBuffer_methodinfo, 3, JSPROP_ENUMERATE),
  JS_FNINFO("createBufferSource", genericMethod, &createBufferSource_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FNINFO("createGain", genericMethod, &createGain_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FNINFO("createDelay", genericMethod, &createDelay_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FNINFO("createBiquadFilter", genericMethod, &createBiquadFilter_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FNINFO("createPanner", genericMethod, &createPanner_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FNINFO("createDynamicsCompressor", genericMethod, &createDynamicsCompressor_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FS_END
};

static Prefable<JSFunctionSpec> sMethods[] = {
  { true, &sMethods_specs[0] },
  { false, NULL }
};

static jsid sMethods_ids[8] = { JSID_VOID };

static JSPropertySpec sAttributes_specs[] = {
  { "destination", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &destination_getterinfo }, JSOP_NULLWRAPPER},
  { "sampleRate", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &sampleRate_getterinfo }, JSOP_NULLWRAPPER},
  { "listener", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &listener_getterinfo }, JSOP_NULLWRAPPER},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};

static jsid sAttributes_ids[4] = { JSID_VOID };


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sMethods, sMethods_ids, sMethods_specs,
  sAttributes, sAttributes_ids, sAttributes_specs,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr
};
const NativePropertyHooks sNativePropertyHooks = {
  nullptr,
  nullptr,
  { &sNativeProperties, nullptr },
  prototypes::id::mozAudioContext,
  constructors::id::mozAudioContext,
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
  ErrorResult rv;
  nsRefPtr<AudioContext> result;
  result = AudioContext::Constructor(global, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "mozAudioContext", "constructor");
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
    "mozAudioContextPrototype",
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


  if (sMethods_ids[0] == JSID_VOID &&
      (!InitIds(aCx, sMethods, sMethods_ids) ||
       !InitIds(aCx, sAttributes, sAttributes_ids))) {
    sMethods_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::mozAudioContext],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::mozAudioContext],
                              &Class.mClass,
                              &sNativeProperties,
                              nullptr,
                              "mozAudioContext");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}

bool
PrefEnabled()
{
  return AudioContext::PrefEnabled();
}


DOMJSClass Class = {
  { "mozAudioContext",
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
    { prototypes::id::mozAudioContext, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    false,
    &sNativePropertyHooks,
    GetParentObject<AudioContext>::Get,
    GetProtoObject,
    NS_CYCLE_COLLECTION_PARTICIPANT(AudioContext)
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, AudioContext* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<AudioContext*>(aObject) ==
             reinterpret_cast<AudioContext*>(aObject));

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

} // namespace mozAudioContextBinding



} // namespace dom
} // namespace mozilla