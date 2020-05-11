// DlgTable.h : main header file for the DLGTABLE application
//

#if !defined(AFX_DLGTABLE_H__A190584E_62DB_4ACB_979A_796A814C3E6B__INCLUDED_)
#define AFX_DLGTABLE_H__A190584E_62DB_4ACB_979A_796A814C3E6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgTableApp:
// See DlgTable.cpp for the implementation of this class
//

class CDlgTableApp : public CWinApp
{
public:
	CDlgTableApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTableApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgTableApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTABLE_H__A190584E_62DB_4ACB_979A_796A814C3E6B__INCLUDED_)
