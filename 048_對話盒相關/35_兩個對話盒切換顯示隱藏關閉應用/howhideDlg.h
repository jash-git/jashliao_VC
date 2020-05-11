// howhideDlg.h : main header file for the HOWHIDEDLG application
//

#if !defined(AFX_HOWHIDEDLG_H__9C3C0087_413B_4331_A948_C66680084CE6__INCLUDED_)
#define AFX_HOWHIDEDLG_H__9C3C0087_413B_4331_A948_C66680084CE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHowhideDlgApp:
// See howhideDlg.cpp for the implementation of this class
//

class CHowhideDlgApp : public CWinApp
{
public:
	CHowhideDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHowhideDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHowhideDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOWHIDEDLG_H__9C3C0087_413B_4331_A948_C66680084CE6__INCLUDED_)
