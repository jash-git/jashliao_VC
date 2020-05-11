// combox_control.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "combox_control.h"
#include "combox_controlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////
//Step2_Hook
#define ON_0 WM_USER + 500
#define ON_1 WM_USER + 501
#define ON_2 WM_USER + 502
#define ON_3 WM_USER + 503 
#define ON_4 WM_USER + 504 
#define ON_5 WM_USER + 505 
#define ON_6 WM_USER + 506 
#define ON_7 WM_USER + 507 
#define ON_8 WM_USER + 508 
#define ON_9 WM_USER + 509 
static HHOOK Hook=NULL;
LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam); 
void SaveLog(char* c); 
LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam) 
{ 
	//让其它全局钩子获得消息
	LRESULT Result=CallNextHookEx(Hook,nCode,wParam,lParam); 
	int intvalue=0;
	if(nCode==HC_ACTION) 
	{ 
		if(lParam & 0x80000000) 
		{ 
			//保存按键消息
			char c[1]; 
			c[0]=wParam;
			intvalue=wParam;
			if(intvalue>47||intvalue<58)
			{
				HWND hWnd = FindWindow(NULL, "combox_control");
				switch(intvalue)
				{
					case 48://0
						::PostMessage(hWnd,ON_0,0,0);
						break;
					case 49://1
						::PostMessage(hWnd,ON_1,0,0);
						break;
					case 50://2
						::PostMessage(hWnd,ON_2,0,0);
						break;
					case 51://3
						::PostMessage(hWnd,ON_3,0,0);
						break;
					case 52://4
						::PostMessage(hWnd,ON_4,0,0);
						break;
					case 53://5
						::PostMessage(hWnd,ON_5,0,0);
						break;
					case 54://6
						::PostMessage(hWnd,ON_6,0,0);
						break;
					case 55://7
						::PostMessage(hWnd,ON_7,0,0);
						break;
					case 56://8
						::PostMessage(hWnd,ON_8,0,0);
						break;
					case 57://9
						::PostMessage(hWnd,ON_9,0,0);
						break;
				}
			}
			SaveLog(c);
		} 
	} 
	return Result;
}
void SaveLog(char* c) 
{ 
	//获得当前时间
	CTime tm=CTime::GetCurrentTime(); 
	CString name; 
	name.Format("Key_%d_%d.log",tm.GetMonth(),tm.GetDay()); 
	CFile file; 
	//打开文件
	if(!file.Open(name,CFile::modeReadWrite)) 
	{ 
		file.Open(name,CFile::modeCreate|CFile::modeReadWrite); 
	} 
	//在文件末尾写
	file.SeekToEnd(); 
	file.Write(c,1); 
	file.Close(); 
}
///////////////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////////////////
// CCombox_controlApp

BEGIN_MESSAGE_MAP(CCombox_controlApp, CWinApp)
	//{{AFX_MSG_MAP(CCombox_controlApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCombox_controlApp construction

CCombox_controlApp::CCombox_controlApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCombox_controlApp object

CCombox_controlApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCombox_controlApp initialization

BOOL CCombox_controlApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();
	Hook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD,(HOOKPROC)LauncherHook,m_hInstance,0);//Step3_Hook
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CCombox_controlDlg dlg;
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
