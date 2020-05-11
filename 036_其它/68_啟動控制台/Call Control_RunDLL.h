// Call Control_RunDLL.h : main header file for the CALL CONTROL_RUNDLL application
//

#if !defined(AFX_CALLCONTROL_RUNDLL_H__4D7465E0_8CD2_4E57_A3E6_A35FF5946B18__INCLUDED_)
#define AFX_CALLCONTROL_RUNDLL_H__4D7465E0_8CD2_4E57_A3E6_A35FF5946B18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCallControl_RunDLLApp:
// See Call Control_RunDLL.cpp for the implementation of this class
//

class CCallControl_RunDLLApp : public CWinApp
{
public:
	CCallControl_RunDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallControl_RunDLLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCallControl_RunDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLCONTROL_RUNDLL_H__4D7465E0_8CD2_4E57_A3E6_A35FF5946B18__INCLUDED_)
