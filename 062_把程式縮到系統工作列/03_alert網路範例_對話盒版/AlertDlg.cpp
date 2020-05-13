// AlertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Alert.h"
#include "AlertDlg.h"
//#include "Shellapi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlertDlg dialog

CAlertDlg::CAlertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAlertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlertDlg)
	m_Interval = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAlertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlertDlg)
	DDX_Text(pDX, IDC_INTERVAL, m_Interval);
	DDV_MinMaxInt(pDX, m_Interval, 5, 150);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAlertDlg, CDialog)
	//{{AFX_MSG_MAP(CAlertDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_APPLY, OnClickApply)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_HIDE, OnClickHide)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_NOTIFYICON, OnNotifyIcon)
	ON_WM_QUERYENDSESSION( )
	ON_WM_SYSCOMMAND( )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlertDlg message handlers

BOOL CAlertDlg::OnInitDialog()
{

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// 初始化时间间隔
	CSpinButtonCtrl * pSpin;
	pSpin = (CSpinButtonCtrl *) GetDlgItem(IDC_SPIN);
	pSpin->SetRange(5,150);
	m_Interval = 30;
	CDialog::OnInitDialog();
	
	// 设置定时器，每秒一次心跳
	SetTimer(1, 1000, NULL);

	// 将图标放入系统托盘
	NOTIFYICONDATA nd;
	nd.cbSize	= sizeof (NOTIFYICONDATA);
	nd.hWnd	= m_hWnd;
	nd.uID	= IDI_ICON;
	nd.uFlags	= NIF_ICON|NIF_MESSAGE|NIF_TIP;
	nd.uCallbackMessage	= WM_NOTIFYICON;
	nd.hIcon	= m_hIcon;
	strcpy(nd.szTip, "我的闹钟");
	
	Shell_NotifyIcon(NIM_ADD, &nd);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAlertDlg::OnPaint() 
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
HCURSOR CAlertDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAlertDlg::OnClickApply() 
{
	// TODO: Add your control notification handler code here
	// 重置时间间隔
	UpdateData();
	OnTimer(IDT_APPLY);
}

void CAlertDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	// 释放定时器
	KillTimer(1);

	// 将图标从系统托盘中删除
	NOTIFYICONDATA nd;
	nd.cbSize	= sizeof (NOTIFYICONDATA);
	nd.hWnd	= m_hWnd;
	Shell_NotifyIcon(NIM_DELETE, &nd);
	
	CDialog::OnCancel();
}

void CAlertDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	static CString	strTemp;
	static int		Count = 0;
	COleDateTime	dtTime;

	// 刷新时间
	dtTime = COleDateTime::GetCurrentTime();
	strTemp.Format("现在时间 %02i:%02i:%02i ",dtTime.GetHour(),dtTime.GetMinute(),dtTime.GetSecond());
	GetDlgItem(IDC_CURTIME)->SetWindowText(strTemp);

	// 刷新剩余时间值
	if (nIDEvent == IDT_APPLY) Count = 0;
	Count++;
	int RestTime;
	RestTime = m_Interval - Count/60;
	if (RestTime <= 0) 
	{
		Count = 0;
		ShowMessage();
	}
	strTemp.Format("离下次提醒还差 %i 分钟", RestTime);
	GetDlgItem(IDC_RESTTIME)->SetWindowText(strTemp);	
	CDialog::OnTimer(nIDEvent);
}

void CAlertDlg::ShowMessage()
{
	::WinExec("C:\\INFOCD\\WINAMP\\WINAMP.EXE music.m3u",SW_HIDE);
	MessageBox("您该休息一会儿了......", "休息", MB_SYSTEMMODAL|MB_OK|MB_ICONEXCLAMATION|MB_ICONWARNING);
	ShellExecute(m_hWnd,"open","C:\\WINDOWS\\SYSTEM\\太空.scr", NULL,NULL,SW_SHOWNORMAL);

}

afx_msg void CAlertDlg::OnNotifyIcon(WPARAM wParam, LPARAM lParam)
{
	// 响应在托盘图标上的单击
	if ((wParam == IDI_ICON)&&(lParam == WM_LBUTTONDOWN))
		ShowWindow(SW_SHOWNORMAL);
}

void CAlertDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// 屏蔽最大化(MFC Bug)，将最小化重定向至隐藏窗口
	if (nID == SC_MAXIMIZE)
		return;
	if (nID == SC_MINIMIZE)
		ShowWindow(SW_HIDE);
	else
		CWnd::OnSysCommand(nID, lParam);
}

BOOL CAlertDlg::OnQueryEndSession()
{
	// 在用户退出Windows时自动退出应用程序
	CAlertDlg::OnCancel();
	return TRUE;
}

void CAlertDlg::OnClickHide() 
{
	// TODO: Add your control notification handler code here
	OnSysCommand(SC_MINIMIZE, 0x0000);
	return;
}

CAlertDlg::~CAlertDlg()
{

}
