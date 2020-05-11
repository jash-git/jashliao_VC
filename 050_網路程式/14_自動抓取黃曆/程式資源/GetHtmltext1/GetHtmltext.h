// GetHtmltext.h : main header file for the GETHTMLTEXT application
//

#if !defined(AFX_GETHTMLTEXT_H__8EDC0F73_12CF_4C57_9260_0DB42D4041F3__INCLUDED_)
#define AFX_GETHTMLTEXT_H__8EDC0F73_12CF_4C57_9260_0DB42D4041F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetHtmltextApp:
// See GetHtmltext.cpp for the implementation of this class
//

class CGetHtmltextApp : public CWinApp
{
public:
	CGetHtmltextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetHtmltextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetHtmltextApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETHTMLTEXT_H__8EDC0F73_12CF_4C57_9260_0DB42D4041F3__INCLUDED_)
