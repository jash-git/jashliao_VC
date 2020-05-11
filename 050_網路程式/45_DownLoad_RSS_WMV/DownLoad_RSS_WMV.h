// DownLoad_RSS_WMV.h : main header file for the DOWNLOAD_RSS_WMV application
//

#if !defined(AFX_DOWNLOAD_RSS_WMV_H__7130AA22_E5D6_41F0_A524_81DB9C5A1B19__INCLUDED_)
#define AFX_DOWNLOAD_RSS_WMV_H__7130AA22_E5D6_41F0_A524_81DB9C5A1B19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownLoad_RSS_WMVApp:
// See DownLoad_RSS_WMV.cpp for the implementation of this class
//

class CDownLoad_RSS_WMVApp : public CWinApp
{
public:
	CDownLoad_RSS_WMVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoad_RSS_WMVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDownLoad_RSS_WMVApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOAD_RSS_WMV_H__7130AA22_E5D6_41F0_A524_81DB9C5A1B19__INCLUDED_)
