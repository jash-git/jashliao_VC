// add.h : main header file for the ADD application
//

#if !defined(AFX_ADD_H__54F578B4_66B6_45D6_AE4C_909CADF59F67__INCLUDED_)
#define AFX_ADD_H__54F578B4_66B6_45D6_AE4C_909CADF59F67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAddApp:
// See add.cpp for the implementation of this class
//

class CAddApp : public CWinApp
{
public:
	CAddApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAddApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__54F578B4_66B6_45D6_AE4C_909CADF59F67__INCLUDED_)
