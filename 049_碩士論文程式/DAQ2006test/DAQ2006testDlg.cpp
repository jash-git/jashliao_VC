// DAQ2006testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DAQ2006test.h"
#include "DAQ2006testDlg.h"
///////////////////////////////
#include "D2kDASK.H"
#include <sys\timeb.h>
#include <stdio.h>
//////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////
I16 card;
U16 card_num=0;
U16 Channel[4]={0,1,2,3};
U16 Data[4]={0,0,0,0};
FILE *TimerGet1,*TimerGet2,*TimerGet3;
bool bopencard=false;
bool bontimer=false;
/////////////////////////////////////////////
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
// CDAQ2006testDlg dialog

CDAQ2006testDlg::CDAQ2006testDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDAQ2006testDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDAQ2006testDlg)
	m_v0 = 0;
	m_v1 = 0;
	m_v2 = 0;
	m_v3 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDAQ2006testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDAQ2006testDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v0);
	DDX_Text(pDX, IDC_EDIT2, m_v1);
	DDX_Text(pDX, IDC_EDIT3, m_v2);
	DDX_Text(pDX, IDC_EDIT4, m_v3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDAQ2006testDlg, CDialog)
	//{{AFX_MSG_MAP(CDAQ2006testDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnOpenCard)
	ON_BN_CLICKED(IDC_BUTTON2, OnReadData)
	ON_BN_CLICKED(IDC_BUTTON3, OnCloseCard)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON4, OnStartTimer)
	ON_BN_CLICKED(IDC_BUTTON5, OnEndTimer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDAQ2006testDlg message handlers

BOOL CDAQ2006testDlg::OnInitDialog()
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

void CDAQ2006testDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDAQ2006testDlg::OnPaint() 
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
HCURSOR CDAQ2006testDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDAQ2006testDlg::OnOpenCard() 
{
	// TODO: Add your control notification handler code here
	///////////////////////////////////////////
	card=D2K_Register_Card(DAQ_2006,card_num);
	/////////////////////////////////////////
	D2K_AI_CH_Config(card,Channel[0],AD_U_5_V);
	D2K_AI_CH_Config(card,Channel[1],AD_U_5_V);
	D2K_AI_CH_Config(card,Channel[2],AD_U_5_V);
	D2K_AI_CH_Config(card,Channel[3],AD_U_5_V);
	////////////////////////////////////////////
	bopencard=true;
	MessageBox("開卡完成");
	
}
void CDAQ2006testDlg::OnReadData() 
{
	// TODO: Add your control notification handler code here
	struct timeb t,t1;
	//////////////////////////////////////////////
	if(bopencard)
	{
		ftime(&t);
		D2K_AI_ReadChannel(card,Channel[0],&Data[0]);
		D2K_AI_ReadChannel(card,Channel[1],&Data[1]);
		D2K_AI_ReadChannel(card,Channel[2],&Data[2]);
		D2K_AI_ReadChannel(card,Channel[3],&Data[3]);
		////////////////////////////////////////////
		UpdateData(true);
		m_v0=Data[0];
		m_v1=Data[1];
		m_v2=Data[2];
		m_v3=Data[3];
		UpdateData(false);
		ftime(&t1);
		FILE *p;
		p=fopen("時間差.txt","a");
		fprintf(p,"%d\t\%d\n%d\t\%d\n",t.time,t.millitm,t1.time,t1.millitm);
	}
	else
	{
		MessageBox("還未開卡");
	}
}

void CDAQ2006testDlg::OnCloseCard() 
{
	// TODO: Add your control notification handler code here
	D2K_Release_Card(card);
	bopencard=false;
}

void CDAQ2006testDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	D2K_Release_Card(card);
	CDialog::OnClose();
}

void CDAQ2006testDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int de[3]={0};
	D2K_AI_ReadChannel(card,Channel[0],&Data[0]);
	D2K_AI_ReadChannel(card,Channel[1],&Data[1]);
	D2K_AI_ReadChannel(card,Channel[2],&Data[2]);
	D2K_AI_ReadChannel(card,Channel[3],&Data[3]);
	UpdateData(true);
	m_v0=Data[0];
	m_v1=Data[1];
	m_v2=Data[2];
	m_v3=Data[3];
	UpdateData(false);
	de[0]=(m_v3/2)-m_v0;
	de[1]=(m_v3/2)-m_v1;
	de[2]=(m_v3/2)-m_v2;
	fprintf(TimerGet1,"%d\n",de[0]);
	fprintf(TimerGet2,"%d\n",de[1]);
	fprintf(TimerGet3,"%d\n",de[2]);
	CDialog::OnTimer(nIDEvent);
}

void CDAQ2006testDlg::OnStartTimer() 
{
	// TODO: Add your control notification handler code here
	if(bopencard)
	{
	TimerGet1=fopen("aV1.txt","w");
	TimerGet2=fopen("aV2.txt","w");
	TimerGet3=fopen("aV3.txt","w");
	SetTimer(1,10,NULL);
	bontimer=true;
	}
	else
	{
		bontimer=false;
		MessageBox("還未開卡");
	}
}

void CDAQ2006testDlg::OnEndTimer() 
{
	// TODO: Add your control notification handler code here
	if(bontimer)
	{
	fclose(TimerGet1);
	fclose(TimerGet2);
	fclose(TimerGet3);
	KillTimer(1);
	bontimer=false;
	bopencard=false;
	}
	else
	{
		MessageBox("未啟動timer");
	}
}

BOOL CDAQ2006testDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	D2K_Release_Card(card);
	bopencard=false;
	return CDialog::DestroyWindow();
}
