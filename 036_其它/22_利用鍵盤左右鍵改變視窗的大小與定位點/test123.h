// test123.h : main header file for the TEST123 application
//

#if !defined(AFX_TEST123_H__2430E55B_A4AC_4F9D_9481_129AEA633755__INCLUDED_)
#define AFX_TEST123_H__2430E55B_A4AC_4F9D_9481_129AEA633755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest123App:
// See test123.cpp for the implementation of this class
//

class CTest123App : public CWinApp
{
public:
	CTest123App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest123App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest123App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST123_H__2430E55B_A4AC_4F9D_9481_129AEA633755__INCLUDED_)
