// test_ListControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_ListControl.h"
#include "test_ListControlDlg.h"

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
// CTest_ListControlDlg dialog

CTest_ListControlDlg::CTest_ListControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_ListControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_ListControlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CTest_ListControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_ListControlDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListControl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_ListControlDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_ListControlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_ListControlDlg message handlers

BOOL CTest_ListControlDlg::OnInitDialog()
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
	//m_ListControl初始化
	m_ListControl.SetExtendedStyle(
		LVS_EX_FLATSB            
		|LVS_EX_FULLROWSELECT    
		|LVS_EX_HEADERDRAGDROP   
		|LVS_EX_ONECLICKACTIVATE 
		|LVS_EX_GRIDLINES        
		);
	m_ListControl.InsertColumn(0,"歌曲名稱");
	m_ListControl.InsertColumn(1,"歌曲類型");
	m_ListControl.InsertColumn(2,"歌曲長度");
	m_ListControl.InsertColumn(3,"歌曲路徑");
	CRect rect4;
	m_ListControl.GetClientRect(rect4);
	m_ListControl.SetColumnWidth(0,rect4.Width()/4);
	m_ListControl.SetColumnWidth(1,rect4.Width()/5);
	m_ListControl.SetColumnWidth(2,rect4.Width()/5);
	m_ListControl.SetColumnWidth(3,rect4.Width()*8/20);
	m_ListControl.InsertItem(0,"吹吹風");      
	m_ListControl.SetItemText(0,1,"mp3");
	m_ListControl.SetItemText(0,2,"4:20");
	m_ListControl.SetItemText(0,3,"c:\\");
	m_ListControl.InsertItem(1,"吹吹風1");      
	m_ListControl.SetItemText(1,1,"mp3");
	m_ListControl.SetItemText(1,2,"4:20");
	m_ListControl.SetItemText(1,3,"c:\\");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_ListControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_ListControlDlg::OnPaint() 
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
HCURSOR CTest_ListControlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_ListControlDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int int1;
	CString data;
	NMLISTVIEW*   pp=   (NMLISTVIEW*)pNMHDR;
	int1=pp->iItem;
	m_ListControl.GetItemText(int1,0,data.GetBuffer(0),10);
	MessageBox(data);
	*pResult = 0;
}
