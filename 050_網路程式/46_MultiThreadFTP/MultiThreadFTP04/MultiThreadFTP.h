// MultiThreadFTP.h : main header file for the MULTITHREADFTP application
//

#if !defined(AFX_MULTITHREADFTP_H__C03124AE_19E9_462E_8C4A_19562B253783__INCLUDED_)
#define AFX_MULTITHREADFTP_H__C03124AE_19E9_462E_8C4A_19562B253783__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFTPApp:
// See MultiThreadFTP.cpp for the implementation of this class
//
class CMultiThreadFTPApp : public CWinApp
{
public:
	CMultiThreadFTPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThreadFTPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThreadFTPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREADFTP_H__C03124AE_19E9_462E_8C4A_19562B253783__INCLUDED_)
