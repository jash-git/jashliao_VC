// LK_GDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LK_G.h"
#include "LK_GDlg.h"
#include <stdio.h>
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
long time1=0;
FILE *pf;
bool blnstart=false;
double dblPreData=0.0;
char MAP_NAME0[20]=	"spacesoft1 corp0.";
char MAP_NAME1[20]=	"spacesoft1 corp1.";
char MAP_NAME2[20]=	"spacesoft1 corp2.";
char MAP_NAME3[20]=	"spacesoft1 corp3.";
#define	MAP_LENGTH	8
HANDLE hFileMap[4] ={NULL,NULL,NULL,NULL} ;
static char szOldData[MAP_LENGTH] = "" ;
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
// CLK_GDlg dialog

CLK_GDlg::CLK_GDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLK_GDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLK_GDlg)
	Send = _T("R0");
	Rce = _T("");
	m_timer = 0.0;
	m_Data = _T("");
	m_v1 = 0.0;
	m_wide = _T("28900");
	m_hight = _T("700");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	hFileMap[0] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME0 ) ;
	hFileMap[1] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME1 ) ;
	hFileMap[2] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;
	hFileMap[3] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME3 ) ;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
CLK_GDlg::~CLK_GDlg()
{
	CloseHandle(hCom1);
	fclose(pf);
}
void CLK_GDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLK_GDlg)
	DDX_Text(pDX, IDC_EDIT1, Send);
	DDX_Text(pDX, IDC_EDIT2, Rce);
	DDX_Text(pDX, IDC_EDIT3, m_timer);
	DDX_Text(pDX, IDC_EDIT4, m_Data);
	DDX_Text(pDX, IDC_EDIT5, m_v1);
	DDX_Text(pDX, IDC_EDIT6, m_wide);
	DDX_Text(pDX, IDC_EDIT7, m_hight);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLK_GDlg, CDialog)
	//{{AFX_MSG_MAP(CLK_GDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OpenCom, OnOpenCom)
	ON_BN_CLICKED(IDC_SendMsg, OnSendMsg)
	ON_BN_CLICKED(IDC_ReceiveMsg, OnReceiveMsg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_TimerReceive, OnTimerReceive)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLK_GDlg message handlers

BOOL CLK_GDlg::OnInitDialog()
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
	((CButton*)(GetDlgItem(IDC_OpenCom)))->EnableWindow(true);
	((CButton*)(GetDlgItem(IDC_SendMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_ReceiveMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_TimerReceive)))->EnableWindow(false);
	LPVOID mapView[2];
	mapView[0] = MapViewOfFile( hFileMap[0],FILE_MAP_WRITE, 0, 0, 0 ) ;
	mapView[1] = MapViewOfFile( hFileMap[1],FILE_MAP_WRITE, 0, 0, 0 ) ;
	GetDlgItemText(IDC_EDIT6,(LPTSTR)mapView[0],20);
	GetDlgItemText(IDC_EDIT7,(LPTSTR)mapView[1],20);
	UnmapViewOfFile( (LPVOID)mapView[0]);
	UnmapViewOfFile( (LPVOID)mapView[1]);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLK_GDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLK_GDlg::OnPaint() 
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
HCURSOR CLK_GDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLK_GDlg::OnOpenCom() 
{
	// TODO: Add your control notification handler code here
	hCom1=CreateFile("COM1", //串口號 
					GENERIC_READ|GENERIC_WRITE, //允許讀寫 
					0, //通訊設備必須以獨佔方式打開 
					NULL, //無安全屬性 
					OPEN_EXISTING, //通訊設備已存在 
					FILE_FLAG_OVERLAPPED, //非同步I/O 
					0); //通訊設備不能用模板打開
	/////////////////////////////////////
	SetupComm(hCom1,1024,1024);
	/////////////////////////////////////
	TimeOuts.ReadIntervalTimeout=6000000;
	TimeOuts.ReadTotalTimeoutMultiplier=6000000; 
	TimeOuts.ReadTotalTimeoutConstant=6000000;
	TimeOuts.WriteTotalTimeoutMultiplier=0;
	TimeOuts.WriteTotalTimeoutConstant=0; 
	SetCommTimeouts(hCom1,&TimeOuts);
	///////////////////////////////////////
	GetCommState(hCom1,&dcb);
	dcb.BaudRate=9600;
	dcb.ByteSize=8; 
	dcb.Parity=EVENPARITY;
	dcb.StopBits=ONESTOPBIT;
	dcb.fOutX=TRUE;
	dcb.fInX=TRUE;  
	SetCommState(hCom1,&dcb);
	pf=fopen("test.txt","w");
	((CButton*)(GetDlgItem(IDC_OpenCom)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_SendMsg)))->EnableWindow(true);
	((CButton*)(GetDlgItem(IDC_ReceiveMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_TimerReceive)))->EnableWindow(true);
}

void CLK_GDlg::OnSendMsg() 
{
	// TODO: Add your control notification handler code here
	OVERLAPPED ol;
	DWORD nBytesWrite;
	BOOL fState;
	char *pBuf;
	char ch=13;
	UpdateData(true);
		Send+=ch;
		pBuf=Send.GetBuffer(0);
	UpdateData(false);
		ol.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL); 
		ol.Offset=0;        
		ol.OffsetHigh=0; 
		ol.hEvent=NULL;        ///標識事件，資料傳送完成時，將它設定信號狀態 
		fState=WriteFile(hCom1,pBuf,Send.GetLength(),&nBytesWrite,&ol) ;
		if(!fState)
		{

			if(GetLastError()==ERROR_IO_PENDING)

			{
				GetOverlappedResult(hCom1,&ol,&nBytesWrite,TRUE);// 等待
			}
		}
	((CButton*)(GetDlgItem(IDC_OpenCom)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_SendMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_ReceiveMsg)))->EnableWindow(true);
	((CButton*)(GetDlgItem(IDC_TimerReceive)))->EnableWindow(true);
}

void CLK_GDlg::OnReceiveMsg() 
{
	// TODO: Add your control notification handler code here
	OVERLAPPED ol;
	DWORD nBytesRead;
	BOOL fState;
	char *pBuf;
	ol.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL); 
	ol.Offset=0;        
	ol.OffsetHigh=0; 
	ol.hEvent=NULL;        ///標識事件，資料傳送完成時，將它設定信號狀態
	COMSTAT ComStat;
	DWORD dwErrorFlags;
	ClearCommError(hCom1,&dwErrorFlags,&ComStat);
	pBuf=new char[ComStat.cbInQue];
	fState=ReadFile(hCom1,pBuf,ComStat.cbInQue,&nBytesRead,&ol) ;
	if(!fState)
	{
		if(GetLastError()==ERROR_IO_PENDING)
		{
			GetOverlappedResult(hCom1,&ol,&nBytesRead,TRUE);// 等待
		}
	}
	if(ComStat.cbInQue>0)
	{
		UpdateData(true);
			Rce="";
			for(int i=0;i<ComStat.cbInQue;i++)
				Rce+=pBuf[i];
		UpdateData(false);
	}
	delete pBuf;
	((CButton*)(GetDlgItem(IDC_OpenCom)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_SendMsg)))->EnableWindow(true);
	((CButton*)(GetDlgItem(IDC_ReceiveMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_TimerReceive)))->EnableWindow(true);
}

void CLK_GDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
///*
	double dblDataBuf=0.0;
	time1++;
	UpdateData(true);
	if(time1%2==0)
	{
		time1=0;
		OVERLAPPED ol;
		DWORD nBytesWrite;
		BOOL fState;
		char *pBuf;
		char ch=13;
		UpdateData(true);
			m_timer++;
			Send="M1";
			Send+=ch;
			pBuf=Send.GetBuffer(0);
		UpdateData(false);
		ol.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL); 
		ol.Offset=0;        
		ol.OffsetHigh=0; 
		ol.hEvent=NULL;        ///標識事件，資料傳送完成時，將它設定信號狀態 
		fState=WriteFile(hCom1,pBuf,Send.GetLength(),&nBytesWrite,&ol) ;
		if(!fState)
		{

			if(GetLastError()==ERROR_IO_PENDING)

			{
				GetOverlappedResult(hCom1,&ol,&nBytesWrite,TRUE);// 等待
			}

		}
	}
	else
	{
		OVERLAPPED ol;
		DWORD nBytesRead;
		BOOL fState;
		char *pBuf;
		ol.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL); 
		ol.Offset=0;        
		ol.OffsetHigh=0; 
		ol.hEvent=NULL;        ///標識事件，資料傳送完成時，將它設定信號狀態
		COMSTAT ComStat;
		DWORD dwErrorFlags;
		ClearCommError(hCom1,&dwErrorFlags,&ComStat);
		pBuf=new char[ComStat.cbInQue];
		fState=ReadFile(hCom1,pBuf,ComStat.cbInQue,&nBytesRead,&ol) ;
		if(!fState)
		{
			if(GetLastError()==ERROR_IO_PENDING)
			{
				GetOverlappedResult(hCom1,&ol,&nBytesRead,TRUE);// 等待
			}
		}
		if(ComStat.cbInQue>0)
		{
			UpdateData(true);
				Rce="";
				for(int i=0;i<ComStat.cbInQue;i++)
					Rce+=pBuf[i];
				m_Data=Rce.Mid(3,(Rce.GetLength()-4));
				dblDataBuf=atof(m_Data.GetBuffer(0)); 
				m_v1=dblDataBuf;
				//fprintf(pf,"%s\n",m_Data.GetBuffer(0)); 
			UpdateData(false);
			if(blnstart==false)
			{
				if(m_v1!=0.0)
				{
					blnstart=true;
					dblPreData=m_v1;
					fprintf(pf,"%f\n",m_v1); 
				}
				else
				{
					blnstart=false;
				}
			}
			else//blnstart==true
			{
				if(fabs(dblPreData-m_v1)<=0.005)
				{
					dblPreData=m_v1;
					fprintf(pf,"%f\n",m_v1); 					
				}
				else
				{
					fprintf(pf,"%f\n",dblPreData); 
				}
				//LPVOID mapView;
				//mapView = MapViewOfFile( hFileMap[2],FILE_MAP_WRITE, 0, 0, 0 ) ;
				//GetDlgItemText(IDC_EDIT5,(LPTSTR)mapView,20);
				//UnmapViewOfFile( (LPVOID)mapView);
			}
		}
		delete pBuf;
	}
	UpdateData(false);
//*/
/*
	LPVOID mapView;
	mapView = MapViewOfFile( hFileMap[2],FILE_MAP_WRITE, 0, 0, 0 ) ;
	GetDlgItemText(IDC_EDIT5,(LPTSTR)mapView,20);
	UnmapViewOfFile( (LPVOID)mapView);
	CDialog::OnTimer(nIDEvent);
//*/
}

void CLK_GDlg::OnTimerReceive() 
{
	// TODO: Add your control notification handler code here
	((CButton*)(GetDlgItem(IDC_OpenCom)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_SendMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_ReceiveMsg)))->EnableWindow(false);
	((CButton*)(GetDlgItem(IDC_TimerReceive)))->EnableWindow(false);
	SetTimer(1,500,NULL);
}
