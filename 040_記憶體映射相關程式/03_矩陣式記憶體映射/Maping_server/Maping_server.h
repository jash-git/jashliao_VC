// Maping_server.h : main header file for the MAPING_SERVER application
//

#if !defined(AFX_MAPING_SERVER_H__6E93F5B0_374A_4DFA_A099_6E037788B74D__INCLUDED_)
#define AFX_MAPING_SERVER_H__6E93F5B0_374A_4DFA_A099_6E037788B74D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMaping_serverApp:
// See Maping_server.cpp for the implementation of this class
//

class CMaping_serverApp : public CWinApp
{
public:
	CMaping_serverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaping_serverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMaping_serverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPING_SERVER_H__6E93F5B0_374A_4DFA_A099_6E037788B74D__INCLUDED_)
