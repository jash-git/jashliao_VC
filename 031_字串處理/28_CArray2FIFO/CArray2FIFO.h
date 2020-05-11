// CArray2FIFO.h : main header file for the CARRAY2FIFO application
//

#if !defined(AFX_CARRAY2FIFO_H__845ACF8C_6793_4C49_99F5_E0416FBE99C9__INCLUDED_)
#define AFX_CARRAY2FIFO_H__845ACF8C_6793_4C49_99F5_E0416FBE99C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCArray2FIFOApp:
// See CArray2FIFO.cpp for the implementation of this class
//

class CCArray2FIFOApp : public CWinApp
{
public:
	CCArray2FIFOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArray2FIFOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCArray2FIFOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAY2FIFO_H__845ACF8C_6793_4C49_99F5_E0416FBE99C9__INCLUDED_)
