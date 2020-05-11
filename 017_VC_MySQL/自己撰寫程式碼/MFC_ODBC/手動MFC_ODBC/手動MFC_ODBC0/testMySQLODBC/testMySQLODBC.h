// testMySQLODBC.h : main header file for the TESTMYSQLODBC application
//

#if !defined(AFX_TESTMYSQLODBC_H__6DC901C7_2F07_452D_ADF1_05161E9D7050__INCLUDED_)
#define AFX_TESTMYSQLODBC_H__6DC901C7_2F07_452D_ADF1_05161E9D7050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestMySQLODBCApp:
// See testMySQLODBC.cpp for the implementation of this class
//

class CTestMySQLODBCApp : public CWinApp
{
public:
	CTestMySQLODBCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestMySQLODBCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestMySQLODBCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTMYSQLODBC_H__6DC901C7_2F07_452D_ADF1_05161E9D7050__INCLUDED_)
