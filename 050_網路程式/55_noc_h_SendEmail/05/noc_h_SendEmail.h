// noc_h_SendEmail.h : main header file for the NOC_H_SENDEMAIL application
//

#if !defined(AFX_NOC_H_SENDEMAIL_H__4D824B5E_2307_479C_9B95_595F42221F03__INCLUDED_)
#define AFX_NOC_H_SENDEMAIL_H__4D824B5E_2307_479C_9B95_595F42221F03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoc_h_SendEmailApp:
// See noc_h_SendEmail.cpp for the implementation of this class
//

class CNoc_h_SendEmailApp : public CWinApp
{
public:
	CNoc_h_SendEmailApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoc_h_SendEmailApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNoc_h_SendEmailApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOC_H_SENDEMAIL_H__4D824B5E_2307_479C_9B95_595F42221F03__INCLUDED_)
