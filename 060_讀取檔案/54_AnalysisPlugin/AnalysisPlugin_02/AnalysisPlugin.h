// AnalysisPlugin.h : main header file for the ANALYSISPLUGIN application
//

#if !defined(AFX_ANALYSISPLUGIN_H__C617EF40_470B_4F43_ACA1_394F6D5D6DC0__INCLUDED_)
#define AFX_ANALYSISPLUGIN_H__C617EF40_470B_4F43_ACA1_394F6D5D6DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnalysisPluginApp:
// See AnalysisPlugin.cpp for the implementation of this class
//

class CAnalysisPluginApp : public CWinApp
{
public:
	CAnalysisPluginApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisPluginApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnalysisPluginApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISPLUGIN_H__C617EF40_470B_4F43_ACA1_394F6D5D6DC0__INCLUDED_)
