// ScriptControlMacro.h : main header file for the SCRIPTCONTROLMACRO application
//

#if !defined(AFX_SCRIPTCONTROLMACRO_H__40684539_828B_486A_8F4B_48DB080FE7C2__INCLUDED_)
#define AFX_SCRIPTCONTROLMACRO_H__40684539_828B_486A_8F4B_48DB080FE7C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "Resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroApp:
// See ScriptControlMacro.cpp for the implementation of this class
//

class CScriptControlMacroApp : public CWinApp
{
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptControlMacroApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual void AddToRecentFileList(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CScriptControlMacroApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	HANDLE m_hFileMap;
	HINSTANCE m_appLangDLL;
	BOOL m_fMRUMenuVisible;
	BOOL UpdateMRUMenu();
};

// Make application object variable globally accessible.

extern CScriptControlMacroApp theApp;

// MFC "hidden" function declaration.

CString AFXAPI AfxStringFromCLSID( REFCLSID );

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTCONTROLMACRO_H__40684539_828B_486A_8F4B_48DB080FE7C2__INCLUDED_)
