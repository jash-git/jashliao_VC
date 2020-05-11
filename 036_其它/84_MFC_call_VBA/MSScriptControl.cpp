// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"

#include "MSScriptControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IScriptControl operations

void IScriptControl::SetLanguage(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x5dc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void IScriptControl::SetSitehWnd(HWND hWnd)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x5de, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 hWnd);
}

LPDISPATCH IScriptControl::GetError()
{
	LPDISPATCH result;
	InvokeHelper(0x5e3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void IScriptControl::AddObject(LPCTSTR Name, LPDISPATCH Object, BOOL AddMembers)
{
	static BYTE parms[] =
		VTS_BSTR VTS_DISPATCH VTS_BOOL;
	InvokeHelper(0x9c4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name, Object, AddMembers);
}

void IScriptControl::AddCode(LPCTSTR Code)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x7d0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Code);
}

/////////////////////////////////////////////////////////////////////////////
// IScriptError operations

long IScriptError::GetNumber()
{
	long result;
	InvokeHelper(0xc9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IScriptError::GetLine()
{
	long result;
	InvokeHelper(0xce, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long IScriptError::GetColumn()
{
	long result;
	InvokeHelper(0xfffffdef, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CString IScriptError::GetText()
{
	CString result;
	InvokeHelper(DISPID_TEXT, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}