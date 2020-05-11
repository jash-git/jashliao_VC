// number1Andnumber2.h : main header file for the NUMBER1ANDNUMBER2 application
//

#if !defined(AFX_NUMBER1ANDNUMBER2_H__EAD44443_630F_4BB8_BB82_D3A4E7A467B8__INCLUDED_)
#define AFX_NUMBER1ANDNUMBER2_H__EAD44443_630F_4BB8_BB82_D3A4E7A467B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNumber1Andnumber2App:
// See number1Andnumber2.cpp for the implementation of this class
//

class CNumber1Andnumber2App : public CWinApp
{
public:
	CNumber1Andnumber2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumber1Andnumber2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNumber1Andnumber2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBER1ANDNUMBER2_H__EAD44443_630F_4BB8_BB82_D3A4E7A467B8__INCLUDED_)
