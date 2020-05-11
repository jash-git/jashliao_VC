// test_Set_IP.h : main header file for the TEST_SET_IP application
//

#if !defined(AFX_TEST_SET_IP_H__1F5F4C3E_3DCE_44C4_8136_4F20C84DBD04__INCLUDED_)
#define AFX_TEST_SET_IP_H__1F5F4C3E_3DCE_44C4_8136_4F20C84DBD04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_Set_IPApp:
// See test_Set_IP.cpp for the implementation of this class
//

class CTest_Set_IPApp : public CWinApp
{
public:
	CTest_Set_IPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_Set_IPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_Set_IPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_SET_IP_H__1F5F4C3E_3DCE_44C4_8136_4F20C84DBD04__INCLUDED_)
