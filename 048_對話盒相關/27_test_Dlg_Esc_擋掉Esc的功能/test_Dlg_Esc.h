// test_Dlg_Esc.h : main header file for the TEST_DLG_ESC application
//

#if !defined(AFX_TEST_DLG_ESC_H__952D6074_1B80_45DD_A83A_2558B0DEFFD7__INCLUDED_)
#define AFX_TEST_DLG_ESC_H__952D6074_1B80_45DD_A83A_2558B0DEFFD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_Dlg_EscApp:
// See test_Dlg_Esc.cpp for the implementation of this class
//

class CTest_Dlg_EscApp : public CWinApp
{
public:
	CTest_Dlg_EscApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Dlg_EscApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_Dlg_EscApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_DLG_ESC_H__952D6074_1B80_45DD_A83A_2558B0DEFFD7__INCLUDED_)
