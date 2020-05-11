// Moniter_Set_On_OFF.h : main header file for the MONITER_SET_ON_OFF application
//

#if !defined(AFX_MONITER_SET_ON_OFF_H__D066A1AC_880C_4EA1_87B7_B5BF47E84058__INCLUDED_)
#define AFX_MONITER_SET_ON_OFF_H__D066A1AC_880C_4EA1_87B7_B5BF47E84058__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMoniter_Set_On_OFFApp:
// See Moniter_Set_On_OFF.cpp for the implementation of this class
//

class CMoniter_Set_On_OFFApp : public CWinApp
{
public:
	CMoniter_Set_On_OFFApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoniter_Set_On_OFFApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMoniter_Set_On_OFFApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITER_SET_ON_OFF_H__D066A1AC_880C_4EA1_87B7_B5BF47E84058__INCLUDED_)
