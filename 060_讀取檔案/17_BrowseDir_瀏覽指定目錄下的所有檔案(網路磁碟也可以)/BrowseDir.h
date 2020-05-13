// BrowseDir.h : main header file for the BROWSEDIR application
//

#if !defined(AFX_BROWSEDIR_H__F86BED05_66D8_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_BROWSEDIR_H__F86BED05_66D8_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrowseDirApp:
// See BrowseDir.cpp for the implementation of this class
//

class CBrowseDirApp : public CWinApp
{
public:
	CBrowseDirApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseDirApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBrowseDirApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEDIR_H__F86BED05_66D8_11D6_8F32_00E04CE76240__INCLUDED_)
