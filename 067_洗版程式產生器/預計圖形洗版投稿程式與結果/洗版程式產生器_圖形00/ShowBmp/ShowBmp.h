// ShowBmp.h : main header file for the SHOWBMP application
//

#if !defined(AFX_SHOWBMP_H__5A28F840_8EEA_4339_A197_AA93477C6312__INCLUDED_)
#define AFX_SHOWBMP_H__5A28F840_8EEA_4339_A197_AA93477C6312__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowBmpApp:
// See ShowBmp.cpp for the implementation of this class
//

class CShowBmpApp : public CWinApp
{
public:
	CShowBmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowBmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowBmpApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWBMP_H__5A28F840_8EEA_4339_A197_AA93477C6312__INCLUDED_)
