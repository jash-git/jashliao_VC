// dlltest.h : main header file for the DLLTEST application
//

#if !defined(AFX_DLLTEST_H__8C37C880_2FAD_4998_B950_64B2BA28C6E0__INCLUDED_)
#define AFX_DLLTEST_H__8C37C880_2FAD_4998_B950_64B2BA28C6E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlltestApp:
// See dlltest.cpp for the implementation of this class
//

class CDlltestApp : public CWinApp
{
public:
	CDlltestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlltestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlltestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLTEST_H__8C37C880_2FAD_4998_B950_64B2BA28C6E0__INCLUDED_)
