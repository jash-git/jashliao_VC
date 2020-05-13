// test_Hide.h : main header file for the TEST_HIDE application
//

#if !defined(AFX_TEST_HIDE_H__17A34818_73A5_40DD_B545_D72631086B86__INCLUDED_)
#define AFX_TEST_HIDE_H__17A34818_73A5_40DD_B545_D72631086B86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_HideApp:
// See test_Hide.cpp for the implementation of this class
//

class CTest_HideApp : public CWinApp
{
public:
	CTest_HideApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_HideApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest_HideApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_HIDE_H__17A34818_73A5_40DD_B545_D72631086B86__INCLUDED_)
