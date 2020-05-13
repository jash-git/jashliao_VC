// ChangeSizeDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeSizeDlg.h"
#include "ChangeSizeDlgDlg.h"
#include <vfw.h>//Step_1
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HWND m_hWndCap;
long lngTimerSetp=0;
CDibSection DibShow;
BOOL res;
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
// CChangeSizeDlgDlg dialog

CChangeSizeDlgDlg::CChangeSizeDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeSizeDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeSizeDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeSizeDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeSizeDlgDlg)
	DDX_Control(pDX, IDC_EDIT2, m_Ed2);
	DDX_Control(pDX, IDC_EDIT1, m_Ed1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeSizeDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeSizeDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeSizeDlgDlg message handlers

BOOL CChangeSizeDlgDlg::OnInitDialog()
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
	FILE *pd;
	char DrvName[80];
	char DrvVer[80];
	BOOL res;
	int intstartX,intstartY;
	int intWindowW,intWindowH;
	pd=fopen("pardata.txt","r");
	fscanf(pd,"%d",&intstartX);
	fscanf(pd,"%d",&intstartY);
	fscanf(pd,"%d",&intWindowW);
	fscanf(pd,"%d",&intWindowH);
	fclose(pd);
	res=capGetDriverDescription(0,DrvName,sizeof(DrvName),DrvVer,sizeof(DrvVer));
	if(res)
	{
		m_hWndCap=capCreateCaptureWindow("Video Window",
										WS_CHILD | WS_VISIBLE ,
										0, 0,intWindowW,intWindowH,m_Ed1.m_hWnd,0);
		res=capDriverConnect(m_hWndCap,0);
		/*
		res=capOverlay(m_hWndCap,TRUE);
		if(res)
		{
			MessageBox("it is ok");
		}
		else
		{
			MessageBox("it is not ok");
		}
		*/
		capPreviewScale(m_hWndCap,TRUE);
		capPreviewRate(m_hWndCap,33);
		res=capPreview(m_hWndCap,TRUE);
		lngTimerSetp=0;
	}
	else
	{
		MessageBox("沒有");
	}
	this->SetWindowPos(NULL,0,0,intWindowW,intWindowH,0); 
	this->MoveWindow(intstartX,intstartY,intWindowW,intWindowH,TRUE);
	SetTimer(1,3000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChangeSizeDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChangeSizeDlgDlg::OnPaint() 
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
		if(lngTimerSetp==1)
		{
			CRect Rect1;
			CWnd *Wnd;
			Wnd=GetDlgItem(IDC_STATIC1);
			Wnd->GetClientRect(&Rect1);
			CPaintDC dc1(Wnd);
			DibShow.Draw(dc1,0,0,DibShow.Width(),DibShow.Height());
		}
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChangeSizeDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChangeSizeDlgDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	long lngdata=0;
	int i=0,j=0;
	long w=0,h=0;
	long gdata=0;
	double g255num=0;
	double ImageSize=0;
	int R=0,B=0,G=0;
	TCHAR strCurDrt[500];
	CString Strdata;
	CRect Rect1;
	CWnd *Wnd;
	long lngOneData=0;
	int nLen;
	char DrvName[80];
	char DrvVer[80];
	BOOL blngoto=FALSE;
	CDibSection dib;
	switch(nIDEvent)
	{
		case 1:
			m_Ed1.ShowWindow(true);
			capFileSaveDIB(m_hWndCap,"C:\\t1.bmp");
			DibShow.LoadBmp("C:\\t1.bmp");
			w=DibShow.Width();
			h=DibShow.Height();
			ImageSize=w*h;
			///*
			for(i=0;i<w;i++)
			{
				for(j=0;j<h;j++)
				{
					BYTE *q1=(BYTE *)DibShow.GetBits(i,j);
					B=*q1++;
					G=*q1++;
					R=*q1++;
					gdata=(int)(0.299*R+0.587*G+0.114*B);
					if(i==0 &&j==0)
					{
						lngOneData=gdata;
					}
					if(gdata==lngOneData)
					{
						g255num++;
					}
					else
					{
						break;//只要有些許不同，就拜表有訊號，也就不用繼續運算
						//跳離第一層迴圈
						blngoto=TRUE;
					}
				}
				if(blngoto==TRUE)
				{
					break;//只要有些許不同，就拜表有訊號，也就不用繼續運算
					//跳離第二層迴圈
				}
			}
			if(g255num==ImageSize)
			{
				lngTimerSetp=1;
				m_Ed1.ShowWindow(false);
				nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
				Strdata=strCurDrt;
				Strdata+="\\佐助-千鳥.bmp";
				DibShow.LoadBmp(Strdata);
				Wnd=GetDlgItem(IDC_STATIC1);
				Wnd->GetClientRect(&Rect1);
				CClientDC dc1(Wnd);
				KillTimer(1);
				SetTimer(2,60000,NULL);
				
			}
			break;
		case 2:
			m_Ed1.ShowWindow(true);
			lngTimerSetp=0;
			KillTimer(2);
			SetTimer(1,3000,NULL);
			break;
	}
	CDialog::OnTimer(nIDEvent);
}
