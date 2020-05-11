// addDlg.cpp : implementation file
//

#include "stdafx.h"
#include "add.h"
#include "addDlg.h"
#include "matlab.hpp"
#include "addmatrix.hpp"
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
// CAddDlg dialog

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDlg)
	m_v1 = 0;
	m_v2 = 0;
	m_v3 = 0;
	m_v4 = 0;
	m_v5 = 0;
	m_v6 = 0;
	m_v7 = 0;
	m_v8 = 0;
	m_v9 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	DDX_Text(pDX, IDC_EDIT4, m_v4);
	DDX_Text(pDX, IDC_EDIT5, m_v5);
	DDX_Text(pDX, IDC_EDIT6, m_v6);
	DDX_Text(pDX, IDC_EDIT7, m_v7);
	DDX_Text(pDX, IDC_EDIT8, m_v8);
	DDX_Text(pDX, IDC_EDIT9, m_v9);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddDlg, CDialog)
	//{{AFX_MSG_MAP(CAddDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDlg message handlers

BOOL CAddDlg::OnInitDialog()
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

void CAddDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAddDlg::OnPaint() 
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
HCURSOR CAddDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAddDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	mwArray x,y,sum,prod;
	double a[]={1,2,3,4,5,6,7,8,9};
	double b[]={1,1,1,1,1,1,1,1,1};
	double t[3][3];
	///////////////////////////////////////
	double *pr;
	//int i;
	pr=new double[9];
	//for(i=0;i<3;i++)
		//pr[i]=new double[3];
	///////////////////////////////////////
	x=row2mat(3,3,a);
	y=row2mat(3,3,b);
	sum=addmatrix(&prod,x,y);
	//sum.ExtractData(pr);
	prod.ExtractData(pr);
	int i,j,l;
	l=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			{
				t[i][j]=*(pr+l);
				l++;
			}

	UpdateData(true);
	m_v1=t[0][0];
	m_v2=t[0][1];
	m_v3=t[0][2];
	m_v4=t[1][0];
	m_v5=t[1][1];
	m_v6=t[1][2];
	m_v7=t[2][0];
	m_v8=t[2][1];
	m_v9=t[2][2];
	UpdateData(false);	
}

void CAddDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	mwArray x,y,sum,prod;
	double a[]={1,2,3,4,5,6,7,8,9};
	double b[]={1,1,1,1,1,1,1,1,1};
	double t[3][3];
	///////////////////////////////////////
	double *pr;
	//int i;
	pr=new double[9];
	//for(i=0;i<3;i++)
		//pr[i]=new double[3];
	///////////////////////////////////////
	x=row2mat(3,3,a);
	y=row2mat(3,3,b);
	sum=addmatrix(&prod,x,y);
	sum.ExtractData(pr);
	//prod.ExtractData(pr);
	int i,j,l;
	l=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			{
				t[i][j]=*(pr+l);
				l++;
			}

	UpdateData(true);
	m_v1=t[0][0];
	m_v2=t[0][1];
	m_v3=t[0][2];
	m_v4=t[1][0];
	m_v5=t[1][1];
	m_v6=t[1][2];
	m_v7=t[2][0];
	m_v8=t[2][1];
	m_v9=t[2][2];
	UpdateData(false);	
}
