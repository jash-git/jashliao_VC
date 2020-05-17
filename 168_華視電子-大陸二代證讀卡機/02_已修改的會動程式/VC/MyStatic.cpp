// MyStatic.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyStatic.h"
#include "MyStaticDlg.h"
#include <GdiPlus.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#pragma comment(lib, "GdiPlus.lib")
using namespace Gdiplus;


/////////////////////////////////////////////////////////////////////////////
// CMyStaticApp

BEGIN_MESSAGE_MAP(CMyStaticApp, CWinApp)
	//{{AFX_MSG_MAP(CMyStaticApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStaticApp construction

CMyStaticApp::CMyStaticApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_gdiplusToken = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyStaticApp object

CMyStaticApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyStaticApp initialization

BOOL CMyStaticApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	CMyStaticDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CMyStaticApp::ExitInstance()
{
	// TODO: Add your specialized code here and/or call the base class

	GdiplusShutdown(m_gdiplusToken);

	return CWinApp::ExitInstance();
}
