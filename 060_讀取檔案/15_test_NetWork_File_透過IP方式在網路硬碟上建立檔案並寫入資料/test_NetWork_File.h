// test_NetWork_File.h : main header file for the TEST_NETWORK_FILE application
//

#if !defined(AFX_TEST_NETWORK_FILE_H__99F4DFA3_372A_4E38_8A31_2386CFBF4764__INCLUDED_)
#define AFX_TEST_NETWORK_FILE_H__99F4DFA3_372A_4E38_8A31_2386CFBF4764__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_NetWork_FileApp:
// See test_NetWork_File.cpp for the implementation of this class
//

class CTest_NetWork_FileApp : public CWinApp
{
public:
	CTest_NetWork_FileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_NetWork_FileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_NetWork_FileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_NETWORK_FILE_H__99F4DFA3_372A_4E38_8A31_2386CFBF4764__INCLUDED_)
