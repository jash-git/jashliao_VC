// MenuCtrl.h : main header file for the MENUCTRL application
//

#if !defined(AFX_MENUCTRL_H__E2787184_2F34_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_MENUCTRL_H__E2787184_2F34_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlApp:
// See MenuCtrl.cpp for the implementation of this class
//

class CMenuCtrlApp : public CWinApp
{
public:
	CMenuCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMenuCtrlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUCTRL_H__E2787184_2F34_11DA_B776_0040F43A9B72__INCLUDED_)
