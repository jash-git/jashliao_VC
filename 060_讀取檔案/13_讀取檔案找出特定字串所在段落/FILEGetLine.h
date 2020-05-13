// FILEGetLine.h : main header file for the FILEGETLINE application
//

#if !defined(AFX_FILEGETLINE_H__CFBACAAE_41BE_47AF_A165_943F5152F8CF__INCLUDED_)
#define AFX_FILEGETLINE_H__CFBACAAE_41BE_47AF_A165_943F5152F8CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFILEGetLineApp:
// See FILEGetLine.cpp for the implementation of this class
//

class CFILEGetLineApp : public CWinApp
{
public:
	CFILEGetLineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFILEGetLineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFILEGetLineApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEGETLINE_H__CFBACAAE_41BE_47AF_A165_943F5152F8CF__INCLUDED_)
