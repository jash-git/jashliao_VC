// createdeleteie.h : main header file for the CREATEDELETEIE application
//

#if !defined(AFX_CREATEDELETEIE_H__DD8FE148_DFAC_4823_ACC3_E8C6A058D472__INCLUDED_)
#define AFX_CREATEDELETEIE_H__DD8FE148_DFAC_4823_ACC3_E8C6A058D472__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreatedeleteieApp:
// See createdeleteie.cpp for the implementation of this class
//

class CCreatedeleteieApp : public CWinApp
{
public:
	CCreatedeleteieApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreatedeleteieApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreatedeleteieApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDELETEIE_H__DD8FE148_DFAC_4823_ACC3_E8C6A058D472__INCLUDED_)
