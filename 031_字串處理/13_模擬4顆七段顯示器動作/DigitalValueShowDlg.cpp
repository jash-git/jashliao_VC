// DigitalValueShowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalValueShow.h"
#include "DigitalValueShowDlg.h"
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//int gintv1=0;
char gchrv1 []={'0','0','0','0','\0'};
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
// CDigitalValueShowDlg dialog

CDigitalValueShowDlg::CDigitalValueShowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDigitalValueShowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDigitalValueShowDlg)
	m_v1 = 0;
	m_str1 = _T("0000");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDigitalValueShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDigitalValueShowDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_str1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDigitalValueShowDlg, CDialog)
	//{{AFX_MSG_MAP(CDigitalValueShowDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalValueShowDlg message handlers

BOOL CDigitalValueShowDlg::OnInitDialog()
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

void CDigitalValueShowDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDigitalValueShowDlg::OnPaint() 
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
HCURSOR CDigitalValueShowDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDigitalValueShowDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		memcpy(gchrv1,m_str1,4);
		m_str1=ChangeData(gchrv1,m_v1);
	UpdateData(false);
}
void CDigitalValueShowDlg::MoveLeft(char *data)
{
	int i=0;
	for(i=0;i<3;i++)
	{
		data[i]=data[i+1];
	}
}
CString CDigitalValueShowDlg::ChangeData(char *data,int code)
{
	//int gintv1=0;
	//char gchrv1 []={'0','0','0','0','\0'};
	CString StrOutData;
	int mintdata=0;
	char int2str[5];
	mintdata=atoi(data);
	switch(code)
	{
		case 58:/*+1*/
			mintdata++;
			itoa(mintdata,int2str,10);
			if(mintdata<10)
			{
				StrOutData="000";
				StrOutData+=int2str;
			}
			else if(mintdata<99)
			{
				StrOutData="00";
				StrOutData+=int2str;
			}
			else if(mintdata<999)
			{
				StrOutData="0";
				StrOutData+=int2str;
			}
			else
			{
				StrOutData=int2str;
			}
			break;
		case 59: /*+2*/
			mintdata+=2;
			itoa(mintdata,int2str,10);
			if(mintdata<10)
			{
				StrOutData="000";
				StrOutData+=int2str;
			}
			else if(mintdata<99)
			{
				StrOutData="00";
				StrOutData+=int2str;
			}
			else if(mintdata<999)
			{
				StrOutData="0";
				StrOutData+=int2str;
			}
			else
			{
				StrOutData=int2str;
			}
			break;
		case 60:/*-1*/
			mintdata--;
			itoa(mintdata,int2str,10);
			if(mintdata<10)
			{
				StrOutData="000";
				StrOutData+=int2str;
			}
			else if(mintdata<99)
			{
				StrOutData="00";
				StrOutData+=int2str;
			}
			else if(mintdata<999)
			{
				StrOutData="0";
				StrOutData+=int2str;
			}
			else
			{
				StrOutData=int2str;
			}
			break;
		case 61:/*+10*/
			mintdata+=10;
			itoa(mintdata,int2str,10);
			if(mintdata<10)
			{
				StrOutData="000";
				StrOutData+=int2str;
			}
			else if(mintdata<99)
			{
				StrOutData="00";
				StrOutData+=int2str;
			}
			else if(mintdata<999)
			{
				StrOutData="0";
				StrOutData+=int2str;
			}
			else
			{
				StrOutData=int2str;
			}
			break;
		case 62:/*REST*/
			StrOutData="0000";
			break;
		case 57:/*9*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='9';
			StrOutData=int2str;
			break;
		case 54:/*6*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='6';
			StrOutData=int2str;
			break;
		case 51:/*3*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='3';
			StrOutData=int2str;
			break;
		case 48:/*0*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='0';
			StrOutData=int2str;
			break;
		case 56:/*8*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='8';
			StrOutData=int2str;
			break;
		case 53:/*5*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='5';
			StrOutData=int2str;
			break;
		case 50:/*2*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='2';
			StrOutData=int2str;
			break;
		//case 63:/*CALL*/
		//	break;
		case 55:/*7*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='7';
			StrOutData=int2str;
			break;
		case 52:/*4*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='4';
			StrOutData=int2str;
			break;
		case 49:/*1*/
			StrOutData=data;
			memcpy(int2str,StrOutData,4);
			int2str[4]='\0';
			MoveLeft(int2str);
			int2str[3]='1';
			StrOutData=int2str;
			break;
		default:
			StrOutData=data;
	}
	return StrOutData;
}