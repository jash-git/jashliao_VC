/////////////////////////////////////////////////////////////////////////////
// Project：MYIMGAPP
// Author：NorthTibet
// Date：星期四, 九月 26, 2002
// Description：通过定制的C++类在MFC框架中轻松显示多种格式的图象
//
/////////////////////////////////////////////////////////////////////////////
// Myimgapp.h : main header file for the MYIMGAPP application
//

#if !defined(AFX_MYIMGAPP_H__794D50B1_F71B_403E_A251_E84863AEA401__INCLUDED_)
#define AFX_MYIMGAPP_H__794D50B1_F71B_403E_A251_E84863AEA401__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See Myimgapp.cpp for the implementation of this class
//

class CMyApp : public CWinApp
{
public:
	CMyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYIMGAPP_H__794D50B1_F71B_403E_A251_E84863AEA401__INCLUDED_)
