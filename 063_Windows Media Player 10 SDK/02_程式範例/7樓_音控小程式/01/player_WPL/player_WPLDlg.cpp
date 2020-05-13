// player_WPLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "player_WPL.h"
#include "player_WPLDlg.h"
#include "wmpcontrols.h"
#include "wmpmedia.h"
#include "wmpplaylist.h"

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
// CPlayer_WPLDlg dialog

CPlayer_WPLDlg::CPlayer_WPLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayer_WPLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayer_WPLDlg)
	m_SW1 = FALSE;
	m_SW2 = FALSE;
	m_SW3 = FALSE;
	m_SW4 = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlayer_WPLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayer_WPLDlg)
	DDX_Control(pDX, IDC_BUT4, m_BUT4);
	DDX_Control(pDX, IDC_BUT3, m_BUT3);
	DDX_Control(pDX, IDC_BUT2, m_BUT2);
	DDX_Control(pDX, IDC_BUT1, m_BUT1);
	DDX_Control(pDX, IDC_OCX1, m_player);
	DDX_Check(pDX, IDC_SW1, m_SW1);
	DDX_Check(pDX, IDC_SW2, m_SW2);
	DDX_Check(pDX, IDC_SW3, m_SW3);
	DDX_Check(pDX, IDC_SW4, m_SW4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlayer_WPLDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayer_WPLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SW1, OnSw1)
	ON_BN_CLICKED(IDC_SW2, OnSw2)
	ON_BN_CLICKED(IDC_SW3, OnSw3)
	ON_BN_CLICKED(IDC_SW4, OnSw4)
	ON_BN_CLICKED(IDC_BUT1, OnBut1)
	ON_BN_CLICKED(IDC_BUT2, OnBut2)
	ON_BN_CLICKED(IDC_BUT3, OnBut3)
	ON_BN_CLICKED(IDC_BUT4, OnBut4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayer_WPLDlg message handlers

BOOL CPlayer_WPLDlg::OnInitDialog()
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
	UpdateData(false);
	m_SW1=m_SW2=m_SW3=m_SW4=0;
	UpdateData(true);
	StrWPL01=StrWPL02=StrWPL03=StrWPL04="";
	m_BUT1.EnableWindow(false);
	m_BUT2.EnableWindow(false);
	m_BUT3.EnableWindow(false);
	m_BUT4.EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPlayer_WPLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlayer_WPLDlg::OnPaint() 
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
HCURSOR CPlayer_WPLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPlayer_WPLDlg::OnSw1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_SW1)
	{
		StrWPL01=SelectFile(1);
		m_BUT1.EnableWindow(true);
	}
	else
	{
		m_BUT1.EnableWindow(false);
	}	
}

void CPlayer_WPLDlg::OnSw2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);;
	if(m_SW2)
	{
		StrWPL02=SelectFile(2);
		m_BUT2.EnableWindow(true);
	}
	else
	{
		m_BUT2.EnableWindow(false);
	}	
}

void CPlayer_WPLDlg::OnSw3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_SW3)
	{
		StrWPL03=SelectFile(3);
		m_BUT3.EnableWindow(true);
	}
	else
	{
		m_BUT3.EnableWindow(false);
	}	
}

void CPlayer_WPLDlg::OnSw4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_SW4)
	{
		StrWPL04=SelectFile(4);
		m_BUT4.EnableWindow(true);
	}
	else
	{
		m_BUT4.EnableWindow(false);
	}	
}

void CPlayer_WPLDlg::OnBut1() 
{
	// TODO: Add your control notification handler code here
	m_player.GetControls().stop();
	CWMPPlaylist curPlaylist = m_player.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_player.newMedia(StrWPL01);
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	m_player.SetCurrentPlaylist(curPlaylist);
	m_player.GetControls().play();
}

void CPlayer_WPLDlg::OnBut2() 
{
	// TODO: Add your control notification handler code here
	m_player.GetControls().stop();
	CWMPPlaylist curPlaylist = m_player.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_player.newMedia(StrWPL02);
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	m_player.SetCurrentPlaylist(curPlaylist);
	m_player.GetControls().play();
}

void CPlayer_WPLDlg::OnBut3() 
{
	// TODO: Add your control notification handler code here
	m_player.GetControls().stop();
	CWMPPlaylist curPlaylist = m_player.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_player.newMedia(StrWPL03);
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	m_player.SetCurrentPlaylist(curPlaylist);
	m_player.GetControls().play();
}

void CPlayer_WPLDlg::OnBut4() 
{
	// TODO: Add your control notification handler code here
	m_player.GetControls().stop();
	CWMPPlaylist curPlaylist = m_player.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_player.newMedia(StrWPL04);
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	m_player.SetCurrentPlaylist(curPlaylist);
	m_player.GetControls().play();
}
CString CPlayer_WPLDlg::SelectFile(int v)
{
	CString strFileName;
	CString StrBuf;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"WPL¿…|*.wpl");
	if(fdlg.DoModal()==IDOK)
	{
		strFileName=fdlg.GetPathName();
		StrBuf=fdlg.GetFileTitle();
	}
	switch(v)
	{
		case 1:
			m_BUT1.SetWindowText(StrBuf); 
			break;
		case 2:
			m_BUT2.SetWindowText(StrBuf); 
			break;
		case 3:
			m_BUT3.SetWindowText(StrBuf); 
			break;
		case 4:
			m_BUT4.SetWindowText(StrBuf); 
			break;
	}
	return strFileName;
}