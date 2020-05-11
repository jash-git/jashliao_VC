// DC2DC.h : main header file for the DC2DC DLL
//

#if !defined(AFX_DC2DC_H__09BC0DBD_93AC_47EA_A2A8_6D3129742E42__INCLUDED_)
#define AFX_DC2DC_H__09BC0DBD_93AC_47EA_A2A8_6D3129742E42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDC2DCApp
// See DC2DC.cpp for the implementation of this class
//
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall
void EXPORTED_DLL_FUNCTION DC2DC (long GetHDC,int w,int h);
class CDC2DCApp : public CWinApp
{
public:
	CDC2DCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDC2DCApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDC2DCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DC2DC_H__09BC0DBD_93AC_47EA_A2A8_6D3129742E42__INCLUDED_)
