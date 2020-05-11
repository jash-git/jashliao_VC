// RichEditDlg.h : main header file for the RICHEDITDLG application
//

#if !defined(AFX_RICHEDITDLG_H__59E67AD2_D878_4F9F_B875_D3C0EBACF79F__INCLUDED_)
#define AFX_RICHEDITDLG_H__59E67AD2_D878_4F9F_B875_D3C0EBACF79F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRichEditDlgApp:
// See RichEditDlg.cpp for the implementation of this class
//

class CRichEditDlgApp : public CWinApp
{
public:
	CRichEditDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichEditDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRichEditDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHEDITDLG_H__59E67AD2_D878_4F9F_B875_D3C0EBACF79F__INCLUDED_)
