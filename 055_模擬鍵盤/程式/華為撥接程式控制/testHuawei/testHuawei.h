// testHuawei.h : main header file for the TESTHUAWEI application
//

#if !defined(AFX_TESTHUAWEI_H__41087CF9_FCC3_425B_87F1_21D586DE9011__INCLUDED_)
#define AFX_TESTHUAWEI_H__41087CF9_FCC3_425B_87F1_21D586DE9011__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestHuaweiApp:
// See testHuawei.cpp for the implementation of this class
//

class CTestHuaweiApp : public CWinApp
{
public:
	CTestHuaweiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestHuaweiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestHuaweiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTHUAWEI_H__41087CF9_FCC3_425B_87F1_21D586DE9011__INCLUDED_)
