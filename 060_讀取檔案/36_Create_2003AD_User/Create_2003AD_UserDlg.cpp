// Create_2003AD_UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Create_2003AD_User.h"
#include "Create_2003AD_UserDlg.h"
////////////////////////////////
//Step1
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<fstream.h>
/////////////////////////////////
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
// CCreate_2003AD_UserDlg dialog

CCreate_2003AD_UserDlg::CCreate_2003AD_UserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreate_2003AD_UserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreate_2003AD_UserDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreate_2003AD_UserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreate_2003AD_UserDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreate_2003AD_UserDlg, CDialog)
	//{{AFX_MSG_MAP(CCreate_2003AD_UserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CreateFile, OnCreateFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreate_2003AD_UserDlg message handlers

BOOL CCreate_2003AD_UserDlg::OnInitDialog()
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

void CCreate_2003AD_UserDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreate_2003AD_UserDlg::OnPaint() 
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
HCURSOR CCreate_2003AD_UserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCreate_2003AD_UserDlg::OnCreateFile() 
{
	// TODO: Add your control notification handler code here
	//Step2
	FILE *pfbat;
	fstream pf;
	char chrdata[500];
	char chrfirstname[50];
	char chrlastname[50];
	char chrusername[50];
	char chrpassword[50];
	char chrOA[50];
	int result;
	pfbat=fopen("adduser.bat","w");
	pf.open("adduser.csv",ios::in);
	CString StrData1,StrData2,StrBuf;
	while(!pf.eof())
	{
		StrData1="";
		StrData2="";
		StrBuf="";
		memset(chrdata,'\0',500);
		result=0;
		pf.getline(chrdata,500);
		result = sscanf(chrdata, "%[^','],%[^','],%[^','],%[^','],%s", chrfirstname, chrlastname, chrOA, chrusername,chrpassword);
		//dsadd user cn=莊清科,ou=IT,dc=project,dc=tw-airnet,dc=net -upn jcc@project.tw-airnet.net -pwd 778899 -display 莊清科 -fn 清科 -ln 莊 -mustchpwd no -disabled no -samid jcc
		if(result==5)
		{
			StrBuf="dsadd user cn=";
			StrBuf+=chrfirstname;
			StrBuf+=chrlastname;
			StrData1+=StrBuf;
			//**********************
			StrBuf=",ou=";
			StrBuf+=chrOA;
			StrData1+=StrBuf;
			//**********************
			StrBuf=",dc=project,dc=tw-airnet,dc=net -upn ";
			StrBuf+=chrusername;
			StrBuf+="@project.tw-airnet.net ";
			StrData1+=StrBuf;
			//**********************
			StrBuf="-pwd ";
			StrBuf+=chrpassword;
			StrData1+=StrBuf;
			//**********************
			StrBuf=" -display ";//莊清科 -fn 清科 -ln 莊 
			StrBuf+=chrfirstname;
			StrBuf+=chrlastname;
			StrBuf+=" -fn ";
			StrBuf+=chrlastname;
			StrBuf+=" -ln ";
			StrBuf+=chrfirstname;
			StrData1+=StrBuf;
			//**********************
			StrBuf=" -mustchpwd no -disabled no -pwdneverexpires yes -samid ";
			StrBuf+=chrusername;
			StrData1+=StrBuf;
			//**********************
			//winpop add jcc@project.tw-airnet.net
			StrBuf="winpop add ";
			StrBuf+=chrusername;
			StrData2=StrBuf;
			StrData2+="@project.tw-airnet.net";
			//**********************
			fprintf(pfbat,"%s\n%s\n",StrData1.GetBuffer(0),StrData2.GetBuffer(0));
		}
	}
	fclose(pfbat);
	pf.close();
	MessageBox("Create OK");
	
}
