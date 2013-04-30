/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "ElementBinding.h"
#include "EventTargetBinding.h"
#include "NodeBinding.h"
#include "PrimitiveConversions.h"
#include "SVGAnimationElementBinding.h"
#include "SVGElementBinding.h"
#include "SVGSetElementBinding.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/SVGSetElement.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace SVGSetElementBinding {

static JSBool
_addProperty(JSContext* cx, JSHandleObject obj, JSHandleId id, JSMutableHandleValue vp)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::SVGSetElement>::value), "Must be an nsISupports class");
  mozilla::dom::SVGSetElement* self = UnwrapDOMObject<mozilla::dom::SVGSetElement>(obj);
  nsContentUtils::PreserveWrapper(reinterpret_cast<nsISupports*>(self), self);
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::SVGSetElement>::value), "Must be an nsISupports class");
  mozilla::dom::SVGSetElement* self = UnwrapDOMObject<mozilla::dom::SVGSetElement>(obj);
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

const NativePropertyHooks sNativePropertyHooks = {
  nullptr,
  nullptr,
  { nullptr, nullptr },
  prototypes::id::SVGSetElement,
  constructors::id::SVGSetElement,
  &SVGAnimationElementBinding::sNativePropertyHooks
};

JSNativeHolder _constructor_holder = {
  ThrowingConstructor,
  &sNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "SVGSetElementPrototype",
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
  JSObject* parentProto = SVGAnimationElementBinding::GetProtoObject(aCx, aGlobal);
  if (!parentProto) {
    return;
  }


  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::SVGSetElement],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::SVGSetElement],
                              &Class.mClass,
                              nullptr,
                              nullptr,
                              "SVGSetElement");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}


DOMJSClass Class = {
  { "SVGSetElement",
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
    { prototypes::id::EventTarget, prototypes::id::Node, prototypes::id::Element, prototypes::id::SVGElement, prototypes::id::SVGAnimationElement, prototypes::id::SVGSetElement, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    true,
    &sNativePropertyHooks,
    GetParentObject<mozilla::dom::SVGSetElement>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::SVGSetElement* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<mozilla::dom::SVGSetElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::SVGSetElement*>(aObject));
  MOZ_ASSERT(static_cast<mozilla::dom::SVGAnimationElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::SVGAnimationElement*>(aObject));
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

} // namespace SVGSetElementBinding



} // namespace dom
} // namespace mozilla