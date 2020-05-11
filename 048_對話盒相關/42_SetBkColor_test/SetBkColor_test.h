// SetBkColor_test.h : main header file for the SETBKCOLOR_TEST application
//

#if !defined(AFX_SETBKCOLOR_TEST_H__9D8A556D_322D_497C_9D27_F76CBB38090C__INCLUDED_)
#define AFX_SETBKCOLOR_TEST_H__9D8A556D_322D_497C_9D27_F76CBB38090C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSetBkColor_testApp:
// See SetBkColor_test.cpp for the implementation of this class
//

class CSetBkColor_testApp : public CWinApp
{
public:
	CSetBkColor_testApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetBkColor_testApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSetBkColor_testApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETBKCOLOR_TEST_H__9D8A556D_322D_497C_9D27_F76CBB38090C__INCLUDED_)
