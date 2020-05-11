// testContrlShow.h : main header file for the TESTCONTRLSHOW application
//

#if !defined(AFX_TESTCONTRLSHOW_H__AB54B225_BE13_413A_A656_8E2A3E338D13__INCLUDED_)
#define AFX_TESTCONTRLSHOW_H__AB54B225_BE13_413A_A656_8E2A3E338D13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestContrlShowApp:
// See testContrlShow.cpp for the implementation of this class
//

class CTestContrlShowApp : public CWinApp
{
public:
	CTestContrlShowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestContrlShowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestContrlShowApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCONTRLSHOW_H__AB54B225_BE13_413A_A656_8E2A3E338D13__INCLUDED_)
