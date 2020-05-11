// OPenCloseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OPenClose.h"
#include "OPenCloseDlg.h"

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
// COPenCloseDlg dialog

COPenCloseDlg::COPenCloseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COPenCloseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COPenCloseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COPenCloseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COPenCloseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COPenCloseDlg, CDialog)
	//{{AFX_MSG_MAP(COPenCloseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPenCloseDlg message handlers

BOOL COPenCloseDlg::OnInitDialog()
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
	SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE); //jash_liao write	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COPenCloseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COPenCloseDlg::OnPaint() 
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
HCURSOR COPenCloseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COPenCloseDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//"C:\\Program Files\\GRETECH\\GomPlayer\\GOM.exe"
	ShellExecute(NULL,"open","C:\\WINDOWS\\system32\\notepad.exe",NULL,NULL,SW_SHOWNORMAL); 
}

void COPenCloseDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd0 = FindWindow(NULL,"未命名 - 記事本");
	//hWnd0->SendMessage(WM_CLOSE,0,0);//關閉視窗
	hWnd0->MoveWindow(20,50,640,480);//移動視窗並改變大小
	hWnd0->SetMenu(NULL);//隱藏菜單
	hWnd0->DrawMenuBar();//重繪菜單
	long style=GetWindowLong(hWnd0->m_hWnd,GWL_STYLE);
/*
Window Styles 
The following styles can be specified wherever a window style is required. After the control has been created, these styles cannot be modified, except as noted. 
		Constants
		WS_BORDER 
					Creates a window that has a thin-line border.
		WS_CAPTION 
					Creates a window that has a title bar (includes the WS_BORDER style).
		WS_CHILD 
					Creates a child window. A window with this style cannot have a menu bar. This style cannot be used with the WS_POPUP style.

		WS_CHILDWINDOW 
					Same as the WS_CHILD style.
		WS_CLIPCHILDREN 
					Excludes the area occupied by child windows when drawing occurs within the parent window. This style is used when creating the parent window.
		WS_CLIPSIBLINGS 
					Clips child windows relative to each other; that is, when a particular child window receives a WM_PAINT message, the WS_CLIPSIBLINGS style clips all other overlapping child windows out of the region of the child window to be updated. If WS_CLIPSIBLINGS is not specified and child windows overlap, it is possible, when drawing within the client area of a child window, to draw within the client area of a neighboring child window.
		WS_DISABLED 
					Creates a window that is initially disabled. A disabled window cannot receive input from the user. To change this after a window has been created, use EnableWindow. 
		WS_DLGFRAME 
					Creates a window that has a border of a style typically used with dialog boxes. A window with this style cannot have a title bar.
		WS_GROUP 
					Specifies the first control of a group of controls. The group consists of this first control and all controls defined after it, up to the next control with the WS_GROUP style. The first control in each group usually has the WS_TABSTOP style so that the user can move from group to group. The user can subsequently change the keyboard focus from one control in the group to the next control in the group by using the direction keys.
					You can turn this style on and off to change dialog box navigation. To change this style after a window has been created, use SetWindowLong.
		WS_HSCROLL 
					Creates a window that has a horizontal scroll bar.
		WS_ICONIC 
					Creates a window that is initially minimized. Same as the WS_MINIMIZE style.
		WS_MAXIMIZE 
					Creates a window that is initially maximized.
		WS_MAXIMIZEBOX 
					Creates a window that has a maximize button. Cannot be combined with the WS_EX_CONTEXTHELP style. The WS_SYSMENU style must also be specified. 
		WS_MINIMIZE 
					Creates a window that is initially minimized. Same as the WS_ICONIC style.
		WS_MINIMIZEBOX 
					Creates a window that has a minimize button. Cannot be combined with the WS_EX_CONTEXTHELP style. The WS_SYSMENU style must also be specified. 
		WS_OVERLAPPED 
					Creates an overlapped window. An overlapped window has a title bar and a border. Same as the WS_TILED style.
		WS_OVERLAPPEDWINDOW 
					Creates an overlapped window with the WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MINIMIZEBOX, and WS_MAXIMIZEBOX styles. Same as the WS_TILEDWINDOW style. 
		WS_POPUP 
					Creates a pop-up window. This style cannot be used with the WS_CHILD style.
		WS_POPUPWINDOW 
					Creates a pop-up window with WS_BORDER, WS_POPUP, and WS_SYSMENU styles. The WS_CAPTION and WS_POPUPWINDOW styles must be combined to make the window menu visible.
		WS_SIZEBOX 
					Creates a window that has a sizing border. Same as the WS_THICKFRAME style.

		WS_SYSMENU 
		Creates a window that has a window menu on its title bar. The WS_CAPTION style must also be specified.

		WS_TABSTOP 
		Specifies a control that can receive the keyboard focus when the user presses the TAB key. Pressing the TAB key changes the keyboard focus to the next control with the WS_TABSTOP style. 
		You can turn this style on and off to change dialog box navigation. To change this style after a window has been created, use SetWindowLong.


		WS_THICKFRAME 
		Creates a window that has a sizing border. Same as the WS_SIZEBOX style.

		WS_TILED 
		Creates an overlapped window. An overlapped window has a title bar and a border. Same as the WS_OVERLAPPED style. 

		WS_TILEDWINDOW 
		Creates an overlapped window with the WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MINIMIZEBOX, and WS_MAXIMIZEBOX styles. Same as the WS_OVERLAPPEDWINDOW style. 

		WS_VISIBLE 
		Creates a window that is initially visible.
		This style can be turned on and off by using ShowWindow or SetWindowPos.


		WS_VSCROLL 
		Creates a window that has a vertical scroll bar.
*/
	style&=~WS_SYSMENU;//去除系統按鈕
	style&=~WS_CAPTION;//去除標題列
	style&=~WS_POPUP; 
	SetWindowLong(hWnd0->m_hWnd,GWL_STYLE,style);
	////////////////////////變成橢圓
	/*
	CRgn m_rgn;
	CRect rcDialog;
	hWnd0->GetClientRect (rcDialog );
	m_rgn.CreateEllipticRgn (0,0,rcDialog.Width(),rcDialog.Height());
	hWnd0->SetWindowRgn((HRGN)m_rgn,TRUE);
	*/
	/////////////////////
	
}
