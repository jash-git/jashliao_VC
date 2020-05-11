// SetValue.h : main header file for the SETVALUE application
//

#if !defined(AFX_SETVALUE_H__67E9302C_39D4_4499_8B2D_70CE239A5378__INCLUDED_)
#define AFX_SETVALUE_H__67E9302C_39D4_4499_8B2D_70CE239A5378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSetValueApp:
// See SetValue.cpp for the implementation of this class
//

class CSetValueApp : public CWinApp
{
public:
	CSetValueApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetValueApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSetValueApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETVALUE_H__67E9302C_39D4_4499_8B2D_70CE239A5378__INCLUDED_)
