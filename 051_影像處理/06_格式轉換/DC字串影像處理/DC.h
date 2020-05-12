// DC.h : main header file for the DC application
//

#if !defined(AFX_DC_H__6D9D2600_867F_486E_A5FF_453CC236C295__INCLUDED_)
#define AFX_DC_H__6D9D2600_867F_486E_A5FF_453CC236C295__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDCApp:
// See DC.cpp for the implementation of this class
//

class CDCApp : public CWinApp
{
public:
	CDCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDCApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DC_H__6D9D2600_867F_486E_A5FF_453CC236C295__INCLUDED_)
