// sharemem.h : sharemem DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號


// CsharememApp
// 這個類別的實作請參閱 sharemem.cpp
//
#pragma data_seg("jash")
char chrshare[200]="test";
#pragma data_seg()
#pragma comment(linker, "/Section:jash,RWS")
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall
void EXPORTED_DLL_FUNCTION jashGetValue (char *outData);
void EXPORTED_DLL_FUNCTION jashSetValue (char *inData);
class CsharememApp : public CWinApp
{
public:
	CsharememApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
