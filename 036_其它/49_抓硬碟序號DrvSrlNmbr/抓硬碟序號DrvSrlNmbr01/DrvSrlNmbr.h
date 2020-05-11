// DrvSrlNmbr.h : main header file for the DRVSRLNMBR application
//

#if !defined(AFX_DRVSRLNMBR_H__CBBA57E5_702B_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_DRVSRLNMBR_H__CBBA57E5_702B_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrvSrlNmbrApp:
// See DrvSrlNmbr.cpp for the implementation of this class
//

class CDrvSrlNmbrApp : public CWinApp
{
public:
	CDrvSrlNmbrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrvSrlNmbrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrvSrlNmbrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRVSRLNMBR_H__CBBA57E5_702B_11D6_8F32_00E04CE76240__INCLUDED_)
