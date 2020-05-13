// key_event.h : main header file for the KEY_EVENT application
//

#if !defined(AFX_KEY_EVENT_H__57F0FA84_25E5_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_KEY_EVENT_H__57F0FA84_25E5_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKey_eventApp:
// See key_event.cpp for the implementation of this class
//

class CKey_eventApp : public CWinApp
{
public:
	CKey_eventApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKey_eventApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKey_eventApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEY_EVENT_H__57F0FA84_25E5_11DA_B776_0040F43A9B72__INCLUDED_)
