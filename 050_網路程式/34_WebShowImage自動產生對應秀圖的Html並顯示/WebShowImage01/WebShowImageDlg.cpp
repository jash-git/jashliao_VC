// WebShowImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WebShowImage.h"
#include "WebShowImageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR strCurDrt[500];
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
// CWebShowImageDlg dialog

CWebShowImageDlg::CWebShowImageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWebShowImageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWebShowImageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWebShowImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebShowImageDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_WebControl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWebShowImageDlg, CDialog)
	//{{AFX_MSG_MAP(CWebShowImageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebShowImageDlg message handlers

BOOL CWebShowImageDlg::OnInitDialog()
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
	RECT rc;
	this->GetClientRect(&rc);
	m_WebControl.MoveWindow( &rc, true );
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	CString strFileName = strCurDrt;
	CString StrDir;
	StrDir=strFileName+"web";
	BrowseDir(StrDir);
	strFileName+="web\\show.html";
	//****************************************************
	FILE *pfhtml;
	CString StrDataBuf;
	int i,j;
	pfhtml=fopen(strFileName.GetBuffer(0),"w");
	//
	StrDataBuf="<HTML><HEAD><META CONTENT=\"text/html; charset=big5\" HTTP-EQUIV=\"Content-Type\"></HEAD><title>中華聯合多頻道</title>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="<SCRIPT language=JavaScript>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="var slideShowSpeed = 6000;";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="var Pic = new Array();";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	j=m_Array.GetSize(); 
	for(i=0;i<j;i++)
	{
		StrDataBuf.Format("Pic[%d] = '",i); 
		StrDataBuf+=m_Array.GetAt(i);
		StrDataBuf+="'";
		fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	}
	//
	StrDataBuf="var t;var j = 0;var p = Pic.length;var preLoad = new Array();var crossFadeDuration = 3";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="for (i = 0; i < p; i++) {preLoad[i] = new Image();preLoad[i].src = Pic[i];}";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="function runSlideShow() {if (document.all) {document.images.SlideShow.style.filter=\"blendTrans(duration=2)\";document.images.SlideShow.style.filter=\"blendTrans(duration=crossFadeDuration)\";document.images.SlideShow.filters.blendTrans.Apply();}document.images.SlideShow.src = preLoad[j].src;if (document.all) {document.images.SlideShow.filters.blendTrans.Play();}j = j + 1;if (j > (p - 1)) j = 0;t = setTimeout('runSlideShow()', slideShowSpeed);}";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="</SCRIPT>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="<BODY onload=runSlideShow() TOPMARGIN=\"0\" LEFTMARGIN=\"0\" MARGINWIDTH=\"0\" MARGINHEIGHT=\"0\" scroll=\"no\" onload=runSlideShow()><TABLE BORDER=\"0\" CELLPADDING=\"0\" CELLSPACING=\"0\"><TR><TD><IMG src=\"Images/CHTV_01.jpg\" border=0 name=SlideShow></TD></TR></TABLE></BODY></HTML>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	fclose(pfhtml);
	//****************************************************
	COleVariant vaUrl=strFileName;
	COleVariant vtMissing;
	m_WebControl.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
	//***************************************************************************
	CRect rect;
	CRgn m_rgn;//裁減(切)視窗相關物件
	//::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	this->MoveWindow((778-5),(75-29),(235+12),(535+34),TRUE);
	this->GetClientRect(rect);
	m_rgn.CreateRectRgn(5,29,rect.Width(),(rect.Height()+25));
	::SetWindowRgn(GetSafeHwnd(),(HRGN)m_rgn,TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWebShowImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWebShowImageDlg::OnPaint() 
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
HCURSOR CWebShowImageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CWebShowImageDlg::BrowseDir(CString strDir)//Step 1:列出檔案清單
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.jpg";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			BrowseDir(ff.GetFilePath());
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//m_Array.Add(ff.GetFilePath());
			m_Array.Add(ff.GetFileName()); 
		}
	}
	ff.Close();
}