// VFW.h : main header file for the VFW application
//

#if !defined(AFX_VFW_H__555DFC49_F275_416C_9924_F1EAAA9E8512__INCLUDED_)
#define AFX_VFW_H__555DFC49_F275_416C_9924_F1EAAA9E8512__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVFWApp:
// See VFW.cpp for the implementation of this class
//

class CVFWApp : public CWinApp
{
public:
	CVFWApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVFWApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVFWApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VFW_H__555DFC49_F275_416C_9924_F1EAAA9E8512__INCLUDED_)
