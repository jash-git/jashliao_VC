// VFWDlg.h : main header file for the VFWDLG application
//

#if !defined(AFX_VFWDLG_H__7C1141EB_132C_45F5_BA68_9E10674AC899__INCLUDED_)
#define AFX_VFWDLG_H__7C1141EB_132C_45F5_BA68_9E10674AC899__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVFWDlgApp:
// See VFWDlg.cpp for the implementation of this class
//

class CVFWDlgApp : public CWinApp
{
public:
	CVFWDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVFWDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVFWDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VFWDLG_H__7C1141EB_132C_45F5_BA68_9E10674AC899__INCLUDED_)
