// GetIP2MAC.h : main header file for the GETIP2MAC application
//

#if !defined(AFX_GETIP2MAC_H__435A93E9_275C_4AFD_8F6B_AF7C9168D58D__INCLUDED_)
#define AFX_GETIP2MAC_H__435A93E9_275C_4AFD_8F6B_AF7C9168D58D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetIP2MACApp:
// See GetIP2MAC.cpp for the implementation of this class
//

class CGetIP2MACApp : public CWinApp
{
public:
	CGetIP2MACApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetIP2MACApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetIP2MACApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETIP2MAC_H__435A93E9_275C_4AFD_8F6B_AF7C9168D58D__INCLUDED_)
