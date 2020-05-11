// Multithread_Struct.h : main header file for the MULTITHREAD_STRUCT application
//

#if !defined(AFX_MULTITHREAD_STRUCT_H__A5E7D7CB_4750_452D_B4B0_2223F2BB342C__INCLUDED_)
#define AFX_MULTITHREAD_STRUCT_H__A5E7D7CB_4750_452D_B4B0_2223F2BB342C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultithread_StructApp:
// See Multithread_Struct.cpp for the implementation of this class
//

class CMultithread_StructApp : public CWinApp
{
public:
	CMultithread_StructApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultithread_StructApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultithread_StructApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD_STRUCT_H__A5E7D7CB_4750_452D_B4B0_2223F2BB342C__INCLUDED_)
