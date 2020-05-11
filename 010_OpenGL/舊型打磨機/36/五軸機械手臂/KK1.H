// kk1.h : main header file for the KK1 application
//

#if !defined(AFX_KK1_H__D97836AD_C33C_483C_9A19_32C1D0EF4EA9__INCLUDED_)
#define AFX_KK1_H__D97836AD_C33C_483C_9A19_32C1D0EF4EA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKk1App:
// See kk1.cpp for the implementation of this class
//

class CKk1App : public CWinApp
{
public:
	CKk1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKk1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKk1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KK1_H__D97836AD_C33C_483C_9A19_32C1D0EF4EA9__INCLUDED_)
