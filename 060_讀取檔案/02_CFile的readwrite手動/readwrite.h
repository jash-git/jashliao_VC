// readwrite.h : main header file for the READWRITE application
//

#if !defined(AFX_READWRITE_H__117C632B_E13F_4C70_A884_5D79568D55D3__INCLUDED_)
#define AFX_READWRITE_H__117C632B_E13F_4C70_A884_5D79568D55D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadwriteApp:
// See readwrite.cpp for the implementation of this class
//

class CReadwriteApp : public CWinApp
{
public:
	CReadwriteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadwriteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadwriteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READWRITE_H__117C632B_E13F_4C70_A884_5D79568D55D3__INCLUDED_)
