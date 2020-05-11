// Tab.h : main header file for the TAB application
//

#if !defined(AFX_TAB_H__30E86678_33EF_44C0_BB28_8CDC41DCDAD9__INCLUDED_)
#define AFX_TAB_H__30E86678_33EF_44C0_BB28_8CDC41DCDAD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTabApp:
// See Tab.cpp for the implementation of this class
//

class CTabApp : public CWinApp
{
public:
	CTabApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTabApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAB_H__30E86678_33EF_44C0_BB28_8CDC41DCDAD9__INCLUDED_)
