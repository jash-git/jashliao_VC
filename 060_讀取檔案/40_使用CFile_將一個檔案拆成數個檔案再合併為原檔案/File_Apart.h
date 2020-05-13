// File_Apart.h : main header file for the FILE_APART application
//

#if !defined(AFX_FILE_APART_H__D545492C_0280_407C_9866_8FC7F74AFF92__INCLUDED_)
#define AFX_FILE_APART_H__D545492C_0280_407C_9866_8FC7F74AFF92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFile_ApartApp:
// See File_Apart.cpp for the implementation of this class
//

class CFile_ApartApp : public CWinApp
{
public:
	CFile_ApartApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFile_ApartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFile_ApartApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILE_APART_H__D545492C_0280_407C_9866_8FC7F74AFF92__INCLUDED_)
