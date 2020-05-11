// String_test.h : main header file for the STRING_TEST application
//

#if !defined(AFX_STRING_TEST_H__C9C276D7_6201_44AE_959A_9E11F0657A63__INCLUDED_)
#define AFX_STRING_TEST_H__C9C276D7_6201_44AE_959A_9E11F0657A63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CString_testApp:
// See String_test.cpp for the implementation of this class
//

class CString_testApp : public CWinApp
{
public:
	CString_testApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CString_testApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CString_testApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRING_TEST_H__C9C276D7_6201_44AE_959A_9E11F0657A63__INCLUDED_)
