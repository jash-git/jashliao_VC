// CNetControl.h : main header file for the CNETCONTROL application
//

#if !defined(AFX_CNETCONTROL_H__DC97BB95_293C_42B0_A1F9_E76BF54E769F__INCLUDED_)
#define AFX_CNETCONTROL_H__DC97BB95_293C_42B0_A1F9_E76BF54E769F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCNetControlApp:
// See CNetControl.cpp for the implementation of this class
//

class CCNetControlApp : public CWinApp
{
public:
	CCNetControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCNetControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCNetControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNETCONTROL_H__DC97BB95_293C_42B0_A1F9_E76BF54E769F__INCLUDED_)
