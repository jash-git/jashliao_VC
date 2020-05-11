// CString _MakeUpperLower.h : main header file for the CSTRING _MAKEUPPERLOWER application
//

#if !defined(AFX_CSTRING_MAKEUPPERLOWER_H__C46CC6C8_9BE3_4744_B873_1673B9A0D9C4__INCLUDED_)
#define AFX_CSTRING_MAKEUPPERLOWER_H__C46CC6C8_9BE3_4744_B873_1673B9A0D9C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCString_MakeUpperLowerApp:
// See CString _MakeUpperLower.cpp for the implementation of this class
//

class CCString_MakeUpperLowerApp : public CWinApp
{
public:
	CCString_MakeUpperLowerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCString_MakeUpperLowerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCString_MakeUpperLowerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTRING_MAKEUPPERLOWER_H__C46CC6C8_9BE3_4744_B873_1673B9A0D9C4__INCLUDED_)
