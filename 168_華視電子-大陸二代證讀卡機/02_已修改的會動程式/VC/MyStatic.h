// MyStatic.h : main header file for the MYSTATIC application
//

#if !defined(AFX_MYSTATIC_H__41F4CCB3_8B03_4653_8198_BC3800BAE7DE__INCLUDED_)
#define AFX_MYSTATIC_H__41F4CCB3_8B03_4653_8198_BC3800BAE7DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyStaticApp:
// See MyStatic.cpp for the implementation of this class
//

class CMyStaticApp : public CWinApp
{
protected:
	ULONG_PTR m_gdiplusToken;

public:
	CMyStaticApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyStaticApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyStaticApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTATIC_H__41F4CCB3_8B03_4653_8198_BC3800BAE7DE__INCLUDED_)
