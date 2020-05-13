// GetNowNewsAV.h : main header file for the GETNOWNEWSAV application
//

#if !defined(AFX_GETNOWNEWSAV_H__173AFE26_39F2_49F5_9F79_9200FE22397F__INCLUDED_)
#define AFX_GETNOWNEWSAV_H__173AFE26_39F2_49F5_9F79_9200FE22397F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVApp:
// See GetNowNewsAV.cpp for the implementation of this class
//

class CGetNowNewsAVApp : public CWinApp
{
protected:
	BOOL FirstInstance();
public:
	CGetNowNewsAVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetNowNewsAVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetNowNewsAVApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETNOWNEWSAV_H__173AFE26_39F2_49F5_9F79_9200FE22397F__INCLUDED_)
