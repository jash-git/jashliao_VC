// CWMPStringCollection2.h  : 以 Microsoft Visual C++ 建立之 ActiveX 控制項包裝函式類別的宣告

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CWMPStringCollection2

class CWMPStringCollection2 : public COleDispatchDriver
{
public:
	CWMPStringCollection2() {}		// 呼叫 COleDispatchDriver 預設建構函式
	CWMPStringCollection2(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPStringCollection2(const CWMPStringCollection2& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// 屬性
public:

// 作業
public:

	long get_count()
	{
		long result;
		InvokeHelper(0x191, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString Item(long lIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x192, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lIndex);
		return result;
	}
	BOOL isIdentical(LPDISPATCH pIWMPStringCollection2)
	{
		BOOL result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x5ab, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, pIWMPStringCollection2);
		return result;
	}
	CString getItemInfo(long lCollectionIndex, LPCTSTR bstrItemName)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x5ac, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lCollectionIndex, bstrItemName);
		return result;
	}
	long getAttributeCountByType(long lCollectionIndex, LPCTSTR bstrType, LPCTSTR bstrLanguage)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x5ad, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lCollectionIndex, bstrType, bstrLanguage);
		return result;
	}
	VARIANT getItemInfoByType(long lCollectionIndex, LPCTSTR bstrType, LPCTSTR bstrLanguage, long lAttributeIndex)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 ;
		InvokeHelper(0x5ae, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, lCollectionIndex, bstrType, bstrLanguage, lAttributeIndex);
		return result;
	}


};
