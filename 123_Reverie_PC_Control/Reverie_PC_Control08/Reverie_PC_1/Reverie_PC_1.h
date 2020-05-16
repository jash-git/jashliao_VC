// Reverie_PC_1.h : main header file for the REVERIE_PC_1 application
//

#if !defined(AFX_REVERIE_PC_1_H__26E24B23_233A_4465_A3D5_EDCC4EA271E0__INCLUDED_)
#define AFX_REVERIE_PC_1_H__26E24B23_233A_4465_A3D5_EDCC4EA271E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReverie_PC_1App:
// See Reverie_PC_1.cpp for the implementation of this class
//

class CReverie_PC_1App : public CWinApp
{
public:
	CReverie_PC_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReverie_PC_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReverie_PC_1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERIE_PC_1_H__26E24B23_233A_4465_A3D5_EDCC4EA271E0__INCLUDED_)
