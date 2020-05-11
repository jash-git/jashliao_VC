// Get_Len.h : main header file for the GET_LEN application
//

#if !defined(AFX_GET_LEN_H__F3D68908_B22C_4DA6_AC45_24F3E261A162__INCLUDED_)
#define AFX_GET_LEN_H__F3D68908_B22C_4DA6_AC45_24F3E261A162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGet_LenApp:
// See Get_Len.cpp for the implementation of this class
//

class CGet_LenApp : public CWinApp
{
public:
	CGet_LenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_LenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGet_LenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GET_LEN_H__F3D68908_B22C_4DA6_AC45_24F3E261A162__INCLUDED_)
