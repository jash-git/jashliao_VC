// test_IP_BoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_IP_Box.h"
#include "test_IP_BoxDlg.h"

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
// CTest_IP_BoxDlg dialog

CTest_IP_BoxDlg::CTest_IP_BoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_IP_BoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_IP_BoxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_IP_BoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_IP_BoxDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_IP_BoxDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_IP_BoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_IP_BoxDlg message handlers

BOOL CTest_IP_BoxDlg::OnInitDialog()
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

void CTest_IP_BoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_IP_BoxDlg::OnPaint() 
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
HCURSOR CTest_IP_BoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_IP_BoxDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.01");
}

void CTest_IP_BoxDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.02");
}

void CTest_IP_BoxDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.03");
}

void CTest_IP_BoxDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.04");	
}

void CTest_IP_BoxDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.05");
}

void CTest_IP_BoxDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.06");
}

void CTest_IP_BoxDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.07");
}

void CTest_IP_BoxDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.08");
}

void CTest_IP_BoxDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.09");
}

void CTest_IP_BoxDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.10");
}

void CTest_IP_BoxDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.11");
}

void CTest_IP_BoxDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_IPADDRESS1,"192.168.12.12");
}
