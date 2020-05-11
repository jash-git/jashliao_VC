// test01.h : main header file for the TEST01 application
//

#if !defined(AFX_TEST01_H__5073A893_E780_4730_A1ED_884FDB6854D2__INCLUDED_)
#define AFX_TEST01_H__5073A893_E780_4730_A1ED_884FDB6854D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest01App:
// See test01.cpp for the implementation of this class
//

class CTest01App : public CWinApp
{
public:
	CTest01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest01App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST01_H__5073A893_E780_4730_A1ED_884FDB6854D2__INCLUDED_)
