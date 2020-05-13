// test_Analyse_DataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_Analyse_Data.h"
#include "test_Analyse_DataDlg.h"
#include <string.h>
#include <stdlib.h>
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct file_data
{
	int intuid;
	int intaction;
	char chrip[50];
	char chrfile_path[250];
	int intstatus;
	char chrStart_Date[50];
};
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
// CTest_Analyse_DataDlg dialog

CTest_Analyse_DataDlg::CTest_Analyse_DataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_Analyse_DataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_Analyse_DataDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_Analyse_DataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_Analyse_DataDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_Analyse_DataDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_Analyse_DataDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_Analyse_DataDlg message handlers

BOOL CTest_Analyse_DataDlg::OnInitDialog()
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

void CTest_Analyse_DataDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_Analyse_DataDlg::OnPaint() 
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
HCURSOR CTest_Analyse_DataDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_Analyse_DataDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	fstream pf;
	FILE *pf1;
	int intFileNO=0;
	char chrFileName[20];
	CString StrFileName;
	struct file_data fd;
	char chrdata[500];
	bool blnLen=false;
	////////////////////////////////////
	CString StrIP="";
	CString StrBuf="";
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	CString m_strInData="";//主
	CString strInData="";//m_strInData分身
	CString strRemain="";//剩餘資料
	char chrSeps[]=",";//建立分割符號
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	//////////////////////////////01_start
	pf.open("data.txt",ios::in);
	int intCount=0;
	while(!pf.eof())
	//////////////////////////////01_end
	{
		///////////////////////////////////02_start
		pf.getline(chrdata,500);
		m_strInData=chrdata;
		strInData=m_strInData;//取出原來資料
		do
		{
			chrInBuf=strInData.GetBuffer(0);//賦予資料
			lngLen=strlen(chrInBuf);
			if(lngLen<= 0)//防堵最後一筆資料換行所造成誤判
			{
				blnLen=true;
				break;
			}
			chrOutBuf=strtok(chrInBuf,chrSeps);//擷取的資料
			intCount++;
			switch(intCount)
			{
				case 1://uid
					fd.intuid=atoi(chrOutBuf); 
					break;
				case 2://action
					fd.intaction=atoi(chrOutBuf); 
					break;
				case 3://ip
					strcpy(fd.chrip,chrOutBuf);
					break;
				case 4://file_path
					strcpy(fd.chrfile_path,chrOutBuf);
					break;
				case 5://status
					fd.intstatus=atoi(chrOutBuf); 
					break;
				case 6://Start_Data
					strcpy(fd.chrStart_Date,chrOutBuf);
					break;
			}
			lngGetLen1=strlen(chrOutBuf);//提取資料長度
			lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
			if(intCount==1)
			{
				strRemain=m_strInData.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			}
			else
			{
				if(lngGetLen2>0)
					strRemain=strRemain.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			}
			strInData=strRemain;
		}while(intCount<6);
		if(blnLen==true)//防堵最後一筆資料換行所造成誤判
		{
			if(intFileNO!=0)
				fclose(pf1);
			break;
		}
		intCount=0;
		lngLen=0;//建立長度暫存變數
		lngGetLen1=0;//提取資料長度
		lngGetLen2=0;//剩餘資料長度
		/////////////////////////////////02_end
		////////////////////////////////03_start
		StrBuf=fd.chrip;
		if(StrIP!=StrBuf)
		{
			StrIP=StrBuf;
			if(intFileNO!=0)
				fclose(pf1);
			intFileNO++;
			itoa(intFileNO,chrFileName,10);
			StrFileName=chrFileName;
			StrFileName+=".txt";
			pf1=fopen(StrFileName.GetBuffer(0),"w");
			fprintf(pf1,"%s\n",fd.chrip);
			fprintf(pf1,"%d\t%s\n",fd.intaction,fd.chrfile_path);  
		}
		else
		{
			fprintf(pf1,"%d\t%s\n",fd.intaction,fd.chrfile_path);
		}
		////////////////////////////////03_end
	}
	pf.close(); 
	MessageBox("OK");
}
