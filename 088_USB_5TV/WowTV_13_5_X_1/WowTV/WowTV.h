// WowTV.h : main header file for the WOWTV application
//

#if !defined(AFX_WOWTV_H__613C23A7_0178_4BC2_8F4D_DD8903AD6BB7__INCLUDED_)
#define AFX_WOWTV_H__613C23A7_0178_4BC2_8F4D_DD8903AD6BB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWowTVApp:
// See WowTV.cpp for the implementation of this class
//

class CWowTVApp : public CWinApp
{
public:
	CWowTVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWowTVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWowTVApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WOWTV_H__613C23A7_0178_4BC2_8F4D_DD8903AD6BB7__INCLUDED_)
