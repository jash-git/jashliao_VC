// view.h : main header file for the VIEW application
//

#if !defined(AFX_VIEW_H__860941CD_D60C_438E_8492_3FC107AF0DBD__INCLUDED_)
#define AFX_VIEW_H__860941CD_D60C_438E_8492_3FC107AF0DBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CViewApp:
// See view.cpp for the implementation of this class
//
class CViewApp : public CWinApp
{
public:
	CViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__860941CD_D60C_438E_8492_3FC107AF0DBD__INCLUDED_)
