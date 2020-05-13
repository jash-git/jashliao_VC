// test_msxml4.h : main header file for the TEST_MSXML4 application
//

#if !defined(AFX_TEST_MSXML4_H__D73643FD_008F_4608_B9B2_8E1507CD6856__INCLUDED_)
#define AFX_TEST_MSXML4_H__D73643FD_008F_4608_B9B2_8E1507CD6856__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_msxml4App:
// See test_msxml4.cpp for the implementation of this class
//

class CTest_msxml4App : public CWinApp
{
public:
	CTest_msxml4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_msxml4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_msxml4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_MSXML4_H__D73643FD_008F_4608_B9B2_8E1507CD6856__INCLUDED_)
