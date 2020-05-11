// mfcdll.h : main header file for the MFCDLL DLL
//

#if !defined(AFX_MFCDLL_H__55D7143E_F985_4983_BEF1_8B4C8AEE30BC__INCLUDED_)
#define AFX_MFCDLL_H__55D7143E_F985_4983_BEF1_8B4C8AEE30BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfcdllApp
// See mfcdll.cpp for the implementation of this class
//
#define EXPORTED_DLL_FUNCTION \
 __declspec(dllexport) __stdcall

int EXPORTED_DLL_FUNCTION KbdHookProc (int a, int b);
class CMfcdllApp : public CWinApp
{
public:
	CMfcdllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcdllApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMfcdllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLL_H__55D7143E_F985_4983_BEF1_8B4C8AEE30BC__INCLUDED_)
