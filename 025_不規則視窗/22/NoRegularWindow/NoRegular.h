// NoRegular.h : main header file for the NOREGULAR application
//

#if !defined(AFX_NOREGULAR_H__C774C911_CE76_46D0_A072_C65E41917701__INCLUDED_)
#define AFX_NOREGULAR_H__C774C911_CE76_46D0_A072_C65E41917701__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoRegularApp:
// See NoRegular.cpp for the implementation of this class
//

class CNoRegularApp : public CWinApp
{
public:
	CNoRegularApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoRegularApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNoRegularApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOREGULAR_H__C774C911_CE76_46D0_A072_C65E41917701__INCLUDED_)
