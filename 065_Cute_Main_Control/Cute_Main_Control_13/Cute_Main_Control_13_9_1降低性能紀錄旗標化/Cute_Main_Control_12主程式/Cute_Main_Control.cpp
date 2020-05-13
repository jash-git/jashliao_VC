// Cute_Main_Control.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Cute_Main_Control.h"
#include "Cute_Main_ControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlApp

BEGIN_MESSAGE_MAP(CCute_Main_ControlApp, CWinApp)
	//{{AFX_MSG_MAP(CCute_Main_ControlApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlApp construction

CCute_Main_ControlApp::CCute_Main_ControlApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCute_Main_ControlApp object

CCute_Main_ControlApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlApp initialization

BOOL CCute_Main_ControlApp::InitInstance()
{
	HINSTANCE result;
	if(!FirstInstance())//第13.8版->防堵重複執行
	{
		return FALSE;
	}
	else
	{
		CWnd *pWndPrev;
		pWndPrev=CWnd::FindWindow(NULL,"UpdateProgram");
		if(pWndPrev==NULL)
		{
			do
			{
				result=ShellExecute(NULL,"open","UpdateProgram.exe",NULL,NULL,SW_SHOWNORMAL);
			}while((int)result<32);
		}
	}
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}
	::CoInitialize(NULL); //step 讀取XML2
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

	CCute_Main_ControlDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	//SetWindowPos(dlg.m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE); 
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
BOOL CCute_Main_ControlApp::FirstInstance()//第13.8版->防堵重複執行
{
	CWnd *pWndPrev;
	if(pWndPrev=CWnd::FindWindow(_T("#32770"),"Cute_Main_Control"))
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

