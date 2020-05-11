// test_IP_Box.h : main header file for the TEST_IP_BOX application
//

#if !defined(AFX_TEST_IP_BOX_H__3346DE50_8983_44B0_B793_AE9A3E3B81A0__INCLUDED_)
#define AFX_TEST_IP_BOX_H__3346DE50_8983_44B0_B793_AE9A3E3B81A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_IP_BoxApp:
// See test_IP_Box.cpp for the implementation of this class
//

class CTest_IP_BoxApp : public CWinApp
{
public:
	CTest_IP_BoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_IP_BoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_IP_BoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_IP_BOX_H__3346DE50_8983_44B0_B793_AE9A3E3B81A0__INCLUDED_)
