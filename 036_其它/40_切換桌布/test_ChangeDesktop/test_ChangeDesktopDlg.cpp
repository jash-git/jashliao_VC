// test_ChangeDesktopDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_ChangeDesktop.h"
#include "test_ChangeDesktopDlg.h"
#include <shlobj.h>//Step 2
   
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HRESULT hr;//Step 3
IActiveDesktop *pIAD;


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
// CTest_ChangeDesktopDlg dialog

CTest_ChangeDesktopDlg::CTest_ChangeDesktopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_ChangeDesktopDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_ChangeDesktopDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_ChangeDesktopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_ChangeDesktopDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_ChangeDesktopDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_ChangeDesktopDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_ChangeDesktopDlg message handlers

BOOL CTest_ChangeDesktopDlg::OnInitDialog()
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

void CTest_ChangeDesktopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_ChangeDesktopDlg::OnPaint() 
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
HCURSOR CTest_ChangeDesktopDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_ChangeDesktopDlg::OnButton1() //Step 4
{
	// TODO: Add your control notification handler code here
    hr = CoCreateInstance( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,IID_IActiveDesktop, (void**)&pIAD);
	if ( !SUCCEEDED(hr) )
		MessageBox("error1");
	// 設定牆紙前先打開活動桌面開關
	COMPONENTSOPT co = {0};
	co.dwSize = sizeof(COMPONENTSOPT);
	co.fEnableComponents = TRUE;
	co.fActiveDesktop = TRUE;
	hr = pIAD->SetDesktopItemOptions(&co, 0);
	if ( !SUCCEEDED(hr) ) 
		MessageBox("error2");
	// 設定牆紙
	CString strPath;
	strPath="C:\\ASUS_girl\\S1.jpg";
	WCHAR wszPath[100];
	LPTSTR lpStr = strPath.GetBuffer(strPath.GetLength());
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, 100);
	strPath.ReleaseBuffer();
	hr=pIAD->SetWallpaper(wszPath,0);

	WALLPAPEROPT wp = {0};
	wp.dwSize = sizeof(WALLPAPEROPT);
	/*
	WPSTYLE_CENTER
	WPSTYLE_TILE
	WPSTYLE_STRETCH
	WPSTYLE_MAX
	*/
	wp.dwStyle |= WPSTYLE_MAX;
	hr = pIAD->SetWallpaperOptions(&wp, 0);
	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	pIAD->Release(); 
}

void CTest_ChangeDesktopDlg::OnButton2() //Step 4
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
    hr = CoCreateInstance( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,IID_IActiveDesktop, (void**)&pIAD);
	if ( !SUCCEEDED(hr) )
		MessageBox("error1");
	// 設定牆紙前先打開活動桌面開關
	COMPONENTSOPT co = {0};
	co.dwSize = sizeof(COMPONENTSOPT);
	co.fEnableComponents = TRUE;
	co.fActiveDesktop = TRUE;
	hr = pIAD->SetDesktopItemOptions(&co, 0);
	if ( !SUCCEEDED(hr) ) 
		MessageBox("error2");
	// 設定牆紙
	CString strPath;
	strPath="C:\\ASUS_girl\\S2.jpg";
	WCHAR wszPath[100];
	LPTSTR lpStr = strPath.GetBuffer(strPath.GetLength());
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, 100);
	strPath.ReleaseBuffer();
	hr=pIAD->SetWallpaper(wszPath,0);

	WALLPAPEROPT wp = {0};
	wp.dwSize = sizeof(WALLPAPEROPT);
	/*
	WPSTYLE_CENTER
	WPSTYLE_TILE
	WPSTYLE_STRETCH
	WPSTYLE_MAX
	*/
	wp.dwStyle |= WPSTYLE_MAX;
	hr = pIAD->SetWallpaperOptions(&wp, 0);
	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	pIAD->Release(); 	
}

void CTest_ChangeDesktopDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
    hr = CoCreateInstance( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,IID_IActiveDesktop, (void**)&pIAD);
	if ( !SUCCEEDED(hr) )
		MessageBox("error1");
	// 設定牆紙前先打開活動桌面開關
	COMPONENTSOPT co = {0};
	co.dwSize = sizeof(COMPONENTSOPT);
	co.fEnableComponents = TRUE;
	co.fActiveDesktop = TRUE;
	hr = pIAD->SetDesktopItemOptions(&co, 0);
	if ( !SUCCEEDED(hr) ) 
		MessageBox("error2");
	// 設定牆紙
	CString strPath;
	strPath="C:\\ASUS_girl\\S3.jpg";
	WCHAR wszPath[100];
	LPTSTR lpStr = strPath.GetBuffer(strPath.GetLength());
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, 100);
	strPath.ReleaseBuffer();
	hr=pIAD->SetWallpaper(wszPath,0);

	WALLPAPEROPT wp = {0};
	wp.dwSize = sizeof(WALLPAPEROPT);
	/*
	WPSTYLE_CENTER
	WPSTYLE_TILE
	WPSTYLE_STRETCH
	WPSTYLE_MAX
	*/
	wp.dwStyle |= WPSTYLE_MAX;
	hr = pIAD->SetWallpaperOptions(&wp, 0);
	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	pIAD->Release(); 	
}
