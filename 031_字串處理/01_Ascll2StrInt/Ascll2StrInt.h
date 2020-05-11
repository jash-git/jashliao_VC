// Ascll2StrInt.h : main header file for the ASCLL2STRINT application
//

#if !defined(AFX_ASCLL2STRINT_H__F9E1B858_58CF_4007_B575_6803F129B15C__INCLUDED_)
#define AFX_ASCLL2STRINT_H__F9E1B858_58CF_4007_B575_6803F129B15C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAscll2StrIntApp:
// See Ascll2StrInt.cpp for the implementation of this class
//

class CAscll2StrIntApp : public CWinApp
{
public:
	CAscll2StrIntApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAscll2StrIntApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAscll2StrIntApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASCLL2STRINT_H__F9E1B858_58CF_4007_B575_6803F129B15C__INCLUDED_)
