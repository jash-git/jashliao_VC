// MFCDLL.h : MFCDLL DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號


// CMFCDLLApp
// 這個類別的實作請參閱 MFCDLL.cpp
//
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall

int EXPORTED_DLL_FUNCTION add (int a, int b);
class CMFCDLLApp : public CWinApp
{
public:
	CMFCDLLApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
