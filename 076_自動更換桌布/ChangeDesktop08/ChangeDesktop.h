// ChangeDesktop.h : main header file for the CHANGEDESKTOP application
//

#if !defined(AFX_CHANGEDESKTOP_H__4DDEDDAC_4305_4071_AB9E_D330D25C1E20__INCLUDED_)
#define AFX_CHANGEDESKTOP_H__4DDEDDAC_4305_4071_AB9E_D330D25C1E20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChangeDesktopApp:
// See ChangeDesktop.cpp for the implementation of this class
//

class CChangeDesktopApp : public CWinApp
{
public:
	CChangeDesktopApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDesktopApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChangeDesktopApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDESKTOP_H__4DDEDDAC_4305_4071_AB9E_D330D25C1E20__INCLUDED_)
