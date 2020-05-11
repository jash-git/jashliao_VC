// CutString.h : main header file for the CUTSTRING application
//

#if !defined(AFX_CUTSTRING_H__FEADD62B_21C6_411F_9B53_FD09ED987223__INCLUDED_)
#define AFX_CUTSTRING_H__FEADD62B_21C6_411F_9B53_FD09ED987223__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCutStringApp:
// See CutString.cpp for the implementation of this class
//

class CCutStringApp : public CWinApp
{
public:
	CCutStringApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutStringApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCutStringApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTSTRING_H__FEADD62B_21C6_411F_9B53_FD09ED987223__INCLUDED_)
