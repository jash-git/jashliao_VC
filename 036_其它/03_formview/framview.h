// framview.h : main header file for the FRAMVIEW application
//

#if !defined(AFX_FRAMVIEW_H__06852EB7_2062_46D5_BA4E_78975B8F8AC5__INCLUDED_)
#define AFX_FRAMVIEW_H__06852EB7_2062_46D5_BA4E_78975B8F8AC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFramviewApp:
// See framview.cpp for the implementation of this class
//

class CFramviewApp : public CWinApp
{
public:
	CFramviewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFramviewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFramviewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMVIEW_H__06852EB7_2062_46D5_BA4E_78975B8F8AC5__INCLUDED_)
