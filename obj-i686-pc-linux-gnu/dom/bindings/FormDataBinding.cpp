/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "FileReaderSyncBinding.h"
#include "FormDataBinding.h"
#include "PrimitiveConversions.h"
#include "WorkerPrivate.h"
#include "XPCQuickStubs.h"
#include "XPCWrapper.h"
#include "mozilla/Preferences.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/NonRefcountedDOMObject.h"
#include "mozilla/dom/Nullable.h"
#include "nsContentUtils.h"
#include "nsDOMQS.h"
#include "nsFormData.h"
#include "nsHTMLFormElement.h"
#include "nsIDOMFile.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace FormDataBinding {

static bool
append(JSContext* cx, JSHandleObject obj, nsFormData* self, unsigned argc, JS::Value* vp)
{

  unsigned argcount = NS_MIN(argc, 2u);
  switch (argcount) {
    case 2: {
      JS::Value* argv_start = JS_ARGV(cx, vp);
      FakeDependentString arg0_holder;
      const NonNull<nsAString> arg0;
      if (!ConvertJSValueToString(cx, argv_start[0], &argv_start[0], eStringify, eStringify, arg0_holder)) {
        return false;
      }
      const_cast<NonNull<nsAString>&>(arg0) = &arg0_holder;
      if (argv_start[1].isObject()) {
        do {
          nsRefPtr<nsIDOMBlob> arg1_holder;
          nsIDOMBlob* arg1;
          jsval tmpVal = argv_start[1];
          nsIDOMBlob* tmp;
          if (NS_FAILED(xpc_qsUnwrapArg<nsIDOMBlob>(cx, argv_start[1], &tmp, static_cast<nsIDOMBlob**>(getter_AddRefs(arg1_holder)), &tmpVal))) {
            break;
          }
          MOZ_ASSERT(tmp);
          arg1 = tmp;
          self->Append(arg0, arg1);
          *vp = JSVAL_VOID;
          return true;
        } while (0);
      }

      JS::Value* argv = JS_ARGV(cx, vp);

      FakeDependentString arg1_holder;
      const NonNull<nsAString> arg1;
      if (!ConvertJSValueToString(cx, argv[1], &argv[1], eStringify, eStringify, arg1_holder)) {
        return false;
      }
      const_cast<NonNull<nsAString>&>(arg1) = &arg1_holder;
      self->Append(arg0, arg1);
      *vp = JSVAL_VOID;
      return true;
      break;
    }
    default: {
      return ThrowErrorMessage(cx, MSG_MISSING_ARGUMENTS, "FormData.append");

      break;
    }
  }
  MOZ_NOT_REACHED("We have an always-returning default case");
  return false;
}


const JSJitInfo append_methodinfo = {
  (JSJitPropertyOp)append,
  prototypes::id::FormData,
  PrototypeTraits<prototypes::id::FormData>::Depth,
  JSJitInfo::Method,
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

  nsFormData* self;
  {
    nsresult rv = UnwrapObject<prototypes::id::FormData, nsFormData>(cx, obj, self);
    if (NS_FAILED(rv)) {
      return ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "FormData");
    }
  }
  const JSJitInfo *info = FUNCTION_VALUE_TO_JITINFO(JS_CALLEE(cx, vp));
  MOZ_ASSERT(info->type == JSJitInfo::Method);
  JSJitMethodOp method = (JSJitMethodOp)info->op;
  return method(cx, obj, self, argc, vp);
}

static JSBool
_addProperty(JSContext* cx, JSHandleObject obj, JSHandleId id, JSMutableHandleValue vp)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, nsFormData>::value), "Must be an nsISupports class");
  nsFormData* self = UnwrapDOMObject<nsFormData>(obj);
  nsContentUtils::PreserveWrapper(reinterpret_cast<nsISupports*>(self), self);
  return true;
}

static void
_finalize(JSFreeOp* fop, JSObject* obj)
{
  MOZ_STATIC_ASSERT((IsBaseOf<nsISupports, nsFormData>::value), "Must be an nsISupports class");
  nsFormData* self = UnwrapDOMObject<nsFormData>(obj);
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
  JS_FNINFO("append", genericMethod, &append_methodinfo, 2, JSPROP_ENUMERATE),
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


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sMethods, sMethods_ids, sMethods_specs,
  nullptr, nullptr, nullptr,
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
  prototypes::id::FormData,
  constructors::id::FormData,
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

  const Optional< nsRefPtr<nsHTMLFormElement> > arg0_holder;
  const Optional< nsHTMLFormElement* > arg0;
  if (0 < argc) {
    const_cast< Optional< nsHTMLFormElement* > &>(arg0).Construct();
    const_cast< Optional< nsRefPtr<nsHTMLFormElement> > &>(arg0_holder).Construct();
    if (argv[0].isObject()) {
      jsval tmpVal = argv[0];
      nsHTMLFormElement* tmp;
      if (NS_FAILED(xpc_qsUnwrapArg<nsHTMLFormElement>(cx, argv[0], &tmp, static_cast<nsHTMLFormElement**>(getter_AddRefs(const_cast< nsRefPtr<nsHTMLFormElement> & >(arg0_holder.Value()))), &tmpVal))) {
        ThrowErrorMessage(cx, MSG_DOES_NOT_IMPLEMENT_INTERFACE, "HTMLFormElement");return false;
      }
      MOZ_ASSERT(tmp);
      if (tmpVal != argv[0] && !const_cast< nsRefPtr<nsHTMLFormElement> & >(arg0_holder.Value())) {
        // We have to have a strong ref, because we got this off
        // some random object that might get GCed
        const_cast< nsRefPtr<nsHTMLFormElement> & >(arg0_holder.Value()) = tmp;
      }
      const_cast< nsHTMLFormElement* & >(arg0.Value()) = tmp;
    } else {
      ThrowErrorMessage(cx, MSG_NOT_OBJECT);
      return false;
    }
  }
  ErrorResult rv;
  nsRefPtr<nsFormData> result;
  result = nsFormData::Constructor(global, arg0, rv);
  if (rv.Failed()) {
    return ThrowMethodFailedWithDetails<true>(cx, rv, "FormData", "constructor");
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
    "FormDataPrototype",
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
       !InitIds(aCx, sMethods, sMethods_ids))) {
    sChromeMethods_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              &PrototypeClass.mBase, &protoAndIfaceArray[prototypes::id::FormData],
                              nullptr, &_constructor_holder, 0, &protoAndIfaceArray[constructors::id::FormData],
                              &Class.mClass,
                              &sNativeProperties,
                              xpc::AccessCheck::isChrome(aGlobal) ? &sChromeOnlyNativeProperties : nullptr,
                              "FormData");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}


DOMJSClass Class = {
  { "FormData",
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
    { prototypes::id::FormData, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count, prototypes::id::_ID_Count },
    true,
    &sNativePropertyHooks,
    GetParentObject<nsFormData>::Get,
    GetProtoObject,
    nullptr
  }
};

JSObject*
Wrap(JSContext* aCx, JSObject* aScope, nsFormData* aObject, nsWrapperCache* aCache, bool* aTriedToWrap)
{
  MOZ_ASSERT(static_cast<nsFormData*>(aObject) ==
             reinterpret_cast<nsFormData*>(aObject));

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

} // namespace FormDataBinding



} // namespace dom
} // namespace mozilla