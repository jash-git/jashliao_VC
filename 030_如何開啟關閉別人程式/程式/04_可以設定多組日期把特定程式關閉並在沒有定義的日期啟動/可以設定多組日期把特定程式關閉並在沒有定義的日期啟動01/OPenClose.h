// OPenClose.h : main header file for the OPENCLOSE application
//

#if !defined(AFX_OPENCLOSE_H__35650184_2470_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_OPENCLOSE_H__35650184_2470_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COPenCloseApp:
// See OPenClose.cpp for the implementation of this class
//

class COPenCloseApp : public CWinApp
{
public:
	COPenCloseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPenCloseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COPenCloseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENCLOSE_H__35650184_2470_11DA_B776_0040F43A9B72__INCLUDED_)
