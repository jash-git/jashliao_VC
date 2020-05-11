// TopShow.h : main header file for the TOPSHOW application
//

#if !defined(AFX_TOPSHOW_H__F6077724_2393_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOPSHOW_H__F6077724_2393_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTopShowApp:
// See TopShow.cpp for the implementation of this class
//

class CTopShowApp : public CWinApp
{
public:
	CTopShowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopShowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTopShowApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPSHOW_H__F6077724_2393_11DA_B776_0040F43A9B72__INCLUDED_)
