/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/battery/nsINavigatorBattery.idl
 */

#ifndef __gen_nsINavigatorBattery_h__
#define __gen_nsINavigatorBattery_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBatteryManager; /* forward declaration */


/* starting interface:    nsINavigatorBattery */
#define NS_INAVIGATORBATTERY_IID_STR "4a78a8d5-5bbb-4a92-ad97-f19e853a7008"

#define NS_INAVIGATORBATTERY_IID \
  {0x4a78a8d5, 0x5bbb, 0x4a92, \
    { 0xad, 0x97, 0xf1, 0x9e, 0x85, 0x3a, 0x70, 0x08 }}

class NS_NO_VTABLE nsINavigatorBattery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVIGATORBATTERY_IID)

  /* readonly attribute nsIDOMBatteryManager battery; */
  NS_IMETHOD GetBattery(nsIDOMBatteryManager * *aBattery) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavigatorBattery, NS_INAVIGATORBATTERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVIGATORBATTERY \
  NS_IMETHOD GetBattery(nsIDOMBatteryManager * *aBattery); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVIGATORBATTERY(_to) \
  NS_IMETHOD GetBattery(nsIDOMBatteryManager * *aBattery) { return _to GetBattery(aBattery); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVIGATORBATTERY(_to) \
  NS_IMETHOD GetBattery(nsIDOMBatteryManager * *aBattery) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBattery(aBattery); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavigatorBattery : public nsINavigatorBattery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVIGATORBATTERY

  nsNavigatorBattery();

private:
  ~nsNavigatorBattery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavigatorBattery, nsINavigatorBattery)

nsNavigatorBattery::nsNavigatorBattery()
{
  /* member initializers and constructor code */
}

nsNavigatorBattery::~nsNavigatorBattery()
{
  /* destructor code */
}

/* readonly attribute nsIDOMBatteryManager battery; */
NS_IMETHODIMP nsNavigatorBattery::GetBattery(nsIDOMBatteryManager * *aBattery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavigatorBattery_h__ */
