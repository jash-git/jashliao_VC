// AutoBackup.h : main header file for the AUTOBACKUP application
//

#if !defined(AFX_AUTOBACKUP_H__F2D222D9_4F4D_4B6A_9A2C_71C4EBEACD93__INCLUDED_)
#define AFX_AUTOBACKUP_H__F2D222D9_4F4D_4B6A_9A2C_71C4EBEACD93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoBackupApp:
// See AutoBackup.cpp for the implementation of this class
//

class CAutoBackupApp : public CWinApp
{
public:
	CAutoBackupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoBackupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAutoBackupApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOBACKUP_H__F2D222D9_4F4D_4B6A_9A2C_71C4EBEACD93__INCLUDED_)
