// testContrlShowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testContrlShow.h"
#include "testContrlShowDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int gintnum=0;
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
// CTestContrlShowDlg dialog

CTestContrlShowDlg::CTestContrlShowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestContrlShowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestContrlShowDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestContrlShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestContrlShowDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestContrlShowDlg, CDialog)
	//{{AFX_MSG_MAP(CTestContrlShowDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestContrlShowDlg message handlers

BOOL CTestContrlShowDlg::OnInitDialog()
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

void CTestContrlShowDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestContrlShowDlg::OnPaint() 
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
HCURSOR CTestContrlShowDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestContrlShowDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","Showtest3.exe",NULL,NULL,SW_MINIMIZE);
	ShellExecute(NULL,"open","chtvSignage_Player.exe",NULL,NULL,SW_MINIMIZE);
	ShellExecute(NULL,"open","Show1.exe",NULL,NULL,SW_MINIMIZE);
	ShowWindow(SW_MINIMIZE);
	gintnum=0;
	SetTimer(1,10000,NULL);
}

void CTestContrlShowDlg::OnButton2()//3_1_2
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0,*hWnd1,*hWnd2;
	hWnd0=NULL;
	hWnd1=NULL;
	hWnd2=NULL;
		hWnd0 = FindWindow(NULL, "Show1");
		hWnd1 = FindWindow(NULL, "frmPlayer");
		hWnd2 = FindWindow(NULL, "Form1");
		////////////////////////////////////
		hWnd1->ShowWindow(SW_SHOWNORMAL);//2
		hWnd0->ShowWindow(SW_SHOWNORMAL);//1
		hWnd2->ShowWindow(SW_SHOWNORMAL);//3 
		
}

void CTestContrlShowDlg::OnButton3()//3_2_1 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0,*hWnd1,*hWnd2;
	hWnd0=NULL;
	hWnd1=NULL;
	hWnd2=NULL;
		hWnd0 = FindWindow(NULL, "Show1");
		hWnd1 = FindWindow(NULL, "frmPlayer");
		hWnd2 = FindWindow(NULL, "Form1");
		//////////////////////////////////
		hWnd0->ShowWindow(SW_SHOWNORMAL);//1
		hWnd1->ShowWindow(SW_SHOWNORMAL);//2
		hWnd2->ShowWindow(SW_SHOWNORMAL);//3 
}

void CTestContrlShowDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0,*hWnd1,*hWnd2;
	hWnd0=NULL;
	hWnd1=NULL;
	hWnd2=NULL;
		hWnd0 = FindWindow(NULL, "Show1");
		hWnd1 = FindWindow(NULL, "frmPlayer");
		hWnd2 = FindWindow(NULL, "Form1");
		/////////////////////////////////////
		hWnd0->ShowWindow(SW_MINIMIZE);
		hWnd1->ShowWindow(SW_MINIMIZE);
		hWnd2->ShowWindow(SW_MINIMIZE); 
}

void CTestContrlShowDlg::OnButton5()//1_3_2 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0,*hWnd1,*hWnd2;
	hWnd0=NULL;
	hWnd1=NULL;
	hWnd2=NULL;
		hWnd0 = FindWindow(NULL, "Show1");
		hWnd1 = FindWindow(NULL, "frmPlayer");
		hWnd2 = FindWindow(NULL, "Form1");
		//////////////////////////////////
		hWnd1->ShowWindow(SW_SHOWNORMAL);//2
		hWnd2->ShowWindow(SW_SHOWNORMAL);//3
		hWnd0->ShowWindow(SW_SHOWNORMAL);//1 	
}

void CTestContrlShowDlg::OnButton6()//1_2_3 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0,*hWnd1,*hWnd2;
	hWnd0=NULL;
	hWnd1=NULL;
	hWnd2=NULL;
		hWnd0 = FindWindow(NULL, "Show1");
		hWnd1 = FindWindow(NULL, "frmPlayer");
		hWnd2 = FindWindow(NULL, "Form1");
		//////////////////////////////////
		hWnd2->ShowWindow(SW_SHOWNORMAL);//3
		hWnd1->ShowWindow(SW_SHOWNORMAL);//2
		hWnd0->ShowWindow(SW_SHOWNORMAL);//1 
}

void CTestContrlShowDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	OnButton4();
	switch(gintnum)
	{
	case 0:
		OnButton2();
		gintnum++;
		break;
	case 1:
		OnButton3();
		gintnum++;
		break;
	case 2:
		OnButton5();
		gintnum++;
		break;
	case 3:
		OnButton6();
		gintnum=0;
		break;
	}

	CDialog::OnTimer(nIDEvent);
}
