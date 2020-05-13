// Alert.h : main header file for the ALERT application
//

#if !defined(AFX_ALERT_H__74CFEA65_6678_11D6_84BE_CB00B5092942__INCLUDED_)
#define AFX_ALERT_H__74CFEA65_6678_11D6_84BE_CB00B5092942__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAlertApp:
// See Alert.cpp for the implementation of this class
//

class CAlertApp : public CWinApp
{
public:
	CAlertApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlertApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAlertApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALERT_H__74CFEA65_6678_11D6_84BE_CB00B5092942__INCLUDED_)
