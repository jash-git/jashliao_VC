// test_ChangeDesktop.h : main header file for the TEST_CHANGEDESKTOP application
//

#if !defined(AFX_TEST_CHANGEDESKTOP_H__FCC32EAB_FAB1_4FAE_8813_EBB00626A563__INCLUDED_)
#define AFX_TEST_CHANGEDESKTOP_H__FCC32EAB_FAB1_4FAE_8813_EBB00626A563__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_ChangeDesktopApp:
// See test_ChangeDesktop.cpp for the implementation of this class
//

class CTest_ChangeDesktopApp : public CWinApp
{
public:
	CTest_ChangeDesktopApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_ChangeDesktopApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_ChangeDesktopApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CHANGEDESKTOP_H__FCC32EAB_FAB1_4FAE_8813_EBB00626A563__INCLUDED_)
