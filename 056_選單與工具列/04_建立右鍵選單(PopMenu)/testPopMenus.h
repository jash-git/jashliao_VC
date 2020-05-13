// testPopMenus.h : main header file for the TESTPOPMENUS application
//

#if !defined(AFX_TESTPOPMENUS_H__FB0F6190_C08E_4C90_A1CD_983F1319CA80__INCLUDED_)
#define AFX_TESTPOPMENUS_H__FB0F6190_C08E_4C90_A1CD_983F1319CA80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusApp:
// See testPopMenus.cpp for the implementation of this class
//

class CTestPopMenusApp : public CWinApp
{
public:
	CTestPopMenusApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPopMenusApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestPopMenusApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPOPMENUS_H__FB0F6190_C08E_4C90_A1CD_983F1319CA80__INCLUDED_)
