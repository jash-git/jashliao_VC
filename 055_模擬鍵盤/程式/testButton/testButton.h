// testButton.h : main header file for the TESTBUTTON application
//

#if !defined(AFX_TESTBUTTON_H__19DE5384_170F_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TESTBUTTON_H__19DE5384_170F_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestButtonApp:
// See testButton.cpp for the implementation of this class
//

class CTestButtonApp : public CWinApp
{
public:
	CTestButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTBUTTON_H__19DE5384_170F_11DA_B776_0040F43A9B72__INCLUDED_)
