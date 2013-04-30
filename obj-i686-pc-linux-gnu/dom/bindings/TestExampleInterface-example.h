/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 sts=2 et cindent: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

#include "mozilla/Attributes.h"
#include "mozilla/ErrorResult.h"
#include "nsCycleCollectionParticipant.h"
#include "nsWrapperCache.h"

struct JSContext;

namespace mozilla {
namespace dom {

class TestExampleInterface MOZ_FINAL : public nsISupports /* Change nativeOwnership in the binding configuration if you don't want this */,
                                       public nsWrapperCache /* Change wrapperCache in the binding configuration if you don't want this */
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(TestExampleInterface)

public:
  TestExampleInterface();

  ~TestExampleInterface();

  // TODO: return something sensible here, and change the return type
  TestExampleInterface* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JSObject* aScope, bool* aTriedToWrap);

  static already_AddRefed<TestExampleInterface> Constructor(nsISupports* global, ErrorResult& aRv);
  static already_AddRefed<TestExampleInterface> Constructor(nsISupports* global, const nsAString& str, ErrorResult& aRv);
  static already_AddRefed<TestExampleInterface> Constructor(nsISupports* global, uint32_t num, const Nullable< bool >& boolArg, ErrorResult& aRv);
  static already_AddRefed<TestExampleInterface> Constructor(nsISupports* global, mozilla::dom::TestInterface* iface, ErrorResult& aRv);
  static already_AddRefed<TestExampleInterface> Constructor(nsISupports* global, mozilla::dom::TestNonCastableInterface& iface, ErrorResult& aRv);

  int8_t ReadonlyByte() const;

  int8_t WritableByte() const;

  void SetWritableByte(int8_t arg);

  void PassByte(int8_t arg);

  int8_t ReceiveByte();

  void PassOptionalByte(const Optional< int8_t >& arg);

  void PassOptionalByteWithDefault(int8_t arg);

  void PassNullableByte(const Nullable< int8_t >& arg);

  void PassOptionalNullableByte(const Optional< Nullable< int8_t > >& arg);

  void PassVariadicByte(const Sequence< int8_t >& arg);

  int16_t ReadonlyShort() const;

  int16_t WritableShort() const;

  void SetWritableShort(int16_t arg);

  void PassShort(int16_t arg);

  int16_t ReceiveShort();

  void PassOptionalShort(const Optional< int16_t >& arg);

  void PassOptionalShortWithDefault(int16_t arg);

  int32_t ReadonlyLong() const;

  int32_t WritableLong() const;

  void SetWritableLong(int32_t arg);

  void PassLong(int32_t arg);

  int32_t ReceiveLong();

  void PassOptionalLong(const Optional< int32_t >& arg);

  void PassOptionalLongWithDefault(int32_t arg);

  int64_t ReadonlyLongLong() const;

  int64_t WritableLongLong() const;

  void SetWritableLongLong(int64_t arg);

  void PassLongLong(int64_t arg);

  int64_t ReceiveLongLong();

  void PassOptionalLongLong(const Optional< int64_t >& arg);

  void PassOptionalLongLongWithDefault(int64_t arg);

  uint8_t ReadonlyOctet() const;

  uint8_t WritableOctet() const;

  void SetWritableOctet(uint8_t arg);

  void PassOctet(uint8_t arg);

  uint8_t ReceiveOctet();

  void PassOptionalOctet(const Optional< uint8_t >& arg);

  void PassOptionalOctetWithDefault(uint8_t arg);

  uint16_t ReadonlyUnsignedShort() const;

  uint16_t WritableUnsignedShort() const;

  void SetWritableUnsignedShort(uint16_t arg);

  void PassUnsignedShort(uint16_t arg);

  uint16_t ReceiveUnsignedShort();

  void PassOptionalUnsignedShort(const Optional< uint16_t >& arg);

  void PassOptionalUnsignedShortWithDefault(uint16_t arg);

  uint32_t ReadonlyUnsignedLong() const;

  uint32_t WritableUnsignedLong() const;

  void SetWritableUnsignedLong(uint32_t arg);

  void PassUnsignedLong(uint32_t arg);

  uint32_t ReceiveUnsignedLong();

  void PassOptionalUnsignedLong(const Optional< uint32_t >& arg);

  void PassOptionalUnsignedLongWithDefault(uint32_t arg);

  uint64_t ReadonlyUnsignedLongLong() const;

  uint64_t WritableUnsignedLongLong() const;

  void SetWritableUnsignedLongLong(uint64_t arg);

  void PassUnsignedLongLong(uint64_t arg);

  uint64_t ReceiveUnsignedLongLong();

  void PassOptionalUnsignedLongLong(const Optional< uint64_t >& arg);

  void PassOptionalUnsignedLongLongWithDefault(uint64_t arg);

  float WritableFloat() const;

  void SetWritableFloat(float arg);

  float WritableUnrestrictedFloat() const;

  void SetWritableUnrestrictedFloat(float arg);

  Nullable<float> GetWritableNullableFloat() const;

  void SetWritableNullableFloat(const Nullable< float >& arg);

  Nullable<float> GetWritableNullableUnrestrictedFloat() const;

  void SetWritableNullableUnrestrictedFloat(const Nullable< float >& arg);

  double WritableDouble() const;

  void SetWritableDouble(double arg);

  double WritableUnrestrictedDouble() const;

  void SetWritableUnrestrictedDouble(double arg);

  Nullable<double> GetWritableNullableDouble() const;

  void SetWritableNullableDouble(const Nullable< double >& arg);

  Nullable<double> GetWritableNullableUnrestrictedDouble() const;

  void SetWritableNullableUnrestrictedDouble(const Nullable< double >& arg);

  void PassFloat(float arg1, float arg2, const Nullable< float >& arg3, const Nullable< float >& arg4, double arg5, double arg6, const Nullable< double >& arg7, const Nullable< double >& arg8, const Sequence< float >& arg9, const Sequence< float >& arg10, const Sequence< Nullable< float > >& arg11, const Sequence< Nullable< float > >& arg12, const Sequence< double >& arg13, const Sequence< double >& arg14, const Sequence< Nullable< double > >& arg15, const Sequence< Nullable< double > >& arg16);

  void PassLenientFloat(float arg1, float arg2, const Nullable< float >& arg3, const Nullable< float >& arg4, double arg5, double arg6, const Nullable< double >& arg7, const Nullable< double >& arg8, const Sequence< float >& arg9, const Sequence< float >& arg10, const Sequence< Nullable< float > >& arg11, const Sequence< Nullable< float > >& arg12, const Sequence< double >& arg13, const Sequence< double >& arg14, const Sequence< Nullable< double > >& arg15, const Sequence< Nullable< double > >& arg16);

  float LenientFloatAttr() const;

  void SetLenientFloatAttr(float arg);

  double LenientDoubleAttr() const;

  void SetLenientDoubleAttr(double arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestInterface> ReceiveSelf();

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestInterface> ReceiveNullableSelf();

  TestInterface* ReceiveWeakSelf();

  TestInterface* ReceiveWeakNullableSelf();

  void PassSelf(mozilla::dom::TestInterface& arg);

  void PassSelf2(mozilla::dom::TestInterface& arg);

  void PassNullableSelf(mozilla::dom::TestInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestInterface> NonNullSelf() const;

  void SetNonNullSelf(mozilla::dom::TestInterface& arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestInterface> GetNullableSelf() const;

  void SetNullableSelf(mozilla::dom::TestInterface* arg);

  void PassOptionalSelf(const Optional< mozilla::dom::TestInterface* >& arg);

  void PassOptionalNonNullSelf(const Optional< NonNull<mozilla::dom::TestInterface> >& arg);

  void PassOptionalSelfWithDefault(mozilla::dom::TestInterface* arg);

  already_AddRefed<TestNonWrapperCacheInterface> ReceiveNonWrapperCacheInterface();

  already_AddRefed<TestNonWrapperCacheInterface> ReceiveNullableNonWrapperCacheInterface();

  void ReceiveNonWrapperCacheInterfaceSequence(nsTArray< nsRefPtr<TestNonWrapperCacheInterface> >& retval);

  void ReceiveNullableNonWrapperCacheInterfaceSequence(nsTArray< nsRefPtr<TestNonWrapperCacheInterface> >& retval);

  void ReceiveNonWrapperCacheInterfaceNullableSequence(Nullable< nsTArray< nsRefPtr<TestNonWrapperCacheInterface> > >& retval);

  void ReceiveNullableNonWrapperCacheInterfaceNullableSequence(Nullable< nsTArray< nsRefPtr<TestNonWrapperCacheInterface> > >& retval);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestNonCastableInterface> ReceiveOther();

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestNonCastableInterface> ReceiveNullableOther();

  TestNonCastableInterface* ReceiveWeakOther();

  TestNonCastableInterface* ReceiveWeakNullableOther();

  void PassOther(mozilla::dom::TestNonCastableInterface& arg);

  void PassOther2(mozilla::dom::TestNonCastableInterface& arg);

  void PassNullableOther(mozilla::dom::TestNonCastableInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestNonCastableInterface> NonNullOther() const;

  void SetNonNullOther(mozilla::dom::TestNonCastableInterface& arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestNonCastableInterface> GetNullableOther() const;

  void SetNullableOther(mozilla::dom::TestNonCastableInterface* arg);

  void PassOptionalOther(const Optional< mozilla::dom::TestNonCastableInterface* >& arg);

  void PassOptionalNonNullOther(const Optional< NonNull<mozilla::dom::TestNonCastableInterface> >& arg);

  void PassOptionalOtherWithDefault(mozilla::dom::TestNonCastableInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExternalInterface> ReceiveExternal();

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExternalInterface> ReceiveNullableExternal();

  TestExternalInterface* ReceiveWeakExternal();

  TestExternalInterface* ReceiveWeakNullableExternal();

  void PassExternal(mozilla::dom::TestExternalInterface* arg);

  void PassExternal2(mozilla::dom::TestExternalInterface* arg);

  void PassNullableExternal(mozilla::dom::TestExternalInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExternalInterface> NonNullExternal() const;

  void SetNonNullExternal(mozilla::dom::TestExternalInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExternalInterface> GetNullableExternal() const;

  void SetNullableExternal(mozilla::dom::TestExternalInterface* arg);

  void PassOptionalExternal(const Optional< mozilla::dom::TestExternalInterface* >& arg);

  void PassOptionalNonNullExternal(const Optional< mozilla::dom::TestExternalInterface* >& arg);

  void PassOptionalExternalWithDefault(mozilla::dom::TestExternalInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestCallbackInterface> ReceiveCallbackInterface();

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestCallbackInterface> ReceiveNullableCallbackInterface();

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestCallbackInterface> ReceiveWeakCallbackInterface();

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestCallbackInterface> ReceiveWeakNullableCallbackInterface();

  void PassCallbackInterface(mozilla::dom::TestCallbackInterface& arg);

  void PassCallbackInterface2(mozilla::dom::TestCallbackInterface& arg);

  void PassNullableCallbackInterface(mozilla::dom::TestCallbackInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestCallbackInterface> NonNullCallbackInterface() const;

  void SetNonNullCallbackInterface(mozilla::dom::TestCallbackInterface& arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestCallbackInterface> GetNullableCallbackInterface() const;

  void SetNullableCallbackInterface(mozilla::dom::TestCallbackInterface* arg);

  void PassOptionalCallbackInterface(const Optional< nsRefPtr<mozilla::dom::TestCallbackInterface> >& arg);

  void PassOptionalNonNullCallbackInterface(const Optional< OwningNonNull<mozilla::dom::TestCallbackInterface> >& arg);

  void PassOptionalCallbackInterfaceWithDefault(mozilla::dom::TestCallbackInterface* arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<IndirectlyImplementedInterface> ReceiveConsequentialInterface();

  void PassConsequentialInterface(mozilla::dom::IndirectlyImplementedInterface& arg);

  void ReceiveSequence(nsTArray< int32_t >& retval);

  void ReceiveNullableSequence(Nullable< nsTArray< int32_t > >& retval);

  void ReceiveSequenceOfNullableInts(nsTArray< Nullable<int32_t> >& retval);

  void ReceiveNullableSequenceOfNullableInts(Nullable< nsTArray< Nullable<int32_t> > >& retval);

  void PassSequence(const Sequence< int32_t >& arg);

  void PassNullableSequence(const Nullable< Sequence< int32_t > >& arg);

  void PassSequenceOfNullableInts(const Sequence< Nullable< int32_t > >& arg);

  void PassOptionalSequenceOfNullableInts(const Optional< Sequence< Nullable< int32_t > > >& arg);

  void PassOptionalNullableSequenceOfNullableInts(const Optional< Nullable< Sequence< Nullable< int32_t > > > >& arg);

  void ReceiveCastableObjectSequence(nsTArray< // Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<TestInterface> >& retval);

  void ReceiveCallbackObjectSequence(nsTArray< // Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<TestCallbackInterface> >& retval);

  void ReceiveNullableCastableObjectSequence(nsTArray< // Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<TestInterface> >& retval);

  void ReceiveNullableCallbackObjectSequence(nsTArray< // Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<TestCallbackInterface> >& retval);

  void ReceiveCastableObjectNullableSequence(Nullable< nsTArray< // Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<TestInterface> > >& retval);

  void ReceiveNullableCastableObjectNullableSequence(Nullable< nsTArray< // Mark this as resultNotAddRefed to return raw pointers
  nsRefPtr<TestInterface> > >& retval);

  void ReceiveWeakCastableObjectSequence(nsTArray< TestInterface* >& retval);

  void ReceiveWeakNullableCastableObjectSequence(nsTArray< TestInterface* >& retval);

  void ReceiveWeakCastableObjectNullableSequence(Nullable< nsTArray< TestInterface* > >& retval);

  void ReceiveWeakNullableCastableObjectNullableSequence(Nullable< nsTArray< TestInterface* > >& retval);

  void PassCastableObjectSequence(const Sequence< OwningNonNull<mozilla::dom::TestInterface> >& arg);

  void PassNullableCastableObjectSequence(const Sequence< nsRefPtr<mozilla::dom::TestInterface> >& arg);

  void PassCastableObjectNullableSequence(const Nullable< Sequence< OwningNonNull<mozilla::dom::TestInterface> > >& arg);

  void PassNullableCastableObjectNullableSequence(const Nullable< Sequence< nsRefPtr<mozilla::dom::TestInterface> > >& arg);

  void PassOptionalSequence(const Optional< Sequence< int32_t > >& arg);

  void PassOptionalNullableSequence(const Optional< Nullable< Sequence< int32_t > > >& arg);

  void PassOptionalNullableSequenceWithDefaultValue(const Nullable< Sequence< int32_t > >& arg);

  void PassOptionalObjectSequence(const Optional< Sequence< OwningNonNull<mozilla::dom::TestInterface> > >& arg);

  void PassExternalInterfaceSequence(const Sequence< nsRefPtr<mozilla::dom::TestExternalInterface> >& arg);

  void PassNullableExternalInterfaceSequence(const Sequence< nsRefPtr<mozilla::dom::TestExternalInterface> >& arg);

  void ReceiveStringSequence(nsTArray< nsString >& retval);

  void PassStringSequence(const Sequence< nsString >& arg);

  void ReceiveAnySequence(JSContext* cx, nsTArray< JS::Value >& retval);

  void ReceiveNullableAnySequence(JSContext* cx, Nullable< nsTArray< JS::Value > >& retval);

  void PassArrayBuffer(ArrayBuffer& arg);

  void PassNullableArrayBuffer(ArrayBuffer* arg);

  void PassOptionalArrayBuffer(const Optional< ArrayBuffer >& arg);

  void PassOptionalNullableArrayBuffer(const Optional< ArrayBuffer* >& arg);

  void PassOptionalNullableArrayBufferWithDefaultValue(ArrayBuffer* arg);

  void PassArrayBufferView(ArrayBufferView& arg);

  void PassInt8Array(Int8Array& arg);

  void PassInt16Array(Int16Array& arg);

  void PassInt32Array(Int32Array& arg);

  void PassUint8Array(Uint8Array& arg);

  void PassUint16Array(Uint16Array& arg);

  void PassUint32Array(Uint32Array& arg);

  void PassUint8ClampedArray(Uint8ClampedArray& arg);

  void PassFloat32Array(Float32Array& arg);

  void PassFloat64Array(Float64Array& arg);

  JSObject* ReceiveUint8Array(JSContext* cx);

  void PassString(const nsAString& arg);

  void PassNullableString(const nsAString& arg);

  void PassOptionalString(const Optional< nsAString >& arg);

  void PassOptionalStringWithDefaultValue(const nsAString& arg);

  void PassOptionalNullableString(const Optional< nsAString >& arg);

  void PassOptionalNullableStringWithDefaultValue(const nsAString& arg);

  void PassVariadicString(const Sequence< nsString >& arg);

  void PassEnum(TestEnum arg);

  void PassOptionalEnum(const Optional< TestEnum >& arg);

  void PassEnumWithDefault(TestEnum arg);

  TestEnum ReceiveEnum();

  TestEnum EnumAttribute() const;

  void SetEnumAttribute(TestEnum arg);

  TestEnum ReadonlyEnumAttribute() const;

  void PassCallback(TestCallback& arg);

  void PassNullableCallback(TestCallback* arg);

  void PassOptionalCallback(const Optional< OwningNonNull<TestCallback> >& arg);

  void PassOptionalNullableCallback(const Optional< nsRefPtr<TestCallback> >& arg);

  void PassOptionalNullableCallbackWithDefaultValue(TestCallback* arg);

  already_AddRefed<TestCallback> ReceiveCallback();

  already_AddRefed<TestCallback> ReceiveNullableCallback();

  void PassNullableTreatAsNullCallback(TestTreatAsNullCallback* arg);

  void PassOptionalNullableTreatAsNullCallback(const Optional< nsRefPtr<TestTreatAsNullCallback> >& arg);

  void PassOptionalNullableTreatAsNullCallbackWithDefaultValue(TestTreatAsNullCallback* arg);

  void PassAny(JSContext* cx, JS::Value arg);

  void PassOptionalAny(JSContext* cx, const Optional< JS::Value >& arg);

  void PassAnyDefaultNull(JSContext* cx, JS::Value arg);

  JS::Value ReceiveAny(JSContext* cx);

  void PassObject(JSContext* cx, JSObject& arg);

  void PassNullableObject(JSContext* cx, JSObject* arg);

  void PassOptionalObject(JSContext* cx, const Optional< NonNull<JSObject> >& arg);

  void PassOptionalNullableObject(JSContext* cx, const Optional< JSObject* >& arg);

  void PassOptionalNullableObjectWithDefaultValue(JSContext* cx, JSObject* arg);

  JSObject* ReceiveObject(JSContext* cx);

  JSObject* ReceiveNullableObject(JSContext* cx);

  void PassUnion(JSContext* cx, const ObjectOrLong& arg);

  void PassUnionWithNullable(JSContext* cx, const ObjectOrNullOrLong& arg);

  void PassNullableUnion(JSContext* cx, const Nullable< ObjectOrLong >& arg);

  void PassOptionalUnion(JSContext* cx, const Optional< ObjectOrLong >& arg);

  void PassOptionalNullableUnion(JSContext* cx, const Optional< Nullable< ObjectOrLong > >& arg);

  void PassOptionalNullableUnionWithDefaultValue(JSContext* cx, const Nullable< ObjectOrLong >& arg);

  void PassUnionWithArrayBuffer(const ArrayBufferOrLong& arg);

  void PassUnionWithString(JSContext* cx, const StringOrObject& arg);

  void PassUnionWithObject(JSContext* cx, const ObjectOrLong& arg);

  void MethodRenamedTo();
  void MethodRenamedTo(int8_t argument);

  int8_t AttributeGetterRenamedTo() const;

  int8_t AttributeRenamedTo() const;

  void SetAttributeRenamedTo(int8_t arg);

  void PassDictionary(const Dict& x);

  void PassOtherDictionary(const GrandparentDict& x);

  void PassSequenceOfDictionaries(const Sequence< Dict >& x);

  void PassDictionaryOrLong(const Dict& x);
  void PassDictionaryOrLong(int32_t x);

  void PassDictContainingDict(const DictContainingDict& arg);

  void PassDictContainingSequence(const DictContainingSequence& arg);

  void DontEnforceRangeOrClamp(int8_t arg);

  void DoEnforceRange(int8_t arg);

  void DoClamp(int8_t arg);

  void ExerciseTypedefInterfaces1(mozilla::dom::TestInterface& arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestInterface> ExerciseTypedefInterfaces2(mozilla::dom::TestInterface* arg);

  void ExerciseTypedefInterfaces3(mozilla::dom::TestInterface& arg);

  static bool StaticAttribute(nsISupports* global);

  static void SetStaticAttribute(nsISupports* global, bool arg);

  static void StaticMethod(nsISupports* global, bool arg);

  bool Overload1(mozilla::dom::TestInterface& arg);
  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestInterface> Overload1(const nsAString& strs, mozilla::dom::TestInterface& arg);

  void Overload2(mozilla::dom::TestInterface& arg);
  void Overload2(const Dict& arg);
  void Overload2(const nsAString& arg);

  void Overload3(mozilla::dom::TestInterface& arg);
  void Overload3(TestCallback& arg);
  void Overload3(const nsAString& arg);

  void Overload4(mozilla::dom::TestInterface& arg);
  void Overload4(mozilla::dom::TestCallbackInterface& arg);
  void Overload4(const nsAString& arg);

  void PassVariadicThirdArg(const nsAString& arg1, int32_t arg2, const Sequence< OwningNonNull<mozilla::dom::TestInterface> >& arg3);

  int32_t AttrWithLenientThis() const;

  void SetAttrWithLenientThis(int32_t arg);

  int32_t UnforgeableAttr() const;

  int32_t UnforgeableAttr2() const;

  void __stringifier(nsString& retval);

  void PassRenamedInterface(nsRenamedInterface& arg);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExampleInterface> PutForwardsAttr() const;

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExampleInterface> PutForwardsAttr2() const;

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<TestExampleInterface> PutForwardsAttr3() const;

  void ThrowingMethod(ErrorResult& aRv);

  bool GetThrowingAttr(ErrorResult& aRv) const;

  void SetThrowingAttr(bool arg, ErrorResult& aRv);

  bool GetThrowingGetterAttr(ErrorResult& aRv) const;

  void SetThrowingGetterAttr(bool arg);

  bool ThrowingSetterAttr() const;

  void SetThrowingSetterAttr(bool arg, ErrorResult& aRv);

  void __stringify(nsString& retval);
};

} // namespace dom
} // namespace mozilla
