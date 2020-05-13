// combox_control.h : main header file for the COMBOX_CONTROL application
//

#if !defined(AFX_COMBOX_CONTROL_H__D4F462EF_6CE4_4436_B854_FD82EDEF755B__INCLUDED_)
#define AFX_COMBOX_CONTROL_H__D4F462EF_6CE4_4436_B854_FD82EDEF755B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCombox_controlApp:
// See combox_control.cpp for the implementation of this class
//

class CCombox_controlApp : public CWinApp
{
public:
	CCombox_controlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCombox_controlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCombox_controlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOX_CONTROL_H__D4F462EF_6CE4_4436_B854_FD82EDEF755B__INCLUDED_)
