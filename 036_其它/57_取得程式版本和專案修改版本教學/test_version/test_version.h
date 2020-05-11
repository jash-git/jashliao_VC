// test_version.h : main header file for the TEST_VERSION application
//

#if !defined(AFX_TEST_VERSION_H__68DE036D_F4B4_4277_8BED_6B8AA5475F4E__INCLUDED_)
#define AFX_TEST_VERSION_H__68DE036D_F4B4_4277_8BED_6B8AA5475F4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_versionApp:
// See test_version.cpp for the implementation of this class
//

class CTest_versionApp : public CWinApp
{
public:
	CTest_versionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_versionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_versionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_VERSION_H__68DE036D_F4B4_4277_8BED_6B8AA5475F4E__INCLUDED_)
