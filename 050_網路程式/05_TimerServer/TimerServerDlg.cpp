// TimerServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TimerServer.h"
#include "TimerServerDlg.h"
#include <stdio.h>
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct Net_Data
{
	float pitch;
	float yaw;
	float roll;
};
FILE *p,*f;
int count;
float pitch,yaw,roll;
///////////////////////////////////////////////
#define	MAP_NAME	"spacesoft corp."
#define	MAP_LENGTH	1024
HANDLE hFileMap = NULL ;
static char szOldData[MAP_LENGTH] = "" ;
//////////////////////////////////////////////
CSocket sockListen;
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
// CTimerServerDlg dialog

CTimerServerDlg::CTimerServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimerServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimerServerDlg)
	m_v1 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	hFileMap = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME ) ;
	p=fopen("netdata.txt","w");
	f=fopen("data.txt","w");
	pitch=0.0f;
	yaw=0.0f;
	roll=0.0f;
	count=0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimerServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimerServerDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimerServerDlg, CDialog)
	//{{AFX_MSG_MAP(CTimerServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerServerDlg message handlers

BOOL CTimerServerDlg::OnInitDialog()
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

	sockListen.Create(6801,SOCK_STREAM,"140.134.32.77");
	//sockListen.Bind(6801,"140.134.32.74");
	sockListen.Listen(5);
	sockListen.Accept(m_sockSend);
	sockListen.Close();
	SetTimer(1,10,NULL);		
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTimerServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimerServerDlg::OnPaint() 
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
HCURSOR CTimerServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTimerServerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	struct Net_Data data1;
	int a,iSend; 
	pitch=float(5.0*sin(2*3.14159*count/300.0f));
	yaw=float(5.0*sin(2*3.14159*count/300.0f));
	roll=float(5.0*sin(2*3.14159*count/300.0f));
	a=sizeof(data1.pitch)+sizeof(data1.yaw)+sizeof(data1.roll);
	iSend=m_sockSend.Receive(&data1,a,0);
	fprintf(f,"%f\t%f\t%f\n",pitch,yaw,roll);
	count++;
	fprintf(p,"%f\t%f\t%f\n",data1.pitch,data1.yaw,data1.roll);
	m_v1=int(data1.pitch);
	////////////////////////////////////////////
	LPVOID mapView = MapViewOfFile( hFileMap,FILE_MAP_WRITE, 0, 0, 0 ) ;
	if( mapView != NULL ) 
	{
		GetDlgItemText( IDC_EDIT1,(LPTSTR)mapView, MAP_LENGTH ) ;
		//GetDlgItemText( IDC_EDIT2,(LPTSTR)mapView, MAP_LENGTH ) ;
		UnmapViewOfFile( (LPVOID)mapView);
		//fprintf(p,"%d\n",m_v1);
	} 
	else 
	{
		MessageBox("mMapViewOfFile¥¢±Ñ¡C");
		
	}
	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}

void CTimerServerDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	fclose(p);
	KillTimer(1);
}
