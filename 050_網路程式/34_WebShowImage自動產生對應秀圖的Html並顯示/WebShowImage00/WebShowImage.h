// WebShowImage.h : main header file for the WEBSHOWIMAGE application
//

#if !defined(AFX_WEBSHOWIMAGE_H__FDDD98A9_63E1_4842_A5F1_05AE8BF98519__INCLUDED_)
#define AFX_WEBSHOWIMAGE_H__FDDD98A9_63E1_4842_A5F1_05AE8BF98519__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWebShowImageApp:
// See WebShowImage.cpp for the implementation of this class
//

class CWebShowImageApp : public CWinApp
{
public:
	CWebShowImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebShowImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWebShowImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBSHOWIMAGE_H__FDDD98A9_63E1_4842_A5F1_05AE8BF98519__INCLUDED_)
