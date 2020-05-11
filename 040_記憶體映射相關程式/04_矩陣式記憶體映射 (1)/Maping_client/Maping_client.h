// Maping_client.h : main header file for the MAPING_CLIENT application
//

#if !defined(AFX_MAPING_CLIENT_H__61689817_73B5_4FA9_981B_5F494DAC0EF7__INCLUDED_)
#define AFX_MAPING_CLIENT_H__61689817_73B5_4FA9_981B_5F494DAC0EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMaping_clientApp:
// See Maping_client.cpp for the implementation of this class
//

class CMaping_clientApp : public CWinApp
{
public:
	CMaping_clientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaping_clientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMaping_clientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPING_CLIENT_H__61689817_73B5_4FA9_981B_5F494DAC0EF7__INCLUDED_)
