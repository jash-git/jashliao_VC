// play_mp3.h : main header file for the PLAY_MP3 application
//

#if !defined(AFX_PLAY_MP3_H__1A3AABEC_54AE_4CD6_9C7B_5A840F0CA2DA__INCLUDED_)
#define AFX_PLAY_MP3_H__1A3AABEC_54AE_4CD6_9C7B_5A840F0CA2DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlay_mp3App:
// See play_mp3.cpp for the implementation of this class
//

class CPlay_mp3App : public CWinApp
{
public:
	CPlay_mp3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlay_mp3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlay_mp3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAY_MP3_H__1A3AABEC_54AE_4CD6_9C7B_5A840F0CA2DA__INCLUDED_)
