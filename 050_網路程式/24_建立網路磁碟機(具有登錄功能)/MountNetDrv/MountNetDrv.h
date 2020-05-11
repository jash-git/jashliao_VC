// MountNetDrv.h : main header file for the MOUNTNETDRV application
//

#if !defined(AFX_MOUNTNETDRV_H__7B9D53AF_77B9_474F_9956_27DF7FA3C21B__INCLUDED_)
#define AFX_MOUNTNETDRV_H__7B9D53AF_77B9_474F_9956_27DF7FA3C21B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMountNetDrvApp:
// See MountNetDrv.cpp for the implementation of this class
//

class CMountNetDrvApp : public CWinApp
{
public:
	CMountNetDrvApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMountNetDrvApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMountNetDrvApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUNTNETDRV_H__7B9D53AF_77B9_474F_9956_27DF7FA3C21B__INCLUDED_)
