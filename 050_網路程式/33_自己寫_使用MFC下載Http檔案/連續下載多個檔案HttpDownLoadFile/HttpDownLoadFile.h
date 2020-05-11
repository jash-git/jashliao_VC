// HttpDownLoadFile.h : main header file for the HTTPDOWNLOADFILE application
//

#if !defined(AFX_HTTPDOWNLOADFILE_H__9CAF9D95_424A_4007_8FE6_BC29857372CF__INCLUDED_)
#define AFX_HTTPDOWNLOADFILE_H__9CAF9D95_424A_4007_8FE6_BC29857372CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHttpDownLoadFileApp:
// See HttpDownLoadFile.cpp for the implementation of this class
//

class CHttpDownLoadFileApp : public CWinApp
{
public:
	CHttpDownLoadFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHttpDownLoadFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHttpDownLoadFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTTPDOWNLOADFILE_H__9CAF9D95_424A_4007_8FE6_BC29857372CF__INCLUDED_)
