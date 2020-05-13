// Cute_Main_Control.h : main header file for the CUTE_MAIN_CONTROL application
//

#if !defined(AFX_CUTE_MAIN_CONTROL_H__D4734D42_BEA2_4B2F_87CC_B30A822054F1__INCLUDED_)
#define AFX_CUTE_MAIN_CONTROL_H__D4734D42_BEA2_4B2F_87CC_B30A822054F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlApp:
// See Cute_Main_Control.cpp for the implementation of this class
//

class CCute_Main_ControlApp : public CWinApp
{
public:
	CCute_Main_ControlApp();
	BOOL FirstInstance();//²Ä13.8ª©->¨¾°ô­«½Æ°õ¦æ

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCute_Main_ControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCute_Main_ControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTE_MAIN_CONTROL_H__D4734D42_BEA2_4B2F_87CC_B30A822054F1__INCLUDED_)
