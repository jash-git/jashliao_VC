// MFC_sscanf_pro.h : main header file for the MFC_SSCANF_PRO application
//

#if !defined(AFX_MFC_SSCANF_PRO_H__8F7F074D_BFAD_416F_9C51_80F904CBDB7C__INCLUDED_)
#define AFX_MFC_SSCANF_PRO_H__8F7F074D_BFAD_416F_9C51_80F904CBDB7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_sscanf_proApp:
// See MFC_sscanf_pro.cpp for the implementation of this class
//

class CMFC_sscanf_proApp : public CWinApp
{
public:
	CMFC_sscanf_proApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_sscanf_proApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_sscanf_proApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SSCANF_PRO_H__8F7F074D_BFAD_416F_9C51_80F904CBDB7C__INCLUDED_)
