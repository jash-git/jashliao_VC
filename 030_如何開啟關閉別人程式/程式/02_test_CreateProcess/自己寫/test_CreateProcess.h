// test_CreateProcess.h : main header file for the TEST_CREATEPROCESS application
//

#if !defined(AFX_TEST_CREATEPROCESS_H__B0DF7189_D8CE_4B7B_B470_11FF8659DF83__INCLUDED_)
#define AFX_TEST_CREATEPROCESS_H__B0DF7189_D8CE_4B7B_B470_11FF8659DF83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_CreateProcessApp:
// See test_CreateProcess.cpp for the implementation of this class
//

class CTest_CreateProcessApp : public CWinApp
{
public:
	CTest_CreateProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_CreateProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_CreateProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CREATEPROCESS_H__B0DF7189_D8CE_4B7B_B470_11FF8659DF83__INCLUDED_)
