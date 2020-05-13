// NetWork_Browse_Copy.h : main header file for the NETWORK_BROWSE_COPY application
//

#if !defined(AFX_NETWORK_BROWSE_COPY_H__0FC20417_2788_4CF3_923D_F90144EA5083__INCLUDED_)
#define AFX_NETWORK_BROWSE_COPY_H__0FC20417_2788_4CF3_923D_F90144EA5083__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetWork_Browse_CopyApp:
// See NetWork_Browse_Copy.cpp for the implementation of this class
//

class CNetWork_Browse_CopyApp : public CWinApp
{
public:
	CNetWork_Browse_CopyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetWork_Browse_CopyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetWork_Browse_CopyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETWORK_BROWSE_COPY_H__0FC20417_2788_4CF3_923D_F90144EA5083__INCLUDED_)
