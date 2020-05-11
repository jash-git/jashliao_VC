// FTP_UpLoad.h : main header file for the FTP_UPLOAD application
//

#if !defined(AFX_FTP_UPLOAD_H__526B15A5_1BA9_4CA2_BC55_6AB581653ABA__INCLUDED_)
#define AFX_FTP_UPLOAD_H__526B15A5_1BA9_4CA2_BC55_6AB581653ABA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFTP_UpLoadApp:
// See FTP_UpLoad.cpp for the implementation of this class
//

class CFTP_UpLoadApp : public CWinApp
{
public:
	CFTP_UpLoadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTP_UpLoadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFTP_UpLoadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_UPLOAD_H__526B15A5_1BA9_4CA2_BC55_6AB581653ABA__INCLUDED_)
