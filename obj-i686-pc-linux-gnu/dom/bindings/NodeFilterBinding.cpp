/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#include "AccessCheck.h"
#include "NodeBinding.h"
#include "NodeFilterBinding.h"
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
#include "nsIDOMNodeFilter.h"
#include "nsINode.h"

using namespace mozilla::dom;
namespace mozilla {
namespace dom {

namespace NodeFilterBinding {

static ConstantSpec sConstants_specs[] = {
  { "FILTER_ACCEPT", INT_TO_JSVAL(1) },
  { "FILTER_REJECT", INT_TO_JSVAL(2) },
  { "FILTER_SKIP", INT_TO_JSVAL(3) },
  { "SHOW_ALL", UINT_TO_JSVAL(4294967295) },
  { "SHOW_ELEMENT", UINT_TO_JSVAL(1) },
  { "SHOW_ATTRIBUTE", UINT_TO_JSVAL(2) },
  { "SHOW_TEXT", UINT_TO_JSVAL(4) },
  { "SHOW_CDATA_SECTION", UINT_TO_JSVAL(8) },
  { "SHOW_ENTITY_REFERENCE", UINT_TO_JSVAL(16) },
  { "SHOW_ENTITY", UINT_TO_JSVAL(32) },
  { "SHOW_PROCESSING_INSTRUCTION", UINT_TO_JSVAL(64) },
  { "SHOW_COMMENT", UINT_TO_JSVAL(128) },
  { "SHOW_DOCUMENT", UINT_TO_JSVAL(256) },
  { "SHOW_DOCUMENT_TYPE", UINT_TO_JSVAL(512) },
  { "SHOW_DOCUMENT_FRAGMENT", UINT_TO_JSVAL(1024) },
  { "SHOW_NOTATION", UINT_TO_JSVAL(2048) },
  { 0, JSVAL_VOID }
};

static Prefable<ConstantSpec> sConstants[] = {
  { true, &sConstants_specs[0] },
  { false, NULL }
};

static jsid sConstants_ids[17] = { JSID_VOID };


static const NativeProperties sNativeProperties = {
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  nullptr, nullptr, nullptr,
  sConstants, sConstants_ids, sConstants_specs
};
const NativePropertyHooks sNativePropertyHooks = {
  nullptr,
  nullptr,
  { &sNativeProperties, nullptr },
  prototypes::id::_ID_Count,
  constructors::id::NodeFilter,
  NULL
};

void
CreateInterfaceObjects(JSContext* aCx, JSObject* aGlobal, JSObject** protoAndIfaceArray)
{
  JSObject* parentProto = JS_GetObjectPrototype(aCx, aGlobal);
  if (!parentProto) {
    return;
  }


  if (sConstants_ids[0] == JSID_VOID &&
      !InitIds(aCx, sConstants, sConstants_ids)) {
    sConstants_ids[0] = JSID_VOID;
    return;
  }

  dom::CreateInterfaceObjects(aCx, aGlobal, parentProto,
                              nullptr, nullptr,
                              js::Jsvalify(&js::ObjectClass), nullptr, 0, &protoAndIfaceArray[constructors::id::NodeFilter],
                              nullptr,
                              &sNativeProperties,
                              nullptr,
                              "NodeFilter");
}

JSObject*
DefineDOMInterface(JSContext* aCx, JSObject* aGlobal, bool* aEnabled)
{

  *aEnabled = true;
  return GetConstructorObject(aCx, aGlobal);
}

} // namespace NodeFilterBinding



} // namespace dom
} // namespace mozilla