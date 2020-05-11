// 8136_3asix.h : main header file for the 8136_3ASIX application
//

#if !defined(AFX_8136_3ASIX_H__5F3214EE_C28A_4DCF_B79B_3F2B7CA28717__INCLUDED_)
#define AFX_8136_3ASIX_H__5F3214EE_C28A_4DCF_B79B_3F2B7CA28717__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy8136_3asixApp:
// See 8136_3asix.cpp for the implementation of this class
//

class CMy8136_3asixApp : public CWinApp
{
public:
	CMy8136_3asixApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8136_3asixApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy8136_3asixApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8136_3ASIX_H__5F3214EE_C28A_4DCF_B79B_3F2B7CA28717__INCLUDED_)
