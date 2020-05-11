// PortMonitor.h : main header file for the PORTMONITOR application
//

#if !defined(AFX_PORTMONITOR_H__4F85820F_B95C_49CA_A48E_4A5F582A33FD__INCLUDED_)
#define AFX_PORTMONITOR_H__4F85820F_B95C_49CA_A48E_4A5F582A33FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPortMonitorApp:
// See PortMonitor.cpp for the implementation of this class
//

class CPortMonitorApp : public CWinApp
{
public:
	CPortMonitorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortMonitorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPortMonitorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTMONITOR_H__4F85820F_B95C_49CA_A48E_4A5F582A33FD__INCLUDED_)
