/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "DOMSVGAnimatedLengthList.h"
#include "DOMSVGAnimatedNumberList.h"
#include "ElementBinding.h"
#include "EventTargetBinding.h"
#include "NodeBinding.h"
#include "PrimitiveConversions.h"
#include "SVGAnimatedLengthListBinding.h"
#include "SVGAnimatedNumberListBinding.h"
#include "SVGElementBinding.h"
#include "SVGGraphicsElementBinding.h"
#include "SVGLocatableElementBinding.h"
#include "SVGTextContentElementBinding.h"
#include "SVGTextPositioningElementBinding.h"
#include "SVGTransformableElementBinding.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/SVGTextPositioningElement.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace SVGTextPositioningElementBinding {

static bool
get_x(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGTextPositioningElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGAnimatedLengthList> result;
  result = self->X();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo x_getterinfo = {
  (JSJitPropertyOp)get_x,
  prototypes::id::SVGTextPositioningElement,
  PrototypeTraits<prototypes::id::SVGTextPositioningElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_y(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGTextPositioningElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGAnimatedLengthList> result;
  result = self->Y();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo y_getterinfo = {
  (JSJitPropertyOp)get_y,
  prototypes::id::SVGTextPositioningElement,
  PrototypeTraits<prototypes::id::SVGTextPositioningElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_dx(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGTextPositioningElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGAnimatedLengthList> result;
  result = self->Dx();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo dx_getterinfo = {
  (JSJitPropertyOp)get_dx,
  prototypes::id::SVGTextPositioningElement,
  PrototypeTraits<prototypes::id::SVGTextPositioningElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_dy(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGTextPositioningElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGAnimatedLengthList> result;
  result = self->Dy();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo dy_getterinfo = {
  (JSJitPropertyOp)get_dy,
  prototypes::id::SVGTextPositioningElement,
  PrototypeTraits<prototypes::id::SVGTextPositioningElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_rotate(JSContext* cx, JSHandleObject obj, mozilla::dom::SVGTextPositioningElement* self, JS::Value* vp)
{
  nsRefPtr<mozilla::DOMSVGAnimatedNumberList> result;
  result = self->Rotate();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo rotate_getterinfo = {
  (JSJitPropertyOp)get_rotate,
  prototypes::id::SVGTextPositioningElement,
  PrototypeTraits<prototypes::id::SVGTextPositioningElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericGetter(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::SVGTextPositioningElement* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::SVGTextPositioningElement, mozilla::dom::SVGTextPositioningElement>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "SVGTextPositioningElement");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Getter);
  JSJitPropertyOp getter = info->op;
  return getter(cx, obj, self, vp);
}

static JSPropertySpec sAttributes_specs[] = {
  { "x", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &x_getterinfo }, JSOP_NULLWRAPPER},
  { "y", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &y_getterinfo }, JSOP_NULLWRAPPER},
  { "dx", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &dx_getterinfo }, JSOP_NULLWRAPPER},
  { "dy", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &dy_getterinfo }, JSOP_NULLWRAPPER},
  { "rotate", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &rotate_getterinfo }, JSOP_NULLWRAPPER},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};

static jsid sAttributes_ids[6] = { JSID_VOID };


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
  prototypes::id::SVGTextPositioningElement,
  constructors::id::SVGTextPositioningElement,
  &SVGTextContentElementBinding::sNativePropertyHooks
};

JSNativeHolder _constructor_holder = {
  ThrowingConstructor,
  &sNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "SVGTextPositioningElementPrototype",
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
  JSObject* parentProto = SVGTextContentElementBinding::GetProtoObject(aCx, aGlobal);
  if (!parentProto) {
    return;
  }


  if (sAttributes_ids[0] == JSID_VOID &&
      !InitIds(aCx, sAttributes, sAttributes_ids)) {
    sAttributes_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::SVGTextPositioningElement],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::SVGTextPositioningElement],
                              nullptr,
                              &sNativeProperties,
                              nullptr,
                              "SVGTextPositioningElement");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}

} // namespace SVGTextPositioningElementBinding



} // namespace dom
} // namespace mozilla