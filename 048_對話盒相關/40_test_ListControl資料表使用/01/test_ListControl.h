// test_ListControl.h : main header file for the TEST_LISTCONTROL application
//

#if !defined(AFX_TEST_LISTCONTROL_H__56B2EB34_D09E_4045_ADE1_5276F0F4A3A7__INCLUDED_)
#define AFX_TEST_LISTCONTROL_H__56B2EB34_D09E_4045_ADE1_5276F0F4A3A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_ListControlApp:
// See test_ListControl.cpp for the implementation of this class
//

class CTest_ListControlApp : public CWinApp
{
public:
	CTest_ListControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_ListControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_ListControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_LISTCONTROL_H__56B2EB34_D09E_4045_ADE1_5276F0F4A3A7__INCLUDED_)
