// test_UI.h : main header file for the TEST_UI application
//

#if !defined(AFX_TEST_UI_H__B1D3BDAB_E165_48AE_B51E_9610C5F8D783__INCLUDED_)
#define AFX_TEST_UI_H__B1D3BDAB_E165_48AE_B51E_9610C5F8D783__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_UIApp:
// See test_UI.cpp for the implementation of this class
//

class CTest_UIApp : public CWinApp
{
public:
	CTest_UIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_UIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_UIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_UI_H__B1D3BDAB_E165_48AE_B51E_9610C5F8D783__INCLUDED_)
