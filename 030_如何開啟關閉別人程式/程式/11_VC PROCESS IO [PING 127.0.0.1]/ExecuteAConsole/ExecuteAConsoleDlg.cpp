// ExecuteAConsoleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExecuteAConsole.h"
#include "ExecuteAConsoleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CExecuteAConsoleDlg dialog

CExecuteAConsoleDlg::CExecuteAConsoleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExecuteAConsoleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExecuteAConsoleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExecuteAConsoleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExecuteAConsoleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExecuteAConsoleDlg, CDialog)
	//{{AFX_MSG_MAP(CExecuteAConsoleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExecuteAConsoleDlg message handlers

BOOL CExecuteAConsoleDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CExecuteAConsoleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExecuteAConsoleDlg::OnPaint() 
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
HCURSOR CExecuteAConsoleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CExecuteAConsoleDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf;
	StrBuf=ExecuteExternalFile("ping","127.0.0.1");
	MessageBox(StrBuf);// 輸出
	MessageBox("finish...");// 輸出
}
CString CExecuteAConsoleDlg::ExecuteExternalFile(CString csExeName, CString csArguments)
{
  CString csExecute;
  csExecute=csExeName + " " + csArguments;
  
  SECURITY_ATTRIBUTES secattr; 
  ZeroMemory(&secattr,sizeof(secattr));
  secattr.nLength = sizeof(secattr);
  secattr.bInheritHandle = TRUE;

  HANDLE rPipe, wPipe;

  //Create pipes to write and read data
  CreatePipe(&rPipe,&wPipe,&secattr,0);
  //
  STARTUPINFO sInfo; 
  ZeroMemory(&sInfo,sizeof(sInfo));
  PROCESS_INFORMATION pInfo; 
  ZeroMemory(&pInfo,sizeof(pInfo));
  sInfo.cb=sizeof(sInfo);
  sInfo.dwFlags=STARTF_USESTDHANDLES;
  sInfo.hStdInput=NULL; 
  sInfo.hStdOutput=wPipe; 
  sInfo.hStdError=wPipe;
  char command[1024]; 
  strcpy(command,csExecute.GetBuffer(csExecute.GetLength()));

  //Create the process here.
  CreateProcess(0,command,0,0,TRUE,NORMAL_PRIORITY_CLASS|CREATE_NO_WINDOW,0,0,&sInfo,&pInfo);
  CloseHandle(wPipe);

  //now read the output pipe here.
  char buf[100];
  DWORD reDword; 
  CString m_csOutput,csTemp;
  BOOL res;
  do
  {
                  res=::ReadFile(rPipe,buf,100,&reDword,0);
                  csTemp=buf;
                  m_csOutput+=csTemp.Left(reDword);
  }while(res);
  return m_csOutput;
}


void CExecuteAConsoleDlg::OnButton2() 
{
	SECURITY_ATTRIBUTES sa,sa2;
	HANDLE hInputRead,hInputWrite;
	HANDLE hOutputRead,hOutputWrite;
	//CreatePipe1
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreatePipe(&hOutputRead,&hOutputWrite,&sa,0))
	{
		return;
	}
	//CreatePipe2
	sa2.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa2.lpSecurityDescriptor = NULL;
	sa2.bInheritHandle = TRUE;
	if (!CreatePipe(&hInputRead,&hInputWrite,&sa2,0))
	{
		return;
	}
	//CreateProcess
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.hStdError = hOutputWrite;
	si.hStdOutput = hOutputWrite;
	si.hStdInput = hInputRead;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	DWORD dwWritten;
	if (!CreateProcess(NULL,"cmd.exe",NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
	{
		MessageBox("Error On CreateProcess");
		return;
	}
	CloseHandle(hInputRead);
	CloseHandle(hOutputWrite);
	//Write and read
	char szInPut[20] ="ping 127.0.0.1\n";// 設置輸入內容
	WriteFile(hInputWrite, szInPut, strlen(szInPut), &dwWritten, NULL);
	char buffer[4096] = {0};
	DWORD bytesRead;
	bool blncheck;
	while (true)
	{ 
		Sleep(500);
		blncheck=false;
		buffer[0]='\0';
		blncheck=PeekNamedPipe(hOutputRead,buffer,1024,&bytesRead,0,0);
		if(bytesRead>0)
			blncheck=ReadFile(hOutputRead,buffer,bytesRead,&bytesRead,0);
		else
			break;
		MessageBox(buffer);// 輸出
		
	}
	CloseHandle(hInputWrite);
	CloseHandle(hOutputRead);
	MessageBox("finish...");// 輸出

}
