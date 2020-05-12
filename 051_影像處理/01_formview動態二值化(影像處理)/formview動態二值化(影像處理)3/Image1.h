// Image1.h : main header file for the IMAGE1 application
//

#if !defined(AFX_IMAGE1_H__4BB34D9E_5BCD_4D11_B1A5_888F6EB8A640__INCLUDED_)
#define AFX_IMAGE1_H__4BB34D9E_5BCD_4D11_B1A5_888F6EB8A640__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CImage1App:
// See Image1.cpp for the implementation of this class
//

class CImage1App : public CWinApp
{
public:
	CImage1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImage1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CImage1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGE1_H__4BB34D9E_5BCD_4D11_B1A5_888F6EB8A640__INCLUDED_)
