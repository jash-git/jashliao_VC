// GetMediaLen.h : main header file for the GETMEDIALEN application
//

#if !defined(AFX_GETMEDIALEN_H__E8B8832D_12F0_46DA_A3B3_16E4438FE176__INCLUDED_)
#define AFX_GETMEDIALEN_H__E8B8832D_12F0_46DA_A3B3_16E4438FE176__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetMediaLenApp:
// See GetMediaLen.cpp for the implementation of this class
//

class CGetMediaLenApp : public CWinApp
{
public:
	CGetMediaLenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetMediaLenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetMediaLenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETMEDIALEN_H__E8B8832D_12F0_46DA_A3B3_16E4438FE176__INCLUDED_)
