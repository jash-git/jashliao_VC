// NabroSTBTool.h : main header file for the NABROSTBTOOL application
//

#if !defined(AFX_NABROSTBTOOL_H__114E2814_76E5_4E3F_8D15_5C6142A8690E__INCLUDED_)
#define AFX_NABROSTBTOOL_H__114E2814_76E5_4E3F_8D15_5C6142A8690E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolApp:
// See NabroSTBTool.cpp for the implementation of this class
//

class CNabroSTBToolApp : public CWinApp
{
protected:
	BOOL FirstInstance();
public:
	CNabroSTBToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNabroSTBToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNabroSTBToolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NABROSTBTOOL_H__114E2814_76E5_4E3F_8D15_5C6142A8690E__INCLUDED_)
