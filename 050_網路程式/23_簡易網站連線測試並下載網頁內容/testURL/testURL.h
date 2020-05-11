// testURL.h : main header file for the TESTURL application
//

#if !defined(AFX_TESTURL_H__0D27FF05_AEA9_4BB9_8F9C_53E52F58AC88__INCLUDED_)
#define AFX_TESTURL_H__0D27FF05_AEA9_4BB9_8F9C_53E52F58AC88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestURLApp:
// See testURL.cpp for the implementation of this class
//

class CTestURLApp : public CWinApp
{
public:
	CTestURLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestURLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestURLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTURL_H__0D27FF05_AEA9_4BB9_8F9C_53E52F58AC88__INCLUDED_)
