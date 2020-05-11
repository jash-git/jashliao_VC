// NoRegular.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "NoRegular.h"
#include "NoRegularDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoRegularApp

BEGIN_MESSAGE_MAP(CNoRegularApp, CWinApp)
	//{{AFX_MSG_MAP(CNoRegularApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoRegularApp construction

CNoRegularApp::CNoRegularApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNoRegularApp object

CNoRegularApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNoRegularApp initialization

BOOL CNoRegularApp::InitInstance()
{
	// Standard initialization

	CNoRegularDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
