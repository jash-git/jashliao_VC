// LK_G.h : main header file for the LK_G application
//

#if !defined(AFX_LK_G_H__AAA39D5B_9E46_4C5F_9CA2_8BB4916FF0F8__INCLUDED_)
#define AFX_LK_G_H__AAA39D5B_9E46_4C5F_9CA2_8BB4916FF0F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLK_GApp:
// See LK_G.cpp for the implementation of this class
//

class CLK_GApp : public CWinApp
{
public:
	CLK_GApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLK_GApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLK_GApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LK_G_H__AAA39D5B_9E46_4C5F_9CA2_8BB4916FF0F8__INCLUDED_)
