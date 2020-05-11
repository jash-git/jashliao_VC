#if !defined(AFX_TESTACTIVE2IE_H__5DC91B1C_460D_4D31_82F7_0617660572AC__INCLUDED_)
#define AFX_TESTACTIVE2IE_H__5DC91B1C_460D_4D31_82F7_0617660572AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// testActive2IE.h : main header file for TESTACTIVE2IE.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestActive2IEApp : See testActive2IE.cpp for implementation.

class CTestActive2IEApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTACTIVE2IE_H__5DC91B1C_460D_4D31_82F7_0617660572AC__INCLUDED)
