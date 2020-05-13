// wmp002Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "wmp002.h"
#include "wmp002Dlg.h"
#include "wmpcontrols.h"
#include "wmpmedia.h"
#include "wmpplaylist.h"
////////////////////////
#include<fstream.h>
#include <Vfw.h>
#include <stdio.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString gStrMMSArrBuf[10];
int gintcount;
FILE *pfLogFile;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
bool blnloop=false;
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
// CWmp002Dlg dialog

CWmp002Dlg::CWmp002Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWmp002Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWmp002Dlg)
	m_v1 = 0.0;
	m_v2 = -1.0;
	m_v3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWmp002Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWmp002Dlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_OCX1, m_WMP);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWmp002Dlg, CDialog)
	//{{AFX_MSG_MAP(CWmp002Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWmp002Dlg message handlers

BOOL CWmp002Dlg::OnInitDialog()
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
	rc.bottom-=2;
	rc.left-=2;
	rc.right-=2;
	rc.top-=-2; 
	m_WMP.MoveWindow( &rc, true );
	///////////////////////////////////////////////////////
	///*
	m_MMSArray.RemoveAll();
	fstream a1;
	char fg[700];
	CString StrDataBuf,StrDataBuf2,StrDataBuf1;
	int intlen;
	a1.open("data.txt",ios::in);
	int i=0,j=0,k=0;
	while(!a1.eof())
	{
		StrDataBuf="";
		StrDataBuf2="";
		StrDataBuf1="";
		k=0;
		a1.getline(fg,500);
		StrDataBuf=fg;
		if(StrDataBuf.GetLength() >13 )
		{
			j=StrDataBuf.GetLength();
			for(i=0;i<(j-1);i++)
			{
				if(StrDataBuf.Mid(i,1)=="," )
				{
					k=1;
				}
				else
				{
					if(k==0)
					{
						StrDataBuf1+=StrDataBuf.Mid(i,1);
					}
					else
					{
						StrDataBuf2+=StrDataBuf.Mid(i,1);
					}
				}
			}
			m_MMSArray1.Add(StrDataBuf1);
			m_MMSArray.Add(StrDataBuf2);
		}
	}
	

	//*/
	/*
	gStrMMSArrBuf[0]="mms://live2.ncnews.com.cn/sjb?userid=guest&token=7b4821c3f9ae818c3964a687a62773a2";
	gStrMMSArrBuf[1]="mms://212.156.63.102/TV3";
	gStrMMSArrBuf[2]="mms://195.122.130.135/speedup-tv_SpeedUp-TV_10";
	gStrMMSArrBuf[3]="mms://195.122.130.135/speedup-tv_Motorsport-TV_10";
	gStrMMSArrBuf[4]="mms://195.122.130.135/speedup-tv_Kegeln-TV_10";
	gStrMMSArrBuf[5]="mms://195.122.130.139/Bundesligen-TV";
	gStrMMSArrBuf[6]="mms://quik4.impek.tv/brtv";
	gStrMMSArrBuf[7]="mms://91.121.179.127/sbeaute";
	gStrMMSArrBuf[8]="mms://wm9.streaming.telstra.com/ucs-wh_BigPondTV1live2";
	gStrMMSArrBuf[9]="mms://195.122.130.135/speedup-tv_Tennis-TV_10";
	*/
	gintcount=-1;
	//m_WMP.SetUrl("mms://mms.iptv.tw-airnet.net/mms3/movies/M01489.wmv");
	//m_WMP.SetUrl("mms://mms.iptv.tw-airnet.net/mms3/av/A00181.wmv");
	gintcount++;
	CString StrBuf;
	StrBuf=m_MMSArray.GetAt(gintcount);//ㄓ方
	m_WMP.SetUrl(StrBuf);
	m_WMP.GetControls().play();
	SetTimer(1,20000,NULL);
	CTime t1=CTime::GetCurrentTime();
	CString StrFileName;
	DeleteFile("Errlogs.txt");
	StrFileName="Errlogs.txt";
	pfLogFile=fopen(StrFileName.GetBuffer(0),"w"); 
	////////////////////////////////////////////////////////
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWmp002Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWmp002Dlg::OnPaint() 
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
HCURSOR CWmp002Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWmp002Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	/*
CWMPPlaylist CurrentPlayList=wmp4.GetCurrentPlaylist(); //?玡冀
CWMPMedia newMedia=wmp4.newMedia(strTemp); //ミ碈蔨?禜

CurrentPlayList.appendItem(newMedia.m_lpDispatch); //睰?玡冀

	*/
	CWMPPlaylist curPlaylist = m_WMP.GetCurrentPlaylist();
	CWMPMedia newMedia1=m_WMP.newMedia("C:\\MOVIE\\01.rmvb");
	CWMPMedia newMedia2=m_WMP.newMedia("C:\\MOVIE\\02.wm");
	CWMPMedia newMedia3=m_WMP.newMedia("C:\\MOVIE\\03.mpg");
	CWMPMedia newMedia4=m_WMP.newMedia("C:\\MOVIE\\04.flv");
	CWMPMedia newMedia5=m_WMP.newMedia("C:\\MOVIE\\05.avi");
	CWMPMedia newMedia6=m_WMP.newMedia("C:\\MOVIE\\06.asf");
	curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	curPlaylist.insertItem(1,newMedia2.m_lpDispatch);
	curPlaylist.insertItem(2,newMedia3.m_lpDispatch);
	curPlaylist.insertItem(3,newMedia4.m_lpDispatch);
	curPlaylist.insertItem(4,newMedia5.m_lpDispatch);
	curPlaylist.insertItem(5,newMedia6.m_lpDispatch);

	m_WMP.SetCurrentPlaylist(curPlaylist);
	m_WMP.GetControls().play();

	//SetTimer(1,1000,NULL);
	blnloop=true;
}

void CWmp002Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_WMP.GetControls().stop();
}

void CWmp002Dlg::OnTimer(UINT nIDEvent) 
{
	KillTimer(1);
	long lngPlayState;
	int j;
	j=m_MMSArray.GetSize();
	CString StrBuf,StrBuf1;
	CString StrStat="";
	lngPlayState=m_WMP.GetPlayState();//1->STOP 2->PAUSE 3->RUN
	switch(lngPlayState)
	{
		case 1:
			this->SetWindowText("wmp002-STOP");
			StrStat="STOP";
			break;
		case 2:
			this->SetWindowText("wmp002-PAUSE"); 	
			StrStat="PAUSE";
			break;
		case 3:
			this->SetWindowText("wmp002-RUN"); 	
			StrStat="RUN";
			break;
		default:
			StrStat="NOT OK";
	}
	if(StrStat=="NOT OK")
	{
		StrBuf=m_MMSArray.GetAt(gintcount);//ㄓ方
		StrBuf1=m_MMSArray1.GetAt(gintcount);//ㄓ方
		fprintf(pfLogFile,"%s,%s->%s\n",StrBuf1.GetBuffer(0),StrBuf.GetBuffer(0),StrStat.GetBuffer(0)); 
	}
	if(gintcount>=(j-1))
	{
		gintcount=-1;
		fclose(pfLogFile);
		ShellExecute(NULL,"open","MyEmailClient.exe",NULL,NULL,SW_SHOWNORMAL);
		this->OnOK(); 
	}
	else
	{
		gintcount++;
		StrBuf=m_MMSArray.GetAt(gintcount);//ㄓ方
		this->SetWindowText(StrBuf);
		m_WMP.SetUrl(StrBuf);
		m_WMP.GetControls().play();
		SetTimer(1,20000,NULL);
	}
	CDialog::OnTimer(nIDEvent);
}
