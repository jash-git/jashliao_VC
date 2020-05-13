// UpdateProgram.h : main header file for the UPDATEPROGRAM application
//

#if !defined(AFX_UPDATEPROGRAM_H__4507B3F6_FC21_40B8_BB5D_890931CD76D1__INCLUDED_)
#define AFX_UPDATEPROGRAM_H__4507B3F6_FC21_40B8_BB5D_890931CD76D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUpdateProgramApp:
// See UpdateProgram.cpp for the implementation of this class
//

class CUpdateProgramApp : public CWinApp
{
public:
	CUpdateProgramApp();
	BOOL FirstInstance();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateProgramApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUpdateProgramApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEPROGRAM_H__4507B3F6_FC21_40B8_BB5D_890931CD76D1__INCLUDED_)
