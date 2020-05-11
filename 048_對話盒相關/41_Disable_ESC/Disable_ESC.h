// Disable_ESC.h : main header file for the DISABLE_ESC application
//

#if !defined(AFX_DISABLE_ESC_H__F7370DF9_F2A7_41DF_92B9_B71B02C4BF3B__INCLUDED_)
#define AFX_DISABLE_ESC_H__F7370DF9_F2A7_41DF_92B9_B71B02C4BF3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDisable_ESCApp:
// See Disable_ESC.cpp for the implementation of this class
//

class CDisable_ESCApp : public CWinApp
{
public:
	CDisable_ESCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisable_ESCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDisable_ESCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISABLE_ESC_H__F7370DF9_F2A7_41DF_92B9_B71B02C4BF3B__INCLUDED_)
