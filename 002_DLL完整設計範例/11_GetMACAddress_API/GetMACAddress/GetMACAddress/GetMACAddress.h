// GetMACAddress.h : GetMACAddress DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號
///////////////////////////////////////////
//step 01 by jash at 2010/10/20
#include <Iphlpapi.h>
#include <Assert.h>
#include <stdio.h>
#pragma comment(lib, "iphlpapi.lib")
//////////////////////////////////////////
// CGetMACAddressApp
// 這個類別的實作請參閱 GetMACAddress.cpp
//
////////////////////////////////////////////////////////////////
//step 02 by jash at 2010/10/20
#define EXPORTED_DLL_FUNCTION \
__declspec(dllexport) __stdcall
BSTR EXPORTED_DLL_FUNCTION GetMACAddress ();
/////////////////////////////////////////////////////////////////
class CGetMACAddressApp : public CWinApp
{
public:
	CGetMACAddressApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
