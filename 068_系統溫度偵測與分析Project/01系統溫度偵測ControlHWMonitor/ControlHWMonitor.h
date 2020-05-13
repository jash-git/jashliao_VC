// ControlHWMonitor.h : main header file for the CONTROLHWMONITOR application
//

#if !defined(AFX_CONTROLHWMONITOR_H__BFEABCFE_6528_4586_9395_1A23A49C6117__INCLUDED_)
#define AFX_CONTROLHWMONITOR_H__BFEABCFE_6528_4586_9395_1A23A49C6117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CControlHWMonitorApp:
// See ControlHWMonitor.cpp for the implementation of this class
//

class CControlHWMonitorApp : public CWinApp
{
public:
	CControlHWMonitorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlHWMonitorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CControlHWMonitorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLHWMONITOR_H__BFEABCFE_6528_4586_9395_1A23A49C6117__INCLUDED_)
