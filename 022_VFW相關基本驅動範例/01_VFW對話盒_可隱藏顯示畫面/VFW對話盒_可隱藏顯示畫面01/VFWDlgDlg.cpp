// VFWDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VFWDlg.h"
#include "VFWDlgDlg.h"
#include <vfw.h>//Step_1
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HWND m_hWndCap;
bool blnShowHide=false;
CDibSection DibShow;
bool blncheck=false;
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
// CVFWDlgDlg dialog

CVFWDlgDlg::CVFWDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVFWDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVFWDlgDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVFWDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVFWDlgDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Ed1);
	//}}AFX_DATA_MAP
	m_Ed1.ShowWindow(true);
}

BEGIN_MESSAGE_MAP(CVFWDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CVFWDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVFWDlgDlg message handlers

BOOL CVFWDlgDlg::OnInitDialog()
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

void CVFWDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVFWDlgDlg::OnPaint() 
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
		if(blncheck!=false)
		{
			CRect Rect1;
			CWnd *Wnd;
			Wnd=GetDlgItem(IDC_STATIC1);
			Wnd->GetClientRect(&Rect1);
			CPaintDC dc1(Wnd);
			DibShow.Draw(dc1,0,0,DibShow.Width(),DibShow.Height());
		}
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVFWDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVFWDlgDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char DrvName[80];
	char DrvVer[80];
	BOOL res;
	res=capGetDriverDescription(0,DrvName,sizeof(DrvName),DrvVer,sizeof(DrvVer));
	if(res)
	{
		MessageBox(DrvName);
		MessageBox(DrvVer);
		m_hWndCap=capCreateCaptureWindow("Video Window",
										WS_CHILD | WS_VISIBLE ,
										0, 0, 640, 480,m_Ed1.m_hWnd,0);
		res=capDriverConnect(m_hWndCap,0);
		/*
		res=capOverlay(m_hWndCap,TRUE);
		if(res)
		{
			MessageBox("it is ok");
		}
		else
		{
			MessageBox("it is not ok");
		}
		*/
		capPreviewScale(m_hWndCap,FALSE);
		capPreviewRate(m_hWndCap,33);
		res=capPreview(m_hWndCap,TRUE);
	}
	else
	{
		MessageBox("沒有");
	}
	//this->m_hWnd	
}

void CVFWDlgDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_Ed1.ShowWindow(blnShowHide);
	if(!blnShowHide)
	{
		TCHAR strCurDrt[500];
		CString Strdata;
		int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
		Strdata=strCurDrt;
		Strdata+="\\佐助-千鳥.bmp";
		DibShow.LoadBmp(Strdata);
		CRect Rect1;
		CWnd *Wnd;
		Wnd=GetDlgItem(IDC_STATIC1);
		Wnd->GetClientRect(&Rect1);
		CClientDC dc1(Wnd);
		DibShow.Draw(dc1,0,0,DibShow.Width(),DibShow.Height());   
		blncheck=true;
	}
	else
	{
		blncheck=false;
	}
	blnShowHide=!blnShowHide; 
}
