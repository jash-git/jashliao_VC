// Create_2003AD_User.h : main header file for the CREATE_2003AD_USER application
//

#if !defined(AFX_CREATE_2003AD_USER_H__CB04F498_094C_46A3_9BE0_6752FB3AD34B__INCLUDED_)
#define AFX_CREATE_2003AD_USER_H__CB04F498_094C_46A3_9BE0_6752FB3AD34B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreate_2003AD_UserApp:
// See Create_2003AD_User.cpp for the implementation of this class
//

class CCreate_2003AD_UserApp : public CWinApp
{
public:
	CCreate_2003AD_UserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_2003AD_UserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreate_2003AD_UserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_2003AD_USER_H__CB04F498_094C_46A3_9BE0_6752FB3AD34B__INCLUDED_)
