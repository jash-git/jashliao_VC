// Show2.h : main header file for the SHOW2 application
//

#if !defined(AFX_SHOW2_H__5E5B555F_2116_4792_B7F5_6C50B63DE2CE__INCLUDED_)
#define AFX_SHOW2_H__5E5B555F_2116_4792_B7F5_6C50B63DE2CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShow2App:
// See Show2.cpp for the implementation of this class
//

class CShow2App : public CWinApp
{
public:
	CShow2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShow2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShow2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOW2_H__5E5B555F_2116_4792_B7F5_6C50B63DE2CE__INCLUDED_)
