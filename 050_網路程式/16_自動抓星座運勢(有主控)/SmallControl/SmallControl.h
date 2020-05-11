// SmallControl.h : main header file for the SMALLCONTROL application
//

#if !defined(AFX_SMALLCONTROL_H__0915C7AD_4CB7_406F_A30E_723CDCA1DF13__INCLUDED_)
#define AFX_SMALLCONTROL_H__0915C7AD_4CB7_406F_A30E_723CDCA1DF13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSmallControlApp:
// See SmallControl.cpp for the implementation of this class
//

class CSmallControlApp : public CWinApp
{
public:
	CSmallControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSmallControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSmallControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMALLCONTROL_H__0915C7AD_4CB7_406F_A30E_723CDCA1DF13__INCLUDED_)
