// ServerFile.h : main header file for the SERVERFILE application
//

#if !defined(AFX_SERVERFILE_H__2B4EA484_30E1_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_SERVERFILE_H__2B4EA484_30E1_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CServerFileApp:
// See ServerFile.cpp for the implementation of this class
//

class CServerFileApp : public CWinApp
{
public:
	CServerFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CServerFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERFILE_H__2B4EA484_30E1_11DA_B776_0040F43A9B72__INCLUDED_)
