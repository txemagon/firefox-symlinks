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

class TestExampleProxyInterface MOZ_FINAL : public nsISupports /* Change nativeOwnership in the binding configuration if you don't want this */,
                                            public nsWrapperCache /* Change wrapperCache in the binding configuration if you don't want this */
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(TestExampleProxyInterface)

public:
  TestExampleProxyInterface();

  ~TestExampleProxyInterface();

  // TODO: return something sensible here, and change the return type
  TestExampleProxyInterface* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JSObject* aScope, bool* aTriedToWrap);

  int32_t LongIndexedGetter(uint32_t ix);

  void LongIndexedSetter(uint32_t y, int32_t z);

  void MyStringifier(nsString& retval);

  int16_t ShortNameGetter(const nsAString& nom);

  void ShortNamedSetter(const nsAString& me, int16_t value);

  void IndexedDeleter(uint32_t ix, bool &found);

  int32_t IndexedGetter(uint32_t ix, bool &found);

  void IndexedSetter(uint32_t y, int32_t z);

  void NamedDeleter(const nsAString& nomnom, bool &found);

  int16_t NamedGetter(const nsAString& nom, bool &found);

  void NamedSetter(const nsAString& me, int16_t value);

  void Stringifier(nsString& retval);

  uint32_t Length();

  void GetSupportedNames(nsTArray< nsString >& retval);
};

} // namespace dom
} // namespace mozilla
