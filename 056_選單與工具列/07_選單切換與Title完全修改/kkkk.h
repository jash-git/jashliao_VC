// kkkk.h : main header file for the KKKK application
//

#if !defined(AFX_KKKK_H__CEDBB5BE_06B9_4C1A_8940_C2C7467A644A__INCLUDED_)
#define AFX_KKKK_H__CEDBB5BE_06B9_4C1A_8940_C2C7467A644A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKkkkApp:
// See kkkk.cpp for the implementation of this class
//

class CKkkkApp : public CWinApp
{
public:
	CKkkkApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKkkkApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKkkkApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KKKK_H__CEDBB5BE_06B9_4C1A_8940_C2C7467A644A__INCLUDED_)
