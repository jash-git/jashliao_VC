// KeybdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Keybd.h"
#include "KeybdDlg.h"
#include "Winuser.h"
#include "Windows.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define _WIN32_WINNT 0x0500 // so the code would compile
#include <windows.h>


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
// CKeybdDlg dialog

CKeybdDlg::CKeybdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeybdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKeybdDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeybdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeybdDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKeybdDlg, CDialog)
	//{{AFX_MSG_MAP(CKeybdDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeybdDlg message handlers

BOOL CKeybdDlg::OnInitDialog()
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

void CKeybdDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKeybdDlg::OnPaint() 
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
HCURSOR CKeybdDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKeybdDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//OnButton2();
	ShellExecute(NULL,"open","C:\\WINDOWS\\CBLOCKS.EXE",NULL,NULL,SW_SHOWNORMAL);
	Sleep(2000);
	CWnd* hWnd = FindWindow(NULL, "中文輸入法練習 - 輸入法");
	hWnd->SetActiveWindow();
	INPUT input[4],in[2];
	ShowWindow(SW_MINIMIZE);//重點把自己縮小如此才可以使焦點轉移
    ::ZeroMemory(input, sizeof(input));
	::ZeroMemory(in, sizeof(in));
    input[0].type = INPUT_KEYBOARD; 
    input[1].type = INPUT_KEYBOARD; 
    input[2].type = INPUT_KEYBOARD; 
    input[3].type = INPUT_KEYBOARD;

    input[0].ki.wVk = VK_MENU;
    input[1].ki.wVk = 'G';
    input[2].ki.wVk = VK_MENU;
    input[3].ki.wVk = 'G';

    input[2].ki.dwFlags = KEYEVENTF_KEYUP;
    input[3].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(4, input, sizeof(INPUT));
	
	//hWnd->SetActiveWindow();
	in[0].type = INPUT_KEYBOARD; 
    in[1].type = INPUT_KEYBOARD;
	in[0].ki.wVk = 'S';
	in[1].ki.wVk = 'S';
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, in, sizeof(INPUT));
}

void CKeybdDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,"open","C:\\WINDOWS\\CBLOCKS.EXE",NULL,NULL,SW_SHOWNORMAL);
}
