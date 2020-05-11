// testRect.h : main header file for the TESTRECT application
//

#if !defined(AFX_TESTRECT_H__768E1957_905B_4D57_9FF5_2A5E5FDCCE82__INCLUDED_)
#define AFX_TESTRECT_H__768E1957_905B_4D57_9FF5_2A5E5FDCCE82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestRectApp:
// See testRect.cpp for the implementation of this class
//

class CTestRectApp : public CWinApp
{
public:
	CTestRectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestRectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestRectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTRECT_H__768E1957_905B_4D57_9FF5_2A5E5FDCCE82__INCLUDED_)
