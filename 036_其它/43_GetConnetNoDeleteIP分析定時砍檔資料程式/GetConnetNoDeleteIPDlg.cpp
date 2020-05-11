// GetConnetNoDeleteIPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetConnetNoDeleteIP.h"
#include "GetConnetNoDeleteIPDlg.h"
#include <fstream.h>//純c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct ConnetIP
{
	int intcheck;
	char chrIP[50];
};
struct ConnetIP *CIP;
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
// CGetConnetNoDeleteIPDlg dialog

CGetConnetNoDeleteIPDlg::CGetConnetNoDeleteIPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetConnetNoDeleteIPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetConnetNoDeleteIPDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetConnetNoDeleteIPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetConnetNoDeleteIPDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetConnetNoDeleteIPDlg, CDialog)
	//{{AFX_MSG_MAP(CGetConnetNoDeleteIPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetConnetNoDeleteIPDlg message handlers

BOOL CGetConnetNoDeleteIPDlg::OnInitDialog()
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

void CGetConnetNoDeleteIPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGetConnetNoDeleteIPDlg::OnPaint() 
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
HCURSOR CGetConnetNoDeleteIPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGetConnetNoDeleteIPDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	FILE *pf,*pf1;
	///////////////////////////////////////////////////
	char chrdata[500];
	CString strdata="";
	CString strInData="";//strdata分身
	CString strRemain="";//剩餘資料
	long lngIndex=0;//取資料旗標
	CString strbuf="";//建立比對檔頭資料暫存器
	char chrSeps[]="-";//建立分割符號
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	/////////////////////////////////////////////////
	long lngCount=0;
	pf=fopen("OKConnect.txt","r");
	pf1=fopen("OKConnet1.txt","w");
	while(fscanf(pf,"%s",chrdata)!=EOF)
	{
		strdata=chrdata;
		strInData=strdata;
		chrInBuf=strInData.GetBuffer(0);//賦予資料
		lngLen=strlen(chrInBuf);
		chrOutBuf=strtok(chrInBuf,chrSeps);//擷取檔頭
		lngGetLen1=strlen(chrOutBuf);//提取資料長度
		lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
		strRemain=strdata.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
		lngCount++;
		fprintf(pf1,"%s\n",strRemain.GetBuffer(0));
	}
	fclose(pf);
	fclose(pf1);
	////////////////////////////////////////////////////
	pf=fopen("DeleteOK.txt","r");
	pf1=fopen("DeleteOK1.txt","w");
	int i=1;
	while(fscanf(pf,"%s",chrdata)!=EOF)
	{
		if((i%2)!=0)
			fprintf(pf1,"%s\n",chrdata);
		i++;
	}
	fclose(pf);
	fclose(pf1);
	////////////////////////////////////////////////////	
	CIP=new ConnetIP[lngCount];
	char chrIP[50];
	i=0;
	pf=fopen("OKConnet1.txt","r");
	while(fscanf(pf,"%s",chrIP)!=EOF)
	{
		CIP[i].intcheck=0;
		strcpy(CIP[i].chrIP,chrIP); 
		i++;
	}
	fclose(pf);
	///////////////////////////////////////////////////
	pf=fopen("DeleteOK1.txt","r");
	int j=0;
	while(fscanf(pf,"%s",chrIP)!=EOF)
	{
		strdata=chrIP;
		for(i=0;i<lngCount;i++)
		{
			strInData=CIP[i].chrIP;
			if(strdata==strInData)
			{
				CIP[i].intcheck=1;
				j++;
				break;
			}
		}
	}
	///////////////////////////////////////////////////
	pf1=fopen("ConnetNotDelete.txt","w");
	for(i=0;i<lngCount;i++)
	{
		if(CIP[i].intcheck==0)
		{
			fprintf(pf1,"%s\n",CIP[i].chrIP);
		}
	}
	fclose(pf);
	fclose(pf1);
	delete []CIP;
	MessageBox("OK");
}
