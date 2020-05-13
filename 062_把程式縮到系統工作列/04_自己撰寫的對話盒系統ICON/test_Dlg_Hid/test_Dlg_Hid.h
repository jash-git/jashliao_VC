// test_Dlg_Hid.h : main header file for the TEST_DLG_HID application
//

#if !defined(AFX_TEST_DLG_HID_H__A5E2CD7A_D6DC_489B_B8ED_0D497816C5AF__INCLUDED_)
#define AFX_TEST_DLG_HID_H__A5E2CD7A_D6DC_489B_B8ED_0D497816C5AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_Dlg_HidApp:
// See test_Dlg_Hid.cpp for the implementation of this class
//

class CTest_Dlg_HidApp : public CWinApp
{
public:
	CTest_Dlg_HidApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Dlg_HidApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_Dlg_HidApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_DLG_HID_H__A5E2CD7A_D6DC_489B_B8ED_0D497816C5AF__INCLUDED_)
