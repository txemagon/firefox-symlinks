/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "ElementBinding.h"
#include "EventTargetBinding.h"
#include "HTMLCollectionBinding.h"
#include "HTMLElementBinding.h"
#include "HTMLTableRowElementBinding.h"
#include "NodeBinding.h"
#include "PrimitiveConversions.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/HTMLTableRowElement.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"
#include "nsGenericHTMLElement.h"
#include "nsIDOMHTMLTableRowElement.h"
#include "nsIHTMLCollection.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace HTMLTableRowElementBinding {

static bool
get_rowIndex(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  int32_t result;
  result = self->RowIndex();
  *vp = INT_TO_JSVAL(int32_t(result));
  return true;
}


const JSJitInfo rowIndex_getterinfo = {
  (JSJitPropertyOp)get_rowIndex,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  true,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_INT32   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_sectionRowIndex(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  int32_t result;
  result = self->SectionRowIndex();
  *vp = INT_TO_JSVAL(int32_t(result));
  return true;
}


const JSJitInfo sectionRowIndex_getterinfo = {
  (JSJitPropertyOp)get_sectionRowIndex,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  true,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_INT32   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_cells(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  nsIHTMLCollection* result;
  result = self->Cells();
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    MOZ_ASSERT(JS_IsExceptionPending(cx));
    return false;
  }
  return true;
}


const JSJitInfo cells_getterinfo = {
  (JSJitPropertyOp)get_cells,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
insertCell(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, unsigned argc, JS::Value* vp)
{

  JS::Value* argv = JS_ARGV(cx, vp);

  int32_t arg0;
  if (0 < argc) {
    if (!ValueToPrimitive<int32_t, eDefault>(cx, argv[0], &arg0)) {
      return false;
    }
  } else {
    arg0 = -1;
  }
  ErrorResult rv;
  nsRefPtr<nsGenericHTMLElement> result;
  result = self->InsertCell(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "insertCell");
  }
  if (!WrapNewBindingObject(cx, obj, result, vp)) {
    if (!HandleNewBindingWrappingFailure(cx, obj, result, vp)) {
      return false;
    }
    return true;
  }
  return true;
}


const JSJitInfo insertCell_methodinfo = {
  (JSJitPropertyOp)insertCell,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_OBJECT   /* returnType.  Only relevant for getters/methods. */
};

static bool
deleteCell(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, unsigned argc, JS::Value* vp)
{

  if (argc < 1) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "HTMLTableRowElement.deleteCell");
  }

  JS::Value* argv = JS_ARGV(cx, vp);

  int32_t arg0;
  if (!ValueToPrimitive<int32_t, eDefault>(cx, argv[0], &arg0)) {
    return false;
  }
  ErrorResult rv;
  self->DeleteCell(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "deleteCell");
  }
  *vp = JSVAL_VOID;
  return true;
}


const JSJitInfo deleteCell_methodinfo = {
  (JSJitPropertyOp)deleteCell,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Method,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_align(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  nsString result;
  self->GetAlign(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}

static bool
set_align(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* argv)
{
  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
    return false;
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  self->SetAlign(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "align");
  }

  return true;
}


const JSJitInfo align_getterinfo = {
  (JSJitPropertyOp)get_align,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo align_setterinfo = {
  (JSJitPropertyOp)set_align,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_ch(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  nsString result;
  self->GetCh(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}

static bool
set_ch(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* argv)
{
  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
    return false;
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  self->SetCh(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "ch");
  }

  return true;
}


const JSJitInfo ch_getterinfo = {
  (JSJitPropertyOp)get_ch,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo ch_setterinfo = {
  (JSJitPropertyOp)set_ch,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_chOff(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  nsString result;
  self->GetChOff(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}

static bool
set_chOff(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* argv)
{
  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
    return false;
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  self->SetChOff(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "chOff");
  }

  return true;
}


const JSJitInfo chOff_getterinfo = {
  (JSJitPropertyOp)get_chOff,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo chOff_setterinfo = {
  (JSJitPropertyOp)set_chOff,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_vAlign(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  nsString result;
  self->GetVAlign(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}

static bool
set_vAlign(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* argv)
{
  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (!ConvertJSValueToString(cx, argv[0], &argv[0], eStringify, eStringify, arg0_holder)) {
    return false;
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  self->SetVAlign(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "vAlign");
  }

  return true;
}


const JSJitInfo vAlign_getterinfo = {
  (JSJitPropertyOp)get_vAlign,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo vAlign_setterinfo = {
  (JSJitPropertyOp)set_vAlign,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static bool
get_bgColor(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* vp)
{
  nsString result;
  self->GetBgColor(result);
  if (!xpc::NonVoidStringToJsval(cx, result, vp)) {
    return false;
  }
  return true;
}

static bool
set_bgColor(JSContext* cx, JSHandleObject obj, mozilla::dom::HTMLTableRowElement* self, JS::Value* argv)
{
  FakeDependentString arg0_holder;
  const NonNull<nsAString> arg0;
  if (!ConvertJSValueToString(cx, argv[0], &argv[0], eEmpty, eStringify, arg0_holder)) {
    return false;
  }
  const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
  ErrorResult rv;
  self->SetBgColor(arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "HTMLTableRowElement", "bgColor");
  }

  return true;
}


const JSJitInfo bgColor_getterinfo = {
  (JSJitPropertyOp)get_bgColor,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Getter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_STRING   /* returnType.  Only relevant for getters/methods. */
};

const JSJitInfo bgColor_setterinfo = {
  (JSJitPropertyOp)set_bgColor,
  prototypes::id::HTMLTableRowElement,
  PrototypeTraits<prototypes::id::HTMLTableRowElement>::Depth,
  JSJitInfo::Setter,
  false,  /* isInfallible. False in setters. */
  false,  /* isConstant. Only relevant for getters. */
  JSVAL_TYPE_UNDEFINED   /* returnType.  Only relevant for getters/methods. */
};

static JSBool
genericMethod(JSContext* cx, unsigned argc, JS::Value* vp)
{
  js::RootedObject obj(cx, JS_THIS_OBJECT(cx, vp));
  if (!obj) {
    return false;
  }

  mozilla::dom::HTMLTableRowElement* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::HTMLTableRowElement, mozilla::dom::HTMLTableRowElement>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "HTMLTableRowElement");
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

  mozilla::dom::HTMLTableRowElement* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::HTMLTableRowElement, mozilla::dom::HTMLTableRowElement>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "HTMLTableRowElement");
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

  mozilla::dom::HTMLTableRowElement* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::HTMLTableRowElement, mozilla::dom::HTMLTableRowElement>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "HTMLTableRowElement");
    }
  }
  if (argc == 0) {
    return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "HTMLTableRowElement attribute setter");
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
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::HTMLTableRowElement>::value), "Must be an nsISupports class");
  mozilla::dom::HTMLTableRowElement* self = UnwrapDOMObject<mozilla::dom::HTMLTableRowElement>(obj);
  nsContentUtils::PreserveWrapper(reinterpret_cast<nsISupports*>(self), self);
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, mozilla::dom::HTMLTableRowElement>::value), "Must be an nsISupports class");
  mozilla::dom::HTMLTableRowElement* self = UnwrapDOMObject<mozilla::dom::HTMLTableRowElement>(obj);
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
  JS_FNINFO("insertCell", genericMethod, &insertCell_methodinfo, 0, JSPROP_ENUMERATE),
  JS_FNINFO("deleteCell", genericMethod, &deleteCell_methodinfo, 1, JSPROP_ENUMERATE),
  JS_FS_END
};

static Prefable<JSFunctionSpec> sMethods[] = {
  { true, &sMethods_specs[0] },
  { false, NULL }
};

static jsid sMethods_ids[3] = { JSID_VOID };

static JSPropertySpec sAttributes_specs[] = {
  { "rowIndex", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &rowIndex_getterinfo }, JSOP_NULLWRAPPER},
  { "sectionRowIndex", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &sectionRowIndex_getterinfo }, JSOP_NULLWRAPPER},
  { "cells", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &cells_getterinfo }, JSOP_NULLWRAPPER},
  { "align", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &align_getterinfo }, { (JSStrictPropertyOp)genericSetter, &align_setterinfo }},
  { "ch", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &ch_getterinfo }, { (JSStrictPropertyOp)genericSetter, &ch_setterinfo }},
  { "chOff", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &chOff_getterinfo }, { (JSStrictPropertyOp)genericSetter, &chOff_setterinfo }},
  { "vAlign", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &vAlign_getterinfo }, { (JSStrictPropertyOp)genericSetter, &vAlign_setterinfo }},
  { "bgColor", 0, JSPROP_SHARED | JSPROP_ENUMERATE | JSPROP_NATIVE_ACCESSORS, { (JSPropertyOp)genericGetter, &bgColor_getterinfo }, { (JSStrictPropertyOp)genericSetter, &bgColor_setterinfo }},
  { 0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER }
};

static Prefable<JSPropertySpec> sAttributes[] = {
  { true, &sAttributes_specs[0] },
  { false, NULL }
};

static jsid sAttributes_ids[9] = { JSID_VOID };


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
  prototypes::id::HTMLTableRowElement,
  constructors::id::HTMLTableRowElement,
  &HTMLElementBinding::sNativePropertyHooks
};

static JSBool
_hasInstance(JSContext* cx, JSHandleObject obj, JSMutableHandleValue vp, JSBool* bp)
{
  if (!vp.isObject()) {
    *bp = false;
    return true;
  }

  jsval protov;
  if (!JS_GetProperty(cx, obj, "prototype", &protov))
    return false;
  if (!protov.isObject()) {
    JS_ReportErrorNumber(cx, js_GetErrorMessage, NULL, JSMSG_BAD_PROTOTYPE,
                         "HTMLTableRowElement");
    return false;
  }
  JSObject *objProto = &protov.toObject();

  JSObject* instance = &vp.toObject();
  JSObject* proto;
  if (!JS_GetPrototype(cx, instance, &proto))
    return false;
  while (proto) {
    if (proto == objProto) {
      *bp = true;
      return true;
    }
    if (!JS_GetPrototype(cx, proto, &proto))
      return false;
  }

  // FIXME Limit this to chrome by checking xpc::AccessCheck::isChrome(obj).
  nsISupports* native =
    nsContentUtils::XPConnect()->GetNativeOfWrapper(cx, instance);
  nsCOMPtr<nsIDOMHTMLTableRowElement> qiResult = do_QueryInterface(native);
  *bp = !!qiResult;
  return true;

}


static DOMIfaceAndProtoJSClass InterfaceObjectClass = {
  {
    "Function",
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
    ThrowingConstructor, /* call */
    _hasInstance, /* hasInstance */
    ThrowingConstructor, /* construct */
    nullptr,               /* trace */
    JSCLASS_NO_INTERNAL_MEMBERS
  },
  eInterface,
  &sNativePropertyHooks
};

static DOMIfaceAndProtoJSClass PrototypeClass = {
  {
    "HTMLTableRowElementPrototype",
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
  JSObject* parentProto = HTMLElementBinding::GetProtoObject(aCx, aGlobal);
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
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::HTMLTableRowElement],
                              &InterfaceObjectClass.mBase, nullptr, 0, &protoAndIfaceArray[constructors::id::HTMLTableRowElement],
                              &Class.mClass,
                              &sNativeProperties,
                              nullptr,
                              "HTMLTableRowElement");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}


DOMJSClass Class = {
  { "HTMLTableRowElement",
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
    { prototypes::id::EventTarget, prototypes::id::Node, prototypes::id::Element, prototypes::id::HTMLElement, prototypes::id::HTMLTableRowElement, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    true,
    &sNativePropertyHooks,
    GetParentObject<mozilla::dom::HTMLTableRowElement>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, mozilla::dom::HTMLTableRowElement* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<mozilla::dom::HTMLTableRowElement*>(aObject) ==
             reinterpret_cast<mozilla::dom::HTMLTableRowElement*>(aObject));
  MOZ_ASSERT(static_cast<nsGenericHTMLElement*>(aObject) ==
             reinterpret_cast<nsGenericHTMLElement*>(aObject));
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

} // namespace HTMLTableRowElementBinding



} // namespace dom
} // namespace mozilla