// testGetSystemMetrics.h : main header file for the TESTGETSYSTEMMETRICS application
//

#if !defined(AFX_TESTGETSYSTEMMETRICS_H__94288560_2225_472F_B5CB_9CEAA2004BDA__INCLUDED_)
#define AFX_TESTGETSYSTEMMETRICS_H__94288560_2225_472F_B5CB_9CEAA2004BDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestGetSystemMetricsApp:
// See testGetSystemMetrics.cpp for the implementation of this class
//

class CTestGetSystemMetricsApp : public CWinApp
{
public:
	CTestGetSystemMetricsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGetSystemMetricsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestGetSystemMetricsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTGETSYSTEMMETRICS_H__94288560_2225_472F_B5CB_9CEAA2004BDA__INCLUDED_)
