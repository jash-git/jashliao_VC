// playlist.h : main header file for the PLAYLIST application
//

#if !defined(AFX_PLAYLIST_H__0C727F88_A1CE_4C2A_8050_C2037FFCE686__INCLUDED_)
#define AFX_PLAYLIST_H__0C727F88_A1CE_4C2A_8050_C2037FFCE686__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlaylistApp:
// See playlist.cpp for the implementation of this class
//

class CPlaylistApp : public CWinApp
{
public:
	CPlaylistApp();
	BOOL OnlyOneCheck();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaylistApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPlaylistApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYLIST_H__0C727F88_A1CE_4C2A_8050_C2037FFCE686__INCLUDED_)
