// CSEventPlugin_Analysis.h : main header file for the CSEVENTPLUGIN_ANALYSIS application
//

#if !defined(AFX_CSEVENTPLUGIN_ANALYSIS_H__E4D57F7E_B0DC_4BE6_9684_8E947F2E40FF__INCLUDED_)
#define AFX_CSEVENTPLUGIN_ANALYSIS_H__E4D57F7E_B0DC_4BE6_9684_8E947F2E40FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCSEventPlugin_AnalysisApp:
// See CSEventPlugin_Analysis.cpp for the implementation of this class
//

class CCSEventPlugin_AnalysisApp : public CWinApp
{
public:
	CCSEventPlugin_AnalysisApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSEventPlugin_AnalysisApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCSEventPlugin_AnalysisApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSEVENTPLUGIN_ANALYSIS_H__E4D57F7E_B0DC_4BE6_9684_8E947F2E40FF__INCLUDED_)
