// Show1.h : main header file for the SHOW1 application
//

#if !defined(AFX_SHOW1_H__E23ED90A_2530_4BC4_AC0B_B33DFA4BABA4__INCLUDED_)
#define AFX_SHOW1_H__E23ED90A_2530_4BC4_AC0B_B33DFA4BABA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShow1App:
// See Show1.cpp for the implementation of this class
//

class CShow1App : public CWinApp
{
public:
	CShow1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShow1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShow1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOW1_H__E23ED90A_2530_4BC4_AC0B_B33DFA4BABA4__INCLUDED_)
