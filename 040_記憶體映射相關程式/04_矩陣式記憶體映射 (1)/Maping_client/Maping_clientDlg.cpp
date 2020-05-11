// Maping_clientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Maping_client.h"
#include "Maping_clientDlg.h"
/*
#define	MAP_NAME0	"spacesoft1 corp0."
#define	MAP_NAME1	"spacesoft1 corp1."
#define	MAP_NAME2	"spacesoft1 corp2."
#define	MAP_NAME3	"spacesoft1 corp3."
*/
/*
char MAP_NAME0[20]=	"spacesoft1 corp0.";
char MAP_NAME1[20]=	"spacesoft1 corp1.";
char MAP_NAME2[20]=	"spacesoft1 corp2.";
char MAP_NAME3[20]=	"spacesoft1 corp3.";
*/
#define	MAP_LENGTH	8
HANDLE hFileMap[4] ={NULL,NULL,NULL,NULL} ;
static char szOldData[MAP_LENGTH] = "" ;
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
// CMaping_clientDlg dialog

CMaping_clientDlg::CMaping_clientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMaping_clientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMaping_clientDlg)
	m_v1 = 0.0;
	m_v2 = 0.0;
	m_v3 = 0.0;
	m_v4 = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	char *MAP_NAME[20];
	MAP_NAME[0]="spacesoft1 corp0.";
	MAP_NAME[1]="spacesoft1 corp1.";
	MAP_NAME[2]="spacesoft1 corp2.";
	MAP_NAME[3]="spacesoft1 corp3.";

	for(int i=0;i<4;i++)
	{
	hFileMap[i] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME[i] ) ;	
	}
	/*
	hFileMap[0] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME0 ) ;
	hFileMap[1] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME1 ) ;
	hFileMap[2] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;
	hFileMap[3] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME3 ) ;
	*/

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMaping_clientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMaping_clientDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	DDX_Text(pDX, IDC_EDIT4, m_v4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMaping_clientDlg, CDialog)
	//{{AFX_MSG_MAP(CMaping_clientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMaping_clientDlg message handlers

BOOL CMaping_clientDlg::OnInitDialog()
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

void CMaping_clientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMaping_clientDlg::OnPaint() 
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
HCURSOR CMaping_clientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMaping_clientDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
		SetTimer(1,10,NULL);
}

void CMaping_clientDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	LPVOID mapView[4];
	float k=0.0;
	//char *a;
	for(int i=0;i<4;i++)
	{
	mapView[i] = MapViewOfFile( hFileMap[i],FILE_MAP_WRITE, 0, 0, 0 ) ;
	}
	m_v1=atof((LPTSTR)mapView[0]);
	m_v2=atof((LPTSTR)mapView[1]);
	m_v3=atof((LPTSTR)mapView[2]);
	m_v4=atof((LPTSTR)mapView[3]);
	UnmapViewOfFile( (LPVOID)mapView[0]);
	UnmapViewOfFile( (LPVOID)mapView[1]);
	UnmapViewOfFile( (LPVOID)mapView[2]);
	UnmapViewOfFile( (LPVOID)mapView[3]);		
	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}
