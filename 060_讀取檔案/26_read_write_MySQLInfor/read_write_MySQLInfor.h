// read_write_MySQLInfor.h : main header file for the READ_WRITE_MYSQLINFOR application
//

#if !defined(AFX_READ_WRITE_MYSQLINFOR_H__8A8A74EB_0ACD_43C2_AB45_0C53B25A4D7F__INCLUDED_)
#define AFX_READ_WRITE_MYSQLINFOR_H__8A8A74EB_0ACD_43C2_AB45_0C53B25A4D7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRead_Write_MySQLInforApp:
// See read_write_MySQLInfor.cpp for the implementation of this class
//

class CRead_Write_MySQLInforApp : public CWinApp
{
public:
	CRead_Write_MySQLInforApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRead_Write_MySQLInforApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRead_Write_MySQLInforApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READ_WRITE_MYSQLINFOR_H__8A8A74EB_0ACD_43C2_AB45_0C53B25A4D7F__INCLUDED_)
