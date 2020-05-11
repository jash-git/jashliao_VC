// flash.h : main header file for the FLASH application
//

#if !defined(AFX_FLASH_H__B1885BA4_EF8F_4E40_9C36_09912C89F859__INCLUDED_)
#define AFX_FLASH_H__B1885BA4_EF8F_4E40_9C36_09912C89F859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFlashApp:
// See flash.cpp for the implementation of this class
//

class CFlashApp : public CWinApp
{
public:
	CFlashApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFlashApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASH_H__B1885BA4_EF8F_4E40_9C36_09912C89F859__INCLUDED_)
