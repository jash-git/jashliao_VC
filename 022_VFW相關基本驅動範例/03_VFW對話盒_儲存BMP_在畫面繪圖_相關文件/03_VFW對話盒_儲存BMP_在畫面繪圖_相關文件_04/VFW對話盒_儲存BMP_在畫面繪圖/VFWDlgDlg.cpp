// VFWDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VFWDlg.h"
#include "VFWDlgDlg.h"
#include "DibSection.h"
#include <vfw.h>//Step1
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
HWND m_hWndCap;
bool blnShowHide=false;
CPoint pointStart,pointEnd,pointOld;
bool blncheck=false;
bool blnfirstDraw=true;
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
// CVFWDlgDlg dialog

CVFWDlgDlg::CVFWDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVFWDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVFWDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVFWDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVFWDlgDlg)
	DDX_Control(pDX, IDC_STATIC01, m_static);
	DDX_Control(pDX, IDC_EDIT1, m_Ed1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVFWDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CVFWDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVFWDlgDlg message handlers

BOOL CVFWDlgDlg::OnInitDialog()
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
	pointStart.x=0;
	pointStart.y=0;
	pointEnd.x=0;
	pointEnd.y=0;
	pointOld.x=0;
	pointOld.y=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVFWDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVFWDlgDlg::OnPaint() 
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
HCURSOR CVFWDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVFWDlgDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char DrvName[80];
	char DrvVer[80];
	BOOL res;
	res=capGetDriverDescription(0,DrvName,sizeof(DrvName),DrvVer,sizeof(DrvVer));
	if(res)
	{
		MessageBox(DrvName);
		MessageBox(DrvVer);
		m_hWndCap=capCreateCaptureWindow("Video Window",
										WS_CHILD | WS_VISIBLE ,
										0, 0, 640, 480,m_Ed1.m_hWnd,0);
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
		capPreviewScale(m_hWndCap,FALSE);
		capPreviewRate(m_hWndCap,33);
		res=capPreview(m_hWndCap,TRUE);
		SetTimer(1,100,NULL);
		//res=capPreview(m_hWndCap,FALSE);
	}
	else
	{
		MessageBox("沒有");
	}
	//this->m_hWnd	
}

void CVFWDlgDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
}

void CVFWDlgDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	blnShowHide=!blnShowHide;
	capGrabFrame(m_hWndCap);//只要證這一行指令就可以使CCD瞬間攝影又停止
	CDibSection dib,dibshow1,dibshow2;
	int i,j,w,h;
	int k,l;
	int R,B,G;
	////////////////////////////////////////////////////
	CRect Rect1;
	CWnd *Wnd;
	Wnd=GetDlgItem(IDC_EDIT1);
	Wnd->GetClientRect(&Rect1);
	CClientDC dc1(Wnd);
	dc1.SelectStockObject(NULL_BRUSH); 
	CRect rc; 
	rc.left=pointStart.x; 
	rc.top=pointStart.y; 
	rc.right=pointEnd.x; 
	rc.bottom=pointEnd.y; 
	dc1.Rectangle(rc);
	////////////////////////////////////////////////////
	capFileSaveDIB(m_hWndCap,"1.bmp");
	dib.LoadBmp("1.bmp");
	if(pointEnd.x!=0 || pointEnd.y!=0)
	{
		w=pointEnd.x-pointStart.x;
		h=pointEnd.y-pointStart.y;
		if(w>dib.Width())
		{
			w=dib.Width();
		}
		if(h>dib.Height())
		{
			h=dib.Height();
		}
		dibshow1.Create(w,h,24);
		dibshow2.Create(w,h,24);
		BitBlt(CDibDC(dibshow1), 0, 0, w, h, dc1, pointStart.x, pointStart.y, SRCCOPY);
		for(i=0;i<w;i++)
			for(j=0;j<h;j++)
			{
				BYTE *q1=(BYTE *)dibshow1.GetBits(i,j);
				BYTE *q2=(BYTE *)dibshow2.GetBits(i,j);
				B=*q1++;
				G=*q1++;
				R=*q1++;
				*q2++=(int)(0.299*R+0.587*G+0.114*B);
				*q2++=(int)(0.299*R+0.587*G+0.114*B);
				*q2++=(int)(0.299*R+0.587*G+0.114*B);
			}
		dibshow1.SaveBmp("2_1.bmp");
		dibshow2.SaveBmp("2_2.bmp"); 
	}
	CDialog::OnTimer(nIDEvent);
}

void CVFWDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pointStart.x=0;
	pointStart.y=0;
	pointEnd.x=0;
	pointEnd.y=0;
	pointOld.x=0;
	pointOld.y=0;
	pointStart=point;
	blncheck=true;
	blnfirstDraw=true;
	CDialog::OnLButtonDown(nFlags, point);
}

void CVFWDlgDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	pointEnd=point;
	CRect Rect1;
	CWnd *Wnd;
	Wnd=GetDlgItem(IDC_EDIT1);
	Wnd->GetClientRect(&Rect1);
	CClientDC dc1(Wnd); 
	dc1.SelectStockObject(NULL_BRUSH); 
	CRect rc; 
	rc.left=pointStart.x; 
	rc.top=pointStart.y; 
	rc.right=pointEnd.x; 
	rc.bottom=pointEnd.y; 
	dc1.Rectangle(rc);
	blncheck=false;
	/*
	pointStart.x=0;
	pointStart.y=0;
	pointEnd.x=0;
	pointEnd.y=0;
	pointOld.x=0;
	pointOld.y=0;
	*/
	blnfirstDraw=true;
	CDialog::OnLButtonUp(nFlags, point);
}

void CVFWDlgDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(blncheck)
	{
		pointEnd=point;
		CRect Rect1;
		CWnd *Wnd;
		Wnd=GetDlgItem(IDC_EDIT1);
		Wnd->GetClientRect(&Rect1);
		CClientDC dc1(Wnd);
		dc1.SelectStockObject(NULL_BRUSH); 
		CRect rc;
		if(blnfirstDraw!=true)
		{
			rc.left=pointStart.x; 
			rc.top=pointStart.y; 
			rc.right=pointOld.x; 
			rc.bottom=pointOld.y; 
			dc1.SetROP2(R2_NOT);
			dc1.Rectangle(rc);
			dc1.SetROP2(R2_NOT);
		}
		blnfirstDraw=false;
		//////////////////////////////////
		rc.left=pointStart.x; 
		rc.top=pointStart.y; 
		rc.right=point.x; 
		rc.bottom=point.y; 
		dc1.Rectangle(rc);
		///////////////////////////////////
		pointOld=point;
	}
	CDialog::OnMouseMove(nFlags, point);
}
