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
float m[3][3]={0};
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
	m_v00 = 0.0f;
	m_v01 = 0.0f;
	m_v02 = 0.0f;
	m_v10 = 0.0f;
	m_v11 = 0.0f;
	m_v12 = 0.0f;
	m_v20 = 0.0f;
	m_v21 = 0.0f;
	m_v22 = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v00);
	DDX_Text(pDX, IDC_EDIT2, m_v01);
	DDX_Text(pDX, IDC_EDIT3, m_v02);
	DDX_Text(pDX, IDC_EDIT4, m_v10);
	DDX_Text(pDX, IDC_EDIT5, m_v11);
	DDX_Text(pDX, IDC_EDIT6, m_v12);
	DDX_Text(pDX, IDC_EDIT7, m_v20);
	DDX_Text(pDX, IDC_EDIT8, m_v21);
	DDX_Text(pDX, IDC_EDIT9, m_v22);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
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
	int i,j;
	float v[3][3]={0};
	UpdateData(true);
		m[0][0]=m_v00;
		m[0][1]=m_v01;
		m[0][2]=m_v02;
		m[1][0]=m_v10;
		m[1][1]=m_v11;
		m[1][2]=m_v12;
		m[2][0]=m_v20;
		m[2][1]=m_v21;
		m[2][2]=m_v22;
	UpdateData(false);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			v[j][i]=m[i][j];
		}
	UpdateData(true);
		m_v00 =v[0][0];
		m_v01 =v[0][1];
		m_v02 =v[0][2];
		m_v10 =v[1][0];
		m_v11 =v[1][1];
		m_v12 =v[1][2];
		m_v20 =v[2][0];
		m_v21 =v[2][1];
		m_v22 =v[2][2];
	UpdateData(false);
}

void CTestDlg::OnButton2() 
{
	int i,j;
	float det1=0.0f;
	float det2=0.0f;
	float det=0.0f;
	float v[3][3]={0};
	UpdateData(true);
		m[0][0]=m_v00;
		m[0][1]=m_v01;
		m[0][2]=m_v02;
		m[1][0]=m_v10;
		m[1][1]=m_v11;
		m[1][2]=m_v12;
		m[2][0]=m_v20;
		m[2][1]=m_v21;
		m[2][2]=m_v22;
	UpdateData(false);
	det1=(m[0][0]*m[1][1]*m[2][2])+(m[1][0]*m[2][1]*m[0][2])+(m[2][0]*m[0][1]*m[1][2]);
	det2=(m[0][2]*m[1][1]*m[2][0])+(m[1][2]*m[2][1]*m[0][0])+(m[1][0]*m[0][1]*m[2][2]);
	det=det1-det2;
	if(det != 0)
	{
		v[0][0]=(m[1][1]*m[2][2]-m[1][2]*m[2][1])/det;
		v[0][1]=-(m[0][1]*m[2][2]-m[0][2]*m[2][1])/det;
		v[0][2]=(m[0][1]*m[1][2]-m[0][2]*m[1][1])/det;
		////////////////////////////////////////////
		v[1][0]=-(m[1][0]*m[2][2]-m[1][2]*m[2][0])/det;
		v[1][1]=(m[0][0]*m[2][2]-m[0][2]*m[2][0])/det;
		v[1][2]=-(m[0][0]*m[1][2]-m[0][2]*m[1][0])/det;
		///////////////////////////////////////////
		v[2][0]=(m[1][0]*m[2][1]-m[1][1]*m[2][0])/det;
		v[2][1]=-(m[0][0]*m[2][1]-m[0][1]*m[2][0])/det;
		v[2][2]=(m[0][0]*m[1][1]-m[0][1]*m[1][0])/det;
	}
	else
	{
		MessageBox("¨S¦³¤Ï¯x°}");
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				v[i][j]=0;
	}
	
	UpdateData(true);
		m_v00 =v[0][0];
		m_v01 =v[0][1];
		m_v02 =v[0][2];
		m_v10 =v[1][0];
		m_v11 =v[1][1];
		m_v12 =v[1][2];
		m_v20 =v[2][0];
		m_v21 =v[2][1];
		m_v22 =v[2][2];
	UpdateData(false);
}
