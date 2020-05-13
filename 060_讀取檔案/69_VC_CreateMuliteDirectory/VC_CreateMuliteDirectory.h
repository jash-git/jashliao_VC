// VC_CreateMuliteDirectory.h : main header file for the VC_CREATEMULITEDIRECTORY application
//

#if !defined(AFX_VC_CREATEMULITEDIRECTORY_H__ECACDFF2_05B4_4FEC_B524_F6CAA9290A30__INCLUDED_)
#define AFX_VC_CREATEMULITEDIRECTORY_H__ECACDFF2_05B4_4FEC_B524_F6CAA9290A30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVC_CreateMuliteDirectoryApp:
// See VC_CreateMuliteDirectory.cpp for the implementation of this class
//

class CVC_CreateMuliteDirectoryApp : public CWinApp
{
public:
	CVC_CreateMuliteDirectoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVC_CreateMuliteDirectoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVC_CreateMuliteDirectoryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VC_CREATEMULITEDIRECTORY_H__ECACDFF2_05B4_4FEC_B524_F6CAA9290A30__INCLUDED_)
