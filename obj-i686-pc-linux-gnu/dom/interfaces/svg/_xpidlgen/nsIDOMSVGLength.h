/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /home/txema/work/firefox-20.0+build1/dom/interfaces/svg/nsIDOMSVGLength.idl
 */

#ifndef __gen_nsIDOMSVGLength_h__
#define __gen_nsIDOMSVGLength_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGLength */
#define NS_IDOMSVGLENGTH_IID_STR "2596325c-aed0-487e-96a1-0a6d589b9c6b"

#define NS_IDOMSVGLENGTH_IID \
  {0x2596325c, 0xaed0, 0x487e, \
    { 0x96, 0xa1, 0x0a, 0x6d, 0x58, 0x9b, 0x9c, 0x6b }}

class NS_NO_VTABLE nsIDOMSVGLength : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGLENGTH_IID)

  enum {
    SVG_LENGTHTYPE_UNKNOWN = 0U,
    SVG_LENGTHTYPE_NUMBER = 1U,
    SVG_LENGTHTYPE_PERCENTAGE = 2U,
    SVG_LENGTHTYPE_EMS = 3U,
    SVG_LENGTHTYPE_EXS = 4U,
    SVG_LENGTHTYPE_PX = 5U,
    SVG_LENGTHTYPE_CM = 6U,
    SVG_LENGTHTYPE_MM = 7U,
    SVG_LENGTHTYPE_IN = 8U,
    SVG_LENGTHTYPE_PT = 9U,
    SVG_LENGTHTYPE_PC = 10U
  };

  /* readonly attribute unsigned short unitType; */
  NS_IMETHOD GetUnitType(uint16_t *aUnitType) = 0;

  /* attribute float value; */
  NS_IMETHOD GetValue(float *aValue) = 0;
  NS_IMETHOD SetValue(float aValue) = 0;

  /* attribute float valueInSpecifiedUnits; */
  NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits) = 0;
  NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits) = 0;

  /* attribute DOMString valueAsString; */
  NS_IMETHOD GetValueAsString(nsAString & aValueAsString) = 0;
  NS_IMETHOD SetValueAsString(const nsAString & aValueAsString) = 0;

  /* void newValueSpecifiedUnits (in unsigned short unitType, in float valueInSpecifiedUnits); */
  NS_IMETHOD NewValueSpecifiedUnits(uint16_t unitType, float valueInSpecifiedUnits) = 0;

  /* void convertToSpecifiedUnits (in unsigned short unitType); */
  NS_IMETHOD ConvertToSpecifiedUnits(uint16_t unitType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGLength, NS_IDOMSVGLENGTH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGLENGTH \
  NS_IMETHOD GetUnitType(uint16_t *aUnitType); \
  NS_IMETHOD GetValue(float *aValue); \
  NS_IMETHOD SetValue(float aValue); \
  NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits); \
  NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits); \
  NS_IMETHOD GetValueAsString(nsAString & aValueAsString); \
  NS_IMETHOD SetValueAsString(const nsAString & aValueAsString); \
  NS_IMETHOD NewValueSpecifiedUnits(uint16_t unitType, float valueInSpecifiedUnits); \
  NS_IMETHOD ConvertToSpecifiedUnits(uint16_t unitType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGLENGTH(_to) \
  NS_IMETHOD GetUnitType(uint16_t *aUnitType) { return _to GetUnitType(aUnitType); } \
  NS_IMETHOD GetValue(float *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(float aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits) { return _to GetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits) { return _to SetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_IMETHOD GetValueAsString(nsAString & aValueAsString) { return _to GetValueAsString(aValueAsString); } \
  NS_IMETHOD SetValueAsString(const nsAString & aValueAsString) { return _to SetValueAsString(aValueAsString); } \
  NS_IMETHOD NewValueSpecifiedUnits(uint16_t unitType, float valueInSpecifiedUnits) { return _to NewValueSpecifiedUnits(unitType, valueInSpecifiedUnits); } \
  NS_IMETHOD ConvertToSpecifiedUnits(uint16_t unitType) { return _to ConvertToSpecifiedUnits(unitType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGLENGTH(_to) \
  NS_IMETHOD GetUnitType(uint16_t *aUnitType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnitType(aUnitType); } \
  NS_IMETHOD GetValue(float *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(float aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_IMETHOD GetValueAsString(nsAString & aValueAsString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueAsString(aValueAsString); } \
  NS_IMETHOD SetValueAsString(const nsAString & aValueAsString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValueAsString(aValueAsString); } \
  NS_IMETHOD NewValueSpecifiedUnits(uint16_t unitType, float valueInSpecifiedUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewValueSpecifiedUnits(unitType, valueInSpecifiedUnits); } \
  NS_IMETHOD ConvertToSpecifiedUnits(uint16_t unitType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToSpecifiedUnits(unitType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGLength : public nsIDOMSVGLength
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGLENGTH

  nsDOMSVGLength();

private:
  ~nsDOMSVGLength();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGLength, nsIDOMSVGLength)

nsDOMSVGLength::nsDOMSVGLength()
{
  /* member initializers and constructor code */
}

nsDOMSVGLength::~nsDOMSVGLength()
{
  /* destructor code */
}

/* readonly attribute unsigned short unitType; */
NS_IMETHODIMP nsDOMSVGLength::GetUnitType(uint16_t *aUnitType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float value; */
NS_IMETHODIMP nsDOMSVGLength::GetValue(float *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGLength::SetValue(float aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float valueInSpecifiedUnits; */
NS_IMETHODIMP nsDOMSVGLength::GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGLength::SetValueInSpecifiedUnits(float aValueInSpecifiedUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString valueAsString; */
NS_IMETHODIMP nsDOMSVGLength::GetValueAsString(nsAString & aValueAsString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGLength::SetValueAsString(const nsAString & aValueAsString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newValueSpecifiedUnits (in unsigned short unitType, in float valueInSpecifiedUnits); */
NS_IMETHODIMP nsDOMSVGLength::NewValueSpecifiedUnits(uint16_t unitType, float valueInSpecifiedUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void convertToSpecifiedUnits (in unsigned short unitType); */
NS_IMETHODIMP nsDOMSVGLength::ConvertToSpecifiedUnits(uint16_t unitType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGLength_h__ */
