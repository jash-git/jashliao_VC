// CreateCImage.h : main header file for the CreateCImage application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCreateCImageApp:
// See CreateCImage.cpp for the implementation of this class
//

class CCreateCImageApp : public CWinApp
{
public:
	CCreateCImageApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCreateCImageApp theApp;