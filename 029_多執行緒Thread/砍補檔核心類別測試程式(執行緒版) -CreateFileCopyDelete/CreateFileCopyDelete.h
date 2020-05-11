// CreateFileCopyDelete.h : main header file for the CREATEFILECOPYDELETE application
//

#if !defined(AFX_CREATEFILECOPYDELETE_H__7F7FDD89_1D17_48F0_9F33_7B6F3AA757A3__INCLUDED_)
#define AFX_CREATEFILECOPYDELETE_H__7F7FDD89_1D17_48F0_9F33_7B6F3AA757A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateFileCopyDeleteApp:
// See CreateFileCopyDelete.cpp for the implementation of this class
//

class CCreateFileCopyDeleteApp : public CWinApp
{
public:
	CCreateFileCopyDeleteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateFileCopyDeleteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateFileCopyDeleteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEFILECOPYDELETE_H__7F7FDD89_1D17_48F0_9F33_7B6F3AA757A3__INCLUDED_)
