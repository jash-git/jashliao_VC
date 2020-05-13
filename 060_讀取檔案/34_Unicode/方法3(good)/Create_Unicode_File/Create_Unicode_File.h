// Create_Unicode_File.h : main header file for the CREATE_UNICODE_FILE application
//

#if !defined(AFX_CREATE_UNICODE_FILE_H__4581774F_DBC3_4BC3_8163_CD2AAF429567__INCLUDED_)
#define AFX_CREATE_UNICODE_FILE_H__4581774F_DBC3_4BC3_8163_CD2AAF429567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreate_Unicode_FileApp:
// See Create_Unicode_File.cpp for the implementation of this class
//

class CCreate_Unicode_FileApp : public CWinApp
{
public:
	CCreate_Unicode_FileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_Unicode_FileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreate_Unicode_FileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_UNICODE_FILE_H__4581774F_DBC3_4BC3_8163_CD2AAF429567__INCLUDED_)
