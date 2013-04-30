/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "DOMSVGPointList.h"
#include "ElementBinding.h"
#include "EventTargetBinding.h"
#include "NodeBinding.h"
#include "PrimitiveConversions.h"
#include "SVGElementBinding.h"
#include "SVGGraphicsElementBinding.h"
#include "SVGLocatableElementBinding.h"
#include "SVGPointListBinding.h"
#include "SVGPolylineElementBinding.h"
#include "SVGTransformableElementBinding.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/SVGPolylineElement.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace SVGPolylineElementBinding {

static bool
get_points(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGPolylineElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGPointList> result;
  result = self->Points();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo points_getterinfo = {
  (JSJitPropertyOp)get_points,
  prototypes::id::SVGPolylineElement,
  PrototypeTraits<prototypes::id::SVGPolylineElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  true,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_animatedPoints(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGPolylineElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGPointList> result;
  result = self->AnimatedPoints();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo animatedPoints_getterinfo = {
  (JSJitPropertyOp)get_animatedPoints,
  prototypes::id::SVGPolylineElement,
  PrototypeTraits<prototypes::id::SVGPolylineElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  true,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericGetter(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::SVGPolylineElement* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::SVGPolylineElement, mozilla::dom::SVGPolylineElement>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "SVGPolylineElement");
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
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::SVGPolylineElement>::value), "Must be an nsISupports class");
  mozilla::dom::SVGPolylineElement* self = UnwrapDOMObject<mozilla::dom::SVGPolylineElement>(obj);
  nsContentUtils::PreserveWrapper(reinterpret_cast<nsISupports*>(self), self);
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::SVGPolylineElement>::value), "Must be an nsISupports class");
  mozilla::dom::SVGPolylineElement* self = UnwrapDOMObject<mozilla::dom::SVGPolylineElement>(obj);
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

static JSPropertySpec sAttributes_specs[] = {
  { "points", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &points_getterinfo }, JSOP_NULLWRAPPER},
  { "animatedPoints", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &animatedPoints_getterinfo }, JSOP_NULLWRAPPER},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};

static jsid sAttributes_ids[3] = { JSID_VOID };


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sAttributes, sAttributes_ids, sAttributes_specs,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr
};
const NativePropertyHooks sNativePropertyHooks = {
  nullptr,
  nullptr,
  { &sNativeProperties, nullptr },
  prototypes::id::SVGPolylineElement,
  constructors::id::SVGPolylineElement,
  &SVGGraphicsElementBinding::sNativePropertyHooks
};

JSNativeHolder _constructor_holder = {
  ThrowingConstructor,
  &sNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "SVGPolylineElementPrototype",
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
  JSObject* parentProto = SVGGraphicsElementBinding::GetProtoObject(aCx, aGlobal);
  if (!parentProto) {
    return;
  }


  if (sAttributes_ids[0] == JSID_VOID &&
      !InitIds(aCx, sAttributes, sAttributes_ids)) {
    sAttributes_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::SVGPolylineElement],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::SVGPolylineElement],
                              &Class.mClass,
                              &sNativeProperties,
                              nullptr,
                              "SVGPolylineElement");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}


DOMJSClass Class = {
  { "SVGPolylineElement",
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
    { prototypes::id::EventTarget, prototypes::id::Node, prototypes::id::Element, prototypes::id::SVGElement, prototypes::id::SVGLocatableElement, prototypes::id::SVGTransformableElement, prototypes::id::SVGGraphicsElement, prototypes::id::SVGPolylineElement, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    true,
    &sNativePropertyHooks,
    GetParentObject<mozilla::dom::SVGPolylineElement>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::SVGPolylineElement* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<mozilla::dom::SVGPolylineElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::SVGPolylineElement*>(aObject));
  MOZ_ASSERT(static_cast<mozilla::dom::SVGGraphicsElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::SVGGraphicsElement*>(aObject));
  MOZ_ASSERT(static_cast<mozilla::dom::SVGTransformableElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::SVGTransformableElement*>(aObject));
  MOZ_ASSERT(static_cast<mozilla::dom::SVGLocatableElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::SVGLocatableElement*>(aObject));
  MOZ_ASSERT(static_cast<nsSVGElement*>(aObject) ==
             reinterpret_cast<nsSVGElement*>(aObject));
  MOZ_ASSERT(static_cast<mozilla::dom::Element*>(aObject) ==
             reinterpret_cast<mozilla::dom::Element*>(aObject));
  MOZ_ASSERT(static_cast<nsINode*>(aObject) ==
             reinterpret_cast<nsINode*>(aObject));
  MOZ_ASSERT(static_cast<mozilla::dom::EventTarget*>(aObject) ==
             reinterpret_cast<mozilla::dom::EventTarget*>(aObject));

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

} // namespace SVGPolylineElementBinding



} // namespace dom
} // namespace mozilla