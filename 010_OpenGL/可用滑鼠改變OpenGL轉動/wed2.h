// wed2.h : main header file for the WED2 application
//

#if !defined(AFX_WED2_H__57E69964_0F7C_11D6_A27B_002018393AA2__INCLUDED_)
#define AFX_WED2_H__57E69964_0F7C_11D6_A27B_002018393AA2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWed2App:
// See wed2.cpp for the implementation of this class
//

class CWed2App : public CWinApp
{
public:
	CWed2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWed2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWed2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WED2_H__57E69964_0F7C_11D6_A27B_002018393AA2__INCLUDED_)
