// asd.h : main header file for the ASD application
//

#if !defined(AFX_ASD_H__5C1368C7_0848_450C_A0F2_48771187E7E9__INCLUDED_)
#define AFX_ASD_H__5C1368C7_0848_450C_A0F2_48771187E7E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAsdApp:
// See asd.cpp for the implementation of this class
//

class CAsdApp : public CWinApp
{
public:
	CAsdApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAsdApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAsdApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASD_H__5C1368C7_0848_450C_A0F2_48771187E7E9__INCLUDED_)
