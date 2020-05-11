// GetPathAndName.h : main header file for the GETPATHANDNAME application
//

#if !defined(AFX_GETPATHANDNAME_H__4DD71A1E_FF2D_4D78_8C70_08C32B688880__INCLUDED_)
#define AFX_GETPATHANDNAME_H__4DD71A1E_FF2D_4D78_8C70_08C32B688880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetPathAndNameApp:
// See GetPathAndName.cpp for the implementation of this class
//

class CGetPathAndNameApp : public CWinApp
{
public:
	CGetPathAndNameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPathAndNameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetPathAndNameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPATHANDNAME_H__4DD71A1E_FF2D_4D78_8C70_08C32B688880__INCLUDED_)
