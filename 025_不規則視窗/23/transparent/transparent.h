// transparent.h : main header file for the TRANSPARENT application
//

#if !defined(AFX_TRANSPARENT_H__D4FCE10B_429D_4F40_9707_F3B9BA3FE250__INCLUDED_)
#define AFX_TRANSPARENT_H__D4FCE10B_429D_4F40_9707_F3B9BA3FE250__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "MyWnd.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CTransparentApp:
// See transparent.cpp for the implementation of this class
//

class CTransparentApp : public CWinApp
{
public:
	CTransparentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransparentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransparentApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMyWnd m_wndMain;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSPARENT_H__D4FCE10B_429D_4F40_9707_F3B9BA3FE250__INCLUDED_)
