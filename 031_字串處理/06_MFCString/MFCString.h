// MFCString.h : main header file for the MFCSTRING application
//

#if !defined(AFX_MFCSTRING_H__A259BCDF_2419_45D8_AECC_F1DEB614E566__INCLUDED_)
#define AFX_MFCSTRING_H__A259BCDF_2419_45D8_AECC_F1DEB614E566__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCStringApp:
// See MFCString.cpp for the implementation of this class
//

class CMFCStringApp : public CWinApp
{
public:
	CMFCStringApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCStringApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCStringApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSTRING_H__A259BCDF_2419_45D8_AECC_F1DEB614E566__INCLUDED_)
