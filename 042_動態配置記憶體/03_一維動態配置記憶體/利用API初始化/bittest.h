// bittest.h : main header file for the BITTEST application
//

#if !defined(AFX_BITTEST_H__6FEB0E84_2902_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_BITTEST_H__6FEB0E84_2902_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBittestApp:
// See bittest.cpp for the implementation of this class
//

class CBittestApp : public CWinApp
{
public:
	CBittestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBittestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBittestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITTEST_H__6FEB0E84_2902_11DA_B776_0040F43A9B72__INCLUDED_)
