// BeckRS485Control.h : main header file for the BECKRS485CONTROL application
//

#if !defined(AFX_BECKRS485CONTROL_H__56E9A503_6BA4_4E17_A577_1A817FB96F1C__INCLUDED_)
#define AFX_BECKRS485CONTROL_H__56E9A503_6BA4_4E17_A577_1A817FB96F1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBeckRS485ControlApp:
// See BeckRS485Control.cpp for the implementation of this class
//

class CBeckRS485ControlApp : public CWinApp
{
public:
	CBeckRS485ControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBeckRS485ControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBeckRS485ControlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BECKRS485CONTROL_H__56E9A503_6BA4_4E17_A577_1A817FB96F1C__INCLUDED_)
