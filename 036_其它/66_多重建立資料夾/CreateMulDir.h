// CreateMulDir.h : main header file for the CREATEMULDIR application
//

#if !defined(AFX_CREATEMULDIR_H__FD7F0E84_6029_4D17_9F90_333152CA7D2C__INCLUDED_)
#define AFX_CREATEMULDIR_H__FD7F0E84_6029_4D17_9F90_333152CA7D2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateMulDirApp:
// See CreateMulDir.cpp for the implementation of this class
//

class CCreateMulDirApp : public CWinApp
{
public:
	CCreateMulDirApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateMulDirApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateMulDirApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEMULDIR_H__FD7F0E84_6029_4D17_9F90_333152CA7D2C__INCLUDED_)
