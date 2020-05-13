// Create_mms_htm.h : main header file for the CREATE_MMS_HTM application
//

#if !defined(AFX_CREATE_MMS_HTM_H__4184856B_4861_488D_8825_8118093DA2A4__INCLUDED_)
#define AFX_CREATE_MMS_HTM_H__4184856B_4861_488D_8825_8118093DA2A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreate_mms_htmApp:
// See Create_mms_htm.cpp for the implementation of this class
//

class CCreate_mms_htmApp : public CWinApp
{
public:
	CCreate_mms_htmApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_mms_htmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreate_mms_htmApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_MMS_HTM_H__4184856B_4861_488D_8825_8118093DA2A4__INCLUDED_)
