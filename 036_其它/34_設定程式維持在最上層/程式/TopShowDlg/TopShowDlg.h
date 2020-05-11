// TopShowDlg.h : main header file for the TOPSHOWDLG application
//

#if !defined(AFX_TOPSHOWDLG_H__88A70084_239B_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOPSHOWDLG_H__88A70084_239B_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTopShowDlgApp:
// See TopShowDlg.cpp for the implementation of this class
//

class CTopShowDlgApp : public CWinApp
{
public:
	CTopShowDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopShowDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTopShowDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPSHOWDLG_H__88A70084_239B_11DA_B776_0040F43A9B72__INCLUDED_)
