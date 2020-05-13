// MyEmailClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyEmailClient.h"
#include "MyEmailClientDlg.h"
#include "MailMessage.h"
#include "POP3.h"
#include "SMTP.h"
#include<fstream.h>
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
// CMyEmailClientDlg dialog

CMyEmailClientDlg::CMyEmailClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyEmailClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyEmailClientDlg)
	m_Body = _T("");
	m_From = _T("5TV ╰参恨瞶 <5tv_admin@tw-airnet.net>");
	m_Password = _T("5tv_admin");
	m_POP3 = _T("");
	m_SMTP = _T("smtp.tw-airnet.net");
	m_To = _T("jashliao@tw-airnet.net;ethan@tw-airnet.net;jerry@tw-airnet.net;jovi@tw-airnet.net;d2409@tw-airnet.net;evanwu@tw-airnet.net");
	m_User = _T("5tv_admin@tw-airnet.net");
	m_Subject = _T("5TV ╰参恨瞶-TV Check");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyEmailClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyEmailClientDlg)
	DDX_Text(pDX, IDC_BODY, m_Body);
	DDX_Text(pDX, IDC_FROM, m_From);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	DDX_Text(pDX, IDC_POP3, m_POP3);
	DDX_Text(pDX, IDC_SMTP, m_SMTP);
	DDX_Text(pDX, IDC_TO, m_To);
	DDX_Text(pDX, IDC_USER, m_User);
	DDX_Text(pDX, IDC_SUBJECT, m_Subject);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyEmailClientDlg, CDialog)
	//{{AFX_MSG_MAP(CMyEmailClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_RETR, OnRetr)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEmailClientDlg message handlers

BOOL CMyEmailClientDlg::OnInitDialog()
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
	SetTimer(1,1000,NULL);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyEmailClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyEmailClientDlg::OnPaint() 
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
HCURSOR CMyEmailClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//发信
void CMyEmailClientDlg::OnSend() 
{
	//更新数据
	UpdateData( TRUE );

	//建立CSMTP对象
	CSMTP smtp( m_SMTP );

	//新建CMailMessage对象，并初始化
	CMailMessage msg;
	msg.m_sFrom = m_From;
	msg.AddMultipleRecipients( m_To );
	msg.m_sSubject = m_Subject;
	msg.m_sBody = m_Body;

	//连接SMTP服务器
	if( !smtp.Connect() )
	{
		//AfxMessageBox( smtp.GetLastError() );
		return;
	}

	//发信
	if( !smtp.SendMessage( &msg ) )
	{
		//AfxMessageBox( smtp.GetLastError() );
		return;
	}

	//断开连接
	if( !smtp.Disconnect() )
	{
		//AfxMessageBox( smtp.GetLastError() );
		return;
	}
	//AfxMessageBox( _T( "Message Sent Successfully") );
}

//收信
void CMyEmailClientDlg::OnRetr() 
{
	//更新数据
	UpdateData( TRUE );

	//新建CPOP3对象
	CPOP3 pop3( m_POP3 );
	pop3.SetUserProperties(m_User,m_Password);

	//连接POP3服务器
	if (!pop3.Connect())
	{
		//AfxMessageBox( pop3.GetLastError() );
		return;
	}

	//收取信件
	CMailMessage msg;
	if (!pop3.GetMessage(1,&msg))
	{
		//AfxMessageBox( pop3.GetLastError() );
		return;
	}

	//显示信件
	m_Body=msg.m_sBody;
	m_Subject=msg.m_sSubject;
	m_From=msg.m_sFrom;
	m_To="";
	for (int a=0; a<msg.GetNumRecipients(); a++)
	{
		CString sEmail;
		CString sFriendly;
		msg.GetRecipient(sEmail,sFriendly,a);
		m_To+=sEmail;
		m_To+=" ";
	}
	m_To.TrimRight();

	//断开连接
	if( !pop3.Disconnect() )
	{
		//AfxMessageBox( pop3.GetLastError() );
		return;
	}
	//AfxMessageBox( _T( "Successfully disconnected" ) );

	UpdateData(FALSE);
}

void CMyEmailClientDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	//Errlogs.txt
	UpdateData(true);
	fstream a1,b1,c1;
	char fg[700];
	CString StrDataBuf;
	int intlen;
	int intALL=0;
	CString StrALL;
	int intErr=0;
	CString StrErr;
	///////////////////////////////////////////
	CTime t1=CTime::GetCurrentTime();
	CString StrTime;
	StrTime=t1.Format("浪琩丁: %Y/%m/%d %H:%M:%S\n");
	m_Body="";
	m_Body+=StrTime;
	//******************************************
	b1.open("data.txt",ios::in);
	intALL=-1;
	while(!b1.eof())
	{
		intALL++;
		b1.getline(fg,500);
	}
	StrALL.Format("浪琩羆计: %d\n",intALL);
	m_Body+=StrALL;
	b1.close();
	//******************************************
	c1.open("Errlogs.txt",ios::in);
	intErr=-1;
	while(!c1.eof())
	{
		intErr++;
		c1.getline(fg,500);
	}
	StrErr.Format("岿粇繵笵: %d\n\n",intErr);
	m_Body+=StrErr;
	c1.close();
	///////////////////////////////////////////
	m_Subject.Format("5TV ╰参恨瞶_TV Check_岿粇计_%d",intErr);
	///////////////////////////////////////////////////////
	a1.open("Errlogs.txt",ios::in);
	while(!a1.eof())
	{
		StrDataBuf="";
		a1.getline(fg,500);
		StrDataBuf=fg;
		m_Body+=StrDataBuf;
		m_Body+="\n";
	}
	a1.close();
	///////////////////////////////////////////
	UpdateData(false);
	this->OnSend();
	this->OnOK();
	CDialog::OnTimer(nIDEvent);
}
