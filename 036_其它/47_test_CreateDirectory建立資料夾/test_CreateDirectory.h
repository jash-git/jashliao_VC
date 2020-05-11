// test_CreateDirectory.h : main header file for the TEST_CREATEDIRECTORY application
//

#if !defined(AFX_TEST_CREATEDIRECTORY_H__B9F2637F_FE39_4D4E_963F_D0AE09B326FD__INCLUDED_)
#define AFX_TEST_CREATEDIRECTORY_H__B9F2637F_FE39_4D4E_963F_D0AE09B326FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_CreateDirectoryApp:
// See test_CreateDirectory.cpp for the implementation of this class
//

class CTest_CreateDirectoryApp : public CWinApp
{
public:
	CTest_CreateDirectoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_CreateDirectoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_CreateDirectoryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CREATEDIRECTORY_H__B9F2637F_FE39_4D4E_963F_D0AE09B326FD__INCLUDED_)
