// Shell.h : main header file for the SHELL application
//

#if !defined(AFX_SHELL_H__B47AE247_3A3E_4CCD_A787_B4BEE6D9C3EC__INCLUDED_)
#define AFX_SHELL_H__B47AE247_3A3E_4CCD_A787_B4BEE6D9C3EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShellApp:
// See Shell.cpp for the implementation of this class
//

class CShellApp : public CWinApp
{
public:
	CShellApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShellApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShellApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHELL_H__B47AE247_3A3E_4CCD_A787_B4BEE6D9C3EC__INCLUDED_)
