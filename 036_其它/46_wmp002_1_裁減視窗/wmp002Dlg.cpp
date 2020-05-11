// wmp002Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "wmp002.h"
#include "wmp002Dlg.h"
#include "wmpcontrols.h"
#include "wmpmedia.h"
#include "wmpplaylist.h"
////////////////////////
#include <Vfw.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
bool blnloop=false;
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
// CWmp002Dlg dialog

CWmp002Dlg::CWmp002Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWmp002Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWmp002Dlg)
	m_v1 = 0.0;
	m_v2 = -1.0;
	m_v3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWmp002Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWmp002Dlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_OCX1, m_WMP);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWmp002Dlg, CDialog)
	//{{AFX_MSG_MAP(CWmp002Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWmp002Dlg message handlers

BOOL CWmp002Dlg::OnInitDialog()
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
	RECT rc;
	this->GetClientRect(&rc);
	m_WMP.MoveWindow( &rc, true );
	///////////////////////////////////////////////////////
	CWMPPlaylist curPlaylist = m_WMP.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_WMP.newMedia("C:\\11.wmv");
	CWMPMedia newMedia2=m_WMP.newMedia("C:\\22.wmv");
	CWMPMedia newMedia3=m_WMP.newMedia("C:\\33.wmv");
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	curPlaylist.insertItem(2,newMedia2.m_lpDispatch);
	curPlaylist.insertItem(1,newMedia3.m_lpDispatch);
	//curPlaylist.appendItem(newMedia1.m_lpDispatch);
	//curPlaylist.appendItem(newMedia2.m_lpDispatch);
	//curPlaylist.appendItem(newMedia3.m_lpDispatch);
	m_WMP.SetCurrentPlaylist(curPlaylist);
	m_WMP.GetControls().play();
	SetTimer(1,1000,NULL);
	blnloop=true;
	////////////////////////////////////////////////////////
	////裁減視窗 Step 2_start
	CRect rect;
	this->GetClientRect(rect);
	//m_rgn.CreateEllipticRgn(0,0,rect.Width(),rect.Height());
	m_rgn.CreateRectRgn(0,28,rect.Width(),(rect.Height()-28));
	::SetWindowRgn(GetSafeHwnd(),(HRGN)m_rgn,TRUE);
	////裁減視窗 Step 2_end
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWmp002Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWmp002Dlg::OnPaint() 
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
HCURSOR CWmp002Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWmp002Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	/*
CWMPPlaylist CurrentPlayList=wmp4.GetCurrentPlaylist(); //取?前播放列表
CWMPMedia newMedia=wmp4.newMedia(strTemp); //建立媒体?象

CurrentPlayList.appendItem(newMedia.m_lpDispatch); //添加到?前播放列表

	*/
	CWMPPlaylist curPlaylist = m_WMP.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_WMP.newMedia("C:\\11.wmv");
	CWMPMedia newMedia2=m_WMP.newMedia("C:\\22.wmv");
	CWMPMedia newMedia3=m_WMP.newMedia("C:\\33.wmv");
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	curPlaylist.insertItem(2,newMedia2.m_lpDispatch);
	curPlaylist.insertItem(1,newMedia3.m_lpDispatch);
	//curPlaylist.appendItem(newMedia1.m_lpDispatch);
	//curPlaylist.appendItem(newMedia2.m_lpDispatch);
	//curPlaylist.appendItem(newMedia3.m_lpDispatch);
	m_WMP.SetCurrentPlaylist(curPlaylist);
	m_WMP.GetControls().play();
	SetTimer(1,1000,NULL);
	blnloop=true;
}

void CWmp002Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_WMP.GetControls().stop();
}

void CWmp002Dlg::OnTimer(UINT nIDEvent) 
{
	CString data[2];
	data[0]="33";//第二支
	data[1]="11";//第ㄧ支
	UpdateData(true);
		m_v2=m_WMP.GetControls().GetCurrentPosition();
		m_v1=m_WMP.GetCurrentMedia().GetDuration();
		m_v3=m_WMP.GetCurrentMedia().GetName();
		//m_v3=m_WMP.GetCurrentMedia().GetDurationString();
	UpdateData(false);
	if(m_v3==data[0])
	{
		blnloop=false;
	}
	if(m_v3==data[1] && blnloop==false)
	{
		KillTimer(1);
		MessageBox("OK");
		SetTimer(1,1000,NULL);
		m_WMP.GetControls().play();
		blnloop=true;
	}
	CDialog::OnTimer(nIDEvent);
}
