// ShowPath.h : main header file for the SHOWPATH application
//

#if !defined(AFX_SHOWPATH_H__078DF7FF_D605_47AE_BDBF_1DD967083AA7__INCLUDED_)
#define AFX_SHOWPATH_H__078DF7FF_D605_47AE_BDBF_1DD967083AA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowPathApp:
// See ShowPath.cpp for the implementation of this class
//

class CShowPathApp : public CWinApp
{
public:
	CShowPathApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowPathApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowPathApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWPATH_H__078DF7FF_D605_47AE_BDBF_1DD967083AA7__INCLUDED_)
