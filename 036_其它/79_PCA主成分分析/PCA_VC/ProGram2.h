// ProGram2.h : main header file for the PROGRAM2 application
//

#if !defined(AFX_PROGRAM2_H__FF1D9A4C_2466_49DD_BC9C_98AA7242BD05__INCLUDED_)
#define AFX_PROGRAM2_H__FF1D9A4C_2466_49DD_BC9C_98AA7242BD05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProGram2App:
// See ProGram2.cpp for the implementation of this class
//

class CProGram2App : public CWinApp
{
public:
	CProGram2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProGram2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProGram2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAM2_H__FF1D9A4C_2466_49DD_BC9C_98AA7242BD05__INCLUDED_)
