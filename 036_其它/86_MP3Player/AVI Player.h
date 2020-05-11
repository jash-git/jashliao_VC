// AVI Player.h : main header file for the AVI PLAYER application
//

#if !defined(AFX_AVIPLAYER_H__7CCAFC43_A9D7_4629_B15D_FB64E31BA794__INCLUDED_)
#define AFX_AVIPLAYER_H__7CCAFC43_A9D7_4629_B15D_FB64E31BA794__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAVIPlayerApp:
// See AVI Player.cpp for the implementation of this class
//

class CAVIPlayerApp : public CWinApp
{
public:
	CAVIPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVIPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAVIPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIPLAYER_H__7CCAFC43_A9D7_4629_B15D_FB64E31BA794__INCLUDED_)
