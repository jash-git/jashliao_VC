// mainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "mainDlg.h"

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
// CMainDlg dialog

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog()
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

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMainDlg::OnPaint() 
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
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMainDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	HANDLE   hSTDINWrite, hSTDINRead;       // 用於重定向子進程輸入的控制碼   
	HANDLE   hSTDOUTWrite, hSTDOUTRead;     // 用於重定向子進程輸出的控制碼   
	SECURITY_ATTRIBUTES   sa;   
    
	sa.bInheritHandle = TRUE;   
	sa.lpSecurityDescriptor = NULL;   
	sa.nLength = sizeof(sa);   

	// 創建子進程輸出匿名管道   
	if( !CreatePipe(&hSTDOUTRead, &hSTDOUTWrite, &sa, 0) )   
	{   
	AfxMessageBox("Create   STDOUT   pipe   failed");   
	return;   
	}  

	// 創建子進程輸入匿名管道   
	if( !CreatePipe(&hSTDINRead, &hSTDINWrite, &sa, 0) )   
	{   
	AfxMessageBox("Create   STDIN   pipe   failed");   
	return;   
	}

	robin_fox_nan: PROCESS_INFORMATION  pi;   
	ZeroMemory(&pi, sizeof(pi));   
	STARTUPINFO  si; 
	GetStartupInfo(&si);

	si.cb = sizeof(STARTUPINFO);
		si.dwFlags = STARTF_USESTDHANDLES   |   STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	si.hStdInput   =   hSTDINRead;      //重定向子進程輸入   
		si.hStdOutput   =   hSTDOUTWrite;   // 重定向子進程輸入    
	si.hStdError = hSTDOUTWrite; //GetStdHandle( STD_ERROR_HANDLE ); 

	char cmd[20] = {0, };
	::strcpy(cmd, "Client.exe");

	if( !::CreateProcess(NULL, cmd, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi) )   
	{   
		int errorNo = ::GetLastError();
		AfxMessageBox("create process failed");     
	}
	else
	{

		::CloseHandle(hSTDOUTWrite);   
		::CloseHandle(hSTDINRead);

		char strData[1024] = {0, };
		DWORD dwBytes;
		FILE *pf;
		pf=fopen("log.txt","w");
		while(::ReadFile(hSTDOUTRead, strData, sizeof(strData), &dwBytes, NULL))
		{   
			strData[dwBytes] = '\0';
			fprintf(pf,"%s\n",strData);
		}   
		fclose(pf);
		::WaitForSingleObject(pi.hProcess, INFINITE);   
		::CloseHandle(hSTDOUTRead);   
		::CloseHandle(hSTDINWrite);   
		::CloseHandle(pi.hProcess);   
		::CloseHandle(pi.hThread);  
		MessageBox("OK");
	}
}
