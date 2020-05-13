// AnalysisPluginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AnalysisPlugin.h"
#include "AnalysisPluginDlg.h"
#include<stdio.h>
#include<fstream.h>
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
// CAnalysisPluginDlg dialog

CAnalysisPluginDlg::CAnalysisPluginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnalysisPluginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnalysisPluginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnalysisPluginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnalysisPluginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnalysisPluginDlg, CDialog)
	//{{AFX_MSG_MAP(CAnalysisPluginDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalysisPluginDlg message handlers

BOOL CAnalysisPluginDlg::OnInitDialog()
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

void CAnalysisPluginDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAnalysisPluginDlg::OnPaint() 
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
HCURSOR CAnalysisPluginDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAnalysisPluginDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString Strfg;
	CString StrfgMid;
	char fg[700];
	CFileDialog fdlg(true,NULL,"openfile",NULL,"文字|*.txt");
	CString Strfilename;
	CString Strfilepath;
	CString StrCheckBuf;
	CString StrDataBuf;

	////////////////////////////////////////////////////////////
	CString StrEventOpen="WMS_EVENT_OPEN,";
	CString StrRequestName="RequestName=";
	CString StrEventClose="WMS_EVENT_CLOSE,";
	CString StrOpenHttp="Open Http Post Return =";
	CString StrCloseHttp="Close Http Post Return =";

	////////////////////////////////////////////////////////////
	FILE *pfEventOpen=NULL;
	FILE *pfEventClose=NULL;
	FILE *pfOpenHttp=NULL;
	FILE *pfCloseHttp=NULL;

	////////////////////////////////////////////////////////////
	if(fdlg.DoModal()==IDOK)
	{
		Strfilepath=fdlg.GetPathName();
		Strfilename=fdlg.GetFileTitle();
		a.open(Strfilepath.GetBuffer(0),ios::in);
		while(!a.eof())
		{
			a.getline(fg,500);
			Strfg=fg;
			/////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrEventOpen.GetLength());
			if(StrEventOpen==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500],Schrd03[500],Schrd04[500],Schrd05[500],Schrd06[500],Schrd07[500],Schrd08[500],Schrd09[500],Schrd10[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd01,Schrd02,Schrd03,Schrd04,Schrd05);
				sscanf (Schrd05 ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd06,Schrd07,Schrd08,Schrd09,Schrd10);
				char Dchrd01[500],Dchrd02[500],Dchrd03[500],Dchrd04[500],Dchrd05[500],Dchrd06[500],Dchrd07[500],Dchrd08[500],Dchrd09[500],Dchrd10[500];
				sscanf (Schrd02,"%[^'=']=%s",Dchrd01,Dchrd02);//抓取路徑
				StrDataBuf=Dchrd02;
				StrDataBuf+=",";
				sscanf (Schrd06,"%[^'=']=%s",Dchrd01,Dchrd05);//協定
				StrDataBuf+=Dchrd05;
				StrDataBuf+=",";
				sscanf (Schrd08,"%[^'=']=%s",Dchrd01,Dchrd07);//IP
				StrDataBuf+=Dchrd07;
				sscanf (Schrd10,"%[^'='],%s",Dchrd10,Dchrd10);//time
				StrDataBuf+=Dchrd10;
				pfEventOpen=fopen("EventOpen.txt","a");
				fprintf(pfEventOpen,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfEventOpen);
			}

			//////////////////////////////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrEventClose.GetLength());
			if(StrEventClose==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500],Schrd03[500],Schrd04[500],Schrd05[500],Schrd06[500],Schrd07[500],Schrd08[500],Schrd09[500],Schrd10[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd01,Schrd02,Schrd03,Schrd04,Schrd05);
				sscanf (Schrd05 ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd06,Schrd07,Schrd08,Schrd09,Schrd10);
				char Dchrd01[500],Dchrd02[500],Dchrd03[500],Dchrd04[500],Dchrd05[500],Dchrd06[500],Dchrd07[500],Dchrd08[500],Dchrd09[500],Dchrd10[500];
				sscanf (Schrd02,"%[^'=']=%s",Dchrd01,Dchrd02);//抓取路徑
				StrDataBuf=Dchrd02;
				StrDataBuf+=",";
				sscanf (Schrd06,"%[^'=']=%s",Dchrd01,Dchrd05);//協定
				StrDataBuf+=Dchrd05;
				StrDataBuf+=",";
				sscanf (Schrd08,"%[^'=']=%s",Dchrd01,Dchrd07);//IP
				StrDataBuf+=Dchrd07;
				sscanf (Schrd10,"%[^'='],%s",Dchrd10,Dchrd10);//time
				StrDataBuf+=Dchrd10;
				pfEventClose=fopen("EventClose.txt","a");
				fprintf(pfEventClose,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfEventClose);
			}

			//////////////////////////////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrOpenHttp.GetLength());
			if(StrOpenHttp==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^'=']=%s",Schrd01,Schrd02);
				StrDataBuf=Schrd02;
				pfOpenHttp=fopen("OpenHttp.txt","a");
				fprintf(pfOpenHttp,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfOpenHttp);
			}

			//////////////////////////////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrCloseHttp.GetLength());
			if(StrCloseHttp==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^'=']=%s",Schrd01,Schrd02);
				StrDataBuf=Schrd02;
				pfCloseHttp=fopen("CloseHttp.txt","a");
				fprintf(pfCloseHttp,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfCloseHttp);
			}

		}//while(!a.eof())
		a.close();
		MessageBox("write log01 finish");

		/////////////////////////////////////////////////////////////
		fstream b,c;
		CString StrCompare01,StrCompare02;
		CString StrStartTime,StrEndTime;
		FILE *pfAnalysisPlugin=NULL;
		
		b.open("EventOpen.txt",ios::in);
		while(!b.eof())
		{
			b.getline(fg,500);
			Strfg=fg;
			StrCompare01=Strfg.Mid(0,(Strfg.GetLength()-20));
			StrStartTime=Strfg.Mid((Strfg.GetLength()-20));

			c.open("EventClose.txt",ios::in);
			while(!c.eof())
			{
				c.getline(fg,500);
				Strfg=fg;
				StrCompare02=Strfg.Mid(0,(Strfg.GetLength()-20));
				StrEndTime=Strfg.Mid((Strfg.GetLength()-20));

				if(StrCompare01==StrCompare02)
				{
					Strfg=StrCompare01+StrStartTime+StrEndTime;
					pfAnalysisPlugin=fopen("AnalysisPlugin.log","a");
					fprintf(pfAnalysisPlugin,"%s\n",Strfg.GetBuffer(0));
					fclose(pfAnalysisPlugin);
					break;
				}//if(StrCompare01==StrCompare02)
			}//while(!c.eof())
			c.close();
		}//while(!b.eof())
		b.close();
		MessageBox("write log02 finish");
	}//if(fdlg.DoModal()==IDOK)
	DeleteFile("CloseHttp.txt");
	DeleteFile("EventClose.txt");
	DeleteFile("EventOpen.txt");
	DeleteFile("OpenHttp.txt");
	MessageBox("finish");
}
