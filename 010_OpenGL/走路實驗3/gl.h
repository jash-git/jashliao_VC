// gl.h : main header file for the GL application
//

#if !defined(AFX_GL_H__67C8FA27_60B1_424C_8C2B_A375E9680258__INCLUDED_)
#define AFX_GL_H__67C8FA27_60B1_424C_8C2B_A375E9680258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGlApp:
// See gl.cpp for the implementation of this class
//

class CGlApp : public CWinApp
{
public:
	CGlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GL_H__67C8FA27_60B1_424C_8C2B_A375E9680258__INCLUDED_)
