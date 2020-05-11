// Engrave32.h : Engrave32 DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號
#include "GlobalVar.h"
#include "RotateVector.h"
#include "SmoothSolution.h"
#include "RipAngle2Vector.h"
//////////////////////////////////////
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall
long EXPORTED_DLL_FUNCTION EngInitial(long lngBlockAmount,double tolerance,long Direction);//取得Block總數，並動態配置記憶體已用來存放每個Block的Entity數量
long EXPORTED_DLL_FUNCTION EngGetValue(EngarveElement *p,long lngBlock,long lngAmount);//資料陣列指標；資料陣列屬於第幾個lngBlock；陣列大小
long EXPORTED_DLL_FUNCTION EngLineLineSolve(const CInputData &BaseInputData,const CInputData &RipInputData,const CPoint3D &RipPoint3D,CCircle *AnsCircle);//線與線求切圓
long EXPORTED_DLL_FUNCTION EngLineArcSolve(const CArc &BaseArc,const CLine &RipLine,const CPoint3D &RipPoint3D,CCircle *AnsCircle);//線與圓弧求切圓
long EXPORTED_DLL_FUNCTION EngArcLineSolve(const CLine &BaseLine,CArc &RipArc,const CPoint3D &RipPoint3D,CCircle *AnsCircle);//圓弧與線求切圓
long EXPORTED_DLL_FUNCTION EngArcArcSolve(const CArc &BaseArc,const CArc &RipArc,const CPoint3D &RipPoint3D,CCircle *AnsCircle);//圓弧與圓弧求切圓
long EXPORTED_DLL_FUNCTION ArcParagraph(CArc &data,const double tolerance);//圓弧求分段點
long EXPORTED_DLL_FUNCTION LineParagraph(CLine &data,const double tolerance);//線求分段點
long EXPORTED_DLL_FUNCTION EngCalculate();//計算核心
long EXPORTED_DLL_FUNCTION BubbleSort(double **p,long n);//二維陣列排序
//////////////////////////////////////////////////////////////////////////////////
// CEngrave32App
// 這個類別的實作請參閱 Engrave32.cpp
//

class CEngrave32App : public CWinApp
{
public:
	CEngrave32App();

// 覆寫
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
