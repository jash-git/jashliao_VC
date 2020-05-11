// SoyalRS232Reader.h : main header file for the SOYALRS232READER application
//

#if !defined(AFX_SOYALRS232READER_H__025854F2_A572_4577_A323_E9B40FBC36E2__INCLUDED_)
#define AFX_SOYALRS232READER_H__025854F2_A572_4577_A323_E9B40FBC36E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSoyalRS232ReaderApp:
// See SoyalRS232Reader.cpp for the implementation of this class
//

class CSoyalRS232ReaderApp : public CWinApp
{
public:
	CSoyalRS232ReaderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoyalRS232ReaderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSoyalRS232ReaderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOYALRS232READER_H__025854F2_A572_4577_A323_E9B40FBC36E2__INCLUDED_)
