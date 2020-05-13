// Timer_CPP_fstreamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Timer_CPP_fstream.h"
#include "Timer_CPP_fstreamDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//==============================//
#include<fstream.h>
#include <stdlib.h>
#include <string.h>
fstream a;
int intState;
char fg[700];
//=============================//
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
// CTimer_CPP_fstreamDlg dialog

CTimer_CPP_fstreamDlg::CTimer_CPP_fstreamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimer_CPP_fstreamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimer_CPP_fstreamDlg)
	m_V1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimer_CPP_fstreamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimer_CPP_fstreamDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_B1);
	DDX_Text(pDX, IDC_EDIT1, m_V1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimer_CPP_fstreamDlg, CDialog)
	//{{AFX_MSG_MAP(CTimer_CPP_fstreamDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimer_CPP_fstreamDlg message handlers

BOOL CTimer_CPP_fstreamDlg::OnInitDialog()
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

void CTimer_CPP_fstreamDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimer_CPP_fstreamDlg::OnPaint() 
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
HCURSOR CTimer_CPP_fstreamDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTimer_CPP_fstreamDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	intState=-1;
	a.open("01.txt",ios::in);
	intState=0;
	m_B1.EnableWindow(false); 
	SetTimer(1,1000,NULL);
	
}

void CTimer_CPP_fstreamDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	switch(intState)
	{
	case 0://讀取
		if(!a.eof())
		{
			a.getline(fg,500);
			intState=1;
		}
		else
		{
			intState=2;
		}
		SetTimer(1,1000,NULL);
		break;
	case 1://顯示
		intState=0;
		if(strlen(fg)>0)
		{
			UpdateData(true);
				m_V1=fg;
			UpdateData(false);
		}
		SetTimer(1,1000,NULL);
		break;
	case 2://離開
		UpdateData(true);
			m_V1="讀取完成";
		UpdateData(false);
		a.close();
		intState=-1;
		m_B1.EnableWindow(true); 
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}
