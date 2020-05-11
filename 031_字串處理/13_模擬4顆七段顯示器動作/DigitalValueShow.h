// DigitalValueShow.h : main header file for the DIGITALVALUESHOW application
//

#if !defined(AFX_DIGITALVALUESHOW_H__0E32953E_640D_48BB_A745_32D0FD7CD63C__INCLUDED_)
#define AFX_DIGITALVALUESHOW_H__0E32953E_640D_48BB_A745_32D0FD7CD63C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDigitalValueShowApp:
// See DigitalValueShow.cpp for the implementation of this class
//

class CDigitalValueShowApp : public CWinApp
{
public:
	CDigitalValueShowApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalValueShowApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDigitalValueShowApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALVALUESHOW_H__0E32953E_640D_48BB_A745_32D0FD7CD63C__INCLUDED_)
