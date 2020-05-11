// MemsGroServer.h : main header file for the MEMSGROSERVER application
//

#if !defined(AFX_MEMSGROSERVER_H__3D354A06_5E8F_49C5_B722_4C16D6F2EF18__INCLUDED_)
#define AFX_MEMSGROSERVER_H__3D354A06_5E8F_49C5_B722_4C16D6F2EF18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMemsGroServerApp:
// See MemsGroServer.cpp for the implementation of this class
//

class CMemsGroServerApp : public CWinApp
{
public:
	CMemsGroServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemsGroServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMemsGroServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMSGROSERVER_H__3D354A06_5E8F_49C5_B722_4C16D6F2EF18__INCLUDED_)
