// comput.h : main header file for the COMPUT application
//

#if !defined(AFX_COMPUT_H__7BD0C4DE_B0F5_4A41_9AD9_D02B2E44228F__INCLUDED_)
#define AFX_COMPUT_H__7BD0C4DE_B0F5_4A41_9AD9_D02B2E44228F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CComputApp:
// See comput.cpp for the implementation of this class
//

class CComputApp : public CWinApp
{
public:
	CComputApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComputApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CComputApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPUT_H__7BD0C4DE_B0F5_4A41_9AD9_D02B2E44228F__INCLUDED_)
