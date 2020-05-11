// USEActive2IE.h : main header file for the USEACTIVE2IE application
//

#if !defined(AFX_USEACTIVE2IE_H__0103B317_EB8B_49AD_9CF0_C3F2037E7660__INCLUDED_)
#define AFX_USEACTIVE2IE_H__0103B317_EB8B_49AD_9CF0_C3F2037E7660__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUSEActive2IEApp:
// See USEActive2IE.cpp for the implementation of this class
//

class CUSEActive2IEApp : public CWinApp
{
public:
	CUSEActive2IEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUSEActive2IEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUSEActive2IEApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEACTIVE2IE_H__0103B317_EB8B_49AD_9CF0_C3F2037E7660__INCLUDED_)
