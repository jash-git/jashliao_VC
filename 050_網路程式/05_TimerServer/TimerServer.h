// TimerServer.h : main header file for the TIMERSERVER application
//

#if !defined(AFX_TIMERSERVER_H__AD77318C_1723_4803_872E_1897B276338B__INCLUDED_)
#define AFX_TIMERSERVER_H__AD77318C_1723_4803_872E_1897B276338B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimerServerApp:
// See TimerServer.cpp for the implementation of this class
//

class CTimerServerApp : public CWinApp
{
public:
	CTimerServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTimerServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERSERVER_H__AD77318C_1723_4803_872E_1897B276338B__INCLUDED_)
