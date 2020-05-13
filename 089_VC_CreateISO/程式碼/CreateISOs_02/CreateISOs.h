// CreateISOs.h : main header file for the CREATEISOS application
//

#if !defined(AFX_CREATEISOS_H__AC96F464_DC75_4E1F_81DD_CDB3843CCCF7__INCLUDED_)
#define AFX_CREATEISOS_H__AC96F464_DC75_4E1F_81DD_CDB3843CCCF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateISOsApp:
// See CreateISOs.cpp for the implementation of this class
//

class CCreateISOsApp : public CWinApp
{
public:
	CCreateISOsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateISOsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateISOsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEISOS_H__AC96F464_DC75_4E1F_81DD_CDB3843CCCF7__INCLUDED_)
