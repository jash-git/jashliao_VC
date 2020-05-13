// ChekMediaFile.h : main header file for the CHEKMEDIAFILE application
//

#if !defined(AFX_CHEKMEDIAFILE_H__CD741BE6_5FB0_4612_97A4_3D032999C195__INCLUDED_)
#define AFX_CHEKMEDIAFILE_H__CD741BE6_5FB0_4612_97A4_3D032999C195__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChekMediaFileApp:
// See ChekMediaFile.cpp for the implementation of this class
//

class CChekMediaFileApp : public CWinApp
{
public:
	CChekMediaFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChekMediaFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChekMediaFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHEKMEDIAFILE_H__CD741BE6_5FB0_4612_97A4_3D032999C195__INCLUDED_)
