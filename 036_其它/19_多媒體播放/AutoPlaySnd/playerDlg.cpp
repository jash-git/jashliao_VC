// playerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "playerDlg.h"
#include "DlgProxy.h"

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
// CPlayerDlg dialog

IMPLEMENT_DYNAMIC(CPlayerDlg, CDialog);

CPlayerDlg::CPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CPlayerDlg::~CPlayerDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayerDlg)
	DDX_Control(pDX, IDC_BUTTON3, m_stop);
	DDX_Control(pDX, IDC_BUTTON2, m_play);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_BUTTON1, m_openfile);
	DDX_Control(pDX, IDC_ACTIVEMOVIECONTROL1, m_activemovie);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlg message handlers

BOOL CPlayerDlg::OnInitDialog()
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

void CPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlayerDlg::OnPaint() 
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
HCURSOR CPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CPlayerDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CPlayerDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CPlayerDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CPlayerDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CPlayerDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char szFileFilter[]=
		"Mp3 File(*.mp3)|*.mp3|"
		"Wma File(*.wma)|*.wma|"
		"Video File(*.dat)|*.dat|"
		"Wave File(*.wav)|*.wav|"
		"AVI File(*.avi)|*.avi|"
		"Movie File(*.mov)|*.mov|"
		"Media File(*.mmm)|*.mmm|"
		"Mid File(*.mid;*,rmi)|*.mid;*.rmi|"
		"MPEG File(*.mpeg)|*.mpeg|"
		"All File(*.*)|*.*||";

	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,szFileFilter);
	if(dlg.DoModal()==IDOK)
	{
	CString m_filename=dlg.GetPathName();

		m_list.AddString(m_filename);
		UpdateData(FALSE);


	}

}

void CPlayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		double CurPos=m_activemovie.GetCurrentPosition();
	CString filename;
	if(CurPos==0){
    m_list.SetCurSel(0);
	m_list.GetText(0,filename);
	
	m_activemovie.SetAutoStart(1);
	m_activemovie.SetFileName(filename);
	m_activemovie.Run();
	m_list.GetCurSel();
	m_list.InsertString(-1,filename);
	m_list.DeleteString(0);
			   }
	CDialog::OnTimer(nIDEvent);
}

void CPlayerDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
		SetTimer(0,500,NULL);
	
}

void CPlayerDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
		KillTimer(0);
	m_activemovie.Stop();
}


