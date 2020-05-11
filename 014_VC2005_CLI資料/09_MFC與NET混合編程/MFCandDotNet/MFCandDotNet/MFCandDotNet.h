// MFCandDotNet.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCandDotNetApp:
// See MFCandDotNet.cpp for the implementation of this class
//

class CMFCandDotNetApp : public CWinApp
{
public:
	CMFCandDotNetApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCandDotNetApp theApp;