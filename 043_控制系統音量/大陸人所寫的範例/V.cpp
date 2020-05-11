// V.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "V.h"
#include "VDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVApp

BEGIN_MESSAGE_MAP(CVApp, CWinApp)
	//{{AFX_MSG_MAP(CVApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVApp construction

CVApp::CVApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CVApp object

CVApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CVApp initialization

BOOL CVApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	this->m_pszProfileName=".\\Settings.ini";

	CString str="clock";
	m=OpenMutex(MUTEX_ALL_ACCESS,false,str);
	if(m==NULL)
	{
		m=CreateMutex(NULL,false,str);
	}
	
	else
	{
		MessageBox(NULL,"该程序已经在运行了!","音量控制",MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	CVDlg dlg;
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

int CVApp::ExitInstance() 
{
	if(m!=NULL)
		ReleaseMutex(m);
	return CWinApp::ExitInstance();
}
