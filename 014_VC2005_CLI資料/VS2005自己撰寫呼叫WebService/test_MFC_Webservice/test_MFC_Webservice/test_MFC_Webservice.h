// test_MFC_Webservice.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ctest_MFC_WebserviceApp:
// See test_MFC_Webservice.cpp for the implementation of this class
//

class Ctest_MFC_WebserviceApp : public CWinApp
{
public:
	Ctest_MFC_WebserviceApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ctest_MFC_WebserviceApp theApp;