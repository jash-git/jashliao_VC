// NabroSTBTool.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "NabroSTBTool.h"
#include "NabroSTBToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolApp

BEGIN_MESSAGE_MAP(CNabroSTBToolApp, CWinApp)
	//{{AFX_MSG_MAP(CNabroSTBToolApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolApp construction

CNabroSTBToolApp::CNabroSTBToolApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNabroSTBToolApp object

CNabroSTBToolApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolApp initialization

BOOL CNabroSTBToolApp::InitInstance()
{
	if (!FirstInstance())
	{
		return FALSE;
	}
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}
	::CoInitialize(NULL); //step 2:Åª¨úXML
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

	CNabroSTBToolDlg dlg;
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
BOOL CNabroSTBToolApp::FirstInstance()
{
  CWnd *pWndPrev, *pWndChild;
  if (pWndPrev = CWnd::FindWindow(_T("#32770"),"NabroSTBTool"))
  {	  
	  pWndChild = pWndPrev->GetLastActivePopup(); 	  
	  if (pWndPrev->IsIconic()) 
	  {
		  pWndPrev->ShowWindow(SW_RESTORE);
	  }
	  pWndChild->SetForegroundWindow();         
	  return FALSE;                             
  }
  else
  {
	  return TRUE;
  }
}