// player_WPL.h : main header file for the PLAYER_WPL application
//

#if !defined(AFX_PLAYER_WPL_H__AEB003F2_A049_4EDE_99FA_6D9596DDA832__INCLUDED_)
#define AFX_PLAYER_WPL_H__AEB003F2_A049_4EDE_99FA_6D9596DDA832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlayer_WPLApp:
// See player_WPL.cpp for the implementation of this class
//

class CPlayer_WPLApp : public CWinApp
{
public:
	CPlayer_WPLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayer_WPLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlayer_WPLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYER_WPL_H__AEB003F2_A049_4EDE_99FA_6D9596DDA832__INCLUDED_)
