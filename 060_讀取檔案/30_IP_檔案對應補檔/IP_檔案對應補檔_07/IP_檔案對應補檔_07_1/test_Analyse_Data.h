// test_Analyse_Data.h : main header file for the TEST_ANALYSE_DATA application
//

#if !defined(AFX_TEST_ANALYSE_DATA_H__89746ACB_D312_4493_9482_8EFBB104286B__INCLUDED_)
#define AFX_TEST_ANALYSE_DATA_H__89746ACB_D312_4493_9482_8EFBB104286B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_Analyse_DataApp:
// See test_Analyse_Data.cpp for the implementation of this class
//

class CTest_Analyse_DataApp : public CWinApp
{
public:
	CTest_Analyse_DataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Analyse_DataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_Analyse_DataApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_ANALYSE_DATA_H__89746ACB_D312_4493_9482_8EFBB104286B__INCLUDED_)
