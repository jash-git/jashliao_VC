// test_read_msg.h : main header file for the TEST_READ_MSG application
//

#if !defined(AFX_TEST_READ_MSG_H__1A312F73_2C00_4EDC_B258_4AD59C4B7F9F__INCLUDED_)
#define AFX_TEST_READ_MSG_H__1A312F73_2C00_4EDC_B258_4AD59C4B7F9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_read_msgApp:
// See test_read_msg.cpp for the implementation of this class
//

class CTest_read_msgApp : public CWinApp
{
public:
	CTest_read_msgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_read_msgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_read_msgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_READ_MSG_H__1A312F73_2C00_4EDC_B258_4AD59C4B7F9F__INCLUDED_)
