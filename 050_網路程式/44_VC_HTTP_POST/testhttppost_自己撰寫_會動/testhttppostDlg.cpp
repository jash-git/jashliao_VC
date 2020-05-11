// testhttppostDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testhttppost.h"
#include "testhttppostDlg.h"

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
// CTesthttppostDlg dialog

CTesthttppostDlg::CTesthttppostDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTesthttppostDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTesthttppostDlg)
	m_StrUrl = _T("xpe5tv.tw-airnet.net");
	m_StrData = _T("op=source_nownews&row=1030050 || 政治 || 2010/05/26 09:42 || 12814169 || http://219.85.68.173/1030/v1030050.wmv || 現場消息？國軍天馬操演　射擊46枚拖式飛彈 ||");
	m_StrAns = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTesthttppostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTesthttppostDlg)
	DDX_Text(pDX, IDC_EDIT1, m_StrUrl);
	DDX_Text(pDX, IDC_EDIT2, m_StrData);
	DDX_Text(pDX, IDC_EDIT3, m_StrAns);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTesthttppostDlg, CDialog)
	//{{AFX_MSG_MAP(CTesthttppostDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesthttppostDlg message handlers

BOOL CTesthttppostDlg::OnInitDialog()
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

void CTesthttppostDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTesthttppostDlg::OnPaint() 
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
HCURSOR CTesthttppostDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTesthttppostDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString strHeaders =_T("Content-Type: application/x-www-form-urlencoded");
	// URL-encoded form variables -
	// name = "John Doe", userid = "hithere", other = "P&Q"
	CString strFormData; //= _T("op=source_nownews&row=1030050 || 政治 || 2010/05/26 09:42 || 12814169 || [Mail系統 警告: 帶有數字IP的網址通常都是有問題的]: http://219.85.68.173/1030/v1030050.wmv || 現場消息？國軍天馬操演　射擊46枚拖式飛彈 ||");
	CString strServerName;
	UpdateData(true);
		strFormData=m_StrData;
		strServerName=m_StrUrl;
	UpdateData(false);
	CInternetSession session;
	CHttpConnection* pConnection = session.GetHttpConnection(strServerName);
	CHttpFile* pFile = pConnection->OpenRequest(CHttpConnection::HTTP_VERB_POST,_T("cgi-php/media_transform.php"));
	BOOL result = pFile->SendRequest(strHeaders,(LPVOID)(LPCTSTR)strFormData, strFormData.GetLength());
	char buf[2];
	int bytesRead;
	CString resultString = "";
	while( (bytesRead = pFile->Read(buf, 1)) > 0 )
	{
		resultString += buf[0];
	}
	MessageBox(resultString);
	UpdateData(true);
		//0：資料庫寫入失敗
		//1：資料寫入成功
		//4：輸入的資料不足或格式有誤
		if(resultString=="0")
		{
			m_StrAns="資料庫寫入失敗";
		}
		if(resultString=="1")
		{
			m_StrAns="資料寫入成功";
		}
		if(resultString=="4")
		{
			m_StrAns="輸入的資料不足或格式有誤";
		}
	UpdateData(false);
}
