// Offline.h : main header file for the OFFLINE application
//

#if !defined(AFX_OFFLINE_H__7831555D_121A_451A_813F_2E7E22CAB582__INCLUDED_)
#define AFX_OFFLINE_H__7831555D_121A_451A_813F_2E7E22CAB582__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COfflineApp:
// See Offline.cpp for the implementation of this class
//

class COfflineApp : public CWinApp
{
public:
	COfflineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COfflineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COfflineApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OFFLINE_H__7831555D_121A_451A_813F_2E7E22CAB582__INCLUDED_)
