// test_ctrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_ctrl.h"
#include "test_ctrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
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
HINSTANCE hInstLibrary;
typedef void (*SetKeyboardHook)();
typedef void (*ReleaseKeyboardHook)();
SetKeyboardHook _SetKeyboardHook;
ReleaseKeyboardHook _ReleaseKeyboardHook;
/////////////////////////////////////////////////////////////////////////////
  //   globals   
  HANDLE   hCurrentProcess,   hSelfDeleteThread;   
  DWORD   dwSelfDeleteThreadId,   dwExitCode;
   DWORD   WINAPI   tSelfDelete()   
  {   
    
  TCHAR   szModule   [MAX_PATH],   
  szComspec[MAX_PATH],   
  szParams   [MAX_PATH];   
    
  //   get   file   path   names   
  if((GetModuleFileName(0,szModule,MAX_PATH)!=0)   &&   
  (GetShortPathName(szModule,szModule,MAX_PATH)!=0)   &&   
  (GetEnvironmentVariable("Comspec",szComspec,MAX_PATH)!=0))   
  {   
  //   create   comspec   parameters   
  lstrcpy(szParams,"/c   del   ");   //   run   single   command   to...   
  lstrcat(szParams,   szModule);   //   del(ete)   self   file   and...   
  lstrcat(szParams,   "   >   nul");   //   output   results   to   nowhere   
    
  //   execute   command   shell   
  //   and   increase   process+thread   priorities   
  if(((INT)ShellExecute(0,0,szComspec,szParams,0,SW_HIDE)   >   32)&&   
  (SetPriorityClass(hCurrentProcess,HIGH_PRIORITY_CLASS))   &&   
  (SetThreadPriority(hSelfDeleteThread,THREAD_PRIORITY_HIGHEST)))   
  {   
  //   notify   explorer   shell   
  SHChangeNotify(SHCNE_DELETE,SHCNF_PATH,szModule,0);   
  return   1;   
  }   
  }   
  return   0;   
  }   
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_ctrlDlg dialog

CTest_ctrlDlg::CTest_ctrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_ctrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_ctrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_ctrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_ctrlDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_ctrlDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_ctrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_MESSAGE(ON_0,On_click0)
	ON_MESSAGE(ON_1,On_click1)
	ON_MESSAGE(ON_2,On_click2)
	ON_MESSAGE(ON_3,On_click3)
	ON_MESSAGE(ON_4,On_click4)
	ON_MESSAGE(ON_5,On_click5)
	ON_MESSAGE(ON_6,On_click6)
	ON_MESSAGE(ON_7,On_click7)
	ON_MESSAGE(ON_8,On_click8)
	ON_MESSAGE(ON_9,On_click9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_ctrlDlg message handlers

BOOL CTest_ctrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	/////////////////////////////////////////////////////
	hInstLibrary = LoadLibrary("KeybHook.dll");
	if (hInstLibrary == NULL)
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook = (SetKeyboardHook)GetProcAddress(hInstLibrary, "SetKeyboardHook");
	_ReleaseKeyboardHook = (ReleaseKeyboardHook)GetProcAddress(hInstLibrary, "ReleaseKeyboardHook");
	if ((_SetKeyboardHook == NULL) || (_ReleaseKeyboardHook == NULL))
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook();
	///////////////////////////////////////////////////////////////////	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_ctrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTest_ctrlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTest_ctrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CTest_ctrlDlg::On_click0()
{
	OnOK();
}
void CTest_ctrlDlg::On_click1()
{

}
void CTest_ctrlDlg::On_click2()
{

}
void CTest_ctrlDlg::On_click3()
{

}
void CTest_ctrlDlg::On_click4()
{

}
void CTest_ctrlDlg::On_click5()
{

}
void CTest_ctrlDlg::On_click6()
{

}
void CTest_ctrlDlg::On_click7()
{

}
void CTest_ctrlDlg::On_click8()
{

}
void CTest_ctrlDlg::On_click9()
{

}

void CTest_ctrlDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	_ReleaseKeyboardHook();
	FreeLibrary(hInstLibrary);		
}

void CTest_ctrlDlg::OnOK() 
{
	// TODO: Add extra validation here
  //.   .   .   code   .   .   .   
    
  //   set   current   process   to   "all_access"   
  hCurrentProcess=OpenProcess(   
  PROCESS_ALL_ACCESS,TRUE,   
  GetCurrentProcessId());   
    
  //   create   self-delete   thread   
  hSelfDeleteThread=CreateThread(0,0,   
  (LPTHREAD_START_ROUTINE)tSelfDelete,   
  0,0,&dwSelfDeleteThreadId);   
    
  //   add   thread   creation   error   checking   
    
  //   create   thread   state   loop   
  GetExitCodeThread(hSelfDeleteThread,&dwExitCode);   
  while(dwExitCode==STILL_ACTIVE)   
  {   
  GetExitCodeThread(hSelfDeleteThread,&dwExitCode);   
  }   
    
  //   exit   program   stuff   
  CloseHandle(hSelfDeleteThread);   
  CloseHandle(hCurrentProcess);   
  PostQuitMessage(0); 	
	CDialog::OnOK();
}
