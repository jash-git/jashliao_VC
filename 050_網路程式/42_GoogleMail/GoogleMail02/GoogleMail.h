// GoogleMail.h : main header file for the GOOGLEMAIL application
//

#if !defined(AFX_GOOGLEMAIL_H__F13C883E_6382_4B88_8A91_BF4901397858__INCLUDED_)
#define AFX_GOOGLEMAIL_H__F13C883E_6382_4B88_8A91_BF4901397858__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGoogleMailApp:
// See GoogleMail.cpp for the implementation of this class
//

class CGoogleMailApp : public CWinApp
{
public:
	CGoogleMailApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoogleMailApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGoogleMailApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOOGLEMAIL_H__F13C883E_6382_4B88_8A91_BF4901397858__INCLUDED_)
