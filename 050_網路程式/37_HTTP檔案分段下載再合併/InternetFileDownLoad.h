// InternetFileDownLoad.h : main header file for the INTERNETFILEDOWNLOAD application
//

#if !defined(AFX_INTERNETFILEDOWNLOAD_H__BCC8DAB1_575C_4654_A8AE_1311EEA23A12__INCLUDED_)
#define AFX_INTERNETFILEDOWNLOAD_H__BCC8DAB1_575C_4654_A8AE_1311EEA23A12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CInternetFileDownLoadApp:
// See InternetFileDownLoad.cpp for the implementation of this class
//

class CInternetFileDownLoadApp : public CWinApp
{
public:
	CInternetFileDownLoadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInternetFileDownLoadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CInternetFileDownLoadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERNETFILEDOWNLOAD_H__BCC8DAB1_575C_4654_A8AE_1311EEA23A12__INCLUDED_)
