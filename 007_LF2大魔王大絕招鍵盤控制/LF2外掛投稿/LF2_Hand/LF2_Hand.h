// LF2_Hand.h : main header file for the LF2_HAND application
//

#if !defined(AFX_LF2_HAND_H__745F0FF9_AB21_4EFD_86B5_CC27A2965434__INCLUDED_)
#define AFX_LF2_HAND_H__745F0FF9_AB21_4EFD_86B5_CC27A2965434__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLF2_HandApp:
// See LF2_Hand.cpp for the implementation of this class
//

class CLF2_HandApp : public CWinApp
{
public:
	CLF2_HandApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLF2_HandApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLF2_HandApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LF2_HAND_H__745F0FF9_AB21_4EFD_86B5_CC27A2965434__INCLUDED_)
