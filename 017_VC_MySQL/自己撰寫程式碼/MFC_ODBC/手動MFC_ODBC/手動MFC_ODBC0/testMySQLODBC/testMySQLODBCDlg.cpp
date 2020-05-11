// testMySQLODBCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testMySQLODBC.h"
#include "testMySQLODBCDlg.h"

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
// CTestMySQLODBCDlg dialog

CTestMySQLODBCDlg::CTestMySQLODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMySQLODBCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestMySQLODBCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMySQLODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestMySQLODBCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestMySQLODBCDlg, CDialog)
	//{{AFX_MSG_MAP(CTestMySQLODBCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestMySQLODBCDlg message handlers

BOOL CTestMySQLODBCDlg::OnInitDialog()
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

void CTestMySQLODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestMySQLODBCDlg::OnPaint() 
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
HCURSOR CTestMySQLODBCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestMySQLODBCDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//////////////////////////////////////////////////////第3步Start
	bool checkDB=false;
	int checkRS=false;
	CString d1,d2;
	//CDatabase *m_DB;
	m_DB=new CDatabase();
	d1="chtvdata";//ODBC名稱
	checkDB=m_DB->Open(d1);
	if(checkDB)
	{
		MessageBox("DB OK");
		//CRecordset *m_RS;
		m_RS=new CRecordset(m_DB);
		d2="select * from chtvtable";
		d2=m_RS->GetDefaultSQL();
		d2="select * from chtvtable";
		checkRS=m_RS->Open(CRecordset::forwardOnly,d2); 
		if(checkRS)
		{
			MessageBox("RS OK");
		}
		else
		{
			MessageBox("RS NOT OK");
		}
	}
	else
	{
		MessageBox("DB NOT OK");
	}
//////////////////////////////////////////////////////第3步end
}

void CTestMySQLODBCDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	char str[10];
	int excelColCount=m_RS->GetODBCFieldCount();//欄位數
	excelColCount=m_RS->GetRecordCount()+1; //筆數
	itoa(excelColCount,str,10);
	MessageBox(str);
}

void CTestMySQLODBCDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString SQL;
	SQL="insert into chtvtable values (04,'test_liao',40.0,50.0)";
	m_DB->ExecuteSQL(SQL); 
	
}

void CTestMySQLODBCDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	m_RS->MoveNext();

}

void CTestMySQLODBCDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	int ti=0;
	CString var0,var1,var2,var3;//var可以轉換為其他類型的值
	while (!m_RS->IsEOF())
	{
		//讀取Excel內部數值
		m_RS->GetFieldValue(_T("id"),var0);
		m_RS->GetFieldValue(_T("data1"),var1);
		m_RS->GetFieldValue(_T("data2"),var2);
		m_RS->GetFieldValue(_T("data3"),var3);
		ti++;
		m_RS->MoveNext();
	}
  
}
