// Read_Write_MySQLInforDlg.cpp : implementation file
//

#include "stdafx.h"
#include "read_write_MySQLInfor.h"
#include "Read_Write_MySQLInforDlg.h"
#include "MySQL_Info.h"
#include <fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
fstream FileRead,FileWrite;
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
// CRead_Write_MySQLInforDlg dialog

CRead_Write_MySQLInforDlg::CRead_Write_MySQLInforDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRead_Write_MySQLInforDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRead_Write_MySQLInforDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRead_Write_MySQLInforDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRead_Write_MySQLInforDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRead_Write_MySQLInforDlg, CDialog)
	//{{AFX_MSG_MAP(CRead_Write_MySQLInforDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTRead, OnBUTRead)
	ON_BN_CLICKED(IDC_BUTWrite, OnBUTWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRead_Write_MySQLInforDlg message handlers

BOOL CRead_Write_MySQLInforDlg::OnInitDialog()
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

void CRead_Write_MySQLInforDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRead_Write_MySQLInforDlg::OnPaint() 
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
HCURSOR CRead_Write_MySQLInforDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRead_Write_MySQLInforDlg::OnBUTRead() 
{
	// TODO: Add your control notification handler code here
	CString Strfilename;
	CMySQL_Info MSInfo;
	CFileDialog fdlg(true,NULL,"",NULL,"MySQL連結設定檔|*.inf");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
		FileRead.open(Strfilename.GetBuffer(0),ios::in);
		FileRead.read((char*)(&MSInfo),sizeof(CMySQL_Info));
		this->SetDlgItemText(IDC_IPADDRESS1,MSInfo.m_chrHostName);//Host Name: 
		this->SetDlgItemText(IDC_EDIT1,MSInfo.m_chrUserName);//User Name:
		this->SetDlgItemText(IDC_EDIT2,MSInfo.m_chrPassWord);//PassWord:
		this->SetDlgItemText(IDC_EDIT3,MSInfo.m_chrDBName);//DB Name:
		this->SetDlgItemText(IDC_EDIT4,MSInfo.m_chrInputDir);//Input Dir:
		this->SetDlgItemText(IDC_EDIT5,MSInfo.m_chrOutputDir);//Output Dir:
		FileRead.close(); 
	}
}

void CRead_Write_MySQLInforDlg::OnBUTWrite() 
{
	// TODO: Add your control notification handler code here
	CString Strfilename;
	CMySQL_Info MSInfo;
	CFileDialog fdlg(false,NULL,"SQL_Link.inf",NULL,"MySQL連結設定檔|*.inf");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
		FileWrite.open(Strfilename.GetBuffer(0),ios::trunc|ios::out);
		this->GetDlgItemText(IDC_IPADDRESS1,MSInfo.m_chrHostName,50);//Host Name: 
		this->GetDlgItemText(IDC_EDIT1,MSInfo.m_chrUserName,50);//User Name:
		this->GetDlgItemText(IDC_EDIT2,MSInfo.m_chrPassWord,50);//PassWord:
		this->GetDlgItemText(IDC_EDIT3,MSInfo.m_chrDBName,50);//DB Name:
		this->GetDlgItemText(IDC_EDIT4,MSInfo.m_chrInputDir,50);//Input Dir:
		this->GetDlgItemText(IDC_EDIT5,MSInfo.m_chrOutputDir,50);//Output Dir:
		FileWrite.write((char*)(&MSInfo),sizeof(CMySQL_Info));
		FileWrite.close();
	}
}
