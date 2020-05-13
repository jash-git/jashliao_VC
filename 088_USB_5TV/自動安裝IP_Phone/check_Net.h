// check_Net.h : main header file for the CHECK_NET application
//

#if !defined(AFX_CHECK_NET_H__5BF50002_32B6_427A_95D6_CF16FB80AC5A__INCLUDED_)
#define AFX_CHECK_NET_H__5BF50002_32B6_427A_95D6_CF16FB80AC5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCheck_NetApp:
// See check_Net.cpp for the implementation of this class
//

class CCheck_NetApp : public CWinApp
{
public:
	CCheck_NetApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheck_NetApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCheck_NetApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECK_NET_H__5BF50002_32B6_427A_95D6_CF16FB80AC5A__INCLUDED_)
