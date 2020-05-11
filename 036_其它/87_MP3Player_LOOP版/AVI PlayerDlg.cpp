// AVI PlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AVI Player.h"
#include "AVI PlayerDlg.h"
#include "vfw.h"

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
// CAVIPlayerDlg dialog

CAVIPlayerDlg::CAVIPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAVIPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAVIPlayerDlg)
	m_Path = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAVIPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAVIPlayerDlg)
	DDX_Control(pDX, IDC_PLAY, m_Play);
	DDX_Control(pDX, IDC_PAUSE, m_Pause);
	DDX_Text(pDX, IDC_PATH, m_Path);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAVIPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CAVIPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_MESSAGE(MCIWNDM_NOTIFYMODE, OnMCINotify) 
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAVIPlayerDlg message handlers

BOOL CAVIPlayerDlg::OnInitDialog()
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
	m_Video = NULL;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAVIPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAVIPlayerDlg::OnPaint() 
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
HCURSOR CAVIPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAVIPlayerDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	m_Video = NULL;
	if(m_Video == NULL)
	{
		m_Video = MCIWndCreate(this->GetSafeHwnd(),
		  AfxGetInstanceHandle(),
		  WS_CHILD | WS_VISIBLE|MCIWNDF_NOMENU,m_Path);
		
	}
	else
	{
		MCIWndHome(m_Video);
	}
	MCIWndPlay(m_Video);
	Pause = FALSE;
	m_Play.EnableWindow(FALSE);
	SetTimer(1,1000,NULL);
	
}

void CAVIPlayerDlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	if(Pause)
	{
		m_Pause.SetWindowText("Pause");
		MCIWndResume(m_Video);
		Pause = FALSE;
	}
	else
	{
		m_Pause.SetWindowText("UnPause");
		MCIWndPause(m_Video);
		Pause = TRUE;
	}
}

void CAVIPlayerDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_Video !=NULL)
	{
		MCIWndDestroy(m_Video);
		OnOK();
	}
	CDialog::OnCancel();
}

void CAVIPlayerDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	MCIWndStop(m_Video);
	if(m_Video !=NULL)
	{
		MCIWndDestroy(m_Video);
	
	}
	m_Play.EnableWindow(TRUE);
	
}

void CAVIPlayerDlg::OnBrowse() 
{
	// TODO: Add your control notification handler code here
	m_Video = NULL;
	if(m_Video == NULL)
	{
		CFileDialog avi(TRUE,NULL,NULL,OFN_HIDEREADONLY,"MP3 Files (*.mp3)|*.mp3|AVI Files(*.avi)|*.avi|");
		if(avi.DoModal() == IDOK)
		{
			m_Path = avi.GetPathName();
			UpdateData(FALSE);
			
		}
	}
	
}
void CAVIPlayerDlg::OnMCINotify(WPARAM wParam,LPARAM lParam) 
{ 
	if(lParam==MCI_MODE_STOP) 
	{ 
		MessageBox("STOP");
	} 
}

void CAVIPlayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	char lp[3];
	long lMode;
	lMode=MCIWndGetMode(m_Video,lp,sizeof(lp));
	if(lMode==MCI_MODE_STOP)
	{ 
		KillTimer(1);
		OnStop();
		OnPlay();
	} 
	CDialog::OnTimer(nIDEvent);
}
