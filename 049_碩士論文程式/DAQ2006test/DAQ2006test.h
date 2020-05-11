// DAQ2006test.h : main header file for the DAQ2006TEST application
//

#if !defined(AFX_DAQ2006TEST_H__9125336B_2455_4B11_B00E_50FEB97B39C5__INCLUDED_)
#define AFX_DAQ2006TEST_H__9125336B_2455_4B11_B00E_50FEB97B39C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDAQ2006testApp:
// See DAQ2006test.cpp for the implementation of this class
//

class CDAQ2006testApp : public CWinApp
{
public:
	CDAQ2006testApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDAQ2006testApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDAQ2006testApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAQ2006TEST_H__9125336B_2455_4B11_B00E_50FEB97B39C5__INCLUDED_)
