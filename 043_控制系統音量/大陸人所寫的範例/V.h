// V.h : main header file for the V application
//

#if !defined(AFX_V_H__61050CAB_BA2D_4012_81CE_140C40CED951__INCLUDED_)
#define AFX_V_H__61050CAB_BA2D_4012_81CE_140C40CED951__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVApp:
// See V.cpp for the implementation of this class
//

class CVApp : public CWinApp
{
public:
	HANDLE m;
	CVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_V_H__61050CAB_BA2D_4012_81CE_140C40CED951__INCLUDED_)
