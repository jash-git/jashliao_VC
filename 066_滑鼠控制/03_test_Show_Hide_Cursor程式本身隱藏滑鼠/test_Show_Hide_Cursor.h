// test_Show_Hide_Cursor.h : main header file for the TEST_SHOW_HIDE_CURSOR application
//

#if !defined(AFX_TEST_SHOW_HIDE_CURSOR_H__E1CD7E9A_DD12_4B8D_AB22_9B4A550B230E__INCLUDED_)
#define AFX_TEST_SHOW_HIDE_CURSOR_H__E1CD7E9A_DD12_4B8D_AB22_9B4A550B230E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_Show_Hide_CursorApp:
// See test_Show_Hide_Cursor.cpp for the implementation of this class
//

class CTest_Show_Hide_CursorApp : public CWinApp
{
public:
	CTest_Show_Hide_CursorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Show_Hide_CursorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_Show_Hide_CursorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_SHOW_HIDE_CURSOR_H__E1CD7E9A_DD12_4B8D_AB22_9B4A550B230E__INCLUDED_)
