// FrameMedia.h : main header file for the FRAMEMEDIA application
//

#if !defined(AFX_FRAMEMEDIA_H__90C589E3_4D12_4A34_8AFC_E62B318E6244__INCLUDED_)
#define AFX_FRAMEMEDIA_H__90C589E3_4D12_4A34_8AFC_E62B318E6244__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaApp:
// See FrameMedia.cpp for the implementation of this class
//

class CFrameMediaApp : public CWinApp
{
public:
	CFrameMediaApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameMediaApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFrameMediaApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMEMEDIA_H__90C589E3_4D12_4A34_8AFC_E62B318E6244__INCLUDED_)
