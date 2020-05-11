// button.h : main header file for the BUTTON application
//

#if !defined(AFX_BUTTON_H__4ECA1E21_039B_415C_B8D5_8E3E052739F6__INCLUDED_)
#define AFX_BUTTON_H__4ECA1E21_039B_415C_B8D5_8E3E052739F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CButtonApp:
// See button.cpp for the implementation of this class
//

class CButtonApp : public CWinApp
{
public:
	CButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTON_H__4ECA1E21_039B_415C_B8D5_8E3E052739F6__INCLUDED_)
