// CTime2CStrung.h : main header file for the CTIME2CSTRUNG application
//

#if !defined(AFX_CTIME2CSTRUNG_H__BE874FE0_EF8A_45ED_AF6F_35664D51D5B2__INCLUDED_)
#define AFX_CTIME2CSTRUNG_H__BE874FE0_EF8A_45ED_AF6F_35664D51D5B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTime2CStrungApp:
// See CTime2CStrung.cpp for the implementation of this class
//

class CCTime2CStrungApp : public CWinApp
{
public:
	CCTime2CStrungApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTime2CStrungApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCTime2CStrungApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTIME2CSTRUNG_H__BE874FE0_EF8A_45ED_AF6F_35664D51D5B2__INCLUDED_)
