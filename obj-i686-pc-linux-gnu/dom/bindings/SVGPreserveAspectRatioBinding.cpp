/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "PrimitiveConversions.h"
#include "SVGPreserveAspectRatio.h"
#include "SVGPreserveAspectRatioBinding.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace SVGPreserveAspectRatioBinding {

static bool
get_align(JSContext* cx, JSHandleObject obj, mozilla::dom::DOMSVGPreserveAspectRatio* self, JS::Value* vp)
{
  uint16_t result;
  result = self->Align();
  *vp = INT_TO_JSVAL(int32_t(result));
  return true;
}

static bool
set_align(JSContext* cx, JSHandleObject obj, mozilla::dom::DOMSVGPreserveAspectRatio* self, JS::Value* argv)
{
  uint16_t arg0;
  if (!ValueToPrimitive<uint16_t, eDefault>(cx, argv[0], &arg0)) {
    return false;
  }
  ErrorResult rv;
  self->SetAlign(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "SVGPreserveAspectRatio", "align");
  }

  return true;
}


const JSJitInfo align_getterinfo = {
  (JSJitPropertyOp)get_align,
  prototypes::id::SVGPreserveAspectRatio,
  PrototypeTraits<prototypes::id::SVGPreserveAspectRatio>::Depth,
  JSJitInfo::Getter,
  true,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_INT32   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo align_setterinfo = {
  (JSJitPropertyOp)set_align,
  prototypes::id::SVGPreserveAspectRatio,
  PrototypeTraits<prototypes::id::SVGPreserveAspectRatio>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_meetOrSlice(JSContext* cx, JSHandleObject obj, mozilla::dom::DOMSVGPreserveAspectRatio* self, JS::Value* vp)
{
  uint16_t result;
  result = self->MeetOrSlice();
  *vp = INT_TO_JSVAL(int32_t(result));
  return true;
}

static bool
set_meetOrSlice(JSContext* cx, JSHandleObject obj, mozilla::dom::DOMSVGPreserveAspectRatio* self, JS::Value* argv)
{
  uint16_t arg0;
  if (!ValueToPrimitive<uint16_t, eDefault>(cx, argv[0], &arg0)) {
    return false;
  }
  ErrorResult rv;
  self->SetMeetOrSlice(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "SVGPreserveAspectRatio", "meetOrSlice");
  }

  return true;
}


const JSJitInfo meetOrSlice_getterinfo = {
  (JSJitPropertyOp)get_meetOrSlice,
  prototypes::id::SVGPreserveAspectRatio,
  PrototypeTraits<prototypes::id::SVGPreserveAspectRatio>::Depth,
  JSJitInfo::Getter,
  true,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_INT32   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo meetOrSlice_setterinfo = {
  (JSJitPropertyOp)set_meetOrSlice,
  prototypes::id::SVGPreserveAspectRatio,
  PrototypeTraits<prototypes::id::SVGPreserveAspectRatio>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericGetter(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::DOMSVGPreserveAspectRatio* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::SVGPreserveAspectRatio, mozilla::dom::DOMSVGPreserveAspectRatio>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "SVGPreserveAspectRatio");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Getter);
  JSJitPropertyOp getter = info->op;
  return getter(cx, obj, self, vp);
}

static JSBool
genericSetter(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::DOMSVGPreserveAspectRatio* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::SVGPreserveAspectRatio, mozilla::dom::DOMSVGPreserveAspectRatio>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "SVGPreserveAspectRatio");
    }
  }
  if (argc == 0) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "SVGPreserveAspectRatio attribute setter");
  }
  JS::Value* argv = JS_ARGV(cx, vp);
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Setter);
  JSJitPropertyOp setter = info->op;
  if (!setter(cx, obj, self, argv)) {
    return false;
  }
  *vp = JSVAL_VOID;
  return true;
}

static JSBool
_addProperty(JSContext* cx, JSHandleObject obj, JSHandleId id, JSMutableHandleValue vp)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::DOMSVGPreserveAspectRatio>::value), "Must be an nsISupports class");
  mozilla::dom::DOMSVGPreserveAspectRatio* self = UnwrapDOMObject<mozilla::dom::DOMSVGPreserveAspectRatio>(obj);
  nsContentUtils::PreserveWrapper(reinterpret_cast<nsISupports*>(self), self);
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::DOMSVGPreserveAspectRatio>::value), "Must be an nsISupports class");
  mozilla::dom::DOMSVGPreserveAspectRatio* self = UnwrapDOMObject<mozilla::dom::DOMSVGPreserveAspectRatio>(obj);
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
  { "align", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &align_getterinfo }, { (JSStrictPropertyOp)genericSetter, &align_setterinfo }},
  { "meetOrSlice", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &meetOrSlice_getterinfo }, { (JSStrictPropertyOp)genericSetter, &meetOrSlice_setterinfo }},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};

static jsid sAttributes_ids[3] = { JSID_VOID };

static ConstantSpec sConstants_specs[] = {
  { "SVG_PRESERVEASPECTRATIO_UNKNOWN", INT_TO_JSVAL(0) },
  { "SVG_PRESERVEASPECTRATIO_NONE", INT_TO_JSVAL(1) },
  { "SVG_PRESERVEASPECTRATIO_XMINYMIN", INT_TO_JSVAL(2) },
  { "SVG_PRESERVEASPECTRATIO_XMIDYMIN", INT_TO_JSVAL(3) },
  { "SVG_PRESERVEASPECTRATIO_XMAXYMIN", INT_TO_JSVAL(4) },
  { "SVG_PRESERVEASPECTRATIO_XMINYMID", INT_TO_JSVAL(5) },
  { "SVG_PRESERVEASPECTRATIO_XMIDYMID", INT_TO_JSVAL(6) },
  { "SVG_PRESERVEASPECTRATIO_XMAXYMID", INT_TO_JSVAL(7) },
  { "SVG_PRESERVEASPECTRATIO_XMINYMAX", INT_TO_JSVAL(8) },
  { "SVG_PRESERVEASPECTRATIO_XMIDYMAX", INT_TO_JSVAL(9) },
  { "SVG_PRESERVEASPECTRATIO_XMAXYMAX", INT_TO_JSVAL(10) },
  { "SVG_MEETORSLICE_UNKNOWN", INT_TO_JSVAL(0) },
  { "SVG_MEETORSLICE_MEET", INT_TO_JSVAL(1) },
  { "SVG_MEETORSLICE_SLICE", INT_TO_JSVAL(2) },
  { 0, JSVAL_VOID }
};

static Prefable<ConstantSpec> sConstants[] = {
  { true, &sConstants_specs[0] },
  { false, NULL }
};

static jsid sConstants_ids[15] = { JSID_VOID };


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sAttributes, sAttributes_ids, sAttributes_specs,
  nullptr, nullptr, nullptr,
  sConstants, sConstants_ids, sConstants_specs
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
  prototypes::id::SVGPreserveAspectRatio,
  constructors::id::SVGPreserveAspectRatio,
  NULL
};

JSNativeHolder _constructor_holder = {
  ThrowingConstructor,
  &sNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "SVGPreserveAspectRatioPrototype",
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
       !InitIds(aCx, sAttributes, sAttributes_ids) ||
       !InitIds(aCx, sConstants, sConstants_ids))) {
    sChromeMethods_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::SVGPreserveAspectRatio],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::SVGPreserveAspectRatio],
                              &Class.mClass,
                              &sNativeProperties,
                              xpc::AccessCheck::isChrome(aGlobal) ? &sChromeOnlyNativeProperties : nullptr,
                              "SVGPreserveAspectRatio");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}


DOMJSClass Class = {
  { "SVGPreserveAspectRatio",
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
    { prototypes::id::SVGPreserveAspectRatio, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    true,
    &sNativePropertyHooks,
    GetParentObject<mozilla::dom::DOMSVGPreserveAspectRatio>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::DOMSVGPreserveAspectRatio* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<mozilla::dom::DOMSVGPreserveAspectRatio*>(aObject) ==
             reinterpret_cast<mozilla::dom::DOMSVGPreserveAspectRatio*>(aObject));

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

} // namespace SVGPreserveAspectRatioBinding



} // namespace dom
} // namespace mozilla
