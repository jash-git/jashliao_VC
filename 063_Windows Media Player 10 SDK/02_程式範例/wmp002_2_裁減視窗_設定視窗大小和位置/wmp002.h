// wmp002.h : main header file for the WMP002 application
//

#if !defined(AFX_WMP002_H__9BD67283_880C_4430_8C77_5793902609E8__INCLUDED_)
#define AFX_WMP002_H__9BD67283_880C_4430_8C77_5793902609E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWmp002App:
// See wmp002.cpp for the implementation of this class
//

class CWmp002App : public CWinApp
{
public:
	CWmp002App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmp002App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWmp002App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMP002_H__9BD67283_880C_4430_8C77_5793902609E8__INCLUDED_)
