// zipdlg.h : main header file for the ZIPDLG application
//

#if !defined(AFX_ZIPDLG_H__553DDFE6_1BD5_11D5_9158_0020183C9DA9__INCLUDED_)
#define AFX_ZIPDLG_H__553DDFE6_1BD5_11D5_9158_0020183C9DA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZipdlgApp:
// See zipdlg.cpp for the implementation of this class
//

class CZipdlgApp : public CWinApp
{
public:
	CZipdlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZipdlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZipdlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZIPDLG_H__553DDFE6_1BD5_11D5_9158_0020183C9DA9__INCLUDED_)
