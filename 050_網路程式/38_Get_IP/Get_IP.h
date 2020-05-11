// Get_IP.h : main header file for the GET_IP application
//

#if !defined(AFX_GET_IP_H__6A4B95EE_37C2_4E74_9C1C_CC06B75FB59A__INCLUDED_)
#define AFX_GET_IP_H__6A4B95EE_37C2_4E74_9C1C_CC06B75FB59A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGet_IPApp:
// See Get_IP.cpp for the implementation of this class
//

class CGet_IPApp : public CWinApp
{
public:
	CGet_IPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_IPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGet_IPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GET_IP_H__6A4B95EE_37C2_4E74_9C1C_CC06B75FB59A__INCLUDED_)
