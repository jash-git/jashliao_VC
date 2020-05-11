// Get_CRLF.h : main header file for the GET_CRLF application
//

#if !defined(AFX_GET_CRLF_H__DDD60300_0AC1_4504_9647_C95729C22341__INCLUDED_)
#define AFX_GET_CRLF_H__DDD60300_0AC1_4504_9647_C95729C22341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGet_CRLFApp:
// See Get_CRLF.cpp for the implementation of this class
//

class CGet_CRLFApp : public CWinApp
{
public:
	CGet_CRLFApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_CRLFApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGet_CRLFApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GET_CRLF_H__DDD60300_0AC1_4504_9647_C95729C22341__INCLUDED_)
