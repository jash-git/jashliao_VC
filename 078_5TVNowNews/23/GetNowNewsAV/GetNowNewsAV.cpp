// GetNowNewsAV.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "GetNowNewsAV.h"
#include "GetNowNewsAVDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVApp

BEGIN_MESSAGE_MAP(CGetNowNewsAVApp, CWinApp)
	//{{AFX_MSG_MAP(CGetNowNewsAVApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVApp construction

CGetNowNewsAVApp::CGetNowNewsAVApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CGetNowNewsAVApp object

CGetNowNewsAVApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVApp initialization

BOOL CGetNowNewsAVApp::InitInstance()
{
	if (!FirstInstance())
		return FALSE;	//已经有实例存在了，退出
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

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

	// Parse the command line to see if launched as OLE server
	if (RunEmbedded() || RunAutomated())
	{
		// Register all OLE server (factories) as running.  This enables the
		//  OLE libraries to create objects from other applications.
		COleTemplateServer::RegisterAll();
	}
	else
	{
		// When a server application is launched stand-alone, it is a good idea
		//  to update the system registry in case it has been damaged.
		COleObjectFactory::UpdateRegistryAll();
	}

	CGetNowNewsAVDlg dlg;
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
BOOL CGetNowNewsAVApp::FirstInstance()
{
  CWnd *pWndPrev, *pWndChild;
  
  //根据主窗口类名和主窗口名判断是否已经有实例存在了
  if (pWndPrev = CWnd::FindWindow(_T("#32770"),"GetNowNewsAV"))
  {//如果存在就将其激活，并显示出来
	  
	  pWndChild = pWndPrev->GetLastActivePopup(); 
	  
	  //如果是最小化的就还原窗口
	  if (pWndPrev->IsIconic()) 
		  pWndPrev->ShowWindow(SW_RESTORE);      
	  
	  pWndChild->SetForegroundWindow();         
	 
	  return FALSE;                             
  }
  else
	  return TRUE;                             
}