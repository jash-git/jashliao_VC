// UseCRegKey.h : main header file for the USECREGKEY application
//

#if !defined(AFX_USECREGKEY_H__4ED9C2E8_2E3E_4822_8ED3_8611891D86C5__INCLUDED_)
#define AFX_USECREGKEY_H__4ED9C2E8_2E3E_4822_8ED3_8611891D86C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseCRegKeyApp:
// See UseCRegKey.cpp for the implementation of this class
//

class CUseCRegKeyApp : public CWinApp
{
public:
	CUseCRegKeyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseCRegKeyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseCRegKeyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USECREGKEY_H__4ED9C2E8_2E3E_4822_8ED3_8611891D86C5__INCLUDED_)
