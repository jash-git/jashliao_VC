// GPSGetData.h : main header file for the GPSGETDATA application
//

#if !defined(AFX_GPSGETDATA_H__9653607A_9F9F_46CC_8916_673712C777B8__INCLUDED_)
#define AFX_GPSGETDATA_H__9653607A_9F9F_46CC_8916_673712C777B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGPSGetDataApp:
// See GPSGetData.cpp for the implementation of this class
//

class CGPSGetDataApp : public CWinApp
{
public:
	CGPSGetDataApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGPSGetDataApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGPSGetDataApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GPSGETDATA_H__9653607A_9F9F_46CC_8916_673712C777B8__INCLUDED_)
