
/////////////////////////////////////////////////////////////////////////////
// DragMoveDlg.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DragMoveDlg.h"
#include "DragMoveDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyApp

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	//{{AFX_MSG_MAP(CMyApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyApp construction

CMyApp::CMyApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyApp object

CMyApp theApp;

//////////////////
// Vanilla frame window
//
class CMainFrame : public CFrameWnd {
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	CMainFrame();
	~CMainFrame();
};

/////////////////////////////////////////////////////////////////////////////
// CMyApp initialization

BOOL CMyApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// create frame window and load it
	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;
	pFrame->LoadFrame(IDR_MAINFRAME, WS_OVERLAPPED, NULL, NULL);

	// create dialog and run it
	CMyDialog dlg(pFrame);
//	m_pMainWnd = &dlg;
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
CMainFrame::CMainFrame()
{
	// nothing to do
}

CMainFrame::~CMainFrame()
{
	// nothing to do
}

//////////////////
// Pre-create window: set WS_EX_TOOLWINDOW style to hide dialog from task bar
//
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (CFrameWnd::PreCreateWindow(cs)) {
		cs.dwExStyle |= WS_EX_TOOLWINDOW;
		return TRUE;
	}
	return FALSE;
}
