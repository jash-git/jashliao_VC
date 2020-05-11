// Value2Voltage.h : main header file for the VALUE2VOLTAGE application
//

#if !defined(AFX_VALUE2VOLTAGE_H__8A881799_E293_4120_8FDF_D766F9CE8C41__INCLUDED_)
#define AFX_VALUE2VOLTAGE_H__8A881799_E293_4120_8FDF_D766F9CE8C41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CValue2VoltageApp:
// See Value2Voltage.cpp for the implementation of this class
//

class CValue2VoltageApp : public CWinApp
{
public:
	CValue2VoltageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValue2VoltageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CValue2VoltageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VALUE2VOLTAGE_H__8A881799_E293_4120_8FDF_D766F9CE8C41__INCLUDED_)
