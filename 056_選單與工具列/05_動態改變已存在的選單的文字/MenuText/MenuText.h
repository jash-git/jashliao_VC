// MenuText.h : main header file for the MENUTEXT application
//

#if !defined(AFX_MENUTEXT_H__FC8F6A99_65E6_446C_9DE0_A8E0890252D6__INCLUDED_)
#define AFX_MENUTEXT_H__FC8F6A99_65E6_446C_9DE0_A8E0890252D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenuTextApp:
// See MenuText.cpp for the implementation of this class
//

class CMenuTextApp : public CWinApp
{
public:
	CMenuTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMenuTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUTEXT_H__FC8F6A99_65E6_446C_9DE0_A8E0890252D6__INCLUDED_)
