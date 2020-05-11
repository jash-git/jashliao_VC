// HistoryClear.h : main header file for the HISTORYCLEAR application
//

#if !defined(AFX_HISTORYCLEAR_H__88786E73_133C_444D_AFFB_B739EE9D6CFB__INCLUDED_)
#define AFX_HISTORYCLEAR_H__88786E73_133C_444D_AFFB_B739EE9D6CFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHistoryClearApp:
// See HistoryClear.cpp for the implementation of this class
//

class CHistoryClearApp : public CWinApp
{
public:
	CHistoryClearApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryClearApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHistoryClearApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYCLEAR_H__88786E73_133C_444D_AFFB_B739EE9D6CFB__INCLUDED_)
