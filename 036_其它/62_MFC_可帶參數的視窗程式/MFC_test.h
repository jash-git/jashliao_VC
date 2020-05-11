// MFC_test.h : main header file for the MFC_TEST application
//

#if !defined(AFX_MFC_TEST_H__705026C1_0E0F_45AC_AB9A_91C2F54A6C66__INCLUDED_)
#define AFX_MFC_TEST_H__705026C1_0E0F_45AC_AB9A_91C2F54A6C66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_testApp:
// See MFC_test.cpp for the implementation of this class
//

class CMFC_testApp : public CWinApp
{
public:
	CMFC_testApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_testApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_testApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_TEST_H__705026C1_0E0F_45AC_AB9A_91C2F54A6C66__INCLUDED_)
