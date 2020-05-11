// GetNowTime.h : main header file for the GETNOWTIME application
//

#if !defined(AFX_GETNOWTIME_H__BBA865B0_95C5_46FF_9386_27C80A51C420__INCLUDED_)
#define AFX_GETNOWTIME_H__BBA865B0_95C5_46FF_9386_27C80A51C420__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetNowTimeApp:
// See GetNowTime.cpp for the implementation of this class
//

class CGetNowTimeApp : public CWinApp
{
public:
	CGetNowTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetNowTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetNowTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETNOWTIME_H__BBA865B0_95C5_46FF_9386_27C80A51C420__INCLUDED_)
