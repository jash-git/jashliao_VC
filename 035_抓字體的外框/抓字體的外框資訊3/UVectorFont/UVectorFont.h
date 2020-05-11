// UVectorFont.h : main header file for the UVECTORFONT application
//

#if !defined(AFX_UVECTORFONT_H__C772A5BE_9175_4850_BC17_3740B16B4849__INCLUDED_)
#define AFX_UVECTORFONT_H__C772A5BE_9175_4850_BC17_3740B16B4849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontApp:
// See UVectorFont.cpp for the implementation of this class
//

class CUVectorFontApp : public CWinApp
{
public:
	CUVectorFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUVectorFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUVectorFontApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UVECTORFONT_H__C772A5BE_9175_4850_BC17_3740B16B4849__INCLUDED_)
