// Jiugong.h : main header file for the JIUGONG application
//

#if !defined(AFX_JIUGONG_H__22B724E9_7188_41B0_94E8_8FCF2CC9E0C4__INCLUDED_)
#define AFX_JIUGONG_H__22B724E9_7188_41B0_94E8_8FCF2CC9E0C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJiugongApp:
// See Jiugong.cpp for the implementation of this class
//

class CJiugongApp : public CWinApp
{
public:
	CJiugongApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiugongApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJiugongApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIUGONG_H__22B724E9_7188_41B0_94E8_8FCF2CC9E0C4__INCLUDED_)
