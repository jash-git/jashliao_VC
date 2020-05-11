// JashtestFTP.h : main header file for the JASHTESTFTP application
//

#if !defined(AFX_JASHTESTFTP_H__281ED75C_7959_4681_A83C_7D446276090F__INCLUDED_)
#define AFX_JASHTESTFTP_H__281ED75C_7959_4681_A83C_7D446276090F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJashtestFTPApp:
// See JashtestFTP.cpp for the implementation of this class
//

class CJashtestFTPApp : public CWinApp
{
public:
	CJashtestFTPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJashtestFTPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJashtestFTPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JASHTESTFTP_H__281ED75C_7959_4681_A83C_7D446276090F__INCLUDED_)
