// GPSDataSave.h : main header file for the GPSDATASAVE application
//

#if !defined(AFX_GPSDATASAVE_H__0940226B_3E4B_4C52_BB6F_BD596C0FD37D__INCLUDED_)
#define AFX_GPSDATASAVE_H__0940226B_3E4B_4C52_BB6F_BD596C0FD37D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGPSDataSaveApp:
// See GPSDataSave.cpp for the implementation of this class
//

class CGPSDataSaveApp : public CWinApp
{
public:
	CGPSDataSaveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPSDataSaveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGPSDataSaveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPSDATASAVE_H__0940226B_3E4B_4C52_BB6F_BD596C0FD37D__INCLUDED_)
