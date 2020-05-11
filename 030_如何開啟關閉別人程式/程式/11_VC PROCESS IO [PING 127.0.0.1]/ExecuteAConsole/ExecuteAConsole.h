// ExecuteAConsole.h : main header file for the EXECUTEACONSOLE application
//

#if !defined(AFX_EXECUTEACONSOLE_H__A8C5852E_3A5B_41A2_85F1_0C5D8DCF3BB1__INCLUDED_)
#define AFX_EXECUTEACONSOLE_H__A8C5852E_3A5B_41A2_85F1_0C5D8DCF3BB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExecuteAConsoleApp:
// See ExecuteAConsole.cpp for the implementation of this class
//

class CExecuteAConsoleApp : public CWinApp
{
public:
	CExecuteAConsoleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExecuteAConsoleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExecuteAConsoleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXECUTEACONSOLE_H__A8C5852E_3A5B_41A2_85F1_0C5D8DCF3BB1__INCLUDED_)
