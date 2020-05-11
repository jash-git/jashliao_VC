// MultiServer.h : main header file for the MULTISERVER application
//

#if !defined(AFX_MULTISERVER_H__E9A16F1F_469A_4FC2_A6D3_9FC4284E3546__INCLUDED_)
#define AFX_MULTISERVER_H__E9A16F1F_469A_4FC2_A6D3_9FC4284E3546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiServerApp:
// See MultiServer.cpp for the implementation of this class
//

class CMultiServerApp : public CWinApp
{
public:
	CMultiServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTISERVER_H__E9A16F1F_469A_4FC2_A6D3_9FC4284E3546__INCLUDED_)
