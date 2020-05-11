// matrix1to2to1.h : main header file for the MATRIX1TO2TO1 DLL
//

#if !defined(AFX_MATRIX1TO2TO1_H__D1ADAC91_6225_4C13_A5A3_EA6E10895CF0__INCLUDED_)
#define AFX_MATRIX1TO2TO1_H__D1ADAC91_6225_4C13_A5A3_EA6E10895CF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMatrix1to2to1App
// See matrix1to2to1.cpp for the implementation of this class
//
int **image_in;
long lngSize;
int gx,gy;
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall

void EXPORTED_DLL_FUNCTION GetValue1(long *p,long x,long y);
void EXPORTED_DLL_FUNCTION SetValue1(long *p);
void EXPORTED_DLL_FUNCTION SetValue2(long *p);
void EXPORTED_DLL_FUNCTION DeleteArray();
class CMatrix1to2to1App : public CWinApp
{
public:
	CMatrix1to2to1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatrix1to2to1App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMatrix1to2to1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATRIX1TO2TO1_H__D1ADAC91_6225_4C13_A5A3_EA6E10895CF0__INCLUDED_)
