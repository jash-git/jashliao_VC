// transparent.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "transparent.h"
#include "MyWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransparentApp

BEGIN_MESSAGE_MAP(CTransparentApp, CWinApp)
	//{{AFX_MSG_MAP(CTransparentApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransparentApp construction

CTransparentApp::CTransparentApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTransparentApp object

CTransparentApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTransparentApp initialization

BOOL CTransparentApp::InitInstance()
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

	m_pMainWnd = &m_wndMain;

	CRect rectWnd(500, 300, 580, 380);
	m_wndMain.Initialize(_T("loveghost"),rectWnd,IDB_MASK,IDB_SHOW);

	m_wndMain.ShowWindow(SW_SHOW);	// 窗体创建完毕，显示之
//	m_wndMain.UpdateWindow();


	return TRUE;	// 返回非零值表示要继续处理消息
}
