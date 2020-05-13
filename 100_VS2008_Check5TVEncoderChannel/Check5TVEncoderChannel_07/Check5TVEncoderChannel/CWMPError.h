// CWMPError.h  : 以 Microsoft Visual C++ 建立之 ActiveX 控制項包裝函式類別的宣告

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CWMPError

class CWMPError : public COleDispatchDriver
{
public:
	CWMPError() {}		// 呼叫 COleDispatchDriver 預設建構函式
	CWMPError(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPError(const CWMPError& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// 屬性
public:

// 作業
public:

	void clearErrorQueue()
	{
		InvokeHelper(0x353, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_errorCount()
	{
		long result;
		InvokeHelper(0x354, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Item(long dwIndex)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x355, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, dwIndex);
		return result;
	}
	void webHelp()
	{
		InvokeHelper(0x356, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}


};
