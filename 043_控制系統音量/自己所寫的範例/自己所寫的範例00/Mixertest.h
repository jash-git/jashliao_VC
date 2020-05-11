// Mixertest.h : main header file for the MIXERTEST application
//

#if !defined(AFX_MIXERTEST_H__D220BBBE_64F6_42AA_938F_43DC0928B804__INCLUDED_)
#define AFX_MIXERTEST_H__D220BBBE_64F6_42AA_938F_43DC0928B804__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMixertestApp:
// See Mixertest.cpp for the implementation of this class
//

class CMixertestApp : public CWinApp
{
public:
	CMixertestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMixertestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMixertestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIXERTEST_H__D220BBBE_64F6_42AA_938F_43DC0928B804__INCLUDED_)
