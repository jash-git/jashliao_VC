// PointData.h : main header file for the POINTDATA DLL
//

#if !defined(AFX_POINTDATA_H__91D87243_EE7F_491B_88F6_0C58D42EF062__INCLUDED_)
#define AFX_POINTDATA_H__91D87243_EE7F_491B_88F6_0C58D42EF062__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointDataApp
// See PointData.cpp for the implementation of this class
//
struct point
{
	double x;
	double y;
};
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall

void EXPORTED_DLL_FUNCTION GetValue1(point *p,long number);
class CPointDataApp : public CWinApp
{
public:
	CPointDataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointDataApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPointDataApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTDATA_H__91D87243_EE7F_491B_88F6_0C58D42EF062__INCLUDED_)
