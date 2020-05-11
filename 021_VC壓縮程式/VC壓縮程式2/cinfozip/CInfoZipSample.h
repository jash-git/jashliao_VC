// CInfoZipSample.h : main header file for the CINFOZIPSAMPLE application
//

#if !defined(AFX_CINFOZIPSAMPLE_H__0CA4A9F7_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_)
#define AFX_CINFOZIPSAMPLE_H__0CA4A9F7_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCInfoZipSampleApp:
// See CInfoZipSample.cpp for the implementation of this class
//

class CCInfoZipSampleApp : public CWinApp
{
public:
	CCInfoZipSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCInfoZipSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCInfoZipSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CINFOZIPSAMPLE_H__0CA4A9F7_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_)
