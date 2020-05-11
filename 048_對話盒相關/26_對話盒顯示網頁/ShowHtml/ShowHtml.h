// ShowHtml.h : main header file for the SHOWHTML application
//

#if !defined(AFX_SHOWHTML_H__68665645_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_)
#define AFX_SHOWHTML_H__68665645_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlApp:
// See ShowHtml.cpp for the implementation of this class
//

class CShowHtmlApp : public CWinApp
{
public:
	CShowHtmlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowHtmlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowHtmlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWHTML_H__68665645_7E11_11D7_886E_8A3E70C5F33E__INCLUDED_)
