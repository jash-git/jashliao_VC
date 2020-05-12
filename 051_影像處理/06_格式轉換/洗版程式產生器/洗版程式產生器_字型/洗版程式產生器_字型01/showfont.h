// showfont.h : main header file for the SHOWFONT application
//

#if !defined(AFX_SHOWFONT_H__2E5ECCD6_0128_4994_B7B6_A0DF892EEE68__INCLUDED_)
#define AFX_SHOWFONT_H__2E5ECCD6_0128_4994_B7B6_A0DF892EEE68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowfontApp:
// See showfont.cpp for the implementation of this class
//

class CShowfontApp : public CWinApp
{
public:
	CShowfontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowfontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowfontApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWFONT_H__2E5ECCD6_0128_4994_B7B6_A0DF892EEE68__INCLUDED_)
