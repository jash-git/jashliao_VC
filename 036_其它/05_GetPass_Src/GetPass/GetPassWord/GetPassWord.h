// GetPassWord.h : main header file for the GETPASSWORD application
//

#if !defined(AFX_GETPASSWORD_H__C510F1E8_35F9_4DB9_B8EA_8A9C55F1FC4A__INCLUDED_)
#define AFX_GETPASSWORD_H__C510F1E8_35F9_4DB9_B8EA_8A9C55F1FC4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetPassWordApp:
// See GetPassWord.cpp for the implementation of this class
//

class CGetPassWordApp : public CWinApp
{
public:
	CGetPassWordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPassWordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetPassWordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPASSWORD_H__C510F1E8_35F9_4DB9_B8EA_8A9C55F1FC4A__INCLUDED_)
