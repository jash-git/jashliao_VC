// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"

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
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
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

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDlg::OnPaint() 
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

CFile file; 
    WCHAR szwBuffer[128];
    WCHAR *pszUnicodeCh = L"中文\r\n";
    WCHAR *pszUnicode = L"Unicode string\r\n"; // unicode string
    CHAR *pszAnsi = "Ansi string\r\n"; // ansi string
    WORD wSignature = 0xFEFF;
    
    file.Open(TEXT("Test.txt"), CFile::modeCreate|CFile::modeWrite);
    
    file.Write(&wSignature, 2);
    file.Write(pszUnicodeCh, lstrlenW(pszUnicodeCh) * sizeof(WCHAR));
    file.Write(pszUnicode, lstrlenW(pszUnicode) * sizeof(WCHAR)); 
    // explicitly use lstrlenW function
    
    MultiByteToWideChar(CP_ACP, 0, pszAnsi, -1, szwBuffer, 128);
    file.Write(szwBuffer, lstrlenW(szwBuffer) * sizeof(WCHAR));
    ////////////////////////////////////////////////////////////
	//CString Strdata="aaaa中文English123456789\r\n";
	CString Strdata;
	Strdata.Format("%sEnglish123456789\r\n","aaaa中文"); 
	int intLen=Strdata.GetLength();
	WCHAR pszUnicodeAll[500];//OK->CString長度=陣列長度
	//WCHAR *pszUnicodeAll=NULL;
	//pszUnicodeAll= new WCHAR[intLen]; 
	MultiByteToWideChar(CP_ACP, 0,Strdata.GetBuffer(0),-1,pszUnicodeAll,Strdata.GetLength());
	file.Write(pszUnicodeAll, lstrlenW(pszUnicodeAll) * sizeof(WCHAR));
	file.Write(pszUnicodeAll, lstrlenW(pszUnicodeAll) * sizeof(WCHAR));
	file.Write(pszUnicodeAll, lstrlenW(pszUnicodeAll) * sizeof(WCHAR));
	file.Write(pszUnicodeAll, lstrlenW(pszUnicodeAll) * sizeof(WCHAR));
	//delete [] pszUnicodeAll;
	//pszUnicodeAll=NULL;
	////////////////////////////////////////////////////////////   
file.Close();
char unicode[2];   
unicode[0] = 0xFF;   
unicode[1] = 0xFE; 
 FILE *pf;
 //pf=_wfopen(L"data.txt",L"wb");//wb->才會讓換行指令正常
 pf=fopen("data.txt","wb");//wb->才會讓換行指令正常
 fwrite(unicode,sizeof(char),2,pf);//用字元才會正常 
 fwrite(pszUnicodeCh,sizeof(WCHAR),lstrlenW(pszUnicodeCh),pf);
 fwrite(pszUnicode,sizeof(WCHAR),lstrlenW(pszUnicode),pf);
 fwrite(szwBuffer,sizeof(WCHAR),lstrlenW(szwBuffer),pf);
 fwrite(pszUnicodeAll,sizeof(WCHAR),lstrlenW(pszUnicodeAll),pf);
 fwrite(pszUnicodeAll,sizeof(WCHAR),lstrlenW(pszUnicodeAll),pf);
 fwrite(pszUnicodeAll,sizeof(WCHAR),lstrlenW(pszUnicodeAll),pf);
 fwrite(pszUnicodeAll,sizeof(WCHAR),lstrlenW(pszUnicodeAll),pf);
 fclose(pf);	
}
