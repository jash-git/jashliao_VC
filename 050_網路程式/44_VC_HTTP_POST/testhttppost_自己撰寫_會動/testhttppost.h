// testhttppost.h : main header file for the TESTHTTPPOST application
//

#if !defined(AFX_TESTHTTPPOST_H__4CCAE92A_0B95_47FE_8E1D_A6495DD2DAE6__INCLUDED_)
#define AFX_TESTHTTPPOST_H__4CCAE92A_0B95_47FE_8E1D_A6495DD2DAE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTesthttppostApp:
// See testhttppost.cpp for the implementation of this class
//

class CTesthttppostApp : public CWinApp
{
public:
	CTesthttppostApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesthttppostApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTesthttppostApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTHTTPPOST_H__4CCAE92A_0B95_47FE_8E1D_A6495DD2DAE6__INCLUDED_)
