// TABCONTROL.h : main header file for the TABCONTROL application
//

#if !defined(AFX_TABCONTROL_H__41BC4E51_FA28_4F8F_A7D4_393364253F0F__INCLUDED_)
#define AFX_TABCONTROL_H__41BC4E51_FA28_4F8F_A7D4_393364253F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTABCONTROLApp:
// See TABCONTROL.cpp for the implementation of this class
//

class CTABCONTROLApp : public CWinApp
{
public:
	CTABCONTROLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTABCONTROLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTABCONTROLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABCONTROL_H__41BC4E51_FA28_4F8F_A7D4_393364253F0F__INCLUDED_)
