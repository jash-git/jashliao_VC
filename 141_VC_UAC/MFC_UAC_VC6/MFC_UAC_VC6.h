// MFC_UAC_VC6.h : main header file for the MFC_UAC_VC6 application
//

#if !defined(AFX_MFC_UAC_VC6_H__DD0E0C60_B1F8_4286_B0F8_9A85ED875C32__INCLUDED_)
#define AFX_MFC_UAC_VC6_H__DD0E0C60_B1F8_4286_B0F8_9A85ED875C32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_UAC_VC6App:
// See MFC_UAC_VC6.cpp for the implementation of this class
//

class CMFC_UAC_VC6App : public CWinApp
{
public:
	CMFC_UAC_VC6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_UAC_VC6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_UAC_VC6App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_UAC_VC6_H__DD0E0C60_B1F8_4286_B0F8_9A85ED875C32__INCLUDED_)
