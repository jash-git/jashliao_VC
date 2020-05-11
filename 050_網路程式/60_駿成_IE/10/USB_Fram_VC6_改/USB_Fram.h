// USB_Fram.h : main header file for the USB_FRAM application
//

#if !defined(AFX_USB_FRAM_H__4126050A_380C_4419_9EDB_B55071B6EF13__INCLUDED_)
#define AFX_USB_FRAM_H__4126050A_380C_4419_9EDB_B55071B6EF13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramApp:
// See USB_Fram.cpp for the implementation of this class
//

class CUSB_FramApp : public CWinApp
{
public:
	CUSB_FramApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUSB_FramApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUSB_FramApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USB_FRAM_H__4126050A_380C_4419_9EDB_B55071B6EF13__INCLUDED_)
