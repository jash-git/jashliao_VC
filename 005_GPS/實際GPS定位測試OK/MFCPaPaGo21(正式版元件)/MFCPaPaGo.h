// MFCPaPaGo.h : main header file for the MFCPAPAGO application
//

#if !defined(AFX_MFCPAPAGO_H__EEC12A70_762B_4F32_8086_1FA94912CE0A__INCLUDED_)
#define AFX_MFCPAPAGO_H__EEC12A70_762B_4F32_8086_1FA94912CE0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoApp:
// See MFCPaPaGo.cpp for the implementation of this class
//

class CMFCPaPaGoApp : public CWinApp
{
public:
	CMFCPaPaGoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCPaPaGoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCPaPaGoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCPAPAGO_H__EEC12A70_762B_4F32_8086_1FA94912CE0A__INCLUDED_)
