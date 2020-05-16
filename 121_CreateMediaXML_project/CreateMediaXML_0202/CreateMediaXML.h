// CreateMediaXML.h : main header file for the CREATEMEDIAXML application
//

#if !defined(AFX_CREATEMEDIAXML_H__66978A30_C8AE_430B_9B33_1D48F384EBAB__INCLUDED_)
#define AFX_CREATEMEDIAXML_H__66978A30_C8AE_430B_9B33_1D48F384EBAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateMediaXMLApp:
// See CreateMediaXML.cpp for the implementation of this class
//

class CCreateMediaXMLApp : public CWinApp
{
public:
	CCreateMediaXMLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateMediaXMLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateMediaXMLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEMEDIAXML_H__66978A30_C8AE_430B_9B33_1D48F384EBAB__INCLUDED_)
