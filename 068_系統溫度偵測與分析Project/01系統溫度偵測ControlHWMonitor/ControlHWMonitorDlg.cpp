// ControlHWMonitorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ControlHWMonitor.h"
#include "ControlHWMonitorDlg.h"

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
// CControlHWMonitorDlg dialog

CControlHWMonitorDlg::CControlHWMonitorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CControlHWMonitorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CControlHWMonitorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlHWMonitorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CControlHWMonitorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CControlHWMonitorDlg, CDialog)
	//{{AFX_MSG_MAP(CControlHWMonitorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Create_Program, OnCreateProgram)
	ON_BN_CLICKED(IDC_Close_Program, OnCloseProgram)
	ON_BN_CLICKED(IDC_Save_Data, OnSaveData)
	ON_BN_CLICKED(IDC_Save_Datas, OnSaveDatas)
	ON_BN_CLICKED(IDC_automatic, Onautomatic)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControlHWMonitorDlg message handlers

BOOL CControlHWMonitorDlg::OnInitDialog()
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

void CControlHWMonitorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CControlHWMonitorDlg::OnPaint() 
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
HCURSOR CControlHWMonitorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CControlHWMonitorDlg::OnCreateProgram() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","HWMonitor.exe",NULL,NULL,SW_SHOWNORMAL); 

}

void CControlHWMonitorDlg::OnCloseProgram() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0 = FindWindow(NULL, "CPUID Hardware Monitor");
	hWnd0->SendMessage(WM_CLOSE,0,0);	
}

void CControlHWMonitorDlg::OnSaveData() 
{
	// TODO: Add your control notification handler code here
	char cha;
	cha=18;//Alt
	//VK_CONTROL;
	//cha;
	//VK_F3;
	CWnd* hWnd0 = FindWindow(NULL, "CPUID Hardware Monitor");
	hWnd0->ShowWindow(SW_MINIMIZE);
	hWnd0->ShowWindow(SW_SHOWNORMAL);
	::SetWindowPos(hWnd0->m_hWnd,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	Sleep(20);
	//this->ShowWindow(SW_MINIMIZE);
		hWnd0->SetActiveWindow(); 
		keybd_event(VK_CONTROL, 0, 0 ,0);
		keybd_event('S', 0, 0 ,0);
		Sleep(1000);
		keybd_event('S', 0, KEYEVENTF_KEYUP ,0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP ,0);
		Sleep(1000);
		keybd_event(cha, 0, 0 ,0);
		keybd_event('S', 0, 0 ,0);
		Sleep(1000);
		keybd_event('S', 0, KEYEVENTF_KEYUP ,0);
		keybd_event(cha, 0, KEYEVENTF_KEYUP ,0);
	//this->ShowWindow(SW_SHOWNORMAL);
	//hWnd0->ShowWindow(SW_MINIMIZE); 
}

void CControlHWMonitorDlg::OnSaveDatas() 
{
	// TODO: Add your control notification handler code here
	char cha;
	cha=18;//Alt
	//VK_CONTROL;
	//cha;
	//VK_F3;
	///////////////////////////
	CTime time = CTime::GetCurrentTime();
	int m_nYear = time.GetYear();      ///年
	int m_nMonth = time.GetMonth();      ///月
	int m_nDay = time.GetDay();      ///日
	int m_nHour = time.GetHour();      ///時
	int m_nMinute = time.GetMinute();   ///分
	int m_nSecond = time.GetSecond();   ///秒
	CString StrNewFileName;
	StrNewFileName.Format("%d%d%d%d%d%d.txt",m_nYear,m_nMonth,m_nDay,m_nHour,m_nMinute,m_nSecond); 
	///////////////////////////
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	CString StrOldPath,StrNewPath;
	StrOldPath=strCurDrt;
	StrOldPath+="HWMonitor.txt";
	StrNewPath=strCurDrt;
	StrNewPath+="Data\\";
	StrNewPath+=StrNewFileName;
	///////////////////////////
	CWnd* hWnd0 = FindWindow(NULL, "CPUID Hardware Monitor");
	hWnd0->ShowWindow(SW_MINIMIZE);
	hWnd0->ShowWindow(SW_SHOWNORMAL);
	::SetWindowPos(hWnd0->m_hWnd,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	Sleep(20);
	//this->ShowWindow(SW_MINIMIZE);
		hWnd0->SetActiveWindow(); 
		keybd_event(VK_CONTROL, 0, 0 ,0);
		keybd_event('S', 0, 0 ,0);
		Sleep(1000);
		keybd_event('S', 0, KEYEVENTF_KEYUP ,0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP ,0);
	//this->ShowWindow(SW_SHOWNORMAL);
	CopyFile(StrOldPath.GetBuffer(0),StrNewPath.GetBuffer(0),FALSE);
	//hWnd0->ShowWindow(SW_MINIMIZE); 
}

void CControlHWMonitorDlg::Onautomatic() 
{
	// TODO: Add your control notification handler code here
	OnCreateProgram();
	Sleep(20000);
	OnSaveData();
	SetTimer(1,20000,NULL);
}

void CControlHWMonitorDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	OnSaveDatas(); 
	CDialog::OnTimer(nIDEvent);
}
