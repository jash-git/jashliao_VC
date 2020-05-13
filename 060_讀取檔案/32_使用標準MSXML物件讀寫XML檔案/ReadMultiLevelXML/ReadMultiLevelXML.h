// ReadMultiLevelXML.h : main header file for the READMULTILEVELXML application
//

#if !defined(AFX_READMULTILEVELXML_H__8867FB1F_7B60_4747_B1AB_644F8492D814__INCLUDED_)
#define AFX_READMULTILEVELXML_H__8867FB1F_7B60_4747_B1AB_644F8492D814__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReadMultiLevelXMLApp:
// See ReadMultiLevelXML.cpp for the implementation of this class
//

class CReadMultiLevelXMLApp : public CWinApp
{
public:
	CReadMultiLevelXMLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadMultiLevelXMLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReadMultiLevelXMLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READMULTILEVELXML_H__8867FB1F_7B60_4747_B1AB_644F8492D814__INCLUDED_)
