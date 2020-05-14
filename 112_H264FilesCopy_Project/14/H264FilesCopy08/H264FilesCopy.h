// H264FilesCopy.h : main header file for the H264FILESCOPY application
//

#if !defined(AFX_H264FILESCOPY_H__482E4B78_B061_4713_A14E_D4B7D3D00953__INCLUDED_)
#define AFX_H264FILESCOPY_H__482E4B78_B061_4713_A14E_D4B7D3D00953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CH264FilesCopyApp:
// See H264FilesCopy.cpp for the implementation of this class
//

class CH264FilesCopyApp : public CWinApp
{
public:
	CH264FilesCopyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CH264FilesCopyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CH264FilesCopyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_H264FILESCOPY_H__482E4B78_B061_4713_A14E_D4B7D3D00953__INCLUDED_)
