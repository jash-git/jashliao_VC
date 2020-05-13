// ShowHospital.h : main header file for the SHOWHOSPITAL application
//

#if !defined(AFX_SHOWHOSPITAL_H__AFF6BE94_ECED_4414_9B8F_E62C1E90E6E7__INCLUDED_)
#define AFX_SHOWHOSPITAL_H__AFF6BE94_ECED_4414_9B8F_E62C1E90E6E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowHospitalApp:
// See ShowHospital.cpp for the implementation of this class
//

class CShowHospitalApp : public CWinApp
{
public:
	CShowHospitalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowHospitalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowHospitalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWHOSPITAL_H__AFF6BE94_ECED_4414_9B8F_E62C1E90E6E7__INCLUDED_)
