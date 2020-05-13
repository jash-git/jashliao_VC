// testHuaweiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testHuawei.h"
#include "testHuaweiDlg.h"

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
// CTestHuaweiDlg dialog

CTestHuaweiDlg::CTestHuaweiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestHuaweiDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestHuaweiDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestHuaweiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestHuaweiDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestHuaweiDlg, CDialog)
	//{{AFX_MSG_MAP(CTestHuaweiDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestHuaweiDlg message handlers

BOOL CTestHuaweiDlg::OnInitDialog()
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

void CTestHuaweiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestHuaweiDlg::OnPaint() 
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
HCURSOR CTestHuaweiDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestHuaweiDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Mobile Connect");
	//hWnd->SetActiveWindow();
	INPUT input[3],*data;
	INPUT input_up[3];
	//ShowWindow(SW_MINIMIZE);//重點把自己縮小如此才可以使焦點轉移
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
	//SetForegroundWindow
    ::ZeroMemory(input, sizeof(input));
	::ZeroMemory(input_up, sizeof(input_up));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
	input[0].type = INPUT_KEYBOARD; 
	input[1].type = INPUT_KEYBOARD; 
	input[2].type = INPUT_KEYBOARD;
	input_up[0].type = INPUT_KEYBOARD; 
	input_up[1].type = INPUT_KEYBOARD; 
	input_up[2].type = INPUT_KEYBOARD; 
	input_up[0].ki.dwFlags = KEYEVENTF_KEYUP;
	input_up[1].ki.dwFlags = KEYEVENTF_KEYUP;
	input_up[2].ki.dwFlags = KEYEVENTF_KEYUP;
	input[0].ki.wVk = VK_RIGHT;
	input[1].ki.wVk = VK_F2;
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = VK_F2;
	input_up[2].ki.wVk = 'S';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	//data=(input+2);
	//SendInput(1, data, sizeof(INPUT));
	//data=(input);
	//SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	//data=(input_up+2);
	//SendInput(1, data, sizeof(INPUT));
	//data=(input_up);
	//SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 			
}

void CTestHuaweiDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	//C:\Program Files\Huawei technologies\Mobile Connect\Mobile Connect.exe
	ShellExecute(NULL,"open","C:\\Program Files\\Huawei technologies\\Mobile Connect\\Mobile Connect.exe",NULL,NULL,SW_SHOWNORMAL);
}

void CTestHuaweiDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Mobile Connect");
	hWnd->ShowWindow(SW_MINIMIZE); 
	ShowWindow(SW_MINIMIZE);
}
