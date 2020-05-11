// CTime_Format.h : main header file for the CTIME_FORMAT application
//

#if !defined(AFX_CTIME_FORMAT_H__98A8D9E6_0113_4448_8457_0A171B84C0E3__INCLUDED_)
#define AFX_CTIME_FORMAT_H__98A8D9E6_0113_4448_8457_0A171B84C0E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTime_FormatApp:
// See CTime_Format.cpp for the implementation of this class
//

class CCTime_FormatApp : public CWinApp
{
public:
	CCTime_FormatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTime_FormatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCTime_FormatApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTIME_FORMAT_H__98A8D9E6_0113_4448_8457_0A171B84C0E3__INCLUDED_)
