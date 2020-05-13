// 28F_APP.h : main header file for the 28F_APP application
//

#if !defined(AFX_28F_APP_H__67D658ED_F332_4B3D_810D_15BA1DF59FF7__INCLUDED_)
#define AFX_28F_APP_H__67D658ED_F332_4B3D_810D_15BA1DF59FF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy28F_APPApp:
// See 28F_APP.cpp for the implementation of this class
//

class CMy28F_APPApp : public CWinApp
{
public:
	CMy28F_APPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy28F_APPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy28F_APPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_28F_APP_H__67D658ED_F332_4B3D_810D_15BA1DF59FF7__INCLUDED_)
