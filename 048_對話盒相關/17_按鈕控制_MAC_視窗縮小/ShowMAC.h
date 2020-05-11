// ShowMAC.h : main header file for the SHOWMAC application
//

#if !defined(AFX_SHOWMAC_H__CEBB5844_2432_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_SHOWMAC_H__CEBB5844_2432_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowMACApp:
// See ShowMAC.cpp for the implementation of this class
//

class CShowMACApp : public CWinApp
{
public:
	CShowMACApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowMACApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowMACApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWMAC_H__CEBB5844_2432_11DA_B776_0040F43A9B72__INCLUDED_)
