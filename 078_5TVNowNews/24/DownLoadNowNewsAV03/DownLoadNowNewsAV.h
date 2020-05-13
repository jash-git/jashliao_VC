// DownLoadNowNewsAV.h : main header file for the DOWNLOADNOWNEWSAV application
//

#if !defined(AFX_DOWNLOADNOWNEWSAV_H__EAE9ED5C_F026_4CA5_9F0E_D0AF60936B39__INCLUDED_)
#define AFX_DOWNLOADNOWNEWSAV_H__EAE9ED5C_F026_4CA5_9F0E_D0AF60936B39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDownLoadNowNewsAVApp:
// See DownLoadNowNewsAV.cpp for the implementation of this class
//

class CDownLoadNowNewsAVApp : public CWinApp
{
protected:
	BOOL FirstInstance();
public:
	CDownLoadNowNewsAVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoadNowNewsAVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDownLoadNowNewsAVApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOADNOWNEWSAV_H__EAE9ED5C_F026_4CA5_9F0E_D0AF60936B39__INCLUDED_)
