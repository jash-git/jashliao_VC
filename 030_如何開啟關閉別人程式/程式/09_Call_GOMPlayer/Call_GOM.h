// Call_GOM.h : main header file for the CALL_GOM application
//

#if !defined(AFX_CALL_GOM_H__A8C9F1CD_F9BB_4D57_AA0A_B77C95FC7A99__INCLUDED_)
#define AFX_CALL_GOM_H__A8C9F1CD_F9BB_4D57_AA0A_B77C95FC7A99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCall_GOMApp:
// See Call_GOM.cpp for the implementation of this class
//

class CCall_GOMApp : public CWinApp
{
public:
	CCall_GOMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCall_GOMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCall_GOMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALL_GOM_H__A8C9F1CD_F9BB_4D57_AA0A_B77C95FC7A99__INCLUDED_)
