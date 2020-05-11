// Cstring_mid.h : main header file for the CSTRING_MID application
//

#if !defined(AFX_CSTRING_MID_H__0C7D0644_302E_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_CSTRING_MID_H__0C7D0644_302E_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCstring_midApp:
// See Cstring_mid.cpp for the implementation of this class
//

class CCstring_midApp : public CWinApp
{
public:
	CCstring_midApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCstring_midApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCstring_midApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTRING_MID_H__0C7D0644_302E_11DA_B776_0040F43A9B72__INCLUDED_)
