// Decad2Hex.h : main header file for the DECAD2HEX application
//

#if !defined(AFX_DECAD2HEX_H__F33B5A56_62A0_4829_9104_D7C76952E653__INCLUDED_)
#define AFX_DECAD2HEX_H__F33B5A56_62A0_4829_9104_D7C76952E653__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDecad2HexApp:
// See Decad2Hex.cpp for the implementation of this class
//

class CDecad2HexApp : public CWinApp
{
public:
	CDecad2HexApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDecad2HexApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDecad2HexApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DECAD2HEX_H__F33B5A56_62A0_4829_9104_D7C76952E653__INCLUDED_)
