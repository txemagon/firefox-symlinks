/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/battery/nsIDOMBatteryManager.idl
 */

#ifndef __gen_nsIDOMBatteryManager_h__
#define __gen_nsIDOMBatteryManager_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIDOMBatteryManager */
#define NS_IDOMBATTERYMANAGER_IID_STR "3d95d773-3c19-4944-8152-ec6ca01a8bde"

#define NS_IDOMBATTERYMANAGER_IID \
  {0x3d95d773, 0x3c19, 0x4944, \
    { 0x81, 0x52, 0xec, 0x6c, 0xa0, 0x1a, 0x8b, 0xde }}

class NS_NO_VTABLE nsIDOMBatteryManager : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBATTERYMANAGER_IID)

  /* readonly attribute double level; */
  NS_IMETHOD GetLevel(double *aLevel) = 0;

  /* readonly attribute boolean charging; */
  NS_IMETHOD GetCharging(bool *aCharging) = 0;

  /* readonly attribute double dischargingTime; */
  NS_IMETHOD GetDischargingTime(double *aDischargingTime) = 0;

  /* readonly attribute double chargingTime; */
  NS_IMETHOD GetChargingTime(double *aChargingTime) = 0;

  /* [implicit_jscontext] attribute jsval onlevelchange; */
  NS_IMETHOD GetOnlevelchange(JSContext* cx, JS::Value *aOnlevelchange) = 0;
  NS_IMETHOD SetOnlevelchange(JSContext* cx, const JS::Value & aOnlevelchange) = 0;

  /* [implicit_jscontext] attribute jsval onchargingchange; */
  NS_IMETHOD GetOnchargingchange(JSContext* cx, JS::Value *aOnchargingchange) = 0;
  NS_IMETHOD SetOnchargingchange(JSContext* cx, const JS::Value & aOnchargingchange) = 0;

  /* [implicit_jscontext] attribute jsval ondischargingtimechange; */
  NS_IMETHOD GetOndischargingtimechange(JSContext* cx, JS::Value *aOndischargingtimechange) = 0;
  NS_IMETHOD SetOndischargingtimechange(JSContext* cx, const JS::Value & aOndischargingtimechange) = 0;

  /* [implicit_jscontext] attribute jsval onchargingtimechange; */
  NS_IMETHOD GetOnchargingtimechange(JSContext* cx, JS::Value *aOnchargingtimechange) = 0;
  NS_IMETHOD SetOnchargingtimechange(JSContext* cx, const JS::Value & aOnchargingtimechange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBatteryManager, NS_IDOMBATTERYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBATTERYMANAGER \
  NS_IMETHOD GetLevel(double *aLevel); \
  NS_IMETHOD GetCharging(bool *aCharging); \
  NS_IMETHOD GetDischargingTime(double *aDischargingTime); \
  NS_IMETHOD GetChargingTime(double *aChargingTime); \
  NS_IMETHOD GetOnlevelchange(JSContext* cx, JS::Value *aOnlevelchange); \
  NS_IMETHOD SetOnlevelchange(JSContext* cx, const JS::Value & aOnlevelchange); \
  NS_IMETHOD GetOnchargingchange(JSContext* cx, JS::Value *aOnchargingchange); \
  NS_IMETHOD SetOnchargingchange(JSContext* cx, const JS::Value & aOnchargingchange); \
  NS_IMETHOD GetOndischargingtimechange(JSContext* cx, JS::Value *aOndischargingtimechange); \
  NS_IMETHOD SetOndischargingtimechange(JSContext* cx, const JS::Value & aOndischargingtimechange); \
  NS_IMETHOD GetOnchargingtimechange(JSContext* cx, JS::Value *aOnchargingtimechange); \
  NS_IMETHOD SetOnchargingtimechange(JSContext* cx, const JS::Value & aOnchargingtimechange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBATTERYMANAGER(_to) \
  NS_IMETHOD GetLevel(double *aLevel) { return _to GetLevel(aLevel); } \
  NS_IMETHOD GetCharging(bool *aCharging) { return _to GetCharging(aCharging); } \
  NS_IMETHOD GetDischargingTime(double *aDischargingTime) { return _to GetDischargingTime(aDischargingTime); } \
  NS_IMETHOD GetChargingTime(double *aChargingTime) { return _to GetChargingTime(aChargingTime); } \
  NS_IMETHOD GetOnlevelchange(JSContext* cx, JS::Value *aOnlevelchange) { return _to GetOnlevelchange(cx, aOnlevelchange); } \
  NS_IMETHOD SetOnlevelchange(JSContext* cx, const JS::Value & aOnlevelchange) { return _to SetOnlevelchange(cx, aOnlevelchange); } \
  NS_IMETHOD GetOnchargingchange(JSContext* cx, JS::Value *aOnchargingchange) { return _to GetOnchargingchange(cx, aOnchargingchange); } \
  NS_IMETHOD SetOnchargingchange(JSContext* cx, const JS::Value & aOnchargingchange) { return _to SetOnchargingchange(cx, aOnchargingchange); } \
  NS_IMETHOD GetOndischargingtimechange(JSContext* cx, JS::Value *aOndischargingtimechange) { return _to GetOndischargingtimechange(cx, aOndischargingtimechange); } \
  NS_IMETHOD SetOndischargingtimechange(JSContext* cx, const JS::Value & aOndischargingtimechange) { return _to SetOndischargingtimechange(cx, aOndischargingtimechange); } \
  NS_IMETHOD GetOnchargingtimechange(JSContext* cx, JS::Value *aOnchargingtimechange) { return _to GetOnchargingtimechange(cx, aOnchargingtimechange); } \
  NS_IMETHOD SetOnchargingtimechange(JSContext* cx, const JS::Value & aOnchargingtimechange) { return _to SetOnchargingtimechange(cx, aOnchargingtimechange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBATTERYMANAGER(_to) \
  NS_IMETHOD GetLevel(double *aLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLevel(aLevel); } \
  NS_IMETHOD GetCharging(bool *aCharging) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharging(aCharging); } \
  NS_IMETHOD GetDischargingTime(double *aDischargingTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDischargingTime(aDischargingTime); } \
  NS_IMETHOD GetChargingTime(double *aChargingTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChargingTime(aChargingTime); } \
  NS_IMETHOD GetOnlevelchange(JSContext* cx, JS::Value *aOnlevelchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlevelchange(cx, aOnlevelchange); } \
  NS_IMETHOD SetOnlevelchange(JSContext* cx, const JS::Value & aOnlevelchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlevelchange(cx, aOnlevelchange); } \
  NS_IMETHOD GetOnchargingchange(JSContext* cx, JS::Value *aOnchargingchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchargingchange(cx, aOnchargingchange); } \
  NS_IMETHOD SetOnchargingchange(JSContext* cx, const JS::Value & aOnchargingchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchargingchange(cx, aOnchargingchange); } \
  NS_IMETHOD GetOndischargingtimechange(JSContext* cx, JS::Value *aOndischargingtimechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndischargingtimechange(cx, aOndischargingtimechange); } \
  NS_IMETHOD SetOndischargingtimechange(JSContext* cx, const JS::Value & aOndischargingtimechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndischargingtimechange(cx, aOndischargingtimechange); } \
  NS_IMETHOD GetOnchargingtimechange(JSContext* cx, JS::Value *aOnchargingtimechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchargingtimechange(cx, aOnchargingtimechange); } \
  NS_IMETHOD SetOnchargingtimechange(JSContext* cx, const JS::Value & aOnchargingtimechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchargingtimechange(cx, aOnchargingtimechange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBatteryManager : public nsIDOMBatteryManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBATTERYMANAGER

  nsDOMBatteryManager();

private:
  ~nsDOMBatteryManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMBatteryManager, nsIDOMBatteryManager)

nsDOMBatteryManager::nsDOMBatteryManager()
{
  /* member initializers and constructor code */
}

nsDOMBatteryManager::~nsDOMBatteryManager()
{
  /* destructor code */
}

/* readonly attribute double level; */
NS_IMETHODIMP nsDOMBatteryManager::GetLevel(double *aLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean charging; */
NS_IMETHODIMP nsDOMBatteryManager::GetCharging(bool *aCharging)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double dischargingTime; */
NS_IMETHODIMP nsDOMBatteryManager::GetDischargingTime(double *aDischargingTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double chargingTime; */
NS_IMETHODIMP nsDOMBatteryManager::GetChargingTime(double *aChargingTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onlevelchange; */
NS_IMETHODIMP nsDOMBatteryManager::GetOnlevelchange(JSContext* cx, JS::Value *aOnlevelchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBatteryManager::SetOnlevelchange(JSContext* cx, const JS::Value & aOnlevelchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchargingchange; */
NS_IMETHODIMP nsDOMBatteryManager::GetOnchargingchange(JSContext* cx, JS::Value *aOnchargingchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBatteryManager::SetOnchargingchange(JSContext* cx, const JS::Value & aOnchargingchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondischargingtimechange; */
NS_IMETHODIMP nsDOMBatteryManager::GetOndischargingtimechange(JSContext* cx, JS::Value *aOndischargingtimechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBatteryManager::SetOndischargingtimechange(JSContext* cx, const JS::Value & aOndischargingtimechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchargingtimechange; */
NS_IMETHODIMP nsDOMBatteryManager::GetOnchargingtimechange(JSContext* cx, JS::Value *aOnchargingtimechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBatteryManager::SetOnchargingtimechange(JSContext* cx, const JS::Value & aOnchargingtimechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMBatteryManager_h__ */
