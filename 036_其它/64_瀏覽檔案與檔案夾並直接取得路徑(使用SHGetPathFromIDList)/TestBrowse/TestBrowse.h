// TestBrowse.h : main header file for the TESTBROWSE application
//

#if !defined(AFX_TESTBROWSE_H__14132F9C_DF0C_470E_AD27_F580B616AFFE__INCLUDED_)
#define AFX_TESTBROWSE_H__14132F9C_DF0C_470E_AD27_F580B616AFFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestBrowseApp:
// See TestBrowse.cpp for the implementation of this class
//

class CTestBrowseApp : public CWinApp
{
public:
	CTestBrowseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestBrowseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestBrowseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTBROWSE_H__14132F9C_DF0C_470E_AD27_F580B616AFFE__INCLUDED_)
