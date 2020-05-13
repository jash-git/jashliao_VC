// test_createXML.h : main header file for the TEST_CREATEXML application
//

#if !defined(AFX_TEST_CREATEXML_H__9D7118EF_4C27_44E4_A0A0_489DF78F46FA__INCLUDED_)
#define AFX_TEST_CREATEXML_H__9D7118EF_4C27_44E4_A0A0_489DF78F46FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_createXMLApp:
// See test_createXML.cpp for the implementation of this class
//

class CTest_createXMLApp : public CWinApp
{
public:
	CTest_createXMLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_createXMLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_createXMLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_CREATEXML_H__9D7118EF_4C27_44E4_A0A0_489DF78F46FA__INCLUDED_)
