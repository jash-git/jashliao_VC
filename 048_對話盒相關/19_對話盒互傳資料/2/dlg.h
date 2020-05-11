// dlg.h : main header file for the DLG application
//

#if !defined(AFX_DLG_H__897BC6F7_99E8_405C_A3AC_CF0368239156__INCLUDED_)
#define AFX_DLG_H__897BC6F7_99E8_405C_A3AC_CF0368239156__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgApp:
// See dlg.cpp for the implementation of this class
//

class CDlgApp : public CWinApp
{
public:
	CDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__897BC6F7_99E8_405C_A3AC_CF0368239156__INCLUDED_)
