// ProjComb.h : main header file for the PROJCOMB application
//

#if !defined(AFX_PROJCOMB_H__750AF404_196E_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_PROJCOMB_H__750AF404_196E_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProjCombApp:
// See ProjComb.cpp for the implementation of this class
//

class CProjCombApp : public CWinApp
{
public:
	CProjCombApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjCombApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProjCombApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJCOMB_H__750AF404_196E_11DA_B776_0040F43A9B72__INCLUDED_)
