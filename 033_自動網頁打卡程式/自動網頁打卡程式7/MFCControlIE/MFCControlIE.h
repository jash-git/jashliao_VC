// MFCControlIE.h : main header file for the MFCCONTROLIE application
//

#if !defined(AFX_MFCCONTROLIE_H__2AAAFE98_A0E5_4910_89A7_4FCF85267AB6__INCLUDED_)
#define AFX_MFCCONTROLIE_H__2AAAFE98_A0E5_4910_89A7_4FCF85267AB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCControlIEApp:
// See MFCControlIE.cpp for the implementation of this class
//

class CMFCControlIEApp : public CWinApp
{
public:
	CMFCControlIEApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCControlIEApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCControlIEApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCONTROLIE_H__2AAAFE98_A0E5_4910_89A7_4FCF85267AB6__INCLUDED_)
