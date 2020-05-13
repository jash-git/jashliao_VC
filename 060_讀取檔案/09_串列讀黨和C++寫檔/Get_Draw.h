// Get_Draw.h : main header file for the GET_DRAW application
//

#if !defined(AFX_GET_DRAW_H__E4436DF0_E1C9_4ED8_80C2_5455DA3157C2__INCLUDED_)
#define AFX_GET_DRAW_H__E4436DF0_E1C9_4ED8_80C2_5455DA3157C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawApp:
// See Get_Draw.cpp for the implementation of this class
//

class CGet_DrawApp : public CWinApp
{
public:
	CGet_DrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_DrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGet_DrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GET_DRAW_H__E4436DF0_E1C9_4ED8_80C2_5455DA3157C2__INCLUDED_)
