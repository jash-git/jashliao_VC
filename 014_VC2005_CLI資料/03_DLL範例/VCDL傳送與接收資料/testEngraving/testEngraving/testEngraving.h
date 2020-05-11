// testEngraving.h : testEngraving DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號


// CtestEngravingApp
// 這個類別的實作請參閱 testEngraving.cpp
//
struct EngarveElement{
	long Type;
	long CCW;
	double X1;
	double Y1;
	double Z1;
	double X2;
	double Y2;
	double Z2;
};

struct point
{
	double x;
	double y;
};
EngarveElement *EE;
long n;
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall
void EXPORTED_DLL_FUNCTION GetValue1(EngarveElement *p,long number);
long EXPORTED_DLL_FUNCTION SendValue1(EngarveElement *p);
class CtestEngravingApp : public CWinApp
{
public:
	CtestEngravingApp();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
