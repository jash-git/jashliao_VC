// MFCStringDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCString.h"
#include "MFCStringDlg.h"
#include <string.h>
#include <stdlib.h>
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
// CMFCStringDlg dialog

CMFCStringDlg::CMFCStringDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCStringDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCStringDlg)
	m_str1 = _T("");
	m_str2 = _T("");
	m_str3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCStringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCStringDlg)
	DDX_Text(pDX, IDC_EDIT1, m_str1);
	DDX_Text(pDX, IDC_EDIT2, m_str2);
	DDX_Text(pDX, IDC_EDIT3, m_str3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCStringDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCStringDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCStringDlg message handlers

BOOL CMFCStringDlg::OnInitDialog()
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

void CMFCStringDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCStringDlg::OnPaint() 
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
HCURSOR CMFCStringDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCStringDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//計算長度
	char *chr;
	char chr1[10];
	int a;
	UpdateData(true);
	/*
		//C的寫法
		chr=m_str1.GetBuffer(0);
		a=strlen(chr);
		itoa(a,chr1,10);
		m_str3=chr1;
	*/
		//C++的寫法
		a=m_str1.GetLength();
		itoa(a,chr1,10);
		m_str3=chr1;
	UpdateData(false);
}

void CMFCStringDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_str3=m_str1+m_str2;
	UpdateData(false);
}

void CMFCStringDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_str3=m_str1;
	UpdateData(false);	
}

void CMFCStringDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	char *chr1,*chr2;
	UpdateData(true);
		chr1=m_str1.GetBuffer(0);
		chr2=m_str2.GetBuffer(0);
		switch (strcmp(chr1,chr2))
		{
			case 0:
				m_str3="相等";
				break;
			default:
				if(strcmp(chr1,chr2)>0)
					m_str3="大於";
				else
					m_str3="小於";
		}
	UpdateData(false);	

}

void CMFCStringDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	char *chr1,*chr2,*chr3;
	UpdateData(true);
		chr1=m_str1.GetBuffer(0);
		chr2=m_str2.GetBuffer(0);
		chr3=strtok(chr1,chr2);
		m_str3=chr3;
	UpdateData(false);	

}
