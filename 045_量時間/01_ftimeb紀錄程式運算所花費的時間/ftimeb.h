// ftimeb.h : main header file for the FTIMEB application
//

#if !defined(AFX_FTIMEB_H__244A96B4_7AAD_4126_B0EC_2ED5EEC8F5AF__INCLUDED_)
#define AFX_FTIMEB_H__244A96B4_7AAD_4126_B0EC_2ED5EEC8F5AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFtimebApp:
// See ftimeb.cpp for the implementation of this class
//

class CFtimebApp : public CWinApp
{
public:
	CFtimebApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFtimebApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFtimebApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTIMEB_H__244A96B4_7AAD_4126_B0EC_2ED5EEC8F5AF__INCLUDED_)
