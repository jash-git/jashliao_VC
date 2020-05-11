// Engrave32.h : main header file for the ENGRAVE32 DLL
//

#if !defined(AFX_ENGRAVE32_H__25E608BA_BD32_4ABB_BD1C_D2DE469C37CF__INCLUDED_)
#define AFX_ENGRAVE32_H__25E608BA_BD32_4ABB_BD1C_D2DE469C37CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
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
/////////////////////////////////////////////////////////////////////////////
// CEngrave32App
// See Engrave32.cpp for the implementation of this class
//

class CEngrave32App : public CWinApp
{
public:
	CEngrave32App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEngrave32App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CEngrave32App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGRAVE32_H__25E608BA_BD32_4ABB_BD1C_D2DE469C37CF__INCLUDED_)
