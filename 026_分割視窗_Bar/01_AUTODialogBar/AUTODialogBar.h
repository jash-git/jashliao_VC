// AUTODialogBar.h : main header file for the AUTODIALOGBAR application
//

#if !defined(AFX_AUTODIALOGBAR_H__336D28C0_AB77_4385_BF04_287EDEB10D11__INCLUDED_)
#define AFX_AUTODIALOGBAR_H__336D28C0_AB77_4385_BF04_287EDEB10D11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarApp:
// See AUTODialogBar.cpp for the implementation of this class
//

class CAUTODialogBarApp : public CWinApp
{
public:
	CAUTODialogBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAUTODialogBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAUTODialogBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTODIALOGBAR_H__336D28C0_AB77_4385_BF04_287EDEB10D11__INCLUDED_)
