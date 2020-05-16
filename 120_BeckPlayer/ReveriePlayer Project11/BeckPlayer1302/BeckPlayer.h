// BeckPlayer.h : main header file for the BECKPLAYER application
//

#if !defined(AFX_BECKPLAYER_H__FE5DBE15_9015_4F08_88CD_DE6C5A824D1F__INCLUDED_)
#define AFX_BECKPLAYER_H__FE5DBE15_9015_4F08_88CD_DE6C5A824D1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBeckPlayerApp:
// See BeckPlayer.cpp for the implementation of this class
//

class CBeckPlayerApp : public CWinApp
{
public:
	CBeckPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBeckPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBeckPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BECKPLAYER_H__FE5DBE15_9015_4F08_88CD_DE6C5A824D1F__INCLUDED_)
