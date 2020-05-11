// LF2_HandDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LF2_Hand.h"
#include "LF2_HandDlg.h"
#include "Winuser.h"
#include "Windows.h"
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
// CLF2_HandDlg dialog

CLF2_HandDlg::CLF2_HandDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLF2_HandDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLF2_HandDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLF2_HandDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLF2_HandDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLF2_HandDlg, CDialog)
	//{{AFX_MSG_MAP(CLF2_HandDlg)
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
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLF2_HandDlg message handlers

BOOL CLF2_HandDlg::OnInitDialog()
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
	SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);//1 	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLF2_HandDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLF2_HandDlg::OnPaint() 
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
HCURSOR CLF2_HandDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLF2_HandDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
    ::ZeroMemory(input, sizeof(input));
	::ZeroMemory(input_up, sizeof(input_up));
	int i;
	for(i=0;i<30;i++)
	{
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
		input[0].ki.wVk = VK_UP;
		input[1].ki.wVk = 'D';
		input[2].ki.wVk = 'S';
		input_up[0].ki.wVk = VK_UP;
		input_up[1].ki.wVk = 'D';
		input_up[2].ki.wVk = 'S';
		data=(input+1);
		SendInput(1, data, sizeof(INPUT));
		data=(input+2);
		SendInput(1, data, sizeof(INPUT));
		data=(input);
		SendInput(1, data, sizeof(INPUT));
		Sleep(1000);
		data=(input_up+1);
		SendInput(1, data, sizeof(INPUT));
		data=(input_up+2);
		SendInput(1, data, sizeof(INPUT));
		data=(input_up);
		SendInput(1, data, sizeof(INPUT));
		hWnd->SetActiveWindow();
		hWnd->SetForegroundWindow(); 
		Sleep(1000);
	}	
}

void CLF2_HandDlg::OnButton2() 
{
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[0].ki.wVk = VK_DOWN;
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_DOWN;
	input_up[1].ki.wVk = 'D';
	input_up[2].ki.wVk = 'S';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input);
	SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up);
	SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 		
	
}

void CLF2_HandDlg::OnButton3() 
{
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[0].ki.wVk = VK_LEFT;
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'A';
	input_up[0].ki.wVk = VK_LEFT;
	input_up[1].ki.wVk = 'D';
	input_up[2].ki.wVk = 'A';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input);
	SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up);
	SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 			
}

void CLF2_HandDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'A';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = 'D';
	input_up[2].ki.wVk = 'A';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input);
	SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up);
	SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 		
}

void CLF2_HandDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[0].ki.wVk = VK_LEFT;
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_LEFT;
	input_up[1].ki.wVk = 'D';
	input_up[2].ki.wVk = 'S';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input);
	SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up);
	SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 			
}

void CLF2_HandDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = 'D';
	input_up[2].ki.wVk = 'S';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input);
	SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up);
	SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 		
}

void CLF2_HandDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = 'A';
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = 'A';
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

void CLF2_HandDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = 'S';
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = 'S';
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

void CLF2_HandDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = 'D';
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

void CLF2_HandDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = VK_UP;
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = VK_UP;
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

void CLF2_HandDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = VK_LEFT;
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = VK_LEFT;
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

void CLF2_HandDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = VK_RIGHT;
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = VK_RIGHT;
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

void CLF2_HandDlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[1].ki.wVk = VK_DOWN;
	input[2].ki.wVk = 'S';
	input_up[0].ki.wVk = VK_RIGHT;
	input_up[1].ki.wVk = VK_DOWN;
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

void CLF2_HandDlg::OnButton14() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd = FindWindow(NULL, "Little Fighter 2");
	INPUT input[3],*data;
	INPUT input_up[3];
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 
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
	input[0].ki.wVk = VK_DOWN;
	input[1].ki.wVk = 'D';
	input[2].ki.wVk = 'A';
	input_up[0].ki.wVk = VK_DOWN;
	input_up[1].ki.wVk = 'D';
	input_up[2].ki.wVk = 'A';
	data=(input+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input);
	SendInput(1, data, sizeof(INPUT));
	Sleep(1000);
	data=(input_up+1);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up+2);
	SendInput(1, data, sizeof(INPUT));
	data=(input_up);
	SendInput(1, data, sizeof(INPUT));
	hWnd->SetActiveWindow();
	hWnd->SetForegroundWindow(); 		
}
