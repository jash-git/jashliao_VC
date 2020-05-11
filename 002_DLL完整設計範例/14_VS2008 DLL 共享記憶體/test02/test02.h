// test02.h : main header file for the TEST02 application
//

#if !defined(AFX_TEST02_H__499C4FFE_69B4_4ABC_BF52_8F8B9940F016__INCLUDED_)
#define AFX_TEST02_H__499C4FFE_69B4_4ABC_BF52_8F8B9940F016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest02App:
// See test02.cpp for the implementation of this class
//

class CTest02App : public CWinApp
{
public:
	CTest02App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest02App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest02App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST02_H__499C4FFE_69B4_4ABC_BF52_8F8B9940F016__INCLUDED_)
