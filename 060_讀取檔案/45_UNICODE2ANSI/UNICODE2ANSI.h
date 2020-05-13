// UNICODE2ANSI.h : main header file for the UNICODE2ANSI application
//

#if !defined(AFX_UNICODE2ANSI_H__DC0505F0_90FD_44FA_B06A_54634CC25D8F__INCLUDED_)
#define AFX_UNICODE2ANSI_H__DC0505F0_90FD_44FA_B06A_54634CC25D8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUNICODE2ANSIApp:
// See UNICODE2ANSI.cpp for the implementation of this class
//

class CUNICODE2ANSIApp : public CWinApp
{
public:
	CUNICODE2ANSIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUNICODE2ANSIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUNICODE2ANSIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UNICODE2ANSI_H__DC0505F0_90FD_44FA_B06A_54634CC25D8F__INCLUDED_)
