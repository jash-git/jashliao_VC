// CallMediaInfo.h : main header file for the CALLMEDIAINFO application
//

#if !defined(AFX_CALLMEDIAINFO_H__E84FC791_7C80_4743_B7C6_C04FDA8BB084__INCLUDED_)
#define AFX_CALLMEDIAINFO_H__E84FC791_7C80_4743_B7C6_C04FDA8BB084__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCallMediaInfoApp:
// See CallMediaInfo.cpp for the implementation of this class
//

class CCallMediaInfoApp : public CWinApp
{
public:
	CCallMediaInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallMediaInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCallMediaInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLMEDIAINFO_H__E84FC791_7C80_4743_B7C6_C04FDA8BB084__INCLUDED_)
