// test_ctrl.h : main header file for the TEST_CTRL application
//

#if !defined(AFX_TEST_CTRL_H__2ECE0168_449F_4CF2_BD5F_B130D52101C1__INCLUDED_)
#define AFX_TEST_CTRL_H__2ECE0168_449F_4CF2_BD5F_B130D52101C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_ctrlApp:
// See test_ctrl.cpp for the implementation of this class
//

class CTest_ctrlApp : public CWinApp
{
public:
	CTest_ctrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_ctrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_ctrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CTRL_H__2ECE0168_449F_4CF2_BD5F_B130D52101C1__INCLUDED_)
