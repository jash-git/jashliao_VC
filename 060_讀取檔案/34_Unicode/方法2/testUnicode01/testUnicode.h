// testUnicode.h : main header file for the TESTUNICODE application
//

#if !defined(AFX_TESTUNICODE_H__4B09C4BE_A395_4F5E_A0C8_208E6EF5E4E7__INCLUDED_)
#define AFX_TESTUNICODE_H__4B09C4BE_A395_4F5E_A0C8_208E6EF5E4E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestUnicodeApp:
// See testUnicode.cpp for the implementation of this class
//

class CTestUnicodeApp : public CWinApp
{
public:
	CTestUnicodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestUnicodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestUnicodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTUNICODE_H__4B09C4BE_A395_4F5E_A0C8_208E6EF5E4E7__INCLUDED_)
